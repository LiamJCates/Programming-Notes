# Components

As the Web became more interactive, logic increasingly determined content. JavaScript was in charge of the HTML! This is why in React, rendering logic and markup live together in the same place — components. React embraces the fact that rendering logic is inherently coupled with other UI logic: how events are handled, how the state changes over time, and how data is prepared for display. Instead of artificially separating technologies by putting markup and logic in separate files, React separates concerns with loosely coupled units called “components” that contain both. Keeping a button’s rendering logic and markup together ensures that they stay in sync with each other on every edit. Conversely, details that are unrelated, such as the button’s markup and a sidebar’s markup, are isolated from each other, making it safer to change either of them on their own.

---

## Elements

React allows you to break a UI (User Interface) down into independent reusable chunks.

Elements are the smallest building blocks of React apps.

An element describes what you want to see on the screen:

```js
const element = <h1>Hello, world</h1>;
```

Unlike browser DOM elements, React elements are plain javascript objects, and are cheap to create. React DOM takes care of updating the DOM to match the React elements.

React elements are specified using an html like syntax you see above, called JSX.

more on JSX [here](JSX.md)

---

### Rendering an Element into the DOM


#### root node

```html
<div id="root"></div>
```

We call this a “root” DOM node because everything inside it will be managed by React DOM.

Applications built with just React usually have a single root DOM node. If you are integrating React into an existing app, you may have as many isolated root DOM nodes as you like.

To render a React element into a root DOM node, pass both to ReactDOM.render():

```js
import ReactDOM from "react-dom"

const element = <h1>Hello, world</h1>;
ReactDOM.render(element, document.getElementById('root'));
```

The use of a \<div> and id of "root" is just convention, any HTML element type and can be used, and any method of selecting an element to be used is valid.

Another way of doing this without importing the whole of ReactDOM

```jsx
import { createElement } from "react"
import { createRoot } from "react-dom/client"

const root = createRoot(document.getElementById("root"))
const reactElement = createElement("h1", null, "Hello World!")

root.render(
    reactElement
)
```

---

### Updating the Rendered Element

React elements are immutable. Once you create an element, you can’t change its children or attributes. An element is like a single frame in a movie: it represents the UI at a certain point in time.

With our knowledge so far, the only way to update the UI is to create a new element, and pass it to ReactDOM.render().

Consider this ticking clock example:

```js
function tick() {
  const element = (
    <div>
      <h1>Hello, world!</h1>
      <h2>It is {new Date().toLocaleTimeString()}.</h2>
    </div>
  );
  ReactDOM.render(element, document.getElementById('root'));
}

setInterval(tick, 1000);
```

It calls ReactDOM.render() every second from a setInterval() callback.

Note:
In practice, most React apps only call ReactDOM.render() once. We will eventually learn how such code gets encapsulated into stateful components.


#### React Only Updates What’s Necessary

React DOM compares the element and its children to the previous one, and only applies necessary DOM updates.

In the previous example, even though we create an element describing the whole UI tree on every tick, only the text node whose contents have changed gets updated by React DOM.

---

## Components

