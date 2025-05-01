## Class Component Lifecycle  

Before diving into specifics, note that React class components go through three main phases — Mounting, Updating, and Unmounting — each with its own set of lifecycle methods that let you hook into a component’s creation, render updates, and cleanup processes. Additionally, React provides error‐boundary methods and several “UNSAFE_” legacy hooks that you should avoid in new code.


- **Mounting**: when an instance is created and inserted into the DOM. Only happens once, also called `initial render`
- **Updating**: when a component’s props or state change triggering a re-render.  
- **Unmounting**: when a component is removed from the DOM.  

- **Error Handling**: class components can catch render errors via error‐boundary methods.  

### Mounting  

React has four built-in methods, called in this order, when mounting a component:

1. **constructor(props)**  
   - Initialize state and bind event handlers.  
2. **static getDerivedStateFromProps(props, state)**  
   - Rarely used; derive state from props before rendering.  
3. **render()**  
   - Required; returns the component’s JSX.  
4. **componentDidMount()**  
   - Invoked once after initial render. Ideal for data fetching, subscriptions, and imperative DOM work.

The render() method is required and will always be called, the others are optional and will be called if you define them.


#### constructor

The constructor() method is called before anything else, when the component is initiated, and it is the natural place to set up initial state and values.

The constructor() method is called with the props, as arguments, and you should always start by calling the super(props) before anything else, this will initiate the parent's constructor method and allows the component to inherit methods from its parent (React.Component). Otherwise, this.props will be undefined in the constructor, which can lead to bugs.

Typically, in React constructors are only used for two purposes:

  Initializing local state by assigning an object to this.state.
  Binding event handler methods to an instance.

Constructor is the only place where you should assign this.state directly. In all other methods, you need to use this.setState() instead.

Avoid introducing any side-effects or subscriptions in the constructor. For those use cases, use componentDidMount() instead.

```jsx
class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  render() {
    return (
      <h1>My Favorite Color is {this.state.favoritecolor}</h1>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header />);
```

NOTE: If you don’t initialize state and you don’t bind methods, you don’t need to implement a constructor for your React component.


#### getDerivedStateFromProps

The getDerivedStateFromProps() method is called right before rendering the element(s) in the DOM.

This is the natural place to set the state object based on the initial props.

It takes state as an argument, and returns an object with changes to the state.

The example below starts with the favorite color being "red", but the getDerivedStateFromProps() method updates the favorite color based on the favcol attribute:

```jsx
class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  static getDerivedStateFromProps(props, state) {
    return {favoritecolor: props.favcol };
  }
  render() {
    return (
      <h1>My Favorite Color is {this.state.favoritecolor}</h1>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header favcol="yellow"/>);
```

#### render

The render() method is required, and is the method that actually outputs the HTML to the DOM.

```jsx
class Header extends React.Component {
  render() {
    return (
      <h1>This is the content of the Header component</h1>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header />);
```

When called, it should examine this.props and this.state and return one of the following types:

**React elements** Typically created via JSX. For example, <div /> and <MyComponent /> are React elements that instruct React to render a DOM node, or another user-defined component, respectively.

**Arrays and fragments** Let you return multiple elements from render. See the documentation on fragments for more details.

**Portals** Let you render children into a different DOM subtree.

**String or numbers** These are rendered as text nodes in the DOM.

**Booleans or null** Render nothing. (Mostly exists to support return test && <Child /> pattern, where test is boolean.)

The render() function should be pure, meaning that it does not modify component state, it returns the same result each time it’s invoked, and it does not directly interact with the browser.

If you need to interact with the browser, perform your work in componentDidMount() or the other lifecycle methods instead. Keeping render() pure makes components easier to think about.


#### componentDidMount

The componentDidMount() method is called after the component is rendered (inserted into the tree).

This is where you run statements that requires that the component is already placed in the DOM.

Initialization that requires DOM nodes should go here. If you need to load data from a remote endpoint, this is a good place to instantiate the network request.

This method is a good place to set up any subscriptions. If you do that, don’t forget to unsubscribe in componentWillUnmount().

