Using std::sort to custom sort

We previously used std::sort to sort an array in ascending order, but std::sort can do more than that. There’s a version of std::sort that takes a function as its third parameter that allows us to sort however we like. The function takes two parameters to compare, and returns true if the first argument should be ordered before the second. By default, std::sort sorts the elements in ascending order.

sort() sorts the sequence defined by the pair of iterators collection.begin() and collection.end()

Let’s use std::sort to sort an array in reverse order using a custom comparison function named greater:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26

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

Output

99 90 80 40 13 5

Once again, instead of writing our own custom loop functions, we can sort our array however we like in just a few lines of code!

Our greater function needs 2 arguments, but we’re not passing it any, so where do they come from? When we use a function without parentheses (), it’s only a function pointer, not a call. You might remember this from when we tried to print a function without parentheses and std::cout printed “1”. std::sort uses this pointer and calls the actual greater function with any 2 elements of the array. We don’t know which elements greater will be called with, because it’s not defined which sorting algorithm std::sort is using under the hood. We talk more about function pointers in a later chapter.

Tip
Because sorting in descending order is so common, C++ provides a custom type (named std::greater) for that too (which is part of the functional header). In the above example, we can replace:

1

  std::sort(arr.begin(), arr.end(), greater); // call our custom greater function

with:

1
2
3

  std::sort(arr.begin(), arr.end(), std::greater{}); // use the standard library greater comparison
  // Before C++17, we had to specify the element type when we create std::greater
  std::sort(arr.begin(), arr.end(), std::greater<int>{}); // use the standard library greater comparison

Note that the std::greater{} needs the curly braces because it is not a callable function. It’s a type, and in order to use it, we need to instantiate an object of that type. The curly braces instantiate an anonymous object of that type (which then gets passed as an argument to std::sort).

For advanced readers
To further explain how std::sort uses the comparison function, we’ll have to take a step back to a modified version of the selection sort example from lesson 9.4 -- Sorting an array using selection sort.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38

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

So far, this is nothing new and sort always sorts elements from low to high. To add a comparison function, we have to use a new type, std::function, to store a function that takes 2 int parameters and returns a bool. Treat this type as magic for now, we will explain it in chapter 7.

1

void sort(int *begin, int *end, std::function<bool(int, int)> compare)

We can now pass a comparison function like greater to sort, but how does sort use it? All we need to do is replace the line
1

if (*currentElement < *smallestElement)

with
1

if (compare(*currentElement, *smallestElement))

Now the caller of sort can chose how to compare two elements.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44

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
