## Lexical grammar

### Statements

A JavaScript program is a list of programming statements.

JavaScript source text is just a sequence of characters — in order for the interpreter to understand it, the string has to be parsed to a more structured representation. 

The initial step of parsing is called lexical analysis, in which the text gets scanned from left to right, top to bottom, and is converted into a sequence of individual, atomic input elements called tokens.


Some input elements are insignificant to the interpreter, and will be stripped after this step — they include white space and comments. 

Line terminators and multiline comments are also syntactically insignificant, but they guide the process for automatic semicolons insertion to make certain invalid token sequences become valid.

JavaScript Tokens are categorized into five primary types:
  operators
  punctuators
  literals
  identifiers
  keywords 

### Operators

   Symbols or words that represent mathematical, logical, or other operations. Examples include:

   - Arithmetic Operators: `+`, `-`, `*`, `/`

   - Assignment Operators: `=`, `+=`, `-=`

   - Comparison Operators: `==`, `===`, `!=`, `!==`

   - Logical Operators: `&&`, `||`, `!`

   - Type Operators: `typeof`, `instanceof`

### Punctuators

   Symbols used to group, separate, or punctuate code. Examples include:

   - Parentheses: `()`

   - Curly Braces: `{}`

   - Square Brackets: `[]`

   - Comma: `,`

   - Semicolon: `;`

   - Period (used to access object properties): `.`


### Literals

Values used directly in the program, such as numbers (`2`), strings (`'hello world'`), etc.

### Identifiers

Names given by users to variables, functions, and other objects in the code. 

### Keywords

Keywords are tokens that look like identifiers but have special meanings in JavaScript. For example, the keyword async before a function declaration indicates that the function is asynchronous.







In JavaScript, instructions are called statements and are separated by semicolons (;)

A semicolon is not necessary after a statement if it is written on its own line. But if more than one statement on a line is desired, then they must be separated by semicolons.

In most cases, a newline implies a semicolon. But “in most cases” does not mean “always”!

See [Automatic Semicolon Insertion](./Automatic%20Semicolon%20Insertion.md)