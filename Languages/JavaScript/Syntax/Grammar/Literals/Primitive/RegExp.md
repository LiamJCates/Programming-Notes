### Regular expression literals

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