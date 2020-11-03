Abstract Classes and Methods


Class design should ensure a superclass contains common features of its subclasses.

Sometimes you will want to create a superclass that defines only a generalized form that will be shared by all of its subclasses, leaving it to each subclass to fill in the details.
Such a class is referred to as an abstract class

Such a class determines the nature of the methods that the subclasses must implement but does not, itself, provide an implementation of one or more of these methods.
In this case, you want some way to ensure that a subclass overrides all necessary methods.
Java’s solution to this problem is the abstract method,

denoted using the abstract type modifier in the method header
An abstract method contains no body and is, therefore, not implemented by the superclass.
Thus, a subclass must override it—it cannot simply use the version defined in the superclass.

Syntax:
abstract return-type methodName(parameter-list);

The abstract modifier can be used only on instance methods.
It cannot be applied to static methods or to constructors.
A class that contains one or more abstract methods must also be declared as abstract
A class is declared abstract by preceding the "class" declaration keyword with the "abstract" modifier.

abstract class ClassName{
//…
}

Abstract classes cannot be instantiated.
Since an abstract class does not define a complete implementation, there can be no objects of an abstract class.
Abstract class instantiation using new results in a compile-time error.
An abstract method is defined without implementation. Its implementation is provided by the subclasses.

It is good practice to give abstract class constructors the protected access modifier
because it is used only by subclasses.
Abstract classes can't be directly instantiated, only extended, so the use is therefore always from a subclass's constructor. When you create an instance of a concrete subclass, its superclass’s constructor is invoked to initialize data fields defined in the superclass.

You would define a constructor in an abstract class if you are in one of these situations:
you want to perform some initialization (to fields of the abstract class) before the instantiation of a subclass actually takes place
you have defined final fields in the abstract class but you did not initialize them in the declaration itself; in this case, you MUST have a constructor to initialize these fields

Note that:

you may define more than one constructor (with different arguments)
you can (should?) define all your constructors protected (making them public is pointless anyway)
your subclass constructor(s) can call one constructor of the abstract class; it may even have to call it (if there is no no-arg constructor in the abstract class)
In any case, don't forget that if you don't define a constructor, then the compiler will automatically generate one for you (this one is public, has no argument, and does nothing).



An abstract class is a special type of class that is created strictly to be a base class for other classes to derive from.

Abstract classes may have fields and methods just like any other classes.
Abstract classes have a special type of method known as abstract methods.
Abstract methods are methods that have no body and MUST be implemented in the derived class.
They can only exist in abstract classes.

When a subclass inherits an abstract class, it must implement all of the abstract methods in the superclass. If it doesn’t, then the subclass must also be specified as abstract. Thus, the abstract attribute is inherited until such time as a complete implementation is achieved.

A class that contains abstract methods must be abstract. However, it is possible to define an abstract class that doesn’t contain any abstract methods. This abstract class is used as a base class for defining subclasses.

A subclass can override a method from its superclass to define it as abstract. This is very unusual, but it is useful when the implementation of the method in the superclass becomes invalid in the subclass. In this case, the subclass must be defined as abstract.

A subclass can be abstract even if its superclass is concrete.
The Object class is concrete, but is inherited by all abstract subclasses

We add the abstract keyword in a method declaration to indicate an abstract method. In addition, we do not add braces { } after the method declaration as abstract methods have no body. Instead, we end the declaration with a semi-colon (;).




Interfaces
https://docs.oracle.com/javase/tutorial/java/IandI/index.html


An interface is a specialized class used to define a specific behaviour

Like a superclass defines state and behaviour common to its subclasses
an interface defines a common behavior which inheriting classes implement

An interface is said to name contract between implementing classes and their clients
The term client refers to any entity that requests a service
The client is unconcerned with how the entity providing a service performs the service
the client is happy as long as the service is available and fulfills its use case.

In object-oriented programming, it is sometimes helpful to define what a class must do but not how.
While abstract classes and methods are useful, it is possible to take this concept a step further.
An interface is similar to an abstract class, but its intent is to specify a behavior for arbitrary classes rather than subclasses.


In Java, you can separate the interface provided by a class from its implementation using the keyword interface.

