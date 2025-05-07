# Setup

## V1 Node

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

```json
{
  "name": "sample-express",
  "version": "1.0.0",
  "description": "",
  "license": "ISC",
  "author": "",
  "type": "commonjs",
  "main": "index.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "dependencies": {
    "express": "^4.21.2"
  }
}
```

    NOTE: Packages may be later versions than those shown above
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

```bash
$ node index.js
Listening on 3000
```

Now visit `http://localhost:3000/hello` in your browser. You should see the Hello World! message. 

Congratulations! You just wrote your first Node.js web server in JavaScript


## V2 Adding Modules

Modern JavaScript provides the tools you need to write clean and efficient code, lets optimize the server a bit


We’ll replace the server’s require call with named modules for different
routes. To do so, we need to explicitly specify that our project uses native
modules. Other wise, Node.js will throw an error. Modify your package.json
file 

```json
{
  "name": "sample-express",
  "version": "1.0.0",
  "description": "",
  "license": "ISC",
  "author": "",
  "type": "module",
  "main": "index.js",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "dependencies": {
    "express":"^4.18.2",
    "node-fetch": "^3.2.6"
    },
    "devDependencies": {}
}
```

NOTE: Packages may be later versions than those shown above

We changed the property type to the value `module`. 

Also, you’ll want to install the `node-fetch` package to make an asynchronous API call in one of your routes.

```bash
npm install node-fetch
```

### Writing an ES.Next Module with Asynchronous Code

Create the file routes.js in the sample- express folder, next to the index.js file,
and add the code 

```js
import fetch from "node-fetch";

const routeHello = () => "Hello World!";

const routeAPINames = async () => {
    const url = "https://www.usemodernfullstack.dev/api/v1/users";
    let data;
    try {
        const response = await fetch(url);
        data = await response.json();
    } catch (err) {
        return err;
    }
    const names = 
        data
        .map((item) => `id: ${item.id}, name: ${item.name}`)
        .join("<br>");
    return names;
};

export { routeHello, routeAPINames };
```

First we import the fetch module for making asynchronous requests.

Then we create the first route, for our existing `/hello` endpoint. 

    Its behavior should be the same as before; using a fat arrow function with a concise
    body syntax, it returns the string Hello World!

Next, we create a route for a new `/api/names` endpoint. 

    This endpoint will add a page to our web server displaying a list of usernames and IDs. But first we explicitly define an async function so that we can use the await syntax for our fetch call. 

Then we define the API endpoint in a constant and another variable to store asynchronous data. 

    We need to define these before we use them because the await calls happen inside a try...catch block, and these variables are block- scoped. If we defined them inside the block, we wouldn’t be able to use them later.

We call the API and await the response data, which we convert to JSON as soon as the call succeeds. 

    The data variable now holds an array of objects. We use array.map to iterate over the data and create the strings we want to display. Then we join all array items with break tags (<br>) to display them in rows and return the string.

Finally, we export the two routes under their names.

### Adding the Modules to the Server


Modify the file index.js in the sample- express folder to match Listing 2-23. We
use native modules for importing the require module and the routes we cre-
ated

```js
import { routeHello, routeAPINames } from "./routes.js";
import express from "express";

const server = express();
const port = 3000;

server.get("/hello", function (req, res) {
  const response = routeHello(req, res);
  res.send(response);
});

server.get("/api/names", async function (req, res) {
  let response;
  try {
  response = await routeAPINames(req, res);
  } catch (err) {
  console.log(err);
  }
  res.send(response);
});

server.listen(port, function () {
  console.log("Listening on " + port);
});
```

First we import routes with the syntax for named imports. Then we
replace the require call for the express package with an import statement.
The /hello endpoint we created earlier calls the route we imported, and the
server sends Hello World! as the response to the browser.
Finally, we create a new endpoint, /api/names, that contains asynchro-
nous code. Therefore, we mark the handler as async and await the route
inside a try...catch block.

Start the server from your command line:

