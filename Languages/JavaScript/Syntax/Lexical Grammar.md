Lexical grammar

This page describes JavaScript's lexical grammar. 

JavaScript source text is just a sequence of characters — in order for the interpreter to understand it, the string has to be parsed to a more structured representation. 

The initial step of parsing is called lexical analysis, in which the text gets scanned from left to right and is converted into a sequence of individual, atomic input elements (tokens). 
    
Significant tokens will be used for further syntax analysis:
    operators
    punctuators
    keywords 
    identifiers
    literals
    



In JavaScript, a **token** is the smallest unit of the programming language. Tokens are categorized into five primary types:

1. **Operators**

   Symbols or words that represent mathematical, logical, or other operations. Examples include:

   - Arithmetic Operators: `+`, `-`, `*`, `/`

   - Assignment Operators: `=`, `+=`, `-=`

   - Comparison Operators: `==`, `===`, `!=`, `!==`

   - Logical Operators: `&&`, `||`, `!`

   - Type Operators: `typeof`, `instanceof`

2. **Punctuators**

   Symbols used to group, separate, or punctuate code. Examples include:

   - Parentheses: `()`

   - Curly Braces: `{}`

   - Square Brackets: `[]`

   - Comma: `,`

   - Semicolon: `;`

   - Period (used to access object properties): `.`


   Values used directly in the program, such as numbers (`2`), strings (`'hello world'`), etc.




Insignificant tokens are stripped:
    white space
    comments 

Line terminators and multiline comments are also syntactically insignificant, but they guide the process for automatic semicolons insertion to make certain invalid token sequences become valid.




## Format-Control Characters

Format-control characters have no visual representation but are used to control the interpretation of the text.

| Code Point | Name                        | Abbreviation | Description                                                                                   |
|------------|-----------------------------|--------------|-----------------------------------------------------------------------------------------------|
| U+200C     | Zero Width Non-Joiner       | `<ZWNJ>`     | Prevents characters from being displayed as a ligature.                                       |
| U+200D     | Zero Width Joiner           | `<ZWJ>`      | Causes characters to be displayed as a ligature.                                              |
| U+FEFF     | Byte Order Mark             | `<BOM>`      | Indicates the byte order of a text stream and can also signal that the text is encoded in Unicode. |

In JavaScript source text, <ZWNJ> and <ZWJ> are treated as identifier parts, while <BOM> (also called a zero-width no-break space <ZWNBSP> when not at the start of text) is treated as white space.


## White Space Characters


White space characters improve the readability of source text and separate tokens from each other. These characters are usually unnecessary for the functionality of the code. Minification tools are often used to remove whitespace in order to reduce the amount of data that needs to be transferred


| Code Point | Name                         | Abbreviation | Description        | Escape Sequence |
|------------|------------------------------|--------------|--------------------|-----------------|
| U+0009     | Character Tabulation         | `<HT>`       | Horizontal tab     | `\t`            |
| U+000B     | Line Tabulation              | `<VT>`       | Vertical tab       | `\v`            |
| U+000C     | Form Feed                    | `<FF>`       | Form feed          | `\f`            |
| U+0020     | Space                        | `<SP>`       | Space character    |                 |
| U+00A0     | No-Break Space               | `<NBSP>`     | Non-breaking space |                 |
| U+FEFF     | Zero Width No-Break Space    | `<ZWNBSP>`   | Byte order mark    |                 |



## Line Terminators


In addition to white space characters, line terminator characters are used to improve the readability of the source text. However, in some cases, line terminators can influence the execution of JavaScript code as there are a few places where they are forbidden. Line terminators also affect the process of automatic semicolon insertion.

Outside the context of lexical grammar, white space and line terminators are often conflated. For example, String.prototype.trim() removes all white space and line terminators from the beginning and end of a string. The \s character class escape in regular expressions matches all white space and line terminators.

Only the following Unicode code points are treated as line terminators in ECMAScript, other line breaking characters are treated as white space (for example, Next Line, NEL, U+0085 is considered as white space).

| Code Point | Name             | Abbreviation | Description        | Escape Sequence |
|------------|------------------|--------------|--------------------|-----------------|
| U+000A     | Line Feed        | `<LF>`       | Line feed          | `\n`            |
| U+000D     | Carriage Return  | `<CR>`       | Carriage return    | `\r`            |
| U+2028     | Line Separator   |              | Line separator     |                 |
| U+2029     | Paragraph Separator |           | Paragraph separator|                 |

These tables summarize the format-control characters, white space characters, and line terminators as described in the MDN article on JavaScript's lexical grammar. 




## Comments

See Comments:
[Languages\JavaScript\Comments.md]



## Identifiers

Names given by users to variables, functions, and other objects in the code. Rules for identifiers include:

   - Cannot start with a number.

   - Should not be a keyword.

   - If composed of multiple words, use an underscore (`_`) or camelCase instead of spaces.

   - Should not contain special characters but can start with an underscore (`_`) or dollar sign (`$`).

An identifier is used to link a value with a name. Identifiers can be used in various places:

