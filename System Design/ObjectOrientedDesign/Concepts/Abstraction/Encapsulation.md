Encapsulation

Encapsulation is a fundamental concept of object-oriented programming.

"the process of compartmentalizing the elements of an abstraction that constitute its structure and behavior; encapsulation serves to separate the contractual interface of an abstraction and its implementation."

Encapsulation is an implementation technique used reduce the complexity of system by separating logically distinct components into individual abstraction units.

Successful encapsulation enforces a clear separation between the abstract properties of an abstraction unit and the concrete details of its implementation.

The abstract properties are those that are visible to client code and specify a stable interface.

Related data and behavior that comprise the implementation of a logical component are said to be encapsulated by extracting them and placing them into their own unit of abstraction.

The concrete implementation is kept entirely private, and can change. The idea is that such changes, for example to incorporate efficiency improvements over time, have no impact on client code, since they involve no difference in the abstract behavior utilized through a stable interface.

The aggregate system has to be concerned with the interface to a unit of abstraction rather than the complexity of managing that unit.

Abstraction solves problem at design level while encapsulation solves problem at implementation level. Thus, abstraction is focused mainly on what should be done, encapsulation is focused on how it should be done. Abstraction hides the irrelevant details found in the code whereas encapsulation helps developers to organize their code.


## Example

The basic unit of abstraction in a class.

As a developer, there are two main reasons why you would choose to abstract the complexity of the internal workings of the object.

1) provide a simplified and understandable interface to use your object without the need to understand the complexity inside.

Think of an interface as the collection of things you can do to the car without knowing how each works. A driver doesn't need to know how an internal combustion engine works. It is sufficient to know how to start the car, engage the transmission, provide fuel, turning off the engine. These basic operations form an interface for the car. Hiding the complexity of the car from the user allows anyone, not just a mechanic, to drive a car. In the same way, hiding the complex functionality of your object from the user allows anyone to use it and to find ways to reuse it in the future regardless of their knowledge of the internal workings.

2) To manage change.

Today most of us who drive use a vehicle with a gasoline-powered internal combustion engine. However, there a gas-electric hybrids, pure electric motors, and a variety of internal combustion engines that use alternative fuels. Each of those engine types has a different internal mechanism yet we are able to drive each of them because that complexity has been hidden. This means that, even though the mechanism which propels the car changes, the system itself functions the same way from the user's perspective.



## Advantages of Encapsulation

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
