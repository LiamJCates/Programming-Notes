## Floating-Point Types
To deal with decimal numbers, C++ provides the floating-point data type

Floating-point types store approximations of real numbers (which in our case can be defined as any number that has a decimal point and a fractional part, such as 0.33333 or 98.6).

Although it’s not possible to represent an arbitrary real number exactly in computer memory, it’s possible to store an approximation. If this seems hard to believe, just think of a number like π, which has infinitely many digits. With finite computer memory, how could you possibly represent infinitely many digits?

As with all types, floating-point types take up a finite amount of memory, which is called the type’s precision. The more precision a floating-point type has, the more accurate it will be at approximating a real number.

C++ offers three levels of precision for approximations:
float single precision
double double precision
long double extended precision

As with integer types, each floating-point representation depends on
implementation. This section won’t go into detail about floating-point types,
but note that there is substantial nuance involved in these implementations.
On major desktop operating systems, the float level usually has 4 bytes
of precision. The double and long double levels usually have 8 bytes of precision (double precision).
Most users not involved in scientific computing applications can safely
ignore the details of floating-point representation. In such cases, a good
general rule is to use a double.
N O T E For those who cannot safely ignore the details, look at the floating-point specification
relevant to your hardware platform. The predominant implementation of floatingpoint storage and arithmetic is outlined in The IEEE Standard for FloatingPoint Arithmetic, IEEE 754.



Comparing Floating-Point Numbers for Equality: A Precaution
Comparison of floating-point numbers for equality may not behave as you would
expect.


One way to check whether two floating-point
numbers are equal is to check whether the absolute value of their difference is less than
a certain tolerance. For example, suppose the tolerance is 0.000001. Then, x and y are
equal if the absolute value of (x – y) is less than 0.000001. To find the absolute value,
you can use the function fabs (find the absolute value of a floating-point number), of
the header file cmath, as shown in the program. Therefore, the expression fabs(x – y)
< 0.000001 determines whether the absolute value of (x – y) is less than 0.000001.
