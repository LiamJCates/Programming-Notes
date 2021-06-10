### Literals
Literals are data used for representing fixed values. They can be used directly in the code. For example: 1, 2.5, 'c' etc.

Here, 1, 2.5 and 'c' are literals. Why? You cannot assign different values to these terms.

#### Integer Literals
An integer literal can be a decimal, octal, or hexadecimal constant. A prefix specifies the base or radix: 0x or 0X for hexadecimal, 0 for octal, and nothing for decimal.

An integer literal can also have a suffix that is a combination of U and L, for unsigned and long, respectively. The suffix can be uppercase or lowercase and can be in any order.

An integer literal with no suffix is an int.
  1234
the suffix l or L as well as an integer too big to fit into an int indicates a long literal.
  1L
  1234567890
the suffix u or U indicates an unsigned literal.
the suffix ul or UL indicates unsigned long literal.

A integer literal can be specified in octal or hexadecimal with a prefix
A 0 (zero) prefix means octal;
a 0x or 0X prefix means hexadecimal.

Octal and hexadecimal literals may also be suffixed to make them long and unsigned



85         /* decimal */
0213       /* octal */
0x4b       /* hexadecimal */
30         /* int */
30u        /* unsigned int */
30l        /* long */
30ul       /* unsigned long */
0xFUL      /* unsigned long hexadecimal */



#### Floating-Point Literals
Floating-point literals has an integer part, a decimal point and either a fractional part, an exponent part, or both.

While representing decimal form, you must include the decimal point, the exponent, or both;

While representing exponential form, you must include the integer part, the fractional part, or both. The signed exponent is introduced by e or E.

3.14159       /* Legal */
314159E-5L    /* Legal */
510E          /* Illegal: incomplete exponent */
210f          /* Illegal: no decimal or exponent */
.e55          /* Illegal: missing integer or fraction */

their type is double, unless suffixed:
f or F indicate a float.
l or L indicate a long double.



#### Character Literal
A character literal is an integer, written as one character within single quotes, such as 'x'.

The value of a character literal is the numeric value of the character in the machine's character set. For example, in the ASCII character set the character constant '0' has the value 48, which is unrelated to the numeric value 0. If we write '0' instead of a numeric value like 48 that depends on character set, the program is independent of the particular value and easier to read.

Character literals are enclosed in single quotes, e.g., 'x' can be stored in a simple variable of char type.

A character literal can be a plain character (e.g., 'x'), an escape sequence (e.g., '\t'), or a universal character (e.g., '\u02C0').

There are certain characters in C that represent special meaning when preceded by a backslash for example, newline (\n) or tab (\t) called escape sequences




#### Escape Sequences
Certain characters can be represented in character and string constants by escape sequences like \n (newline); these sequences look like two characters, but represent only one. In addition, an arbitrary byte-sized bit pattern can be specified by

\000

where 000 is one to three octal digits (0...7) or

\xhh

where hh is one or more hexadecimal digits (0 ...9, a ...f, A ..F).

So we might write

 #define VTAB '\013'  /* ASCII vertical tab */
 #define BELL '\007   /* ASCII bell character */

or, in hexadecimal,

  #define VTAB '\xb'
  #define BELL '\x7'

The complete set of escape sequences is
\a alert (bell) character
\\ backslash
\b backspace
\? question mark
\f formfeed
\' single quote
\n newline
\" double ,quote
\r carriage return
\000 octal number
\t horizontal tab
\xhh hexadecimal number
\v vertical tab


#### Null Character
The character literal '\0' represents the character with value zero, the null character. '\0' is often written instead of 0 to emphasize the character nature of some expression, but the numeric value is just O.




#### String Literals
A string literal is a sequence of zero or more characters surrounded by double quotes:

"I am a string"

or

""  /* the empty string */

The quotes are not part of the string, but serve only to delimit it.

Escape sequences apply in strings; \" represents the double-quote character.

A string contains characters that are similar to character literals: plain characters, escape sequences, and universal characters.

You can break a long line into multiple lines using string literals and separating them using white spaces as string literal can be concatenated at compile time:


"hello, world"

"hello, \

world"

"hello, " "w" "orld"

All the three forms are identical strings.

This is useful for splitting long strings across several source lines.

Careful
Be careful to distinguish between a character constant and a string that contains a single character: ' x' is not the same as "x". The former is an integer,
used to produce the numeric value of the letter x in the machine's character set.
The latter is an array of characters that contains one character (the letter x)
and a '\0'.


A string literal represents a one-dimensional array of characters terminated by a null character '\0'. Thus a null-terminated string contains the characters that comprise the string followed by a null. Thus the physical storage required is one more than the number of characters written between the quotes. This representation means that there is no limit to how long a string can be, but programs must scan a string completely to determine its length.

The standard library function strlen(s) returns the length of its character string arguments, excluding the terminal '\0'.
