Data Typing

Summary
A data type specifies the behavior of a specific block of memory representing a unit of data at various levels of abstraction which range from the concrete system level details to the logical abstraction understood by end users.
This behavior generally includes the data unit's general format, a set of valid values, the operations performed on those values, and the logical behavior of those operations.


Overview
In computer science and computer programming, a data type is an attribute of each unit of data. A program manipulates data units using their associated variables through identifiers named by the programmer or built into the language standard. Thus, each variable's associated data unit has a given data type that informs both the underlying system and the end user how that data unit is to behave.

Almost all programming languages explicitly include the notion of data typing, though different languages may use different terminology. A data type generally consists of a concrete implementation understood by the system, and two levels of logical abstraction, one that specifies relationships defined by developers and one that follows a logical model understood by end users.

Components of a data type:

Concrete Data Type
Term referencing the concrete implementation used to inform the compiler or interpreter how the underlying system should arrange and manipulate a specific block of memory representing a data unit.

Data Structure
Term referencing the implementation of abstractions used by system developers to organize, manage, and format a data unit.

Abstract Data Type
Term referencing the logical abstraction used by end users to understand the mathematical model that dictates the behavior of a data unit of a given type. This model defines the possible values of the data and what are interface exposed by it.


Provided are outlines of both Concrete Data Typing and Abstract Data Typing to serve as a foundation to explore Data Structures. We begin by outlining a real world example of a type of data.









We begin our data typing journey with a "real-world" example of data with which many are familiar.

The mathematical integers are one of the most common types of data for which many individuals have developed some level of rigorous theoretical understanding. We are taught from a young age of their general format, valid values, operations we can perform with those values, and the logical behavior that produces the results of those operations. While terminology from formal mathematics is used to provide an avenue for future learning, the information relevant to the understanding of this discussion is provided after each term.

Properties of mathematical integers:

Valid Values:
The set of integer values consists of zero (0), the positive natural numbers (1, 2, 3, ...), and their additive inverses (the negative integers, i.e., −1, −2, −3, ...).

Format:
We represent integer values in written format as numerals, using Arabic numbers (0,1,2, … 8, 9) arranged as numeric digits, where each numeral is a sequence of digits which may be of arbitrary (any) length.

Operations:
The set of integers is "closed" under certain arithmetic operations, like addition and multiplication. A set is closed under an operation if performance of that operation on members of the set always produces a member of that set. If we add or multiply two integer values together the result will always be another integer value.
(An operation like division involves all real numbers (result values may require decimal digits))


The mathematical integers are modeled by one of the most common data types, also most typically called integers. We shall use this relationship to explore both the concrete and abstract data type used to computationally represent the mathematical integers.

In computer science, an integer is a data unit of the type which computationally represents some range of mathematical integers. At a high level of abstraction, data possessing the integer type behaves in much the same way we would expect a mathematical integer. However, the concrete implementation exhibited at the system level will display considerable differences.



Concrete Data Type

A data types concrete implementation enforces behavior by
  Constraining the values that can be assigned to it
  Determining the way its value is stored by the computer
  Defining the operations that the system can performed using it

Concrete data types can generally be broken down into two broad classes:
  Primitive data types
  Composite data types

Primitive Types

A primitive data type is either of the following:
Basic type: A data type provided by a programming language as a basic building block.
Built-in type: A data type for which the programming language provides built-in support.

In most programming languages, all basic data types are built-in.
A single mathematical integer can be represented by a data unit of the integer type, a primitive type common to many, if not all, systems.

Properties of computational integer's concrete data type:

Valid Values:
The value of a data unit with an integral type is the mathematical integer that it corresponds to. Integral types may be unsigned (capable of representing only non-negative integers) or signed (capable of representing negative integers), this is system dependent.

(Storage) Format:
The internal representation of integer data is the way the value is stored in the computer's memory. Unlike mathematical integers, a typical computational integer data unit has some minimal and maximum possible value. Integers are commonly represented in a computer as a group of binary digits (bits). The order of the memory bytes storing the bits varies; see endianness. The width or precision of an integral type is the number of bits in its representation. There are four well-known ways to represent signed numbers in a binary computing system. The most common is two's complement, which allows a signed integral type with n bits to represent numbers from −2(n−1) through 2(n−1) −1, where as an unsigned type typically represents the non-negative values 0 through 2(n) −1. Other possibilities include offset binary, sign-magnitude, and ones' complement. Some computer languages define integer sizes in a machine-independent way; others have varying definitions depending on the underlying processor word size (the natural unit of data used by a particular processor design). Not all language implementations define variables of all integer sizes, and defined sizes may not even be distinct in a particular implementation.

