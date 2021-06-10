Floating point representation is a lot more complicated in computers than it is for us human beings. C specification takes floating points description and specification from IEC 60559:1989 which is a standard for floating point arithmetic which is same as IEEE 754. In C there are three types of floating point numbers float, double and long double. It is described in specification in §(iso.5.2.4.2.2)

.

A floating-point number is used to represent real-world fractional value which is a trade-off between range and accuracy because as I said in fractional binary numbers, a decimal fraction cannot represented in binary unless the denominator of that number is an integral power of 2. A number is, in general, represented approximately to a fixed number of significant digits (the significand) and scaled using an exponent; numbers are usually binary, octal, decimal or hexadecimal. A number that can be represented exactly is of the following form:

significand × base^exponent

The term floating point refers to the fact that a number’s radix point (decimal point, or, more commonly in computers, binary point) can “float”; that is, it can be placed anywhere relative to the significant digits of the number.

#### Representation of Floating-Point Numbers

32 bit:
| 1 sign bit | 8 exponent bits | 23 fraction bits |

64 bit:
| 1 sign bit | 11 exponent bits| 52 fractional bits |

C also has concept of positive and negative infinities. Sign bit is 0 for positive infinity and 1 for negative infinity. Fractional bits are 1 while exponent bits are all 1.

Certain operations cause floating point exceptions like division from zero or square rooting a negative number. Such exceptions are represented by NANs which stands for “not a number”. Sign for NaNs is similar i.e. 0 for positive and 1 for negative. Exponent bits are 1 and fractional part is anything but all 0s because that represents positive infinity.
