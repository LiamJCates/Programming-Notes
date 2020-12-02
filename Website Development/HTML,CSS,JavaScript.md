The web works by displaying HTML, styling it with CSS, and adding interaction with JavaScript.

A Look into the History of the Web

1960    research into package switching techniques create networks that could survive nuclear war.

late 1960s
private networks that implemented package switching emerged.
NPL Network and ARPANET connected the University of California with the Stanford Research Institute.

1972
first link between the United States and Europe was created by satellite when ARPANET was connected to the Norwegian Seismic Array.

1981
access to ARPANET was expanded. The NSF, or National Science Foundation, created the Computer Science Network, which connected to ARPANET using TCP/IP.
the Internet Protocol 4 standard was published, an implementation of TCP/IP that still runs most of the internet's traffic today.

late 80s public availability of the internet, public internet service providers emerged
1989     World Wide Web came about and the term World Wide Web was proposed.
1990    Web browser invented

1994
Cascading HTML Style Sheets, or CSS, was introduced
many web browsers available to the public.

1995
JavaScript introduced to enhance the document experience by allowing programmable actions on the web.
people started using mobile phones

1999
mobile phone have very simple access to the internet.
The internet was surging and most businesses were creating websites.

2000    414 million people were connected to the internet and were using the World Wide Web.

2008
Google Chrome was released.
browser wars were in full swing and all the major vendors were heavily competing to have users use their platforms.

2017
3.9 billion people had access to the internet and the World Wide Web.
49% of all web page views, in this year, came from mobile devices.

How the Magic of the Web Works

Package switching: the technique to divide information into message blocks that each get routed separately, made the internet possible.

World Wide Web: an open information system populated with documents reached through URLs.

Unique Resource Locators: (URLs) provide unique addresses to those resources so that your browser can access them

Big Idea:
The World Wide Web is an information space where documents and other web resources are identified by Unique Resource Locators, or URLs, interlinked by hypertext links and can be accessed by the internet.

web basic ingredients:
resources, like HTML documents, images, or other files. This is the content that we want to use, websites that we want to browse, images to look at, files that we want to share.
URLs. These uniquely identify the resources so that your web browser can ultimately show them to you or download them. Every resource on the web has a unique URL.
Hypertext Transfer Protocol, or HTTP. This protocol is the magic that can retrieve documents and communicate them to your web browser.

How it works:
Documents, like HTML documents and other resources like images, are hosted by web servers.
Web servers are computers that run special software to serve up documents and other resources.
The web server will have a unique address on the internet, a URL.
Example:     server.com
All resources hosted by a given server will have unique names related to that server
Example:     server.com/document1.html.
You can use these resources from a client computer that has a web browser installed on it, like Internet Explorer or Google Chrome.
Nowadays, there are many types of client PCs that have web browsers, desktop computers, mobile phones or even virtual reality headsets.

The HTTP protocol takes care of the information communication between the web browser and the web server to deliver documents so that the web browser can render it on the screen.
These web browsers use the HTTP GET operation to ask the internet to serve up a specific document that lives at the address of a given URL.
Whilst painting an HTML document on the screen, a web browser uses CSS and JavaScript to style the document and give it functionality.
A web browser doesn't only get documents from a server, sometimes it sends documents back to the server for processing using an HTTP POST operation.

Now this is a very simplified view of how the web works. There is much more going on, like domain name server calls and TCP/IP protocol handshakes, but that is beyond the scope of this course.

Why Learn About HTML, CSS, and JavaScript?

The web works because of the internet. Magic happens when a web browser asks for a document by a URL and a web server returns it through the HTTP protocol. All of that stuff is infrastructure. Very interesting, but abstracted for developers and software architects.

The magic that happens in the web browser is where we focus.
Content is structured in an HTML document, is formatted and styled with CSS, and gets functionality from JavaScript.

Things to Remember


The history of the internet and the World Wide Web.
Through that, you've learned that the web is only possible because of the underlying infrastructure, which is the internet, and you've seen that the internet and the web are relatively young. The internet has only been around since the '80s, and the web since the '90s.

There are some things that need to be in place for the web to work.
There needs to be a web server that hosts resources like documents and images.
The server and the documents combined create a unique URL that can be used to identify the resources on the internet.
To get the documents and other files from the web server, you'll need data transfer protocols like HTTP.
And finally, you need a computer or other device that runs a web browser to use the resources and view the documents.

