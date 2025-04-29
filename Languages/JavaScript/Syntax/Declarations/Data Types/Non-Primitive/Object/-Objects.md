## Objects

There are eight data types in JavaScript. 
Seven of them are called “primitive”, because their values contain only a single thing (be it a string or a number or whatever).

In contrast, the eighth data type, the only non-primitive, are objects, which store keyed collections.

An object is a collection of related data and/or functionality. 

They consist of key-value pairs (called properties) where a key is a string or symbol and its associated value can be any JavaScript type (primitive, function, or another object).

An object's properties usually consist of several variables (called attributes) and functions (called methods).




https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object




The simplest method of object creation "object literal" or "object initializer" syntax

Here we make an empty person object
```js
let person = {};  
```


### Properties

An object has an optional list of properties.

Property keys are either strings or symbols. When other types (such as numbers) are used to index objects, the values are implicitly converted to strings.

### Dot notation

We can define and access properties using dot notation

Create an empty JavaScript object using {}, and define it's properties:
```js
// Create an Object
const person = {};

// Add Properties
person.name: "Bob Smith";
person.age = 50;
person.eyeColor = "blue";
```

The object name acts as the namespace — it must be entered first to access anything inside the object, then use a dot operator '.', and the name of the key we want to access.

```js
alert( person.name ); // Bob Smith
alert( person.age ); // 50
```



We can also add properties during creation of the object literal

A property is a “key: value” pair, where key is a string or symbol (also called a “property name”), and value can be anything.

A property key (also known as “name” or “identifier”) appears before the colon ":" and it's value to the right of it.

```js
let person = {     
  name: "Bob Smith", 
  age : 50,
  eyeColor : "blue"
};
```



An object property can itself be an object. For example, try changing the name member from

```js
const person = {
  name: "Bob Smith",
  // …
};
```
to

``` js
const person = {
  name: {
    first: "Bob",
    last: "Smith",
  },
  // …
};
```
To access these items you just need to chain the extra step onto the end with another dot.

```js
person.name.first;
person.name.last;
```



### Property Declaration Style

The last property in the list may end with a comma:

```js
let person = {     
  name: "Bob Smith", 
  age : 50,
  eyeColor : "blue",
};
```
That is called a “trailing” or “hanging” comma. Makes it easier to add/remove/move around properties, because all lines become alike, most noticable when viewing a git diff.





### Square Bracket Notation

To access or set properties, we can instead use square brackets:

```js

person.age = 45;
person["name"]["last"] = "Cratchit";

alert( person["age"] ); // 45
alert( person["name"]["first"] ); // Cratchit
```


#### Multiword Property

We can also use multiword property names, but then they must be quoted:

```js
let user = {
  name: "John",
  age: 30,
  "likes birds": true  // multiword property name must be quoted
};
```

For multiword properties, the dot access doesn’t work

```js
let user = {};

// set
user["likes birds"] = true;

// this would give a syntax error
user.likes birds = true

// get
alert(user["likes birds"]); // true

// delete
delete user["likes birds"];
```

Please note that the string inside the brackets is properly quoted (any type of quotes will do).



#### Computed Property Names

Square brackets also provide a way to obtain the property name as the result of any expression – as opposed to a literal string – like from a variable as follows:
```js
let key = "likes birds";

// same as user["likes birds"] = true;
user[key] = true;
```

Here, the variable key may be calculated at run-time or depend on the user input. And then we use it to access the property. That gives us a great deal of flexibility.

```js
let user = {
  name: "John",
  age: 30
};

let key = prompt("What do you want to know about the user?", "name");

// access by variable
alert( user[key] ); // John (if enter "name")

//The dot notation cannot be used in a similar way

let user = {
  name: "John",
  age: 30
};

let key = "name";
alert( user.key ) // undefined
```

We can use square brackets in an object literal, when creating an object. That’s called computed properties.

```js
let fruit = prompt("Which fruit to buy?", "apple");

let bag = {
  [fruit]: 5, // the name of the property is taken from the variable fruit
};

alert( bag.apple ); // 5 if fruit="apple"
```

