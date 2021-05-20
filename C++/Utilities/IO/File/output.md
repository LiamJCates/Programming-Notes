o write to a file, you define an ofstream object. To open the file, simply
name the file in the variable’s initializer. If the file does not exist, it will be created. If the file does exist, its old
contents are discarded in preparation for writing new contents. If the file cannot be opened, the ofstream
object is left in an error state, so remember to test it before you try to use it. Use an ofstream object the same
way you use std::cout.

```cpp
//Copying Integers from a Named File to a Named File
#include <cerrno>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <system_error>

int main()
{
  std::ifstream in{"list1402.in"};
  if (not in)
    std::cerr << "list1402.in: " <<
      std::generic_category().message(errno) << '\n';
  else
  {
    std::ofstream out{"list1402.out"};
    if (not out)
      std::cerr << "list1402.out: " <<
        std::generic_category().message(errno) << '\n';
    else
    {
      std::ranges::copy(std::ranges::istream_view<int>(in),
        std::ostream_iterator<int>{out, "\n"});
      out.close();
      in.close();
    }
  }
}
```

The program opens the input file first. If that succeeds, it opens the output file. If the order were
reversed, the program might create the output file, then fail to open the input file, and the result would be a
wasted, empty file. Always open input files first.

Also notice that the program does not close the input file, if it cannot open the output file. Don’t worry:
it closes the input file just fine. When in is destroyed at the end of main, the file is automatically closed.
I know what you’re thinking: if in is automatically closed, why call close at all? Why not let in close
automatically in all cases? For an input file, that’s actually okay. Feel free to delete the in.close();
statement from the program. For an output file, however, doing so is unwise.
Some output errors do not arise until the file is closed, and the operating system flushes all its internal
buffers and does all the other cleanup it needs to do when closing a file. Thus, an output stream object might
not receive an error from the operating system until you call close(). Detecting and handling these errors is
an advanced skill. The first step toward developing that skill is to adopt the habit of calling close() explicitly
for output files. When it comes time to add the error-checking, you will have a place where you can add it.



```cpp
/*Copying Integers, with Minimal Error-Checking */
#include <cerrno>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <system_error>

int main()
{
  std::ifstream in{"list1403.in"};
  if (not in)
    std::cerr << "list1403.in: " <<
      std::generic_category().message(errno) << '\n';
  else
  {
    std::ofstream out{"list1403.out"};
    if (out) {
      std::ranges::copy(std::ranges::istream_view<int>(in),
        std::ostream_iterator<int>{out, "\n"});
      out.close();
    }
    if (not out)
      std::cerr << "list1403.out: " <<
        std::generic_category().message(errno) << '\n';
  }
}
```

C++ offers a few different ways to check for output errors, but they all have drawbacks.
The easiest is to test whether the output stream is in an error state. You can check the stream after every
output operation, but that approach is cumbersome, and few people write code that way. Another way lets
the stream check for an error condition after every operation and alerts your program with an exception.
You’ll learn about this technique in Exploration 45. A frighteningly common technique is to ignore output
errors altogether. As a compromise, I recommend testing for errors after calling close().

Basic I/O is not difficult, but it can quickly become a morass of gooey, complicated code when you start
to throw in sophisticated error-handling, international issues, binary I/O, and so on.
