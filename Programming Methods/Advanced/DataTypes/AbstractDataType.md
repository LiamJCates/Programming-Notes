## Abstract Data Type
Abstract data types (ADT) dictate the logical properties of a data unit of a  given type and presents an interface to a data type's client.

An ADT encompasses:
	the set of values belonging to the ADT, called the domain
	the set of operations, and the logical behavior of those operations

An ADT is a mathematical model, defined by its behavior (semantics) from the point of view of a user, of the data, specifically in terms of possible values, possible operations on data of this type, and the behavior of these operations.

The mathematical model presented by an ADT contrasts with an underlying data structure and type system, which represent the concrete organization of data at the design and system level. In this sense, ADTs inhabit the opposite end of the conceptual spectrum from the concrete data types understood by the computational system. While a computational system typically has a predetermined method of efficiently expressing concrete data types, an ADT may be implemented by a myriad of data types and structures, each providing a logically equivalent interface.

ADTs are used (among other things), in computer science, to simplify the description and analysis of abstract algorithms, to classify and evaluate data structures, and to formally describe the type systems of programming languages.

ADTs are a theoretical model and do not correspond to specific features of computer languages. However, various language features support the implementation of ADTs.

Completely implementing an ADT means providing one procedure or function for each abstract operation specified by the mathematical model. The ADT instances are represented by some concrete data structure that is manipulated by those procedures, according to the ADT's specifications. When using an ADT for the proposes of implementing a given algorithm there is no rule telling us which operations must be supported; this is a design decision. Error handling and tie breaking (where appropriate) are also generally up to the program designer.


### Integer Example
We again use integers as an example when first exploring abstract data types.

We discussed Integers as an example of a primitive data type and briefly discussed the concrete internal representation using bits. However, the complexity of this underlying representation is exactly what is avoided when we consider the integer type through a higher level of abstraction. As an end user, we are unconcerned with how the individual bits of an integer value are moved around the computer while they are stored and processed. The complexity of these operations and the systems concrete representation are abstracted away so that we may focus on what we would like to use the integer data for, rather than how the system interprets integer and performs operations on them.

When we consider the integers through the lens of the mathematical model capture by their ADT, we understand we are working with:
  The values ..., −2, −1, 0, 1, 2, ...,
  The operations of addition, subtraction, multiplication, and division, together with greater than, less than, etc., which proceed according to familiar mathematics.
  The "behavior" we know to apply to mathematical integers, which includes obeying various axioms (associativity and commutativity of addition, etc.), and preconditions on operations (cannot divide by zero).

All of this understanding of what an integer is and how to work with them is independent of their representation by the computer. We are free to imagine them operating as they would "normally" following the model of mathematics by which humans perform arithmetic calculations.


### Stack Example
For an example of an ADT that originates from computer science and uses composite types rather than primitive, we explore the abstract stack.

In computer science, a stack is an abstract data type that serves as a collection of elements, with two principal operations:
    push:	Adds an element to the collection
    pop:	Removes the most recently added element that was not yet removed.

We can picture an abstract stack similar to a stack of plates, adding or removing a plate is only easily achieved at a single location, the topmost place in the stack. Similar to this abstraction, the push and pop operations of a stack occur only at one end of the composite structure, referred to as the top of the stack.
Thus, for example, an abstract stack can be implemented by an array, a composite type representing a sequence of elements. The array is given the added restriction of emulating the push and pop operations by only adding/removing elements from the array's end, which we now refer to as the top.


### Common ADTs
Common ADTs, proven useful in a great variety of applications, include:
  Container
  List
  Set
  Multiset
  Map
  Multimap
  Graph
  Tree
  Stack
  Queue
  Priority queue
  Double-ended queue
  Double-ended priority queue


Advantages of abstract data typing

Abstraction
Abstract data types are mathematical abstractions; nowhere in an ADT’s definition is there any mention of how the set of operations is implemented. The end user of an ADT does not need to worry about any underlying implementation details, only in interface available to the rest of the system.

Encapsulation
Abstraction provides a promise that any implementation of the ADT has certain properties and abilities; knowing these is all that is required to make use of an ADT object. The user does not need any technical knowledge of how the implementation works to use the ADT. In this way, the implementation may be complex but will be encapsulated in a simple, reliable, and efficient interface when it is actually used.

Localization of change
Code that uses an ADT object will not need to be edited if the implementation of the ADT is changed. Since any changes to the implementation must still comply with the interface, and since code using an ADT object may only refer to properties and abilities specified in the interface, changes may be made to the implementation without requiring any changes in code where the ADT is used.

Flexibility
Different implementations of the ADT, having all the same properties and abilities, are equivalent and may be used somewhat interchangeably in code that uses the ADT. This gives a great deal of flexibility when using ADT objects in different situations. For example, different implementations of the ADT may be more efficient in different situations; it is possible to use each in the situation where they are preferable, thus increasing overall efficiency.
