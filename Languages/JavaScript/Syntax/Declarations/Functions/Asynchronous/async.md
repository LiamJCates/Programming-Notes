# **async/await**
Modern JavaScript introduces a new, simpler pattern for handling asynchro-
nous requests: the async/await keywords. Instead of relying on chained func-
tions, we can write code whose structure is similar to regular synchronous
code by employing these keywords.
When using this pattern, you mark functions explicitly as asynchronous
with async. Then you use await instead of the promise-based syntax for your
asynchronous code. 



We use the native fetch API with async/await to perform another long-running task and fetch JSON data from a
remote location. 



```js
async function fetchData (url) {
  try {
    const response = await fetch(url);
    const json = await response.json();
    console.log(json);
  } catch (error) {
    console.error(`Error : ${error}`);
  }
}
fetchData("https://www.usemodernfullstack.dev/api/v1/users");
```

This code is functionally the same as the first example in the [Promise](Promise.md) and you
should see that its syntax is more intuitive and cleaner than the chain of
then calls.

First we declare the function as async to enable the await keyword inside
the function. Then we use await to wait for the response of the fetch call.
Unlike the promise syntax we used before, await simplifies the code. It awaits
the response object and returns it. Thus, the code block looks similar to
regular synchronous code.
This pattern requires us to handle errors manually. Unlike with prom-
ises, there is no default reject function. Therefore, we must wrap await state-
ments in a try...catch block to handle error states gracefully.





Async/await is a syntax introduced in ES2017 that builds on Promises to make asynchronous code read and behave more like synchronous code. 

An **async** function always returns a Promise whose resolution value is whatever the function returns (or whose rejection reason is any exception thrown) ([MDN Web Docs][1], [The Modern JavaScript Tutorial][2]). 

Within an async function, the **await** keyword pauses execution until a given Promise settles, then returns its fulfillment value (or throws its rejection reason) ([Modern JavaScript Eğitimi][3], [The Modern JavaScript Tutorial][2]). 

This mechanism simplifies chaining and error propagation, and works naturally with `try`/`catch` blocks for concise error handling ([Wes Bos][4]).

## 1. Defining Async Functions

### Syntax

```js
async function fetchData() {
  // body
}
```

* Declaring `async` before `function` makes it return a Promise implicitly ([MDN Web Docs][1]).
* You can also write async function expressions or IIFEs for one-off usage:

  ```js
  (async () => { /* … */ })();
  ```

  ([MDN Web Docs][5])

### Return Behavior

* **Return value**: any returned value becomes `Promise.resolve(value)` ([MDN Web Docs][1]).
* **Throws**: any uncaught exception becomes a rejected Promise with that error ([MDN Web Docs][1]).

## 2. Using `await`

### Basics

```js
let data = await fetch(url).then(res => res.json());
```

* `await` can only appear inside async functions (or at the module top level) ([MDN Web Docs][6], [Stack Overflow][7]).
* It pauses execution of the surrounding async function until the Promise settles ([Modern JavaScript Eğitimi][3]).
* On fulfillment, it returns the resolved value; on rejection, it throws the rejection reason, which can be caught with `try`/`catch` ([Wes Bos][4]).

### Example

```js
async function getJSON(url) {
  try {
    let response = await fetch(url);
    let json    = await response.json();
    return json;
  } catch (err) {
    console.error("Failed to fetch or parse", err);
    throw err;
  }
}
```

Here, both the network error and JSON parsing error flow through the same `catch` block ([Wes Bos][4]).

## 3. Sequential vs. Parallel Execution

### Sequential `await`

```js
let a = await fetch(aURL);
let b = await fetch(bURL);
```

* Each fetch waits for the previous to finish, potentially slowing overall runtime ([Medium][8]).

### Parallel with `Promise.all`

```js
let [a, b] = await Promise.all([fetch(aURL), fetch(bURL)]);
```

* Starts both fetches concurrently, then waits for both to settle ([MDN Web Docs][9], [Stack Overflow][10]).
* Fails fast: rejects as soon as any Promise rejects ([Stack Overflow][10]).

## 4. Error Handling Patterns