All of this leads to why you should learn about the technologies in this course, HTML, CSS, and JavaScript. You should learn these to discover what they are, why they are relevant, and how they are used.
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


HTML TIMELINE
1990         HTML specified, web browser and the World Wide Web created

1993        official draft proposal of an HTML specification by the Internet Engineering Task Force.

early 1994    Internet Engineering Task Force created HTML 2.0 specification
HTML 2.0 became the standard for web browsers.

Jan 1997    HTML 3. 2 specification proposed by the World Wide Web Consortium (W3C)

Dec 1997    W3C published a recommendation for HTML 4. 0.

1999         revision called HTML 4. 01 was published by the W3C.

aside from drafts and minor versions, no new versions were published for a long time

2014         HTML5 published by W3C
developed by the Web Hypertext Application Technology Working Group

2016        W3C delivered HTML 5. 1
2017        W3C delivered HTML 5. 2.

As you can see, developing a specification and evolving it is hard and time consuming.
You've heard about several taskforces and organizations involved in the evolution of HTML.
So, who manages the HTML specification?

1990        inventor of the World Wide Web and the web browser, Tim Berners-Lee
came up with the first specification of HTML, the first elements that it consisted of.

This wasn't a standard yet.

1993        Internet Engineering Task Force proposed the first official specification
This is a United States-based group that creates internet standards
Were heavily involved in the TCP/IP standard.
Oct 1994    The W3C founded by Tim Berners-Lee
1996        World Wide Web Consortium, or W3C, maintains the HTML specification hereafter, with input from commercial software vendors.

2000 HTML officially became an international standard, registered with the International Organization for Standardization and the International Electronical Commission.
2004, a new group founded by people from Mozilla, Apple, and Opera was formed. This group was called the Web Hypertext Application Technology Working Group. This group formed in response to the slow development of web standards by the W3C. The group started working on HTML 5. 0, which was adopted by the W3C as the way forward and became a joint deliverable of the W3C and the Web Hypertext Application Technology Working Group. HTML5 is now considered a living standard. Some say that there will never be a 6. 0 version of HTML, as HTML5 or the living HTML standard will just be evolved to have new features.

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


Example

Some basic HTML elements        How they render

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


In this example, the Microsoft ASP. NET MVC framework is used.

With this framework, you create CSHTML files, like this Details.cshtml file.
It is a C# HTML file that uses the Razor language to manipulate data.
In the CSHTML file, you'd write HTML like this, combined with the Razor language to work with data.

Additionally, you have C# files like this OrderController.cs file.

This code runs on the web server and responds to the URL request to serve up the details page. Before it does that, it looks for an order record in the database, which is performed by this line of code, and then it returns the view, which is the Details.cshtml file, which triggers the generation of HTML that is sent to the browser. So, a framework like this provides a lot of flexibility and features, but is also much more advanced than just HTML. To use it, you need to learn how the framework works, and in this case how C# works.

ASP. NET MVC is just one example of a framework; there are many others:

PHP, which is well known for being the language that WordPress uses.
Because of this, most of the websites and web applications are actually written in PHP.
Java, which is a programming language that has several frameworks that generate HTML.
ASP. NET MVC, which we've just seen.
Node. js, which is a framework based on JavaScript

There are other ways to create web pages as well, like by using wordpress. com, which is a blogging engine. This is a ready-made product that you can use to configure a website.
Another example of a similar product is ghost. org, which is also a ready-made product that you can use to display content in a web browser.

The takeaway is that there are many tools, frameworks, and ways to create HTML.

Things to Remember

HTML is the basic markup for the web.
It is what the web consists of.
Without HTML, there would be no World Wide Web as we know it today.
HTML is a standard that defines elements and attributes that browsers understand and display.
HTML is a standard, which is interpreted by web browsers.
The HTML standard consists of many elements and attributes, some simple, some more advanced.
HTML is evolving to have more and more interactive elements, like the video element.

We've seen that you can write HTML from scratch using tools like text editors and integrated development environments
You can use frameworks like ASP. NET to generate HTML and do more advanced things like connecting to a database.
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

history of CSS.

1994    CSS was first proposed as a style sheet language.

