Objects

Objects have
• Properties (analogous to adjectives)
• Methods (like verbs in a sentence)
• Events: Turning the ignition key results in the car starting event.


The object type is special.
All other types are called “primitive” because their values can contain only a single thing (be it a
string or a number or whatever). In contrast, objects are used to store collections of data and
more complex entities.


Some of the objects you’ll be using are part of the language specification: the String object, the Date object, and the Math object, for example. These objects are usually referred to as core objects because they are independent of the implementation. The browser also makes itself available for programming through objects you can use to obtain information about the browser and to change the look and feel of the application. For example, the browser makes available the Document object, which represents a web page available to JavaScript.

For now, all you need to know is that objects in JavaScript are entities you can use to add functionality to web pages, and that they can have properties and methods.





JavaScript objects can be thought of as simple collections of name-value pairs. As such, they are similar to:

    Dictionaries in Python.
    Hashes in Perl and Ruby.
    Hash tables in C and C++.
    HashMaps in Java.
    Associative arrays in PHP.

The fact that this data structure is so widely used is a testament to its versatility. Since everything (bar core types) in JavaScript is an object, any JavaScript program naturally involves a great deal of hash table lookups. It's a good thing they're so fast!

The "name" part is a JavaScript string, while the value can be any JavaScript value — including more objects. This allows you to build data structures of arbitrary complexity.

There are two basic ways to create an empty object:

var obj = new Object();

And:

var obj = {};

These are semantically equivalent; the second is called object literal syntax and is more convenient. This syntax is also the core of JSON format and should be preferred at all times.

Object literal syntax can be used to initialize an object in its entirety:

var obj = {
  name: 'Carrot',
  _for: 'Max', // 'for' is a reserved word, use '_for' instead.
  details: {
    color: 'orange',
    size: 12
  }
};

Attribute access can be chained together:

obj.details.color; // orange
obj['details']['size']; // 12

The following example creates an object prototype(Person) and an instance of that prototype(you).

function Person(name, age) {
  this.name = name;
  this.age = age;
}

// Define an object
var you = new Person('You', 24);
// We are creating a new person named "You" aged 24.

Once created, an object's properties can again be accessed in one of two ways:

// dot notation
obj.name = 'Simon';
var name = obj.name;

And...

// bracket notation
obj['name'] = 'Simon';
var name = obj['name'];
// can use a variable to define a key
var user = prompt('what is your key?')
obj[user] = prompt('what is its value?')

These are also semantically equivalent. The second method has the advantage that the name of the property is provided as a string, which means it can be calculated at run-time. However, using this method prevents some JavaScript engine and minifier optimizations being applied. It can also be used to set and get properties with names that are reserved words:

obj.for = 'Simon'; // Syntax error, because 'for' is a reserved word
obj['for'] = 'Simon'; // works fine










In classic Object Oriented Programming, objects are collections of data and methods that operate on that data. JavaScript is a prototype-based language that contains no class statement, as you'd find in C++ or Java (this is sometimes confusing for programmers accustomed to languages with a class statement). Instead, JavaScript uses functions as classes. Let's consider a person object with first and last name fields. There are two ways in which the name might be displayed: as "first last" or as "last, first". Using the functions and objects that we've discussed previously, we could display the data like this:

function makePerson(first, last) {
  return {
    first: first,
    last: last
  };
}
function personFullName(person) {
  return person.first + ' ' + person.last;
}
function personFullNameReversed(person) {
  return person.last + ', ' + person.first;
}

var s = makePerson('Simon', 'Willison');
personFullName(s); // "Simon Willison"
personFullNameReversed(s); // "Willison, Simon"

This works, but it's pretty ugly. You end up with dozens of functions in your global namespace. What we really need is a way to attach a function to an object. Since functions are objects, this is easy:

function makePerson(first, last) {
  return {
    first: first,
    last: last,
    fullName: function() {
      return this.first + ' ' + this.last;
    },
    fullNameReversed: function() {
      return this.last + ', ' + this.first;
    }
  };
}

var s = makePerson('Simon', 'Willison');
s.fullName(); // "Simon Willison"
s.fullNameReversed(); // "Willison, Simon"

Note on the this keyword. Used inside a function, this refers to the current object. What that actually means is specified by the way in which you called that function. If you called it using dot notation or bracket notation on an object, that object becomes this. If dot notation wasn't used for the call, this refers to the global object.

Note that this is a frequent cause of mistakes. For example:

