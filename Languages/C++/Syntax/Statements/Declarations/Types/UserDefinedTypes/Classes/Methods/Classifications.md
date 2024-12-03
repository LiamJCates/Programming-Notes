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


The inline keyword is a hint to the compiler that it should optimize speed over size by trying to expand a function at its point of call. You can use inline with member functions too. Indeed, for trivial functions, such as those that return a data member and do nothing else, making the function inline can improve speed and program size. When you define a function inside the class definition, the compiler automatically adds the inline keyword. If you separate the definition from the declaration, you can still make the function inline by adding the inline keyword to the function declaration or definition. Common practice is to place the inline keyword only on the definition, but I recommend putting the keyword in both places, to help the human reader. Remember that inline is just a hint. The compiler does not have to heed the hint. Modern compilers are becoming better and better at making these decisions for themselves. My personal guideline is to define one-line functions in the class definition. Longer functions or functions that are complicated to read usually belong outside the class definition. Some functions are too long to fit in the class definition but are short and simple enough that they should be inline. Organizational coding styles usually include guidelines for inline functions. For example, directives for large projects may eschew inline functions because they increase coupling between software components. Thus, inline may be allowed only on a function-by-function basis, when performance measurements demonstrate their need.

Don’t agonize over deciding which functions should be inline. When in doubt, don’t bother. Make
functions inline only if performance measures show that the function is called often and the function call
overhead is significant. In all other aspects, I regard the matter as one of aesthetics and clarity: I find one-line
functions are easier to read when they are inside the class definition.

### const
The const specifiers on the functions indicate that a function does not modify the object for which it is called. A const member function can be invoked for both const and non-const objects, but a non-const member function can only be invoked for non-const objects.

It is generally recommended that all methods be marked const if they can be.


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
