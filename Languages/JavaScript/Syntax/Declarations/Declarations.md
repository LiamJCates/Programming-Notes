## Declarations


### Variable Declarations

JavaScript offers three different ways to declare a named value: var, let, and const. 

In a statement like `let x = 42`, the let x part is called a `declaration`, and the = 42 part is called an `initializer`. 
- the declaration allows the variable to be accessed later in code without throwing a ReferenceError
- the initializer assigns a value to the variable

In essence, `let x = 42` is equivalent to `let x; x = 42`

Variables should always be declared before they are used. JavaScript used to allow assigning to undeclared variables, which created an undeclared global variable.
This is an error in `strict mode` and should be avoided altogether.



“var” variables can be redeclared and redefined, meaning that once values are declared, they can be changed and mutated.


#### Initialization

In var and let declarations, the initializer is optional. If a variable is declared without an initializer, it is assigned the value `undefined`.

```js
let x;
console.log(x); // logs "undefined"
```

const declarations always need an initializer, because they forbid any kind of assignment after declaration, and implicitly initializing it with undefined is likely a programmer mistake. A constant cannot change value through assignment or be re-declared while the script is running. It must be initialized to a value.

```js
const x; // SyntaxError: Missing initializer in const declaration
```

#### `var` Outdated?

Often, you’ll be given the advice to avoid var because it is “outdated.” You can rest assured that it’s not, and you must understand each of these variable declaration methods in order to choose the right tool for the job.



#### Const

Constants in JavaScript are different from those in many other lan-
guages, where they function as immutable data types. In JavaScript, con-
stants only look immutable. In fact, they are read- only references to their
value. Therefore, you cannot directly reassign another value to the variable
identifier for primitive data types. However, objects or arrays are non-
primitive data types, so even when you use const, you can mutate their val-
ues through methods or direct property access.

```js
const primitiveDataType = 1;
try {
primitiveDataType = 2;
} catch (err) {
console.log(err);
}
const nonPrimitiveDataType = [];
nonPrimitiveDataType.push(1);
console.log(nonPrimitiveDataType);
```