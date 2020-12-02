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

So while it started as a very text-based, link-based sort of tool, HTML has aged and is still the core foundational component that we use to build web pages in all the different types of websites that we use.

We now have more tools to make those pages richer visually and interactively, we also have more responsibilities because not everyone's going to be viewing these on a big monitor at a desktop, maybe on a laptop, a tablet, or a phone.

responsive design: practice of designing documents that can render properly on any device is an important factor.



## What is HTML?
HTML is a markup language.
Content to be displayed on a page is wrapped in this markup language "marked up"
The markup is not displayed
markup provides additional information and instructions to clients that render the content
browsers are the clients that markup and they render the content in the HTML document.

## Terms
HTML, Hypertext Markup Language.
HTTP, Hypertext Transport Protocol.
The method by which we exchange these HTML documents.

We have a document on a particular computer, and we want somebody in a browser on a different computer to be able to view it. They need to use HTTP to request that document and receive it back in their browser.

URI and a URL are interchangeable, these are simply addresses Universal Resource Identifier or Resource Locator. There are pieces of that address that indicate the server where that document resides, the folders, and the name of the file.

## HTML Documents

The first thing you should see in an HTML document is the DOCTYPE:
\<!--DOCTYPE--\>
This is information the client can use to understand the structure of the document
the rest of the document is HTML marked-up text.  
Today, we typically just see the HTML tag indicating that it's an HTML document in usually HTML5.

If you're looking at an older web page, created several years ago, you may see something similar to this:

```html
<!DOCTYPE HTML PUBLIC
  "-//W3C//DTD HTML 4.01//EN"
  "HTTP:/www.w3.org/TR/html4/strict.dtd">
```

with a DTD or other type of schema or standard applied to it.
Again, this tells the browser or the client that the text that follows is going to be structured in such a way that it conforms to that standard.
There have been a lot of different standards as the versions changed and with different levels of strictness. As you can see here, this was a strict reference or a strict schema, and so the browsers had to be able to understand those different versions.

After the document type is the HTML element or tag.
This acts as a root container for all of the content that we're going to see inside the document.
Having a root element like this is fairly common in markup languages to provide a single point with which we can start to traverse all document elements. This becomes really important as the browsers provide programmatic access through programming languages like JavaScript.


Inside the HTML element, we're going to find two other core elements,
the head and body elements

\<head\>\</head\>
The head contains all sorts of content that won't be rendered to the user.
metadata about the document and processing of the document
For example,
\<title\>         doesn't display in the page, but it might display in the browser's window.
\<meta\>     provides metadata about how to render this page
\<link\>         linking some other type of document into the processing of our HTML document.
\<href\>         a hypertext reference to another file

\<body\>\</body\>.
Contains the content  we want our users to see, where we put our text, where we're going to define images and tables and lists and other information that will be displayed to the user.

Demo: An HTML Document

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
Or we can validate it by copying to validator.w3.org.

It gives us one little warning saying it would be nice if on the HTML element you told us what language this document was. We add the lang attribute to the html tag
\<html lang="en-us"\> for English US.


I mentioned there were other types of DOCTYPES,

Over at the W3C site, w3.org, they list all these different DOCTYPES.
DOCTYPE HTML is the common one and the recommended one.


The Head Element

Inside the head element, there are six key child elements

title    gives us a title for the page and is often displayed in the title bar of the window.

meta    provides metadata about the document
can be anything from the viewport and how it can render or it can be keywords and information that can be used in searches or to index the pages.

script     provides some script or code that can make our pages more interactive,
either right inside the document or linking to another document.
These days, that script is almost always JavaScript.

style     provides styles or additional information about how to render certain content,
either right inside the document or linking to another document.
Styles are the primary way that we change the visual appearance of elements on our screen.
Styles are applied with Cascading Style Sheets, or CSS.

link     provides links to a variety of different types of resources that are related to our page.
It may be, for example, in a table of contents or pointing back to the chapter we're in or somewhere else in that table of contents.

base    allows us to specify a base address with which all our links to other documents will be based on.

Demo: Working with the Head

