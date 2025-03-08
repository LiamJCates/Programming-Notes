In software design, a design pattern is a named description of a problem and solution that can be applied in new contexts; ideally, a pattern advises us on how to apply its solution in varying circumstances and considers the forces and trade-offs.


In short Software design patterns are common solutions to recurring problems in software design.

Design patterns can be organized into groups based on what kind of problem they solve. 

Object-oriented design patterns typically show relationships and interactions between classes or objects, without specifying the final application classes or objects that are involved. 

Object Oriented
    Creational 
    Structural 
    Behavioral

Efforts have also been made to codify design patterns in particular domains, including the use of existing design patterns as well as domain-specific design patterns. 

Domain-specific patterns
    Concurrency 
    Architectural

---

## **1. Creational Patterns**  
These patterns focus on object creation mechanisms to increase flexibility and reuse.

### **1.1 Singleton**  
Ensures that a class has only one instance and provides a global access point to it.

### **1.2 Factory Method**  
Defines an interface for creating an object but allows subclasses to alter the type of objects that will be created.

### **1.3 Abstract Factory**  
Provides an interface for creating families of related or dependent objects without specifying their concrete classes.

### **1.4 Builder**  
Separates the construction of a complex object from its representation, allowing the same construction process to create different representations.

### **1.5 Prototype**  
Creates new objects by copying an existing object (cloning) rather than instantiating from scratch.

---

## **2. Structural Patterns**  
These patterns deal with object composition, ensuring that components can be combined in flexible and efficient ways.

### **2.1 Adapter (Wrapper)**  
Allows two incompatible interfaces to work together by translating one interface into another.

### **2.2 Bridge**  
Decouples an abstraction from its implementation, allowing them to vary independently.

### **2.3 Composite**  
Allows individual objects and compositions of objects to be treated uniformly by representing part-whole hierarchies.

### **2.4 Decorator**  
Dynamically adds responsibilities to objects at runtime without modifying their base structure.

### **2.5 Facade**  
Provides a simplified interface to a larger body of code, making a complex system easier to use.

### **2.6 Flyweight**  
Minimizes memory usage by sharing as much object state as possible between instances.

### **2.7 Proxy**  
Provides a surrogate or placeholder for another object to control access to it.

---

## **3. Behavioral Patterns**  
These patterns focus on communication between objects, making interactions more flexible and efficient.

### **3.1 Chain of Responsibility**  
Passes a request along a chain of handlers, where each handler either processes the request or passes it to the next one.

### **3.2 Command**  
Encapsulates a request as an object, allowing for parameterization, queuing, and logging.

### **3.3 Interpreter**  
Defines a grammar and provides an interpreter to process sentences in that grammar.

### **3.4 Iterator**  
Provides a way to access elements of a collection sequentially without exposing its underlying structure.

### **3.5 Mediator**  
Centralizes communication between objects to reduce dependencies between them.

### **3.6 Memento**  
Captures and restores an object’s state without violating encapsulation.

### **3.7 Observer (Publish-Subscribe)**  
Defines a dependency between objects such that when one object changes state, all its dependents are notified.

### **3.8 State**  
Allows an object to alter its behavior when its internal state changes.

### **3.9 Strategy**  
Defines a family of algorithms and allows them to be interchangeable without altering client code.

### **3.10 Template Method**  
Defines the structure of an algorithm in a base class but allows subclasses to implement specific steps.

### **3.11 Visitor**  
Lets you add further operations to objects without modifying their structure.

---

## **4. Concurrency Patterns**  
These patterns deal with multi-threading and synchronization in concurrent programming.

### **4.1 Active Object**  
Decouples method execution from method invocation by using an asynchronous queue.

### **4.2 Balking**  
Prevents execution if an object is in an inappropriate state.

### **4.3 Double-Checked Locking**  
Reduces the overhead of acquiring a lock by first checking the condition without synchronization.

### **4.4 Guarded Suspension**  
Delays execution until a certain condition is met.

### **4.5 Monitor Object**  
Uses a single lock to control access to an object.

### **4.6 Read-Write Lock**  
Allows multiple threads to read an object but only one to write at a time.

### **4.7 Thread Pool**  
Manages a group of worker threads to limit resource consumption.

---

## **5. Architectural Patterns**  
These are higher-level patterns that influence the architecture of a system.

### **5.1 Model-View-Controller (MVC)**  
Separates concerns into model (data), view (UI), and controller (logic).

### **5.2 Model-View-ViewModel (MVVM)**  
A variation of MVC where the ViewModel acts as an intermediary.

### **5.3 Microservices**  
Breaks a system into loosely coupled services that communicate over a network.

### **5.4 Layered Architecture**  
Organizes a system into layers (presentation, business logic, data).

### **5.5 Event-Driven Architecture**  
Uses events to trigger actions asynchronously.

### **5.6 Pipe and Filter**  
Passes data through a sequence of processing elements.

### **5.7 Blackboard**  
Multiple components work together by reading and writing to a common data structure.





The documentation for a design pattern describes the context in which the pattern is used, the forces within the context that the pattern seeks to resolve, and the suggested solution.[27] There is no single, standard format for documenting design patterns.

Design Patterns: Elements of Reusable Object-Oriented Software (1994) is a software engineering book describing software design patterns. The book was written by Erich Gamma, Richard Helm, Ralph Johnson, and John Vlissides, with a foreword by Grady Booch. The book is divided into two parts, with the first two chapters exploring the capabilities and pitfalls of object-oriented programming, and the remaining chapters describing 23 classic software design patterns. The book includes examples in C++ and Smalltalk. 

A commonly used software design pattern documentation format is the one used in book Design Patterns. It contains the following sections:

    Pattern Name and Classification: A descriptive and unique name that helps in identifying and referring to the pattern.
    Intent: A description of the goal behind the pattern and the reason for using it.
    Also Known As: Other names for the pattern.
    Motivation (Forces): A scenario consisting of a problem and a context in which this pattern can be used.
    Applicability: Situations in which this pattern is usable; the context for the pattern.
    Structure: A graphical representation of the pattern. Class diagrams and Interaction diagrams may be used for this purpose.
    Participants: A listing of the classes and objects used in the pattern and their roles in the design.
    Collaboration: A description of how classes and objects used in the pattern interact with each other.
    Consequences: A description of the results, side effects, and trade offs caused by using the pattern.
    Implementation: A description of an implementation of the pattern; the solution part of the pattern.
    Sample Code: An illustration of how the pattern can be used in a programming language.
    Known Uses: Examples of real usages of the pattern.
    Related Patterns: Other patterns that have some relationship with the pattern; discussion of the differences between the pattern and similar patterns.





Anti-Patterns

Service locator