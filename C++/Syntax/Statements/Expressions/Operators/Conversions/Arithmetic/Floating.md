### Floating point conversions

An object of a floating type can be safely converted to a more precise floating type — that is, the conversion causes no loss of significance. For example, conversions from float to double or from double to long double are safe, and the value is unchanged.

#### Floating-Point-to-Floating-Point Conversions
Floating-point numbers can be implicitly cast to and from other floating-point numbers. As long as the destination value can fit the source value,
all is well. When it cannot, you have undefined behavior. Again, braced initialization can prevent potentially dangerous conversions.





An object of a floating type can also be converted to a less precise type, if it's in a range representable by that type. (See Floating Limits for the ranges of floating types.) If the original value isn't representable precisely, it can be converted to either the next higher or the next lower representable value. The result is undefined if no such value exists. Consider the following example:
C++

cout << (float)1E300 << endl;

The maximum value representable by type float is 3.402823466E38 — a much smaller number than 1E300. Therefore, the number is converted to infinity, and the result is "inf".






When an object of floating type is converted to an integral type, the fractional part is truncated, or rounded toward zero. A number like 1.3 is converted to 1, and -1.3 is converted to -1. If the truncated value is higher than the highest representable value, or lower than the lowest representable value, the result is undefined.
