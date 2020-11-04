The Cloneable Interface
The Cloneable interface specifies that an object can be cloned.

Often, it is desirable to create a copy of an object. To do this, you need to use the clone method and understand the Cloneable interface.

An interface contains constants and abstract methods, but the Cloneable interface is a
special case. The Cloneable interface in the java.lang package is defined as follows:
package java.lang;
public interface Cloneable {
}
This interface is empty. An interface with an empty body is referred to as a marker interface.
A marker interface is used to denote that a class possesses certain desirable properties. A class
that implements the Cloneable interface is marked cloneable, and its objects can be cloned
using the clone() method defined in the Object class.

The clone method is defined by the Object class, so it’s available to all Java classes, but clone is declared with protected access in the Object class. As a result, the clone method for a given class is available only within that class. If you want other objects to be able to clone your object, you must override the clone method and give it public access. Note that the clone method defined by the Object class returns an Object type. That makes perfect sense, because the Object class doesn’t know the type of the class in which you’ll be overriding the clone method. An inconvenient side effect of returning an Object is that whenever you call the clone method for a class that overrides clone, you must cast the result to the desired object type.

Most simply, the clone method can be used to manually create a copy of the invoking object via the constructor using 'this' to reference all instance variables of the invoking object then return it.

But what if your class has a hundred or more fields that need to be duplicated? The chance of forgetting to copy one of the fields is high, and if you add a field to the class later on, you may forget to modify the clone method to include the new field.

Fortunately, you can solve this problem by using the clone method of the Object class directly in your own clone method. The clone method of the Object class can automatically create a copy of your object that contains duplicates of all the fields that are primitive types (such as int and double), as well as copies of immutable reference types — most notably, strings. So if all the fields in your class are either primitives or strings, you can use the clone method provided by the Object class to clone your class. This type of clone is known as a shallow copy.

To call the clone method from your own clone method, just specify super.clone().

Before you can do that, however, you must do two things:

» Declare that the class supports the Cloneable interface. The Cloneable interface is a tagging interface that doesn’t provide any methods. It simply marks a class as being appropriate for cloning.

» Enclose the call to super.clone() in a try/catch statement that catches the exception CloneNotSupportedException. This exception is thrown if you try to call clone on a class that doesn’t implement the Cloneable interface. Provided that you implement Cloneable, this exception won’t ever happen, but because CloneNotSupportedException is a checked exception, you must catch it.

Creating deep copies
It’s not uncommon for some fields in a class actually to be other objects.

If that’s the case, the super.clone() method won’t make a complete copy of the object. The clone won’t get a clone of the address field. Instead, it has a reference to the same address object as the original.

To solve this problem, you must do a deep copy of the object. A deep copy is a clone in which any subobjects within the main object are also cloned. To accomplish this feat, the clone method override first calls super.clone() to create a shallow copy of the object. Then it calls the clone method of each of the subobjects contained by the main object to create clones of those objects. (For a deep copy to work, of course, those objects must also support the clone methods.)

First, why is the clone method in the Object class defined protected, not public? Not
every object can be cloned. The designer of Java purposely forces the subclasses to override
it if an object of the subclass is cloneable.
Second, why is the clone method not defined in the Cloneable interface? Java provides a
native method that performs a shallow copy to clone an object. Since a method in an interface
is abstract, this native method cannot be implemented in the interface. Therefore, the designer
of Java decided to define and implement the native clone method in the Object class.
Third, why doesn’t the Object class implement the Cloneable interface? The answer is
the same as in the first question.
