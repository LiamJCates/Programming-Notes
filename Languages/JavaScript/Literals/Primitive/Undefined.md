Represents an uninitialized value.

A variable that has not been assigned a value is of type undefined. A method or statement also returns undefined if the variable that is being evaluated does not have an assigned value. A function returns undefined if a value was not returned.

When a memory block is uninitialized, the JavaScript engine implicitly assigns 'undefined' to it during the variable phase. Variables declared with `var` are initialized in this way, while those declared with `let` and `const` are not initialized during the variable phase.


Note: While you can use undefined as an identifier (variable name) in any scope other than the global scope (because undefined is not a reserved word), doing so is a very bad idea that will make your code difficult to maintain and debug.

```javascript
// DON'T DO THIS

(() => {
  const undefined = "foo";
  console.log(undefined, typeof undefined); // foo string
})();

((undefined) => {
  console.log(undefined, typeof undefined); // foo string
})("foo");
```


Strict equality and undefined

You can use undefined and the strict equality and inequality operators to determine whether a variable has a value. In the following code, the variable x is not initialized, and the if statement evaluates to true.

```javascript
let x;
if (x === undefined) {
  // these statements execute
} else {
  // these statements do not execute
}
```

Note: The strict equality operator (as opposed to the standard equality operator) must be used here, because x == undefined also checks whether x is null, while strict equality doesn't. This is because null is not equivalent to undefined.

See Equality comparison and sameness for details.
typeof operator and undefined

Alternatively, typeof can be used:

```javascript
let x;
if (typeof x === "undefined") {
  // these statements execute
}
```

One reason to use typeof is that it does not throw an error if the variable has not been declared.

```javascript
// x has not been declared before
// evaluates to true without errors
if (typeof x === "undefined") {
  // these statements execute
}

// Throws a ReferenceError
if (x === undefined) {
}
```

However, there is another alternative. JavaScript is a statically scoped language, so knowing if a variable is declared can be read by seeing whether it is declared in an enclosing context.

The global scope is bound to the global object, so checking the existence of a variable in the global context can be done by checking the existence of a property on the global object, using the in operator, for instance:
```javascript
if ("x" in window) {
  // These statements execute only if x is defined globally
}
```
void operator and undefined

The void operator is a third alternative.
```javascript
let x;
if (x === void 0) {
  // these statements execute
}

// y has not been declared before
if (y === void 0) {
  // throws Uncaught ReferenceError: y is not defined
}
```