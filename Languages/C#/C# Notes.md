C# is a general-purpose, type-safe, object-oriented programming language.

The C# language is platform neutral and works with a range of platform-specific
runtimes.

The chief architect of the language since its first
version is Anders Hejlsberg (creator of Turbo Pascal and architect of Delphi).



Object Orientation

C# implements the object-orientation paradigm, 

this includes encapsulation, inheritance, and polymorphism. 

Encapsulation means creating a boundary around an object to separate its external (public) behavior from its internal (private) implementation details. Following are the distinctive features of C#
from an object-oriented perspective:

Unified type system
The fundamental building block in C# is an encapsulated unit of data and functions called a type. C# has a unified type system in which all types ultimately share a common base type. This means that all types, whether they represent
business objects or are primitive types such as numbers, share the same basic
functionality. For example, an instance of any type can be converted to a string
by calling its ToString method.
Classes and interfaces
In a traditional object-oriented paradigm, the only kind of type is a class. In C#,
there are several other kinds of types, one of which is an interface. An interface
is like a class that cannot hold data. This means that it can define only behavior
(and not state), which allows for multiple inheritance as well as a separation
between specification and implementation.
1
Properties, methods, and events
In the pure object-oriented paradigm, all functions are methods. In C#, meth‐
ods are only one kind of function member, which also includes properties and
events (there are others, too). Properties are function members that encapsulate
a piece of an object’s state, such as a button’s color or a label’s text. Events are
function members that simplify acting on object state changes.
Although C# is primarily an object-oriented language, it also borrows from the
functional programming paradigm; specifically:
Functions can be treated as values
Using delegates, C# allows functions to be passed as values to and from other
functions.
C# supports patterns for purity
Core to functional programming is avoiding the use of variables whose values
change, in favor of declarative patterns. C# has key features to help with
those patterns, including the ability to write unnamed functions on the fly
that “capture” variables (lambda expressions) and the ability to perform list or
reactive programming via query expressions. C# also provides records, which
make it easy to write immutable (read-only) types.