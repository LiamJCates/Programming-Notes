A function is a group of statements that together perform a task. Every C program has at least one function, which is main(), and all the most trivial programs can define additional functions.

You can divide up your code into separate functions.

Functions break large computing tasks into smaller ones, and enable people to build on what others have done instead of starting over from scratch.

Appropriate functions hide details of operation from parts of the program that don't need to know about them, thus clarifying the whole, and easing the pain of making changes

How you divide up your code among different functions is up to you, but logically the division is such that each function performs a specific task.

Normally you are at liberty to give functions whatever
names you like, but "main" is special - your program begins executing at the beginning of main. This means that every program must have a main somewhere.

This main function typically calls other functions.

Functions called in main communicate with main code execution through
supplied parameters and their returned value


Function names other than main usually take the form of a verb.



One method of communicating data between functions is for the calling
function to provide a list of values, called arguments, to the function it calls.
The parentheses after the function name surround the argument list.

The first line of a function declares the parameter types and names, and the type of the result that the function returns.



A function definition form:
return-type function-name(parameter declarations)
{
  //statements
}


A function definition in C programming consists of a function header and a function body. Here are all the parts of a function −

Return Type − A function may return a value. The return_type is the data type of the value the function returns.

Function Name − This is the actual name of the function. The function name and the parameter list together constitute the function signature.

Parameters − A parameter is like a placeholder. When a function is invoked, you pass a value to the parameter. This value is referred to as actual parameter or argument. The parameter list refers to the type, order, and number of the parameters of a function. Parameters are optional; that is, a function may contain no parameters.

Function Body − The function body contains a collection of statements that define what the function does.


C functions cannot be split between files





The declaration
double sum, atof(char []);
says that sumis a double variable, and that atof is a function that takes one
char [ ] argument and returns a double.
The function atof must be declared and defined consistently. If atof
itself and the call to it in main have inconsistent types in the same source file,
the error will be detected by the compiler. But if (as is more likely) atof were
compiled separately, the mismatch would not be detected, atof would return a
double that main would treat as an int, and meaningless answers would
result.
In the light of what we have said about how declarations must match definitions, this might seem surprising. The reason a mismatch can happen is that if there is no function prototype, a function is implicitly declared by its first
appearance in an expression, such as
sum += atof(line)

If a name that has not been previously declared occurs in an expression and is
followed by a left parenthesis, it is declared by context to be a function name,
the function is assumed to return an int, and nothing is assumed about its
arguments. Furthermore, if a function declaration does not include arguments,
as in


double atof();
that too is taken to mean that nothing is to be assumed about the arguments of
atof; all parameter checking is turned off. This special meaning of the empty

argument list is intended to permit older C programs to compile with new compilers. But it's a bad idea to use it with new programs. If the function takes
arguments, declare them; if it takes no arguments, use void.



Parameters

In C, all function arguments are passed by value.

"Pass by value" means that the called function is given the values of its arguments in
temporary variables rather than the originals.

In "call by reference" languages like Fortran or with var parameters in Pascal the called routine has
access to the original argument, not a local copy.

In C, the called function cannot directly alter a variable in the calling function;it can only
alter its private, temporary copy

"Call by value" usually leads to more compact programs with fewer extraneous variables, because parameters can be treated as conveniently initialized local variables in the called routine.

For a function to modify a variable in a calling routine, the caller must provide
the address of the variable (a pointer), and the called function must declare the parameter to be a pointer.

When the name of an array is used as an argument, the value passed to the function is
the address of the beginning of the array.


Passing Arrays as Function Arguments in C

If you want to pass a single-dimension array as an argument in a function, you would have to declare a formal parameter in one of following three ways and all three declaration methods produce similar results because each tells the compiler that an integer pointer is going to be received. Similarly, you can pass multi-dimensional arrays as formal parameters.


1) Formal parameters as a pointer

void myFunction(int *param) {

}

2) Formal parameters as a sized array

void myFunction(int param[10]) {

}

3) Formal parameters as an unsized array

void myFunction(int param[]) {

}




Variable Parameters
Sometimes, you may come across a situation, when you want to have a function, which can take variable number of arguments, i.e., parameters, instead of predefined number of parameters. The C programming language provides a solution for this situation and you are allowed to define a function which can accept variable number of parameters based on your requirement. The following example shows the definition of such a function.

int func(int, ... ) {
   .
   .
   .
}

