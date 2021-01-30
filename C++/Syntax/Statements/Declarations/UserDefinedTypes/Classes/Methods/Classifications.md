### Accessor
A member function of a class that only accesses (that is, does not modify) the value(s) of the member variable(s).

### Mutator
A member function of a class that modifies the value(s) of the member variable(s).




### Outer Declaration
We may declare a method prototype within a class, but its definition outside it. In this outside definition, the operator of scope (::) is used to specify that the function being defined is a member of the class and not a regular non-member function.

The scope operator (::) specifies the class to which the member being defined belongs, granting exactly the same scope properties as if this function definition was directly included within the class definition.

### Inline
The only difference between defining a member function completely within the class definition or to just include its declaration in the function and define it later outside the class, is that in the first case the function is automatically considered an inline member function by the compiler, while in the second it is a normal (not-inline) class member function. This causes no differences in behavior, but only on possible compiler optimizations.

C++ inline function is a powerful concept that is commonly used with classes. If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time.

A function definition in a class definition is an inline function definition by default.

### const
The const specifiers on the functions indicate that a function does not modify the object for which it is called. A const member function can be invoked for both const and non-const objects, but a non-const member function can only be invoked for non-const objects.


### constexpr
It is possible to define a constructor as a constant expression too, using keyword constexpr. In special cases where such a construct would be useful from a performance point of view, you would use it at the constructor declaration.

  class Sample {
    const char* someString;
  public:
    constexpr Sample(const char* input) :someString(input)
    { // constructor code }
  };



constexpr offers a powerful way to improve the performance of your C++ application.

By marking functions that operate on constants or const-expressions as constexpr, we are instructing the compiler to evaluate those functions and insert their result instead of inserting instructions that compute the result when the application is executed.

This keyword can also be used with classes and objects that evaluate as constants.
