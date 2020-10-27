## Defining Functions
Functions enable you to divide the content of your application into functional units that can be invoked in a sequence of your choosing.

A function must be declared before it can be used.

A function declaration or function prototype gives the type of the value returned (if any), the name of the function, and the number and types of the arguments that must be supplied in a call.

return_type function_name( parameter list );

A function definition includes the function's body

return_type function_name( parameter list ) {
   body of the function
}



## main()
Every C++ program must have exactly one global function named main().
The program starts by executing that function. The int integer value returned by main(), if any, is the program’s return value to ‘‘the system.’’

If no value is returned, the system will receive a value indicating successful completion, a zero. A nonzero value from main() indicates failure.


## Function Composition
We want our code to be comprehensible, because that is the first step on the way to maintainability.

The first step to comprehensibility is to break computational tasks into meaningful chunks (represented as functions and classes) and name those. Such functions then provide the basic vocabulary of computation, just as the types (built-in and user-defined) provide the basic vocabulary of data.

Defining a function is the way you specify how an operation is to be done.

Next, we can compose functions representing common or specialized tasks into larger computations.

The number of errors in code correlates strongly with the amount of code and the complexity of the code. Both problems can be addressed by using more and shorter functions. Using a function to do a specific task often saves us from writing a specific piece of code in the middle of other code;
making it a function forces us to name the activity and document its dependencies.


## Conflicts
If two functions are defined with the same name, but with different argument types, the compiler will choose the most appropriate function to invoke for each call

If two alternative functions could be called, but neither is better than the other, the call is deemed
ambiguous and the compiler gives an error. For example:

void print(int, double);
void print(double, int);

void user2() {
  print(0,0); // error: ambiguous
}


## Arguments
The semantics of argument passing are identical to the semantics of initialization, argument types are checked and implicit argument type conversion takes place when necessary


 #include <iostream>        //include I/O stream library declarations
using namespace std;        //make names from std visible without std::
double square(double x) {
  return x*x;
}

void print_square(double x) {
cout << "the square of " << x << " is " << square(x) << "\n";
}

int main() {
  print_square(1.234); // print: the square of 1.234 is 1.52276
}

The value of such compile-time checking and type conversion should not be underestimated.

default arguments can be assigned a value when declared
double Area(double radius, double pi = 3.14);

The function Area() can be invoked as
if the second parameter didn’t exist:
Area(radius);
In this case, the second parameter defaults to the value of 3.14. However, when required,
the same function can be invoked using two arguments:
Area(radius, 3.14159); // more precise pi


You can have multiple parameters with default values; however, these should all be at the tail end of the parameter list.

Functions don’t restrict you to passing values one at a time; you can pass an array of
values to a function. You can create two functions with the same name and return value
but different parameters. You can program a function such that its parameters are not
created and destroyed within the function call; instead, you use references that are
valid even after the function has exited so as to allow you to manipulate more data or
parameters in a function call.

Functions with the same name and return type but with different parameters or set of
parameters are said to be overloaded functions.  Overloaded functions can be quite useful in applications where a function with a particular name that produces a certain type of output might need to be invoked with different sets of parameters.

Say you need to be writing an application that computes the area of a circle and the area of a cylinder.
The function that computes the area of a circle needs a parameter—the radius. The
other function that computes the area of the cylinder needs the height of the cylinder in
addition to the radius of the cylinder. Both functions need to return the data of the same
type, containing the area. So, C++ enables you to define two overloaded functions, both
called Area, both returning double, but one that takes only the radius as input and
another that takes the height and the radius as input parameters

Passing Arguments by Reference

when you declare a parameter that takes an argument by reference. A form of the function Area() that computes and returns the area as a parameter by reference looks like this:
// output parameter result by reference
void Area(double radius, double& result)
{
result = Pi * radius * radius;
}

Don’t miss the ampersand (&) next
to the second parameter result. This sign indicates to the compiler that the second
argument should NOT be copied to the function; instead, it is a reference to the variable
being passed. The return type has been changed to void as the function no longer supplies the area computed as a return value, rather as an output parameter by reference.

A function can return only one value using the return statement. So, if your function needs to perform operations that
affect many values required at the caller, passing arguments
by reference is one way to get a function to supply those many
modifications back to the calling module.

