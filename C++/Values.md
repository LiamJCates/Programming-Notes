Values are supplied by name (variables, constants) and expressions

Variables are tools that help the programmer temporarily store data for
a finite amount of time. Constants are tools that help the programmer
define artifacts that are not allowed to change or make changes.


## Variables
When programming in languages like C++, you define variables to store those values.
Defining a variable is quite simple and follows this pattern:
VariableType VariableName;
or
VariableType VariableName = InitialValue;

The variable type attribute tells the compiler the nature of data the variable can store, and
the compiler reserves the necessary space for it. The name chosen by the programmer is
a friendly replacement for the address in the memory where the variable’s value is stored.Unless the initial value is assigned, you cannot be sure of the contents of that memory
location, which can be bad for the program. Therefore, initialization is optional, but
it’s often a good programming practice

Naming variables appropriately is important for writing good,
understandable, and maintainable code.
Variable names in C++ can be alphanumeric, but they cannot
start with a number. They cannot contain spaces and cannot
contain arithmetic operators (such as +, –, and so on) within
them. Variable names also cannot be reserved keywords. For
example, a variable named return will cause compilation failure.
Variable names can contain the underscore character_that often
is used in descriptive variable naming

Keywords You Cannot Use as Variable or Constant Names

asm else new this
auto enum operator throw
bool explicit private true
break export protected try
case extern public typedef
catch false register typeid
char float reinterpret_cast typename
class for return union
const friend short unsigned
constexpr goto signed using
continue if sizeof virtual
default inline static void
delete int static_cast volatile
do long struct wchar_t
double mutable switch while
dynamic_cast namespace template
In addition, the following words are reserved:
and bitor not_eq xor
and_eq compl or xor_eq
bitand not or_eq

int firstNumber = 0, secondNumber = 0, multiplicationResult = 0;
C++ makes it possible to declare multiple
variables of a type at once and to declare variables at the
beginning of a function. Yet, declaring a variable when it is first
needed is often better as it makes the code readable—one
notices the type of the variable when the declaration is close to
its point of first use.


## Types
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

Each fundamental type corresponds directly to hardware facilities and has a fixed size that determines the range of values that can be stored in it.

A char variable is of the natural size to hold a character on a given machine (typically an 8-bit byte), and the sizes of other types are multiples of the size of a char.

The size of a type is implementation-defined (i.e., it can vary among different machines) and can be obtained by the sizeof operator; for example, sizeof(char) equals 1 and sizeof(int) is often 4.

C++11 introduced fixed-width integer types that allow you to
specify the exact width of the integer in bits. These are int8_t
or uint8_t for 8-bit signed and unsigned integers, respectively.
You may also use 16-bit (int16_t, uint16_t), 32-bit (int32_t,
uint32_t), and 64-bit (int64_t, uint64_t) integer types. To use
these types, remember to include header
<cstdint>.

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


bool true or false
char 256 character values
unsigned short int 0 to 65,535
short int –32,768 to 32,767
unsigned long int 0 to 4,294,967,295
long int –2,147,483,648 to 2,147,483,647
unsigned long long 0 to 18,446,744,073,709,551,615
long long –9,223,372,036,854,775,808 to
9,223,372,036,854,775,807
int (16 bit) –32,768 to 32,767
int (32 bit) –2,147,483,648 to 2,147,483,647
unsigned int (16 bit) 0 to 65,535
unsigned int (32 bit) 0 to 4,294,967,295
float 1.2e–38 to 3.4e38
double 2.2e–308 to 1.8e308

Data types such as short, int, long, unsigned short, unsigned int, unsigned
long, and the like have a finite capacity for containing numbers. When you exceed the
limit imposed by the type chosen in an arithmetic operation, you create an overflow.

C++14 adds support for chunking separators in the form of a
single quotation mark. This improves readability of code, as seen
in the following initializations:
int moneyInBank = -70'000; // -70000
long populationChange = -85'000; // -85000
long long countryGDPChange = -70'000'000'000; //
-70 billion
double pi = 3.141'592'653'59; // 3.14159265359
TIP
The data types mentioned thus far are often referred to as POD
(Plain Old Data). The category POD contains these as well as
aggregations (structs, enums, unions, or classes) thereof.



