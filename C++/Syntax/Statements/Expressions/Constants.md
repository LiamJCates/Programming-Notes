## Constants

Constants are expressions with a fixed value, a value that doesn't change.

Constants in C++ can be
■ Literal constants
■ Named Constants: constants declared using the const keyword
■ Constant expressions using the constexpr keyword (new since C++11)
■ Enumerated constants using the enum keyword
■ Defined constants that are not recommended and deprecated


Nonintegral constants must be converted (either explicitly or implicitly) to integral types to be legal in a constant expression.

Explicit conversions to integral types are legal in constant expressions; all other types and derived types are illegal except when used as operands to the sizeof operator.

The comma operator and assignment operators cannot be used in constant expressions.


## Non-Literal Constant

C++ provides two keywords to enable you to express the intent that an object is not intended to be modified, and to enforce that intent.

C++ supports two notions of immutability:
• const: meaning roughly ‘‘I promise not to change this value.’’ This is used primarily to specify interfaces so that data can be passed to functions using pointers and references without fear of it being modified. The compiler enforces the promise made by const. The value of a const can be calculated at run time.

• constexpr: meaning roughly ‘‘to be evaluated at compile time.’’ This is used primarily to specify constants, to allow placement of data in read-only memory (where it is unlikely to be corrupted), and for performance. The value of a constexpr must be calculated by the compiler.




### Named Constants
A memory location whose content is not allowed to change during program execution.

Some data must stay the same throughout a program. In C++, you can use a named constant to instruct a program to mark those memory locations in which data is fixed throughout program execution.


To allocate constant memory, we use C++’s declaration statement with the const keyword type qualifier:

const dataType identifier = value;

In C++, const is a reserved word. It should be noted that a named constant must be initialized when it is declared because from this statement on the compiler will reject any attempt to change the value.

By convention identifiers of named constants use upper snake case:
[Programming Methods\Fundamentals\Constructs\Declarations\Identifiers.md]

Using a named constant to store fixed data, rather than using a literal, has one major advantage. If the fixed data changes, you do not need to replace the literal value throughout the entire program. Instead, you change the const declaration, which is just one place, recompile the program, and execute it using the new value throughout.

In addition, by storing a value and referring to
that memory location whenever the value is needed, you avoid typing the same value again and again and prevent accidental typos. If you misspell the name of the constant value’s location, the computer will warn you through an error message, but it will not warn you if a literal value is mistyped.




Constant expressions are expressions that can be evaluated at compile time.

For performance and safety reasons, whenever a computation can be done at compile time rather than runtime, you should do it.

Simple mathematical operations involving literals are an obvious example of expressions that can be evaluated at compile time.

You can extend the reach of the compiler by using the expression constexpr.

Whenever all the information required to compute an expression is present at compile time, the compiler is compelled to do so if that expression is marked constexpr. This simple commitment can enable a surprisingly large impact on code readability and runtime performance.

Both const and constexpr are closely related.

Whereas constexpr enforces that an expression is compile time evaluable, const enforces that a variable cannot change within some scope (at runtime). All constexpr expressions are const because they’re always fixed at runtime.

All constexpr expressions begin with one or more fundamental types (int, float, whchar_t, and so on). You can build on top of these types by using operators and constexpr functions.

C++ requires constant expressions — expressions that evaluate to a constant — for declarations of:
    Array bounds
    Selectors in case statements
    Bit-field length specification
    Enumeration initializers

The only operands that are legal in constant expressions are:
    Literals
    Enumeration constants
    Values declared as const that are initialized with constant expressions
    sizeof expressions

Constant expressions are used mainly to replace manually computed values in your code. This generally produces code that is more robust and easier to understand, because you can eliminate so-called magic values—manually calculated constants copy and pasted directly into source code.











For example:
constexpr int dmv = 17; // dmv is a named constant

int var = 17; // var is not a constant

const double sqv = sqrt(var); // sqv is a named constant, possibly computed at run time

double sum(const vector<double>&); // sum will not modify its argument (§1.7)

vector<double> v {1.2, 3.4, 4.5}; // v is not a constant

const double s1 = sum(v); // OK: sum(v) is evaluated at run time

constexpr double s2 = sum(v); // error : sum(v) is not a constant expression

For a function to be usable in a constant expression, that is, in an expression that will be evaluated by the compiler, it must be defined constexpr.

For example:
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








## Defining Constants Using #define
First and foremost, don’t use this if you are writing a program anew. The only reason
this book analyzes the definition of constants using #define is to help you understand
certain legacy programs that do define constants such as pi using this syntax:
 #define pi 3.14286

This is a preprocessor macro, and what is done here is that all mentions of pi
henceforth are replaced by 3.14286 for the compiler to process. Note that this is a text
replacement (read: non-intelligent replacement) done by the preprocessor. The compiler
neither knows nor cares about the actual type of the constant in question.
Defining constants using the preprocessor via #define is deprecated and should not be used.
