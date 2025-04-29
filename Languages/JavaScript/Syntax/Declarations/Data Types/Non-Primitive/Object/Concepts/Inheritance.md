## JavaScript Object Prototypes

https://medium.com/javascript-scene/3-different-kinds-of-prototypal-inheritance-es6-edition-32d777fa16c9


JavaScript is a prototype-based language. Instead of classical inheritance (as in some other languages),  JavaScript uses prototype-based inheritance, which means that objects inherit properties and methods from a prototype object via what is called the **prototype chain**.




## 4. Prototypes and Inheritance

JavaScript uses prototypal inheritance, meaning that objects inherit properties and methods from a prototype. Every object has an internal link to another object called its prototype.

### A. The Prototype Chain

When you try to access a property or method on an object, JavaScript first checks the object itself. If it doesn’t exist, it moves up the prototype chain until it finds it or reaches the end.

```js
function Animal(name) {
  this.name = name;
}
Animal.prototype.speak = function() {
  console.log(`${this.name} makes a noise.`);
};

const dog = new Animal('Dog');
dog.speak();  // Output: Dog makes a noise.
```

### B. Inheritance with Classes

ES6 classes provide an easier syntax to work with prototypes. The `extends` keyword is used to create a subclass that inherits from a parent class.

```js
class AnimalClass {
  constructor(name) {
    this.name = name;
  }
  
  speak() {
    console.log(`${this.name} makes a noise.`);
  }
}

class Dog extends AnimalClass {
  speak() {
    console.log(`${this.name} barks.`);
  }
}

const rover = new Dog('Rover');
rover.speak();  // Output: Rover barks.
```

### C. The `Object.getPrototypeOf` and `Object.setPrototypeOf` Methods

These methods allow you to query or change an object’s prototype.

```js
const parentObj = { a: 1 };
const childObj = { b: 2 };

Object.setPrototypeOf(childObj, parentObj);
console.log(childObj.a);  // Output: 1, inherited from parentObj

console.log(Object.getPrototypeOf(childObj));  // Output: { a: 1 }
```

---




## 1. What Is a Prototype?

- **Prototype Definition:**  
  Every JavaScript object has a hidden property called `[[Prototype]]` (commonly accessed via `__proto__` or by using `Object.getPrototypeOf()`). This prototype is simply another object from which the first object inherits properties and methods.

- **Prototype Chain:**  
  When trying to access a property on an object, JavaScript first looks for the property on the object itself. If it isn’t found, the search continues in the object’s prototype, then in that prototype’s prototype, and so on, until the property is found or the chain ends (usually at `null`).

- **Constructor’s Prototype Property:**  
  For objects created via a constructor function or class, the constructor has a `prototype` property which becomes the `[[Prototype]]` for all instances created by that constructor.

---

## 2. Creating and Working with Prototypes

#### 2.1.1b. Object Literals

A basic object literal’s prototype is `Object.prototype`.

```javascript
let obj = {
  name: 'Alice'
};

console.log(obj.toString()); // Inherited from Object.prototype
```

#### 2.1.2. Constructor Functions

When using a constructor function, every instance’s `[[Prototype]]` is set to the constructor’s `prototype` property.

```javascript
function Person(name) {
  this.name = name;
}

Person.prototype.greet = function() {
  return `Hello, my name is ${this.name}.`;
};

let person1 = new Person("Bob");
console.log(person1.greet()); // "Hello, my name is Bob."
```

- **Key Concepts:**
  - **`new` Operator:**  
    When used with a constructor function, `new` creates a new object, sets its prototype to `Person.prototype`, and returns that object.
  - **Prototype Property:**  
    The `greet` method is defined on `Person.prototype` so that all instances share it.

#### 2.1.3. ES6 Classes

ES6 classes are essentially syntactic sugar over the prototype-based system.

