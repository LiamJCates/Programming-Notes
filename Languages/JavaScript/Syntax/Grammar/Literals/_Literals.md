## Literals


## Literals

Note: This section discusses literals that are atomic tokens. Object literals and array literals are expressions that consist of a series of tokens.


### Null literal
```js
null
```
### Boolean literal
```js
true
false
```
### Numeric literals

The Number and BigInt types use numeric literals.

#### Decimal

```js
1234567890
42
```

Decimal literals can start with a zero (0) followed by another decimal digit, but if all digits after the leading 0 are smaller than 8, the number is interpreted as an octal number. This is considered a legacy syntax, and number literals prefixed with 0, whether interpreted as octal or decimal, cause a syntax error in strict mode — so, use the 0o prefix instead.

```js
0888 // 888 parsed as decimal
0777 // parsed as octal, 511 in decimal
```

#### Exponential

The decimal exponential literal is specified by the following format: beN; where b is a base number (integer or floating), followed by an E or e character (which serves as separator or exponent indicator) and N, which is exponent or power number – a signed integer.

```js
0e-5   // 0
0e+5   // 0
5e1    // 50
175e-2 // 1.75
1e3    // 1000
1e-3   // 0.001
1E3    // 1000
```

#### Binary

Binary number syntax uses a leading zero followed by a lowercase or uppercase Latin letter "B" (0b or 0B). Any character after the 0b that is not 0 or 1 will terminate the literal sequence.

```js
0b10000000000000000000000000000000 // 2147483648
0b01111111100000000000000000000000 // 2139095040
0B00000000011111111111111111111111 // 8388607
```

#### Octal

Octal number syntax uses a leading zero followed by a lowercase or uppercase Latin letter "O" (0o or 0O). Any character after the 0o that is outside the range (01234567) will terminate the literal sequence.

```js
0O755 // 493
0o644 // 420
```

#### Hexadecimal

Hexadecimal number syntax uses a leading zero followed by a lowercase or uppercase Latin letter "X" (0x or 0X). Any character after the 0x that is outside the range (0123456789ABCDEF) will terminate the literal sequence.


```js
0xFFFFFFFFFFFFFFFFF // 295147905179352830000
0x123456789ABCDEF   // 81985529216486900
0XA                 // 10
```

#### BigInt literal

The BigInt type is a numeric primitive in JavaScript that can represent integers with arbitrary precision. BigInt literals are created by appending n to the end of an integer.

```js
123456789123456789n     // 123456789123456789
0o777777777777n         // 68719476735
0x123456789ABCDEFn      // 81985529216486895
0b11101001010101010101n // 955733
```

BigInt literals cannot start with 0 to avoid confusion with legacy octal literals.

```js
0755n; // SyntaxError: invalid BigInt syntax
```

For octal BigInt numbers, always use zero followed by the letter "o" (uppercase or lowercase):

```js
0o755n;
```


#### Numeric separators

To improve readability for numeric literals, underscores (_, U+005F) can be used as separators:

```js
1_000_000_000_000
1_050.95
0b1010_0001_1000_0101
0o2_2_5_6
0xA0_B0_C0
1_000_000_000_000_000_000_000n
```

Note these limitations:

```js
// More than one underscore in a row is not allowed
100__000; // SyntaxError

// Not allowed at the end of numeric literals
100_; // SyntaxError

// Can not be used after leading 0
0_1; // SyntaxError
```







Literals represent values in JavaScript. These are fixed values — not variables — that you literally provide in your script.

    Array
    Boolean
    Floating-point
    Numeric 
    Object
    RegExp
    String


There are 7 primitive literal types:

    string
    number
    bigint
    boolean
    undefined
    symbol
    null








| Character | Meaning                                                                                                        |
|-----------|----------------------------------------------------------------------------------------------------------------|
| \0        | Null Byte                                                                                                      |
| \b        | Backspace                                                                                                      |
| \f        | Form Feed                                                                                                      |
| \n        | New Line                                                                                                       |
| \r        | Carriage Return                                                                                                |
| \t        | Tab                                                                                                            |
| \v        | Vertical tab                                                                                                   |
| \'        | Apostrophe or single quote                                                                                     |
| \"        | Double quote                                                                                                   |
| \\        | Backslash character                                                                                            |
| \XXX      | The character with the Latin-1 encoding specified by up to three octal digits XXX between 0 and 377. For example, \251 is the octal sequence for the copyright symbol. |
| \xXX      | The character with the Latin-1 encoding specified by the two hexadecimal digits XX between 00 and FF. For example, \xA9 is the hexadecimal sequence for the copyright symbol. |
| \uXXXX    | The Unicode character specified by the four hexadecimal digits XXXX. For example, \u00A9 is the Unicode sequence for the copyright symbol. |
| \u{XXXXX} | Unicode code point escapes. For example, \u{2F804} is the same as the Unicode escapes \uD87E\uDC04.             |
