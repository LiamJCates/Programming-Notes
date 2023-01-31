### Generic Lambdas

Generic lambdas are lambda expression templates.

For the most part, lambda parameters work by the same rules as regular function parameters.

One notable exception is that since C++14 we’re allowed to use auto for parameters (note: in C++20, regular functions are able to use auto for parameters too). When a lambda has one or more auto parameter, the compiler will infer what parameter types are needed from the calls to the lambda.

Because lambdas with one or more auto parameter can potentially work with a wide variety of types, they are called generic lambdas.

When auto is specified for one or more parameters, rather than a concrete type, these auto types become template parameters, meaning the compiler will stamp out a custom instantiation of the lambda.

  #include <cstdio>
  #include <cstdint>

  template <typename Fn, typename T>
    void transform(Fn fn, const T* in, T* out, size_t len) {
      for(size_t i{}; i<len; i++) {
        out[i] = fn(in[i]);
      }
  }

  int main() {
    constexpr size_t len{ 3 };
    int base_int[]{ 1, 2, 3 }, a[len];
    float base_float[]{ 10.f, 20.f, 30.f }, b[len];

    auto translate = [](auto x) { return 10 * x + 5; };

    transform(translate, base_int, a, l);
    transform(translate, base_float, b, l);

    for (size_t i{}; i < l; i++) {
      printf("Element %zd: %d %f\n", i, a[i], b[i]);
    }
  }

Output:

  Element 0: 15 105.000000
  Element 1: 25 205.000000
  Element 2: 35 305.000000

A second template parameter to transform is used as the pointed-to type of in and out. This allows transform to use arrays of any type.

Two arrays with different pointed-to types, int and float, are declared

Next, you assign a generic lambda expression to translate x. This allows you to use the same lambda for each instantiation of transform: when you
instantiate with base_int and with base_float.

Without a generic lambda, parameter types must be declared explicitly, requiring multiple lambda declarations:

  transform([](int x) { return 10 * x + 5; }, base_int, a, l);
  transform([](double x) { return 10 * x + 5; }, base_float, b, l);





### Example

When used in the context of a lambda, auto is just a shorthand for a template parameter.

Let’s take a look at a generic lambda:

  #include <algorithm>
  #include <array>
  #include <iostream>
  #include <string_view>

  int main()
  {
    constexpr std::array months{ // pre-C++17 use std::array<const char*, 12>
      "January",
      "February",
      "March",
      "April",
      "May",
      "June",
      "July",
      "August",
      "September",
      "October",
      "November",
      "December"
    };

    // Search for two consecutive months that start with the same letter.
    const auto sameLetter{ std::adjacent_find(months.begin(), months.end(),
                                        [](const auto& a, const auto& b) {
                                          return (a[0] == b[0]);
                                        }) };

    // Make sure that two months were found.
    if (sameLetter != months.end())
    {
      // std::next returns the next iterator after sameLetter
      std::cout << *sameLetter << " and " << *std::next(sameLetter)
                << " start with the same letter\n";
    }

    return 0;
  }

Output:

  June and July start with the same letter

In the above example, we use auto parameters to capture our strings by const reference. Because all string types allow access to their individual characters via operator[], we don’t need to care whether the user is passing in a std::string, C-style string, or something else. This allows us to write a lambda that could accept any of these, meaning if we change the type of months later, we won’t have to rewrite the lambda.

However, auto isn’t always the best choice. Consider:

  #include <algorithm>
  #include <array>
  #include <iostream>
  #include <string_view>

  int main()
  {
    constexpr std::array months{ // pre-C++17 use std::array<const char*, 12>
      "January",
      "February",
      "March",
      "April",
      "May",
      "June",
      "July",
      "August",
      "September",
      "October",
      "November",
      "December"
    };

    // Count how many months consist of 5 letters
    const auto fiveLetterMonths{ std::count_if(months.begin(), months.end(),
                                         [](std::string_view str) {
                                           return (str.length() == 5);
                                         }) };

    std::cout << "There are " << fiveLetterMonths << " months with 5 letters\n";

    return 0;
  }

Output:

  There are 2 months with 5 letters

In this example, using auto would infer a type of const char*. C-style strings aren’t easy to work with (apart from using operator[]). In this case, we prefer to explicitly define the parameter as a std::string_view, which allows us to work with the underlying data much more easily (e.g. we can ask the string view for its length, even if the user passed in a C-style array).




### static variables

One thing to be aware of is that a unique lambda will be generated for each different type that auto resolves to. The following example shows how one generic lambda turns into two distinct lambdas:

  #include <algorithm>
  #include <array>
  #include <iostream>
  #include <string_view>

  int main()
  {
    // Print a value and count how many times print has been called.
    auto print{
      [](auto value) {
        static int callCount{ 0 };
        std::cout << callCount++ << ": " << value << '\n';
      }
    };

    print("hello"); // 0: hello
    print("world"); // 1: world

    print(1); // 0: 1
    print(2); // 1: 2

    print("ding dong"); // 2: ding dong

    return 0;
  }

Output

  0: hello
  1: world
  0: 1
  1: 2
  2: ding dong

In the above example, we define a lambda and then call it with two different parameters (a string literal parameter, and an integer parameter). This generates two different versions of the lambda (one with a string literal parameter, and one with an integer parameter).

Most of the time, this is inconsequential. However, note that if the generic lambda uses static duration variables, those variables are not shared between the generated lambdas.

We can see this in the example above, where each type (string literals and integers) has its own unique count! Although we only wrote the lambda once, two lambdas were generated -- and each has its own version of callCount. To have a shared counter between the two generated lambdas, we’d have to define a variable outside of the lambda that is captured by reference.
