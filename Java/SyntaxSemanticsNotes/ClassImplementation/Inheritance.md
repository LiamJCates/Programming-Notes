Inheritance: (Sub/Super Classes, Overriding, Object Class)
Inheritance allows you to derive the state and behavior of a class from a superclass.

Java classes allow the definition of subclasses that are extensions of existing classes.
A subclass is said to inherit the properties, i.e. non-private instance variables and methods, of its super class.

Each Java class is allowed to have
one direct parent (super) class
an unlimited number of child (sub) classes

With inheritance, all classes—including those you create and the ones in the Java Class Library—are arranged in a hierarchy. In fact, all classes in Java are inherited from a pre-written base class known as the Object class. Each class further down the hierarchy becomes more tailored to a specific purpose. A class hierarchy defines abstract concepts at the top of the hierarchy. Those concepts become more concrete further down the line of subclasses.

If you’re creating a large set of classes, it makes sense for your classes to inherit from the existing class hierarchy and to form a hierarchy themselves. This gives your classes several advantages:
Functionality common to multiple classes can be put into a superclass, which enables it to be part of all classes below it in the hierarchy.
Changes to a superclass automatically are reflected in all its subclasses, their subclasses, and so on. There is no need to change or recompile any of the lower classes; they receive the new information through inheritance.

Designing an effective class hierarchy involves a lot of planning and revision. As you attempt to put attributes and behavior into a hierarchy, you’re likely to find reasons to move some classes to different spots in the hierarchy. The goal is to reduce the number of repetitive features (and redundant code) needed.


Creating a subclass
A subclass provides its own fields and methods that extend a superclass
The keyword extends indicates a subclass.
Syntax:
class [subclass-name] extends [superclass-name] {
// body of class
}



A child class inherits all public and protected fields and methods from the parent class.
This facilitates code reuse and is especially valuable if the parent class has a large number of public/protected fields and methods that the child class can use.

The child class can use inherited members as if they are part of its own code;
we do not have to declare inherited members in a child class.

A child class can override fields and methods of the superclass by providing new code for them.

A child class cannot access private parent class fields directly.
However, these fields do exist in the child class.
The only difference is that the child class cannot access them directly but has to use constructors or setter and getter methods instead.

Inheritance allows subclass code to focus exclusively on the features that make it unique.
You must take care to properly document, in a subclass code block, the state and behavior that each superclass defines, since that code will not appear in the source file of each subclass.


Constructors
Q: What constructor is responsible for building an object of the subclass?
A: The constructor for the superclass constructs the superclass portion of the object, and the constructor for the subclass constructs the subclass part.

This makes sense because the superclass has no knowledge of or access to subclass members.

When only the subclass defines a constructor we simply construct the subclass object.
The superclass portion is constructed automatically
the subclass constructor implicitly invokes its default constructor.

super
When the superclass defines constructors the subclass must explicitly invoke one with the use of the keyword "super"

    super( [parameter-list] );         //calls the relevant constructor of the parent class

The super keyword has two general forms.
Call a superclass constructor.
Access a member of the superclass that has been hidden by a member of a subclass.


Class hierarchy constructors complete their execution in order of derivation, from super to sub class.
this order is the same whether or not super( ) is used
If super( ) is not used, then the default (parameterless) constructor of each superclass will be executed.
To call a parameterized constructor in the parent class, you have to use the super keyword.
If used, super() must be the first statement in a subclass’ constructor or a compilation error is thrown.

Any form of constructor defined by the superclass can be called by super( ).

The second form of super that acts somewhat like the "this" keyword
super reference the direct superclass of the subclass in which it is used.
super.fieldName;    super.methodName();
Overriding
Overriding provides a new implementation for a superclass instance member in the subclass with
the same field identifiers
the same method signature and compatible return types
 A Compatible type is the same or a subclass type

When an overridden method is called from within a subclass, it will always refer to the method definition found first (starting at the bottom of the hierarchy and working upward)
allows creation of subclass methods which prevent superclass methods from being used.

Instance methods can be overridden since they are resolved using dynamic binding at run time.
An instance method can be overridden only if it is accessible.
private instance members cannot be overridden as they are not accessible outside their class.
If an instance member defined in a subclass is private in its superclass, the two are unrelated.

When overriding a method, use the @Override annotation
@Override annotation is a useful compile-time check which instructs the compiler that you intend to override a method in the superclass.
If the child class fails to override a method correctly, the compiler will generate an error
Syntax:
@Override
public return-type parentMethodName() {
    //new behaviour
}

If you want to access the superclass version of an overridden method, you can do so by using super:
super.methodName();


Overridden Methods Support Polymorphism
Method overriding forms the basis for one of Java’s most powerful concepts: dynamic method dispatch. Dynamic method dispatch is the mechanism by which a call to an overridden method is resolved at run time rather than compile time. Dynamic method dispatch is important because this is how Java implements run-time polymorphism.

When an overridden method is called through a superclass reference, Java determines which version of that method to execute based upon the type of the object being referred to at the time the call occurs. Thus, this determination is made at run time. When different types of objects are referred to, different versions of an overridden method will be called. In other words, it is the type of the object being referred to (not the type of the reference variable) that determines which version of an overridden method will be executed.
Overriding and Overloading:
In a subclass, you can overload the methods inherited from the superclass. Such overloaded methods neither hide nor override the superclass instance methods—they are new methods, unique to the subclass.

Overriding is a run-time concept while overloading is a compile-time concept.
The real object type at run-time, not the reference variable's type, determines which overridden method is used at runtime.
In contrast, reference type determines which overloaded method will be used at compile time.
Polymorphism applies to overriding, not to overloading.