You may call setState() immediately in componentDidMount(). It will trigger an extra rendering, but it will happen before the browser updates the screen. This guarantees that even though the render() will be called twice in this case, the user won’t see the intermediate state. Use this pattern with caution because it often causes performance issues. In most cases, you should be able to assign the initial state in the constructor() instead. It can, however, be necessary for cases like modals and tooltips when you need to measure a DOM node before rendering something that depends on its size or position.

```jsx
class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  componentDidMount() {
    setTimeout(() => {
      this.setState({favoritecolor: "yellow"})
    }, 1000)
  }
  render() {
    return (
      <h1>My Favorite Color is {this.state.favoritecolor}</h1>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header />);
```

--- 

### Updating  

An update or rerender occurs when a components state or props change.

React has five built-in methods that gets called, in this order, when a component is updated:

1. **static getDerivedStateFromProps(props, state)**  
   - Also called on updates to sync state with props.  
2. **shouldComponentUpdate(nextProps, nextState)**  
   - Return `false` to skip rendering. Use for performance optimizations.  
3. **render()**  
   - Re-renders component JSX.  
4. **getSnapshotBeforeUpdate(prevProps, prevState)**  
   - Capture information (e.g., scroll position) before the DOM is updated.  
5. **componentDidUpdate(prevProps, prevState, snapshot)**  
   - Invoked after updates. Perform DOM operations or network calls based on changes.

The render() method is required and will always be called, the others are optional and will be called if you define them.

#### getDerivedStateFromProps

This is still the natural place to set the state object based on the initial props.

The example below has a button that changes the favorite color to blue, but since the getDerivedStateFromProps() method is called, which updates the state with the color from the favcol attribute, the favorite color is still rendered as yellow:

Example:

```jsx
class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  static getDerivedStateFromProps(props, state) {
    return {favoritecolor: props.favcol };
  }
  changeColor = () => {
    this.setState({favoritecolor: "blue"});
  }
  render() {
    return (
      <div>
      <h1>My Favorite Color is {this.state.favoritecolor}</h1>
      <button type="button" onClick={this.changeColor}>Change color</button>
      </div>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header favcol="yellow" />);
```

#### shouldComponentUpdate

In the shouldComponentUpdate() method you can return a Boolean value that specifies whether React should continue with the rendering or not.

The default value is true.

The example below shows what happens when the shouldComponentUpdate() method returns false:

```jsx
class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  shouldComponentUpdate() {
    return false;
  }
  changeColor = () => {
    this.setState({favoritecolor: "blue"});
  }
  render() {
    return (
      <div>
      <h1>My Favorite Color is {this.state.favoritecolor}</h1>
      <button type="button" onClick={this.changeColor}>Change color</button>
      </div>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header />);
```


Same example as above, but this time the shouldComponentUpdate() method returns true instead:
```jsx
class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  shouldComponentUpdate() {
    return true;
  }
  changeColor = () => {
    this.setState({favoritecolor: "blue"});
  }
  render() {
    return (
      <div>
      <h1>My Favorite Color is {this.state.favoritecolor}</h1>
      <button type="button" onClick={this.changeColor}>Change color</button>
      </div>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header />);
```

#### render

The render() method is of course called when a component gets updated, it has to re-render the HTML to the DOM, with the new changes.

The example below has a button that changes the favorite color to blue:
Example:

Click the button to make a change in the component's state:

