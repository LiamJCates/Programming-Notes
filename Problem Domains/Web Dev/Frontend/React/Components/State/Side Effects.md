# Side Effects

React components must synchronize with external systems—data fetching, subscriptions, timers, logging, manual DOM mutations, etc. — collectively called **side effects**.  
  
Effective side-effect management entails:   
  
- declaring effects with correct dependencies  
- cleaning up subscriptions or timers to prevent memory leaks  
- splitting unrelated effects  
- memoizing callbacks  
- knowing when **not** to use effects at all  

Common pitfalls include:
  
- missing dependencies (stale closures)  
- infinite loops  
- uncleaned subscriptions  
- over-reliance on effects for pure logic  
  
You can avoid these by:  
  
- adhering to the Rules of Hooks  
- leveraging ESLint’s `react-hooks` rules  
- returning cleanup functions  
- moving complex logic into custom Hooks or external libraries  
  
---

## Side Effects in React   
  
Side effects are operations that reach outside the component to interact with the world: network requests, timers, subscriptions, logging, or manual DOM updates 
  
Without proper management, side effects can lead to inconsistent UI state, memory leaks, or performance issues.
  
### 1.1 Pure Rendering vs. Side Effects  

- **Pure rendering**: computing JSX from props/state —no external interactions.  
- **Side effects**: anything else — e.g., updating `document.title`, fetching data, registering event listeners.



---

## 2. Tools for Managing Side Effects  

### 2.1 `useEffect` Hook  

React's primary tool for managing side effects in function components is the `useEffect` Hook, combining lifecycle methods (`componentDidMount`, `componentDidUpdate`, `componentWillUnmount`) into one API.

React’s **useEffect** Hook enables function components to synchronize with external systems by running side‑effectful code *after* React has updated the DOM.

Common use cases include fetching data on mount, validating inputs on state change, subscribing/unsubscribing to external events, and updating document titles. 

### 2.2 `useLayoutEffect`  

Runs synchronously after DOM mutations but before the browser paints. Use for measurements or DOM reads that must happen before paint to avoid flicker.

### 2.3 Custom Hooks  

Encapsulate and reuse side-effect logic (e.g., data fetching, event subscriptions) across components.

### 2.4 External Libraries  

- **React Query / TanStack Query**: Manages server state, caching, retries, synchronization—minimizes manual effects for data fetching.  
- **SWR**: Similar benefits for data fetching with stale-while-revalidate caching.

---

## 3. Declaring `useEffect`

### 3.1 Syntax  
```js
useEffect(() => {
  // Side effect callback
  return () => {
    // Cleanup code
  };
}, [dep1, dep2]);
```
- **Callback** runs after render. A function that contains side‑effect code. It can optionally return a **cleanup** function. 
- **Cleanup** (optional) function return value, to be run before next effect or on unmount, used to undo or unsubscribe from the effect.
- **Dependencies** (optional) controls when the effect re-runs:  
  - `[]`: once on mount  
  - Omitted: every render  
  - `[vars]`: when any var changes  

```js
useEffect(() => {
  // This runs after every render
});

useEffect(() => {
  // This runs only on mount (when the component appears)
}, []);

useEffect(() => {
  // This runs on mount *and also* if either a or b have changed since the last render
}, [a, b]);
```

---

##  Common Use Cases

### 2.1 Data Fetching on Mount  

Run a fetch once when the component mounts:

```jsx
useEffect(() => {
  fetch('/api/data')
    .then(res => res.json())
    .then(setData);
}, []);  // Empty array ensures this runs only once
```

This pattern is ubiquitous for loading initial data.

---

### 2.2 Responding to State or Prop Changes  

Validate input or filter lists when dependencies update:

```jsx
const [query, setQuery] = useState('');
const [results, setResults] = useState([]);

useEffect(() => {
  const filtered = items.filter(item => item.includes(query));
  setResults(filtered);
}, [query, items]);  // Runs whenever `query` or `items` changes
```
Enables live search or validation flows .

---

### 2.3 Subscriptions and Event Listeners  
Attach and clean up listeners to avoid memory leaks:

```jsx
useEffect(() => {
  function handleResize() { setWidth(window.innerWidth); }
  window.addEventListener('resize', handleResize);
  return () => {
    window.removeEventListener('resize', handleResize);
  };
}, []);  // Clean-up runs on unmount
```

