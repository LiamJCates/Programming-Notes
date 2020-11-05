## Primitive Types

Java provides eight primitive data types for numeric values, characters, and Boolean values.

Type      Bit Depth         Value Range

boolean   1 (JVM-specific)  true or false
char      16                (unsigned)2^16-1   0 to 65535

byte      8                 (-2^7 to 2^7-1)    -128 to 127
short     16                (-2^15 to 2^15-1)  -32768 to
                                                32767
int       32                (-2^31 to 2^31-1)  -2147483648 to
                                                2147483647
long      64                (-2^63 to 2^63-1)  -huge to huge

float     32                varies
double    64                varies

The compiler allocates memory space for each variable or constant according to its data type.
Every data type has a range of values.
Under Java, the ranges of the integer types do not depend on the machine on which you will be running the Java code.









## Numeric Types

Two’s Complement
The storage of the binary values of short, int, and long use a representation in memory called Two’s Complement.

[See ProgrammingNotes/Math/TwosComplement]

All Numeric Types are Signed
Numeric types are signed meaning they can hold positive and negative values.
Java does not support unsigned (positive-only) integers.

Performing unsigned arithmetic in Java can be tricky, because in most cases, Java only "natively" caters for signed arithmetic: that is, it expects to interpret the top bit of an integer type (int, but also byte, short and long) as the sign bit.


Automatic Type Conversions
Before a value can be stored in a variable, the value’s data type must be compatible with the variable’s data type. Java performs some conversions between data types automatically, but does not automatically perform any conversion that can result in the loss of data.

numeric primitive data types are ranked.

double > float > long > int > short > byte

One data type outranks another if it can hold a larger number. In assignment statements where values of lower-ranked data types are stored in variables of higher-ranked data types, Java automatically converts the lower-ranked value to the higher ranked type.

This is called a widening conversion.

Widening conversions, those that increase in data type rank, don't incur information loss (such as short to int or float to double) and are always legal. Values of type char can be converted to int. All integer types can be converted to float or double, even though some of the conversions (such as long to double) lose precision.

Casting
The cast operator lets you manually convert a value, even if it means that information loss will take place, a narrowing conversion. Cast operators are unary operators that appear as a data type name enclosed in a set of parentheses. These operators precede the value being converted.

All other conversions require a cast:
double x = 10.0 / 3.0; / / sets x to 3.3333333333333335
int n = (int) x; / / sets n to 3
float f = (float) x; / / sets f to 3.3333333

If you try to cast a number of one type to another that is out of range for the target type, the result will be a truncated number that has a different value.

One of the nuances of the Java language is the way it internally handles arithmetic operations on int, byte, and short variables. When values of the byte or short data types are used in arithmetic expressions, they are temporarily converted to int values. The result of an arithmetic operation using only a mixture of byte, short, or int values will always be an int.

Q: Why does Java have different data types for integers and floating-point values? That is, why aren’t all numeric values just the same type?
A: Java supplies different data types so that you can write efficient programs. For example, integer arithmetic is faster than floating point calculations. Thus, if you don’t need fractional values, then you don’t need to incur the overhead associated with types float or double. Second, the amount of memory required for one type of data might be less than that required for another. By supplying different types, Java enables you to make best use of system resources. Finally, some algorithms require (or at least benefit from) the use of a specific type of data. In general, Java supplies a number of built-in types to give you the greatest flexibility.









## boolean

boolean variables may hold only the value true or false
A boolean and an integer are not compatible types in Java as they are in c and other languages. (False != 0)
Thus, it is not possible to convert between the boolean type and number types.

A Boolean expression is an expression that evaluates to a Boolean value: true or false.














## Floating-Point Types
The float and double types are used to represent numbers with a decimal point.

Called floating-point numbers because they are stored in scientific notation internally. When a number such as 50.534 is converted into scientific notation, such as 5.0534E+1, its decimal point is moved (i.e., floated) to a new position

Precision
The name double refers to the fact that these numbers have twice the precision of the float type.
(Some people call these double-precision numbers.) The limited precision of float (6–7 significant digits) is simply not sufficient for many situations. Use float values only when you work with a library that requires them, or when you need to store a very large number of them.

Numbers of type float have a suffix F or f (for example, 3.14F).
Floating point numbers without an F suffix (such as 3.14) are always considered to be of type double.
You can optionally supply the D or d suffix (for example, 3.14D).
Java uses E notation to represent values in scientific notation.
In E notation, the number 4.728197 × 10^4 would be 4.728197E4.


All floating-point computations follow the IEEE 754 specification. In particular, there are three special floating-point values to denote overflows and errors:
Positive infinity
Negative infinity
NaN (not a number)
For example, the result of dividing a positive number by 0 is positive infinity.
Computing 0/0 or the square root of a negative number yields NaN.

