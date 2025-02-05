## HTML Documents

The first thing you should see in an HTML document is the DOCTYPE:
\<!--DOCTYPE--\>
This is information the client uses to understand the structure of the document
the rest of the document is HTML marked-up text.  

If you're looking at an older web page, created several years ago, you may see something similar to this:

```html
<!DOCTYPE HTML PUBLIC
  "-//W3C//DTD HTML 4.01//EN"
  "HTTP:/www.w3.org/TR/html4/strict.dtd">
```

with a DTD or other type of schema or standard applied to it.

Again, this tells the browser or the client that the text that follows is going to be structured in such a way that it conforms to that standard.
There have been a lot of different standards as the versions changed and with different levels of strictness, so browsers had to be able to understand those different versions.

After the document type is the HTML element or tag.

	\<HTML\>\</HTML\>

This acts as a root container for all of the content inside the document.

Having a root element like this is fairly common in markup languages to provide a single point with which we can start to traverse all document elements.

Inside the HTML element, we're going to find two other core elements:

\<head\>\</head\>
Contains content that won't be rendered to the user, metadata about the document and processing of the document

\<body\>\</body\>.
Contains content to be rendered visually, information that will be displayed to the user.

Demo: A basic HTML Document

```html
<!DOCTYPE HTML>
<html>
  <head>
    <title> Hello World </title>
  </head>
  <body>
    Hello World.
  </body>
</html>
```

Begin with DOCTYPE HTML.
Remember our first element is HTML.
All elements have an opening tag; the element name surrounded by the brackets, and a closing tag; indicated by slash before the HTML.

Inside the root HTML element we place the head and body elements
Inside the head we add a title element
In the body we add some text for display

Now this looks like a valid HTML document.
We can test/validate it by saving and going and trying to open it in a browser.

Or we can validate it by copying to:
https://validator.w3.org/#validate_by_input

It gives us one little warning saying it would be nice if on the HTML element you told us what language this document was. We add the lang attribute to the html tag
\<html lang="en-us"\> for English US.


I mentioned there were other types of DOCTYPES,

Over at the W3C site, w3.org, they list all these different DOCTYPES.
DOCTYPE HTML is the common one and the recommended one.
