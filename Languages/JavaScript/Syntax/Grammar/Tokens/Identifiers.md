### Identifiers

Names given by users to variables, functions, and other objects in the code. 


JavaScript is case-sensitive and uses the Unicode character set. For example, the word Früh (which means "early" in German) could be used as a variable name.


const Früh = "foobar";

But, the variable früh is not the same as Früh because JavaScript is case sensitive.



Rules for identifiers include:

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
