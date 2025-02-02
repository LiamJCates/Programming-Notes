# Data Structure

A data structure is a particular way of organizing relationships between data elements so that operations on them may be performed reliably and efficiently.

More formally, a data structure is defined by:
  a collection of data values
  the relationships among constituent data elements
  operations that maintain those relationships

Data structures support the utilization of abstract data types logical models by specifying computationally feasible mechanisms that maintain relationships  between underlying concrete system representations.

While the underlying concrete implementation is responsible for maintaining the physical form of data units, the data structure is responsible for orchestrating those units and ensuring that the individual operations performed on data units coalesce to support the behavior specified by the ADT.

"Data structure" is a very general term of theoretical computer science. Any technique for the organization of data units can be thought of as a data structure, because there's more than one way that the relationship between component bits could be interpreted.



### Data Structure Classification

Before processing the data in any application, we must decide how we want to interact with a data unit of a given type. The answer to that question depends on the operations we want to perform on the data and the frequency of the operations. We should choose an organization that allows the best performance in terms of latency, memory footprint, or any other parameter, without affecting the correctness of the application.

Different types of data structures are suited to different kinds of applications, and some are highly specialized to specific tasks.

Data Structures can be partitioned into
  Primitive
  Non-Primitive  



### Primitive

Primitive data structures are the fundamental data structures or predefined data structures which are supported by a programming language and are typically directly operated upon by machine-level instructions

A primitive data type is either of the following:
  Basic: A data type provided as a basic building block.
  Built-in: A data type with built-in language support.

In most programming languages, all basic data types are built-in.

The primitive data types available for a program's implementation is dependent upon the specific programming language being used.  

Common Primitive Data Types
  Boolean
  Character
  Floating-point numbers
  Fixed-point numbers
  Integer
  Reference (also called a pointer or handle)
  Date Time

The above primitives are generally supported more or less directly by computer hardware, so operations on primitives are usually fairly efficient ( with the possible exception of floating point values)

A general overview of each primitive type can be found here:
https://en.wikipedia.org/wiki/Primitive_data_type#Specific_primitive_data_types




### Non-Primitives

Non-Primitive Data Types are more complex data types comprised of multiple primitive data types.

We could implement all of our programs using only the primitive types, but it is much more convenient to implement programs at a higher level of abstraction. So, In addition to primitive types, many languages also provide a set of composite data types.

In computer science, a composite data type or compound data type is any data type which can be constructed in a program using the programming language's primitive data types and other composite types. The act of constructing a composite type is known as composition.

Composite types derived from primitive types include:
| Type | Explanation |
|------|-------------|
| Array | Stores a sequence of elements, typically of the same data type |
| Record | Contains values, typically a fixed number and sequence, of potentially mixed type. The elements of records are usually called fields or members |
| Unions | A definition that specifies which of a number of permitted primitive types may be stored in its instances, e.g. "float or integer". Contrast with a record, which could be defined to contain a float and an integer; whereas, in a union, there is only one type allowed at a time |
| Objects | A definition of a number of data fields, like a record, and also a number of subroutines for accessing or modifying them, called methods |

Many others are possible, but they tend to be further variations and compounds of the composite types above.

Composing a primitive type into a compound type generally results in a new type.

A group of mathematical integers may be represented by a composite type, e.g. an array of integers, creating type different from an individual integer.

The assortment of primitive and composite types a language possesses and how they act is formalized by its type system.




For information regarding common data structures, see:
[Data Structures\CommonStructures]
