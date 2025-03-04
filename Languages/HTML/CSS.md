# CSS

CSS can be added to HTML documents in 3 ways:

    Inline - by using the style attribute inside HTML elements
    Internal - by using a <style> element in the <head> section
    External - by using a <link> element to link to an external CSS file

The recommended way to add CSS is to keep the styles in external CSS files.


### Inline CSS

An inline CSS is used to apply a unique style to a single HTML element.

An inline CSS uses the style attribute of an HTML element.

The following example sets the text color of the <h1> element to blue, and the text color of the <p> element to red:
Example
<h1 style="color:blue;">A Blue Heading</h1>

<p style="color:red;">A red paragraph.</p>


### Internal CSS

An internal CSS is used to define a style for a single HTML page.

An internal CSS is defined in the <head> section of an HTML page, within a <style> element.

The following example sets the text color of ALL the <h1> elements (on that page) to blue, and the text color of ALL the <p> elements to red. 

In addition, the page will be displayed with a "powderblue" background color: 

Example
<!DOCTYPE html>
<html>
<head>
<style>
body {background-color: powderblue;}
h1   {color: blue;}
p    {color: red;}
</style>
</head>
<body>

<h1>This is a heading</h1>
<p>This is a paragraph.</p>

</body>
</html>


### External CSS

An external style sheet is used to define the style for many HTML pages.

To use an external style sheet, add a link to it in the <head> section of each HTML page:
Example
<!DOCTYPE html>
<html>
<head>
  <link rel="stylesheet" href="styles.css">
</head>
<body>

<h1>This is a heading</h1>
<p>This is a paragraph.</p>

</body>
</html>

The external style sheet can be written in any text editor. The file must not contain any HTML code, and must be saved with a .css extension.

Here is what the "styles.css" file looks like:

body {
  background-color: powderblue;
}
h1 {
  color: blue;
}
p {
  color: red;
}
