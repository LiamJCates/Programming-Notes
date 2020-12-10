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
