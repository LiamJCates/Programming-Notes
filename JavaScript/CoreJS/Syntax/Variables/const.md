We use const when the reference assigned to a variable is meant to be a constant one.
```js
// Scalar values
const answer = 42;
const greeting = 'Hello';

// Arrays and Objects
const numbers = [2, 4, 6];
const person = {
  firstName: 'John',
  lastName: 'Doe',
};
```

References assigned with const cannot be changed. Note how I'm saying references here and not values, because defining an object, as numbers and persons above, with const does not make it an immutable object. It just means constant reference to it. We can still change that object just like we can do within functions that receive objects as arguments. If the variable defined with const is a scaler one, like a string or an integer, you can think of it as an immutable object. Because these scaler values in JavaScript are immutable, we can't mutate the value of a string or an integer in JavaScript. And when we use const with these scalar values, we can't change the references either. However, placing an array or object in a const is a different story. The const will guarantee that the variable is pointing to the same array or object, but the content of the array or object can still be mutated. So be careful here, and keep that in mind.

Variables defined with const are much better than those defined with let for scaler values and functions because you get a guarantee that the value did not accidentally change. Looking at this code example here:
```js
const answer1 = 42;

/*
	A big program here...
*/

answer1; // is still 42;
```
assuming that between the first and last line there is a big program, on the last line, if the program runs without any errors, we can confidently say that the answer variable still holds the 42 value.

For the same example with let:
```js
let answer2 = 42;

/*
	A big program here...
*/

answer2; // might have changed;
```
we would have to parse through the code to figure out if the answer variable still holds the 42 value.

If you need a variable to hold a changing scaler value, like a counter, for example, then using let is okay. However, for most other cases, it's probably much better for you to stick with using const for all your variables.
