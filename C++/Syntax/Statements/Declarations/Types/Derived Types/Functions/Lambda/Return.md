## Lambda Return Types

The compiler deduces a lambda’s return type for you.

To take over from the compiler we specify a trailing return type using the arrow -> syntax:

[](int x, double y) -> double { return x + y; }

This lambda expression accepts an int and a double and returns a double. You can also use decltype expressions:

[](auto x, double y) -> decltype(x+y) { return x + y; }

Here you’ve explicitly declared that the return type of the lambda is whatever type results from adding an x to a y. You’ll rarely need to specify a lambda’s return type explicitly.



### Return type deduction and trailing return types

If return type deduction is used, a lambda’s return type is deduced from the return-statements inside the lambda. If return type inference is used, all return statements in the lambda must return the same type (otherwise the compiler won’t know which one to prefer).

For example:

  #include <iostream>

  int main()
  {
    auto divide{ [](int x, int y, bool bInteger) { // note: no specified return type
      if (bInteger)
        return x / y;
      else
        return static_cast<double>(x) / y; // ERROR: return type doesn't match previous return type
    } };

    std::cout << divide(3, 2, true) << '\n';
    std::cout << divide(3, 2, false) << '\n';

    return 0;
  }

This produces a compile error because the return type of the first return statement (int) doesn’t match the return type of the second return statement (double).

In the case where we’re returning different types, we have two options:
  1) Do explicit casts to make all the return types match, or
  2) explicitly specify a return type for the lambda, and let the compiler do implicit conversions.

The second case is usually the better choice:

  #include <iostream>

  int main()
  {
    // note: explicitly specifying this returns a double
    auto divide{ [](int x, int y, bool bInteger) -> double {
      if (bInteger)
        return x / y; // will do an implicit conversion to double
      else
        return static_cast<double>(x) / y;
    } };

    std::cout << divide(3, 2, true) << '\n';
    std::cout << divide(3, 2, false) << '\n';

    return 0;
  }

That way, if you ever decide to change the return type, you (usually) only need to change the lambda’s return type, and not touch the lambda body.
