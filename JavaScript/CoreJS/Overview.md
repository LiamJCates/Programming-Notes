Interacting with the Web with JavaScript

JavaScript ("JS" for short) is a full-fledged dynamic programming language that can add interactivity to a website. It was invented by Brendan Eich (co-founder of the Mozilla project, the Mozilla Foundation, and the Mozilla Corporation).

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




ECMA
JavaScript is a very different language than it used to be just a few years ago. ECMAScript, which is the official specification that JavaScript conforms to, has improved a lot in the past few years after a rather long period of no updates to the language at all. Today, the ECMAScript Technical Committee, which is known as TC39, makes yearly releases of ECMAScript, and modern browsers shortly follow by implementing the new features introduced in each year.

This has started with ECMAScript 2015, or its other commonly known name, ES6. Since then, we've had yearly releases named ES plus the current year. Some of these releases were big, and others were very small, but the language now has a continuous update cycle that drives more innovative features and phases out the famous problems JavaScript had over the years.






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
