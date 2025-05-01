
# Class Component

NOTE: React documentation recommends defining function components instead of classes, so, while information related to class components is still part of the standard, it is becoming less and less relevant.

https://react.dev/reference/react/Component#alternatives



Class components use an ES6 class to define a component:

```js
class Welcome extends React.Component {
  render() {
    return <h1>Hello, {this.props.name}</h1>;
  }
}
```

A class component must include the extends React.Component statement. This statement creates an inheritance to React.Component, and gives your component access to React.Component's functions.
The component requires a render() method, this method returns HTML.
The component's name must start with an upper case letter.



It is recommeneded to use functional components whenever possible, however, there are a few cases where functional components may not be suitable:

    Stateful components: Functional components cannot hold state on their own.*(This is no longer the case)
    Lifecycle methods: If you need to use lifecycle methods such as componentDidMount, componentDidUpdate, or componentWillUnmount, you will need to use a class component.

*Before React 16.8, Class components were the only way to track state and lifecycle on a React component. Function components were considered "state-less". With the addition of Hooks, Function components are now almost equivalent to Class components. The differences are so minor that you will probably never need to use a Class component in React.

Even though Function components are preferred, there are no current plans on removing Class components from React.


### Component Constructor

If there is a constructor() function in your component, this function will be called when the component gets initiated.

The constructor function is where you initiate the component's properties.

In React, component properties should be kept in an object called state.

The constructor function is also where you honor the inheritance of the parent component by including the super() statement, which executes the parent component's constructor function, and your component has access to all the functions of the parent component (React.Component).

```jsx
class Car extends React.Component {
  constructor() {
    super();
    this.state = {color: "red"};
  }
  render() {
    return <h2>I am a Car!</h2>;
  }
}
```

Example property

```jsx
class Car extends React.Component {
  constructor() {
    super();
    this.state = {color: "red"};
  }
  render() {
    return <h2>I am a {this.state.color} Car!</h2>;
  }
}
```

Class components also have access to props via their this member

```js
class Car extends React.Component {
  render() {
    return <h2>I am a {this.props.color} Car!</h2>;
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Car color="red"/>);
```

### Props in the Constructor

If your component has a constructor function, the props should always be passed to the constructor and also to the React.Component via the super() method.

```jsx
class Car extends React.Component {
  constructor(props) {
    super(props);
  }
  render() {
    return <h2>I am a {this.props.model}!</h2>;
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Car model="Mustang"/>);
```



### Class Components in Class Components

We can refer to components inside other components:

```jsx
// Use the Car component inside the Garage component:

class Car extends React.Component {
  render() {
    return <h2>I am a Car!</h2>;
  }
}

class Garage extends React.Component {
  render() {
    return (
      <div>
      <h1>Who lives in my Garage?</h1>
      <Car />
      </div>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Garage />);
```


### React Class Component State

React Class components have a built-in state object.

The state object is where you store property values that belongs to the component.

When the state object changes, the component re-renders.


The state object is initialized in the constructor.

The state object can contain as many properties as you like:

```jsx
class Car extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      brand: "Ford",
      model: "Mustang",
      color: "red",
      year: 1964
    };
  }
  render() {
    return (
      <div>
        <h1>My Car</h1>
      </div>
    );
  }
}
```

Refer to the state object anywhere in the component by using the this.state.propertyname syntax:

```jsx
class Car extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      brand: "Ford",
      model: "Mustang",
      color: "red",
      year: 1964
    };
  }
  render() {
    return (
      <div>
        <h1>My {this.state.brand}</h1>
        <p>
          It is a {this.state.color}
          {this.state.model}
          from {this.state.year}.
        </p>
      </div>
    );
  }
}
```


To change a value in the state object, use the this.setState() method.

Always use the setState() method to ensure that the component knows its been updated and calls the render() method (and all the other lifecycle methods).

When a value in the state object changes, the component will re-render, meaning that the output will change according to the new value(s).

Add a button with an onClick event that will change the color property:

```jsx
class Car extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      brand: "Ford",
      model: "Mustang",
      color: "red",
      year: 1964
    };
  }
  changeColor = () => {
    this.setState({color: "blue"});
  }
  render() {
    return (
      <div>
        <h1>My {this.state.brand}</h1>
        <p>
          It is a {this.state.color}
          {this.state.model}
          from {this.state.year}.
        </p>
        <button
          type="button"
          onClick={this.changeColor}
        >Change color</button>
      </div>
    );
  }
}
```