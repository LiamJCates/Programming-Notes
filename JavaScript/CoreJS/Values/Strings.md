Strings in JavaScript are sequences of Unicode characters. This should be welcome news to anyone who has had to deal with internationalization. More accurately, they are sequences of UTF-16 code units; each code unit is represented by a 16-bit number. Each Unicode character is represented by either 1 or 2 code units.


### Representing Strings
You can use single quotes( ' ' ), double quotes ( " " ), or backticks ( ` ` ) to mark strings, as long as the quotes at the start and the end of the string match.

Strings written with single or double quotes behave very much the same—the only difference is in which type of quote you need to escape inside of them. Backtick-quoted strings, usually called template literals, can do a few more tricks.

Apart from being able to span lines, they can also embed other values.
When you write something inside ${} in a template literal, its result will be computed, converted to a string, and included at that position.
'half of 100 is ${100 / 2}'

Newlines can be included without escaping only when the string is quoted with backticks (\`).

If you want to represent a single character, you just use a string consisting of that single character.


### Length
To find the length of a string (in code units), access its length property:

'hello'.length; // 5

Strings are objects, they have methods as well that allow you to manipulate the string and access information about the string:

'hello'.charAt(0); // "h"
'hello, world'.replace('world', 'mars'); // "hello, mars"
'hello'.toUpperCase(); // "HELLO"








Escape Sequence
https://mathiasbynens.be/notes/javascript-escapes

The following characters are reserved in JavaScript and must be properly escaped to be used in strings:
Horizontal Tab is replaced with \t
Vertical Tab is replaced with \v
Nul char is replaced with \0
Backspace is replaced with \b
Form feed is replaced with \f
Newline is replaced with \n
Carriage return is replaced with \r
Single quote is replaced with \'
Double quote is replaced with \"
Backslash is replaced with \\


'abc\
def' == 'abcdef'; // true
The \ followed by a new line is not a character escape sequence, but a LineContinuation. The new line doesn’t become part of the string. This is simply a way to spread a string over multiple lines (for easier code editing, for example), without the string actually including any new line characters.




### String to Number Conversions
You can convert a string to an integer using the built-in parseInt() function.

parseInt('123', 10); // 123
parseInt('010', 10); // 10

This takes the base for the conversion as an optional second argument, which you should always provide

In older browsers, strings beginning with a "0" are assumed to be in octal (radix 8), but this hasn't been the case since 2013 or so. Unless you're certain of your string format, you can get surprising results on those older browsers:

parseInt('010');  //  8
parseInt('0x10'); // 16

Here, we see the parseInt() function treat the first string as octal due to the leading 0, and the second string as hexadecimal due to the leading "0x". The hexadecimal notation is still in place; only octal has been removed.

If you want to convert a binary number to an integer, just change the base:

parseInt('11', 2); // 3

Similarly, you can parse floating point numbers using the built-in parseFloat() function. Unlike its parseInt() cousin, parseFloat() always uses base 10.

You can also use the unary + operator to convert values to numbers:

+ '42';   // 42
+ '010';  // 10
+ '0x10'; // 16

A special value called NaN (short for "Not a Number") is returned if the string is non-numeric:

parseInt('hello', 10); // NaN

NaN is toxic: if you provide it as an operand to any mathematical operation, the result will also be NaN:

NaN + 5; // NaN

You can test for NaN using the built-in isNaN() function:

isNaN(NaN); // true

JavaScript also has the special values Infinity and -Infinity:

 1 / 0; //  Infinity
-1 / 0; // -Infinity

You can test for Infinity, -Infinity and NaN values using the built-in isFinite() function:

isFinite(1 / 0); // false
isFinite(-Infinity); // false
isFinite(NaN); // false

The parseInt() and parseFloat() functions parse a string until they reach a character that isn't valid for the specified number format, then return the number parsed up to that point. However the "+" operator converts the string to NaN if there is an invalid character contained within it. Just try parsing the string "10.2abc" with each method by yourself in the console and you'll understand the differences better.
