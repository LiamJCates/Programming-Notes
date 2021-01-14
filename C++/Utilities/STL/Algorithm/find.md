Using std::find to find an element by value

std::find searches for the first occurrence of a value in a container. std::find takes 3 parameters: an iterator to the starting element in the sequence, an iterator to the ending element in the sequence, and a value to search for. It returns an iterator pointing to the element (if it is found) or the end of the container (if the element is not found).

For example:

#include <algorithm>
#include <array>
#include <iostream>

int main()
{
  std::array arr{ 13, 90, 99, 5, 40, 80 };

  std::cout << "Enter a value to search for and replace with: ";  
  int search{};
  int replace{};
  std::cin >> search >> replace;

  // Input validation omitted

  // std::find returns an iterator pointing to the found element (or the end of the container)
  // we'll store it in a variable, using type inference to deduce the type of
  // the iterator (since we don't care)
  auto found{ std::find(arr.begin(), arr.end(), search) };

  // Algorithms that don't find what they were looking for return the end iterator.
  // We can access it by using the end() member function.
  if (found == arr.end())
  {
    std::cout << "Could not find " << search << '\n';
  }
  else
  {
    // Override the found element.
    *found = replace;
  }

  for (int i : arr)
  {
    std::cout << i << ' ';
  }

  std::cout << '\n';

  return 0;
}

Sample run when the element is found

Enter a value to search for and replace with: 5 234
13 90 99 234 40 80

Sample run when the element isn’t found

Enter a value to search for and replace with: 0 234
Could not find 0
13 90 99 5 40 80

Using std::find_if to find an element that matches some condition

Sometimes we want to see if there is a value in a container that matches some condition (e.g. a string that contains a specific substring) rather than an exact value. In such cases, std::find_if is perfect. The std::find_if function works similarly to std::find, but instead of passing in a value to search for, we pass in a callable object, such as a function pointer (or a lambda, which we’ll cover later) that checks to see if a match is found. std::find_if will call this function for every element until a matching element is found (or no more elements remain in the container to check).

Here’s an example where we use std::find_if to check if any elements contain the substring “nut”:

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

// Our function will return true if the element matches
bool containsNut(std::string_view str)
{
  // std::string_view::find returns std::string_view::npos if it doesn't find
  // the substring. Otherwise it returns the index where the substring occurs
  // in str.
  return (str.find("nut") != std::string_view::npos);
}

int main()
{
  std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

  // Scan our array to see if any elements contain the "nut" substring
  auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

  if (found == arr.end())
  {
    std::cout << "No nuts\n";
  }
  else
  {
    std::cout << "Found " << *found << '\n';
  }

  return 0;
}

Output

Found walnut

If you were to write the above example by hand, you’d need at least three loops (one to loop through the array, and two to match the substring). The standard library functions allow us to do the same thing in just a few lines of code!