Pointers are an effective way to pass memory space that contains relevant data for
functions to work on. The memory space shared can also return the result of an
operation. When using a pointer with functions, it becomes important to ensure that the
called function is only allowed to modify parameters that you want to let it modify, but
not others. For example, a function that calculates the area of a circle given radius sent as
a pointer should not be allowed to modify the radius. This is where you use the keyword
const to control what a function is allowed to modify




Call Type & Description
1 	Call by Value

This method copies the actual value of an argument into the formal parameter of the function. In this case, changes made to the parameter inside the function have no effect on the argument.

2 	Call by Pointer

This method copies the address of an argument into the formal parameter. Inside the function, the address is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.

3 	Call by Reference

This method copies the reference of an argument into the formal parameter. Inside the function, the reference is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.

By default, C++ uses call by value to pass arguments.

A function cannot be called unless it has been previously declared.

A function declaration may contain argument names. This can be a help to the reader of a program, but unless the declaration is also a function definition, the compiler simply ignores such names.

For example:
double sqrt(double d); //return the square root of d
double square(double); //return the square of the argument

The type of a function consists of its return type and the sequence of its argument types. For example:

double get(const vector<double>& vec, int index); // type: double(const vector<double>&,int)

A function can be a member of a class.
For such a member function, the name of its class is also part of the function type. For example:
char& String::operator[](int index); // type: char& String::(int)

How Function Calls Are Handled
by the Microprocessor
A function call essentially means that the microprocessor jumps to executing the next
instruction belonging to the called function at a nonsequential memory location. After it
is done with executing the instructions in the function, it returns to where it left off. To
implement this logic, the compiler converts your function call into a CALL instruction
for the microprocessor. This instruction is accompanied by the address in memory the
next instruction needs to be taken from—this address belongs to your function routine.
When the microprocessor encounters CALL, it saves the position of the instruction to be
executed after the function call on the stack and jumps to the memory location contained
in the CALL instruction.
As the stack grows upward, the stack pointer always increments as it grows and points to the top of the stack.
The nature of the stack makes it optimal for handling function calls. When a function
is called, all local variables are instantiated on the stack—that is, pushed onto the
stack. When the function ends, they’re simply popped off it, and the stack pointer
returns to where it originally was.


This memory location contains instructions belonging to the function. The
microprocessor executes them until it reaches the RET statement (the microprocessor’s
code for return programmed by you). The RET statement results in the microprocessor
popping that address from the stack stored during the CALL instruction. This address
contains the location in the calling function where the execution needs to continue from.
Thus, the microprocessor is back to the caller and continues where it left off.

However, what if your function is a very simple one like the following?
double GetPi()
{
return 3.14159;
}The overhead of performing an actual function call on this might be quite high for the
amount of time spent actually executing GetPi(). This is why C++ compilers enable the
programmer to declare such functions as inline. Keyword inline is the programmers’
request that these functions be expanded inline where called.
inline double GetPi()
{
return 3.14159;
}
Functions that perform simple operations like doubling a number are good candidates for
being inlined, too.

Compilers typically see this keyword
as a request to place the contents of the function directly where the function has been invoked which increases the execution speed of the code.

Classifying functions as inline can also result in a lot of code bloat, especially if the
function being inline does a lot of sophisticated processing. Using the inline keyword
should be kept to a minimum and reserved for only those functions that do very little and
need to do it with minimal overhead, as demonstrated earlier.

Automatic Return Type Deduction

Starting with C++14, the same
applies also to functions. Instead of specifying the return type, you would use auto and
let the compiler deduce the return type for you on the basis of return values you program.

Functions that rely on automatic return type deduction need to
be defined (i.e., implemented) before they’re invoked. This is
because the compiler needs to know a function’s return type at
the point where it is used. If such a function has multiple return
statements, they need to all deduce to the same type. Recursive
calls need to follow at least one return statement.

Lambda Functions

Lambda functions were introduced in C++11 and help in the usage of STL algorithms to
sort or process data. Typically, a sort function requires you to supply a binary predicate.
This is a function that compares two arguments and returns true if one is less than the
other, else false, thereby helping in deciding the order of elements in a sort operation.
Such predicates are typically implemented as operators in a class, leading to a tedious bit
of coding. Lambda functions can compact predicate definitions

The syntax of a lambda function is the following:
[optional parameters](parameter list){ statements; }
