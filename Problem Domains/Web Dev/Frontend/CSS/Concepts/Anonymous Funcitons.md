 Anonymous Functions

Anonymous functions are useful and expressive in some cases where a function's name is meaningless and cumbersome, such as an initial window.onload handler. But over-using anonymous functions leads to code that is too heavily nested and has too few names to guide the programmer, so over-use of anonymous functions should be avoided. In general, give names to your functions unless the name is truly useless and meaningless.

Bad
```javascript
window.onload = function() {
  myButton.onclick = function() {
    setTimeout(function() {
      alert("hi!");
    }, 1000);
  };
}
```

Good
```javascript
window.onload = function() {
  myButton.onclick = myButtonClick;
}

function myButtonClick() {
  setTimeout(displayMessage, 1000);
}

function displayHiMessage() {
  alert("hi!");
}
```
