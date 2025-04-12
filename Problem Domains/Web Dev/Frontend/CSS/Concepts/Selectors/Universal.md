The **CSS universal selector (`*`)** is used to select **all** elements on a webpage. It applies styles globally unless overridden by more specific selectors.  

### **Syntax**
```css
* {
    property: value;
}
```
- The `*` symbol targets **every element** in the document.
- It can be used alone or in combination with other selectors.

### **Example 1: Applying Styles to All Elements**
```css
* {
    margin: 0;
    padding: 0;
    box-sizing: border-box;
}
```
This ensures that all elements have **no margin or padding** and use `box-sizing: border-box` to maintain consistent sizing.

### **Example 2: Universal Selector with Another Selector**
```css
div * {
    color: red;
}
```
- This selects **all elements inside a `<div>`**, making their text red.

### **Key Features of the Universal Selector**
1. **Applies to All Elements** – Useful for resetting default browser styles.
2. **Can Be Combined** – Works with other selectors for more specific targeting.
3. **Should Be Used Carefully** – Overusing it may cause performance issues in large projects.




The universal selector is a special type selector and can therefore be namespaced when using @namespace. This is useful when dealing with documents containing multiple namespaces such as HTML with inline SVG or MathML, or XML that mixes multiple vocabularies.

    ns|* - matches all elements in namespace ns
    *|* - matches all elements
    |* - matches all elements without any declared namespace


The asterisk is optional with simple selectors. For instance, *.classname and .classname are equivalent.