```javascript
const decl = 1; // Variable declaration (may also be `let` or `var`)
function fn() {} // Function declaration
const obj = { key: "value" }; // Object keys
// Class declaration
class C {
  #priv = "value"; // Private property
}
lbl: console.log(1); // Label
```

In JavaScript, identifiers are commonly made of alphanumeric characters, underscores (_), and dollar signs ($). Identifiers are not allowed to start with numbers. However, JavaScript identifiers are not only limited to ASCII — many Unicode code points are allowed as well. Namely:

    Start characters can be any character in the ID_Start category plus _ and $.
    After the first character, you can use any character in the ID_Continue category plus U+200C (ZWNJ) and U+200D (ZWJ).

Note: If, for some reason, you need to parse some JavaScript source yourself, do not assume all identifiers follow the pattern /[A-Za-z_$][\w$]*/ (i.e. ASCII-only)! The range of identifiers can be described by the regex /[$_\p{ID_Start}][$\p{ID_Continue}]*/u (excluding unicode escape sequences).

In addition, JavaScript allows using Unicode escape sequences in the form of \u0000 or \u{000000} in identifiers, which encode the same string value as the actual Unicode characters. For example, 你好 and \u4f60\u597d are the same identifiers:
js

const 你好 = "Hello";
console.log(\u4f60\u597d); // Hello

Not all places accept the full range of identifiers. Certain syntaxes, such as function declarations, function expressions, and variable declarations require using identifiers names that are not reserved words.
js

function import() {} // Illegal: import is a reserved word.

Most notably, private properties and object properties allow reserved words.
js

const obj = { import: "value" }; // Legal despite `import` being reserved
class C {
  #import = "value";
}


## Keywords

Keywords are tokens that look like identifiers but have special meanings in JavaScript. For example, the keyword async before a function declaration indicates that the function is asynchronous.

Some keywords are reserved, meaning that they cannot be used as an identifier for variable declarations, function declarations, etc. They are often called reserved words. A list of these reserved words is provided below. Not all keywords are reserved — for example, async can be used as an identifier anywhere. Some keywords are only contextually reserved — for example, await is only reserved within the body of an async function, and let is only reserved in strict mode code, or const and let declarations.

Identifiers are always compared by string value, so escape sequences are interpreted. For example, this is still a syntax error:
js

const els\u{65} = 1;
// `els\u{65}` encodes the same identifier as `else`

### Reserved words

These keywords cannot be used as identifiers for variables, functions, classes, etc. anywhere in JavaScript source.

    break
    case
    catch
    class
    const
    continue
    debugger
    default
    delete
    do
    else
    export
    extends
    false
    finally
    for
    function
    if
    import
    in
    instanceof
    new
    null
    return
    super
    switch
    this
    throw
    true
    try
    typeof
    var
    void
    while
    with

The following are only reserved when they are found in strict mode code:

    let (also reserved in const, let, and class declarations)
    static
    yield (also reserved in generator function bodies)

The following are only reserved when they are found in module code or async function bodies:

    await

### Future reserved words

The following are reserved as future keywords by the ECMAScript specification. They have no special functionality at present, but they might at some future time, so they cannot be used as identifiers.

These are always reserved:

    enum

The following are only reserved when they are found in strict mode code:

    implements
    interface
    package
    private
    protected
    public

Future reserved words in older standards

The following are reserved as future keywords by older ECMAScript specifications (ECMAScript 1 till 3).

    abstract
    boolean
    byte
    char
    double
    final
    float
    goto
    int
    long
    native
    short
    synchronized
    throws
    transient
    volatile

### Identifiers with special meanings

A few identifiers have a special meaning in some contexts without being reserved words of any kind. They include:

    arguments (not a keyword, but cannot be declared as identifier in strict mode)
    as (import * as ns from "mod")
    async
    eval (not a keyword, but cannot be declared as identifier in strict mode)
    from (import x from "mod")
    get
    of
    set



## Literals

Note: This section discusses literals that are atomic tokens. Object literals and array literals are expressions that consist of a series of tokens.
Null literal

See also null for more information.
js

null

Boolean literal

See also boolean type for more information.
js

true
false

Numeric literals

The Number and BigInt types use numeric literals.
Decimal
js

1234567890
42

Decimal literals can start with a zero (0) followed by another decimal digit, but if all digits after the leading 0 are smaller than 8, the number is interpreted as an octal number. This is considered a legacy syntax, and number literals prefixed with 0, whether interpreted as octal or decimal, cause a syntax error in strict mode — so, use the 0o prefix instead.
js

0888 // 888 parsed as decimal
0777 // parsed as octal, 511 in decimal

Exponential

The decimal exponential literal is specified by the following format: beN; where b is a base number (integer or floating), followed by an E or e character (which serves as separator or exponent indicator) and N, which is exponent or power number – a signed integer.
js

0e-5   // 0
0e+5   // 0
5e1    // 50
175e-2 // 1.75
1e3    // 1000
1e-3   // 0.001
1E3    // 1000

Binary

Binary number syntax uses a leading zero followed by a lowercase or uppercase Latin letter "B" (0b or 0B). Any character after the 0b that is not 0 or 1 will terminate the literal sequence.
js

