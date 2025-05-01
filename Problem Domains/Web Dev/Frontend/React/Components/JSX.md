# JSX

https://react.dev/learn/writing-markup-with-jsx
https://react.dev/learn/javascript-in-jsx-with-curly-braces




## What is JSX

JSX: a syntax extension to JavaScript invented by the React team that looks like HTML but compiles to React.createElement calls at build time

JSX is a syntax extension for JavaScript that lets you write HTML-like markup inside a JavaScript file. 
    It’s not required to use JSX when writing React components, but it does make writing them more concise.
    Most React developers prefer the conciseness of JSX, and most codebases use it.
    JSX also allows React to show more useful error and warning messages.


Each React component is a JavaScript function that may contain some markup that React renders into the browser. React components use a syntax extension called JSX to represent that markup. JSX looks a lot like HTML, but it is a bit stricter and can display dynamic information. 

### Specifying JSX

```jsx
const element = <h1>Hello, world!</h1>;
```

This tag syntax is neither a string nor HTML.
JSX may remind you of a template language, but it comes with the full power of JavaScript.

JSX produces React “elements”.

Essentially, JSX is syntactic sugar for the React createElement function. This function creates a React element, which is a plain object, so JSX compiles down to plain JavaScript objects.


If a tag is empty, you may close it immediately with />, like XML:
```js
const element = <img src"https://i.imgur.com/example.jpg" />;
```

JSX tags may contain children:
```js
const element = (
  <div>
    <h1>Hello!</h1>
    <h2>Good to see you here.</h2>
  </div>
);
```


### The Problem JSX Solves 

While using JSX is not required, it almost always results in less verbos code.
```jsx
// Using JSX
const myElement = <h1>I Love JSX!</h1>;

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(myElement);


// Without JSX

const myElement = React.createElement('h1', {}, 'I do not use JSX!');

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(myElement);
```

JSX allows us to write HTML elements in JavaScript and place them in the DOM without any createElement()  and/or appendChild() methods.

To prevent this:

```jsx
// <h1><span><p></p></span></h1> example
import { createElement } from "react"
import { createRoot } from "react-dom/client"

const root = createRoot(document.getElementById("root"))

const reactElement = 
  createElement("h1", null, 
    createElement("span", null, 
      createElement("p", null, "I'm inside all three")))

console.log(reactElement)

root.render(
    reactElement
)
```






## The Rules of JSX

1. Return a single root element
2. Close tags
3. camelCase most of the things!

### Return a single root element

To return multiple elements from a component, wrap them with a single parent tag.

For example, you can use a `<div>`:
```jsx
<div>
  <h1>Hedy Lamarr's Todos</h1>
  <img 
    src="https://i.imgur.com/yXOvdOSs.jpg" 
    alt="Hedy Lamarr" 
    class="photo"
  >
  <ul>
    ...
  </ul>
</div>
```

#### Using Fragments

If you don’t want to add an extra `<div>` to your markup, you can write <> and </> instead:

```jsx
<>
  <h1>Hedy Lamarr's Todos</h1>
  <img 
    src="https://i.imgur.com/yXOvdOSs.jpg" 
    alt="Hedy Lamarr" 
    className="photo"
  >
  <ul>
    ...
  </ul>
</>
```

This empty tag is called a Fragment. 
Fragments let you group things without leaving any trace in the browser HTML tree.


Why do multiple JSX tags need to be wrapped?

JSX looks like HTML, but under the hood it is transformed into plain JavaScript objects. 

You can’t return two objects from a function without wrapping them into an array. This explains why you also can’t return two JSX tags without wrapping them into another tag or a Fragment.


### Close tags

JSX requires tags to be explicitly closed: self-closing tags like `<img>` must become `<img />`, and wrapping tags like `<li>oranges must be written as <li>oranges</li>`.

This is how Hedy Lamarr’s image and list items look closed:
```jsx
<>
  <img 
    src="https://i.imgur.com/yXOvdOSs.jpg" 
    alt="Hedy Lamarr" 
    className="photo"
   />
  <ul>
    <li>Invent new traffic lights</li>
    <li>Rehearse a movie scene</li>
    <li>Improve the spectrum technology</li>
  </ul>
</>
```

### camelCase

JSX turns into JavaScript and attributes written in JSX become keys of JavaScript objects. In your own components, you will often want to read those attributes into variables. But JavaScript has limitations on variable names. For example, their names can’t contain dashes or be reserved words like class.

This is why, in React, many HTML and SVG attributes are written in camelCase. For example, instead of stroke-width you use strokeWidth. 

Since class is a reserved word, in React you write className instead, named after the corresponding DOM property:

```html
<img 
  src="https://i.imgur.com/yXOvdOSs.jpg" 
  alt="Hedy Lamarr" 
  className="photo"
/>
```

You can find all these attributes in the list of DOM component props. If you get one wrong, don’t worry — React will print a message with a possible correction to the browser console.

NOTE: For historical reasons, aria-* and data-* attributes are written as in HTML with dashes.


### JSX Converter

Pro-tip: Use a JSX Converter
https://transform.tools/html-to-jsx

