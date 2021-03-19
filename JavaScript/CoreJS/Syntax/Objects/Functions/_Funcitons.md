A JavaScript function can take 0 or more named parameters. The function body can contain as many statements as you like and can declare its own variables which are local to that function. The return statement can be used to return a value at any time, terminating the function. If no return statement is used (or an empty return with no value), JavaScript returns undefined.

A function definition (also called a function declaration, or function statement) consists of the function keyword, followed by:

    The name of the function.
    A list of zero or more parameters, delimited by parentheses and separated by commas.
    The JavaScript statements that define the function, enclosed in curly brackets, {...}.

For example, the following code defines a simple function named square:

function square(number) {
  return number * number;
}


A function name is an identifier included as part of a function declaration or function expression. The function name's scope depends on whether the function name is a declaration or expression.



### Different types of functions

An anonymous function is a function without a function name. Only function expressions can be anonymous, function declarations must have a name:

// When used as a function expression
(function () {});
// or using the ECMAScript 2015 arrow notation
() => {};

The following terms are not used in the ECMAScript language specification, they're jargon used to refer to different types of functions.

A named function is a function with a function name:

// Function declaration
function foo() {};
// Named function expression
(function bar() {});
// or using the ECMAScript 2015 arrow notation
const foo = () => {};

An inner function is a function inside another function (square in this case). An outer function is a function containing a function (addSquares in this case):

function addSquares(a,b) {
   function square(x) {
      return x * x;
   }
   return square(a) + square(b);
};
//Using ECMAScript 2015 arrow notation
const addSquares = (a,b) => {
   const square = x => x*x;
   return square(a) + square(b);
};
