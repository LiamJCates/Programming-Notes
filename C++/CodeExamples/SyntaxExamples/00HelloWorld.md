#include <iostream>
int main()
{
  std::cout << "Hello, World!" << std::endl;
}

It is tradition to discuss a HelloWorld program in the start which will print the phrase “Hello, World!” to the output screen.

This is a small program but it contains many common features of all the C++ programs.
1. This program begins with “#include <iostream>”:
a. This tells the compiler that we are going to use the functions defined in iostream file. Cpp language provide a number of predefined files, which contain functions that are commonly used by programmer.
For example std::cout is defined inside iostream file which will be
used to print “Hello, World!” to the output screen.

2. Next comes the method “int main()”:
a. A method is a set of statements that are executed to give desire
result.
b. main() is a special method of a class this is the entry point of the
application.
c. The int keyword means that this method is going to return an integer
value in our case it is 0.

3. “std::cout << "Hello, World!" << std::endl;”, is a system providedoperator(object) which will print “Hello, World! ” to the standard output and will print next line char in the end.
