## Objects

There are eight data types in JavaScript. 
Seven of them are called “primitive”, because their values contain only a single thing (be it a string or a number or whatever).

In contrast, the eighth data type, the only non-primitive, are objects, which store keyed collections of one or more values.

An object is a collection of related data and/or functionality. These usually consist of several variables and functions (which are called properties and methods when they are inside objects).


https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Object


An empty object can be created using one of two syntaxes:

```js
let user = new Object(); // "object constructor" syntax
let user = {};  // "object literal" syntax
```



### Properties

An object has an optional list of properties. 
A property is a “key: value” pair, where key is a string or symbol (also called a “property name”), and value can be anything.

A property key (also known as “name” or “identifier”) appears before the colon ":" and it's value to the right of it.
```js
let user = {     // an object
  name: "John",  // by key "name" store value "John"
  age: 30        // by key "age" store value 30
};
```

The last property in the list may end with a comma:

```js
let user = {
  name: "John",
  age: 30,
}
```
That is called a “trailing” or “hanging” comma. Makes it easier to add/remove/move around properties, because all lines become alike, most noticable when viewing a git diff.



### Function Returning Object

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
```



### Dot notation

Once an object has been defined, property values are accessible using the dot notation:

```js
alert( user.name ); // John
alert( user.age ); // 30
```
The object name acts as the namespace — it must be entered first to access anything inside the object. Next you write a dot, then the property you want to access.



An object property can itself be an object. For example, try changing the name member from

```js
const person = {
  name: ["Bob", "Smith"],
  age: 32
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



### Square Bracket Notation

You can instead use square brackets:

```js
person["age"];
person["name"]["first"];
```



### Setting object members

So far we've only looked at retrieving (or getting) object members — you can also set (update) the value of object members by declaring the member you want to set (using dot or bracket notation), like this:

```js
person.age = 45;
person["name"]["last"] = "Cratchit";
```


Setting members doesn't just stop at updating the values of existing properties and methods; you can also create completely new members. Try these in the JS console:

```js
person["eyes"] = "hazel";
person.farewell = function () {
  console.log("Bye everybody!");
};
```

You can now test out your new members:

```js
person["eyes"];
person.farewell();
// "Bye everybody!"
```



### Delete

To remove a property, we can use the delete operator:
```js
delete user.age;
```


### Multiword Property

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



### Property Name Rules

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



### Key From Expression

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

