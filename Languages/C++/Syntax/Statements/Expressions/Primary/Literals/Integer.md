## Integer Literals
Integer literals begin with a digit and have no fractional parts or exponents. You can specify integer literals in decimal, binary, octal, or hexadecimal form.

| Representation | Base |Prefix | Example |
|----------------|------|-------|---------|
| decimal (default) | 10 | none | 65 |
| hexadecimal | 16 | 0x | 0x41 |
| octal | 8 | 0 | 0101 |
| binary | 2 | 0b | 0b1000001|




### Syntax
An integer literal has the form

decimal-literal integer-suffix(optional)
octal-literal integer-suffix(optional)
hex-literal integer-suffix(optional)
binary-literal integer-suffix(optional)	(since C++14)

where

decimal-literal is a non-zero decimal digit (1, 2, 3, 4, 5, 6, 7, 8, 9), followed by zero or more decimal digits (0, 1, 2, 3, 4, 5, 6, 7, 8, 9)

octal-literal is the digit zero (0)
followed by zero or more octal digits (0, 1, 2, 3, 4, 5, 6, 7)

hex-literal is the character sequence 0x or 0X
followed by one or more hexadecimal digits (0, 1, 2, 3, 4, 5, 6, 7, 8, 9, a, A, b, B, c, C, d, D, e, E, f, F)

binary-literal is the character sequence 0b or 0B
followed by one or more binary digits (0, 1)

integer-suffix, if provided, may contain one or both of the following (if both are provided, they may appear in any order:
  unsigned-suffix (the character u or the character U)
  either
  long-suffix (the character l or L)
  long-long-suffix (the character sequence ll or LL) (since C++11)




### Decimal
When no prefix or suffix is present, the compiler will give an integral literal value type int (32 bits), if the value will fit, otherwise it will give it type long long (64 bits).

For example, the integer literal 112114 could be held by an int, a long, or a long long. Since an int can store 112114, the resulting integer literal is an int. If you really want, say, a long, you can instead specify 112114L (or 112114l).

Examples:
65         // int
65u        // unsigned int
65l        // long
65ul       // unsigned long
65lu       // unsigned long
65ll       // long long
65ull      // unsigned long long
65llu      // unsigned long long



### Hexadecimal
To specify a hexadecimal integral literal, begin the specification with 0x or 0X (the case of the "x" doesn't matter), followed by a sequence of digits in the range 0 through 9 and a (or A) through f (or F). Hexadecimal digits a (or A) through f (or F) represent values in the range 10 through 15.

To specify an unsigned type, use either the u or U suffix. To specify a long type, use either the l or L suffix. To specify a 64-bit integral type, use the LL, or ll suffix.

Examples:
0x41         // hexadecimal literal  
0x41u        // unsigned int specified as hex literal
0x41l        // long specified as hex literal
0x41ul       // unsigned long specified as hex literal
0x41lu       // unsigned long specified as hex literal
0x41ll       // long long specified as hex literal
0x41ull      // unsigned long long specified as hex literal
0x41llu      // unsigned long long specified as hex literal



### Octal
To specify an octal integral literal, begin the specification with 0, followed by a sequence of digits in the range 0 through 7. The digits 8 and 9 are errors in specifying an octal literal.

The octal prefix is a holdover from the B language, back in the days of the PDP-8 computer and ubiquitous octal literals. C, and by extension C++, continues the dubious tradition.

You must be careful, for example, when you’re hardcoding ZIP codes:
int mit_zip_code = 02139; // Won't compile

This line doesn’t compile because 9 is not an octal digit.

Eliminate leading zeros on decimal literals; otherwise, they’ll cease to be decimal.

Examples:
0101         // octal literal
0101u        // unsigned int specified as octal literal
0101l        // long specified as octal literal
0101ul       // unsigned long specified as octal literal
0101lu       // unsigned long specified as octal literal
0101ll       // long long specified as octal literal
0101ull      // unsigned long long specified as octal literal
0101llu      // unsigned long long specified as octal literal



### Binary
A binary literal can be specified by the use of the 0B or 0b prefix, followed by a sequence of 1's and 0's

0b1000001         // binary literal
0b1000001u        // unsigned int specified as binary literal
0b1000001l        // long specified as binary literal
0b1000001ul       // unsigned long specified as binary literal
0b1000001lu       // unsigned long specified as binary literal
0b1000001ll       // long long specified as binary literal
0b1000001ull      // unsigned long long specified as binary literal
0b1000001llu      // unsigned long long specified as binary literal
