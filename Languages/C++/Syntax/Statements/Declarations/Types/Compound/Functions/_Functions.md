A C++ program is a collection of one or more subprograms, called functions.

For clarification of the subroutine terminology and concepts see:
[Programming Methods\Fundamentals\Constructs\Declarations\Subroutine]



### C++ Functions
Functions are C++'s primary method of abstraction, turning a group of statements into a cohesive operation.

For general information regarding functions, see:
[Programming Methods\Fundamentals\Constructs\Declarations\Subroutine\_Subroutine.md]

In the context of C++ functions are a named collection of statements, which executes sequentially, defining a relationship that generally consists of an input, processing steps, and an output.

  The input, called parameters, are data values provided to the function when it is called.

  The processing steps are performed on input data by a collection of statements called the function body.

  The output, called a return value, is generally the outcome of the processing steps operating on the provided function input, and is returned to the program that called the function.

Every C++ program contains one or more functions. C++ program execution begins with the first statement in a special function called main and typically terminates (finishes running) when the last statement inside function main is executed (though errors may cause the program to abort early).

While a program can theoretically do all computation necessary within main, for all but the most simple of programs, this leads to code that is cluttered, difficult to debug, and hard to reuse.

To accomplish most tasks, programmers write their own functions.



### Declaring a Function
Functions cannot be called before they are declared.

Function declarations are optional if the function is defined before it is called.

C++ programmers customarily place the function main( ... ) before all other user-defined functions. 

However, this organization could produce a compilation error because functions are compiled in the order in which they appear in the program. For example, if the function main is placed before a function called "sortArray( ... )", the identifier "sortArray" will be undefined when the function main is compiled. 

To work around this problem of undeclared identifiers, we place function declarations before any function definition (including the definition of main).

While function declarations are optional, they allow a function to be called before the implementation is defined. Known as forward declaration, this allows us to tell the compiler about the existence of an identifier before actually defining the value of that identifier. 

Once declared, a function can be called so long as you provide a definition somewhere in your program the compiler tool chain can direct execution appropriately.

A function declaration specifies a function’s interface, also called the function signature, without actually defining the function completely.

This interface includes all types involved (the return type and the type of its parameters), to indicate that this is a forward declaration only, known as a function prototype,  we replace the body of the function (the block of statements) with an ending semicolon and must define the function somewhere else in the source code:

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






https://stackoverflow.com/questions/67728450/why-is-it-legal-to-change-function-prototype-after-its-definition

int test();
int test(){
 return 5;
}
int test(int in);

int main() {
   return test();
}

I know it's ok to have multiple (and similar) declarations of a function, and only 1 single definition.

My question is related to a declaration after its own definition. Does the compiler pick the last prototype it has encountered as the true prototype? even if it comes father its full definition?

This doesn't compile with the error saying: error: too few arguments to function 'test'



There are three declarations of test in your sample code:

    int test(); is a declaration that is not a prototype1 or a definition2.
    int test() { return 5; } is a declaration that is a definition of the function.
    int test(int in); is a declaration that is a prototype for the function.

The plain declaration, number 1, is incomplete.3 It leaves it unstated whether there are any parameters or what their types are. This declaration can be completed by either declaration 2 or declaration 3, but not by both. If both 2 and 3 are present, a compiler should give you a warning or error message.4

Specifically, to answer your question “Why is it legal to change function prototype after its definition?”: After an incomplete declaration, you can change what is known about the function type by adding more information, using either an old-style definition or a modern prototype. You cannot make changes other than adding more information.5 (After a prototype or a definition, the function type is complete, and you cannot make any changes.)

Declaration 2 matches an old style of function definition in which the parameters were defined after the closing ) and before the opening {:

return-type name-of-function(names-of-parameters)
declarations of parameters
{
    body-of-function
}

For example:

int test(n, x)
int n;
double x;
{
    …
}

When there are no parameters in this style of definition, it means the function takes no parameters. Note the difference:

    int test(); does not say what the parameters are, not even how many there are.
    int test() { return 5; } says there are no parameters.

As you can see, these are compatible: Not stating how many parameters there are is compatible with saying there are no parameters.6

Declaration 3 is a modern declaration that says there is one parameter, with type int. As with 2, declarations 1 and 3 are compatible: Not stating how many parameters there are or what types they might have is compatible with saying there is one parameter of type int.

However, declarations 2 and 3 are incompatible:

    Declaration 2 says there are no parameters.
    Declaration 3 says there is one parameter.

Footnotes

1 A function prototype declares the types of its parameters. Since () is empty, there are no parameter types declared. (Due to C history, () in a function declaration means nothing is said about the parameters, and (void) is a prototype saying there are no parameters.)

2 A function definition includes the body of the function, the brace-enclosed compound-statement containing the code the function executes.

3 “Incomplete” is used here in the ordinary English sense, not the sense in which the C standard applies to object types.

4 This is required by the constraint in C 2018 6.7 4: “All declarations in the same scope that refer to the same object or function shall specify compatible types.”

5 There may be some minor changes possible. For example, qualifiers such as const can be added to or removed from parameters, although this does not change the function type for purposes of compatibility.

6 Specific rules for function type compatibility are in C 2018 6.7.6.3 15.
