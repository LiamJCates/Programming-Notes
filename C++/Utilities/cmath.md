<cmath> Header

This header contains various function prototypes related to mathematical functions. Some of the prototypes that are used extensively are listed here.

|Function |	Description |
|---------|-------------|
| sqrt(x) | Accepts any non-negative numeric parameter x and returns the square root of this number x |
| pow(base,exponent) | Raises the ‘base’ value to the power specified by the exponent. Returns base^exponent. |
| exp(x) | Takes any number (positive, negative or zero) as a parameter and returns exponential (Euler’s number) e raised to the given parameter |
| abs(x) | Returns absolute value of an argument. |
|fmod(x, y) | Returns the remainder of x/y, result is always the same sign as x ex: mod(3,4) = 3 |
| remainder(x, y) | Returns the remainder of x/y ex: remainder(3,4) = -1  |
| log(x) | Returns the natural logarithm (to the base e) of value x |
| log 10(x) | Return the logarithm (to the base 10) of value x |
| sin(x) | Returns sine of the angle x (in radians) |
| cos(x) | Returns cosine of angle x (in radians) |
| tan(x) | Returns tangent of angle x (in radians) |
| asin(x) | Returns inverse sine (in radians) of number x |
| acos(x) | Returns inverse cosine (in radians) of number x |
| atan(x) | Returns inverse tangent (in radians) of number x |


#### absolute values

When defined by <cmath>,
abs() returns the absolute value of an integral value
fabs() accept all numeric types
fabsf() and fabsl() only float and long double.

Starting with C++17, abs() no longer converts integers into doubles (as is
conventional for <cmath>: see earlier). Instead, it behaves as abs() in
<cstdlib> for integral x’s.

When defined by <cstdlib>. Returns absolute value for an integral x. abs()
accepts int, long, or long long (smaller integral types are promoted
to int); labs() and llabs() only long and long long. The result has
the same (possibly promoted) type as the input.
