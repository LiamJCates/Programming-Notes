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
