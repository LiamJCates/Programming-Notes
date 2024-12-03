Creating your own libraries with the librarian

You can collect your own functions together into a library. Most programming packages come with a librarian that manages groups of object modules. Each librarian has its own commands, but the general idea is this:

Make a header file containing the function prototypes for all the functions in your library.

Put this header file somewhere in the preprocessor’s search path,
  either in the local directory (so it can be found by #include "header")
  in the include directory (so it can be found by #include <header>).

Now take all the object modules and hand them to the librarian along with a name for the finished library (most librarians require a common extension, such as .lib or .a).

Place the finished library where the other libraries reside so the linker can find it.

When you use your library, you will have to add something to the command line so the linker knows to search the library for the functions you call.

You must find all the details in your local manual, since they vary from system to system.



Productivity, in computer programming terms, means that fewer people can make much more complex and impressive programs in less time. There are certainly other issues when it comes to choosing a language, such as efficiency (does the nature of the
language cause slowdown and code bloat?), safety (does the
language help you ensure that your program will always do what
you plan, and handle errors gracefully?), and maintenance (does
the language help you create code that is easy to understand,
modify, and extend?).

The only way to get massive increases in
productivity is to leverage off other people’s code. That is, to use
libraries.
A library is simply a bunch of code that someone else has written
and packaged together. Often, the most minimal package is a file
with an extension like lib and one or more header files to tell your
compiler what’s in the library. The linker knows how to search
through the library file and extract the appropriate compiled code.
But that’s only one way to deliver a library. On platforms that span
many architectures, such as Linux/Unix, often the only sensible
way to deliver a library is with source code, so it can be
reconfigured and recompiled on the new target.

Thus, libraries are probably the most important way to improve
productivity, and one of the primary design goals of C++ is to
make library use easier. This implies that there’s something hard
about using libraries in C. Understanding this factor will give you a
first insight into the design of C++, and thus insight into how to use
it.
