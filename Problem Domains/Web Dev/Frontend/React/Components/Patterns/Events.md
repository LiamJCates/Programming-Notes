# Responding to Events

You can respond to events by declaring event handler functions inside your components.

React lets you add event handlers to your JSX. Event handlers are your own functions that will be triggered in response to user interactions like clicking, hovering, focusing on form inputs, and so on.

Built-in components like <button> only support built-in browser events like onClick. However, you can also create your own components, and give their event handler props any application-specific names that you like.

```js
function MyButton() {
  function handleClick() {
    alert('You clicked me!');
  }

  return (
    <button onClick={handleClick}>
      Click me
    </button>
  );
}
```

NOTE: Notice how `onClick={handleClick}` has no parentheses at the end! Using parentheses would call the event handler function, you only need to pass the reference down. 

React will call your event handler when the user clicks the button.




Components Reusability

One of the selling points about components is reusability, making a component generic enough so that we can reuse it in different cases.

Let's make the Button component more generic.
```js
function Button(props) {
  return (
    <button onClick={props.onClickFunction}>
      +1
    </button>
  );
}
```
Let's assume that we can pass in an increment value, and the Button component will use that value instead of the hard coded one.
```js
function Button(props) {
  return (
    <button onClick={props.onClickFunction}>
      +{props.increment}
    </button>
  );
}
```
We upgraded the +1 to something dynamic, a property of the component, the amount to increment, passed down from the parent. We named this new attribute increment, and the value we need to pass here is a number. Since the value here is not a string, we'll need to use a set of curly braces here as well.
```js
<Button onClickFunction = {handleClick} increment={5}/>
```
So, for example, we can pass in 5. One quick note about this syntax here. We could pass the number like this increment="5", but the Button component in this case will see and work with that value as a string. So don't do that. Keep it this way, increment={5}, so the Button component receives it as a numeric value, not a string. To use this new increment prop, we access it here as props.increment. There we go. We've got a +5. So let me go ahead and add a few more buttons here and use increment values of 1, 5, 10, and 100.
```js
function App () {
  const[counter, setCounter] = useState(0);
  const handleClick = () => setCounter(counter+1);
  return (
  <div>
    <Button onClickFunction = {handleClick} increment={1}/>
    <Button onClickFunction = {handleClick} increment={5}/>
    <Button onClickFunction = {handleClick} increment={10}/>
    <Button onClickFunction = {handleClick} increment={100}/>
    <Display message={counter}/>
  </div>
  );
}
```

The UI rendered four buttons now with different labels, but they're not going to work yet. In fact, all of them would still increment with a +1 at this point because we did not change their handlers. So the challenge now is to make each button increment the globally displayed counter by its increment value, not just 1.

This incrementCounter function here will now need to receive an increment value, and we can use its argument to do that.
```js
const incrementCounter = (incrementValue) => setCounter(counter+incrementValue);
```
So receive incrementValue in here, and instead of using +1 we'll use the new incrementValue. Now we can invoke the incrementCounter function with different values. The incrementCounter function is aliased as onClickFunction for the button. So the Button component needs to invoke the onClick function with an argument now, which is its own increment value, and that can be accessed using props.increment. But we can't just pass the argument to onClickFunction like this onClickFunction(props.increment) because remember, we need a function reference for the onClickEvent handler, and what this is not a reference. It's an invocation of a function.

But we can simply wrap this invocation in an inline function to make it into a reference, and through the magic of JavaScript closures, this will work just fine.
```js
<button onClick={() => props.onClickFunction(props.increment)}>
```
But again, it's a bit cleaner to do this logic inside the handleClick local function here. So let me go back to handleClick and put this new logic inside handleClick:

```js
function Button(props) {
  const handleClick = () => props.onClickFunction(props.increment);
  return (
    <button onClick={handleClick}>
      +{props.increment}
    </button>
  );
}
```
Make sure this is still working, and all is good.

This is the final code of this example:
https://jscomplete.com/playground/rgs1.6


Through this example, we've touched on the many basic React concepts, but this is still a relatively simple example. Let's build something a bit more useful next. But first, I need you to absolutely understand the value you're getting from using React's tree reconciliation under the hood That's the next video.






### Event propagation

Event handlers will also catch events from any children your component might have. We say that an event “bubbles” or “propagates” up the tree: it starts with where the event happened, and then goes up the tree.

