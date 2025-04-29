## Factory Functions

A **factory function** is a function that creates, configures, and returns an object. 

Unlike constructors or classes, a factory function is a regular function that returns a new object. This technique is especially useful when you want to centralize or customize the instantiation process, handle complex configuration, or simply avoid the verbosity or constraints of class-based inheritance.

factory functions are often used in place of constructors because they can return any kind of object (including instances of different types), handle default values, enforce immutability, or even create private states via closures.

Factory functions abstract away the process of object creation from the rest of your code, which can improve readability and maintainability.


### Simple Factory Function Example

```js
function createPerson(name, age) {
  return {
    name: name,
    age: age,
    greet() {
      console.log(`Hi, I'm ${this.name} and I'm ${this,age} years old.`);
    }
  };
}

const person = createPerson('Alice', 30);
person.greet();  // Output: Hi, I'm Alice and I'm 30 years old.
```

**Key Points:**
- The function `createPerson` encapsulates object creation.
- There’s no need to use the `new` keyword, reducing the chance of misusing object construction.
- It can easily validate or modify input before constructing the object.

---

## Common Uses of factory functions

### A. Encapsulation of Object Creation

factory functions centralize the creation logic so that if the instantiation process changes, you only need to update the factory. For example, if you later decide to add additional properties or default behaviors, you can modify the factory without altering every part of your code that creates an object.

### B. Hiding Complex Logic

When objects need to be configured in complex ways based on input data, a factory function can manage that complexity:

```js
function createCar(options) {
  const car = {
    model: options.model || 'Generic Model',
    color: options.color || 'white',
    wheels: options.wheels || 4,
    drive() {
      console.log(`Driving a ${this.color} ${this.model} with ${this.wheels} wheels.`);
    }
  };
  // Additional configuration or validation can happen here.
  return car;
}

const myCar = createCar({ model: 'Sedan', color: 'red' });
myCar.drive();  // Output: Driving a red Sedan with 4 wheels.
```

### C. Managing Object Variability

A factory can return different types of objects based on certain conditions:

```js
function createShape(type, options) {
  if (type === 'circle') {
    return {
      type: 'circle',
      radius: options.radius,
      draw() {
        console.log(`Drawing a circle with radius ${this.radius}`);
      }
    };
  } else if (type === 'rectangle') {
    return {
      type: 'rectangle',
      width: options.width,
      height: options.height,
      draw() {
        console.log(`Drawing a rectangle with width ${this.width} and height ${this.height}`);
      }
    };
  } else {
    throw new Error('Shape type not supported.');
  }
}

const circle = createShape('circle', { radius: 5 });
circle.draw();  // Output: Drawing a circle with radius 5
```

### D. Creating Private State (Closure-based Factories)

Factory functions can enclose private data with closures, exposing only selected methods and properties:

```js
function createCounter() {
  let count = 0;  // Private variable

  return {
    increment() {
      count++;
      return count;
    },
    decrement() {
      count--;
      return count;
    },
    getCount() {
      return count;
    }
  };
}

const counter = createCounter();
console.log(counter.increment());  // Output: 1
console.log(counter.getCount());   // Output: 1
```

---

## Typical Pitfalls and How to Avoid or Resolve Them

Despite their flexibility and utility, factory functions can lead to common pitfalls if not applied carefully.

### A. Pitfall: Method Re-Creation and Memory Overhead

#### **Issue:**
When methods are defined inside a factory function, each time the function is called, new copies of these methods are created. This can lead to a higher memory footprint if many objects are created.

#### **Solution:**
Use a shared prototype (or an external helper object) to define methods so that they are not recreated for each instance.

#### **Example Without Optimization:**

```js
function createAnimal(name) {
  return {
    name,
    speak() {
      console.log(`${name} makes a noise.`);
    }
  };
}

const animal1 = createAnimal('Dog');
const animal2 = createAnimal('Cat');
// `speak` is re-created for every object.
```

#### **Optimized Example Using a Shared Prototype:**

```js
const animalMethods = {
  speak() {
    console.log(`${this.name} makes a noise.`);
  }
};

function createAnimal(name) {
  const animal = Object.create(animalMethods);
  animal.name = name;
  return animal;
}

const animal1 = createAnimal('Dog');
const animal2 = createAnimal('Cat');

animal1.speak();  // Output: Dog makes a noise.
animal2.speak();  // Output: Cat makes a noise.
```

By using `Object.create(animalMethods)`, the `speak` method is shared across all instances.

### B. Pitfall: Improper Handling of `this` in Factories

#### **Issue:**
When using factory functions, especially if arrow functions are involved, there is a risk of losing the proper `this` context. Arrow functions do not bind their own `this`, which can be problematic when trying to refer to the current object.

