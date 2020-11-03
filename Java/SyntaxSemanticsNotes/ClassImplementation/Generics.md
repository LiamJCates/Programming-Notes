Generics https://docs.oracle.com/javase/tutorial/java/generics/index.html

In a nutshell, generics enable types (classes and interfaces) to be parameters when defining classes, interfaces and methods. Much like the more familiar formal parameters used in method declarations, type parameters provide a way for you to re-use the same code with different inputs. The difference is that the inputs to formal parameters are values, while the inputs to type parameters are types.

Alternatives to Generics are either
non-type safe code that handles Objects that result in having to cast values and the possibility of runtime exceptions
Repeated code used to perform the same action for differing types that result in bloated code that is a refactoring nightmare

Code that uses generics has many benefits over non-generic code:
Stronger type checks at compile time.
 A Java compiler applies strong type checking to generic code and issues errors if the code violates type safety. Fixing compile-time errors is easier than fixing runtime errors, which can be difficult to find.
Elimination of casts.

The following code snippet without generics requires casting:
 List list = new ArrayList();
list.add("hello");
String s = (String) list.get(0);

 When re-written to use generics, the code does not require casting:
 List<String> list = new ArrayList<String>();
list.add("hello");
String s = list.get(0);   // no cast



Enabling programmers to implement generic algorithms.
 By using generics, programmers can implement generic algorithms that work on collections of different types, can be customized, and are type safe and easier to read.


Generics Parameterize Types
Generics are also known as parameterized types.

Parameterized types enable creation of classes, interfaces, and methods in which the type of data upon which they operate is specified as a parameter. A class, interface, or method that operates on a type parameter is called generic, as in generic class or generic method.

Generic classes, interfaces and methods work with varied data types. Hence, we do not need to write a new class for each data type that we want it to work with.

In addition, when we instantiate an object, we can specify what data type we want the object to work with. This allows the compiler to check for any errors that can arise if we use the wrong data type.   A generic class or method permits you to specify allowable types of objects that the class or method can work with. If you attempt to use an incompatible object, the compiler will detect that error.

With this capability, you can define a class or a method with generic types that the compiler can replace with concrete types.

Many algorithms are logically the same no matter what type of data they are being applied to. For example, a Quicksort is the same whether it is sorting items of type Integer, String, Object, or Thread.
With generics, you can define an algorithm once, independently of any specific type of data, and then apply that algorithm to a wide variety of data types without any additional effort.


Generic Types
A generic type is a generic class or interface that is parameterized over types.

A Simple Box Class
Begin by examining a non-generic Box class that operates on objects of any type. It needs only to provide two methods: set, which adds an object to the box, and get, which retrieves it:

public class Box {
    private Object object;

    public void set(Object object) { this.object = object; }
    public Object get() { return object; }
}

Since its methods accept or return an Object, you are free to pass in whatever you want, provided that it is not one of the primitive types. There is no way to verify, at compile time, how the class is used. One part of the code may place an Integer in the box and expect to get Integers out of it, while another part of the code may mistakenly pass in a String, resulting in a runtime error.



A Generic Version of the Box Class

To update the Box class to use generics, you create a generic type declaration by changing the code "public class Box" to "public class Box<T>". This introduces the type variable, T, that can be used anywhere inside the class.
With this change, the Box class becomes:

public class Box<T> {

    private T t;

    public void set(T t) { this.t = t; }
    public T get() { return t; }
}

As you can see, all occurrences of Object are replaced by T. A type variable can be any non-primitive type you specify: any class type, any interface type, any array type, or even another type variable.
This same technique can be applied to create generic interfaces.


The General Form of a Generic Class

