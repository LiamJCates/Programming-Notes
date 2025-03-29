CSS Selectors

CSS selectors are used to "find" (or select) the HTML elements you want to style.




Here are the tables from [W3Schools' CSS Selectors Reference](https://www.w3schools.com/cssref/css_selectors.php), formatted for GitHub Markdown:


**CSS Simple Selectors**

| Selector | Example     | Description                               |
|----------|-------------|-------------------------------------------|
| `element` | `p`         | Selects all `<p>` elements               |
| `#id`     | `#firstname`| Selects the element with `id="firstname"`|
| `*`       | `*`         | Selects all elements                     |
| `.class`  | `.intro`    | Selects all elements with `class="intro"`|
| `element.class` | `p.intro` | Selects all `<p>` elements with `class="intro"` |

**CSS Grouping Selector**
| Selector | Example  | Description                                                                 |
|----------|----------|-----------------------------------------------------------------------------|
| `,` | `h1, h2, p`  | Selects all `<h1>` `<h2>` `<p>` elements |

**CSS Combinator Selectors**

| Selector | Example  | Description                                                                 |
|----------|----------|-----------------------------------------------------------------------------|
| ` ` (space) | `div p`  | Selects all `<p>` elements inside `<div>` elements (descendant combinator)|
| `>`      | `div > p` | Selects all `<p>` elements where the parent is a `<div>` element (child combinator)|
| `+`      | `div + p` | Selects the first `<p>` element that is placed immediately after `<div>` elements (adjacent sibling combinator)|
| `~`      | `div ~ p` | Selects all `<p>` elements that are next siblings of `<div>` elements (general sibling combinator)|



**CSS Nesting Selector**
| Selector | Example  | Description                                                                 |
|----------|----------|-----------------------------------------------------------------------------|
| `&` | `parentrule {css declarations; & childrule { css declarations; } }`  | Applies styles for an element within the context of another element |
 	 	



**CSS Attribute Selectors**

| Selector       | Example             | Description                                                                 |
|----------------|---------------------|-----------------------------------------------------------------------------|
| `[attribute]`  | `[target]`          | Selects all elements with a `target` attribute                              |
| `[attribute=value]` | `[target=_blank]` | Selects all elements with `target="_blank"`                                 |
| `[attribute~=value]` | `[title~=flower]` | Selects all elements with a `title` attribute containing the word "flower"  |
| `[attribute\|=value]` | `[lang\|=en]`      | Selects all elements with a `lang` attribute value equal to "en" or starting with "en-" |
| `[attribute^=value]` | `a[href^="https"]` | Selects all `<a>` elements with an `href` attribute value that starts with "https" |
| `[attribute$=value]` | `a[href$=".pdf"]`  | Selects all `<a>` elements with an `href` attribute value that ends with ".pdf" |
| `[attribute*=value]` | `a[href*="w3schools"]` | Selects all `<a>` elements with an `href` attribute value that contains "w3schools" |





**CSS Pseudo-element Selectors**

| Selector | Example        | Description                                           |
|----------|----------------|-------------------------------------------------------|
| `::before` | `p::before`   | Inserts content before every `<p>` element            |
| `::after`  | `p::after`    | Inserts content after every `<p>` element             |


**CSS Pseudo-class Selectors**

| Selector | Example  | Description                                                                 |
|----------|----------|-----------------------------------------------------------------------------|
| `:active` | `a:active` | Selects the active link |
| `:checked` | `input:checked` | Selects every checked `<input>` element |
| `:default` | `input:default` | Selects the default `<input>` element |
| `:disabled` | `input:disabled` | Selects every disabled `<input>` element |
| `:empty` | `p:empty` | Selects every `<p>` element that has no children |
| `:enabled` | `input:enabled` | Selects every enabled `<input>` element |
| `:first-child` | `p:first-child` | Selects every `<p>` element that is the first child of its parent |
| `::first-letter` | `p::first-letter` | Selects the first letter of every `<p>` element |
| `::first-line` | `p::first-line` | Selects the first line of every `<p>` element |
| `:first-of-type` | `p:first-of-type` | Selects every `<p>` element that is the first `<p>` of its parent |
| `:focus` | `input:focus` | Selects the input element which has focus |
| `:fullscreen` | `:fullscreen` | Selects the element that is in fullscreen mode |
| `:hover` | `a:hover` | Selects links on mouse over |
| `:in-range` | `input:in-range` | Selects input elements with a value in a specific range |
| `:indeterminate` | `input:indeterminate` | Selects input elements that are in an indeterminate state |
| `:invalid` | `input:invalid` | Selects all input elements with an invalid value |
| `:lang(language)` | `p:lang(it)` | Selects every `<p>` element with a lang attribute equal to "it" |
| `:last-child` | `p:last-child` | Selects every `<p>` element that is the last child of its parent |
| `:last-of-type` | `p:last-of-type` | Selects every `<p>` element that is the last `<p>` of its parent |
| `:link` | `a:link` | Selects all unvisited links |
| `:not(selector)` | `:not(p)` | Selects every element that is not a `<p>` element |
| `:nth-child(n)` | `p:nth-child(2)` | Selects every `<p>` element that is the second child of its parent |
| `:nth-last-child(n)` | `p:nth-last-child(2)` | Selects every `<p>` element that is the second child of its parent, counting from the last child |
| `:nth-last-of-type(n)` | `p:nth-last-of-type(2)` | Selects every `<p>` element that is the second `<p>` of its parent, counting from the last child |
| `:nth-of-type(n)` | `p:nth-of-type(2)` | Selects every `<p>` element that is the second `<p>` of its parent |
| `:only-of-type` | `p:only-of-type` | Selects every `<p>` element that is the only `<p>` of its parent |
| `:only-child` | `p:only-child` | Selects every `<p>` element that is the only child of its parent |
| `:optional` | `input:optional` | Selects input elements with no "required" attribute |
| `:out-of-range` | `input:out-of-range` | Selects input elements with a value outside a specified range |
| `::placeholder` | `input::placeholder` | Selects input elements with placeholder text |
| `:read-only` | `input:read-only` | Selects input elements with the "readonly" attribute specified |
| `:read-write` | `input:read-write` | Selects input elements with no "readonly" attribute |
| `:required` | `input:required` | Selects input elements with the "required" attribute specified |
| `:root` | `:root` | Selects the document's root element |
| `::selection` | `::selection` | Selects the portion of an element that is selected by a user |
| `:target` | `#news:target` | Selects the current active #news element (clicked on a URL containing that anchor name) |
| `:valid` | `input:valid` | 



Here are the tables from the W3Schools CSS Selectors Reference page, formatted for GitHub Markdown:







These tables summarize various CSS selectors and their usage as outlined in the W3Schools CSS Selectors Reference. 



https://www.w3schools.com/cssref/trysel.php