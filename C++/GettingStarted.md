https://code.visualstudio.com/docs/cpp/config-wsl


https://cppreference.com

Compile and linker overview

through programs designated as C++ compilers and linkers text becomes executable

Text, or code, begins with a source code file
a source code file must be properly formatted according to language syntax and semantics


source code files are input into a compiler
if improperly formatted the compiler will produce and error message
if properly formatted the compiler will output a transformation called an object file

All object files made from individual source files then need to be made into a single executable

a linker is used to link object files together
if it can't link the object files it will produce an error message
if it can, the object files are linked together to create an executable file

the executable can then be run


Syntax and semantics
While there is no single organization the controls all of C++, individual vendors and communities implement the ISO standard which determines the syntax and semantics of the C++ language
The ISO committee updates the standard every three years
always used the most recent implementation of the standard



Tools
Bare minimum
text editor
compiler (gcc, clang, etc)
linker

Nice additions
Integrated Development Environment:
  code-aware editor
  debugger
  code-specific tools

Libraries and Frameworks



smallest valid program

int main() {}

save to .cpp file extension

use console to navigate to containing folder, then run:
g++ [filename].cpp

this will compile to an a.out
a.out is a file format used in older versions of Unix-like computer operating systems for executables, object code, and, in later systems, shared libraries. This is an abbreviated form of "assembler output", the filename of the output of Ken Thompson's PDP-7 assembler.

to execute run:
./a.out

to name the file something other than a.out run:
g++ -o [executable name] [filename].cpp
