Arrow functions, the basics

There’s another very simple and concise syntax for creating functions, that’s often better than
Function Expressions.
It’s called “arrow functions”, because it looks like this:
let func = (arg1, arg2, ...argN) => expression

…This creates a function func that accepts arguments arg1..argN , then evaluates the
expression on the right side with their use and returns its result.

In other words, it’s the shorter version of:

let func = function(arg1, arg2, ...argN) {
return expression;
};

If we have only one argument, then parentheses around parameters can be omitted, making
that even shorter.

If there are no arguments, parentheses will be empty (but they should be present):

Sometimes we need something a little bit more complex, like multiple expressions or statements.
It is also possible, but we should enclose them in curly braces. Then use a normal return
within them.





Arrow Functions

Example code:
```js
const X = function() {
  // "this" here is the caller of X
};

const Y = () => {
  // "this" here is NOT the caller of Y
  // It's the same "this" found in Y's scope
};
```
There are many ways to define a function in JavaScript, and the modern specification introduced a new way, arrow functions. It is a way to define a function without typing the keyword function, but rather by using an arrow symbol like above. This shorter syntax is preferable not only because it's shorter, but also because it behaves more predictably with closures.


Regular functions give access to their "calling" environment while arrow functions give access to their "defining" environment

The value of the "this" keyword inside a regular function depends on HOW the function was CALLED (the OBJECT that made the call).

The value of the "this" keyword inside an arrow function depends on WHERE the function was DEFINED (the SCOPE that defined the function).

An arrow function does not care who calls it, while a regular function cares very much about that. A regular function, like X above, always binds the value for its this keyword for its caller. If it didn't have an explicit caller, the value of the this keyword will be determined by the calling environment. In the playground here, it's the global window object. An arrow function, on the other hand, like Y here, not caring about who called it, will close over the value of the this keyword for its scope at the time it was defined. Let me say that one more time. An arrow function will close over the value of the this keyword for its scope at the time it was defined. This makes it great for delayed execution cases like events and listeners because it gives easy access to the defining environment, not the calling environment.
