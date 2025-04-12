There are eight data types in JavaScript. Seven of them are called “primitive”, because their values contain only a single thing (be it a string or a number or whatever).

In contrast, objects are used to store keyed collections.

An object is a collection of related data and/or functionality. These usually consist of several variables and functions (which are called properties and methods when they are inside objects).

An object can be created with figure brackets {…} with an optional list of properties. A property is a “key: value” pair, where key is a string (also called a “property name”), and value can be anything.

An empty object can be created using one of two syntaxes:

let user = new Object(); // "object constructor" syntax
let user = {};  // "object literal" syntax

 properties are represented as “key: value” pairs. A property has a key (also known as “name” or “identifier”) before the colon ":" and a value to the right of it.

let user = {     // an object
  name: "John",  // by key "name" store value "John"
  age: 30        // by key "age" store value 30
};


Dot notation

Property values are accessible using the dot notation:

The object name acts as the namespace — it must be entered first to access anything inside the object. Next you write a dot, then the item you want to access — this can be the name of a simple property, an item of an array property, or a call to one of the object's methods

// get property values of the object:
alert( user.name ); // John
alert( user.age ); // 30


Objects as object properties

An object property can itself be an object. For example, try changing the name member from

```js
const person = {
  name: ["Bob", "Smith"],
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
``
To access these items you just need to chain the extra step onto the end with another dot. Try these in the JS console:

```js
person.name.first;
person.name.last;
```

You can instead use square brackets:

```js
person["age"];
person["name"]["first"];
```

To remove a property, we can use the delete operator:

delete user.age;


We can also use multiword property names, but then they must be quoted:

let user = {
  name: "John",
  age: 30,
  "likes birds": true  // multiword property name must be quoted
};


The last property in the list may end with a comma:

let user = {
  name: "John",
  age: 30,
}

That is called a “trailing” or “hanging” comma. Makes it easier to add/remove/move around properties, because all lines become alike, most noticable when viewing a git diff.

For multiword properties, the dot access doesn’t work:

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

Now everything is fine. Please note that the string inside the brackets is properly quoted (any type of quotes will do).

Square brackets also provide a way to obtain the property name as the result of any expression – as opposed to a literal string – like from a variable as follows:

let key = "likes birds";

// same as user["likes birds"] = true;
user[key] = true;


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


Property value shorthand

In real code, we often use existing variables as values for property names.

```js
function makeUser(name, age) {
  return {
    name: name,
    age: age,
    // ...other properties
  };
}

let user = makeUser("John", 30);
alert(user.name); // John

//The use-case of making a property from a variable is so common, that there’s a special property value shorthand to make it shorter.

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

Property names limitations

A variable cannot have a name equal to one of the language-reserved words.
An object property has no such restriction:

```js
// these properties are all right
let obj = {
  for: 1,
  let: 2,
  return: 3
};

alert( obj.for + obj.let + obj.return );  // 6
```
In short, there are no limitations on property names. They can be any strings or symbols.

Other types are automatically converted to strings.
```js
let obj = {
  0: "test" // same as "0": "test"
};

// both alerts access the same property (the number 0 is converted to string "0")
alert( obj["0"] ); // test
alert( obj[0] ); // test (same property)
```
There’s a minor gotcha with a special property named __proto__. We can’t set it to a non-object value:
```js
let obj = {};
obj.__proto__ = 5; // assign a number
alert(obj.__proto__); // [object Object] - the value is an object, didn't work as intended
//The assignment to a primitive 5 is ignored.
```

### Property existence test, “in” operator


A notable feature of objects in JavaScript, compared to many other languages, is that it’s possible to access any property. There will be no error if the property doesn’t exist!

Reading a non-existing property just returns undefined. So we can easily test whether the property exists:

let user = {};

alert( user.noSuchProperty === undefined ); // true means "no such property"

There’s also a special operator "in" for that.

The syntax is:

"key" in object

For instance:

let user = { name: "John", age: 30 };

alert( "age" in user ); // true, user.age exists
alert( "blabla" in user ); // false, user.blabla doesn't exist

Please note that on the left side of in there must be a property name. That’s usually a quoted string.

If we omit quotes, that means a variable should contain the actual name to be tested. For instance:

let user = { age: 30 };

let key = "age";
alert( key in user ); // true, property "age" exists

Why does the in operator exist? Isn’t it enough to compare against undefined?

