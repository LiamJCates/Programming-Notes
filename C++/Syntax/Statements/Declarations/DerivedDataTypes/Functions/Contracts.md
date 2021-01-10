Contracts
There is currently no general and standard way of writing optional run-time tests of invariants, preconditions, etc.

A contract mechanism is proposed for C++20 [Garcia,2016] [Garcia,2018]. The aim is to support users who want to rely on testing to get programs right – running with extensive run-time checks – but then deploy code with minimal checks. This is popular in high-performance applications in organizations that rely on systematic and extensive checking.

For now, we have to rely on ad hoc mechanisms. For example, we could use a command-line macro to control a run-time check:

  double& Vector::operator[](int i)
  {
    if (RANGE_CHECK && (i<0 || size()<=i))
      throw out_of_range{"Vector::operator[]"};

    return elem[i];
  }

The standard library offers the debug macro, assert(), to assert that a condition must hold at run time. For example:

  void f(const char∗ p)
  {
    assert(p!=nullptr); // p must not be the nullptr
    // ...
  }

If the condition of an assert() fails in ‘‘debug mode,’’ the program terminates.

If we are not in debug mode, the assert() is not checked. That’s pretty crude and inflexible, but often sufficient.








https://www.modernescpp.com/index.php/c-core-guidelines-a-detour-to-contracts


What is a contract?

A contract specifies in a precise and checkable way interfaces for software components. This software components are typically functions and methods, that have to fulfil preconditions, postconditions, and invariants. Here are the shortened definitions from the proposals.

    A precondition: a predicate that is supposed to hold upon entry in a function. It is placed outside the function definition.
    A postcondition: a predicate that is supposed to hold upon exit from the function. It is placed outside the function definition.
    An assertion: a predicate that is supposed to hold at its point in the computation. It is placed inside the function definition.

The precondition and the postconditon is in C++20 placed outside the function defintion but the invariant is placed inside the function definition. A predicate is a function which returns a boolean.

Here is a first example:


int push(queue& q, int val)
  [[ expects: !q.full() ]]
  [[ ensures !q.empty() ]]{
  ...
  [[assert: q.is_ok() ]]
  ...
}



The attribute expects is a precondition, the attribute ensures is a postcondition, and the attribute assert is an assertion.

The contracts for the function push are that the queue is not full before adding an element, that is not empty after adding and the assertion q.is_ok() holds.

Preconditions and postconditions are part of the function interface. This means they can't access local members of a function or private or protected members of a class. In contrast, assertions are part of the implementation and can, therefore, access local members of a function of private or protected members of a class.



class X {
public:
    void f(int n)
        [[ expects: n<m ]]  // error; m is private
    {
        [[ assert: n<m ]];  // OK
        // ...
    }
private:
    int m;
};     



m is private and can, therefore, not be part of a precondition.

By default, a violation of a contract terminates the program. This is not the full story, let me give you more details.
More Details

Here is the full syntax of the contract attributes: [[contract-attribute modifier: conditional-expression ]]

    contract-attribute: expects, ensures, and assert
    modifier: specifies the contract level or the enforcement of the contract; possible values are default, audit, and axiom
        default: the cost of run-time checking should be small; it is the default modifier
        audit: the cost of run-time checking is assumed to be large
        axiom: the predicate is not checked at run-time
    conditional-expression: the predicate of the contract

For the ensures attribute, there is an additional identifier available. [[ensures modifier identifier: conditional-expression ]]

The identifier let you refer to the return value of the function.

int mul(int x, int y)
  [[expects: x > 0]]         // implicit default
  [[expects default: y > 0]]
  [[ensures audit res: res > 0]]{
  return x * y;
}



res as the identifier is, in this case, an arbitrary name. As shown in the example, you can use more contracts of the same kind.

Let me dive deeper into the modifiers and the handling of the contract violations.
Handling contract violations

A compilation has three assertion build levels:

    off: no contracts are checked
    default: default contracts are checked; this is the default
    audit: default and audit contract are checked

If a contract violation occurs - that means the predicate evaluates to false -, the violation handler is invoked. The violation handler is a function of type noexcept which takes a const std::contract_violation and returns a void. Because the function is noexcept, this means that std::terminate is called in case of a violation of the contract. A user can set a violation handler.

The class std::contract_violation gives information about the violation of the contract.

namespace std{
  class contract_violation{
  public:
    uint_least32_t line_number() const noexcept;
    string_view file_name() const noexcept;
    string_view function_name() const noexcept;
    string_view comment() const noexcept;
    string_view assertion_level() const noexcept;
  };
}

    line_number: line number of the contract violation
    file_name: file name of the contract violation
    function_name: function name of the contract violation
    comment: the predicate to the contract
    assertion_level: assertion level to the contract

 There are a few rules to keep in mind if you declare a contract.
Declaration of contracts

A contract can be placed on the declaration of a function. This includes declarations of virtual functions or function templates.

    The contracts declaration of a function must be identical. Any declaration different from the first one can omit the contract.

int f(int x)
  [[expects: x>0]]
  [[ensures r: r>0]];

int f(int x); // OK. No contract.

int f(int x)
  [[expects: x>=0]]; // Error missing ensures and different expects condition



    A contract can not be modified in an overriding function.



struct B{
  virtual void f(int x)[[expects: x > 0]];
  virtual void g(int x);
}

struct D: B{
  void f(int x)[[expects: x >= 0]];   // error
  void g(int x)[[expects: x != 0]];   // error
};

Both contract definitions of class D are erroneous. The contract of the method f differs from the one from B::f. The method D::g adds a contract to B::g.
Closing Thoughts

Impressed? Me too! I still can not imagine how fundamentally contracts will change the way we write functions and think about interfaces and exception handling. Maybe Herb Sutter's thoughts on Sutter's Mill give you an idea because for him "contracts is the most impactful feature of C++20 so far, and arguably the most impactful feature we have added to C++ since C++11."
