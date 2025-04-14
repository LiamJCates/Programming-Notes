### this

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

This isn't hugely useful when you are writing out object literals by hand, as using the object's name (person1 and person2) leads to the exact same result, but it will be essential when using constructors to create more than one object from a single object definition.