#### **Solution:**
Avoid arrow functions for methods that rely on `this`. Instead, use regular function expressions or method shorthand syntax.

#### **Example of the Pitfall:**

```js
function createUser(name) {
  return {
    name,
    greet: () => {
      console.log(`Hello, ${this.name}`);  // 'this' does not refer to the returned object
    }
  };
}

const user = createUser('Bob');
user.greet();  // Output: "Hello, undefined"
```

#### **Corrected Version:**

```js
function createUser(name) {
  return {
    name,
    greet() {
      console.log(`Hello, ${this.name}`);
    }
  };
}

const user = createUser('Bob');
user.greet();  // Output: "Hello, Bob"
```

### C. Pitfall: Lack of Input Validation

#### **Issue:**
factory functions might be misused if you pass invalid or unexpected data, leading to runtime errors or poorly constructed objects.

#### **Solution:**
Incorporate input validation within the factory function to ensure that passed parameters meet the expected criteria.

#### **Example with Validation:**

```js
function createBook(title, author) {
  if (typeof title !== 'string' || typeof author !== 'string') {
    throw new Error('Invalid input: title and author must be strings.');
  }

  return {
    title,
    author,
    displayInfo() {
      console.log(`Title: ${this.title}, Author: ${this.author}`);
    }
  };
}

try {
  const book = createBook('1984', 123);  // 123 is not a valid author
  book.displayInfo();
} catch (error) {
  console.error(error.message);  // Output: Invalid input: title and author must be strings.
}
```

### D. Pitfall: Overuse of Factories

#### **Issue:**
While factories are powerful, overusing them for simple objects or where a constructor or class might be more straightforward can lead to unnecessarily complex code.

#### **Solution:**
Assess the complexity of the object creation and decide if a simple literal or a class-based approach would be more readable and maintainable. For instance, ECMAScript 2015 (ES6) classes often provide syntactic clarity for object creation and inheritance.

#### **Comparison Example:**

**factory function:**

```js
function createPoint(x, y) {
  return {
    x,
    y,
    display() {
      console.log(`Point at (${this.x}, ${this.y})`);
    }
  };
}
```

**ES6 Class Approach:**

```js
class Point {
  constructor(x, y) {
    this.x = x;
    this.y = y;
  }

  display() {
    console.log(`Point at (${this.x}, ${this.y})`);
  }
}

const point = new Point(5, 10);
point.display();  // Output: Point at (5, 10)
```

In simpler scenarios, the class-based approach can be more intuitive.

---

## 5. Additional Advanced Techniques

### A. Using Closures for Private Variables

Factory functions can leverage closures to create private state:

```js
function createCounter() {
  let count = 0;  // This variable is private and cannot be accessed directly.

  return {
    increment() {
      count += 1;
      return count;
    },
    decrement() {
      count -= 1;
      return count;
    },
    getCount() {
      return count;
    }
  };
}

const counter = createCounter();
console.log(counter.increment());  // Output: 1
console.log(counter.getCount());   // Output: 1
```

### B. Configurable and Extendable Factories

A flexible factory function can take configuration objects to modify behavior, making your object creation even more dynamic.

```js
function createLogger(options = {}) {
  const { level = 'info', prefix = '' } = options;

  return {
    log(message) {
      console.log(`${prefix}[${level}] ${message}`);
    },
    error(message) {
      if (level === 'error' || level === 'debug') {
        console.error(`${prefix}[ERROR] ${message}`);
      }
    }
  };
}

const logger = createLogger({ level: 'debug', prefix: 'MyApp ' });
logger.log('Application started');  // Output: MyApp [debug] Application started
```

This pattern allows you to easily introduce additional customization without altering the core object creation logic.

---

## 6. Conclusion

JavaScript factory functions offer a versatile, flexible approach to object creation. They enable better encapsulation of instantiation logic, streamline the creation of complex objects, and allow for dynamic behavior based on inputs. While they have many benefits, be mindful of potential pitfalls such as unnecessary method re-creation, improper `this` binding, poor input validation, or overcomplicating your design when simpler approaches might suffice.








Prototypal inheritance with factories

Factory functions can use prototype and inheritance to give our objects access to the properties of another.
This example extend a User factory into a Player factory:

```js
function createPlayer (name, level) {
  const { getReputation, giveReputation } = createUser(name);

  const increaseLevel = () => level++;
  return { name, getReputation, giveReputation, increaseLevel };
}
```
And there you go! You can create your User, extract what you need from it, and re-return whatever you want to - hiding the rest as some private variables or functions! In case you want to extend it, you can also use the Object.assign method to add on the properties you want!

```js
function createPlayer (name, level) {
  const user = createUser(name);

  const increaseLevel = () => level++;
  return Object.assign({}, user, { increaseLevel });
}
```