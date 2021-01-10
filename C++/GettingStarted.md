To demonstrate a simple C++ program we must create then compile some source code text. C++ is a compiled language, this means, for a program to run, its source code has to be processed by a compiler.

For more information about compilation see:
[C++\Compiler.md]

### Smallest Valid Program

int main() {}

save to [filename].cpp
C++ files use the .cpp file extension

use console to navigate to containing folder, then run:
g++ [filename].cpp

this will compile an a.out, a.out is a file format used in older versions of Unix-like computer operating systems for executables, object code, and, in later systems, shared libraries. This is an abbreviated form of "assembler output", the filename of the output of Ken Thompson's PDP-7 assembler.

run using:
./a.out

to name the file something other than a.out specifie the -o flag and provide a desired executable name:
g++ -o [executable name] [filename].cpp

run using:
./[executable name]


The previous program, while a complete program, will produce no obvious effect, to ensure that you have correctly formatted, compiled, and executed a C++ program use:

 #include <iostream>

int main() {std::cout << "Hello world" << std::endl;}
