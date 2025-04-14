### Property existence test, “in” operator

A notable feature of objects in JavaScript, compared to many other languages, is that it’s possible to access any property. There will be no error if the property doesn’t exist!

Reading a non-existing property just returns undefined. So we can easily test whether the property exists:

```js
let user = {};

alert( user.noSuchProperty === undefined ); // true means "no such property"
```

There’s also a special operator "in" for that.

The syntax is:

"key" in object

```js
let user = { name: "John", age: 30 };

alert( "age" in user ); // true, user.age exists
alert( "blabla" in user ); // false, user.blabla doesn't exist
```

Please note that on the left side of in there must be a property name. That’s usually a quoted string.

If we omit quotes, that means a variable should contain the actual name to be tested. For instance:

```js
let user = { age: 30 };

let key = "age";
alert( key in user ); // true, property "age" exists
```
Why does the in operator exist? Isn’t it enough to compare against undefined?

Well, most of the time the comparison with undefined works fine. But there’s a special case when it fails, but "in" works correctly.

It’s when an object property exists, but stores undefined:
```js
let obj = {
  test: undefined
};

alert( obj.test ); // it's undefined, so - no such property?

alert( "test" in obj ); // true, the property does exist!
```

In the code above, the property obj.test technically exists. So the in operator works right.

Situations like this happen very rarely, because undefined should not be explicitly assigned.



### The "for..in" loop

To walk over all keys of an object, there exists a special form of the loop: for..in. 

```js
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
```
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