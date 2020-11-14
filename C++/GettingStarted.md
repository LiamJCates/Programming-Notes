https://cppreference.com

Compile and linker overview
C++ is a compiled language, this means, for a program to run, its source text has to be processed by a compiler, producing object files, which are combined by a linker yielding an executable program.

Text, or code, begins with a source code file.
You write C++ source code into human-readable text files called source files.

A source code file must be properly formatted according to language syntax and semantics

A C++ program typically consists of many source code files (called source files).

Then you use a compiler to convert your C++ into executable machine code, which is a program that computers can run.


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

The ISO C++ standard defines two kinds of entities:
• Core language features, such as built-in types (e.g., char and int) and loops (e.g., for-statements and while-statements)
• Standard-library components, such as containers (e.g., vector and map) and I/O operations
(e.g., << and getline())







smallest valid program

int main() {}


C++ programs have a single entry point called the main function. An entry point is a function that executes when a user runs
a program. Functions are blocks of code that can take inputs, execute some
instructions, and return results.

Then the program exits by returning the
exit code 0 to the operating system x. Exit codes are integer values that the
operating system uses to determine how well a program ran. Generally, aUp and Running
zero (0) exit code means the program ran successfully. Other exit codes
might indicate a problem. Having a return statement in main is optional; the
exit code defaults to 0.



save to [filename].cpp
C++ files use the .cpp file extension

use console to navigate to containing folder, then run:
g++ [filename].cpp

this will compile to an a.out, a.out is a file format used in older versions of Unix-like computer operating systems for executables, object code, and, in later systems, shared libraries. This is an abbreviated form of "assembler output", the filename of the output of Ken Thompson's PDP-7 assembler.

run using:
./a.out

to name the file something other than a.out run:
g++ -o [executable name] [filename].cpp

run using:
./[executable name]
