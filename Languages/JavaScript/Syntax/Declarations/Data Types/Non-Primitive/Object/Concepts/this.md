What is this?

In JavaScript, the this keyword refers to an object.

The this keyword refers to different objects depending on how it is used:
In an object method, this refers to the object.

Alone, this refers to the global object.

In a function, this refers to the global object.
In a function, in strict mode, this is undefined.
In an event, this refers to the element that received the event.
Methods like call(), apply(), and bind() can refer this to any object.



this is not a variable. It is a keyword. You cannot change the value of this.


### This in Methods

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

This isn't hugely useful when you are writing out object literals by hand, as using the object's name (person1.name and person2.name) leads to the exact same result, but it will be essential when using constructors to create more than one object from a single object definition.



### this Alone

When used alone, this refers to the global object.

Because this is running in the global scope.

In a browser window the global object is [object Window]:

```js
let x = this; 
```


#### This in strict mode

 In strict mode, when used alone, this also refers to the global object:

```js
"use strict";
let x = this; 
```


#### this in a Function (Default)

In a function, the global object is the default binding for this.

In a browser window the global object is [object Window]:

```js
function myFunction() {
  return this;
}
```


#### this in a Function (Strict)

JavaScript strict mode does not allow default binding.

So, when used in a function, in strict mode, this is undefined.

```js
"use strict";
function myFunction() {
  return this;
}
```

#### this in Event Handlers

In HTML event handlers, this refers to the HTML element that received the event:

```js
<button onclick="this.style.display='none'">
  Click to Remove Me!
</button> 
```


#### Object Method Binding

In these examples, this is the person object:

```js
const person = {
  firstName  : "John",
  lastName   : "Doe",
  id         : 5566,
  myFunction : function() {
    return this;
  }
};
```




Explicit Function Binding

The `call()` and `apply()` methods are predefined JavaScript methods.

They can both be used to call an object method with another object as argument.

The example below calls person1.fullName with person2 as an argument, this refers to person2, even if fullName is a method of person1:

```js
const person1 = {
  fullName: function() {
    return this.firstName + " " + this.lastName;
  }
}

const person2 = {
  firstName:"John",
  lastName: "Doe",
}

// Return "John Doe":
person1.fullName.call(person2);
```

The call() method can accept arguments:

```js
const person = {
  fullName: function(city, country) {
    return this.firstName + " " + this.lastName + "," + city + "," + country;
  }
}

const person1 = {
  firstName:"John",
  lastName: "Doe"
}

person.fullName.call(person1, "Oslo", "Norway");
```



With the apply() method, you can write a method that can be used on different objects.

The apply() method is similar to the call() method.

```js
const person = {
  fullName: function() {
    return this.firstName + " " + this.lastName;
  }
}

const person1 = {
  firstName: "Mary",
  lastName: "Doe"
}

// This will return "Mary Doe":
person.fullName.apply(person1);
```

The Difference Between call() and apply() is:

The call() method takes arguments separately.

The apply() method takes arguments as an array.



```js
const person = {
  fullName: function(city, country) {
    return this.firstName + " " + this.lastName + "," + city + "," + country;
  }
}

const person1 = {
  firstName:"John",
  lastName: "Doe"
}

person.fullName.apply(person1, ["Oslo", "Norway"]);

//Compared with the call() method:
person.fullName.call(person1, "Oslo", "Norway");
```



The apply() method is very handy if you want to use an array instead of an argument list.

You can find the largest number (in a list of numbers) using the Math.max() method.

Since JavaScript arrays do not have a max() method, you can apply the Math.max() method instead.
```js
Math.max(1,2,3);  // Will return 3

Math.max.apply(null, [1,2,3]); // Will also return 3

// The first argument (null) does not matter.
// It is not used in this example.
// These examples will give the same result:

Math.max.apply(Math, [1,2,3]); // Will also return 3

Math.max.apply(" ", [1,2,3]); // Will also return 3

Math.max.apply(0, [1,2,3]); // Will also return 3
```


JavaScript Strict Mode

In JavaScript strict mode, if the first argument of the apply() method is not an object, it becomes the owner (object) of the invoked function. In "non-strict" mode, it becomes the global object.
















#### Function Borrowing

With the bind() method, an object can borrow a method from another object.

This example creates 2 objects (person and member).

The member object borrows the fullname method from the person object:

```js
const person = {
  firstName:"John",
  lastName: "Doe",
  fullName: function () {
    return this.firstName + " " + this.lastName;
  }
}

const member = {
  firstName:"Hege",
  lastName: "Nilsen",
}

let fullName = person.fullName.bind(member);
```


Preserving this

Sometimes the `bind()` method has to be used to prevent losing `this`.

In the following example, the person object has a display method. In the display method, this refers to the person object:

```js
const person = {
  firstName:"John",
  lastName: "Doe",
  display: function () {
    let x = document.getElementById("demo");
    x.innerHTML = this.firstName + " " + this.lastName;
  }
}

person.display();
```

When a function is used as a callback, `this` is lost.

This example will try to display the person name after 3 seconds, but it will display undefined instead:

```js
const person = {
  firstName:"John",
  lastName: "Doe",
  display: function () {
    let x = document.getElementById("demo");
    x.innerHTML = this.firstName + " " + this.lastName;
  }
}

setTimeout(person.display, 3000);
```

The bind() method solves this problem.

In the following example, the bind() method is used to bind person.display to person.

This example will display the person name after 3 seconds:

```js
const person = {
  firstName:"John",
  lastName: "Doe",
  display: function () {
    let x = document.getElementById("demo");
    x.innerHTML = this.firstName + " " + this.lastName;
  }
}

let display = person.display.bind(person);
setTimeout(display, 3000);
```



#### This Precedence

To determine which object this refers to; use the following precedence of order.
Precedence	Object
1	bind()
2	apply() and call()
3	Object method
4	Global scope

Is this in a function being called using bind()?

Is this in a function being called using apply()?

Is this in a function being called using call()?

Is this in an object function (method)?

Is this in a function in the global scope.






Inconsistent Use of `this`
- **Pitfall:** Arrow functions do not bind their own `this`, which might result in unexpected values inside methods.
- **Solution:** Use regular functions for object methods that rely on `this`, or carefully manage context with `.bind()`, `.call()`, or `.apply()`.