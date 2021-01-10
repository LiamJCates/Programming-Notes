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
