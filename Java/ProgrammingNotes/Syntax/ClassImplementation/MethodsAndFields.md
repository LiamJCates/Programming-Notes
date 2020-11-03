Methods and Fields

A class describes object state and behavior, represented by fields and methods.


Fields
A field is a variable that is declared as a class member.
Fields can either be instance or class variables

A member variable consists of a
modifier keywords
data type
identifier

Declaration Syntax:

class ClassName {
modifiers data_type fieldName;
}


Methods
A method is a function/procedure declared in a class
Methods can either be an instance or class method

The method declaration includes
modifier keywords
return type
method name
parameter list
body

Syntax:
class ClassName {
modifiers ret-type methodName( parameter-list ) {
// method body
}
}

A Java method is executed by calling (invoking) the method signature:
Two of the components of a method declaration comprise the method signature
method name
parameter list
Instance Members


Instance Variables:
are also called member variables
have a specific type
Each defines an attribute of a unique object instance's state.
Have a copy initialized for each object instance
can be given a value during instantiation and stay constant or vary during runtime.

Reference Syntax:
objectInstance.instanceVariableName;


Instance variables always get a default value, even if you don’t explicitly assign a value
integers 0     floating points 0.0     booleans false     references null




Instance Method
While every unique instance can have different instance variable values, every instance has the same methods, but those methods can behave differently based on instance state

Instance methods depend on and require an object instance to be invoked

Reference Syntax:
objectInstance.instanceMethodName( parameter list );


An instance method is always invoked relative to a class instance, called the implicit parameter
The implicit parameter alleviates the need to specify the instance identity within a method body
The body of an instance method has access to all instance variables declared inside its class.
Inside an instance method the implicit parameters instance variables are referenced directly    without the dot operator.

Memory allocation: These methods themselves are stored in Permanent Generation space of heap but the parameters (arguments passed to them) and their local variables and the value to be returned are allocated in stack.
Instance methods are not stored on a per-instance basis, even with virtual methods.
Instance methods are stored in a single memory location, and only “know” which object they belong to because their implicit parameter


This
The implicit parameter reference is typically omitted unless needed to resolve the ambiguity between the name of a parameter or local variable and a class member.

Java permits instance method parameters or local variables to share the names of instance variables.
When this happens, the local name hides the instance variable.
You can regain access to a hidden instance variable by referring to the implicit parameter
The instance method's implicit parameter is referenced through the keyword "this".  

this in setter methods
It is a good practice to use the data field as the parameter name in a setter method or constructor
This makes code easier to read and avoids creating unnecessary names.

class ClassName{
    String name;

void setName(String name) { this.name = name; }
}

Access Modifiers
Access modifiers control whether other classes can use a particular field, method, or class declaration.
Explicate:     private, public and protected
Implicit:    package-private.

Access modifiers are also known as visibility or accessibility modifiers because they specify how classes and class members are accessed, whether they are "visible" to other classes:
PUBLIC elements are accessible by any class in the program

PROTECTED elements are accessible within the class in which it is declared, any class that is derived from it and any class that is in the same package. Thus, a protected member is available for all subclasses to use but is still protected from arbitrary access by code outside its package.

PACKAGE-PRIVATE (default) elements are only accessible to other classes within the same package. If an access modifier is not stated, the access level is taken to be package-private the default access level.

PRIVATE elements are only accessible within the same class

The private and protected modifiers can be used only for class members and inner/nested classes.
The public and default modifiers (i.e., no modifier) can be used on class members and top level classes.

Make class members:
private         if they are not intended for use from outside the class.
protected     if they are intended for the extenders of the class but not for the users of the class.
public         if they are intended for the users of the class.

A subclass may override a protected method defined in its superclass and change its visibility to public. However, a subclass cannot weaken the accessibility of a method defined in the superclass. For example, if a method is defined as public in the superclass, it must be defined as public in the subclass.

Q: When should I make an instance variable private?
A: There are no hard and fast rules, but here are two general principles.
If an instance variable is to be used only by methods defined within its class, then it should be made private.
If an instance variable must be within certain bounds, then it should be private and made available only through accessor methods to prevent invalid values.
Final Class Members

Final Fields

The final keyword can be included in field declarations
    Syntax:
final [type] [name] = [value];

The keyword final indicates that a variable's value does not change after initialization.

Final field rules for initialization:
final local variables initialized at declaration.
final instance variables initialized at declaration, by instance-initializer block, or by constructor.


Final Methods
any non-final public or protected method can be overridden.
To prevent a Java method from being overridden use the keyword final during method declaration
    Syntax:
access-modifier final return-type methodName(){ //… }




Static Class Members

In Java static class members are those which belong to the class rather than a unique instance
To create static class members we use the static keyword.

class ClassName{
    static type identifier;

    static return-type methodName() { //… }
}

We access static class members without instantiating the class, using the class name instead:
    ClassName.staticField;        ClassName.staticMethod();



Q What’s the distinction between instance and static fields and methods?
A Almost everything you do in a Java program involves individual object instances rather than classes.
However, some behavior and attributes make more sense if stored in a class rather than in an object.
    these behaviours or attributes are shared by all instances regardless of instance state

For example, the java.lang.Math package includes static members
The class variable called Math.PI holds the approximate value of pi.
This value does not change, so object instances don't need their own individual copy
If the value of PI did change, all instances would still use that single value
similarly the Math.pow() method behaviour is identical for any invocation
It does not change in relation to instance state, and as such should not be associated with any single instance


Why "static"?
The term "static" is an unfortunate and meaningless holdover from C++.
Static Fields

For some variables that don’t need to be different in each object, it makes more sense to have one value shared by all objects of that class.
A static field is more accurately called a class variable
The variable applies to the class itself and to all its instances, so only one value is stored, no matter how many objects of that class have been created in a program.

What is the difference between instance and class variables
Changes made to instance variables don't reflect in other instances of that class.
    Changes made to a static variable are reflected in all current and future instances


Static variables are created when a class is loaded into the memory by the class loader and destroyed when a class is destroyed or unloaded. These class variables occupy memory until a Java program is finished running, so they should be used with care. If a class variable references an object, that object will remain in memory as well. This is a common problem that causes a program to take up too much memory and run slowly.



Static Methods

Instance methods, usually just called methods, are used to work with an object instance.
If a method changes an individual object instance, it must be an instance method.

Static methods are the methods in Java that can be called without creating an object of class.

The most common example of a static method is main( )
main( ) is declared as static because it must be called by the JVM when your program begins.

Memory Allocation:
Static methods are stored in Permanent Generation space of heap as they are associated to the class in which they reside not to the objects of that class.
Their local variables and argument(s) are stored in the stack.

Static methods can't be overridden, but can be overloaded since they are resolved using static binding by compiler at compile time.

Methods declared as static have several restrictions:
● They can only directly reference other static class members as they have no implicit parameter



Java Globals

Q: What if I need global variables and methods? How do I do that if everything has to go in a class?

Marking a class member as public and static makes it behave much like a ‘global’.
Any code, in any class of your application, can access a public static method.
Mark a variable as public, static, and final – you have essentially made a globally-available constant.

Q: Then how is this object oriented if you can still make global functions and global data?
A: First of all, everything in Java goes in a class. So the constant for pi and the method for random(), although both public and static, are defined within the Math class. And you must keep in mind that these static (global-like) things are the exception rather than the rule in Java. They represent a very special case, where you don’t have multiple instances/objects.
