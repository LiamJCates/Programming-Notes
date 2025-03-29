The **CSS type selector** (also called the **element selector**) is used to target HTML elements by their tag name. It applies styles to all instances of a specific element in the document.

### **Syntax**
```css
element {
    property: value;
}
```
- The selector is simply the name of the HTML tag you want to style.
- It applies the style to **all** matching elements.

### **Example**
#### **CSS:**
```css
p {
    color: green;
    font-size: 18px;
}
```
#### **HTML:**
```html
<p>This paragraph will be green and have a font size of 18px.</p>
<p>All paragraphs on the page will follow this style.</p>
```
In this example, **all `<p>` elements** on the page will have **green text** and a **font size of 18px**.

### **Key Features of the Type Selector**
1. **Applies to All Matching Elements** – Styles all elements of the specified type.
2. **Less Specific than Classes and IDs** – Can be overridden by class (`.class`) or ID (`#id`) selectors.
3. **Good for Global Styling** – Useful for setting default styles for common elements like headings, paragraphs, and buttons.

### **Example: Combining Type Selectors with Other Selectors**
```css
p.special {
    color: blue;
}
```
This targets only `<p>` elements **with class="special"**, overriding the general `p` selector.





Type selectors can be namespaced when using @namespace. This is useful when dealing with documents containing multiple namespaces such as HTML with inline SVG or MathML, or XML that mixes multiple vocabularies.

    ns|h1 - matches <h1> elements in namespace ns
    *|h1 - matches all <h1> elements
    |h1 - matches all <h1> elements without any declared namespace