0b10000000000000000000000000000000 // 2147483648
0b01111111100000000000000000000000 // 2139095040
0B00000000011111111111111111111111 // 8388607

Octal

Octal number syntax uses a leading zero followed by a lowercase or uppercase Latin letter "O" (0o or 0O). Any character after the 0o that is outside the range (01234567) will terminate the literal sequence.
js

0O755 // 493
0o644 // 420

Hexadecimal

Hexadecimal number syntax uses a leading zero followed by a lowercase or uppercase Latin letter "X" (0x or 0X). Any character after the 0x that is outside the range (0123456789ABCDEF) will terminate the literal sequence.
js

0xFFFFFFFFFFFFFFFFF // 295147905179352830000
0x123456789ABCDEF   // 81985529216486900
0XA                 // 10

BigInt literal

The BigInt type is a numeric primitive in JavaScript that can represent integers with arbitrary precision. BigInt literals are created by appending n to the end of an integer.
js

123456789123456789n     // 123456789123456789
0o777777777777n         // 68719476735
0x123456789ABCDEFn      // 81985529216486895
0b11101001010101010101n // 955733

BigInt literals cannot start with 0 to avoid confusion with legacy octal literals.
js

0755n; // SyntaxError: invalid BigInt syntax

For octal BigInt numbers, always use zero followed by the letter "o" (uppercase or lowercase):
js

0o755n;

For more information about BigInt, see also JavaScript data structures.
Numeric separators

To improve readability for numeric literals, underscores (_, U+005F) can be used as separators:
js

1_000_000_000_000
1_050.95
0b1010_0001_1000_0101
0o2_2_5_6
0xA0_B0_C0
1_000_000_000_000_000_000_000n

Note these limitations:
js

// More than one underscore in a row is not allowed
100__000; // SyntaxError

// Not allowed at the end of numeric literals
100_; // SyntaxError

// Can not be used after leading 0
0_1; // SyntaxError

String literals

A string literal is zero or more Unicode code points enclosed in single or double quotes. Unicode code points may also be represented by an escape sequence. All code points may appear literally in a string literal except for these code points:

    U+005C \ (backslash)
    U+000D <CR>
    U+000A <LF>
    The same kind of quote that begins the string literal

Any code points may appear in the form of an escape sequence. String literals evaluate to ECMAScript String values. When generating these String values Unicode code points are UTF-16 encoded.
js

'foo'
"bar"

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
js

const longString =
  "This is a very long string which needs \
to wrap across multiple lines because \
otherwise my code is unreadable.";

Make sure there is no space or any other character after the backslash (except for a line break), otherwise it will not work. If the next line is indented, the extra spaces will also be present in the string's value.

You can also use the + operator to append multiple strings together, like this:
js

const longString =
  "This is a very long string which needs " +
  "to wrap across multiple lines because " +
  "otherwise my code is unreadable.";

Both of the above methods result in identical strings.
Hexadecimal escape sequences

Hexadecimal escape sequences consist of \x followed by exactly two hexadecimal digits representing a code unit or code point in the range 0x0000 to 0x00FF.
js

"\xA9"; // "©"

Unicode escape sequences

A Unicode escape sequence consists of exactly four hexadecimal digits following \u. It represents a code unit in the UTF-16 encoding. For code points U+0000 to U+FFFF, the code unit is equal to the code point. Code points U+10000 to U+10FFFF require two escape sequences representing the two code units (a surrogate pair) used to encode the character; the surrogate pair is distinct from the code point.

See also String.fromCharCode() and String.prototype.charCodeAt().
js

"\u00A9"; // "©" (U+A9)

Unicode code point escapes

A Unicode code point escape consists of \u{, followed by a code point in hexadecimal base, followed by }. The value of the hexadecimal digits must be in the range 0 and 0x10FFFF inclusive. Code points in the range U+10000 to U+10FFFF do not need to be represented as a surrogate pair.

See also String.fromCodePoint() and String.prototype.codePointAt().
js

"\u{2F804}"; // CJK COMPATIBILITY IDEOGRAPH-2F804 (U+2F804)

// the same character represented as a surrogate pair
"\uD87E\uDC04";

Regular expression literals

Regular expression literals are enclosed by two forward slashes (/). The lexer consumes all characters up to the next unescaped forward slash or the end of the line, unless the forward slash appears within a character class ([]). Some characters (namely, those that are identifier parts) can appear after the closing slash, denoting flags.

The lexical grammar is very lenient: not all regular expression literals that get identified as one token are valid regular expressions.

See also RegExp for more information.
js

/ab+c/g
/[/]/

A regular expression literal cannot start with two forward slashes (//), because that would be a line comment. To specify an empty regular expression, use /(?:)/.
Template literals

One template literal consists of several tokens: `xxx${ (template head), }xxx${ (template middle), and }xxx` (template tail) are individual tokens, while any expression may come between them.

See also template literals for more information.
js

`string text`

`string text line 1
 string text line 2`

`string text ${expression} string text`

tag`string text ${expression} string text`
