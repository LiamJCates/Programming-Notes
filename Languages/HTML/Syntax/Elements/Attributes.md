# HTML Attributes


All HTML elements can have attributes
Attributes provide additional information about elements
Attributes are always specified in the start tag
Attributes usually come in name/value pairs like: name="value"



### id

The id attribute specifies a unique id for an HTML element (the value must be unique within the HTML document).

The id attribute is most used to point to a style in a style sheet, and by JavaScript (via the HTML DOM) to manipulate the element with the specific id.

It can also be used as the target of a link.

The id attribute is a Global Attribute, and can be used on any HTML element.


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