 yn# Introduction to the DOM

The Document Object Model (DOM) is a programming interface for web documents. It represents the page so that programs can change the document structure, style, and content. Although the DOM is not a programming language, it is most commonly used with JavaScript to build interactive web applications.

---

## What is the DOM?

- **Definition:**  
  The DOM is an object-oriented representation of an HTML or XML document. It defines the structure of a document as a tree of nodes (elements, text nodes, comments, etc.) that scripts can interact with.

- **Purpose:**  
  - Provides a structured representation of the document.
  - Allows dynamic changes (e.g., updating content or style) to the document through scripting languages like JavaScript.
  - Serves as a bridge between the web page and the scripts running on it.

- **Example – Accessing Elements:**  
  The following JavaScript snippet shows how to select all `<p>` elements and alert the node name of the first one:

  ```js
  const paragraphs = document.querySelectorAll("p");
  // paragraphs[0] is the first <p> element
  // paragraphs[1] is the second <p> element, etc.
  alert(paragraphs[0].nodeName);
  ```

---

## DOM and JavaScript

- **Relationship:**  
  Although the DOM is language-independent, it is most frequently manipulated using JavaScript in web browsers. The DOM provides a structured interface so that JavaScript can interact with web pages.

- **Key Points:**  
  - The DOM is not part of the JavaScript language itself but a Web API.
  - JavaScript (running in a browser) uses the DOM to access, manipulate, and update HTML and XML documents.
  - The same DOM model can also be implemented in other languages, though JavaScript is the most common.

- **Additional Note:**  
  The page even includes an example of DOM manipulation in Python (using `xml.dom.minidom`), but here we focus on the JavaScript examples.

---

## Accessing the DOM

- **How to Access:**  
  Developers do not need to do anything special to access the DOM. Once a script is loaded (either inline in a `<script>` tag or from an external file), the DOM is available via global objects such as `document` and `window`.

- **Basic Example – Logging a Message:**  
  You can run JavaScript as soon as the document is loaded. For instance, using an HTML attribute:

  ```html
  <body onload="console.log('Welcome to my home page!');">
    …
  </body>
  ```

- **Creating and Appending Elements:**  
  This example shows how to create a new `<h1>` element and add it to the document when the page loads:

  ```html
  <html lang="en">
    <head>
      <script>
        // Run this function when the document is loaded
        window.onload = () => {
          // Create new elements
          const heading = document.createElement("h1");
          const headingText = document.createTextNode("Big Head!");
          heading.appendChild(headingText);
          document.body.appendChild(heading);
        };
      </script>
    </head>
    <body></body>
  </html>
  ```

---

## Fundamental Data Types in the DOM

- **Document:**  
  Represents the entire HTML or XML document. It’s the root of the DOM tree.

- **Node:**  
  Every object within the DOM is a node (e.g., element nodes, text nodes, attribute nodes).

- **Element:**  
  Specific types of nodes representing HTML or XML elements. Elements inherit from the basic Node interface.

- **NodeList:**  
  An array-like collection of nodes (e.g., returned by `document.querySelectorAll()`).

- **Attr:**  
  Represents attributes of an element, accessible as part of an element’s properties.

- **NamedNodeMap:**  
  Similar to a NodeList but used for collections of attributes where nodes can also be accessed by name.

---

## DOM Interfaces

- **Overview:**  
  The DOM is built on multiple interfaces that define methods and properties for different types of nodes:
  
  - **document:** The root object.
  - **Element:** For HTML elements; extends the basic Node interface.
  - **HTML-specific Interfaces:** Many elements are further enhanced (e.g., `HTMLTableElement` for `<table>` elements).
  
- **Interfacing Example – Table Manipulation:**  
  The following snippet demonstrates accessing a table by its ID, iterating over its attributes, and modifying them:

  ```js
  const table = document.getElementById("table");
  const tableAttrs = table.attributes; // Access attributes from the Node/Element interface
  for (let i = 0; i < tableAttrs.length; i++) {
    // Check for the "border" attribute
    if (tableAttrs[i].nodeName.toLowerCase() === "border") {
      table.border = "1";
    }
  }
  // Set a summary attribute using the HTMLTableElement interface
  table.summary = "note: increased border";
  ```

