 Using Classes

Classes should be used whenever you are applying CSS styles to multiple elements. Classes may be applied to different elements (e.g., both a <p> tag and a <h1> tag to set the same styles (e.g., font-family: Helvetica, Arial, serif;).

<h1 class="important-content">
  WPL Changes  
<h1>

<p class="important-content">
  Don't forget to check for any changes to the WPL schedule!
</p>

.important-content {
  font-style: italic;
  font-family: Helvetica, Arial, serif;
  text-transform: uppercase;
}

Using ID's

ID's should be used whenever you are applying CSS styles to a unique single element (e.g., a single <h2> tag). You may not use an ID on two of the same elements (nor two different elements).

<h2 id="announcements">
  Recent Announcements 
<h2>

<ul id="announcements">
  <li>Remember to read the syllabus!</li> 
<ul>

<h2 id="announcements-heading">
  Recent Announcements 
<h2>

<ul id="announcements-list">
  <li>Remember to read the syllabus!</li> 
<ul>

When to Use Classes vs. ID's (or Neither)

Choose appropriately between classes and ID's. If an element belongs to a general category that can include multiple elements, use a class. If it is a unique part of the page that deserved to be named on its own, use an ID.

Avoid Class-itis and ID-itis

Do not over-use classes and ids on elements that do not need them. If an equivalent style can be described cleanly using a CSS context selector such as .announcements li > strong rather than a class or id, consider doing that instead. A class or id is still more appropriate than a context selector if the context is very complicated or not really related to the styling.
