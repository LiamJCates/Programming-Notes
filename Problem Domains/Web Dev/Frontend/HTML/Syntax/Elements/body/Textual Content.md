# Textual Content


### **HTML Elements That Deal with Text**  

HTML provides a variety of elements specifically designed for working with text. These elements help define structure, meaning, and formatting. Below is a categorized list of text-related HTML elements:

---

## **1. Basic Text Content Elements**
| **Element** | **Description** | **Example** |
|------------|----------------|-------------|
| `<p>` | Defines a paragraph. | `<p>This is a paragraph.</p>` |
| `<br>` | Inserts a line break. | `First line<br>Second line` |
| `<hr>` | Creates a thematic break (horizontal line). | `<hr>` |


### Paragraph

HTML paragraphs are defined with the <p> tag:

```html
<p>This is a paragraph.</p>
<p>This is another paragraph.</p> 
```

#### Paragraph Display

You cannot be sure how HTML will be displayed.

Large or small screens, and resized windows will create different results.

With HTML, you cannot change the display by adding extra spaces or extra lines in your HTML code.

The browser will automatically remove any extra spaces and lines when the page is displayed:


<p>
This paragraph
contains a lot of lines
in the source code,
but the browser
ignores it.
</p>

<p>
This paragraph
contains         a lot of spaces
in the source         code,
but the        browser
ignores it.
</p> 



### Horizontal Rules

The <hr> tag defines a thematic break in an HTML page, and is most often displayed as a horizontal rule.

The <hr> element is used to separate content (or define a change) in an HTML page:

Example
<h1>This is heading 1</h1>
<p>This is some text.</p>
<hr>
<h2>This is heading 2</h2>
<p>This is some other text.</p>
<hr> 



### Line Breaks

The HTML <br> element defines a line break.

Use <br> if you want a line break (a new line) without starting a new paragraph

<p>This is<br>a paragraph<br>with line breaks.</p> 


---

## **2. Headings**
| **Element** | **Description** | **Example** |
|------------|----------------|-------------|
| `<h1>` to `<h6>` | Defines six levels of headings, from largest (`<h1>`) to smallest (`<h6>`). | `<h1>Main Title</h1>` |


Each heading has to be wrapped in a heading element:
html

<h1>I am the title of the story.</h1>

There are six heading elements: h1, h2, h3, h4, h5, and h6. Each element represents a different level of content in the document; <h1> represents the main heading, <h2> represents subheadings, <h3> represents sub-subheadings, and so on.


### Implementing structural hierarchy

For example, in this story, the <h1> element represents the title of the story, the <h2> elements represent the title of each chapter, and the <h3> elements represent subsections of each chapter:
html

<h1>The Crushing Bore</h1>

<p>By Chris Mills</p>

<h2>Chapter 1: The dark night</h2>

<p>
  It was a dark night. Somewhere, an owl hooted. The rain lashed down on the…
</p>

<h2>Chapter 2: The eternal silence</h2>

<p>Our protagonist could not so much as a whisper out of the shadowy figure…</p>

<h3>The specter speaks</h3>

<p>
  Several more hours had passed, when all of a sudden the specter sat bolt
  upright and exclaimed, "Please have mercy on my soul!"
</p>

It's really up to you what the elements involved represent, as long as the hierarchy makes sense. You just need to bear in mind a few best practices as you create such structures:

    Preferably, you should use a single <h1> per page—this is the top level heading, and all others sit below this in the hierarchy.
    Make sure you use the headings in the correct order in the hierarchy. Don't use <h3> elements to represent subheadings, followed by <h2> elements to represent sub-subheadings—that doesn't make sense and will lead to weird results.
    Of the six heading levels available, you should aim to use no more than three per page, unless you feel it is necessary. Documents with many levels (for example, a deep heading hierarchy) become unwieldy and difficult to navigate. On such occasions, it is advisable to spread the content over multiple pages if possible.



