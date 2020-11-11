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


C functions cannot be split between files












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












RETURN
A function must return a value, and this value must be of the type listed by the function definition.

Some functions return a useful value; others, are used only for their effect and return
no value


int is the default return type and could be omitted

However, it is good programming practice to always declare a return type in the function definition.


return statement form:
return expression;

The value of expression, if present, is returned to the calling function. If expression is omitted, the return value of the function is undefined. The expression, if present, is evaluated and then converted to the type returned by the function. When a return statement contains an expression in functions that have a void return type, the compiler generates a warning, and the expression isn't evaluated.

If no return statement appears in a function definition, control automatically returns to the calling function after the last statement of the called function is executed. In this case, the return value of the called function is undefined. If the function has a return type other than void, it's a serious bug, and the compiler prints a warning diagnostic message. If the function has a void return type, this behavior is okay, but may be considered poor style. Use a plain return statement to make your intent clear.

An empty return statement or "falling off the end", reaching the terminating right brace causes control, but no useful value to be returned to the caller

The return; statement is used with a function that has a no return type

Typically, a return value of zero implies normal termination; non-zero values signal
unusual or erroneous termination conditions

















Function Prototypes
A function can be declared before it is defined, called a function prototype.

Function prototypes have the form:
return-type function-name(parameter declaration);

It is an error if the definition of a function or any uses of it do not agree with its
prototype.


The word void must be used for function prototypes with an explicitly empty list.

Parameter names in prototypes and definitions need not agree. Indeed, parameter names are optional in a function prototype
