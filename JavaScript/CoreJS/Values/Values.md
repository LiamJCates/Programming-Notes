The JavaScript syntax defines two types of values: Fixed and variable values.

Fixed values are called literals.
Variable values are called variables.

There are two special values that are used to denote the absence of a meaningful value. They are themselves values, but they carry no information.
null
undefined


Many operations in the language that don’t produce a meaningful value yield undefined simply because they have to yield some value.


Data and Structure types

The latest ECMAScript standard defines nine types:

All types except objects define immutable values (that is, values which can't be changed). For example (and unlike in C), Strings are immutable. We refer to values of these types as "primitive values".

Six Data Types that are primitives, checked by typeof operator:

undefined : typeof instance === "undefined"
    A variable that has not been assigned a value has the value undefined.

Boolean : typeof instance === "boolean"
    True/False

Number : typeof instance === "number"
BigInt : typeof instance === "bigint"

String : typeof instance === "string"

Symbol : typeof instance === "symbol"

null : typeof instance === "object".
Special primitive type having additional usage for its value: if object is not inherited, then null is shown;

Object : typeof instance === "object". Special non-data but structural type for any constructed object instance also used as data structures: new Object, new Array, new Map, new Set, new WeakMap, new WeakSet, new Date and almost everything made with new keyword;

function: typeof instance === "function"
Function non data structure, though it also answers for typeof operator. This answer is done as a special shorthand for Functions, though every Function constructor is derived from Object constructor.
Keep in mind the only valuable purpose of typeof operator usage is checking the Data Type. If we wish to check any Structural Type derived from Object it is pointless to use typeof for that, as we will always receive "object".

The proper way to check what sort of Object we are using an instanceof keyword. But even in that case there might be misconceptions.





The BigInt type is a numeric primitive in JavaScript that can represent integers with arbitrary precision. With BigInts, you can safely store and operate on large integers even beyond the safe integer limit for Numbers.

A BigInt is created by appending n to the end of an integer or by calling the constructor.

You can obtain the safest value that can be incremented with Numbers by using the constant Number.MAX_SAFE_INTEGER. With the introduction of BigInts, you can operate with numbers beyond the Number.MAX_SAFE_INTEGER.

This example demonstrates, where incrementing the Number.MAX_SAFE_INTEGER returns the expected result:

const x = 2n ** 53n;
9007199254740992n
const y = x + 1n;
9007199254740993n
You can use the operators +, *, -, **, and % with BigInts—just like with Numbers. A BigInt is not strictly equal to a Number, but it is loosely so.
Besides regular numbers, there are so-called “special numeric values” which also belong to this data type: Infinity, -Infinity and NaN.
Infinity represents the mathematical Infinity ∞. It is a special value that’s greater than any number.
We can get it as a result of division by zero:
alert( 1 / 0 ); // Infinity
Or just reference it directly:
alert( Infinity ); // Infinity
NaN represents a computational error. It is a result of an incorrect or an undefined mathematical operation, for instance:
alert( "not a number" / 2 ); // NaN, such division is erroneous
NaN is sticky. Any further operation on NaN returns NaN:
alert( "not a number" / 2 + 5 ); // NaN
So, if there’s a NaN somewhere in a mathematical expression, it propagates to the whole result.
Mathematical operations are safe
Doing maths is “safe” in JavaScript. We can do anything: divide by zero, treat non-numeric strings as numbers, etc.
The script will never stop with a fatal error (“die”). At worst, we’ll get NaN as the result.
Special numeric values formally belong to the “number” type. Of course they are not numbers in the common sense of this word.

A hexadecimal literal begins with 0x or 0X, followed by a string of hexadecimal digits.

In ES6 and later, you can also express integers in binary (base 2) or octal (base 8)
using the prefixes 0b and 0o (or 0B and 0O) instead of 0x:
0b10101 // => 21: (1*16 + 0*8 + 1*4 + 0*2 + 1*1)
0o377 // => 255: (3*64 + 7*8 + 7*1)

Floating-point literals can have a decimal point; they use the traditional syntax for
real numbers. A real value is represented as the integral part of the number, followed
by a decimal point and the fractional part of the number.
Floating-point literals may also be represented using exponential notation: a real
number followed by the letter e (or E), followed by an optional plus or minus sign,
followed by an integer exponent. This notation represents the real number multiplied
by 10 to the power of the exponent.
More succinctly, the syntax is:
[digits][.digits][(E|e)[(+|-)]digits]

Arithmetic in JavaScript does not raise errors in cases of overflow, underflow, or divi‐
sion by zero. When the result of a numeric operation is larger than the largest repre‐
sentable number (overflow), the result is a special infinity value, Infinity. Similarly,
when the absolute value of a negative value becomes larger than the absolute value of
the largest representable negative number, the result is negative infinity, -Infinity.
The infinite values behave as you would expect: adding, subtracting, multiplying, or
dividing them by anything results in an infinite value (possibly with the sign
reversed).


Underflow occurs when the result of a numeric operation is closer to zero than the
smallest representable number. In this case, JavaScript returns 0. If underflow occurs
from a negative number, JavaScript returns a special value known as “negative zero.”
This value is almost completely indistinguishable from regular zero and JavaScript
programmers rarely need to detect it.e, and the result of this operation is the special not-a-number value, NaN.
NaN also arises if you attempt to divide infinity by infinity, take the square root of a
Division by zero is not an error in JavaScript: it simply returns infinity or negative
infinity. There is one exception, however: zero divided by zero does not have a welldefined valu
negative number, or use arithmetic operators with non-numeric operands that cannot
be converted to numbers.



Conversions

Number(value)
Explicit conversion is usually required when we read a value from a string-based source like a
text form but expect a number to be entered.
If the string is not a valid number, the result of such a conversion is NaN .

Numeric conversion rules:
Value         Becomes…

undefined     NaN

null         0

true / false     1 / 0

string
Whitespaces from the start and end are removed. If the remaining string is empty, the result is 0 .
Otherwise, the number is “read” from the string. An error gives NaN .

String(value)

Boolean(value)