Interfaces, like abstract classes, cannot be instantiated.
An interface is syntactically similar to an abstract class, in that you can specify one or more methods that have no body.
Those methods must be implemented by a class in order for their actions to be defined.
Thus, an interface specifies what must be done, but not how to do it.

Interfaces must be implemented by classes or extended by other interfaces.
The relationship between the class and the interface is known as interface inheritance.
Once an interface is defined, any number of classes can implement it.
A class can implement any number of interfaces.

When a class implements an interface, it has to implement all the abstract methods in that interface.
Each class is free to determine the details of its own implementation.
Two classes might implement the same interface in different ways, but each class still supports the same set of methods.

All methods in an interface are implicitly public and abstract while all constant values are implicitly public, static, and final. You do not have to specify these modifiers.

An interface can inherit other interfaces using the extends keyword.
Such an interface is called a subinterface.
An interface can not inherit/extend classes.
An interface can inherit one or more other interfaces by specifying a comma delimited extends clause.


Basic interface syntax :
[access-mod] interface InterfaceName {
[type] var1 = value;
[type] var2 = value;
// ...
[type] varN = value;
[ret-type] methodName1( [param-list] );
[ret-type] methodName2( [param-list] );
// …
[ret-type] methodNameN( [param-list] );
}






To start, you code the public keyword, followed by the interface keyword, followed by the name of the
interface. When you name an interface, it's common to end the name with a
suffix of "able" or "er". For example, the Java API uses names like Cloneable,
Comparable, EventListener, ActionListener, and so on. Another common naming
strategy is to prefix the name of an interface with "I". For example, some
programmers use names such as IProduct.


An interface that doesn't contain any methods is known as a tagging interface. This type of interface is typically used to identify that an object is safe for a certain type of operation such as cloning or serializing.


A class can inherit another class and also implement one or more interfaces. • If a class inherits another class that implements an interface, the subclass automatically implements the interface. However, you can code the implements keyword in the subclass for clarity. • If a class inherits another class that implements an interface, the subclass has access to any methods of the interface that are implemented by the superclass and can override those methods.


• A class that implements an interface must implement all abstract methods declared
by the interface as well as all abstract methods declared by any inherited interfaces
unless the class is defined as abstract.
• A class that implements an interface can use any of the constants declared in the
interface as well as any constants declared by any inherited interfaces.

interface-based programming
The important thing is to use an interface type whenever possible and avoid specifying a concrete class that implements it unless it is necessary.

When you use a library, your code should only depend on an interface, like List. It should not depend on a specific implementation, like ArrayList. That way, if the implementation changes in the future, the code that uses it will still work.
Implementing Interfaces
To implement an interface, use keyword "implements" in the class definition and create the required abstract.
Syntax:
class classname extends superclass implements interface {
// class-body
}

To implement more than one interface, interface names are comma delimited.
The methods that implement an interface must be declared public.
The type signature of the implementing method must match exactly the type signature specified in the interface definition.

One significant difference between classes and interfaces is that classes can have fields whereas interfaces cannot.
Whenever you implement a method defined by an interface, it must be implemented as public because all members of an interface are implicitly public.

One more point: If a class includes an interface but does not fully implement the methods defined by that interface, then that class must be declared abstract. No objects of such a class can be created, but it can be used as an abstract superclass, allowing subclasses to provide the complete implementation.

Using Interface References
You can declare a reference variable of an interface type. In other words, you can create an interface reference variable. Such a variable can refer to any object that implements its interface. When you call a method on an object through an interface reference, it is the version of the method implemented by the object that is executed. This process is similar to using a superclass reference to access a subclass object


Variables in Interfaces
variables can be declared in an interface, but they are implicitly public, static, and final.

To define a set of shared constants, create an interface that contains only these constants, without any methods. Each file that needs access to the constants simply “implements” the interface. This brings the constants into view


Interfaces Can Be Extended
One interface can inherit another by use of the keyword extends. The syntax is the same as for inheriting classes. When a class implements an interface that inherits another interface, it must provide implementations for all methods required by the interface inheritance chain.



