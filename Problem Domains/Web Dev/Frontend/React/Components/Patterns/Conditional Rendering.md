### Conditionally rendering UI


https://react.dev/learn/conditional-rendering


#### Using the ternary operator

```js
function List(props) {
  return (
    <ul>
      {
        props.animals.map( animal => animal.startsWith("L") ? <li key={animal}>{animal}</li> : null )
      }
    </ul>
  );
}

export function App() {
  const animals = ["Lion", "Cow", "Snake", "Lizard"];

  return (
    <div>
      <h1>Animals: </h1>
      <List animals={animals} />
    </div>
  );
}
```

#### Using the && operator

```js
function List(props) {
  return (
    <ul>
      {
        props.animals.map( animal => animal.startsWith("L") && <li key={animal}>{animal}</li>)
      }
    </ul>
  );
}

export function App() {
  const animals = ["Lion", "Cow", "Snake", "Lizard"];

  return (
    <div>
      <h1>Animals: </h1>
      <List animals={animals} />
    </div>
  );
}
```

We will leverage the return value of startsWith with the && operator. If the result of the startsWith function is true, then it returns the second operand



### Numbers with Logical AND (&&) - a common pitfall  

[!NOTE]  

When using && for conditional rendering, don’t put numbers on the left side. The React docs on conditional rendering provide more details about this in the Pitfall box in the section about &&.

https://react.dev/learn/conditional-rendering#logical-and-operator-


In this example, even though 0 is a falsey value, the 0 will be rendered rather than the expected conditional rendering behavior we might expect 
```jsx
import React from "react"

export default function App() {
    const [unreadMessages, setUnreadMessages] = React.useState([])
    
    return (
        <div>
            {
                unreadMessages.length && 
                <h1>You have {unreadMessages.length} unread messages!</h1>
            }
            
        </div>
    )
}
```


because of this, it is a common recommendation to always use a ternary, with a falsey return of `null` 
```jsx
import React from "react"

export default function App() {
    const [unreadMessages, setUnreadMessages] = React.useState([])
    
    return (
        <div>
            {
                unreadMessages.length ?
                <h1>You have {unreadMessages.length} unread messages!</h1> :
                null
            }
            
        </div>
    )
}
```

#### Other ways to render conditionally

We can also use if, if/else, and switch to conditionally render something.

This time we will have two conditions:

    Check if the animals property is provided
    Check if the animals length is greater than 0


```js
function List(props) {
  if (!props.animals) {
    return <div>Loading...</div>;
  }
  else if (props.animals.length === 0) {
    return <div>There are no animals in the list!</div>;
  }

  return (
    <ul> { props.animals.map( animal => <li key={animal}>{animal}</li> ) } </ul>
  );
}

function App() {
  const animals = [];

  return (
    <div>
      <h1>Animals: </h1>
      <List animals={animals} />
    </div>
  );
}
```