You can find a detailed component API reference [here](https://reactjs.org/docs/react-component.html)

One might confuse elements with a more widely known concept of “components”. Elements are what components are “made of”.

Conceptually, components are like JavaScript functions:
	(optionally) accept an arbitrary input parameter (called “props” which stands for properties)
	return React elements describing what should appear on the screen.

The first thing to understand is that everything on screen in a React app is part of a component. Essentially, a React app is just components within components within components. So developers don’t build pages in React; they build components.

A React component can be one of two types. It can be either a function component or a class component. Both types can be stateful and have side effects, or they can be purely presentational. You should learn them both, but prefer to use function components over class components because they're recommended by the [React documentation](https://react.dev/reference/react/Component#alternatives).

---

### Function Component

```js
const MyComponent = () => {
	return(
		<domElementOrComponent ... />
		);
}
```

---

### Class Component

```jsx
class MyComponent extends React.Component {
	render () {
		return (
		<domElementOrComponent ... />
		);
	}
}
```

The remainder of this page will focus on function components.

Class components are detailed [here](./Class%20Components.md)

---

## Function Components

The simplest way to define a component is to write a JavaScript function.
We call such components “function components” because they are literally JavaScript functions. 

```js
import { createElement } from "react"
import { createRoot } from "react-dom/client"

function Welcome() {
  return <h1>Hello, World!</h1>;
}

const root = createRoot(document.getElementById("root"))

root.render(
    <\Welcome>
)
```

The Welcome function is a valid React component because it returns a React element.

    NOTE: React components must be capitalized or they will not function as expected. React uses the capitalization to tell the difference between an HTML tag and an instance of a React component. For example, \<div /> represents an HTML div tag, but \<Welcome /> represents a component and requires Welcome to be in scope.

---

### Why use Functional Components

ReactJS functional components offer several benefits over class components, including:

    Simplicity: simpler syntax and easier to read than class components, making them ideal for small to medium-sized projects with limited need for inheritance.
    Performance: faster than class components because they don’t use the this keyword, which can slow down rendering.
    Testability: easier to test because they are stateless and don’t rely on lifecycle methods.
    Reusability: be reused across multiple projects, making them a great choice for building component libraries.

Functional components should be used whenever possible because they are simpler, easier to test, and more performant than class components. 

---

### Rendering a Component

Previously, we only encountered React elements that represent DOM tags:

```js
const element = <p>Hello, World!</p>;
```

However, elements can also represent user-defined components:

```js
const element = <Welcome name="Sara"/>;
```

When React sees an element representing a user-defined component, it passes JSX attributes and children to this component as a single object. We call this object “props”.

```js
function Welcome(props) {  
  return <h1>Hello, {props.name}</h1>;
}

const element = <Welcome name="Sara" />;
ReactDOM.render(
  element,
  document.getElementById('root')
);
```

Let’s recap what happens in this example:

    We call ReactDOM.render() with the <Welcome name="Sara" /> element.
    React calls the Welcome component with {name: 'Sara'} as the props.
    Our Welcome component returns a <h1>Hello, Sara</h1> element as the result.
    React DOM efficiently updates the DOM to match <h1>Hello, Sara</h1>.


More information on props [here](./Props.md)

---

### Composing Components

Components can refer to other components in their output. This lets us use the same component abstraction for any level of detail. A button, a form, a dialog, a screen: in React apps, all those are commonly expressed as components.

For example, we can create an App component that renders Welcome many times:

```js
function Welcome(props) {
  return <h1>Hello, {props.name}</h1>;
}

function App() {
  return (
    <div>
      <Welcome name="Sara" />
			<Welcome name="Cahal" />
			<Welcome name="Edite" />
		</div>
  );
}

ReactDOM.render(
  <App />,
  document.getElementById('root')
);
```


By convention, React apps have a single \<App/> component that is the ancestor of (includes) all other components. However, if you integrate React into an existing app, you might start bottom-up with a small component like Button and gradually work your way to the top of the view hierarchy.

---

### Extracting Components

Increase maintainability and seperate concerns by spliting components into smaller logical units.

For example, consider this Comment component:
```js
function Comment(props) {
  return (
    <div className="Comment">
      <div className="UserInfo">
        <img className="Avatar"
          src={props.author.avatarUrl}
          alt={props.author.name}
        />
        <div className="UserInfo-name">
          {props.author.name}
        </div>
      </div>
      <div className="Comment-text">
        {props.text}
      </div>
      <div className="Comment-date">
        {formatDate(props.date)}
      </div>
    </div>
  );
}
```

It accepts author (an object), text (a string), and date (a date) as props, and describes a comment on a social media website.

This component can be tricky to change because of all the nesting, and it is also hard to reuse individual parts of it. Let’s extract a few components from it.

First, we will extract Avatar:

```js
function Avatar(props) {
  return (
    <img className="Avatar"
			src={props.user.avatarUrl}
			alt={props.user.name}
		/>  
	);
}
```

The Avatar doesn’t need to know that it is being rendered inside a Comment. This is why we have given its prop a more generic name: user rather than author.

We recommend naming props from the component’s own point of view rather than the context in which it is being used.

Next, we will extract a UserInfo component that renders an Avatar next to the user’s name:

```js
function UserInfo(props) {
  return (
    <div className="UserInfo">
      <Avatar user={props.user} />
      <div className="UserInfo-name">
        {props.user.name}
      </div>
    </div>  );
}
```

This lets us simplify Comment:

```js
function Comment(props) {
  return (
    <div className="Comment">
      <UserInfo user={props.author} />
      <div className="Comment-text">
        {props.text}
      </div>
      <div className="Comment-date">
        {formatDate(props.date)}
      </div>
    </div>
  );
}
```

Extracting components might seem like grunt work at first, but having a palette of reusable components pays off in larger apps. A good rule of thumb is that if a part of your UI is used several times (Button, Panel, Avatar), or is complex enough on its own (App, FeedStory, Comment), it is a good candidate to be extracted to a separate component.

---

### Exporting Components

A component can use functionality created elsewhere, and share itself with other components via importing and exporting! 

export components so that parent components can use it as a child throughout a project.

```js
//in Greeting.jsx
function Greeting() {
  return <h1>&quot;I swear by my pretty floral bonnet, I will end you.&quot;</h1>;
}

export default Greeting;
```

The import should look something like this:

```js
//import React from 'react'; no longer necessary (See NOTE below)
import { StrictMode } from "react";
import { createRoot } from "react-dom/client";
import Greeting from "./Greeting.jsx";
import "./index.css";

createRoot(document.getElementById("root")).render(
  <StrictMode>
    <Greeting />
  </StrictMode>,
);
```

NOTE: Previous to React v17.0, it was necessary to import React in your JavaScript files that used React components