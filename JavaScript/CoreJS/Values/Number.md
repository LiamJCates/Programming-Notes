Number type
The number type represents both integer and floating point numbers.

ECMAScript has two built-in numeric types: Number and BigInt

Numbers in JavaScript are "double-precision 64-bit format IEEE 754 values", according to the spec —  There's no such thing as an integer in JavaScript (except BigInt), so you have to be a little careful.

watch out for stuff like:

0.1 + 0.2 == 0.30000000000000004;

In practice, integer values are treated as 32-bit ints, and some implementations even store it that way until they are asked to perform an instruction that's valid on a Number but not on a 32-bit integer. This can be important for bit-wise operations.


JavaScript uses a fixed number of bits, 64 of them, to store a single number value.
Not all whole numbers less than 18 quintillion fit in a JavaScript number, though. Those bits also store negative numbers, so one bit indicates the sign of the number.
A bigger issue is that non-whole numbers must also be represented. To do this, some of the bits are used to store the position of the decimal point.

The actual maximum whole number that can be stored is more in the range of 9 quadrillion (15 zeros)—which is still pleasantly huge.

The Number type is a double-precision 64-bit binary format IEEE 754 value
between -(2^53 − 1) and 2^53 − 1.

For very big or very small numbers, you may also use scientific notation by adding an e (for exponent), followed by the exponent of the number.
2.998e8
That is 2.998 × 108 = 299,800,000.

In addition to representing floating-point numbers, the number type has three symbolic values: +Infinity, -Infinity, and NaN ("Not a Number").

Infinity and -Infinity, represent the positive and negative infinities.
Infinity - 1 is still Infinity, and so on.

NaN stands for “not a number,” even though it is a value of the number type. You’ll get this result when you, for example, try to calculate 0 / 0 (zero divided by zero), Infinity - Infinity, or any number of other numeric operations that don’t yield a meaningful result.

To check for the largest available value or smallest available value within ±Infinity, you can use the constants Number.MAX_VALUE or Number.MIN_VALUE.

Starting with ECMAScript 2015, you are also able to check if a number is in the double-precision floating-point number range using Number.isSafeInteger() as well as Number.MAX_SAFE_INTEGER and Number.MIN_SAFE_INTEGER. Beyond this range, integers in JavaScript are not safe anymore and will be a double-precision floating point approximation of the value.
The number type has only one integer with two representations: 0 is represented as both -0 and +0. (0 is an alias for +0.)
In the praxis, this has almost no impact. For example, +0 === -0 is true. However, you are able to notice this when you divide by zero:
> 42 / +0 Infinity > 42 / -0 -Infinity
