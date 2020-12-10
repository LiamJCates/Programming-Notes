## main()
Every C++ program must have exactly one global function named main().
The program starts by executing that function.
This function is defined as the program’s entry point, the function invoked at program startup.

Accepting input from the command line, a given program uses the main function entry point to begin execution of the instructions specified therein, the  program then exits by returning the integer exit code to the operating system.

Exit codes are integer values that the operating system uses to determine how well a program ran. Generally, a zero (0) exit code means the program ran successfully. Other exit codes might indicate a problem. To return other exit codes would require a return statement. Having a return statement in main is optional; the exit code defaults to 0.


### main parameters
Programs can accept any number of environment-provided arguments called command line parameters upon startup.
Users pass command line parameters to programs to customize their
behavior.

You can choose whether your program handles command line parameters by how you declare main.

You can access command line parameters within main by adding arguments to your main declaration.
There are three valid varieties of overload for main:

int main();
int main(int argc, char* argv[]);
int main(int argc, char* argv[], impl-parameters);


The second overload accepts two parameters, argc and argv:
  The first argument, argc, is a non-negative number corresponding to the number of elements in argv. The environment calculates this automatically: you don’t have to provide the number of elements in argc.
  The second argument, argv, is an array of pointers to null-terminated strings that corresponds to an argument passed in from the execution environment.

The third overload is an extension of the second overload:
  it accepts an arbitrary number of additional implementation parameters. This way, the target platform can offer some additional arguments to the program. Implementation parameters aren’t common in modern desktop environments.

Usually, an operating system passes the full path to the program’s
executable as the first command line argument. This behavior depends
on your operating environment. On macOS, Linux, and Windows, the executable’s path is the first argument. The format of this path depends on
the operating system.







### main return value
The int integer value returned by main(), if any, is the program’s return value to ‘‘the system’’, called the exit status.

What the values represent is environment defined. On modern desktop systems, for example, a zero return value corresponds with a successful program execution.  A nonzero value from main() indicates failure.

If no value is returned, the system will receive a value indicating successful completion, a zero.


Accessing the Command-Line Parameters
#include <iostream>
#include <stdlib.h>
int main(int argc, char *argv[])
{
for (int index=0; index < argc; index++)
{
cout << argv[index] << endl;
}
return 0;
}
