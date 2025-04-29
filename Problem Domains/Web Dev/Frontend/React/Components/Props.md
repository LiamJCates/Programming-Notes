## Props

https://react.dev/learn/passing-props-to-a-component

In React, data is transferred from parent components to child components via props. This data transfer is unidirectional, meaning it flows in only one direction, "from top to bottom". Any changes made to this data will only affect child components using the data, and not parent or sibling components. Once props are sent the data recieved by the child component is immutable. This restriction on the flow of data gives us more explicit control over it, resulting in fewer errors in our application.






### React Props

Function components can take a single optional object parameter, conventionally called props.

React Props are like function arguments in JavaScript and attributes in HTML.

To send props into a component, use the same syntax as HTML attributes.
The component receives the argument as a props object.

Add a "brand" attribute to the Car element:

```jsx
const myElement = <Car brand="Ford" />;

function Car(props) {
  return <h2>I am a { props.brand }!</h2>;
}
```

Props are how you pass data from one component to another, as parameters.

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

When a functional component receives input and is rendered, React uses props and updates the virtual DOM to ensure the UI reflects the current state.

Here’s a breakdown of how this process works:

    Props: Functional components receive input data through props, which are objects containing key-value pairs.
    Processing Props: After receiving props, the component processes them and returns a JSX element that defines the component’s structure and content.
    Virtual DOM: When the component is rendered, React creates a virtual DOM tree that represents the current state of the application.
    Re-rendering: If the component’s props or state change, React updates the virtual DOM tree accordingly and triggers the component to re-render.





    

### Pass Props

Props are used to pass data from a parent component to a child component. 
Props are read-only and allow you to make a component dynamic by passing different values into it.

```js
//greeting.js
const Greeting = (props) => {
  return <h1>{props.message}</h1>;  

export default Greeting;
```

```js
//app.js
import Greeting from './components/Greeting';  

export function App() {
  return (
    <div style={{ textAlign: "center", marginTop: "50px" }}>
      <Greeting message="Hello, World!" />  {/* Passing 'message' prop */}
    </div>
  );
}
```

In this code

  In the App.js component, we are passing a name prop to the Greeting component.
  In Greeting.js, the name prop is accessed using props.name, and it is used to dynamically display the greeting message.
  When you render <Greeting name=”John” />.



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

The individual properties are then referenced within the component via props.propertyName

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



### Props are Read-Only

Whether you declare a component as a function or a class, it must never modify its own props. Consider this sum function:
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

React is pretty flexible but it has a single strict rule:

All React components must act like pure functions with respect to their props.

Of course, application UIs are dynamic and change over time. 

In the next section, we will introduce a new concept of “state”. State allows React components to change their output over time in response to user actions, network responses, and anything else, without violating this rule.