Other languages were also being proposed at the time. However, the W3C, or World Wide Web Consortium, who were already working on the HTML standard, added CSS to the deliverables of the HTML working group.

1996    official recommendation of the CSS level 1 standard (CSS1)

Such a recommendation is considered a specification that web browsers can adopt, which they did, although in the beginning there was very little support for CSS in the major browsers.

1998    publication of the CSS level 2 recommendation

After that, a lot of time went by before there were any official new versions of the standard, although browser support became better and better.

2004    CSS level 2.1 became a candidate recommendation published by the W3C.

The level 2.1 recommendation ping‑ponged back and forth between candidate recommendation and working draft until it was finally published as an official recommendation

2011    actual specification of CSS

In the meantime, work on the next level of CSS had already begun. This new level was CSS level 3 and wasn't going to be one all‑encompassing recommendation, but rather an ever‑evolving collection of CSS modules that each described a category of capabilities. This resulted in the publication of the standard recommendation for a couple of CSS level 3 modules, including the CSS3 selectors and CSS3 colors module.

2012    Official recommendations for more CSS3 modules emerged, like the CSS3 mediaqueries module

2017    CSS3 UI module

Future developments of the CSS specification follows the module principle where some modules reach level 4 and new modules are introduced as level 1 modules. It is important to remember that these versions all contain different capabilities of CSS and are all determined by commissions like the World Wide Web Consortium. This results in standards that are agreed upon capabilities that only work because web browsers implements them.

What Is CSS?

styling the web, so styling HTML in a web browser, is still difficult.
It still feels hard to do basic things, like displaying something in the absolute middle of a page, always, regardless of the size of the screen or the object, just like you see here.

CSS Is Awesome is the text that you might have seen on some coffee mugs that famously point out that CSS is difficult.

Inline CSS

Suppose we want blue text and one of the list items in italic. I could do that with HTML that looks like this. Here, I've added a style to the div that contains the list and the text and told it to use the color blue. And here on the list item, I've added a style that tells it to display its text as italic. This works, and this is CSS, which I've added inline in HTML elements.

\<style\> \</style\>

We declare the styles here in the head element. This tells the rest of the HTML document that every div should display blue text, and it declares a CSS class that I can use on items that I want to be italic. This is more reusable than inline styles, as I can reuse these styles anywhere in the HTML document.

external style sheets


We use a link to a StyleSheet.css file, shown on the left.
When the browser loads this HTML, it also loads the CSS file.
External style sheets provide maximum maintainability and reusability.
The styles are not in the HTML document, which makes everything easier to read and to maintain.
With a separate document, I can link that document in multiple HTML documents and apply the same styles there. Maximum reusability, which results in the styles being applied to both web pages when they are rendered by the browser.

CSS Syntax Selectors
CSS consists of properties and attributes
CSS can indicate to what elements the property should be applied.
You do this with so‑called selectors:

This selects all of the div elements in an HTML page.


Or this one that selects all of the elements that have a class attribute set to class1.


This selects all elements in an HTML page that have an ID of para1.



You can also nest things like this. This selector selects all paragraph elements that have a div element as their parent.



selects multiple elements on an HTML page.
It selects all heading1, heading2, and paragraph elements.



These are some of the CSS selectors. There are many more selectors that you can use in CSS to select elements in HTML and apply properties to them.



CSS Priority

CSS is called cascading, as in Cascading Style Sheets, because properties are applied in a specific order, based on priority.

Example:

Consider this HTML, two paragraph elements with text in them.
They both have the class specific assigned to them, and one of them has an id of morespecific.

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

Interacting with the Web with JavaScript


The glue of the web, JavaScript, used to interact with HTML, the browser, and other systems to make the web more interactive.

Where Did JavaScript Come From?

This is a website from w3schools.com, a free front‑end learning ground where you can learn and practice. This is a simple JavaScript example. On the left, we see simple HTML that displays some text and a button. Inside the HTML of the button, we can see an onclick event.
Inside the onclick is a piece of JavaScript, which you write inline in HTML, just like inline CSS.

This JavaScript simply pops up an alert that says This is a JavaScript alert! So this little piece of programming language actually interacted with the web browser to show us more than just the HTML web page.