```javascript
class Animal {
  constructor(type) {
    this.type = type;
  }
  speak() {
    return `The ${this.type} speaks.`;
  }
}

let animal1 = new Animal("dog");
console.log(animal1.speak()); // "The dog speaks."
```

- **Behind the Scenes:**  
  The `speak` method is stored on `Animal.prototype`, and instances of `Animal` have their `[[Prototype]]` linked to it.

#### 2.1.4. `Object.create()`

Creates a new object with a specified prototype.

```javascript
const proto = { sayHi: () => "Hi" };
let obj2 = Object.create(proto);
console.log(obj2.sayHi()); // "Hi"
```

---

## 3. Prototype Chain and Property Lookup

### 3.1. How the Prototype Chain Works

When you try to access `obj.property`, JavaScript:
1. Checks if `property` is an own property of `obj`.
2. If not found, looks at `obj.__proto__` (or via `Object.getPrototypeOf(obj)`).
3. Continues up the chain until reaching `null`.

#### Example:

```javascript
let animal = {
  eats: true
};

let rabbit = Object.create(animal);
rabbit.jumps = true;

console.log(rabbit.eats); // true, from animal
console.log(rabbit.jumps); // true, own property
```

### 3.2. Overriding and Shadowing

- **Overriding:**  
  If an object defines a property with the same name as a property on its prototype, the object’s own property overrides (or “shadows”) the prototype property.
  
```javascript
let parent = { value: 42 };
let child = Object.create(parent);
child.value = 100;
console.log(child.value); // 100 (own property)
```

- **Deleting Own Properties:**  
  Deleting an own property reveals the inherited property (if it exists).

```javascript
delete child.value;
console.log(child.value); // 42, from the prototype parent
```

---

## 4. Practical Uses of Prototypes

### 4.1. Shared Methods and Memory Efficiency

Placing methods on the prototype ensures that all instances share the same function, reducing memory consumption.

```javascript
function Car(model) {
  this.model = model;
}

Car.prototype.drive = function() {
  return `${this.model} is driving.`;
};

let car1 = new Car("Toyota");
let car2 = new Car("Honda");

console.log(car1.drive()); // "Toyota is driving."
console.log(car2.drive()); // "Honda is driving."
```

### 4.2. Inheritance Patterns

#### 4.2.1. Classical Inheritance (Using Constructor Functions)

Using constructor functions and setting prototypes manually:

```javascript
function Vehicle(wheels) {
  this.wheels = wheels;
}

Vehicle.prototype.info = function() {
  return `This vehicle has ${this.wheels} wheels.`;
};

function Bicycle(model) {
  Vehicle.call(this, 2); // Inherit properties from Vehicle
  this.model = model;
}

// Inherit methods from Vehicle
Bicycle.prototype = Object.create(Vehicle.prototype);
Bicycle.prototype.constructor = Bicycle;

Bicycle.prototype.ride = function() {
  return `Riding a ${this.model} bicycle.`;
};

let bike = new Bicycle("Mountain");
console.log(bike.info());  // "This vehicle has 2 wheels."
console.log(bike.ride());  // "Riding a Mountain bicycle."
```

#### 4.2.2. ES6 Class Inheritance

```javascript
class Vehicle {
  constructor(wheels) {
    this.wheels = wheels;
  }
  info() {
    return `This vehicle has ${this.wheels} wheels.`;
  }
}

class Bicycle extends Vehicle {
  constructor(model) {
    super(2);
    this.model = model;
  }
  ride() {
    return `Riding a ${this.model} bicycle.`;
  }
}

let bike = new Bicycle("Road");
console.log(bike.info()); // "This vehicle has 2 wheels."
console.log(bike.ride()); // "Riding a Road bicycle."
```

---

## 5. Common Issues and Resolutions

### 5.1. Unexpected Prototype Pollution

- **Issue:**  
  Accidentally modifying `Object.prototype` can lead to unpredictable behavior.
- **Resolution:**  
  Never add enumerable properties directly to `Object.prototype`. If you need helper methods, consider using non-enumerable definitions or helper libraries.

