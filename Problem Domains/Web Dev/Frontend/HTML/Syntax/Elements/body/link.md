Summary

    <a> element to define a link
    href attribute to define the link address
    target attribute defines where to open the linked document
    <img> element (inside <a>) to use an image as a link
    mailto: inside the href to create a link that opens the user's email program




Linking Documents

Links allowing users to click their way from page to page are essential for navigating the web and found in nearly all web pages. 

HTML links are hyperlinks.
You click on a link and jump to another document.

By default, links will appear as follows in all browsers:

    An unvisited link is underlined and blue
    A visited link is underlined and purple
    An active link is underlined and red
    On mouse over, the mouse arrow will turn into a little hand.



### Linking to a webpage

The HTML anchor tag \<a> defines a hyperlink
The href attribute, or hypertext reference, indicates the link's destination.
The "link text" content is the part that will be visible in the browser.
Clicking on the link text, will send the reader to the specified URL address.

This example shows how to create a link to W3Schools.com:

<a href="https://www.w3schools.com/">Visit W3Schools.com!</a> 



### Linking to a file

```html
<a href="link.html">
  Link Text
</a>
```

In this case, the link will direct you to the file called link.html that is in the same directory, on the same file server, as whatever the current file is.





When you reference an HTML document in your link you're going to provide that hyperlink reference, the URL of the document that you want the browser to navigate to. This can be either an absolute or relative link.

```html
<a href="http://example.com/index.html">
  Link Text
</a>
```

In the example you see here, we have an absolute link where we're telling the browser the full URL of that document. We are redirecting to a particular server, example.com, to the index.html page.

```html
<a href="./content/locations.html">
  Link Text
</a>
```

Above is a relative link, these apply to content on the same server file system.

For example, you are on the index.html file in a folder called content that also has a locations.html and a careers.html. to link from index.html page to locations.html, use this href.

The period, or dot, at the beginning of the URL says start in the current directory. Then we reference the content directory and the locations.html file.


Further Examples

Use a full URL to link to a web page: 
<a href="https://www.w3schools.com/html/default.asp">HTML tutorial</a>

Link to a page located in the html folder on the current web site: 
<a href="/html/default.asp">HTML tutorial</a>

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

With a named anchor, you can then link directly to a specific point and not just the document itself, using another link that targets that name.

The pound symbol in front of href value indicates that it is targeting a named anchor with the name value that follows.

NOTE: as of HTML5, named anchors are deprecated 


### id Link

```html
<a href="#loc2">
</a>

<div id="loc1">
  <p>content...</p>
</div>

<div id="loc2">
  <p>more content...</p>
</div>
```

In addition to explicit targets with a named anchor, there are also implicit anchors that we can use. For example, a particular div with an ID. 

As it is recommended that element IDs within a document should be unique, we can target a specific element.


We can combine a URL and a target to link directly to a location on another page.

```html
<a href="http://example.com/index.html#loc1">
  Link Text
</a>
```

If you hover over it, you'll often find in your status bar down at the bottom the actual URL that a link resolves to.

Whether it's an anchor or a div, it takes us right to that point in the document.





### Additional Link Attributes


In addition to the href or name attributes that we can apply on an anchor, there's other metadata that we can provide that can be helpful to viewers that are using a browser or using other tools to interpret your page.


language
indicating a link points to a particular language version of another document.

relationship
indicates how that document relates to this page, often used in things like table of contents, but there are other possibilities there to indicate how the two are related.

content
indicates to the client that the link is a document or image or other type of content.

accesskey
allows the client to reference the link using keyboard shortcuts instead of using the click gesture with a mouse.






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



```html
<a href="https://www.theodinproject.com/about" target="_blank" rel="noopener noreferrer">About The Odin Project</a>
```

You may have noticed that we snuck in the rel attribute above. This attribute is used to describe the relation between the current page and the linked document.

noopener: The noopener attribute ensures that a link opened in a new tab or window cannot interact with or access the original page. Without it, the new page can use JavaScript to manipulate the original page, which poses a security risk.


In this code: target=”_blank”: opens the link in a new tab. rel=”noopener”: prevents the new tab from accessing the original page, ensuring security.

Without noopener, the new tab could use JavaScript to interact with the original page, which is unsafe.

noreferrer: The noreferrer attribute provides both privacy and security. It prevents the new page from knowing where the user came from (hiding the referrer) and also includes the behavior of noopener, preventing the new page from accessing the original page.


In this example: target=”_blank”: opens the link in a new tab. rel=”noreferrer”: ensures the new page cannot see the referring page’s address (privacy) and prevents it from accessing the original page (security).

By using rel=”noreferrer”, you automatically get the benefits of both privacy and security.

Why do we need this added behaviour for opening links in new tabs? Security reasons. The prevention of access that is caused by noopener prevents phishing attacks where the opened link may change the original webpage to a different one to trick users. This is referred to as tabnabbing. Adding the noreferrer value can be done if you wish to not let the opened link know that your webpage links to it.

Note that you may be fine if you forget to add rel="noopener noreferrer" since more recent versions of browsers provide security if only target="_blank" is present. Nevertheless, in line with good coding practices and to err on the side of caution, it is recommended to always pair a target="_blank" with a rel="noopener noreferrer".