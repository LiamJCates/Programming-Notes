## Object Manipulation



### Object vs Variable Copy

Objects are reference types, meaning that variables store references to the object rather than the object itself. 

This is incontrast to primitive variables which contain a copy of the information provided to it.
```js
let data = 42;
// dataCopy will store a copy of what data contains, so a copy of 42
let dataCopy = data;

// which means that making changes to dataCopy won't affect data
dataCopy = 43;

console.log(data); // 42
console.log(dataCopy); // 43
```

An object variable will contain a reference to the object provided to it:

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




### Iterating Over Properties

- **for...in Loop:** Iterates over all enumerable properties (including inherited ones).
- **Object.keys():** Returns an array of a given object's own enumerable property names.
- **Object.values() & Object.entries():** Return arrays of property values and key-value pairs respectively.

```js
const obj = { a: 1, b: 2, c: 3 };

for (let key in obj) {
  console.log(`${key}: ${obj[key]}`);
}

console.log(Object.keys(obj));     // Output: [ 'a', 'b', 'c' ]
console.log(Object.values(obj));   // Output: [1, 2, 3]
console.log(Object.entries(obj));  // Output: [ ['a', 1], ['b', 2], ['c', 3] ]
```




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





 Unintentional Property Enumeration
- **Pitfall:** Using a `for...in` loop without filtering can iterate over inherited properties.
- **Solution:** Use `Object.hasOwnProperty()` check or `Object.keys()` when only own properties are desired.





### Immutability with Object.freeze() and Object.seal()

- **Object.freeze():** Makes an object immutable so that no properties can be added, removed, or changed.
- **Object.seal():** Prevents new properties from being added and marks all existing properties as non-configurable, but values of writable properties can still be changed.

```js
const frozenObj = Object.freeze({ x: 10 });
frozenObj.x = 20;  // No effect
console.log(frozenObj.x);  // Output: 10

const sealedObj = Object.seal({ y: 30 });
sealedObj.y = 40;
console.log(sealedObj.y);  // Output: 40
// However, adding a new property will fail:
sealedObj.z = 50;
console.log(sealedObj.z);  // Output: undefined
```


Mutable Objects and Unintended Side Effects
- **Pitfall:** Since objects are reference types, changes to an object in one part of your code can inadvertently affect another.
- **Solution:** Use immutability techniques (e.g., `Object.freeze()`, libraries like Immutable.js) or clone objects before modification.




### Object Spread and Rest Properties

ES2018 introduced spread properties for objects, allowing you to copy properties from one object to another concisely.

```js
const obj1 = { a: 1, b: 2 };
const obj2 = { ...obj1, c: 3 };
console.log(obj2);  // Output: { a: 1, b: 2, c: 3 }

const { a, ...rest } = obj2;
console.log(a);     // Output: 1
console.log(rest);  // Output: { b: 2, c: 3 }
```

### Destructuring Objects

Destructuring provides a concise way to extract multiple properties from an object.

```js
const settings = {
  host: 'localhost',
  port: 8080,
  protocol: 'http'
};

const { host, port, protocol } = settings;
console.log(`Connecting to ${protocol}://${host}:${port}`);
```