A generic class is defined with the following format:
class ClassName <type-param-list>{ // ...

The type parameter section, delimited by angle brackets (<>), follows the class name.
class name<T1, T2, ..., Tn> { /* ... */ }

It specifies the type parameters (also called type variables) T1, T2, ..., and Tn.

Here, <T> represents a formal generic type, which can be replaced later with an actual concrete type.
When a generic class is specified, the class declaration includes one or more type parameters enclosed in angle brackets <> after the class name. T is known as a type parameter. In other words, it is a parameter for specifying the type of data that the class will operate on. It is a convention to use the uppercase letter T to represent a type parameter. Replacing a generic type is called a generic instantiation. By convention, a single capital letter such as E or T is used to denote a formal generic type.




Type Parameter Naming Conventions
By convention, type parameter names are single, uppercase letters. This stands in sharp contrast to the variable naming conventions that you already know about, and with good reason: Without this convention, it would be difficult to tell the difference between a type variable and an ordinary class or interface name.
The most commonly used type parameter names are:
E - Element (used extensively by the Java Collections Framework)
K - Key
N - Number
T - Type
V - Value
S,U,V etc. - 2nd, 3rd, 4th types


Invoking and Instantiating a Generic Type



To reference the generic Box class from within your code, you must perform a generic type invocation, which replaces T with some concrete value, such as Integer:
Box<Integer> integerBox;

Like any other variable declaration, this code does not actually create a new Box object. It simply declares that integerBox will hold a reference to a "Box of Integer", which is how Box<Integer> is read.

An invocation of a generic type is generally known as a parameterized type.

To instantiate this class, use the new keyword, as usual, but place <Integer> between the class name and the parenthesis:
Box<Integer> integerBox = new Box<Integer>();

Here is the full syntax for declaring a reference to a generic class and creating a generic instance:
class-name <type-arg-list> var-name = new class-name<type-arg-list>(cons-arg-list);

You can think of a generic type invocation as being similar to an ordinary method invocation, but instead of passing an argument to a method, you are passing a type argument — Integer in this case — to the Box class itself.

This could mislead you into thinking that the constructor of a generic class should be defined as
public GenericsClass<T>()

This is wrong. It should be defined as
public GenericsClass()

Type Parameter and Type Argument
Many developers use the terms "type parameter" and "type argument" interchangeably, but these terms are not the same. When coding, one provides type arguments in order to create a parameterized type. Therefore, the T in Foo<T> is a type parameter and the String in Foo<String> f is a type argument. This lesson observes this definition when using these terms.





The Diamond
In Java SE 7 and later, you can replace the type arguments required to invoke the constructor of a generic class with an empty set of type arguments (<>) as long as the compiler can determine, or infer, the type arguments from the context. This pair of angle brackets, <>, is informally called the diamond.

For more information on diamond notation and type inference, see Type Inference.

Type Inference with the Diamond Operator
Beginning with JDK 7, it is possible to shorten the syntax used to create an instance of a generic type.

TwoGen<Integer, String> tgObj = new TwoGen<Integer, String>(88, "str");

This form is a bit more verbose than it needs to be. Since, in the new clause, the type of the type arguments can be readily inferred, there is really no reason that they need to be specified a second time.

TwoGen<Integer, String> tgObj = new TwoGen<>(88, "str");

Notice that the instance creation portion simply uses < >, which is an empty type argument list. This is referred to as the diamond operator. It tells the compiler to infer the type arguments needed by the constructor in the new expression. The principal advantage of this type-inference syntax is that it shortens what are sometimes quite long declaration statements. This is especially helpful for generic types that specify bounds.

When type inference is used, the declaration syntax for a generic reference and instance creation has this general form:
class-name<type-arg-list> var-name = new class-name<>(cons-arg-list);



Local Variable Type Inference and Generics

You can also use the new local variable type inference feature added by JDK 10 with a generic class

var tgObj = new TwoGen<Integer, String>(88, "str");

the type of tgOb is inferred to be TwoGen because that is the type of its initializer.  In general, generic type names can often be quite long and (in some cases) complicated. The use of var is another way to substantially shorten such declarations.
Multiple Type Parameters
As mentioned previously, a generic class can have multiple type parameters. For example, the generic OrderedPair class, which implements the generic Pair interface:
public interface Pair<K, V> {
    public K getKey();
    public V getValue();
}

public class OrderedPair<K, V> implements Pair<K, V> {

    private K key;
    private V value;

    public OrderedPair(K key, V value) {
    this.key = key;
    this.value = value;
    }

