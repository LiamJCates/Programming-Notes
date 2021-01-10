A C++ program is a collection of one or more subprograms, called functions.

For clarification of the subroutine terminology and concepts see:
[Programming Methods\Fundamentals\Constructs\Declarations\Subroutine]



### C++ Functions
Functions enable you to divide the content of your application into functional units that can be invoked in a sequence of your choosing.

Some C++ functions, called predefined or standard functions, are already written and are provided as part of the system. But to accomplish most tasks, programmers must learn to write their own functions.

The primary and recommended way of passing information from one part of a program to another is through a function call.

The most common syntax to define a function is:

  return-type function-name ( parameters ) { statements }

where:
  return-type is the type of the value returned by the function.
  function-name is the identifier by which the function can be called.
  parameters is a comma seperated list of zero or more parameters. Each parameter consists of a type followed by an identifier.
  statements is the function's body a curly brace delimited block of statements



### Declaring a Function
In C++, identifiers can only be used in expressions once they have been declared. For example, some variable x cannot be used before being declared with a statement, such as:

  int x;

The same applies to functions. Functions cannot be called before they are declared.

The compiler reads files from top to bottom, so the function’s declaration must appear before its point of first use.

Typically, functions must be declared before the main function, the program entry point, from which other functions are called.

C++ programmers customarily place the function main before all other user-defined functions. However, this organization could produce a compilation error because functions are compiled in the order in which they appear in the program. For example, if the function main is placed before the function larger, the identifier larger will be undefined when the function main is compiled. To work around this problem of undeclared identifiers, we place function prototypes before any function definition (including the definition of main).

A function declaration specifies a function’s interface, also called a function prototype or signature, without actually defining the function completely. Naturally, the function shall be defined somewhere else in the source code.

This interface specification includes all types involved (the return type and the type of its parameters), and replaces the body of the function (the block of statements) with an ending semicolon.

  return-type function-name (parameter-type1, ..., parameter-typeN) ;

Function declarations begin with a return-type. This is the type of the value returned by the function, to which a function call expression resolves. If the function does not return a value, the type to be used is void, which is a special type to represent the absence of value.

This difference classifies C++ user-defined functions into two categories:
  Value-returning functions — return a value of their specified return type
  Void functions — have return type of void and do not return a value

The function name is the identifier used to reference the function in other parts of the program and its potential specification follows the rules of identifier specification.

A function declaration's parameter list does not need to include the parameter names, only their types. Parameter names can nevertheless be specified, but they are optional, and do not need to necessarily match those in the later function definition. void can also be used in the function's parameter list to explicitly specify that the function takes no actual parameters when called. n C++, an empty parameter list can be used instead of void with same meaning, but the use of void in the argument list was popularized by the C language, where this is a requirement.

For example, a function called protofunction with two int parameters can be declared with either of these statements:

int protofunction (int first, int second);
int protofunction (int, int);


Basic functions, declared at namespace scope outside of main(), are called non-member functions, or sometimes free functions. Member functions are specified as part of a class, called a class member.

Function declarations are optional. So why do they exist?

The answer is that you can use declared functions throughout your
code as long as they’re eventually defined somewhere. Your compiler tool
chain can figure it out.



### Function Calls
To call (or invoke) a function, you use the name of the desired function, parentheses, and a comma-separated list of values of order and type specified by the function's parameters.



### Defining Functions
A function’s definition, in addition to it's declaration, defines its implementation, which includes the statements the function executes, the name of zero or more parameters used during that execution and optionally a return statement:

  return-type function_name(par-type1 par_name1, ..., par-typeN par_nameN) {
    //statements
    return return-value;
  }

A function definition also declares a function if it had not been previously.



## Example

  #include <iostream>
  using namespace std;
  double square(double x) {
    return x*x;
  }

  void print_square(double x) {
  cout << "the square of " << x << " is " << square(x) << "\n";
  }

  int main() {
    print_square(1.234);
  }
