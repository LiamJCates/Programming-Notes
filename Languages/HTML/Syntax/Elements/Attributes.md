# HTML Attributes


All HTML elements can have attributes
Attributes provide additional information about elements
Attributes won't appear in the content.
Attributes are always specified in the start tag
Attributes usually come in name/value pairs like: name="value"


An attribute should have:

    A space between it and the element name. (For an element with more than one attribute, the attributes should be separated by spaces too.)
    The attribute name, followed by an equal sign.
    An attribute value, wrapped with opening and closing quote marks.



### Boolean attributes

Sometimes you will see attributes written without values. This is entirely acceptable. These are called Boolean attributes. When a boolean attribute is written without a value, or with any value, even like "false", the boolean attribute is always set to true. Otherwise, if the attribute is not written in an HTML tag, the attribute is set to false. The spec requires the attribute's value to either be the empty string (including when the attribute has no value explicitly specified) or the same as the attribute's name, but other values work the same. For example, consider the disabled attribute, which you can assign to form input elements. (You use this to disable the form input elements so the user can't make entries. The disabled elements typically have a grayed-out appearance.) For example:
html

<input type="text" disabled="disabled" />

As shorthand, it is acceptable to write this as follows:
html

<!-- using the disabled attribute prevents the end user from entering text into the input box -->
<input type="text" disabled />

<!-- text input is allowed, as it doesn't contain the disabled attribute -->
<input type="text" />

For reference, the example above also includes a non-disabled form input element.




### Suggestion: Always Use Lowercase Attributes

The HTML standard does not require lowercase attribute names.

The title attribute (and all other attributes) can be written with uppercase or lowercase like title or TITLE.

However, W3C recommends lowercase attributes in HTML, and demands lowercase attributes for stricter document types like XHTML.




### Suggestion: Always Quote Attribute Values

The HTML standard does not require quotes around attribute values.

However, W3C recommends quotes in HTML, and demands quotes for stricter document types like XHTML.
Good:
<a href="https://www.w3schools.com/html/">Visit our HTML tutorial</a>
Bad:
<a href=https://www.w3schools.com/html/>Visit our HTML tutorial</a>

Sometimes you have to use quotes. This example will not display the title attribute correctly, because it contains a space:
Example
<p title=Description of W3Schools> 


Double quotes around attribute values are the most common in HTML, but single quotes can also be used.

In some situations, when the attribute value itself contains double quotes, it is necessary to use single quotes:
<p title='John "ShotGun" Nelson'>

Or vice versa:
<p title="John 'ShotGun' Nelson"> 




### Omitting quotes around attribute values

If you look at code for a lot of other sites, you might come across a number of strange markup styles, including attribute values without quotes. This is permitted in certain circumstances, but it can also break your markup in other circumstances. The element in the code snippet below, <a>, is called an anchor. Anchors enclose text and turn them into links. The href attribute specifies the web address the link points to. You can write this basic version below with only the href attribute, like this:
html

<a href=https://www.mozilla.org/>favorite website</a>

Anchors can also have a title attribute, a description of the linked page. However, as soon as we add the title in the same fashion as the href attribute there are problems:
html

<a href=https://www.mozilla.org/ title=The Mozilla homepage>favorite website</a>

As written above, the browser misinterprets the markup, mistaking the title attribute for three attributes: a title attribute with the value The, and two Boolean attributes, Mozilla and homepage. Obviously, this is not intended! It will cause errors or unexpected behavior.

Always include the attribute quotes. It avoids such problems, and results in more readable code.









Another common attribute is ID And you can also use name, but the name attribute is depricated.

\<p id="p1" name="p1n"\>
They don't have to be the same, but they can be.




Whereas the ID should be unique, elements should have unique IDs and unique names
ID and name would be unique on a particular element and those are often used with style sheets, as well as when we get into programming with JavaScript to identify a very particular element on the page that we want to do something with.




### id

The id attribute specifies a unique id for an HTML element (the value must be unique within the HTML document).

The id attribute is most used to point to a style in a style sheet, and by JavaScript (via the HTML DOM) to manipulate the element with the specific id.

It can also be used as the target of a link.

The id attribute is a Global Attribute, and can be used on any HTML element.



### class

A class can be uses on many different elements in the same page because it's a class of item.



### href

The <a> tag defines a hyperlink. The href attribute specifies the URL of the page the link goes to:

<a href="https://www.w3schools.com">Visit W3Schools</a>


### src

The <img> tag is used to embed an image in an HTML page. The src attribute specifies the path to the image to be displayed:
Example
<img src="img_girl.jpg">

There are two ways to specify the URL in the src attribute:

1. Absolute URL - Links to an external image that is hosted on another website. Example: src="https://www.w3schools.com/images/img_girl.jpg".

Notes: External images might be under copyright. If you do not get permission to use it, you may be in violation of copyright laws. In addition, you cannot control external images; it can suddenly be removed or changed.

2. Relative URL - Links to an image that is hosted within the website. Here, the URL does not include the domain name. If the URL begins without a slash, it will be relative to the current page. Example: src="img_girl.jpg". If the URL begins with a slash, it will be relative to the domain. Example: src="/images/img_girl.jpg".

Tip: It is almost always best to use relative URLs. They will not break if you change domain.




### alt

The required alt attribute for the <img> tag specifies an alternate text for an image, if the image for some reason cannot be displayed. This can be due to a slow connection, or an error in the src attribute, or if the user uses a screen reader.
Example
<img src="img_girl.jpg" alt="Girl with a jacket">
Example

See what happens if we try to display an image that does not exist:
<img src="img_typo.jpg" alt="Girl with a jacket"> 




### lang

You should always include the lang attribute inside the <html> tag, to declare the language of the Web page. This is meant to assist search engines and browsers.

The following example specifies English as the language:
<!DOCTYPE html>
<html lang="en">
<body>
...
</body>
</html>

Country codes can also be added to the language code in the lang attribute. So, the first two characters define the language of the HTML page, and the last two characters define the country.

The following example specifies English as the language and United States as the country:
<!DOCTYPE html>
<html lang="en-US">
<body>
...
</body>
</html>



The title Attribute

The title attribute defines some extra information about an element.

The value of the title attribute will be displayed as a tooltip when you mouse over the element:

<p title="I'm a tooltip">This is a paragraph.</p> 