Let's add a few things to the head.
a meta tag.
\<meta name="description" content="A simple introduction to HTML"\>.
\<meta name="author" content="Your Name Here"\>.
This tag doesn't need a closing tag.
Now meta tags used to be really useful for search engine optimization, but these days that's not really the case anymore because Google and Bing and other search engines actually optimize on the content of your page. But something like the title, for example, might be useful.  The description and author content can get surfaced in search results and other places, so if that's important to you you may want to add these in.

Down to the body
put a paragraph element \<p\>\</p\> around our text because we're going to see some impacts of that in a minute.

Save this as index.html.
A pretty common name for the first HTML document in a folder or in a directory.

The Hello World in the tab comes from our title element in the head.
our Hello HTML Fundamentals gets rendered in the body there.
The meta elements don't actually show up here at all.

I'm going to go ahead and paste into my head a link for a style sheet here.
\<link rel="stylesheet" href="https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/css/bootstrap.min.css"\>
The link element doesn't need a closing tag
rel says what's the relationship to this document? And it's a style sheet.
This href is a link to CSS file, or Cascading Style Sheets.
then add a class to the paragraph tag \<p class="lead"\>.

The browser sees the link element, it pulls in that style sheet, and that style sheet has instructions that say when you see something like this p element and it's been labeled with a class of lead then render it differently.

Let's add a script element, a JavaScript function, alert.
\<script\>
    alert("Hello Javascript");
\</script\>
And when the browser sees this script element it's going to run that script.

Point Out:
DOCTYPE starts with ! an exclamation point.
That indicates that this is a processing instruction. It's not part of the document itself necessarily, but it's something that is specifically called out to the browser that's rendering this document as an instruction that we want it to do something.

Another example of that might be a comment.

\<!--
comment
--\>

These processing instructions tell the browser to do something or, in this case, not do something

opening and closing elements, certain things require them and some don't.

attributes
In the meta element we have these attributes, name and content.
They provide additional information about that particular element.

A Class is a very common attribute that identifies an element as a particular class of element.


The Body Element

the body boils down to a core five.

text
A variety of sizes and styles
headings, citations, paragraphs, and quotes are all types of text that we might need to render.

lists
allow us to identify a set of items that belong together
in either an ordered or unordered fashion

links
the ability to connect one document to another or to provide a link to another resource part of the power of the web and the power of HTML

tables
for displaying data

images
to provide a very rich visual interaction on our page


Demo: Working with the Body

Another common attribute is ID And you can also use name.
\<p id="p1" name="p1n"\>
They don't have to be the same, but they can be.
A class can be uses on many different elements in the same page because it's a class of item.
Whereas the ID should be unique, elements should have unique IDs and unique names
ID and name would be unique on a particular element and those are often used with style sheets, as well as when we get into programming with JavaScript to identify a very particular element on the page that we want to do something with.


Displaying Text

Specifically, we'll look at
headings in order to mark different content or sections of content within our page and to call out different levels of information.
block and inline elements. Different elements in our markup will be treated differently in regards to how they're rendered.
line breaks and white space
displaying reference text, how we can use things like citations or quotations, abbreviations, and superscript and subscript when we cite additional work or references.

headings.
Headings generally denote different sections of your document.
We have different levels of headings all the way from on H1 to an H6.
H1 is highest level heading, the heading for the document, have one H1 per page.
And this gets used by certain tools as they look at your page to understand what the core content of the page is. The other levels you can use to segment your content into different sections and different hierarchies. These headings get rendered usually as a single line of text and with varying levels of font size and boldness or emphasis based on the level of the heading.

block / inline elements.
The distinction refers to how the browser's going to render those items on the page in reference to other items.
We've already seen briefly the p, or paragraph element, and the div, which are both block level elements.
Block level elements are containers to other groups of elements or text.
These contain other block level elements or they can contain inline elements.

An inline element is something that you would see in line with other text
Example is a span element.
A span just simply lets you mark up a section of text to indicate that this span of text is significant in some way. You may use it to apply styles, you may use it with an ID or a name to identify that block of text. These inline elements can contain other inline elements, but they can't contain block level elements.

