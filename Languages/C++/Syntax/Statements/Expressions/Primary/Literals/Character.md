## Character Literals
C++ supports various character types, and provides ways to express literal values of each of these types. In your source code, you express the content of your character literals using a character set.

A character literal is composed of a constant character. It's represented by the character surrounded by single quotation marks.

There are five kinds of character literals:

  Ordinary character literals of type char                    'a'
  UTF-8 character literals of type char (char8_t in C++20)    u8'a'
  Wide-character literals of type wchar_t                     L'a'
  UTF-16 character literals of type char16_t                  u'a'
  UTF-32 character literals of type char32_t                  U'a'


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
      excluding single-quote ('), backslash (\), or the newline character,
  escape sequence, as defined in escape sequences
  universal character name, as defined in escape sequences

c-char-sequence is a sequence of two or more c-chars.


### Character Literal Types
Character literals are encoded differently based their prefix.

1) narrow / ordinary character literal
  e.g. 'a' or '\n' or '\13'.
  A character literal without a prefix is an ordinary character literal. The value of an ordinary character literal containing a single character, escape sequence, or universal character name that can be represented in the execution character set has a value equal to the numerical value of its encoding in the execution character set. An ordinary character literal that contains more than one character, escape sequence, or universal character name is a multicharacter literal. A multicharacter literal or an ordinary character literal that can't be represented in the execution character set has type int, and its value is implementation-defined.
  Such literal has type char and the value equal to the representation of c-char in the execution character set. If c-char is not representable as a single byte in the execution character set, the literal has type int and implementation-defined value

2) UTF-8 character literal
  e.g. u8'a'
  A character literal that begins with the u8 prefix is a UTF-8 character literal. The value of a UTF-8 character literal containing a single character, escape sequence, or universal character name has a value equal to its ISO 10646 code point value if it can be represented by a single UTF-8 code unit (corresponding to the C0 Controls and Basic Latin Unicode block). If the value can't be represented by a single UTF-8 code unit, the program is ill-formed. A UTF-8 character literal containing more than one character, escape sequence, or universal character name is ill-formed.
  Such literal has type char (until C++20)char8_t (since C++20) and the value equal to ISO 10646 code point value of c-char, provided that the code point value is representable with a single UTF-8 code unit (that is, c-char is in the range 0x0-0x7F, inclusive). If c-char is not representable with a single UTF-8 code unit, the program is ill-formed.

3) UTF-16 character literal
  e.g. u'貓', but not u'🍌' (u'\U0001f34c')
  A character literal that begins with the u prefix is a UTF-16 character literal. The value of a UTF-16 character literal containing a single character, escape sequence, or universal character name has a value equal to its ISO 10646 code point value if it can be represented by a single UTF-16 code unit (corresponding to the basic multi-lingual plane). If the value can't be represented by a single UTF-16 code unit, the program is ill-formed. A UTF-16 character literal containing more than one character, escape sequence, or universal character name is ill-formed.
  Such literal has type char16_t and the value equal to ISO 10646 code point value of c-char, provided that the code point value is representable with a single UTF-16 code unit (that is, c-char is in the range 0x0-0xFFFF, inclusive). If c-char is not representable with a single UTF-16 code unit, the program is ill-formed.

4) UTF-32 character literal
  e.g. U'貓' or U'🍌'
  A character literal that begins with the U prefix is a UTF-32 character literal. The value of a UTF-32 character literal containing a single character, escape sequence, or universal character name has a value equal to its ISO 10646 code point value. A UTF-32 character literal containing more than one character, escape sequence, or universal character name is ill-formed.
  Such literal has type char32_t and the value equal to ISO 10646 code point value of c-char.