The constants Double.POSITIVE_INFINITY, Double.NEGATIVE_INFINITY, and Double.NaN (as well as
corresponding Float constants) represent these special values, but they are rarely used in practice. In particular, you cannot test
if (x == Double.NaN)     //is never true

to check whether a particular result equals Double.NaN. All “not a number” values are considered distinct. However, you can use the Double.isNaN method:
if (Double.isNaN(x))     // check whether x is "not a number"

Floating-point numbers are not suitable for financial calculations in which roundoff errors cannot be tolerated. For example, the command System.out.println(2.0 - 1.1) prints 0.8999999999999999, not 0.9 as you would expect. Such roundoff errors are caused by the fact that floating-point numbers are represented in the binary number system. There is no precise binary representation of the fraction 1/10, just as there is no accurate representation of the fraction 1/3 in the decimal system.

If you need precise numerical computations without roundoff errors, use the BigDecimal class












## char

The char type was originally intended to describe individual characters. However, this is no longer the case. Nowadays, Java uses Unicode, which is a set of numbers that are used as codes for representing characters. Some Unicode characters can be described with one char value, and other Unicode characters require two char values.


Unicode Characters are internally represented by numbers or numeric codes.
When a character is stored in memory, it is actually the numeric code that is stored
Each printable character, as well as many non-printable characters, is assigned a unique numeric code.
Each Unicode number requires two bytes of memory, so char variables occupy two bytes. When the computer is instructed to print the value on the screen, it displays the character that corresponds with the numeric code.

When initializing a char data type, we need to enclose the character in single quotes.  
For example, 'A' is a character constant with value 65. It is different from "A", a string containing a single character

Caution
Unicode escape sequences are processed before the code is parsed. For example, "\u0022+\u0022" is not a string consisting of a plus sign surrounded by quotation marks (U+0022). Instead, the \u0022 are
converted into " before parsing, yielding ""+"", or an empty string.

Even more insidiously, you must beware of \u inside comments. The comment
// \u000A is a newline
yields a syntax error since \u000A is replaced with a newline when the program is read.

Similarly, a comment can yield a syntax error if \u is not followed by four hex digits.
// look inside c:\users



char Casting
A char can be cast into any numeric type, and vice versa.
When an integer is cast into a char, only its lower 16 bits of data are used; the other part is ignored.
When a floating-point value is cast into a char, the floating-point value is first cast into an int, which is then cast into a char.
When a char is cast into a numeric type, the character’s Unicode is cast into the specified numeric type.
Any positive integer between 0 and FFFF in hexadecimal can be cast into a character implicitly. Any number not in this range must be cast into a char explicitly. All numeric operators can be applied to char operands. A char operand is automatically cast into a number if the other operand is a number or a character. If the other operand is a string, the character is concatenated with the string.
Two characters can be compared using the relational operators just like comparing two numbers. This is done by comparing the Unicodes of the two characters.

Q: You say that there are four integer types: int, short, long, and byte. However, I have heard that char can also be categorized as an integer type in Java. Can you explain?
A: The formal specification for Java defines a type category called integral types, which includes byte, short, int, long, and char. They are called integral types because they all hold whole number, binary values. However, the purpose of the first four is to represent numeric integer quantities. The purpose of char is to represent characters. Therefore, the principal uses of char and the principal uses of the other integral types are fundamentally different. Because of the differences, the char type is treated separately














## Unicode and the char Type

Binary Numbers are used internally to store each character as a sequence of 0s and 1s.
Encoding is the act of mapping a character to its binary representation.
Encoding schemes define a particular method of character encoding.

To fully understand the char type, you have to know about the Unicode encoding scheme. Unicode was invented to overcome the limitations of traditional character encoding schemes. Before Unicode, there were many different standards: ASCII in the United States, ISO 8859-1 for Western European languages, KOI-8 for Russian, GB18030 and BIG-5 for Chinese, and so on.

This caused two problems.
First, a particular code value corresponds to different letters in the different encoding schemes.
Second, the encodings for languages with large character sets have variable length: Some common characters are encoded as single bytes, others require two or more bytes.

Unicode was designed to solve these problems.
When the unification effort started in the 1980s, a fixed 2-byte code was more than sufficient to encode all characters used in all languages in the world, with room to spare for future expansion—or so everyone thought at the time.

Unicode was originally designed as a 16-bit character encoding. The primitive data type char was intended to take advantage of this design by providing a simple data type that could hold any character. However, it turned out that the 65,536 characters possible in a 16-bit encoding are not sufficient to represent all the characters in the world. The Unicode standard therefore has been extended to allow up to 1,112,064 characters. Those characters that go beyond the original 16-bit limit are called supplementary characters.

