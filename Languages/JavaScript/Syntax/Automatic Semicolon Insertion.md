## Automatic semicolon insertion

Some JavaScript statements' syntax definitions require semicolons (;) at the end. They include:

    var, let, const
    Expression statements
    do...while
    continue, break, return, throw
    debugger
    Class field declarations (public or private)
    import, export

However, to make the language more approachable and convenient, JavaScript is able to automatically insert semicolons when consuming the token stream, so that some invalid token sequences can be "fixed" to valid syntax. This step happens after the program text has been parsed to tokens according to the lexical grammar. There are three cases when semicolons are automatically inserted:

1. When a token not allowed by the grammar is encountered, and it's separated from the previous token by at least one line terminator (including a block comment that includes at least one line terminator), or the token is "}", then a semicolon is inserted before the token.

```js
{ 1
2 } 3

// is transformed by ASI into:

{ 1
;2 ;} 3;

// Which is valid grammar encoding three statements,
// each consisting of a number literal
```
The ending ")" of do...while is taken care of as a special case by this rule as well.

```js
do {
  // ...
} while (condition) /* ; */ // ASI here
const a = 1
```

However, semicolons are not inserted if the semicolon would then become the separator in the for statement's head.

```js
for (
  let a = 1 // No ASI here
  a < 10 // No ASI here
  a++
) {}
```

Semicolons are also never inserted as empty statements. For example, in the code below, if a semicolon is inserted after ")", then the code would be valid, with an empty statement as the if body and the const declaration being a separate statement. However, because automatically inserted semicolons cannot become empty statements, this causes a declaration to become the body of the if statement, which is not valid.

```js
if (Math.random() > 0.5)
const x = 1 // SyntaxError: Unexpected token 'const'
```

2. When the end of the input stream of tokens is reached, and the parser is unable to parse the single input stream as a complete program, a semicolon is inserted at the end.

```js
const a = 1 /* ; */ // ASI here
```

This rule is a complement to the previous rule, specifically for the case where there's no "offending token" but the end of input stream.

3. When the grammar forbids line terminators in some place but a line terminator is found, a semicolon is inserted. These places include:

    expr <here> ++, expr <here> --
    continue <here> lbl
    break <here> lbl
    return <here> expr
    throw <here> expr
    yield <here> expr
    yield <here> * expr
    (param) <here> => {}
    async <here> function, async <here> prop(), async <here> function*, async <here> *prop(), async <here> (param) <here> => {}

Here ++ is not treated as a postfix operator applying to variable b, because a line terminator occurs between b and ++.

```js
a = b
++c

// is transformed by ASI into

a = b;
++c;
```

Here, the return statement returns undefined, and the a + b becomes an unreachable statement.

```js
return
a + b

// is transformed by ASI into

return;
a + b;
```

Note that ASI would only be triggered if a line break separates tokens that would otherwise produce invalid syntax. If the next token can be parsed as part of a valid structure, semicolons would not be inserted. For example:

```js
const a = 1
(1).toString()

const b = 1
[1, 2, 3].forEach(console.log)
```

Because () can be seen as a function call, it would usually not trigger ASI. Similarly, [] may be a member access. The code above is equivalent to:

```js
const a = 1(1).toString();

const b = 1[1, 2, 3].forEach(console.log);
```

This happens to be valid syntax. 1[1, 2, 3] is a property accessor with a comma-joined expression. Therefore, you would get errors like "1 is not a function" and "Cannot read properties of undefined (reading 'forEach')" when running the code.

Within classes, class fields and generator methods can be a pitfall as well.

```js
class A {
  a = 1
  *gen() {}
}
```

It is seen as:

```js
class A {
  a = 1 * gen() {}
}
```

And therefore will be a syntax error around {.

There are the following rules-of-thumb for dealing with ASI, if you want to enforce semicolon-less style:

    Write postfix ++ and -- on the same line as their operands.

```js
const a = b
++
console.log(a) // ReferenceError: Invalid left-hand side expression in prefix operation
```

```js
const a = b++
console.log(a)
```

The expressions after return, throw, or yield should be on the same line as the keyword.

```js
function foo() {
  return
    1 + 1 // Returns undefined; 1 + 1 is ignored
}
```

```js
function foo() {
  return 1 + 1
}

function foo() {
  return (
    1 + 1
  )
}
```

Similarly, the label identifier after break or continue should be on the same line as the keyword.

```js
outerBlock: {
  innerBlock: {
    break
      outerBlock // SyntaxError: Illegal break statement
  }
}
```

```js
outerBlock: {
  innerBlock: {
    break outerBlock
  }
}
```

The => of an arrow function should be on the same line as the end of its parameters.

```js
const foo = (a, b)
  => a + b
```

```js
const foo = (a, b) =>
  a + b
```

The async of async functions, methods, etc. cannot be directly followed by a line terminator.

```js
async
function foo() {}
```

```js
async function
foo() {}
```

If a line starts with one of (, [, `, +, -, / (as in regex literals), prefix it with a semicolon, or end the previous line with a semicolon.

```js
// The () may be merged with the previous line as a function call
(() => {
  // ...
})()

// The [ may be merged with the previous line as a property access
[1, 2, 3].forEach(console.log)

// The ` may be merged with the previous line as a tagged template literal
`string text ${data}`.match(pattern).forEach(console.log)

// The + may be merged with the previous line as a binary + expression
+a.toString()

// The - may be merged with the previous line as a binary - expression
-a.toString()

// The / may be merged with the previous line as a division expression
/pattern/.exec(str).forEach(console.log)
```

```js
;(() => {
  // ...
})()
;[1, 2, 3].forEach(console.log)
;`string text ${data}`.match(pattern).forEach(console.log)
;+a.toString()
;-a.toString()
;/pattern/.exec(str).forEach(console.log)
```

Class fields should preferably always be ended with semicolons — in addition to the previous rule (which includes a field declaration followed by a computed property, since the latter starts with [), semicolons are also required between a field declaration and a generator method.

```js
class A {
  a = 1
  [b] = 2
  *gen() {} // Seen as a = 1[b] = 2 * gen() {}
}
```

```js
class A {
  a = 1;
  [b] = 2;
  *gen() {}
}
```