Using std::for_each to do something to all elements of a container

std::for_each takes a list as input and applies a custom function to every element. This is useful when we want to perform the same operation to every element in a list.

Here’s an example where we use std::for_each to double all the numbers in an array:

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

#include <algorithm>
#include <array>
#include <iostream>

void doubleNumber(int &i)
{
  i *= 2;
}

int main()
{
  std::array arr{ 1, 2, 3, 4 };

  std::for_each(arr.begin(), arr.end(), doubleNumber);

  for (int i : arr)
  {
    std::cout << i << ' ';
  }

  std::cout << '\n';

  return 0;
}

Output

2 4 6 8

This often seems like the most unnecessary algorithm to new developers, because equivalent code with a range-based for-loop is shorter and easier. But there are benefits to std::for_each. Let’s compare std::for_each to a range-based for-loop.

1
2
3
4
5
6
7

std::ranges::for_each(arr, doubleNumber); // Since C++20, we don't have to use begin() and end().
// std::for_each(arr.begin(), arr.end(), doubleNumber); // Before C++20

for (auto& i : arr)
{
  doubleNumber(i);
}

With std::for_each, our intentions are clear. Call doubleNumber with each element of arr. In the range-based for-loop, we have to add a new variable, i. This leads to several mistakes that a programmer could do when they’re tired or not paying attention. For one, there could be an implicit conversion if we don’t use auto. We could forget the ampersand, and doubleNumber wouldn’t affect the array. We could accidentally pass a variable other than i to doubleNumber. These mistakes cannot happen with std::for_each.

Additionally, std::for_each can skip elements at the beginning or end of a container, for example to skip the first element of arr, std::next can be used to advance begin to the next element.

1
2

std::for_each(std::next(arr.begin()), arr.end(), doubleNumber);
// Now arr is [1, 4, 6, 8]. The first element wasn't doubled.

This isn’t possible with a range-based for-loop.

Like many algorithms, std::for_each can be parallelized to achieve faster processing, making it better suited for large projects and big data than a range-based for-loop.
