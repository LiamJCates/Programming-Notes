### The Compiler Tool Chain

A C++ program is derived from one or more human-readable text files called source code files (source files) which are formatted according to language syntax and semantics. After writing the source code for a C++ program, the next step is to turn your source code into an executable program. 

From a high level, the compiler tool chain (or tool chain) is a collection of three elements:

preprocessor
compiler
linker

These run one after the other to convert source code into a program.

1. The preprocessor performs basic source code manipulation.

  For example, #include <cstdio> is a directive that instructs the preprocessor to include information about the cstdio library directly into your program’s source code. When the preprocessor finishes processing a source file, it produces a single translation unit. Each translation unit is then passed to the compiler for further processing.

2. The compiler reads a translation unit and generates an object file.

    If source files are properly formatted the compiler will output a transformation called an object file, otherwise it will produce an error message and fail. Object files contain data and instructions in an intermediate format that most humans wouldn’t understand, a set of low-level machine instructions called object code. Compilers work on one translation unit at a time, so each translation unit corresponds to a single object file.

3. The linker generates programs from object files.

    All object files made from individual source files are linked into a single executable file (an executable), if it can't link the object files it will produce an error message. Machine code is the language that computers use to understand programs, and object code is a form of machine code that is not yet fully linked into a program. A linker is used to convert object files into an executable machine code file. Linkers are also responsible for finding the libraries you’ve included within your source code. For example, the linker will find the cstdio library and include everything your program needs to use it's functions. Note that the cstdio header is distinct from the cstdio library. The header contains information about how to use the library.

Executables can be run by the operating system.



Sometimes we need to know what C++ standard a compiler is using. 
To get this information, we use the __cplusplus macro, which produces one of values below:

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



#### Todo

Look into assemblers


If separate, is the compiler responsible for just the assembly code creation as well as optimizing the assembly code?

Assembly language creation is not a required part of the process.
Typically, compilers have an option you can supply in order to print an assembly language listing.
Some compilers emit executable code without going through the generation of assembly language. 


There several mandatory steps:

1/ turn the C++ code into assembly code

2/ assembly the code to produce an object file containing the binary instructions, static data, and symbolic references to variable and functions.

3/ gather all the object files and libraries to make an executable. (linking)

In theory steps 1/ and 2/ could be merged and one could design a compiler that directly generates an object file. But nobody does that. The development and debug of such a compiler would be a nightmare, and it would lack portability.

Indeed modern compilers have more internal steps before generating the assembly. They start by generating a intermediate representation of the program in a non optimized pseudo assembly. Then there are several steps to optimize this intermediate representation, first in a machine independent way. Then machine dependent optimization are performed and the actual assembly is generated.

This presents several advantages:

1/ if you want to generate code for another language (say you have a C++ compiler and you want a compiler for Objective-C), you just have to rewrite the first steps (generating an intermediate representation of the program) and all the other steps can be reused.

2/ if you want to compile for another architecture, you just have to modify the final step, while of the part that manipulate the intermediate representation can stay unchanged.




    Machine language instructions (ML) are the only instructions the processor/CPU can execute.

    ML is just numbers. When the ML is put into memory, it can be fetched, decoded and executed by the processor. Different numbers will cause the processor to perform different actions.

    Different type of processors usually have different ML's

    Assembly language (AL) is a symbolic representation of ML.

A translation of the C++ program statements to machine language is necessary.
Stages in Compiling

A number of steps are involved in the compilation process.

                                                 other ML   ----+
                                                                V       
         +--------------+   +----------+   +-----------+   +--------+
  C++ -->| PREPROCESSOR |-->| COMPILER |-->| ASSEMBLER |-->| LINKER |-->  
Program  +--------------+   +----------+   +-----------+   +--------+     

  Output:  Modified C++       Assembly      Executable     "Complete"
           program (copy)     language        code (ML)    Executable

Stages in Compiling - Explanation

PREPROCESSOR
	

The source program undergoes modification before it is compiled. A modified copy of the original program is created, however it is still valid C++. Things the preprocessor does includes:

    #includes are processed. In the copy of the original file, the #include is removed, and C++ statements are inserted at the point of the #include just as if the programmer had typed them in themself.

    Comments are removed.

COMPILER
The C++ statements are converted into AL statements.

ASSEMBLER
The AL statements are converted into ML called object code.

LINKER
Object code from multiple sources is combined together to form a complete executable program. For example the ML to perform input/output is almost always linked in since most programs do input or output.
Linking

Linking is an important phase of the compilation process.

All machine language can be compiled into a single executable program. This is called static linking. More common today is dynamic linking. With dynamic linking the "other" machine language remains separate and the linker arranges for your program to connect to the "other" machine language. Typing, at the prompt:

ldd executable_file_name

will show the dynamic libraries (files) the program requires. Try a.out for the executable_file_name.

When the program name is typed at the prompt the command interpreter, usually called the shell, causes the operating system to load the program into memory and begin executing it.

Note that the whole process is also called compiling and gets its name from the subpart, the conversion from C++ to AL.