Operations:
Operations performed with computational integers are those defined by the system, typically these operations are consistent with operations on the mathematical integers, additionally functions that take the computational integer data type as their parameters, analogous to mathematical functions.

The primitive data types available for a program's implementation is dependent upon the specific programming language being used.  

Typical primitive types include:
  Character (character, char)
  Integer (integer, int, short, long, byte) with a variety of precisions
  Floating-point number (float, double, real, double precision)
  Fixed-point number (fixed) with a variety of precisions and a programmer-selected scale.
  Boolean, logical values true and false.
  Reference (also called a pointer or handle or descriptor), a value referring to another object.

The above primitives are generally supported more or less directly by computer hardware, so operations on primitives are usually fairly efficient ( with the possible exception of floating point values)

A general overview of each primitive type can be found: here
https://en.wikipedia.org/wiki/Primitive_data_type#Specific_primitive_data_types


Composite Types

We could implement all of our programs using only the primitive types, but it is much more convenient to implement programs at a higher level of abstraction. So, In addition to primitive types, many languages also provide a set of composite data types.

In computer science, a composite data type or compound data type is any data type which can be constructed in a program using the programming language's primitive data types and other composite types. The act of constructing a composite type is known as composition.

Composite types derived from primitive types include:
Arrays:        Stores a sequence of elements, typically of the same data type.
Records:    Contains values, typically a fixed number and sequence, of potentially mixed type. The elements of records are usually called fields or members.
Unions:        A definition that specifies which of a number of permitted primitive types may be stored in its instances, e.g. "float or integer". Contrast with a record, which could be defined to contain a float and an integer; whereas, in a union, there is only one type allowed at a time.
Objects:    A definition of a number of data fields, like a record, and also a number of subroutines for accessing or modifying them, called methods.

Many others are possible, but they tend to be further variations and compounds of the composite types above.

A group of mathematical integers may be represented by a composite type. Composing a primitive type into a compound type generally results in a new type, e.g. array-of-integer is a different type to integer.

The assortment of primitive and composite types a language possesses and how they act is formalized by its type system.








Abstract Data Type
An abstract data type (ADT) is the mathematical model that serves as the interface visible to the end user of a data type.

Abstract data types (ADT) separate their logical properties from the implementation details.

Like any other data type such as an integer, an ADT has three things associated with it:
the name of the ADT, called the type name
the set of values belonging to the ADT, called the domain
the set of operations on the data.

While concrete data typing is beneficial in specifying meaningful code which defines how the implementer or programmer intends the compiler or interpreter to enforce data behavior. An abstract data type is defined by its behavior from the point of view of an end user, of the data, specifically in terms of possible values, possible operations on data of this type, and the behavior of these operations.

Though the mathematical models presented to us since childhood, we have developed a shared intuition regarding the behavior of different types of data. We shall see that the concepts presented by interactions with abstract data types are those closest to our own understanding of the behavior of data and are on the other end of the conceptual spectrum from the concrete data types understood by the computational system.

ADTs are a theoretical concept, in computer science, used in the design and analysis of algorithms, data structures, and software systems, and do not correspond to specific features of computer languages — mainstream computer languages do not directly support formally specified ADTs. However, various language features correspond to certain aspects of ADTs. The central concept related to abstract data types is the "interface" to an abstract data type. This is the set of operations that the abstract data type provides that can be used to manipulate values of the data type.

We again use integers as an example when first exploring abstract data types. We discussed Integers as an example of a primitive data type and briefly discussed the concrete internal representation using bits. However, the complexity of this underlying representation is exactly what is avoided when we consider the Integer through a higher level of abstraction. As an end user, we are unconcerned with how the individual bits of an integer value are moved around the computer while they are stored and processed. The complexity of these operations and the systems concrete representation are abstracted away so that we may focus on what we would like to use the integer data for, rather than how the system performs integer operations.

When we consider the integers through the lens of the mathematical model capture by their ADT, we understand we are working with:
  The values ..., −2, −1, 0, 1, 2, ...,
  The operations of addition, subtraction, multiplication, and division, together with greater than, less than, etc., which proceed according to familiar mathematics (with care for integer division).
  The "behavior" we know to apply to mathematical integers, which includes obeying various axioms (associativity and commutativity of addition, etc.), and preconditions on operations (cannot divide by zero).

All of this understanding of what an integer is and how to work with them is independent of their representation by the computer. We are free to imagine them operating as they would "normally" following the model of mathematics by which humans perform arithmetic calculations.

For an example of an ADT that originates from computer science and uses composite types rather than primitive, we explore the abstract stack. In computer science, a stack is an abstract data type that serves as a collection of elements, with two principal operations:
    push:    Adds an element to the collection
    pop:    Removes the most recently added element that was not yet removed.

