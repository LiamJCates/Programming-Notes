Getting started with JavaScript

To get started with JavaScript, all you need is a modern web browser. Recent versions of Firefox, Chrome, Microsoft Edge, and Safari all support the features discussed in this guide.

A very useful tool for exploring JavaScript is the JavaScript Console (sometimes called the Web Console, or just the console): this is a tool which enables you to enter JavaScript and run it in the current page.

Each browser has it's own method of accessing the console, which can be found via a quick web search.

https://developer.mozilla.org/en-US/docs/Web/JavaScript/Guide/Introduction#opening_the_console



The console appears at the bottom of the browser window. Along the bottom of the console is an input line that you can use to enter JavaScript, and the output appears in the panel above


The console works the exact same way as eval: the last expression entered is returned. For the sake of simplicity, it can be imagined that every time something is entered into the console, it is actually surrounded by console.log around eval, like so:
js

console.log(eval("3 + 5"));

Multi-line input in the console


By default, if you press Enter (or Return, depending on your keyboard) after entering a line of code, then the string you typed is executed. To enter multi-line input:

    If the string you typed was incomplete (for example, you typed function foo() {) then the console will treat Enter as a line break, and let you type another line.
    If you hold down Shift while pressing Enter, then the console will treat this as a line break, and let you type another line.
    In Firefox only, you can activate multi-line input mode, in which you can enter multiple lines in a mini-editor, then run the whole thing when you are ready.



To get started with writing JavaScript, open the console, copy the following code, and paste it in at the prompt:
js

(function () {
  "use strict";
  /* Start of your code */
  function greetMe(yourName) {
    alert(`Hello ${yourName}`);
  }

  greetMe("World");
  /* End of your code */
})();



 for now, remember to always include the (function(){"use strict"; before your code, and add })(); to the end of your code. The strict mode and IIFE articles explain what those do,
 
https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Strict_mode
https://developer.mozilla.org/en-US/docs/Glossary/IIFE

 for now they can be thought of as doing the following:

    Prevent semantics in JavaScript that trip up beginners.
    Prevent code snippets executed in the console from interacting with one another (e.g., having something created in one console execution being used for a different console execution).

