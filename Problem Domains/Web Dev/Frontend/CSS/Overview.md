### **Overview of Cascading Style Sheets (CSS)**

**Cascading Style Sheets (CSS)** is a **stylesheet language** that describes the presentation of a document in a markup language, and is used to control the presentation and layout of HTML and XML documents. 

CSS enables the separation of **content** (written in HTML or XML) from **presentation** (such as colors, fonts, spacing, layout, etc.), which makes it easier to manage and maintain web pages.

CSS is an essential technology for creating modern web designs. It allows web developers to define styles for elements, such as how text and images appear, how content is laid out, and how websites respond to different screen sizes and devices (responsive design).

When used correctly, CSS increases site adaptability, readability, and useability,

CSS can save a lot of work by controlling the layout of multiple web pages at once.

While there are limited ways to style content using HTML style attributes, this is not done in practice. 
(Other than some unique cases like HTML email)



### **CSS Syntax:**

The basic syntax of a CSS rule consists of:
1. **Selector**: The HTML element or elements to style.
2. **Declaration Block**: A pair of curly braces `{}` containing one or more declarations.
3. **Declaration**: A property-value pair, where the property is the aspect of the element to style, and the value is the setting.

```css
selector {
    property: value;
    property: value;
}
```

**Example:**

```css
/* Selector targets <h1> elements */
h1 {
    color: red;          /* Property: color, Value: red */
    font-size: 24px;     /* Property: font-size, Value: 24px */
    text-align: center;  /* Property: text-align, Value: center */
}
```


### **Key Concepts of CSS:**

1. **Selectors**: A selector targets HTML elements that you want to style. Common selectors include element selectors, class selectors, ID selectors, and pseudo-class selectors.

**Element Selector**: Targets all instances of a particular HTML element (e.g., `p` for paragraphs).
```css
p{
	color: blue
}
```
We can select multiple elements.
```css
h1, h2, p{
	color: blue
}
/* Selects all heading1, heading2, and paragraph elements */
```
You can also use multiple selectors to get the exact elements you want, by using parental nesting. By using the “greater-than” symbol (>), you can select only the direct children of an element, going down only one level.

```css
ul > li {
  display: inline-block
}
/* Selects only the first-level list items in all unordered lists in the HTML */
```

```css
ul a {
  text-underline: none;
}
/* Selects all anchors which have an unordered list their ancestry */
```

```css
ul + span {
  display: inline;
}
/* Selects only spans that directly follow an unordered list */
```

```css
a ~ h1 {
  color: blue;
}
/* Selects all h1 elements that are in the general vicinity of an anchor */
```


**Class Selector**: Targets all elements with a specific class attribute (e.g., `.class-name`).

```css
.class1{
	color: blue
}
/* Selects all of elements that have a class attribute set to class1 */
```

```css
a.link {
  font-size: 12px;
}
/* HTML Selected: <a href="http://google.com" class="link">, 
<a href="http://codecademy.com" class="link jumbo"> */
```


**ID Selector**: Targets a specific element with a unique ID (e.g., `#id-name`).

Like the term (“identification”) indicates, ID selectors will ONLY select the first element with a matching ID.

```css
#thatThingINeededToStyle {
  color: blue;
  font-size: 24px;
}
/* HTML Selected: <span id="thatThingINeededToStyle"> */
```

```css
a#anID {
  color: purple;
}
/* HTML Selected: <a href="http://codecademy.com" id="anID"> */
```


**Attribute Selector**: Targets elements with a specific attribute (e.g., `[type="text"]`).
Example

a[href="http://example.com"] {
  color: purple;
}

/* HTML Selected: <a href="http://example.com"> */

Example

input[type="text"] {
  width: 100px;
}

/* HTML Selected: <input type="text"> */

Example

input[required] {
  border: 1px red solid;
}

/* HTML Selected: <input type="text" required> */

Universal selector

The universal selector (*) may be used to select all the elements in a particular range. Be aware that the universal selector is the most performance taxing selector, and should be used sparingly.

Example

* {
  background-color: blue;
}

/* Selects ALL HTML elements in the page */

Example

body * {
  color: red;
}

/* Selects ALL children of the body */

Example

div > * {
  color: red;
}

/* Selects ALL first-level children of all divs on the page */



**Pseudo-classes**: Targets elements based on their state or position (e.g., `:hover`, `:first-child`).

Pseudo Selectors can be used to narrow down a selection with certain rules.

Example

li:first-child {
  color: red;
}

/* 
    This selects only <li> elements that have no elements before them
    <ul>
      <li>Selected; will be red</li>
      <li>Not selected</li>
      <li>Not selected</li>
    </ul>
*/

li:last-child {
  color: red;
}

/* This does the opposite; only the last <li> will be red. */

Example

a:hover {
  text-decoration: underline;
}

/* Will underline all links when the user puts their mouse over them */

a:active {
  font-weight: bold;
}

/* Will make all links bold while the user is clicking on them. */




2. **Properties**: Properties define what aspect of the selected element you want to style (e.g., `color`, `font-size`, `margin`, etc.).
   
   - Example: `color: blue;` changes the text color of the element to blue.

3. **Values**: Values are the settings applied to properties (e.g., `font-size: 16px;` or `background-color: #f0f0f0`).

4. **Cascade**: The "cascading" part of CSS refers to the order in which styles are applied. When multiple styles conflict, the one with the highest specificity or importance will be applied.

5. **Inheritance**: Some CSS properties are inherited from parent elements to child elements, such as font properties (`font-family`, `font-size`) or color properties.

6. **Box Model**: CSS uses a "box model" to define the layout of elements. Every element is considered a box with properties such as:
   - `content` (the actual content),
   - `padding` (space around the content),
   - `border` (edge around the padding),
   - `margin` (space outside the border).