5) wide character literal
  e.g. L'β' or L'貓'.
  A character literal that begins with the L prefix is a wide-character literal. The value of a wide-character literal containing a single character, escape sequence, or universal character name has a value equal to the numerical value of its encoding in the execution wide-character set unless the character literal has no representation in the execution wide-character set, in which case the value is implementation-defined. The value of a wide-character literal containing multiple characters, escape sequences, or universal character names is implementation-defined.
  Such literal has type wchar_t and the value equal to the value of c-char in the execution wide character set. If c-char is not representable in the execution character set (e.g. a non-BMP value on Windows where wchar_t is 16-bit), the value of the literal is implementation-defined.
  If a wide character literal prefixed with L contains a multicharacter sequence, the value is taken from the first character, and the compiler raises warning C4066. Subsequent characters are ignored, unlike the behavior of the equivalent ordinary multicharacter literal.
  wchar_t w1 = L'\100';   // L'@'
  wchar_t w2 = L'\1000';  // C4066 L'@', 0 ignored
  wchar_t w3 = L'\009';   // C4066 L'\0', 9 ignored
  wchar_t w4 = L'\089';   // C4066 L'\0', 89 ignored
  wchar_t w5 = L'\qrs';   // C4129, C4066 L'q' escape, rs ignored
  wchar_t w6 = L'\x0050'; // L'P'
  wchar_t w7 = L'\x0pqr'; // C4066 L'\0', pqr ignored

6) Multicharacter literal
  e.g. 'AB'
  has type int and implementation-defined value.
  To create a value from a narrow multicharacter literal, the compiler converts the character or character sequence between single quotes into 8-bit values within a 32-bit integer. Multiple characters in the literal fill corresponding bytes as needed from high-order to low-order. The compiler then converts the integer to the destination type following the usual rules. For example, to create a char value, the compiler takes the low-order byte. To create a wchar_t or char16_t value, the compiler takes the low-order word. The compiler warns that the result is truncated if any bits are set above the assigned byte or word.
  char c0    = 'abcd';    // C4305, C4309, truncates to 'd'
  wchar_t w0 = 'abcd';    // C4305, C4309, truncates to '\x6364'
  int i0     = 'abcd';    // 0x61626364

Notes

Multicharacter literals were inherited by C from the B programming language. Although not specified by the C or C++ standard, most compilers (MSVC is a notable exception) implement multicharacter literals as specified in B: the values of each char in the literal initialize successive bytes of the resulting integer, in big-endian zero-padded right-adjusted order, e.g. the value of '\1' is 0x00000001 and the value of '\1\2\3\4' is 0x01020304.


int main()
{
    // Character literals
    auto c0 =   'A'; // char
    auto c1 = u8'A'; // char
    auto c2 =  L'A'; // wchar_t
    auto c3 =  u'A'; // char16_t
    auto c4 =  U'A'; // char32_t

    // Multicharacter literals
    auto m0 = 'abcd'; // int, value 0x61626364
}




### Escape Sequences
Some characters don’t display on the screen. Instead, they force the display to do things like move the cursor to the left side of the screen (carriage return) or move the cursor down one line (newline). Other characters can display onscreen, but they’re part of the C++ language syntax, such as single or double quotes, so you must use them very carefully. To put these characters into a char, you use the escape sequences.

There are three kinds of escape sequences: simple, octal, and hexadecimal.

#### Simple Escape Sequences

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


#### Numeric escape sequences
|Escape Sequence | Value | Representation |
|----------------|-------|----------------|
| \nnn | octal | byte nnn |
| \xnn | hexadecimal |byte nn |


#### Octal
Octal escape sequences have a limit of three octal digits, but terminate at the first character that is not a valid octal digit if encountered sooner.
The highest possible octal value is \377, as this is decimal 255.
An octal escape sequence that appears to contain more than three digits is treated as a 3-digit octal sequence, followed by the subsequent digits as characters in a multicharacter literal, which can give surprising results. For example:
char c1 = '\100';   // '@'
char c2 = '\1000';  // C4305, C4309, truncates to '0'

