The **CSS class selector** is used to select and style elements that have a specific class attribute. It allows you to apply the same styles to multiple elements without affecting others.  

### **Syntax**
```css
.classname {
    property: value;
}
```
- The class name is prefixed with a **dot (`.`)**.
- It can be applied to multiple elements by assigning the class name in the HTML.

### **Example**
#### **CSS:**
```css
.highlight {
    color: red;
    font-weight: bold;
}
```
#### **HTML:**
```html
<p class="highlight">This text will be red and bold.</p>
<span class="highlight">This span will also be red and bold.</span>
```
Here, both the `<p>` and `<span>` elements share the same `highlight` class and will have **red, bold text**.

### **Key Features of Class Selectors**
1. **Reusability** – The same class can be used for multiple elements.
2. **Flexibility** – Unlike ID selectors (`#id`), which are unique, class selectors can be applied to multiple elements.
3. **Specificity** – Class selectors are more specific than element selectors but less specific than ID selectors.

