Object Literals

You can create a JavaScript object in a few different ways, but the most common way is to use an object literal.
```js
const obj = {
        key: value
      };
```

This is a lot easier than doing something like new object, which you can do if you want to. Literal initiation is very common in JavaScript. We use it for objects, arrays, strings, numbers, and even things like regular expressions. The object literal syntax supports a few modern goodies. Here's a simple example where this object defined two regular properties and two functions.
```js
const mystery = 'answer';
const InverseOfPI = 1 / Math.PI;

const obj = {
	p1: 10,
  p2: 20,
  f1() {},
  f2: () => {},
  [mystery]: 42,
  InverseOfPI,
};
```
If you need to define a property that holds a function, you can use the short syntax that f1 does with object liberals. Of course, if you need an arrow function, you can still use the regular property syntax of f2.

Modern object literals also support dynamic properties using this syntax.
```js
[mystery]: 42,
```

It looks like an array literal, but don't confuse it with that. JavaScript will evaluate what's within the square brackets and make the result of that the new property name. So, assuming we have a variable named mystery defined before this X object, here's a JavaScript interview question. What is the value of obj.mystery? It's undefined because this mystery property was defined with a dynamic property syntax. This means JavaScript will evaluate the mystery expression first, and whatever that expression evaluates to will become the object's property. For this case, the object will have a property named answer with the value of 42.
```js
console.log(obj.answer); //42
```

Another widely popular feature about object liberals is available to you when you need to define an object with property names to map values that exist in the current scope with the exact same name. Here's an example. If we have a variable named InverseOfPI, we would like obj here to have a property named InverseOfPI holding the same value as the variable InverseOfPI:
```js
InverseOfPI: InverseOfPI
```
Instead of typing that name twice, you can use the shorter syntax by removing the second part. This shorter syntax, shown in the initial example above, is equivalent to what I had before. Objects are very popular in JavaScript. They are used to manage and communicate data, and using these features will make the code a bit shorter and easier to read.
