Encapsulation

Encapsulation is a fundamental concept of object-oriented programming.

Encapsulation is a technique used to abstract components of a system to reduce its complexity

Related data and behaviour that comprise a logical component are said to be encapsulated by extracting them and placing them into their own unit of abstraction

The aggregate system no longer has to be concerned with the complexity of managing that unit

This abstraction unit exposes an interface that is used by the system to achieve what it needs from the component without being concerned about how the component system operates.

"the process of compartmentalizing the elements of an abstraction that constitute its structure and behavior; encapsulation serves to separate the contractual interface of an abstraction and its implementation."

Encapsulation promotes
code reuse            as complex systems can rely on similar components
Separation of Concerns        
Single Responsibility Principle
Low Cohesion

Bundling code into individual software objects provides a number of benefits, including:

Modularity: The source code for an object can be written and maintained independently of the source code for other objects. Once created, an object can be easily passed around inside the system.

Information-hiding: By interacting only with an object's methods, the details of its internal implementation remain hidden from the outside world.

Code re-use: If an object already exists (perhaps written by another software developer), you can use that object in your program. This allows specialists to implement/test/debug complex, task-specific objects, which you can then trust to run in your own code.

Pluggability and debugging ease: If a particular object turns out to be problematic, you can simply remove it from your application and plug in a different object as its replacement. This is analogous to fixing mechanical problems in the real world. If a bolt breaks, you replace it, not the entire machine.
As a developer, there are two main reasons why you would choose to abstract the complexity of the internal workings of the object.

1) provide a simplified and understandable interface to use your object without the need to understand the complexity inside.

A driver doesn't need to know how an internal combustion engine works.
Think of an interface as the collection of things you can do to the car without knowing how each works.
It is sufficient to know how to start the car, engage the transmission, provide fuel, turning off the engine. These basic operations form an interface for the car.
Hiding the complexity of the car from the user allows anyone, not just a mechanic, to drive a car.

In the same way, hiding the complex functionality of your object from the user allows anyone to use it and to find ways to reuse it in the future regardless of their knowledge of the internal workings.

2) To manage change.
Today most of us who drive use a vehicle with a gasoline-powered internal combustion engine. However, there a gas-electric hybrids, pure electric motors, and a variety of internal combustion engines that use alternative fuels. Each of those engine types has a different internal mechanism yet we are able to drive each of them because that complexity has been hidden. This means that, even though the mechanism which propels the car changes, the system itself functions the same way from the user's perspective.


Data/Information hiding takes encapsulation a step further to maintain separation by ensuring an encapsulated component's internals are hidden, rather than only abstracted, exposing only a user interface.

Information hiding is the way to give an object “black box” behavior
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