We can use more complex expressions inside square brackets:

```js
let fruit = 'apple';
let bag = {
  [fruit + 'Computers']: 5 // bag.appleComputers = 5
};
```

Square brackets are much more powerful than dot notation. They allow any property names and variables. But they are also more cumbersome to write.



### Property Shorthand Notation

In real code, we often use existing variables as values for property names.

The use-case of making a property from a variable is so common, that there’s a special property value shorthand to make it shorter.

```js
function makeUser(name, age) {
  return {
    name, // same as name: name
    age,  // same as age: age
    // ...
  };
}

//We can use both normal properties and shorthands in the same object:

let user = {
  name,  // same as name:name
  age: 30
};
```



### Object shorthand notation

In 2015, a shortcut to creating objects was added to JavaScript. Say we wanted to create an object with a name, age, and color, we would write it as follows:

```js
const name = "Bob";
const age = 28;
const color = "red";

const thatObject = { name: name, age: age, color: color };
```

However, now, if we have a variable with the same name as that of the property to which we are assigning it, then we can write it once!
```js
const nowFancyObject = { name, age, color };

An added advantage to this is that it’s now possible to console.log values neatly!

// If you wanted to log these values, earlier,
// you would have done the following
console.log(name, age, color);
// which would have resulted in a mess - Bob 28 red

// Try wrapping it in some { curly braces } now,
// which makes it an object!
console.log({ name, age, color });
// now it logs as - { name: "Bob", age: 28, color: "red" }g           
```




### Property Descriptors and Attributes

Every object property has associated attributes that control how it behaves. These include:
- **Writable:** Can the property value be changed?
- **Enumerable:** Will the property show up during enumeration (e.g., in `for...in` loops)?
- **Configurable:** Can the property be deleted or its attributes modified?

You can inspect and modify these settings using methods like `Object.getOwnPropertyDescriptor()` and `Object.defineProperty()`.

```js
const book = {};
Object.defineProperty(book, 'title', {
  value: '1984',
  writable: false,       // Read-only property
  enumerable: true,      // Shows up in enumeration
  configurable: false    // Cannot be deleted or reconfigured
});

console.log(book.title);  // Output: 1984
// Attempting to change the title
book.title = 'Animal Farm';
console.log(book.title);  // Output remains: 1984
```





### Methods and the `this` Keyword

Methods are functions that are stored as object properties. 


Adding a method to a created object is easy:

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

const mySelf = new Person("Johnny", "Rally", 22, "green");



mySelf.changeName = function (name) {
  this.lastName = name;
}


mySelf.changeName("Bobby");

```

They can use the `this` keyword to refer to the object the method is called on.

```js
const calculator = {
  a: 10,
  b: 20,
  sum() {
    return this.a + this.b;
  }
};

console.log(calculator.sum());  // Output: 30
```





### Object Constructor Functions

Sometimes we need to create many objects of the same type.

To create an object type we use an object constructor function.

It is considered good practice to name constructor functions with an upper-case first letter.

```js
function Person(first, last, age, eye) {
  this.firstName = first;
  this.lastName = last;
  this.age = age;
  this.eyeColor = eye;
}
```





### JavaScript Object Methods

JavaScript Object Methods can be grouped into:

    General Methods
    Property Management Methods
    Object Protection Methods


#### General Methods

```js
// Copies properties from a source object to a target object
Object.assign(target, source)

// Creates an object from an existing object
Object.create(object)

// Returns an array of the key/value pairs of an object
Object.entries(object)

// Creates an object from a list of keys/values
Object.fromEntries()

// Returns an array of the keys of an object
Object.keys(object)

// Returns an array of the property values of an object
Object.values(object)

// Groups object elements according to a function
Object.groupBy(object, callback)
```

https://www.w3schools.com/js/js_object_methods.asp




### Property Management Methods


Dynamic: Objects in JavaScript are dynamic. You can add, change, or delete properties at runtime.



```js
// Adding or changing an object property
Object.defineProperty(object, property, descriptor)