Event handlers are nested functions inside your components that do things rather than just calculate them. An event handler might update an input field, submit an HTTP POST request to buy a product, or navigate the user to another screen. Event handlers contain “side effects” (they change the program’s state) caused by a specific user action (for example, a button click or typing).

---

### 2.4 Timers and Intervals  

Set up and clear intervals:

```jsx
useEffect(() => {
  const id = setInterval(() => tick(), 1000);
  return () => clearInterval(id);
}, []);  // Ensures only one interval is active
```

---

### 2.5 Manual DOM Updates  

Interact with non‑React libraries or update document titles:

```jsx
useEffect(() => {
  document.title = `You clicked ${count} times`;
}, [count]);  // Updates title whenever `count` changes
```
This replaces class‑based lifecycle methods like `componentDidMount` and `componentDidUpdate` citeturn0search16.

---

## 4. Best Practices

1. **Include All Dependencies**  
   List every external variable used inside the effect to avoid stale closures. Use ESLint’s `react-hooks/exhaustive-deps` rule.  
2. **Split Unrelated Effects**  
   Separate distinct concerns into multiple `useEffect` calls for clarity and maintainability.  
3. **Return Cleanup Functions**  
   Always clean up subscriptions, timers, or event listeners to prevent memory leaks.  
4. **Avoid Async Directly in Effect Callback**  
   Don’t make the effect callback `async`. Instead, define and call an inner async function.  
5. **Memoize Callbacks and Values**  
   Wrap functions or objects in `useCallback`/`useMemo` when used in the dependency array to prevent infinite loops.  
6. **Opt Out When You Don’t Need Effects**  
  If you only need to derive state from props or other state, compute it directly during render rather than using an effect.  
7. **Use Custom Hooks for Reusable Logic**  
   Encapsulate common patterns (e.g., data fetching, form subscriptions) into custom Hooks.





---



## 5. Common Pitfalls & Resolutions

| Pitfall                                        | Resolution |
|------------------------------------------------|--------------------------------------------------------------------------------|
| **Missing Dependencies**                       | Effect doesn’t re-run when needed or uses stale values. **Fix:** List every external value in dependency array; use ESLint to detect omissions. |
| **Infinite Loops**                             | Caused by effects updating a dependency that triggers the same effect. **Fix:** Ensure stable references via `useCallback`/`useMemo` or refine the dependency list. |
| **Memory Leaks (uncleaned subscriptions)**     | Listeners or timers persist after unmount. **Fix:** Return cleanup function to remove listeners, clear timers, cancel fetches. |
| **Stale State in Closures**                    | Use functional state updates (`setCount(c => c+1)`) or include state in deps; memoize handlers. |
| **Over-Rendering with Effects**                | Move pure logic out of effects; use conditional rendering or memoization instead |
| **Overusing Effects**                          | Over-reliance on effects for logic that could be handled during render. **Fix:** Move pure computations out of `useEffect`. |
| **Async Effect Callback**                      | Declaring the effect callback as `async` returns a promise instead of cleanup. **Fix:** Define async logic inside the effect as seen below | 
```js
useEffect(() => {
  let cancelled = false;
  async function fetchData() { … }
  fetchData();
  return () => { cancelled = true; };
}, [deps]);
``` 


---

## 6. Advanced Patterns

### 5.1 Data Fetch with Cleanup

```jsx
import { useEffect, useState } from 'react';

function DataLoader({ url }) {
  const [data, setData] = useState(null);

  useEffect(() => {
    let cancelled = false;

    async function fetchData() {
      const res = await fetch(url);
      const json = await res.json();
      if (!cancelled) setData(json);
    }

    fetchData();

    return () => {
      cancelled = true;  // Prevent state update after unmount
    };
  }, [url]);

  return data ? <pre>{JSON.stringify(data, null, 2)}</pre> : <p>Loading...</p>;
}
```

---

### 6.1 Custom Hook: Data Fetching  
```js
function useFetch(url) {
  const [data, setData] = useState(null);
  useEffect(() => {
    let cancelled = false;
    async function fetchData() {
      const res = await fetch(url);
      const json = await res.json();
      if (!cancelled) setData(json);
    }
    fetchData();
    return () => { cancelled = true; };
  }, [url]);
  return data;
}
```

---

