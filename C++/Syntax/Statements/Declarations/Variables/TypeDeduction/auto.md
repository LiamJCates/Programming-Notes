## auto

When defining a variable, you don’t need to state its type explicitly when it can be deduced from the initializer:

  auto b = true; // a bool
  auto ch = 'x'; // a char
  auto i = 123; // an int
  auto d = 1.2; // a double
  auto z = sqrt(y); // z has the type of whatever sqr t(y) retur ns
  auto bb {true}; // bb is a bool

With auto, we tend to use the = because there is no potentially troublesome type conversion involved, but if you prefer to use {} initialization consistently, you can do that instead.



### auto and Reference Types
It’s common to add modifiers like &, *, and const to auto. Such modifications add the intended meanings (reference, pointer, and const, respectively):

  auto year { 2019 }; // int
  auto& year_ref = year; // int&
  const auto& year_cref = year; // const int&
  auto\* year_ptr = &year; // int*
  const auto\* year_cptr = &year; // const int*

Adding modifiers to the auto declaration behaves just as you’d expect: if you add a modifier, the resulting type is guaranteed to have that modifier.


We use auto where we don’t have a specific reason to mention the type explicitly. ‘‘Specific reasons’’ include:
  The definition is in a large scope where we want to make the type clearly visible to readers of our code.
  We want to be explicit about a variable’s range or precision (e.g., double rather than float).

Using auto, we avoid redundancy and writing long type names. This is especially important in generic programming where the exact type of an object can be hard for the programmer to know and the type names can be quite long.

### Using auto whenever possible
Automatic type deduction is one of the most important and widely used features in modern C++. The new C++ standards have made it possible to use auto as a placeholder for types in various contexts and let the compiler deduce the actual type. In C++11, auto can be used for declaring local variables and for the return type of a function with a trailing return type. In C++14, auto can be used for the return type of a function without specifying a trailing type and for parameter declarations in lambda expressions. Future standard versions are likely to expand the use of auto to even more cases. The use of auto in these contexts has several important benefits. Developers should be aware of them, and prefer auto whenever possible.

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

There are two ways to declare the return value of a function:
  Lead a function declaration with its return.
  Have the compiler deduce the correct return type by using auto.

As with auto type deduction, the compiler deduces the return type, fixing the runtime type:

  auto my-function(arg1-type arg1, arg2-type arg2, ...) {
    // return any type and the
    // compiler will deduce what auto means
  }

This feature should be used judiciously. Because function definitions are documentation, it’s best to provide concrete return types when available.



### auto and Function Templates

The primary use case for auto type deduction is with function templates, where a return type can depend (in potentially complicated ways) on the template parameters.

It’s possible to extend the auto-return-type deduction syntax to provide the return type as a suffix with the arrow operator ->. This way, you can append an expression that evaluates to the function’s return type:

  auto my-function(arg1-type arg1, arg2-type arg2, ...) -> type-expression {
    // return an object with type matching
    // the type-expression above
  }