var s = makePerson('Simon', 'Willison');
var fullName = s.fullName;
fullName(); // undefined undefined

When we call fullName() alone, without using s.fullName(), this is bound to the global object. Since there are no global variables called first or last we get undefined for each one.

We can take advantage of the this keyword to improve our makePerson function:

function Person(first, last) {
  this.first = first;
  this.last = last;
  this.fullName = function() {
    return this.first + ' ' + this.last;
  };
  this.fullNameReversed = function() {
    return this.last + ', ' + this.first;
  };
}
var s = new Person('Simon', 'Willison');

We have introduced another keyword: new. new is strongly related to this. It creates a brand new empty object, and then calls the function specified, with this set to that new object. Notice though that the function specified with this does not return a value but merely modifies the this object. It's new that returns the this object to the calling site. Functions that are designed to be called by new are called constructor functions. Common practice is to capitalize these functions as a reminder to call them with new.

The improved function still has the same pitfall with calling fullName() alone.

Our person objects are getting better, but there are still some ugly edges to them. Every time we create a person object we are creating two brand new function objects within it — wouldn't it be better if this code was shared?

function personFullName() {
  return this.first + ' ' + this.last;
}
function personFullNameReversed() {
  return this.last + ', ' + this.first;
}
function Person(first, last) {
  this.first = first;
  this.last = last;
  this.fullName = personFullName;
  this.fullNameReversed = personFullNameReversed;
}

That's better: we are creating the method functions only once, and assigning references to them inside the constructor. Can we do any better than that? The answer is yes:

function Person(first, last) {
  this.first = first;
  this.last = last;
}
Person.prototype.fullName = function() {
  return this.first + ' ' + this.last;
};
Person.prototype.fullNameReversed = function() {
  return this.last + ', ' + this.first;
};

Person.prototype is an object shared by all instances of Person. It forms part of a lookup chain (that has a special name, "prototype chain"): any time you attempt to access a property of Person that isn't set, JavaScript will check Person.prototype to see if that property exists there instead. As a result, anything assigned to Person.prototype becomes available to all instances of that constructor via the this object.

This is an incredibly powerful tool. JavaScript lets you modify something's prototype at any time in your program, which means you can add extra methods to existing objects at runtime:

var s = new Person('Simon', 'Willison');
s.firstNameCaps(); // TypeError on line 1: s.firstNameCaps is not a function

Person.prototype.firstNameCaps = function() {
  return this.first.toUpperCase();
};
s.firstNameCaps(); // "SIMON"

Interestingly, you can also add things to the prototype of built-in JavaScript objects. Let's add a method to String that returns that string in reverse:

var s = 'Simon';
s.reversed(); // TypeError on line 1: s.reversed is not a function

String.prototype.reversed = function() {
  var r = '';
  for (var i = this.length - 1; i >= 0; i--) {
    r += this[i];
  }
  return r;
};

s.reversed(); // nomiS

Our new method even works on string literals!

'This can now be reversed'.reversed(); // desrever eb won nac sihT

As mentioned before, the prototype forms part of a chain. The root of that chain is Object.prototype, whose methods include toString() — it is this method that is called when you try to represent an object as a string. This is useful for debugging our Person objects:

var s = new Person('Simon', 'Willison');
s.toString(); // [object Object]

Person.prototype.toString = function() {
  return '<Person: ' + this.fullName() + '>';
}

s.toString(); // "<Person: Simon Willison>"

Remember how avg.apply() had a null first argument? We can revisit that now. The first argument to apply() is the object that should be treated as 'this'. For example, here's a trivial implementation of new:

function trivialNew(constructor, ...args) {
  var o = {}; // Create an object
  constructor.apply(o, args);
  return o;
}

This isn't an exact replica of new as it doesn't set up the prototype chain (it would be difficult to illustrate). This is not something you use very often, but it's useful to know about. In this snippet, ...args (including the ellipsis) is called the "rest arguments" — as the name implies, this contains the rest of the arguments.

Calling

var bill = trivialNew(Person, 'William', 'Orange');

is therefore almost equivalent to

var bill = new Person('William', 'Orange');

apply() has a sister function named call, which again lets you set this but takes an expanded argument list as opposed to an array.

function lastNameCaps() {
  return this.last.toUpperCase();
}
var s = new Person('Simon', 'Willison');
lastNameCaps.call(s);
// Is the same as:
s.lastNameCaps = lastNameCaps;
s.lastNameCaps(); // WILLISON
