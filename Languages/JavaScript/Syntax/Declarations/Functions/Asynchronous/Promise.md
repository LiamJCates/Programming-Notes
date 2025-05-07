# Promise



### Using Promises

Promises provide a much cleaner syntax than callbacks for chainable asynchronous tasks.

Similar to callbacks, they defer further tasks until a previous action has
completed or failed. Essentially, promises are function calls that do not
return an immediate result. Instead, they promise to return the result at
some later point. If there is an error, the promise is rejected instead of
resolved.

The Promise object has two properties: the `state` and the `result`. When
the state is pending, the result is undefined. However, as soon as the prom-
ise resolves, the state changes to fulfilled, and the result reflects the return
value. 

If the promise is rejected instead, the state is also set to rejected, and
the result contains an error object.


Promises follow a unique syntax. 

To use them:
- create a new Promise or call a function that returns a Promise. 
- consume the Promise object
- clean up

This is done by registering the consuming functions `then`, `catch`, and `finally`. 

The promise initially calls `then` as soon as the state changes from `pending` to `fulfilled` and passes the returned
data to it. Each following `then` method receives the return value of the previous one, allowing you to create a single task chain that works with and
manipulates these return values.

The promise chain invokes the `catch` method only if an error occurs
either initially or later in the chain of tasks. In addition, a state change (of
this particular promise) to `rejected` also invokes it. In any case, the parser
calls the `finally` method after the stack of then methods has completed or
the catch method was invoked. You use the finally method for cleanup tasks

such as unlocking the user interface or closing database connections. It’s
similar to the finally call of a try...catch statement.
You can use promises in any function. In Listing 2-16, we use the native
fetch API to request JSON data.

```js
function fetchData(url) {
  fetch(url)
    .then((response) => response.json())
    .then((json) => console.log(json))
    .catch((error) => {
      console.error(`Error : ${error}`);
    });
}

fetchData("https:// www . usemodernfullstack . dev / api / v1 / users");
```


Like I/O operations on the filesystem, network requests are long-
running tasks that block the application. Therefore, we should use asyn-
chronous patterns to load remote datasets. As in Listing 2-15, we need to
wait until the operation is complete before we can process the requested
data or handle an error.
The fetch API is promise-based by default. As soon as the promise
resolves and the state changes to fulfilled, the following then function
receives the response object. We then parse the data and pass the JSON
object to the next function in the promise chain, a sequence of functions con-
nected with a dot (.then). If there is an error, the promise is rejected. In this
case, we catch the error and write it to the console.


A **Promise** is a JavaScript object representing the eventual completion (or failure) of an asynchronous operation and its resulting value. 

Promises begin in a **pending** state, then settle to either **fulfilled** (with a value) or **rejected** (with a reason). 

They provide a cleaner alternative to nested callbacks by centralizing success and error handling through chainable methods (`.then()`, `.catch()`, and `.finally()`). 

Promises also come with several utility static methods—such as `Promise.all()`, `Promise.race()`, `Promise.allSettled()`, and `Promise.any()`—that simplify coordinating multiple asynchronous tasks. 

Finally, Promises are the foundation of `async`/`await` syntax, which further streamlines asynchronous code.

## 1. Promise States and Core Concepts

* **Pending**: initial state; neither fulfilled nor rejected.
* **Fulfilled**: operation completed successfully, yielding a value.
* **Rejected**: operation failed, yielding a reason (error). ([MDN Web Docs][1])
* **Settled**: a promise that is either fulfilled or rejected.

A Promise is created by calling `new Promise(executor)`, where the **executor** is a function with two callbacks—`resolve(value)` to fulfill, or `reject(reason)` to reject—invoked once the asynchronous work completes ([The Modern JavaScript Tutorial][2]).

```js
const p = new Promise((resolve, reject) => {
  // async operation…
  if (success) resolve(result);
  else reject(new Error("Failure reason"));
});
```

## 2. Consuming Promises

Once you have a promise, attach handlers:

* `.then(onFulfilled, onRejected?)` — handles success and optionally immediate failure.
* `.catch(onRejected)` — handles any rejection in the chain.
* `.finally(onFinally)` — runs regardless of outcome, without receiving a value. ([MDN Web Docs][3])

```js
p
  .then(value => {
    console.log("Got:", value);
  })
  .catch(err => {
    console.error("Error:", err);
  })
  .finally(() => {
    console.log("Cleanup if needed");
  });
```

## 3. Chaining and Composition

Every call to `.then()` (or `.catch()`/`.finally()`) returns a new promise, enabling chains. If a handler returns a value, the next `.then()` receives it; if it returns a promise, the chain waits for it to settle. Any thrown exception or returned rejected promise skips directly to the next `.catch()`. ([The Modern JavaScript Tutorial][4])

```js
fetch(url)
  .then(res => res.json())
  .then(data => process(data))      // returns value or a new Promise
  .then(result => console.log(result))
  .catch(err => console.error("Failed at any step:", err));
```

## 4. Static Utility Methods

* **`Promise.all(iterable)`**
  Waits for *all* promises to fulfill; rejects immediately if any rejects. Returns an array of results. ([The Modern JavaScript Tutorial][5])
* **`Promise.race(iterable)`**
  Settles as soon as one promise in the iterable settles—fulfills or rejects—with that value/reason.
* **`Promise.allSettled(iterable)`**
  Waits for all to settle, then returns an array of outcome objects (`{status, value/reason}`).
* **`Promise.any(iterable)`**
  Fulfills as soon as any promise fulfills; rejects only if all reject.

## 5. Error Handling Best Practices

* Use `.catch()` at the end of chains to handle any errors.
* Avoid passing an error handler as the second `.then()` argument unless you intentionally want to intercept only that stage’s errors.
* Use `.finally()` for cleanup that must run regardless of success or failure. ([The Modern JavaScript Tutorial][6])

## 6. Promisification and `async`/`await`

* **Promisification**: wrapping callback-based APIs in a promise.

  ```js
  function delay(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
  }
  ```
* **`async`/`await`**: syntactic sugar over promises. An `async` function implicitly returns a promise; use `await` to pause execution until a promise settles. Errors can be caught via `try`/`catch`.

  ```js
  async function getData() {
    try {
      const res = await fetch(url);
      const data = await res.json();
      return data;
    } catch (err) {
      console.error("Fetch error:", err);
    }
  }
  ```

---

**Sources**

* MDN Web Docs: Promise (overview) — developer.mozilla.org
* The Modern JavaScript Tutorial: Promise basics & chaining — javascript.info
* MDN Web Docs: Using promises — developer.mozilla.org

[1]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Promise?utm_source=chatgpt.com "Promise - JavaScript - MDN Web Docs"
[2]: https://javascript.info/promise-basics?utm_source=chatgpt.com "Promise - The Modern JavaScript Tutorial"
[3]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Using_promises?utm_source=chatgpt.com "Using promises - JavaScript - MDN Web Docs"
[4]: https://javascript.info/promise-chaining?utm_source=chatgpt.com "Promises chaining - The Modern JavaScript Tutorial"
[5]: https://javascript.info/promise-api?utm_source=chatgpt.com "Promise API - The Modern JavaScript Tutorial"
[6]: https://javascript.info/promise-error-handling?utm_source=chatgpt.com "Error handling with promises - The Modern JavaScript Tutorial"
