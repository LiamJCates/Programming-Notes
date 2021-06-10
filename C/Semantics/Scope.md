The scope of a name is the part of the program within which the name can be used.

 In general there are three kinds of scope. Global scope, function scope and block scope. Variables declared outside any function have global scope and they persist throughout the lifetime of the program. Variables declared inside functions at outermost level have function scope and they live as long as function remains active. A block in C is marked by braces({ and }). Function bodies are also marked by this. Here I mean blocks inside a function. Starting from C99 you can declare variables anywhere inside a function and this block variables which have less lifetime than functions are possible. We will see more of these when we see more code. Note that identifiers can be reused in different scopes. For example, a loop index integer identifier is repeated many times but every time it is a new variable(We will see loops soon). Two identifiers have same scope if and only if their scope terminates at the same point.

There are three places where variables can be declared in C programming language −

    Inside a function or a block which is called local variables.

    Outside of all functions which is called global variables.

    In the definition of function parameters which are called formal parameters.

Let us understand what are local and global variables, and formal parameters.


Local Variables

Variables that are declared inside a function or block are called local variables. They can be used only by statements that are inside that function or block of code. Local variables are not known to functions outside their own.




Global Variables

Global variables are defined outside a function, usually on top of the program. Global variables hold their values throughout the lifetime of your program and they can be accessed inside any of the functions defined for the program.

A global variable can be accessed by any function. That is, a global variable is available for use throughout your entire program after its declaration.

A program can have same name for local and global variables but the value of local variable inside a function will take preference.


Formal Parameters

Formal parameters, are treated as local variables with-in a function and they take precedence over global variables.































Storage Classes
A storage class defines the scope (visibility) and life-time of variables and/or functions within a C Program. They precede the type that they modify.

We have four different storage classes in a serial C program:
  auto
  register
  static
  extern



The auto Storage Class

The auto storage class is the default storage class for all local variables.

{
   int mount;
   auto int month;
}

The example above defines two variables with in the same storage class. 'auto' can only be used within functions, i.e., local variables.

Variables defined and declared within a function are private or local to the function, no other function can have direct access to them.

Each local
variable in a function comes into existence only when the function is called, and
disappears when the function is exited. This is why such variables are usually
known as automatic variables, following terminology in other languages. We
will use the term automatic henceforth to refer to these local variables

Because automatic variables come and go with function invocation, they do
not retain their values from one call to the next, and must be explicitly set upon
each entry. If they are not set, they will contain garbage.












The register Storage Class

A register declaration advises the compiler that the variable in question
will be heavily used. The idea is that register variables are to be placed in
machine registers, which may result in smaller and faster programs. But compilers are free to ignore the advice.
The register declaration looks like
register int X;
register char c;

and so on. The register declaration can only be applied to automatic variables and to the formal parameters of a function
f{register unsigned m, register long n)
  {
     register int  miles;
  }


The register storage class is used to define local variables that should be stored in a register instead of RAM. This means that the variable has a maximum size equal to the register size (usually one word) and can't have the unary '&' operator applied to it (as it does not have a memory location).



The register should only be used for variables that require quick access such as counters. It should also be noted that defining 'register' does not mean that the variable will be stored in a register. It means that it MIGHT be stored in a register depending on hardware and implementation restrictions.

In practice, there are restrictions on register variables, reflecting the realities
of underlying hardware. Only a few variables in each function may be kept in
registers, and only certain types are allowed. Excess register declarations are
harmless, however, since the word register is ignored for excessor disallowed
declarations. And it is not possible to take the address of a register variable (a
topic to be covered in Chapter 5), regardless of whether the variable is actually
placed in a register. The specific restrictions on number and types of register
variables vary from machine to machine.











The static Storage Class

Static storage is specified by prefixing the normal declaration with the word static.


Static variables are for the private use of the functions in their respective source files, and are not meant to be accessed by anything else. The static declaration, applied to an external variable or function, limits the scope of that object to the rest of the source file being compiled

External static thus provides a way to hide names

If the two routines and the two variables are compiled in one file then no other routine will be able to access the variables
and those names will not conflict with the same names in other files of the same program.

The external static declaration is most often used for variables, but it can
be applied to functions as well.

Normally, function names are global, visible to any part of the entire program. If a function is declared static, however, its name is invisible outside of the file in which it is declared.

The static declaration can also be applied to internal variables. Internal static variables are local to a particular function just as automatic variables are, but unlike automatics, they remain in existence rather than coming and going each time the function is activated. This means that internal static variables provide private, permanent storage within a single function.

The static storage class instructs the compiler to keep a local variable in existence during the life-time of the program instead of creating and destroying it each time it comes into and goes out of scope. Therefore, making local variables static allows them to maintain their values between function calls.

The static modifier may also be applied to global variables. When this is done, it causes that variable's scope to be restricted to the file in which it is declared.

In C programming, when static is used on a global variable, it causes only one copy of that member to be shared by all the objects of its class.

#include <stdio.h>

/* function declaration */
void func(void);

static int count = 5; /* global variable */

