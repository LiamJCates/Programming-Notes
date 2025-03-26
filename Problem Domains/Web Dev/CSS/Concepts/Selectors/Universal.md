The CSS universal selector (*) matches elements of any type.

```css
/* Selects all elements */
* {
  color: green;
}
```

The universal selector is a special type selector and can therefore be namespaced when using @namespace. This is useful when dealing with documents containing multiple namespaces such as HTML with inline SVG or MathML, or XML that mixes multiple vocabularies.

    ns|* - matches all elements in namespace ns
    *|* - matches all elements
    |* - matches all elements without any declared namespace

Syntax

```css
* { style properties }
```

The asterisk is optional with simple selectors. For instance, *.warning and .warning are equivalent.