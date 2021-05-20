## References

A reference is an alias for a variable. When you declare a reference, you need to initialize it to a variable using the reference operator (&):

  VarType original = Value;
  VarType& ReferenceVariable = original;

In a declaration, the unary suffix & means ‘‘reference to.’’ A reference is similar to a pointer, except that you don’t need to use a prefix ∗ to access the value referred to by the reference.

NOTE
A reference must be initialized to a variable.
A reference cannot be made to refer to a different object after its initialization.



### Assignment to a reference

does not change what the reference refers to but assigns to the referenced object:
int x = 2;
int y = 3;
int& r = x; // r refers to x
int& r2 = y; // now r2 refers to y
r = r2; // read through r2, write through r: x becomes 3

Initialization differs from assignment. In general, for an assignment to work correctly, the assigned-to object must have a value. On the other hand, the task of initialization is to make an uninitialized piece of memory into a valid object. For almost all types, the effect of reading from or writing to an uninitialized variable is undefined. For built-in types, that’s most obvious for references:

  int x = 7;
  int& r {x};   // bind r to x (r refers to x)
  r = 7;        // assign to whatever r refers to
  int& r2;      // error : uninitialized reference
  r2 = 99;      // error : assign to whatever r2 refers to

Fortunately, we cannot have an uninitialized reference; if we could, then that r2=99 would assign 99 to some unspecified memory location; the result would eventually lead to bad results or a crash.

You can use = to initialize a reference but please don’t let that confuse you. For example:

  int& r = x; // bind r to x (r refers to x)

This is still initialization and binds r to x, rather than any form of value copy.


### References as shortcuts

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




### Using Keyword const on References

You might need to have references that are not allowed to change the value of the original variable being aliased. Using const when declaring such references is the way to achieve that:

  int original = 30;
  const int& constRef = original;

  // Illegal: constRef can’t change value in original
  constRef = 40;

  //  Illegal: ref2 is not const
  int& ref2 = constRef;

  // Legal
  const int& constRef2 = constRef;

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
