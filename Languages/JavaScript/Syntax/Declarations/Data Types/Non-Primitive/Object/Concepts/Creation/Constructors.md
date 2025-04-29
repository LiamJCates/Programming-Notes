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

This works fine but is a bit long-winded: we have to create an empty object, initialize it, and return it. A better way is to use a constructor. A constructor is just a function called using the new keyword. When you call a constructor, it will:

    create a new object
    bind this to the new object, so you can refer to this in your constructor code
    run the code in the constructor
    return the new object.

Constructors, by convention, start with a capital letter and are named for the type of object they create. So we could rewrite our example like this:

To call Person() as a constructor we use new


```js
function Person(name) {
  this.name = name;
  this.introduceSelf = function () {
    console.log(`Hi! I'm ${this.name}.`);
  };
}

const salva = new Person("Salva");
salva.introduceSelf();
// "Hi! I'm Salva."

const frankie = new Person("Frankie");
frankie.introduceSelf();
// "Hi! I'm Frankie."

```



### Safeguarding constructors

Note that, as constructors are just regular functions, they could be called without using new by mistake, which would cause hard-to-track errors. To prevent that, you can use the new.target meta-property like this:

```js
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
```


### Problems With Constructors

The biggest problem with constructors is that they don’t provide automatic safeguards that prevent from using them wrong.

One of the key arguments is how they look like regular JavaScript functions, even though they do not behave like regular functions. As we warned in the object constructors lesson, if you try to use a constructor function without the new keyword, and you didn’t include additional safeguards in the constructor not only does your program fail to work, but it also produces error messages that are hard to track down and understand.

Yet another issue stems from misusing instanceof. In other programming languages, the keyword is a reliable way to know the code with which an object was made; but in JavaScript, it checks the presence of a constructor’s prototype in an object’s entire prototype chain - which does nothing to confirm if an object was made with that constructor since the constructor’s prototype can even be reassigned after the creation of an object.

Because of that, constructors have become unpopular in favor of a pattern that is similar but addresses a ton of these problems by not relying on those troublesome features: Factory Functions.