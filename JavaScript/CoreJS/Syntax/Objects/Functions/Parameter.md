Primitive parameters (such as a number) are passed to functions by value; the value is passed to the function, but if the function changes the value of the parameter, this change is not reflected globally or in the calling function.

If you pass an object (i.e. a non-primitive value, such as Array or a user-defined object) as a parameter and the function changes the object's properties, that change is visible outside the function, as shown in the following example:



Function parameters
Default parameters

Default function parameters allow formal parameters to be initialized with default values if no value or undefined is passed. For more details, see default parameters.
Rest parameters

The rest parameter syntax allows representing an indefinite number of arguments as an array. For more details, see rest parameters.
The arguments object

You can refer to a function's arguments within the function by using the arguments object. See arguments.

    arguments: An array-like object containing the arguments passed to the currently executing function.
    arguments.callee : The currently executing function.
    arguments.caller : The function that invoked the currently executing function.
    arguments.length: The number of arguments passed to the function.




Optional Arguments

If we define a function with only one parameter, yet call it with three, the language doesn’t complain. It ignores the extra arguments and computes the square of the first one. JavaScript is extremely broad-minded about the number of arguments you pass to a function. If you pass too many, the extra ones are ignored. If you pass too few, the missing parameters get assigned the value undefined.

this behavior can be used to allow a function to be called with different numbers of arguments.

function minus(a, b) {
if (b === undefined) return -a;
else return a - b;
}

If you write an = operator after a parameter, followed by an expression, the value of that expression will replace the argument when it is not given.








The named parameters turn out to be more like guidelines than anything else. You can call a function without passing the parameters it expects, in which case they will be set to undefined.

add(); // NaN
// You can't perform addition on undefined

You can also pass in more arguments than the function is expecting:

add(2, 3, 4); // 5
// added the first two; 4 was ignored

That may seem a little silly, but functions have access to an additional variable inside their body called arguments, which is an array-like object holding all of the values passed to the function. Let's re-write the add function to take as many values as we want:

function add() {
  var sum = 0;
  for (var i = 0, j = arguments.length; i < j; i++) {
    sum += arguments[i];
  }
  return sum;
}

add(2, 3, 4, 5); // 14

That's really not any more useful than writing 2 + 3 + 4 + 5 though. Let's create an averaging function:

function avg() {
  var sum = 0;
  for (var i = 0, j = arguments.length; i < j; i++) {
    sum += arguments[i];
  }
  return sum / arguments.length;
}

avg(2, 3, 4, 5); // 3.5

This is pretty useful, but it does seem a little verbose. To reduce this code a bit more we can look at substituting the use of the arguments array through Rest parameter syntax. In this way, we can pass in any number of arguments into the function while keeping our code minimal. The rest parameter operator is used in function parameter lists with the format: ...variable and it will include within that variable the entire list of uncaptured arguments that the function was called with. We will also replace the for loop with a for...of loop to return the values within our variable.

function avg(...args) {
  var sum = 0;
  for (let value of args) {
    sum += value;
  }
  return sum / args.length;
}

avg(2, 3, 4, 5); // 3.5

In the above code, the variable args holds all the values that were passed into the function.

It is important to note that wherever the rest parameter operator is placed in a function declaration it will store all arguments after its declaration, but not before. i.e. function avg(firstValue, ...args) will store the first value passed into the function in the firstValue variable and the remaining arguments in args. That's another useful language feature but it does lead us to a new problem. The avg() function takes a comma-separated list of arguments — but what if you want to find the average of an array? You could just rewrite the function as follows:

function avgArray(arr) {
  var sum = 0;
  for (var i = 0, j = arr.length; i < j; i++) {
    sum += arr[i];
  }
  return sum / arr.length;
}

avgArray([2, 3, 4, 5]); // 3.5

But it would be nice to be able to reuse the function that we've already created. Luckily, JavaScript lets you call a function with an arbitrary array of arguments, using the apply() method of any function object.

avg.apply(null, [2, 3, 4, 5]); // 3.5

The second argument to apply() is the array to use as arguments; the first will be discussed later on. This emphasizes the fact that functions are objects too.

You can achieve the same result using the spread operator in the function call.

For instance: avg(...numbers)