And here we see another important lesson of HTML, which is just because you can do something doesn't mean that you should. For example, you can nest paragraph elements, but logically that doesn't really make sense. A paragraph is a standalone block of content, and you wouldn't want to embed another paragraph inside of there. However, with the div where we use that primarily to identify a block of content, you can nest those as you may have smaller blocks of content within there.


Demo: Block vs. Inline Elements

Paragraphs have a very particular semantic meaning.
We have a paragraph of text that we want to display and that is a unit of text.

A div is a general purpose element that we can use to identify a section of the page.
Using those div elements allows us to separate our document into different sections that makes it a little easier to understand and manage. As you get further in your HTML development and start using styles and script, you may use this to compartmentalize things

A span element says a particular bit of text is special in some way.
Maybe I'm going to add a class to display or style that differently.

Text Breaking and Whitespace

Some things may not get rendered the way you would initially think.
Part of that may come down to the block versus inline that we just talked about and some of it's about how browsers handle white space and breaking logic.

\<pre\>\</pre\>    pre element, which tells the client this particular content has been preformatted
        This changes the way that the browser handles things like line breaks and white spaces.

\<br/\>        break element, a line break at that point.
\<hr /\>        hr element, or horizontal rule, places a horizontal line right across the page.
Not used as much anymore as people tend to use style sheets and borders

character entity        represents a character that's special
start these entities with the ampersand,and end them with a semicolon.
Special Characters
&lt;        \< - Less-Than Symbol
&gt;        \> - Greater-Than Symbol
&amp;        & - Ampersand, or 'and' sign
&quot;        " - Quotation Mark
&copy;        © - Copyright Symbol
&trade;        ™ - Trademark Symbol
&nbsp;        - A space (non-breaking space)
&#??;        ISO 8859-1 character - replace ?? with the iso code

less than and greater than symbols.
putting one of those right in the middle of our text would confuse the browser.
To display a less than or a greater than sign you use the character entity, starting again with the ampersand, then either lt or gt plus the semicolon.

Reference Text

There's also a set of elements that are specifically around reference text.
There're a lot of things we can use around our text in order to reference other materials or do special types of citations. For example, you may need to

create a superscript or a subscript.
\<sup\>\</sup\>
\<sub\>\</sub\>

cite element, which allows you to cite another work or another person.

abbreviation element that allows you to identify an abbreviation in your document and, more importantly, provide the text of what that abbreviation stands for so that someone looking at your document who may not be familiar with it can mouse over that abbreviation and get the full text that it stands for.

\<code\>
\<samp\>
As developers, documenting your APIs etc... the code and sample elements specify code text and sample output.
\<kbd\>
\<var\>
Likewise, if you're defining keyboard input or variables as you're documenting that code, you can call those out.
\<blockquote\>
\<q\>
quotes. And you can have a standard inline quote with a q element or a blockquote. If we think back to our inline versus block elements, you'll see that these really fall into that category where a blockquote is going to give us the text in a blocked quote format, whereas a q can be used inline to wrap something in quotation marks to indicate that it is a direct quote.
Demo: Reference Text

You'll notice a couple of things
the block quote is both rendered as a block, so it's indented by the browser and rendered as a block quote, and it's rendered in block versus inline. So, the citation, or the cite element that followed it drops down to the next line. It's pushed down because the block quote is a block element.
However, the q, or quote, has added quotation marks in an inline representation. And so inside of our paragraph the inline elements, the quote and the cite, both show up on the same line.
We could add a \<br /\>to  drop it down to the next line. Again, you'll see the difference between a break and the block elements where, by default, there's more spacing around those blocks.

the WB is an abbreviation for Wired Brain. We use the \<abbr\>\</abbr\> tag
then add a title attribute title="Wired Brain".
Now If we hover over the WB the browser shows us the text in the title attribute.

 you'll now be able to understand why things are rendering the way they are and why they're showing up on that new line with or without some padding.
Semantic Meaning

There are a number of formatting elements that I haven't touched
b or the i tags for bold and italics.
emphasis and strong will give you similar results.
etc...
generally, those types of formatting of text, in order to get bold, italics, larger font, etc…
are handled with those Cascading Style Sheets

