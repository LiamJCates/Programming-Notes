CSS
We style the web with CSS, or Cascading Style Sheets.
Displaying text and images on the web is nice, but we need to be able to style the content so that it is readable and useable.

Where Did CSS Come From?

Let's take a brief look at CSS.
Here is the website internationalcookies.eu
You see HTML in the browser tools, which you can access when you press F12 in your browser.
There we can also see the CSS, which is code that tells the browser how to style the HTML.

Let's select the image of the cookie.
This selects the HTML of that image, and it also displays the CSS for the image, which tells the browser to vertically align an image in the middle.

Alright, so that is CSS. I like to define it as such; CSS, or Cascading Style Sheets, is a style sheet language that is used to describe the presentation of a document in a markup language.
There are also other style sheet languages to style different things like XML.
CSS is one of those and is the most important one for the web.



What Is CSS?

Methods of applying css styling

### Inline CSS
```html
<div style="color:blue">
	<ul>
		<li>This</li>
		<li style="font-style:italic">is an</li>
		<li>unordered list</li>
	<ul>
</div>
```
Suppose we want blue text and one of the list items in italic. I could do that with HTML that looks like this. Here, I've added a style to the div that contains the list and the text and told it to use the color blue. And here on the list item, I've added a style that tells it to display its text as italic. This works, and this is CSS, which I've added inline in HTML elements.

### \<style\> \</style\>
```html
<div>
	<ul>
		<li>This</li>
		<li class="italic">is an</li>
		<li>unordered list</li>
	<ul>
</div>

<style>
	div{
		color: blue
	}
	.italic{
		font-style: italic;
	}
</style>
```
We declare the styles here in the head element. This tells the rest of the HTML document that every div should display blue text, and it declares a CSS class that I can use on items that I want to be italic. This is more reusable than inline styles, as I can reuse these styles anywhere in the HTML document.

### external style sheets

in html head:
```html
<link rel="stylesheet" type="text/css" href="Stylesheet.css">
```
external css stylesheet
```css
div{
	color: blue
}
.italic{
	font-style: italic;
}
```
We use a link to a StyleSheet.css file
When the browser loads this HTML, it also loads the CSS file.
External style sheets provide maximum maintainability and reusability.
The styles are not in the HTML document, which makes everything easier to read and to maintain.
With a separate document, I can link that document in multiple HTML documents and apply the same styles there. Maximum reusability, which results in the styles being applied to both web pages when they are rendered by the browser.



### CSS Syntax Selectors
CSS consists of properties and attributes
CSS can indicate to what elements the property should be applied.
You do this with so‑called selectors:


```css
div{
	color: blue
}
```
This selects all of the div elements in an HTML page.

```css
.class1{
	color: blue
}
```
Or this one that selects all of the elements that have a class attribute set to class1.

```css
#para1{
	color: blue
}
```
This selects all elements in an HTML page that have an ID of para1.

```css
div p{
	text-align: center;
	color: red;
}
```
You can also nest things like this. This selector selects all paragraph elements that have a div element as their parent.


```css
h1, h2, p{
	color: blue
}
```
selects multiple elements on an HTML page.
It selects all heading1, heading2, and paragraph elements.



These are some of the CSS selectors. There are many more selectors that you can use in CSS to select elements in HTML and apply properties to them.



CSS Priority

CSS is called cascading, as in Cascading Style Sheets, because properties are applied in a specific order, based on priority.

Example:

Consider this HTML, two paragraph elements with text in them.
They both have the class specific assigned to them, and one of them has an id of more specific.

Now we apply this CSS to the HTML
The CSS paragraph selector says that the background color should be blue

But the class attribute on the paragraph element has a higher priority so the gray background‑color is applied

but not on both paragraphs as the id attribute has an even higher priority and overrides the background‑color to red.

Now, what about the lack of border?
This is overwritten by the property with the !important value , which has the highest priority of all. As the specific class applies to both paragraphs, none of them have borders around it.

What about the white text color and space in between the paragraphs, padding?
Well, that comes from the paragraph selector, as none of the higher priority selectors have overwritten these properties.

You can create large and complex hierarchies within CSS, which can be very useful, and can also make your CSS difficult to read and maintain.


Advanced CSS Syntax
There are also more advanced capabilities, which can be found in the newer properties of CSS.

The media query property.
In this example, whenever we are displaying HTML on the screen, as opposed to when we print a page for instance, and when the screen has a minimum width of 480 pixels, body element background‑color is lightgreen:

Whenever the width of the page is less than 480 pixels, the background‑color is the default one, which is white in this case. And whenever I expand the width to a minimum of 480 pixels, it turns light green.

This is what we call a responsive web page, and it responds to change and adjusts accordingly. This enables you to have a different look and feel for bigger screens than for smaller screens, like on mobile devices.

