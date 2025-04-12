The **CSS grouping selector** allows you to apply the same style to multiple selectors by separating them with a **comma (,)**. This helps reduce redundancy in your stylesheets and makes the code more efficient and readable.

### **Syntax**
```css
selector1, selector2, selector3 {
    property: value;
}
```

### **Example**
```css
h1, h2, h3 {
    color: blue;
    font-family: Arial, sans-serif;
}
```
In this example:
- The `h1`, `h2`, and `h3` elements will all have **blue text** and use the **Arial** font.

### **Benefits of Using Grouping Selectors**
1. **Reduces Repetition** – Instead of writing the same styles multiple times for different elements, you can group them together.
2. **Improves Readability** – It makes your CSS cleaner and easier to maintain.
3. **Enhances Performance** – Less code means faster rendering and better performance.

