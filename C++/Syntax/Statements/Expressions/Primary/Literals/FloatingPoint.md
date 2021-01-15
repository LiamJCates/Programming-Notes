## Floating Point Literals
Floating-point numbers are recognized by a digit-sequence along with either a decimal point "." or an exponent


### Syntax
1)  (digit-sequence) (exponent) (suffix)*
2)  (digit-sequence) . (exponent)* (suffix)*
3)  (digit-sequence) . (digit-sequence) (exponent)* (suffix)*
since C++17
4)  0x | 0X (hex-digit-sequence) (exponent) (suffix)*
5)  0x | 0X (hex-digit-sequence) . (exponent) (suffix)*
6)  0x | 0X (hex-digit-sequence)* . (hex-digit-sequence) (exponent) (suffix)*
(*) optional

Note
No spaces are permitted between the significand (the base) and the
suffix (the exponential portion).



### Forms
1) digit-sequence representing a whole number without a decimal separator, in this case the exponent is not optional: 1e10, 1e-5L

2) digit-sequence representing a whole number with a decimal separator, in this case the exponent is optional: 1., 1.e-2

3) digit-sequence representing a fractional number. The exponent is optional: 3.14, .1f, 0.1e-1L

4) Hexadecimal digit-sequence representing a whole number without a radix separator. The exponent is never optional for hexadecimal floating-point literals: 0x1ffp10, 0X0p-1

5) Hexadecimal digit-sequence representing a whole number with a radix separator. The exponent is never optional for hexadecimal floating-point literals: 0x1.p0, 0xf.p-1

6) Hexadecimal digit-sequence representing a fractional number with a radix separator. The exponent is never optional for hexadecimal floating-point literals: 0x0.123p-1, 0xa.bp10l



### Exponent Form
e | E exponent-sign* digit-sequence 	(1) 	
p | P exponent-sign* digit-sequence 	(2) 	(since C++17)
(*) optional

1) The exponent syntax for a decimal floating-point literal
2) The exponent syntax for hexadecimal floating-point literal

exponent-sign, if present, is either + or -


### Suffix
The suffix determines the type of the floating-point literal:
suffix, if present, is one of f/F or l/L.

Floating-point literals are of three types:
  double precision specified by default.
  single precision specified by an f or F suffix
  extended precision specified by l or L suffix

Example:
  auto a = 0.1F;    //float
  auto b = 0.1;     //double
  auto c = 0.1L;    //long double



Optional single quotes (') can be inserted between the digits as a separator, they are ignored when compiling. 	(since C++14)




### Explanation

Decimal scientific notation represents the value of the floating-point literal as the significand multiplied by the number 10 raised to the power of exponent.

double d = 123e4 //digital sequence 123 scaled by 10^4


Since C++17, if the floating literal begins with the character sequence 0x or 0X, the floating literal is a hexadecimal floating literal. Otherwise, it is a decimal floating literal.

For a hexadecimal floating literal, the significand is interpreted as a hexadecimal rational number, and the digit-sequence of the exponent is interpreted as the integer power of 2 to which the significand has to be scaled.

double d = 0x1.4p3; // hex fraction 1.4 (decimal 1.25) scaled by 2^3, that is 10.0


Example

  #include <iostream>
  int main()
  {
    std::cout << 58.         << '\n'
              << 4e2         << '\n'
              << 123.456e-67 << '\n'
              << .1E4f       << '\n'
              << 0x10.1p0    << '\n';
  }

Output:

  58
  400
  1.23456e-65
  1000
  16.0625
