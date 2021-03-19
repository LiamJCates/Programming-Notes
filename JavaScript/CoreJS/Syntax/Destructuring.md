Destructuring and Rest/Spread

The destructuring syntax is really simple, but I've seen it confuse many people before. Let me make sure that does not happen to you. Destructuring works for both arrays and objects. Here's an example for objects using the built‑in Math object in JavaScript:
```js
// const PI = Math.PI;
// const E = Math.E;
// const SQRT2 = Math.SQRT2;

const {PI, E, SQRT2}  = Math;
```
When you have an object like Math, and you want to extract values out of this object into the enclosing scope, for example, instead of using Math.PI, you'd like to have a constant named PI to hold the value of Math.PI, which is easy because you can have a line like this for PI and another one for E if you need the same for E and so on. With the destructuring syntax, these three lines are equivalent to this single line. It destructures the three properties out of its right‑hand object and into the current scope.


This is useful when you need to use a few properties out of a bigger object. For example, here's a line to destructure Component, Fragment, and useState out of the React API.
```js
// Somewhere in a React App
const {Component, Fragment, useState} = require('react');
useState();
```
After the first line, I can use the useState method directly like this. If I don't use destructuring here, I'll have to type a lot more characters and lines.

Destructuring also works inside function arguments. If the argument passed to a function is an object, instead of using the name of the object every time you want to access its properties, you can use the destructuring syntax within the function parentheses to destructure just the properties that you're interested in and make them local to that function. This generally improves the readability of functions, and you'll see it used a lot for the props argument in React function components.
```js
const circle = {
  label: 'circleX',
  radius: 2,
};

const circleArea = ({radius}) =>
  (PI * radius * radius);
```
So here we have a circleArea function, which expects an object as its argument, and it expects that object to have a radius property. We're destructuring the radius property out of that object and using it locally in the function. If we call this circleArea function with an object like circle here, it will use its radius property inside of its calculation. Let's go ahead and test that. You'll see the circleArea calculation working as expected.


Destructured arguments can also be defined with defaults, like regular arguments. Say I'd like to use a default value of 2 for a precision property here.
```js
const circleArea = ({radius}, {precision = 2}) =>
  (PI * radius * radius).toFixed(precision);
```
We define a second options argument for this circleArea function here, and lets destructure our precisions out of that argument to use it in the function's body. If I'd like to use a default value of 2 for the precision property, I can just use the equal sign here after destructuring precision, and that means the default for precision, if not specified, will be 2.

I can also make this whole second argument optional using an equal sign after the destructuring syntax.
```js
const circleArea = ({radius}, {precision = 2} = {}) =>
  (PI * radius * radius).toFixed(precision);
```
The same call here will use an empty object for the second argument of the function, and then it will use a default value of 2 for the precision property that is now used in the function.

Of course, if we invoke the circleArea function with a second argument that has the precision property, that value will be used inside the function.
```js
console.log(
   circleArea(circle, { precision: 5 })
);
```
As you can see, this destructuring feature offers a good alternative to using named arguments in functions, which is much better than relying on positional arguments.

#### Destructuring Arrays
Destructuring, whether you do it in function arguments or directly with variables, also works for arrays. If you have an array of values and you want to extract these values into local variables, you can use the item's positions to destructure their values into local variables just like this.
```js
const [first, second,, forth] = [10, 20, 30, 40];
```
Note how I used double commas here to skip destructuring the third item in the array. The destructured variable fourth here will hold the value of 40.

In React, the useState function returns an array of two items. We use array destructuring with useState to capture these two items into local variables.
```js
const [value, setValue] = useState(initialValue);
```

Array destructuring is useful when combined with the rest operator, which has an example here.
```js
const [first, ...restOfItems] = [10, 20, 30, 40];
```

By using these three dots, we are asking JavaScript to destructure only one item out of this array and then create a new array under the name restOfItems to hold the rest of the items after removing the first one.

Let's test that.
```js
console.log(first);
console.log(restOfItems);
```
So first, here will be 10, and rest of items will be an array of 20, 30, and 40.

This is powerful for splitting the array, and it's also even more powerful when working with objects to filter out certain properties from an object. Here's an example of that.
```js
const data = {
	temp1: '001',
  temp2: '002',
  firstName: 'John',
  lastName: 'Doe',
};

const {temp1, temp2, ...person} = data;
```

We have this data object that has a few temp properties, and we'd like to create a new object that has the same data except for temp1 and temp2. We can destructure temp1 and temp2 and then use the rest operator to get the remaining properties into a new object called person.

Just like the three dots of rest, you can use the three dots to spread one array or object into a new array or object. This is useful for copying arrays and objects. You can spread the items in an array into a new array, like in this example.
```js
const newArray = [...restOfItems];
```
NewArray here will be a copy of the restOfItems array that we destructured above.

Similarly, you can also spread the key‑value pairs of an object into a new object, like this example.
```js
const newObject = {
  ...person
}
```
The newObject here will be a copy of the person object. Note that these copies are shallow copies. Any nested objects or arrays will be shared between these copies. Don't forget that.
