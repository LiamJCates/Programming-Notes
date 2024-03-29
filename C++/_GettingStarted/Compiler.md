

A compiler is a software that converts a program written in a high-level language (in this case C++) into low-level machine language instructions which the computer can understand.

Having written the program, we need to compile it. How you compile a program
depends on your operating system and compiler. For details on how your particu-
lar compiler works, check the reference manual or ask a knowledgeable colleague.

Later, the computer executes each of these instructions to produce the desired results. 
This set of low-level machine instructions is called an Object code.

An executable program is created for a specific hardware/system combination; it is not portable, say, from a Mac to a Windows PC. When we talk about portability of C++ programs, we usually mean portability of source code; that is, the source code can be successfully compiled and run on a variety of systems.

A C++ program is typically derived from many source code files (source files) by a compiler and linker in the steps that follow:

Code begins as a source code file.
  You write C++ source code into human-readable text files called source files.
  A source code file is formatted according to language syntax and semantics.

A compiler is used to produce object files:
  If source files properly formatted the compiler will output a transformation called an object file, otherwise it will produce an error message and fail.
  An object file is a computer file containing object code, that is, machine code output of an assembler or compiler.

A linker is used to convert object files into an executable machine code file:
  All object files made from individual source files are linked into a single executable file (an executable), if it can't link the object files it will produce an error message.

Executables can be run by the operating system.



### The Compiler Tool Chain
After writing the source code for a C++ program, the next step is to turn your source code into an executable program. The compiler tool chain (or tool chain) is a collection of three elements that run one after the other to convert source code into a program:

1. The preprocessor performs basic source code manipulation.

  For example, #include <cstdio> is a directive that instructs the preprocessor to include information about the cstdio library directly into your program’s source code. When the preprocessor finishes processing a source file, it produces a single translation unit. Each translation unit is then passed to the compiler for further processing.

2. The compiler reads a translation unit and generates an object file.

    Object files contain an intermediate format called object code. These files contain data and instructions in an intermediate format that most humans wouldn’t understand. Compilers work on one translation unit at a time, so each translation unit corresponds to a single object file.

3. The linker generates programs from object files.

    Linkers are also responsible for finding the libraries you’ve included within your source code. For example, the linker will find the cstdio library and include everything your program needs to use it's functions. Note that the cstdio header is distinct from the cstdio library. The header contains information about how to use the library.






Sometimes we need to know what C++ standard a compiler is using. To get this information, we use the __cplusplus macro, which produces one of values below:

| Standard | __cplusplus output |
|----------|--------------------|
| C++ pre C++98 | 1 |
| C++98 | 199711L |
| C++11 | 201103L |
| C++14 | 201402L |
| C++17 | 201703L |

Example Usage:

  #include <iostream>
  using namespace std;

  int main() {

    switch(__cplusplus) {
      case 201703L: cout << "C++17"; break;
      case 201402L: cout << "C++14"; break;
      case 201103L: cout << "C++11"; break;
      case 199711L: cout << "C++98"; break;
      case 1:       cout << "pre-98 C++"; break;
      default:      cout << "non-standard"; break;
    }

    cout << endl;
  }
