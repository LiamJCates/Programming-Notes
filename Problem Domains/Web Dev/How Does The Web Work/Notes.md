




## Overview of modern web technologies


### HTML, CSS, and JavaScript

HTML, CSS, and JavaScript are the main three technologies you'll use to build a website.

    HTML is for structure and semantics (meaning).
    CSS is for styling and layout.
    JavaScript and APIs are for controlling dynamic behavior.

#### HTML

HyperText Markup Language, or HTML, is a markup language consisting of different elements you can wrap (mark up) content in to give it meaning (semantics) and structure. 

#### CSS

Cascading Style Sheets (CSS) is a rule-based language used to apply styles to your HTML — for example, setting text and background colors, adding borders, animating things, or laying out a page in a certain way. 

#### JavaScript

JavaScript is the programming language we use to add interactivity to websites, from dynamic style switching, to fetching updates from the server, right through to complex 3D graphics. There are many frameworks and libraries built on top of JavaScript that allow you to build certain types of website much more quickly and effectively.


### Other web technologies

There are other technologies used on the web, for example:

    HTTP for communicating between clients and servers, as mentioned earlier.
    SVG for creating and manipulating vector graphics.
    MathML for describing mathematical formulae.


### Server-side languages and frameworks

HTML, CSS, and JavaScript are front-end (or client-side) languages, which means they are run by the browser to produce a website front-end that your users can use.

There is another class of languages called back-end (or server-side) languages, meaning that they are run on the server before the result is then sent to the browser to be displayed. A typical use for a server-side language is to get some data out of a database, generate some HTML to contain the data, then send the HTML over to the browser to display it to the user.

