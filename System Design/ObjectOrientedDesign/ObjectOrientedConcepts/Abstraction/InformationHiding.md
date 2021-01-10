Data/Information hiding takes encapsulation a step further to force the use of a programmatically defined abstraction. Information hiding mechanisms define a distinction between an encapsulated abstraction unit's (a classes') public interface and private internals. The internals of a component are then said to be "hidden" from the classes' clients.

Data hiding is a technique of protecting class members such that they are only manipulated inside the class, unauthorized access is prevented.

Information hiding is the way to give an object “black box” behavior.

An object is like a black box in that it has a well defined behavior, and we use the object because we know what it does, not because we have an insight into how it does it.


An example of a common object with internal complexity and a simple interface is a watch.

The body of a watch prevents access to the internals mitigating the chance of both inadvertent and intentional damage or alteration. The internal mechanism is hidden from us, we have no immediate access to it, and the watch is protected and works better than when its mechanism is open for everyone to see.

Rather than being able to alter internal gears, a safe interface designed by the a watch maker is exposed such that the watch owner can set the desired time.





An object discloses only as much as is needed for the user to utilize it, which is defined by the object's interface. An object's interface is defined by public members. This interface consists of the name and expected inputs required to alter the state of the object and the output produced. The object's behaviors are then invoked by the classes' client via messages that match the name and expected inputs.


Hiding the internals of the object
  limits interdependencies between software components via a stable interface
  protects object integrity by preventing users from setting the internal data to an invalid state.




The internal complexity of an object is expressed via private members. Private members are not visible to the clients of a class and allow the hiding of specific information and control of access to the internal state of the object. Typically private members are bundled with methods that provide read or write access.

Through the mechanism of information hiding we can segregate the design decisions in a computer program that are most likely to change, thus protecting other parts of the program from modification. The protection involves providing and maintaining a stable interface which the remainder of the program interacts with.

The following type is merely encapsulated: we have created a concept representing a geometrical concept (the point in a 2D space).

class Point
{
    public double x;
    public double y;
}

The following type, on the other hand, is an example of information hiding applied to the same concept:

class Point
{
    double GetX();
    double GetY();
    void SetCartesian(double x, double y);
    double GetR();
    double GetTheta();
    void SetPolar(double r, double theta);
}

In this second example, the actual implementation is completely hidden: the client doesn't know whether the internal representation of the point is in rectangular or polar coordinates but can use an interface to interact with a point option regardless of the internal implementation.