```bash
$ node index.js
Listening on 3000
```
Now visit `http://localhost:3000/api/names` in your browser and receive:

```
id: 1, name: Olivia Smith
id: 2, name: Liam Johnson
id: 3, name: Noah Williams
id: 4, name: Emma Brown
id: 5, name: Oliver Jones
id: 6, name: Charlotte Garcia
id: 7, name: Elijah Miller
id: 8, name: Amelia Davis
id: 9, name: James Rodriguez
id: 10, name: Ava Martinez
```

## V3 TypeScript


First Setup TypeScript as instructed [here](../../../../../Languages/JavaScript/TypeScript/Setup.md)

Next, because Express.js isn’t typed,
add type definitions from DefinitelyTyped to your project by running the
following:

```bash
$ npm install --save-dev @types/express
```

Your package.json should now look like this:

```json
{
  "name": "sample-express-2",
  "version": "1.0.0",
  "description": "",
  "license": "ISC",
  "author": "",
  "type": "module",
  "main": "index.ts",
  "scripts": {
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "dependencies": {
    "express": "^4.21.2",
    "node-fetch": "^3.3.2"
  },
  "devDependencies": {
    "@types/express": "^5.0.1",
    "typescript": "^5.8.3"
  }
}
```

Now you can create configuration and type declaration files for the project.

### tsconfig.json File

Replace the contents of the tsconfig.json file

```json
{
  "compilerOptions": {
    "esModuleInterop": true,
    "module": "es6",
    "moduleResolution": "node",
    "target": "es6",
    "noImplicitAny": true
  }
}
```

We configure TypeScript for our simple Express.js server, which
requires only a few settings. We use ES.Next modules for our TypeScript
code, and because we want to keep them after transpiling the TypeScript
to JavaScript, we set module and target to es6. The express package is a
CommonJS module. Therefore, we need to use the esModuleInterop option
and set the moduleResolution to node. Finally, we use the noImplicitAny option
to disallow the implicit use of the any type and require explicit typing.

### Defining Custom Types

For our server, we’ll follow a simple rule of thumb: every time we use an
object, we should consider adding a custom type or interface to our project.
If the object is a function parameter, we’ll create a custom interface. If we
use this particular object more than once, we’ll create a custom type.

To define the custom types for this sample project, we create a file
custom.d.ts next to the index.ts file

```ts
type responseItemType = {
  id: string;
  name: string;
};

type WeatherDetailType = {
  zipcode: string;
  weather: string;
  temp?: number;
};

interface WeatherQueryInterface {
  zipcode: string;
}
```

We create two custom types and an interface. One defines the response
items of the asynchronous API call. The other type and the interface are
similar to examples shown earlier in this chapter. They are necessary for
the new weather route we will create shortly.

### Adding Type Annotations to the routes.ts File

Next, we must add type annotations to our server code. Rename the routes.js
file in the sample- express folder to routes.ts to enable the TSC for this file. You
should instantly see the errors and warnings appear in your editor. 

Then adjust the code to match

```ts
import fetch from "node-fetch";

const routeHello = (): string => "Hello World!";

const routeAPINames = async (): Promise<string> => {

    const url = "https://www.usemodernfullstack.dev/api/v1/users";
    let data: responseItemType[];

    try {
        const response = await fetch(url);
        data = (await response.json()) as responseItemType[];
    } catch (err) {
        return "Error";
    }

    const names = 
        data
        .map((item) => `id: ${item.id}, name: ${item.name}`)
        .join("<br>");

    return names;
};

const routeWeather =
    (query: WeatherQueryInterface): WeatherDetailType => queryWeatherData(query);

const queryWeatherData = (query: WeatherQueryInterface): WeatherDetailType => {
    return {
        zipcode: query.zipcode,
        weather: "sunny",
        temp: 35
    };
};

export { routeHello, routeAPINames, routeWeather };
```

