Course Overview

In this course, we're going to answer three questions.
Why should I choose React?
What tradeoffs are inherent in React's design, ecosystem, and philosophy?
Why shouldn't I choose React?

Some of the major topics that we'll cover include the many potential use cases for React, what sets React apart from its competition, key projects to consider in the React ecosystem, approaches to mitigating React's downsides, and the five key decisions that you need to make to get started.

By the end of this course, you'll understand React in its ecosystem at a high level, and you'll have a clear view of React's strengths, tradeoffs, and weaknesses.

If you're reading this, I assume that you're new to React, and you're looking for a short overview of what it is and why it has become so popular so that you can decide if React is right for your team.

This course consists of three short modules. In this first module, we'll explore what makes React special and worth choosing over the competition. In the next module, we'll discuss the tradeoffs inherent in React's design so that you can understand what you're getting and what you're giving up by choosing React. And I'll close out the course by considering common concerns that I hear about React and approaches for how to mitigate these concerns.



History

Facebook created React in 2011 for their own use on facebook.com, one of the highest trafficked websites in the world. React was then utilized by Instagram a year later in 2012. After already using React internally for two years, Facebook open sourced React in 2013. Some initially dismissed it because React ran contrary to popular practices by placing markup and logic together in a single file. But as more people experimented with the library, many embraced the new component‑centric philosophy for separating concerns.

Each React component is a separate concern.

A year later, in 2014, React had grown significantly in popularity and was embraced by many notable companies outside of Facebook. This popularity led Facebook to open source React Native too in 2015.

React Native is a related library that allows you to create native mobile applications for iOS and Android using React.

In April of 2016, React reached another significant milestone by publishing version 15. This was a notable release because the previous version was 0.14. Moving to 15.0 finally put React's semantic versioning scheme in sync with traditional semantic versioning practices, and it also helped convey that React was now a mature and stable platform with over five years of active development and heavy production usage to back it up.

Today, there are over 50,000 React components in production at Facebook. Facebook is deeply committed to React since it also uses React on Instagram and React Native for mobile development. Today, Facebook employs a full‑time React development staff that regularly releases bug fixes, enhancements, blog posts, and documentation. And as you'll see soon, many large, well‑respected Fortune 500 companies utilize React in production too.



Why React?

Why should I choose React over the long list of alternatives?

Six key reasons:
flexibility
developer experience
corporate commitment
community support
performance
testability

Reason 1: Flexibility

Perhaps the most compelling reason to choose React is once you learn it, you can build user interfaces for a huge variety of platforms and use cases. React is remarkably flexible.

React embeds fewer opinions than it's competition, so it's more flexible than opinionated frameworks like Angular and Ember. React is a library, not a framework. And as you're about to see, React's library approach has allowed it to evolve into a remarkably flexible tool.

When React was initially created, it had a single, focused use case. It was for creating components for web applications.

However, as React has grown in popularity, its ecosystem has grown to cover a variety of use cases:
	generate static sites with React using popular tools like Gatsby and Phenomic.
	build truly native mobile applications using React Native.
	Electron, allows creation of installable desktop apps that run on Mac and Windows using web technologies like React.
	supports server rendering out of the box, and popular frameworks like Next.js make it really easy to set up.
	use React to create virtual reality websites and 360 experiences with React VR.

In summary, learn React once, and you can write applications just about everywhere.

React is highly versatile because the renderer is separate from React itself:
	For web apps, you call react‑dom to render your components to HTML.
	For React Native, you use react‑native to render React components into native‑friendly code.
	react-vr is useful for rendering your React components into a virtual reality environment.

In fact, there are over a dozen different renderers for React:
https://github.com/chentsulin/awesome-react-renderer

React‑dom provides a simple function called renderToString that renders your component to a string of HTML.

	ReactDomServer.renderToString()

This is useful if you want to render your React components on the server. So this means you can use React to replace your traditional servier‑side rendering technologies. And there are multiple popular libraries that make it easy to render React components on the server, including Next.js, Gatsby, and Phenomic. You can also generate static content with these libraries as well, so you can easily use React to deploy plain HTML and JavaScript files to any host.

Since React is a lightweight library, you can use it with existing apps too, even server‑side rendered apps. In fact, that's precisely what React was designed for. Facebook used React to slowly replace its server‑side rendered PHP application. You can start with small portions of the page like this, then move on to slightly larger portions of the page, and eventually rebuild the entire page by slowly replacing larger sections with React. It's a low‑risk way to migrate an existing app to React or to use React in places where it's most valuable.

Finally, since React is used heavily by Facebook, you can trust that it will continue to run reliably in all popular browsers, including recent versions of Internet Explorer. Of course, Facebook can't afford to have its website only run on some browsers.



Reason 2: Developer Experience

The rapid feedback development experience combined with React's small, logical API creates a development experience that's very hard to beat. React is special because it offers a simple API that's easy to learn. There are very few concepts to master.

React's API is so small and straightforward that developers rarely need to check the docs. The entire API just fits in your head. Could this get simpler? It's basically a function that returns what looks like HTML.

import React from 'react';

function HelloWorld(props){
	return <div>Hello {props.name}</div>
}

With React components, you import React at the top using a standard JavaScript import statement. Then declare a component using a standard JavaScript function. The function receives variables via an object called props.


You can also declare a React component using a standard JavaScript class. This approach is slightly more typing, but gives you a little more power.

import React from 'react';

class HelloWorld extends React.Component{
	render() {
		return <div>Hello {props.name}</div>
	}
}

