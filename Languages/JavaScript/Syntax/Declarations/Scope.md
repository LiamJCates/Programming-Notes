https://wesbos.com/javascript/03-the-tricky-bits/scope

The word “scoping” essentially asks, “Where is a certain variable available to me?” - it indicates the current context of a variable. When a variable is not declared within any functions, existing outside any { curly braces }, they are said to be in the global scope, meaning that they are available everywhere. If they are within a function or { curly braces }, they are known to be locally scoped.

Before ECMAScript 6, JavaScript had a single keyword to declare a variable, var. These variables can be redefined and updated, and are said to be defined within the function scope, meaning, they are only available within the function they are declared in.

In ECMAScript 6, the keywords let and const were introduced. While var variables were function scoped, these allow you to define variables that are block scoped - basically, scoping the variable to only be available within the closest set of { curly braces } in which it was defined. These braces can be those of a for loop, if-else condition, or any other similar construct, and are called, a block. Let’s see an example to sum this all up.

```js
let globalAge = 23; // This is a global variable

// This is a function - and hey, a curly brace indicating a block
function printAge (age) {
  var varAge = 34; // This is a function scoped variable

  // This is yet another curly brace, and thus a block
  if (age > 0) {
    // This is a block-scoped variable that exists
    // within its nearest enclosing block, the if's block
    const constAge = age * 2;
    console.log(constAge);
  }

  // ERROR! We tried to access a block scoped variable
  // not within its scope
  console.log(constAge);
}

printAge(globalAge);

// ERROR! We tried to access a function scoped variable
// outside the function it's defined in
console.log(varAge);
```
