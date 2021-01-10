For an overview of the Object Oriented programming paradigm see:
[Programming Methods\Paradigms\Imperative\Object-Oriented.md]

Object-oriented design is the discipline of defining the objects and their interactions to solve a problem.

Topics
  Classes
  Encapsulation
  Information Hiding
  Inheritance
  Polymorphism
  Modularity
  Generics
  Relationships
  Message Passing
  Class Design
  Design Process





















To make a method available outside the class, we can use the public keyword. A method that allows access from outside the class to retrieve private data is a getter. A method that allows access from outside the class to alter private data is a setter.

A natural question at this point is why we need to bother having these getters and setters. Why can't we just leave data public and let anyone read and change them as they want? The reason is that keeping the data private and controlling access to it through methods will give us control.

If a stranger walks up to you and asks for your name, you will have some options. You could respond with your actual name, you could tell them that it is none of their business, or you could lie and tell them a different name. You have control over the access to your private data, just as the class will have control over the access to its private data with the help of these methods.



Exactly how object-oriented programming is implemented differs from language to language. Languages that support object-orientation will also sometimes have slightly different rules for how object-orientation is used. As always, we will need to learn how the language we are using has defined the object-oriented principles.







Those that use classes support two main concepts:




Creation

calculate the size of an object - the size is mostly the same as that of the class but can vary. When the object in question is not derived from a class, but from a prototype instead, the size of an object is usually that of the internal data structure (a hash for instance) that holds its slots.
allocation - allocating memory space with the size of an object plus the growth later, if possible to know in advance
binding methods - this is usually either left to the class of the object, or is resolved at dispatch time, but nevertheless it is possible that some object models bind methods at creation time.
calling an initializing code (namely, constructor) of superclass
calling an initializing code of class being created


Inheritance

Inheritance should not be confused with subtyping.[3][4] In some languages inheritance and subtyping agree,[a] whereas in others they differ; in general, subtyping establishes an is-a relationship, whereas inheritance only reuses implementation and establishes a syntactic relationship, not necessarily a semantic relationship (inheritance does not ensure behavioral subtyping). To distinguish these concepts, subtyping is also known as interface inheritance, whereas inheritance as defined here is known as implementation inheritance or code inheritance.[5] Still, inheritance is a commonly used mechanism for establishing subtype relationships.[6]

Subclasses, derived classes, heir classes, or child classes are modular derivative classes that inherits one or more language entities from one or more other classes (called superclass, base classes, or parent classes). The semantics of class inheritance vary from language to language, but commonly the subclass automatically inherits the instance variables and member functions of its superclasses.

Inheritance is similar to but distinct from subtyping.[15] Subtyping enables a given type to be substituted for another type or abstraction, and is said to establish an is-a relationship between the subtype and some existing abstraction, either implicitly or explicitly, depending on language support. The relationship can be expressed explicitly via inheritance in languages that support inheritance as a subtyping mechanism.


In computer science, dynamic dispatch is the process of selecting which implementation of a polymorphic operation (method or function) to call at run time. It is commonly employed in, and considered a prime characteristic of, object-oriented programming (OOP) languages and systems.[1]
Object-oriented systems model a problem as a set of interacting objects that enact operations referred to by name. Polymorphism is the phenomenon wherein somewhat interchangeable objects each expose an operation of the same name but possibly differing in behavior.

Dynamic dispatch contrasts with static dispatch, in which the implementation of a polymorphic operation is selected at compile time. The purpose of dynamic dispatch is to defer the selection of an appropriate implementation until the run time type of a parameter (or multiple parameters) is known.
Dynamic dispatch is different from late binding (also known as dynamic binding). Name binding associates a name with an operation. A polymorphic operation has several implementations, all associated with the same name. Bindings can be made at compile time or (with late binding) at run time. With dynamic dispatch, one particular implementation of an operation is chosen at run time. While dynamic dispatch does not imply late binding, late binding does imply dynamic dispatch, since the implementation of a late-bound operation is not known until run time.


this, self, and Me are keywords used in some computer programming languages to refer to the object, class, or other entity of which the currently running code is a part. The entity referred to by these keywords thus depends on the execution context (such as which object is having its method called). Different programming languages use these keywords in slightly different ways. In languages where a keyword like "this" is mandatory, the keyword is the only way to access data and methods stored in the current object. Where optional, they can disambiguate variables and functions with the same name.

In many object-oriented programming languages, this (also called self or Me) is a variable that is used in instance methods to refer to the object on which they are working

The concept is similar in all languages: this is usually an immutable reference or pointer which refers to the current object; the current object often being the code that acts as 'parent' to the property, method, sub-routine or function that contains the this keyword. After an object is properly constructed, or instantiated, this is always a valid reference. Some languages require it explicitly; others use lexical scoping to use it implicitly to make symbols within their class visible.