we
annotate only a function’s parameters and return types. We also annotate
local variables only when their types cannot be inferred, as when convert-
ing the fetch response to JSON. Here we need to explicitly type the variable
with our custom responseItemType and cast the conversion’s return value as
an array of responseItemTypes.
In the rest of the listing, we create the functions for the additional
weather route. We use the custom interface for typing both functions’
parameters and the custom type for their return types. In this basic exam-
ple, the query function returns mostly static data, except the ZIP code,
which it takes from the passed parameters. A regular implementation
would query a database with the ZIP code and retrieve actual data.
Finally, we add the new route for the weather endpoint to the export
statement.

### Adding Type Annotations to the index.ts File

Rename the file index.js in the sample- express folder to index.ts and adjust the
code to match

```ts
import { routeHello, routeAPINames, routeWeather } from "./routes.js";
import express, { Request, Response } from "express";

const server = express();
const port = 3000;

server.get(
  "/hello", 
  function (_req: Request, res: Response): void {
    const response = routeHello();
    res.send(response);
  }
);

server.get("/api/names",
  async function (_req: Request, res: Response): Promise<void> {
    let response: string;

    try {
      response = await routeAPINames();
      res.send(response);
    } 
    catch (err) {
      console.log(err);
    }
  }
);

server.get(
  "/api/weather/:zipcode",
  function (req: Request, res: Response): void {
    const response = routeWeather({ zipcode: req.params.zipcode });
    res.send(response);
  }
);

server.listen(
  port, 
  function (): void {
    console.log("Listening on " + port);
  }
);
```

In addition to the necessary type annotations,
create a new endpoint and follow the TypeScript convention to prefix unused
parameters with an underscore (_)

First we import the new weather route from the available routes and
the Request and Response types from the express package. These are all named
exports. Thus, we use curly brackets ({}).
Then, following best practices, we add code annotations and, at the
same time, prefix the unused req parameters with an underscore. TSC will
follow the convention of functional programming languages by ignoring
these parameters. The api/names entry point is marked as an async func-
tion, so it needs to return a value wrapped in a promise. Hence, nothing is
returned, and we return void as the promise’s value.
In the following lines of code, we create an additional route for a new
/api/weather/:zipcode endpoint. The colon (:) creates a parameter on the
request’s params object. We retrieve the value for zipcode with req.params
.zipcode and pass it down to the routeWeather function. Note that there is no
underscore on the request parameter this time. Finally, we use the same
function as before to start the Express.js server and listen to port 3000.

### Transpiling and Running the Code
To transpile the code with the TypeScript compiler to JavaScript, run TSC with npx on the command line:

```bash
$ npx tsc
```

TSC generates two new files, index.js and routes.js, from the TypeScript files. Start the server from your command line with the regular Node.js call:

```bash
$ node index.js
Listening on 3000
```

Now visit `http://localhost:3000/api/weather/12345` in your browser. 

You should see

```
zipcode	"12345"
weather	"sunny"
temp	35
```

---

## V4 Barebones Next.js

### Initialization

To manually create a new Next.js app, install the required packages:

```bash
mkdir my-next-app
cd my-next-app
npm install next@latest react@latest react-dom@latest

added 55 packages in 27s

24 packages are looking for funding
  run `npm fund` for details
```


### Add Scripts

Then, add the following scripts to the newly created package.json file:
```json
{
  "scripts": {
    "dev": "next dev",
    "build": "next build",
    "start": "next start",
    "lint": "next lint"
  },
  "dependencies": {
    "next": "^15.3.1",
    "react": "^19.1.0",
    "react-dom": "^19.1.0"
  }
}
```

These scripts refer to the different stages of developing an application:

    next dev: Starts the development server.
    next build: Builds the application for production.
    next start: Starts the production server.
    next lint: Runs ESLint.


### Create A Landing Page

Next.js uses file-system routing, which means the routes in your application are determined by how you structure your files.

Create an `app` folder. Then, inside app, create a `layout.jsx file`. 
```bash
mkdir app
cd app
touch layout.jsx
```

This file is the root layout. It's required and must contain the <html> and <body> tags.

