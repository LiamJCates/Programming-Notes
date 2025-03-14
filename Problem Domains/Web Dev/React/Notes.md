If you haven’t worked with JavaScript in the last few years, these three points should give you enough knowledge to feel comfortable reading the React documentation:

    We define variables with let and const statements. For the purposes of the React documentation, you can consider them equivalent to var.
    We use the class keyword to define JavaScript classes. There are two things worth remembering about them. Firstly, unlike with objects, you don't need to put commas between class method definitions. Secondly, unlike many other languages with classes, in JavaScript the value of this in a method depends on how it is called.
    We sometimes use => to define "arrow functions". They're like regular functions, but shorter. For example, x => x * 2 is roughly equivalent to function(x) { return x * 2; }. Importantly, arrow functions don't have their own this value so they're handy when you want to preserve the this value from an outer method definition.

Don't worry if this is too much to take in at once. The MDN JavaScript Reference is a stellar resource, and you can consult it whenever you get confused by something.

Also, when you feel unsure about what some newer syntax means, you can use the Babel REPL with the ES2015 preset to check what equivalent older syntax it compiles to.
