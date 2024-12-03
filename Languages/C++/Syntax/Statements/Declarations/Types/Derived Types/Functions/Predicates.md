A predicate is a function that returns a bool result. These
functions have many uses in the standard library.
For example, the sort function sorts values in ascending order. What if you wanted to sort data in
descending order? The sort function lets you provide a predicate to compare items. The ordering predicate
(call it pred) must meet the following qualifications:

• pred(a, a) must be false (a common error is to implement <= instead of <, which violates this requirement).

• If pred(a, b) is true, and pred(b, c) is true, then pred(a, c) must also be true.

• The parameter types must match the element type to be sorted.

• The return type must be bool or something that C++ can convert automatically to bool.

```cpp
/** Listing 22-4. Sorting into Descending Order */
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

/** Predicate for sorting into descending order. */
int descending(int a, int b)
{
  return a > b;
}

int main()
{
  std::vector<int> data{std::istream_iterator<int>(std::cin),
                        std::istream_iterator<int>()};

  std::ranges::sort(data, descending);

  std::ranges::copy(data, std::ostream_iterator<int>(std::cout, "\n"));
}
```
