### String literals

A string literal is zero or more Unicode code points enclosed in single or double quotes. Unicode code points may also be represented by an escape sequence. All code points may appear literally in a string literal except for these code points:

    U+005C \ (backslash)
    U+000D <CR>
    U+000A <LF>
    The same kind of quote that begins the string literal

Any code points may appear in the form of an escape sequence. String literals evaluate to ECMAScript String values. When generating these String values Unicode code points are UTF-16 encoded.

```js
'foo'
"bar"
```

The following subsections describe various escape sequences (\ followed by one or more characters) available in string literals. Any escape sequence not listed below becomes an "identity escape" that becomes the code point itself. For example, \z is the same as z. There's a deprecated octal escape sequence syntax described in the Deprecated and obsolete features page. Many of these escape sequences are also valid in regular expressions — see Character escape.
Escape sequences

Special characters can be encoded using escape sequences:
Escape sequence 	Unicode code point
\0 	null character (U+0000 NULL)
\' 	single quote (U+0027 APOSTROPHE)
\" 	double quote (U+0022 QUOTATION MARK)
\\ 	backslash (U+005C REVERSE SOLIDUS)
\n 	newline (U+000A LINE FEED; LF)
\r 	carriage return (U+000D CARRIAGE RETURN; CR)
\v 	vertical tab (U+000B LINE TABULATION)
\t 	tab (U+0009 CHARACTER TABULATION)
\b 	backspace (U+0008 BACKSPACE)
\f 	form feed (U+000C FORM FEED)
\ followed by a line terminator 	empty string

The last escape sequence, \ followed by a line terminator, is useful for splitting a string literal across multiple lines without changing its meaning.

```js
const longString =
  "This is a very long string which needs \
to wrap across multiple lines because \
otherwise my code is unreadable.";
```

Make sure there is no space or any other character after the backslash (except for a line break), otherwise it will not work. If the next line is indented, the extra spaces will also be present in the string's value.

You can also use the + operator to append multiple strings together, like this:

```js
const longString =
  "This is a very long string which needs " +
  "to wrap across multiple lines because " +
  "otherwise my code is unreadable.";
```

Both of the above methods result in identical strings.

#### Hexadecimal escape sequences

Hexadecimal escape sequences consist of \x followed by exactly two hexadecimal digits representing a code unit or code point in the range 0x0000 to 0x00FF.

```js
"\xA9"; // "©"
```

#### Unicode escape sequences

A Unicode escape sequence consists of exactly four hexadecimal digits following \u. It represents a code unit in the UTF-16 encoding. For code points U+0000 to U+FFFF, the code unit is equal to the code point. Code points U+10000 to U+10FFFF require two escape sequences representing the two code units (a surrogate pair) used to encode the character; the surrogate pair is distinct from the code point.

See also String.fromCharCode() and String.prototype.charCodeAt().

```js
"\u00A9"; // "©" (U+A9)
```

#### Unicode code point escapes

A Unicode code point escape consists of \u{, followed by a code point in hexadecimal base, followed by }. The value of the hexadecimal digits must be in the range 0 and 0x10FFFF inclusive. Code points in the range U+10000 to U+10FFFF do not need to be represented as a surrogate pair.

See also String.fromCodePoint() and String.prototype.codePointAt().

```js
"\u{2F804}"; // CJK COMPATIBILITY IDEOGRAPH-2F804 (U+2F804)

// the same character represented as a surrogate pair
"\uD87E\uDC04";
```






There are two types of strings:

     - **Single-line String**: Enclosed by single (`' '`) or double (`" "`) quotes. Does not allow line breaks and whitespaces.

     - **Multi-line String**: Enclosed by backticks (`` ` ``). Allows line breaks and whitespaces. Also known as template strings, they allow the insertion of variables and expressions directly using `${variable_name}` notation.


String literals

A string literal is zero or more characters enclosed in double (") or single (') quotation marks. A string must be delimited by quotation marks of the same type (that is, either both single quotation marks, or both double quotation marks).

The following are examples of string literals:
js

'foo'
"bar"
'1234'
'one line \n another line'
"Joyo's cat"

You should use string literals unless you specifically need to use a String object. See String for details on String objects.

You can call any of the String object's methods on a string literal value. JavaScript automatically converts the string literal to a temporary String object, calls the method, then discards the temporary String object. You can also use the length property with a string literal:
js

// Will print the number of symbols in the string including whitespace.
console.log("Joyo's cat".length); // In this case, 10.

Template literals are also available. Template literals are enclosed by the back-tick (`) (grave accent) character instead of double or single quotes.

Template literals provide syntactic sugar for constructing strings. (This is similar to string interpolation features in Perl, Python, and more.)
js

// Basic literal string creation
`In JavaScript '\n' is a line-feed.`

// Multiline strings
`In JavaScript, template strings can run
 over multiple lines, but double and single
 quoted strings cannot.`

// String interpolation
const name = 'Lev', time = 'today';
`Hello ${name}, how are you ${time}?`

