Encapsulation

Encapsulation is a fundamental concept of object-oriented programming.

"the process of compartmentalizing the elements of an abstraction that constitute its structure and behavior; encapsulation serves to separate the contractual interface of an abstraction and its implementation."


Encapsulation is a technique used to abstract components of a system to reduce its complexity.

Related data and behavior that comprise a logical component are said to be encapsulated by extracting them and placing them into their own unit of abstraction.

The aggregate system has to be concerned with the interface to a unit of abstraction rather than the complexity of managing that unit.



An suitable example of an encapsulated object is a watch.

We are aware that there are gears and springs inside the watch, but we usually know very little about why all these parts are in a particular configuration.

As users, we are interested in the watches interface
The initial input required is a watch battery and the current time
The output is what the hands show

With this interface we can use a watch without worrying about the complexity of the inner workings, the watch's implementation.




The basic unit of abstraction in a class.

As a developer, there are two main reasons why you would choose to abstract the complexity of the internal workings of the object.

1) provide a simplified and understandable interface to use your object without the need to understand the complexity inside.

A driver doesn't need to know how an internal combustion engine works.
Think of an interface as the collection of things you can do to the car without knowing how each works.
It is sufficient to know how to start the car, engage the transmission, provide fuel, turning off the engine. These basic operations form an interface for the car.
Hiding the complexity of the car from the user allows anyone, not just a mechanic, to drive a car.

In the same way, hiding the complex functionality of your object from the user allows anyone to use it and to find ways to reuse it in the future regardless of their knowledge of the internal workings.

2) To manage change.
Today most of us who drive use a vehicle with a gasoline-powered internal combustion engine. However, there a gas-electric hybrids, pure electric motors, and a variety of internal combustion engines that use alternative fuels. Each of those engine types has a different internal mechanism yet we are able to drive each of them because that complexity has been hidden. This means that, even though the mechanism which propels the car changes, the system itself functions the same way from the user's perspective.









Encapsulation promotes
Bundling code into individual software objects provides a number of benefits, including:

Code-Reuse
As complex systems can rely on similar components if an object already exists (perhaps written by another software developer), you can use that object in your program. This allows specialists to implement/test/debug complex, task-specific objects, which you can then trust to run in your own code.


Separation of Concerns        

Single Responsibility Principle:


Low Cohesion:


Modularity:
The source code for an object can be written and maintained independently of the source code for other objects. Once created, an object can be easily passed around inside the system.

Information-hiding:
By interacting only with an object's methods, the details of its internal implementation remain hidden from the outside world.

Pluggability and debugging ease:
If a particular object turns out to be problematic, you can simply remove it from your application and plug in a different object as its replacement. This is analogous to fixing mechanical problems in the real world. If a bolt breaks, you replace it, not the entire machine.
