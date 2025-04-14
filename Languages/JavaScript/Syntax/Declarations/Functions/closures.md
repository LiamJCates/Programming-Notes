https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Closures
https://wesbos.com/javascript/03-the-tricky-bits/closures



Functions in JavaScript form closures. A closure refers to the combination of a function and the surrounding state in which the function was declared. This surrounding state, also called its lexical environment, consists of any local variables that were in scope at the time the closure was made.

```js
function makeAdding (firstNumber) {
  // "first" is scoped within the makeAdding function
  const first = firstNumber;
  return function resulting (secondNumber) {
    // "second" is scoped within the resulting function
    const second = secondNumber;
    return first + second;
  }
}
// but we've not seen an example of a "function"
// being returned, thus far - how do we use it?

const add5 = makeAdding(5);
console.log(add5(2)) // logs 7
```

The makeAdding function takes an argument, firstNumber, declares a constant first with the value of firstNumber, and returns another function.

When an argument is passed to the returned function, which we have assigned to add5, it returns the result of adding up the number passed earlier to the number passed now (first to second).

Here, add5 is a reference to the resulting function, created when the makeAdding function is executed, thus it has access to the lexical environment of the resulting function, which contains the first variable, making it available for use.






Private variables and functions

Now you may be thinking - where does closure come into all of this? Factories seem to be returning an object. This is where we can extend our User factory to add a few more variables and introduce “private” ones. Take a look at this, now:

function createUser (name) {
  const discordName = "@" + name;

  let reputation = 0;
  const getReputation = () => reputation;
  const giveReputation = () => reputation++;

  return { name, discordName, getReputation, giveReputation };
}

const josh = createUser("josh");
josh.giveReputation();
josh.giveReputation();

console.log({
  discordName: josh.discordName,
  reputation: josh.getReputation()
});
// logs { discordName: "@josh", reputation: 2 }

We’ve introduced a new metric for a new user - a reputation. Notice that the object we return in the factory function does not contain the reputation variable itself, nor any copy of its value. Instead, the returned object contains two functions - one that reads the value of the reputation variable, and another that increases its value by one. The reputation variable is what we call a “private” variable, since we cannot access the variable directly in the object instance - it can only be accessed via the closures we defined.

Concerning factory functions, a private variable or function uses closures to create smaller, dedicated variables and functions within a factory function itself - things that we do not need to return in the object itself. This way we can create neater code, without polluting the returned object with unnecessary variables that we create while creating the object itself. Often, you do not need every single function within a factory to be returned with the object, or expose an internal variable. You can use them privately since the property of closures allows you to do so.

In this case, we did not need control of the reputation variable itself. To avoid foot guns, like accidentally setting the reputation to -18000, we expose the necessary details in the form of getReputation and giveReputation.
Constructors and closure

Note that you could technically also use closure in constructors, by defining the methods to access a “private property” inside the constructor, instead of on the prototype. But that would make them non-inheritable, which defies the purpose of constructors.
