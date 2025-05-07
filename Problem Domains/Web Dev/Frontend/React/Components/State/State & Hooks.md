# State


https://react.dev/learn/state-a-components-memory
https://www.geeksforgeeks.org/reactjs-reconciliation/
https://medium.com/javarevisited/react-reconciliation-algorithm-86e3e22c1b40



https://react.dev/learn/state-as-a-snapshot
https://react.dev/learn/choosing-the-state-structure
https://react.dev/learn/sharing-state-between-components



## What is state in React?

If we want components to undergo visual changes as a result of interactions, the component needs to “remember” things about itself.

State is a specifically declared object that functions as a component’s memory, and is internally managed by a component, to be used during it's execution, similar to a functions local variables.

The view, what is visually presented as the UI, is dependent on the state of your components

React components are `rendered` to the browser window, this is the act of running the functional component function to produce the JSX necessary to produce the UI in the browser window

a component will only be rerendered if either the
  props it is receiving change in the parent component
  state it manages changes



### Non-state Variables

Changing a non-state variable will not cause the component in which it resides to rerender. 

```jsx
export default function App() {
    let state = "Yes"
    
    function handleClick() {
        state = "No"
    }
    
    return (
        <main>
            <h1 className="title">Is state important to know?</h1>
            <button onClick={handleClick} className="value">{state}</button>
        </main>
    )
}
```
Even though the event handler changes this variable's value, we do not see this reflected in the UI.

NOTE:
While variable values are generally considered to be part of the program state in a more general context, a React component's state consist of specifically declared state objects.

---

### useState

useState is a React feature that allows you to define a state object in a functional component. 

useState takes an initial value as a parameter and returns a two element array containing:
  
    The current state value  
    A function to update the state value, which internally the `setState` method of the internal React state object  
  
useState definition:

```jsx
import {useState} from "react"

const [stateValue, setStateValue] = useState(initialValue);
```

NOTE: It is common to destructure the array returned by useState, and name the function referencing the internal state objects setState method in accordance with the identifier provided to the stateValue variable in the context of a given component 

NOTE: The remainder of this document uses the setState method name when referencing the function returned by the useState, as is stated above, the function returned will have a name relative to the context in which it is used, determined by the identifier used to reference the current state.



You can use state to store and increment the number of times a user has clicked the "Like" button. In fact, the React hook used to manage state is called: useState()

Add useState() to your project. It returns an array, and you can access and use those array values inside your component using array destructuring:

```jsx
function HomePage() {
  // ...
  const [] = React.useState();
 
  // ...
}
```
The first item in the array is the state value, which you can name anything. It's recommended to name it something descriptive:

```jsx
function HomePage() {
  // ...
  const [likes] = React.useState();
 
  // ...
}
```

The second item in the array is a function to update the value. You can name the update function anything, but it's common to prefix it with set followed by the name of the state variable you're updating:

```jsx
function HomePage() {
  // ...
  const [likes, setLikes] = React.useState();
 
  // ...
}
```

You can also take the opportunity to add the initial value of your likes state to 0:

```jsx
function HomePage() {
  // ...
  const [likes, setLikes] = React.useState(0);
}
```

Then, you can check the initial state is working by using the state variable inside your component.

```jsx
function HomePage() {
  // ...
  const [likes, setLikes] = React.useState(0);
  // ...
 
  return (
    // ...
    <button onClick={handleClick}>Like({likes})</button>
  );
}
```
Finally, you can call your state updater function, setLikes in your HomePage component, let's add it inside the handleClick() function you previously defined:

```jsx
function HomePage() {
  // ...
  const [likes, setLikes] = React.useState(0);
 
  function handleClick() {
    setLikes(likes + 1);
  }
 
  return (
    <div>
      {/* ... */}
      <button onClick={handleClick}>Likes ({likes})</button>
    </div>
  );
}
```

Clicking the button will now call the handleClick function, which calls the setLikes state updater function with a single argument of the current number of likes + 1.


## How does state work in React?

In React, when a component’s state or props change, the component is destroyed, including variables, functions, and child nodes, and the entire component is reinitialized and the latest state value will be returned from useState. This process, called `Rerendering`, is a key feature of React that enables it to efficiently update the user interface in response to changes in the underlying data.

The process of rerendering generates a new `virtual DOM` (Document Object Model) tree, a lightweight representation of the actual DOM that React uses to keep track of the current state of the UI. React then compares the new virtual DOM tree to the previous one and calculates the minimal set of changes needed to update the actual DOM. This behavior is managed by the `reconciliation algorithm`.

An app that changes its background color based on the clicked button