JavaScript is a high‑level interpreted programming language.
It is a programming language with all the bells and whistles that come with something like that.
An interpreted language, which means that you don't have to compile the code before you execute it.
It is interpreted at runtime, and it is a high‑level programming language, which means that it is a high abstraction from the computer, which makes it easy to use.

In contrast, the C programming language is a low‑level language, which is more complicated, but gives you more control over things like memory management.

Let's look at that definition again. Now we can understand why it is high level and interpreted. This was intentional to make the language easy to use without the need for compilers or otherwise complicated tooling. This has also been a point of controversy as many developers wrote and still write the language off as too simple and error prone. However you feel about it, JavaScript is everywhere, and it is more popular than ever.
history of JavaScript.

It all started in the few years before 1995 when the Netscape Navigator web browser was being developed by the company Netscape Communications.  Netscape was very popular in the '90s and dominated the browser market. The founder of Netscape Communications believed that HTML needed a glue language that was easy to use by web designers.

1995     Netscape hired Brendan Eich to integrate the Scheme programming language into Netscape Navigator.
He created a prototype of what was called LiveScript.
When the first version shipped with Netscape Navigator, was renamed JavaScript.
As Netscape just closed a deal with Sun to incorporate Java in their products, JavaScript was positioned as the lightweight scripting language for the web that complements the Java programming language, which you'd use for more robust tasks.
However, JavaScript just looks a little bit like Java, but its implementation is more like a combination of the programming languages Scheme and Self.
Soon after JavaScript released in Netscape Navigator, Netscape introduced a server‑side implementation of JavaScript that worked with Netscape Enterprise Server.
On the other side of the camp, Microsoft also included scripting languages in their browser, Internet Explorer. They used JScript and VBScript to do similar things to JavaScript as Internet Explorer and Netscape had different implementations creating websites that would run on both browsers was difficult.

1996    websites popped up with messages like this website is best viewed using Netscape.
Netscape submitted JavaScript to ECMA International to create a standard specification, just like the standards for HTML and CSS.

1997    First official standard, called ECMAScript
was implemented by JavaScript, as well as languages like ActionScript and JScript.
1998    standard evolved with more features into ECMAScript 2
1999    ECMAScript version 3
2000    work started on ECMAScript 4,
2004     ECMAScrit standard scrapped


2007    ECMAScript evolved to version 3.1 to oppose the version 4 effort.
2008    everybody with different implementations, like JScript, came together to further the development of the standard.
2009    rename of ECMAScript version 3.1 to version 5
2011     ECMAScript 5.1.
2015    the standard was called ECMAScript 2015 and evolved into 2016, 2017, 2018, and 2019 with a lot of new features and paradigms.

Nowadays, almost all the major browsers implement the ECMAScript standard and often offer more functionality than just the standard. JavaScript is an implementation of ECMAScript. You can find implementations of JavaScript everywhere. It runs in web browsers, on your mobile devices, and server side in implementations like Node.js.

What Is JavaScript?

JavaScript can be used to manipulate HTML, the browser, and to talk with service is like API's that live on other servers.

Javascript, like CSS can be inline. You can basically write it anywhere in HTML.

JavaScript is used to select an HTML element and alter one of its properties, and it does that without refreshing the page.

the JavaScript code can also be moved to the head element in a script tag.
Now it is reusable in the rest of the HTML document by just calling the show date function, which fills the demo element with the current date and time.

The JavaScript can also be moved to a separate Javascript .js file and in the HTML document, we referenced that file. This is very similar to how you can include external CSS in your HTML document
When you separate JavaScript from HTML, it becomes reusable.

We can also use JavaScript to interact with the browser that it runs in to do all sorts of interactive and advanced things from the browser without having to refresh the page.
Here is how it works in your Web browser.
You have loaded an HTML document and some JavaScript that might have come from an external JavaScript documents.
Now, from the browser, you can call an external API by URL
This API can return something like a document that you then process using JavaScript in the browser. The point of this is that using JavaScript in the context of the Ajax technique you can call server side resource is like API's without refreshing your browser. This allows developers to create very interactive Web applications.
Ajax, by the way, stands for asynchronous Javascript and XML and is just a certain technique that involves JavaScript. It is not an additional technology.


Working with JavaScript

Recap how the web works and let's incorporate JavaScript in it.
Any web page or application consists of three main documents,
HTML that contains content like text and images,
CSS to style the HTML,
JavaScript to make it interactive.