## initialization
The = form is traditional and dates back to C, but if in doubt, use the general {}-list form.

If nothing else, it saves you from conversions that lose information:
int i1 = 7.8; // i1 becomes 7 (surprise?)
int i2 {7.8}; // error : floating-point to integer conversion

Unfortunately, conversions that lose information, narrowing conversions, such as double to int and int to char, are allowed and implicitly applied when you use = (but not when you use {}).

The problems caused by implicit narrowing conversions are a price paid for C compatibility (§16.3).

A constant (§1.6) cannot be left uninitialized and a variable should only be left uninitialized in
extremely rare circumstances. Don’t introduce a name until you have a suitable value for it. Userdefined types (such as string, vector, Matrix, Motor_controller, and Orc_warrior) can be defined to be
implicitly initialized (§4.2.1).
When defining a variable, you don’t need to state its type explicitly when it can be deduced from the initializer:
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


##Constants

Constants in C++ can be
■ Literal constants
■ Declared constants using the const keyword
■ Constant expressions using the constexpr keyword (new since C++11)
■ Enumerated constants using the enum keyword
■ Defined constants that are not recommended and deprecated


C++ supports two notions of immutability:
• const: meaning roughly ‘‘I promise not to change this value.’’ This is used primarily to specify interfaces so that data can be passed to functions using pointers and references without fear of it being modified. The compiler enforces the promise made by const. The value of a const can be calculated at run time.

• constexpr: meaning roughly ‘‘to be evaluated at compile time.’’ This is used primarily to specify constants, to allow placement of data in read-only memory (where it is unlikely to be corrupted), and for performance. The value of a constexpr must be calculated by the compiler.

For example:
constexpr int dmv = 17; // dmv is a named constant

int var = 17; // var is not a constant

const double sqv = sqrt(var); // sqv is a named constant, possibly computed at run time

double sum(const vector<double>&); // sum will not modify its argument (§1.7)

vector<double> v {1.2, 3.4, 4.5}; // v is not a constant

const double s1 = sum(v); // OK: sum(v) is evaluated at run time

constexpr double s2 = sum(v); // error : sum(v) is not a constant expression

For a function to be usable in a constant expression, that is, in an expression that will be evaluated by the compiler, it must be defined constexpr. For example:
constexpr double square(double x) { return x∗x; }

constexpr double max1 = 1.4∗square(17); // OK 1.4*square(17) is a constant expression

constexpr double max2 = 1.4∗square(var); // error : var is not a constant expression

const double max3 = 1.4∗square(var); // OK, may be evaluated at run time

A constexpr function can be used for non-constant arguments, but when that is done the result is not a constant expression. We allow a constexpr function to be called with non-constant-expression arguments in contexts that do not require constant expressions. That way, we don’t have to define essentially the same function twice: once for constant expressions and once for variables.


Keyword constexpr allows function-like declaration of constants:
constexpr double GetPi() {return 22.0 / 7;}
One constexpr can use another:
constexpr double TwicePi() {return 2 * GetPi();}
constexpr may look like a function, however, allows for optimization possibilities from
the compiler’s and application’s point of view. So long as a compiler is capable of evaluating a constant expression to a constant, it can be used in statements and expressions at
places where a constant is expected. In the preceding example, TwicePi() is a constexpr
that uses a constant expression GetPi(). This will possibly trigger a compile-time optimization wherein every usage of TwicePi() is simply replaced by 6.28571 by the compiler,
and not the code that would calculate 2 x 22 / 7 when executed.

Constant expressions need to contain simple implementations
that return simple types like integer, double, and so on. C++14
allows constexpr to contain decision-making constructs such as
if and switch statements. These conditional statements are discussed in detail in Lesson 6, “Controlling Program Flow.”
The usage of constexpr will not guarantee compile-time
optimization—for example, if you use a constexpr expression to
double a user provided number. The outcome of such an expression cannot be calculated by the compiler, which may ignore the
usage of constexpr and compile as a regular function.

