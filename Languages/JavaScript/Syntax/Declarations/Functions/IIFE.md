# Immediately Invoked Function Expression

## Overview

An **Immediately Invoked Function Expression** (IIFE) is a JavaScript function that’s defined and executed in one shot, creating a private scope for its variables and avoiding global-namespace pollution ([MDN Web Docs][1]). It’s written by wrapping a function expression in parentheses and appending `()` to invoke it immediately ([GeeksforGeeks][2]). IIFEs support classic functions, arrow functions, and even `async` functions—each running as soon as they’re parsed ([MDN Web Docs][1], [Udacity][3]).

An IIFE—often called a “self-executing anonymous function”—combines a function expression with its invocation so that its contents run immediately and cannot be accessed from the outside ([MDN Web Docs][1]). Because the function’s variables live in its own lexical scope, they don’t collide with other code or the global object ([GeeksforGeeks][2]). This pattern predates ES6 modules as a way to simulate private modules or namespaces in browser scripts ([FreeCodeCamp][4]).

## Syntax Variants

### Classic Function IIFE

```js
(function() {
  // private scope
  const hidden = 42;
  console.log(hidden);
})();
```

Here, the outer parentheses force the parser to treat the `function` keyword as an expression, and the trailing `()` invokes it ([MDN Web Docs][1]).

### Arrow-Function IIFE

```js
(() => {
  let msg = "Hello!";
  console.log(msg);
})();
```

This shorter form uses ES6 arrow syntax but works identically ([MDN Web Docs][1]).

### Async IIFE

```js
(async () => {
  const data = await fetch("/api/data").then(r => r.json());
  console.log(data);
})();
```

Allows top-level `await` behavior in scripts or modules without wrapping in another async function ([MDN Web Docs][5]).

## Common Use Cases

* **Module Pattern**: Encapsulate private helpers and expose a public API.

  ```js
  const Counter = (function() {
    let count = 0;
    return {
      inc() { return ++count; },
      dec() { return --count; }
    };
  })();
  console.log(Counter.inc()); // 1
  ```
* **Avoiding Globals**: Wrap legacy scripts so that their variables don’t leak into `window` ([FreeCodeCamp][4]).
* **One-off Initialization**: Execute setup code exactly once at load time.

## Benefits and Pitfalls

### Benefits

* **Encapsulation**: Creates a private namespace, preventing accidental variable clashes ([GeeksforGeeks][2]).
* **Immediate Execution**: Runs code at definition time, useful for setup or bootstrapping.

### Pitfalls

* **Readability**: Overuse can make code harder to follow, especially with nested IIFEs.
* **Debugging**: Stack traces refer to anonymous functions unless named inside the IIFE.

---

**Sources**

* MDN Web Docs: Glossary “IIFE” — [https://developer.mozilla.org/en-US/docs/Glossary/IIFE](https://developer.mozilla.org/en-US/docs/Glossary/IIFE)
* GeeksforGeeks: Immediately Invoked Function Expressions (IIFE) — [https://www.geeksforgeeks.org/immediately-invoked-function-expressions-iife-in-javascript/](https://www.geeksforgeeks.org/immediately-invoked-function-expressions-iife-in-javascript/)
* MDN Web Docs: Function expressions — [https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/function](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/function)
* Udacity Blog: Immediately Invoked Function Expressions (IIFE) — [https://www.udacity.com/blog/2023/03/immediately-invoked-function-expressions-iife-in-javascript.html](https://www.udacity.com/blog/2023/03/immediately-invoked-function-expressions-iife-in-javascript.html)
* FreeCodeCamp: IIFE in JavaScript — [https://www.freecodecamp.org/news/iife-in-javascript-what/](https://www.freecodecamp.org/news/iife-in-javascript-what/)

[1]: https://developer.mozilla.org/en-US/docs/Glossary/IIFE?utm_source=chatgpt.com "IIFE - MDN Web Docs Glossary: Definitions of Web-related terms"
[2]: https://www.geeksforgeeks.org/immediately-invoked-function-expressions-iife-in-javascript/?utm_source=chatgpt.com "Immediately Invoked Function Expressions (IIFE) in JavaScript"
[3]: https://www.udacity.com/blog/2023/03/immediately-invoked-function-expressions-iife-in-javascript.html?utm_source=chatgpt.com "Immediately invoked function expressions (IIFE) in JavaScript - Udacity"
[4]: https://www.freecodecamp.org/news/iife-in-javascript-what/?utm_source=chatgpt.com "IIFE in JavaScript: What Are Immediately Invoked Function ..."
[5]: https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/async_function?utm_source=chatgpt.com "async function expression - JavaScript - MDN Web Docs - Mozilla"
