## Character Literals
A character literal typically represents a single, constant character value

Single quotation marks (' ') surround a character literal.

If the character is any type but char, you must also provide a prefix:
L for wchar_t,
u for char16_t,
U for char32_t
u8 for char8_t

For example, 'J' declares a char literal and L'J' declares a wchar_t.


### Syntax
Character Literals

| Syntax | type | width | name | version |
|--------|------|-------|------|---------|
| 'c-char' | char | 8-bit | narrow / ordinary | |
| u8'c-char' | char | 8-bit | UTF-8  | |
| u8'c-char' | char8_t | 8-bit | UTF-8 | C++20 |  
| u'c-char' | char16_t | 16-bit | UTF-16 | C++11 |
| U'c-char' | char32_t | 32-bit | UTF-32 | C++11 |
| L'c-char' | wchar_t | 16/32-bit | wide character | |
| 'c-char-sequence' | int | 32-bit | multicharacter | |

where
c-char is either
  a character from the source character set
      minus single-quote ('), backslash (\), or the newline character,
  escape sequence, as defined in escape sequences
  universal character name, as defined in escape sequences

c-char-sequence is a sequence of two or more c-chars.


### Character Literal Types
1) narrow / ordinary character literal
  e.g. 'a' or '\n' or '\13'.
  Such literal has type char and the value equal to the representation of c-char in the execution character set. If c-char is not representable as a single byte in the execution character set, the literal has type int and implementation-defined value

2) UTF-8 character literal
  e.g. u8'a'
  Such literal has type char (until C++20)char8_t (since C++20) and the value equal to ISO 10646 code point value of c-char, provided that the code point value is representable with a single UTF-8 code unit (that is, c-char is in the range 0x0-0x7F, inclusive). If c-char is not representable with a single UTF-8 code unit, the program is ill-formed.

3) UTF-16 character literal
  e.g. u'貓', but not u'🍌' (u'\U0001f34c')
  Such literal has type char16_t and the value equal to ISO 10646 code point value of c-char, provided that the code point value is representable with a single UTF-16 code unit (that is, c-char is in the range 0x0-0xFFFF, inclusive). If c-char is not representable with a single UTF-16 code unit, the program is ill-formed.

4) UTF-32 character literal
  e.g. U'貓' or U'🍌'
  Such literal has type char32_t and the value equal to ISO 10646 code point value of c-char.

5) wide character literal
  e.g. L'β' or L'貓'.
  Such literal has type wchar_t and the value equal to the value of c-char in the execution wide character set. If c-char is not representable in the execution character set (e.g. a non-BMP value on Windows where wchar_t is 16-bit), the value of the literal is implementation-defined.

6) Multicharacter literal
  e.g. 'AB'
  has type int and implementation-defined value.

Notes

Multicharacter literals were inherited by C from the B programming language. Although not specified by the C or C++ standard, most compilers (MSVC is a notable exception) implement multicharacter literals as specified in B: the values of each char in the literal initialize successive bytes of the resulting integer, in big-endian zero-padded right-adjusted order, e.g. the value of '\1' is 0x00000001 and the value of '\1\2\3\4' is 0x01020304.






### Escape Sequences
Some characters don’t display on the screen. Instead, they force the display to do things like move the cursor to the left side of the screen (carriage return) or move the cursor down one line (newline). Other characters can display onscreen, but they’re part of the C++ language syntax, such as single or double quotes, so you must use them very carefully. To put these characters into a char, you use the escape sequences

Reserved Characters and Their Escape Sequences

| Value | Escape sequence |
|-------|-----------------|
| Newline | \n |
| Tab (horizontal) | \t |
| Tab (vertical) | \v |
| Backspace | \b |
| Carriage return | \r |
| Form feed | \f |
| Alert | \a |
| Backslash | \\ |
| Question mark | \? |
| Single quote | \' |
| Double quote | \" |
| null character | \0 |


Numeric escape sequences
|Escape Sequence | Value | Representation |
|----------------|-------|----------------|
| \nnn | octal | byte nnn |
| \xnn | hexadecimal |byte nn |

