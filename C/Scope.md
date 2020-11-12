A scope in any programming is a region of the program where a defined variable can have its existence and beyond that variable it cannot be accessed. There are three places where variables can be declared in C programming language −

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





Initializing Local and Global Variables

When a local variable is defined, it is not initialized by the system, you must initialize it yourself. Global variables are initialized automatically by the system when you define them as follows −
int 	0
char 	'\0'
float 	0
double 	0
pointer 	NULL

It is a good programming practice to initialize variables properly, otherwise your program may produce unexpected results, because uninitialized variables will take some garbage value already available at their memory location.






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

The register storage class is used to define local variables that should be stored in a register instead of RAM. This means that the variable has a maximum size equal to the register size (usually one word) and can't have the unary '&' operator applied to it (as it does not have a memory location).

{
   register int  miles;
}

The register should only be used for variables that require quick access such as counters. It should also be noted that defining 'register' does not mean that the variable will be stored in a register. It means that it MIGHT be stored in a register depending on hardware and implementation restrictions.













The static Storage Class

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