### Why do we need structure?

When you open an unstructured document in your browser, you'll see that the text appears as a big chunk!

The content is a wall of unformatted text, because there are no elements on the page to structure it.

    Users looking at a web page tend to scan quickly to find relevant content, often just reading the headings, to begin with. (We usually spend a very short time on a web page.) If they can't see anything useful within a few seconds, they'll likely get frustrated and go somewhere else.

    Search engines indexing your page consider the contents of headings as important keywords for influencing the page's search rankings. Without headings, your page will perform poorly in terms of SEO (Search Engine Optimization).
    
    Severely visually impaired people often don't read web pages; they listen to them instead. This is done with software called a screen reader. This software provides ways to get fast access to given text content. Among the various techniques used, they provide an outline of the document by reading out the headings, allowing their users to find the information they need quickly. If headings are not available, they will be forced to listen to the whole document read out loud.
    
    To style content with CSS, or make it do interesting things with JavaScript, you need to have elements wrapping the relevant content, so CSS/JavaScript can effectively target it.

Therefore, we need to give our content structural markup.

---

## **3. Text Formatting (Styling)**
| **Element** | **Description** | **Example** |
|------------|----------------|-------------|
| `<b>` | Bold text (without emphasis). | `<b>Bold text</b>` |
| `<strong>` | Bold text (with semantic emphasis). | `<strong>Important text</strong>` |
| `<i>` | Italic text (without emphasis). | `<i>Italic text</i>` |
| `<em>` | Italic text (with semantic emphasis). | `<em>Emphasized text</em>` |
| `<u>` | Underlined text. | `<u>Underlined text</u>` |
| `<mark>` | Highlights text. | `<mark>Highlighted text</mark>` |
| `<small>` | Displays smaller text. | `<small>Small text</small>` |
| `<del>` | Strikethrough text (deleted content). | `<del>Deleted text</del>` |
| `<ins>` | Underlined text (inserted content). | `<ins>Inserted text</ins>` |
| `<sub>` | Subscript text. | `H<sub>2</sub>O` |
| `<sup>` | Superscript text. | `X<sup>2</sup>` |


In human language, we often emphasize certain words to alter the meaning of a sentence, and we often want to mark certain words as important or different in some way. HTML provides various semantic elements to allow us to mark up textual content with such effects, and in this section, we'll look at a few of the most common ones.

In HTML we use the <em> (emphasis) element to mark up such instances. As well as making the document more interesting to read, these are recognized by screen readers, which can be configured to speak them in a different tone of voice. Browsers style this as italic by default, but you shouldn't use this tag purely to get italic styling. To do that, you'd use a <span> element and some CSS, or perhaps an <i> element.


To emphasize important words, we tend to stress them in spoken language and bold them in written language. In HTML we use the <strong> (strong importance) element to mark up such instances. As well as making the document more useful, again these are recognized by screen readers, which can be configured to speak them in a different tone of voice. Browsers style this as bold text by default, but you shouldn't use this tag purely to get bold styling. To do that, you'd use a <span> element and some CSS, or perhaps a <b> element.


Italic, bold, underline…

The elements we've discussed so far have clear-cut associated semantics. The situation with <b>, <i>, and <u> is somewhat more complicated. They came about so people could write bold, italics, or underlined text in an era when CSS was still supported poorly or not at all. Elements like this, which only affect presentation and not semantics, are known as presentational elements and should no longer be used because, as we've seen before, semantics is so important to accessibility, SEO, etc.

HTML5 redefined <b>, <i>, and <u> with new, somewhat confusing, semantic roles.

Here's the best rule you can remember: It's only appropriate to use <b>, <i>, or <u> to convey a meaning traditionally conveyed with bold, italics, or underline when there isn't a more suitable element; and there usually is. Consider whether <strong>, <em>, <mark>, or <span> might be more appropriate.