add the following code
```jsx
export default function RootLayout( { children } ) {
  return (
    <html lang="en">
      <body>{children}</body>
    </html>
  )
}
```

This component takes a `children` prop which will be used to render the other components we define

Create a home page `app/page.jsx`

```bash
touch page.jsx
```

add the following

```jsx
export default function Page() {
  return <h1>Hello, Next.js!</h1>
}
```

Both layout.tsx and page.tsx will be rendered when the user visits the root of your application (/).


```jsx
<RootLayout>
  <Page/>
</RootLayout>
```

next execute `npm run dev`:

```bash
npm run dev

> dev
> next dev

   ▲ Next.js 15.3.1
   - Local:        http://localhost:3000
   - Network:      http://10.255.255.254:3000

 ✓ Starting...
```

this command, recognizing our current file configuration and content, will finish setting up the project, as well as providing typescript dependencies.


connect to `localhost:3000` and receive the following output in the terminal window

```bash
 ○ Compiling / ...
 ✓ Compiled / in 2.8s (647 modules)
 GET / 200 in 3312ms
```

if everything worked correctly, you should see `Hello, Next.js!` in the browser

---

### File Based Routing

The Next.js  `Pages Router` has a `file-system based` router built on the concept of pages. When a file is configured properly, it's automatically available as a route, or new endpoint, e.g. a unique URL that maps to a page in our app.

In Next.js, we create new routes (pages) by creating sub-folders in the root/app directory with a file called `page.jsx/tsx` and whatever you export from the new file is Nextjs displays on that new page.


Be precise with directories and files

Next.js relies on directory and filename conventions. This is convenient for
producing desired behaviour by default, but can lead to confusing errors in some
situations. 

Keep in mind:

app/ and pages/ directories are special, so avoid directories with those names
except in the exact places where Next.js expects them for routing.

There are special filenames that have specific behavior, such as page.tsx.
They are documented in Next.js’s file conventions. Only use those names as
intended by Next.js.
https://nextjs.org/docs/app/building-your-application/routing#file-conventions

Avoid whitespace in paths and filenames.

Avoid extraneous empty directories.


### Nested Page Routes

We will explore nested routes

create a subdirectory within the `app` directory

```bash
mkdir about
cd about
touch page.jsx
```

and add the code 

```jsx
export default function AboutPage() {
    return <h1>Welcome to the About Page!</h1>
}
```
terminate the current server instance and rerun `npm run dev` for the server to recognize the added folder structure

Then connect to `http://localhost:3000/about` 

your terminal window will then show next.js handling a recompile of your project

```bash
 ○ Compiling /about ...
 ✓ Compiled /about in 947ms (649 modules)
 GET /about 200 in 1090ms
 GET / 200 in 64ms
 ```

and you should be met with `Welcome to the About Page!`

---

## V5 create-next-app


### Initialization

Follow these steps to create the next version of our project using create-next-app

