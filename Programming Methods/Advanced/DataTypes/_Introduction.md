Data Typing

## Overview
In computer science and computer programming, a data type is an attribute of any specific block of memory aka a data unit. Almost all programming languages explicitly include the notion of data typing, though different languages may use different terminology.

In general, a program manipulates data units using their associated variables through identifiers named by the programmer or built into the language standard.

Thus, each variable's associated data unit has a given data type that generally consists of a concrete implementation understood by the system, and two levels of logical abstraction, one that specifies relationships defined by developers and one that follows a logical model understood by end users.

The terms used to reference these respective abstraction levels are:
  Concrete Data Type
  Data Structure
  Abstract Data Type


### Concrete Data Type
Term referencing the concrete implementation used by the underlying system to arrange and manipulate a specific block of memory, the bits that represent a given data unit.


### Data Structure
Term referencing the relationships that the physical form of the data type, the concrete implementation, must maintain to enable the operations defined by ADTs.

used by system developers to organize, manage, and format a data unit.


### Abstract Data Type
Term referencing the interface that supports end user (client of a data type) interactions with a mathematical model defining the logical form and behaviors which correspond to data units of a given type, completely uncoupled from the underlying implementation.



### Real World Example
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


The mathematical integers are modeled by one of the most common data types, also most typically called "integers" in various languages. We shall use this relationship to explore both the concrete and abstract data type used to computationally represent the mathematical integers.

In computer science, an integer is a data unit of the type which computationally represents some range of mathematical integers. At a high level of abstraction, data possessing the integer type behaves in much the same way we would expect a mathematical integer. However, the concrete implementation exhibited at the system level will display considerable differences.

To summarize, at the system level, groups of individual bits are used to form primitive data types, the basic building blocks of programming languages. Primitive data types, either on their own or joined into composite data types, form the concrete implementation of data structures. Data structures manage the relationships necessary to computationally realize the mathematical model specified by abstract data types. The mathematical models specified by Abstract Data Types are the key enabling factor in provably correct algorithms that provide solutions to real world problems.

Data Structures have great importance as efficient data structures allow us to design efficient algorithms. The more efficient an algorithm is, the more real world value it possesses. Thus, data structures are a key organizing factor in software design.

"Bad programmers worry about the code. Good programmers worry about data structures and their relationships. ”
— Linus Torvalds
