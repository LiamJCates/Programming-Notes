# Setup

### Initialize A Project

create a new folder called `sample-express` and initialize a new Node.js project within, run 

```bash
mkdir sample-express
cd sample-express
npm init
``` 

The interactive guide should ask you for some details, such as the name and version of your application.  
Accept the defaults for now.

---

### Add Express.js Dependency

Use the Express.js package as the foundation of the server, run:

```bash
npm install express@4 
```

to install the latest release of the major version 4. 

You will see that the package.json file now contains express as a dependency.

---

### Server Code

Create an index.js file in the `sample-express` folder and add create a basic Express.js server:

```js
const express = require('express');             // load the express package into the file
const server = express();                       // instantiate the app
const port = 3000;                              // define a port to use

server.get('/hello', function (req, res) {      // create a server route, so GET requests sent to /hello base URL 
    res.send('Hello World!');                   // respond with "Hello World!"
});

server.listen(port, function () {               // start the web server listening on port 3000
    console.log('Listening on ' + port);
});
```

We use the Express.js `get` method and pass `/hello` as the first parameter and a callback function as the second parameter. 

For each `GET` request sent to the `/hello` endpoint, the server runs the callback function that sends `Hello World!` as the response to the browser. 

the Express.js `listen` method spins up a web server and we provide the port number `3000` to listen on

Start the server from your command line:

$ node index.js
Listening on 3000

Now visit http://localhost:3000/hello in your browser. You should see the
Hello World! message. Congratulations! You just wrote your first Node.js web
server in JavaScript