Now, you're likely wondering what's happening here inside this render function. It looks like HTML, but it's sitting in a JavaScript file. So, how does that work?


Well, that's called JSX.

<h1 color="red">Heading here</h1>

-->

React.createElement("h1", {color: "red"}, "Heading here")


As you can see, the JSX on top looks like HTML.

JSX compiles down to JavaScript. It becomes a call to React.createElement.

The function is passed:
	the name of the tag that you created
	an object that specifies the attributes you'd like to set
	the markup that should sit inside.

This final parameter contains calls to other elements if you have nested markup.

So you can avoid JSX if you want to write this JavaScript yourself, but, of course, I recommend using JSX since clearly the top is easier to read and nest.

Traditional libraries like Angular, Vue, and Ember seek to enhance the power of HTML by inventing their own syntax for simple operations like looping.

For example

Angular

<div *ngFor="let user of users">

Vue

<div v‑for="user in users">

Ember

{{ #each user in users}}

React went the exact opposite route. Instead of trying to make HTML more powerful, React just handles HTML with JavaScript. You don't need to learn new framework‑specific keywords, rules, and syntax for conditionals, looping, and so on. You just use JavaScript. JavaScript already has a built‑in function for iterating over an array called map,

{users.map(createUser)}

so in React, you just use plain JavaScript. Basically, traditional libraries put fake JavaScript in HTML, and React is doing the exact opposite. It puts fake HTML in JavaScript.

Many find React's approach preferable because it creates a simpler API.

React encourages you to get better at JavaScript, and in doing so, you also get better at React.

Using create‑react‑app is the most popular way to do React development today.
I just say create‑react‑app with the desired name for my app, and it creates a full working development environment on my machine. With a single command, npm start, it starts up a web server on my machine and serves my React app. In React, each component is atomic. It stands alone. This means you can work with each component in isolation, and every time I hit Save the changes are immediately reflected in the browser.

And here's the great thing. If you make a mistake, you receive a detailed error message in the browser. If I forget to close a tag within JSX, I get a compile time message about the precise line where I made a mistake. And if you need to debug your code, it's easy to set a breakpoint and view the original code in the browser. Through the power of source maps, you can see the original code that you wrote in your editor displayed within the browser. And everything I'm showing you here happens automatically with create‑react‑app.

Or you can use an online React editor like CodeSandbox to easily experiment with React, share your work, and even build your entire app. There's no configuration required. Just load the site and start coding. CodeSandbox makes it easy to experiment with React and share your work. When I'm trying an idea, I just load up this site and start coding. You can create multiple files, reference them, use modern JavaScript, and every time you hit a key, you see your changes reflected on the right.



Reason 3: Corporate Investment

Many well‑respected corporations are deeply invested in React and its ecosystem today. React was created by Facebook, so of course React is heavily used on Facebook, one of the highest trafficked apps in the world, as well as Facebook's other properties, such as Instagram and WhatsApp. Facebook is deeply committed to React. Although React is an open‑source project, four of the top six committers to the React project are current full‑time Facebook employees. And the Facebook Development Team maintains an active blog that consistently outlines the details of each release and plans for the future. Because of Facebook's deep existing commitment to React in production, when breaking changes occur in React, Facebook has consistently provided a codemod that automates the change. Now a codemod is a command line tool that you can point at your code base to automate changes. So with React codemod, you can automatically update older React components to the latest specifications. Over the years when breaking changes have occurred, the Facebook team has consistently published a codemod in order to automate updating to the latest version.

The beauty is we can feel confident about writing React components today because of Facebook's deep investment in the production React code means they must rely on the codemods that they create to update their own code. Codemods exist because Facebook needs them. Facebook has over 50,000 components in production. This is a benefit of using React because it helps assure that significant breaking changes in the future are highly unlikely. Doing so would require Facebook to deal with painful breaking changes to tens of thousands of their own components. This helps assure the project's long‑term stability



Reason 4: Community

The fourth reason to consider React is it boasts a huge active community. Since 2013, React's popularity has steadily grown to over 140,000 stars today. This makes React one of the most popular repositories on GitHub. Today, React has over 1000 contributors. In fact, out of over 3.5 million repositories, only two repos have more stars on GitHub than React. At the time of this recording, the React npm package is downloaded over 6 million times every single week. That's seriously impressive. On StackShare, a site where companies can share the technology that they're using, over 8,000 companies have reported using React. And React is the third most popular technology on StackShare. Facebook developers and a long list of open source React contributors are involved in ReactiFlux, an online community of over 80,000 React developers. And there are over 189,000 threads on Stack Overflow that are tagged ReactJS and around 100,000 threads on related technologies like React, React Native, React Router, and Redux. Now all of this matters because it adds up to a simple fact. If you're trying to do something in React, you can almost certainly find an example of it online. And hey, what developer doesn't love a little copy and paste now and then? It's pretty awesome being able to consistently get answers from other people who have run up against the same challenge that you're trying to solve. And that's because React is embraced by far more than just Facebook. Today, many of the world's most respected companies use React, including Apple, Netflix, Amazon, Airbnb, PayPal, and many more that you see here. Many of these companies regularly open source their React‑related work as well. So if you choose React, you're certainly in great company. And you don't need to create your own components since there's a huge list of free and mature component libraries online. Microsoft open sourced a large React component library for making user interfaces that have a look and feel like Office. It's called Fabric. Material‑UI offers a set of React components that implement Google's Material Design guidelines. React Bootstrap is a popular library that contains React components that make it easy to work with Bootstrap. And there are literally hundreds of interesting, standalone React components out there on GitHub that you might find useful. Check out the awesome‑react list on GitHub for a long list of additional components.

Deep community investment has led to a wide variety of mature, related projects. Do you need routing? Well, check out React Router. Do you want to handle complex data flows using a library? Well, Redux and MobX are two popular options to consider today. Do you want to set up automated testing? We'll check out Jest, which is also from Facebook. Want an alternative to RESTful API calls where you can declare your API calls on the client? Try out GraphQL. Want to quickly set up a server‑side rendered site in React with Node? Then try Next.js. Of course, this just scratches the surface of the ecosystem. This list could go on and on. So, uh, I guess you could say that React is kind of a big deal right now.



Reason 5: Performance

When React was first released, its performance was striking and helped set it apart from the competition. The React team recognized that JavaScript is fast, but it's the DOM that makes it feel slow. They realized that updating the DOM is expensive, so they found that updating the DOM in the most efficient way would help enhance performance. So behind the scenes, when you change data, React intelligently figures out the most efficient way to update the DOM. When React was created, years ago, this was a novel design that gave React a notable performance advantage in many cases. See, before React, most libraries would unintelligently update the DOM to reflect the new state. This often lead to redrawing a significant portion of the page, even when only a minor change had occurred. In contrast, React monitors the values of each component state. When a component state changes, React compares the existing DOM state to what the new DOM should look like. It then determines the least expensive way to update the DOM. This sounds complicated, but it's all handled automatically behind the scenes. And there are multiple benefits to this approach. It helps avoid layout thrashing, which is when a browser has to recalculate the position of everything when a DOM element changes. And being efficient is increasingly important in a world where many people are using mobile devices. Mobile devices vary widely in their CPU power, and conserving battery life is a concern as well. This also enables React simple programming model. When data changes, React efficiently updates the DOM automatically, and there's nothing extra that you have to do to enjoy this performance benefit. When you update the state of a component, it happens automatically. The comparison happens in memory, so it's typically very fast. Today, a variety of other libraries use a similar approach, but Reacts performance remains quite competitive. React offers various performance optimizations, but in my experience, they're rarely necessary. React is fast enough by default that many apps run great on the first try. Of course, the library size also has an impact on performance, too. React with React DOM weighs only 35k when G‑zipped and minified, so React lends itself well to bandwidth constraint use cases like mobile. It's significantly smaller than many of its competitors, but if you need the smallest library size possible, there are alternative React‑like libraries that you can consider using as well. Inferno is a lightweight React alternative that only weighs 9k, but has a very similar API to React. And Preact is even smaller, weighing in at only 3k. Both Preact and Inferno are extremely similar to React and utilize the same API. They just omit a few features to help keep the size down. So these are great options if the bundle size is a high priority for you. And it's easy to switch to these later, if desired.


Reason 6: Testability

Typically, testing a front end is hard, that's why so few teams do comprehensive front end testing, but React is attractive and noteworthy because its design is very friendly to automated testing.

Traditional UI testing is a hassle to configure. You have to carefully wire together multiple open source projects to get it to work. With React, there is little to no configuration required. In fact, if you use a popular boilerplate like create React app, testing is already configured for you out of the box. Traditional UI tests often require a browser, but you can reliably test your React components quickly in memory using Node. And while traditional browser‑based UI tests are often slow, testing React in memory on the command line is fast enough that you can quickly run a large test suite every time that you had save.

Traditional UI tests are brittle because they operate more like integration tests, but with React, you can write reliable, deterministic unit tests that test a single React component in isolation.

Finally, traditional UI tests are often time consuming to write and maintain because you have to carefully interact with the browser in the DOM to test the UI. In contrast, React tests can be written quickly using popular tools like Jest and Enzyme. You can easily update your tests too, in many cases, with a single keystroke after confirming that you're output was changed as expected. With React, the vast majority of your components can be plain pure functions. A pure function always returns the same output for a given input, it has no side effects. React's functional component style makes it trivial to test your component since it's pure. For example, if I set the message prop to world for this component, it will always output a div that contains the text, Hello World. It's reliable, deterministic, and it has no side effects. It relies upon no global state, and while this is a simple example, this design can scale the highly complex user interfaces. There is a wide variety of JavaScript testing frameworks available, and since React is just javascript, any one of these will work just great. But for React, the most popular choice today is Jest. Jest was created by Facebook and Jest makes it trivial to get started doing automated testing in React. Jest is built in to create React app. Every time you hit Save, it automatically runs any affected tests. This instant feedback can rapidly speed development. Jest also offers unique features like snapshot testing that make it easy to store a text‑based snapshot of your component's output. This way, if you accidentally change the way your component renders, you're immediately notified. Here, I'm using Jest to write an automated snapshot test. Note that I instantly see feedback on the command line as I hit Save, and it finds any new tests I write automatically since it looks for files that end in .test, .js, or .spec.js by default, no configuration required. And there are powerful and well‑documented libraries like React testing library that make it easy to manipulate and traverse your React components output. This allows you to write tests that interact with your React components to assure that they operate as expected, and you don't even need to open up a browser since the tests run in memory via Node.





Tradeoffs

Let's consider six key tradeoffs that you accept when you choose React. These are the key tradeoffs that the React development team made when designing React.

Trade Off						Decision
Framework						Library
Concise							Explicit
Template-centric		JavaScript-centric
Separate template		Non-standard
Community backed 		Corporate backed


Tradeoff 1: Framework vs. Library

Competitors like Angular and Ember are frameworks. React, in contrast, is generally considered a library since it's lean and focused on components.

Now a framework isn't fundamentally better than a library. It's a tradeoff. Here's a few advantages to choosing the framework approach.

A framework contains more opinions, so you can avoid spending time trying to choose between many options. This reduces decision fatigue, and there's often less setup overhead.

Frameworks can help enforce consistency since most frameworks are more opinionated. However, React's Library approach also has some clear advantages. At only around 35K Gzipped, React is significantly smaller than most frameworks. This means that it's small enough that you can sprinkle it on existing applications so that you can slowly migrate an existing app to React, even a server‑side rendered app. Imagine you have an existing app built in .NET, Java, Ruby, PHP, Python, whatever. Since React is small and flexible, you can replace a single component on the page with a React component.

React doesn't force many decisions on you.
It allows you to only pull in the features that you need to keep your app lean and fast. You're free to pick the precise technologies that you need for your project, and you're free to select the best technology for your use case as well. Decision fatigue is also largely a solved problem with React because opinionated boiler plates, like create‑react‑app, effectively turn React into an optional framework.

Now since React is a focused component library, more comprehensive frameworks like Angular come bundled with more features, including testing, a library for HTTP calls, routing, and internationalization all built in. In contrast with React, you select the pieces that apply to your use case and you add them in. Since React is very popular, there's almost certainly a mature library that does what you need.



Tradeoff 2: Concise vs. Explicit

The second trade‑off to consider is concise versus explicit. React trades conciseness for predictability and explicitness. You spend a little more time explicitly wiring things up together, but that helps them not fall apart. And it also helps people better understand what the code is doing. Here's a concrete example. Frameworks like Knockout and Angular popularized two‑way binding as a way to avoid typing by automatically keeping form inputs in sync with the underlying data. This approach was extremely popular until React came along. It was popular because it requires less coding. With two‑way binding, JavaScript values and inputs are automatically kept in sync. In contrast, React embraces one‑way binding instead. It requires a little more code. With React, you declare an explicit change handler, and you reference it on your input. This extra work has some benefits. You have more control because you can declare precisely what should happen on every event. This means you can transform and validate input before updating state and perform performance optimizations as desired. Your code is more explicit since you clearly state what you want to happen when an event occurs. And this makes it easy to understand and debug when an error happens. Although React helped repopularize doing one‑way binding, other popular libraries like Angular have shifted gears and embrace it as well today for these reasons. Now, if your team strongly prefers two‑way binding, you can use libraries that add it to React, but for the reasons I just mentioned, few do so, and I don't recommend it. Also, don't worry. You don't need to declare a separate change handler for each input. There are simple patterns for centralizing your change handlers in React, as I show in my other React courses. So in the real world, the amount of code that you write in React isn't substantially larger because of one‑way binding because you typically have a single change handler for an entire form. In summary, here's the trade‑off. React requires more typing to implement than traditional two‑way binding approaches, but with the benefit of easier maintenance, greater clarity, reliability, and performance.


Tradeoff 3: Template-centric vs. JavaScript-centric

The third trade‑off is template‑centric versus JavaScript‑centric. In a previous clip, I contrasted the template‑centric approach of traditional frameworks with React's JavaScript‑centric approach. Angular, Vue, and Ember seek to make HTML more powerful by inventing their own unique syntax for writing code in HTML. React takes the exact opposite approach and instead utilizes the power of JavaScript to handle HTML. This fundamental difference is what makes React so elegant. Let's consider simple if logic for conditionally showing an h1 tag when a Boolean called isAdmin is true. Here I'm using Angular's unique ngIf directive, which must be prefixed with an asterisk. My conditional is written inside a string. With Vue, I use v‑if and again declare my conditional inside of a string. Ember also uses a unique syntax that looks a bit like JavaScript, but with no parentheses, and the entire statement must be wrapped in double curly braces. With React, I can use JavaScript's logical and operator. If you're not familiar with it, the right‑hand side only runs when the left‑hand side is true. So, Hi Admin will only display when isAdmin is true. And since the code I'm writing inside the curly braces is ultimately just JavaScript in a JS file, any editor will provide autocomplete support along the way as I type and reference my functions. If I make a typo, I'll see warnings in my editor if I reference a variable that doesn't exist. Now let's consider writing a loop in each technology. With Angular, you say *ngFor, then use a syntax that looks a bit like JS, but is declared inside a string. Vue is similar, but a little less typing. Again, you write your looping code inside a string. With Ember, you use Ember's #each helper, which is rather wordy compared to the others above. Finally, with React, you use JavaScript's built‑in map function and a plain JavaScript arrow function to display each username. So the only React‑specific syntax is the curly braces around user.name. So it's not just preferable because it's less code. It's preferable because the syntax is plain JavaScript. Finally, let's see how each handles clicking on a button. With Angular, you had parentheses around the event, and unlike traditional event handlers, you also put parentheses by the event handler name as though you're invoking it. This syntax wouldn't work if it were real JavaScript. With Vue, you use v‑on with a colon and the event name, or you can put an at sign at the front of click. Again, both of these are Vue‑specific syntax. Finally, with Ember, you specify a plain onclick, which is nice, but inside you use an Ember‑specific convention to tie the click to a specific action, which is declared via a string. Finally, with React, you declare an onClick handler. So, in React, you use the native click handler name, but it's CamelCased since React's JSX uses JavaScript casing rules. Otherwise, the only unique syntax is that you specify the function name inside a curly brace instead of in quotes. Place these together, and you can see the contrast. If you know JavaScript, then you know how to handle conditionals, looping, and events in React. This is why React's API is so small. So after seeing the comparisons, let's contrast the benefits of each approach. The benefit of the template approach is that it requires less JavaScript knowledge. Template languages provide a streamlined API for performing core functions. You focus on enhancing a template with framework‑specific syntax. And these unique syntaxes have some advantages, like avoiding the confusion that's often caused by JavaScripts this keyword behavior. This makes templates more approachable for developers who are new to JavaScript. And in theory, a template language is preferable because of a principle called the rule of least power. It's counterintuitive, but less powerful languages can theoretically be preferable because they can protect from misuse by only allowing the user to perform a small set of prescribed operations. For example, Angular's template syntax only supports a selected subset of JavaScript‑like expressions. This helps avoid misuse. Of course, there's an obvious downside that we just saw, which is that the template‑centric approach leads to framework‑specific syntax. To get good at template‑centric libraries like Angular and Vue, you must spend your time learning their specific syntax and rules for doing things that JavaScript can already handle. In contrast, React has very little unique syntax to learn. And since React embraces JavaScript, you don't have to learn a new vocabulary to describe the new features that other template‑centric libraries like Angular add to HTML. Most of what you write in React is really just plain JavaScript. This leads to less typing and less code, which I find produces a result that's easier to read and debug. Finally, React's JavaScript‑centric approach encourages improving your JavaScript skills. The list of features added to JavaScript in the last few years is significant. If your team isn't yet up to speed on the latest JavaScript features, it can take a while to get comfortable with all of this. But the great news is, once you do, you won't just be better at React, you'll be better at JavaScript forever more. In summary, to get better at React, you mostly need to learn modern JavaScript, and this is great because it means your skills will transfer to all other JavaScript code that you write, even if you move away from React in the future.

Tradeoff 4: Separate vs. Single File

The fourth trade‑off is a separate template versus a single file per component.

Patterns like MVC popularized separating the model, view, and controller into three separate files.

Traditionally, for web apps, this means that
	the view is HTML.
	The model declares the data for the view in JavaScript
	the controller controls the interactions with the model.

In contrast, with React, each component is an autonomous concern. Each component stands on its own and can be composed with other components to build rich, complex UIs. This means markup and logic are collocated in the same file.

When React was introduced in 2013, people were very skeptical, and for good reason. React's design ran against the current best practice of placing HTML templates and JavaScript logic in separate files.

In React, each component contains both logic and markup in the same file, so on the surface, this feels like it violates the principle of separation of concerns. However, in React, you think about separation of concerns differently. Traditional separation of concerns often fixates on placing each technology in a separate file. So in web development, this means placing HTML, CSS, and JS in separate files. But React recognizes that while these are indeed separate technologies, they must be carefully composed together to do anything useful. So in React, each component is a separate concern. Examples include a button, a date picker, an accordion, or a text input. Each of these components is a separate concern. It will often embed logic, styling, and markup concerns because JavaScript, CSS, and JSX work together to create a useful component. In my experience, placing such intertwined concerns in separate files actually hinders debugging and slows feedback because you have to mentally keep these separate files in sync. And, of course, by composing small, simple components together, you can create more complex components like contact forms, customer details, and so on. In my experience, components are the common concern worth separating. The old mindset of separating HTML, JavaScript, and CSS into separate files merely separated technologies, but their concerns and interactions are actually fundamentally intertwined. If you change one file, it often requires corresponding changes to other files. Oh, and you're not forced to handle styling in the same file. With React, you're free to handle CSS in a traditional separate CSS file, if you prefer. Think of component composition like Russian dolls. Russian dolls are interesting because each doll can hold a smaller doll inside. React's component model works the same way. Simple, reusable components can be composed together to build rich, complex user interfaces. With React, you can think of the page as a set of nested components. Consider an author page on pluralsight.com. We could build this page in React by creating simple components like a star rating, an author photo, a navigation link, and so on. Then we could compose those simple components together to make the course summary, the author summary, or the sidebar navigation. Finally, we could compose those larger components together to create even larger components like author courses. When you see all this displayed at the same time, you can see how the small components in orange are used as part of the larger components in blue, and the larger components in blue, like the course summary, are composed together to create large portions of the app in green, like the author courses. As you can see, React's component approach lends itself well to building complex Uis by breaking your page down into small, autonomous pieces that you can reason about and test in isolation.


Tradeoff 5: Standard vs. Non-standard

The fifth tradeoff is standard versus non‑standard. React is just one of many non‑standard component libraries, but the web component standard has actually been around for years without much usage yet. So why aren't many people building apps with standardized web components yet? Well, first, let's review what the web component standard is. The web component standard exists of four core technologies, templates which contained markup, custom elements, which allow you to expand HTML with your own custom elements, the shadow DOM, which encapsulates styling to avoid your styles leaking outside of your component, and imports, which bundle everything together into a single line that you can import onto the page. I published HTML5 Web Component Fundamentals in 2015, and I remain hopeful about standardized HTML components. But unfortunately, the standard has yet to be embraced much by the development community. Today, most developers continue to use libraries like Angular, Vue, and React instead. So the big question is, why hasn't the web component standard taken off yet? Well, likely the biggest reason that people aren't using plain web components is browser support remains spotty. The template tag isn't supported in any versions of Internet Explorer, HTML imports are only supported in Chrome, Opera, and Android, custom elements are only supported in Chrome, Opera, and some of the newest Android browsers, and it's pretty much the same sad story with the shadow DOM. After years of waiting, it's become clear that browser vendors have shown little interest in implementing the full suite of HTML5 web component features. So you need to add polyfills to make it all work cross‑browser. And once you're pulling in extra JavaScript, you have to ask why you're choosing an unpopular and poorly supported standard like web components instead of an extremely popular technology like React. Second, web components no longer enable anything new. Everything that you can do in web components can be accomplished today in a cross‑browser friendly way using a variety of modern JavaScript libraries, including React. Let's consider the core features of the web component standard and contrast them with React. Web components have templates for holding your markup, and in React, you use JSX to declare your markup along with plain JavaScript. Web components allow you to expand HTML by declaring custom elements. React components accomplished that same thing. The shadow DOM lets you encapsulate your styles within your web component. Various technologies, like CSS modules, CSS in JS, and even React's built‑in inline styles, assure that your styles are encapsulated automatically. Finally, web components offer HTML imports for bundling the component together into a single import. With React, each component is a single file, so you can always import it via a single line import. So in summary, web components enable nothing new compared to React today. The third reason web components aren't taking off is JavaScript libraries like React, Angular, and Vue offer compelling component stories that continue to improve. It's both difficult and unlikely for standards bodies to be able to keep up with the pace of JavaScript innovation. Today, modern libraries offer a number of compelling features for binding, bundling, packing, and testing JavaScript‑based components. Finally, since web components utilize standards built into a web browser, you can't use them elsewhere like on native mobile. React in contrast works on mobile and virtual reality too, as well as a number of other interesting platforms. In summary, the web component standard may take off at some point, but currently the majority of developers continue to reach for the tools on the right because they're innovating more quickly, offer a strong user experience, and run reliably cross‑browser today.
Tradeoff 6: Community vs. Corporate

The final trade‑off we'll consider is community versus corporate backing. Many popular open source JavaScript projects are community driven. React is an open source project, but it's backed and actively maintained by Facebook. This means that React is driven by Facebook's needs. So if your apps are very different from what Facebook is building, React may not be ideal for your use case. But as I alluded to earlier, React's corporate backing has some clear benefits. Facebook provides React a full‑time development staff that carefully plans releases, writes documentation and blog posts, and provides ongoing support for issues on GitHub and often even on social media. Even though React has a full‑time staff, there are over 1,000 contributors to React, so the community is vibrant and engaged. Facebook is currently wildly successful. At the time of this recording, it's the fifth most valuable company in the world, with a market capitalization of $445 billion. Even if Facebook were no longer involved in React, the project would certainly live on without full‑time Facebook involvement for the foreseeable future. Plus, many competitors lack the benefit of a full‑time corporate development staff that React boasts today. So while React's corporate tie is a potential concern, it's also a significant benefit for support and ongoing development for the foreseeable future. Finally, as I mentioned earlier, Facebook is deeply invested in React with over 50,000 components in production. So as long as Facebook is around, they're likely to continue providing significant ongoing React support. And that's it. Those are the trade‑offs to consider with React. Let's close out this module with short summary.
Summary

In this module, we looked at six tradeoffs to consider with React. Frameworks offer more opinion and standardization, but React's library approach allows you to select only the tools that you need and pick the best tools for your use case. Other frameworks strive to be concise, using techniques like two‑way binding and abstractions over JavaScript operations. But React is explicit, so code is more readable and scalable at the admitted expense of doing a little more typing on the keyboard. React chooses to be JavaScript‑centric instead of template‑centric. React's JavaScript‑centric approach is easier to understand and debug and requires learning less unique syntax, but at the cost of requiring modern JavaScript knowledge. Many frameworks utilize a separate template file. In contrast, each React component is a single autonomous file that you can work with and test in isolation. The web component standard has been around for years, yet it continues to lack broad adoption. Non‑standard approaches, like React and Angular, remain more popular because they offer the same power, more rapid innovation, and a superior developer experience. And React is corporate‑backed, which means its design is influenced by Facebook's needs. But Facebook continues to accept input from the community and has evolved React into a highly flexible and well‑supported system. Of course, with tradeoffs, there's no right answer. But at least now you understand what you're getting and what you're giving up with each of these tradeoffs. In the next module, I'll be even more critical. Let's explore the common concerns that I hear about with React so that you can decide if the downsides that other people talk about matter to you.


Why Not React?
Intro

React common concerns:
	JSX differs from HTML.
	React requires a build step.
	There's a potential for version conflicts.
	And React has evolved over time, so you'll find references to old features when searching the Web.
	And since React is a lightweight library, you may feel intimidated by the number of decisions you need to make up front.

Oh, and you might have heard that React's license has a patent clause, that's no longer an issue. With the release of React 16, Facebook re‑licensed React to use the standard MIT open source license.


Concern 1: HTML and JSX Differ

React uses an optional syntax that looks a lot like HTML called JSX.

It's optional because JSX needs to be compiled down to plain JavaScript so that the browser can understand it, so React developers are free to use JavaScript.

Most people prefer using JSX since it feels extremely similar to HTML, and it's easier to read.
JSX's syntax is 99% the same as HTML, but it does differ in a few ways, such as htmlFor instead of for and className instead of class. Inline styles are declared in JSON format. And finally, comments are handled in JavaScript style instead of HTML style. So as you can see, learning JSX's differences is trivial. The list of differences is quite short and thus easy to adopt.

Now maybe you're still worried, but I have a lot of existing HTML. Won't that be a hassle to convert into JSX? Well the good news is, that's easy. There are multiple ways to handle it. Honestly, since there are only a few differences between HTML and JSX, I typically convert existing HTML with a simple find and replace.

There's also an online HTML to JSX compiler and an npm package called htmltojsx that you can use.

If you have a lot of HTML to convert to JSX, you can convert it in bulk using the htmltojsx package on npm as a command line tool.


Concern 2: Build Step Required

As mentioned, you need to compile JSX down to plain JavaScript calls so that the browser can understand it. In practice, this is trivial to handle today. Frankly, worrying about needing a build step makes little sense today. These days, a build step is a critical part of just about any web application. No matter what JavaScript framework you're using, you're going to want to build step. You'll want to minify your code to save bandwidth. You'll want to transpile your code so that you can use modern JavaScript features today, even before your platform offers full support. And you'll want to lint your code and run your automated tests when you hit Save as well. So compiling JSX is just another thing that happens automatically along the way. Today's two most popular transpilers both work great with React, Babel and TypeScript, and both allow you to use modern JavaScript features today, even before all browsers offer full support. And, most importantly for React developers, both transpile React's JSX for you. And there are a variety of React boilerplates that make it easy to get started and have build steps built in automatically to transpile JSX for you. create‑react‑app, which I have mentioned earlier, is the most popular option today, and it also minifies and bundles your code and even includes automated testing support so you don't even need to configure your development or production build environment to work with JSX. This all just happens automatically.


Concern 3: Version Conflicts

The third concern is potential version conflicts. As I mentioned earlier, React with React DOM weighs only around 35K minified and gzipped. That's a very reasonable size, but there are some downsides to having a runtime at all. See, you can't run two versions of React at the same time on the same page, so this means that you need to keep your React components on the same version for a given page. In contrast, if you build standardized web components, you don't have to worry about version conflicts at all since there's no runtime. Standard web components just leverage the support that's built right into the browser. However, for reasons I outlined in a previous module, I still prefer working in React over using plain web components. And that's partially because the web component standard lacks features that I've grown to know and love from React and other frameworks, like efficient DOM updates, reactive data binding, and more. So, there are other interesting tools to consider, like skatejs, Svelte, and Stencil, which bring those features to web components without the need for a framework. These options are interesting because they leverage the web component standard, but add extra features. They also embed the runtime within each component, so you don't need to worry about version conflicts. And since React is a lean component library, you will often choose to use related libraries with React, such as React Router, so you need to run compatible versions. This means that you typically need to run a recent version of React to avoid a version conflict. In practice, though, I found version conflicts are rarely a problem in React. Since Facebook has been consistent about releasing code mods when breaking releases occur, upgrades to your existing React components can typically be easily automated. Here are three tips to avoid version conflicts. First, agree is a team which version of React you're working with. Second, upgrade React when you're upgrading related libraries. And finally, on the rare instances where there are breaking changes in a future release, decide as a team when to upgrade.

Concern 4: Outdated Resources Online

The fourth concern is old stuff showing up in searches. React is a large, mature community, and it has evolved since it was open sourced in 2013. Search for the term React example on Google, and you'll get over 300 million results. There are over 189,000 threads tagged with React on Stack Overflow and around 100,000 threads on related technologies like React, React Native, React Router, and Redux. And there are thousands of blog posts out there on blogging platforms like Medium and dev.to that cover React and related technologies. And hey, having many great resources online is a great thing, right? Absolutely. But there's an obvious risk. Some of this public content is outdated. React has evolved since it was released in 2013, so as you search around the web, you'll see some patterns that are no longer popular today. So what has changed? Well, recently, features have been extracted from React Core to keep the library lean and simple. Since React is used for more than just the web now, React DOM was extracted to a separate package, so you'll see many posts using the style on the left, but today reference the separate React DOM library for web development. And if you're doing development for other platforms, you'll import the renderer that's appropriate for that platform, such as React Native. Second, since most people are using ES classes today, React.createClass was extracted to a separate library called create‑react‑class. So you need to reference this separate library if you want to declare React components using the createClass style. And since only some teams choose to use PropTypes over alternatives like TypeScript and Flow, the prop‑types library was extracted to a separate npm package too, so you'll need to install the prop‑types library and import it like you see here on the right. Finally, mix‑ins were initially a popular way to share functionality between components in React. However, mix‑ins are no longer part of React Core. Today, React's Hooks are the most popular way to share logic across components. Of course, when in doubt, check React's documentation. It's excellent, up to date, and actively maintained by Facebook.
Concern 5: Decision Fatigue

The fifth and final concern is decision fatigue. React is lightweight and unopinionated, so there are multiple ways to do some of the same things. Okay, I'm about to run through a few decisions, but keep in mind one can view having many decisions as a glass half empty or a glass half full. I like having lots of options because it means that I can set things up in a way that's perfect for my team's unique needs and preferences, so I see React's rich ecosystem as a big win. Getting started in React can feel intimidating, so let me break this down for you. There's really five key decisions to make up front, your development environment, whether to use classes or functions, and how to handle types, state, and styling. Let's quickly walk through these five decisions. The first decision is a development environment. There are over 100 boilerplate projects available on GitHub, and Andrew Farmer was nice enough to create a searchable list of React boilerplates on his website. You can search through the list for things that you want and things that you don't. When starting React, this tool is a handy way to see all the different ways that you could choose to configure your team's React development approach. But I recommend starting with create‑react‑app, which is the official development environment that's supported by Facebook. This is a mature platform for rapidly creating react applications. This project includes automated testing, transpiling, bundling, linting, and an automated build process all set up and ready to go. And in a poll of over 2000 React developers, 65% use create‑react‑app. The next largest group of 25% chooses to build their own dev environment. I show how to build your own environment in my React and Redux course. And if you're wanting to build a native mobile app with React, I suggest using create‑react‑native‑app. Now, admittedly, create‑react‑app doesn't include all of your decisions baked in. For example, related libraries like React Router for routing or Redux for state management aren't included in create‑react‑app. But you don't need these to get started, so look into these related libraries later. On decision two, you need to decide whether to declare your components via classes or functions. Here's what the two approaches look like side by side. You can accomplish the same things in both, but today, most React developers prefer declaring React components as functions. The function syntax is more concise, and it tends to help avoid bugs. So for new development, I suggest using functions. That said, I show both class and function approaches in my React and Flux course and my React and Redux course. There are three popular ways to handle types: React PropTypes, TypeScript, and Flow. To see the difference between these options, let's consider a simple component called Greeting. With PropTypes, you can declare the types of the data that are passed into your component. Here, I'm declaring that the name passed into the Greeting component is a string. With PropTypes, types are checked only at runtime and only during development. TypeScript is the second option. It's a popular project from Microsoft. TypeScript is a superset of JavaScript that adds strong typing support and compiles down to plain JavaScript. TypeScript will feel very familiar it anyone who has coded in C# or Java. Here I'm using an interface to declare the type for the Greeting component's Props, and I'm saying the Props argument getting passed into my Greeting component has a type of Props. Unlike PropTypes, TypeScript checks types at compile time, so you find out earlier about any potential type issues. The third option is Flow, a project from Facebook for adding static type checking to your JavaScript. Flow provides type safety in a different way than TypeScript. With Flow, you add type annotations to plain JavaScript, and Flow intelligently infers types throughout your codebase. With Flow, you annotate the top of each file that you'd like it to check. Here, I'm declaring my type above the component, then specifying the type within the argument. Flow will process plain JavaScript without type annotations, and it will infer those types or, in other words, flow through your code. Now, Flow runs as a separate process, so types can be checked whenever you choose to run Flow. I recommend PropTypes for developers getting started with React. PropTypes are simple to implement, trivial to learn, and require no special configuration. But if you already know TypeScript, it's also a great option. Create‑react‑app has TypeScript support built in, so it's easy to get started. And as you can see in this Twitter poll, Typescript is quite popular in the React community today. React works great alone, but many developers prefer to enhance React with popular third‑party state libraries. Now what do I mean by state? Well, simple. State is your app's data. Popular ways to handle state in React include plain React, Flux, Redux, and MobX. React handles state great all by itself, so these other libraries are totally optional. With plain React, your components handle state on their own. But shortly after React was open sourced, Facebook also released Flux as an optional way to handle state in React. Flux is still heavily used by Facebook, and it centralizes your application's state. But today, Redux is the most popular state management library for working in React. Like Flux, with Redux, your app's data is centralized, but Redux offers a more elegant approach than Flux and uses an immutable data store. Finally, MobX is a lighter weight alternative to Redux, but with a fundamentally different take on state management. MobX uses observable data structures. In short, Redux is more explicit and scalable, but MobX requires less code and is easier to learn. That said, I want to emphasize React works great all alone. You can build applications using just plain React. You often don't need a separate state management library like Redux. I recommend starting with plain React. Don't feel obligated to immediately learn and use Redux or MobX. You can build powerful apps using just React by itself. And this final decision is where it gets a little silly. There are over 50 different styling approaches that you could potentially use with React, but really, React works great with traditional CSS, Sass, and Less too, so my suggestion is just get started by using whatever you know today. And in fact, the majority of React developers continue to use traditional styling approaches with React. After you've gotten comfortable with React, if you're curious about the styling options, I explore them in detail in my Creating Reusable React Components course. So in summary, yes, the benefit of React being a lightweight library is that you have options, but the obvious downside is the number of options can feel intimidating, so I'd encourage you to use these recommendations as a starting point for standardizing your approach. And don't let these decisions intimidate you. The implications of these decisions are really mostly minor anyway. Okay, let me wrap up the course by suggesting some next steps.


Next Steps

Pluralsight offers a suggested React Learning Path with beginner, intermediate, and advanced courses. If you aren't yet up to speed on modern JavaScript, check out React Fundamentals and Building Applications with React and Flux. Both teach React using React's create class syntax and plain ES5 JavaScript. If you're comfortable with modern JavaScript or ready to learn by example, check out React.js: Getting Started. After that, you're ready for courses on React router and Redux, techniques for writing scalable React apps, steps for building your own React development environment, styling your React components, automated testing, and much more. And don't feel constrained to the React Learning Path. There are over a dozen great React courses on Pluralsight on related topics such as React Native, Relay, and GraphQL. So there is plenty to explore. Let's close out this course with a quick module summary.
Summary

In this module, we considered the common concerns that I hear about React today. Yes, JSX differs from HTML in some minor ways, but it's easy to convert using find and replace or handy existing tools. React typically requires a build step to compile JSX, but any modern JavaScript app should have a build step anyway to handle minification, bundling, and so on. And all popular React boilerplates, such as Create React App, automatically transpile JSX for you. You can only run one version of React on a given page, so there's a risk of version conflicts. But in practice, this isn't a big deal because it's easy to upgrade your React components to the latest version using Facebook's codemod project when necessary. Now since React is popular, you will stumble across old features and searches. So I noted the key changes that you should understand to avoid getting confused. Finally, decision fatigue is definitely a valid concern with React. So my suggestion is to start simple. Just use Create React App and my other recommendations to get started. They're the most popular approaches to doing React today. Add the complexity of other tools like Redux only as needed later.
