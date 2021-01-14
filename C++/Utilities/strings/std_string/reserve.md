### Reserve

Understanding of the reserve functionality

void string::reserve()
void string::reserve(size_type unSize)

The second flavor of this function sets the capacity of the string to at least unSize (it can be greater). Note that this may require a reallocation to occur.
If the first flavor of the function is called, or the second flavor is called with unSize less than the current capacity, the function will try to shrink the capacity to match the length. This is a non-binding request.

  string sString("01234567");
  cout << "Length: " << sString.length() << endl;
  cout << "Capacity: " << sString.capacity() << endl;

  sString.reserve(200);
  cout << "Length: " << sString.length() << endl;
  cout << "Capacity: " << sString.capacity() << endl;

  sString.reserve();
  cout << "Length: " << sString.length() << endl;
  cout << "Capacity: " << sString.capacity() << endl;

Output:

Length: 8
Capacity: 15
Length: 8
Capacity: 207
Length: 8
Capacity: 207

This example shows two interesting things. First, although we requested a capacity of 200, we actually got a capacity of 207. The capacity is always guaranteed to be at least as large as your request, but may be larger. We then requested the capacity change to fit the string. This request was ignored, as the capacity did not change.

If you know in advance that you’re going to be constructing a large string by doing lots of string operations that will add to the size of the string, you can avoid having the string reallocated multiple times by immediately setting the string to its final capacity:


  #include <iostream>
  #include <string>
  #include <cstdlib> // for rand() and srand()
  #include <ctime> // for time()

  using namespace std;

  int main()
  {
      std::srand(std::time(nullptr)); // seed random number generator

      string sString{}; // length 0
      sString.reserve(64); // reserve 64 characters

      // Fill string up with random lower case characters
      for (int nCount{ 0 }; nCount < 64; ++nCount)
          sString += 'a' + std::rand() % 26;

      cout << sString;
  }

The result of this program will change each time, but here’s the output from one execution:

wzpzujwuaokbakgijqdawvzjqlgcipiiuuxhyfkdppxpyycvytvyxwqsbtielxpy

Rather than having to reallocate sString multiple times, we set the capacity once and then fill the string up. This can make a huge difference in performance when constructing large strings via concatenation.
