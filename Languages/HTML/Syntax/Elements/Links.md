Summary

    Use the <a> element to define a link
    Use the href attribute to define the link address
    Use the target attribute to define where to open the linked document
    Use the <img> element (inside <a>) to use an image as a link
    Use the mailto: scheme inside the href attribute to create a link that opens the user's email program




Linking Documents

Links allow users to click their way from page to page and are essential for navigating the web.
Links are found in nearly all web pages. 

HTML links are hyperlinks.
You can click on a link and jump to another document.



By default, links will appear as follows in all browsers:

    An unvisited link is underlined and blue
    A visited link is underlined and purple
    An active link is underlined and red
    On mouse over, the mouse arrow will turn into a little hand.



### Linking to a webpage

The HTML anchor tag <a> defines a hyperlink

<a href="url">link text</a>

The href attribute indicates the link's destination.
The link text is the part that will be visible in the browser.
Clicking on the link text, will send the reader to the specified URL address.

This example shows how to create a link to W3Schools.com:

<a href="https://www.w3schools.com/">Visit W3Schools.com!</a> 



### Linking to a file

We use the \<a> tag, or anchor, in order to identify that we're creating either the source or target of a link.

```html
<a href="link.html">
  Link Text
</a>
```

In this example, you can see we have an anchor tag with an href attribute or a hypertext reference, where we're indicating that the content inside of this anchor is a clickable link that's going to navigate the browser to the target or the href. In this case, we're saying if you click on the link text it will take you to the file called link.html that is in the same directory as whatever the current file is.




More on Absolute URLs and Relative URLs

Example

Use a full URL to link to a web page: 
<a href="https://www.w3schools.com/html/default.asp">HTML tutorial</a>

Example

Link to a page located in the html folder on the current web site: 
<a href="/html/default.asp">HTML tutorial</a>

Example

Link to a page located in the same folder as the current page: 
<a href="default.asp">HTML tutorial</a>















If you have a long document or a long page, you may want to allow the user to click on a link and move further down into the document to a very specific point.

There are a number of ways this can be achieved.


### name Link 

```html
<a href="#TOC">
</a>

<p>content...</p>

<a name="TOC">
</a>
<p>more content...</p>

```

The anchor tag can be used as a target of another link.

A named anchor, provides the name attribute on the \<a> element. 
This doesn't render a link or create anything visible, but it does provide a target for you to be able to then link to. 


So a particular point in your document, for example, you can create an anchor and you can then link directly to a specific point and not just the document itself, using another link that targets that name.

The pound symbol in front of the indicates that it is targeting the named anchor.



### id Link

```html
<a href="#article">
</a>

<div id="article">
</div>
```

In addition to explicit targets with a named anchor, there are also implicit anchors that we can use. For example, a particular div with an ID. 

As it is recommended that element IDs within a document should be unique, we can target a specific element.




When you reference an HTML document in your link you're going to provide that hyperlink reference, the URL of the document that you want the browser to navigate to. This can be either an absolute or relative link.

```html
<a href="http://example.com/index.html">
  Link Text
</a>
```

In the example you see here, we have an absolute link where we're telling the browser the full URL of that document. We want you to go out to a very particular server, example.com, and we want you to get the index.html page.

```html
<a href="./content/locations.html">
  Link Text
</a>
```

Above is a relative link, these apply to content on the same server file system.

For example, you are on the index.html file in a folder called content that also has a locations.html and a careers.html. to link from index.html page to locations.html, use this href.

The period, or dot, at the beginning of the URL says start in the current directory. Then we reference the content directory and the locations.html file.

















Understanding Targets


If you hover over it, you'll often find in your status bar down at the bottom the actual URL that it's resolving to.

Whether it's an anchor or a div, it takes us right to that point in the document.

We can combine a URL and a target to link directly to a location on another page.

So, all we have to do is add that target #target, the named anchor within that target file that we want to go to. So now our reference for this anchor is a specific file and a named anchor within that file.


So we can use relative and absolute links. We can also use these pound symbols to go to named or implicit anchors.






Linking to Targets

In addition to the href or name attributes that we can apply on an anchor, there's other metadata that we can provide that can be helpful to viewers that are using a browser or using other tools to interpret your page.


