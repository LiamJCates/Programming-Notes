Converting numbers to strings

One notable omission in the std::string class is the lack of ability to create strings from numbers. For example:

std::string sFour{ 4 };

The easiest way to convert numbers into strings is to involve the std::ostringstream class. std::ostringstream is already set up to accept input from a variety of sources, including characters, numbers, strings, etc…

It is also capable of outputting strings (either via the extraction operator>>, or via the str() function).

Here’s a simple solution for creating std::string from various types of inputs:

  #include <iostream>
  #include <sstream>
  #include <string>

  template <typename T>
  inline std::string ToString(T tX)
  {
    std::ostringstream oStream;
    oStream << tX;
    return oStream.str();
  }

  int main()
  {
    std::string sFour{ ToString(4) };
    std::string sSixPointSeven{ ToString(6.7) };
    std::string sA{ ToString('A') };
    std::cout << sFour << '\n';
    std::cout << sSixPointSeven << '\n';
    std::cout << sA << '\n';
  }

Output:

  4
  6.7
  A



Converting strings to numbers

Similar to the solution above:

  #include <iostream>
  #include <sstream>
  #include <string>

  template <typename T>
  inline bool FromString(const std::string& sString, T &tX)
  {
      std::istringstream iStream(sString);
      return !(iStream >> tX).fail(); // extract value into tX, return success or not
  }

  int main()
  {
      double dX;
      if (FromString("3.4", dX))
          cout << dX << '\n';
      if (FromString("ABC", dX))
          cout << dX << '\n';
  }

Output:

  3.4

Note that the second conversion failed and returned false.




Conversion to C-style arrays

Many functions (including all C functions) expect strings to be formatted as C-style strings rather than std::string. For this reason, std::string provides 3 different ways to convert std::string to C-style strings.
const char* string::c_str () const

    Returns the contents of the string as a const C-style string
    A null terminator is appended
    The C-style string is owned by the std::string and should not be deleted

  std::string sSource{ "abcdefg" };
  std::cout << std::strlen(sSource.c_str());

Output:

7

const char* string::data () const

    Returns the contents of the string as a const C-style string
    A null terminator is appended. This function performs the same action as c_str()
    The C-style string is owned by the std::string and should not be deleted

  std::string sSource{ "abcdefg" };
  const char *szString{ "abcdefg" };
  // memcmp compares the first n characters of two C-style strings and returns 0 if they are equal
  if (std::memcmp(sSource.data(), szString, sSource.length()) == 0)
      std::cout << "The strings are equal";
  else
      std::cout << "The strings are not equal";

Output:

The strings are equal

size_type string::copy(char *szBuf, size_type nLength) const
size_type string::copy(char *szBuf, size_type nLength, size_type nIndex) const

    Both flavors copy at most nLength characters of the string to szBuf, beginning with character nIndex
    The number of characters copied is returned
    No null is appended. It is up to the caller to ensure szBuf is initialized to NULL or terminate the string using the returned length
    The caller is responsible for not overflowing szBuf

Sample code:

  std::string sSource{ "sphinx of black quartz, judge my vow" };

  char szBuf[20];
  int nLength{ static_cast<int>(sSource.copy(szBuf, 5, 10)) };
  szBuf[nLength] = '\0';  // Make sure to terminate buffer string

  std::cout << szBuf << '\n';

Output:

black

Unless you need every bit of efficiency, c_str() is the easiest and safest of the three functions to use.



If you need a C-style string (a zero-terminated array of char), string offers read-only access to its contained characters.

s.c_str() returns a pointer to s’ characters


void print(const string& s)
{
  printf("For people who like printf: %s\n",s.c_str()); //
  cout << "For people who like streams: " << s << '\n';
}

A C string literal is by definition a const char∗.
To get a literal of type std::string use a s suffix:

auto s = "Cat"s; // a std::string
auto p = "Dog"; // a C-style string: a const char*

To use the s suffix, you need to use the namespace std::literals::string_literals
