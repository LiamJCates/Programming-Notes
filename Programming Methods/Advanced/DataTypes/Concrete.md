# Concrete Data Type

A concrete type
  Constrains the values that can be represented by a group of bits
  Determines the way a value is stored in memory
  Defines how the system performs transformations on memory values



### Integer Example

Properties of computational integer's concrete data type:

Valid Values:
The value of a data unit with an integral type is the mathematical integer that it corresponds to a given configuration of bits. Integral types may be unsigned (capable of representing only non-negative integers) or signed (capable of representing negative integers), this is system dependent.

(Storage) Format:
The internal representation of integer data is the way the value is stored in the computer's memory. Unlike mathematical integers, a typical computational integer data unit has some minimal and maximum possible value. Integers are commonly represented in a computer as a group of binary digits (bits). The order of the memory bytes storing the bits varies; see endianness. The width or precision of an integral type is the number of bits in its representation. There are four well-known ways to represent signed numbers in a binary computing system. The most common is two's complement, which allows a signed integral type with n bits to represent numbers from −2(n−1) through 2(n−1) −1, where as an unsigned type typically represents the non-negative values 0 through 2(n) −1. Other possibilities include offset binary, sign-magnitude, and ones' complement. Some computer languages define integer sizes in a machine-independent way; others have varying definitions depending on the underlying processor word size (the natural unit of data used by a particular processor design). Not all language implementations define variables of all integer sizes, and defined sizes may not even be distinct in a particular implementation.

Operations:
Operations performed with computational integers are those defined by the systems chosen method of bit manipulation such that the transformation of the bits in a given memory unit represents values consistent with operations on the mathematical integers.
