## Arithmetic conversions

Binary arithmetic operators, arithmetic operations with two operands, cause conversions of operands, and yield results the same way. The conversions these operators cause are called usual arithmetic conversions.  


Floating-point and integral types can coexist peacefully within arithmetic
expressions. The reason is implicit type conversion: when the compiler
encounters mixed types, it performs the necessary promotions so arithmetic
proceeds as expected.


Arithmetic Conversions:
	Integer-to-Integer
	Integer-to-Floating-Point

	Floating-Point-to-Integer
	Floating-Point-to-Floating-Point

	Bool




Conditions for Arithmetic type conversion

Arithmetic conversions of operands that have different native types are done as follows:

If either operand is of type long double the other operand is converted to type long double.

If preceding condition not met and either operand is of type double the other operand is converted to type double.

If preceding conditions not met and either operand is of type float the other operand is converted to type float.

If preceding conditions not met (none of the operands are of floating types).

Operands get integral promotions as follows:

If either operand is of type unsigned long, the other operand is converted to type unsigned long.

If preceding condition not met, and if either operand is of type long and the other of type unsigned int, both operands are converted to type unsigned long.

If the preceding two conditions aren't met, and if either operand is of type long, the other operand is converted to type long.

If the preceding three conditions aren't met, and if either operand is of type unsigned int, the other operand is converted to type unsigned int.

If none of the preceding conditions are met, both operands are converted to type int.

Typedef types behave according to their underlying native types.











Converting from a smaller to a larger integer or floating type is known as promotion.

Type promotion is guaranteed to produce the exact same value in the destination type.

Other conversions between arithmetic types may not always be able to represent the same value exactly and are known as narrowing conversions as some precision or data is lost as a result of the conversion.

Examples of arithmetic narrowing conversions:
    If a negative integer value is converted to an unsigned type, the resulting value corresponds to its 2's complement bitwise representation (i.e., -1 becomes the largest value representable by the type, -2 the second largest, ...).
    The conversions from/to bool consider false equivalent to zero (for numeric types) and to null pointer (for pointer types); true is equivalent to all other values and is converted to the equivalent of 1.
    If the conversion is from a floating-point type to an integer type, the value is truncated (the decimal part is removed). If the result lies outside the range of representable values by the type, the conversion causes undefined behavior.
    Otherwise, if the conversion is between numeric types of the same kind (integer-to-integer or floating-to-floating), the conversion is valid, but the value is implementation-specific (and may not be portable).