These documents are hosted on a web server that exposes them to the internet using unique URLs. Then, web browsers that are used from client computers can access these documents to the HTTP, or Hypertext Transfer Protocol.
As a web developer, you just need to worry about creating the documents and putting them on the web server.
Once the documents are on the client machine, the web browser interprets them and styles the HTML with CSS and loads the JavaScript to be executed.
The web browsers are the main ingredient that actually run the code that you write in your HTML, CSS, and JavaScript documents.

Just like with HTML and CSS, there are several ways to work with JavaScript.

Just like there are CSS libraries that provide premade styles for you, there are JavaScript libraries that provide premade JavaScript functionality for you.
There are so many JavaScript libraries that it is hard to keep up with. Here are some of them.
A very well-known library is jQuery.
Bootstrap, which we've seen as a CSS library, also contains JavaScript functionality in the form of jQuery plugins to do things like animations.
Libraries like this can speed up your development time significantly. However, you don't know exactly what they are doing, and often they are relatively large in size. This introduces the risk that a library might contain bugs or security flaws that you don't know about, and that you load unnecessary kilobytes of JavaScript into your web page where you only use a small part of a library, which can make your web app less performant.
It's up to you to weigh the pros against the cons of using a JavaScript library.

The same goes for the more advanced libraries and frameworks. These are things like Angular, Knockout, React, and TypeScript. They all help you to be more productive in some way, but they also require specific knowledge.

Frameworks and libraries like these are abstractions on top of plain JavaScript and you need to learn how they work.

So using a library like Angular can be very useful and help us to speed up development a lot. But keep in mind that you need to learn how Angular works, in this case what these HTML attributes do. And also, using a library like this means that you don't know what JavaScript is actually loaded, so you have to trust Angular to be secure.

Things to Remember

Recap
JavaScript is truly the glue of the web.
It is the language that makes web applications interactive.
JavaScript is not derived from Java, although it was marketed as a companion language to Java.
JavaScript kind of looks like Java, but works very differently.
JavaScript is a high-level programming language that was created to be easy to use by web developers and designers, and you can do a lot with it.
You can use JavaScript to interact with HTML and change it on the fly.
You can use it to interact with the browser to do things like pop ups, but also to interact with things like the webcam and microphone that the web browser can access.
And you can use JavaScript to interact with other systems like APIs that live on other servers.
It can do all of this without refreshing the web page, which creates a seamless experience for users.

The functionality of JavaScript is a standard that is described in the ECMAScript standard.
Web browsers implement this standard.
The point is that without tools like web browsers, ECMAScript is just a standard.
Just like HTML and CSS, JavaScript is just text.


Things to Remember

The most important technologies that make the web work are HTML, or Hypertext Markup Language, CSS, or Cascading Style Sheets, and JavaScript.
Any website that you visit today consists out of these three technologies.

It is important to remember that HTML, CSS, and JavaScript or ECMAScript are standards that describe functionalities. They don't do much by themselves.

These standards are implemented in web browsers, like Chrome, Firefox, Edge, and Safari.
The web browser is the one that determines how it interprets the HTML, CSS, and JavaScript.

HTML documents contain the content of a web page.
This is often text with images, and sometimes richer media like audio and video.
HTML has lots of elements to display content, and also has elements that lets users interact with content.

HTML can contain links, links to sections in the HTML document and links to other documents. This is the way the web works.
Everything has a unique address, a unique URL, and pages linked to each other to get from one page to the other.

You can use CSS to style HTML.
CSS can change the look and feel of HTML, like its color or font. You can write CSS in files that you reference from your HTML documents. When you do that, your CSS styles become reusable and your HTML becomes more readable and maintainable as you separate style from content. CSS has evolved to have advanced styling mechanisms.

JavaScript is the glue of the web.
You can use it to interact with HTML, with a browser, and even with services and APIs, all without refreshing the page. JavaScript is one of the core technologies of the web, but web browsers are not the only ones that can interpret and run it. There are also server-side implementations of JavaScript, like Node. js. If you want to learn how to develop applications for the web, you need to learn to program in HTML, CSS, and JavaScript.

Resources to Learn More

https://www.w3schools.com  Free HTML, CSS, and JavaScript tutorials.

https://www.caniuse.com     which browsers implement which features of HTML, CSS, and JavaScript.
