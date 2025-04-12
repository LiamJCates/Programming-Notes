Naming Conventions in HTML Class and ID Names

When giving an element an id or class, give it a descriptive name, such as main-heading or announcements.

Avoid one-letter names like x or c.

Letter-Casing and Special Characters

Always favor lowercase, for elements, for attributes and their values, for classes and ids. Multi-word names for classes and ids should either 1., concatenate the words in lowercase without any in-between character, or 2., separate each word with a "-" (not "_") and maintain lowercasing throughout. Regardless of whether you prefer convention 1. or convention 2., you should not switch between the two conventions (remember, consistency is key in web programming). No other special characters should be used for separating words, and there should never be capitalization of the next word.

Bad
<h1 id="first_heading"></h1>
<P Class="importantReminder"></P>

Good
<h1 id="mainheading"></h1>
<p class="importantreminder"></p>
<!-- or -->
<h1 id="main-heading"></h1>
<p class="important-reminder"></p>