- **Core Interfaces:**  
  Other common methods include:
  - `document.querySelector()` / `document.querySelectorAll()`
  - `document.createElement()`
  - `Element.innerHTML`, `Element.setAttribute()`, and `Element.getAttribute()`
  - `EventTarget.addEventListener()`
  - `Node.appendChild()` and `Node.removeChild()`
  - Global objects such as `window.onload`

---

## Examples

### Example 1: Setting Text Content

This example demonstrates how to set and clear text content inside a `<textarea>` using JavaScript.

- **HTML:**

  ```html
  <div class="container">
    <textarea class="story"></textarea>
    <button id="set-text" type="button">Set text content</button>
    <button id="clear-text" type="button">Clear text content</button>
  </div>
  ```

- **CSS:**

  ```css
  .container {
    display: flex;
    gap: 0.5rem;
    flex-direction: column;
  }

  button {
    width: 200px;
  }
  ```

- **JavaScript:**

  ```js
  const story = document.body.querySelector(".story");

  const setText = document.body.querySelector("#set-text");
  setText.addEventListener("click", () => {
    story.textContent = "It was a dark and stormy night...";
  });

  const clearText = document.body.querySelector("#clear-text");
  clearText.addEventListener("click", () => {
    story.textContent = "";
  });
  ```

### Example 2: Adding a Child Element

This example shows how to dynamically add and remove a child element within a parent `<div>`.

- **HTML:**

  ```html
  <div class="container">
    <div class="parent">parent</div>
    <button id="add-child" type="button">Add a child</button>
    <button id="remove-child" type="button">Remove child</button>
  </div>
  ```

- **CSS:**

  ```css
  .container {
    display: flex;
    gap: 0.5rem;
    flex-direction: column;
  }

  button {
    width: 100px;
  }

  div.parent {
    border: 1px solid black;
    padding: 5px;
    width: 100px;
    height: 100px;
  }

  div.child {
    border: 1px solid red;
    margin: 10px;
    padding: 5px;
    width: 80px;
    height: 60px;
    box-sizing: border-box;
  }
  ```

- **JavaScript:**

  ```js
  const parent = document.body.querySelector(".parent");

  const addChild = document.body.querySelector("#add-child");
  addChild.addEventListener("click", () => {
    // Only add a child if we don't already have one in addition to the text node "parent"
    if (parent.childNodes.length > 1) {
      return;
    }
    const child = document.createElement("div");
    child.classList.add("child");
    child.textContent = "child";
    parent.appendChild(child);
  });

  const removeChild = document.body.querySelector("#remove-child");
  removeChild.addEventListener("click", () => {
    const child = document.body.querySelector(".child");
    parent.removeChild(child);
  });
  ```

---

## Specifications

- **Standards:**  
  The DOM is standardized by bodies such as the [WHATWG](https://dom.spec.whatwg.org) (Living Standard) and the [W3C](https://www.w3.org/).

- **Further Reading:**  
  MDN provides extensive documentation on the various DOM interfaces and methods, ensuring consistent behavior across web browsers.

---

## Summary

- The DOM is a structured, object-oriented representation of web documents.
- It allows dynamic manipulation using JavaScript.
- The DOM tree consists of nodes such as elements, text, and attributes.
- JavaScript interacts with the DOM through a rich set of interfaces and methods (e.g., `querySelector`, `createElement`, `appendChild`).
- Examples on the page demonstrate practical DOM manipulation, including setting text content and dynamically adding or removing elements.

---

*For additional details and further reading, please refer to the [MDN Web Docs – Introduction to the DOM](https://developer.mozilla.org/en-US/docs/Web/API/Document_Object_Model/Introduction).*

