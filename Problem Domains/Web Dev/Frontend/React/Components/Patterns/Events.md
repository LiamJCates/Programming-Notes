### Responding to events

You can respond to events by declaring event handler functions inside your components:

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
Notice how `onClick={handleClick}` has no parentheses at the end! Using parentheses would call the event handler function, you only need to pass the reference down. 
React will call your event handler when the user clicks the button.
