A function is a group of statements that together perform a task. Every C program has at least one function, which is main(), and all the most trivial programs can define additional functions.

You can divide up your code into separate functions. How you divide up your code among different functions is up to you, but logically the division is such that each function performs a specific task.

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

Return Type − A function may return a value. The return_type is the data type of the value the function returns. Some functions perform the desired operations without returning a value. In this case, the return_type is the keyword void.

Function Name − This is the actual name of the function. The function name and the parameter list together constitute the function signature.

Parameters − A parameter is like a placeholder. When a function is invoked, you pass a value to the parameter. This value is referred to as actual parameter or argument. The parameter list refers to the type, order, and number of the parameters of a function. Parameters are optional; that is, a function may contain no parameters.

Function Body − The function body contains a collection of statements that define what the function does.


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


Passing Arrays as Function Arguments in C

Previous Page
Next Page  

If you want to pass a single-dimension array as an argument in a function, you would have to declare a formal parameter in one of following three ways and all three declaration methods produce similar results because each tells the compiler that an integer pointer is going to be received. Similarly, you can pass multi-dimensional arrays as formal parameters.
Way-1

Formal parameters as a pointer −

void myFunction(int *param) {
   .
   .
   .
}

Way-2

Formal parameters as a sized array −

void myFunction(int param[10]) {
   .
   .
   .
}

Way-3

Formal parameters as an unsized array −

void myFunction(int param[]) {
   .
   .
   .
}









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

It is an error if the definition of a function or any uses of it do not agree with its
prototype.


The word void must be used for function prototypes with an explicitly empty list.

Parameter names in prototypes and definitions need not agree. Indeed, parameter names are optional in a function prototype
