# Scope

JavaScript’s `scope` model determines where identifiers (variables, functions, classes) are visible and how they are resolved at runtime. 

There are four primary scope types—`global`, `module`, `function`, and `block`—each with distinct rules for `var`, `let`, `const`, `function declarations`, and `function expressions`, and `class declarations`. 

A variable may belong to one of the following scopes:

    Global scope: The default scope for all code running in script mode.
    Module scope: The scope for code running in module mode.
    Function scope: The scope created within a function.

In addition, variables declared with let or const can belong to an additional scope:

    Block scope: The scope created with any pair of curly braces (a block).

A variable is always available in its own scope and all of its child scopes.

When you declare a variable outside of any function, it is called a `global variable`, because it is available to any other code in the current document. 

When you declare a variable within a function, it is called a `local variable`, because it is available only within that function.


`Hoisting` moves declarations to the top of their scopes during compilation, before code execution. However, the outcomes of hoisting differ based on the type of declaration and how they are initialized.

When code references a binding outside its scope or within its `temporal dead zone`, JavaScript throws a `ReferenceError`


## Overview of Scope Types

### Global Scope
Any code outside any block, function, or module runs in `global scope`. In browsers, this is the web page’s top‐level environment.

Variables declared in the global scope and are accessible anywhere in the script.

Global scope encompasses script-mode code, flies loaded with `<script>`.

Global scope binds `var`‐declared variables and function declarations to the global object (e.g. window in browsers), they become properties of the global object (e.g., `window`, `globalThis`), meaning you can access them via `window.myVar` or `globalThis.myVar`. 

Global scope `let`, `const`, and `class` declarations create top‐level bindings in the global lexical environment but do **not** become global object properties.

In browsers, global-scope declarations create properties on the global object, (`window` in browsers or `globalThis`), but the behavior differs by declaration type. 

Knowing which declarations attach to the global object is critical for avoiding unwanted global state and collisions.

* **`var`**: creates property on global object in global scope. 
* **`let`/`const`**: do *not* create properties on the global object. 
* **Function declarations**: in global scope, create non-configurable properties on the global object. 
* **Class declarations**: in global scope, create block-scoped bindings without global object properties. 

```js
var a = 1;
let b = 2;
const c = 3;
function foo() { return 'bar'; }

console.log(window.a);   // 1
console.log(window.b);   // undefined
console.log(window.c);   // undefined
console.log(window.foo); // function foo() {...}
```

---

### Module Scope

Module scope (in ES modules) is like global scope but isolated per‐module: top‐level bindings neither pollute nor read from the host global object

In ES modules (e.g., files loaded with `<script type="module">` or via `import`), each file has its own top-level scope, meaning variables and functions declared at the top level of one module are not visible in another module unless explicitly exported and imported.

* **Behavior**: `var`, `let`, `const`, and function declarations at the top level are local to the module and do not attach to the host global object or collide with other modules.

```js
// module.js
export const x = 42;
var y = 100;
function greet() { console.log('hello'); }

// In another file or REPL:
import { x } from './module.js';
console.log(x);            // 42
console.log(globalThis.x); // undefined
console.log(typeof y);     // "undefined"
```

---

### Function Scope
Entering a function creates a new scope.

Any variable declared with `var` or via `function` parameters lives in the enclosing function scope.  Nested functions form new inner scopes that can access variables from their parent scopes, enabling closures. 

* **`var`**: declarations are scoped to the entire function.
* **`let`/`const`**: Inside functions, these remain block‐scoped (see Block Scope below).

```js
function example() {
  var x = 1;
  let y = 2;
  const z = 3;

  if (true) {
    var x = 10;   // same function‐scoped x
    let y = 20;   // new block‐scoped y
    console.log(z); // 3
  }

  console.log(x); // 10
  console.log(y); // 2
}
example();
```
---

### Block Scope

Blocks delimited by `{}` create block scopes.  Any `{ … }` block creates a scope for `let`, `const`, `class`, and (in strict mode) `function` declarations.

