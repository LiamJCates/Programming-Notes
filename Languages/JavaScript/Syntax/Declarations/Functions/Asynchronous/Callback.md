# Asynchronous Scripts

JavaScript is single-threaded, which means that it can run only one task at a time. 
Therefore, long-running tasks can block the application. 

A simple solution is asynchronous programming, a pattern where you start a long-running task without blocking the whole application. While your script
waits for a result, the rest of the application can still respond to interactions or user interface events and perform other calculations.

### Avoiding Traditional Callbacks
Traditional JavaScript implements asynchronous code with callback functions executed after another function returns a result.


One common use case for this technique in full-stack web development is performing I/O operations in Node.js or calling remote APIs.

Reading a file is a common example of asynchronous scripting. We
don’t want the application to be blocked while waiting for the file content
to be ready; however, we also need to use the file’s content in a specific part
of the application.

Here we import the Node.js fs module, which handles filesystem operations, and use a callback function to
display the file’s contents as soon as the operation concludes.

```js
const fs = require("fs");

const callback = (err, data) => {
    if (err) {
        return console.log("error");
    }

    console.log(`File content ${ data }`);
};

fs.readFile(" file.txt", callback);
```

We create the callback function and pass it as a parameter to the fs.readFile function. This function reads a file from the filesystem and executes the callback as soon as the I/O operation fails or succeeds. 

The callback receives the file data and an optional error object, which we write
to the console for now.

Callbacks are a clumsy solution to asynchronous scripting. 

As soon as you have multiple dependent callback functions, you end up in so- called
callback hell, where every callback function takes another callback func-
tion as an argument. The result is a pyramid of functions that are difficult
to read and prone to errors.


Modern JavaScript introduced promises and
async/await as an alternative to callbacks.


