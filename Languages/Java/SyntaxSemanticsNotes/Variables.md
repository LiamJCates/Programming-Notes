Variables
A variable is a name associated with a region of computer memory
A variable typically stores a value that changes as an application executes.
A variable allows us to manipulate, store, and retrieve values used by our programs.
A variable must be declared and initialized before it holds a value.


Value
Java values are of two fundamental categories: primitive and reference.
primitives are fundamental values including numeric types, characters, and booleans.
reference values are the addresses of the data object they refer to.

Typing
Data types are especially important in Java because it is a strongly typed language.
This means that all operations are type-checked by the compiler for type compatibility.
Any operation performed must use variables, expressions, and values of compatible types.
Illegal operations will not be compiled.

strong type checking helps prevent runtime errors and enhances reliability.

The type of a variable designates:
the range of data it may hold
operations allowed to be performed with it.

Calcification
Instance:     non-static class members
Class:         static class members
Local:         variables declared within a method body
Parameters    variables declared within a method header

Local Variables
A variable declared within a method,
Local variables must store a value before it can be used.
If the compiler determines that the program might manipulate a variable before a value has been stored in it, an error will occur.
Whenever possible, declare a local variable and assign its initial value in the same statement.
This will improve readability and reduce programming errors.

Method Parameters
virtually the same as local variables—they’re declared inside the method (well, technically they’re declared in the argument list of the method rather than within the body of the method, but they’re still local variables as opposed to instance variables). But method parameters will never be uninitialized, so you’ll never get a compiler error telling you that a parameter variable might not have been initialized. But that’s because the compiler will give you an error if you try to invoke a method without sending arguments that the method needs. So parameters are ALWAYS initialized, because the compiler guarantees that methods are always called with arguments that match the parameters declared for the method, and the arguments are assigned (automatically) to the parameters.

Declaration
Declaration Statements, which consist of a type and an associated identifier, create variables:
type identifier;

The variable's type denotes the range of data values it may store as Java is a strongly-typed language.
The variable's identifier denotes a programmer-defined name for a memory location.
    identifiers are case sensitive

After you declare a variable:
program memory space needed by the variable's type is allocated
you then access this location using the variable's identifier

Initialization
Assignment Statement, consisting of an assignment operator and an expression, is used to initialize, or assign, the value of a variable:
identifier = expression;

= sign is known as an assignment operator.
The left of the assignment operator is the variable identifier we wish to initialize
The right of the assignment operator is an expression that resolves to the assigned value

In an assignment statement, the data type of the variable on the left must be compatible with the data type of the value on the right
Assignment statements evaluate to the value assigned

You can assign a value to a variable in one of several ways:
■ assign a literal value (x=12, isGood = true, etc.)
■ assign the value of one variable to another (y = x)
■ assign the value of a method call or operations on variables or literals. (dynamic initialization)


Dynamic Initialization
variables may be initialized dynamically, using any expression valid at the time of the initialization


Multiple Declaration and Initialization
Multiple variables of the same type can be declared on a single line by specifying a type then comma delimiting an identifier for each variable.
This can be done without initialization, with initialization, or a mix.
int score, speed, enemies;    //without
int level = 2, experience = 0;    //with
int lives = 3, completionTime;    //mix    


Variable Naming Rules / Conventions

Name identifiers (classes, methods, labels, packages, variables, etc… ) according to the following rules
(the real rules are slightly more flexible, but these will keep you safe):
■ identifiers can be of any length.
■ identifiers may use only alphabetic letters (non-Latin), digits, underscores, or dollar signs
        [A-Z], [a-z], [0-9], $, _
■ identifiers must start with a letter, underscore (_), or dollar sign ($). (Not a number)
■ identifiers cannot include spaces
■ identifiers can't be one of Java’s reserved words.

Sixty-one keywords are currently defined in the Java language:
[See /ReservedWords]


In addition to the keywords, Java reserves four other names.
Three have been part of Java since the start: true, false, and null. These are values defined by Java.
Beginning with JDK 10, the word var has been added as a context-sensitive, reserved type name.

Conventions
Do not use the name of any standard method, such as println, as an identifier.
Always begin your variable names with a letter, not "$" or "_".
Variable names should be short but meaningful, designed to indicate to the casual reader the intent of its use.
Each variable name should be a noun or a noun preceded by one or more adjectives.
Try to use meaningful names that are easy to remember.
To make a name easy to remember, you should avoid abbreviations.

■ Use camel casing when naming Java variable and method identifiers
Camel casing is the practice of writing compound words with mixed casing, capitalising the first letter of each word except the first word (e.g. thisIsAVariableName)
■ Capitalize the first letter of each word in a class name
■ Capitalize every letter in a constant, and use underscores between words
Creating Objects
A class is essentially a programmer-defined type.
A class is a reference type, which means that a variable of the class type can reference an instance of the class.

To access the data and use the methods of a class we must construct an object of that class,

Use the new operator and the class name to invoke a class constructor:
<Type> objName = new <Type>(arg-list)

