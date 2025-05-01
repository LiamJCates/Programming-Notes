# Rendering

Before your components are displayed on screen, they must be rendered by React.

Instead of manipulating the browser's DOM directly, React creates a virtual DOM in memory, where it does all the necessary manipulating, before making the changes in the browser DOM.

The process of rerendering generates a new `virtual DOM` (Document Object Model) tree, a lightweight representation of the actual DOM that React uses to keep track of the current state of the UI. React then compares the new virtual DOM tree to the previous one and calculates the minimal set of changes needed to update the actual DOM. This behavior is managed by the `reconciliation algorithm`.

React finds out what changes have been made, and changes only what needs to be changed. 

This process of requesting and serving UI has three steps:

    Triggering a render
    Rendering the component
    Committing to the DOM

![Component Lifecycle](../../img/ComponentLifecycle.png)

---

## Trigger a render 

There are two reasons for a component to render:

    It’s the component’s initial render.
    A re-render when the component’s (or one of its ancestors’) props or state has been updated.


### Initial render

When your app starts, you need to trigger the initial render. Frameworks and sandboxes sometimes hide this code, but it’s done by calling createRoot with the target DOM node, and then calling its render method:

```jsx
import { createElement } from "react"
import { createRoot } from "react-dom/client"

const root = createRoot(document.getElementById("root"))
const reactElement = createElement("h1", null, "Hello World!")

root.render(
    reactElement
)
```

### Re-renders

Once the component has been initially rendered, you can trigger further renders by updating its state with the set function. Additionally, if a parent component is rerendered and, in the process, the props object that one or more of it's children receive from it change, then the child component will undergo a rerender.

---  

## Render and Commit

Once triggered, React splits every update into two distinct phases — **Render (Reconciliation)** and **Commit** processeses as implemented by the `Fiber architecture`.


## Why Two Phases?  
React’s Fiber architecture introduced a **Render** phase that is _pure_ (no DOM mutations) and “interruptible,” allowing React to pause and resume work for higher‐priority updates like user input or animations

Once work is complete, React enters the **Commit** phase, which _must_ run synchronously to apply all changes to the real DOM and invoke lifecycle methods or Hooks effects

---  

## Render Phase (Reconciliation)  

After you trigger a render, React calls your components to figure out what to display on screen. “Rendering” is React calling your components.

    On initial render, React will call the root component.
    For subsequent renders, React will call the function component whose state update triggered the render.

Rendering is recursive: if the updated component returns some other component, React will render that component next, and if that component also returns something, it will render that component next, and so on. The process will continue until there are no more nested components.

During the initial render, React will create the DOM nodes for each html tag.

During a re-render, React will calculate which of their properties, if any, have changed since the previous render. It won’t do anything with that information until the next step, the commit phase.


    NOTE:
    Rendering must always be a pure calculation:

    Same inputs, same output. Given the same inputs, a component should always return the same JSX.
    It should not change any objects or variables that existed before rendering.

    Otherwise, you can encounter confusing bugs and unpredictable behavior as your codebase grows in complexity. When developing in “Strict Mode”, React calls each component’s function twice, which can help surface mistakes caused by impure functions.


### Characteristics  
- **Pure computation**: Builds or updates the in‐memory Fiber tree without touching the DOM.  
- **Interruptible & Prioritized**: Work can be split into units and scheduled by priority (e.g., user input beats low‐priority updates).  

### Core Steps  
1. **Trigger/Reconciliation**: React calls `beginWork()` on each Fiber node to compute new child fibers, then `completeWork()` to finalize nodes and collect DOM mutations.  
2. **Diffing**: The new Fiber tree is compared to the previous tree using a heuristic O(n) algorithm to mark insertions, updates, and deletions.  
3. **Prepare for Commit**: React accumulates side‐effect flags (Placement, Update, Deletion) on fibers but defers all DOM operations until the commit phase.

---

## Commit Phase  

After rendering (calling) your components, React will modify the DOM.

    For the initial render, React will use the appendChild() DOM API to put all the DOM nodes it has created on screen.
    For re-renders, React will apply the minimal necessary operations (calculated while rendering!) to make the DOM match the latest rendering output.

React only changes the DOM nodes if there’s a difference between renders. For example, here is a component that re-renders with different props passed from its parent every second. Notice how you can add some text into the <input>, updating its value, but the text doesn’t disappear when the component re-renders:

```js
//Clock.js
export default function Clock({ time }) {
  return (
    <>
      <h1>{time}</h1>
      <input />
    </>
  );
}
```

```js
//App.js
import { useState, useEffect } from 'react';
import Clock from './Clock.js';

function useTime() {
  const [time, setTime] = useState(() => new Date());
  useEffect(() => {
    const id = setInterval(() => {
      setTime(new Date());
    }, 1000);
    return () => clearInterval(id);
  }, []);
  return time;b
}

export default function App() {
  const time = useTime();
  return (
    <Clock time={time.toLocaleTimeString()} />
  );
}
```

This works because during this last step, React only updates the content of \<h1> with the new time. It sees that the \<input> appears in the JSX in the same place as last time, so React doesn’t touch the \<input> — or its value!

### Sub‐Phases  
1. **Before Mutation**: Optional lifecycle methods/hooks (`getSnapshotBeforeUpdate`) run, and refs update to old DOM nodes.  
2. **Mutation**: React synchronously applies all DOM mutations—insert, update, remove—by calling `commitMutationEffectsOnFiber()`.  
3. **Layout**: After DOM is updated, React runs layout‐effects (`useLayoutEffect`), class‐component `componentDidMount`/`componentDidUpdate`, and updates refs to new nodes.  
4. **Passive Effects**: Finally (after a brief timeout), React runs passive effects (`useEffect`) outside the commit-synchronous work.

