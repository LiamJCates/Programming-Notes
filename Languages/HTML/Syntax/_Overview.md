## HTML Tags

HTML documents are composed of HTML elements. 
HTML elements inform a web browser how to display content.
The HTML specification defines elements understood by all web browsers.


### Tag Syntax

HTML element type is specified by the HTML tags used. 
HTML tags are defined by a tag name, within angle braces 

An HTML element, generally, encompasses an opening tag, a closing tag, and the content the tag wraps.

\<p>This is the content\</p>


An HTML tag is the opening or closing entity of a given HTML element.

\<p> is the opening tag 
\</p> is the closing tag

the only difference being them being the forward slash "/" in the closing tag 


The content part can either be some text or they can also contain other tags. 


### Nested HTML Elements

HTML elements can be nested.
Nested elements are contained withing the content part of another element.

Each HTML document can actually be referred to as a document tree. We describe the elements in the tree like we would describe a family tree. There are ancestors, descendants, parents, children and siblings.

When an element is nested, we call that element the child element, and the element that wraps it, the parent element. The parents appear higher in the document tree, and the children lower.

A descendant refers to any element that is connected but lower down the document tree - no matter how many levels lower.
An ancestor refers to any element that is connected but further up the document tree - no matter how many levels higher.
A parent is an element that is directly above and connected to an element in the document tree.
A child is an element that is directly below and connected to an element in the document tree.
A sibling is an element that shares the same parent with another element. 


All HTML documents consist of nested HTML elements.

The following example contains four HTML elements (\<html>, \<body>, \<h1> and \<p>):

```html
<!DOCTYPE html>
<html>
<body>

<h1>My First Heading</h1>
<p>My first paragraph.</p>

</body>
</html>
```


The html> element is called the root element, all other elements are defined within its content portion, thus all other elements are descendants of \<html>.
The \<html> element defines the bounds of the HTML document.
It has a start tag \<html> and an end tag \</html>.

Nested within the \<html> element is a \<body> element.
The \<body> element is the child of the of \\<html> element.
It has a start tag \<body> and an end tag \</body>.
Inside the \<body> element is nested two other elements \<h1> and \<p>.

It has a start tag \<h1> and an end tag \</h1>
It has a start tag \<p> and an end tag \</p>

\<h1> and \<p> are siblings
\<h1> and \<p> are children of \<body> and descendants of \<html> and \\<body>
\<html> is the ancestor of \<body>, \<h1>, and \<p> elements




### HTML is Not Case Sensitive

HTML tags are not case sensitive: \<P> means the same as \<p>.

The HTML standard does not require lowercase tags, but W3C recommends lowercase in HTML, and demands lowercase for stricter document types like XHTML.



### Never Skip the End Tag

Some HTML elements will display correctly, even if you forget the end tag:

```html
<html>
<body>

<p>This is a paragraph
<p>This is a paragraph

</body>
</html>
```

However, never rely on this! Unexpected results and errors may occur if you forget the end tag!



### Tag Types

There are two types of tags in HTML:

    Container tags
    Empty Tags



#### Container tags

Container tags are generally divided into three parts, i.e., opening tag, content(which will display on the browser), and closing tag. 

Opening and closing tags are used in pairs which are start tag and end tag, often called ON and OFF tags.

If you forget to close the container tag, the browser applies the effect of the opening tag until the end of the page. So be careful while working with container tags. 

The majority of tags present in HTML are container tags. 

Syntax:

<tag_name> ...</tag_name> 








### Empty Tags


However, not all tags have an open and a closing tag, some are defined by just a start tag.

The tags that do not contain content or closing tags are known as empty tags.


Syntax:

<tag_name>


Example

<p>This is a <br> paragraph with a line break.</p> 

It's "empty" in the sense that it doesn't have content within its opening and closing tags. For example, the <p> has text between its opening and closing tags (<p>Lorum ipsum dolor</p>). For an <img>, you don't have a closing tag (</img>), and its behavior is defined entirely by its attributes (width, height, src, etc).









### HTML Documents

All HTML documents must start with a document type declaration: <!DOCTYPE html>.

The HTML document itself begins with <html> and ends with </html>.

The visible part of the HTML document is between <body> and </body>. 

A DOCTYPE, html, head, and body elements are all the elements that are necessary in an HTML document.



### Basic HTML Document

```html
<!DOCTYPE html>
<html>
<head>
<title>Page Title</title>
</head>
<body>

<h1>This is a Heading</h1>
<p>This is a paragraph.</p>

</body>
</html> 
```


The <!DOCTYPE html> declaration defines that this document is an HTML5 document
The <html> element is the root element of an HTML page
The <head> element contains meta information about the HTML page
The <title> element specifies a title for the HTML page (which is shown in the browser's title bar or in the page's tab)
The <body> element defines the document's body, and is a container for all the visible contents, such as headings, paragraphs, images, hyperlinks, tables, lists, etc.
The <h1> element defines a large heading
The <p> element defines a paragraph











Within the head element is

a meta tag     \<meta charset="utf-8"\>
the charset attribute that tells the browser that the character encoding that is used in the document is UTF-8.

a title tag, \<title\>\</title\>
 which appears in the browser tab.





Within the body element is
a div tag\<div\>\</div\>
indicates that everything in this tag belongs together.

An unordered list \<ul\>\</ul\>
in it with three list items \<li\>\</li\> that contain text.
\<ul\>
\<li\>\</li\>
\</ul\>


There are much more elements and tags in HTML than just these standard ones. Especially with the introduction of HTML5.

HTML5 offers a large number of new HTML elements that allow for more expressive markup and more interactive web pages.

They explain what they are used for so that the browser can understand them better and search engines know better which parts of the document are actual data and which parts are metadata.


More Expressive Elements

Here are some of these elements.

A header element \<header\>\</header\>
represents a container for introductory content

A nav tag \<nav\>\</nav\>
defines a set of navigation links.

A main tag \<main\>\</main\>
specifies the main content of a document

An article tag \<article\>\</article\>
specifies independent, self-contained content

An aside tag \<aside\>\</aside\>
defines some content aside from the content it is placed in.

A footer tag \<footer\>\</footer\>
that contains things like copyright or an address

An address tag \</address\>
specifies an address

These types of tags are geared towards the content that you display on a web page and provide more nuance to the HTML markup language.

There are also elements that allow you to have more interaction with the browser

audio element    \<audio control\> \</audio\>
You can use this to display an audio control bar on your page and have the browser play audio.

Canvas element \<canvas\>\</canvas\>
provides a place in your page that you use to paint on in order to display custom shapes.

form element
the basis for most interactive websites and applications, used to post information from the browser to the server, for instance text that a user entered in a text field.

video tag
play videos in the browser.

There are a lot more of these types of elements, which are very powerful.

The takeaway is that HTML is a markup language with many elements, tags, and attributes that web browsers understand, and that not all web browsers support all elements.
