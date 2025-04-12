### DOM

The Document Object Model (DOM) is a cross-platform and language-independent interface that treats an HTML or XML document as a tree structure wherein each node is an object representing a part of the document. The DOM represents a document with a logical tree. Each branch of the tree ends in a node, and each node contains objects. 


In HTML DOM (Document Object Model), every element is a node:

    A document is a document node.
    All HTML elements are element nodes.
    All HTML attributes are attribute nodes.
    Text inserted into HTML elements are text nodes.
    Comments are comment nodes.

    

DOM methods allow programmatic access to the tree; with them one can change the structure, style or content of a document. Nodes can have event handlers (also known as event listeners) attached to them. Once an event is triggered, the event handlers get executed.




The principal standardization of the DOM was handled by the World Wide Web Consortium (W3C), which last developed a recommendation in 2004. WHATWG took over the development of the standard, publishing it as a living document. The W3C now publishes stable snapshots of the WHATWG standard.





Web browsers

To render a document such as a HTML page, most web browsers use an internal model similar to the DOM. The nodes of every document are organized in a tree structure, called the DOM tree, with the topmost node named as "Document object". When an HTML page is rendered in browsers, the browser downloads the HTML into local memory and automatically parses it to display the page on screen. However, the DOM does not necessarily need to be represented as a tree,[11] and some browsers have used other internal models.[12]
JavaScript

When a web page is loaded, the browser creates a Document Object Model of the page, which is an object oriented representation of an HTML document that acts as an interface between JavaScript and the document itself. This allows the creation of dynamic web pages,[13] because within a page JavaScript can:

    add, change, and remove any of the HTML elements and attributes
    change any of the CSS styles
    react to all the existing events
    create new events

DOM tree structure

A Document Object Model (DOM) tree is a hierarchical representation of an HTML or XML document. It consists of a root node, which is the document itself, and a series of child nodes that represent the elements, attributes, and text content of the document. Each node in the tree has a parent node, except for the root node, and can have multiple child nodes.
Elements as nodes

Elements in an HTML or XML document are represented as nodes in the DOM tree. Each element node has a tag name and attributes, and can contain other element nodes or text nodes as children. For example, an HTML document with the following structure:

<html>
  <head>
    <title>My Website</title>
  </head>
  <body>
    <h1>Welcome to DOM</h1>
    <p>This is my website.</p>
  </body>
</html>

will be represented in the DOM tree as:

- Document (root)
  - html
    - head
      - title
        - "My Website"
    - body
      - h1
        - "Welcome"
      - p
        - "This is my website."

Text nodes

Text content within an element is represented as a text node in the DOM tree. Text nodes do not have attributes or child nodes, and are always leaf nodes in the tree. For example, the text content "My Website" in the title element and "Welcome" in the h1 element in the above example are both represented as text nodes.


Attributes as properties

Attributes of an element are represented as properties of the element node in the DOM tree. For example, an element with the following HTML:

<a href="https://example.com">Link</a>

will be represented in the DOM tree as:

- a
  - href: "https://example.com"
  - "Link"

