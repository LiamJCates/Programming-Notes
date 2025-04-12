Applying CSS and JavaScript to HTML

Just about all websites you'll use in the modern day will employ CSS to make them look cool, and JavaScript to power interactive functionality. 

These are most commonly applied to a web page using the \<link> element and the \<script> element, respectively.

The \<link> element should always go inside the head of your document. This takes two attributes, rel="stylesheet", which indicates that it is the document's stylesheet, and href, which contains the path to the stylesheet file:

```html
<link rel="stylesheet" href="my-css-file.css" />
```

The \<script> element should also go into the head, and should include a src attribute containing the path to the JavaScript you want to load, and defer, which basically instructs the browser to load the JavaScript after the page has finished parsing the HTML. This is useful as it makes sure that the HTML is all loaded before the JavaScript runs, so that you don't get errors resulting from JavaScript trying to access an HTML element that doesn't exist on the page yet. There are actually a number of ways to handle loading JavaScript on your page, but this is the most reliable one to use for modern browsers (for others, read Script loading strategies).

```html
<script src="my-js-file.js" defer></script>
```

If src is set, the script content is ignored.

A single \<script> tag can’t have both the src attribute and code inside.

This won’t work:

```html
<script src="file.js">
  alert(1); // the content is ignored, because src is set
</script>
```
We must choose either an external <script src="…"> or a regular <script> with code.

The example above can be split into two scripts to work:
```html
<script src="file.js"></script>
<script>
  alert(1);
</script>
```

### Modern markup

The \<script> tag has a few attributes that are rarely used nowadays but can still be found in old code:

The type attribute: <script type=…>

    The old HTML standard, HTML4, required a script to have a type. Usually it was type="text/javascript". It’s not required anymore. Also, the modern HTML standard totally changed the meaning of this attribute. Now, it can be used for JavaScript modules. But that’s an advanced topic, we’ll talk about modules in another part of the tutorial.
The language attribute: <script language=…>

    This attribute was meant to show the language of the script. This attribute no longer makes sense because JavaScript is the default language. There is no need to use it.
Comments before and after scripts.

    In really ancient books and guides, you may find comments inside <script> tags, like this:

<script type="text/javascript"><!--
    ...
//--></script>

This trick isn’t used in modern JavaScript. These comments hide JavaScript code from old browsers that didn’t know how to process the <script> tag. Since browsers released in the last 15 years don’t have this issue, this kind of comment can help you identify really old code.