Use a span element to wrap the items, give them a particular class,
\<span class="important"\> WarningL Coffee is hot!\</span\>

and then apply styles to those class of elements.
```html
<style>
  span.important{
    color:red;
  }
</style>
```

And along those same lines, when we think about the modern use of HTML and the HTML5 that we have today versus the older original versions, we have many more notions of the semantics of the different parts of our document. Let's go back to our document with our divs and our paragraphs and look at some of the new ways in HTML5 we can actually structure that document a little differently with some more semantic tags that provide more context and more understanding of what the content means.

Demo: Using Semantically Meaningful Elements

div elements carve out specific sections of our document so they make sense. But honestly, to the browser or a client the div doesn't mean anything. It's really for our own internal structuring most of the time.

HTML5 introduced some additional elements that act much like the div, but provide much more semantic meaning. So for example, instead of a div with an ID of article, we can use the article element, and that's much like the h1. It should only appear one time in your document. And that represents the main content of the page. You'd probably really appreciate this in pages where you can go into reading mode on your browser and get rid of all the ads and the extra things around the edges of the content and focus purely on the article.

Likewise, we can get rid of the div with and ID of header and just have a \<header\>. And again, this has semantic meaning. It's different from the head element, which is for processing, and it indicates that this is a header within our document. Likewise, if we go down here, instead of a div with an ID of footer, we actually have an element called footer that we can use now.

So again, these don't necessarily change much, but it is very common these days to use these more semantically relevant elements. And the last one is section. So a section, again, is much like a div, but it has some sort of relevance, meaning that this is a section of our page, and we explicitly want to call it out as such. Inside a section, you may still have divs that wrap certain other elements and that you use for those same purposes, but you can use this section to have a little more meaning and a little more context around your content to indicate what that content means to the overall page.

Creating Lists
Understanding Lists

three core types of lists that we can build
fundamentals of building out those lists and defining the different elements within them.
show  how lists are used today in modern application development and modern web pages.

types of lists in HTML
unordered list    a series of items, essentially content, tags, store links, or buttons even, that you want to identify as belonging to a group together and being in a list, but they don't have a particular order associated with them.

ordered list. Very similar in concept, but we care about the order of the items as they appear in the list.

These are really semantic details for us, but they also impact the way that these lists are typically rendered by default in a browser.

definition list. And this one is a little bit different. Where the first two each have a series of items, this really has a list of pairs of items, both the definition term and the actual definition of that term.

Demo: Creating Lists

If we think about the ingredients in a recipe, that's something we might use an unordered list for.
use \<ul\> tags to indicate an unordered list.
each item is tagged \<li\>, or a list item. S

If we think about the steps in a recipe, for example, we might want to have an ordered list.
Use \<ol\>, for ordered list. And we similarly create \<li\> list items underneath there.

Unordered list items get indented and bulleted
Ordered list items are numbered
That's the  semantic difference between an unordered list and an ordered list.
Both appear in the order that we put them in that list, but order lists provide context that these things need to happen in a particular sequence.

To create a definition list. use the \<dl\> element.
Instead of a list item in here, we have a dt, or a definition term and a dd for definition definition, and we can add in a definition for this particular item.
A similar concept to our ordered and unordered list, but instead of just a single list item we have this pair where we have a definition term and the corresponding definition that goes with it.
The default rendering shows the term on one line and the definition on the following line with an indent. Again, this is all just default. And we could apply styles in how that lays out, but that gives you the separation of the term and the definition in a very clear way.
Modern Lists
If you're thinking gosh, I just don't know if I'll actually use lists very much when you think about the web pages you visit, consider:

You don't see anything that appears to be a list, but actually most of this page is probably created with lists and list items. From the navigation at the top with links to the different categories to the pictures on the left side, the thumbnails that let you pick the highlighted picture, the color swatch is probably a list of those images or those boxes with colors. And those customer also viewed items at the bottom is probably also a list of items, in this case a much richer list with a picture and some text, that's a clickable link to that particular product. As I mentioned, lists are really about the semantics of items that are grouped together and kept together, but the display of those lists can be controlled through style sheets. So while the default display is a bulleted list or a numbered list, for example, you can apply styles to get the content that you see on this page.