To be constexpr, a function must be rather simple and cannot have side effects and can only use information passed to it as arguments. In particular, it cannot modify non-local variables, but it can have loops and use its own local variables.

For example:
constexpr double nth(double x, int n) // assume 0<=n
{
double res = 1;
int i = 0;
while (i<n) { // while-loop: do while the condition is true (§1.7.1)
res∗=x;
++i;
}
return res;
}
In a few places, constant expressions are required by language rules (e.g., array bounds (§1.7), case
labels (§1.8), template value arguments (§6.2), and constants declared using constexpr). In other
cases, compile-time evaluation is important for performance. Independently of performance issues,
the notion of immutability (an object with an unchangeable state) is an important design concern.

Defining Constants Using #define
First and foremost, don’t use this if you are writing a program anew. The only reason
this book analyzes the definition of constants using #define is to help you understand
certain legacy programs that do define constants such as pi using this syntax:
 #define pi 3.14286

This is a preprocessor macro, and what is done here is that all mentions of pi
henceforth are replaced by 3.14286 for the compiler to process. Note that this is a text
replacement (read: non-intelligent replacement) done by the preprocessor. The compiler
neither knows nor cares about the actual type of the constant in question.
Defining constants using the preprocessor via #define is depreCAUTION cated and should not be used.

## typedef

C++ allows you to substitute variable types to something that you might find convenient.
You use the keyword typedef for that. Here is an example where a programmer wants
to call an unsigned int a descriptive STRICTLY_POSITIVE_INTEGER.
typedef unsigned int STRICTLY_POSITIVE_INTEGER;
STRICTLY_POSITIVE_INTEGER numEggsInBasket = 4532;

typedef or type substitution is particularly convenient when
dealing with complex types that can have a cumbersome syntax,
for example, types that use templates.



## Enumerations
There are situations where a particular variable should be allowed to accept only a
certain set of values. These are situations where you don’t want the colors in the rainbow
to contain Turquoise or the directions on a compass to contain Left. In both these cases,
you need a type of variable whose values are restricted to a certain set defined by you.
Enumerations are exactly the tool you need in this situation and are characterized by the
keyword enum. Enumerations comprise a set of constants called enumerators.
In the following example, the enumeration RainbowColors contains individual colors
such as Violet as enumerators:
enum RainbowColors
{
Violet = 0,
Indigo,
Blue,
Green,
Yellow,
Orange,
Red
};


## Array
arrays enable you to store data elements of a type in the memory, in a sequential
and ordered fashion.
To declare five distinct
and unique integer variables and use them to store by declaring an array of five
integers each initialized to zero, like this:
int myNumbers [5] = {};

  In general, the amount of memory reserved by
  the compiler for an array in bytes is
  Bytes consumed by an array = sizeof(element-type) * Number of Elements

You can even declare an array and initialize its contents on a per-element basis, like this integer array where each of the five integers is initialized to five different integer values:

int myNumbers [5] = {34, 56, -21, 5002, 365}

You can also partially initialize elements in an array, like this:
int myNumbers [5] = {34, 56};
// initialize first two elements to 34 and 56 and the rest to 0

An array of five characters would be defined as
char myCharacters [5];



Such arrays are called static arrays because the number of elements they contain as well
as the memory the array consumes is fixed at the time of compilation.

ElementType ArrayName [constant_number of elements] = {optional initial values};

You can define the length of an array (that is, the number of elements in one) as a
constant and use that constant in your array definition:
const int ARRAY_LENGTH = 5;
int myNumbers [ARRAY_LENGTH] = {34, 56, -21, 5002, 365};
This is particularly useful when you need to access and use the length of the array at
multiple places, such as when iterating elements in one, and then instead of having to
change the length at each of those places, you just correct the initialization value at the
const int declaration.
You can opt to leave out the number of elements in an array if you know the initial values
of the elements in the array:
int myNumbers [] = {2016, 2052, -525}; // array of 3 elements



Arrays declared thus far are called static arrays as the length
of the array is a constant and fixed by the programmer at
compile-time. This array cannot take more data than what the
programmer has specified. It also does not consume any less
memory if left half-used or unused. Arrays where the length is
decided at execution-time are called dynamic arrays.


