## Defining Functions
Functions enable you to divide the content of your application into functional units that
can be invoked in a sequence of your choosing. A function, when invoked, typically
returns a value to the invoking/calling function.

A function declaration gives the name of the function, the type of the value returned (if any), and the number and types of the arguments that must be supplied in a call.

Functions in C++ need to return a value unless explicitly specified with a void return type

## main()
Every C++ program must have exactly one global function named main().
The program starts by executing that function. The int integer value returned by main(), if any, is the program’s return value to ‘‘the system.’’

If no value is returned, the system will receive a value indicating successful completion. A nonzero value from main() indicates failure.


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
