Primitives are Efficient
Java uses primitive types to hold the basic data types supported by the language. Primitive types, rather than objects, are used for these quantities for the sake of performance. Using objects for these basic types would add an unacceptable overhead to otherwise simple calculations.

Wrapper Classes
However, Java is an object-oriented language and much of the language revolves around the idea of treating everything as an object. Hence, oftentimes, despite the performance benefit, we find it necessary to convert a primitive type into an object.

To facilitate this conversion, Java provides us with what is known as wrapper classes.
Each primitive type in Java has a corresponding wrapper class.
Wrapper class names are their primitive type with the first letter capitalized.
The wrapper classes for boolean, char, byte, short, int, long, float and double:
Boolean, Character, Byte, Short, Integer, Long, Float and Double

Primitive type can store every value of their corresponding wrapper type except null.
How does autoboxing handle the following code fragment?
Integer a = null;
int b = a;

It results in a run-time error.


Boxing
The process of encapsulating a value within an object is called boxing.
For instance, to convert int into an Integer object, we do the following:
Integer intObject = new Integer(100);

Here, we declare and instantiate an Integer object by passing an int value of 100 to the Integer class constructor. This constructor accepts the value and creates an Integer object based on that value.

You can construct a wrapper object either from
a primitive data type value
a string representing the value.

Unboxing
The process of extracting a value from a type wrapper is called unboxing.
If we want to convert the Integer object back to an int, we use the intValue() method:
int m = intObject.intValue();

<type>Value()
All of the numeric type wrappers inherit the abstract class Number. Number declares methods that return the value of an object in each of the different numeric types. These methods are shown here:
byte byteValue( )
double doubleValue( )
float floatValue( )
int intValue( )
long longValue( )
short shortValue( )

toString()
All of the type wrappers override toString( ). It returns the humanreadable form of the value contained within the wrapper. This allows you to output the value by passing a type wrapper object to println( ), for example, without having to convert it into its primitive type.
Autoboxing and Unboxing
Beginning with JDK 5, Java has included two very helpful features: autoboxing and auto-unboxing. Auto-boxing and Auto-unboxing greatly simplifies and streamlines code that must convert primitive types into objects, and vice versa.

To convert from int to Integer, we can simply write:
Integer intObject = 100;

Here, we assign the int literal 100 to intObject. We do not need to pass this int value to the Integer constructor; Java does it for us behind the scene. This process is known as autoboxing.

To convert from Integer to int, we can simply write:
int m = intObject;

Here, we do not need to explicitly use the intValue() method. When we assign an Integer object to an int variable, Java automatically converts the Integer object to int type.  


Uses of Wrapper Classes
Java is an object-oriented programming language, so there are times where we need to deal with objects rather than primitives:
Change the value in Method: Java supports only call by value. So, if we pass a primitive value, it will not change the original value. But, if we convert the primitive value in an object, it will change the original value.
Serialization: We need to convert the objects into streams to perform the serialization. If we have a primitive value, we can convert it in objects through the wrapper classes.
    Synchronization: Java synchronization works with objects in Multithreading.
    java.util package: The java.util package provides the utility classes to deal with objects.    
Collection Framework: Java collection framework works with objects only. All classes of the collection framework (ArrayList, LinkedList, Vector, HashSet, LinkedHashSet, TreeSet, PriorityQueue, ArrayDeque, etc.) deal with objects only.


Parse
Wrapper classes provide us with methods for converting strings into primitive types using the classes respective parse[Type]() method. Suppose you want to convert a string into an int, you can use the parseInt() method in the Integer class as shown below:

int n = Integer.parseInt("5");

The wrapper classes do not have no-arg constructors.
The instances of all wrapper classes are immutable; this means that, once the objects are created, their internal values cannot be changed.
Each numeric wrapper class has the constants MAX_VALUE and MIN_VALUE.
MAX_VALUE represents the maximum value of the corresponding primitive data type.
MIN_VALUE represents the minimum value of the corresponding primitive data type.





Autoboxing and Methods
In addition to the simple case of assignments, autoboxing automatically occurs whenever a primitive type must be converted into an object, and auto-unboxing takes place whenever an object must be converted into a primitive type. Thus, autoboxing/unboxing might occur when an argument is passed to a method or when a value is returned by a method.

Autoboxing/Unboxing Occurs in Expressions
In general, autoboxing and unboxing take place whenever a conversion into an object or from an object is required. This applies to expressions. Within an expression, a numeric object is automatically unboxed. The outcome of the expression is reboxed, if necessary.

Warning
In general, you should restrict your use of the type wrappers to only those cases in which an object representation of a primitive type is required. Autoboxing/unboxing was not added to Java as a “back door” way of eliminating the primitive types.