language
indicating a link points to a particular language version of another document.

relationship
indicates how that document relates to this page, often used in things like table of contents, but there are other possibilities there to indicate how the two are related.

content
indicates to the client that the link is a document or image or other type of content.

access key
allows the client to reference the link using keyboard shortcuts instead of using the click gesture with a mouse.

target
defines where that link will open.








Additional Link Attributes






If you're going to target any window that refers to a site that you don't own, another thing you'll want to add is a rel. Remember, this is the relationship to this particular document.

rel="next"
indicates that there's a flow in terms of documents that are together, in a table of contents for example.

Here we're going to use some special ones, noreferrer and noopener. And what does that mean? This is a security-related measure. That means when we go out to this site and we create a new window or in the same window, we go to the site, we don't want that site to have access to the window that opened it or to the site that referred it. And this is to protect against malicious sites or hijacked sites being able to take control of the window that contains your site or being able to get access to where the user just came from. So it's a good idea to use this, again, when you're connecting to sites outside of your current site and control. If the other page had some malicious  JavaScript it wouldn't have access .









A link does not have to be text. A link can be an image or any other HTML element!


Use an Image as a Link

To use an image as a link, just put the <img> tag inside the <a> tag:
Example
<a href="default.asp">
<img src="smiley.gif" alt="HTML tutorial" style="width:42px;height:42px;">
</a> 


Link to an Email Address

Use mailto: inside the href attribute to create a link that opens the user's email program (to let them send a new email):
Example
<a href="mailto:someone@example.com">Send email</a> 


Button as a Link

To use an HTML button as a link, you have to add some JavaScript code.

JavaScript allows you to specify what happens at certain events, such as a click of a button:
Example
<button onclick="document.location='default.asp'">HTML Tutorial</button> 





Absolute URLs vs. Relative URLs

Both examples above are using an absolute URL (a full web address) in the href attribute.

A local link (a link to a page within the same website) is specified with a relative URL (without the "https://www" part):
Example
<h2>Absolute URLs</h2>
<p><a href="https://www.w3.org/">W3C</a></p>
<p><a href="https://www.google.com/">Google</a></p>

<h2>Relative URLs</h2>
<p><a href="html_images.asp">HTML Images</a></p>
<p><a href="/css/default.asp">CSS Tutorial</a></p> 













Create a Bookmark in HTML

Bookmarks can be useful if a web page is very long.

To create a bookmark - first create the bookmark, then add a link to it.

When the link is clicked, the page will scroll down or up to the location with the bookmark.
Example

First, use the id attribute to create a bookmark:
<h2 id="C4">Chapter 4</h2>

Then, add a link to the bookmark ("Jump to Chapter 4"), from within the same page:
Example
<a href="#C4">Jump to Chapter 4</a>

You can also add a link to a bookmark on another page:
<a href="html_demo.html#C4">Jump to Chapter 4</a>






The target Attribute

By default, the linked page will be displayed in the current browser window. To change this, you must specify another target for the link.

The target attribute specifies where to open the linked document.

The target attribute can have one of the following values:

    _self - Default. Opens the document in the same window/tab as it was clicked
    _blank - Opens the document in a new window or tab
    _parent - Opens the document in the parent frame
    _top - Opens the document in the full body of the window

Example

Use target="_blank" to open the linked document in a new browser window or tab:
<a href="https://www.w3schools.com/" target="_blank">Visit W3Schools!</a> 




Generally, when we click on a hyperlink it opens in the same window or browser tab.

You can actually ask the browser to open it in a different context.
For example, you might ask it to open it in a new blank container. And depending on the user's setting in the browser, that may be a new tab or it may be a new window. The end result for you is that your page remains active in a browser window or browser tab and the content of the link opens up in a new window for the user.


The target allows you to provide some context or direction to the browser about where you want this content to open. It's pretty common to use target="_blank"
This tells the browser you want to open this in a new window or tab.
You could use target="_self", but that's the default. It just opens it right inside the same window that you're currently in. And you can use thing such as _top, which would open it in the top-level window, which again in this case would give us the same exact result. So blank is the most commonly-used target because the goal is to break the user out into a new window to visit a different site.


