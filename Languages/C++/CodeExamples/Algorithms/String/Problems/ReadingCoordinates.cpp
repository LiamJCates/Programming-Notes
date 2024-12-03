/** Listing 17-3. Reading and Writing Points */
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

int main()
{
  using intvec = std::vector<int>;
  intvec xs{}, ys{};        // store the x's and y's

  char sep{};
  // Loop while the input stream has an integer (x), a character (sep),
  // and another integer (y); then test that the separator is a comma.
  for (int x{},y{}; std::cin >> x >> sep and sep == ',' and std::cin >> y;)
  {
    xs.emplace_back(x);
    ys.emplace_back(y);
  }

  for (auto x{xs.begin()}, y{ys.begin()}; x != xs.end(); ++x, ++y)
    std::cout << *x << ',' << *y << '\n';
}

/*
The first for loop is the key. The loop condition reads an integer and a character and tests to determine
if the character is a comma, before reading a second integer. The loop terminates if the input is invalid or
ill-formed or if the loop reaches the end-of-file. 
*/
