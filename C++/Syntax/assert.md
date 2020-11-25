Terminating a Program with the assert Function

C11 includes a predefined function, assert, that
is useful in stopping program execution when certain elusive errors occur.

you can use the assert function to ensure that a program terminates with an appropriate error message indicating the type of error and the program
location where the error occurred.

However, C11 provides an effective
method to halt a program if required conditions are not met through the assert
function.
The syntax to use the assert function is:
assert(expression);

Here, expression is any logical expression. If expression evaluates to true, the
next statement executes. If expression evaluates to false, the program terminates
and indicates where in the program the error occurred.
The specification of the assert function is found in the header file cassert. Therefore, for a program to use the assert function, it must include the following statement:
#include <cassert>
A statement using the assert function is sometimes called an assert statement.


the assert statement not only
halts the program, but also identifies the expression where the assertion failed, the name
of the file containing the source code, and the line number where the assertion failed.

Although assert statements are useful during program development, after a program has been developed and put into use, if an assert statement fails for some reason, an end user would have no idea what the error means. Therefore, after you have
developed and tested a program, you might want to remove or disable the assert
statements. In a very large program, it could be tedious, and perhaps impossible, to
remove all of the assert statements that you used during development. In addition, if
you plan to modify a program in the future, you might like to keep the assert statements. Therefore, the logical choice is to keep these statements but to disable them.
You can disable assert statements by using the following preprocessor directive:
#define NDEBUG
This preprocessor directive #define NDEBUG must be placed before the directive
#include <cassert>.
