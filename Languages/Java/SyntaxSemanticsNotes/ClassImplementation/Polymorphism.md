Polymorphism
Polymorphism is a feature of inheritance that lets you treat objects of different subclasses that are derived from the same superclass as if they had the type of the superclass.

Polymorphism allows you to make a definition for a certain type of behavior, and have many different classes implement that behavior.

If you access a method of a superclass object and the method is overridden in the subclasses of that class, polymorphism determines which method is executed based on the object's type.


public class Rectangle {

 private final int width;
 private final int height;
 public Rectangle(final int width, final int height) {
 this.width = width;
 this.height = height;
 }

 public int area() {
 return width * height;
 }
}
public class Square extends Rectangle {
 public Square(final int sideLength) {
 super(sideLength, sideLength);
 }
}
@Test
public void polymorphicList() {
 List<Rectangle> rectangles = new ArrayList<>(3);
 rectangles.add(new Rectangle(5, 1));
 rectangles.add(new Rectangle(2, 10));
 rectangles.add(new Square(9));
 assertEquals(rectangles.get(0).area(), 5);
 assertEquals(rectangles.get(1).area(), 20);
 assertEquals(rectangles.get(2).area(), 81);
}

This explores the use of the Square and Rectangle classes with polymorphism. As far as the ArrayList is concerned, it is only dealing with Rectangles; it does not understand, nor does it need to understand, the difference between a Rectangle and a Square. Considering a Square is-a Rectangle, the code works fine. Had any specific methods been defined on the Square class, these would not have been available to any users of the rectangles list, because that method is not available on the Rectangle class.
Superclass References and Subclass Objects
Java is a strongly typed language. Aside from the standard conversions and automatic promotions that apply to its primitive types, type compatibility is strictly enforced. Therefore, a reference variable for one class type cannot normally refer to an object of another class type. There is, however, an important exception to Java’s strict type enforcement. A reference variable of a superclass can be assigned a reference to an object of any subclass derived from that superclass.

Polymorphism refers to method invocation based on an objects run-time type.
Polymorphism allows code designed for a superclass to function with any derived class instances.
polymorphism allows a reference variable to refer to a subclass instance.
Through polymorphism, though an object reference is declared to be of a parent type, the program is smart enough to use the correct method based on the object's runtime type

Polymorphism allows a general class to specify methods that will be common to all of its derivatives, while allowing subclasses to define the specific implementation of some or all of those methods.

Polymorphism is the quality that allows one interface to access a general class of actions.
Polymorphism is often expressed by the phrase “one interface, multiple methods.”
Polymorphism helps reduce complexity by allowing the same interface to be used to specify a general class of action.

Polymorphism allows your applications to be more flexible, and less resistant to change.



Overridden methods are another way that Java implements the “one interface, multiple methods” aspect of polymorphism. Part of the key to successfully applying polymorphism is understanding that the superclasses and subclasses form a hierarchy that moves from lesser to greater specialization. Used correctly, the superclass provides all elements that a subclass can use directly. It also defines those methods that the derived class must implement on its own. This allows the subclass the flexibility to define its own methods, yet still enforces a consistent interface. Thus, by combining inheritance with overridden methods, a superclass can define the general form of the methods that will be used by all of its subclasses.


Dynamic Binding
A method can be implemented in several classes along the inheritance chain. Through dynamic binding the JVM decides which method is invoked at runtime.

A method can be defined in a superclass and overridden in its subclass.

For example, the toString() method is defined in the Object class and can be overridden in any subclass.
Consider the following code:
Object o = new GeometricObject();
System.out.println(o.toString());

Which toString() method is invoked by o?
To answer this question, we first introduce two terms: declared type and actual type.
A variable must be declared a type. The type that declares a variable is called the variable’s declared type. Here, o’s declared type is Object. A variable of a reference type can hold a null value or a reference to an instance of the declared type. The instance may be created using the constructor of the declared type or its subtype.
The actual type of the variable is the actual class for the object referenced by the variable.

Here, o’s actual type is GeometricObject, because o references an object created using new GeometricObject().

Which toString() method is invoked by o is determined by o’s actual type.
This is known as dynamic binding.

Dynamic binding works as follows: Suppose that an object o is an instance of classes C1, C2, . . . , Cn-1, and Cn, where C1 is a subclass of C2, C2 is a subclass of C3, . . . , and Cn-1 is a subclass of Cn, as shown in Figure 11.2. That is, Cn is the most general class, and C1 is the most specific class. In Java, Cn is the Object class. If o invokes a method p, the JVM searches for the implementation of the method p in C1, C2, . . . , Cn-1, and Cn, in this order, until it is found. Once an implementation is found, the search stops and the first-found implementation is invoked.

Matching a method signature and binding a method implementation are two separate issues. The declared type of the reference variable decides which method to match at compile time. The compiler finds a matching method according to the parameter type, number of parameters, and order of the parameters at compile time. A method may be implemented in several classes along the inheritance chain. The JVM dynamically binds the implementation of the method at runtime, decided by the actual type of the variable.

Casting Objects
One potentially confusing aspect of using inheritance is knowing when to cast inherited objects explicitly. The basic rule is that Java can implicitly cast a subclass to its superclass, but you must use explicit casting if you want to treat a superclass object as one of its subclasses.

One object reference can be typecast into another object reference. This is called casting object.

The statement Object o = new Student(),
known as implicit casting, is legal because an instance of Student is an instance of Object.

Suppose you want to assign the object reference o to a variable of the Student type using
the following statement:
Student b = o;

In this case a compile error would occur.
The reason is that a Student object is always an instance of Object, but an Object is not necessarily an instance of Student.
Even though you can see that o is really a Student object, the compiler is not clever enough to know it. To tell the compiler o is a Student object, use explicit casting. The syntax is similar to the one
used for casting among primitive data types. Enclose the target object type in parentheses and
place it before the object to be cast, as follows:
Student b = (Student)o; // Explicit casting


It is always possible to cast an instance of a subclass to a variable of a superclass (known as upcasting) because an instance of a subclass is always an instance of its superclass.
When casting an instance of a superclass to a variable of its subclass (known as downcasting), explicit casting must be used to confirm your intention to the compiler with the (SubclassName) cast notation.

Once you perform a cast like this, you can't call methods that are specific to the subclass.

Caution
The object member access operator (.) precedes the casting operator. Use parentheses
to ensure that casting is done before the . operator, as in
 ((SubClassName)object).methodName();


instanceof Operator
For downcasting to succeed, you must ensure the object to be cast is an instance of the subclass.
If the superclass object is not an instance of the subclass, a runtime ClassCastException occurs.

It is a good practice, therefore, to ensure the object is an instance of another object before attempting a casting. This can be accomplished by using the instanceof operator.


instanceof is a Java keyword. Every letter in a Java keyword is in lowercase
if (myObject instanceof ClassName) {/ … }

To enable generic programming, it is a good practice to declare a variable with a supertype that can accept an object of any subtype.
Casting can be done only when the source object is an instance of the target class. Java programs use the instanceof operator to ensure that the source object is an instance of the target class before performing a casting



Casting Primitives vs Objects

Casting a primitive-type value returns a new value.
int age = 45;
byte newAge = (byte)age;     // A new value is assigned to newAge

If newAge's value varies, age will not be altered

Casting an object reference does not create a new object:
Object o = new Circle();
Circle c = (Circle)o;         // No new object is created

Now, reference variables o and c point to the same object.
If o is altered, all changes will be reflected by c as well
