Boolean values can be one of two values: true or false, representing the truth value of a logical proposition.


## Description

Boolean values are typically produced by relational operators, equality operators, and logical NOT (!). They can also be produced by functions that represent conditions, such as Array.isArray(). Note that binary logical operators such as && and || return the values of the operands, which may or may not be boolean values.

Boolean values are typically used in conditional testing, such as the condition for if...else and while statements, the conditional operator (? :), or the predicate return value of Array.prototype.filter().


#### Constructor

Boolean()

    Creates Boolean objects. When called as a function, it returns primitive values of type Boolean.

#### Instance properties

These properties are defined on Boolean.prototype and shared by all Boolean instances.

Boolean.prototype.constructor

    The constructor function that created the instance object. For Boolean instances, the initial value is the Boolean constructor.

#### Instance methods

Boolean.prototype.toString()

    Returns a string of either true or false depending upon the value of the object. Overrides the Object.prototype.toString() method.
Boolean.prototype.valueOf()

    Returns the primitive value of the Boolean object. Overrides the Object.prototype.valueOf() method.




### Boolean coercion

Many built-in operations that expect booleans first coerce their arguments to booleans. The operation can be summarized as follows:

    Booleans are returned as-is.
    undefined turns into false.
    null turns into false.
    0, -0, and NaN turn into false; other numbers turn into true.
    0n turns into false; other BigInts turn into true.
    The empty string "" turns into false; other strings turn into true.
    Symbols turn into true.
    All objects become true.

Note: A legacy behavior makes document.all return false when used as a boolean, despite it being an object. This property is legacy and non-standard and should not be used.

Note: Unlike other type conversions like string coercion or number coercion, boolean coercion does not attempt to convert objects to primitives by calling user methods.

In other words, there are only a handful of values that get coerced to false — these are called falsy values. All other values are called truthy values. A value's truthiness is important when used with logical operators, conditional statements, or any boolean context.



You would rarely need to explicitly convert something to a boolean value, as JavaScript does this automatically in boolean contexts, so you can use any value as if it's a boolean, based on its truthiness. You are also encouraged to use if (condition) and if (!condition) instead of if (condition === true) or if (condition === false) in your own code so you can take advantage of this convention. However, making sure that values representing conditions are always booleans can help clarify the intent of your code.

```javascript
// Do this:
// This always returns a boolean value
const isObject = (obj) => !!obj && typeof obj === "object";

// Or this:
const isObject = (obj) => Boolean(obj) && typeof obj === "object";

// Or this:
const isObject = (obj) => obj !== null && typeof obj === "object";

// Instead of this:
// This may return falsy values that are not equal to false
const isObject = (obj) => obj && typeof obj === "object";
```




### Boolean primitives and Boolean objects

For converting non-boolean values to boolean, use Boolean as a function or use the double NOT operator. Do not use the Boolean() constructor with new.

```javascript
const good = Boolean(expression);
const good2 = !!expression;

const bad = new Boolean(expression); // don't use this!
```

This is because all objects, including a Boolean object whose wrapped value is false, are truthy and evaluate to true in places such as conditional statements. 

```javascript
if (new Boolean(true)) {
  console.log("This log is printed.");
}

if (new Boolean(false)) {
  console.log("This log is ALSO printed.");
}

const myFalse = new Boolean(false); // myFalse is a Boolean object (not the primitive value false)
const g = Boolean(myFalse); // g is true
const myString = new String("Hello"); // myString is a String object
const s = Boolean(myString); // s is true
```

Warning: You should rarely find yourself using Boolean as a constructor.


There are two ways to achieve the same effect in JavaScript.

    Double NOT: !!x negates x twice, which converts x to a boolean using the same algorithm as above.
    The Boolean() function: Boolean(x) uses the same algorithm as above to convert x.

Note that truthiness is not the same as being loosely equal to true or false.

```javascript
if ([]) {
  console.log("[] is truthy");
}
if ([] == false) {
  console.log("[] == false");
}
// [] is truthy
// [] == false
```

[] is truthy, but it's also loosely equal to false. It's truthy, because all objects are truthy. However, when comparing with false, which is a primitive, [] is also converted to a primitive, which is "" via Array.prototype.toString(). Comparing strings and booleans results in both being converted to numbers, and they both become 0, so [] == false is true. 

In general, falsiness and == false differ in the following cases:

    NaN, undefined, and null are falsy but not loosely equal to false.
    "0" (and other string literals that are not "" but get coerced to 0) is truthy but loosely equal to false.
    Objects are always truthy, but their primitive representation may be loosely equal to false.

Truthy values are even more unlikely to be loosely equal to true. All values are either truthy or falsy, but most values are loosely equal to neither true nor false.

```javascript
// Creating false values

const bNoParam = Boolean();
const bZero = Boolean(0);
const bNull = Boolean(null);
const bEmptyString = Boolean("");
const bfalse = Boolean(false);

// Creating true values

const btrue = Boolean(true);
const btrueString = Boolean("true");
const bfalseString = Boolean("false");
const bSuLin = Boolean("Su Lin");
const bArrayProto = Boolean([]);
const bObjProto = Boolean({});
```