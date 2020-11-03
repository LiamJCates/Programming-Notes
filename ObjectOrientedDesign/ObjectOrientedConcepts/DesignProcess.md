From Problem to Code
A common practice to break up the software development process into three phases:
• Analysis
• Design
• Implementation


The Analysis Phase
analysis concerns what needs to be done, not how it should be done.
Goal: complete functional description of the software product.
Result: a detailed textual description, functional specification, of the following characteristics:
• completely defines the tasks to be performed.
• free from contradictions.
• readable by domain experts and developers.
• reviewable by diverse interested parties.
• testable against reality.

One possible format for an analysis document is a user manual, very precisely worded to remove as much ambiguity as possible.

A set of use cases are a common format to describe the behavior of a system.
A use case describes a sequence of actions that yields a benefit for a user of a system.


The Design Phase
The program designer must structure the programming tasks into a set of interrelated classes. The designer strives for well defined classes with relationships are of manageable complexity.

Here are the major goals of the design phase:
• Identify the classes, their responsibilities, and the relationships among these classes

The end result of the design process consists of a number of artifacts:
• A textual description of the classes and their most important responsibilities
• Diagrams of the relationships among the classes
• Diagrams of important usage scenarios
• State diagrams of objects whose behavior is highly state-dependent

Typically, the design phase is more time-consuming than the the actual programming and greatly reduces the time required for implementation and testing.

2.1.3 The Implementation Phase
The goal of the implementation phase is the programming, testing, and deployment of the software product.  In the implementation phase, the classes and methods are coded, tested, and deployed.

Traditional programming methods rely on completion and unit testing of procedural units, followed by an integration phase. This integration tends to be frustrating and disappointing. Few programs are born according to plan out of a successful "big bang" integration. Object-oriented development encourages the gradual growth of a program by successively attaching more working classes and class clusters and repeated testing.

It is quite common to defer the implementation of some operations and build a "rapid prototype" that displays some functionality of the final product. You should not rush the analysis and design phase just to get to a working prototype quickly, nor should you hesitate to reopen the previous phases if a prototype yields new insight.  Object-oriented design is particularly suited for prototyping. The objects supporting the prototype are likely to be the same that need to be present in the final product, and growing the prototype into a complete program often is feasible.


The Object and Class Concepts

Objects are entities in a computer program that have three characteristic properties:
• State
• Behavior
• Identity

An object can store information that is the result of its prior operations. That information may determine how the object behaves in the future. The collection of all information held by an object is the object's state.

There must be a mechanism for rejecting improper requests. Object-oriented programming systems differ in this regard. Some systems attempt to weed out unsupported operations at compile time; others generate run-time errors.

A class describes a collection of related objects. Objects of the same class support the same collection of operations and have a common set of possible states. A class definition must therefore include the following:
• The (behavior)operations that are allowed on the objects of the class
• The possible states for objects of the class

Each object is constrained by the properties of its class.
It supports only those operations that the class lists as admissible
its legal states must stay within the range that the class permits.  

Objects that conform to a class description are called instances of that class.


Identifying Classes
A simple rule of thumb for identifying classes is to look for nouns in the functional specification.

Make sure not to fall into the trap of making your designs too specific.
classes KitchenAppliance, Toaster, and Blender. However if the kitchen appliance hierarchy is irrelevant to our problem, namely to process orders for products. A Product class is probably a better choice.

Don't fall into the opposite trap of making your designs unreasonably general. Consider the mail system example. A mailbox is a kind of component, and there are connections between various components. Connections can carry data (such as messages). Should you therefore design classes Component, Connection, and Data? No-those classes are too general. You would not be able to come up with clear responsibilities for them, and you would be no closer to a solution of your design problem.

Class names should be nouns in the singular form, stay away from generic names

Sometimes the noun needs to be prefixed by an adjective or participle: RectangularShape, BufferedReader.

after you go beyond the technique of finding nouns in the functional specification, it is useful to look at other categories of classes that are often helpful. Here are some of these categories:
• Tangible things
• Agents
• Events and transactions
• Users and roles
• Systems
• System interfaces and devices
• Foundational classes

Tangible things are the easiest classes to discover because they are visible in the problem domain.
Sometimes it is helpful to change an operation into an agent class. For example, the "compute page breaks" operation on a document could be turned into a Paginator class, which operates on documents.
Agent classes often end in "er" or "or".

Event and transaction classes are useful to model records of activities that describe what happened in the past or what needs to be done later. An example is a MouseEvent class, which remembers when and where the mouse was moved or clicked

User and role classes are stand-ins for actual users of the program. An Adm; n; strator class is a representation of the human administrator of the system. A Rev; ewe r class in an interactive authoring system models a user whose role is to add critical annotations and recommendations for change. User classes are common in systems that are used by more than one person or where one person needs to perform distinct tasks.
System classes model a subsystem or the overall system being built. Their roles are typically to perform initialization and shutdown and to start the flow of input into the system.
System interface classes model interfaces to the host operating system, the windowing system, a database, and so on. A typical example is the File class.
Foundation classes are classes such as String, Date, or Rectangle. They encapsulate basic data types with well-understood properties. At the design stage, you should simply assume that these classes are readily available, just as the fundamental types (integers and floating-point numbers) are.