The new operator constructs new instances of a class.
The new operator invokes the class constructor which returns a reference to a newly constructed object.
To store this reference we must declare a variable of a compatible type and assign the return value to it.

Since memory is finite, it is possible that new will not be able to allocate memory for an object because insufficient memory exists. If this happens, a run-time exception will occur.

Dot Operator (.)
The dot operator (.) gives you access to an object’s state and behavior (instance variables and methods).

Once we create an object, that object’s data and methods can be accessed through the dot (.) operator via the object’s reference variable:
■ objectRefVar.dataField references a data field in the object.
■ objectRefVar.method(arguments) invokes a method on the object.

The object on which an instance method is invoked is called a calling object.


Object References
Any type that is not a primitive is known as a reference type.

A primitive variable is a memory location whose bits represent the actual value of the variable
A reference variable is a memory location whose bits represent another location in memory

The 3 steps to initialize a reference variable: Declaration, Instantiation, Assignment

Declaration:                 ClassType identifier;
This variable does not define an object, it simply holds an object reference.
This statement tells the JVM to allocate space for a reference variable.
The identifier specified is associated with the allocated space.
Any Java class can be used as the type of a reference variable.
Some classes cannot be instantiated

Instantiation:                new ClassType( arg-list )
The new operator tells the JVM to invoke an object constructor
The object constructor dynamically allocates memory space for the object's attributes
This object data is located on the garbage collectable heap
The constructor returns a reference to the allocated memory space
The reference is, essentially, the address in memory of the object allocated by new.
Thus all Java class objects must be dynamically allocated.

Assignment:                identifier = new ClassType( arg-list );
An object reference must be assigned to a variable of the same type.
The identifier is then associated with a reference value that describes the location of an object.
In Java, you manipulate object references, not objects.


These steps can be a single statement:    ClassType identifier = new ClassType();


Q: Why don’t I need to use new for variables of the primitive types, such as int or float?
A: Java’s primitive types are not implemented as objects. Rather, because of efficiency concerns, a variable of a primitive type actually contains the value that you have given it. As explained, object variables are references to the object. This layer of indirection (and other object features) adds overhead to an object that is avoided by a primitive type.
Reference Variable Value?
In Java we don’t technically know what is at the reference variable's memory location.
Whatever it is, it represents one and only one object.
There are pointers in there somewhere, but you can’t access them.
Whatever it is it's a 64-bit value.
The JVM uses the data at the reference variables memory location to access the object's data.
Objects are stored on the garbage collectible heap!


But when you’re talking about memory allocation issues, your big concern should be about how many objects (as opposed to object references) you’re creating, and how big those objects really are.

All references for a given JVM will be the same size regardless of the objects they reference, but each JVM might have a different way of representing references, so references on one JVM may be smaller or larger than references on another JVM.

Q: Can I do arithmetic on a reference variable, increment it, you know, C stuff?
A: Nope. “Java is not C.”



Null Value
null is the reserved constant used in Java to represent a void reference
i.e a pointer to nothing.

Internally it is just a binary 0, but in the high level Java language, it is a magic constant, quite distinct from zero, that internally could have any representation.

null refers to no object:            Object obj = null;

If a reference variable has been declared and does not yet hold an object reference its the null value.
null is a literal just like true and false.
As true and false are literals of Boolean type, null is a literal for a reference type.

You must assign an object reference to the variable before using that variable to invoking a field or method.
If you invoke a method on a null reference, a NullPointerException is thrown.
Anonymous Objects
Usually you create an object and assign it to a variable, then later you can use the variable to reference the object. Occasionally, an object does not need to be referenced later. In this case, you can create an object without explicitly assigning it to a variable using the syntax:
new Circle();

System.out.println("Area is " + new Circle(5).getArea());

This statement creates a Circle object and invokes its getArea method to return its area. An object created in this way is known as an anonymous object.



Final Variables

A named constant, or simply constant, is an identifier that represents a permanent value.
While other variable's values may change during program execution, a named constant never changes.
Constants are useful for values that are used in several places throughout a program
A constant is also known as a final variable in Java.

A constant declaration begins with the keyword final:
access-modifier modifiers final type IDENTIFIER;

Convention dictates that final variables identifiers be UPPERCASE.
A final variable must be initialized or the compiler will throw an error

The keyword final indicates that a variable's value does not change after initialization.
Each type of variable can be final and has its own rules for initialization:
final local variables initialized at declaration.
final instance variables initialized at declaration, by instance-initializer block, or by constructor.
final class variable initialized at declaration or by static-initializer block.
final parameter initialized by the method call.

A blank final is a final variable whose declaration lacks an initializer.

Declaring a parameter final prevents it from being changed within the method.

const is a reserved Java keyword, but it is not currently used for anything. You must use final for a constant.


Benefits of using constants:
eliminate a magic value
you don’t have to repeatedly type the same value for multiple uses;
If you have to change the constant value (e.g., from 3.14 to 3.14159 for PI), it is a single location in the source code;
a descriptive name for a constant makes the program easy to read.


