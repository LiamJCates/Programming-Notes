## Variables

In JavaScript, **variables** are used to store data values. They provide a way to label and manipulate data in a program. Variables can hold different types of data, such as numbers, strings, objects, and arrays.

---

## **Declaring Variables**

JavaScript provides three ways to declare variables:

1. **`var`** (old way, avoid using it)
2. **`let`** (preferred for variables that can change)
3. **`const`** (preferred for variables that should not change)

### **1. Using `var` (Function-scoped, avoid using)**
```javascript
var name = "Alice";
var age = 25;
var isStudent = true;
```
- Can be re-declared and updated.
- Function-scoped (not block-scoped), which can lead to issues.
- Hoisted to the top of the function but initialized as `undefined`.

### **2. Using `let` (Block-scoped)**
```javascript
let city = "New York";
city = "Los Angeles"; // Allowed
```
- Can be updated but **cannot be re-declared** in the same scope.
- Block-scoped, meaning it is only accessible inside the block `{}` where it was declared.

### **3. Using `const` (Block-scoped, cannot be changed)**
```javascript
const PI = 3.14159;
PI = 3.14; // ❌ Error: Assignment to constant variable
```
- Must be initialized when declared.
- Cannot be reassigned.
- Block-scoped like `let`.

---

## **Variable Naming Rules**
- Must start with a letter, `_`, or `$`
- Cannot start with a number (e.g., `var 1name = "John";` is invalid)
- Case-sensitive (`myVar` and `MyVar` are different)
- Should use camelCase for readability (e.g., `userAge`, `totalPrice`)

---



## Multiple Declarations

We can also declare multiple variables in one line:

```js
let user = 'John', age = 25, message = 'Hello';
```

That might seem shorter, but we don’t recommend it. For the sake of better readability, please use a single line per variable.




### Declare Once

A repeated declaration of the same variable is an error:

```js
let message = "This";

// repeated 'let' leads to an error
let message = "That"; // SyntaxError: 'message' has already been declared
```

So, we should declare a variable once and then refer to it without let.


### Non-Latin letters

Non-Latin letters are allowed, but not recommended

It is possible to use any language, including Cyrillic letters, Chinese logograms and so on, like this:

let имя = '...';
let 我 = '...';

Technically, there is no error here. Such names are allowed, but there is an international convention to use English in variable names. Even if we’re writing a small script, it may have a long life ahead. People from other countries may need to read it sometime.


## Reserved Names

There is a list of reserved words, which cannot be used as variable names because they are used by the language itself.

For example: let, class, return, and function are reserved.

The code below gives a syntax error:

let let = 5; // can't name a variable "let", error!
let return = 5; // also can't name it "return", error!



## An assignment without use strict

Normally, we need to define a variable before using it. But in the old times, it was technically possible to create a variable by a mere assignment of the value without using let. This still works now if we don’t put use strict in our scripts to maintain compatibility with old scripts.

// note: no "use strict" in this example

num = 5; // the variable "num" is created if it didn't exist

alert(num); // 5

This is a bad practice and would cause an error in strict mode:

"use strict";

num = 5; // error: num is not defined




### Capital const

Uppercase constants

There is a widespread practice to use constants as aliases for difficult-to-remember values that are known before execution.

Such constants are named using capital letters and underscores.

For instance, let’s make constants for colors in so-called “web” (hexadecimal) format:

```js
const COLOR_RED = "#F00";
const COLOR_GREEN = "#0F0";
const COLOR_BLUE = "#00F";
const COLOR_ORANGE = "#FF7F00";

// ...when we need to pick a color
let color = COLOR_ORANGE;
alert(color); // #FF7F00
```

Benefits:

    COLOR_ORANGE is much easier to remember than "#FF7F00".
    It is much easier to mistype "#FF7F00" than COLOR_ORANGE.
    When reading the code, COLOR_ORANGE is much more meaningful than #FF7F00.

When should we use capitals for a constant and when should we name it normally? Let’s make that clear.

Being a “constant” just means that a variable’s value never changes. But some constants are known before execution (like a hexadecimal value for red) and some constants are calculated in run-time, during the execution, but do not change after their initial assignment.

For instance:
```js
const pageLoadTime = /* time taken by a webpage to load */;
```

The value of pageLoadTime is not known before the page load, so it’s named normally. But it’s still a constant because it doesn’t change after the assignment.

In other words, capital-named constants are only used as aliases for “hard-coded” values.