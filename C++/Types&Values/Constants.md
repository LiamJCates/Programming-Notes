## Constants

Constants in C++ can be
■ Literal constants
■ Declared constants using the const keyword
■ Constant expressions using the constexpr keyword (new since C++11)
■ Enumerated constants using the enum keyword
■ Defined constants that are not recommended and deprecated

# Literals
A literal constant is a hardcoded value in a program.


## Integer Literals
You can use one of four hardcoded, integer literal representations:
decimal default no prefix
hexadecimal prefix 0x
octal prefix 0
binary prefix 0b

Integer literals are by default decimal (e.g., 42 means forty-two).
A 0b prefix indicates a binary (base 2) integer literal (e.g., 0b10101010).
A 0x prefix indicates a hexadecimal (base 16) integer literal (e.g., 0xBAD1234).
A 0 prefix indicates an octal (base 8) integer literal (e.g., 0334).

The octal prefix is a holdover from the B language, back in the days of the PDP-8 computer and ubiquitous octal literals. C, and by extension C++, continues the dubious tradition. You must be careful, for example, when you’re hardcoding ZIP codes:
int mit_zip_code = 02139; // Won't compile

This line doesn’t compile because 9 is not an octal digit.

Eliminate leading zeros on decimal literals; otherwise, they’ll cease to be decimal.

By default, an integer literal’s type is one of the following: int, long, or long long. An integer literal’s type is the smallest of these three types that fits. (This is defined by the language and will be enforced by the compiler.) This means that among all types allowed for a particular integer, the smallest type will apply. For example, the integer literal 112114 could be held by an int, a long, or a long long. Since an int can store 112114, the resulting integer literal is an int.

If you want more control, you can supply suffixes to an integer literal to specify its type (suffixes are case insensitive, so you can choose the style you like best):
•	 The unsigned suffix u or U
•	 The long suffix l or L
•	 The long long suffix ll or LL

If you really want, say, a long, you can instead specify 112114L
(or 112114l).

Examples:
85         // decimal
0213       // octal
0x4b       // hexadecimal
30         // int
30u        // unsigned int
30l        // long
30ul       // unsigned long


### Boolean Literals
To initialize Boolean types, you use two Boolean literals, true and false





## Character Literals
A character literal is a single, constant character. Single quotation marks (' ') surround a character. If the character is any type but char, you must also provide a prefix:
L for wchar_t,
u for char16_t,
U for char32_t.

For example, 'J' declares a char literal and L'J' declares a wchar_t.


### Escape Sequences
Some characters don’t display on the screen. Instead, they force the display
to do things like move the cursor to the left side of the screen (carriage
return) or move the cursor down one line (newline). Other characters can
display onscreen, but they’re part of the C++ language syntax, such as single
or double quotes, so you must use them very carefully. To put these characters into a char, you use the escape sequences

Reserved Characters and Their Escape Sequences

| Value | Escape sequence |
|-------|-----------------|
| Newline | \n |
| Tab (horizontal) | \t |
|Tab (vertical) | \v |
|Backspace | \b |
|Carriage return | \r |
|Form feed | \f |
|Alert | \a |
|Backslash | \\ |
|Question mark | ? or \? |
|Single quote | \' |
|Double quote | \" |
|The null character | \0 |

Several different character data sets are currently in use. The most common are the
American Standard Code for Information Interchange (ASCII) and Extended BinaryCoded Decimal Interchange Code (EBCDIC). The ASCII character set has 128 values.
The EBCDIC character set has 256 values and was created by IBM.

### ASCII
The American Standard Code for Information Interchange (ASCII) table assigns integers to characters.

Each of the 128 values of the ASCII character set represents a different character. For example, the value 65 represents 'A', and the value 43 represents '+'. Thus, each character has a predefined ordering represented by the numeric value associated with the
character. This ordering is called a collating sequence, in the set. The collating sequence is used when you compare characters. For example, the value representing 'B' is 66, so 'A' is smaller than 'B'. Similarly, '+' is smaller than 'A' because 43 is smaller than 65.

ASCII codes 0 to 31 are the control code characters that control devices. These are mostly anachronisms. When the American Standards Association formalized ASCII in the 1960s, modern devices included teletype machines, magnetic tape readers, and dot-matrix printers. Some control codes still in common use are the following:

•	 0 (NULL) is used as a string terminator by programming languages.
•	 4 (EOT), the end of transmission, terminates shell sessions and PostScript printer communications.
•	 7 (BELL) causes a device to make a noise.
•	 8 (BS), the backspace, causes the device to erase the last character.
•	 9 (HT), the horizontal tab, moves a cursor several spaces to the right.
•	 10 (LF), the line feed, is used as the end-of-line marker on most operating systems.
•	 13 (CR), the carriage return, is used in combination with LF as the end-of-line marker on Windows systems.
•	 26 (SUB), the substitute character/end of file/ctrl-Z, suspends the currently executing interactive process on most operating systems.

