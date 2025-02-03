All programming languages using floating-point numbers store them in a fixed number of bits, and this leads some numbers to be represented only approximately:

print("0.1 = {0:.17f}".format(0.1))
print("0.2 = {0:.17f}".format(0.2))
print("0.3 = {0:.17f}".format(0.3))
0.1 = 0.10000000000000001
0.2 = 0.20000000000000001
0.3 = 0.29999999999999999

We're accustomed to thinking of numbers in decimal (base-10) notation, so that each fraction must be expressed as a sum of powers of 10:

1/8 = 1 · 10^-1 + 2 · 10^-2 + 5 · 10^-3

In the familiar base-10 representation, we represent this in the
familiar decimal expression: 0.125.

Computers usually store values in binary notation, so that each
number is expressed as a sum of powers of 2:

1/8 = 0 · 2^-1 + 0 · 2^-2 + 1 · 2^-3

In a base-2 representation, we can write this 0.0012, where the sub‐
script 2 indicates binary notation. The value 0.125 = 0.0012 happens
to be one number which both binary and decimal notation can rep‐
resent in a finite number of digits.

 bIn the familiar base-10 representation of numbers, you are probably familiar with numbers that can’t be expressed in a finite number of digits. For example, dividing 1 by 3 gives, in standard decimal notation:

1/3 = 0.333333333...

The 3s go on forever: that is, to truly represent this quotient, the
number of required digits is infinite!
Similarly, there are numbers for which binary representations
require an infinite number of digits. For example:

1/10 = 0.00011001100110011...<sub>2</sub>

Just as decimal notation requires an infinite number of digits to perfectly represent 1/3, binary notation requires an infinite number of digits to represent 1/10. 

For example Python internally truncates these representations at 52 bits beyond the first nonzero bit on most systems.

This rounding error for floating-point values is a necessary evil of
working with floating-point numbers. 

The best way to deal with it is to always keep in mind that floating-point arithmetic is approximate, and never rely on exact equality tests with floating-point values.