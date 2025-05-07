Functions are fundamental building blocks in JavaScript, acting as reusable blocks of code designed to perform specific tasks.  

Functions can be defined using: 
    function declarations 
    function expressions
    arrow functions

## Defining Functions


**Function Declarations**

A function definition (also called a function declaration, or function statement) consists of the function keyword, followed by:

    The name of the function.
    A list of parameters to the function, enclosed in parentheses and separated by commas.
    The JavaScript statements that define the function, enclosed in curly braces, { /* … */ }.


A function declaration defines a named function that can be invoked anywhere in its scope.

```javascript
function square(number) {
  return number * number;
}
```


**Function Expressions**

A function expression defines a function inside an expression. 

This enables anonymous function expressions, which are defined without a name. 
For example, the function square could have been defined as:

```javascript
const square = function(number) {
  return number * number;
};
```

However, providing a name allows the function to refer to itself, and also makes it easier to identify the function in a debugger's stack traces:

```javascript
const factorial = function fac(n) {
  return n < 2 ? 1 : n * fac(n - 1);
};

console.log(factorial(3)); // 6
```


Function expressions are convenient when passing a function as an argument to another function. The following example defines a map function that should receive a function as first argument and an array as second argument. Then, it is called with a function defined by a function expression:

```javascript
function map(f, a) {
  const result = new Array(a.length);
  for (let i = 0; i < a.length; i++) {
    result[i] = f(a[i]);
  }
  return result;
}

const numbers = [0, 1, 2, 5, 10];
const cubedNumbers = map(function (x) {
  return x * x * x;
}, numbers);
console.log(cubedNumbers); // [0, 1, 8, 125, 1000]
```

In JavaScript, a function can be defined based on a condition. For example, the following function definition defines myFunc only if num equals 0:

```javascript
let myFunc;
if (num === 0) {
  myFunc = function (theObject) {
    theObject.make = "Toyota";
  };
}
```



**Arrow Functions**

Introduced in ECMAScript 6, arrow functions provide a concise syntax for writing function expressions and do not have their own `this` context.

```javascript
const square = (number) => number * number;
```


## Calling Functions

Functions are executed when they are invoked. You can call a function by using its name followed by parentheses, optionally passing arguments.

```javascript
square(5); // Returns 25
```


Parameters are essentially passed to functions by value — so if the code within the body of a function assigns a completely new value to a parameter that was passed to the function, the change is not reflected globally or in the code which called that function.

When you pass an object as a parameter, if the function changes the object's properties, that change is visible outside the function, as shown in the following example:
js
```javascript
function myFunc(theObject) {
  theObject.make = "Toyota";
}

const myCar = {
  make: "Honda",
  model: "Accord",
  year: 1998,
};

console.log(myCar.make); // "Honda"
myFunc(myCar);
console.log(myCar.make); // "Toyota"
```


When you pass an array as a parameter, if the function changes any of the array's values, that change is visible outside the function, as shown in the following example:
js

```javascript
function myFunc(theArr) {
  theArr[0] = 30;
}

const arr = [45];

console.log(arr[0]); // 45
myFunc(arr);
console.log(arr[0]); // 30
```

Function declarations and expressions can be nested, which forms a scope chain. For example:

```javascript
function addSquares(a, b) {
  function square(x) {
    return x * x;
  }
  return square(a) + square(b);
}
```


## Function Scopes and Closures

Functions in JavaScript form closures. A closure is a function that retains access to its lexical scope, even when the function is executed outside that scope.

```javascript
function outerFunction() {
  const outerVariable = 'I am outside!';
  
  function innerFunction() {
    console.log(outerVariable);
  }
  
  return innerFunction;
}

const myInnerFunction = outerFunction();
myInnerFunction(); // Logs: 'I am outside!'
```


## Using the Arguments Object

The `arguments` object is an array-like object accessible inside functions that contains the values of the arguments passed to that function. However, in modern JavaScript, rest parameters are preferred.

```javascript
function multiply(a, b) {
  return a * b;
}

multiply(2, 3); // Returns 6
```


## Function Parameters

**Default Parameters**

Default parameters allow you to set default values for function parameters.

```javascript
function greet(name = 'Guest') {
  return `Hello, ${name}!`;
}

greet(); // Returns 'Hello, Guest!'
greet('Alice'); // Returns 'Hello, Alice!'
```


**Rest Parameters**

Rest parameters allow you to represent an indefinite number of arguments as an array.

```javascript
function sum(...numbers) {
  return numbers.reduce((acc, curr) => acc + curr, 0);
}

sum(1, 2, 3); // Returns 6
```


## Arrow Functions

Arrow functions provide a shorter syntax for writing functions and do not have their own `this`, `arguments`, `super`, or `new.target` bindings. They are best suited for non-method functions.

This syntax, also called the fat arrow, reduces noise and results in more compact code.

```javascript
const add = (a, b) => a + b;

add(2, 3); // Returns 5
```

NOTE: Because arrow functions use curly brackets, {} you cannot implicitly return an object. To return an object using an arrow function, you must either use the return keyword or wrap the curly brackets in round brackets.

### Understanding Lexical Scope

Unlike regular functions, arrow functions do not bind their scope to the
object that calls the function. Instead, they use a lexical scope, in which the
surrounding scope determines the value of the this keyword. Therefore,
the scope to which this refers in an arrow function always represents the
object defining the arrow function instead of the object calling the function.

```js
this.scope = "lexical scope"; //1
const scopeOf = {
  scope: "defining scope", //2
  traditional: function () {
    return this.scope; //3
  },
  arrow: () => {
    return this.scope;
  },
};
console.log(scopeOf.traditional()); //defining scope
console.log(scopeOf.arrow());       // lexical scope
```

We first declare the scope property on the lexical scope 1; this is the
defining object. Then we create an object with a property of the same name
inside the defining scope 2. Next, we define two functions, both of which
use this to return the value of this.scope 3.
Upon calling them, you can see the difference between the two references.
Whereas this.scope in the arrow function refers to the property defined in the
lexical scope, the traditional function’s this refers to the second property we
defined. Consequently, the scopeOf.traditional function outputs defining scope,
whereas the scopeOf.arrow function outputs lexical scope.