Hiding Methods
If a subclass defines a static member that is also in the superclass, then the method in the subclass hides the one in the superclass.

The distinction between hiding a static member and overriding an instance member has important implications:

The version of the overridden instance member that gets invoked is the one in the subclass.
The version of the hidden static member that gets invoked depends on whether it is invoked from the superclass or the subclass.

hidden static members can be invoked using the syntax:
SuperClassName.staticMember




The Object Superclass
Java defines one special class called Object that is an implicit superclass of all other classes.
In other words, all other classes are subclasses of Object.
While we are required to use the extends keyword whenever we want one class to inherit from another class, the only exception is when inheriting from the Object class.
As all Java classes inherit from the Object class, there is no need to state this inheritance explicitly.


The Object class consists of a number of pre-written methods that we can use whenever we work with classes. One such method is the toString() method that returns a string that represents the object.

obj.clone()        //Creates a new object that is the same as the one being cloned
obj.equals(obj2)    //return boolean indicating object equality
obj.finalize()        //Called before and unused object is recycles (deprecated)
obj.getClass()        //obtains class of an object at runtime
obj.hashCode()        //returns hash code associated with the invoking object
obj.notify()        //resumes execution of a thread waiting on the invoking object
obj.notifyAll()        //resumes execution of all threads waiting on the invoking object
obj.toString()        //returns the string "[Classname]@[hashcode]"
obj.wait()        //waits on another thread for execution


The methods getClass( ), notify( ), notifyAll( ), and wait( ) are declared as final. You can override the others.
equals()
The equals(Object) method is a useful method defined in the Object class.

public boolean equals(Object o)

This method tests whether two objects are equal.
    Syntax:
object1.equals(object2);

The default implementation of the equals method in the Object class is

public boolean equals(Object obj) {
 return this == obj;
}

This implementation checks whether two reference variables point to the same object using the
== operator. You should override this method in a class to test whether two distinct
objects have the same content.

The equals method is overridden in many classes in the Java API, such as java.lang.String
and java.util.Date, to compare whether the contents of two objects are equal.

The == comparison operator is used for comparing two primitive-data-type values or for
determining whether two objects have the same references.

The equals method is intended to test whether two objects share state, provided the method is overridden in the defining class of the objects.

Caution
Using the signature to override the equals method in a subclass is a common mistake.
public boolean equals(SomeClassName obj)
You should use
public boolean equals(Object obj).

Explain how some of the methods on the Object class are used when overridden.

The method equals(Object other) is used for testing that two references are logically equal. For
collection classes, such as java.util.TreeSet or java.util.HashMap, these classes make use of an
object’s equals method to determine if an object already exists in the collection. The implementation of equals on Object compares the memory location of the objects, meaning that if two objects
have the same memory location, they are actually the same object, so they must be equal. This is
usually not much use, nor is it intended for testing equality, so overriding the method is a must for
any need for testing equality.
The rule for hashCode is that two equal objects must return the same value. Note that the
reverse is not required: that if two objects return the same hashCode, they are not necessarily
equal. This is a nice feature to have, but not required: The more variance in the hashCode between
different instances, the more distributed those instances will be when stored in a HashMap. Note
that hashCode returns an int—this means that if unequal hashCodes meant unequal objects, there
would only be a maximum of 2^32 unique variations of a specific instance. This would be quite a
limitation, especially for objects like Strings!
The reason for the relationship between hashCode and equals is in the way collection classes such
as java.util.HashMap are implemented. As discussed in Chapter 5, the data structure backing
a HashMap is some sort of table, like an array or a List. The hashCode value is used to determine
which index in the table to use. Because the hashCode returns an int, this means that the value
could be negative, or perhaps a value larger than the size of the table. Any HashMap implementation
will have to manipulate this value to a meaningful index for the table.
Like equals, hashCode also uses the memory location to generate the hashCode value on the
Object class. This means that two separate instances that are logically equal will be in different
memory locations, and therefore will not return the same hashCode.

The behavior of Set in Listing 8-11 is not performing as expected. The set does not know how to
compare the Person objects properly, because Person does not implement equals. This can


Given the relationship between hashCode and equals, the golden rule is: Whenever overriding hashCode or equals, you MUST override both methods.


The Class class

Every class used by a Java application is represented in memory by an object of type Class. If your program uses Employee objects, for example, there’s also a Class object for the Employee class. This Class object has information not about specific employees but about the Employee class itself.

You can get a Class object by using the getClass method. This method is defined by the Object class, so it’s available to every object. Here’s an example:
Employee emp = new Employee();
Class c = emp.getClass();

Note that you have to initialize a variable with an object instance before you can call its getClass method. That’s because the getClass method returns a Class object that corresponds to the type of object the variable refers to, not the type the variable is declared as.

Suppose that an HourlyEmployee class extends the Employee class. Then consider these statements:
HourlyEmployee emp = new Employee();
Class c = emp.getClass();

Here c refers to a Class object for the HourlyEmployee class, not the Employee class.

The Class class has more than 50 methods, but only 2 of them are worthy of your attention:
» getName(): Returns a String representing the name of the class
» getSuperclass(): Returns another Class object representing this Class object’s superclass

One of the most common uses of the getClass method is to tell whether two objects are of the same type by comparing their Class objects. This works because Java guarantees that the Class object has only one instance for each different class used by the application. So even if your application instantiates 1,000 Employee objects, there is only one Class object for the Employee class

To find out whether an object is of a particular type, use the object’s getClass method to get the corresponding Class object. Then use the getName method to get the class name, and use a string comparison to check the class name. Here’s an example:
if (emp.getClass().getName().equals("Employee"))
 System.out.println("This is an employee object.");
