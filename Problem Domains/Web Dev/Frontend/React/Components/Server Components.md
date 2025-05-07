# Server Components










































https://www.joshwcomeau.com/react/server-components/


Server Components are a new type of Component that renders ahead of time, before bundling, in an environment separate from your client app or SSR server.

This separate environment is the “server” in React Server Components. Server Components can run once at build time on your CI server, or they can be run for each request using a web server.



### Server Side Rendering

To put React Server Components in context, it's helpful to understand how Server Side Rendering (SSR) works.

pre SSR The user would receive an HTML file that looked like this:
```html
<!DOCTYPE html>
<html>
  <body>
    <div id="root"></div>
    <script src="/static/js/bundle.js"></script>
  </body>
</html>
```

That bundle.js script includes everything we need to mount and run the application, including React, other third-party dependencies, and all of the code we've written.

Once the JS has been downloaded and parsed, React springs into action, conjuring all of the DOM nodes for our entire application, and housing it in that empty `<div id="root">`.

The problem with this approach is that it takes time to do all of that work. And while it's all happening, the user is staring at a blank white screen. This problem tends to get worse over time: every new feature we ship adds more kilobytes to our JavaScript bundle, prolonging the amount of time that the user has to sit and wait.

Server Side Rendering was designed to improve this experience. Instead of sending an empty HTML file, the server will render our application to generate the actual HTML. The user receives a fully-formed HTML document.

That HTML file will still include the `<script>` tag, since we still need React to run on the client, to handle any interactivity. But we configure React to work a little bit differently in-browser: instead of conjuring all of the DOM nodes from scratch, it instead adopts the existing HTML. This process is known as hydration.

Once the JS bundle has been downloaded, React will quickly run through our entire application, building up a virtual sketch of the UI, and “fitting” it to the real DOM, attaching event handlers, firing off any effects, and so on.

And so, that's SSR in a nutshell. A server generates the initial HTML so that users don't have to stare at an empty white page while the JS bundles are downloaded and parsed. Client-side React then picks up where server-side React left off, adopting the DOM and sprinkling in the interactivity.

#### An umbrella term

When we talk about Server Side Rendering, we typically imagine a flow that looks like this:

    User visits myWebsite.com.
    A Node.js server receives the request, and immediately renders the React application, generating the HTML.
    That freshly-baked HTML is sent to the client.

This is one possible way to implement Server Side Rendering, but it's not the only one. Another option is to generate the HTML when we build the application.

Typically, React applications need to be compiled, transforming JSX into plain ol’ JavaScript, and bundling all of our modules. What if, during that same process, we “pre-rendered” all of the HTML for all of our different routes?

This is commonly known as static site generation (SSG). It's a sub-variant of Server Side Rendering.

“Server Side Rendering” can be thought of as an umbrella term that includes several different rendering strategies. They all have one thing in common: the initial render happens in a server runtime like Node.js, using the ReactDOMServer APIs. It doesn't actually matter when this happens, whether it's on-demand or at compile-time. Either way, it's Server Side Rendering.


### Data-Fetching in React. 
 
Typically, we've had two separate applications that communicate over the network:

    A client-side React app

    A server-side REST API




Server Components without a Server

Server components can run at build time to read from the filesystem or fetch static content, so a web server is not required. For example, you may want to read static data from a content management system.

Without Server Components, it’s common to fetch static data on the client with an Effect:

```jsx
// bundle.js
import marked from 'marked'; // 35.9K (11.2K gzipped)
import sanitizeHtml from 'sanitize-html'; // 206K (63.3K gzipped)

function Page({page}) {
  const [content, setContent] = useState('');
  // NOTE: loads *after* first page render.
  useEffect(() => {
    fetch(`/api/content/${page}`).then((data) => {
      setContent(data.content);
    });
  }, [page]);
  
  return <div>{sanitizeHtml(marked(content))}</div>;
}
```
```jsx
// api.js
app.get(`/api/content/:page`, async (req, res) => {
  const page = req.params.page;
  const content = await file.readFile(`${page}.md`);
  res.send({content});
});
```

This pattern means users need to download and parse an additional 75K (gzipped) of libraries, and wait for a second request to fetch the data after the page loads, just to render static content that will not change for the lifetime of the page.

With Server Components, you can render these components once at build time:

```jsx
import marked from 'marked'; // Not included in bundle
import sanitizeHtml from 'sanitize-html'; // Not included in bundle

async function Page({page}) {
  // NOTE: loads *during* render, when the app is built.
  const content = await file.readFile(`${page}.md`);
  
  return <div>{sanitizeHtml(marked(content))}</div>;
}
```

The rendered output can then be server-side rendered (SSR) to HTML and uploaded to a CDN. When the app loads, the client will not see the original Page component, or the expensive libraries for rendering the markdown. The client will only see the rendered output:
```html
<div><!-- html for markdown --></div>
```
This means the content is visible during first page load, and the bundle does not include the expensive libraries needed to render the static content.
Note

You may notice that the Server Component above is an async function:

```jsx
async function Page({page}) {
  //...
}
```

