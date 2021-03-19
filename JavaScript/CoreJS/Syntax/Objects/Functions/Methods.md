Defining method functions
Getter and setter functions

You can define getters (accessor methods) and setters (mutator methods) on any standard built-in object or user-defined object that supports the addition of new properties. The syntax for defining getters and setters uses the object literal syntax.

get

    Binds an object property to a function that will be called when that property is looked up.
set
    Binds an object property to a function to be called when there is an attempt to set that property.

Method definition syntax

Starting with ECMAScript 2015, you are able to define own methods in a shorter syntax, similar to the getters and setters. See method definitions for more information.

var obj = {
  foo() {},
  bar() {}
};