```jsx
//App.jsx
import { useState } from "react";

const COLORS = ["pink", "green", "blue", "yellow", "purple"];

export function App() {
  const [backgroundColor, setBackgroundColor] = useState(COLORS[0]);

  const onButtonClick = (color) => () => {
    setBackgroundColor(color);
  };

  return (
    <div
      className="App"
      style={{
        width: '300px',
        height: '300px',
        backgroundColor: backgroundColor,
      }}
    >
      {COLORS.map((color) => (
        <button
          type="button"
          key={color}
          onClick={onButtonClick(color)}
          className={backgroundColor === color ? "selected" : ""}
        >
          {color}
        </button>
      ))}
    </div>
  );
}
```

```jsx
//index.jsx
import React from 'react';
import ReactDOM from 'react-dom/client';

import { App } from './App.jsx'

ReactDOM.createRoot( 
  document.getElementById('root')
).render(<App />)
```

```html
<!DOCTYPE html>
<html lang="en">
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="src/style.css">
  </head>
  <body>
    <div id="root"></div>

    <script src="src/index.jsx"></script>
  </body>
</html>
```

The backgroundColor state is defined with the `useState` hook. 

On button click, an event handler that calls the setBackgroundColor function with the corresponding value.

In the example above, whenever setBackgroundColor is called, our App component is rerendered. The onButtonClick function and our div and buttons are recreated. You might wonder, shouldn’t the backgroundColor state be recreated? Well, React takes the responsibility of keeping track of the latest state and providing it to the component. The initial state value is only used for the component’s first render and is ignored on subsequent renders.

Note: Unlike props which are passed to components as the first function parameter, the state is initiated and stored within a component. You can pass the state information to children components as props, but the logic for updating the state should be kept within the component where state was initially created.

## Hooks

Simply put, React Hooks are functions that allow you to “hook into” an internal React state object.

All hooks are recognizable by the `use-` prefix.

NOTE:
  Originally (before hooks), functional components were stateless and used only for rendering UI based on props.
  With hooks, functional components can manage state and side effects, making them just as powerful as class components.


### Hook Rules

For now, remember that hooks have rules that we need to abide by:

    Hooks can only be called from the top level of a functional component.
    Hooks can’t be called from inside loops or conditions.



## How to structure state

Managing and structuring state effectively is by far one of the most crucial parts of building your application. It can become a source of bugs and headaches.

As a rule of thumb: don’t put values in state that can be calculated using existing values, state, and/or props.


### State should not be mutated

State can hold any kind of JavaScript value, including objects.

Mutating state is a no-go area in React as it leads to unpredictable results. Primitives are already immutable, but if you are using reference-type values, i.e., arrays and objects, never mutate them. According to the React documentation, we should treat state as if it was immutable, you shouldn’t change objects and arrays that you hold in the React state directly. Instead, when you want to update an object and array, you need to create a new one (or make a copy of an existing one), and then update the state to use that copy.

Usually, you will use the ... spread syntax to copy objects and arrays that you don't want to change, and then provide all the changed values for the new object or array. 

To change state, we should always use the setter function returned by useState

```js
function Person() {
  const [person, setPerson] = useState({ name: "John", age: 100 });

/* BAD - Don't do this!
  const handleIncreaseAge = () => {
    // mutating the current state object
    person.age = person.age + 1;

    additionally, person.age++ is equal to the above
    setPerson(person);
  };
*/
  // GOOD - Do this!
  const handleIncreaseAge = () => {
    // copy the existing person object into a new object
    // while updating the age property of that new object
    const newPerson = { ...person, age: person.age + 1 };
    setPerson(newPerson);
  };

  return (
    <>
      <h1>{person.name}</h1>
      <h2>{person.age}</h2>
      <button onClick={handleIncreaseAge}>Increase age</button>
    </>
  );
}
```

Notice, we create a new object and then copy the existing state values into the new object using the spread syntax, while providing a new value for age. That is because if we don’t provide a new object to setState it is not guaranteed to re-render the page. Therefore, we should always provide a new Object for setState to trigger a re-render. 

During a re-render, React uses Object.is() to determine if the previous state is the same.

As for nested objects and arrays, state can get tricky fast since you will have to copy the nested items as well. Be careful when using them.


### How state updates

State variables might look like regular JavaScript variables that you can read and write to. However, state behaves more like a snapshot. Setting it does not change the state variable you already have, but instead triggers a re-render.

State updates are asynchronous. What this implies is that whenever you call the setState function, React will apply the update in the next component render.

Remember, state variables aren’t reactive; the component is. This can be understood by the fact that calling setState re-renders the entire component instead of just changing the state variable on the fly.