---

## Declarations and Their Scope Behaviors

### `var` Declarations

* **Scope**: enclosing function or module, otherwise global
* **Hoisting**: Declaration is hoisted and initialized to `undefined`, so you can reference it before its line without a `ReferenceError`.
* **Global Object**: At top level, creates a non‐configurable property on the global object.


```js
function demoVar() {
  console.log(x); // undefined (hoisted)
  var x = 10;
  console.log(x); // 10
}
demoVar();

console.log(globalThis.x); // undefined
console.log(x); // ReferenceError due to funciton scope
```

```js
{
  var x = 3;
  console.log(x); // 3
}
console.log(globalThis.x); // undefined
console.log(x); // 3
```
---

### `let` Declarations

* **Scope**: Block scope
* **Temporal Dead Zone (TDZ)**: `let` is hoisted but uninitialized until their declaration line; accessing them beforehand throws a `ReferenceError`.
* **Global Object**: Top‐level `let` does not attach to the global object. 

```js
console.log(b); // ReferenceError: b is not defined
let b = 6;
```


```js
{
  let x = 3;
  console.log(x); // 3
}
console.log(globalThis.x); // undefined
//console.log(x); // ReferenceError: x is not defined
let x = 2;
console.log(globalThis.x); // undefined
console.log(x); // 2
```


```js
let name = 'Abe'

const greetAbe = () => 'Hello, ' + name + '!'

name = 'Ben'

const greetBen = () => 'Hello, ' + name + '!'

console.log(greetAbe()) // Hello, Ben!
console.log(greetBen()) // Hello, Ben!
```

---

### `const` Declarations

* **Scope**: Block scope
* **Temporal Dead Zone (TDZ)**: `const` is hoisted but uninitialized until their declaration line; accessing them beforehand throws a `ReferenceError`.
* **Global Object**: Top‐level `const` does not attach to the global object.

```js
{
  // console.log(y); // ReferenceError
  const y = { name: "JS" };
  y.name = "JavaScript"; // allowed
  // y = {}; // TypeError: Assignment to constant variable.
}
```

```js
{
  const x = 'inside';
  console.log(x); // "inside"
}
console.log(x); // ReferenceError: x is not defined
```

---

### Function Declarations

* **Scope**: Global, module, function, or block (strict mode).
* **Hoisting**: Fully hoisted—both name and body—allowing you to call the function before its declaration line.
* **Global Object**: In global script mode, creates a property on the global object.




---

### Function Expressions

* **Scope**: follows the surrounding scope (function or block) depending on the variable to which they are defined.
* **Hoisting**: Behave like variable declarations; if assigned to a `var`, the variable is hoisted as `undefined`; if assigned to `let`/`const`, they follow TDZ rules (TypeError if called before assignment).
* **Named vs. Anonymous**: A named function expression’s name is only visible within its own body.

- **Be Cautious with Function Expressions:** Be aware that function expressions are not hoisted in the same way as function declarations. Ensure that function expressions are defined before they are invoked.

```js
console.log(sayHi); // undefined
// sayHi(); // TypeError
var sayHi = function() {
  console.log("Hi");
};
sayHi(); // "Hi"
```

```js
console.log(expr); // undefined
var expr = function() { return "expr"; };

//console.log(inner); // ReferenceError
const namedExpr = function inner() { 
  console.log(inner) //[Function: inner]
  return "named"; 
};
//console.log(inner) //ReferenceError: inner is not defined
namedExpr()
```

---

### Class Declarations

Classes in JavaScript are hoisted similarly to `let` and `const`: the declaration is recognized at the top of its containing scope, but the binding is uninitialized until the actual declaration line, creating a temporal dead zone (TDZ). Attempting to access the class before its line of declaration results in a `ReferenceError` rather than `undefined`, which avoids unintended global pollution and enforces safer coding patterns and discourages reliance on forward references.