7. **Responsive Design**: CSS allows you to create flexible, responsive layouts that adapt to different screen sizes, from large desktop monitors to small mobile screens, using techniques like media queries and flexible box layouts.



### **CSS Types:**

CSS can be added to HTML documents in 3 ways:

1. **Inline CSS**: 
CSS rules are written directly within HTML elements using the `style` attribute. This is generally not recommended for large projects but can be useful for quick tests or overriding specific styles.

```html
<div style="color:blue">
	<ul>
		<li>This</li>
		<li style="font-style:italic">is an</li>
		<li>unordered list</li>
	<ul>
</div>
```

2. **Internal CSS**: 
 CSS rules are placed within the `<style>` element inside the `<head>` section of an HTML document. It is suitable for styling a single page or when no external stylesheets are needed.

```html
  <head>
    <style>
      div{
        color: blue
      }
      .italic{
        font-style: italic;
      }
    </style>
  </head>
  <body>
    <div>
      <ul>
        <li>This</li>
        <li class="italic">is an</li>
        <li>unordered list</li>
      <ul>
    </div>
  </body>
```


3. **External CSS**: 
CSS rules are written in a separate `.css` file, and the file is linked to the HTML document using the `<link>` tag. This is the most common and recommended approach for large websites. With a separate document, we can link a given stylesheet in multiple HTML documents for maximum reusability, and a single location for future changes increases maintainability.


```html
<head>
  <link rel="stylesheet" type="text/css" href="Stylesheet.css">
</head>
```
Stylesheet.css in the same web server directory
```css
div{
	color: blue
}
.italic{
	font-style: italic;
}
```

The web consists out of HTML documents that can optionally be styled with CSS documents. HTML documents and CSS documents live on a web server somewhere and are identified by unique URLs. HTML and CSS can live on the same web server or on different web servers, it doesn't matter, as you can link to any document from an HTML document. These documents are then transported through the HTTP protocol, which sends them to web browsers that requested them on client computers. The web browser styles HTML. Web browsers receive and interpret HTML files, and as well as receive and apply the styles described in the CSS document.

To work with CSS, all we need to know about is how to couple CSS to HTML, and that we need to host CSS documents on web servers for external linking.


### **Common CSS Properties:**

- **Text Properties**: Control the appearance of text.
  - `font-family`, `font-size`, `font-weight`, `line-height`, `letter-spacing`, `text-align`, `text-transform`, `text-decoration`, `color`.
  
- **Box Model Properties**: Control spacing, dimensions, and borders.
  - `width`, `height`, `padding`, `margin`, `border`, `box-sizing`.

- **Layout Properties**: Define how elements are arranged.
  - `display`, `position`, `top`, `bottom`, `left`, `right`, `float`, `clear`, `z-index`.

- **Background Properties**: Control background styles.
  - `background-color`, `background-image`, `background-size`, `background-position`, `background-repeat`.

- **Flexbox and Grid Properties**: Control layout using modern layout techniques.
  - `display: flex;`, `flex-direction`, `justify-content`, `align-items`, `grid-template-columns`, `grid-gap`.

- **Animation and Transition Properties**: Control animations and transitions between styles.
  - `transition`, `transition-duration`, `animation`, `keyframes`, `transform`.

### **Example of Flexbox Layout:**

```css
.container {
    display: flex;            /* Using flexbox layout */
    justify-content: space-between;  /* Distribute items evenly */
    align-items: center;      /* Vertically align items */
}

.item {
    width: 100px;
    height: 100px;
    background-color: lightblue;
}
```

```html
<div class="container">
    <div class="item">Item 1</div>
    <div class="item">Item 2</div>
    <div class="item">Item 3</div>
</div>
```

In this example, the `.container` is a flex container that arranges its child `.item` elements in a row, spacing them evenly and centering them vertically.

### **Media Queries and Responsive Design:**

Media queries allow CSS to apply styles based on certain conditions, such as the width of the viewport, enabling responsive web design. With media queries, you can design layouts that work well on both desktops and mobile devices.

```css
/* Mobile-first design */
.container {
    display: grid;
    grid-template-columns: 1fr;  /* Single column layout for small screens */
}

/* For devices wider than 768px (tablets, desktops) */
@media (min-width: 768px) {
    .container {
        grid-template-columns: 1fr 1fr;  /* Two-column layout for larger screens */
    }
}
```

In this example:
- On smaller devices (like phones), the `.container` will display a single column.
- On wider devices (like tablets or desktops), the layout changes to two columns.

### **CSS Specificity and Cascade:**

When multiple CSS rules target the same element, **CSS specificity** determines which rule is applied:
1. Inline styles have the highest specificity.
2. IDs have higher specificity than classes.
3. Classes have higher specificity than element selectors.

The **cascade** is the order in which styles are applied. The order of rules in the stylesheet, as well as the specificity of the selectors, influences which styles take precedence.

---

### **Conclusion:**

Cascading Style Sheets (CSS) is a fundamental technology for creating modern web designs. It allows developers to control the look and feel of web pages while keeping the content (HTML) separate from its presentation. The separation of structure and style enhances maintainability and scalability, which is essential for building complex and responsive websites.

CSS provides powerful layout capabilities like Flexbox and Grid, making it easier to create fluid, responsive designs. Additionally, media queries allow developers to create designs that adapt to different screen sizes and devices.

CSS continues to evolve with new features like custom properties (CSS variables), animations, and improved layout modules, helping developers create engaging and user-friendly web experiences.






What you are seeing are the browser's default styles — very basic styling that the browser applies to HTML to make sure that the page will be basically readable even if no explicit styling is specified by the author of the page. These styles are defined in default CSS stylesheets contained within the browser — they have nothing to do with HTML.