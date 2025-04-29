### Creating JavaScript Objects

There are several ways to create objects in JavaScript. Each method serves different purposes and offers various features.



Methods for Defining JavaScript Objects

    Object Literal
    new Keyword
    Object Constructor
    Factory Function
    Object.assign()
    Object.create()
    Object.fromEntries()




#### Object Literals

The simplest method to create an object is the object literal, which is concise and clear.


An object literal is a list of property names:values inside curly braces {}.


```js
{firstName:"John", lastName:"Doe", age:50, eyeColor:"blue"};
```

```js
const person = {
  name: 'Alice',
  age: 30,
  greet() {
    console.log(`Hello, my name is ${this.name}`);
  }
};

person.greet();  // Output: Hello, my name is Alice
```



#### new Object()

```js
// Create an Object
const person = new Object();

// Add Properties
person.firstName = "John";
person.lastName = "Doe";
person.age = 50;
person.eyeColor = "blue";
```



#### Constructor Functions

Constructor functions are used to create multiple instances of an object. 
They require the use of the `new` keyword.

```js
function Person(first, last, age, eyecolor) {
  this.firstName = first;
  this.lastName = last;
  this.age = age;
  this.eyeColor = eyecolor;
  this.fullName = function() {
    return this.firstName + " " + this.lastName;
  };
}

const bob = new Person('Bob', 'Smith'. 25, 'blue');
bob.fullName();  // Output: "Bob Smith"
```



#### Factory Functions

Factory functions are regular functions that return objects. They help encapsulate creation logic and can be used to hide complex configuration details.

```js
function createPerson(name, age) {
  return {
    name,
    age,
    greet() {
      console.log(`Hi, I'm ${name} and I'm ${age} years old.`);
    }
  };
}

const emily = createPerson('Emily', 35);
emily.greet();  // Output: Hi, I'm Emily and I'm 35 years old.

```



#### Object.create()

This method creates a new object with the specified prototype. It’s useful for setting up a specific inheritance chain.

```js
const personPrototype = {
  greet() {
    console.log(`Hello, I'm ${this.name}`);
  }
};

const john = Object.create(personPrototype);
john.name = 'John';
john.age = 40;
john.greet();  // Output: Hello, I'm John
```



#### ES6 Classes

Introduced in ES6, classes provide a syntactic sugar over the prototypal inheritance model. They make the code more intuitive for those coming from class-based languages.

```js
class PersonClass {
  constructor(name, age) {
    this.name = name;
    this.age = age;
  }

  greet() {
    console.log(`Hello, I'm ${this.name}`);
  }
}

const jane = new PersonClass('Jane', 28);
jane.greet();  // Output: Hello, I'm Jane
```















































### Module Pattern

The module pattern: IIFEs

ECMAScript 6 introduced a new JavaScript feature called “modules” - which are a set of syntax for importing and exporting code between different JavaScript files. While they are important and powerful, they are covered a bit later in the curriculum. We are not talking about them in this section.

Oftentimes, you do not need a factory to produce multiple objects - instead, you are using it to wrap sections of code together, hiding the variables and functions that you do not need elsewhere as private. This is easily achievable by wrapping your factory function in parentheses and immediately calling (invoking) it. This immediate function call is commonly referred to as an Immediately Invoked Function Expression (duh) or IIFE in short. This pattern of wrapping a factory function inside an IIFE is called the module pattern.

const calculator = (function () {
  const add = (a, b) => a + b;
  const sub = (a, b) => a - b;
  const mul = (a, b) => a * b;
  const div = (a, b) => a / b;
  return { add, sub, mul, div };
})();

calculator.add(3,5); // 8
calculator.sub(6,2); // 4
calculator.mul(14,5534); // 77476

In this example, we have a factory function creating some basic operations that we need only once. We can wrap it in parentheses and immediately call it by adding () - returning the result object that we store in calculator. In this way we can write code, wrapping away things that we do not need as private variables and functions inside our factory function and while they are tucked inside of our module, we can use the returned variables and functions outside the factory, as necessary.
Encapsulating with the module pattern

At first glance, this does not seem particularly useful. If we have some code that we use only once, why not write it in the main section of our JavaScript file itself? After all, the power of factory functions lies in being, well, a factory to make multiple objects, right?

This is where we encounter the word encapsulation - bundling data, code, or something into a single unit, with selective access to the things inside that unit itself. While it sounds general, this is what happens when we wrap, or encapsulate our code into modules - we don’t expose everything to the body of our program itself. This encapsulation leads to an effect called namespacing. Namespacing is a technique that is used to avoid naming collisions in our programs.

Take the calculator example into consideration. It’s very easy to imagine a scenario where you can accidentally create multiple functions with the name add. What does add do - does it add two numbers? Strings? Does it take its input directly from the DOM and display the result? What would you name the functions that do these things? Instead, we can easily encapsulate them inside a module called calculator which generates an object with that name, allowing us to explicitly call calculator.add(a, b) or calculator.sub(a, b).