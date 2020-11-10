### Class
In Java programs, classes are the basic building blocks. When defining
a class, you describe all the parts and characteristics of one of those
building blocks. To use most classes, you have to create objects. An
object is a runtime instance of a class in memory. An object is often
referred to as an instance since it represents a single representation of
the class. All the various objects of all the different classes represent
the state of your program. A reference is a variable that points to an
object.


In Java, everything goes in it's own class and every Java application has to have at least one class
Each java source file typically holds one class or interface definition.
The programs used by clients typically consist of a collection of classes


Q: Why does everything have to be in a class?
A: Java is an object-oriented (OO) language. It’s solution space consists of abstract representations of the physical world called objects, each object is defined by its own class.

A class is a template or contract that defines an object.
Java uses a class specification to inform the JVM how to construct objects of that classes' type.
An object is an instance of a class.

Important: a class is a logical abstraction.
It is not until an object of that class has been created, called instantiation, that a physical representation of that class exists in memory

Objects are entities in program memory with three characteristic properties: State, Behavior, Identity

Once an object has been constructed/instantiated it is given an identity / reference

All Java code is defined in classes
The code and data that constitutes a class are called class members.

Class members define the object's state and behaviour.
Data elements which define an object's state are referred to as its fields, attributes, or instance variables.
The code that operates to enact an object's behaviour are referred to as its methods.


Q: What’s the difference between a class and an object?
A: Classes are object recipes.

A class informs the java virtual machine (JVM) how to make an object of that particular type. Each object made from that class can have its own values for the instance variables of that class.
For example, you might use the Button class to make dozens of different buttons, and each button might have its own color, size, shape, label, and so on.


The simplest Java class you can write looks like this:
public class Name {}


The syntax for declaring a basic class is as follows:

class ClassName {
  // declare instance variables
  type var1;
  // …
  type varN;

  // declare methods
  type method1(parameters) {  // body of method }
  // …
  type methodN(parameters) { // body of method }
}


We begin class definitions with the "class" keyword to indicate that we are declaring a class,
We follow this with the class name. Use PascalCasing when naming classes, capitalizing the first letter of each word.


Java class body elements:

» Fields:         Variable declarations define class fields.
» Methods:         Method declarations define class methods.
» Constructors:         Special methods that instantiate class objects, returning a new object reference.
» Initializers:         Code blocks executed only once whenever an instance of a class is created.
» Other classes:        A class can include another class, called "inner" or "nested" classes.
» Interfaces:         Classes can contain interfaces.

Unlike some programming languages, Java doesn’t care about the order of class members.
However, good programming practice dictates a consistent structure. That way you know where to find them.
One method is:
» Fields together at the start of the class, followed by constructors and then methods.
» Initializers are placed near the fields they initialize.
» Inner classes and interfaces are placed after the methods that use them.
