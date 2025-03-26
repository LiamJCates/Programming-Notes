Declarations

JavaScript has three kinds of variable declarations.

var

    Declares a variable, optionally initializing it to a value.
let

    Declares a block-scoped, local variable, optionally initializing it to a value.
const

    Declares a block-scoped, read-only named constant. A constant cannot change value through assignment or be re-declared while the script is running. It must be initialized to a value.



With the keyword var. For example, var x = 42. This syntax can be used to declare both local and global variables, depending on the execution context.

With the keyword const or let. For example, let y = 13. This syntax can be used to declare a block-scope local variable. (See Variable scope below.)




In a statement like let x = 42, the let x part is called a declaration, and the = 42 part is called an initializer. The declaration allows the variable to be accessed later in code without throwing a ReferenceError, while the initializer assigns a value to the variable. In var and let declarations, the initializer is optional. If a variable is declared without an initializer, it is assigned the value undefined.
js

let x;
console.log(x); // logs "undefined"

In essence, let x = 42 is equivalent to let x; x = 42.

const declarations always need an initializer, because they forbid any kind of assignment after declaration, and implicitly initializing it with undefined is likely a programmer mistake.
js

const x; // SyntaxError: Missing initializer in const declaration



Variables should always be declared before they are used. JavaScript used to allow assigning to undeclared variables, which creates an undeclared global variable. This is an error in strict mode and should be avoided altogether.




Variable scope

A variable may belong to one of the following scopes:

    Global scope: The default scope for all code running in script mode.
    Module scope: The scope for code running in module mode.
    Function scope: The scope created with a function.

In addition, variables declared with let or const can belong to an additional scope:

    Block scope: The scope created with a pair of curly braces (a block).

When you declare a variable outside of any function, it is called a global variable, because it is available to any other code in the current document. When you declare a variable within a function, it is called a local variable, because it is available only within that function.

let and const declarations can also be scoped to the block statement that they are declared in.
js

if (Math.random() > 0.5) {
  const y = 5;
}
console.log(y); // ReferenceError: y is not defined

However, variables created with var are not block-scoped, but only local to the function (or global scope) that the block resides within.

For example, the following code will log 5, because the scope of x is the global context (or the function context if the code is part of a function). The scope of x is not limited to the immediate if statement block.
js

if (true) {
  var x = 5;
}
console.log(x); // x is 5