* **Scope**: Nearest enclosing block. 
* **Temporal Dead Zone (TDZ)**: `let`/`const` are hoisted but uninitialized until their declaration line; accessing them beforehand throws a `ReferenceError`.
* **Global Object**: At top level in scripts, a `class` is block-scoped and lives in the global lexical environment, but it never becomes a `window` (or `globalThis`) property,.


Block Scope Example
```js
function demo() {
  class LocalClass { constructor(){this.x="outer"} }
  {
    class LocalClass { constructor(){this.x="inner"} }  // shadows outer LocalClass
    console.log(new LocalClass().x); // inner
  }
  console.log(new LocalClass().x);   // outer
}
demo();
```

```js
class MyGlobalClass {
  constructor() { this.name = 'global'; }
}

console.log(typeof MyGlobalClass);        // "function"
console.log(window.MyGlobalClass);        // undefined
console.log(globalThis.MyGlobalClass);    // undefined
```


In ES modules, every file has its own scope. A top-level `class` in a module is module-local, and you must explicitly export it to use it elsewhere ([MDN Web Docs][2]). Even if you omit `export`, the class remains private to that module and is not a property on the shared global object ([Contentful][5]).

```js
// module.js
class PrivateClass { /* ... */ }
export class PublicClass { /* ... */ }

// In another file:
import { PublicClass } from './module.js';
console.log(typeof PrivateClass);       // "undefined"
console.log(typeof PublicClass);        // "function"
```


```js
// console.log(MyClass); // ReferenceError
class MyClass {
  constructor(name) {
    this.name = name;
  }
}
const obj = new MyClass("Scope");
console.log(obj.name); // "Scope"
```

Here, attempting to instantiate `MyClass` before its declaration throws a `ReferenceError` because the class is in the temporal dead zone until the declaration is evaluated.


Unlike `var` and function declarations, class declarations never create properties on the global object, even when declared at the script’s top level . This design decision prevents inadvertent pollution of the global namespace and is consistent with ES2015’s move toward modular, encapsulated code.

If you need a class to be globally accessible as a property (for example, for a legacy script that depends on `window.MyClass`), you must explicitly assign it:

```js
class ExplicitGlobal { }
window.ExplicitGlobal = ExplicitGlobal;

console.log(window.ExplicitGlobal); // class ExplicitGlobal { }
```

---

## ReferenceError

A `ReferenceError` occurs when you try to access a variable that:

1. Has never been declared in the current scope
2. Is inside its TDZ (for `let`/`const`/`class`) before initialization.

This immediate feedback helps catch errors early in development, unlike `var` which would silently return `undefined` and potentially cause runtime bugs.

```js
console.log(foo); // ReferenceError: foo is not defined
let foo = 1;
```

```js
{
  console.log(Local); // ReferenceError
  class Local { }
}
```

---

## Hoisting

### **Variable Hoisting:**

In JavaScript, **hoisting** refers to the interpreter's behavior of moving declarations to the top of their scope during the compilation phase, before code execution. This means that variables, functions, and classes can be referenced before they are explicitly declared in the code. 

---

#### **`var`**

Variables declared with `var` are hoisted to the top of their function or global scope and initialized with `undefined`. This means you can reference them before their declaration without causing a runtime error, but their value will be `undefined` until the assignment is encountered during execution.
  
```js
console.log(message); // Output: undefined
var message = 'Hello, World!';
console.log(message); // Output: 'Hello, World!'
```

In this example, the declaration of `message` is hoisted, but its assignment occurs at the original line. Therefore, the first `console.log` outputs `undefined`.

Because of hoisting, all var statements in a function should be placed as near to the top of the function as possible. This best practice increases the clarity of the code.

---

#### **`let` and `const`**

Variables declared with `let` and `const` are also hoisted to the top of their block scope. However, unlike `var`, they are not initialized during hoisting. For this reason, they are considered `non-hoisted` variables. Accessing them before their declaration results in a `ReferenceError` due to the `temporal dead zone`, which is the period between entering the scope and the actual declaration where the variable cannot be accessed.

