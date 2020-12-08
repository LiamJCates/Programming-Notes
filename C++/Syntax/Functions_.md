In general, a C++ program is a collection of one or more subprograms, called functions. Roughly speaking, a subprogram or a function is a collection of statements, and when it is activated, or executed, it accomplishes something. Some functions, called predefined or standard functions, are already written and are provided as part of the system. But to accomplish most tasks, programmers must learn to write their own functions.


Functions are blocks of code that accept input and return output to their callers. input objects called are called parameters or arguments output objects


To call (or invoke) a function, you use the name of the desired function, parentheses, and a comma-separated list of the required parameters.

The compiler reads files from top to bottom, so the function’s declaration must appear before its point of first use.


Because C++ does not provide every function that you will ever need and designers cannot possibly know a user’s specific needs, you must learn to write your own
functions.

User-defined functions in C++ are classified into two categories:
Value-returning functions — functions that have a return type. These functions return a value of a specific data type
Void functions — functions that do not have a return type. These functions do not use a return statement to return a value


## Defining Functions
Functions enable you to divide the content of your application into functional units that can be invoked in a sequence of your choosing.

A function has three main parts:
✦ Inputs: The function can receive data through its inputs. When you create a function, you can have as many inputs as you want (or even zero, if necessary).
✦ Processor: The processor is the actions the function takes.
✦ Output: A function can return something when it has finished processing.


A function must be declared before it can be used.

A function declaration or function prototype gives the type of the value returned (if any), the name of the function, and the number and types of the arguments that must be supplied in a call. These elements are also referred to as the function header.

Function declarations have the following familiar form:
prefix-modifiers return-type func-name(arguments) suffix-modifiers;


You can provide a number of optional modifiers (or specifiers) to functions.
Modifiers alter a function’s behavior in some way. Some modifiers appear at
the beginning in the function’s declaration or definition (prefix modifiers),
whereas others appear at the end (suffix modifiers). The prefix modifiers
appear before the return type. The suffix modifiers appear after the argument list.
There isn’t a clear language reason why certain modifiers appear as
prefixes or suffixes: because C++ has a long history, these features evolved
incrementally




A function definition includes the function's body:

return-type function_name(par-type1 par_name1, ..., par-typeN par_nameN) {
  //statements
  return return-value;
}

### prototype
C++ programmers customarily place the function main before all other
user-defined functions. However, this organization could produce a compilation
error because functions are compiled in the order in which they appear in the program. For example, if the function main is placed before the function larger, the
identifier larger will be undefined when the function main is compiled. To work
around this problem of undeclared identifiers, we place function prototypes before
any function definition (including the definition of main).Value-Returning Functions | 361
6
The function prototype is not a definition. It gives the program the name of the function, the number and data types of the parameters, and the data type of the returned
value: just enough information to let C++ use the function. It is also a promise that
the full definition will appear later in the program. If you neglect to write the definition of the function, the program may compile, but it will not execute.
Function Prototype: The function heading, terminated by a semicolon, ;, without
the body of the function.

Function prototypes typically appear before any function definition, so the compiler complies
these first. The compiler can then correctly translate a function call. However, when
the program executes, the first statement in the function main always executes first,
regardless of where in the program the function main is placed. Other functions execute only when they are called.


## main()
Every C++ program must have exactly one global function named main().
The program starts by executing that function. The int integer value returned by main(), if any, is the program’s return value to ‘‘the system.’’

If no value is returned, the system will receive a value indicating successful completion, a zero. A nonzero value from main() indicates failure.


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
Parameters provide a communication link between the calling function (such as
main) and the called function. They enable functions to manipulate different data
each time they are called. In general, there are two types of formal parameters: value
parameters and reference parameters.
Value parameter: A formal parameter that receives a copy of the content of the
corresponding actual parameter.
Reference parameter: A formal parameter that receives the location (memory
address) of the corresponding actual parameter.

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



## Passing Arguments by Reference

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


We can now formally present two definitions:
Formal Parameter: A variable declared in the function heading.
Actual Parameter: A variable or expression listed in a call to a function.

Call Type & Description
1 	Call by Value

This method copies the actual value of an argument into the formal parameter of the function. In this case, changes made to the parameter inside the function have no effect on the argument.

2 	Call by Pointer

This method copies the address of an argument into the formal parameter. Inside the function, the address is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.

3 	Call by Reference

This method copies the reference of an argument into the formal parameter. Inside the function, the reference is used to access the actual argument used in the call. This means that changes made to the parameter affect the argument.

By default, C++ uses call by value to pass arguments.

When we care about performance, we usually pass small values by-value and larger ones by-reference. Here ‘‘small’’ means ‘‘something that’s really cheap to copy.’’ Exactly what ‘‘small’’ means
depends on machine architecture, but ‘‘the size of two or three pointers or less’’ is a good rule of
thumb.




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





## How Function Calls Are Handled by the Microprocessor
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



## Inline
However, what if your function is a very simple one like the following?

int Max(int x, int y) {
   return (x > y)? x : y;
}

The overhead of performing an actual function call on this might be quite high for the amount of time spent actually executing Max.

This is why C++ compilers enable the programmer to declare such functions as inline. Keyword inline is the programmers’
request that these functions be expanded inline where called.

Compilers typically see this keyword as a request to place the contents of the function directly where the function has been invoked which increases the execution speed of the code.

To inline a function, place the keyword inline before the function name and define the function before any calls are made to the function. The compiler can ignore the inline qualifier in case defined function is more than a line.

 #include <iostream>

using namespace std;

inline int Max(int x, int y) {
   return (x > y)? x : y;
}

// Main function for the program
int main() {
   cout << "Max (20,10): " << Max(20,10) << endl;
   cout << "Max (0,200): " << Max(0,200) << endl;
   cout << "Max (100,1010): " << Max(100,1010) << endl;

   return 0;
}

