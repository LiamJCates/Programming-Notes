Object-Oriented Paradigm

an approach to programming that breaks a programming problem into objects that interact with each other.

In the most general sense, a program can be organized in one of two ways:
around its code (what is happening)
around its data (what is being affected).

Structured programming techniques organize around code.
“code acting on data.”
Traditional structured programming consists of designing a set of procedures (or algorithms) to solve a problem. Once the procedures are determined, the traditional next step was to find appropriate ways to store the data.

Software design using the object oriented paradigm focuses on objects and operations on objects. The object-oriented approach combines the power of the procedural paradigm with an added dimension that integrates data with operations into objects. In procedural programming, data and operations on the data are separate, and this methodology requires passing data to methods.

Object-oriented programming places data and the operations that pertain to them in an object. This approach solves many of the problems inherent in procedural programming. The object-oriented programming approach organizes programs in a way that mirrors the real world, in which all objects are associated with both attributes and activities. Using objects improves software reusability and makes programs easier to develop and easier to maintain. Programming in Java involves thinking in terms of objects; a Java program can be viewed as a collection of cooperating objects.

Object-oriented programs reverse the order: putting the data first, then looking at the algorithms to operate on the data. They are organized around data, with the key principle being “data controlling access to code.” In an object-oriented language, you define the data and the routines that are permitted to act on that data. Thus, a data type defines precisely what sort of operations can be applied to that data. To support the principles of object-oriented programming, all OOP languages, including Java, have three traits in common: encapsulation, polymorphism, and inheritance.

Object-oriented programming (OOP) involves programming using objects. An object represents an entity in the real world that can be distinctly identified.

An object has a unique identity, state, and behavior.
■ The state of an object (also known as its properties or attributes) is represented by data fields with their current values.
■ The behavior of an object (also known as its actions) is defined by methods. To invoke a method on an object is to ask the object to perform an action.

Objects of the same type are defined using a common class.
















Object-oriented programming (OOP) revolves around the concept of an object.

Objects, however, are created using a class definition. A class is a template in accordance to which objects are created. A class is a piece of software that includes a data specification and functions operating on that data.

Functions defined in a class are called methods, member functions, or function members, and variables used in a class are called data members
(more properly, they should be called datum members).

This combining of the data and related operations is called data encapsulation.

An object is an instance of a class, an entity created using a class definition.

In contradistinction to functions in languages that are not object-oriented, objects make the connection between data and member functions much tighter and more meaningful. In languages that are not object-oriented, declarations of data and definitions of functions can be interspersed through the entire program, and only the program documentation indicates that there is a connection between them. In OOLs, a connection is established right at the outset; in fact, the program is based on this connection. An object is defined by related data and operations, and because there may be many objects used in the same program, the objects communicate by exchanging messages that reveal as little detail about their internal structure as necessary for adequate communication. Structuring programs in terms of objects allows us to accomplish several goals.

First, this strong coupling of data and operations can be used much better in modeling a fragment of the world, which is emphasized especially by software engineering.

Second, objects allow for easier error finding because operations are localized to the confines of their objects. Even if side effects occur, they are easier to trace.

Third, objects allow us to conceal certain details of their operations from other objects so that these operations may not be adversely affected by other objects. This is known as the information-hiding principle.
