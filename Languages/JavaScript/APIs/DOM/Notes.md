The Document Object Model (DOM) is a programming interface for web documents.

The Document Object Model (DOM) connects web pages to scripts or programming languages by representing the structure of a document with a logical tree so that programs can change the document structure, style, and content. 

Each branch of the tree ends in a node, and each node contains objects. DOM methods allow programmatic access to the tree.


Nodes can also have event handlers attached to them. Once an event is triggered, the event handlers get executed.








    element.querySelector(selector) - returns a reference to the first match of selector.
    element.querySelectorAll(selectors) - returns a “NodeList” containing references to all of the matches of the selectors.






When you have a reference to an element, you can use that reference to alter the element’s own properties. This allows you to do many useful alterations, like adding, removing, or altering attributes, changing classes, adding inline style information, and more.

// creates a new div referenced in the variable 'div'
const div = document.createElement("div");

// adds the indicated style rule to the element in the div variable
div.style.color = "blue";

// adds several style rules
div.style.cssText = "color: blue; background: white;";

// adds several style rules
div.setAttribute("style", "color: blue; background: white;");






When accessing a kebab-cased CSS property like background-color with JS, you will need to either use camelCase with dot notation or bracket notation. When using bracket notation, you can use either camelCase or kebab-case, but the property name must be a string.

// dot notation with kebab case: doesn't work as it attempts to subtract color from div.style.background
// equivalent to: div.style.background - color
div.style.background-color;

// dot notation with camelCase: works, accesses the div's background-color style
div.style.backgroundColor;

// bracket notation with kebab-case: also works
div.style["background-color"];

// bracket notation with camelCase: also works
div.style["backgroundColor"];






// adds class "new" to your new div
div.classList.add("new");

// removes "new" class from div
div.classList.remove("new");

// if div doesn't have class "active" then add it, or if it does, then remove it
div.classList.toggle("active");

It is often standard (and cleaner) to toggle a CSS style rather than adding and removing inline CSS.





Adding text content

// creates a text node containing "Hello World!" and inserts it in div
div.textContent = "Hello World!";

Adding HTML content

// renders the HTML inside div
div.innerHTML = "<span>Hello World!</span>";

Note that using textContent is preferred over innerHTML for adding text, as innerHTML should be used sparingly to avoid potential security risks. To understand the dangers of using innerHTML, watch this video about preventing the most common cross-site scripting attack.
https://www.youtube.com/watch?v=ns1LX6mEvyM






Example of adding a div via javascript
```html
<!-- your HTML file: -->
<body>
  <h1>THE TITLE OF YOUR WEBPAGE</h1>
  <div id="container"></div>
</body>
```
```js
const container = document.querySelector("#container");

const content = document.createElement("div");
content.classList.add("content");
content.textContent = "This is the glorious text-content!";

container.appendChild(content);
```






Creating and placing new nodes

The above has given you a little taste of what you can do, but let's go further and look at how we can create new elements.

    Going back to the current example, let's start by grabbing a reference to our <section> element — add the following code at the bottom of your existing script (do the same with the other lines too):
    js

const sect = document.querySelector("section");

Now let's create a new paragraph using Document.createElement() and give it some text content in the same way as before:
js

const para = document.createElement("p");
para.textContent = "We hope you enjoyed the ride.";

You can now append the new paragraph at the end of the section using Node.appendChild():
js

sect.appendChild(para);

Finally for this part, let's add a text node to the paragraph the link sits inside, to round off the sentence nicely. First we will create the text node using Document.createTextNode():
js

const text = document.createTextNode(
  " — the premier source for web development knowledge.",
);

Now we'll grab a reference to the paragraph the link is inside, and append the text node to it:
js

    const linkPara = document.querySelector("p");
    linkPara.appendChild(text);

That's most of what you need for adding nodes to the DOM — you'll make a lot of use of these methods when building dynamic interfaces (we'll look at some examples later).





Note on script location

Your JavaScript, for the most part, is run whenever the JS file is run or when the script tag is encountered in the HTML. If you are including your JavaScript at the top of your file, many of these DOM manipulation methods will not work because the JS code is being run before the nodes are created in the DOM. The simplest way to fix this is to include your JavaScript at the bottom of your HTML file so that it gets run after the DOM nodes are parsed and created.

Alternatively, you can link the JavaScript file in the \<head> of your HTML document. Use the \<script> tag with the src attribute containing the path to the JS file, and include the defer keyword to load the file after the HTML is parsed, as such:
```html
<head>
  <script src="js-file.js" defer></script>
</head>
```




