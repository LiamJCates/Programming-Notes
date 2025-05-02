Most runtime environments have implemented
the features covered here. Other wise, you can transpile them with Babel.js,
creating backward- compatible JavaScript that emulates the new features for
older runtimes.

https://en.wikipedia.org/wiki/Babel_(transcompiler)

Babel is a free and open-source JavaScript transcompiler that is mainly used to convert ECMAScript 2015+ (ES6+) code into backwards-compatible JavaScript code that can be run by older JavaScript engines. It allows web developers to take advantage of the newest features of the language.[4]

Developers can use new JavaScript language features by using Babel to convert their source code into versions of JavaScript that a Web browser can process.[5] Babel can also be used to compile TypeScript into JavaScript.[6] The core version of Babel was downloaded 5 million times a month in 2016, and this increased to 16 million times a week in 2019.[7][8]

Babel plugins transform syntax that is not widely supported into a backward-compatible version. For example, arrow functions, which are specified in ES6, are converted into regular function declarations.[9] Non-standard JavaScript syntax such as JSX can also be transformed.[10][11]

In software development, a polyfill is code that implements a new standard feature of a deployment environment within an old version of that environment that does not natively support the feature.

Babel can automatically inject polyfills provided by core-js[12] for support features that are missing entirely from JavaScript environments. For example, static methods such as Array.from and built-ins such as Promise are available only in ES6 and above, but they can be used in older environments if core-js is used. 

 