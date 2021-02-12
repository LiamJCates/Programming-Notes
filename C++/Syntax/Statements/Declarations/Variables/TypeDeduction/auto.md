## auto
The new C++ standards have made it possible to use auto as a placeholder for types in various contexts and let the compiler deduce the actual type.

In C++11, auto can be used for declaring local variables and for the return type of a function with a trailing return type.

In C++14, auto can be used for the return type of a function without specifying a trailing type and for parameter declarations in lambda expressions.

Future standard versions are likely to expand the use of auto to even more cases.

We use auto where we don’t have a specific reason to mention the type explicitly.

‘‘Specific reasons’’ include:
  The definition is in a large scope where we want to make the type clearly visible to readers of our code.
  We want to be explicit about a variable’s range or precision (e.g., double rather than float).

Using auto, we avoid redundancy and writing long type names. This is especially important in generic programming where the exact type of an object can be hard for the programmer to know and the type names can be quite long.



## Definitions Using Auto
When defining a variable, you don’t need to state its type explicitly when it can be deduced from the initializer:

  auto b = true; // a bool
  auto ch = 'x'; // a char
  auto i = 123; // an int
  auto d = 1.2; // a double
  auto z = sqrt(y); // z has the type of whatever sqrt(y) returns
  auto bb {true}; // bb is a bool

With auto, we tend to use the = because there is no potentially troublesome type conversion involved, but if you prefer to use {} initialization consistently, you can do that instead.



### auto and Reference Types
It’s common to add modifiers like &, *, and const to auto. Such modifications add the intended meanings (reference, pointer, and const, respectively):

  auto year { 2019 };             // int
  auto& year_ref = year;          // int&
  const auto& year_cref = year;   // const int&
  auto\* year_ptr = &year;        // int*
  const auto\* year_cptr = &year; // const int*

Adding modifiers to the auto declaration behaves just as you’d expect: if you add a modifier, the resulting type is guaranteed to have that modifier.



### Using auto whenever possible

Automatic type deduction is one of the most important and widely used features in modern C++. The new C++ standards have made it possible to use auto as a placeholder for types in various contexts and let the compiler deduce the actual type as mentioned above.

The use of auto in these contexts has several important benefits. Developers should be aware of them, and prefer auto whenever possible.

An actual term was coined for this by Andrei Alexandrescu and promoted by Herb Sutter - almost always auto (AAA).


How to do it...

To declare local variables with the form:

  auto name = expression

Consider using auto as a placeholder for the actual type in the following situations:

  auto i = 42; // int
  auto d = 42.5; // double
  auto s = "text"; // char const *
  auto v = { 1, 2, 3 }; // std::initializer_list<int>

We declare local variables with the form:

  auto name = type-id { expression }

  auto b = new char[10]{ 0 }; // char*
  auto s1 = std::string {"text"}; // std::string
  auto v1 = std::vector<int> { 1, 2, 3 }; // std::vector<int>
  auto p = std::make_shared<int>(42); // std::shared_ptr<int>

We can declare named lambda functions, with the form:

  auto name = lambdaexpression

unless the lambda needs to be passed or return to a function:

  auto upper = [](char const c) {return toupper(c); };

To declare lambda parameters and return values:

  auto add = [](auto const a, auto const b) {return a + b;};

To declare function return type when you don't want to commit to a specific type:

  template <typename F, typename T>
  auto apply(F&& f, T value)
  {
    return f(value);
  }




TODO: More... Modern C++ Programming pg9




### auto Return Types
Functions that rely on automatic return type deduction need to be defined (i.e., implemented) before they’re invoked. This is because the compiler needs to know a function’s return type at the point where it is used. If such a function has multiple return statements, they need to all deduce to the same type. Recursive calls need to follow at least one return statement.

In C++14, the auto keyword was extended to be able to deduce a function’s return type from return statements in the function body.

There are two ways to declare the return value of a function:
  Lead a function declaration with its return.
  Have the compiler deduce the correct return type by using auto.

As with auto type deduction, the compiler deduces the return type, fixing the runtime type:

  auto my-function(arg1-type arg1, arg2-type arg2, ...) {
    // return any type and the
    // compiler will deduce what auto means
  }

This feature should be used judiciously. Because function definitions are documentation, it’s best to provide concrete return types when available.

Consider the following program:

  auto add(int x, int y)
  {
      return x + y;
  }

Since x + y evaluates to an int, the compiler will deduce this function should have a return type of int. When using an auto return type, all return statements must return the same type, otherwise an error will result.

While this may seem neat, we recommend that this syntax be avoided for normal functions. The return type of a function is of great use in helping to document for the caller what a function is expected to return. When a specific type isn’t specified, the caller may misinterpret what type the function will return, which can lead to inadvertent errors.



## Best practice

Avoid using type inference for function return types.

Interested readers may wonder why using auto when initializing variables is okay, but not recommended for function return types. A good rule of thumb is that auto is okay to use when defining a variable, because the object the variable is inferring a type from is visible on the right side of the statement. However, with functions, that is not the case -- there’s no context to help indicate what type the function returns. A user would actually have to dig into the function body itself to determine what type the function returned. It’s much less intuitive, and therefore more error prone.



### auto and Function Templates

The primary use case for auto type deduction is with function templates, where a return type can depend (in potentially complicated ways) on the template parameters.

It’s possible to extend the auto-return-type deduction syntax to provide the return type as a suffix with the arrow operator ->. This way, you can append an expression that evaluates to the function’s return type:

  auto my-function(arg1-type arg1, arg2-type arg2, ...) -> type-expression {
    // return an object with type matching
    // the type-expression above
  }



### Trailing return type syntax

The auto keyword can also be used to declare functions using a trailing return syntax, where the return type is specified after the rest of the function prototype.

Consider the following function:

  int add(int x, int y)
  {
    return (x + y);
  }

Using auto, this could be equivalently written as:

  auto add(int x, int y) -> int
  {
    return (x + y);
  }

In this case, auto does not perform type inference -- it is just part of the syntax to use a trailing return type.

Why would you want to use this?

One nice thing is that it makes all of your function names line up:

  auto add(int x, int y) -> int;
  auto divide(double x, double y) -> double;
  auto printSomething() -> void;
  auto generateSubstring(const std::string &s, int start, int len) -> std::string;

we’ll see this trailing return type syntax crop up in lambda functions.



### Type inference for function parameter types

Starting in C++20, the auto keyword can be used as a shorthand way to create function templates, so the below code will compile and run.

  #include <iostream>

  void addAndPrint(auto x, auto y) // only valid starting in C++20
  {
    std::cout << x + y;
  }

  int main()
  {
    addAndPrint(2, 3); // int
    addAndPrint(4.5, 6.7); // double
  }

Prior to C++20, this won’t work, because the compiler can’t infer types for function parameters x and y at compile time. Pre-C++20, if you’re looking to create generic functions that work with a variety of different types, you should be using function templates, not type inference.
