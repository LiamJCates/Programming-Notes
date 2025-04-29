# Rendering Lists

https://react.dev/learn/rendering-lists

https://www.developerway.com/posts/react-key-attribute

```js
export function App() {
  return (
    <div>
      <h1>Animals: </h1>
      <ul>
        <li>Lion</li>
        <li>Cow</li>
        <li>Snake</li>
        <li>Lizard</li>
      </ul>
    </div>
  );
}
```

We should deal with a data structure (like a list) rather than hard-coding each animal. 
```js
export function App() {
  const animals = ["Lion", "Cow", "Snake", "Lizard"];

  return (
    <div>
      <h1>Animals: </h1>
      <ul>
        {
          animals.map((animal) => <li key={animal}>{animal}</li>)
        }
      </ul>
    </div>
  );
}
```

NOTE: You may be curious as to what the key is in our `<li>` element. We will dive into how keys work in the next lesson. But, to explain briefly, it is to let React know the identity of each element in the list. React must know this information if you are dealing with a dynamic list where you add or remove elements. Since we are only dealing with a static list, it does not matter for now.



If we move our `<ul>` element to a different component called `<ListAnimals />`. It still returns the `<ul>` element, but we can do a lot more with it as a component.

```js
function ListItem(props) {
  return <li>{props.animal}</li>
}

function ListAnimals(props) {
  return (
    <ul>
      {
        props.animals.map( animal => <ListItem key={animal} animal={animal} />)
      }
    </ul>
  );
}

export function App() {
  const animals = ["Lion", "Cow", "Snake", "Lizard"];

  return (
    <div>
      <h1>Animals: </h1>
      <ListAnimals animals={animals} />
    </div>
  );
}
```

### Why does React need keys?

When rendering lists, if any of the items in the list were to change, how would React know which item to update?

If the list were to change, one of two things should happen:

    we completely re-render the entire list, or:
    we hunt down the specific items that were changed and only re-render those.

Assuming we do NOT want to re-render the entire list, we need to track specific items.

When the list is updated for whatever reason (either from a server or a user interaction), React matches the keys of each of the previous list items to the updated list. If there were any changes, React will only update the items that have changed.

As long as keys remain consistent and unique, React can handle the DOM effectively and efficiently.



### Key Syntax

Keys are passed into the component or a DOM element as a prop. You should already be familiar with the syntax.

<Component key={keyValue} />
//or
<div key={keyValue} />



### Key Usage

What should be used as a key? 

Ideally, there should be some identifier that is unique to each item in the list. 

Most databases assign a unique id to each entry, so you shouldn’t have to worry about assigning an id yourself. 

If you are defining data yourself, it is good practice to assign a unique id to each item. You can use the `crypto.randomUUID()` function to generate a unique id.

```js
// a list of todos, each todo object has a task and an id
const todos = [
  { task: "mow the yard", id: crypto.randomUUID() },
  { task: "Work on Odin Projects", id: crypto.randomUUID() },
  { task: "feed the cat", id: crypto.randomUUID() },
];

function TodoList() {
  return (
    <ul>
      {todos.map((todo) => (
        // here we are using the already generated id as the key.
        <li key={todo.id}>{todo.task}</li>
      ))}
    </ul>
  );
}
```

Don't use the array index as a key since it can lead to confusing bugs if the list changes when items are deleted, inserted, or rearranged.

```js
const months = ['January', 'February', 'March', 'April', 'May', 'June', 'July', 'August', 'September', 'October', 'November', 'December'];

function MonthList() {
  return (
    <ul>
      {/* here we are using the index as key, don't do this */}
      {months.map((month, index) => (<li key={index}>{month}</li>))} 
    </ul>
  );
}
```

There is an anti-pattern you should be aware of. 

Keys should never be generated on the fly. Using `key={Math.random()}` or `key={crypto.randomUUID()}` while rendering the list defeats the purpose of the key, as now a new key will get created for every render of the list. As shown in the above example, key should be inferred from the data itself.

```js
const todos = [
  { task: "mow the yard", id: crypto.randomUUID() },
  { task: "Work on Odin Projects", id: crypto.randomUUID() },
  { task: "feed the cat", id: crypto.randomUUID() },
];

function TodoList() {
  return (
    <ul>
      {todos.map((todo) => (
        // DON'T do the following i.e. generating keys during render
        <li key={crypto.randomUUID()}>{todo.task}</li>
      ))}
    </ul>
  );
}
```