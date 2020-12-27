## main()
Every C++ program must have exactly one global function named main().

When starting a C++ program, execution starts by invoking the function main(). As such, main() is defined as the program’s entry point.

As any other function, main() is a transformation that defines a relationship between input and output

Typically, main():
accepts command-line strings as input
returns an integer exit code upon termination as output




### main parameters
Programs can accept any number of environment-provided arguments called command line parameters upon startup.
Users pass command line parameters to programs to customize their behavior.

You can determine whether your program handles command line parameters by how you declare main().

C++ specifies three valid overloads:
  int main();
  int main(int argc, char* argv[]);
  int main(int argc, char* argv[], impl-parameters);

The first accepts no parameters

The second overload accepts two parameters, argc and argv:
  The first argument, argc, is a non-negative number corresponding to the number of elements in argv.
  The second argument, argv, is an array of pointers to null-terminated strings that corresponds to arguments passed in from the execution environment.

The third overload is an extension of the second overload:
  it accepts an arbitrary number of additional implementation parameters. This way, the target platform can offer some additional arguments to the program. Implementation parameters aren’t common in modern desktop environments.

Usually, an operating system passes the full path to the program’s executable as the first command line argument. This behavior depends on your operating environment. On macOS, Linux, and Windows, the executable’s path is the first argument. The format of this path depends on the operating system.









### main return value
The integer value returned by main() is the program’s return value to ‘‘the system’’, called the exit status.

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
