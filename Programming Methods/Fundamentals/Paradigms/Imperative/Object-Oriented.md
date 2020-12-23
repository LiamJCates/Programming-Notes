in object-oriented programming, code is organized into objects that contain state that is only modified by the code that is part of the object. Most object-oriented languages are also imperative languages.




The main idea within object-oriented programming is to model the code in the same way as we as humans look at the world. Even if you've never thought about it, we are always classifying things and grouping things together using abstraction. We can talk about vehicles, and we have shared knowledge of what is included in this group. Cars, bicycles, boats, and airplanes are, while pencils, ducks, and swimsuits are not.


Grouping things into these abstractions make our lives easier as we will not go into details every single time, we talk about something. I can ask for a vehicle instead of describing that I need a device that can transport me from my current location to town. Things within such an abstraction can be very different, but if they share some key characteristics, we will understand it.

In object-oriented programming, we try to preserve this way of describing things and represent them in a way that is not too different from how we just described them here.

To summarize this, we can state that a class is a model or the blueprint for the objects. The data that is defined within the class is often referred to as member variables or attributes.

A member variable is just like any other variable, with one key difference: it lives inside of an object.

Object-oriented programming states that member data should be encapsulated within its object and that information hiding should be used such that direct access to this data from the outside should be prevented.

One design goal is to treat classes as "black boxes," whose external interface is public but whose internal details are hidden from view. Hiding internal information permits implementation of a class to be changed without requiring any clients of the class to modify code.

The vital key here is the interface. An interface is what we use to communicate with an object.

The remote control object is a black box as we can't see the internals of the remote, and there is no need for us to either. The only thing we need to understand to be able to use the object is the interface. If the remote is not working correctly, we can take it to someone who understands the inner workings of it, and they can repair it. If they don't change the interface, the buttons, and what functionality that is associated with them, we won't need to change the way we use the remote before and after the modification.


We say that objects communicate by passing messages to each other.


Object-oriented programming is very focused around data, so when we're deciding what a class will look like, this is often where we start. The data that makes it into our class will often dictate what kind of behavior we want it to have. This behavior often dictates the operations we need to perform on the data.

A class method is nothing but a function that belongs to a class. The reason we have a different name for these functions is so that we can distinguish between a function that is part of a class and one that is not. As soon as you hear someone mention a method, you know that it is a function that belongs to a class.

Two popular methods that we will find in classes are what are called getters and setters. A getter is a method that returns the value of a private member variable, while a setter is a method that lets us change its value.

When we hide the data by using the private keyword, getters and setters become useful as interfaces to this data.

To make a method available outside the class, we can use the public keyword. A method that allows access from outside the class to retrieve private data is a getter. A method that allows access from outside the class to alter private data is a setter.

A natural question at this point is why we need to bother having these getters and setters. Why can't we just leave data public and let anyone read and change them as they want? The reason is that keeping the data private and controlling access to it through methods will give us control.

If a stranger walks up to you and asks for your name, you will have some options. You could respond with your actual name, you could tell them that it is none of their business, or you could lie and tell them a different name. You have control over the access to your private data, just as the class will have control over the access to its private data with the help of these methods.



Exactly how object-oriented programming is implemented differs from language to language. Languages that support object-orientation will also sometimes have slightly different rules for how object-orientation is used. As always, we will need to learn how the language we are using has defined the object-oriented principles.





Object-oriented programming (OOP) is a programming paradigm based on the concept of "objects", which can contain data, in the form of fields (often known as attributes), and code, in the form of procedures (often known as methods). A feature of objects is an object's procedures that can access and often modify the data fields of the object with which they are associated (objects have a notion of "this" or "self"). In OOP, computer programs are designed by making them out of objects that interact with one another.[1][2] OOP languages are diverse, but the most popular ones are class-based, meaning that objects are instances of classes, which also determine their types.

Languages that support object-oriented programming typically use inheritance for code reuse and extensibility in the form of either classes or prototypes.

Those that use classes support two main concepts:

Classes – the definitions for the data format and available procedures for a given type or class of object; may also contain data and procedures (known as class methods) themselves, i.e. classes contain the data members and member functions

Objects – instances of classes

Class variables – belong to the class as a whole; there is only one copy of each one

Instance variables or attributes – data that belongs to individual objects; every object has its own copy of each one

Member variables – refers to both the class and instance variables that are defined by a particular class

Class methods – belong to the class as a whole and have access only to class variables and inputs from the procedure call

Instance methods – belong to individual objects, and have access to instance variables for the specific object they are called on, inputs, and class variables

Languages that support classes almost always support inheritance. This allows classes to be arranged in a hierarchy that represents "is-a-type-of" relationships.

Subtyping - a form of polymorphism - is when calling code can be agnostic as to which class in the supported hierarchy it is operating on - the parent class or one of its descendants. Meanwhile, the same operation name among objects in an inheritance hierarchy may behave differently.


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
