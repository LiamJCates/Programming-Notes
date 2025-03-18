Object literals

An object literal is a list of zero or more pairs of property names and associated values of an object, enclosed in curly braces ({}).

Warning: Do not use an object literal at the beginning of a statement! This will lead to an error (or not behave as you expect), because the { will be interpreted as the beginning of a block.

The following is an example of an object literal. The first element of the car object defines a property, myCar, and assigns to it a new string, "Saturn"; the second element, the getCar property, is immediately assigned the result of invoking the function (carTypes("Honda")); the third element, the special property, uses an existing variable (sales).
js

const sales = "Toyota";

function carTypes(name) {
  return name === "Honda" ? name : `Sorry, we don't sell ${name}.`;
}

const car = { myCar: "Saturn", getCar: carTypes("Honda"), special: sales };

console.log(car.myCar); // Saturn
console.log(car.getCar); // Honda
console.log(car.special); // Toyota

Additionally, you can use a numeric or string literal for the name of a property or nest an object inside another. The following example uses these options.
js

const car = { manyCars: { a: "Saab", b: "Jeep" }, 7: "Mazda" };

console.log(car.manyCars.b); // Jeep
console.log(car[7]); // Mazda

Object property names can be any string, including the empty string. If the property name would not be a valid JavaScript identifier or number, it must be enclosed in quotes.

Property names that are not valid identifiers cannot be accessed as a dot (.) property.
js

const unusualPropertyNames = {
  '': 'An empty string',
  '!': 'Bang!'
}
console.log(unusualPropertyNames.'');   // SyntaxError: Unexpected string
console.log(unusualPropertyNames.!);    // SyntaxError: Unexpected token !

Instead, they must be accessed with the bracket notation ([]).
js

console.log(unusualPropertyNames[""]); // An empty string
console.log(unusualPropertyNames["!"]); // Bang!

Enhanced Object literals

Object literals support a range of shorthand syntaxes that include setting the prototype at construction, shorthand for foo: foo assignments, defining methods, making super calls, and computing property names with expressions.

Together, these also bring object literals and class declarations closer together, and allow object-based design to benefit from some of the same conveniences.
js

const obj = {
  // __proto__
  __proto__: theProtoObj,
  // Shorthand for 'handler: handler'
  handler,
  // Methods
  toString() {
    // Super calls
    return "d " + super.toString();
  },
  // Computed (dynamic) property names
  ["prop_" + (() => 42)()]: 42,
};
