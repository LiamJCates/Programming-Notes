Normally you are at liberty to give functions whatever
names you like, but "main" is special-your program begins executing at the beginning of main. This means that every program must have a main somewhere.

This main function typically calls other functions.
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
