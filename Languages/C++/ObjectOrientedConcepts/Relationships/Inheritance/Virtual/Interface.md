Interface Classes

In software engineering, an interface is a shared boundary that contains no data or code. It defines function signatures that all implementations of the interface agree to support. An implementation is code or data that declares support for an interface. You can think of an interface as a contract between classes that implement the interface and users (also called consumers or clients) of that class.

C++ "interface" classes are implemented using "pure abstract" classes, classes which exclusively contain pure virtual functions (and no data) as members.

For information regarding pure virtual functions, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\Virtual\PureVirtualMethod.md]

These interface classes should not be confused with conceptual interfaces defined by data abstraction which is the concept of keeping a data type's public behavioral interface separate from it's private implementation details.

As an interface class has no member variables and only pure virtual functions. In other words, the class is purely a definition, and has no actual implementation. Interfaces are useful when you want to define the functionality that derived classes must implement, but leave the details of how the derived class implements that functionality entirely up to the derived class.

Interface classes are often named beginning with an I.

For an example interface use case, see:
[C++\ObjectOrientedConcepts\Relationships\Inheritance\Virtual\InterfaceExample.md]


### Implementing Interfaces

To declare an interface, declare a pure virtual class. To implement an interface, derive from it. Because the interface is pure virtual, an implementation must implement all of the interface’s methods.

It’s good practice to mark these methods with the override keyword.
This communicates that you intend to override a virtual function, allowing
the compiler to save you from simple mistakes.

Usually, you add virtual destructors to interfaces.

Adding the virtual destructor causes the Derived class destructor to get invoked when you delete a Base class pointer.

Without a virtual destructor for your interface classes, the derived destructor won't be called if a pointer to the interface is deleted. This can be an issue for derived classes that necessitate a non-default destructor.

While, declaring a virtual destructor is optional when declaring an interface, be aware, if you forget that you haven’t implemented a virtual destructor in the interface, you can leak resources, and the compiler won’t warn you.

NOTE
Declaring a protected non-virtual destructor is a good alternative to declaring a public virtual destructor because it will cause a compilation error when writing code that deletes a base class pointer. Some don’t like this approach because you eventually have to make a class with a public destructor, and if you derive from that class, you run into the same issues.



### Using Interfaces

Consumers know how to use any class implementing an interface because they are aware of the behavioral contract specified by the interface. In fact, the consumer never needs to know the underlying implementation type.



Because interfaces have no data and no function bodies, they avoid a lot of the traditional problems with multiple inheritance while still providing much of the flexibility.

The flip side of this flexibility is that objects must be manipulated through pointers or references.


Interfaces impose stringent requirements. A consumer of an interface can use only the methods explicitly defined by the interface's behavioral contract.

Interfaces promote highly reusable and loosely coupled code.



To decouple the interface from the representation we give up local variables. Since we don’t know anything about the representation of an abstract type (not even its size), we must allocate objects on the free store and access them through references or pointers.

As a consumer, you can only deal in references or pointers to interfaces. The compiler cannot know ahead of time how much memory to allocate for the underlying type: if the compiler could know the underlying type, you would be better off using templates.



There are two options for how to set the member:

Constructor injection
With constructor injection, you typically use an interface reference. Because references cannot be reseated, they won’t change for the lifetime of the object.

Property injection
With property injection, you use a method to set a pointer member. This allows you to change the object to which the member points.

You can combine these approaches by accepting an interface pointer in a constructor while also providing a method to set the pointer to something else.
Typically, you’ll use constructor injection when the injected field won’t change throughout the lifetime of the object. If you need the flexibility of modifying the field, you’ll provide methods to perform property injection.

Interface classes have become extremely popular because they are easy to use, easy to extend, and easy to maintain.



In fact, some modern languages, such as Java and C#, have added an “interface” keyword that allows programmers to directly define an interface class without having to explicitly mark all of the member functions as abstract. Furthermore, although Java (prior to version 8) and C# will not let you use multiple inheritance on normal classes, they will let you multiple inherit as many interfaces as you like.