### 6.2 Using React Query  
```js
import { useQuery } from '@tanstack/react-query';
function Todos() {
  const { data, isLoading, error } = useQuery(['todos'], () => fetch('/api/todos').then(r => r.json()));
  if (isLoading) return 'Loading…';
  if (error) return 'Error!';
  return <ul>{data.map(t => <li key={t.id}>{t.text}</li>)}</ul>;
}
```  
This offloads caching, retries, and sync logic to a library.

---

### 6.3 Event Subscription Hook  
```js
function useWindowWidth() {
  const [width, setWidth] = useState(window.innerWidth);
  useEffect(() => {
    const handler = () => setWidth(window.innerWidth);
    window.addEventListener('resize', handler);
    return () => window.removeEventListener('resize', handler);
  }, []);
  return width;
}
```

---


### 7.1 Debounced Search Input  

```js
function Search({ items }) {
  const [query, setQuery] = useState('');
  const [results, setResults] = useState([]);
  useEffect(() => {
    const id = setTimeout(() => {
      setResults(items.filter(i => i.includes(query)));
    }, 300);
    return () => clearTimeout(id);
  }, [query, items]);
  return (
    <>
      <input value={query} onChange={e => setQuery(e.target.value)} />
      <ul>{results.map(r => <li key={r}>{r}</li>)}</ul>
    </>
  );
}
```

```jsx
import { useEffect, useState } from 'react';

function Search({ items }) {
  const [query, setQuery] = useState('');
  const [results, setResults] = useState([]);

  useEffect(() => {
    const handler = setTimeout(() => {
      setResults(items.filter(i => i.includes(query)));
    }, 300);

    return () => clearTimeout(handler);
  }, [query, items]);

  return (
    <>
      <input value={query} onChange={e => setQuery(e.target.value)} />
      <ul>{results.map(r => <li key={r}>{r}</li>)}</ul>
    </>
  );
}
```

---

### 7.2 Cleanup of Subscription  
```js
import { useEffect, useState } from 'react';

function ChatRoom({ roomId }) {
  const [messages, setMessages] = useState([]);
  useEffect(() => {
    const sub = chatAPI.subscribe(roomId, newMsg => setMessages(msgs => [...msgs, newMsg]));
    return () => chatAPI.unsubscribe(sub);
  }, [roomId]);
  return <MessageList messages={messages} />;
}
```

```jsx
import { useEffect, useState } from 'react';

function WindowWidth() {
  const [width, setWidth] = useState(window.innerWidth);

  useEffect(() => {
    function handleResize() {
      setWidth(window.innerWidth);
    }
    window.addEventListener('resize', handleResize);
    return () => window.removeEventListener('resize', handleResize);
  }, []);  // Empty array: subscribe once
  return <div>Width: {width}</div>;
}
```


