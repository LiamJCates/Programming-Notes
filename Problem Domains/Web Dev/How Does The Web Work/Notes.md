
### Web Standards

Web standards are the technologies we use to build websites. These standards exist as long technical documents called specifications, which detail exactly how the technology should work. These documents are not very useful for learning how to use the technologies they describe. Instead, they are intended to be used by software engineers to implement these technologies (usually in web browsers).

Web standards are created by standards bodies — institutions that invite groups of people from different technology companies to come together and agree on how the technologies should work in the best way to fulfill all of their use cases.

The W3C is the best known web standards body, but there are others. For example:

    WHATWG maintains the HTML Living Standard, which describes exactly how HTML (all the HTML elements, and their associated APIs, and other surrounding technologies) should be implemented.
    TC39 and ECMA specify and publish the standard for ECMAScript, which modern JavaScript is based on.
    Khronos publish technologies for 3D graphics, such as WebGL.


The key principles of the web, which make the web a unique and exciting industry to get involved in, are as follows:

    Open to contribute and use, and therefore not patent-encumbered or controlled by a single private entity.
    Accessible and interoperable.
    They don't break the web.


"Open" standards

One of the key aspects of web standards, which TimBL and the W3C agreed on from the start, is that the web (and web technologies) should be open. This means they are free to both contribute to and use, and not encumbered by patents/licensing. Open standards enable the web to remain a freely-available public resource, where anyone can write the code to build a website for free, and anyone can contribute to the standards creation process.

Accessible and interoperable

The web and web browsers are fundamentally designed so that web content is accessible to people with disabilities. It was originally envisaged as a great leveller, enabling people to access information regardless of circumstance. This means that, for example:

    People who are unable to use a mouse or pointing device can use the keyboard to navigate the web.
    People who are visually impaired can magnify content, or use a program called a screen reader to read content out to them and describe controls in a way that makes sense.

In addition, web technologies are intended to be interoperable. Because web technologies are implemented according to published standards, browsers should provide the same rendered output for a given input (for example, HTML, CSS, or JS code) — in other words, a website should work consistently across multiple browsers.


Don't break the web

Another phrase you'll hear around open web standards is "don't break the web". The idea behind this is that any new web technology should be backwards compatible with what went before it, so existing websites will continue to work in the same way as they did before.

Web browser vendors should be able to implement new web technologies without causing a difference in rendering or functionality that would cause their users to think a website is broken and try another browser as a result.



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




### Web best practices

We have briefly talked about the technologies that you'll use to build websites. Now let's discuss the best practices that web developers generally employ to ensure that their websites are usable by as many people as possible.

When doing web development, the main cause of uncertainty comes from the fact that you don't know what combination of technology each user will use to view your website:

    User 1 might be looking at it on an iPhone, with a small, narrow screen.
    User 2 might be looking at it on a Windows laptop with a widescreen monitor attached to it.
    User 3 might be visually impaired, and using a screen reader to read and interact with the web page.
    User 4 might be using a really old desktop machine that can't run modern browsers.

Because you don't know exactly what your users will use, you need to design defensively — make your website as flexible as possible, so that all of the above users can make use of it, even if they might not all get the same experience.

You'll come across the below concepts at some point in your studies, which represent best practices your websites should ideally adhere to. Don't worry about these too much for now. Throughout most of the course we try to teach these implicitly, meaning that when we teach you HTML, CSS, and JavaScript, our examples will follow the best practices where possible. Later on in your learning journey you will likely explore explicit teachings in these areas.

#### Progressive enhancement

    Creating a minimal experience that provides the essential functionality to all users, and layering on a better experience and other enhancements in browsers that can support them. Progressive enhancement is often seen as unimportant, because browsers tend to support new features more consistently these days, and people tend to have faster internet connections with higher limits on data usage. However, consider examples like cutting down on decoration to make a mobile experience smoother and save on data or providing a lighter, low-bandwidth experience for users who pay by the megabyte or have metered connections.

#### Cross-browser compatibility

    Trying to make sure your webpage works across as many devices as possible. This includes using technologies that all the browsers support, delivering better experiences to browsers that can handle them (progressive enhancement), and/or writing code so that it falls back to a simpler but still usable experience in older browsers (termed graceful degradation). It also requires testing to see if anything fails in certain browsers, and then more work to fix those failures.

#### Separating the layers

    Putting your content (HTML), styling (CSS), and behavior (JavaScript) in different code files, rather than lumping them all together in the same place. This is a good idea for many reasons, including code management and comprehension and teamwork/separation of roles. In reality, the separation is not always clear. It is an ideal to aim for where possible, rather than an absolute.

#### Responsive web design

    Making your functionality and layouts flexible so they can automatically adapt to different browsers. An obvious example is a website that is laid out one way in a widescreen browser on the desktop, but displays as a more compact, single-column layout on mobile phone browsers. Try adjusting the width of your browser window now, and see what happens to the site layout.

#### Performance

    Getting websites to load as quickly as possible, but also making them intuitive and easy to use so that users don't get frustrated and go somewhere else.

#### Internationalization

    Making websites usable by people from different cultures, who speak different languages to your own. There are technical considerations here (such as altering your layout so that it still works OK for right-to-left or top-to-bottom languages), and human ones (such as using simple, non-slang language so that diverse cultures are more likely to understand your text).

#### Privacy & Security

    These two concepts are related but different. Privacy refers to allowing people to go about their business privately and not spying on them or collecting more of their data than you absolutely need to. Security refers to constructing your website in a secure way so that malicious users cannot steal information contained on it from you or your users.





### The difference between web page, website, web server, and search engine

Common web-related concepts: web pages, websites, web servers, and search engines.

Web page

    A document that can be displayed in a web browser.
Website

    A collection of web pages grouped together into a single resource, with links connecting them together. Often called a "site".

Web server

    A computer that hosts a website on the Internet.

Web service

    A software that responds to requests over the Internet to perform a function or provide data. A web service is typically backed by a web server, and may provide web pages for users to interact with. Many websites are also web services, though some websites comprise of static content only. Examples of web services would be something that resizes images, provides a weather report, or handles user login.

Search engine

    A web service that helps you find other web pages, such as Google, Bing, Yahoo, or DuckDuckGo. Search engines are normally accessed through a web browser (for example, you can perform search engine searches directly in the address bar of Firefox, Chrome, etc.) or through a web page (for example, bing.com or duckduckgo.com).

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

A web page, often called just "page", is a simple document displayable by a browser. Such documents are written in the HTML language. A web page can embed a variety of different types of resources such as:

    Style information — controlling a page's look-and-feel.
    Scripts — which add interactivity to the page.
    Media — images, sounds, and videos.

All web pages can each be found at a unique location (web address, also called a URL). To access a page, just type its address in your browser address bar.


Website

A website is a collection of linked web pages (plus their associated resources) that share a unique domain name. Each web page of a given website provides explicit links—most of the time in the form of clickable portions of text—that allow the user to move from one page of the website to another.

When you load your favorite website in a browser, it tends to first display the website's main web page, or homepage (casually referred to as "home").

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