This <div> contains two buttons. Both the <div> and each button have their own onClick handlers. Which handlers do you think will fire when you click a button?

export default function Toolbar() {
  return (
    <div className="Toolbar" onClick={() => {
      alert('You clicked on the toolbar!');
    }}>
      <button onClick={() => alert('Playing!')}>
        Play Movie
      </button>
      <button onClick={() => alert('Uploading!')}>
        Upload Image
      </button>
    </div>
  );
}

If you click on either button, its onClick will run first, followed by the parent <div>’s onClick. So two messages will appear. If you click the toolbar itself, only the parent <div>’s onClick will run.
Pitfall

All events propagate in React except onScroll, which only works on the JSX tag you attach it to.

### Stopping propagation

Event handlers receive an event object as their only argument. By convention, it’s usually called e, which stands for “event”. You can use this object to read information about the event.

That event object also lets you stop the propagation. If you want to prevent an event from reaching parent components, you need to call e.stopPropagation() like this Button component does:

function Button({ onClick, children }) {
  return (
    <button onClick={e => {
      e.stopPropagation();
      onClick();
    }}>
      {children}
    </button>
  );
}

export default function Toolbar() {
  return (
    <div className="Toolbar" onClick={() => {
      alert('You clicked on the toolbar!');
    }}>
      <Button onClick={() => alert('Playing!')}>
        Play Movie
      </Button>
      <Button onClick={() => alert('Uploading!')}>
        Upload Image
      </Button>
    </div>
  );
}

When you click on a button:

    React calls the onClick handler passed to <button>.
    That handler, defined in Button, does the following:
        Calls e.stopPropagation(), preventing the event from bubbling further.
        Calls the onClick function, which is a prop passed from the Toolbar component.
    That function, defined in the Toolbar component, displays the button’s own alert.
    Since the propagation was stopped, the parent <div>’s onClick handler does not run.

As a result of e.stopPropagation(), clicking on the buttons now only shows a single alert (from the <button>) rather than the two of them (from the <button> and the parent toolbar <div>). Clicking a button is not the same thing as clicking the surrounding toolbar, so stopping the propagation makes sense for this UI.
 
### Passing handlers as alternative to propagation

Notice how this click handler runs a line of code and then calls the onClick prop passed by the parent:

function Button({ onClick, children }) {
  return (
    <button onClick={e => {
      e.stopPropagation();
      onClick();
    }}>
      {children}
    </button>
  );
}

You could add more code to this handler before calling the parent onClick event handler, too. This pattern provides an alternative to propagation. It lets the child component handle the event, while also letting the parent component specify some additional behavior. Unlike propagation, it’s not automatic. But the benefit of this pattern is that you can clearly follow the whole chain of code that executes as a result of some event.

If you rely on propagation and it’s difficult to trace which handlers execute and why, try this approach instead.

### Preventing default behavior

Some browser events have default behavior associated with them. For example, a <form> submit event, which happens when a button inside of it is clicked, will reload the whole page by default:

export default function Signup() {
  return (
    <form onSubmit={() => alert('Submitting!')}>
      <input />
      <button>Send</button>
    </form>
  );
}

You can call e.preventDefault() on the event object to stop this from happening:

export default function Signup() {
  return (
    <form onSubmit={e => {
      e.preventDefault();
      alert('Submitting!');
    }}>
      <input />
      <button>Send</button>
    </form>
  );
}

Don’t confuse e.stopPropagation() and e.preventDefault(). They are both useful, but are unrelated:

    e.stopPropagation() stops the event handlers attached to the tags above from firing.
    e.preventDefault() prevents the default browser behavior for the few events that have it.



### Recap

    You can handle events by passing a function as a prop to an element like <button>.
    Event handlers must be passed, not called! onClick={handleClick}, not onClick={handleClick()}.
    You can define an event handler function separately or inline.
    Event handlers are defined inside a component, so they can access props.
    You can declare an event handler in a parent and pass it as a prop to a child.
    You can define your own event handler props with application-specific names.
    Events propagate upwards. Call e.stopPropagation() on the first argument to prevent that.
    Events may have unwanted default browser behavior. Call e.preventDefault() to prevent that.
    Explicitly calling an event handler prop from a child handler is a good alternative to propagation.
