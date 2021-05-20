To demonstrate a simple C++ program we must create then compile some source code text.

C++ is a compiled language, this means, for a program to run, its source code has to be processed by a compiler.

For more information about compilation see:
[C++\Compiler.md]

### Smallest Valid Program

```cpp
int main() {}
```
above is the smallest valid C++ program. The contents do not matter for this example as we are only using this to show the compilation process.


C++ source code files use the .cpp file extension save the above text as:

  [filename].cpp

where filename is the desired name of our program, TestCompile.cpp could be used, for example.

use console to navigate to the folder that contains the file, then run:

  g++ [filename].cpp

this will compile an a.out, a.out is a file format used in older versions of Unix-like computer operating systems for executables, object code, and, in later systems, shared libraries. This is an abbreviated form of "assembler output", the filename of the output of Ken Thompson's PDP-7 assembler.

run using the C++ program using:

  ./a.out

to name the file something other than a.out specify the -o flag and provide a desired executable name:

  g++ -o [executable name] [filename].cpp

then run using:

  ./[executable name]



The previous program, while a complete program, will produce no obvious effect, to ensure that you have correctly formatted, compiled, and executed a C++ program copy and paste the following text and repeat the process above:

```cpp
 #include <iostream>

 int main() {std::cout << "Hello world" << std::endl;}
```


A note on file type extensions
Several different file-name extensions are popular for C++ programs. I like to use .cpp, where the p means “plus.” Other common extensions are .cxx and .cc. Some compilers recognize .C (uppercase C) as a C++ file extension, but I don’t recommend using it, because it is too easy to confuse with .c (lowercase c), the default extension for C programs. Many desktop environments do not distinguish between uppercase and lowercase file names, further compounding the problem. Pick your favorite and stick with it.
