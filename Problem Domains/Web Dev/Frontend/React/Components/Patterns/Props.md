# Props

https://react.dev/learn/passing-props-to-a-component

In React, data is transferred from parent components to child components via props. This data transfer is unidirectional, meaning it flows in only one direction, "from top to bottom". Any changes made to this data will only affect child components using the data, and not parent or sibling components. Once props are sent the data recieved by the child component is immutable. This restriction on the flow of data gives us more explicit control over it, resulting in fewer errors in our application.


## React Props

Props allow you to make a component dynamic by passing different values into it.

Function components take a single, optional object parameter, called `props`.

The parent component declares prop values like attributes in HTML, using an attribute value pair.
The child component receives an object parameter and accesses prop value as object members using the same name provided to the attribute.


A "brand" attribute on the Car component:

```jsx
const myElement = <Car brand="Ford" />;

function Car(props) {
  return <h2>I am a { props.brand }!</h2>;
}
```

Send the "brand" property from the Garage component to the Car component:

```jsx
function Car(props) {
  return <h2>I am a { props.brand }!</h2>;
}

function Garage() {
  return (
    <>
      <h1>Who lives in my garage?</h1>
      <Car brand="Ford" />
    </>
  );
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Garage />);
```

When a functional component receives input and is rendered, React updates the virtual DOM to ensure the UI reflects the current state.



### Using props in React

Consider the following Button component, which then gets rendered multiple times within our App component.

```js
function Button() {
  return (
    <button>Click Me!</button>
  );
}

export default function App() {
  return (
    <div>
      <Button />
      <Button />
      <Button />
    </div>
  );
}
```

Let’s see how by using props, we can account for any number of variations with a single button component.


```js
function Button(props) {
  const buttonStyle = {
    color: props.color,
    fontSize: props.fontSize + 'px'
  };

  return (
    <button style={buttonStyle}>{props.text}</button>
  );
}

export default function App() {
  return (
    <div>
      <Button text="Click Me!" color="blue" fontSize={12} />
      <Button text="Don't Click Me!" color="red" fontSize={12} />
      <Button text="Click Me!" color="blue" fontSize={20} />
    </div>
  );
}
```

---

### Prop destructuring

```js
function Button({ text, color, fontSize }) {
  const buttonStyle = {
    color: color,
    fontSize: fontSize + "px"
  };

  return <button style={buttonStyle}>{text}</button>;
}

export default function App() {
  return (
    <div>
      <Button text="Click Me!" color="blue" fontSize={12} />
      <Button text="Don't Click Me!" color="red" fontSize={12} />
      <Button text="Click Me!" color="blue" fontSize={20} />
    </div>
  );
}
```

---

### Default props

```js
function Button({ text = "Click Me!", color = "blue", fontSize = 12 }) {
  const buttonStyle = {
    color: color,
    fontSize: fontSize + "px"
  };

  return <button style={buttonStyle}>{text}</button>;
}

export default function App() {
  return (
    <div>
      <Button />
      <Button text="Don't Click Me!" color="red" />
      <Button fontSize={20} />
    </div>
  );
}
```

NOTE: React now prefers the default parameter approach for function components, understanding **defaultProps** is useful.

```js
function Button({ text, color, fontSize }) {
  const buttonStyle = {
    color: color,
    fontSize: fontSize + "px"
  };

  return <button style={buttonStyle}>{text}</button>;
}

Button.defaultProps = {
  text: "Click Me!",
  color: "blue",
  fontSize: 12
};

export default function App() {
  return (
    <div>
      <Button />
      <Button text="Don't Click Me!" color="red" />
      <Button fontSize={20} />
    </div>
  );
}
```

---

### Functions as props

```js
function Button({ text = "Click Me!", color = "blue", fontSize = 12, handleClick }) {
  const buttonStyle = {
    color: color,
    fontSize: fontSize + "px"
  };

  return (
    <button onClick={handleClick} style={buttonStyle}>
      {text}
    </button>
  );
}

export default function App() {
  const handleButtonClick = () => {
    window.location.href = "https://www.google.com";
  };

  return (
    <div>
      <Button handleClick={handleButtonClick} />
    </div>
  );
}
```

We only pass through a reference to handleButtonClick, i.e. we do not include parenthesis when passing the function to Button. If we were to do something like handleClick={handleButtonClick()} then the function would be called as the button renders.

Every Button calling this function will navigate to the same page. 


We can refactor the function and supply an argument within Button to customize this functionality.

```js
function Button({ text = "Click Me!", color = "blue", fontSize = 12, handleClick }) {
  const buttonStyle = {
    color: color,
    fontSize: fontSize + "px"
  };

  return (
    <button onClick={handleClick} style={buttonStyle}>
      {text}
    </button>
  );
}

export default function App() {
  const handleButtonClick = (url) => {
    window.location.href = url;
  };

  return (
    <div>
      <Button handleClick={() => handleButtonClick('https://www.theodinproject.com')} />
    </div>
  );
}
```