Elements in an array can be accessed using their zero-based index. These indexes are
called zero-based because the first element in an array is at index 0. So, the first integer
value stored in the array myNumbers is myNumbers[0], the second is myNumbers[1],
and so on. The fifth is myNumbers[4]. In other words, the index of the last element in
an array is always (Length of Array – 1).
When asked to access element at index N, the compiler uses the memory address of the
first element (positioned at index zero) as the starting point and then skips N elements
by adding the offset computed as N*sizeof(element) to reach the address containing
the (N+1)th element. The C++ compiler does not check if the index is within the actual
defined bounds of the array. You can try fetching the element at index 1001 in an array of
only 10 elements, putting the security and stability of your program at risk. The onus of
ensuring that the array is not accessed beyond its bounds lies solely on the programmer.Accessing an array beyond its bounds results in unpredictable
behavior. In many cases this causes your program to crash.
Accessing arrays beyond their bounds should be avoided at
all costs.

C++ enables you to declare multidimensional arrays by indicating the number of
elements you want to reserve in each dimension.

arrayType arrayName [rows] [columns];

int solarPanels [2][3] = {{0, 1, 2}, {3, 4, 5}};

|0|1|2|
|3|4|5|

Even though C++ enables us to model multidimensional arrays,
the memory where the array is contained is one-dimensional. So,
the compiler maps the multidimensional array into the memory
space, which expands only in one direction.
If you wanted to, you could also initialize the array called
solarPanels like the following, and it would still contain the
same values in the respective elements:
int solarPanels [2][3] = {0, 1, 2, 3, 4, 5};
However, the earlier method makes a better example because
it’s easier to imagine and understand a multidimensional array
as an array of arrays.

When you need to access an integer in this array, you would need to use a first subscript
to address the array where the integer is and the second subscript to address that integer
in this array.


## Dynamic Arrays
choose
dynamic arrays that optimize memory consumption and scale up depending on the
demand for resources and memory at execution-time. C++ provides you with convenient
and easy-to-use dynamic arrays in the form of std::vector

 #include <iostream>
 #include <vector>

using namespace std;

int main()
{
vector<int> dynArray (3); // dynamic array of int

dynArray[0] = 365;
dynArray[1] = -421;
dynArray[2]= 789;

cout << "Number of integers in array" << dynArray.size() << endl;

cout << "Enter another element to insert" << endl;
int newValue = 0;
cin >> newValue;
dynArray.push_back(newValue);

cout << "Number of integers in array" << dynArray.size() << endl;
cout << "Last element in array";
cout << dynArray[dynArray.size() - 1] << endl;
return 0;

}

To use the dynamic array class std::vector, you need to
include header vector, which is also shown in Line 1 of Listing 4.4.
 #include <vector>



## Strings
C-style strings are a special case of an array of characters. You have already seen some
examples of C-style strings in the form of string literals that you have been writing into
your code:
std::cout << "Hello World";
This is equivalent to using the array declaration:
char sayHello[] = {'H', 'e', 'l', 'l', 'o', ' ', 'W', 'o', 'r', 'l', 'd',
'\0'};
std::cout << sayHello << std::endl;
Note that the last character in the array is a null character '\0'. This is also called the
string-terminating character because it tells the compiler that the string has ended. Such
C-style strings are a special case of character arrays in that the last character always precedes the null-terminator '\0'. When you embed a string literal in your code, the compiler
does the job of adding a '\0' after it.

Applications programmed in C (or in C++ by programmers who
have a strong C background) often use string copy functions
such as strcpy(), concatenation functions such as strcat(),
and strlen() to determine the length of a string, in addition to
others of this kind.
These functions take C-style strings as input and are dangerous
as they seek the null-terminator and can exceed the boundaries
of the character array they’re using if the programmer has not
ensured the presence of the terminating null

C++ standard strings are an efficient and safer way to deal with text input—and to
perform string manipulations like concatenations. std::string is not static in size
like a char array implementation of a C-style string is and can scale up when more
data needs to be stored in it.
