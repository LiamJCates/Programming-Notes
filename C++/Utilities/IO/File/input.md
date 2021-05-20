program that reads integers from a file named list1401.in and writes them,
one per line, to the standard output stream. If the program cannot open the file, it prints an error message.
```cpp
#include <cerrno>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <system_error>

int main()
{
  std::ifstream in{"list1401.in"};
  if (not in)
    std::cerr << "list1401.in: " <<
      std::generic_category().message(errno) << '\n';
  else
  {
    std::ranges::copy(std::ranges::istream_view<int>(in),
        std::ostream_iterator<int>{std::cout, "\n"});
    in.close();
  }
}
```