// Adding or changing object properties
Object.defineProperties(object, descriptors)

// Accessing a Property
Object.getOwnPropertyDescriptor(object, property)

// Accessing Properties
Object.getOwnPropertyDescriptors(object)

// Returns all properties as an array
Object.getOwnPropertyNames(object)

// Accessing the prototype
Object.getPrototypeOf(object)
```

https://www.w3schools.com/js/js_object_properties.asp





### Object Protection Methods

```js
// Prevents re-assignment
const car = {type:"Fiat", model:"500", color:"white"};

// Prevents adding object properties
Object.preventExtensions(object)

// Returns true if properties can be added to an object
Object.isExtensible(object)

// Prevents adding and deleting object properties
Object.seal(object)

// Returns true if object is sealed
Object.isSealed(object)

// Prevents any changes to an object
Object.freeze(object)

// Returns true if object is frozen
Object.isFrozen(object)
```

https://www.w3schools.com/js/js_object_protection.asp



JavaScript Object.defineProperty()

The Object.defineProperty() method can be used to:

    Adding a new property to an object
    Changing property values
    Changing property metadata
    Changing object getters and setters

Syntax:

```js
Object.defineProperty(object, property, descriptor)
```

```js
// Create an Object:
const person = {
  firstName: "John",
  lastName : "Doe",
  language : "EN"
};

// Add a Property
Object.defineProperty(person, "year", {value:"2008"});

