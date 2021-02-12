Data/Information hiding takes encapsulation a step further to force the use of the interface provided by a programmatically defined abstraction. Information hiding mechanisms define a distinction between an encapsulated abstraction unit's (a classes') public interface and private internals. The internals of a component are then said to be "hidden" from the classes' clients.

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

To make a method available outside the class, we can use public members. A method that allows access from outside the class to retrieve private data is a getter. A method that allows access from outside the class to alter private data is a setter.

A natural question at this point is why we need to bother having these getters and setters. Why can't we just leave data public and let anyone read and change them as they want? The reason is that keeping the data private and controlling access to it through methods will give us control.

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










I’ve been told to never use protected data, and instead to always use private data with protected access functions. Is that a good rule?  

Nope.

Whenever someone says to you, “You should always make data private,” stop right there — it’s a one-size-fits-all rule. The real world isn’t that simple.

If I expect derived classes, I should ask this question: who will create them? If the people who will create them will be outside your team, or if there are a huge number of derived classes, then and only then is it worth creating a protected interface and using private data. If I expect the derived classes to be created by my own team and to be reasonable in number, it’s just not worth the trouble: use protected data. And hold your head up, don’t be ashamed: it’s the right thing to do!

The benefit of protected access functions is that you won’t break your derived classes as often as you would if your data was protected. Put it this way: if you believe your users will be outside your team, you should do a lot more than just provide get/set methods for your private data. You should actually create another interface. You have a public interface for one set of users, and a protected interface for another set of users. But they both need an interface that is carefully designed — designed for stability, usability, performance, etc. And at the end of the day, the real benefit of privatizing your data (including providing an interface that is coherent and, as much as possible, opaque) is to avoid breaking your derived classes when you change that data structure.

But if your own team is creating the derived classes, and there are a reasonably small number of them, it’s simply not worth the effort: use protected data. Some purists (translation: people who’ve never stepped foot in the real world, people who’ve spent their entire lives in an ivory tower, people who don’t understand words like “customer” or “schedule” or “deadline” or “ROI”) think that everything ought to be reusable and everything ought to have a clean, easy to use interface. Those kinds of people are dangerous: they often make your project late, since they make everything equally important. They’re basically saying, “We have 100 tasks, and I have carefully prioritized them: they are all priority 1.” They make the notion of priority meaningless.

You simply will not have enough time to make life easy for everyone, so the very best you can do is make life easy for a subset of the world. Prioritize. Select the people that matter most and spend time making stable interfaces for them. You may not like this, but everyone is not created equal; some people actually do matter more than others. We have a word for those important people. We call them “customers.”
