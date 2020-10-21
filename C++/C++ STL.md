C++ is a compiled language, this means, for a program to run, its source text has to be processed by a compiler, producing object files, which are combined by a linker yielding an executable program.

A C++ program typically consists of many source code files (called source files).

The ISO C++ standard defines two kinds of entities:
• Core language features, such as built-in types (e.g., char and int) and loops (e.g., for-statements and while-statements)
• Standard-library components, such as containers (e.g., vector and map) and I/O operations
(e.g., << and getline())

C++ is a statically typed language. That is, the type of every entity (e.g., object, value, name, and expression) must be known to the compiler at its point of use.
The type of an object determines the set of operations applicable to it.

Every C++ program must have exactly one global function named main().
The program starts by executing that function. The int integer value returned by main(), if any, is the program’s return value to ‘‘the system.’’

If no value is returned, the system will receive a value indicating successful completion. A nonzero value from main() indicates failure.

#include <iostream>
int main() {
std::cout << "Hello, World!\n";
}


We want our code to be comprehensible, because that is the first step on the way to maintainability.
The first step to comprehensibility is to break computational tasks into meaningful chunks (represented as functions and classes) and name those. Such functions then provide the basic vocabulary
of computation, just as the types (built-in and user-defined) provide the basic vocabulary of data.
The C++ standard algorithms (e.g., find, sor t, and iota) provide a good start (Chapter 12).

Defining a
function is the way you specify how an operation is to be done.

Next, we
can compose functions representing common or specialized tasks into larger computations.

A function declaration gives the name of the function, the type of the value returned (if any),
and the number and types of the arguments that must be supplied in a call.

The semantics of argument passing are identical to the semantics of initialization (§3.6.1). That
is, argument types are checked and implicit argument type conversion takes place when necessary


#include <iostream> // include (‘‘import’’) I/O stream library declarations
using namespace std; // make names from std visible without std::
double square(double x)
{
return x*x;
}
void print_square(double x)
{
cout << "the square of " << x << " is " << square(x) << "\n";
}
int main()
{
print_square(1.234); // pr int: the square of 1.234 is 1.52276
}



The value of such compile-time checking and type conversion should not be underestimated.

A function cannot be called unless
it has been previously declared.

A function declaration may contain argument names. This can be a help to the reader of a program, but unless the declaration is also a function definition, the compiler simply ignores such
names. For example:
double sqrt(double d); // retur n the square root of d
double square(double); // retur n the square of the argument

The type of a function consists of its return type and the sequence of its argument types. For example:
double get(const vector<double>& vec, int index); // type: double(const vector<double>&,int)
A function can be a member of a class (§2.3, §4.2.1). For such a member function, the name of its
class is also part of the function type. For example:
char& String::operator[](int index); // type: char& String::(int)



The number of errors in code correlates strongly with the amount of code and the complexity of
the code. Both problems can be addressed by using more and shorter functions. Using a function
to do a specific task often saves us from writing a specific piece of code in the middle of other code;
making it a function forces us to name the activity and document its dependencies.
If two functions are defined with the same name, but with different argument types, the compiler will choose the most appropriate function to invoke for each call

If two alternative functions could be called, but neither is better than the other, the call is deemed
ambiguous and the compiler gives an error. For example:

void print(int, double);
void print(double, int);

void user2() {
  print(0,0); // error: ambiguous
}

Every name and every expression has a type that determines the operations that may be performed on it.

A declaration is a statement that introduces an entity into the program. It specifies a type for
the entity:
• A type defines a set of possible values and a set of operations (for an object).
• An object is some memory that holds a value of some type.
• A value is a set of bits interpreted according to a type.
• A variable is a named object.


bool // Boolean, possible values are true and false
char // character, for example, 'a', 'z', and '9'
int // integer, for example, -273, 42, and 1066
double // double-precision floating-point number, for example, -273.15, 3.14, and 6.626e-34
unsigned // non-negative integer, for example, 0, 1, and 999 (use for bitwise logical operations)

Each fundamental type corresponds directly to hardware facilities and has a fixed size that determines the range of values that can be stored in it

A char variable is of the natural size to hold a character on a given machine (typically an 8-bit
byte), and the sizes of other types are multiples of the size of a char. The size of a type is implementation-defined (i.e., it can vary among different machines) and can be obtained by the siz eof
operator; for example, siz eof(char) equals 1 and siz eof(int) is often 4.
Numbers can be floating-point or integers.
• Floating-point numbers are recognized by a decimal point (e.g., 3.14) or by an exponent
(e.g., 3e−2).
• Integer literals are by default decimal (e.g., 42 means forty-two). A 0b prefix indicates a
binary (base 2) integer literal (e.g., 0b10101010). A 0x prefix indicates a hexadecimal (base
16) integer literal (e.g., 0xBAD1234). A 0 prefix indicates an octal (base 8) integer literal
(e.g., 0334).
To make long literals more readable for humans, we can use a single quote (') as a digit separator.
For example, π is about 3.14159'26535'89793'23846'26433'83279'50288 or if you prefer hexadecimal
0x3.243F'6A88'85A3'08D3.

The = form is traditional and dates back to C, but if in doubt, use the general {}-list form.

If nothing else, it saves you from conversions that lose information:
int i1 = 7.8; // i1 becomes 7 (surprise?)
int i2 {7.8}; // error : floating-point to integer conversion

Unfortunately, conversions that lose information, narrowing conversions, such as double to int and int to char, are allowed and implicitly applied when you use = (but not when you use {}).

The problems caused by implicit narrowing conversions are a price paid for C compatibility (§16.3).

A constant (§1.6) cannot be left uninitialized and a variable should only be left uninitialized in
extremely rare circumstances. Don’t introduce a name until you have a suitable value for it. Userdefined types (such as string, vector, Matrix, Motor_controller, and Orc_warrior) can be defined to be
implicitly initialized (§4.2.1).
When defining a variable, you don’t need to state its type explicitly when it can be deduced
from the initializer:
auto b = true; // a bool
auto ch = 'x'; // a char
auto i = 123; // an int
auto d = 1.2; // a double
auto z = sqrt(y); // z has the type of whatever sqr t(y) retur ns
auto bb {true}; // bb is a bool
With auto, we tend to use the = because there is no potentially troublesome type conversion involved, but if you prefer to use {} initialization consistently, you can do that instead.

We use auto where we don’t have a specific reason to mention the type explicitly. ‘‘Specific reasons’’ include:
• The definition is in a large scope where we want to make the type clearly visible to readers of our code.
• We want to be explicit about a variable’s range or precision (e.g., double rather than float).

Using auto, we avoid redundancy and writing long type names. This is especially important in
generic programming where the exact type of an object can be hard for the programmer to know
and the type names can be quite long (§12.2).


Page 9