### Problems with Inline
Any change to an inline function could require all clients of the function to be recompiled because compiler would need to replace all the code once again otherwise it will continue with old functionality.

Classifying functions as inline can also result in a lot of code bloat, especially if the
function being inline does a lot of sophisticated processing. Using the inline keyword
should be kept to a minimum and reserved for only those functions that do very little and
need to do it with minimal overhead, as demonstrated earlier.





## Value Return
Once we have computed a result, we need to get it out of the function and back to the caller. Again,
the default for value return is to copy and for small objects that’s ideal. We return ‘‘by reference’’
only when we want to grant a caller access to something that is not local to the function. For example:
class Vector {
public:
// ...
double& operator[](int i) { return elem[i]; } // retur n reference to ith element
private:
double∗ elem; // elem points to an array of sz
// ...
};
The ith element of a Vector exists independently of the call of the subscript operator, so we can
return a reference to it.
On the other hand, a local variable disappears when the function returns, so we should not
return a pointer or reference to it:
int& bad()
{
int x;
// ...
return x; // bad: return a reference to the local var iable x
}
Fortunately, all major C++ compilers will catch the obvious error in bad().
Returning a reference or a value of a ‘‘small’’ type is efficient, but how do we pass large
amounts of information out of a function? Consider:44 Modularity Chapter 3
Matrix operator+(const Matrix& x, const Matrix& y)
{
Matrix res;
// ... for all res[i,j], res[i,j] = x[i,j]+y[i,j] ...
return res;
}
Matrix m1, m2;
// ...
Matrix m3 = m1+m2; // no copy
A Matrix may be very large and expensive to copy even on modern hardware. So we don’t copy, we
give Matrix a move constructor (§5.2.2) and very cheaply move the Matrix out of operator+(). We do
not need to regress to using manual memory management:
Matrix∗ add(const Matrix& x, const Matrix& y) // complicated and error-prone 20th century style
{
Matrix∗ p = new Matrix;
// ... for all *p[i,j], *p[i,j] = x[i,j]+y[i,j] ...
return p;
}
Matrix m1, m2;
// ...
Matrix∗ m3 = add(m1,m2); // just copy a pointer
// ...
delete m3; // easily forgotten
Unfortunately, returning large objects by returning a pointer to it is common in older code and a
major source of hard-to-find errors. Don’t write such code. Note that operator+() is as efficient as
add(), but far easier to define, easier to use, and less error-prone.
If a function cannot perform its required task, it can throw an exception (§3.5.1). This can help
avoid code from being littered with error-code tests for ‘‘exceptional problems.’’
The return type of a function can be deduced from its return value. For example:
auto mul(int i, double d) { return i∗d; } // here, "auto" means "deduce the return type"
This can be convenient, especially for generic functions (function templates; §6.3.1) and lambdas
(§6.3.3), but should be used carefully because a deduced type does not offer a stable interface: a
change to the implementation of the function (or lambda) can change the type.





## Automatic Return Type Deduction

Starting with C++14, the same
applies also to functions. Instead of specifying the return type, you would use auto and
let the compiler deduce the return type for you on the basis of return values you program.

Functions that rely on automatic return type deduction need to
be defined (i.e., implemented) before they’re invoked. This is
because the compiler needs to know a function’s return type at
the point where it is used. If such a function has multiple return
statements, they need to all deduce to the same type. Recursive
calls need to follow at least one return statement.








## Structured Binding
A function can return only a single value, but that value can be a class object with many members.
This allows us to efficiently return many values. For example:
struct Entry {
string name;
int value;
};Section 3.6.3 Structured Binding 45
Entr y read_entry(istream& is) // naive read function (for a better version, see §10.5)
{
string s;
int i;
is >> s >> i;
return {s,i};
}
auto e = read_entry(cin);
cout << "{ " << e.name << " , " << e.value << " }\n";
Here, {s,i} is used to construct the Entr y return value. Similarly, we can ‘‘unpack’’ an
Entr y’s members into local variables:
auto [n,v] = read_entry(is);
cout << "{ " << n << " , " << v << " }\n";
The auto [n,v] declares two local variables n and v with their types deduced from
read_entr y()’s return type. This mechanism for giving local names to members of a class
object is called structured binding.
Consider another example:
map<string,int> m;
// ... fill m ...
for (const auto [key,value] : m)
cout << "{" << key "," << value << "}\n";
As usual, we can decorate auto with const and &. For example:
void incr(map<string,int>& m) // increment the value of each element of m
{
for (auto& [key,value] : m)
++value;
}
When structured binding is used for a class with no private data, it is easy to see how the binding is
done: there must be the same number of names defined for the binding as there are nonstatic data
members of the class, and each name introduced in the binding names the corresponding member.
There will not be any difference in the object code quality compared to explicitly using a composite
object; the use of structured binding is all about how best to express an idea.
It is also possible to handle classes where access is through member functions. For example:
complex<double> z = {1,2};
auto [re,im] = z+2; // re=3; im=2
A complex has two data members, but its interface consists of access functions, such as real() and
imag(). Mapping a complex<double> to two local variables, such as re and im is feasible and efficient, but the technique for doing so is beyond the scope of this book.










## Lambda Functions

Lambda functions were introduced in C++11 and help in the usage of STL algorithms to
sort or process data. Typically, a sort function requires you to supply a binary predicate.
This is a function that compares two arguments and returns true if one is less than the
other, else false, thereby helping in deciding the order of elements in a sort operation.
Such predicates are typically implemented as operators in a class, leading to a tedious bit
of coding. Lambda functions can compact predicate definitions

The syntax of a lambda function is the following:
[optional parameters](parameter list){ statements; }
