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
