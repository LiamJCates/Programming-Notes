### Lambda Parameters and Bodies

Lambda expressions produce function objects. As function objects, lambdas are callable. Most of the time, you’ll want your function object to accept parameters upon invocation. Just like a function, all of the parameters have function scope.

You declare lambda parameters using essentially the same syntax that you use for functions.

For example, the following lambda expression yields a function object
that will square its int argument:

  [](int x) { return x*x; }

The lambda takes a single int x and uses it within the lambda’s body to
perform the squaring.
```cpp
  #include <cstdio>
  #include <cstdint>

  template <typename Fn>
  void transform(Fn fn, const int* in, int* out, size_t length) {
    for(size_t i{}; i<length; i++)
      out[i] = fn(in[i]);
  }

  int main() {
    const size_t len{ 3 };
    int base[]{ 1, 2, 3 }, a[len], b[len], c[len];

    transform([](int x) { return 1; }, base, a, len);
    transform([](int x) { return x; }, base, b, len);
    transform([](int x) { return 10*x+5; }, base, c, len);

    for (size_t i{}; i < len; i++)
      printf("Element %zd: %d %d %d\n", i, a[i], b[i], c[i]);
  }
```
Output:
```
Element 0: 1 1 15
Element 1: 1 2 25
Element 2: 1 3 35
```
The transform template function accepts four arguments: a function object fn, an in array, an out array, and the corresponding length of those arrays. Within transform, you invoke fn on each element of in and assign the result to the corresponding element of out.


The first call to transform passes a lambda ([](int x) { return 1; }) that always returns 1, and the result is stored into a.

The second call to transform ([](int x) { return x; }) simply returns its argument x, and the result is stored into b.

The third call to transform multiplies the argument by 10 and adds 5. The result is stored in c.


Notice that transform is declared as a template function, allowing it's reuse with any function object.


Example using C++20 features
 
```cpp
#include <iostream>
#include <iterator>
#include <ranges>

int main()
{
   auto data{ std::ranges::istream_view<int>(std::cin)
              | std::views::transform([](int i) { return i * 2; })
              | std::views::transform([](int i) { return i + 3; })
   };
   for (auto element : data)
      std::cout << element << '\n';
}
```

### Default Arguments
You can provide default arguments to a lambda. Default lambda parameters
behave just like default function parameters, using the operator =. The caller can specify values for default parameters, in which case the lambda uses the caller-provided values. If the caller doesn’t specify a value, the lambda uses the default.
