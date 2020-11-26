Data/Information hiding takes encapsulation a step further to maintain separation by ensuring an encapsulated component's internals are hidden, rather than only abstracted, exposing only a user interface.

Information hiding is the way to give an object “black box” behavior



Like a watch, we should not have access to the mechanism so that we do not damage it, inadvertently or on purpose. This mechanism is hidden from us, we have no immediate access to it, and the watch is protected and works better than when its mechanism is open for everyone to see.

An object is like a black box whose behavior is very well defined, and we use the object because we know what it does, not because we have an insight into how it does it.

An object discloses only as much as is needed for the user to utilize it. It has a public part that can be accessed by any user when the user sends a message matching any of the member function names revealed by the object. In this public part, the object displays to the user buttons that can be pushed to invoke the object's operations. The user knows only the names of these operations and the expected behavior.

Information hiding tends to blur the dividing line between data and operations.

In procedural languages, the distinction between data and functions or procedures is clear and rigid. They are defined differently and their roles are very distinct.

OOLs put data and methods together, and to the user of the object, this distinction is much less noticeable. 



Data hiding is a technique of protecting class members such that they are only manipulated inside the class, protecting them from unauthorized access.

Internal data and methods are made private
The components desired interface is made public

If you have an attribute that is not visible from the outside of an object, and bundle it with methods that provide read or write access to it, then you can hide specific information and control access to the internal state of the object.

To continue the Car metaphor, imagine that the car's body is now a solid shell of metal, the engine is no longer accessible and rather than going to a particular fuel station, all cars now accept a universal pump that either refuels or fast charges in the same amount of time.

We can no longer access or know what sort of engine or fuel type we use but the method by which we interface with the car, starting, shifting, refueling, and turning off the engine remains consistent.

Hiding the internals of the object
limits the interdependencies between software components through a stable interface
protects its integrity by preventing users from setting the internal data to an invalid state.

information hiding is the principle of segregation of the design decisions in a computer program that are most likely to change, thus protecting other parts of the program from extensive modification if the design decision is changed. The protection involves providing a stable interface which protects the remainder of the program from the implementation (the details that are most likely to change).

The following type is merely encapsulated: we have created a concept representing a geometrical concept (the point in a 2D space).

public class Point
{
    public double x;
    public double y;
}
The following type, on the other hand, is an example of information hiding applied to the same concept:

public class Point
{
    double GetX();
    double GetY();
    void SetCartesian(double x, double y);
    double GetR();
    double GetTheta();
    void SetPolar(double r, double theta);
}
In this second example, the actual implementation is completely hidden: the client doesn't know whether the internal representation of the point is in rectangular or polar coordinates.