```bash
mkdir create-my-next-app
cd create-my-next-app
npx create-next-app@latest .
✔ Would you like to use TypeScript? … No / (Yes)
✔ Would you like to use ESLint? … No / (Yes)
✔ Would you like to use Tailwind CSS? … No / (Yes)
✔ Would you like your code inside a `src/` directory? … (No) / Yes
✔ Would you like to use App Router? (recommended) … No / (Yes)
✔ Would you like to use Turbopack for `next dev`? … (No) / Yes
✔ Would you like to customize the import alias (`@/*` by default)? … (No) / Yes
Creating a new Next.js app in /mnt/d/git/practice-projects/complete-developer-practice/sample-next/create-my-next-app.

Using npm.

Initializing project with template: app-tw


Installing dependencies:
- react
- react-dom
- next

Installing devDependencies:
- typescript
- @types/node
- @types/react
- @types/react-dom
- @tailwindcss/postcss
- tailwindcss
- eslint
- eslint-config-next
- @eslint/eslintrc


added 436 packages, and audited 437 packages in 55s

165 packages are looking for funding
  run `npm fund` for details

found 0 vulnerabilities
Success! Created v5 at /mnt/d/git/practice-projects/complete-developer-practice/sample-next/create-my-next-app
```

We create a new folder, switch to it, and then initialize a new Next.js project. 

We use the npx command instead of npm because npx doesn’t require us to install anything as a dependency
or development dependency. 

When asked configuration questions follow the answers in `(...)` above.

The script creates a complete sample project with all necessary files and folders. Finally, it installs the dependencies and development dependencies through npm.


### App Router vs Page Router
Use App Router. From the Next.js Page Router docs:

    Before Next.js 13, the Pages Router was the main way to create routes in Next.js. It used an intuitive file-system router to map each file to a route. The Pages Router is still supported in newer versions of Next.js, but we recommend migrating to the new App Router to leverage React’s latest features.

While some of the newer React features available with App Router aren’t needed
for a static blog, App Router is the default in the latest versions of the Next.js CLI.
You can use a static blog built with App Router as a stepping stone to towards
more dynamic and interactive sites.


When searching for or within Next.js documentation, make sure you’re
looking at the modern “App Router” version of the docs. There is an on-page
toggle to switch between “App Router” and the older “Page Router”. There are
also tabs for “App Router” and “Page Router” results in the Next.js
documentation search command menu. Outside of the Next.js docs, there are
lots of links to the older “Page Router” so keep an eye out for changes to the
URL and on-page toggle.




### Project Structure

We can then spin up the server using `npm run dev`

```bash
$ npm run dev
> create-my-next-app@0.1.0 dev
> next dev

   ▲ Next.js 15.3.1
   - Local:        http://localhost:3000
   - Network:      http://10.255.255.254:3000

 ✓ Starting...
 ✓ Ready in 8.7s
```

Visit the provided URL in your browser, which will prompt the node server to compile, producing this output in the terminal

```bash
 ○ Compiling / ...
 ✓ Compiled / in 3.7s (690 modules)
 GET / 200 in 4334ms
```

You should see a default page provided by `create-next-app`

    NOTE: If a previous project is running on port 3000, the script opts for the next open port, 3001 for example. Either adjust the following project configuration accordingly or terminate the terminal instance running the server on port 3000 and rerun `npm run dev`

While this new project as a more robust directory structure and verbose file contents the structure of the `/app` folder should be familiar as well as the `page.tsx` and `layout.tsx`


New additions to  `/app` are `globals.css` where, as the name suggests, global css styles are defined and `favicon.ico` where an icon is defined.

New additions to the project root are `/public` which is an optional directory where static assets are defined, like the `.svg` files used in the default project provided.

The remainder of the files defined in the project root are config related files, we will not need to pay these any mind at this time.

We will start gutting the default project to be used for our own purposes.

remove the contents of `/public` and delete `/app/favicon.ico`

alter `/app/page.tsx`

```tsx
export default function Home() {
  return <h1> Welcome Home! </h1>;
}
```

alter `/app/layout.tsx`

```tsx
import "./globals.css";

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html lang="en">
      <body>
        {children}
      </body>
    </html>
  );
}
```

restart the node server and run

```bash
$ npm run dev
> create-my-next-app@0.1.0 dev
> next dev

   ▲ Next.js 15.3.1
   - Local:        http://localhost:3000
   - Network:      http://10.255.255.254:3000

 ✓ Starting...
 ✓ Ready in 10.7s
```

Visit the provided URL in your browser, which will prompt the node server to compile, producing this output in the terminal

```bash
 ○ Compiling / ...
 ✓ Compiled / in 3.7s (690 modules)
 GET / 200 in 4334ms
```

You should see `Welcome Home!`

for the next example, it will be helpful to have an additional route in this project, so follow the steps in the `Making An About Page` section above and add a simple about page to this project, however, use the typescript file extension this time.

create a subdirectory within the `app` directory

```bash
mkdir about
cd about
touch page.tsx
```

and add the code 

```jsx
export default function AboutPage() {
    return <h1>Welcome to the About Page!</h1>
}
```

terminate the current server instance and rerun `npm run dev` for the server to recognize the added folder structure

Then connect to `http://localhost:3000/about` 

### Layouts

The React model allows us to deconstruct a page into a series of components. 

Pages, as we have been making use of in previous examples, are only rendered for a specific URL. Changing URL, aka changing routes, will always render a different page component, the one defined at that route level in the project file structure. 

However, many website reuse components between pages. A layout is UI that is shared between multiple pages. On navigation, layouts preserve state, remain interactive, and do not rerender. Layouts in Next.js is a higher-order component (HOC) that wraps your application’s pages. It allows you to define a consistent structure and appearance for all your pages, making it easy to maintain a consistent user experience. Layouts are a great way to reuse code and save time, especially when building larger applications.

You can define a layout by default exporting a React component from a `layout.tsx` file in much the same way we have been doing so with `page.tsx` files. The component should accept a `children` prop which is where the component defined in `page.tsx` on the same route level will be rendered.

The layout defined in the root of the project, `/app/layout.tsx`, is known as a root layout and will remain rendered no matter how many levels deep we are nested in a given route.

For example, you might have the same navigation bar and footer on every page.

replace the code in `/app/layout.tsx` with:

```jsx
export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html lang="en">
      <body>

        <header>
          <nav>
            <ul>
              <li>Home</li>
              <li>About</li>
            </ul>
          </nav>
        </header>

        <main>{children}</main>

        <footer>&copy; {new Date().getFullYear()} Web Dev, LLC.</footer>

      </body>
    </html>
  )
}
```

terminate the current server instance and rerun `npm run dev` for the server to recognize the code edits.

Connect to `http://localhost:3000` 

and notice the header and footer content above and below the content defined in `/app/page.tsx`

Then connect to `http://localhost:3000/about` 

and notice the same header and footer content above and below the content defined in `/app/about/page.tsx`


### Adding Navigation

We could use an anchor tag, an href attribute, and a relative path URL to navigate between pages using our navbar

```jsx
<li><a href="/">Home</a></li>
<li><a href="/about">About</a></li>
```

however, this makes for a slow transition between pages, as everything is rerendered

Next provides 4 ways to navigate between routes:
https://nextjs.org/docs/app/building-your-application/routing/linking-and-navigating

We are going to use the `Link` component

```jsx
import "./globals.css"
import Link from "next/link"

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html lang="en">
      <body>

        <header>
          <nav>
            <ul>
              <li><Link href="/">Home</Link></li>
              <li><Link href="/about">About</Link></li>
            </ul>
          </nav>
        </header>

        <main>{children}</main>

        <footer>&copy; {new Date().getFullYear()} Web Dev, LLC.</footer>

      </body>
    </html>
  )
}
```

We add an import for the `Link` component

and replace the anchor tags with `Link` tags

The link component enables client side navigation, which means we no longer need a round trip to the server

A further optimization, whenever a link is in view on a page, Next will prefetch the route

a powerful feature is that the Link component will maintain react state between navigation





### TypeScript Types and Custom Components

We have seen above, to create new routes, we add subfolder to the `/app` directory with a `page.jsx/tsx`

However, if we provide a subfolder and do not include a `page.jsx/tsx`, it will not create a new route and we can put whatever content we want in there.

This will allow us to group custom components and TypeScript type files with the routes they correspond to.


#### Custom Components


Now that we have a navbar and footer, lets separate these components into their own folder.

create a new subfolder `/app/components` and create two files `/app/components/Navbar.tsx` `/app/components/Footer.tsx`

```bash
cd ..
mkdir components
cd components
touch Navbar.tsx Footer.tsx
```

Move the navbar code into it's own function
```tsx
import Link from "next/link"

export function Navbar()
{
  return(
    <header>
      <nav>
        <ul>
          <li><Link href="/">Home</Link></li>
          <li><Link href="/about">About</Link></li>
        </ul>
      </nav>
    </header>
  )
}
```

and do the same for the footer

```tsx
export function Footer()
{
    return <footer>&copy; {new Date().getFullYear()} Web Dev, LLC.</footer>
}
```

then import our new components

```tsx
import "./globals.css"
import type { RootLayoutProps } from "@/app/types"
import { Navbar } from "./components/Navbar"
import { Footer } from "./components/Footer"

export default function RootLayout({
  children,
}: Readonly<{
  children: React.ReactNode;
}>) {
  return (
    <html lang="en">
      <body>

        <Navbar/>

        <main>{children}</main>

        <Footer/>

      </body>
    </html>
  )
}
```

#### TypeScript Types

TypeScript type defined in our root layout in a new type file.

create a new subdir `/app/types` as well as a new file `/app/types/index.ts`

```bash
cd ..
mkdir types
cd types
touch index.ts
```

and define within it

```ts
export type RootLayoutProps = Readonly<{
  children: React.ReactNode;
}>
```

here we export a type identical to the one currently found in our root layout

we can now replace the inline type definition on our root layout 

```jsx
import "./globals.css"
import type { RootLayoutProps } from "@/app/types"
import Link from "next/link"

export default function RootLayout({ children } : RootLayoutProps) {
  return (
    <html lang="en">
      <body>

        <Navbar/>

        <main>{children}</main>

        <Footer/>

      </body>
    </html>
  )
}
```

### Dynamic Routes

When you don't know the exact URL ahead of time and want to create URLs from dynamic data, called Dynamic Routes

We will make an example blog page that shows excerpts of individual posts and links to pages containing the individual post

first we will add the posts page to our navbar

```tsx
import Link from "next/link"

export function Navbar()
{
    return(
        <header>
          <nav>
            <ul>
              <li><Link href="/">Home</Link></li>
              <li><Link href="/about">About</Link></li>
              <li><Link href="/posts">Posts</Link></li>
            </ul>
          </nav>
        </header>
    )
}
```


return to the root folder `/app` and create a new subdirectory `/app/posts` as well as an `/app/posts/page.tsx`

```bash
cd ..
mkdir posts
cd posts
touch page.tsx
```

include the code

```tsx
export default async function PostsPage() {
  const res = await fetch("https://jsonplaceholder.typicode.com/posts")
  const posts = await res.json()

  return (
    <div>
      <h1>Blog Posts</h1>
      <ul>
        {posts.map((post) => (
          <li key={post.id}>
            <h2>{post.title}</h2>
          </li>
        ))}
      </ul>
    </div>
  )
}
```
Here we use server component, denoted by the async function, to fetch data with `await` before sending HTML/JSON to the client

then map the posts into an unordered list

we must add a new typescript type to `/app/types/index.ts`


```tsx
export type Post = Readonly<{
    userId: number,
    id: number,
    title: string,
    body: string,
}>
```

and import this type and specify the type for the map function parameter

```tsx
import Link from "next/link"
import type { Post } from "@/app/types"

export default async function PostsPage() {
  const res = await fetch("https://jsonplaceholder.typicode.com/posts")
  const posts = await res.json()

  return (
    <div>
      <h1>Blog Posts</h1>
      <ul>
        {posts.map((post: Post) => (
          <li key={post.id}>
            <h2>{post.title}</h2>
          </li>
        ))}
      </ul>
    </div>
  )
}
```

we will now add routing

```tsx
import Link from "next/link"

export default async function PostsPage() {
  const res = await fetch("https://jsonplaceholder.typicode.com/posts")
  const posts = await res.json()

  return (
    <div>
      <h1>Blog Posts</h1>
      <ul>
        {posts.map((post) => (
          <li key={post.id}>
            <Link href={`/posts/${post.id}`}><h2>{post.title}</h2></Link>
          </li>
        ))}
      </ul>
    </div>
  )
}
```

we import the Next.js Link component and add a Link to each blog post (surrounding the `h2` elements) that leads to {`/posts/${post.id}`}

These Links will lead to non-existing pages. We'll fix that next. However, if we click on them, we will see that the URL they take us two includes the post id.

to create a Dynamic route, we create a folder whose name represents what the path contains, and surround that name in square brackets.

much like a typical nested route, we must specify the dynamic route via a nested subfolder and create a new `page.tsx` file

in this case, as we are using the `post.id` member, lets call the subfolder `[id]` and create `/app/posts/[id]/page.tsx`

```bash
mkdir [id]
cd [id]
touch page.tsx
```

```tsx
export default async function PostDetail({
    params,
  }: {
    params: { id: string }
  }) {  
    const { id } = await params
    const res = await fetch(`https://jsonplaceholder.typicode.com/posts/${id}`)
    const post = await res.json()
  
    return (
      <>
        <h1>{post.title}</h1>
        <p>{post.body}</p>
      </>
    )
}
```


### API Routes

In addition to a user-friendly interface, a full- stack application might also
need a machine-readable interface. 

Here we will create REST API to return all blog posts, as well as a dynamic api route to return individual blog posts


With Next.js, we can design and create APIs via the same patterns we use for pages. Each file in the `/app/api/` folder is a single API endpoint, and we can define nested API routes in the same way we define nested page routes. 

However, unlike page routes, API routes are not React components. Instead, they are async functions that take a `Request` parameter and return a `NextResponse` and JSON data.

There are two caveats you need to remember when it comes to API routes. 

First, they do not specify a Cross- Origin Resource Sharing (CORS) header by default. This set of HTTP headers, most notably the Access-Control-Allow-Origin header, lets a server define the origins from which client-side scripts can request resources. If you want client-side scripts running in websites on third-party domains to access your API endpoints, you’ll need to add additional middleware to enable CORS directly in the Next.js server. Other wise, external requests will prompt a CORS error. This isn’t specific to Next.js; Express.js and most other server frameworks require you to do the same.

The second caveat is that static exports done by running next export do not support API routes. They rely on the built-in Next.js server and cannot run as static files.


return to the root folder `/app` and create a new directory structure `/app/api/posts` as well as an `/app/api/posts/route.ts` file

```bash
cd ..
mkdir -p api/posts
cd api/posts
touch route.ts
```

NOTE: the -p flag creates the parent directory if it does not exist

```ts
import { NextResponse } from 'next/server';

export async function GET(
  request: Request
) {
  try {
    const url = "https://jsonplaceholder.typicode.com/posts";
    const result = await fetch(url);
    const data = await result.json();

    return NextResponse.json(data);
  } 
  catch (error) {
    return NextResponse.json({ error: 'Internal Server Error' }, { status: 500 });
  }  
}
```

We import the `NextResponse` type for the API response from the Next.js package.
We export and define the async function GET HTTP method and specify the required parameter and type `request: Request`

we open a try block and make await calls to fetch the posts data
we specify a return statement to return the API response

open a catch block to handle any errors by returning an API response with no content and a status code of 500, for an Internal Server Error


### Dynamic API Routes


```bash
mkdir [id]
cd [id]
touch route.ts
```

```ts
import { NextResponse } from 'next/server';

export async function GET( 
  request: Request,
  {params} : {params : {id : string} }
) {
  const { id } = await params;
  try {
    const url = `https://jsonplaceholder.typicode.com/posts/${id}`;
    const result = await fetch(url);

    if (!result.ok) {
      return NextResponse.json({ error: 'Post not found' }, { status: 404 });
    }
    
    const data = await result.json();

    return NextResponse.json(data)
  }
  catch (error) {
    return NextResponse.json({ error: 'Internal Server Error' }, { status: 500 });
  }  
}
```


### Styling the Application
To add styles to our Next.js application, we create regular CSS files, writ-
ten without the vendor prefixes used in other frameworks. Later, Next.js’s
postprocessor will add necessary properties to generate backward- compatible
styles. While CSS syntax is beyond the scope of this book, this section
describes how to use Next.js’s two kinds of CSS styles: global styles and locally
scoped component styles, defined in CSS modules.