Changes to Interfaces
Through Java 7,
interfaces could only contain abstract methods (no bodies) and constants ( final fields).
an interface could not define any implementation whatsoever.
interfaces could define only what, but not how, methods were implemented.

JDK 8 changed interface capabilities adding default and static implementations to interface methods.
beginning with JDK 9, an interface can also include private methods.
Thus, it is now possible for interfaces to specify some behavior. However, such methods constitute what are, in essence, special-use features, and the original intent behind interfaces still remain.


Default methods
Default interface methods use the keyword "default".
A default method provides a default implementation for the method in the interface.
By use of a default method, it is possible for an interface method to provide a body, rather than being abstract.
default methods may also be referred to as extension methods
A class that implements the interface may simply use the default implementation for the method or override the method with a new implementation. This feature enables you to add a new method to an existing interface with a default implementation without having to rewrite the code for the existing classes that implement this interface

Java 8 also permits public static methods in an interface.
A public static method in an interface can be used just like a public static method in a class.

A primary motivation for the default method was to provide a means by which interfaces could be expanded without breaking existing code.
Java added default and static methods in interfaces mainly to ensure binary compatibility. Simply stated, binary compatibility means that when you change your interface, you do not need to make any changes to the classes that implement it.

A class that implements an interface must implement all the abstract methods in the interface.
Hence, if you add an abstract method to your interface, you need to ensure that all classes that implement your interface implement the new method.
This is often impossible to do as you may have no idea which classes implemented your interface.
To overcome this problem, Java added support for default and static methods for interfaces.

In the past, if a new method were added to a popular, widely used interface, then the addition of that method would break existing code because no implementation would be found for that method. The default method solves this problem by supplying an implementation that will be used if no other implementation is explicitly provided. Thus, the addition of a default method will not cause preexisting code to break.
This allows us to add methods to our interfaces without having to make any changes to the classes that implemented it.

Another motivation for the default method was the desire to specify methods in an interface that are, essentially, optional, depending on how the interface is used.

For example, an interface might define a group of methods that act on a sequence of elements. One of these methods might be called remove( ), and its purpose is to remove an element from the sequence. However, if the interface is intended to support both modifiable and non-modifiable sequences, then remove( ) is essentially optional because it won’t be used by non-modifiable sequences. In the past, a class that implemented a non-modifiable sequence would have had to define an empty implementation of remove( ), even though it was not needed. Today, a default implementation for remove( ) can be specified in the interface that either does nothing or reports an error. Providing this default prevents a class used for non-modifiable sequences from having to define its own placeholder for remove( ).

Thus, by providing a default, the interface makes the implementation of that method by a class optional.

It is important to point out that the addition of default methods does not change a key aspect of interface: an interface still cannot have instance variables. Thus, the defining difference between an interface and a class is that a class can maintain state information, but an interface cannot.



Use static Methods in an Interface
JDK 8 added another new capability to interface: the ability to define one or more static methods. Like static methods in a class, a static method defined by an interface can be called independently of any object. Thus, no implementation of the interface is necessary, and no instance of the interface is required in order to call a static method. Instead, a static method is called by specifying the interface name, followed by a period, followed by the method name. Here is the general form: InterfaceName.staticMethodName

Notice that this is similar to the way that a static method in a class is called.

Private Interface Methods
Beginning with JDK 9, an interface can include a private method. A private interface method can be called only by a default method or another private method defined by the same interface. Because a private interface method is specified private, it cannot be used by code outside the interface in which it is defined. This restriction includes subinterfaces because a private interface method is not inherited by a subinterface. The key benefit of a private interface method is that it lets two or more default methods use a common piece of code, thus avoiding code duplication.



Interface Vs Abstract Class

An interface can be used more or less the same way as an abstract class, but defining an interface is different from defining an abstract class.

Java allows only single inheritance for class extension, but allows multiple extensions for interfaces.

Abstract class     
Can hold state.
No variable restrictions.
Constructors are invoked by subclasses through constructor chaining.
An abstract class cannot be instantiated using the new operator.
No method restrictions.
abstract keyword lets you remove method body
Interface
Cannot hold state
All variables must be public static final.
No constructors.
An interface cannot be instantiated using the new operator.
May contain public abstract instance methods, public default, and public static methods.
default keyword lets you add a method body