Demo: Modern Lists

On my recipes page, I want to create a breadcrumb. And this is a concept you may be familiar with when you're on a page and it shows you the hierarchy of how you've navigated there. So it may show you that you're in a particular category of products and a subcategory.
create an ordered list and assign it a class breadcrumb.
Add some list items and classes to indicate that I want to process those differently as well.
So I can say breadcrumb-item for each of those.
keeping in mind that we can apply the same class to different items to put them in a class together.
And finally, I'll add another class of active to this last one. So it's a breadcrumb item, and it also falls under the class active because we can have an item or an element that has multiple classes applied to it.

```html
<ol class="breadcrumb">
    <li class="breadcrumb-item">Wired Brain Coffee</li>
    <li class="breadcrumb-item">Recipes</li>
    <li class="breadcrumb-item active">Hot Cocoa</li>
</ol>
```
Remember that this doesn't really have an impact unless we use that class.
In the header we'll add in a reference to a style sheet.
\<link rel="stylesheet" href="https://stackpath.bootstrap.cdn.com..."/\>
This is pointing to that Bootstrap library, a very popular framework with lots of styling and capabilities that we can add.
The class, breadcrumb, breadcrumb-item, and active, are things that the style sheet has defined styles for.


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


Now the anchor tag can also be used as a target, a named anchor, one where you just provide the name attribute on the a element. And that doesn't render a link or create anything visible, but it does provide a target for you to be able to then link to. So a particular point in your document, for example, you can create an anchor and you can then link directly to that very specific point and not just the document itself.


In addition to explicit targets with a named anchor, there are also implicit anchors that we can use. For example, a particular div with an ID can be used as a target because you can use that ID as the item you want to navigate to. If you recall, IDs for elements within a document should be unique. That means that if we want to target a very specific element in the page it should have its own unique ID and the browser should be able to find it and scroll the window to that very specific point.


When you reference an HTML document in your link you're going to provide that hyper reference, the URL of the document that you want the browser to navigate to. This can be either an absolute or relative link.

In the example you see here, we have an absolute link where we're telling the browser the full URL of that document. We want you to go out to a very particular server, wiredbraincoffee.com, and we want you to get the index.html page.

relative links apply to content on the same server file system
For example, you are on the index.html file in a folder called content that also has a locations.html and a careers.html. to link from index.html page to locations.html, use this href.

The period, or dot, at the beginning of the URL says start in the current directory. Then we reference the content directory and the locations.html file. Likewise, to access the careers.html, we'd use a very similar path with just a different file name.


Link concepts

Demo: Linking Documents

You can also connect to a very specific anchor point within a document.

In this first example, the text loc2 if it's clicked will actually reference a local anchor. It's going to point to that div with an ID of loc2 and navigate us to that point in the document. We can combine these two ideas of referencing a document and referencing an anchor by using a special syntax in our href. We could use either the absolute or relative URL of the file, then we use the pound or hash symbol and the anchor name. So this particular reference could point us back to our locations.html and then either the anchor tag with the name of loc2 or to another element with an ID of loc2.


Understanding Targets

I want to work with some anchors now as targets.



What are those links pointing to? Well, they're looking for anchors here within this particular document.

Then one way I could create an anchor is to use that a tag and give it a name. So I might come in here and say this is cocoa.

Notice the name cocoa matches up to the href we had for the Hot Cocoa Recipe link. That added that pound symbol in front of it to indicate that it was a named anchor.

We could do the same thing for brownies or we could also come down and simply use an implicit anchor. So we could say the ID for this is brownies.

That's the div that wraps our brownie recipe. And that now becomes an implicit anchor called brownies that's also available from that href using the pound sign.

If I click the Brownies Recipe that takes me down lower in the document where that div with that ID lives.
If you hover over it, you'll often find in your status bar down at the bottom the actual URL that it's resolving to.
Whether it's an anchor or a div, it takes us right to that point in the document.



And we keep going on that page until we get back then to the landing page or the main page for our site. Let's go back into that default.html, and let's add one other link here. We can combine a URL and a target to link directly to the brownie recipe.