Escape sequences that appear to contain non-octal characters are evaluated as an octal sequence up to the last octal character, followed by the remaining characters as the subsequent characters in a multicharacter literal. Warning C4125 is generated if the first non-octal character is a decimal digit. For example:
char c3 = '\009';   // '9'
char c4 = '\089';   // C4305, C4309, truncates to '9'
char c5 = '\qrs';   // C4129, C4305, C4309, truncates to 's'

An octal escape sequence that has a higher value than \377 causes error C2022: 'value-in-decimal': too big for character.



#### Hexadecimal
Hexadecimal escape sequences have no length limit and terminate at the first character that is not a valid hexadecimal digit. If the value represented by a single hexadecimal escape sequence does not fit the range of values represented by the character type used in this string literal (char, char8_t (since C++20), char16_t, char32_t (since C++11), or wchar_t), the result is unspecified.  Leading zeroes are ignored. In an ordinary or u8-prefixed character literal, the highest hexadecimal value is 0xFF. In an L-prefixed or u-prefixed wide character literal, the highest hexadecimal value is 0xFFFF. In a U-prefixed wide character literal, the highest hexadecimal value is 0xFFFFFFFF.

An escape sequence that appears to have hexadecimal and non-hexadecimal characters is evaluated as a multicharacter literal that contains a hexadecimal escape sequence up to the last hexadecimal character, followed by the non-hexadecimal characters. A hexadecimal escape sequence that contains no hexadecimal digits causes compiler error C2153: "hex literals must have at least one hex digit".
char c6 = '\x0050'; // 'P'
char c7 = '\x0pqr'; // C4305, C4309, truncates to 'r'



#### Universal character names
|Escape Sequence | Value | Representation |
|----------------|-------|----------------|
| \unnnn | Unicode* C++11 | code point U+nnnn |
| \Unnnnnnnn | Unicode* C++11 | code point  U+nnnnnnnn |

*may result in several characters

Characters may be specified by using universal character names, as long as the type is large enough to hold the character.

You can specify Unicode character literals using the universal character names, and you can form a universal character name in one of two ways: the prefix \u followed by a 4-digit Unicode code point or the prefix \U followed by an 8-digit Unicode code point. All four or eight digits, respectively, must be present to make a well-formed universal character name.


A universal character name in a narrow string literal or a 16-bit string literal may map to more than one character, e.g. \U0001f34c is 4 char code units in UTF-8 (\xF0\x9F\x8D\x8C) and 2 char16_t code units in UTF-16 (\uD83C\uDF4C).

If a universal character name does not correspond to a code point in ISO/IEC 10646 (the range 0x0-0x10FFFF, inclusive) or if a universal-character-name corresponds to a surrogate code point (the range 0xD800-0xDFFF, inclusive), the program is ill-formed.

char u1 = 'A';          // 'A'
char u2 = '\101';       // octal, 'A'
char u3 = '\x41';       // hexadecimal, 'A'
char u4 = '\u0041';     // \u UCN 'A'
char u5 = '\U00000041'; // \U UCN 'A'




### Character Sets
The character sets that C++ uses at compile time and runtime are implementation-defined. A source file is read as a sequence of characters in the physical character set. When a source file is read, the physical characters are mapped to the compile-time character set, which is called the source character set. The mapping is implementation-defined, but many implementations use the same character set.

Several different character data sets are currently in use.

The most common are the:
  ASCII
  Unicode


the numeric value of a character, such as 'A', depends on the character
set. The compiler must decide which character set to use at compile time and at runtime. This is typically based on preferences that the end user selects in the host operating system. Character-set issues rarely arise for the basic subset of characters—such as letters, digits, and
punctuation symbols—that are used to write C++ source code. You will most likely find yourself using one
or more character sets that share some common characteristics. For example, all ISO 8859 character sets
use the same numeric values for the letters of the Roman alphabet, digits, and basic punctuation. Even most
Asian character sets preserve the values of these basic characters.
Thus, most programmers blithely ignore the character-set issue. We use character literals, such as '%',
and assume the program will function the way we expect it to, on any system, anywhere in the world—and
we are usually right. But not always.




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
