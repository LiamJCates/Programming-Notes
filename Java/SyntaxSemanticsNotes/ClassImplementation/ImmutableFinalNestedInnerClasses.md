Immutable Objects and Classes
Normally, you create an object and allow its contents to be changed later. However, occasionally it is desirable to create an object whose contents cannot be changed once the object has been created.
We call such an object as immutable object and its class as immutable class.
The String class, for example, is immutable.
If a class is immutable, then all its data fields must be private and it cannot contain public setter methods for any data fields.

For a class to be immutable, it must meet the following requirements:
■■ All data fields must be private.
■■ There can’t be any mutator methods for data fields.
■■ No accessor methods can return a reference to a data field that is mutable.
Final  Class

Prevents Inheritance
You can prevent a class from being inherited by preceding its declaration with final.
    Syntax:
    final class ClassName{
}

Declaring a class as final implicitly declares all of its methods as final.
As you might expect, it is illegal to declare a class as both abstract and final since an abstract class is incomplete by itself and relies upon its subclasses to provide complete implementations.


The String, StringBuilder, and StringBuffer classes, and all wrapper classes for primitive data types are also final classes.


Nested and Inner Classes

A nested class is a class that is declared within another class.
A nested class does not exist independently of its enclosing class. Thus, the scope of a nested class is bounded by its outer class. A nested class that is declared directly within its enclosing class scope is a member of its enclosing class. It is also possible to declare a nested class that is local to a block.

There are two general types of nested classes:
those preceded by the static modifier
those that are not.


Inner Class
The non-static variety of nested class is also called an inner class.
An inner class has access to all of the variables and methods of its outer class and may refer to them directly in the same way that other non-static members of the outer class do.

The basic structure for creating an inner class is as follows:

class outerClassName {
private class innerClassName {
// body of inner class
 }
}

The class that contains the inner class is called an outer class. You can use a visibility modifier with the inner class to specify whether the class should be public, protected, or private. This visibility determines whether other classes can see the inner class.

While there can only be one public outer or "top level" class per file, an inner class can be public and usable by other classes.

The inner class is useful in a situation in which each inner class object is associated with exactly one instance of an outer class object. In such a case, the inner class object can never exist without having an outer class object with which to be associated.

Here are some key points about inner classes:
» An inner class automatically has access to all the fields and methods of the outer class, even to private fields and methods as if they were part of the inner class. Thus an inner class has more access to its outer class than a subclass has to its superclass. (A subclass can access public and protected members of its superclass, but not private members.)

» When you declare an inner class, the compiler adds an implicit reference to the outer class object that caused the inner class object’s construction. Occasionally, code in an inner class needs to refer to the instance of its outer class. To do that, you list the name of the outer class followed by the dot operator and this. If the name of the outer class is Outer, then the implicit reference is Outer.this.

» Because of the outer-class instance reference, you can’t create or refer to an inner class from a static method of the outer class. You can, however, create a static inner class.

» One of the main reasons for creating an inner class is to create a class-that’s of interest only to the outer class. As a result, you usually declare inner classes to be private so that other classes can’t access them.



Using Static Inner Classes

A static inner class is similar to an inner class but doesn’t require an instance of the outer class. Its basic form is the following:
class outerClassName
{
 private static class innerClassName
 {
 // body of inner class
 }
}

Like a static method, a static inner class can’t access any nonstatic fields or methods in its outer class. It can access static fields or methods, however.

One last point: You can create an inner class that does not have a name. This is called an anonymous inner class. An object of an anonymous inner class is instantiated when the class is declared, using new

Q: What makes a static nested class different from a non-static one? A: A static nested class is one that has the static modifier applied. Because it is static, it can access only other static members of the enclosing class directly. It must access other members of its outer class through an object reference.
Using Anonymous Inner Classes
An anonymous class is a type of inner class that doesn't have a name. • You can code the braces for an anonymous class immediately after the parentheses that attempt to create an object from an interface. • Within the braces for an anonymous class, you can supply the code that implements the interface. • If you want to use the object that's created from the inner class more than once, you can assign that object to a variable.
Anonymous inner classes (usually just called anonymous classes) An anonymous class is a class that’s defined on the spot, right at the point where you want to instantiate it. Because you code the body of the class right where you need it, you don’t have to give it a name. (That’s why it’s called an anonymous class.)

The basic form for declaring and instantiating an anonymous class is this:
new ClassOrInterface() { class-body };

As you can see, you specify the new keyword followed by the name of a class or interface that specifies the type of the object created from the anonymous class. This class or interface name is followed by parentheses, which may include a parameter list that’s passed to the constructor of the anonymous class. Then you code a class body enclosed in braces. This class body can include anything that a regular class body can include: fields, methods, and even other classes or interfaces.

Here’s an example of a simple anonymous class:

public class AnonClass {
public static void main(String[] args) {
 Ball b = new Ball() {
             public void hit() {
 System.out.println("You hit it!");
             }
         };
 b.hit();
 }
interface Ball {
void hit();
}
}

In this example, I create an interface named Ball that has a single method named hit. Then, back in the main method, I declare a variable of type Ball and use an anonymous class to create an object.

Here are some things to ponder when you work with anonymous classes:
» You can’t create a constructor for an anonymous class, because the anonymous class doesn’t have a name. What would you call the constructor, anyway?
» You can’t pass parameters if the anonymous class is based on an interface. That makes sense; interfaces don’t have constructors, so Java wouldn’t have anything to pass the parameters to.
» An assignment statement can use an anonymous class as shown in this example. In that case, the anonymous class body is followed by a semicolon that marks the end of the assignment statement. Note that this semicolon is part of the assignment statement, not the anonymous class.
» An anonymous class is a special type of inner class; like any inner class, it automatically has access to the fields and methods of its outer class.
» An anonymous class can’t be static