The remainder of the ASCII table, codes from 32 to 127, is the printable characters. These represent the English characters, digits, and punctuation.

On most systems, the char type’s representation is ASCII. Although this relationship is not strictly guaranteed, it is a de facto standard.



### Unicode Escape Characters
You can specify Unicode character literals using the universal character names,
and you can form a universal character name in one of two ways: the prefix
\u followed by a 4-digit Unicode code point or the prefix \U followed by an
8-digit Unicode code point.






## Floating Point Literals
Floating-point numbers are recognized by:
decimal point (e.g., 3.14)
exponent (e.g., 3e−2).

A floating-point literal has an integer part, a decimal point, a fractional part, and an exponent part. You can represent floating point literals either in decimal form or exponential form.

Floating-point literals are double precision by default.

If you need single precision, use an f or F suffix; for extended precision, use l or L, as shown here:
float a = 0.1F;
double b = 0.2;
long double c = 0.3L;

You can also use scientific notation in literals:
double plancks_constant = 6.62607004ue-34v;

No spaces are permitted between the significand (the base u) and the
suffix (the exponential portion v).

While representing using decimal form, you must include the decimal point, the exponent, or both and while representing using exponential form, you must include the integer part, the fractional part, or both. The signed exponent is introduced by e or E.

3.14159       // Legal
314159E-5L    // Legal

### Chunking Seperators
C++14 adds support for chunking separators in the form of a
single quotation mark:

Integer and Floating Point literals can contain any number of single quotes (') for readability.  These are completely ignored by the compiler.

int moneyInBank = -70'000; // -70000
long populationChange = -85'000; // -85000
long long countryGDPChange = -70'000'000'000; //
-70 billion
double pi = 3.141'592'653'59; // 3.14159265359
long double π is about 3.14159'26535'89793'23846'26433'83279'50288
hexadecimal π is 0x3.243F'6A88'85A3'08D3.










## String Literals
String Literals
Declare string literals by enclosing text in quotation marks (""). Like character literals, string literals support Unicode: just prepend the literal with
the appropriate prefix, such as L. The following example assigns string literals
to the arrays english and chinese:
char english[] = "A book holds a house of gold.";
char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";

Printing Unicode to the console is surprisingly complicated. Typically, you need to ensure that the correct code page is selected. If you need to embed Unicode characters into a string literal, look at
wprintf in the <cwchar> header.

Consecutive string literals get concatenated together, and any intervening whitespaces or newlines get ignored. So, you can place string literals on multiple lines in your source, and the compiler will treat them as one:
#include <cstdio>
int main() {
char house[] = "a "
"house "
"of " "gold.";
printf("A book holds %s\n ", house);
}

Usually, such constructions are useful for readability only when you
have a long string literal that would span multiple lines in your source code.



## Non-Literal Constants
C++ supports two notions of immutability:
• const: meaning roughly ‘‘I promise not to change this value.’’ This is used primarily to specify interfaces so that data can be passed to functions using pointers and references without fear of it being modified. The compiler enforces the promise made by const. The value of a const can be calculated at run time.

• constexpr: meaning roughly ‘‘to be evaluated at compile time.’’ This is used primarily to specify constants, to allow placement of data in read-only memory (where it is unlikely to be corrupted), and for performance. The value of a constexpr must be calculated by the compiler.




### Named Constants
Some data must stay the same throughout a program.
In C11, you can use a named
constant to instruct a program to mark those memory locations in which data is
fixed throughout program execution.
Named constant: A memory location whose content is not allowed to change during
program execution.
To allocate memory, we use C11’s declaration statements. The syntax to declare a
named constant is:
const dataType identifier = value;
In C11, const is a reserved word. It should be noted that a named constant is initialized and declared all in one statement and that it must be initialized when it is declared
because from this statement on the compiler will reject any attempt to change the value.

Note that the identifier for a named constant is in uppercase letters. Even though there
are no written rules, C11 programmers typically prefer to use uppercase letters to
name a named constant. Moreover, if the name of a named constant is a combination
of more than one word, called a run-together word, then the words are typically separated using an underscore.

Using a named constant to store fixed data, rather than using the data value itself, has one major advantage. If the fixed data changes, you do not need to edit the entire program and change the old value to the new value wherever the old value is used.

Instead, you can make the change at just one place, recompile the program, and execute it using the new value throughout. In addition, by storing a value and referring to
that memory location whenever the value is needed, you avoid typing the same value
again and again and prevent accidental typos. If you misspell the name of the constant
value’s location, the computer will warn you through an error message, but it will not
warn you if the value is mistyped.







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