Converting all these attributes in existing markup can be tedious! We recommend using a converter to translate your existing HTML and SVG to JSX. Converters are very useful in practice, but it’s still worth understanding what is going on so that you can comfortably write JSX on your own.


Here is your final result:

```js
export default function TodoList() {
  return (
    <>
      <h1>Hedy Lamarr's Todos</h1>
      <img 
        src="https://i.imgur.com/yXOvdOSs.jpg" 
        alt="Hedy Lamarr" 
        className="photo" 
      />
      <ul>
        <li>Invent new traffic lights</li>
        <li>Rehearse a movie scene</li>
        <li>Improve the spectrum technology</li>
      </ul>
    </>
  );
}
```







### Embedding Expressions in JSX

Sometimes you will want to add JavaScript logic or reference a dynamic property inside JSX. In this situation, you can use curly braces in your JSX to open a window to JavaScript.

You can only use curly braces in two ways inside JSX:

1. As text directly inside a JSX tag: `<h1>{name}'s To Do List</h1>` works, but `<{tag}>Gregorio Y. Zara's To Do List</{tag}>` will not.
2. As attributes immediately following the = sign: `src={avatar}` will read the avatar variable, but `src="{avatar}"` will pass the string "{avatar}".


```js
const name = 'Josh Perez';
const element = <h1>Hello, {name}</h1>;
ReactDOM.render(
  element,
  document.getElementById('root')
);
```

You can put any valid JavaScript expression inside the curly braces in JSX.

In the example below, we embed the result of calling a JavaScript function, formatName(user), into an `<h1>` element.

```jsx
function formatName(user) {
  return user.firstName + ' ' + user.lastName;
}

const user = {
  firstName: 'Harper',
  lastName: 'Perez'
};

const element = (
  <h1>
    Hello, {formatName(user)}!
  </h1>
);

ReactDOM.render(
  element,
  document.getElementById('root')
);
```

We split JSX over multiple lines for readability. While it isn’t required, when doing this, we also recommend wrapping it in parentheses to avoid the pitfalls of automatic semicolon insertion




### Specifying Attributes with JSX

You may use quotes to specify string literals as attributes:

```js
const element = <div tabIndex="0"></div>;
```

You may also use curly braces to embed a JavaScript expression in an attribute:
```js
const element = <img src={user.avatarUrl}></img>;
```

Don’t put quotes around curly braces when embedding a JavaScript expression in an attribute. You should either use quotes (for string values) or curly braces (for expressions), but not both in the same attribute.

Warning:

Since JSX is closer to JavaScript than to HTML, React DOM uses camelCase property naming convention instead of HTML attribute names.

For example, class becomes className in JSX, and tabindex becomes tabIndex.





### JSX is an Expression Too

After compilation, JSX expressions become regular JavaScript function calls and evaluate to JavaScript objects.

This means that you can use JSX inside of if statements and for loops, assign it to variables, accept it as arguments, and return it from functions:

```js
function getGreeting(user) {
  if (user) {
    return <h1>Hello, {formatName(user)}!</h1>;
  }
  return <h1>Hello, Stranger.</h1>;}
```




### Using “double curlies”: CSS and other objects in JSX

In addition to strings, numbers, and other JavaScript expressions, you can even pass objects in JSX. Objects are also denoted with curly braces, like { name: "Hedy Lamarr", inventions: 5 }. Therefore, to pass a JS object in JSX, you must wrap the object in another pair of curly braces: person={{ name: "Hedy Lamarr", inventions: 5 }}.

You may see this with inline CSS styles in JSX. React does not require you to use inline styles (CSS classes work great for most cases). But when you need an inline style, you pass an object to the style attribute:


```js
export default function TodoList() {
  return (
    <ul style={{
      backgroundColor: 'black',
      color: 'pink'
    }}>
      <li>Improve the videophone</li>
      <li>Prepare aeronautics lectures</li>
      <li>Work on the alcohol-fuelled engine</li>
    </ul>
  );
}
```

NOTE: Inline style properties are written in camelCase. For example, HTML `<ul style="background-color: black">` would be written as `<ul style={{ backgroundColor: 'black' }}>`  in your component.


if we want to conditionally define a className, this will not work
```jsx
className={props.on ? "on" : ""}
```

we would get this error

Received `false` for a non-boolean attribute `className`. If you want to write it to the DOM, pass a string instead: className="false" or className={value.toString()}. If you used to conditionally omit it with className={condition && value}, pass className={condition ? value : undefined} instead.













### JSX Represents Objects

Babel compiles JSX down to React.createElement() calls.

These two examples are identical:

const element = (
  <h1 className="greeting">
    Hello, world!
  </h1>
);

const element = React.createElement(
  'h1',
  {className: 'greeting'},
  'Hello, world!'
);

React.createElement() performs a few checks to help you write bug-free code but essentially it creates an object like this:

// Note: this structure is simplified
const element = {
  type: 'h1',
  props: {
    className: 'greeting',
    children: 'Hello, world!'
  }
};

These objects are called “React elements”. You can think of them as descriptions of what you want to see on the screen. React reads these objects and uses them to construct the DOM and keep it up to date.

We will explore rendering React elements to the DOM in the next section.
