Using std::count and std::count_if to count how many occurrences there are

std::count and std::count_if search for all occurrences of an element or an element fulfilling a condition.

In the following example, we’ll count how many elements contain the substring “nut”:

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

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

bool containsNut(std::string_view str)
{
  return (str.find("nut") != std::string_view::npos);
}

int main()
{
  std::array<std::string_view, 5> arr{ "apple", "banana", "walnut", "lemon", "peanut" };

  auto nuts{ std::count_if(arr.begin(), arr.end(), containsNut) };

  std::cout << "Counted " << nuts << " nut(s)\n";

  return 0;
}

Output

Counted 2 nut(s)