```js
function Person() {
  const [person, setPerson] = useState({ name: "John", age: 100 });

  const handleIncreaseAge = () => {
    console.log("in handleIncreaseAge (before setPerson call): ", person);
    setPerson({ ...person, age: person.age + 1 });
    // we've called setPerson, surely person has updated?
    console.log("in handleIncreaseAge (after setPerson call): ", person);
  };

  // this console.log runs every time the component renders
  // what do you think this will print?
  console.log("during render: ", person);

  return (
    <>
      <h1>{person.name}</h1>
      <h2>{person.age}</h2>
      <button onClick={handleIncreaseAge}>Increase age</button>
    </>
  );
}
```

![person state](../../img/state.png)

Uh-oh, what is happening? Let’s break it down (ignore the double console.logs for the render case).

1. The component renders for the first time. The person state variable is initialized to { name: 'John', age: 100 }. The “during render” console.log prints the state variable.
2. The button is clicked invoking handleIncreaseAge. Interestingly, the console.log before and after the setPerson call prints the same value.
3. The component re-renders. The person state variable is updated to { name: 'John', age: 101 }.

The person state stays the same throughout the current render of the component. This is what “state as a snapshot” refers to. The setState call triggers a component re-render, and the person state is updated to the new value.


#### The unexpected infinite loop

The following is an infinite loop

```jsx
function Component() {
  const [count, setCount] = useState(0);

  setCount(count + 1);

  return <h1>{count}</h1>;
}
```

This is because the setCount method is called whenever the Component is rendered
but, as stated above, calling setState re-renders the entire component instead of just changing the state variable on the fly.
so the Component is rerendered and setState is called again.



### React batches state updates

Let’s look at another implementation of handleIncreaseAge; what do you think it does?

```js
const handleIncreaseAge = () => {
  setPerson({ ...person, age: person.age + 1 });
  setPerson({ ...person, age: person.age + 1 });
};
```
Surely, it will increase the age by 2? Nope. The above code is saying to React:

    Hey, replace the current render’s person with an increase in age by 1. Then, replace the current render’s person with an increase in age by 1.

There are two setPerson calls in the above example, and setState call triggers a component re-render. So, the component should re-render twice, right?
However, wherever possible, React batches the state updates. Here, the component only re-renders once.


Notice the word “replace”. When you pass in the value to the setState function, React will replace the current state with the value you passed in. You might be wondering, what if I want to update the state multiple times using the latest state? This is where the state updater function comes in.



### State updater functions

When a callback is passed to the setState function, it ensures that the latest state is passed in as an argument to the callback.

```js
const handleIncreaseAge = () => {
  setPerson((prevPerson) => ({ ...prevPerson, age: prevPerson.age + 1 }));
  setPerson((prevPerson) => ({ ...prevPerson, age: prevPerson.age + 1 }));
};
```
Using an updater is not always necessary.

```jsx
import React from "react"

export default function App() {
    const [count, setCount] = React.useState(0)
    /**
     * Note: if you ever need the old value of state
     * to help you determine the new value of state,
     * you should pass a callback function to your
     * state setter function instead of using
     * state directly. This callback function will
     * receive the old value of state as its parameter,
     * which you can then use to determine your new
     * value of state.
     */
    function add() {
        setCount(prevCount=> prevCount + 1) // We could have just as well used the method below
    }

    function subtract() {
        setCount(count - 1) // We could have just as well used the method above
    }

    return (
        <main className="container">
            <h1>How many times will Bob say "state" in this section?</h1>
            <div className="counter">
                <button className="minus" onClick={subtract} aria-label="Decrease count">–</button>
                <h2 className="count">{count}</h2>
                <button className="plus" onClick={add} aria-label="Increase count">+</button>
            </div>
        </main>
    )
}
```

If you want to change the state using your previous state and you prefer consistency over verbosity, then you might consider using an updater.

Use a callback function to add items to an array as we need the previous value of the state to maintain the current array items. 
Rather than using the Array.push operation, we create a new array using the spread operator to reference all previous values, and include the new value. 

```jsx
import React from "react"

export default function App() {

  const [myFavoriteThings, setMyFavoriteThings] = React.useState([])
  
  const allFavoriteThings = ["💦🌹", "😺", "💡🫖", "🔥🧤", "🟤🎁", 
  "🐴", "🍎🥧", "🚪🔔", "🛷🔔", "🥩🍝"]
  const thingsElements = myFavoriteThings.map(thing => <p key={thing}>{thing}</p>)

  function addFavoriteThing() {
    setMyFavoriteThings(prevFavThings => [...prevFavThings, allFavoriteThings[prevFavThings.length]])
  }
  
  return (
    <main>
      <button onClick={addFavoriteThing}>Add item</button>
      <section aria-live="polite">
        {thingsElements}
      </section>
    </main>
  )
}
```




