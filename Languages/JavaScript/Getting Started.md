## Getting started with JavaScript

To get started with JavaScript, all you need is a modern web browser. 

Recent versions of Firefox, Chrome, Microsoft Edge, and Safari all support the features discussed in this guide.

A very useful tool for exploring JavaScript is the JavaScript Console (sometimes called the Web Console, or just the console): this is a tool which enables you to enter JavaScript and run it in the current page.

Each browser has it's own method of accessing the console, which can be found via a quick web search.

https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Introduction#opening_the_console



The console appears at the bottom of the browser window. Along the bottom of the console is an input line that you can use to enter JavaScript, the output of which appears in the panel above

To get started with writing JavaScript, open the console, copy the following code, and paste it in at the prompt:

```js
(function () {
  "use strict";
  /* Start of your code */
  function greetMe(yourName) {
    alert(`Hello ${yourName}`);
  }

  greetMe("World");
  /* End of your code */
})();
```

for now, remember to always include the (function(){"use strict"; before your code, and add })(); to the end of your code. The strict mode and IIFE articles explain what those do,
 
https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Strict_mode
https://developer.mozilla.org/en-US/docs/Glossary/IIFE

for now they can be thought of as doing the following:

  Prevent semantics in JavaScript that trip up beginners.
  Prevent code snippets executed in the console from interacting with one another (e.g., having something created in one console execution being used for a different console execution).

