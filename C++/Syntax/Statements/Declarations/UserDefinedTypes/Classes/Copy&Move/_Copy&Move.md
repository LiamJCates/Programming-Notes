For classes with pointer member variables, three things are normally done:
1. Include the destructor in the class
2. Overload the assignment operator for the class
3. Include the copy constructor

Constructors, destructors, copy, and move operations for a type are not logically separate. We must define them as a matched set or suffer logical or performance problems.

If a class X has a destructor that performs a nontrivial task, such as free-store deallocation or lock release, the class is likely to need the full complement of functions:

class X {
public:
  X(Sometype);            // ‘‘ordinary constructor’’: create an object
  X();                    // default constructor
  X(const X&);            // copy constructor
  X(X&&);                 // move constructor
  X& operator=(const X&); // copy assignment: clean up target and copy
  X& operator=(X&&);      // move assignment: clean up target and move
  ˜X();                   // destructor: clean up
  // ...
};

There are five situations in which an object can be copied or moved:
• As the source of an assignment
• As an object initializer
• As a function argument
• As a function return value
• As an exception

An assignment uses a copy or move assignment operator. In principle, the other cases use a copy or move constructor. However, a copy or move constructor invocation is often optimized away by constructing the object used to initialize right in the target object. For example:

X make(Sometype);
X x = make(value);

Here, a compiler will typically construct the X from make() directly in x; thus eliminating (‘‘eliding’’) a copy. In addition to the initialization of named objects and of objects on the free store, constructors are used to initialize temporary objects and to implement explicit type conversion.

A good rule of thumb (sometimes called the rule of zero) is to either define all of the essential operations or none (using the default for all).


Compiler-Generated Methods

Five methods govern move and copy behavior:
•	 The destructor
•	 The copy constructor
•	 The move constructor
•	 The copy assignment operator
•	 The move assignment operator

[C++\Types&Values\Classes\Copy&Move\Compiler Generated Methods.png]

The compiler can generate default implementations for each under certain circumstances. Unfortunately, the rules for which methods get generated are complicated and potentially uneven across compilers. You can eliminate this complexity by setting these methods to default/delete or by implementing them as appropriate. This general rule is the rule of five, because there are five methods to specify. Being explicit costs a little time, but it saves a lot of future headaches.

If you provide nothing, the compiler will generate all five destruct/copy/move functions. This is the rule of zero. If you explicitly define any of destructor/copy constructor/copy assignment operator, you get all three. This is dangerous: it’s too easy to get into an unintended situation in which the compiler will essentially convert all your moves into copies.

Finally, if you provide only move semantics for your class, the compiler will not automatically generate anything except a destructor.