```javascript
// Avoid this:
Object.prototype.badPractice = function() { /* ... */ };

// Instead, if necessary, define non-enumerable:
Object.defineProperty(Object.prototype, "goodPractice", {
  value: function() { /* ... */ },
  enumerable: false
});
```

Enumerable properties in JavaScript are those that show up in for...in loops and are accessible by methods like Object.keys(). By default, properties created by simple assignment or property initializers are enumerable. However, properties defined using Object.defineProperty() are not enumerable unless explicitly configured.
The enumerability attribute of a property determines whether it will be included when iterating over an object's properties. Non-enumerable properties are hidden from these iterations but can still be accessed directly if their name is known.
JavaScript

```js
const object1 = {
  a: 1,
  b: 2,
};

Object.defineProperty(object1, 'c', {
  value: 3,
  enumerable: false,
});

object1.d = 4;

console.log(Object.keys(object1)); // Output: ['a', 'b', 'd']

for (const key in object1) {
  console.log(key); // Output: a, b, d
}
```

In this example, property 'c' is non-enumerable, so it doesn't appear in the output of Object.keys() or the for...in loop. However, properties 'a', 'b', and 'd', being enumerable, are included in the iterations.


### 5.2. Overwriting the Prototype

- **Issue:**  
  Reassigning a prototype can break constructor relationships.
- **Resolution:**  
  When replacing prototypes (for example, with `Object.create()`), always reset the `constructor` property.

```javascript
function Person(name) {
  this.name = name;
}

Person.prototype = {
  greet: function() {
    return `Hello, ${this.name}`;
  }
};

// Reset constructor property after replacement:
Person.prototype.constructor = Person;
```

### 5.3. Performance Considerations

- **Issue:**  
  Deep prototype chains can slow down property lookups.
- **Resolution:**  
  - Keep your prototype chains as short as possible.
  - Use own properties for frequently accessed data.

### 5.4. Shadowing Built-in Properties

- **Issue:**  
  Overriding built-in methods (such as `toString` on `Object.prototype`) can lead to unexpected behavior.
- **Resolution:**  
  Use caution when naming properties and methods; consider using symbols if you need to avoid naming collisions.

---



Overlooking the Prototype Chain
- **Pitfall:** Accidentally modifying properties on the prototype can lead to unexpected behavior across objects.
- **Solution:** Prefer using object literals and ES6 classes for clear inheritance and avoid modifying built-in prototypes.



## 6. Debugging Prototypes

### 6.1. Tools and Techniques

- **Browser DevTools:**  
  Modern browsers allow you to inspect the prototype chain of objects in the console.
  
  ```javascript
  console.dir(someObject);
  ```
  
- **`Object.getPrototypeOf()`:**  
  Use this method to see an object’s direct prototype.
  
  ```javascript
  let proto = Object.getPrototypeOf(someObject);
  console.log(proto);
  ```

- **`instanceof` Operator:**  
  Check if an object is an instance of a particular constructor.
  
  ```javascript
  console.log(someObject instanceof Person);
  ```

---

## 7. Summary and Best Practices

- **Understand the Prototype Chain:**  
  Know that each object has a hidden `[[Prototype]]` and that property lookups continue up the chain.
- **Use Constructors or Classes:**  
  Use function constructors or ES6 classes to create objects that share methods via their prototype.
- **Avoid Modifying Global Prototypes:**  
  Do not alter `Object.prototype` or other built-in prototypes in ways that affect every object.
- **Reset the Constructor:**  
  When replacing the prototype, set the correct `constructor` property.
- **Use Debugging Tools:**  
  Leverage browser dev tools and built-in methods like `Object.getPrototypeOf()` to inspect and debug the prototype chain.

---

## 8. Code Examples Recap

### Example 1: Constructor Function and Prototype Method

