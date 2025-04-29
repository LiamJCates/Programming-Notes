# Forms

https://react.dev/reference/react-dom/components/form

https://developer.mozilla.org/en-US/docs/Web/HTML/Reference/Elements/form



<form>

To create interactive controls for submitting information, render the built-in browser <form> component.


The <form> HTML element represents a document section containing interactive controls for submitting information.


The built-in browser <form> component lets you create interactive controls for submitting information.

<form action={search}>
    <input name="query" />
    <button type="submit">Search</button>
</form>




```jsx
import React from 'react';
import ReactDOM from 'react-dom/client';

function App() {
  
  function handleSubmit(event) {
    event.preventDefault() //prevent form refresh
    const formEl = event.currentTarget  // get current event
    const formData = new FormData(formEl) //init FormData from event data
    const email = formData.get("email") // input name attribute specifies form field to extract 
    // Submit the info to a backend
    formEl.reset() // clear form on submit
  }
  
  return (
    <section>
      <h1>Signup form</h1>
      <form onSubmit={handleSubmit} method="post"> // change from GET so that url is not generated
        <label>Email:
        <input id="email" type="email" name="email" placeholder="joe@schmoe.com" />
        </label>// wrap input with label tags
        <br />
        
        <label htmlFor="password">Password:</label> // Or use the htmlFor attribute with the id of the input it is related to
        <input id="password" type="password" name="password" />
        <br />
        
        <button>Submit</button>
        
      </form>
    </section>
  )
}

ReactDOM.createRoot(document.getElementById('root')).render(<App />);
```


React 19 improvements allow us to use the form action attribute and lets us be less verbos

```jsx
import React from 'react';
import ReactDOM from 'react-dom/client';

function App() {
  
  function signUp(formData) {
    /* These are no longer required
        event.preventDefault() //prevent form refresh
        const formEl = event.currentTarget  // get current event
        const formData = new FormData(formEl) //init FormData from event data
    */
    const email = formData.get("email")
    //formEl.reset() React clears form for us
  }
  
  return (
    <section>
      <h1>Signup form</h1>
      //change from onSubmit to action attribute
      // no longer need method attribute
      <form action={signUp}> 
        <label htmlFor="email">Email:</label>
        <input id="email" type="email" name="email" placeholder="joe@schmoe.com" />
        <br />
        
        <label htmlFor="password">Password:</label>
        <input id="password" type="password" name="password" />
        <br />
        
        <button>Submit</button>
        
      </form>
    </section>
  )
}

ReactDOM.createRoot(document.getElementById('root')).render(<App />);
```


Radio buttons example

```jsx
import React from 'react';
import ReactDOM from 'react-dom/client';

function App() {
  function signUp(formData) {
    const employmentStatus = formData.get("employmentStatus")
  }

  return (
    <section>
      <h1>Signup form</h1>
      <form action={signUp}>

        // so that we can only select one of the radio buttons, the name attributes must match
        // each radio must have a value so that we can extract the selected option
        // we can provide a default answer with the defaultChecked attribute

        <fieldset> // wrap related radio buttons
          <legend>Employment Status:</legend> // provide a description for buttons in a set
          <label>
            <input type="radio" name="employmentStatus" value="unemployed" /> 
            Unemployed
          </label>
            <label>
              <input type="radio" name="employmentStatus" value="part-time" />
              Part-time
          </label>
            <label>
              <input type="radio" name="employmentStatus" defaultChecked={true} value="full-time" />
              Full-time
          </label>
        </fieldset>



        <button>Submit</button>

      </form>
    </section>
  )
}

ReactDOM.createRoot(document.getElementById('root')).render(<App />);
```


Check boxes are similar, except that we must use `getAll()` to return an array of selected `value` attributes
```jsx
import React from 'react';
import ReactDOM from 'react-dom/client';

function App() {
    function submitRestrictions(formData) {
    const dietaryRestrictions = formData.getAll("dietaryRestrictions")
    console.log(dietaryRestrictions)
  }

  return (
    <section>
      <h1>Signup form</h1>
      <form action={submitRestrictions}>

        <fieldset>
          <legend>Dietary restrictions:</legend>
          <label>
            <input type="checkbox" name="dietaryRestrictions" value="kosher" />
            Kosher
        </label>
          <label>
            <input type="checkbox" name="dietaryRestrictions" value="vegan" />
            Vegan
        </label>
          <label>
            <input type="checkbox" name="dietaryRestrictions" defaultChecked={true} value="gluten-free" />
            Gluten-free
        </label>
        </fieldset>




        <button>Submit</button>

      </form>
    </section>
  )
}

ReactDOM.createRoot(document.getElementById('root')).render(<App />);
```


Drop down example

```jsx
import React from 'react';
import ReactDOM from 'react-dom/client';

function App() {

  function submitColor(formData) {
    // the name property is used to extract the value
    const selectedColor = formData.get("favColor")
    console.log(selectedColor)
  }

  return (
    <section>
      <h1>Signup form</h1>
      <form action={submitColor}>

        <label htmlFor="favColor">What is your favorite color?</label>
        // set defaultValue to empty string to defaul to user prompt,
        //    or remove this to default to first option
        // or provide one of the value attributes from below

        // the required attribute may be used to prevent form submission without a user selection

        <select id="favColor" name="favColor" defaultValue="" required>
        // provide the disabled attribute to prevent the prompt from being selectable

          <option value="" disabled>-- Choose a color --</option> // user promp has emtpy value
          <option value="red">Red</option>
          <option value="orange">Orange</option>
          <option value="yellow">Yellow</option>
          <option value="green">Green</option>
          <option value="blue">Blue</option>
          <option value="indigo">Indigo</option>
          <option value="violet">Violet</option>
        </select>

        <button>Submit</button>

      </form>
    </section>
  )
}

ReactDOM.createRoot(document.getElementById('root')).render(<App />);
```


to create an object that uses all of the name properties as keys and all of the values submitted by the user us `Object.fromEntries(formData)` an provide it the form data


```jsx
function logFormData(formData) {
    console.log(Object.fromEntries(formData))
  }
```

their is a single caveat, this object will only return the first selected value from a group of check boxes, to get all boxes that were checked. We are required to use `formData.getAll()` with the desired check box name value. Then use the spread operator to overwrite the single data extracted by the object with our individually extracted array.

```jsx
  function signUp(formData) {
    const data = Object.fromEntries(formData)
    const dietaryRestrictions = formData.getAll("dietaryRestrictions")
    const allData = {
      ...data,
      dietaryRestrictions
    }
    console.log(allData)
  }
```