```js
console.log(greeting); // Throws ReferenceError
let greeting = 'Hello!';
```

Here, attempting to access `greeting` before its declaration throws a `ReferenceError` because `let` does not initialize the variable during hoisting.

---

### **Function Hoisting:**

#### **Function Declarations:**

Function declarations are hoisted entirely, meaning both the function's name and its implementation are moved to the top of their scope. This allows functions to be invoked before they appear in the code.

```js
sayHello(); // Output: 'Hello!'

function sayHello() {
  console.log('Hello!');
}
```

In this case, the function `sayHello` is hoisted, so it can be called before its declaration.

#### **Function Expressions:**

Function expressions, whether using `var`, `let`, or `const`, are not hoisted in the same way as function declarations. Only the variable declaration is hoisted, not the function assignment. This means that attempting to invoke the function before its assignment will result in an error.

---

**Best Practices:**

- **Declare Variables and Functions at the Top:** To avoid confusion and potential errors related to hoisting, it's advisable to declare all variables and functions at the beginning of their scope.

- **Use `let` and `const`:** Prefer `let` and `const` over `var` to prevent unintentional hoisting issues and to leverage block scope, which can lead to more predictable and maintainable code.

Understanding hoisting is crucial for writing predictable and bug-free JavaScript code. By being aware of how declarations are processed during the compilation phase, developers can avoid common pitfalls and ensure that their code behaves as intended. 

---

### Sources