So, all we have to do is add that #brownies, the named anchor within that target file that we want to go to. So now our reference for this anchor is a specific file and a named anchor within that file.
So we can use relative and absolute links. We can also use these pound symbols to go to named or implicit anchors.
And again, looking at the recipes, we have that anchor tag with a name, our explicit anchor, and we also have that div with an ID of brownies that's more of an implicit anchor that we can use.
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

Displaying Data with Tables


tables are for data. They're all about displaying data to the user. And historically, when HTML was created this was research data. It may have been specific data points in some experiments or other research. But today, we still use tables for displaying sets of data to users. As I said, we'll display some nutrition information, which is a nice natural fit for that. And there are other use cases for displaying that data. What tables are not for, and I'll touch on this in more detail later, is for formatting your pages or formatting your documents. So when we talk about displaying data, I truly mean data. If you're creating a table of contents for your document, that's not data, that's a table of contents. If you're going to display a lot of pictures and you want to do it in a grid, that's not data, that's pictures. And we'll use style sheets and some of the newer CSS or Cascading Style Sheet technologies to do that.

Defining HTML Tables

key components

caption        information for telling the user what this table shows them. And it's especially important for someone who's using, say, an assistive screen reader or other technology to help them understand the page

header        the top row in your table, or set of rows, that are going to provide information to the user that helps them understand the data that falls below each of those columns.

body         where the data will be displayed.

footer         can define things like aggregate values, sums, averages, etc.

Inside of the table, we're going to structure our data using rows and columns.

The rows are represented with a TR element, and that defines the wrapper around the entire row.

Inside of a row you could have a table header. So if this is the header of your table each element or cell within there is identified with a TH.

Within the body of your table, if you're inside a row and you're creating a cell, you use the TD or table data element to identify that table cell.

As you can see, when you create a table you take this row-first approach where you define the row and then you define each of the cells within that row that make up the columns.

Sometimes your data isn't going to fit neatly into grid spaces that are all aligned, and for that you have the ability to use colspan and rowspan attributes  so that a particular cell can span across multiple columns or multiple rows.
This allows you to handle things such as headers where you need to have a top- level header that spans a couple of different columns or when you've got data that applies to multiple levels of your grid.

Demo: Creating Tables


Now in the head, remember, we're going to start with a row-first approach. So we use a tr for a table row. But also in the head, for each element or each cell or column we use the th for the table head.

If I go down to the footer, I'm going to have the same number of columns. So I want to have another tr or row. In this case, I'll use the table data.


now we get to the body of the table. So again, we use the tr for a row. And we're going to use those tds, or table datas.

we've got a table, we've got a caption at the top with the information about what's in that table, and then we've got our table head. Now notice that, by convention, browsers are rendering those column headers as bolded text to make them stand out from the data. and, of course, the footer at the bottom providing some max values or aggregate values for us.



Formatting Tables

Typically we use style sheets.

we'll type in a td, th, and then we'll use curly brackets. And what this does is indicates that when the browser sees the table data or table head element it should apply these styles to it.

Another common formatting task you might have is you may want to center that table in the middle of the page.


Including Images
Understanding Images in HTML

how to
add images to a page
provide different image sources in order to give the best experience on those different devices.
use images different ways in your page.

image element, img

attributes
src    tells the client or the browser the address of the image file.
usually relative to the HTML document that we're currently viewing.

alt    tells the client or the browser a text representation of the image. So if the browser can't display the image for some reason it can still display the text. If you mouse over a particular image in your document you'll see the alternate text.

height / width     control display sizing
keep in mind that this doesn't change the size of the image. So if you have a very large image, even though it might render smaller the browser still has to download that potentially very large file, which will slow down the performance of your web page for the user.



Defining Alternate Images

srcset         attribute which allows us to provide different sources, different files with the image in them, that will have different sizes. So one may be a much larger file both in terms of the actual image and the file size, and you may have one that's smaller for smaller devices or screens.

sizes    tells the browser when you render this I want you to make it relative to the viewport, that viewable area of the browser window.
