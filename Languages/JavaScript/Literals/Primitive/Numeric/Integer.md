## Integer literals

Integer literals can be written in decimal (base 10), hexadecimal (base 16), octal (base 8) and binary (base 2).

    A decimal integer literal is a sequence of digits without a leading 0 (zero).
    A leading 0 (zero) on an integer literal, or a leading 0o (or 0O) indicates it is in octal. Octal integer literals can include only the digits 0 – 7.
    A leading 0x (or 0X) indicates a hexadecimal integer literal. Hexadecimal integers can include digits (0 – 9) and the letters a – f and A – F. (The case of a character does not change its value. Therefore: 0xa = 0xA = 10 and 0xf = 0xF = 15.)
    A leading 0b (or 0B) indicates a binary integer literal. Binary integer literals can only include the digits 0 and 1.
    A trailing n suffix on an integer literal indicates a BigInt literal. The BigInt literal can use any of the above bases. Note that leading-zero octal syntax like 0123n is not allowed, but 0o123n is fine.

Some examples of integer literals are:

0, 117, 123456789123456789n             (decimal, base 10)
015, 0001, 0o777777777777n              (octal, base 8)
0x1123, 0x00111, 0x123456789ABCDEFn     (hexadecimal, "hex" or base 16)
0b11, 0b0011, 0b11101001010101010101n   (binary, base 2)

For more information, see Numeric literals in the Lexical grammar reference.

