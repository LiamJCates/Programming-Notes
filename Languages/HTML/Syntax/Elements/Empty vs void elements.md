### **Difference Between Empty and Void HTML Tags**  

The terms **empty tags** and **void tags** are sometimes used interchangeably, but they have distinct meanings in HTML.

---

## **1️⃣ Empty HTML Tags**
**Definition:**  
Empty tags are **elements that do not have any content inside them**, but they can still have an opening and closing tag.

### **Example of Empty Tags**:
```html
<p></p>  <!-- Empty paragraph tag -->
<div></div>  <!-- Empty div tag -->
<span></span>  <!-- Empty span tag -->
```
- **These tags normally hold content** but are currently empty.
- They **can contain text or other elements** when needed.

---

## **2️⃣ Void HTML Tags**  
**Definition:**  
Void tags are **self-closing elements that do not have a closing tag** and **cannot contain any content** inside them. These tags are inherently empty because they **serve structural or functional purposes** (e.g., inserting images, line breaks, metadata, etc.).

### **Examples of Void Tags**:
```html
<img src="image.jpg" alt="Description">  <!-- Image tag -->
<br>  <!-- Line break -->
<hr>  <!-- Horizontal rule -->
<meta charset="UTF-8">  <!-- Metadata -->
<link rel="stylesheet" href="styles.css">  <!-- CSS link -->
<input type="text">  <!-- Input field -->
```
- **These tags do not and cannot contain any child elements or content**.
- **Self-closing syntax (`<tag />`) is optional in HTML5**, but mandatory in XHTML.

---

## **3️⃣ Key Differences Between Empty and Void Tags**
| Feature           | Empty Tags                   | Void Tags                   |
|------------------|----------------------------|-----------------------------|
| **Definition**   | Tags that currently contain no content but can hold content | Tags that are inherently empty and self-closing |
| **Closing Tag**  | Requires an opening and closing tag (`<tag></tag>`) | Does not have a closing tag (`<tag>` or `<tag />`) |
| **Content**      | Can contain text or child elements | Cannot contain any content or child elements |
| **Examples**     | `<p></p>`, `<div></div>`, `<span></span>` | `<img>`, `<br>`, `<meta>`, `<hr>`, `<input>` |

---

## **4️⃣ Example of Both in Action**
```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8"> <!-- Void tag -->
    <title>Empty vs Void Tags</title>
    <link rel="stylesheet" href="styles.css"> <!-- Void tag -->
</head>
<body>

    <p>This is a paragraph.</p> <!-- Not empty -->
    <p></p> <!-- Empty tag -->

    <img src="image.jpg" alt="Sample Image"> <!-- Void tag -->
    <br> <!-- Void tag -->

</body>
</html>
```

✅ **Empty tags** can hold content but currently don’t.  
✅ **Void tags** are inherently empty and self-closing.





Question



I've been writing HTML since the 90s, but I just found out about the colgroup and col elements. According to MDN, col is a void element and the end tag is forbidden.

    Tag omission: The start tag is mandatory, but, as it is a void element, the use of an end tag is forbidden.

I had never heard of a void element before. MDN doesn't have a page on void elements, but the empty element page says:

    Note: In very rare cases, empty elements are referred to as void elements. This is an improper name and should be avoided.

However, the W3 spec refers to void elements only and never mentions empty elements:

    A void element is an element whose content model never allows it to have contents under any circumstances. Void elements can have attributes.

So I'm wondering:

    If these are the same thing, should they be referred to as empty elements and never as void elements? In that case, is the W3 spec outdated and not to be trusted? Or should the W3 spec take precedence, even if it is outdated?
    If they are not the same thing, is <col span="2" /> valid syntax or should it be <col span="2"> (without the slash) because the end tag is forbidden? I may have the wrong idea of "end tag" but I've always thought of the /> (as in <br /> and <img />) to be an end tag of sorts.





Answer


The term "empty element" comes from SGML, on which HTML standards prior to HTML5 were based, and where the EMPTY keyword is used to represent elements with an empty content model. Here's what the HTML 4 spec says:

    The allowed content for an element is called its content model. Element types that are designed to have no content are called empty elements. The content model for such element types is declared using the keyword "EMPTY".

With an example declaration for the img element:

    This example illustrates the declaration of an empty element type:

    <!ELEMENT IMG - O EMPTY>

        The element type being declared is IMG.
        The hyphen and the following "O" indicate that the end tag can be omitted, but together with the content model "EMPTY", this is strengthened to the rule that the end tag must be omitted.
        The "EMPTY" keyword means that instances of this type must not have content.

XML defines an "empty element" quite differently:

    [Definition: An element with no content is said to be empty.]

The difference here is that XML does not say that an "empty element" is "an element whose content model is empty". Instead, it simply says that an "empty element" is one that has no content. This is regardless of whether or not the document type or XML schema defines that specific element to have no content by necessity; XML itself by nature places no such restrictions.

An additional term, "empty-element tag", is used to describe the shortcut syntax /> commonly used to indicate empty elements (again, regardless of whether or not they are empty by definition). This is also commonly referred to as "self-closing" syntax.

The term "void element" is new to HTML5. It has the same definition as the pre-HTML5 definition of "empty element": namely, an element that only has a start tag, no end tag, and cannot have any content whatsoever. Although the W3C HTML5 spec does not reference the term "empty element", the term "empty-element tag" as described in XML is used in a related document:

    In the HTML syntax, void elements are elements that always are empty and never have an end tag. All elements listed as void in the HTML specification or in an extension spec, MUST in polyglot markup have the syntactic form of an XML empty-element tag (<foo/>). Other elements MUST NOT use the XML empty-element tag syntax.

It seems that modern HTML standards now prefer the XML definition and eschew the former definition. This seems fitting, because modern HTML is no longer an SGML application, but a markup language in its own right. (It's not XML either, but that's where polyglot markup comes into play.)

So, to summarize:

    An empty element is one that has no content, regardless of whether it is allowed to have content in the first place.
    A void element is one that cannot have any content.

Additionally, it can be said that all void elements are empty elements by definition, but an empty element does not necessarily represent a void element.

In answer to your questions:

        If these are the same thing, should they be referred to as empty elements and never as void elements? In that case, is the W3 spec outdated and not to be trusted? Or should the W3 spec take precedence, even if it is outdated?

    Elements such as area, br, col and img are more accurately referred to as void elements, as in HTML5. They are considered empty as well, but only because they can't be "non-empty".

    I have no idea why MDN has an article that says "['Void elements'] is an improper name and should be avoided." when it uses the name in most of its HTML references anyway, never mind that such a statement directly contradicts the official specifications.

        If they are not the same thing, is <col span="2" /> valid syntax or should it be <col span="2"> (without the slash) because the end tag is forbidden? I may have the wrong idea of "end tag" but I've always thought of the /> (as in <br /> and <img />) to be an end tag of sorts.

    <col span="2" /> is only valid syntax because HTML5 recognizes it as a popular way of marking up void elements thanks to XHTML, and to disallow it would needlessly break validation compatibility with many XHTML documents that would otherwise validate as HTML5. HTML5 itself defines /> to be meaningless (with one specific exception that's not really relevant here), so in actuality <col span="2" /> in HTML5 simply represents a col with just a start tag and no end tag, and is therefore identical to <col span="2">, albeit XML-friendly.

