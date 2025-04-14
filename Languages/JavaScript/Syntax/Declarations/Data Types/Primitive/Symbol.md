## Symbols

JavaScript Symbols are a primitive data type introduced in the ES6 version of the language. They are used to represent unique values that can be used as identifiers or keys in objects. They are also used to create private properties and methods in classes.

Why should you use it?

    Symbols are unique and immutable, so they can be used as unique identifiers in objects and classes.
    Symbols can be used to create private properties and methods in classes.
    Symbols are useful for creating constants that can be shared across different parts of your code.


The JavaScript Symbol is a primitive data type, just like Number, String, Boolean, etc. It represents a unique identifier and can be used in various ways. Symbols are used to create object properties, for example, when you want to assign a unique identifier to an object. They can also be used as a way to create private properties in objects, as they are not enumerable. In addition, Symbols can be used to create unique constants, which are useful when creating APIs. Symbols are created using the Symbol() function. The function takes an optional string parameter, which can be used to give the Symbol a description. This description is useful for debugging purposes, as it can be used to identify the Symbol.

```js
// Create a Symbol
const mySymbol = Symbol();

console.log(mySymbol);
// expected output: Symbol()
```
The Symbol() function also accepts an optional object parameter. This object can be used to create a global Symbol, which can be accessed from anywhere in the code. A global Symbol can be created by passing in an object with a 'global' property set to true.

```js
// Create a global Symbol
const myGlobalSymbol = Symbol('myGlobalSymbol', { global: true });

console.log(myGlobalSymbol);
// expected output: Symbol(myGlobalSymbol)
```
Symbols can also be used to create constants, which are useful for creating APIs. Constants are created by passing in an object with a 'constant' property set to true.

```js
// Create a constant
const MY_CONSTANT = Symbol('MY_CONSTANT', { constant: true });

console.log(MY_CONSTANT);
// expected output: Symbol(MY_CONSTANT)
```
Symbols can also be used as object keys. This is useful when you want to assign a unique identifier to an object.

```js
const mySymbol = Symbol();

const myObject = {
  [mySymbol]: 'Hello World'
};

console.log(myObject[mySymbol]);
// expected output: 'Hello World'
```
Symbols can also be used to create private properties in objects. Private properties are not enumerable, which means they will not show up when iterating over the object's properties.

```js
const mySymbol = Symbol();

const myObject = {
  [mySymbol]: 'Hello World'
};

// Private property is not enumerable
console.log(Object.keys(myObject));
// expected output: []
```
Symbols can also be used to create unique constants, which are useful when creating APIs. Constants are created by passing in an object with a 'constant' property set to true.

```js
// Create a constant
const MY_CONSTANT = Symbol('MY_CONSTANT', { constant: true });

// Create another constant
const MY_OTHER_CONSTANT = Symbol('MY_CONSTANT', { constant: true });

console.log(MY_CONSTANT === MY_OTHER_CONSTANT);
// expected output: false
```
Symbols can also be used to create unique constants, which are useful when creating APIs. Constants are created by passing in an object with a 'constant' property set to true.

```js
const mySymbol = Symbol();

const myObject = {
  [mySymbol]: 'Hello World'
};

console.log(myObject[mySymbol]);
// expected output: 'Hello World'
```
Symbols can also be used to create unique identifiers, which can be used to identify objects. This is useful when you want to assign a unique identifier to an object.

```js
// Create a constant
const MY_CONSTANT = Symbol('MY_CONSTANT', { constant: true });

// Create another constant
const MY_OTHER_CONSTANT = Symbol('MY_CONSTANT', { constant: true });

console.log(MY_CONSTANT === MY_OTHER_CONSTANT);
// expected output: false
```
Symbols can also be used to create unique constants, which are useful when creating APIs. Constants are created by passing in an object with a 'constant' property set to true.

```js
// Create a constant
const MY_CONSTANT = Symbol('MY_CONSTANT', { constant: true });

// Create another constant
const MY_OTHER_CONSTANT = Symbol('MY_CONSTANT', { constant: true });

console.log(MY_CONSTANT === MY_OTHER_CONSTANT);
// expected output: false
```