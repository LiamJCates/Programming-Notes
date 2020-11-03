A constructor is a block of code used to ‘construct’ / initialize an instance of a class template.

Constructors are a special kind of method:
■ A constructor must have the same name as the class itself.
■ Constructors do not have a return type (do not use the void keyword when declaring a constructor.)

Typically, you will use a constructor to give initial values to the instance variables defined by the class, or to perform any other startup procedures required to create a fully formed object.

All classes have constructors,
If one is not defined Java automatically provides a default constructor.
A default constructor sets uninitialized member variables to their default values.
Once you define your own constructor, the default constructor is no longer used.

As a result, if you declare a constructor that accepts parameters and still want to have an empty constructor (with no parameters and no body), you must explicitly declare an empty constructor for the class.

Parameters are declared by a constructor header in the same way as a method header

Constructors are not Inherited
Constructors are not class members, so they are not inherited when you extend a class.

This
use this in the constructor body to reference the class instance being constructed.
we use 'this' to differentiate fields from constructor parameters and local variables:

public Actor(String last, String first)
{
 this.last = last;
 this.first = first;
}


Overloading
constructors can be overloaded making it easy to construct objects with different initial data values.
Similar to methods, we can have more than one constructor as long as the signature is different.


Calling other constructors
A constructor can call another constructor of the same class by using the special keyword this as a method call. This technique is commonly used when you have several constructors that build on one another. Consider this class:

public class Actor {
 private String lastName;
 private String firstName;
 private boolean goodActor;

public Actor(String last, String first)  {
 lastName = last;
 firstName = first;
 }

 public Actor(String last, String first, boolean good) {
 this(last, first);
 goodActor = good;
 }
}




Using Initializers

An initializer (sometimes called an initializer block) is a lonely block of code that’s placed outside any method, constructor, or other block of code. Initializers are executed whenever an instance of a class is created, regardless of which constructor is used to create the instance. Initializer blocks are similar to variable initializers used to initialize variables. The difference is that with an initializer block, you can code more than one statement.

class PrimeClass
{
 private Scanner sc = new Scanner(System.in);
 public int x;
 {
 System.out.print("Enter the starting value for x: ");
 x = sc.nextInt();
 }
}

Here are a few other tidbits of information concerning initializers:
» There are actually two types, called static initializers and instance initializers.
» If a class contains more than one initializer, the initializers are executed in the order in which they appear
» Initializers are executed before any class constructors.
» A static initializer lets you initialize static fields.


Static Blocks
Sometimes a class will require some type of initialization before it is ready to create objects. For example, it might need to establish a connection to a remote site. It also might need to initialize certain static variables before any of the class’ static methods are used. To handle these types of situations, Java allows you to declare a static block. A static block is executed when the class is first loaded. Thus, it is executed before the class can be used for any other purpose.

The first time you access a static member such as a static field or a static method, any static initializers in the class are executed  — provided that you haven’t already created an instance of the class. That’s because the static initializers are also executed the first time you create an instance. In that case, the static initializers are executed before the constructor is executed. If a class has more than one static initializer, the initializers are executed in the order in which they appear in the program.

class StaticBlock{
    static double rootOf2;
    static double rootOf3;

    static{
        rootOf2 = Math.sqrt(2.0);
        rootOf3 = Math.sqrt(3.0);
}
}
When are instance initializers useful?

The use of instance initializers are rare, but still it can be a useful alternative to instance variable initializers if:

(1) initializer code must handle exceptions
(2) perform calculations that can't be expressed with an instance variable initializer.

Of course, such code could be written in constructors. But if a class had multiple constructors, you would have to repeat the code in each constructor.

With an instance initializer, you can just write the code once, and it will be executed no matter what constructor is used to create the object. (I guess this is just a concept, and it is not used often.)

Another case in which instance initializers are useful is anonymous inner classes, which can't declare any constructors at all. (Will this be a good place to place a logging function?)

Thanks to Heinrich Hartmann for his comment:

    Also note that Anonymous classes that implement interfaces [1] have no constructors. Therefore instance initializers are neede to execute any kinds of expressions at construction time.

Preventing Instances

Sometimes you want to create a class that can’t be instantiated at all. Such a class consists entirely of static fields and methods.