class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  changeColor = () => {
    this.setState({favoritecolor: "blue"});
  }
  render() {
    return (
      <div>
      <h1>My Favorite Color is {this.state.favoritecolor}</h1>
      <button type="button" onClick={this.changeColor}>Change color</button>
      </div>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header />);

#### getSnapshotBeforeUpdate

In the getSnapshotBeforeUpdate() method you have access to the props and state before the update, meaning that even after the update, you can check what the values were before the update.

If the getSnapshotBeforeUpdate() method is present, you should also include the componentDidUpdate() method, otherwise you will get an error.

The example below might seem complicated, but all it does is this:

When the component is mounting it is rendered with the favorite color "red".

When the component has been mounted, a timer changes the state, and after one second, the favorite color becomes "yellow".

This action triggers the update phase, and since this component has a getSnapshotBeforeUpdate() method, this method is executed, and writes a message to the empty DIV1 element.

Then the componentDidUpdate() method is executed and writes a message in the empty DIV2 element:

Use the getSnapshotBeforeUpdate() method to find out what the state object looked like before the update:
```jsx
class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  componentDidMount() {
    setTimeout(() => {
      this.setState({favoritecolor: "yellow"})
    }, 1000)
  }
  getSnapshotBeforeUpdate(prevProps, prevState) {
    document.getElementById("div1").innerHTML =
    "Before the update, the favorite was " + prevState.favoritecolor;
  }
  componentDidUpdate() {
    document.getElementById("div2").innerHTML =
    "The updated favorite is " + this.state.favoritecolor;
  }
  render() {
    return (
      <div>
        <h1>My Favorite Color is {this.state.favoritecolor}</h1>
        <div id="div1"></div>
        <div id="div2"></div>
      </div>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header />);
```

---

#### componentDidUpdate

componentDidUpdate(prevProps, prevState, snapshot)

componentDidUpdate() is invoked immediately after DOM update occurs. This method is not called for the initial render.

Use this as an opportunity to operate on the DOM when the component has been updated. This is also a good place to do network requests as long as you compare the current props to previous props (e.g. a network request may not be necessary if the props have not changed).

The example below might seem complicated, but all it does is this:

When the component is mounting it is rendered with the favorite color "red".
When the component has been mounted, a timer changes the state, and the color becomes "yellow".
This action triggers the update phase, and since this component has a componentDidUpdate method, this method is executed and writes a message in the empty DIV element:

```jsx
class Header extends React.Component {
  constructor(props) {
    super(props);
    this.state = {favoritecolor: "red"};
  }
  componentDidMount() {
    setTimeout(() => {
      this.setState({favoritecolor: "yellow"})
    }, 1000)
  }
  componentDidUpdate() {
    document.getElementById("mydiv").innerHTML =
    "The updated favorite is " + this.state.favoritecolor;
  }
  render() {
    return (
      <div>
      <h1>My Favorite Color is {this.state.favoritecolor}</h1>
      <div id="mydiv"></div>
      </div>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Header />);
```




### Unmounting    

The next phase in the lifecycle is when a component is removed from the DOM.

React has only one built-in method that gets called when a component is unmounted:
- **componentWillUnmount()**  
  - Cleanup tasks such as invalidating timers, canceling network requests, or removing event listeners.


### componentWillUnmount

The componentWillUnmount method is called when the component is about to be removed from the DOM.

Click the button to delete the header:
```jsx
class Container extends React.Component {
  constructor(props) {
    super(props);
    this.state = {show: true};
  }
  delHeader = () => {
    this.setState({show: false});
  }
  render() {
    let myheader;
    if (this.state.show) {
      myheader = <Child />;
    };
    return (
      <div>
      {myheader}
      <button type="button" onClick={this.delHeader}>Delete Header</button>
      </div>
    );
  }
}

class Child extends React.Component {
  componentWillUnmount() {
    alert("The component named Header is about to be unmounted.");
  }
  render() {
    return (
      <h1>Hello World!</h1>
    );
  }
}

const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(<Container />);
```


### Error Boundary Methods  
- **static getDerivedStateFromError(error)**  
  - Update state to display a fallback UI after an error is thrown.  
- **componentDidCatch(error, info)**  
  - Log error information (e.g., to an error tracking service).

### Legacy “UNSAFE_” Methods  
Avoid using these in new code; they will be removed in future releases:  
- `UNSAFE_componentWillMount()`  
- `UNSAFE_componentWillReceiveProps(nextProps)`  
- `UNSAFE_componentWillUpdate(nextProps, nextState)`

### Best Practices  
- Prefer Hooks and functional components for new development.  
- Use error boundaries sparingly to isolate crashing subtrees.  
- Memoize expensive renders via `shouldComponentUpdate` or `React.PureComponent`.  
- Keep lifecycle methods focused: one responsibility per method.

---

### Sources  

1. **React Component API Reference** (React Docs – legacy)  
   https://legacy.reactjs.org/docs/react-component.html  ([React.Component](https://legacy.reactjs.org/docs/react-component.html?utm_source=chatgpt.com))

2. **Component – React** (React.dev reference – defining class components & lifecycle methods)  
   https://react.dev/reference/react/Component  ([Component - React](https://react.dev/reference/react/Component?utm_source=chatgpt.com))

3. **React Component Lifecycle Methods – Explained with Examples** (freeCodeCamp)  
   https://www.freecodecamp.org/news/react-component-lifecycle-methods/  ([React Component Lifecycle Methods – Explained with Examples](https://www.freecodecamp.org/news/react-component-lifecycle-methods/?utm_source=chatgpt.com))

4. **Explain Lifecycle Methods of React Components** (GeeksforGeeks article)  
   https://www.geeksforgeeks.org/explain-lifecycle-methods-of-react-components/  ([Explain Lifecycle Methods of React Components | GeeksforGeeks](https://www.geeksforgeeks.org/explain-lifecycle-methods-of-react-components/?utm_source=chatgpt.com))

5. **React Lifecycle** (W3Schools tutorial)  
   https://www.w3schools.com/react/react_lifecycle.asp  ([React Lifecycle - W3Schools](https://www.w3schools.com/react/react_lifecycle.asp?utm_source=chatgpt.com))

6. **Understanding the React Component Lifecycle: A Deep Dive into the Life of a React Component** (Medium – Arpit Parekh)  
   https://medium.com/@arpitparekh54/understanding-the-react-component-lifecycle-a-deep-dive-into-the-life-of-a-react-component-74813cb8dfb5  ([Understanding the React Component Lifecycle: A Deep Dive into ...](https://medium.com/%40arpitparekh54/understanding-the-react-component-lifecycle-a-deep-dive-into-the-life-of-a-react-component-74813cb8dfb5?utm_source=chatgpt.com))

7. **A Deep Dive into React Class Lifecycle Methods** (JavaScript in Plain English)  
   https://javascript.plainenglish.io/react-lifecycle-methods-a-deep-dive-f97c4553c5c2  ([A Deep Dive into React Class Lifecycle Methods | by Ayush Verma](https://javascript.plainenglish.io/react-lifecycle-methods-a-deep-dive-f97c4553c5c2?utm_source=chatgpt.com))

8. **React Lifecycle Methods and Hooks – a Beginner’s Guide** (freeCodeCamp News)  
   https://www.freecodecamp.org/news/react-lifecycle-methods-and-hooks-for-beginners/  ([React Lifecycle Methods and Hooks – a Beginner's Guide](https://www.freecodecamp.org/news/react-lifecycle-methods-and-hooks-for-beginners/?utm_source=chatgpt.com))

9. **React Lifecycle with Class and Hooks 2024** (Level Up Coding)  
   https://levelup.gitconnected.com/react-lifecycle-with-class-and-hooks-2024-2369b9d42173  ([React Lifecycle with Class and Hooks 2024 - Level Up Coding](https://levelup.gitconnected.com/react-lifecycle-with-class-and-hooks-2024-2369b9d42173?utm_source=chatgpt.com))

10. **React Lifecycle Methods | GeeksforGeeks Web Development** (YouTube video)  
    https://www.youtube.com/watch?v=00lo9io7gFY  ([(Let-3) React lifecycle methods | GeeksforGeeks Web Development](https://www.youtube.com/watch?v=00lo9io7gFY&utm_source=chatgpt.com))

11. **React Components** (GeeksforGeeks overview of components)  
    https://www.geeksforgeeks.org/reactjs-components/  ([React Components - GeeksforGeeks](https://www.geeksforgeeks.org/reactjs-components/?utm_source=chatgpt.com))

12. **Functional Components vs Class Components in React** (freeCodeCamp)  
    https://www.freecodecamp.org/news/functional-components-vs-class-components-in-react/  ([Functional Components vs Class Components in React](https://www.freecodecamp.org/news/functional-components-vs-class-components-in-react/?utm_source=chatgpt.com))