Identifying Responsibilities
Just as classes correspond to nouns in the problem description, responsibilities correspond to verbs.
When you discover a responsibility, you must find one class (and only one class) that owns that responsibility.

It is helpful to have more than one person involved in the design phase. If one person assigns a responsibility to a particular class, another can ask the hard question, "How can an object of this class possibly carry out this responsibility?" It is appropriate to consider a "reasonable" implementation, or better, two different possibilities, to demonstrate that the responsibility can be carried out.

When assigning responsibilities, respect the natural layering of abstraction levels.
lowest system levels have files, keyboard mouse interfaces, and other system services.
highest levels there are classes that tie together the software system, such as Mail System.
The responsibilities of a class should stay at one abstraction level. A class Mailbox that represents a mid-level abstraction should not deal with processing keystrokes, a low-level responsibility, nor should it be concerned with the initialization of the system, a high-level responsibility


2.6 Use Cases

Use cases are an analysis technique to describe in a formal way how a computer system should work. Each use case focuses on a specific scenario, and describes the steps that are necessary to bring it to successful completion. Each step in a use case represents an interaction with people or entities outside the computer system (the actors) and the system itself.

A use case lists a sequence of actions that yields a result that is of value to an actor.

An essential aspect of a use case is that it must describe a scenario that completes to a point that is of some value to one of the actors.

Of course, most scenarios that potentially deliver a valuable outcome can also fail for one reason or another. Perhaps the message queue is full, or a mailbox owner enters the wrong password. A use case should include variations that describe these situations. Minimally, a use case should have a name that describes it concisely, a main sequence of actions, and, if appropriate, variants to the main sequence. Some analysts prefer a more formal writeup that numbers the use cases, calls out the actors, refers to related use cases, and so on.

2.8 UML Class Diagrams
Graphical notations are very popular for conveying design information, it is easier to extract relationship information by looking at a diagram than by reading documentation.
Three well-known researchers, Booch, Rumbaugh, and Jacobson, got together to unify their disparate notations and developed UML, the unified modeling language.
illustrates object -oriented design, using a standardized notation.  
A class diagram shows classes and the relationships among them.
There are a number of different types of UML diagrams.

Classes are drawn as boxes, which contain the class name
maybe the names of attributes and methods in additional compartments.
The UML defines an attribute as a named property of a class that describes a range of values that instances of the property may hold. Often, an attribute simply corresponds to an instance field. Occasionally, an attribute is conceptually at a higher level than the actual implementation. You usually do not list all attributes and methods, only the most important ones.

Unlike in Java, where the type precedes a variable, the UML format is attribute : Type
the parameter and return types of a method, for example
getMessage (index : int) : Message



Often, the types of attributes, parameters, and return values are omitted to conserve space. Thus, if you see methodName(), you cannot automatically assume that the method has no parameters.

You have to be careful about the shapes of the arrow tips. The inheritance arrow is closed, whereas the dependency arrow is open. Also note that the arrow tips for inheritance and dependency are at the end of the dependent class, but the diamond for aggregation is at the end of the aggregating class. For the "has" relationship, you can also write the multiplicity on the end points of the connection. The most common choices for the multiplicity are:
• any number (zero or more): *
• one or more: 1 .. *
• zero or one: 0 .. 1
• exactly one: 1

Some designers differentiate between aggregation and composItion.
Composition is a stronger form of aggregation where the contained objects do not have an existence independent of their container.
Use aggregation (or composition) only if a class actively manages objects of another class.

Some designers do not like the aggregation relationship because they feel it is too implementation-specific. UML defines a more general association between classes. An association is drawn as a solid line without a diamond. write roles at the ends of the lines


The relationship between courses and students is bidirectional-course objects will need to know about the students in the course, and Student objects need to know about the courses for which they are registered. Often, an association is directed, that is, it can only be navigated in one way. For example, a message queue needs to be able to locate the messages inside, but a message need not know in which message queue it is. A directed association is drawn with an open arrow tip

UML notation, you denote an interface by adding the stereotype descriptor «interface» above the interface name. (The « and » characters are called guillemets or French quotation marks. They have Unicode values \u00AB = 171 and \u00BB = 187.) If a class implements an interface, you draw a dotted arrow with a closed arrow tip.

Because the javadoc documentation and the class browsers in integrated development environments only display the inheritance relationship, they give the false impression that inheritance is the most important of the relationships between classes. Actually, that is not the case-inheritance is simply easy to determine from the program code. The most important relationship to control is the dependency or "uses" relationship. Too many dependencies make it difficult to evolve a design over time.

You should not aim for a comprehensive diagram that shows all classes and relationships in the system. A diagram with too much information becomes just a blur. The reason for drawing diagrams is to communicate design decisions. To achieve this purpose, each UML diagram should focus on a particular aspect of the design, and it should be accompanied by text that explains its relevance. When drawing a diagram, you should only include those elements that are needed to make a particular point, and omit all distractions.
