## Constants

Constants are expressions with a fixed value, a value that doesn't change.

Constants in C++ can be:
  Literal constants
  Named Constants
  Constant expressions (since C++11)
  Enumerated constants
  Defined constants


C++ provides two keywords to enable you to express immutable objects, the intent that an object is not to be modified:
  const
  constexpr

const
meaning roughly ‘‘I promise not to change this value.’’ This is used primarily as a type qualifier to specify interfaces so that data passed to functions using pointers and references isn't modified. The value of a const can be calculated at run time.

constexpr
meaning roughly ‘‘to be evaluated at compile time.’’ This is used primarily to specify constants, to allow placement of data in read-only memory (where it is unlikely to be corrupted), and for performance. The value of a constexpr must be calculated by the compiler.



Constant Expressions
C++ requires constant expressions — expressions that evaluate to a constant at compile time — for declarations of:
    Array bounds
    Selectors in case statements
    Bit-field length specification
    Enumeration initializers

The only operands that are legal in constant expressions are:
    Literals
    Enumeration constants
    Values declared as const that are initialized with constant expressions
    sizeof expressions

Constant expressions are used mainly to replace manually computed values in your code. This generally produces code that is more robust and easier to understand, because you can eliminate so-called magic values—manually calculated constants copy and pasted directly into source code.


For more information see:
[https://en.cppreference.com/w/cpp/language/constant_expression]
