A JavaScript engine is a software component that executes JavaScript code. The first JavaScript engines were mere interpreters, but all relevant modern engines use just-in-time compilation for improved performance.

JavaScript engines are typically developed by web browser vendors, and every major browser has one. In a browser, the JavaScript engine runs in concert with the rendering engine via the Document Object Model and Web IDL bindings. However, the use of JavaScript engines is not limited to browsers; for example, the V8 engine is a core component of the Node.js runtime system.

Since ECMAScript is the standardized specification of JavaScript, ECMAScript engine is another name for these implementations. With the advent of WebAssembly, some engines can also execute this code in the same sandbox as regular JavaScript code




How do engines work?

Engines are complicated. But the basics are easy.

    The engine (embedded if it’s a browser) reads (“parses”) the script.
    Then it converts (“compiles”) the script to machine code.
    And then the machine code runs, pretty fast.

The engine applies optimizations at each step of the process. It even watches the compiled script as it runs, analyzes the data that flows through it, and further optimizes the machine code based on that knowledge.




https://en.wikipedia.org/wiki/JavaScript_engine