Another advanced property is the gradient property. In this example, I tell the browser to render everything with the ID grad with a gradient color that linearly goes from red to yellow. Cool, right?


There are a lot more advanced properties that can do things like this, including things like animations. Just like with HTML, the web browsers are the ones that provide the actual capabilities of CSS. CSS just specifies the standard of what they should do when they interpret a certain property.

And just like with HTML, not every browser provides the same support for every CSS property. Nowadays, most browsers support most of the CSS standard, but not everything as well.

On the website caniuse.com, you can find out if a certain property, like in this case the gradient that we just saw, is supported. And in this case, we can see that it is mostly supported, but not by any version of Opera Mini.

Working with CSS

The web consists out of HTML documents that can optionally be styled with CSS documents.
HTML documents and CSS documents live on a web server somewhere and are identified by unique URLs.
HTML and CSS can live on the same web server or on different web servers, it doesn't matter, as you can link to any document from an HTML document.
These documents are then transported through the HTTP protocol, which sends them to web browsers that requested them on client computers.

To work with CSS, all we need to know about is
how to couple CSS to HTML
that we need to host CSS documents on web servers.
it is the web browser that does all the work when it styles HTML.
Web browsers receive and interpret HTML files, and applies the styles described in the CSS document.

To create CSS.
write it from scratch using tools like text editors, Notepad or Notepad++.

Another way of writing CSS from scratch is by using an integrated development environment, or IDE, like Visual Studio, Eclipse, or Atom. These provide advanced features that help you write CSS more easily.

IDEs recognize CSS and knows the CSS standard and colorize the code segmetns
shows possible properties and possible values for those properties.
reduces errors and speeds up development.

CSS Libraries.
These are CSS files that are written by other people that already contain a lot of styles that you can use in your HTML document.
There are lots of CSS libraries around, and most of them are open source and free.
Some contain only CSS styles, others contain a lot more stuff like JavaScript files, images, and more.

A very popular CSS library is Bootstrap, which is created by Twitter.
Another one is hamburgers. css. And there is Font Awesome, Ionic, and Materialize.
Each of these provides different styles and different capabilities, and all of these are designed to make life easier for you as you don't have to create the styles, you just use them.

To get Bootstrap linked to your HTML, you could point to a URL like this.
This URL points to a Bootstrap CSS file, which is hosted on a CDN server, so somebody else's server. When you use a URL like this, you don't have to worry about hosting the CSS file on your own web server, but you do need to be aware that this server that you don't control can sometimes be unavailable.
Using something like Bootstrap can save you a lot of time, but you do have to learn how to use it. You need to learn what the different styles are, what they are called, and what they do.
CSS Preprocessors
A CSS preprocessor is a framework or language that is used to create CSS styles with.
CSS preprocessors can do more advanced things than CSS.
They were created because some people aren't happy with the simplistic expressions that you can do in CSS and how this can lead to large and difficult to maintain CSS documents.

There are lots of CSS preprocessors out there, like Sass and LESS.
When you use a CSS preprocessor, you write your style code in the language of the preprocessor, like this. The language of the preprocessor is more advanced than CSS and in the case of LESS has features like variables. This can be very useful. In this example, I use a variable named color that defines the color instead of having to type the actual color value in the properties of the style. When you are done writing your styling codes in your preprocessor, you compile it to generate CSS files. This compilation can be done with a tool that comes with the preprocessor. Once compiled, you end up with regular CSS, like this, where the color value is written out for each property. This CSS can be used just like any other regular CSS on a web server to be served up and style HTML. CSS preprocessors, like LESS, can be very useful and can increase your productivity, but you do need to learn how to use them, just like with CSS libraries.

Things to Remember

CSS, or Cascading Style Sheets, is the styling mechanism for the web.
It is a standard that describes selectors to select HTML elements and properties and value attributes to assign styles to HTML elements.
This standard continues to be developed as new features are added to the standard all the time.
The CSS standard itself doesn't do anything, it just tells the people who created the web browsers, like Chrome, Edge, and Firefox, how to interpret the CSS language and how to style HTML with it.
Each browser interprets CSS. Hopefully, they all interpret it exactly to the standards, but this is not always the case.
CSS is useful to separate style from content, where style is described in the CSS documents, and content in HTML documents.
CSS is a very rich standard that describes lots of capabilities.
CSS3 brought many advanced capabilities like media queries, animations, and gradients. And it looks like CSS is evolving to include more and more capabilities that make it easier to style content for mobile devices and to create animations.

We've seen that there are different ways to use CSS.
One of them is to write it from scratch, just as you can write HTML from scratch using text editors or integrated development environments.
A CSS library, like Bootstrap, which provides premade styles.
A CSS preprocess, like Sass or LESS. provide a richer language to write CSS in and compile into regular CSS files when you are done.
