### Type of a lambda

Above the keyword auto is used to perform type deduction to store the lambda variable. This begs the question, what is the type of a lambda?

As it turns out, lambdas don’t have a type that we can explicitly use. When we write a lambda, the compiler generates a unique type just for the lambda that is not exposed to us.

In actuality, lambdas aren’t functions (which is part of how they avoid the limitation of C++ not supporting nested functions). They’re a special kind of object called a functor. Functors or function objects, contain an overloaded operator() that make them callable like a function making the underlying system implementation of lambdas more closely related to that of function objects, not functions.

Although we don’t know the type of a lambda, there are several ways of storing a lambda for use post-definition.

If the lambda has an empty capture clause, we can use a regular function pointer. If the lambda hase a non-empty capture clause a function pointer won’t work anymore at that point. However, std::function can be used.

  #include <functional>

  int main()
  {
    // A regular function pointer. Only works with an empty capture clause.
    double (*addNumbers1)(double, double){
      [](double a, double b) {
        return (a + b);
      }
    };

    addNumbers1(1, 2);

    // Using std::function. The lambda could have a non-empty capture clause.
    std::function addNumbers2{
      // note: pre-C++17, use std::function<double(double, double)>
      [](double a, double b) {
        return (a + b);
      }
    };

    addNumbers2(3, 4);

    // Using auto. Stores the lambda with its real type.
    auto addNumbers3{
      [](double a, double b) {
        return (a + b);
      }
    };

    addNumbers3(5, 6);

    return 0;
  }

The only way of using the lambda’s actual type is by means of auto. auto also has the benefit of having no overhead compared to std::function.

Unfortunately, we can’t always use auto. In cases where the actual lambda is unknown (e.g. because we’re passing a lambda to a function as a parameter and the caller determines what lambda will be passed in), we can’t use auto. In such cases, std::function should be used.

  #include <functional>
  #include <iostream>

  // We don't know what fn will be. std::function works with regular functions and lambdas.
  void repeat(int repetitions, const std::function<void(int)>& fn)
  {
    for (int i{ 0 }; i < repetitions; ++i)
      fn(i);
  }

  int main()
  {
    repeat(3, [](int i) {
      std::cout << i << '\n';
    });

    return 0;
  }

Output

  0
  1
  2

Rule
Use auto when initializing variables with lambdas, and std::function if you can’t initialize the variable with the lambda.



### constexpr Lambda Expressions

All lambda expressions are constexpr as long as the lambda can be invoked at compile time. You can optionally make the constexpr declaration explicit:

  [] (int x) constexpr { return x * x; }

You should mark a lambda constexpr if you want to make sure that it meets all constexpr requirements. As of C++17, this means no dynamic memory allocations and no calling non-constexpr functions, among other restrictions. The standards committee plans to loosen these restrictions with each release, so if you write a lot of code using constexpr, be sure to brush up on the latest constexpr constraints.
