JavaScript is the default scripting language in HTML.

## The <script> Tag

In HTML, JavaScript code is inserted between <script> and </script> tags.

<script>
	alert("My First JavaScript");
</script>

You can place any number of scripts in an HTML document.
You can place Scripts in the <body>, <head>, or both sections of an HTML page.

NOTE
Old JavaScript examples may use a type attribute:

	<script type="text/javascript">.

The type attribute is not required.




### JavaScript in <head>

In this example, a JavaScript function is placed in the <head> section of an HTML page.

The function is invoked (called) when a button is clicked:


<!DOCTYPE html>
<html>
	<head>
		<script>
			function myFunction() {
			  document.getElementById("demo").innerHTML = "Paragraph changed.";
			}
		</script>
	</head>
	<body>
		<h1>A Web Page</h1>
		<p id="demo">A Paragraph</p>
		<button type="button" onclick="myFunction()">Try it</button>
	</body>
</html>



### JavaScript in <body>

In this example, a JavaScript function is placed in the <body> section of an HTML page.

The function is invoked (called) when a button is clicked:

<!DOCTYPE html>
<html>
	<body>
		<h1>A Web Page</h1>
		<p id="demo">A Paragraph</p>
		<button type="button" onclick="myFunction()">Try it</button>

		<script>
			function myFunction() {
			  document.getElementById("demo").innerHTML = "Paragraph changed.";
			}
		</script>

	</body>
</html>


NOTE:
Placing scripts at the bottom of the <body> element improves the display speed, because script interpretation slows down the display.



## External JavaScript

Scripts can also be placed in external files:
External file: myScript.js

function myFunction() {
  document.getElementById("demo").innerHTML = "Paragraph changed.";
}

External scripts are practical when the same code is used in many different web pages.

JavaScript files have the file extension .js.

To use an external script, put the name of the script file in the src (source) attribute of a <script> tag:

<script src="myScript.js"></script>

You can place an external script reference in <head> or <body> as you like.

The script will behave as if it was located exactly where the <script> tag is located.

External scripts cannot contain <script> tags.



### External References

External scripts can be referenced with a full URL or with a path relative to the current web page.

This example uses a full URL to link to a script:

<script src="https://www.w3schools.com/js/myScript1.js"></script>

This example uses a script located in a specified folder on the current web site:

<script src="/js/myScript1.js"></script>

This example links to a script located in the same folder as the current page:

<script src="myScript1.js"></script>



### External JavaScript Advantages

Placing scripts in external files has some advantages:

    It separates HTML and code
    It makes HTML and JavaScript easier to read and maintain
		The same script file can be used by multiple pages
		Cached JavaScript files can speed up page loads

To add several script files to one page  - use several script tags:
Example
<script src="myScript1.js"></script>
<script src="myScript2.js"></script>
