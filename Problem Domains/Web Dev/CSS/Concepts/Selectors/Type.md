The CSS type selector matches elements by node name. In other words, it selects all elements of the given type within a document.


Syntax
```css
element { style properties }
```


```css
/* All <a> elements. */
a {
  color: red;
}
```

Type selectors can be namespaced when using @namespace. This is useful when dealing with documents containing multiple namespaces such as HTML with inline SVG or MathML, or XML that mixes multiple vocabularies.

    ns|h1 - matches <h1> elements in namespace ns
    *|h1 - matches all <h1> elements
    |h1 - matches all <h1> elements without any declared namespace
