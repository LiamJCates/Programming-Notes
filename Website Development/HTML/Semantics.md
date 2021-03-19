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

Likewise, we can get rid of the div with and ID of header and just have a <header>. And again, this has semantic meaning. It's different from the head element, which is for processing, and it indicates that this is a header within our document. Likewise, if we go down here, instead of a div with an ID of footer, we actually have an element called footer that we can use now.

So again, these don't necessarily change much, but it is very common these days to use these more semantically relevant elements. And the last one is section. So a section, again, is much like a div, but it has some sort of relevance, meaning that this is a section of our page, and we explicitly want to call it out as such. Inside a section, you may still have divs that wrap certain other elements and that you use for those same purposes, but you can use this section to have a little more meaning and a little more context around your content to indicate what that content means to the overall page.
