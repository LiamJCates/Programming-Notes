## References

In a declaration, the unary suffix & means ‘‘reference to.’’ A reference is similar to a pointer, except that you don’t need to use a prefix ∗ to access the value referred to by the reference. Also, a reference cannot be made to refer to a different object after its initialization.

References are particularly useful for specifying function arguments:

  void sort(vector<double>& v);

By using a reference, we ensure that for a call sort(my_vec), we do not copy my_vec and that it really is my_vec that is sorted.

When we don’t want to modify an argument but still don’t want the cost of copying, we use a const reference:

double sum(const vector<double>&)

Functions taking const references are very common.

When used in declarations, operators (such as &, ∗, and [ ]) are called declarator operators:

T a[n] // T[n]: a is an array of n Ts
T∗ p // T*: p is a pointer to T
T& r // T&: r is a reference to T
T f(A) // T(A): f is a function taking an argument of type A returning a result of type T



What Is a Reference?
A reference is an alias for a variable. When you declare a reference, you need to initialize it to a variable using the reference operator (&):

  VarType original = Value;
  VarType& ReferenceVariable = original;



References as shortcuts

A secondary (much less used) use of references is to provide easier access to nested data. Consider the following struct:

  struct Something
  {
    int value1;
    float value2;
  };

  struct Other
  {
    Something something;
    int otherValue;
  };

  Other other;

Let’s say we needed to work with the value1 field of the Something struct of other. Normally, we’d access that member as other.something.value1. If there are many separate accesses to this member, the code can become messy. References allow you to more easily access the member:

  int &ref{ other.something.value1 };
  // ref can now be used in place of other.something.value1

The following two statements are thus identical:

  other.something.value1 = 5;
  ref = 5;

This can help keep your code cleaner and more readable.


Passing by Reference
A reference is another way of specifying a parameter in a function whereby the function can modify the original variable. Instead of following the parameter type with an asterisk (*) to denote a pointer, you follow it with an ampersand (&).

Then, throughout your function, you can use the parameter just as you normally would, not as a pointer. But every change you make to the parameter
affects the original variable

void MessMeUp(int &myparam)
{
  myparam = myparam * 2 + 10;
}

If you have string parameters, and you use the & to pass them by reference, skip the shortcut -> notation to call the string functions. And don’t
dereference anything. There are no pointers. Just type the dot (or period)
and the function. No asterisks needed.

If you write a function that uses a reference and somebody else uses your
function in code (see Book I, Chapter 6, for information on how to do this),
you could end up making that other person angry. The other person may not
realize that, “Hey, man — this thing just messed up my variable!” WHAM! The
variable gets changed. How do you avoid this? Warn the other person. Make
it clear to anybody using your function that it uses references and will
modify variables


Function DoSomething() is invoked like this:
ReturnType Result = DoSomething(argument); // function call

The preceding code would result in the argument being copied into Parameter, which is then used by the function DoSomething(). This copying step can be quite an overhead if the argument in question consumes a lot of memory. Similarly, when DoSomething() returns a value, it is copied again into Result. It would be ideal if we could avoid or eliminate the copy steps, enabling the function to work directly on the data in the caller’s stack. References enable you to do just that.

A version of the function without the copy step looks like this:
ReturnType DoSomething(Type& parameter); // note the reference&

This function would be invoked as the following:
ReturnType Result = DoSomething(argument);

As the argument is being passed by reference, Parameter is not a copy of argument, rather it is an alias

#include <iostream>
 using namespace std;

 void GetSquare(int& number)
 {
 number *= number;
 }

 int main()
 {
 cout << "Enter a number you wish to square ";
 int number = 0;
 cin >> number;

 GetSquare(number);
 cout << "Square is " << number << endl;

 return 0;
 }

 The function that performs the operation of accepts
the number to be squared as a parameter by reference and returns the result in the same.
Had you forgotten to mark the parameter number as a reference (&), the result would not
reach the calling function main() as GetSquare() would then perform its operations
on a local copy of number and that would be destroyed when the function exits. Using
references, you ensure that GetSquare() is operating in the same address space where
number in main() is defined. Thus, the result of the operation is available in main()
even after the function GetSquare() has exited



Using Keyword const on References
You might need to have references that are not allowed to change the value of the
original variable being aliased. Using const when declaring such references is the way
to achieve that:
int original = 30;
const int& constRef = original;
constRef = 40; // Not allowed: constRef can’t change value in original
int& ref2 = constRef; // Not allowed: ref2 is not const
const int& constRef2 = constRef; // OK



References to r-values extend the lifetime of the referenced value

Normally r-values have expression scope, meaning the values are destroyed at the end of the expression in which they are created.

  // 2 + 3 evaluates to r-value 5, which is destroyed at the end of this statement
  std::cout << 2 + 3 << '\n';

However, when a reference to a const value is initialized with an r-value, the lifetime of the r-value is extended to match the lifetime of the reference.

  int somefcn()
  {
      const int& ref{ 2 + 3 }; // normally the result of 2+3 has expression scope and is destroyed at the end of this statement
      // but because the result is now bound to a reference to a const value...
      std::cout << ref << '\n'; // we can use it here
  } // and the lifetime of the r-value is extended to here, when the const reference dies



Assignment to a reference
does not change what the reference refers to but assigns to the referenced object:
int x = 2;
int y = 3;
int& r = x; // r refers to x
int& r2 = y; // now r2 refers to y
r = r2; // read through r2, write through r: x becomes 3

Initialization differs from assignment. In general, for an assignment to work correctly, the
assigned-to object must have a value. On the other hand, the task of initialization is to make an
uninitialized piece of memory into a valid object. For almost all types, the effect of reading from or
writing to an uninitialized variable is undefined. For built-in types, that’s most obvious for references:
int x = 7;
int& r {x}; // bind r to x (r refers to x)
r = 7; // assign to whatever r refers to
int& r2; // error : uninitialized reference
r2 = 99; // assign to whatever r2 refers to
Fortunately, we cannot have an uninitialized reference; if we could, then that r2=99 would assign 99
to some unspecified memory location; the result would eventually lead to bad results or a crash.
You can use = to initialize a reference but please don’t let that confuse you. For example:
int& r = x; // bind r to x (r refers to x)
This is still initialization and binds r to x, rather than any form of value copy.