Abstract classes and interfaces can both be used to specify common behavior of objects. How do you decide whether to use an interface or a class? In general, a strong is-a relationship that clearly describes a parent–child relationship should be modeled using classes.

A weak is-a relationship, also known as an is-kind-of relationship, indicates that an object possesses a certain property. A weak is-a relationship can be modeled using interfaces. For example, all strings are comparable, so the String class implements the Comparable interface.

In general, interfaces are preferred over abstract classes because an interface can define a common supertype for unrelated classes. Interfaces are more flexible than classes.

Both interfaces and abstract classes can be used to specify common behavior for objects. How
do you decide whether to use an interface or a class? In general, a strong is-a relationship
that clearly describes a parent–child relationship should be modeled using classes. For example, since an orange is a fruit, their relationship should be modeled using class inheritance.
A weak is-a relationship, also known as an is-kind-of relationship, indicates that an object
possesses a certain property. A weak is-a relationship can be modeled using interfaces.
Interfaces are more flexible than abstract classes because a subclass can extend only one superclass, but can implement any number of interfaces. However, interfaces cannot contain data fields. In Java 8, interfaces can contain default methods and static methods, which are very useful to simplify class design.
Multiple Inheritance Issues
Some programming languages allow you to derive a subclass from several classes. This capability is known as multiple inheritance. Java, however, does not allow multiple inheritance. A Java class may inherit directly from only one superclass. This restriction is known as single inheritance. If you use the extends keyword to define a subclass, it allows only one parent class. Nevertheless, multiple inheritance can be achieved through interfaces

Now that an interface can include default methods, you might be wondering if an interface can provide a way around this restriction. The answer is, essentially, no. Recall that there is still a key difference between a class and an interface: a class can maintain state information (through the use of instance variables), but an interface cannot.

The preceding notwithstanding, default methods do offer a bit of what one would normally associate with the concept of multiple inheritance. For example, you might have a class that implements two interfaces. If each of these interfaces provides default methods, then some behavior is inherited from both. Thus, to a limited extent, default methods do support multiple inheritance of behavior. As you might guess, in such a situation, it is possible that a name conflict will occur.

For example, assume that two interfaces called Alpha and Beta are implemented by a class called MyClass. What happens if both Alpha and Beta provide a method called reset( ) for which both declare a default implementation? Is the version by Alpha or the version by Beta used by MyClass? Or, consider a situation in which Beta extends Alpha. Which version of the default method is used? Or, what if MyClass provides its own implementation of the method?
To handle these and other similar types of situations, Java defines a set of rules that resolve such conflicts.

First, in all cases a class implementation takes priority over an interface default implementation. Thus, if MyClass provides an override of the reset( ) default method, MyClass’s version is used. This is the case even if MyClass implements both Alpha and Beta. In this case, both defaults are overridden by MyClass’s implementation.

Second, in cases in which a class inherits two interfaces that both have the same default method, if the class does not override that method, then an error will result. Continuing with the example, if MyClass inherits both Alpha and Beta, but does not override reset( ), then an error will occur.

In cases in which one interface inherits another, with both defining a common default method, the inheriting interface’s version of the method takes precedence. Therefore, continuing the example, if Beta extends Alpha, then Beta’s version of reset( ) will be used.

It is possible to refer explicitly to a default implementation by using a new form of super. Its general form is shown here: InterfaceName.super.methodName( ) For example, if Beta wants to refer to Alpha’s default for reset( ), it can use this statement:

Alpha.super.reset();

Resolving Default Method Conflicts
If a class implements two interfaces, one of which has a default method and the other a method (default or not) with the same name and parameter types, then you must resolve the conflict.
In this example ClassName extends both the Alpha and Beta interfaces, each of which have a reset() implementation that ClassName inherits. There is no way for the Java compiler to choose one over the other. The compiler reports an error and leaves it up to you to resolve the ambiguity.
Provide a reset() method in ClassName and either implement your own scheme, which overrides the interface implementations or delegate to one of the conflicting methods, like this:

public class ClassName implements Alpha, Beta {
public int reset() { return Alpha.super.reset(); }
...
}
