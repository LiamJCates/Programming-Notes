## **List Elements (For Text-Based Lists)**

| **Element** | **Description** | **Example** |
|------------|----------------|-------------|
| `<ul>` | Defines an unordered list. | `<ul><li>Item 1</li><li>Item 2</li></ul>` |
| `<ol>` | Defines an ordered list. | `<ol><li>Step 1</li><li>Step 2</li></ol>` |
| `<li>` | Defines a list item inside `<ul>` or `<ol>`. | `<li>List item</li>` |
| `<dl>` | Defines a description list. | `<dl><dt>Term</dt><dd>Definition</dd></dl>` |
| `<dt>` | Defines a term in a description list. | `<dt>HTML</dt>` |
| `<dd>` | Defines a description in a description list. | `<dd>Hypertext Markup Language</dd>` |



The three types of HTML lists are:  

1. **Unordered List (`<ul>`)** – A bullet-point list without a specific order.  
   ```html
   <ul>
       <li>Item one</li>
       <li>Item two</li>
       <li>Item three</li>
   </ul>
   ```
   This will render as:  
   - Item one  
   - Item two  
   - Item three  

   
a series of items, essentially content, tags, store links, or buttons even, that you want to identify as belonging to a group together and being in a list, but they don't have a particular order associated with them.

Unordered list items get indented and bulleted
The ingredients in a recipe might use an unordered list for.
use \<ul\> tags to indicate an unordered list.
each item is tagged \<li\>, or a list item.


2. **Ordered List (`<ol>`)** – A numbered list where each item is sequentially arranged.  
   ```html
   <ol>
       <li>First item</li>
       <li>Second item</li>
       <li>Third item</li>
   </ol>
   ```
   This will render as:  
   1. First item  
   2. Second item  
   3. Third item  


Very similar in concept to the unordered list, but we care about the order of the items as they appear in the list.
Ordered list items are numbered


That's the semantic difference between an unordered list and an ordered list.
Both appear in the order that we put them in that list, but order lists provide context that these things need to happen in a particular sequence.


The steps in a recipe might use an ordered list.

Use \<ol\>, for ordered list
Create \<li\> list items with


3. **Definition List (`<dl>`)** – A list of terms and their corresponding descriptions.  
   ```html
   <dl>
       <dt>HTML</dt>
       <dd>HyperText Markup Language</dd>
       <dt>CSS</dt>
       <dd>Cascading Style Sheets</dd>
   </dl>
   ```
   This will render as:  
   **HTML**  
   - HyperText Markup Language  

   **CSS**  
   - Cascading Style Sheets


definition list
The first two each have a series of items, this really has a list of pairs of items, both the definition term and the actual definition of that term.



To create a definition list. use the \<dl\> element.
Instead of a list item in here, we have a dt, or a definition term and a dd for definition definition, and we can add in a definition for this particular item.
A similar concept to our ordered and unordered list, but instead of just a single list item we have this pair where we have a definition term and the corresponding definition that goes with it.

The default rendering shows the term on one line and the definition on the following line with an indent.

Note that it is permitted to have a single term with multiple descriptions


### Modern Lists

If you're thinking gosh, I just don't know if I'll actually use lists very much when you think about the web pages you vhyisit, consider:

You don't see anything that appears to be a list, but actually most of this page is probably created with lists and list items. For example top navigation bars are typically lists of links. In this case a much richer list with a picture and some text, that's a clickable link to that particular product. As I mentioned, lists are really about the semantics of items that are grouped together and kept together, but the display of those lists can be controlled through style sheets. So while the default display is a bulleted list or a numbered list, for example, you can apply styles to get the content that you see on this page.

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


Nesting lists

It is perfectly OK to nest one list inside another one. You might want to have some sub-bullets sitting below a top-level bullet. Let's take the second list from our recipe example:
html

<ol>
  <li>Remove the skin from the garlic, and chop coarsely.</li>
  <li>Remove all the seeds and stalk from the pepper, and chop coarsely.</li>
  <li>Add all the ingredients into a food processor.</li>
  <li>Process all the ingredients into a paste.</li>
  <li>If you want a coarse "chunky" hummus, process it for a short time.</li>
  <li>If you want a smooth hummus, process it for a longer time.</li>
</ol>

Since the last two bullets are very closely related to the one before them (they read like sub-instructions or choices that fit below that bullet), it might make sense to nest them inside their own unordered list and put that list inside the current fourth bullet. This would look like so:
html

<ol>
  <li>Remove the skin from the garlic, and chop coarsely.</li>
  <li>Remove all the seeds and stalk from the pepper, and chop coarsely.</li>
  <li>Add all the ingredients into a food processor.</li>
  <li>
    Process all the ingredients into a paste.
    <ul>
      <li>
        If you want a coarse "chunky" hummus, process it for a short time.
      </li>
      <li>If you want a smooth hummus, process it for a longer time.</li>
    </ul>
  </li>
</ol>