Tagged templates are a compact syntax for specifying a template literal along with a call to a "tag" function for parsing it. A tagged template is just a more succinct and semantic way to invoke a function that processes a string and a set of relevant values. The name of the template tag function precedes the template literal — as in the following example, where the template tag function is named print. The print function will interpolate the arguments and serialize any objects or arrays that may come up, avoiding the pesky [object Object].
js

const formatArg = (arg) => {
  if (Array.isArray(arg)) {
    // Print a bulleted list
    return arg.map((part) => `- ${part}`).join("\n");
  }
  if (arg.toString === Object.prototype.toString) {
    // This object will be serialized to "[object Object]".
    // Let's print something nicer.
    return JSON.stringify(arg);
  }
  return arg;
};

const print = (segments, ...args) => {
  // For any well-formed template literal, there will always be N args and
  // (N+1) string segments.
  let message = segments[0];
  segments.slice(1).forEach((segment, index) => {
    message += formatArg(args[index]) + segment;
  });
  console.log(message);
};

const todos = [
  "Learn JavaScript",
  "Learn Web APIs",
  "Set up my website",
  "Profit!",
];

const progress = { javascript: 20, html: 50, css: 10 };

print`I need to do:
${todos}
My current progress is: ${progress}
`;

// I need to do:
// - Learn JavaScript
// - Learn Web APIs
// - Set up my website
// - Profit!
// My current progress is: {"javascript":20,"html":50,"css":10}

Since tagged template literals are just sugar of function calls, you can re-write the above as an equivalent function call:
js

print(["I need to do:\n", "\nMy current progress is: ", "\n"], todos, progress);

This may be reminiscent of the console.log-style interpolation:
js

console.log("I need to do:\n%o\nMy current progress is: %o\n", todos, progress);

You can see how the tagged template reads more naturally than a traditional "formatter" function, where the variables and the template itself have to be declared separately.
Using special characters in strings

In addition to ordinary characters, you can also include special characters in strings, as shown in the following example.
js

"one line \n another line";

The following table lists the special characters that you can use in JavaScript strings.
Character 	Meaning
\0 	Null Byte
\b 	Backspace
\f 	Form Feed
\n 	New Line
\r 	Carriage Return
\t 	Tab
\v 	Vertical tab
\' 	Apostrophe or single quote
\" 	Double quote
\\ 	Backslash character
\XXX 	The character with the Latin-1 encoding specified by up to three octal digits XXX between 0 and 377. For example, \251 is the octal sequence for the copyright symbol.
\xXX 	The character with the Latin-1 encoding specified by the two hexadecimal digits XX between 00 and FF. For example, \xA9 is the hexadecimal sequence for the copyright symbol.
\uXXXX 	The Unicode character specified by the four hexadecimal digits XXXX. For example, \u00A9 is the Unicode sequence for the copyright symbol. See Unicode escape sequences.
\u{XXXXX} 	Unicode code point escapes. For example, \u{2F804} is the same as the Unicode escapes \uD87E\uDC04.
Escaping characters

For characters not listed in the table, a preceding backslash is ignored, but this usage is deprecated and should be avoided.

You can insert a quotation mark inside a string by preceding it with a backslash. This is known as escaping the quotation mark. For example:
js

const quote = "He read \"The Cremation of Sam McGee\" by R.W. Service.";
console.log(quote);

The result of this would be:

He read "The Cremation of Sam McGee" by R.W. Service.

To include a literal backslash inside a string, you must escape the backslash character. For example, to assign the file path c:\temp to a string, use the following:
js

const home = "c:\\temp";

You can also escape line breaks by preceding them with backslash. The backslash and line break are both removed from the value of the string.
js

const str =
  "this string \
is broken \
across multiple \
lines.";
console.log(str); // this string is broken across multiple lines.



### Numbers and the '+' operator

In expressions involving numeric and string values with the + operator, JavaScript converts numeric values to strings. For example, consider the following statements:
js

x = "The answer is " + 42; // "The answer is 42"
y = 42 + " is the answer"; // "42 is the answer"
z = "37" + 7; // "377"

With all other operators, JavaScript does not convert numeric values to strings. For example:
js

"37" - 7; // 30
"37" * 7; // 259

### Converting strings to numbers

In the case that a value representing a number is in memory as a string, there are methods for conversion.

    parseInt()
    parseFloat()

parseInt only returns whole numbers, so its use is diminished for decimals.

Note: Additionally, a best practice for parseInt is to always include the radix parameter. The radix parameter is used to specify which numerical system is to be used.
js

parseInt("101", 2); // 5

An alternative method of retrieving a number from a string is with the + (unary plus) operator:
js

"1.1" + "1.1"; // '1.11.1'
(+"1.1") + (+"1.1"); // 2.2
// Note: the parentheses are added for clarity, not required.


### Parsing Numeric Values
- **Functions:**  
  Use `parseInt()`, `parseFloat()`, or the `Number()` constructor to convert strings to numbers.
- **Examples:**
  ```javascript
  console.log(parseInt("42", 10));    // 42
  console.log(parseFloat("3.14"));     // 3.14
  console.log(Number("123"));          // 123
  ```

---