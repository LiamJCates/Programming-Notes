## Literals
In Java, literals are fixed values with a human readable representation.
A literal is a constant value that appears directly in a program.

For example, 34 and 0.305 are literals in the following statements:
int numberOfYears = 34;
double weight = 0.305;

For the most part, literals, and their usage, are so intuitive that they have been used in one form or another by all the preceding sample programs. Now the time has come to explain them formally. Java literals can be of any of the primitive data types.

How literals are represented depends upon their types:

character literals are enclosed in single quotes
'a' and ' %'

Integer literals are numbers without fractional components
10 and –100

Long literals are specified by a suffix of l or an L.
12 is an int, but 12L is a long.

Floating-point literals have a fractional component and are defaulted to type double.

Double literals are specified by  a suffix of d or D;
10.19 or 10.19D

Float literals are specified by a suffix of f or F.
10.19F

Floating-point Literals may use scientific notation by specifying an integer with an optional fractional component with a suffix of e or E followed by a signed integer with an optional suffix to distinguish float and double literals.
1.0E1   // this means 1.0 x 10^1 ... or 10.0 (double)
1E-1D   // this means 1.0 x 10^(-1) ... or 0.1 (double)
1.0e10f // this means 1.0 x 10^(10) ... or 10000000000.0 (float)

Octal literals are specified by prepending a 0 to a base 8 value using the digits 0 through 8
0457

Binary literals are specified by prepending 0 and b or B to a bit string
0b1101 or 0B1101

Hexadecimal literals are specified by prepending 0 and x or X to a base 16 value consisting of the digits 0 through 9 and the letters A through F
0xAFC or 0XAFC

We may use scientific notation to express floating point literals in hexadecimal by following the specification of a hexadecimal literal with a mandatory p or P then an integer representing a scaling factor of a power of 2. These values default to a double type by a float may be specified using f or F   
0x0.0p0f    // this is zero expressed in hexadecimal form (`float`)
0xff.0p19   // this is 255.0 x 2^19 (`double`)


All variable suffixes can be either in upper- or lowercase, but uppercase is always recommended.

Although integer literals create an int value by default, they can still be assigned to variables of type char, byte, or short if the value being assigned can be represented by the target type.
An integer literal can always be assigned to a long variable.

You can embed one or more underscores into an integer or floating point literal. Doing so can make it easier to read values consisting of many digits. The use of underscores is particularly useful when encoding things like part numbers, customer IDs, and status codes that are commonly thought of as consisting of subgroups of digits. When the literal is compiled, the underscores are simply discarded.
For example 123_45_1234 specifies the value 123,451,234.
