
The std::ranges::sort function sorts stuff, as you can tell from the name. In some other object-oriented language, you might expect vector to have a sort() member function. Alternatively, the standard library could have a sort function that can sort anything the library can throw at it. The C++ library falls into the latter category.

The sort() function can sort almost anything that has a begin() and an end(). An additional requirement is to be able to access specific elements of the data. To get the third element, use data.at(2) because indexing is zero-based. That is, data.front() is similar to data.at(0) and data.back() is like data.at(data.size() - 1)



Using std::sort to custom sort

We previously used std::sort to sort an array in ascending order, but std::sort can do more than that. There’s a version of std::sort that takes a function as its third parameter that allows us to sort however we like. The function takes two parameters to compare, and returns true if the first argument should be ordered before the second. By default, std::sort sorts the elements in ascending order.

sort() sorts the sequence defined by the pair of iterators collection.begin() and collection.end()

Let’s use std::sort to sort an array in reverse order using a custom comparison function named greater:
```cpp
#include <algorithm>
#include <array>
#include <iostream>

bool greater(int a, int b)
{
  // Order @a before @b if @a is greater than @b.
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
```
Output
```
99 90 80 40 13 5
```
Once again, instead of writing our own custom loop functions, we can sort our array however we like in just a few lines of code!

Our greater function needs 2 arguments, but we’re not passing it any, so where do they come from? When we use a function without parentheses (), it’s only a function pointer, not a call. You might remember this from when we tried to print a function without parentheses and std::cout printed “1”. std::sort uses this pointer and calls the actual greater function with any 2 elements of the array. We don’t know which elements greater will be called with, because it’s not defined which sorting algorithm std::sort is using under the hood. We talk more about function pointers in a later chapter.

Tip
Because sorting in descending order is so common, C++ provides a custom type (named std::greater) for that too (which is part of the functional header). In the above example, we can replace:

```cpp
  std::sort(arr.begin(), arr.end(), greater); // call our custom greater function
```

with:
```cpp
  // use the standard library greater comparison
  std::sort(arr.begin(), arr.end(), std::greater{});
  //post C++17

  // use the standard library greater comparison
  std::sort(arr.begin(), arr.end(), std::greater<int>{});
  // preC++17 code, specifies the element type when we create std::greater
```

Note that the std::greater{} needs the curly braces because it is not a callable function. It’s a type, and in order to use it, we need to instantiate an object of that type. The curly braces instantiate an anonymous object of that type (which then gets passed as an argument to std::sort).






Since C++20 there is also std::ranges::sort















For advanced readers
To further explain how std::sort uses the comparison function, we’ll have to take a step back to a modified version of a selection sort.

```cpp
#include <iostream>
#include <iterator>
#include <utility>

void sort(int *begin, int *end)
{
  for (auto startElement{ begin }; startElement != end; ++startElement)
  {
    auto smallestElement{ startElement };

    // std::next returns a pointer to the next element, just like (startElement + 1) would.
    for (auto currentElement{ std::next(startElement) }; currentElement != end; ++currentElement)
    {
      if (*currentElement < *smallestElement)
      {
        smallestElement = currentElement;
      }
    }

    std::swap(*startElement, *smallestElement);
  }
}

int main()
{
  int array[]{ 2, 1, 9, 4, 5 };

  sort(std::begin(array), std::end(array));

  for (auto i : array)
  {
    std::cout << i << ' ';
  }

  std::cout << '\n';

  return 0;
}
```

So far, this is nothing new and sort always sorts elements from low to high. To add a comparison function, we have to use a new type, std::function, to store a function that takes 2 int parameters and returns a bool. Treat this type as magic for now, we will explain it in chapter 7.
```cpp
void sort(int *begin, int *end, std::function<bool(int, int)> compare)
```
We can now pass a comparison function like greater to sort, but how does sort use it? All we need to do is replace the line
```cpp
if (*currentElement < *smallestElement)
```
with

```cpp
if (compare(*currentElement, *smallestElement))
```


Now the caller of sort can chose how to compare two elements.

```cpp
#include <functional> // std::function
#include <iostream>
#include <iterator>
#include <utility>

// sort accepts a comparison function
void sort(int *begin, int *end, std::function<bool(int, int)> compare)
{
  for (auto startElement{ begin }; startElement != end; ++startElement)
  {
    auto smallestElement{ startElement };

    for (auto currentElement{ std::next(startElement) }; currentElement != end; ++currentElement)
    {
      // the comparison function is used to check if the current element should be ordered
      // before the currently "smallest" element.
      if (compare(*currentElement, *smallestElement))
      {
        smallestElement = currentElement;
      }
    }

    std::swap(*startElement, *smallestElement);
  }
}

int main()
{
  int array[]{ 2, 1, 9, 4, 5 };

  // use std::greater to sort in descending order
  // (We have to use the global namespace selector to prevent a collision
  // between our sort function and std::sort.)
  ::sort(std::begin(array), std::end(array), std::greater{});

  for (auto i : array)
  {
    std::cout << i << ' ';
  }

  std::cout << '\n';

  return 0;
}
```