Async Components are a new feature of Server Components that allow you to await in render, we will cover them below.

---

### Server Components with a Server

Server Components can also run on a web server during a request for a page, letting you access your data layer without having to build an API. They are rendered before your application is bundled, and can pass data and JSX as props to Client Components.

Without Server Components, it’s common to fetch dynamic data on the client in an Effect:
```jsx
// bundle.js
function Note({id}) {
  const [note, setNote] = useState('');
  // NOTE: loads *after* first render.
  useEffect(() => {
    fetch(`/api/notes/${id}`).then(data => {
      setNote(data.note);
    });
  }, [id]);
  
  return (
    <div>
      <Author id={note.authorId} />
      <p>{note}</p>
    </div>
  );
}

function Author({id}) {
  const [author, setAuthor] = useState('');
  // NOTE: loads *after* Note renders.
  // Causing an expensive client-server waterfall.
  useEffect(() => {
    fetch(`/api/authors/${id}`).then(data => {
      setAuthor(data.author);
    });
  }, [id]);

  return <span>By: {author.name}</span>;
}
```
```jsx
// api
import db from './database';

app.get(`/api/notes/:id`, async (req, res) => {
  const note = await db.notes.get(id);
  res.send({note});
});

app.get(`/api/authors/:id`, async (req, res) => {
  const author = await db.authors.get(id);
  res.send({author});
});
```

With Server Components, you can read the data and render it in the component:

```jsx
import db from './database';

async function Note({id}) {
  // NOTE: loads *during* render.
  const note = await db.notes.get(id);
  return (
    <div>
      <Author id={note.authorId} />
      <p>{note}</p>
    </div>
  );
}

async function Author({id}) {
  // NOTE: loads *after* Note,
  // but is fast if data is co-located.
  const author = await db.authors.get(id);
  return <span>By: {author.name}</span>;
}
```

The bundler then combines the data, rendered Server Components and dynamic Client Components into a bundle. Optionally, that bundle can then be server-side rendered (SSR) to create the initial HTML for the page. When the page loads, the browser does not see the original Note and Author components; only the rendered output is sent to the client:

```jsx
<div>
  <span>By: The React Team</span>
  <p>React 19 is...</p>
</div>
```

Server Components can be made dynamic by re-fetching them from a server, where they can access the data and render again. This new application architecture combines the simple “request/response” mental model of server-centric Multi-Page Apps with the seamless interactivity of client-centric Single-Page Apps, giving you the best of both worlds.

---

### Adding interactivity to Server Components

Server Components are not sent to the browser, so they cannot use interactive APIs like useState. To add interactivity to Server Components, you can compose them with Client Component using the "use client" directive.

In the following example, the Notes Server Component imports an Expandable Client Component that uses state to toggle its expanded state:

```jsx
// Server Component
import Expandable from './Expandable';

async function Notes() {
  const notes = await db.notes.getAll();
  return (
    <div>
      {notes.map(note => (
        <Expandable key={note.id}>
          <p note={note} />
        </Expandable>
      ))}
    </div>
  )
}
```
```jsx
// Client Component
"use client"

export default function Expandable({children}) {
  const [expanded, setExpanded] = useState(false);
  return (
    <div>
      <button
        onClick={() => setExpanded(!expanded)}
      >
        Toggle
      </button>
      {expanded && children}
    </div>
  )
}
```
This works by first rendering Notes as a Server Component, and then instructing the bundler to create a bundle for the Client Component Expandable. In the browser, the Client Components will see output of the Server Components passed as props:

```jsx
<head>
  <!-- the bundle for Client Components -->
  <script src="bundle.js" />
</head>
<body>
  <div>
    <Expandable key={1}>
      <p>this is the first note</p>
    </Expandable>
    <Expandable key={2}>
      <p>this is the second note</p>
    </Expandable>
    <!--...-->
  </div> 
</body>
```

---

### Async Components with Server Components

Server Components introduce a new way to write Components using `async/await`. When you await in an `async component`, React will suspend and wait for the promise to resolve before resuming rendering. This works across server/client boundaries with streaming support for Suspense.

You can even create a promise on the server, and await it on the client:
```jsx
// Server Component
import db from './database';

async function Page({id}) {
  // Will suspend the Server Component.
  const note = await db.notes.get(id);
  
  // NOTE: not awaited, will start here and await on the client. 
  const commentsPromise = db.comments.get(note.id);
  return (
    <div>
      {note}
      <Suspense fallback={<p>Loading Comments...</p>}>
        <Comments commentsPromise={commentsPromise} />
      </Suspense>
    </div>
  );
}
```
```jsx
// Client Component
"use client";
import {use} from 'react';

function Comments({commentsPromise}) {
  // NOTE: this will resume the promise from the server.
  // It will suspend until the data is available.
  const comments = use(commentsPromise);
  return comments.map(commment => <p>{comment}</p>);
}
```
The note content is important data for the page to render, so we await it on the server. The comments are below the fold and lower-priority, so we start the promise on the server, and wait for it on the client with the use API. This will Suspend on the client, without blocking the note content from rendering.

Since async components are not supported on the client, we await the promise with use.