8. **TC39 ECMA-262 (ECMAScript® 2026 Language Specification)**
   [https://tc39.es/ecma262/](https://tc39.es/ecma262/)

17. **MDN Web Docs: JavaScript Guide — Grammar and types**
    [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Grammar\_and\_types](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Grammar_and_types)




10. **MDN Web Docs: Function reference**
    [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/function](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/function)




5. ReferenceError – MDN Web Docs ([https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Errors/Not\_defined](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Errors/Not_defined))

20. **MDN Web Docs: JavaScript Error Reference**
    [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Errors](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Errors)

6. **MDN Web Docs: ReferenceError object**
   [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global\_Objects/ReferenceError](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/ReferenceError)





15. **MDN Web Docs: `var` statement reference**
    [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/var](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/var)


19. **JavaScript.info: `var` tutorial**
    [https://javascript.info/var](https://javascript.info/var)

4. **MDN Web Docs: `let` declaration**
   [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/let](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/let)


10. `const` – MDN Web Docs ([https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/const](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/const))

11. **freeCodeCamp: “Var, Let, and Const – What’s the Difference?”**
    [https://www.freecodecamp.org/news/var-let-and-const-whats-the-difference/](https://www.freecodecamp.org/news/var-let-and-const-whats-the-difference/)




11. Classes – MDN Web Docs ([https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes))



3. **MDN Web Docs: Block statement**
   [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/block](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/block)




12. JavaScript modules introduction – javascript.info ([https://javascript.info/modules-intro](https://javascript.info/modules-intro))

9. **MDN Web Docs: JavaScript modules guide**
   [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Modules](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Modules)




16. **MDN Web Docs: Global object (globalThis)**
    [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global\_Objects/globalThis](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/globalThis)

1. **MDN Web Docs: Global scope**
   [https://developer.mozilla.org/en-US/docs/Glossary/Global\_scope](https://developer.mozilla.org/en-US/docs/Glossary/Global_scope)

2. **MDN Web Docs: Scope glossary**
   [https://developer.mozilla.org/en-US/docs/Glossary/Scope](https://developer.mozilla.org/en-US/docs/Glossary/Scope)

14. Scope & closures – javascript.info ([https://javascript.info/closure](https://javascript.info/closure))

12. **W3Schools: JavaScript Scope**
    [https://www.w3schools.com/js/js\_scope.asp](https://www.w3schools.com/js/js_scope.asp)

18. **Medium: “Scope and Closure Demystified”**
    [https://medium.com/javascript-in-plain-english/scope-and-closure-demystified-196f8b288e1a](https://medium.com/javascript-in-plain-english/scope-and-closure-demystified-196f8b288e1a)

7. **JavaScript.info: Scope and closure**
   [https://javascript.info/closure](https://javascript.info/closure)





13. **W3Schools: JavaScript Hoisting**
    [https://www.w3schools.com/js/js\_hoisting.asp](https://www.w3schools.com/js/js_hoisting.asp)

14. **GeeksforGeeks: Hoisting in JavaScript**
    [https://www.geeksforgeeks.org/hoisting-in-javascript/](https://www.geeksforgeeks.org/hoisting-in-javascript/)

3. **MDN Web Docs: Hoisting glossary**
   [https://developer.mozilla.org/en-US/docs/Glossary/Hoisting](https://developer.mozilla.org/en-US/docs/Glossary/Hoisting)







https://wesbos.com/javascript/03-the-tricky-bits/scope







* MDN Web Docs: Classes – [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Classes) (turn0search0)
* Stack Overflow: How does the scope of JavaScript classes work? – [https://stackoverflow.com/q/58048127](https://stackoverflow.com/q/58048127) (turn0search13)
* Stack Overflow: Are class declarations subject to scope in JavaScript? – [https://stackoverflow.com/q/14676405](https://stackoverflow.com/q/14676405) (turn0search14)
* MDN Web Docs: Using classes (guide) – [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Using\_classes](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Using_classes) (turn0search4)
* Contentful Blog: What is the global object in JavaScript? – [https://www.contentful.com/blog/the-global-object-in-javascript/](https://www.contentful.com/blog/the-global-object-in-javascript/) (turn0search2)
* Stack Overflow: How hoisting works for a class in JavaScript? – [https://stackoverflow.com/q/58098455](https://stackoverflow.com/q/58098455) (turn0search17)
* GeeksforGeeks: JavaScript Hoisting – [https://www.geeksforgeeks.org/javascript-hoisting/](https://www.geeksforgeeks.org/javascript-hoisting/) (turn0search12)
* MDN Web Docs: Grammar and types – [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Grammar\_and\_types](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Grammar_and_types) (turn0search6)
* W3Schools: JavaScript Hoisting – [https://www.w3schools.com/js/js\_hoisting.asp](https://www.w3schools.com/js/js_hoisting.asp) (turn0search1)
* MDN Web Docs: Standard built-in objects (global scope) – [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global\_Objects](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects) (turn0search7)

[1]: https://stackoverflow.com/questions/58048127/how-does-the-scope-of-javascript-classes-work?utm_source=chatgpt.com "How does the scope of Javascript classes work? - Stack Overflow"
[2]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Using_classes?utm_source=chatgpt.com "Using classes - JavaScript - MDN Web Docs - Mozilla"
[3]: https://stackoverflow.com/questions/58098455/how-hoisting-works-for-a-class-in-javascript?utm_source=chatgpt.com "How hoisting works for a class in JavaScript? - Stack Overflow"
[4]: https://stackoverflow.com/questions/14676405/are-class-declarations-subject-to-scope-in-javascript?utm_source=chatgpt.com "Are class declarations subject to scope in JavaScript? - Stack Overflow"
[5]: https://www.contentful.com/blog/the-global-object-in-javascript/?utm_source=chatgpt.com "What is the global object in JavaScript? A practical guide for ..."
[6]: https://www.geeksforgeeks.org/javascript-hoisting/?utm_source=chatgpt.com "JavaScript Hoisting | GeeksforGeeks"
[7]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Grammar_and_types?utm_source=chatgpt.com "Grammar and types - JavaScript - MDN Web Docs - Mozilla"
[8]: https://www.w3schools.com/js/js_hoisting.asp?utm_source=chatgpt.com "JavaScript Hoisting - W3Schools"