    public K getKey()    { return key; }
    public V getValue() { return value; }
}

The following statements create two instantiations of the OrderedPair class:
Pair<String, Integer> p1 = new OrderedPair<String, Integer>("Even", 8);
Pair<String, String>  p2 = new OrderedPair<String, String>("hello", "world");

The code, new OrderedPair<String, Integer>, instantiates K as a String and V as an Integer. Therefore, the parameter types of OrderedPair's constructor are String and Integer, respectively. Due to autoboxing, it is valid to pass a String and an int to the class.
As mentioned in The Diamond, because a Java compiler can infer the K and V types from the declaration OrderedPair<String, Integer>, these statements can be shortened using diamond notation:
OrderedPair<String, Integer> p1 = new OrderedPair<>("Even", 8);
OrderedPair<String, String>  p2 = new OrderedPair<>("hello", "world");

To create a generic interface, follow the same conventions as for creating a generic class.

Parameterized Types
You can also substitute a type parameter (i.e., K or V) with a parameterized type (i.e., List<String>). For example, using the OrderedPair<K, V> example:
OrderedPair<String, Box<Integer>> p = new OrderedPair<>("primes", new Box<Integer>(...));


Generic Methods
A generic type can be defined for a static method

To declare a generic method, you place the generic type <E> immediately after the keyword
static in the method header and before the return type.

Generic methods are methods that introduce their own type parameters. This is similar to declaring a generic type, but the type parameter's scope is limited to the method where it is declared. Static and non-static generic methods are allowed, as well as generic class constructors.
The syntax for both static and non-static generic methods includes a list of type parameters, inside angle brackets, which appears before the method's return type.
The Util class includes a generic method, compare, which compares two Pair objects:
public class Util {
    public static <K, V> boolean compare(Pair<K, V> p1, Pair<K, V> p2) {
        return p1.getKey().equals(p2.getKey()) &&
               p1.getValue().equals(p2.getValue());
    }
}

public class Pair<K, V> {

    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    public void setKey(K key) { this.key = key; }
    public void setValue(V value) { this.value = value; }
    public K getKey()   { return key; }
    public V getValue() { return value; }
}

The complete syntax for invoking this method would be:
Pair<Integer, String> p1 = new Pair<>(1, "apple");
Pair<Integer, String> p2 = new Pair<>(2, "pear");
boolean same = Util.<Integer, String>compare(p1, p2);

The type has been explicitly provided, as shown in bold. Generally, this can be left out and the compiler will infer the type that is needed:
Pair<Integer, String> p1 = new Pair<>(1, "apple");
Pair<Integer, String> p2 = new Pair<>(2, "pear");
boolean same = Util.compare(p1, p2);

This feature, known as type inference, allows you to invoke a generic method as an ordinary method, without specifying a type between angle brackets. This topic is further discussed in the following section, Type Inference.


An unbounded generic type <E> is the same as <E extends Object>.
Note
To define a generic type for a class, place it after the class name, such as
GenericStack<E>. To define a generic type for a method, place the generic type
before the method return type, such as <E> void max(E o1, E o2).

methods inside a generic class can make use of a class’ type parameter and are, therefore, automatically generic relative to the type parameter. However, it is possible to declare a generic method that uses one or more type parameters of its own. Furthermore, it is possible to create a generic method that is enclosed within a nongeneric class.

The following program declares a nongeneric class called GenericMethodDemo and a static generic method within that class called arraysEqual( ). This method determines if two arrays contain the same elements, in the same order. It can be used to compare any two arrays as long as the arrays are of the same or compatible types and the array elements are, themselves, comparable.

class GenericMethodDemo {

static <T extends Comparable<T>, V extends T> boolean arraysEqual (T[] x, V[] y) {
if (x. length y. length) return false;
for (int 1=0; i < x. length; i++)
if ( !x[i].equals(y[i]) ) return false;
return true;
}

The type parameters are declared before the return type of the method. Also note that T extends Comparable. Comparable is an interface declared in java.lang. A class that implements Comparable defines objects that can be ordered. Thus, requiring an upper bound of Comparable ensures that arraysEqual( ) can be used only with objects that are capable of being compared. Comparable is generic, and its type parameter specifies the type of objects that it compares. (Shortly, you will see how to create a generic interface.) Next, notice that the type V is upper-bounded by T. Thus, V must be either the same as type T or a subclass of T. This relationship enforces that arraysEqual( ) can be called only with arguments that are comparable with each other. Also notice that arraysEqual( ) is static, enabling it to be called independently of any object. Understand, though, that generic methods can be either static or nonstatic. There is no restriction in this regard.

Here is the syntax for a generic method:
<type-param-list> ret-type meth-name(param-list) { //… }

In all cases, type-param-list is a comma-separated list of type parameters. Notice that for a generic method, the type parameter list precedes the return type.


Generic Constructors
A constructor can be generic, even if its class is not.

class Summation {
private int sum;

<T extends Number> Summation (T arg) {
sum = 0;
for (int i = 0; i <= arg.intValue(); i++)
sum += i;
    }

int getSum() {
return sum;
}
}

class GenConsDemo {
public static void main (String args []) {
Summation ob = new Summation (4.0) ;
System.out.println("Summation of 4.0 is " + ob.getSum() ) ;
}
}


Because Summation( ) specifies a type parameter that is bounded by Number, a Summation object can be constructed using any numeric type, including Integer, Float, or Double. No matter what numeric type is used, its value is converted to Integer by calling intValue( ), and the summation is computed. Therefore, it is not necessary for the class Summation to be generic; only a generic constructor is needed.

Generics, Inheritance, and Subtypes
As you already know, it is possible to assign an object of one type to an object of another type provided that the types are compatible. For example, you can assign an Integer to an Object, since Object is one of Integer's supertypes:
Object someObject = new Object();
Integer someInteger = new Integer(10);
someObject = someInteger;   // OK

In object-oriented terminology, this is called an "is a" relationship. Since an Integer is a kind of Object, the assignment is allowed. But Integer is also a kind of Number, so the following code is valid as well:
public void someMethod(Number n) { /* ... */ }

someMethod(new Integer(10));   // OK
someMethod(new Double(10.1));   // OK

The same is also true with generics. You can perform a generic type invocation, passing Number as its type argument, and any subsequent invocation of add will be allowed if the argument is compatible with Number:
Box<Number> box = new Box<Number>();
box.add(new Integer(10));   // OK
box.add(new Double(10.1));  // OK

Now consider the following method:
public void boxTest(Box<Number> n) { /* ... */ }

What type of argument does it accept? By looking at its signature, you can see that it accepts a single argument whose type is Box<Number>. But what does that mean? Are you allowed to pass in Box<Integer> or Box<Double>, as you might expect? The answer is "no", because Box<Integer> and Box<Double> are not subtypes of Box<Number>.
This is a common misunderstanding when it comes to programming with generics, but it is an important concept to learn.

Box<Integer> is not a subtype of Box<Number> even though Integer is a subtype of Number.
Note: Given two concrete types A and B (for example, Number and Integer), MyClass<A> has no relationship to MyClass<B>, regardless of whether or not A and B are related. The common parent of MyClass<A> and MyClass<B> is Object.

For information on how to create a subtype-like relationship between two generic classes when the type parameters are related, see Wildcards and Subtyping.

How does type variance affect generics?

Given the following class hierarchy:
class A {}
class B extends A {}

B is a subtype of A. But List<B> is not a subtype of List<A>.
Known as covariance, Java’s generics system has no way to model this.

When dealing with generic types, at certain times you may want to accept subtypes of a class. Using
the GenericStack class from the previous question, imagine a utility method, which creates a new
GenericStack from a List of A:
public static GenericStack<A> pushAllA(final List<A> listOfA) {
 final GenericStack<A> stack = new GenericStack<>();
 for (A a : listOfA) {
 stack.push(a);
 }
 return stack;
}
This compiles and works exactly as expected for Lists of A:
@Test
public void usePushAllA() {
 final ArrayList<A> list = new ArrayList<>();
 for (int i = 0; i < 10; i++) {
 list.add(new A());
 }
 final GenericStack<A> genericStack = pushAllA(list);
 assertNotNull(genericStack.pop());
 }
}
But when trying to add a List of B, it doesn’t compile:
@Test
public void usePushAllAWithBs() {
 final ArrayList<B> listOfBs = new ArrayList<>();
 for(int i = 0; i < 10; i++) {
 listOfBs.add(new B());
 }

 final GenericStack<A> genericStack = pushAllA(listOfBs);
 assertNotNull(genericStack.pop());
}
Although B is a subclass of A, List<B> is not a subtype of List<A>. The method signature of
pushAllA needs to change to explicitly allow A, and any subclass of A:
public static GenericStack<A> pushAllA(final List<? extends A> listOfA) {
The question mark is called a wildcard, and it is telling the compiler to allow any instance of a class
extending A.
Generic Classes and Subtyping
You can subtype a generic class or interface by extending or implementing it. The relationship between the type parameters of one class or interface and the type parameters of another are determined by the extends and implements clauses.
Using the Collections classes as an example, ArrayList<E> implements List<E>, and List<E> extends Collection<E>. So ArrayList<String> is a subtype of List<String>, which is a subtype of Collection<String>. So long as you do not vary the type argument, the subtyping relationship is preserved between the types.

A sample Collections hierarchy
Now imagine we want to define our own list interface, PayloadList, that associates an optional value of generic type P with each element. Its declaration might look like:
interface PayloadList<E,P> extends List<E> {
  void setPayload(int index, P val);
  ...
}

The following parameterizations of PayloadList are subtypes of List<String>:
PayloadList<String,String>
PayloadList<String,Integer>
PayloadList<String,Exception>

A sample PayloadList hierarchy

Generics allow for type-checking
The key benefit of generics is to enable errors to be detected at compile time rather than at runtime

For example, prior to Java 5 the Comparable interface was not generic, and its compareTo method took an Object as the parameter. As a result, any reference variable passed to the compareTo method would compile, even if the variable was not a sensible type, and only at runtime would the error be reported as a ClassCastException. In Java 5, the Comparable class is generic, as shown in Figure 1.10. The String class, for instance, now implements Comparable<String> and has a compareTo method that takes a String as a parameter. By making the class generic, many of the errors that were previously only reported at runtime become compile-time errors.


Only One Version of a Generic Class
The Java compiler does not actually create different versions of Gen, or of any other generic class. Although it’s helpful to think in these terms, it is not what actually happens. Instead, the compiler removes all generic type information, substituting the necessary casts, to make your code behave as if a specific version of Gen was created. Thus, there is really only one version of Gen that actually exists in your program. The process of removing generic type information is called erasure


Generics Work Only with Reference Types
When declaring an instance of a generic type, the type argument passed to the type parameter must be a reference type. You cannot use a primitive type, of course, not being able to specify a primitive type is not a serious restriction because you can use the type wrappers (as the preceding example did) to encapsulate a primitive type. Further, Java’s autoboxing and auto-unboxing mechanism makes the use of the type wrapper transparent.


Generic Types Differ Based on Their Type Arguments
A key point to understand about generic types is that a reference of one specific version of a generic type is not type-compatible with another version of the same generic type.


Pre-Generic Code
It is important to understand that Java has always given you the ability to create generalized classes, interfaces, and methods by operating through references of type Object. Because Object is the superclass of all other classes, an Object reference can refer to any type of object. Thus, in pregenerics code, generalized classes, interfaces, and methods used Object references to operate on various types of data.

The problem was that they could not do so with type safety because casts were needed to explicitly convert from Object to the actual type of data being operated upon. Thus, it was possible to accidentally create type mismatches. Generics add the type safety that was lacking because they make these casts automatic and implicit. In short, generics expand your ability to reuse code and let you do so safely and reliably.


Bounded Types

Sometimes, it may be useful to limit the data types that can be passed to a type parameter. For instance, we may want to create a generic class that only works with numbers.

This is accomplished through the use of an extends clause when specifying the type parameter:
<T extends superclass>
This specifies that T can be replaced only by superclass, or subclasses of superclass. Thus, superclass defines an inclusive, upper limit.

All numeric classes in Java (e.g. Integer and Double) are subclasses of the Number class. If we want our class to only work with numeric data types, we can declare the class as

class MyGenericsClass2 <T extends Number> {
}

Now, if we instantiate a MyGenericsClass2 object as follows,
MyGenericsClass2<String> g2 = new MyGenericsClass2();

we’ll get an error as String is not a subclass of Number.

In contrast, the statements
MyGenericsClass2<Integer> g3 = new MyGenericsClass2();
MyGenericsClass2<Double> g4 = new MyGenericsClass2();

are fine as Integer and Double are both subclasses of Number.

Bounded Type Parameters
There may be times when you want to restrict the types that can be used as type arguments in a parameterized type. For example, a method that operates on numbers might only want to accept instances of Number or its subclasses. This is what bounded type parameters are for.
To declare a bounded type parameter, list the type parameter's name, followed by the extends keyword, followed by its upper bound, which in this example is Number. Note that, in this context, extends is used in a general sense to mean either "extends" (as in classes) or "implements" (as in interfaces).
public class Box<T> {

    private T t;          

    public void set(T t) {
        this.t = t;
    }

    public T get() {
        return t;
    }

    public <U extends Number> void inspect(U u){
        System.out.println("T: " + t.getClass().getName());
        System.out.println("U: " + u.getClass().getName());
    }

    public static void main(String[] args) {
        Box<Integer> integerBox = new Box<Integer>();
        integerBox.set(new Integer(10));
        integerBox.inspect("some text"); // error: this is still String!
    }
}

By modifying our generic method to include this bounded type parameter, compilation will now fail, since our invocation of inspect still includes a String:
Box.java:21: <U>inspect(U) in Box<java.lang.Integer> cannot
  be applied to (java.lang.String)
                        integerBox.inspect("10");
                                  ^
1 error

In addition to limiting the types you can use to instantiate a generic type, bounded type parameters allow you to invoke methods defined in the bounds:
public class NaturalNumber<T extends Integer> {

    private T n;

    public NaturalNumber(T n)  { this.n = n; }

    public boolean isEven() {
        return n.intValue() % 2 == 0;
    }

    // ...
}

The isEven method invokes the intValue method defined in the Integer class through n.
Multiple Bounds
The preceding example illustrates the use of a type parameter with a single bound, but a type parameter can have multiple bounds:
<T extends B1 & B2 & B3>

A type variable with multiple bounds is a subtype of all the types listed in the bound. If one of the bounds is a class, it must be specified first. For example:
Class A { /* ... */ }
interface B { /* ... */ }
interface C { /* ... */ }

class D <T extends A & B & C> { /* ... */ }

If bound A is not specified first, you get a compile-time error:
class D <T extends B & A & C> { /* ... */ }  // compile-time error


Using Wildcard Arguments

As useful as type safety is, sometimes it can get in the way of perfectly acceptable constructs.

The trouble with the parameter type specified by <T> is that it will work only with other objects whose type is the same as the invoking object. If the invoking object is of type <Integer>, then the parameter object must also be of type <Integer>.

You can use  wildcards to specify a range for a generic type.

To create a generic method, you must use another feature of Java generics: the wildcard argument. The wildcard argument is specified by the ?, and it represents an unknown type.

return-type method-name(generic-class<?> arg) {}

A wildcard generic type has three forms: ?, ? extends T, and ? super T, where T is a generic type.
?        unbounded wildcard, is the same as ? extends Object.
? extends T    bounded wildcard, represents T or a subtype of T.
? super T    lower bound wildcard, denotes T or a supertype of T.

The wildcard can be used in a variety of situations: as the type of a parameter, field, or local variable; sometimes as a return type (though it is better programming practice to be more specific). The wildcard is never used as a type argument for a generic method invocation, a generic class instance creation, or a supertype.


Upper Bounded Wildcards
You can use an upper bounded wildcard to relax the restrictions on a variable. For example, say you want to write a method that works on List<Integer>, List<Double>, and List<Number>; you can achieve this by using an upper bounded wildcard.
To declare an upper-bounded wildcard, use the wildcard character ('?'), followed by the extends keyword, followed by its upper bound. Note that, in this context, extends is used in a general sense to mean either "extends" (as in classes) or "implements" (as in interfaces).
To write the method that works on lists of Number and the subtypes of Number, such as Integer, Double, and Float, you would specify List<? extends Number>. The term List<Number> is more restrictive than List<? extends Number> because the former matches a list of type Number only, whereas the latter matches a list of type Number or any of its subclasses.
Consider the following process method:
public static void process(List<? extends Foo> list) { /* ... */ }

The upper bounded wildcard, <? extends Foo>, where Foo is any type, matches Foo and any subtype of Foo. The process method can access the list elements as type Foo:
public static void process(List<? extends Foo> list) {
    for (Foo elem : list) {
        // ...
    }
}
In the foreach clause, the elem variable iterates over each element in the list. Any method defined in the Foo class can now be used on elem.
The sumOfList method returns the sum of the numbers in a list:
public static double sumOfList(List<? extends Number> list) {
    double s = 0.0;
    for (Number n : list)
        s += n.doubleValue();
    return s;
}

The following code, using a list of Integer objects, prints sum = 6.0:
List<Integer> li = Arrays.asList(1, 2, 3);
System.out.println("sum = " + sumOfList(li));

A list of Double values can use the same sumOfList method. The following code prints sum = 7.0:
List<Double> ld = Arrays.asList(1.2, 2.3, 3.5);
System.out.println("sum = " + sumOfList(ld));


Unbounded Wildcards
The unbounded wildcard type is specified using the wildcard character (?), for example, List<?>. This is called a list of unknown type. There are two scenarios where an unbounded wildcard is a useful approach:
If you are writing a method that can be implemented using functionality provided in the Object class.
When the code is using methods in the generic class that don't depend on the type parameter. For example, List.size or List.clear. In fact, Class<?> is so often used because most of the methods in Class<T> do not depend on T.

Consider the following method, printList:
public static void printList(List<Object> list) {
    for (Object elem : list)
        System.out.println(elem + " ");
    System.out.println();
}

The goal of printList is to print a list of any type, but it fails to achieve that goal — it prints only a list of Object instances; it cannot print List<Integer>, List<String>, List<Double>, and so on, because they are not subtypes of List<Object>. To write a generic printList method, use List<?>:
public static void printList(List<?> list) {
    for (Object elem: list)
        System.out.print(elem + " ");
    System.out.println();
}

Because for any concrete type A, List<A> is a subtype of List<?>, you can use printList to print a list of any type

It's important to note that List<Object> and List<?> are not the same. You can insert an Object, or any subtype of Object, into a List<Object>. But you can only insert null into a List<?>. The Guidelines for Wildcard Use section has more information on how to determine what kind of wildcard, if any, should be used in a given situation.

Lower Bounded Wildcards
A lower bounded wildcard restricts the unknown type to be a specific type or a super type of that type.

Expressed using the wildcard character ('?'), the super keyword, and the lower bound:
<? super A>.

Note: You can specify an upper bound for a wildcard, or you can specify a lower bound, but you cannot specify both.

Say you want to write a method that puts Integer objects into a list. To maximize flexibility, you would like the method to work on List<Integer>, List<Number>, and List<Object> — anything that can hold Integer values.

To write the method that works on lists of Integer and the supertypes of Integer, such as Integer, Number, and Object, you would specify List<? super Integer>.

The following code adds the numbers 1 through 10 to the end of a list:
public static void addNumbers(List<? super Integer> list) {
    for (int i = 1; i <= 10; i++) {
        list.add(i);
    }
}

The Guidelines for Wildcard Use section provides guidance on when to use upper bounded wildcards and when to use lower bounded wildcards.




Generic Interfaces
an interface can be generic    example Comparable<T>

In general, a generic interface is declared in the same way as a generic class.
In this case, the type parameter T specifies the type of objects that are contained.

In general, if a class implements a generic interface, then that class must also be generic, at least to the extent that it takes a type parameter that is passed to the interface.
class class-name<T> implements gen-interface<T> {}

However, if a class implements a specific type of generic interface, then the implementing class does not need to be generic.
class class-name implements gen-interface<Integer> {}

As you might expect, the type parameter(s) specified by a generic interface can be bounded. This lets you limit the type of data for which the interface can be implemented. For example, if you wanted to limit Containment to numeric types:

interface inter-name<T extends superclass>

Now, any implementing class must pass to Containment a type argument also having the same bound.

class class-name<T extends superclass> implements gen-interface<T> {}

If the interface extends a certain superclass so must the class that implements it.
Once this bound has been established, there is no need to specify it again in the implements clause and would cause an error.

Here is the generalized syntax for a generic interface:
interface interface-name<type-param-list> { // ...

Here, type-param-list is a comma-separated list of type parameters. When a generic interface is implemented, you must specify the type arguments:
class class-name<type-param-list> implements interface-name<type-param-list> {}
Raw Types
A raw type is the name of a generic class or interface without any type arguments. For example, given the generic Box class:
public class Box<T> {
    public void set(T t) { /* ... */ }
    // ...
}

To create a parameterized type of Box<T>, you supply an actual type argument for the formal type parameter T:
Box<Integer> intBox = new Box<>();

If the actual type argument is omitted, you create a raw type of Box<T>:
Box rawBox = new Box();

Therefore, Box is the raw type of the generic type Box<T>. However, a non-generic class or interface type is not a raw type.
Raw types show up in legacy code because lots of API classes (such as the Collections classes) were not generic prior to JDK 5.0. When using raw types, you essentially get pre-generics behavior — a Box gives you Objects. For backward compatibility, assigning a parameterized type to its raw type is allowed:
Box<String> stringBox = new Box<>();
Box rawBox = stringBox;               // OK

But if you assign a raw type to a parameterized type, you get a warning:
Box rawBox = new Box();           // rawBox is a raw type of Box<T>
Box<Integer> intBox = rawBox;     // warning: unchecked conversion

You also get a warning if you use a raw type to invoke generic methods defined in the corresponding generic type:
Box<String> stringBox = new Box<>();
Box rawBox = stringBox;
rawBox.set(8);  // warning: unchecked invocation to set(T)

The warning shows that raw types bypass generic type checks, deferring the catch of unsafe code to runtime. Therefore, you should avoid using raw types.
The Type Erasure section has more information on how the Java compiler uses raw types.



Erasure
The information on generics is used by the compiler but is not available at runtime. This is called type erasure.

Generics were introduced to the Java language to provide tighter type checks at compile time and to support generic programming. To implement generics, the Java compiler applies type erasure to:
Replace all type parameters in generic types with their bounds or Object if the type parameters are unbounded. The produced bytecode, therefore, contains only ordinary classes, interfaces, and methods.
Insert type casts if necessary to preserve type safety.
Generate bridge methods to preserve polymorphism in extended generic types.
Type erasure ensures that no new classes are created for parameterized types; consequently, generics incur no runtime overhead.

An important constraint that governed the way generics were added to Java was the need for compatibility with previous versions of Java. Simply put: generic code had to be compatible with preexisting, nongeneric code. Thus, any changes to the syntax of the Java language, or to the JVM, had to avoid breaking older code. The way Java implements generics while satisfying this constraint is through the use of erasure.

In general, here is how erasure works. When your Java code is compiled, all generic type information is removed (erased). This means replacing type parameters with their bound type, which is Object if no explicit bound is specified, and then applying the appropriate casts (as determined by the type arguments) to maintain type compatibility with the types specified by the type arguments. The compiler also enforces this type compatibility. This approach to generics means that no type parameters exist at run time. They are simply a source-code mechanism.

Generics are implemented using type erasure:
The compiler uses the generic-type information to compile the code, but erases it afterward. Thus, the generic information is not available at runtime. This approach enables the generic code to be backward compatible with the legacy code that uses raw types. The generics are present at compile time. Once the compiler confirms that a generic type is used safely, it converts the generic type to a raw type.

When generic classes, interfaces, and methods are compiled, the compiler replaces the generic type with the Object type.
If a generic type is bounded, the compiler replaces it with the bounded type

Ambiguity Errors
The inclusion of generics gives rise to a new type of error that you must guard against: ambiguity.

Ambiguity errors occur when erasure causes two seemingly distinct generic declarations to resolve to the same erased type, causing a conflict

class TwoGen<T, V>{
private T ob1;
private V ob2;

    void set(T o){ ob1 = o; }
void set(V o){ ob2 = o; }
}

Notice that MyGenClass declares two generic types: T and V.
Inside MyGenClass, an attempt is made to overload set( ) based on parameters of type T and V. This looks reasonable because T and V appear to be different types. However, there are two ambiguity problems here. First, as MyGenClass is written there is no requirement that T and V actually be different types. This would make both versions of set( ) identical, which is, of course, an error. Second, and more fundamental, is that the type erasure of set( ) effectively reduces both versions to the following:

void set(Object o) { // … }

Thus, the overloading of set( ) as attempted in MyGenClass is inherently ambiguous. The solution in this case is to use two separate method names rather than trying to overload set( ).
Erasure of Generic Types
During the type erasure process, the Java compiler erases all type parameters and replaces each with its first bound if the type parameter is bounded, or Object if the type parameter is unbounded.
Consider the following generic class that represents a node in a singly linked list:
public class Node<T> {

    private T data;
    private Node<T> next;

    public Node(T data, Node<T> next) {
        this.data = data;
        this.next = next;
    }

    public T getData() { return data; }
    // ...
}

Because the type parameter T is unbounded, the Java compiler replaces it with Object:
public class Node {

    private Object data;
    private Node next;

    public Node(Object data, Node next) {
        this.data = data;
        this.next = next;
    }

    public Object getData() { return data; }
    // ...
}

In the following example, the generic Node class uses a bounded type parameter:
public class Node<T extends Comparable<T>> {

    private T data;
    private Node<T> next;

    public Node(T data, Node<T> next) {
        this.data = data;
        this.next = next;
    }

    public T getData() { return data; }
    // ...
}

The Java compiler replaces the bounded type parameter T with the first bound class, Comparable:
public class Node {

    private Comparable data;
    private Node next;

    public Node(Comparable data, Node next) {
        this.data = data;
        this.next = next;
    }

    public Comparable getData() { return data; }
    // ...
}


Erasure of Generic Methods
The Java compiler also erases type parameters in generic method arguments. Consider the following generic method:
// Counts the number of occurrences of elem in anArray.
//
public static <T> int count(T[] anArray, T elem) {
    int cnt = 0;
    for (T e : anArray)
        if (e.equals(elem))
            ++cnt;
        return cnt;
}

Because T is unbounded, the Java compiler replaces it with Object:
public static int count(Object[] anArray, Object elem) {
    int cnt = 0;
    for (Object e : anArray)
        if (e.equals(elem))
            ++cnt;
        return cnt;
}

Suppose the following classes are defined:
class Shape { /* ... */ }
class Circle extends Shape { /* ... */ }
class Rectangle extends Shape { /* ... */ }

You can write a generic method to draw different shapes:
public static <T extends Shape> void draw(T shape) { /* ... */ }

The Java compiler replaces T with Shape:
public static void draw(Shape shape) { /* ... */ }


Some Generic Restrictions
There are a few restrictions that you need to keep in mind when using generics. They involve creating objects of a type parameter, static members, exceptions, and arrays

Type Parameters Can’t Be Instantiated
It is not possible to create an instance of a type parameter.

class Gen<T>{
    T ob;
    Gen() {
    ob = new T();
}
}

Here, it is illegal to attempt to create an instance of T. The reason should be easy to understand: the compiler has no way to know what type of object to create. T is simply a placeholder.

Restrictions on Static Members
No static member can use a type parameter declared by the enclosing class.
Both of the static members of this class are illegal:

class Gen<T>{
    static T ob;

    static T getob(){ return ob; }
}

Although you can’t declare static members that use a type parameter declared by the enclosing class, you can declare static generic methods, which define their own type parameters.

Generic Array Restrictions
There are two important generics restrictions that apply to arrays. First, you cannot instantiate an array whose element type is a type parameter. Second, you cannot create an array of type-specific generic references.

Generic Exception Restriction
A generic class cannot extend Throwable. This means that you cannot create generic exception classes.

Restrictions on Generics
To use Java generics effectively, you must consider the following restrictions:
Cannot Instantiate Generic Types with Primitive Types
Cannot Create Instances of Type Parameters
Cannot Declare Static Fields Whose Types are Type Parameters
Cannot Use Casts or instanceof With Parameterized Types
Cannot Create Arrays of Parameterized Types
Cannot Create, Catch, or Throw Objects of Parameterized Types
Cannot Overload a Method Where the Formal Parameter Types of Each Overload Erase to the Same Raw Type
Cannot Instantiate Generic Types with Primitive Types
Consider the following parameterized type:
class Pair<K, V> {

    private K key;
    private V value;

    public Pair(K key, V value) {
        this.key = key;
        this.value = value;
    }

    // ...
}

When creating a Pair object, you cannot substitute a primitive type for the type parameter K or V:
Pair<int, char> p = new Pair<>(8, 'a');  // compile-time error

You can substitute only non-primitive types for the type parameters K and V:
Pair<Integer, Character> p = new Pair<>(8, 'a');

Note that the Java compiler autoboxes 8 to Integer.valueOf(8) and 'a' to Character('a'):
Pair<Integer, Character> p = new Pair<>(Integer.valueOf(8), new Character('a'));

For more information on autoboxing, see Autoboxing and Unboxing in the Numbers and Strings lesson.
Cannot Create Instances of Type Parameters
You cannot create an instance of a type parameter. For example, the following code causes a compile-time error:
public static <E> void append(List<E> list) {
    E elem = new E();  // compile-time error
    list.add(elem);
}

As a workaround, you can create an object of a type parameter through reflection:
public static <E> void append(List<E> list, Class<E> cls) throws Exception {
    E elem = cls.newInstance();   // OK
    list.add(elem);
}

You can invoke the append method as follows:
List<String> ls = new ArrayList<>();
append(ls, String.class);

Cannot Declare Static Fields Whose Types are Type Parameters
A class's static field is a class-level variable shared by all non-static objects of the class. Hence, static fields of type parameters are not allowed. Consider the following class:
public class MobileDevice<T> {
    private static T os;

    // ...
}

If static fields of type parameters were allowed, then the following code would be confused:
MobileDevice<Smartphone> phone = new MobileDevice<>();
MobileDevice<Pager> pager = new MobileDevice<>();
MobileDevice<TabletPC> pc = new MobileDevice<>();

Because the static field os is shared by phone, pager, and pc, what is the actual type of os? It cannot be Smartphone, Pager, and TabletPC at the same time. You cannot, therefore, create static fields of type parameters.
Cannot Use Casts or instanceof with Parameterized Types
Because the Java compiler erases all type parameters in generic code, you cannot verify which parameterized type for a generic type is being used at runtime:
public static <E> void rtti(List<E> list) {
    if (list instanceof ArrayList<Integer>) {  // compile-time error
        // ...
    }
}

The set of parameterized types passed to the rtti method is:
S = { ArrayList<Integer>, ArrayList<String> LinkedList<Character>, ... }

The runtime does not keep track of type parameters, so it cannot tell the difference between an ArrayList<Integer> and an ArrayList<String>. The most you can do is to use an unbounded wildcard to verify that the list is an ArrayList:
public static void rtti(List<?> list) {
    if (list instanceof ArrayList<?>) {  // OK; instanceof requires a reifiable type
        // ...
    }
}
What does reified mean?
Essentially, being reified means being available at run time. Java’s generic types are not reified.
This means all the type information the compiler uses to check that any implementing code is using
generic parameters correctly is not part of the .class file definition.

Typically, you cannot cast to a parameterized type unless it is parameterized by unbounded wildcards. For example:
List<Integer> li = new ArrayList<>();
List<Number>  ln = (List<Number>) li;  // compile-time error

However, in some cases the compiler knows that a type parameter is always valid and allows the cast. For example:
List<String> l1 = ...;
ArrayList<String> l2 = (ArrayList<String>)l1;  // OK

Cannot Create Arrays of Parameterized Types
You cannot create arrays of parameterized types. For example, the following code does not compile:
List<Integer>[] arrayOfLists = new List<Integer>[2];  // compile-time error

The following code illustrates what happens when different types are inserted into an array:
Object[] strings = new String[2];
strings[0] = "hi";   // OK
strings[1] = 100;    // An ArrayStoreException is thrown.

If you try the same thing with a generic list, there would be a problem:
Object[] stringLists = new List<String>[];  // compiler error, but pretend it's allowed
stringLists[0] = new ArrayList<String>();   // OK
stringLists[1] = new ArrayList<Integer>();  // An ArrayStoreException should be thrown,
                                            // but the runtime can't detect it.

If arrays of parameterized lists were allowed, the previous code would fail to throw the desired ArrayStoreException.
Cannot Create, Catch, or Throw Objects of Parameterized Types
A generic class cannot extend the Throwable class directly or indirectly. For example, the following classes will not compile:
// Extends Throwable indirectly
class MathException<T> extends Exception { /* ... */ }    // compile-time error

// Extends Throwable directly
class QueueFullException<T> extends Throwable { /* ... */ // compile-time error

A method cannot catch an instance of a type parameter:
public static <T extends Exception, J> void execute(List<J> jobs) {
    try {
        for (J job : jobs)
            // ...
    } catch (T e) {   // compile-time error
        // ...
    }
}

You can, however, use a type parameter in a throws clause:
class Parser<T extends Exception> {
    public void parse(File file) throws T {     // OK
        // ...
    }
}

Cannot Overload a Method Where the Formal Parameter Types of Each Overload Erase to the Same Raw Type
A class cannot have two overloaded methods that will have the same signature after type erasure.
public class Example {
    public void print(Set<String> strSet) { }
    public void print(Set<Integer> intSet) { }
}

The overloads would all share the same classfile representation and will generate a compile-time error.