* **`try`/`catch`** inside async functions catches awaited errors:

  ````js
  async function foo() {
    try { await doSomething(); }
    catch (e) { console.error(e); }
  }
  ``` :contentReference[oaicite:14]{index=14}  
  ````
* **Handling within loops**: use `try`/`catch` per iteration or `Promise.allSettled()` for aggregate results ([Codedamn][11]).
* **Global catch**: attach `.catch()` to the returned Promise if not using `try`/`catch` inside ([FreeCodeCamp][12]).

## 5. Top-Level `await`

* Modern ES modules allow `await` at the top level, pausing module loading until the Promise settles ([Stack Overflow][7], [V8][13]).
* Enables simpler initialization logic in modules without wrapper functions ([Stack Overflow][7]).

## 6. Advanced Patterns

### Async Generators & `for await…of`

* `async function*` produces an async iterable; use `for await…of` to consume ([MDN Web Docs][14], [MDN Web Docs][15]).
* Useful for streaming data or paginated APIs.

### Concurrency Control

* Despite `await` looking synchronous, true concurrency must be managed via Promise utilities (`all`, `race`, etc.) ([Medium][8]).
* Libraries like p-limit or promise pools help throttle concurrency.

---

**Sources**

1. MDN Web Docs: async function — [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/async\_function](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/async_function)
2. MDN Web Docs: await expression — [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/await](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/await)
3. JavaScript.info: Async/await — [https://javascript.info/async-await](https://javascript.info/async-await)
4. Wes Bos: Async/Await Error Handling — [https://wesbos.com/javascript/12-advanced-flow-control/71-async-await-error-handling/](https://wesbos.com/javascript/12-advanced-flow-control/71-async-await-error-handling/)
5. Piotr Karpala: Async/await and Parallel Code — [https://medium.com/@piotrkarpaa/async-await-and-parallel-code-in-node-js-6de6501eea48](https://medium.com/@piotrkarpaa/async-await-and-parallel-code-in-node-js-6de6501eea48)
6. Stack Overflow: Top-level await in modules — [https://stackoverflow.com/questions/46515764/how-can-i-use-async-await-at-the-top-level](https://stackoverflow.com/questions/46515764/how-can-i-use-async-await-at-the-top-level)
7. FreeCodeCamp: How to Use Async/Await in JavaScript — [https://www.freecodecamp.org/news/javascript-async-await/](https://www.freecodecamp.org/news/javascript-async-await/)
8. MDN Web Docs: Promise.all() — [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global\_Objects/Promise/all](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/all)
9. Stack Overflow: Async/await chaining and `.catch()` — [https://stackoverflow.com/questions/31590975/es6-tagged-templates-practical-usability](https://stackoverflow.com/questions/31590975/es6-tagged-templates-practical-usability)
10. Codedamn: Error Handling in Loops — [https://codedamn.com/news/javascript/javascript-async-await-error](https://codedamn.com/news/javascript/javascript-async-await-error)
11. MDN Web Docs: SyntaxError: await only valid in async functions — [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Errors/Bad\_await](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Errors/Bad_await)
12. MDN Web Docs: async function expression — [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/async\_function](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/async_function)
13. MDN Web Docs: AsyncFunction object — [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global\_Objects/AsyncFunction](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/AsyncFunction)
14. MDN Web Docs: for await…of — [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for-await...of](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for-await...of)
15. GeeksforGeeks: Promise.all with async/await — [https://www.geeksforgeeks.org/explain-promise-all-with-async-await-in-javascript/](https://www.geeksforgeeks.org/explain-promise-all-with-async-await-in-javascript/)

[1]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/async_function?utm_source=chatgpt.com "async function - JavaScript - MDN Web Docs - Mozilla"
[2]: https://javascript.info/async-await?utm_source=chatgpt.com "Async/await - The Modern JavaScript Tutorial"
[3]: https://tr.javascript.info/async-await?utm_source=chatgpt.com "Async/await"
[4]: https://wesbos.com/javascript/12-advanced-flow-control/71-async-await-error-handling/?utm_source=chatgpt.com "Async/Await Error Handling - Beginner JavaScript - Wes Bos"
[5]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/async_function?utm_source=chatgpt.com "async function expression - JavaScript - MDN Web Docs - Mozilla"
[6]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Errors/Bad_await?utm_source=chatgpt.com "SyntaxError: await is only valid in async functions ... - MDN Web Docs"
[7]: https://stackoverflow.com/questions/46515764/how-can-i-use-async-await-at-the-top-level?utm_source=chatgpt.com "How can I use async/await at the top level? - Stack Overflow"
[8]: https://medium.com/%40piotrkarpaa/async-await-and-parallel-code-in-node-js-6de6501eea48?utm_source=chatgpt.com "Async await and concurrent code in Node.js | by Piotr Karpala"
[9]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise/all?utm_source=chatgpt.com "Promise.all() - JavaScript - MDN Web Docs"
[10]: https://stackoverflow.com/questions/45285129/any-difference-between-await-promise-all-and-multiple-await?utm_source=chatgpt.com "Any difference between await Promise.all() and multiple await?"
[11]: https://codedamn.com/news/javascript/javascript-async-await-error?utm_source=chatgpt.com "Mastering Async Await Error Handling in JavaScript - Codedamn"
[12]: https://www.freecodecamp.org/news/javascript-async-await/?utm_source=chatgpt.com "How to Use Async/Await in JavaScript – Explained with Code ..."
[13]: https://v8.dev/features/top-level-await?utm_source=chatgpt.com "Top-level await - V8.Dev"
[14]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/async_function%2A?utm_source=chatgpt.com "async function* expression - JavaScript - MDN Web Docs - Mozilla"
[15]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Statements/for-await...of?utm_source=chatgpt.com "for await...of - JavaScript - MDN Web Docs"
