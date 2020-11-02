A UML class diagram describes the fields and methods of one or more classes

identifies the Vocabulary of our system.

class diagram illustrates class templates and objects in a system, attributes, and operations of each class and the relationship between each class.

helps us understand and have a common language between all members of the team.

defines Relationships between entities in our system, our nouns.






Class Diagrams

Classes represent Nouns within our system.
[import class structure png]
Classes are boxes with three sections
class name or title
attributes
operations

It's also possible to omit these sections if the details are unnecessary for a particular diagram.
We can drop off both the Attributes and the Operations or potentially we only drop one of them.

+----------------------------------------------------------+
|                     ClassName                            |
+----------------------------------------------------------+
|              - privateFieldName : Type                   |
|              + publicFieldName : Type                    |
+----------------------------------------------------------+
| - privateMethodName( Parameter Type List ) : Return_Type |
| + publicMethodName( Parameter Type List ) : Return_Type  |
+----------------------------------------------------------+


Fields and Methods can be marked with
|+    indicates a public access member
|-    indicates a private access member


For each field, the diagram gives access modifier, the name of the field, a colon, and the data type.

For each method, the diagram gives access modifier, the name of the method, a set of parentheses, the data type of each parameter in the parentheses, then a colon, followed by the data type that's returned by the method.

A UML diagram may not show constructors, variable's access modifiers, and some members might be hidden if they are not necessary to show class logic/ are only used internally


[circle example]



















## Users
Class Diagrams can be used by anybody related to the system, but these are some of the common roles and how they relate.

Product Owners confirm our vocabulary of the system and the terminology that is used in the business space in which our software is being used.

Business Analysts facilitate communication between the technical people, the architects and developers, and the Product Owner. They become quite skilled in both the business and the technology and help these communications go forward. They also represent the Product Owner quite often to the technical team.

The Architect often creates most of the UML artifacts

The Developer consumes Class Diagrams,
sometimes they'll create them as well, but largely they'll take Class Diagrams that have been created and they will implement the objects, the classes, that use these Class Diagrams or that implement the Class Diagrams











## Relationships
In a large system with many related classes, classes are grouped together to create class diagrams. Different relationships between classes are shown by different types of arrows.

[import relationship type png]
[import relationship type2 png]


Relationships Between Classes
To design classes, you need to explore the relationships among classes. The common relationships among classes are association, aggregation, composition, and inheritance.

Association
Association is a general binary relationship that describes an activity between two classes.
For example, a student taking a course is an association between the Student class and the Course class, and a faculty member teaching a course is an association between the Faculty class and the Course class. These associations can be represented in UML graphical notation:

[Association example png]

This UML diagram shows that a student may take any number of courses, a faculty member may teach at most three courses, a course may have from 5 to 60 students, and a course is taught by only one faculty member.
An association is illustrated by a solid line between two classes with an optional label that describes the relationship.

Each class involved in the relationship may have a role name that describes the role it plays in the relationship. In Figure 10.4, teacher is the role name for Faculty. Each class involved in an association may specify a multiplicity, which is placed at the side of the class to specify how many of the class’s objects are involved in the relationship in UML. A multiplicity could be a number or an interval that specifies how many of the class’s objects are involved in the relationship. The character * means an unlimited number of objects, and the interval m..n indicates that the number of objects is between m and n, inclusively. In Figure 10.4, each student may take any number of courses, and each course must have at least 5 and at most 60 students. Each course is taught by only one faculty member, and a faculty member may teach from 0 to 3 courses per semester

In Java code, you can implement associations by using data fields and methods.

Aggregation and Composition
Aggregation is a special form of association that represents an ownership relationship between
two objects. Aggregation models has-a relationships. The owner object is called an aggregating
object, and its class is called an aggregating class. The subject object is called an aggregated
object, and its class is called an aggregated class.
We refer aggregation between two objects as composition if the existence of the aggregated
object is dependent on the aggregating object. In other words, if a relationship is composition,
the aggregated object cannot exist on its own. For example, “a student has a name” is a composition
relationship between the Student class and the Name class because Name is dependent on
Student, whereas “a student has an address” is an aggregation relationship between the Student
class and the Address class because an address can exist by itself. Composition implies exclusive
ownership. One object owns another object. When the owner object is destroyed, the dependent
object is destroyed as well.

In UML, a filled diamond is attached to an aggregating class (in this case, Student) to denote the composition relationship with an aggregated class (Name), and an empty diamond is attached to an aggregating class (Student) to denote the aggregation relationship with an aggregated class (Address):

[Aggregation and Composition png]


An aggregation relationship is usually represented as a data field in the aggregating class.

Aggregation may exist between objects of the same class.

For example, a person may have a supervisor:
[SingleAggregation.png]

If a person can have several supervisors, you may use an array to store supervisors
[MultiAggregation.png]












"Is A" relationships

Interface
Similar to a class
Interface title uses a stereotype        <<Interface>>
a dashed line with enclosed arrowhead, pointing to the interface being implemented

Inheritance
a solid line with enclosed arrowhead, pointing to the parent of the derived/generalized class

[import class interface and inheritance png]

Concepts to keep in mind: Abstract and Concrete Classes.
An Abstract Class is a class that we can't ever instantiate
Abstract Class names are italicized or a stereotype is used

Concrete Classes being some kind of a class that we can actually instantiate.
The Concrete Classes are the default, so no special notation is given to them











"Has A" relationship.

Has-A relationships invoke multiplicity in their relationships
How many items on each side of the relationship can exist?

numbers at the two endpoints of the representative lines denote multiplicity

Some typical examples of multiplicity:
Multiplicity
Option
Cardinality
0..0
0
Collection must be empty

0..1
No instances or one instance

1..1
1
Exactly one instance

0..*
*
Zero or more instances

1..*
At least one instance

5..5
5
Exactly 5 instances

m..n
At least m but no more than n instances



Aggregation
In Aggregation, we're identifying a part of a whole
a solid line, with an unfilled diamond, at the container class.

Composition
a solid line, with a filled diamond at the owner class. We can still show multiplicity and in this case one customer can have many addresses.

The difference between Composition and Aggregation is in Composition, really the item that is related to the base doesn't stand on its own so much.


[import Composition and Aggregation png]

 The top diagram on top shows Composition:
A Car has exactly one Carburetor, and a Carburetor is a part of one Car. Carburetors cannot exist as separate parts, detached from a specific car.
The bottom diagram shows Aggregation:
A Pond has zero or more Ducks, and a Duck has at most one Pond (at a time). Duck can exist separately from a Pond.

Uses relationship. Dependency
a dashed line with an open arrow pointing to the classes that are used by a class
a dependency between classes
helps us understand that if a used class were to change, that could have an affect on the class using them


Association
Represents a relationship where by one entity makes the other perform some action in its behalf
a straight, solid line, between two entities


Generalizations/Inheritance
Represents a class one generalization anyway, where we inherit from one class to another and we create a specialized version of it.
a solid line with enclosed arrowhead, pointing to the parent of the derived/generalized class

Implementation.
a dashed line with enclosed arrowhead, pointing to the interface being implemented

Dependency
identifies a relationship where one object is dependent upon the other.
a dashed line with an open arrowhead
The object that is pointed to with the arrowhead is the one on which the other is dependent.
