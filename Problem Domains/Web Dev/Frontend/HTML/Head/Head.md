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
