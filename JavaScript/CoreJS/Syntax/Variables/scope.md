Variables and Block Scopes

Here's one of my favorite JavaScript trick questions. Is this a valid JavaScript line of code?
```js
{{{}}}
```
Testing it in the playground seems to work fine. There are no errors, which means it's valid.

So now the question is, what did it do?

These are nested block scopes. We could write code in here like var v = 42; and then access the v variable right after, and it would work fine.
```js
{{{var v = 42;}}}

v

//output 42
```
JavaScript does not really care about the spacing or new lines in here. A block scope is created with a pair of curly braces, just like this example here:
```js
{
  // Block Scope
}

if (true) {
  // Block Scope
}

for (var i = 1; i <= 10; i++) {
  // Block Scope
}

function sum(a, b) {
  // Function Scope
  var result = a + b;
}

sum(4 + 3);
```
This also applies to if statements and for statements as well. These also get their own block scopes. Block scopes are a bit different than function scopes, which are created for each function.

You can see one difference when using the var keyword to define variables. Variables defined with var inside a function scope are okay. They don't leak out of that scope. If you try to access them outside of that scope, you can't. As you can see in the example, if we were to try and access the result varialbe outside the sum function, we cannot, as the result variable  was defined inside the sum function's scope. 

However, when you define variables with var in a block scope, you can totally access them outside that scope afterward, which is a bit problematic. The example shows one case where this occurs.
```js
for (var i = 1; i <= 10; i++) {
  // Block Scope
}

i
```

The for loop has an index variable that ticks from 1 to 10. You can access that variable inside the loop normally, but you can also access the same variable outside the loop. After all the iterations are done, the value of i here will be reported as 11, which is a bit weird.

This is why the more recommended way to declare variables in modern JavaScript is by using the let keyword instead of the var keyword. When defining variables with let, we won't have this weird out of scope access problem. If we replace this var here with let and redo the same test and try to access i after that, you'll get the error that i is not defined. This makes sense because we're outside of the scope where it was defined, so this is much better.

Block scopes, like function scopes, can also be nested, like the trick question we started with. This is a nested block scoop. Within each level, the scope will protect the variables defined in it as long as we use the let keyword or the const keyword, which behaves like the let keyword.