// Change a Property
Object.defineProperty(person, "language", {value : "NO"});
```


Property Attributes

All properties have a name. In addition they also have a value.

The value is one of the property's attributes.

Other attributes are: enumerable, configurable, and writable.

These attributes define how the property can be accessed (is it readable?, is it writable?)

In JavaScript, all attributes can be read, but only the value attribute can be changed (and only if the property is writable).



Getters and setters can also be changed:
// Defining a getter
get: function() { return language }
// Defining a setter
set: function(value) { language = value }

This example makes language read-only:
Object.defineProperty(person, "language", {writable:false});

This example makes language not enumerable:
Object.defineProperty(person, "language", {enumerable:false});
JavaScript getOwnPropertyNames()



The Object.getOwnPropertyNames() method can:

    List object properties

Syntax
Object.getOwnPropertyNames(object)
List all Object Properties

This example gets all properties of an object:
Example
// Create an Object
const person = {
  firstName: "John",
  lastName : "Doe",
  language : "EN"
};

// Get all Properties
Object.getOwnPropertyNames(person);

Object.getOwnPropertyNames() will also list properties that is not enumerable:




JavaScript Object.keys()

The Object.keys() method can:

    List enumerable object properties

Syntax
Object.keys(object)
List Enumerable Object Properties

This example uses Object.keys() insted of Object.getOwnPropertyNames():
Example
// Create an Object
const person = {
  firstName: "John",
  lastName : "Doe",
  language : "EN"
};

// Change the "language" Property
Object.defineProperty(person, "language", {enumerable:false});

// Get all Enumerable Properties
Object.keys(person);
Note

The getOwnPropertyNames() method returns all properties.

The Object.keys() method returns all enumerable properties.

If you define object properties without enumerable:false, the two methods will return the same.
Adding Getters and Setters

The Object.defineProperty() method can also be used to add Getters and Setters:
Example
//Create an object
const person = {firstName:"John", lastName:"Doe"};

// Define a getter
Object.defineProperty(person, "fullName", {
  get: function () {return this.firstName + " " + this.lastName;}
});
A Counter Example
Example
// Define object
const obj = {counter:0};

// Define setters
Object.defineProperty(obj, "reset", {
  get : function () {this.counter = 0;}
});
Object.defineProperty(obj, "increment", {
  get : function () {this.counter++;}
});
Object.defineProperty(obj, "decrement", {
  get : function () {this.counter--;}
});
Object.defineProperty(obj, "add", {
  set : function (value) {this.counter += value;}
});
Object.defineProperty(obj, "subtract", {
  set : function (i) {this.counter -= i;}
});

// Play with the counter:
obj.reset;
obj.add = 5;
obj.subtract = 1;
obj.increment;
obj.decrement;
Prototype Properties

JavaScript objects inherit the properties of their prototype.

The delete keyword does not delete inherited properties, but if you delete a prototype property, it will affect all objects inherited from the prototype.


#### Delete

To remove a property, we can use the delete operator:
```js
delete user.age;
```






### Accessor descriptors

Descriptors for accessor properties are different from those for data properties.

For accessor properties, there is no value or writable, but instead there are get and set functions.

That is, an accessor descriptor may have:

    get – a function without arguments, that works when a property is read,
    set – a function with one argument, that is called when the property is set,
    enumerable – same as for data properties,
    configurable – same as for data properties.

For instance, to create an accessor fullName with defineProperty, we can pass a descriptor with get and set:

let user = {
  name: "John",
  surname: "Smith"
};

Object.defineProperty(user, 'fullName', {
  get() {
    return `${this.name} ${this.surname}`;
  },

  set(value) {
    [this.name, this.surname] = value.split(" ");
  }
});

alert(user.fullName); // John Smith

for(let key in user) alert(key); // name, surname

Please note that a property can be either an accessor (has get/set methods) or a data property (has a value), not both.

If we try to supply both get and value in the same descriptor, there will be an error:

// Error: Invalid property descriptor.
Object.defineProperty({}, 'prop', {
  get() {
    return 1
  },

  value: 2
});


### Smarter getters/setters

Getters/setters can be used as wrappers over “real” property values to gain more control over operations with them.

For instance, if we want to forbid too short names for user, we can have a setter name and keep the value in a separate property _name:

let user = {
  get name() {
    return this._name;
  },

  set name(value) {
    if (value.length < 4) {
      alert("Name is too short, need at least 4 characters");
      return;
    }
    this._name = value;
  }
};

user.name = "Pete";
alert(user.name); // Pete

user.name = ""; // Name is too short...

So, the name is stored in _name property, and the access is done via getter and setter.

Technically, external code is able to access the name directly by using user._name. But there is a widely known convention that properties starting with an underscore "_" are internal and should not be touched from outside the object.


### Using for compatibility

One of the great uses of accessors is that they allow to take control over a “regular” data property at any moment by replacing it with a getter and a setter and tweak its behavior.

Imagine we started implementing user objects using data properties name and age:

function User(name, age) {
  this.name = name;
  this.age = age;
}

let john = new User("John", 25);

alert( john.age ); // 25

…But sooner or later, things may change. Instead of age we may decide to store birthday, because it’s more precise and convenient:

function User(name, birthday) {
  this.name = name;
  this.birthday = birthday;
}

let john = new User("John", new Date(1992, 6, 1));

Now what to do with the old code that still uses age property?

We can try to find all such places and fix them, but that takes time and can be hard to do if that code is used by many other people. And besides, age is a nice thing to have in user, right?

Let’s keep it.

Adding a getter for age solves the problem:

function User(name, birthday) {
  this.name = name;
  this.birthday = birthday;

  // age is calculated from the current date and birthday
  Object.defineProperty(this, "age", {
    get() {
      let todayYear = new Date().getFullYear();
      return todayYear - this.birthday.getFullYear();
    }
  });
}

let john = new User("John", new Date(1992, 6, 1));

alert( john.birthday ); // birthday is available
alert( john.age );      // ...as well as the age

Now the old code works too and we’ve got a nice additional property.









There are two types of object properties: The data property and the accessor property. Each property has corresponding attributes. Each attribute is accessed internally by the JavaScript engine, but you can set them through Object.defineProperty(), or read them through Object.getOwnPropertyDescriptor(). 


#### Data property

Data properties associate a key with a value. 

Data properties have the following attributes:

value

    The value retrieved by a get access of the property. Can be any JavaScript value.
writable

    A boolean value indicating if the property can be changed with an assignment.
enumerable

    A boolean value indicating if the property can be enumerated by a for...in loop. See also Enumerability and ownership of properties for how enumerability interacts with other functions and syntaxes.
configurable

    A boolean value indicating if the property can be deleted, can be changed to an accessor property, and can have its attributes changed.




#### Accessor property

Associates a key with one of two accessor functions (get and set) to retrieve or store a value.

Note: It's important to recognize it's accessor property — not accessor method. We can give a JavaScript object class-like accessors by using a function as a value — but that doesn't make the object a class.


An accessor property has the following attributes:

get

    A function called with an empty argument list to retrieve the property value whenever a get access to the value is performed. See also getters. May be undefined.
set

    A function called with an argument that contains the assigned value. Executed whenever a specified property is attempted to be changed. See also setters. May be undefined.
enumerable

    A boolean value indicating if the property can be enumerated by a for...in loop. See also Enumerability and ownership of properties for how enumerability interacts with other functions and syntaxes.
configurable

    A boolean value indicating if the property can be deleted, can be changed to a data property, and can have its attributes changed.

The prototype of an object points to another object or to null — it's conceptually a hidden property of the object, commonly represented as [[Prototype]]. Properties of the object's [[Prototype]] can also be accessed on the object itself.












### Getters and setters

Accessor properties are represented by “getter” and “setter” methods. In an object literal they are denoted by get and set:

```js
let obj = {
  get propName() {
    // getter, the code executed on getting obj.propName
  },

  set propName(value) {
    // setter, the code executed on setting obj.propName = value
  }
};
```

The getter works when obj.propName is read, the setter – when it is assigned.

For instance, we have a user object with name and surname:
```js
let user = {
  name: "John",
  surname: "Smith"
};
```
Now we want to add a fullName property, that should be "John Smith". Of course, we don’t want to copy-paste existing information, so we can implement it as an accessor:

```js
let user = {
  name: "John",
  surname: "Smith",

  get fullName() {
    return `${this.name} ${this.surname}`;
  }
};

