## HTML Fundamentals

HTML's a core technology behind the trillions of web pages that exist today

HTML's been around for a long time, and it's aged very well.

HTML first introduced for research with the ability to
  share documents with peers
  link to related research,
  display their data and tables,
  show some graphs or pictures.

Today, HTML is used to
  build online store fronts,
  full-blown applications,
  file / photo sharing,
  big social media applications.
  They have very interactive interfaces, and they're graphically rich.

While it started as a very text-based, link-based sort of tool, HTML has aged and is still the core foundational component that we use to build web pages.

We now have more tools to make those pages richer visually and interactively, we also have more responsibilities because not everyone's going to be viewing these on a big monitor at a desktop, maybe on a laptop, a tablet, or a phone.





## What is HTML?
HTML is a markup language.
Content to be displayed on a page is wrapped in this markup language "marked up"
The markup is not displayed but provides additional information and instructions to clients that render the content.
browsers are the clients that markup and they render the content in the HTML document.

## Terms
HTML, Hypertext Markup Language: Standard that defines the syntax and semantics of HTML documents


HTTP, Hypertext Transport Protocol: The protocol used to exchange HTML documents, typically requested by a client from a server over a network and rendered by browser software.

URI and a URL are interchangeable, these are simply addresses Universal Resource Identifier or Universal Resource Locator. There are pieces of that address that indicate the server where that document resides, the folders, and the name of the file.

Responsive Design: Design practice that focuses on rendering content properly on any device.





Displaying the Web with HTML

Where Did HTML Come From?

Example of a web page.
A web page is a web application
a simple web application with pages display text and images, and every page can be accessed by a unique URL
This URL is unique throughout the internet; that is how web browsers are able to navigate to a page.
All of this is HTML, which itself can contain URLs or links to other web pages, like this GitHub page.

right-click a webpage to View page source to actually see the HTML
It consists of elements with attributes

HTML is the standard markup language for creating web pages and applications, so it is the standard language for the web

HTML is a markup language and not a programming language or a scripting language.

This means that you use it to control the presentation of data just like we've seen in the website where the data is the text and the images.






What Is HTML?

HTML is the standard markup language for creating websites and web applications.
The things that you see in websites and web applications are rendered by the web browser from HTML documents.
These are documents with the HTM or HTML extension
HTML documents contain various elements that are specified in the HTML specification and can be understood by all web browsers.
The first element in any HTML document is the DOCTYPE element.
\<!DOCTYPE html\>

This is strictly not an element that is part of the HTML standard, but it does tell the browser that this is an HTML document and tells it which version of HTML it is written in.

HTML element         \<html\> \</html\>
Every element has an open and a close tag.
This tells the browser that everything in here is HTML.

head element \<head\>\</head\>
This can include a title for the document, scripts, styles, metainformation, and more.

body element \<body\>\</body\>
contains everything that you want to be displayed on the screen.

\<!--comment--\>

A DOCTYPE, html, head, and body elements are all the elements that are necessary in an HTML document.
All web browsers understand these elements and use them to display content on the screen.


[img/ShortExample.png]
[img/ExampleRender.png]

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
They explain what they are used for so that the browser can understand them better and search engines know better which parts of the document are actual data and which parts are metainformation.
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
To look at the HTML of a page open the web browser tools by pressing F12 in most web browsers.
The takeaway is that HTML is a markup language with many elements, tags, and attributes that web browsers understand, and that not all web browsers support all elements.

Working with HTML

Web browsers understand HTML elements, tags, and attributes, and display them on screen.
To write a website using HTML, you don't need to worry about HTTP, nor the client computers.
You just write HTML documents and deploy those on the web server.
You can write HTML documents yourself from scratch by writing all of the HTML elements, tags, and attributes that we saw.

Tools
write HTML documents from scratch using a simple text editor, like Notepad or Notepad++.

IDE
You can also use an integrated development environment, or IDE.
These are tools that provide a lot of extra features, like suggesting HTML tags to use and error checking.
Microsoft Visual Studio, the open-source Eclipse IDE, and GitHub's Atom IDE.

Online Editors
There are also online HTML editors that you don't have to install on your computer.
An example is htmlivecode.com, a free, browser-based HTML editor.
On the left you type HTML, and on the right it gets rendered.
A browser-based tool like this is very useful for prototyping.

Framework
When you don't want to write the HTML from scratch, you can use a framework to generate the HTML. You write software code in a programming language like C# or Java, and often you write bits of HTML as well. You do this using a framework, like PHP or ASP. NET.
Using a framework does not only generate HTML for you, but also allows you to do more advanced things like communicate with a database.
All of the code that you write and all of the code of the framework lives on the web server.
Now the client PC, which has a web browser, can request a document from a URL.
The framework will then generate HTML for the requested document and send that to the browser to be displayed on the screen. So instead of having plain HTML documents, a framework provides a layer around it, which generates HTML and provides additional features, like being able to connect to a database.
