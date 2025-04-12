The **CSS ID selector** is used to apply styles to a single, unique element on a webpage. Unlike classes, which can be used on multiple elements, an ID should be assigned to only one element per page.

### **Syntax**
```css
#idname {
    property: value;
}
```
- The **ID name** is prefixed with a **hash (`#`)**.
- Each **ID should be unique** within an HTML document.

### **Example**
#### **CSS:**
```css
#main-title {
    color: blue;
    font-size: 24px;
    text-align: center;
}
```
#### **HTML:**
```html
<h1 id="main-title">Welcome to My Website</h1>
```
Here, the `<h1>` element with the **id="main-title"** will be styled with **blue color, a font size of 24px, and centered text**.

### **Key Features of ID Selectors**
1. **Uniqueness** – An ID should be used only once per page.
2. **Higher Specificity** – IDs have higher specificity than class and element selectors, meaning they override conflicting class styles.
3. **Best for Targeting Specific Elements** – Useful for unique page sections like navigation bars, headers, or footers.

### **ID vs. Class: When to Use What?**
| Feature       | ID Selector (`#id`) | Class Selector (`.class`) |
|--------------|------------------|------------------|
| **Usage**    | Unique element only | Multiple elements |
| **Specificity** | Higher | Lower |
| **Reusability** | Not reusable | Reusable |

Would you like an example that combines ID and class selectors?