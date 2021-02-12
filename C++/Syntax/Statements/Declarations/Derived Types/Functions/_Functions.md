A C++ program is a collection of one or more subprograms, called functions.

For clarification of the subroutine terminology and concepts see:
[Programming Methods\Fundamentals\Constructs\Declarations\Subroutine]



### C++ Functions
In C++, statements are grouped into units called functions. A function is a reusable collection of statements that executes sequentially.

C++ program execution begins with the first statement in a special function called main and typically terminates (finishes running) when the last statement inside function main is executed (though they may abort early in some circumstances).

The C++ Standard Library is a library file, a collection of precompiled code that has been “packaged up” as part of C++, for reuse in other programs. It contains common functionality for reuse in programs. However, to accomplish most tasks, programmers must learn to write their own functions.



### Declaring a Function
In C++, identifiers can only be used in expressions once they have been declared. For example, some variable x cannot be used before being declared with a statement, such as:

  int x;

The same applies to functions. Functions cannot be called before they are declared.

The compiler reads files from top to bottom, so the function’s declaration must appear before its point of first use.

Typically, functions must be declared before the main function, the program entry point, from which other functions are called.

C++ programmers customarily place the function main before all other user-defined functions. However, this organization could produce a compilation error because functions are compiled in the order in which they appear in the program. For example, if the function main is placed before the function larger, the identifier larger will be undefined when the function main is compiled. To work around this problem of undeclared identifiers, we place function prototypes before any function definition (including the definition of main).

Function declarations are optional. However they allow you to declared functions before you define the implementation. This is called forward declaration, it allows us to tell the compiler about the existence of an identifier before actually defining the identifier. Once declared a function can be called so long as you provide a definition later in your program the compiler tool chain can direct execution appropriately.

A function declaration specifies a function’s interface, also called a function prototype or signature, without actually defining the function completely, indicating that the function shall be defined somewhere else in the source code.

This interface specification includes all types involved (the return type and the type of its parameters), and replaces the body of the function (the block of statements) with an ending semicolon.

  return-type function-name (parameter-type1, ..., parameter-typeN) ;

#### Return Type
Function declarations begin with a return-type. This is the type of the value returned by the function, to which a function call expression resolves. If the function does not return a value, the type to be used is void, which is a special type to represent the absence of value.

#### Name
The function name is the identifier used to reference the function in other parts of the program and its potential specification follows the rules of identifier specification.

#### Parameters
A function declaration's parameter list does not need to include the parameter names, only their types. Parameter names can nevertheless be specified, but they are optional, and do not need to necessarily match those in the later function definition. void can also be used in the function's parameter list to explicitly specify that the function takes no actual parameters when called. In C++, an empty parameter list can be used instead of void with same meaning, but the use of void in the argument list was popularized by the C language, where this is a requirement.

#### Example
For example, a function called protofunction with two int parameters can be declared with either of these statements:

  int protofunction (int first, int second);
  int protofunction (int, int);



### Function Calls
To call (or invoke) a function, you use the name of the desired function, parentheses, and a comma-separated list of values of order and type specified by the function's parameters.

When a function call is made, execution of statements in function that contains them is suspended, and execution jumps to the top of called function. When a called function finishes, execution jumps to the statement following the function call.



### Defining Functions
A function’s definition, in addition to the elements included in the declaration, defines its implementation, which includes the statements the function executes, the name of zero or more parameters used during that execution and optionally a return statement:

  return-type function_name(parameter-list) {
    //statements
  }

where:
  return-type is the type of the value returned by the function.
  function-name is the identifier by which the function can be called.
  parameters-list is a comma separated list of zero or more parameters. Each parameter consists of a type followed by an identifier.
  statements is the function's body a curly brace delimited block of statements

A function definition also declares a function if it had not been previously.



#### Function Classifications

Some terminology classifying functions:
  Value-returning: return a value to caller, specified by return type
  Void: return no value to caller, return type of void
  Non-member: declared at namespace scope, also called free functions.
  Member functions specified as a class member.
  User-defined: provided by the user
  Predefined: provided as part of the system, also called standard functions


#### Example

  #include <iostream>
  using namespace std;

  //A non-member value returning function
  double square(double x) {
    return x*x;
  }

  //A non-member void function
  void print_square(double x) {
    cout << "the square of " << x << " is " << square(x) << "\n";
  }

  int main() {
    print_square(1.234);
  }
