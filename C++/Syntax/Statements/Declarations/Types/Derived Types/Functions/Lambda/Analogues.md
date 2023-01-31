### Analogue Example

Defined below are a conceptually similar function, function object, and lambda expression definition which compute the frequency of a particular char in a null-terminated string.


#### Function Definition:

  size_t count_if(char x, const char* str) {
    size_t index{}, result{};

    while (str[index])
      if (str[index++] == x) result++;

    return result;
  }

  void funcTest()
  {
    auto sally = count_if('s', "Sally sells seashells by the seashore.");
    printf("Sally: %zd\n", sally);
    auto sailor = count_if('s', "Sailor went to sea to see what he could see.");
    printf("Sailor: %zd\n", sailor);
  }


#### Function Object Definition:

  struct CountIf
  {
    CountIf(char x) : x{x} {}

    size_t operator()(const char *str) const
    {
      size_t index{}, result{};

      while (str[index])
        if (str[index++] == x)
          result++;

      return result;
    }
  private:
    const char x;
  };

  void objTest()
  {
    CountIf s_counter{ 's' };
    auto sally = s_counter("Sally sells seashells by the seashore.");
    printf("Sally: %zd\n", sally);
    auto sailor = s_counter("Sailor went to sea to see what he could see.");
    printf("Sailor: %zd\n", sailor);
  }

#### Lambda Definition:

  void lambdaTest()
  {
    char to_count{ 's' };
    auto s_counter = [to_count](const char* str)
    {
      size_t index{}, result{};

      while (str[index])
        if (str[index++] == to_count) result++;

      return result;
    };

    auto sally = s_counter("Sally sells seashells by the seashore.");
    printf("Sally: %zd\n", sally);
    auto sailor = s_counter("Sailor went to sea to see what he could see.");
    printf("Sailor: %zd\n", sailor);
  }

#### Usage Test

  int main()
  {
    //function usage
    funcTest();

    //function object usage
    objTest();

    //lambda usage
    lambdaTest();
  }

Output:

  Sally: 7
  Sailor: 3
  Sally: 7
  Sailor: 3
  Sally: 7
  Sailor: 3

Each lambda component has a direct analogue within the function and function object. To form a bridge between these consider:
  The parameters in the function and member variables set in the CountIf constructor have an analog in the lambda’s capture.
  The function and function-call operator’s arguments, body, and return type are analogous to the lambda’s parameters, body, and return type.
  The modifiers applied to the function signature and function-call operator are analogous to those of the lambda.

Due to these nearly direct analogues, a lambda is sometimes called a function literal.



### Standard library function objects

For common operations (e.g. addition, negation, or comparison) you don’t need to write your own lambdas, because the standard library comes with many basic callable objects that can be used instead. These are defined in the <functional> header.

In the following example:

  #include <algorithm>
  #include <array>
  #include <iostream>

  bool greater(int a, int b)
  {
    return (a > b);
  }

  int main()
  {
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    // Pass greater to std::sort
    std::sort(arr.begin(), arr.end(), greater);

    for (int i : arr)
    {
      std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
  }

Output

  99 90 80 40 13 5

Instead of converting our greater function to a lambda (which would obscure its meaning a bit), we can instead use std::greater:

  #include <algorithm>
  #include <array>
  #include <iostream>
  #include <functional> // for std::greater

  int main()
  {
    std::array arr{ 13, 90, 99, 5, 40, 80 };

    // Pass std::greater to std::sort
    std::sort(arr.begin(), arr.end(), std::greater{}); // note: need curly braces to instantiate object

    for (int i : arr)
    {
      std::cout << i << ' ';
    }

    std::cout << '\n';

    return 0;
  }

Output

  99 90 80 40 13 5

Conclusion

Lambdas and the algorithm library may seem unnecessarily complicated when compared to a solution that uses a loop. However, this combination can allow some very powerful operations in just a few lines of code, and can be more readable than writing your own loops. On top of that, the algorithm library features powerful and easy-to-use parallelism, which you won’t get with loops. Upgrading source code that uses library functions is easier than upgrading code that uses loops.

Lambdas are great, but they don’t replace regular functions for all cases. Prefer regular functions for non-trivial and reusable cases.
