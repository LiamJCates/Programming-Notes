


https://cppreference.com


C++ is a middle-level programming language developed by Bjarne Stroustrup starting in 1979 at Bell Labs.



C++ runs on a variety of platforms, such as Windows, Mac OS, and the various versions of UNIX.


Why Learn C++
    C++ is very close to hardware, so you get a chance to work at a low level which gives you lot of control in terms of memory management, better performance and finally a robust software development.

    C++ programming gives you a clear understanding about Object Oriented Programming. You will understand low level implementation of polymorphism when you will implement virtual tables and virtual table pointers, or dynamic type identification.

    C++ is very popular

    C++ is the most widely used programming languages in application and system programming. So you can choose your area of interest of software development.

    C++ really teaches you the difference between compiler, linker and loader, different data types, storage classes, variable types their scopes etc.



C++ Characteristics
C++ is a statically typed, compiled, general-purpose, case-sensitive, free-form programming language that supports procedural, object-oriented, and generic programming.

C++ is regarded as a middle-level language, as it comprises a combination of both high-level and low-level language features.

C++ is a superset of C, and that virtually any legal C program is a legal C++ program.



C++ is a statically typed language. That is, the type of every entity (e.g., object, value, name, and expression) must be known to the compiler at its point of use.
The type of an object determines the set of operations applicable to it.



Initially C++ was designed to be an object-oriented successor to C that implements concepts such as inheritance, abstraction, polymorphism, and encapsulation.

C++ features classes that are used to contain member data and member
methods. These member methods operate using member data. The effect of this
organization is that the programmer models objects containing data and actions they wants to perform.








Compile and linker overview
C++ is a compiled language, this means, for a program to run, its source text has to be processed by a compiler, producing object files, which are combined by a linker yielding an executable program.

Many popular C++ compilers have continued to support C programming too.

A C++ program typically consists of many source code files (called source files).


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

The ISO C++ standard defines two kinds of entities:
• Core language features, such as built-in types (e.g., char and int) and loops (e.g., for-statements and while-statements)
• Standard-library components, such as containers (e.g., vector and map) and I/O operations
(e.g., << and getline())






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










The following list shows some application types:
✦ GTK+ Project: This is a graphical application that includes, well, a window.
You know the kind: It usually has a menu across the top and something
inside it that you can either click or type into. It relies on the Gimp Toolkit
(GTK), which provides an incredibly flexible interface that runs on a
number of platforms including Linux, Mac, and Windows systems. Read
more about GTK in the “What about all of those other projects?” sidebar.
✦ Console Application: This is an application that gets a paltry Console
window instead of a graphical window. Console refers to a window with
a command prompt. (Folks who recall the old days, before Windows, call
it a DOS box, and you may know it as a terminal window when working
with operating systems such as the Mac or Linux.)
✦ Static library: A static library is a set of C++ code that you use later in
another project. It’s like making a really great marinade that you won’t
use up today. You’ll use some of it tomorrow and some of it after that.
Same with a C++ library.
✦ Dynamic Link Library: A Dynamic Link Library (DLL) is kind of like a
static library except it is separated from the main application and gets
its own file with a .DLL extension.