Always keep an accessibility mindset. The concept of italics isn't very helpful to people using screen readers, or to people using a writing system other than the Latin alphabet.


NOTE: You can nest strong and emphasis inside one another if desired:
html

<p>This liquid is <strong>highly toxic</strong> — if you drink it, <strong>you may <em>die</em></strong>.</p>


---

## **4. Quotation and Citation Elements**
| **Element** | **Description** | **Example** |
|------------|----------------|-------------|
| `<blockquote>` | Defines a block quotation. | `<blockquote>Quoted text</blockquote>` |
| `<q>` | Inline short quotation. | `<q>Inline quote</q>` |
| `<cite>` | Defines a citation (e.g., book title). | `<cite>HTML Guide</cite>` |
| `<abbr>` | Defines an abbreviation. | `<abbr title="Hypertext Markup Language">HTML</abbr>` |
| `<address>` | Represents contact information. | `<address>Email: example@example.com</address>` |

---

## **5. Code and Keyboard Input**
| **Element** | **Description** | **Example** |
|------------|----------------|-------------|
| `<code>` | Displays inline code. | `<code>console.log("Hello");</code>` |
| `<pre>` | Displays preformatted text (preserves spaces & line breaks). | `<pre>Text with spacing</pre>` |
| `<kbd>` | Represents keyboard input. | `<kbd>Ctrl + C</kbd>` |
| `<samp>` | Represents sample output. | `<samp>Command Output</samp>` |
| `<var>` | Represents a variable name. | `<var>x</var> = 10;` |

---

## **6. Miscellaneous Text Elements**
| **Element** | **Description** | **Example** |
|------------|----------------|-------------|
| `<span>` | Generic inline container for text styling. | `<span style="color:red;">Red text</span>` |
| `<wbr>` | Word break opportunity (suggests line break). | `Super<wbr>longword` |

---


These HTML elements provide structure, formatting, and meaning to text-based content on web pages. Would you like an example combining multiple text elements in a webpage?




Most structured text consists of headings and paragraphs, whether you are reading a story, a newspaper, a college textbook, a magazine, etc.






### The HTML \<pre> Element

The HTML <pre> element defines preformatted text.

The text inside a <pre> element is displayed in a fixed-width font (usually Courier), and it preserves both spaces and line breaks:

<pre>
  My Bonnie lies over the ocean.

  My Bonnie lies over the sea.

  My Bonnie lies over the ocean.

  Oh, bring back my Bonnie to me.
</pre> 








### HTML Formatting Elements

Formatting elements were designed to display special types of text:

    <b> 	Defines bold text
    <em> 	Defines emphasized text 
    <i> 	Defines a part of text in an alternate voice or mood
    <small> 	Defines smaller text
    <strong> 	Defines important text
    <sub> 	Defines subscripted text
    <sup> 	Defines superscripted text
    <ins> 	Defines inserted text
    <del> 	Defines deleted text
    <mark> 	Defines marked/highlighted text

    <abbr> 	Defines an abbreviation or acronym
    <address> 	Defines contact information for document author/owner
    <bdo> 	Defines the text direction
    <blockquote> 	Defines a section that is quoted from another source
    <cite> 	Defines the title of a work
    <q> 	Defines a short inline quotation




# HTML Headings

HTML headings are defined with the <h1> to <h6> tags.

\<h1> defines the most important heading. <h6> defines the least important heading: 

```html
<h1>This is heading 1</h1>
<h2>This is heading 2</h2>
<h3>This is heading 3</h3> 
```

Headings generally denote different sections of your document.
We have different levels of headings from H1 to H6.

\<h1> is highest level heading, the heading for the document.

It is recommended to have one \<h1> per page.
The \<h1> gets used by certain tools as they look at your page to understand what the core content of the page is. 

The other levels you can use to segment your content into different sections and different hierarchies. 

These headings get rendered usually as a single line of text and with varying levels of font size and boldness or emphasis based on the level of the heading.