main() {

   while(count--) {
      func();
   }

   return 0;
}

/* function definition */
void func( void ) {

   static int i = 5; /* local static variable */
   i++;

   printf("i is %d and count is %d\n", i, count);
}

When the above code is compiled and executed, it produces the following result −

i is 6 and count is 4
i is 7 and count is 3
i is 8 and count is 2
i is 9 and count is 1
i is 10 and count is 0














The extern Storage Class

The extern storage class is used to give a reference of a global variable that is visible to ALL the program files. When you use 'extern', the variable cannot be initialized however, it points the variable name at a storage location that has been previously defined.

When you have multiple files and you define a global variable or function, which will also be used in other files, then extern will be used in another file to provide the reference of defined variable or function. Just for understanding, extern is used to declare a global variable or function in another file.

The extern modifier is most commonly used when there are two or more files sharing the same global variables or functions as explained below.

First File: main.c

#include <stdio.h>

int count;
extern void write_extern();

main() {
   count = 5;
   write_extern();
}

Second File: support.c

#include <stdio.h>

extern int count;

void write_extern(void) {
   printf("count is %d\n", count);
}

Here, extern is being used to declare count in the second file, where as it has its definition in the first file, main.c. Now, compile these two files as follows −

$gcc main.c support.c

It will produce the executable program a.out. When this program is executed, it produces the following result −

count is 5



As an alternative to automatic variables, it is possible to define variables that
are external to all functions, that is, variables that can be accessed by name by
any function.


It is important to distinguish between the declaration of an external variable
and its definition. A declaration announces the properties of a variable (primarily its type); a definition also causes storage to be set aside. If the lines

int sp;
double val[MAXVAL];

appear outside of any function, they define the external variables sp and val, cause storage to be set aside, and also serve as the declaration for the rest of
that source file. On the other hand, the lines

extern int sp;
extern double vall];

declare for the rest of the source file that sp is an int and that val is a
double array (whose size is determined elsewhere), but they do not create the
variables or reserve storage for them.
There must be only one definition of an external variable among all the files
that make up the source program; other files may contain extern declarations
to access it. (There may also be extern declarations in the file containing the
definition') Array sizes must be specified with the definition, but are optional
with an extern declaration.
Initialization of an external variable goes only with the definition.

Although it is not a likely organization for this program, the functions push
and pop could be defined in one file, and the variables val and sp defined and
initialized in another. Then these definitions and declarations would be necessary to tie them together:

Infilel:
  extern int sp;
  extern double vall];

Infile2:
  int sp = 0;
  double val [MAXVAL] ;


Because the extern declarations in file} lie ahead of and outside the function definitions, they apply to all functions; one set of declarations suffices for all of file1. This same organization would also be needed if the definitions of sp and val followed their use in one file.


Because external variables are globally
accessible, they can be used instead of argument lists to communicate data
between functions. Furthermore, because external variables remain in existence
permanently, rather than appearing and disappearing as functions are called and
exited, they retain their values even after the functions that set them have
returned.
An external variable must be defined, exactly once, outside of any function;
this sets aside storage for it. The variable must also be declared in each function that wants to access it; this states the type of the variable. The declaration
may be an explicit extern statement or may be implicit from context.





Print Longest Line

#include <stdio.h>
#define MAXLINE 1000

int max;
char current_line[MAXLINE];
char longest_line[MAXLINE];

int getline(void);
void copy(void);

main(){
  int len;
  extern int max;
  extern char longest_line[];

  max = 0;

  while((len = getline(current_line)) > 0){
    if(len > max) {
      max = len;
      copy();
    }
  }
  if(max > 0)
    printf("%s", longest);

  return 0;
}

getline(void){
  int c, i;
  extern char current_line[];

  for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; i++)
    current_line[i] = c;
  if(c == '\n')
    current_line[i++] = c;

  current_line[i] = '\0';
  return i;
}

void copy(void){
  int i;
  extern char current_line[], longest_line[];

  for(i = 0;(longest_line[i] = current_line[i]) != '\0'; ++i);
}


The external variables in main, getline, and copy are defined by the
first lines of the example above, which state their type and cause storage to be
allocated for them. Syntactically, external definitions are just like definitions of
local variables, but since they occur outside of functions, the variables are external. Before a function can use an external variable, the name of the variable
must be made known to the function. One way to do this is to write an
extern declaration in the function; the declaration is the same as before except
for the added keyword extern.
In certain circumstances, the extern declaration can be omitted. If the
definition of an external variable occurs in the source file before its use in a particular function, then there is no need for an extern declaration in the function. The extern declarations in main,getline and copyare thus redundant. In fact, common practice is to place definitions of all external variables at
the beginning of the source file, and then omit all extern declarations.
If the program is in several source files, and a variable is defined in filel
and used in fUe2 and file3, then extern declarations are needed in file2 and
file3 to connect the occurrences of the variable. The usual practice is to collect
extern declarations of variables and functions in a separate file, historically
called a header, that is included by #include at the front of each source file.
The suffix •h is conventional for header names.
