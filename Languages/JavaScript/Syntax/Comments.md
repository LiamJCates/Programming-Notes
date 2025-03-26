## Comments


### Line comments

```javascript
function comment() {
  // This is a JavaScript line comment
  console.log("Hello world!");
}
comment();
```

### Block comments

```javascript
function comment() {
  /* This is a one line JavaScript block comment */
  console.log("Hello world!");
}
comment();
```
```javascript
function comment() {
  /* This comment spans multiple lines. Notice
     that we don't need to end the comment until we're done. */
  console.log("Hello world!");
}
comment();
```

You can also use it in the middle of a line, if you wish, although this can make your code harder to read so it should be used with caution:

```javascript
function comment(x) {
  console.log("Hello " + x /* insert the value of x */ + " !");
}
comment("world");
```

```javascript
function comment() {
  /* console.log("Hello world!"); a comment used to disable code */
}
comment();
```

It's important to note that comments do not nest. For example, the following will cause an error:​
```javascript
/*
  This is a comment block.
  /* This is a nested comment block, which is not allowed. */
*/
```

To comment out a block of code that contains comments, you can use single-line comments to prevent syntax errors:​

```javascript
// /*
// This is a comment block.
// /* This is a nested comment block. */
// */
```

Alternatively, you can break the closing sequence of the inner comment to avoid premature termination:​

```javascript
/*
  This is a comment block.
  /* This is a nested comment block. *\/
*/
```

In the example above, the sequence *\\/ is interpreted as part of the comment text, preventing the premature end of the outer comment.


Block comments that contain at least one line terminator behave like line terminators in automatic semicolon insertion.

### Hashbang comments

There's a special third comment syntax, the hashbang comment. A hashbang comment behaves exactly like a single line-only (//) comment, except that it begins with #! and is only valid at the absolute start of a script or module. Note also that no whitespace of any kind is permitted before the #!. The comment consists of all the characters after #! up to the end of the first line; only one such comment is permitted.

Hashbang comments in JavaScript resemble shebangs in Unix which provide the path to a specific JavaScript interpreter that you want to use to execute the script. Before the hashbang comment became standardized, it had already been de-facto implemented in non-browser hosts like Node.js, where it was stripped from the source text before being passed to the engine. An example is as follows:

```javascript
#!/usr/bin/env node

console.log("Hello world");
```

The JavaScript interpreter will treat it as a normal comment — it only has semantic meaning to the shell if the script is directly run in a shell.

Warning: If you want scripts to be runnable directly in a shell environment, encode them in UTF-8 without a BOM. Although a BOM will not cause any problems for code running in a browser — because it's stripped during UTF-8 decoding, before the source text is analyzed — a Unix/Linux shell will not recognize the hashbang if it's preceded by a BOM character.

You must only use the #! comment style to specify a JavaScript interpreter. In all other cases just use a // comment (or multiline comment).