In 1991, Unicode 1.0 was released, using slightly less than half of the available 65,536 code values. Java
was designed from the ground up to use 16-bit Unicode characters, which was a major advance over other programming languages that used 8-bit characters. Unfortunately, over time, the inevitable happened. Unicode grew beyond 65,536 characters, primarily due to the addition of a very large set of ideographs used
for Chinese, Japanese, and Korean.

A 16-bit Unicode takes two bytes, preceded by \u, expressed in four hexadecimal digits that run from \u0000 to \uFFFF. Most computers use ASCII (American Standard Code for Information Interchange), an 8-bit encoding scheme, for representing all uppercase and lowercase letters, digits, punctuation marks, and control characters. Unicode includes ASCII code, with \u0000 to \u007F corresponding to the 128 ASCII characters.

Now, the 16-bit char type is insufficient to describe all Unicode characters.

We need a bit of terminology to explain how this problem is resolved in Java, beginning with Java 5.

A code point is a code value that is associated with a character in an encoding scheme. In the Unicode standard, code points are written in hexadecimal and prefixed with U+, such as U+0041 for the code
point of the Latin letter A.

Unicode has code points that are grouped into 17 code planes. The first code plane, called the basic multilingual plane, consists of the “classic” Unicode characters with code points U+0000 to U+FFFF. Sixteen additional planes, with code points U+10000 to U+10FFFF, hold the supplementary characters.

The UTF-16 encoding represents all Unicode code points in a variable-length code. The characters in the basic multilingual plane are represented as 16-bit values, called code units. The supplementary characters are encoded as consecutive pairs of code units. Each of the values in such an encoding pair falls into a range of 2048 unused values of the basic multilingual plane, called the surrogates area (U+D800 to U+DBFF for the first code unit, U+DC00 to U+DFFF for the second code unit). This is rather clever, because you can
immediately tell whether a code unit encodes a single character or it is the first or second part of a supplementary character. For example, (the mathematical symbol for the set of octonions, http://math.ucr.edu/home/baez/octonions) has code point U+1D546 and is encoded by the two code units U+D835 and U+DD46. (See https://tools.ietf.org/html/rfc2781 for a description of the encoding algorithm.)
In Java, the char type describes a code unit in the UTF-16 encoding.

Our strong recommendation is not to use the char type in your programs unless you are actually manipulating UTF-16 code units. You are almost always better off treating strings as abstract data types.














## Literals
In Java, literals refer to fixed values that are represented in their human readable form.
A literal is a constant value that appears directly in a program. For example, 34 and 0.305 are literals in the following statements:
int numberOfYears = 34;
double weight = 0.305;

Literals are also commonly called constants. For the most part, literals, and their usage, are so intuitive that they have been used in one form or another by all the preceding sample programs. Now the time has come to explain them formally. Java literals can be of any of the primitive data types.

The way each literal is represented depends upon its type:
character constants are enclosed in single quotes.
For example, 'a' and ' %'
Integer literals are specified as numbers without fractional components.
By default Integer literals are of type int.
For example, 10 and –100
Long literals are specified by appending an l or an L. The absence of L implies an int.
For example, 12 is an int, but 12L is a long.
Floating-point literals require the use of the decimal point followed by the number’s fractional component.
By default, floating-point literals are of type double, though a D can be used to specify a double literal.
For example, 11.123 is a floating-point literal.
Float literals are specified by appending an F or f to the constant. The absence of f implies a double.
For example, 10.19F is of type float.
Java also allows you to use scientific notation for floating-point numbers using E (or e).
For example, 1.2345 * 10^2 is written as 1.2345E2 or 1.2345E+2 and 1.2345 * 10-2 as 1.2345E-2.

All variable suffixes can be either in upper- or lowercase, but uppercase is always recommended.

Although integer literals create an int value by default, they can still be assigned to variables of type char, byte, or short as long as the value being assigned can be represented by the target type.
An integer literal can always be assigned to a long variable.

You can embed one or more underscores into an integer or floating point literal. Doing so can make it easier to read values consisting of many digits. The use of underscores is particularly useful when encoding things like part numbers, customer IDs, and status codes that are commonly thought of as consisting of subgroups of digits. When the literal is compiled, the underscores are simply discarded.
For example 123_45_1234 specifies the value 123,451,234.

Hexadecimal, Octal, and Binary Literals
Sometimes it is easier to use a number system based on 8 or 16 instead of 10.
Hexadecimal literals must begin with 0x or 0X (a zero followed by an x or X) and uses the digits 0 through 9 plus the letters A through F
Octal literals begin with a zero and uses the digits 0 through 8
Binary literals begin with a 0b or 0B.
For example
hex = 0xFF;     //255
oct = 011;    //9
bin = 0b1100;    //12
As a point of interest, Java also allows hexadecimal floating-point literals, but they are seldom used.
