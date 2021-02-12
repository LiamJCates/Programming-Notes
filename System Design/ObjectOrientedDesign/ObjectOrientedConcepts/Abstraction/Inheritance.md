Object-oriented programming allows you to define new classes with respect to existing classes.

This existing class is called the base class, and the new class is referred to as the derived class.

Typically the derived class is defined as a modified or more specialized version of a base class.

Inheritance causes the creation of hierarchical classifications:
Classes that others derive from are known as parent, base or super classes
Classes that are derived from others are known as child or sub classes

Each derived class, in turn, can become a base class for a future derived class.

The act of being derived from another class is termed inheritance.

When class B inherits from class A:
class A is B’s parent or base class
class B is A’s subclass.


The derived classes inherit the properties of the base classes.
So rather than create completely new classes from scratch, we can take advantage of inheritance and reduce software development complexity

Instead of writing completely new data members and member functions, the programmer can designate that the new class should inherit the members of an existing class.


In the inheritance hierarchy:
classes become more specialized and concrete as we move down the chain of subclasses.
classes become more generalized and abstract as we move up the chain of super classes.

The idea of inheritance implements the is a relationship. For example, mammal IS-A animal, dog IS-A mammal hence dog IS-A animal as well and so on.



Without the use of hierarchies, each object would have to explicitly define all of its characteristics

Using inheritance, a child class definition only defines those qualities that make it unique within its class. A child class inherits its general state attributes and behavior from its parent. A child class is thus able to avoid duplicating code that it requires from it's parent class, and is able to extend functionality without effecting previously tested, working code.

Thus, it is the inheritance mechanism that makes it possible for one    object to be a specific instance of a more general case.

That is to say, classes higher in the hierarchy are more general, possessing traits common to a defined entity set.
(Super Class Ex: Animal)
Classes lower in the hierarchy derive from those above them, adding increasingly specialized members.
(SubClass Exs: Cat, Dog, Bear, Mouse)


Inheritance can be either single inheritance or multiple inheritance. In single inheritance, the derived class is derived from a single base class; in multiple inheritance, the derived class is derived from more than one base class.


















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