To create a class instance, you have to have at least one public constructor. If you don’t provide a constructor in your class, Java automatically inserts a default constructor, which happens to be public.
All you have to do to prevent a class instance from being created, then, is provide a single private constructor, like this:

public class Validation {
 private Validation() {} // prevents instances
     // static methods and fields go here
}

Now, because the constructor is private, the class can’t be instantiated.

In most cases, the constructor should be public. However, if you want to prohibit the
user from creating an instance of a class, use a private constructor. For example, there
is no reason to create an instance from the Math class, because all of its data fields and
methods are static. To prevent the user from creating objects from the Math class, the
constructor in java.lang.Math is defined as follows:
private Math() {
}
Order of static blocks, non static blocks and constructor executes in java.

Any code written inside class with static keyword is called static block. This static block is class level code. So whenever Class Loader loads the class in jvm the static code in that class is executed. So we should be clear that the static block will be executed only once at time of loading of class. It will be executed before any code in the class. If you have any super class which contains static block too, then the static blocks of the super class will be executed first. We know that higher level classes are loaded first.

The code in class with out any keyword are non static block. Non static blocks are also called initializer blocks because non static blocks are executed when object is initialized i.e. when constructor body is executed. But if we have super class, then constructor of super class is executed. Execution of super class constructor is part of object creation  and execution of sub class constructor is part of object initialization. So as the name implies, initializer block execute after super class constructor but before sub class constructor.

The execution order of this example concludes:
    First Static block is executed (class loading )
    Then super class constructor is executed(object creation).
    Next initializer block will be executed(before object initialization)
    Then constructor will be executed(object initialization )

Output will be:

Static of super
static
non static super
super class constructor
nonstatic
constructor
Main method
non static supper
Supper class constructor
nonstatic
constructor
package blocksOrder;

public class Supper {
{
    System.out.println("non static super");        //Not static super
}
static {
System.out.println("Static of super");        //static super
}
Supper(){
System.out.println("super class constructor");    //super constructor
}
}

public class Test extends Supper {
Test() {
System.out.println("constructor");        // constructor
}
static {         
System.out.println("static");            // Static block
}
{         
System.out.println("nonstatic");            // Non static block
}


public static void main(String[] args) {
Test t = new Test();
System.out.println("Main method");
Test t1=new Test();
}
}
Class Loading

a class is loaded:

    when the new bytecode is executed. For example, SomeClass f = new SomeClass();
    when the bytecodes make a static reference to a class. For example, System.out.

When and how is a Java class initialized?

A class is initialized when a symbol in the class is first used. When a class is loaded it is not initialized.

JVM will initialize superclass and fields in textual order, initialize static, final fields first, and give every field a default value before initialization.

Class loading
Whenever the JVM determines it needs a class (to use its static variables, to create a new object, to use its static methods etc) it will load the class and static initialisation blocks will run, static variables are initialised etc. This is (at least under normal circumstances) done only once

SomeClass.someStaticMethod(); //SomeClass is loaded (if its not already)
SomeClass.someStaticVariable; //SomeClass is loaded (if its not already)
SomeClass var=new SomeClass(); //SomeClass is BOTH loaded (if its not already) AND instantiated

As a result the following runs (as an example):
static Vector3d var=new Vector3d(); //static variables are initialised

static{
    //static initialisation block are run
}
Instantiating a class
On the other hand you instantiate a class when you create an instance of the class with the new keyword; instantiating a class is creating an object of the class.
SomeClass var=new SomeClass(); //SomeClass is instantiating (and loaded if its not already)
As a result the constructor runs:
public SomeClass(){
}
and
{
    //initialisation block(s) also run (but these are very uncommonly used)
}

When Class is loaded in Java
Class loading is done by ClassLoaders in Java which can be implemented to eagerly load a class as soon as another class references it or lazy load the class until a need of class initialization occurs. If Class is loaded before its actually being used it can sit inside before being initialized. I believe this may vary from JVM to JVM. While its guaranteed by JLS that a class will be loaded when there is a need of static initialization.

When a Class is initialized in Java
After class loading, initialization of class takes place which means initializing all static members of class. A Class is initialized in Java when :


1) an Instance of class is created using either new() keyword or using reflection using class.forName(), which may throw ClassNotFoundException in Java.

