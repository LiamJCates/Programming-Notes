Script loading strategies

All the HTML on a page is loaded in the order in which it appears. If you are using JavaScript to manipulate elements on the page (or more accurately, the Document Object Model), your code won't work if the JavaScript is loaded and parsed before the HTML you are trying to do something to.

There are a few different strategies to make sure your JavaScript only runs after the HTML is parsed:

    In the internal JavaScript example above, the script element is placed at the bottom of the body of the document, and therefore only run after the rest of the HTML body is parsed.

    In the external JavaScript example above, the script element is placed in the head of the document, before the HTML body is parsed. But because we're using <script type="module">, the code is treated as a module and the browser waits for all HTML to be processed before executing JavaScript modules. (You could also place external scripts at the bottom of the body. But if there is a lot of HTML and the network is slow, it may take a lot of time before the browser can even start fetching and loading the script, so placing external scripts in the head is usually better.)

    If you still want to use non-module scripts in the document head, which could block the whole page from displaying, and could cause errors because it executes before the HTML is parsed:
        For external scripts, you should add the defer (or if you don't need the HTML to be ready, the async) attribute on the <script> element.
        For internal scripts, you should wrap the code in a DOMContentLoaded event listener.