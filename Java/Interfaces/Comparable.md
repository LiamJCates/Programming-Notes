The Comparable Interface
The Comparable interface defines the compareTo method for comparing objects.

Suppose you want to compare objects of the same type, to sort them for example.
The two objects must be comparable, so a common behavior for the objects must be the ability to be compared. Java provides the Comparable interface which defines a generic method for this purpose:

package java.lang;

public interface Comparable<E> {
     public int compareTo(E o);
}

In order to implement this interface, a class has to
Specify the type T refers to, and
Provide a method named compareTo that takes an object as a parameter and returns an int.

For example, here’s the source code for java.lang.Integer:

public final class Integer extends Number implements Comparable<Integer> {
public int compareTo(Integer anotherInteger) {
int thisVal = this.value;
int anotherVal = anotherInteger.value;
return (thisVal < anotherVal ? -1 : (thisVal==anotherVal ? 0 : 1));
}
// other methods omitted
}


This class extends Number, so it inherits the methods and instance variables of Number; and it
implements Comparable<Integer>, so it provides a method named compareTo that takes an
Integer and returns an int.



The compareTo method determines the order of this object with the specified object o and returns a negative integer, zero, or a positive integer if this object is less than, equal to, or greater than o. The Comparable interface is a generic interface. The generic type E is replaced by a concrete type when implementing this interface. Many classes in the Java library implement Comparable to define a natural order for objects.

An interface provides another form of generic programming. It would be difficult to use a generic sort method to sort the objects without using an interface in this example, because multiple inheritance would be necessary to inherit Comparable and another class

The Object class contains the equals method, which is intended for the subclasses of the Object class to override in order to compare whether the contents of the objects are the same. Suppose the Object class contains the compareTo method, as defined in the Comparable interface; the sort method can be used to compare a list of any objects. Whether a compareTo method should be included in the Object class is debatable. Since the compareTo method is not defined in the Object class, the Comparable interface is defined in Java to enable objects to be compared if they are instances of the Comparable interface. compareTo should be consistent with equals. That is, for two objects o1 and o2, o1.compareTo(o2) == 0 if and only if o1.equals(o2) is true.
