#include <iostream>

int main()
{
  std::cout << "Hello, World!" << std::endl;
}

It is tradition to begin discussion with a HelloWorld program
which prints the phrase “Hello, World!”

This is a small program that contains many of C++ program's common features:
1. This program begins with “#include <iostream>”:
a. This tells the compiler that we are going to use the functions defined in iostream file.
Cpp language provide a number of predefined files, which contain functions that are commonly used by programmer.

For this example std::cout and std::endl are defined by the iostream file
used to print “Hello, World!”

2. Next comes the method “int main()”:
a. A method is a set of statements that are executed to give desire
result.
b. main() is a special method of a class this is the entry point of the
application.
c. The int keyword means that this method is going to return an integer
value in our case it is 0.

3. “std::cout << "Hello, World!" << std::endl;”, is a system providedoperator(object) which will print “Hello, World! ” to the standard output and will print next line char in the end.
