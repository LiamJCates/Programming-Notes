# Literals
A literal constant is a hardcoded value in a program.


## Integer Literals
You can use one of four hardcoded, integer literal representations:
decimal default no prefix
hexadecimal prefix 0x
octal prefix 0
binary prefix 0b

Integer literals are by default decimal (e.g., 42 means forty-two).
A 0b prefix indicates a binary (base 2) integer literal (e.g., 0b10101010).
A 0x prefix indicates a hexadecimal (base 16) integer literal (e.g., 0xBAD1234).
A 0 prefix indicates an octal (base 8) integer literal (e.g., 0334).

The octal prefix is a holdover from the B language, back in the days of the PDP-8 computer and ubiquitous octal literals. C, and by extension C++, continues the dubious tradition. You must be careful, for example, when you’re hardcoding ZIP codes:
int mit_zip_code = 02139; // Won't compile

This line doesn’t compile because 9 is not an octal digit.

Eliminate leading zeros on decimal literals; otherwise, they’ll cease to be decimal.

By default, an integer literal’s type is one of the following: int, long, or long long. An integer literal’s type is the smallest of these three types that fits. (This is defined by the language and will be enforced by the compiler.) This means that among all types allowed for a particular integer, the smallest type will apply. For example, the integer literal 112114 could be held by an int, a long, or a long long. Since an int can store 112114, the resulting integer literal is an int.

If you want more control, you can supply suffixes to an integer literal to specify its type (suffixes are case insensitive, so you can choose the style you like best):
•	 The unsigned suffix u or U
•	 The long suffix l or L
•	 The long long suffix ll or LL

If you really want, say, a long, you can instead specify 112114L
(or 112114l).

Examples:
85         // decimal
0213       // octal
0x4b       // hexadecimal
30         // int
30u        // unsigned int
30l        // long
30ul       // unsigned long


### Boolean Literals
To initialize Boolean types, you use two Boolean literals, true and false





## Character Literals
A character literal is a single, constant character. Single quotation marks (' ') surround a character. If the character is any type but char, you must also provide a prefix:
L for wchar_t,
u for char16_t,
U for char32_t.

For example, 'J' declares a char literal and L'J' declares a wchar_t.


### Escape Sequences
Some characters don’t display on the screen. Instead, they force the display
to do things like move the cursor to the left side of the screen (carriage
return) or move the cursor down one line (newline). Other characters can
display onscreen, but they’re part of the C++ language syntax, such as single
or double quotes, so you must use them very carefully. To put these characters into a char, you use the escape sequences

Reserved Characters and Their Escape Sequences

| Value | Escape sequence |
|-------|-----------------|
| Newline | \n |
| Tab (horizontal) | \t |
|Tab (vertical) | \v |
|Backspace | \b |
|Carriage return | \r |
|Form feed | \f |
|Alert | \a |
|Backslash | \\ |
|Question mark | ? or \? |
|Single quote | \' |
|Double quote | \" |
|The null character | \0 |

Several different character data sets are currently in use. The most common are the
American Standard Code for Information Interchange (ASCII) and Extended BinaryCoded Decimal Interchange Code (EBCDIC). The ASCII character set has 128 values.
The EBCDIC character set has 256 values and was created by IBM.

### ASCII
The American Standard Code for Information Interchange (ASCII) table assigns integers to characters.

Each of the 128 values of the ASCII character set represents a different character. For example, the value 65 represents 'A', and the value 43 represents '+'. Thus, each character has a predefined ordering represented by the numeric value associated with the
character. This ordering is called a collating sequence, in the set. The collating sequence is used when you compare characters. For example, the value representing 'B' is 66, so 'A' is smaller than 'B'. Similarly, '+' is smaller than 'A' because 43 is smaller than 65.

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



### Unicode Escape Characters
You can specify Unicode character literals using the universal character names,
and you can form a universal character name in one of two ways: the prefix
\u followed by a 4-digit Unicode code point or the prefix \U followed by an
8-digit Unicode code point.






## Floating Point Literals
Floating-point numbers are recognized by:
decimal point (e.g., 3.14)
exponent (e.g., 3e−2).

A floating-point literal has an integer part, a decimal point, a fractional part, and an exponent part. You can represent floating point literals either in decimal form or exponential form.

Floating-point literals are double precision by default.

If you need single precision, use an f or F suffix; for extended precision, use l or L, as shown here:
float a = 0.1F;
double b = 0.2;
long double c = 0.3L;

You can also use scientific notation in literals:
double plancks_constant = 6.62607004ue-34v;

No spaces are permitted between the significand (the base u) and the
suffix (the exponential portion v).

While representing using decimal form, you must include the decimal point, the exponent, or both and while representing using exponential form, you must include the integer part, the fractional part, or both. The signed exponent is introduced by e or E.

3.14159       // Legal
314159E-5L    // Legal

### Chunking Seperators
C++14 adds support for chunking separators in the form of a
single quotation mark:

Integer and Floating Point literals can contain any number of single quotes (') for readability.  These are completely ignored by the compiler.

int moneyInBank = -70'000; // -70000
long populationChange = -85'000; // -85000
long long countryGDPChange = -70'000'000'000; //
-70 billion
double pi = 3.141'592'653'59; // 3.14159265359
long double π is about 3.14159'26535'89793'23846'26433'83279'50288
hexadecimal π is 0x3.243F'6A88'85A3'08D3.










## String Literals
String Literals
Declare string literals by enclosing text in quotation marks (""). Like character literals, string literals support Unicode: just prepend the literal with
the appropriate prefix, such as L. The following example assigns string literals
to the arrays english and chinese:
char english[] = "A book holds a house of gold.";
char16_t chinese[] = u"\u4e66\u4e2d\u81ea\u6709\u9ec4\u91d1\u5c4b";

Printing Unicode to the console is surprisingly complicated. Typically, you need to ensure that the correct code page is selected. If you need to embed Unicode characters into a string literal, look at
wprintf in the <cwchar> header.

Consecutive string literals get concatenated together, and any intervening whitespaces or newlines get ignored. So, you can place string literals on multiple lines in your source, and the compiler will treat them as one:
#include <cstdio>
int main() {
char house[] = "a "
"house "
"of " "gold.";
printf("A book holds %s\n ", house);
}

Usually, such constructions are useful for readability only when you
have a long string literal that would span multiple lines in your source code.
