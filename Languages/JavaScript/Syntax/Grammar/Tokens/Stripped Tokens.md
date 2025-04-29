## Stripped Tokens

Stripped tokens include white space and comments.

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