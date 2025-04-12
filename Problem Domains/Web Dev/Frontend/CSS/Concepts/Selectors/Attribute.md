The CSS attribute selector matches elements based on the element having a given attribute explicitly set, with options for defining an attribute value or substring value match.

```css
/* <a> elements with a title attribute */
a[title] {
  color: purple;
}

/* <a> elements with an href matching "https://example.org" */
a[href="https://example.org"]
{
  color: green;
}

/* <a> elements with an href containing "example" */
a[href*="example"] {
  font-size: 2em;
}

/* <a> elements with an href ending ".org", case-insensitive */
a[href$=".org" i] {
  font-style: italic;
}

/* <a> elements whose class attribute contains the word "logo" */
a[class~="logo"] {
  padding: 2px;
}
```

### Syntax

[attr]

    Represents elements with an attribute name of attr.
[attr=value]

    Represents elements with an attribute name of attr whose value is exactly value.
[attr~=value]

    Represents elements with an attribute name of attr whose value is a whitespace-separated list of words, one of which is exactly value.
[attr|=value]

    Represents elements with an attribute name of attr whose value can be exactly value or can begin with value immediately followed by a hyphen, - (U+002D). It is often used for language subcode matches.
[attr^=value]

    Represents elements with an attribute name of attr whose value is prefixed (preceded) by value.
[attr$=value]

    Represents elements with an attribute name of attr whose value is suffixed (followed) by value.
[attr*=value]

    Represents elements with an attribute name of attr whose value contains at least one occurrence of value within the string.

[attr operator value i]

    Adding an i (or I) before the closing bracket causes the value to be compared case-insensitively (for characters within the ASCII range).

[attr operator value s]

    Adding an s (or S) before the closing bracket causes the value to be compared case-sensitively (for characters within the ASCII range).

### Values

<attr>

    An <ident>, that is, the unquoted name of the attribute. This can be any valid language-specific attribute (SVG, HTML, XML, etc), a data-* attribute, or an author-created attribute.
<value>

    An <ident> or <string>, representing the attribute value. The value must be quoted if it contains spaces or special characters.
s or i

    Case sensitivity or insensitivity flag. If included before the closing bracket (]), makes the value case sensitive or insensitive, irrespective of the markup language.

### Description

The case sensitivity of attribute names and values depends on the document language. In HTML, attribute names are case-insensitive, as are spec-defined enumerated values. The case-insensitive HTML attribute values are listed in the HTML spec. For these attributes, the attribute value in the selector is case-insensitive, regardless of whether the value is invalid or the attribute for the element on which it is set is invalid.

If the attribute value is case-sensitive, like class, id, and data-* attributes, the attribute selector value match is case-sensitive. Attributes defined outside of the HTML specification, like role and aria-* attributes, are also case-sensitive. Case-sensitive attribute selectors can be made case-insensitive with the inclusion of the case-insensitive modifier (i).