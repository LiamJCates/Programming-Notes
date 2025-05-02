## ECMAScript Specification

JavaScript is standardized at ECMA International to deliver a standardized, international programming language based on JavaScript. 

The European association for standardizing information and communication systems (ECMA was formerly an acronym for the European Computer Manufacturers Association)

This standardized version of JavaScript, called ECMAScript, behaves the same way in all applications that support the standard. Companies can use the open standard language to develop their implementation of JavaScript. The ECMAScript standard is documented in the ECMA-262 specification.

The ECMA-262 standard is also approved by the ISO (International Organization for Standardization) as ISO-16262. You can also find the specification on the Ecma International website. The ECMAScript specification does not describe the Document Object Model (DOM), which is standardized by the World Wide Web Consortium (W3C) and/or WHATWG (Web Hypertext Application Technology Working Group)


### JavaScript documentation versus the ECMAScript specification

The ECMAScript specification is a set of requirements for implementing ECMAScript. It is useful if you want to implement standards-compliant language features in your ECMAScript implementation or engine (such as SpiderMonkey in Firefox, or V8 in Chrome).

The ECMAScript document is not intended to help script programmers. Use the JavaScript documentation for information when writing scripts.

The ECMAScript specification uses terminology and syntax that may be unfamiliar to a JavaScript programmer. Although the description of the language may differ in ECMAScript, the language itself remains the same. JavaScript supports all functionality outlined in the ECMAScript specification.

The JavaScript documentation describes aspects of the language that are appropriate for a JavaScript programmer.


### What falls under the ECMAScript scope?

Among other things, ECMAScript defines:

    Language syntax (parsing rules, keywords, control flow, object literal initialization, ...)
    Error handling mechanisms (throw, try...catch, ability to create user-defined Error types)
    Types (boolean, number, string, function, object, ...)
    A prototype-based inheritance mechanism
    Built-in objects and functions, including JSON, Math, Array methods, parseInt, decodeURI, etc.
    Strict mode
    A module system
    Basic memory model


### Versions

ES Next

    ESNext is a dynamic name that refers to whatever the next version is at the time of writing.
    ESNext features are more correctly called proposals, because, by definition, the specification has not been finalized yet.

ES2022

    Private Fields – learn how to define private fields in a class.
    Private Methods – show you how to define private methods in a class.
    Top-level await – explain top-level await module and its use cases.
    Array.prototype.at() method – guide you on how to use the Array.prototype.at() method to access array elements.

ES2021

    String.prototype.replaceAll() – replace all occurrences of a substring that matches a pattern with a new one.
    Logical Assignment Operators – introduce to you the logical assignment operators, including ||=, &&=, and ??=
    Numeric Separator– show you how to make the numbers more readable by using underscores as numeric separators.
    Promise.any() – learn how to use the JavaScript Promise.any() method to return the first Promise that fulfills.

ES2020

    Nullish coalescing operator (??) – accept two operands and return the right operand if the left one is null or undefined.
    Optional chaining operator (?.) – simplify the way to access a property located deep within a chain of connected objects without having to check if each reference in the chain is null or undefined.
    Promise.allSettled() – accept a list of promises and returns a new promise that resolves to an array of values, which were settled (either resolved or rejected) by the input promises.
    Dynamic import – show you how to import a module dynamically via the function-like object import().
    BigInt – introduce you to a new primitive type that can represent whole numbers bigger than 253 – 1, which is the largest number Javascript can reliably represent with the Number type.
    globalThis – provide a standard way to access the global object across environments.

ES2019

    Array.prototype.flat() – flatten an array recursively up to a specified depth.
    Array.prototype.flatMap() – execute a mapping function on every element and flatten the result. It is the combination of the map() followed by the flat() method.
    Object.fromEntries() – convert a list of key-value pairs to an Object.
    Optional catch binding – omit the catch binding when the binding would not be used.
    String.prototype.trimStart() – remove the leading whitespace characters of a string.
    String.prototype.trimEnd() – remove the ending whitespace characters of a string.

ES2018

    Object spread operator – use the spread operator ( ...) for objects.
    Promise.prototype.finally() – execute a piece of code when the promise is settled, regardless of its outcome.
    Asynchronous iterators – learn how to use async iterators to access asynchronous data sources sequentially.
    Async generators – show you how to create an async generator.

ES2017

    Padding a string – show you how to use a pair of methods:  padStart() and  padEnd() that allow you to pad a string with another string to a certain length.
    Object.values() – return own enumerable property’s values of an object as an array.
    Object.entries() – return own enumerable string-keyed property [key, value] pairs of an object.
    JavaScript async / await – write asynchronous code in a clearer syntax.

ES2016

    Exponentiation Operator   – introduce you to the exponentiation operator (**) that allows you to calculate a base to the exponent power, which is similar to Math.pow() method.
    Array includes()  – allow you to check if an element is in an array.

ES versions

The following table describes the editions and official names of ECMAScript:
Edition	Official name	Date published
ES12	ES2021	June 2020
ES11	ES2020	June 2020
ES10	ES2019	Summer 2019
ES9	ES2018	June 2018
ES8	ES2017	June 2017
ES7	ES2016	June 2016
ES6	ES2015	June 2015
ES5.1	ES5.1	June 2011
ES5	ES5	December 2009
ES4	ES4	Abandoned
ES3	ES3	December 1999
ES2	ES2	June 1998
ES1	ES1	June 1997