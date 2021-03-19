Promises and Async/Await


When you need to work with asynchronous operations, usually have to deal with promise objects.

A promise is an object that might deliver data at a later point in the program.

An example of an async function that returns a promise is the web fetch API that's natively available in some browsers. Here we're fetching information from the top‑level GitHub API.
```js
const fetchData = () => {
  fetch('https://api.github.com').then(resp => {
    resp.json().then(data => {
      console.log(data);
    });
  });
};

fetchData();
```
Since fetch returns a promise, to consume that promise, we do at .then call on the result of fetch and supply a callback function in here. This callback function will receive the data from the API. The fetch API has a raw response. If you need to parse the data as JSON, you need to call the json method on the response object, and that json method is also on asynchronous one, so it returns a promise as well. To get the data, we need another .then call on the result of the json method, and in the callback of that, we can access the data.

As you can see, this syntax might get complicated with more nesting of asynchronous operations or when we need to combine this with any looping logic. You can simplify the nesting by making each promise callback return the promise object, but the whole .then syntax is a bit less readable than the modern way to consume promises in JavaScript, which is using async await:
```js
const fetchData = async () => {
  const resp = await fetch('https://api.github.com');
  const data = await resp.json();
  console.log(data);
};

fetchData();
```
You just await on the asynchronous call that returns a promise, and that will give you back the response object. Then you can await on the json method to access the JSON data. And to make these await calls, you need to label the function as async, and this will work exactly the same. The async await syntax is just a way for us to consume promises without having to nest .then calls. It's a bit simpler to read, but keep in mind that once you await on anything in a function like fetchData here, this function itself becomes asynchronous, and it will return a promise object.
