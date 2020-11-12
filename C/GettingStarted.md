#include <stdio.h>

main(){
  printf("hello world\n");
}

Just how to run this program depends on the system you are using. On the UNIX operating system you must create the program in a file whose name ends in ".c", such as hello.c, then compile it with the command

/cc hello.c

compilation will proceed silently, and make an executable file
called a.out

In Linux, UNIX and related operating systems
"." denotes the current directory
".." denotes the parent directory

We use "./command_name" to execute a command in the current file directory

to run a.out type the command

./a.out





Program components
A C program, whatever its size, consists of functions and variables.

functions contains statements that specify the computing operations to be done

variables store values used during the computation



Variables and constants are the basic data objects manipulated in a program.
Declarations list the variables to be used, and state what type they have and
perhaps what their initial values are.

Expressions combine variables, constants, and operators to produce new values.
Operators specify what is to be done within an expression.

The type of an object determines the set of values it can have and what operations can be performed on it.















Directives

Directives are special instructions directed to the preprocessor (preprocessor directive) or to the compiler (compiler directive) on how it should process part or all of your source code or set some flags on the final object and are used to make writing source code easier (more portable for instance) and to make the source code more understandable. Directives are handled by the preprocessor, which is either a separate program invoked by the compiler or part of the compiler itself.

Compiler Directive indicating inclusion of standard input/output library
 #include <stdio.h>



Symbolic Constants

A #define line defines a symbolic name or symbolic constant to be a particular string of characters:
 #define name replacement text

Thereafter, any occurrence of name (not in quotes and not part of another
name) will be replaced by the corresponding replacement text. The name has
the same form as a variable name: a sequence of letters and digits that begins
with a letter. The replacement text can be any sequence of characters; it is not
limited to numbers