We can picture an abstract stack similar to a stack of plates, adding or removing a plate is only easily achieved at a single location, the topmost place in the stack. Similar to this abstraction, the push and pop operations of a stack occur only at one end of the composite structure, referred to as the top of the stack.

Thus, for example, an abstract stack can be implemented by an array, a composite type representing a sequence of elements. The array is given the added restriction of emulating the push and pop operations by only adding/removing elements from the array's end, which we now refer to as the top.

A stack of plates                A stack of integers

Abstract data types are purely theoretical entities, used (among other things) to simplify the description of abstract algorithms, to classify and evaluate data structures, and to formally describe the type systems of programming languages.


The mathematical model presented by an abstract data type contrasts with its underlying type system and data structures, which represent the concrete organization of data at the system level. While a computational system typically has only one way of expressing concrete data types, an ADT may be implemented by specific data types or data structures in many ways, each providing a logically equivalent interface. Implementing an ADT means providing one procedure or function for each abstract operation. The ADT instances are represented by some concrete data structure that is manipulated by those procedures, according to the ADT's specifications.

Example common ADTs, proven useful in a great variety of applications:
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

An ADT consists of two parts:
1. Declaration of data
2. Declaration of operations


Abstract data types are mathematical abstractions; nowhere in an ADT’s definition is there any mention of how the set of operations is implemented.

Implementation of ADTs should appropriately hide implementation details. Thus any other part of the program that needs to perform an operation on the ADT can do so by calling the appropriate method.

If for some reason implementation details need to be changed, it should be easy to do so by merely changing the routines that perform the ADT operations. This change, in a perfect world, would be completely transparent to the rest of the program.

There is no rule telling us which operations must be supported for each ADT; this is a design decision. Error handling and tie breaking (where appropriate) are also generally up to the program designer


Advantages of abstract data typing

Encapsulation
Abstraction provides a promise that any implementation of the ADT has certain properties and abilities; knowing these is all that is required to make use of an ADT object. The user does not need any technical knowledge of how the implementation works to use the ADT. In this way, the implementation may be complex but will be encapsulated in a simple interface when it is actually used.

Localization of change
Code that uses an ADT object will not need to be edited if the implementation of the ADT is changed. Since any changes to the implementation must still comply with the interface, and since code using an ADT object may only refer to properties and abilities specified in the interface, changes may be made to the implementation without requiring any changes in code where the ADT is used.

Flexibility
Different implementations of the ADT, having all the same properties and abilities, are equivalent and may be used somewhat interchangeably in code that uses the ADT. This gives a great deal of flexibility when using ADT objects in different situations. For example, different implementations of the ADT may be more efficient in different situations; it is possible to use each in the situation where they are preferable, thus increasing overall efficiency.





We now have an overview of how the meaning of a given data instance is generally communicated to system hardware via concrete data typing, as well as how end users are protected from implementation details through the use of abstract data typing. We can now discuss how to bridge the gap between the concrete implementation and the logical abstraction.

Data structures serve to make the utilization of abstract data types (ADT) computationally feasible. The ADT defines the logical form of the data type while a data structure specifies the relationship that the physical form of the data type, the concrete implementation, must maintain to enable the operations defined by ADTs.

"Data structure" is a very general term of theoretical computer science. Any technique for the organization of machine-manipulable data can be thought of as a data structure. Even a single machine integer is a data structure, because there's more than one way that the bits could be interpreted.

This brings us to an important distinction, every Concrete Data Type is a Data Structure but not every data structure is a concrete data type.

A data structure is distinct from its underlying concrete data implementation as it maintains some abstract relationship that enables the functionality specified by an ADT.

Data structures are generally based on the ability of a computer to fetch and store data at any place in its memory, specified by a pointer—a bit string, representing a memory address, that can be itself stored in memory and manipulated by the program. While the underlying concrete implementation is responsible for maintaining individual data units, the data structure is responsible for orchestrating those units and ensuring that the individual operations performed on data units of concrete type coalesce to support the behavior specified by the ADT.


To summarize, at the system level, groups of individual bits are used to form primitive data types, the basic building blocks of programming languages. Primitive data types, either on their own or joined into composite data types, form the concrete implementation of data structures. Data structures manage the relationships necessary to computationally realize the mathematical model specified by abstract data types. The mathematical models specified by Abstract Data Types are the key enabling factor in provably correct algorithms that provide solutions to real world problems.

Data Structures have great importance as efficient data structures allow us to design efficient algorithms. The more efficient an algorithm is, the more real world value it possesses. Thus, data structures are a key organizing factor in software design.

"Bad programmers worry about the code. Good programmers worry about data structures and their relationships. ”
— Linus Torvalds