Example server-side frameworks and languages include ASP.NET (C#), Django (Python), Laravel (PHP), and Next.js (JavaScript).

These technologies are not considered to be "web standards" — they are developed by organizations outside the web standards processes of organizations such as the W3C and WHATWG — although some of them will have processes that are similarly open.


### Static versus dynamic

Another way that client-side and server-side languages are often described is static and dynamic:

    A plain HTML file is stored on the server. When requested, it is delivered to the client, unchanged, and rendered by the browser. Because it does not change, it is referred to as "static".
    When server-side code (for example, a Python script or an ASP.NET page) generates some HTML containing data and returns that HTML to the client, the contents of the HTML change depending on what the server-side code does. It is therefore referred to as "dynamic".

There is often a bit of overlap between the concepts of static and dynamic code. Server-side languages usually define HTML structures inside a template file, which tend to be mostly static HTML with some special dynamic sections included that change depending on what data needs to be inserted.



### Presenting Documents

A document is usually a text file structured using a markup language, most commonly HTML (these are termed HTML documents). You may also come across documents written in other markup languages such as SVG or XML. Where previously we've talked about web pages, an HTML document contains the web page's content and specifies its structure.

Presenting a document to a user means converting it into a form usable by your audience. Browsers like Firefox, Chrome, Safari, and Edge are designed to present documents visually, for example, on a computer screen, projector, mobile device, or printer. In a web context, this is generally referred to as rendering; we provided a simplified description of the process by which a web page is rendered in How browsers load websites.









### The difference between web page, website, web server, and search engine

Common web-related concepts: web pages, websites, web servers, and search engines.

Web page: A document that can be displayed in a web browser.
Website: A collection of web pages grouped together into a single resource, with links connecting them together. Often called a "site".
Web server: A computer that hosts a website on the Internet.
Web service

    A software that responds to requests over the Internet to perform a function or provide data. A web service is typically backed by a web server, and may provide web pages for users to interact with. Many websites are also web services, though some websites comprise of static content only. Examples of web services would be something that resizes images, provides a weather report, or handles user login.

Search engine: A web service that helps you find other web pages, accessed through a web browser address bar or designated web page.

Let's look at an analogy — a public library. This is what you would generally do when visiting a library:

    Find a search index and look for the title of the book you want.
    Make a note of the catalog number of the book.
    Go to the particular section containing the book, find the right catalog number, and get the book.

Let's compare a public library with the web:

    The library is like a web server. It has several sections, which is similar to a web server hosting multiple websites.
    The different sections (science, math, history, etc.) in the library are like websites. Each section is like a unique website (two sections do not contain the same books).
    The books in each section are like web pages. One website may have several web pages, for example, the Science section (the website) will have books on heat, sound, thermodynamics, statics, etc.
    The search index is like the search engine. Each book has its own unique location in the library (two books cannot be kept at the same place) which is specified by the catalog number.

Let's now take the time to look at each term in a little bit more detail.

Web page

A web page, often called just "page", is a simple document displayable by a browser. 
Such documents are written in the HTML language. 

A web page can embed a variety of different types of resources such as:

    Style information — controlling a page's look-and-feel.
    Scripts — which add interactivity to the page.
    Media — images, sounds, and videos.

All web pages can each be found at a unique location (web address, also called a URL). To access a page, just type its address in your browser address bar.


Website

A website is a collection of linked web pages (plus their associated resources) that share a unique domain name. Each web page of a given website provides explicit links, typically in the form of clickable portions of text, that allow the user to move from one page of the website to another.

When you load a website in a browser, it tends to first display the website's main web page, or homepage (casually referred to as "home").

It is also possible to have a single-page app: a website that consists of a single web page that is dynamically updated with new content when needed.


Web server

A web server is a computer hosting one or more websites. "Hosting" means that all the web pages and their associated files are available on that computer. The web server will send web page files it is hosting to a user's browser when they attempt to load it.

Don't confuse websites and web servers. For example, if you hear someone say, "My website is not responding", it actually means that the web server is not responding and therefore the website is not available. More importantly, since a web server can host multiple websites, the term web server is never used to designate a website, as it could cause great confusion. In our previous example, if we said, "My web server is not responding", it means that multiple websites on that web server are not available.


Search engine

Search engines are a common source of confusion on the web. A search engine is a special kind of website that helps users find web pages from other websites.

There are plenty out there: Google, Bing, Yandex, DuckDuckGo, and many more. Some are generic, some are specialized around certain topics.

Many beginners on the web confuse search engines and browsers. Let's make it clear: A browser is a piece of software that retrieves and displays web pages; a search engine is a website that helps people find web pages from other websites. The confusion arises because, the first time someone launches a browser, the browser often displays a search engine's homepage or a search box allowing them to search for a term using that search engine. Most browsers also allow their users to use a search engine by typing search terms directly into the browser address bar.

This all makes sense because the first thing people tend to want to do with a browser is find a web page to display. Don't confuse the software (the browser) with the service (the search engine).




How the web works: the basics

When you access the web, quite a lot happens between your first interaction (for example, typing a web address (URL) into a browser and pressing Enter/Return) and the result of your action being presented to you (for example, the website appearing in your web browser):

-  The web browser requests the resource (for example, a web page, some data, or an image or video) you want to access from the web server it is stored on. Such requests (and the resulting responses) are made using a technology called HTTP (Hypertext Transfer Protocol), which uses a language of verbs (such as GET) to describe what should happen.
-  If the request is successful, the web server sends an HTTP response back to the web browser containing the requested resource.
-  In some cases, the requested resource will then fire off more HTTP requests, which will result in more responses. For example:
    -  When a website is loaded, initially the main index HTML file of the site's home page is requested.
    -  When that file is received by the browser, it will start to parse it, and will probably find instructions to make more requests.
    -  As discussed above, these might be for files to embed such as images, style information, scripts, and so on.
-  When all of the resources have been requested, the web browser parses and renders them as required, before displaying the result to the user.






When you load a web page in your browser, you are running your code (the HTML, CSS, and JavaScript) inside an execution environment (the browser tab)