Encapsulation

Encapsulation is a technique used to reduce system complexity

We encapsulate an aspect of system behaviour by extracting its logical components into a discrete abstraction unit

Java’s basic unit of encapsulation is the class.
The encapsulating class provides an interface to the system which then becomes its client

As long as the interface is maintained
    The Client no longer has to manage this encapsulated behavior
The encapsulating class is free to change the behavior's implementation
The Client is unaffected by an change in implementation as the interface remains static

Java provides many levels of abstraction
Class abstraction separates class implementation from how the class is used.
The creator of a class describes the functions of the class and lets the user know how the class interface use is intended






Information Hiding

Information Hiding is a technique to reduce system complexity while promoting security and reliability

We hide aspects of a classes state and behaviour from other classes exposing only the desired interface necessary for interaction


The key to information hiding is to prevent direct access to implementation details hidden by the class
hiding of behaviour and attributes is typically achieved through private access modifiers
only the desired interface is given public access modifiers
interaction with a well hidden class is only achieved through the publicly exposed interface

The collection of public constructors, methods, and fields that are accessible from outside the class, together with the description of how these members are expected to behave, serves as the class’s contract or interface.

Using information hiding we allow for calculations and checks performed by a class to be preserved
hidden attributes and behaviour are no longer directly accessible from outside use
protects hidden attributes from being set incorrectly
protects hidden behaviour from being used incorrectly
protects client classes if hidden class members change in implementation




Getters/Setters

Information hiding is most often achieved through publicly exposed getter and setter methods.
These methods read and write instance variable values, respectively.
formally Accessors and Mutators but Getters and Setters fit the Java naming convention.

Getter         returns the value of an instance variable
Setter         takes an argument value and uses it to set the value of an instance variable.

Leaving members exposed means reachable with the dot operator:     Class.instVar, Class.method()
We protect instance variables with non-public access modifiers and provide public getters and setters for access control.

public class ClassName {

    private type identifier;
    public type getIdentifier(){ return this.identifier; }

public void setIdentifier(type value){
    //value preprocessing, validation, or exception handling operations
    this.identifier = value;
}
}

Methods implemented determine if an attribute
can be read and changed    Getter and Setter
is read-only            Getter
is not visible at all.         None Implemented


A setter method is often used to implement boundaries to ensure an object maintains a valid state

So how does information hiding set boundaries?
By forcing other code to go through setter methods.
The setter method can perform validation checks
reject it and do nothing, throw an Exception, or round the parameter sent in to the nearest acceptable value.
You are free to implement the setter method
You can’t protect public instance variables

There are setter methods that simply set private attributes without checking anything, doesn’t that create unnecessary overhead?

The point to setters (and getters, too) is that you can change implementation in the future without breaking any client code!
Performance gain from using variables directly is so miniscule and rarely be worth it.