alert(user.fullName); // John Smith
```

From the outside, an accessor property looks like a regular one. That’s the idea of accessor properties. We don’t call user.fullName as a function, we read it normally: the getter runs behind the scenes.

As of now, fullName has only a getter. If we attempt to assign user.fullName=, there will be an error:
```js
let user = {
  get fullName() {
    return `...`;
  }
};

user.fullName = "Test"; // Error (property has only a getter)
```
Let’s fix it by adding a setter for user.fullName:
```js
let user = {
  name: "John",
  surname: "Smith",

  get fullName() {
    return `${this.name} ${this.surname}`;
  },

  set fullName(value) {
    [this.name, this.surname] = value.split(" ");
  }
};

// set fullName is executed with the given value.
user.fullName = "Alice Cooper";

alert(user.name); // Alice
alert(user.surname); // Cooper
```
As the result, we have a “virtual” property fullName. It is readable and writable.










### Recap

Objects are associative arrays with several special features.

They store properties (key-value pairs), where:

    Property keys must be strings or symbols (usually strings).
    Values can be of any type.

To access a property, we can use:

    The dot notation: obj.property.
    Square brackets notation obj["property"]. Square brackets allow taking the key from a variable, like obj[varWithKey].

Additional operators:

    To delete a property: delete obj.prop.
    To check if a property with the given key exists: "key" in obj.
    To iterate over an object: for (let key in obj) loop.

What we’ve studied in this chapter is called a “plain object”, or just Object.

There are many other kinds of objects in JavaScript:

    Array to store ordered data collections,
    Date to store the information about the date and time,
    Error to store the information about an error.
    …And so on.


Sometimes people say something like “Array type” or “Date type”, but formally they are not types of their own, but belong to a single “object” data type. And they extend it in various ways.




Objects are ad-hoc key-value pairs, so they are often used as maps. However, there can be ergonomics, security, and performance issues. Use a Map for storing arbitrary data instead. The Map reference contains a more detailed discussion of the pros & cons between plain objects and maps for storing key-value associations.