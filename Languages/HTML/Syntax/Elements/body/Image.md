Including Images
Understanding Images in HTML

how to
add images to a page
provide different image sources in order to give the best experience on those different devices.
use images different ways in your page.

image element, img
```html
<img
	src="example.png"
	alt="alternate hover text"
	height="200px"
	width"200px"
/>
```

attributes
src    tells the client or the browser the address of the image file.
usually relative to the HTML document that we're currently viewing.

alt    tells the client or the browser a text representation of the image. So if the browser can't display the image for some reason it can still display the text. If you mouse over a particular image in your document you'll see the alternate text.

height / width     control display sizing
keep in mind that this doesn't change the size of the image. So if you have a very large image, even though it might render smaller the browser still has to download that potentially very large file, which will slow down the performance of your web page for the user.



Defining Alternate Images

srcset         attribute which allows us to provide different sources, different files with the image in them, that will have different sizes. So one may be a much larger file both in terms of the actual image and the file size, and you may have one that's smaller for smaller devices or screens.

sizes    tells the browser when you render this I want you to make it relative to the viewport, that viewable area of the browser window.
