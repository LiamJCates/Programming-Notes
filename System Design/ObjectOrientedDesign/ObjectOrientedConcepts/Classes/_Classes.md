Object-oriented programming models the entities of a domain as a collection of objects.

Concisely, objects group together related state, behavior, and an identity.

Objects of the same type are defined using a common class. A class is a contract that defines the state and behavior of a classification of objects. A class definition is a template, or a piece of software that includes the specification of its object's variables which compose the objects state and functions which provides behavior relative to the state.

The relationship between classes and objects is analogous to the relationship between an apple-pie recipe and apple pies: You can make many unique apple pies as you want from a single recipe.

To summarize this, we can state that a class is a model or the blueprint for the objects. This combining of data and related operations in a class is called encapsulation.

When an instance of an object is created from a class template, called instantiation, that object is given a unique identity. An object instance is defined by its set of states, behaviors, and an identity.

	Object state is modeled by data variables, known as attributes, fields, properties, or data members.
	Object behavior is modeled by procedures, known as methods, member functions, or function members.
	Object identity is modeled by an object reference


Example:
"Door" object has
state, "opened" or "closed"
methods such as "open" and "close"





Variables
Member variables: class and instance variables of a particular class

Class variables: Variable of a class; as there is only one copy, they are  shared by every instance of a class

Instance variables: Variables of individual objects; every class instance has its own copy
Local Variables: Variables in a method or code block
Parameters: Variables in a method declaration


Procedures
Member functions: class and instance methods of a particular class

Class methods: Methods of a class; shared by every instance of a class
can access only class variables and method parameters

Instance methods: Methods of an instance; associated with each class instance
can access instance variables, method parameters, and class variables








An object-oriented program is described by the interactions of it's objects. Objects are referenced by their consumers for use. Object state and behavior comprises the 'object interface' that specifies how the object is utilized by consumers.

Client refers to any entity that requests a service from another entity. The client does not bother about how the entity providing the service actually provides the service - the client is happy as long as the service is available and fulfills its use case. Hence, when a method M1 within a class calls another method M2 then M1 is a client of M2. Similarly when a class C1 requests service of C2 then C1 is a client of C2.





In casual use, people often refer to the "class" of an object, but narrowly speaking objects have type: the interface, namely the types of member variables, the signatures of member functions (methods), and properties these satisfy. At the same time, a class has an implementation (specifically the implementation of the methods), and can create objects of a given type, with a given implementation.

In the terms of type theory, a class is an implementation‍ - ‌a concrete data structure and collection of subroutines‍ — ‌while a type is an interface. Different (concrete) classes can produce objects of the same (abstract) type (depending on type system); for example, the type Stack might be implemented with two classes – SmallStack (fast for small stacks, but scales poorly) and ScalableStack (scales well but high overhead for small stacks). Similarly, a given class may have several different constructors.

Class types generally represent nouns, such as a person, place or thing, or something nominalized, and a class represents an implementation of these. For example, a Banana type might represent the properties and functionality of bananas in general, while the ABCBanana and XYZBanana classes would represent ways of producing bananas (say, banana suppliers or data structures and functions to represent and draw bananas in a video game). The ABCBanana class could then produce particular bananas: instances of the ABCBanana class would be objects of type Banana. Often only a single implementation of a type is given, in which case the class name is often identical with the type name.