([Avoiding 5 Pitfalls with React JS useEffect - Medium](https://medium.com/%40asiandigitalhub/avoiding-5-pitfalls-with-react-js-useeffect-ecf868ae9726))
([Hooks Pattern - Patterns.dev](https://www.patterns.dev/react/hooks-pattern/)). 
([React's useEffect Hook Simplified: Manage Side Effects Like a Pro](https://dev.to/chintanonweb/reacts-useeffect-hook-simplified-manage-side-effects-like-a-pro-2clj)).
([You Might Not Need an Effect - React](https://react.dev/learn/you-might-not-need-an-effect)).
([Hooks Pattern - Patterns.dev](https://www.patterns.dev/react/hooks-pattern/)).
([Reusing Logic with Custom Hooks - React](https://react.dev/learn/reusing-logic-with-custom-hooks))
([Overview | TanStack Query React Docs](https://tanstack.com/query/latest/docs/framework/react/overview))
([Using SWR and React Query for Efficient Data Fetching in React](https://medium.com/%40ignatovich.dm/using-swr-and-react-query-for-efficient-data-fetching-in-react-87f4256910f0))
[Pitfalls of useEffect for React Programmers | by Inna Sinicka - Medium](https://medium.com/better-programming/pitfalls-of-useeffect-for-react-programmers-4ac3f73284b5)
[What I learned from React-Query, and why I won't use it again Duda](https://medium.com/duda/what-i-learned-from-react-query-and-why-i-will-not-use-it-in-my-next-project-a459f3e91887)
([Understanding React's useEffect cleanup function - LogRocket Blog](https://blog.logrocket.com/understanding-react-useeffect-cleanup-function/))
([How to stop memory leak in useEffect hook react - Stack Overflow](https://stackoverflow.com/questions/58038008/how-to-stop-memory-leak-in-useeffect-hook-react))
([useEffect Explained: Managing Side Effects in React Apps](https://blog.bitsrc.io/useeffect-explained-managing-side-effects-in-react-applications-eeade81c5b00))
([10 Best Practices for Efficient State and Side Effect Management](https://medium.com/%40stheodorejohn/10-best-practices-for-efficient-state-and-side-effect-management-mastering-useeffect-in-react-c8278890335))
([How to stop memory leak in useEffect hook react - Stack Overflow](https://stackoverflow.com/questions/58038008/how-to-stop-memory-leak-in-useeffect-hook-react))
([Understanding React's useEffect cleanup function - LogRocket Blog](https://blog.logrocket.com/understanding-react-useeffect-cleanup-function/))
([useEffect Explained: Managing Side Effects in React Apps](https://blog.bitsrc.io/useeffect-explained-managing-side-effects-in-react-applications-eeade81c5b00))
([Why everyone hate useEffect? : r/reactjs - Reddit](https://www.reddit.com/r/reactjs/comments/1dtqk2s/why_everyone_hate_useeffect/))
([7 Common Mistakes When Using React Hooks - Telerik.com](https://www.telerik.com/blogs/7-common-mistakes-using-react-hooks))






memoization
https://medium.com/@sdolidze/react-hooks-memoization-99a9a91c8853





















a Clock component that shows how many seconds have passed since the user has loaded the webpage. To update it every second, we can use our nifty setInterval function to add one to the counter state variable, every second. 

```js
import { useState } from "react";

export default function Clock() {
  const [counter, setCounter] = useState(0);

  setInterval(() => {
    setCounter(count => count + 1)
  }, 1000);

  return (
    <p>{counter} seconds have passed.</p>
  );
}
```

our counter gose berserk, because the setInterval function is being called not once, but at every state render.

When our component first renders, it calls our initial setInterval function. That interval updates the state every second, triggering the component to re-render. But every re-render calls setInterval again, which triggers more frequent state updates, which each spawn new intervals

### useEffect hook

useEffect hook can be used to move the call outside the rendering calculation.

By default, useEffect hook runs on every render. Since setting state rerenders the component, we still get multiple setter calls on every render.

The second argument accepts an array of dependencies allowing the hook to re-render only when those dependencies are changed. So if you have a state variable and want to have some side-effect occur any time the state changes, you can use this hook and mention the state variable in the dependency array.

We pass an empty array in this example because we do not want the useEffect hook to run anytime other than the initial component render.

Usually, you do not need to add dependencies to your useEffecthook manually. Your linter should let you know about the dependencies it expects. Letting the linter show errors and fixing them instead of suppressing them is usually the best idea. On a general note, the following block does a good job of summing this point up.



```js
import { useEffect, useState } from "react";

export default function Clock() {
  const [counter, setCounter] = useState(0);

  useEffect(() => {
    setInterval(() => {
      setCounter(count => count + 1)
    }, 1000);
  }, [])

  return (
    <p>{counter} seconds have passed.</p>
  );
}
```

Oh, it’s not going berserk anymore! We still have an issue with the counter updating twice every second though. That can be understood as a behavior caused by the React StrictMode. It is supposed to help us catch bugs, so what is that bug here?

With StrictMode, the App component is mounted, unmounted, then mounted again. This behaviour of StrictMode is only in the development environment. Notice that every time the useEffect hook runs, a new setInterval is used. When the component is unmounted the first time, setInterval is not stopped, it keeps incrementing. This unnecessary behavior can be prevented by clearing the interval when the component is unmounted and that is where the third part of our useEffect hook comes in - the cleanup function.

### The clean-up function

You can return a function from the callback in the useEffect hook, which will be executed each time before the next effect is run, and one final time when the component is unmounted.

```js
import { useEffect, useState } from "react";

export default function Clock() {
  const [counter, setCounter] = useState(0);

  useEffect(() => {
    const key = setInterval(() => {
      setCounter(count => count + 1)
    }, 1000);

    return () => {
      clearInterval(key);
    };
  }, [])

  return (
    <p>{counter} seconds have passed.</p>
  );
}
```

```js
useEffect(
  () => {
    // execute side effect
    return () => {
      // cleanup function on unmounting or re-running effect
    }
  },
  // optional dependency array
  [/* 0 or more entries */]
)
```

But do we need the effect?

useEffect is a mechanism outside the concepts that React usually applies, allowing you to sync your component with various external systems like a server, API, or browser DOM. The single question that you can ask yourself before you use an effect is if there are any such external systems that need to be synced with, apart from props or state. Unnecessary useEffect hooks are code-smell, error-prone, and cause unnecessary performance issues.

Let us address a few cases where useEffect does not need to be used.

#### Not for Calculations based on state

    You do not need to use an effect if you are only calculating something based on the state during rendering. For a change in a component, due to a change in the props, you can calculate and set it during rendering.

```js
import { useState } from "react";

export default function AdditionDisplay() {
  const [number1, setNumber1] = useState(0);
  const [number2, setNumber2] = useState(0);

  // This is all unnecessary.

  // const [sum, setSum] = useState(0);
  // useEffect(() => {
  //   setSum(number1 + number2);
  // }, [number1, number2]);

  const sum = number1 + number2;

  return (
    <p>{number1} + {number2} = {sum}</p>
  );
}
```

#### Not For Events

You do not need effects for events. Code that runs when a component is displayed should be in effects, the rest should be in events.

```js
import { useState } from "react";

export default function App() {
    
    const [input, setInput] = useState("");

    const handleInput = (e) => {
        setInput(e.target.value);
    };

    // You should avoid direct manipulation when not necessary

    // useEffect(() => {
    //   document.getElementById("name").addEventListener("change", handleInput);
    //   return () => {
    //     document.getElementById("name").removeEventListener("change", handleInput);
    //   }
    // });

    return (
        <>
        {/* <input id="name" /> */}

        <input onChange={handleInput} value={input} />
        <p>{ input }</p>
        </>
    );
}
```
You do not need an effect to reset the state based on a condition most of the time. You have learned about keys in React. Just like using a key on a list’s item, adding one to a component, based on the state on which it should be reset creates a unique version of that component for each change in the value of the state.

If you are having issues with managing your state and want to use an effect to update the state of a parent or some other non-child component, consider lifting the state. As we know, in React, the state flows in one direction, generally down the DOM. So the parents know of the data before passing it to the children. If multiple children are required to make use of a single state, it should be moved up to the parent that has all of the components that need it, instead of using escape hatches like an effect.









Effects let you specify side effects that are caused by rendering itself, rather than by a particular event. Sending a message in the chat is an event because it is directly caused by the user clicking a specific button. However, setting up a server connection is an Effect because it should happen no matter which interaction caused the component to appear. Effects run at the end of a commit after the screen updates. This is a good time to synchronize the React components with some external system (like network or a third-party library).


### Fetch Data

```jsx
import React from "react"

export default function App(props) {
    const [starWarsData, setStarWarsData] = React.useState(null)
    
    fetch("https://swapi.dev/api/people/1")
        .then(res => res.json())
        .then(data => setStarWarsData(data))
    
    return (
        <div>
            <pre>{JSON.stringify(starWarsData, null, 2)}</pre>
        </div>
    )
}
```

While this might seem to work, because the fetch runs on every render, updating the state, it prompts a rerender and an infinite loop.
























## How to write an Effect

To write an Effect, follow these three steps:

1. Declare an Effect. By default, your Effect will run after every commit.
2. Specify the Effect dependencies. Most Effects should only re-run when needed rather than after every render. For example, a fade-in animation should only trigger when a component appears. Connecting and disconnecting to a chat room should only happen when the component appears and disappears, or when the chat room changes. You will learn how to control this by specifying dependencies.
3. Add cleanup if needed. Some Effects need to specify how to stop, undo, or clean up whatever they were doing. For example, “connect” needs “disconnect”, “subscribe” needs “unsubscribe”, and “fetch” needs either “cancel” or “ignore”. You will learn how to do this by returning a cleanup function.

Let’s look at each of these steps in detail.

### Step 1: Declare an Effect

To declare an Effect in your component, import the useEffect Hook from React.
Then, call it at the top level of your component and put some code inside your Effect

```jsx
import { useEffect } from 'react';

function MyComponent() {
  useEffect(() => {
    // Code here will run after *every* render
  });
  return <div />;
}
```

Every time your component renders, React will update the screen and then run the code inside useEffect. In other words, useEffect “delays” a piece of code from running until that render is reflected on the screen.

Let’s see how you can use an Effect to synchronize with an external system. Consider a <VideoPlayer> React component. It would be nice to control whether it’s playing or paused by passing an isPlaying prop to it:

```jsx
<VideoPlayer isPlaying={isPlaying} />;

function VideoPlayer({ src, isPlaying }) {
  // TODO: do something with isPlaying
  return <video src={src} />;
}
```
However, the browser <video> tag does not have an isPlaying prop. The only way to control it is to manually call the play() and pause() methods on the DOM element. You need to synchronize the value of isPlaying prop, which tells whether the video should currently be playing, with calls like play() and pause().

We’ll need to first get a ref to the <video> DOM node.

You might be tempted to try to call play() or pause() during rendering, but that isn’t correct:

```jsx
import { useState, useRef, useEffect } from 'react';

function VideoPlayer({ src, isPlaying }) {
  const ref = useRef(null);

  if (isPlaying) {
    ref.current.play();  // Calling these while rendering isn't allowed.
  } else {
    ref.current.pause(); // Also, this crashes.
  }

  return <video ref={ref} src={src} loop playsInline />;
}

export default function App() {
  const [isPlaying, setIsPlaying] = useState(false);
  return (
    <>
      <button onClick={() => setIsPlaying(!isPlaying)}>
        {isPlaying ? 'Pause' : 'Play'}
      </button>
      <VideoPlayer
        isPlaying={isPlaying}
        src="https://interactive-examples.mdn.mozilla.net/media/cc0-videos/flower.mp4"
      />
    </>
  );
}
```

    Runtime Error

    App.js: ref.current is null (9:4)

      6 |   if (isPlaying) {
      7 |     ref.current.play();  // Calling these while rendering isn't allowed.
      8 |   } else {
    >  9 |     ref.current.pause(); // Also, this crashes.
              ^
      10 |   }
      11 | 
      12 |   return <video ref={ref} src={src} loop playsInline />;


The reason this code isn’t correct is that it tries to do something with the DOM node during rendering. In React, rendering should be a pure calculation of JSX and should not contain side effects like modifying the DOM.

Moreover, when VideoPlayer is called for the first time, its DOM does not exist yet! There isn’t a DOM node yet to call play() or pause() on, because React doesn’t know what DOM to create until you return the JSX.

The solution here is to wrap the side effect with useEffect to move it out of the rendering calculation:

```jsx
import { useState, useRef, useEffect } from 'react';

function VideoPlayer({ src, isPlaying }) {
  const ref = useRef(null);

  useEffect(() => {
    if (isPlaying) {
      ref.current.play();
    } else {
      ref.current.pause();
    }
  });

  return <video ref={ref} src={src} loop playsInline />;
}

export default function App() {
  const [isPlaying, setIsPlaying] = useState(false);
  return (
    <>
      <button onClick={() => setIsPlaying(!isPlaying)}>
        {isPlaying ? 'Pause' : 'Play'}
      </button>
      <VideoPlayer
        isPlaying={isPlaying}
        src="https://interactive-examples.mdn.mozilla.net/media/cc0-videos/flower.mp4"
      />
    </>
  );
}
```

By wrapping the DOM update in an Effect, you let React update the screen first. Then your Effect runs.

When your VideoPlayer component renders (either the first time or if it re-renders), a few things will happen. First, React will update the screen, ensuring the <video> tag is in the DOM with the right props. Then React will run your Effect. Finally, your Effect will call play() or pause() depending on the value of isPlaying.

### Pitfall: Infinite Loops

By default, Effects run after every render. This is why code like this will produce an infinite loop:

```jsx
const [count, setCount] = useState(0);
useEffect(() => {
  setCount(count + 1);
});
```

Effects run as a result of rendering. Setting state triggers rendering. Setting state immediately in an Effect is like plugging a power outlet into itself. The Effect runs, it sets the state, which causes a re-render, which causes the Effect to run, it sets the state again, this causes another re-render, and so on.

Effects should usually synchronize your components with an external system. If there’s no external system and you only want to adjust some state based on other state, you might not need an Effect.


TODO
https://react.dev/learn/synchronizing-with-effects