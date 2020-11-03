Object-oriented programming allows you to define new classes that are extensions of existing classes.

Inheritance allows a class to be defined as a modified or more specialized version of another class. When class B inherits from class A (Java uses the term extends), class A is B’s parent or base class, and class B is A’s subclass. All the behaviors defined by class A are also part of class B, though possibly in a modified form. In fact, an instance of class B can be used wherever an instance of class A is required.

Inheritance causes the creation of hierarchical classifications.
Derived classes are known as child or sub classes
Classes from which others derive are known as parent classes, base classes or super classes.

In the inheritance hierarchy,
classes become more specialized and concrete as we move up the chain of subclasses.
classes become more generalized and abstract as we move up the chain of super classes

Classes higher in the hierarchy are more general, possessing traits common to a defined entity set.
(Super Class Ex: Animal)
Classes lower in the hierarchy derive from those above them, adding increasingly specialized members.
(SubClass Exs: Cat, Dog, Bear, Mouse)


Inheritance allows
a subclass to inherit common state attributes and behavior
build classes based on other classes to avoid duplicating code
extension of a class without having to touch previously tested, working code

Without the use of hierarchies, each object would have to explicitly define all of its characteristics.
Using inheritance, each additional object definition only defines those qualities that make it unique within its class. It can inherit its general attributes from its parent.
Thus, it is the inheritance mechanism that makes it possible for one object to be a specific instance of a more general case.
