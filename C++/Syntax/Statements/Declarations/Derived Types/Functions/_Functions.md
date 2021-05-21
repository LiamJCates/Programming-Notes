A C++ program is a collection of one or more subprograms, called functions.

For clarification of the subroutine terminology and concepts see:
[Programming Methods\Fundamentals\Constructs\Declarations\Subroutine]



### C++ Functions
In C++, statements are grouped into units called functions.

Function: a named collection of statements which executes sequentially.

For general information regarding functions, see:
[Programming Methods\Fundamentals\Constructs\Declarations\Subroutine\_Subroutine.md]

Like a C++ program, a function is a relationship that generally consists of input values, processing steps, and an output value.

A function takes some input values, performs some processing steps, and produces an output:
  The input, called parameters, are date values provided to the function when it is called by the program that uses the function.
  The processing steps are performed by the collection of statements called the function body.
  The output, called a return value, is the generally the outcome of the processing steps operating on the provided function input, and is returned to the program that called the function.


C++ program execution begins with the first statement in a special function called main and typically terminates (finishes running) when the last statement inside function main is executed (though errors may cause the program to abort early).

While a simple program can theoretically do all computation necessary to complete a task within main, for all but the most simple of programs, this leads to code that is cluttered, difficult to debug, and hard to reuse.

To accomplish most tasks, programmers must learn to write their own functions.



### Benefits
Functions provide a number of benefits that make them extremely useful in programs of non-trivial length or complexity.

#### Organization
As programs grow in complexity, having all the code live inside the main() function becomes increasingly complicated. A function is almost like a mini-program that we can write separately from the main program, without having to think about the rest of the program while we write it. This allows us to reduce a complicated program into smaller, more manageable chunks, which reduces the overall complexity of our program.

#### Reusability
Once a function is written, it can be called multiple times from within the program. This avoids duplicated code (“Don’t Repeat Yourself”) and minimizes the probability of copy/paste errors. Functions can also be shared with other programs, reducing the amount of code that has to be written from scratch (and retested) each time.

#### Testing
Because functions reduce code redundancy, there’s less code to test in the first place. Also because functions are self-contained, once we’ve tested a function to ensure it works, we don’t need to test it again unless we change it. This reduces the amount of code we have to test at one time, making it much easier to find bugs (or avoid them in the first place).

#### Extensibility
When we need to extend our program to handle a case it didn’t handle before, functions allow us to make the change in one place and have that change take effect every time the function is called.

#### Abstraction
In order to use a function, you only need to know its name, inputs, outputs, and where it lives. You don’t need to know how it works, or what other code it’s dependent upon to use it. This lowers the amount of knowledge required to use other people’s code (including everything in the standard library).



### Declaring a Function
In C++, identifiers can only be used in expressions once they have been declared. For example, some variable x cannot be used before being declared with a statement, such as:

  int x;

The same applies to functions. Functions cannot be called before they are declared.

The compiler reads files from top to bottom, so the function’s declaration must appear before its point of first use.

Typically, functions must be declared before the main function, the program entry point, from which other functions are called.

C++ programmers customarily place the function main before all other user-defined functions. However, this organization could produce a compilation error because functions are compiled in the order in which they appear in the program.

Function declarations are optional as long as the function is defined before it is called.

For example, if the function main is placed before a function called "sortArray", the identifier "sortArray" will be undefined when the function main is compiled. To work around this problem of undeclared identifiers, we place function prototypes before any function definition (including the definition of main).

While function declarations are optional, they allow you to declared functions before you define the implementation. Known as forward declaration, this allows us to tell the compiler about the existence of an identifier before actually defining the identifier. Once declared a function can be called so long as you provide a definition later in your program the compiler tool chain can direct execution appropriately.

A function declaration specifies a function’s interface, also called the function signature, without actually defining the function completely.

This interface includes all types involved (the return type and the type of its parameters), to indicate that this is a forward declaration only, a function prototype,  we replace the body of the function (the block of statements) with an ending semicolon and must define the function somewhere else in the source code:

  return-type function-name (parameter-type1, ..., parameter-typeN) ;

#### Return Type
Simple function declarations begin with a return-type. This is the type of the value returned by the function, the type of value that a function call expression resolves to.

#### Name
The function name is the identifier used to reference the function in other parts of the program and, as an identifier, its specification follows the rules of identifier specification.

#### Parameters
A function declaration's parameter list defines the types of input values necessary to perform the function. Parameters can be specified with names like a variable, but we are not required to include names in the function prototype. If parameter names are specified, they are also not required to match those used in the later function definition. void can also be used in the function's parameter list to explicitly specify that the function takes no actual parameters when called. In C++, an empty parameter list can be used instead of void with same meaning, but the use of void in the argument list was popularized by the C language, where this is a requirement.

#### Example
For example, a function called protofunction with two int parameters can be declared with either of these statements:

  int protofunction (int first, int second);
  int protofunction (int, int);


In a function call, all arguments are evaluated before the function is called. Each argument is copied to the corresponding parameter in the function, then the function body begins to run.

When the function executes a return statement, the value in the statement is copied back to the caller, which can then use the value in an expression, assign it to a variable, and so on.

### Defining Functions
A function’s definition, in addition to the elements included in the declaration, defines its implementation, which consists of the statements the function executes, the name of zero or more parameters used during that execution and optionally a return statement that specifies the value to return to the calling function and must be of the type that matches the return type defined by the function signature:

```cpp
  return_type function_name(parameter-list)
  {
    //statements
  }
```

where:
  return-type is the type of the value returned by the function.
  function-name is the identifier by which the function can be called.
  parameters-list is a comma separated list of zero or more parameters. Each parameter consists of a type followed by an identifier.
  statements is the function's body, a curly brace delimited block of statements

A function definition also declares a function if it had not been previously declared by a matching function prototype.



### Function Calls

To call (or invoke) a function, you use the name of the desired function followed by parentheses "()". These parentheses must delimit (contain within them) a comma-separated list of values. These values must be in the same order and of the same type as the parameter list specified by the function definition (and, by extension, the function prototype if on has been specified).

function_name( parameter_list )

This is known as a function call expression, the values in the parameter list can be literals or values that the calling function has access to.

As with other expressions
  A function call resolves to a value, this value is of the type specified by the return type of the function definition.
  A function call is not a statement unless followed by a terminating semicolon
  The values the expression resolves to can be used as an operand within a larger expression.

For example, a function called sumThree, defined with an integer return type, and three integer parameters, as such:

```cpp
int sumThree(int a, int b, int c)
{
  return a + b + c;
}
```

would be called in a case such as this:

```cpp
int main()
{
  int n, x = 0, y = 1, z = 2;

  n = sumThree(x, y, z);
}
```

such that sumThree takes the three integer parameters, x, y, z, called a, b, and c within the function, performs the processing step, a + b + c, then returns the value to the calling function, main, where the return value is used as an operator in an assignment expression, to assign the returned value to another integer, n.

When a function call such as this is made with a previously defined function identifier followed by the function call operator (), which contains a parameter list with values of the proper type in the proper order, execution of statements in that function that contains it is suspended, in this case main, and execution jumps to the top of called function, in this case sumThree.
When a called function finishes, any expression using the return value of the function as an operand is resolved, in this case assignment of the return value to n, and execution jumps to the statement following the function call.


#### Function Classifications

Some terminology classifying functions:
  Value-returning: return a value to caller, specified by return type
  Void: return no value to caller, return type of void, which is a special type to represent the absence of value.
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