2) an static method of Class is invoked.
3) an static field of Class is assigned.
4) an static field of class is used which is not a constant variable.
5) if Class is a top level class and an assert statement lexically nested within class is executed.

Reflection can also cause initialization of class. Some methods of java.lang.reflect package may cause class to be initialized. JLS Strictly says that a class should not be initialized by any reason other than above.

How Class is initialized in Java
Now we know what triggers initialization of a class in Java, which is precisely documented in Java language specification. Its also important to know in which order various fields (static and non static), block (static an non static), various classes (sub class and super class) and various interfaces (sub interface, implementation class and super interface) is initialized in Java. Infact many Core Java interview question and SCJP question based on this concept because it affect final value of any variable if its initialized on multiple places. Here are some of the rules of class initialization in Java:

1) Classes are initialized from top to bottom so field declared on top initialized before field declared in bottom
2) Super Class is initialized before Sub Class or derived class in Java
3) If Class initialization is triggered due to access of static field, only Class which has declared static field is initialized and it doesn't trigger initialization of super class or sub class even if static field is referenced by Type  of Sub Class, Sub Interface or by implementation class of interface.

4) interface initialization in Java doesn't cause super interfaces to be initialized.
5) static fields are initialized during static initialization of class while non static fields are initialized when instance of class is created. It means static fields are initialized before non static fields in Java.

6)non static fields are initialized by constructors in Java. sub class constructor implicitly call super class constructor before doing any initialization, which guarantees that non static or instance variables of super class is initialized before sub class.

Examples of  class initialization in Java:
Here is an example of when class is initialized in Java. In this example we will see which classes are initialized in Java.

/**
 * Java program to demonstrate class loading and initialization in Java.
 */
public class ClassInitializationTest {

    public static void main(String args[]) throws InterruptedException {

        NotUsed o = null; //this class is not used, should not be initialized
        Child t = new Child(); //initializing sub class, should trigger super class initialization
        System.out.println((Object)o == (Object)t);
    }
}

/**
 * Super class to demonstrate that Super class is loaded and initialized before Subclass.
 */
class Parent {
    static { System.out.println("static block of Super class is initialized"); }
    {System.out.println("non static blocks in super class is initialized");}
}

/**
 * Java class which is not used in this program, consequently not loaded by JVM
 */
class NotUsed {
    static { System.out.println("NotUsed Class is initialized "); }
}

/**
 * Sub class of Parent, demonstrate when exactly sub class loading and initialization occurs.
 */
class Child extends Parent {
    static { System.out.println("static block of Sub class is initialized in Java "); }
    {System.out.println("non static blocks in sub class is initialized");}
}

Output:
static block of Super class is initialized
static block of Sub class is initialized in Java
non static blocks in super class is initialized
non static blocks in sub class is initialized
false


Observation:
1) Super class is initialized before sub class in Java.
2) Static variables or blocks are initialized before non static blocks or fields.
3) Not used class is not initialized at all because its not been used, none of the cases mentioned on JLS or above which triggers initialization of class is not happened here.

Let's have a look on another example of class initialization in Java:

/**
 * Another Java program example to demonstrate class initialization and loading in Java.
 */

public class ClassInitializationTest {

    public static void main(String args[]) throws InterruptedException {

       //accessing static field of Parent through child, should only initialize Parent
       System.out.println(Child.familyName);
    }
}

class Parent {
    //compile time constant, accessing this will not trigger class initialization
    //protected static final String familyName = "Lawson";

    protected static String familyName = "Lawson";

    static { System.out.println("static block of Super class is initialized"); }
    {System.out.println("non static blocks in super class is initialized");}
}

Output:
static block of Super class is initialized
Lawson


Observation
1. Here class initialization occurs because static field is accessed which is not a compile time constant. had you declare "familyName" compile time constant using final keyword in Java (as shown in commented section) class initialization of super class would not have occurred.

2) Only super class is initialized even though static field is referenced using sub type.

There is another example of class initialization related to interface on JLS which explains clearly that initialization of sub interfaces does not trigger initialization of super interface. I highly recommend reading JLS 14.4 for understating  class loading and initialization in more detail.

That's all on When a class is initialized and loaded in Java. We have seen clear guidelines form JLS regarding class initialization. We have also seen the order on which super type and sub type are initialized and order of initialization for both static and non static fields and blocks in Java.
