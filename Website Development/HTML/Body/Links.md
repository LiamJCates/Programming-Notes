Linking Documents


We're going to take a look at our HTML documents and understand how to link from one document to another to give us the capability to create that web of documents.

In this module, we're going to focus on

anchors        allow us to create what's called a hyperlink, or that clickable link that you're used to that allows you to click and link to a different document. It can also be targets of a particular link.

how to link from one document to another
how to link within a document
If you have a long document or a long page, you may want to allow the user to click on a link and move further down into the document to a very specific point.

link metadata, some of the information you can provide about the link such that a client, like a browser, can interpret that and potentially influence how it's rendered or the information given to the client about that link.



Links
A link is just another HTML element. We use the \<a\> tag, or anchor, in order to identify that we're creating either the source or target of a link.

```html
<a href="link.html">
  Link Text
</a>
```

In this first example, you can see we have an anchor tag with an href attribute or a hypertext reference, where we're indicating that the content inside of this anchor is a clickable link that's going to navigate the browser to the target or the href. In this case, we're saying if you click on the text Pluralsight it will take you to the file called Pluralsight.html that sits right next to whatever the current file is.

```html
<a name="TOC">
</a>
```
Now the anchor tag can also be used as a target, a named anchor, one where you just provide the name attribute on the a element. And that doesn't render a link or create anything visible, but it does provide a target for you to be able to then link to. So a particular point in your document, for example, you can create an anchor and you can then link directly to that very specific point and not just the document itself.

```html
<div id="article">
</div>
```

In addition to explicit targets with a named anchor, there are also implicit anchors that we can use. For example, a particular div with an ID can be used as a target because you can use that ID as the item you want to navigate to. If you recall, IDs for elements within a document should be unique. That means that if we want to target a very specific element in the page it should have its own unique ID and the browser should be able to find it and scroll the window to that very specific point.


When you reference an HTML document in your link you're going to provide that hyper reference, the URL of the document that you want the browser to navigate to. This can be either an absolute or relative link.

```html
<a href="http://example.com/index.html">
  Link Text
</a>
```

In the example you see here, we have an absolute link where we're telling the browser the full URL of that document. We want you to go out to a very particular server, wiredbraincoffee.com, and we want you to get the index.html page.

```html
<a href="./content/locations.html">
  Link Text
</a>
```

Above is a relative link, these apply to content on the same server file system
For example, you are on the index.html file in a folder called content that also has a locations.html and a careers.html. to link from index.html page to locations.html, use this href.

The period, or dot, at the beginning of the URL says start in the current directory. Then we reference the content directory and the locations.html file. Likewise, to access the careers.html, we'd use a very similar path with just a different file name.


Link concepts

Demo: Linking Documents

```html
<a href="#loc2">Location 2</a>
<div id="locations">
	<div id="loc1">First</div>
	<div id="loc2">Second</div>
</div>
```

You can also connect to a very specific anchor point within a document.

In this first example, the text loc2 if it's clicked will actually reference a local anchor. It's going to point to that div with an ID of loc2 and navigate us to that point in the document. We can combine these two ideas of referencing a document and referencing an anchor by using a special syntax in our href. We could use either the absolute or relative URL of the file, then we use the pound or hash symbol and the anchor name. So this particular reference could point us back to our locations.html and then either the anchor tag with the name of loc2 or to another element with an ID of loc2.


Understanding Targets

I want to work with some anchors now as targets.

What are those links pointing to? Well, they're looking for anchors here within this particular document.

Then one way I could create an anchor is to use that as a tag and give it a name.

An added that pound symbol in front of it to indicate that it was a named anchor.

We could do the same thing for brownies or we could also come down and simply use an implicit anchor. So we could say the ID for this is brownies.

That's the div that wraps our brownie recipe. And that now becomes an implicit anchor called brownies that's also available from that href using the pound sign.

If I click an anchor with a target it takes us to the point in the document where that div with that ID lives.
If you hover over it, you'll often find in your status bar down at the bottom the actual URL that it's resolving to.
Whether it's an anchor or a div, it takes us right to that point in the document.



We can combine a URL and a target to link directly to a location on another page.

So, all we have to do is add that target #target, the named anchor within that target file that we want to go to. So now our reference for this anchor is a specific file and a named anchor within that file.
So we can use relative and absolute links. We can also use these pound symbols to go to named or implicit anchors.


Demo: Linking to Targets

In addition to the href or name that we can apply on an anchor, there's other metadata that we can provide that can be helpful to viewers that are using a browser or using other tools to interpret your page.
language     indicating a link points to a particular language version of another document.

relationship    indicates how that document relates to this page,
often used in things like table of contents,
but there are other possibilities there to indicate how the two are related.

content     indicates to the client that the link is a document or image or other type of content.

access key    allows the client to reference the link using keyboard shortcuts instead of using the click gesture with a mouse.

target         defines where that link will open.
Generally, when we click on a hyperlink it opens in the same window or browser tab.
You can actually ask the browser to open it in a different context.
For example, you might ask it to open it in a new blank container. And depending on the user's setting in the browser, that may be a new tab or it may be a new window. The end result for you is that your page remains active in a browser window or browser tab and the content of the link opens up in a new window for the user.

Additional Link Attributes

The target allows you to provide some context or direction to the browser about where you want this content to open. It's pretty common to use target="_blank"
This tells the browser you want to open this in a new window or tab.
You could use target="_self", but that's the default. It just opens it right inside the same window that you're currently in. And you can use thing such as _top, which would open it in the top-level window, which again in this case would give us the same exact result. So blank is the most commonly-used target because the goal is to break the user out into a new window to visit a different site.

If you're going to target any window that refers to a site that you don't own, another thing you'll want to add is a rel. Remember, this is the relationship to this particular document.
rel="next"
indicates that there's a flow in terms of documents that are together, in a table of contents for example.

Here we're going to use some special ones, noreferrer and noopener. And what does that mean? This is a security-related measure. That means when we go out to this site and we create a new window or in the same window, we go to the site, we don't want that site to have access to the window that opened it or to the site that referred it. And this is to protect against malicious sites or hijacked sites being able to take control of the window that contains your site or being able to get access to where the user just came from. So it's a good idea to use this, again, when you're connecting to sites outside of your current site and control. If the other page had some malicious  JavaScript it wouldn't have access .
