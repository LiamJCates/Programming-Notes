## Object-oriented Programming Principles

A design principle is a technique that can be applied when designing or writing code to make it more maintainable, flexible, or extensible.

One of the main problems when developing software is dealing with change. Software that is not well designed breaks easily at the first sign of change, but well-designed software can be changed easily.

### SOLID principles
The most popular set of principles are the SOLID principles.

SOLID is an acronym for
* Single responsibility
* Open-closed
* Liskov substitution
* Interface segregation
* Dependency injection

### Single Responsibility
The Single Responsibility principle states a class should only do one thing, this way you're making sure each class has only one reason to change. When you see a class that has more than one reason to change, it's probably trying to do too many things. Take for example this Car class represented in a UML class diagram, drive, fillTank, changeTires. Sounds like this class is trying to do too many things. So maybe it could be better to have some methods to start and stop the car in the Car class and move the drive and fillTanks methods to a Driver class, passing a current instance as a parameter of these methods. In the same way, we can move the changeTires method to a Mechanic class.

### Open-Closed
The Open-Closed principle states classes will be open for extension and closed for modification. This means allowing change, but in a way that doesn't require you to modify existing code. The easiest way to apply this principle is by using inheritance. For example, instead of modifying the Car class to make it behave like an SUV, we can extend it to create an SUVCar subclass. Applying this principle is actually a combination of applying encapsulation and abstraction. The behavior that stays the same is abstracted into a base class and locked for a modification. When you need new or different behavior, subclasses can handle the changes by extending the base class.

### Liskov Substitution
The Liskov substitution principle says that when you inherit from the class, you must be able to substitute the subclass for base class without things going wrong. When you use inheritance, your subclass gets almost all the methods and fields from the superclass. If you use inheritance incorrectly, you're going to end up with methods and fields that probably don't make sense or that you don't need on your subclass. For example, can you actually use an SUVCar class instead of the more generic Car class? Does it make sense in your application? That's what the Liskov substitution principle is about.

When a derived class specializes the behavior and attributes of a base class (which is the common case), any
code that you write involving the base class should work equally well with an object of the derived class.

Barbara Liskov and Jeannette Wing formalized this fundamental principle of object-oriented programming, which is often known today as the Substitution Principle or Liskov’s Substitution Principle.
Briefly, the Substitution Principle states that if you have base class B and derived class D, in any situation
that calls for an object of type B, you can substitute an object of type D, with no ill effects.

The Substitution Principle helps you write programs, but it also imposes a burden. It helps because it
frees you to write code that depends on base class behavior without concerning yourself about any derived
classes.

The burden is on class authors to ensure that their click behavior meets the requirements of the Substitution Principle. The easiest way to meet the
requirements is to let the derived class inherit the behavior of the base class. Sometimes, however, the
derived class has additional work to do. Instead of inheriting, it provides new behavior. In that case, the
programmer must ensure that the behavior is a valid substitution for the base class behavior.


### Interface Segregation
The interface segregation principle says that you should define fine-grained interfaces as specific to the client that is going to use them. This means that it's better to have many as modern interfaces than fewer bigger interfaces. For example, let's say we have an interface with the methods start, stop, activate4WheelDrive, and openSunRoof. And for the purpose of this example, the interface doesn't violate the single responsibility principle. So following the interface segregation principle, we can break this interface into three smaller ones, separating the FourWheel and the SunRoofBehaviors. Not every car has a 4-wheel system or a sun roof, so this will allow us to make different combinations.

### Dependency Injection
The Dependency Injection principle states high-level modules should not depend on low-level modules; however, both should depend upon instructions, which can be interfaces or after classes. In this example, the Car class depends on Engine, the base class for FourCylinderEngine and V6Engine. This way through polymorphism we can inject into Car either one of these subclasses.

### Other Principles
There are many other principles that I'll be mentioning throughout the course, the don't repeat yourself principle, or DRY for short, about avoiding duplicated code, encapsulate what changes to protect your classes for unnecessary changes, favor composition over inheritance because object composition is an alternative to class inheritance that allow us to keep each class encapsulated and focused on one task, and programming to an interface, not an implementation because by using interfaces, your code will work with all the present and future implementations, which give you flexibility. If you know these principles by heart, your software well be well designed. But you don't have to start from scratch with these principles, it's better to reuse solutions that have worked for us in the past. The same patterns represent these reasonable solutions, and they are based on all these principles. We can say that principles are low-level design knowledge and patterns are high level. Patterns are proven solutions that other experts have applied successfully, and everyone can apply them without having to rediscover them.
<br/><br/><br/>