Final Reference Variable
While the value of a final variable of primitive type cannot change and a final variable of a reference type cannot be re-bound to reference another object
The internal state of the object referenced by a final variable can be changed e.g. you can:
change the state of attributes associated with an object referenced by a final variable
add or remove elements from an array or collection referenced by a final variable
Local Variable Type Inference
In principle, a variable type could be inferred from the type of the initialization expression.
JDK 10 allows the compiler to infer the type of a local variable based on the type of its initialization expression if the context-sensitive type identifier var is used:
var arg = 10.0;        //arg is the type of the initializer expression, double

a variable declared with var as the type name must include an initializer.
The following statement would cause an error to be thrown:
var counter;

var can be used to declare an array:
var arr = new int[10];

Do not use brackets on the left side of a var declaration:
var[] arr = new int[10];    //invalid
var arr[] = new int[10];    //invalid

The for loop control variable, or the iteration variable in a for-each can use type inference
for(var x = 2.5; x < 100; x *= 2){...}

for(var v : nums){...}

Local variable type inference offers a number of advantages.
streamlines code by eliminating redundant variable type specification
simplify variable declaration of a lengthy type name
helpful when a type is difficult to discern or cannot be denoted. (Ex an anonymous class)

Furthermore, local variable type inference has become a common part of the contemporary programming environment. Its inclusion in Java helps keep Java up-to-date with evolving trends in language design.

Type Inference Restrictions
can be used only to declare local variables.
cannot be used when declaring instance variables, parameters, or return types
Only one variable can be declared per statement
null cannot be used as an initializer
The variable being declared cannot be used by the initializer expression.
the initializer expression cannot use an array initializer
var arr = new int[10];        //valid
var arr = {1,2,3};            //invalid

cannot be used as a reference type name
including a class, interface, enumeration, or annotation identifier
type inference cannot be used to declare the exception type caught by a catch statement.
cannot lambda expressions nor method references can be used as initialization expressions.

Type Casting In Java

It is common to assign data of one type to a variable of a distinct type.
When compatible types are mixed in an assignment, the value of the right side is automatically converted to the type of the left side.

Implicit casts are performed automatically and can be used to convert data with a less precise type such as the float type to a more precise type such as the double type.

An automatic type conversion will take place if:
● The two types are compatible.
● The destination type is larger than the source type

However, because of Java’s strict type checking, not all types are compatible, and thus, not all type conversions are implicitly allowed.

If you assign a less precise data type to a more precise data type, or you assign a smaller data type to a larger data type, Java automatically performs the cast and makes the conversion.
This can be referred to as an implicit cast or a widening conversion.

To code an assignment statement that assigns a more precise data type to a less precise data type, you must use parentheses to specify the less precise data type.
This can be referred to as an explicit cast or a narrowing conversion.

To perform an explicit narrowing conversion or to convert incompatible types we use type casting.
A type cast is an instruction to the compiler to convert one type into another:
type varName = (target-type) expression;

Here, target-type specifies the desired type to convert the specified expression to.
When you code an explicit cast, an exception may occur at runtime if the JRE isn't able to perform the cast. As a result, you should use an explicit cast only when you're sure that the JRE is able to perform the cast.

Even if the JRE can perform the cast in general, narrowing conversions can result in a data loss and are thus unsafe and should be avoided unless absolutely necessary.

In Java, an augmented expression of the form x1 op= x2 is implemented as x1 = (T) (x1 op x2), where T is the type for x1.

Therefore, the following code is correct:
int sum = 0;
sum += 4.5;     //The value of sum is 4 after this statement, equivalent to sum = (int)(sum + 4.5).

When you code an arithmetic expression,
Java implicitly casts the less precise data types to the most precise data type.
Java performs the cast before any arithmetic operations.
Multiple variables can store references to the same object.
ClassName objName = new ClassName() ;
ClassName obj2 = obj;

When you assign the value of one reference variable to another, both reference the same object.



Copying Objects
To ensure two reference variables refer to the same object instance use the = operator.
To ensure two reference variables contain equal data values use the .clone() method

The cone() makes a copy of the implicite object's state at a distinct memory location and returns a reference.

obj2 = (ClassName) obj.clone();

The cast (ClassName) is necessary because clone is a generic method with return type Object.



Object Equality

To know if two reference variables refer the same object instance use the == operator.
To know if two reference variables contain equal data values use the .equals() method.

The idea of equality for objects depends on the type of object.
If two different String objects contain the same character values (say, “expeditious”), they are meaningfully equivalent, regardless of whether they are two distinct objects on the heap.

Do you want to treat two Dogs as being equal if they happen to have the same size and weight? Probably not. So whether two different objects should be treated as equal depends on what makes sense for that particular object type.

Understand that the == operator is used only to compare the bits in two variables. What those bits represent doesn’t matter.

boolean boolValue = a == b;
== examines the bits in a and b and boolVal is set to returns true if the bit patterns are the same.

== doesn’t care about the size of the variable, so all the extra zeroes on the left end don’t matter).

int a = 3;
byte b = 3;
if (a == b) { // true }

We don’t know what the bit pattern is because it’s dependent on the JVM, and hidden from us
We do know that whatever it looks like, it will be the same for two references to a single object
