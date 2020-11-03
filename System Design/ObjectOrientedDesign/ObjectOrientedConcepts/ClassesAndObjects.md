object-oriented programming models the entities of a domain as a collection of objects.

Concisely, objects encapsulate state and behavior.
An object can be defined as a collection of variables, the values of which, when viewed collectively represents the state of a single, complex entity, and a collection of methods providing operations relevant to that entity.

An object instance is defined by sets of states, behaviours, and an identity.

Object state is modeled by data variables, known as fields, attributes, or properties
Object behaviour is modeled by procedures, known as member functions or methods
Object identity is modeled by an object reference


Objects are referenced by their consumers for use
Object state and behavior comprise an interface that specifies how the object is utilized by consumers.

Example: "Door" object has
a state, "opened" or "closed"
methods such as "open" and "close"


A class is a contract that defines the state and behaviour of a classification of objects.

Creating an individual object, a class instance, is referred to as instantiation.
Upon instantiation an object's reference model's a unique identity

The relationship between classes and objects is analogous to the relationship between an apple-pie recipe and apple pies: You can make as many apple pies as you want from a single recipe.

https://en.wikipedia.org/wiki/Class_(computer_programming)
In casual use, people often refer to the "class" of an object, but narrowly speaking objects have type: the interface, namely the types of member variables, the signatures of member functions (methods), and properties these satisfy. At the same time, a class has an implementation (specifically the implementation of the methods), and can create objects of a given type, with a given implementation.[3] In the terms of type theory, a class is an implementation‍—‌a concrete data structure and collection of subroutines‍—‌while a type is an interface. Different (concrete) classes can produce objects of the same (abstract) type (depending on type system); for example, the type Stack might be implemented with two classes – SmallStack (fast for small stacks, but scales poorly) and ScalableStack (scales well but high overhead for small stacks). Similarly, a given class may have several different constructors.

Class types generally represent nouns, such as a person, place or thing, or something nominalized, and a class represents an implementation of these. For example, a Banana type might represent the properties and functionality of bananas in general, while the ABCBanana and XYZBanana classes would represent ways of producing bananas (say, banana suppliers or data structures and functions to represent and draw bananas in a video game). The ABCBanana class could then produce particular bananas: instances of the ABCBanana class would be objects of type Banana. Often only a single implementation of a type is given, in which case the class name is often identical with the type name.

Terms

Each object is an instance of a particular class

Data that comprise the state of a class of objects are held in variables known as fields
Procedures that comprise the behaviour of a class of objects are known as methods


Variables
Class variables        Variable of a class; shared by every instance of a class
Instance variables    Variables of individual objects; every class instance has its own copy
Member variables     class and instance variables of a particular classes
Local Variables        Variables in a method or code block
Parameters        Variables in a method declaration

Procedures
Class methods         – associated with a class
can access only to class variables and method parameters

Instance methods    – associated with each class instance
can access to instance variables, method parameters and class variables
Object Oriented Concepts    https://en.wikipedia.org/wiki/Object-oriented_programming

Inheritance

Composition

Dynamic dispatch/message passing
It is the responsibility of the object, not any external code, to select the procedural code to execute in response to a method call, typically by looking up the method at run time in a table associated with the object. This feature is known as dynamic dispatch, and distinguishes an object from an abstract data type (or module), which has a fixed (static) implementation of the operations for all instances. If the call variability relies on more than the single type of the object on which it is called (i.e. at least one other parameter object is involved in the method choice), one speaks of multiple dispatch.

A method call is also known as message passing. It is conceptualized as a message (the name of the method and its input parameters) being passed to the object for dispatch.


Encapsulation

Composition, inheritance, and delegation

Polymorphism

Open recursion
