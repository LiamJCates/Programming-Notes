Classes

JavaScript offers many programming paradigms, and object‑oriented programming is one of them. Everything in JavaScript is an object, including functions. Modern JavaScript also added support for the class syntax.

A class is a template or blueprint for you to define shared structure and behavior between similar objects.

You can define new classes, make them extend other classes, and instantiate objects out of them using the new keyword, You can customize the construction of every object and define shared functions between these objects. Here's a standard class example that demonstrate all these features.
```js
class Person {
  constructor(name) {
    this.name = name;
  }
  greet() {
    console.log(`Hello ${this.name}!`);
  }
}

class Student extends Person {
  constructor(name, level) {
    super(name);
    this.level = level;
  }
  greet() {
    console.log(`Hello ${this.name} from ${this.level}`);
  }
}
```
We have a Person class and a Student class that extends the Person class. Every student is also a person. Both classes define a constructor function. The constructor function is a special one that gets called every time we instantiate an object out of the class, which we do using the new keyword:
```js
const o1 = new Person("Max");
const o2 = new Student("Tina", "1st Grade");
const o3 = new Student("Mary", "2nd Grade");
o3.greet = () => console.log('I am special!');

o1.greet();
o2.greet();
o3.greet();
```
We are instantiating one object from the Person class and two other objects from the Student class. The arguments we pass here when we instantiate these objects are accessible in the constructor function of the class. The Person class expects a name argument, and it stores that value on the instance using the this keyword here. The Student class expects a name argument and the level argument. It stores the level value on its instance, and since it extends the Person class, it will call the super method with the name argument, which will invoke the Person class constructor function and store the name as well. Both classes defined a greet function that uses the values they store on each instance. In the third object, which we instantiated from the Student class here, I also defined a greet function directly on the object. When we test this script, o1 will use the greet method from its class, the Person class, o2 will use the great method from the Student class, and o3 will use its own directly defined greet method.
