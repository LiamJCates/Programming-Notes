
JavaScript declares new variables using the keywords: let, const, or var.

An equal sign is used to assign values to variables, called binding.

The = operator can be used at on existing bindings to disconnect them from their current value and have them point to a new one.

var variable1 = 1;
variable1 = 2;





### let
let allows you to declare block-level variables. The declared variable is available from the block it is enclosed in.

let a;
let name = 'Simon';

The following is an example of scope with a variable declared with let:

```js
// myLetVariable is *not* visible out here

for (let myLetVariable = 0; myLetVariable < 5; myLetVariable++) {
  // myLetVariable is only visible in here
}

// myLetVariable is *not* visible out here
```



### const
The word const stands for constant. It defines a constant binding, which points at the same value for as long as it lives

const allows you to declare variables whose values are never intended to change. The variable is available from the block it is declared in.

```js
const Pi = 3.14; // variable Pi is set
Pi = 1; // will throw an error because you cannot change a constant variable.
```



### var

var is the most common declarative keyword. It does not have the restrictions that the other two keywords have. This is because it was traditionally the only way to declare a variable in JavaScript. A variable declared with the var keyword is available from the function it is declared in.

```js
var a;
var name = 'Simon';
```
An example of scope with a variable declared with var:

```js
// myVarVariable *is* visible out here

for (var myVarVariable = 0; myVarVariable < 5; myVarVariable++) {
  // myVarVariable is visible to the whole function
}

// myVarVariable *is* visible out here
```


If you declare a variable without assigning any value to it, its type is undefined.

An attempt to access an undeclared variable results in a ReferenceError exception being thrown:

```js
var a;
console.log('The value of a is ' + a); // The value of a is undefined
```

## Scope
The collection of bindings and their values that exist at a given time is called the environment.

An important difference between JavaScript and other languages like Java is that in JavaScript, blocks do not have scope; only functions have a scope. So if a variable is defined using var in a compound statement (for example inside an if control structure), it will be visible to the entire function. However, starting with ECMAScript 2015, let and const declarations allow you to create block-scoped variables.





### Global variables
Variables declared outside of any function are called global.
Global variables are visible from any function (unless shadowed by locals).
It’s a good practice to minimize the use of global variables. Modern code has few or no
globals. Most variables reside in their functions. Sometimes though, they can be useful to
store project-level data