Octal escape sequences have a limit of three octal digits, but terminate at the first character that is not a valid octal digit if encountered sooner.

Hexadecimal escape sequences have no length limit and terminate at the first character that is not a valid hexadecimal digit. If the value represented by a single hexadecimal escape sequence does not fit the range of values represented by the character type used in this string literal (char, char8_t (since C++20), char16_t, char32_t (since C++11), or wchar_t), the result is unspecified.


Universal character names
|Escape Sequence | Value | Representation |
|----------------|-------|----------------|
| \unnnn | Unicode* C++11 | code point U+nnnn |
| \Unnnnnnnn | Unicode* C++11 | code point  U+nnnnnnnn |

*may result in several characters

You can specify Unicode character literals using the universal character names, and you can form a universal character name in one of two ways: the prefix \u followed by a 4-digit Unicode code point or the prefix \U followed by an 8-digit Unicode code point.


A universal character name in a narrow string literal or a 16-bit string literal may map to more than one character, e.g. \U0001f34c is 4 char code units in UTF-8 (\xF0\x9F\x8D\x8C) and 2 char16_t code units in UTF-16 (\uD83C\uDF4C).

If a universal character name does not correspond to a code point in ISO/IEC 10646 (the range 0x0-0x10FFFF, inclusive) or if a universal-character-name corresponds to a surrogate code point (the range 0xD800-0xDFFF, inclusive), the program is ill-formed.





### Character Sets
The character sets that C++ uses at compile time and runtime are implementation-defined. A source file is read as a sequence of characters in the physical character set. When a source file is read, the physical characters are mapped to the compile-time character set, which is called the source character set. The mapping is implementation-defined, but many implementations use the same character set.

Several different character data sets are currently in use.

The most common are the:
  ASCII
  Unicode


### ASCII
The American Standard Code for Information Interchange (ASCII) table assigns integers to characters.

Each of the 128 values of the ASCII character set represents a different character.

For example:
the value 65 represents 'A'
the value 43 represents '+'.

Thus, each character has a predefined ordering represented by the numeric value associated with the character. This ordering is called a collating sequence, in the set.

The collating sequence is used when you compare characters.
For example,
the value representing 'B' is 66, so 'A' is smaller than 'B'.
Similarly, '+' is smaller than 'A' because 43 is smaller than 65.

ASCII codes 0 to 31 are the control code characters that control devices. These are mostly anachronisms. When the American Standards Association formalized ASCII in the 1960s, modern devices included teletype machines, magnetic tape readers, and dot-matrix printers. Some control codes still in common use are the following:

•	 0 (NULL) is used as a string terminator by programming languages.
•	 4 (EOT), the end of transmission, terminates shell sessions and PostScript printer communications.
•	 7 (BELL) causes a device to make a noise.
•	 8 (BS), the backspace, causes the device to erase the last character.
•	 9 (HT), the horizontal tab, moves a cursor several spaces to the right.
•	 10 (LF), the line feed, is used as the end-of-line marker on most operating systems.
•	 13 (CR), the carriage return, is used in combination with LF as the end-of-line marker on Windows systems.
•	 26 (SUB), the substitute character/end of file/ctrl-Z, suspends the currently executing interactive process on most operating systems.

The remainder of the ASCII table, codes from 32 to 127, is the printable characters. These represent the English characters, digits, and punctuation.

On most systems, the char type’s representation is ASCII. Although this relationship is not strictly guaranteed, it is a de facto standard.




### Unicode
Unicode is maintained by Unicode Consortium. It covers a wide range of characters. It contains representations for letters in languages such as English, Greek, Arabic etc., mathematical symbols, emoji and many more.

Unicode is a superset of ASCII.

There are three types of encoding available in Unicode.
They are UTF-8, UTF-16 and UTF-32.

UTF-8 uses 8 bits per character
UTF-16 uses 16 bit per character
UTF-32 uses 32 bits for a character

In UTF-8, the first 128 characters are the ASCII characters. Therefore, ASCII is valid in UTF-8. Usually, Unicode is used in internationalization and localization of computer software. This standard is also used in operating systems, XML, .NET framework and programming languages such as Java.