int main() {
   func(1, 2, 3);
   func(1, 2, 3, 4);
}

It should be noted that the function func() has its last argument as ellipses, i.e. three dotes (...) and the one just before the ellipses is always an int which will represent the total number variable arguments passed. To use such functionality, you need to make use of stdarg.h header file which provides the functions and macros to implement the functionality of variable arguments and follow the given steps −

    Define a function with its last parameter as ellipses and the one just before the ellipses is always an int which will represent the number of arguments.

    Create a va_list type variable in the function definition. This type is defined in stdarg.h header file.

    Use int parameter and va_start macro to initialize the va_list variable to an argument list. The macro va_start is defined in stdarg.h header file.

    Use va_arg macro and va_list variable to access each item in argument list.

    Use a macro va_end to clean up the memory assigned to va_list variable.

Now let us follow the above steps and write down a simple function which can take the variable number of parameters and return their average −
Live Demo

#include <stdio.h>
#include <stdarg.h>

double average(int num,...) {

   va_list valist;
   double sum = 0.0;
   int i;

   /* initialize valist for num number of arguments */
   va_start(valist, num);

   /* access all the arguments assigned to valist */
   for (i = 0; i < num; i++) {
      sum += va_arg(valist, int);
   }

   /* clean memory reserved for valist */
   va_end(valist);

   return sum/num;
}

int main() {
   printf("Average of 2, 3, 4, 5 = %f\n", average(4, 2,3,4,5));
   printf("Average of 5, 10, 15 = %f\n", average(3, 5,10,15));
}






















RETURN
A function must return a value, and this value must be of the type listed by the function definition.

Some functions return a useful value; others, are used only for their effect and return
no value


int is the default return type and could be omitted

However, it is good programming practice to always declare a return type in the function definition.


return statement form:
return expression;

The expression will be converted to the return type of the function if necessary

The value of expression, if present, is returned to the calling function. If expression is omitted, the return value of the function is undefined. The expression, if present, is evaluated and then converted to the type returned by the function. When a return statement contains an expression in functions that have a void return type, the compiler generates a warning, and the expression isn't evaluated.

If no return statement appears in a function definition, control automatically returns to the calling function after the last statement of the called function is executed. In this case, the return value of the called function is undefined. If the function has a return type other than void, it's a serious bug, and the compiler prints a warning diagnostic message. If the function has a void return type, this behavior is okay, but may be considered poor style. Use a plain return statement to make your intent clear.

An empty return statement or "falling off the end", reaching the terminating right brace causes control, but no useful value to be returned to the caller

The return; statement is used with a function that has a no return type

Typically, a return value of zero implies normal termination; non-zero values signal
unusual or erroneous termination conditions


Return array from function in C
C programming does not allow to return an entire array as an argument to a function. However, you can return a pointer to an array by specifying the array's name without an index.

If you want to return a single-dimension array from a function, you would have to declare a function returning a pointer as in the following example −

int * myFunction() {
   .
   .
   .
}

Second point to remember is that C does not advocate to return the address of a local variable to outside of the function, so you would have to define the local variable as static variable.








Calling a Function

While creating a C function, you give a definition of what the function has to do. To use a function, you will have to call that function to perform the defined task.

When a program calls a function, the program control is transferred to the called function. A called function performs a defined task and when its return statement is executed or when its function-ending closing brace is reached, it returns the program control back to the main program.

To call a function, you simply need to pass the required parameters along with the function name, and if the function returns a value, then you can store the returned value.







Function Prototypes
A function can be declared before it is defined, called a function prototype.

Function prototypes have the form:
return-type function-name(parameter declaration);

It is an error if the definition of a function or any uses of it do not agree with its prototype.

The word void must be used for function prototypes with an explicitly empty list.

Parameter names in prototypes and definitions need not agree and parameter names are optional in a function prototype

The order and type of
the arguments must match in the declaration, definition, and
function call.



Recursion
Recursion is the process of repeating items in a self-similar way. In programming languages, if a program allows you to call a function inside the same function, then it is called a recursive call of the function.

void recursion() {
   recursion(); /* function calls itself */
}

int main() {
   recursion();
}

The C programming language supports recursion, i.e., a function to call itself. But while using recursion, programmers need to be careful to define an exit condition from the function, otherwise it will go into an infinite loop.

Recursive functions are very useful to solve many mathematical problems, such as calculating the factorial of a number, generating Fibonacci series, etc.
