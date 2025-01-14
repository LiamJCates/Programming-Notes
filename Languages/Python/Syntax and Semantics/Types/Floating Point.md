Floating-Point Numbers

can be
defined either in standard decimal notation, or in exponential notation:
In [5]: x = 0.000005
y = 5e-6
print(x == y)
True
In [6]: x = 1400000.00
y = 1.4e6
print(x == y)
True

In the exponential notation, the e or E can be read "…times ten to the…", so that 1.4e6 is interpreted as 1.4 * 10^6.


An integer can be explicitly converted to a float with the float
constructor:
In [7]: float(1)
Out [7]: 1.0

likewise a float can be converted to an int, any fractional portion will be truncated

print(int(1.5))



Floating-point precision

floating-point arithmetic precision is limited:

In [8]: 0.1 + 0.2 == 0.3
Out [8]: False

This it is not a behavior unique to Python, but is due to the fixed-precision format of the binary floating-point storage used by most, if not all, scientific computing platforms. 

Python internally truncates these representations at 52 bits beyond the first nonzero bit on most systems.