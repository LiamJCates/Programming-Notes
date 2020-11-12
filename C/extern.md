A C program consists of a set of external objects, which are either variables
or functions. The adjective "external" is used in contrast to "internal," which
describes the arguments and variables defined inside functions. External variables are defined outside of any function, and are thus potentially available to
many functions. Functions themselves are always external, because C does not
allow functions to be defined inside other functions. By default, external variables and functions have the property that all references to them by the same
name, even from functions compiled separately, are references to the same
thing. (The standard calls this property external linkage.)

An external variable declaration is useful when you are using multiple files and you define your variable in one of the files which will be available at the time of linking of the program. You will use the keyword extern to declare a variable at any place. Though you can declare a variable multiple times in your C program, it can be defined only once in a file, a function, or a block of code


Example

Try the following example, where variables have been declared at the top, but they have been defined and initialized inside a function

 #include <stdio.h>

// Variable declaration:
extern int a, b;
extern int c;
extern float f;

int main () {

   /* variable definition: */
   int a, b;
   int c;
   float f;

   /* actual initialization */
   a = 10;
   b = 20;

   c = a + b;
   printf("value of c : %d \n", c);

   f = 70.0/3.0;
   printf("value of f : %f \n", f);

   return 0;
}


The extern keyword applies to C variables (data objects) and C functions. Basically, the extern keyword extends the visibility of the C variables and C functions.



Declaration of a variable or function simply declares that the variable or function exists somewhere in the program, but the memory is not allocated for them. The declaration of a variable or function serves an important role–it tells the program what its type is going to be. In case of function declarations, it also tells the program the arguments, their data types, the order of those arguments, and the return type of the function.

Definition, when we define a variable or function, in addition to everything that a declaration does, it also allocates memory for that variable or function. Therefore, we can think of definition as a superset of the declaration (or declaration as a subset of definition).

A variable or function can be declared any number of times, but it can be defined only once.




Extern Functions
It turns out that when a function is declared or defined, the extern keyword is implicitly assumed.

When we write:

    int foo(int arg1, char arg2);

The compiler treats it as:

    extern int foo(int arg1, char arg2);

Since the extern keyword extends the function’s visibility to the whole program, the function can be used (called) anywhere in any of the files of the whole program, provided those files contain a declaration of the function. (With the declaration of the function in place, the compiler knows the definition of the function exists somewhere else and it goes ahead and compiles the file).





Extern Variables
Now let’s consider the use of extern with variables. To begin with, how would you declare a variable without defining it? You would do something like this:

    extern int var;

Here, an integer type variable called var has been declared (it hasn’t been defined yet, so no memory allocation for var so far). And we can do this declaration as many times as we want. So far so good

Now, how would you define var? You would do this:

    int var;

In this line, an integer type variable called var has been both declared and defined (remember that definition is the superset of declaration). Since this is a definition, the memory for var is also allocated. Now here comes the surprise. When we declared/defined a function, we saw that the extern keyword was present implicitly. But this isn’t the case with variables. If it were, memory would never be allocated for them. Therefore, we need to include the extern keyword explicitly when we want to declare variables without defining them. Also, as the extern keyword extends the visibility to the whole program, by using the extern keyword with a variable, we can use the variable anywhere in the program provided we include its declaration the variable is defined somewhere.

Now let us try to understand extern with examples.

Example 1:

int var;
int main(void)
{
   var = 10;
   return 0;
}

This program compiles successfully. var is defined (and declared implicitly) globally.


Example 2:
extern int var;
int main(void)
{
  return 0;
}

This program compiles successfully. Here var is declared only. Notice var is never used so no problems arise.

Example 3:
extern int var;
int main(void)
{
  var = 10;
  return 0;
}

This program throws an error in compilation because var is declared but not defined anywhere. Essentially, the var isn’t allocated any memory. And the program is trying to change the value to 10 of a variable that doesn’t exist at all.


In projects with multiple modules, one must instantiate the global variable; the other(s) must declare it as an "extern" variable.

If a variable is defined in file1 and used in file2 and file3, then extern declarations are needed in
file2 and file3 to connect the occurrences of the variable.

A multi file program collects extern declarations of variables and functions into
a separate header file used by #include at the front of each source file.

The suffix .h is conventional for header names.

Example 4:

#include "somefile.h"
extern int var;
int main(void)
{
 var = 10;
 return 0;
}

Assuming that somefile.h contains the definition of var, this program will compile successfully.

Example 5:

extern int var = 0;
int main(void)
{
 var = 10;
 return 0;
}

If a variable is only declared and an initializer is also provided with that declaration, then the memory for that variable will be allocated–in other words, that variable will be considered as defined.

So that was a preliminary look at the extern keyword in C.

In short, we can say:

    A declaration can be done any number of times but definition only once.
    the extern keyword is used to extend the visibility of variables/functions.
    Since functions are visible throughout the program by default, the use of extern is not needed in function declarations or definitions. Its use is implicit.
    When extern is used with a variable, it’s only declared, not defined.
    As an exception, when an extern variable is declared with initialization, it is taken as the definition of the variable as well.












External variables are also known as global variables. These variables are defined outside the function. These variables are available globally throughout the function execution. The value of global variables can be modified by the functions. “extern” keyword is used to declare and define the external variables.

Scope − They are not bound by any function. They are everywhere in the program i.e. global.

Default value − Default initialized value of global variables are Zero.

Lifetime − Till the end of the execution of the program.


Example

#include <stdio.h>
extern int x = 32;
int b = 8;
int main() {
   auto int a = 28;
   extern int b;
   printf("The value of auto variable : %d\n", a);
   printf("The value of extern variables x and b : %d,%d\n",x,b);
   x = 15;
   printf("The value of modified extern variable x : %d\n",x);
   return 0;
}

Output

The value of auto variable : 28
The value of extern variables x and b : 32,8
The value of modified extern variable x : 15









Problems with Extern
Relying heavily on external variables leads to confusing programs,
variables can be changed in unexpected and even inadvertent ways, and the program is hard to modify.

Relying heavily on external variables destroys the generality of functions by
wiring into them the names of the variables they manipulate.