### Characteristics  
- **Synchronous & Non‐interruptible**: Ensures the DOM reaches a consistent state before control returns to the browser.  
- **Batched Updates**: All mutations from one update pass are applied together to minimize layout thrashing.

---

## React Fiber Internals  
- **Fiber Nodes**: Represent components and DOM elements in a linked structure with pointers to parent, child, and sibling fibers.  
- **Scheduler & Lanes**: React schedules fibers into “lanes” representing priority levels (e.g., user interactions vs. background updates).  
- **beginWork/completeWork**: `beginWork()` creates or updates child fibers; `completeWork()` generates the side‐effect list for commit.  
- **commitWork**: Walks the side‐effect list, invoking DOM APIs and lifecycle/Hook callbacks in the correct order.

https://medium.com/@aliWhosane/react-fiber-data-structure-demystified-d3794470a8a4

---

## Best Practices & Performance  
- **Avoid Expensive Work in Commit**: Keep synchronous DOM work minimal to prevent frame drops.  
- **Use `useLayoutEffect` Sparingly**: Only when you need to measure or imperatively modify the DOM before paint.  
- **Leverage Concurrent Features**: In React 18+, concurrent updates allow React to further split render work and improve responsiveness.

---

### Full Reference List  
1. React.dev: “Render and Commit” (Rendering steps)  ([Render and Commit - React](https://react.dev/learn/render-and-commit?utm_source=chatgpt.com))  
2. Sparsh Malhotra, Medium: “A Guide to React Rendering Behaviour - Part 1”  ([A Guide to React Rendering Behaviour - Part 1 | by Sparsh Malhotra](https://medium.com/%40sparshmalhotraaa/a-guide-to-react-rendering-behaviour-part-1-32374f0caa0d?utm_source=chatgpt.com))  
3. React docs (legacy): “Reconciliation”  ([Reconciliation - React](https://legacy.reactjs.org/docs/reconciliation.html?utm_source=chatgpt.com))  
4. LogRocket: “A deep dive into React Fiber”  ([A deep dive into React Fiber - LogRocket Blog](https://blog.logrocket.com/deep-dive-react-fiber/?utm_source=chatgpt.com))  
5. DeveloperWay: “Reconciliation in React”  ([React reconciliation: how it works and why should we care](https://www.developerway.com/posts/reconciliation-in-react?utm_source=chatgpt.com))  
6. isquaredsoftware.com: “Guide to React Rendering Behavior”  ([Blogged Answers: A (Mostly) Complete Guide to React Rendering ...](https://blog.isquaredsoftware.com/2020/05/blogged-answers-a-mostly-complete-guide-to-react-rendering-behavior/?utm_source=chatgpt.com))  
7. Souvik Sen, Medium: “Understanding React Reconciliation in React 18”  ([Understanding React Reconciliation in React 18: A Deep Dive](https://medium.com/%40souviksen093/understanding-react-reconciliation-in-react-18-a-deep-dive-16b083e5592a?utm_source=chatgpt.com))  
8. Chioma Christopher, Medium: “How React works behind the scene – render phase”  ([How React works behind the scene -React render phase - Medium](https://medium.com/%40chiomachristopher91/how-react-works-behind-the-scene-react-render-phase-ba00158ae81a?utm_source=chatgpt.com))  
9. Stack Overflow: “React and Reconciliation process”  ([React and Reconciliation process - Stack Overflow](https://stackoverflow.com/questions/78909355/react-and-reconciliation-process?utm_source=chatgpt.com))  
10. Stackademic Blog: “Understanding React’s Render Phase: A Simplified Guide”  ([Understanding React's Render Phase: A Simplified Guide |](https://blog.stackademic.com/understanding-reacts-render-phase-a-simplified-guide-3a84ea7aacba?utm_source=chatgpt.com))  
11. Liubomyr Klipinsky, Medium: “React Fiber: Reconciliation under the hood”  ([React Fiber: Reconciliation under the hood (with links to source code)](https://medium.com/%40LiubomyrKl/react-fiber-reconciliation-under-the-hood-with-links-to-source-code-14408664dbd5?utm_source=chatgpt.com))  
12. JSer.dev: “How React re-renders internally”  ([How does React re-render internally? - JSer.dev](https://jser.dev/2023-07-18-how-react-rerenders/?utm_source=chatgpt.com))  
13. Velotio: “An Introduction to React Fiber – The Algorithm Behind React”  ([An Introduction to React Fiber - The Algorithm Behind React](https://www.velotio.com/engineering-blog/react-fiber-algorithm?utm_source=chatgpt.com))  
14. Gervais Amoah, Dev.to: “Understanding React’s Fiber Tree”  ([A Deep Dive into React's Architecture and Rendering Process](https://dev.to/gervaisamoah/understanding-reacts-fiber-tree-a-deep-dive-into-reacts-architecture-and-rendering-process-2loo?utm_source=chatgpt.com))  
15. DhiWise: “A deep dive into React reconciliation algorithm”  ([A Deep Dive into React Reconciliation Algorithm - DhiWise](https://www.dhiwise.com/post/a-deep-dive-into-react-reconciliation-algorithm?utm_source=chatgpt.com))