Well, most of the time the comparison with undefined works fine. But there’s a special case when it fails, but "in" works correctly.

It’s when an object property exists, but stores undefined:

let obj = {
  test: undefined
};

alert( obj.test ); // it's undefined, so - no such property?

alert( "test" in obj ); // true, the property does exist!

In the code above, the property obj.test technically exists. So the in operator works right.

Situations like this happen very rarely, because undefined should not be explicitly assigned.

### The "for..in" loop

To walk over all keys of an object, there exists a special form of the loop: for..in. 

let user = {
  name: "John",
  age: 30,
  isAdmin: true
};

for (let key in user) {
  // keys
  alert( key );  // name, age, isAdmin
  // values for the keys
  alert( user[key] ); // John, 30, true
}

Note that all “for” constructs allow us to declare the looping variable inside the loop, like let key here.


### Property Order

Are objects ordered? In other words, if we loop over an object, do we get all properties in the same order they were added? Can we rely on this?

The short answer is: “ordered in a special fashion”: integer properties are sorted, others appear in creation order. 

```js
let codes = {
  "49": "Germany",
  "41": "Switzerland",
  "44": "Great Britain",
  // ..,
  "1": "USA"
};

for (let code in codes) {
  alert(code); // 1, 41, 44, 49
}
```

The “integer property” term here means a string that can be converted to-and-from an integer without a change.

So, "49" is an integer property name, because when it’s transformed to an integer number and back, it’s still the same. But "+49" and "1.2" are not

On the other hand, if the keys are non-integer, then they are listed in the creation order, for instance:

```js
let user = {
  name: "John",
  surname: "Smith"
};
user.age = 25; // add one more

// non-integer properties are listed in the creation order
for (let prop in user) {
  alert( prop ); // name, surname, age
}
```

Summary

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



The this keyword typically refers to the current object the code is being executed in. In the context of an object method, this refers to the object that the method was called on.

```js
const person1 = {
  name: "Chris",
  introduceSelf() {
    console.log(`Hi! I'm ${this.name}.`);
  },
};

const person2 = {
  name: "Deepti",
  introduceSelf() {
    console.log(`Hi! I'm ${this.name}.`);
  },
};
```

In this case, person1.introduceSelf() outputs "Hi! I'm Chris."; person2.introduceSelf() outputs "Hi! I'm Deepti."


### Constructors

```js
function createPerson(name) {
  const obj = {};
  obj.name = name;
  obj.introduceSelf = function () {
    console.log(`Hi! I'm ${this.name}.`);
  };
  return obj;
}

const salva = createPerson("Salva");
salva.introduceSelf();
// "Hi! I'm Salva."

const frankie = createPerson("Frankie");
frankie.introduceSelf();
// "Hi! I'm Frankie."

```
This function creates and returns a new object each time we call it. The object will have two members:

    a property name
    a method introduceSelf().


```js
function Person(name) {
  this.name = name;
  this.introduceSelf = function () {
    console.log(`Hi! I'm ${this.name}.`);
  };
}

//To call Person() as a constructor, we use new:

const salva = new Person("Salva");
salva.introduceSelf();
// "Hi! I'm Salva."

const frankie = new Person("Frankie");
frankie.introduceSelf();
// "Hi! I'm Frankie."

```


Besides the formal differences, there are also some technical differences which affect how we use each data type. When you define a primitive variable, it will contain a copy of the information provided to it:
```js
let data = 42;
// dataCopy will store a copy of what data contains, so a copy of 42
let dataCopy = data;

// which means that making changes to dataCopy won't affect data
dataCopy = 43;

console.log(data); // 42
console.log(dataCopy); // 43
```
On the other hand, when you define an object variable, it will contain a reference to the object provided to it:
```js
// obj contains a reference to the object we defined on the right side
const obj = { data: 42 };
// objCopy will contain a reference to the object referenced by obj
const objCopy = obj;

// making changes to objCopy will make changes to the object that it refers to
objCopy.data = 43;

console.log(obj); // { data: 43 }
console.log(objCopy); // { data: 43 }
```

### Safeguarding constructors

Note that, as constructors are just regular functions, they could be called without using new by mistake, which would cause hard-to-track errors. To prevent that, you can use the new.target meta-property like this:

function Player(name, marker) {
  if (!new.target) {
    throw Error("You must use the 'new' operator to call the constructor");
  }
  this.name = name;
  this.marker = marker;
  this.sayName = function() {
    console.log(this.name)
  };
}