When supplying an argument to the function, we can’t just write onClick={handleClick('https://www.theodinproject.com')}, and instead must attach a reference to an anonymous function which then calls the function with the argument. Like the previous example, this is to prevent the function being called during the render.

---

### Props are Read-Only

React is pretty flexible, however, whether you declare a component as a function or a class, it must never modify its own props. 

    props have a single strict rule:  
    All React components must act like pure functions with respect to their props.  

Consider this sum function:

```js
function sum(a, b) {
  return a + b;
}
```

Such functions are called “pure” because they do not attempt to change their inputs, and always return the same result for the same inputs.

In contrast, this function is impure because it changes its own input:

```js
function withdraw(account, amount) {
  account.total -= amount;
}
```

### Keeping components pure

A Pure function only perform a calculation and nothing more:

    Minds its own business. It does not change any objects or variables that existed before it was called.
    Same inputs, same output. Given the same inputs, a pure function should always return the same result.

By strictly only writing your components as pure functions, you can avoid an entire class of baffling bugs and unpredictable behavior as your codebase grows. 

#### Side Effects: (un)intended consequences

React’s rendering process must always be pure. Components should only return their JSX, and not change any objects or variables that existed before rendering—that would make them impure!

Here is an example of an impure component:

```jsx
let guest = 0;

function Cup() {
  // Bad: changing a preexisting variable!
  guest = guest + 1;
  return <h2>Tea cup for guest #{guest}</h2>;
}

export default function TeaSet() {
  return (
    <>
      <Cup />
      <Cup />
      <Cup />
    </>
  );
}
```

This component is reading and writing a guest variable declared outside of it. This means that calling this component multiple times will produce different JSX! And what’s more, if other components read guest, they will produce different JSX, too, depending on when they were rendered! That’s not predictable.

You can make this component pure by passing guest as a prop instead of modifying a preexisting variable:

```jsx
function Cup({ guest }) {
  return <h2>Tea cup for guest #{guest}</h2>;
}

export default function TeaSet() {
  return (
    <>
      <Cup guest={1} />
      <Cup guest={2} />
      <Cup guest={3} />
    </>
  );
}
```

NOTE: It’s completely fine to mutate local variables or objects that are created while rendering a given component.

#### Why does React care about purity?

Writing pure functions takes some habit and discipline. But it also unlocks marvelous opportunities:

    Your components could run in a different environment—for example, on the server! Since they return the same result for the same inputs, one component can serve many user requests.
    You can improve performance by skipping rendering components whose inputs have not changed. This is safe because pure functions always return the same results, so they are safe to cache.
    If some data changes in the middle of rendering a deep component tree, React can restart rendering without wasting time to finish the outdated render. Purity makes it safe to stop calculating at any time.

---

### Forwarding With Spread Syntax

Sometimes, passing props gets very repetitive:

```jsx
function Profile({ person, size, isSepia, thickBorder }) {
  return (
    <div className="card">
      <Avatar
        person={person}
        size={size}
        isSepia={isSepia}
        thickBorder={thickBorder}
      />
    </div>
  );
}
```

There’s nothing wrong with repetitive code—it can be more legible. But at times you may value conciseness. Some components forward all of their props to their children, like how this Profile does with Avatar. Because they don’t use any of their props directly, it can make sense to use a more concise “spread” syntax:

```jsx
function Profile(props) {
  return (
    <div className="card">
      <Avatar {...props} />
    </div>
  );
}
```

This forwards all of Profile’s props to the Avatar without listing each of their names.

Use spread syntax with restraint. If you’re using it in every other component, something is wrong. Often, it indicates that you should split your components and pass children as JSX

---

### Passing JSX as children

It is common to nest built-in browser tags:

<div>
  <img />
</div>

Sometimes you’ll want to nest your own components the same way:

<Card>
  <Avatar />
</Card>

When you nest content inside a JSX tag, the parent component will receive that content in a prop called children. For example, the Card component below will receive a children prop set to <Avatar /> and render it in a wrapper div:

```jsx
import Avatar from './Avatar.js';

function Card({ children }) {
  return (
    <div className="card">
      {children}
    </div>
  );
}

export default function Profile() {
  return (
    <Card>
      <Avatar
        size={100}
        person={{ 
          name: 'Katsuko Saruhashi',
          imageId: 'YfeOqp2'
        }}
      />
    </Card>
  );
}
```

We can replace the <Avatar> inside <Card> with some text to see how the Card component can wrap any nested content. It doesn’t need to “know” what’s being rendered inside of it. You will see this flexible pattern in many places.

You can think of a component with a children prop as having a “hole” that can be “filled in” by its parent components with arbitrary JSX. You will often use the children prop for visual wrappers: panels, grids, etc.