### Controlled components

There are native HTML elements that maintain their own internal state. The input element is a great example. You type into an input and it updates its own value on every keystroke. For many use-cases, you would like to control the value of the input element, i.e., set its value yourself. This is where controlled components come in.

```js
function CustomInput() {
  const [value, setValue] = useState("");

  return (
    <input
      type="text"
      value={value}
      onChange={(event) => setValue(event.target.value)}
    />
  );
}
```

Instead of letting the input maintain its own state, we define our own state using the useState hook. We then set the value prop of the input to the state variable and update the state variable on every onChange event. Now, every time the user types something in the input, React will ensure you have the latest comment, review, or post (whatever the user was typing) in value.





Callback functions respond how we would expect while the setter function get's batched

```jsx
import React from "react"

export default function App() {
    const [count, setCount] = React.useState(0)

    function add() {
        setCount(prevCount=> prevCount + 1)
        setCount(prevCount=> prevCount + 1)
        setCount(prevCount=> prevCount + 1)
    }

    function subtract() {
        setCount(count - 1)
        setCount(count - 1)
        setCount(count - 1)
    }

    return (
        <main className="container">
            <h1>How many times will Bob say "state" in this section?</h1>
            <div className="counter">
                <button className="minus" onClick={subtract} aria-label="Decrease count">–</button>
                <h2 className="count">{count}</h2>
                <button className="plus" onClick={add} aria-label="Increase count">+</button>
            </div>
        </main>
    )
}
```


### Review

1. You have 2 options for what you can pass in to a state setter function (e.g. `setCount`). What are they?
   1. Pass the new state value
   2. Pass a callback function, with a single parameter that is the old state value and returns the new state value.


2. When would you want to pass the first option (from answer
   above) to the state setter function?
   
   Whenever we don't need the old state value, we simply want to set a new value.


3. When would you want to pass the second option (from answer
   above) to the state setter function?

   Whenever we need the previous state value to determine what the new value should be.




For a child component to effect a state value in a parent, pass the state value as props


```jsx
// In Star.jsx
import starFilled from "./images/star-filled.png"
import starEmpty from "./images/star-empty.png"

export default function Star(props) {
    
    let starIcon = props.isFilled ? starFilled : starEmpty
    
    return (
        <button
            onClick={props.handleClick}
            aria-pressed={props.isFilled}
            aria-label={props.isFilled ? "Remove from favorites" : "Add to favorites"}
            className="favorite-button"
        >
            <img
                src={starIcon}
                alt={props.isFilled ? "filled star icon" : "empty star icon"}
                className="favorite"
            />
        </button>
    )
}



// in App.jsx
export default function App() {

    function toggleFavorite() {
        setContact(prevContact => ({
            ...prevContact,
            isFavorite: !prevContact.isFavorite
        }))
    }
  
 const [contact, setContact] = React.useState({
        //...
        isFavorite: true
    })

return (
  //...
  <Star isFilled={contact.isFavorite} handleClick={toggleFavorite} />
)
}
```




In order to have one handler function manage multiple members of a state object, ensure the object member name, and the name attribute of the html element are the same.

We can then extract the name attribute from the event and use that as the member name we will update

```jsx
import { useState } from "react"

export default function Main() {
    const [meme, setMeme] = useState({
        topText: "One does not simply",   //For example: this member name
        bottomText: "Walk into Mordor",
        imageUrl: "http://i.imgflip.com/1bij.jpg"
    })
    
    function handleChange(event) {
        const {value, name} = event.currentTarget     // which we extract the html element name to which the event corresponds
        setMeme(prevMeme => ({
            ...prevMeme,
            [name]: value                           // and use here during setting a new state value
        }))
    }

    return (
        <main>
            <div className="form">
                <label>Top Text
                    <input
                        type="text"
                        placeholder="One does not simply"
                        name="topText"                      //Matches this name
                        onChange={handleChange}
                        value={meme.topText}
                    />
                </label>

                <label>Bottom Text
                    <input
                        type="text"
                        placeholder="Walk into Mordor"
                        name="bottomText"
                        onChange={handleChange}
                        value={meme.bottomText}
                    />
                </label>
                <button>Get a new meme image 🖼</button>
            </div>
            <div className="meme">
                <img src={meme.imageUrl} />
                <span className="top">{meme.topText}</span>
                <span className="bottom">{meme.bottomText}</span>
            </div>
        </main>
    )
}
```