```javascript
function Person(name) {
  this.name = name;
}

Person.prototype.greet = function() {
  return `Hello, my name is ${this.name}.`;
};

let alice = new Person("Alice");
console.log(alice.greet()); // "Hello, my name is Alice."
```

### Example 2: Inheritance with Constructor Functions

```javascript
function Animal(type) {
  this.type = type;
}

Animal.prototype.info = function() {
  return `This is a ${this.type}.`;
};

function Dog(name) {
  Animal.call(this, 'dog');
  this.name = name;
}

Dog.prototype = Object.create(Animal.prototype);
Dog.prototype.constructor = Dog;

Dog.prototype.bark = function() {
  return `${this.name} barks!`;
};

let buddy = new Dog("Buddy");
console.log(buddy.info()); // "This is a dog."
console.log(buddy.bark()); // "Buddy barks!"
```

### Example 3: Using ES6 Classes

```javascript
class Vehicle {
  constructor(wheels) {
    this.wheels = wheels;
  }
  describe() {
    return `A vehicle with ${this.wheels} wheels.`;
  }
}

class Car extends Vehicle {
  constructor(brand) {
    super(4);
    this.brand = brand;
  }
  honk() {
    return `${this.brand} goes beep beep!`;
  }
}

let myCar = new Car("Toyota");
console.log(myCar.describe()); // "A vehicle with 4 wheels."
console.log(myCar.honk());     // "Toyota goes beep beep!"
```

---

## 9. Further Reading and Resources

- [MDN Web Docs: Working with objects](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Working_with_Objects)
- [MDN: Object prototypes](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Objects/Object_prototypes)
- [Eloquent JavaScript – Chapter on Objects and Prototypes](https://eloquentjavascript.net/06_object.html)
- [Understanding Prototypal Inheritance on JavaScript.info](https://javascript.info/prototype-inheritance)

By studying and experimenting with these examples, you’ll gain a deeper understanding of how prototypes work in JavaScript, how to use them effectively for inheritance, and how to debug prototype-related issues. Happy coding!

---





function Person(name) {
  this.name = name;
}

Person.prototype.sayName = function() {
  console.log(`Hello, I'm ${this.name}!`);
};

function Player(name, marker) {
  this.name = name;
  this.marker = marker;
}

Player.prototype.getMarker = function() {
  console.log(`My marker is '${this.marker}'`);
};

Object.getPrototypeOf(Player.prototype); // returns Object.prototype

// Now make `Player` objects inherit from `Person`
Object.setPrototypeOf(Player.prototype, Person.prototype);
Object.getPrototypeOf(Player.prototype); // returns Person.prototype

const player1 = new Player('steve', 'X');
const player2 = new Player('also steve', 'O');

player1.sayName(); // Hello, I'm steve!
player2.sayName(); // Hello, I'm also steve!

player1.getMarker(); // My marker is 'X'
player2.getMarker(); // My marker is 'O'


Though it seems to be an easy way to set up Prototypal Inheritance using Object.setPrototypeOf(), the prototype chain has to be set up using this function before creating any objects. Using setPrototypeOf() after objects have already been created can result in performance issues.



function Person(name) {
  this.name = name;
}

Person.prototype.sayName = function() {
  console.log(`Hello, I'm ${this.name}!`);
};

function Player(name, marker) {
  this.name = name;
  this.marker = marker;
}

// Don't do this!
// Use Object.setPrototypeOf(Player.prototype, Person.prototype)
Player.prototype = Person.prototype;

function Enemy(name) {
  this.name = name;
  this.marker = '^';
}

// Not again!
// Use Object.setPrototypeOf(Enemy.prototype, Person.prototype)
Enemy.prototype = Person.prototype;

Enemy.prototype.sayName = function() {
  console.log('HAHAHAHAHAHA');
};

const carl = new Player('carl', 'X');
carl.sayName(); // Uh oh! this logs "HAHAHAHAHAHA" because we edited the sayName function! 