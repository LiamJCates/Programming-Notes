These characteristics represent a pure approach to object-oriented programming:

1. Everything is an object
  Think of an object as a fancy variable; it stores data, but you can “make requests” to that object, asking it to perform operations on itself. In theory, you can take any conceptual component in the problem you’re trying to solve (dogs, buildings, services, etc.) and represent it as an object in your program.

2. A program is a bunch of objects telling each other what to do by sending message.
  To make a request of an object, you “send a message” to that object. More concretely, you can think of a message as a request to call a function that belongs to a particular object.

3. Each object has its own memory made up of other objects.
  Put another way, you create a new kind of object by making a package containing existing objects. Thus, you can build complexity in a program while hiding it behind the simplicity of objects.

4. Every object has a type.
  Using the parlance, each object is an instance of a class, in which “class” is synonymous with “type.” The most important distinguishing characteristic of a class is “What messages can you send to it?”

5. All objects of a particular type can receive the same messages.
  This is actually a loaded statement, as you will see later. Because an object of type “circle” is also an object of type “shape,” a circle is guaranteed to accept shape messages. This means you can write code that talks to shapes and automatically handles anything that fits the description of a shape. This substitutability is one of the most powerful concepts in OOP.


Aristotle was probably the first to begin a careful study of the concept of type; he spoke of “the class of fishes and the class of birds.” The idea that all objects, while being unique, are also part of a class of objects that have characteristics and behaviors in common was used directly in the first object-oriented language, Simula-67, with its fundamental keyword class that introduces a new type into a program.

Creating abstract data types (classes) is a fundamental concept in object-oriented programming. Abstract data types work almost exactly like built-in types: You can create variables of a type (called objects or instances in object-oriented parlance) and manipulate those variables (called sending messages or requests; you send a message and the object figures out what to do with it).
The members (elements) of each class share some commonality in the characteristics and possible behaviors they model.

At the same time, each member has its own state

each be represented with a unique
entity in the computer program. This entity is the object, and each
object belongs to a particular class that defines its characteristics
and behaviors.

So, although what we really do in object-oriented programming is
create new data types, virtually all object-oriented programming
languages use the “class” keyword. When you see the word “type”
think “class” and vice versa.

Some people make a distinction, stating that type determines the interface while
class is a particular implementation of that interface.

Since a class describes a set of objects that have identical
characteristics (data elements) and behaviors (functionality), a class
is really a data type because a floating point number, for example,
also has a set of characteristics and behaviors. The difference is that
a programmer defines a class to fit a problem rather than being
forced to use an existing data type that was designed to represent a unit of storage in a machine. You extend the programming
language by adding new data types specific to your needs. The
programming system welcomes the new classes and gives them all
the care and type-checking that it gives to built-in types.
The object-oriented approach is not limited to building simulations.
Whether or not you agree that any program is a simulation of the
system you’re designing, the use of OOP techniques can easily
reduce a large set of problems to a simple solution.
Once a class is established, you can make as many objects of that
class as you like, and then manipulate those objects as if they are
the elements that exist in the problem you are trying to solve.
Indeed, one of the challenges of object-oriented programming is to
create a one-to-one mapping between the elements in the problem
space and objects in the solution space.
But how do you get an object to do useful work for you? There
must be a way to make a request of the object so that it will do
something, such as complete a transaction, draw something on the
screen or turn on a switch. And each object can satisfy only certain
requests. The requests you can make of an object are defined by its
interface, and the type is what determines the interface.

The interface establishes what requests you can make for a
particular object. However, there must be code somewhere to
satisfy that request. This, along with the hidden data, comprises the

implementation. From a procedural programming standpoint, it’s
not that complicated. A type has a function associated with each
possible request, and when you make a particular request to an
object, that function is called. This process is usually summarized
by saying that you “send a message” (make a request) to an object,
and the object figures out what to do with that message (it executes
code)

It is helpful to break up the playing field into class creators (those
who create new data types) and client programmers4 (the class
consumers who use the data types in their applications). The goal
of the client programmer is to collect a toolbox full of classes to use for rapid application development. The goal of the class creator is
to build a class that exposes only what’s necessary to the client
programmer and keeps everything else hidden. Why? Because if
it’s hidden, the client programmer can’t use it, which means that
the class creator can change the hidden portion at will without
worrying about the impact to anyone else. The hidden portion
usually represents the tender insides of an object that could easily
be corrupted by a careless or uninformed client programmer, so
hiding the implementation reduces program bugs. The concept of
implementation hiding cannot be overemphasized.

If all the members of a class are available to everyone, then the
client programmer can do anything with that class and there’s no
way to enforce rules. Even though you might really prefer that the
client programmer not directly manipulate some of the members of
your class, without access control there’s no way to prevent it.
Everything’s naked to the world.

So the first reason for access control is to keep client programmers’
hands off portions they shouldn’t touch – parts that are necessary
for the internal machinations of the data type but not part of the
interface that users need in order to solve their particular problems.
This is actually a service to users because they can easily see what’s
important to them and what they can ignore.
The second reason for access control is to allow the library designer
to change the internal workings of the class without worrying
about how it will affect the client programmer. For example, you
might implement a particular class in a simple fashion to ease
development, and then later discover that you need to rewrite it in
order to make it run faster. If the interface and implementation are clearly separated and protected, you can accomplish this easily and
require only a relink by the user.

Once a class has been created and tested, it should (ideally)
represent a useful unit of code. It turns out that this reusability is
not nearly so easy to achieve as many would hope; it takes
experience and insight to produce a good design. But once you
have such a design, it begs to be reused. Code reuse is one of the
greatest advantages that object-oriented programming languages
provide.
The simplest way to reuse a class is to just use an object of that class
directly, but you can also place an object of that class inside a new
class. We call this “creating a member object.” Your new class can
be made up of any number and type of other objects, in any
combination that you need to achieve the functionality desired in
your new class. Because you are composing a new class from
existing classes, this concept is called composition (or more
generally, aggregation). Composition is often referred to as a “has-a”
relationship, as in “a car has an engine.”

Composition comes with a great deal of flexibility. The member
objects of your new class are usually private, making them
inaccessible to the client programmers who are using the class. This
allows you to change those members without disturbing existing
client code. You can also change the member objects at runtime, to
dynamically change the behavior of your program. Inheritance,
which is described next, does not have this flexibility since the
compiler must place compile-time restrictions on classes created
with inheritance.
Because inheritance is so important in object-oriented
programming it is often highly emphasized, and the new
programmer can get the idea that inheritance should be used
everywhere. This can result in awkward and overly-complicated
designs. Instead, you should first look to composition when
creating new classes, since it is simpler and more flexible. If you
take this approach, your designs will stay cleaner. Once you’ve had
some experience, it will be reasonably obvious when you need
inheritance.

A type does more than describe the constraints on a set of objects; it
also has a relationship with other types.

Two types can have characteristics and behaviors in common, but one type may contain more characteristics than another and may also handle more
messages (or handle them differently).

Inheritance expresses this similarity between types using the concept of base types and derived types.

A base type contains all of the characteristics and behaviors that are shared among the types derived from it. You create a base type to represent the core of your ideas about some objects in your system. From the base type, you derive other types to express the different ways that this core can be realized.

Casting the solution in the same terms as the problem is
tremendously beneficial because you don’t need a lot of
intermediate models to get from a description of the problem to a
description of the solution. With objects, the type hierarchy is the
primary model, so you go directly from the description of the
system in the real world to the description of the system in code.
Indeed, one of the difficulties people have with object-oriented
design is that it’s too simple to get from the beginning to the end. A
mind trained to look for complex solutions is often stumped by this
simplicity at first.

When you inherit from an existing type, you create a new type.
This new type contains not only all the members of the existing
type, but more importantly it duplicates the interface of the base class.
That is, all the messages you can send to objects of the base class
you can also send to objects of the derived class. Since we know the
type of a class by the messages we can send to it, this means that
the derived class is the same type as the base class.

This type equivalence via inheritance
is one of the fundamental gateways in understanding the meaning
of object-oriented programming

Since both the base class and derived class have the same interface,
there must be some implementation to go along with that interface.
That is, there must be some code to execute when an object receives
a particular message. If you simply inherit a class and don’t do
anything else, the methods from the base-class interface come right
along into the derived class. That means objects of the derived class
have not only the same type, they also have the same behavior,
which isn’t particularly interesting.

You have two ways to differentiate your new derived class from
the original base class. The first is quite straightforward: You
simply add brand new functions to the derived class. These new
functions are not part of the base class interface. This means that
the base class simply didn’t do as much as you wanted it to, so you
added more functions. This simple and primitive use for
inheritance is, at times, the perfect solution to your problem.
However, you should look closely for the possibility that your base
class might also need these additional functions. This process of
discovery and iteration of your design happens regularly in object-oriented programming.

Although inheritance may sometimes imply that you are going to
add new functions to the interface, that’s not necessarily true. The
second and more important way to differentiate your new class is
to change the behavior of an existing base-class function. This is
referred to as overriding that function.

To override a function, you simply create a new definition for the
function in the derived class. You’re saying, “I’m using the same
interface function here, but I want it to do something different for
my new type".


Is-a vs. is-like-a relationships
There’s a certain debate that can occur about inheritance: Should
inheritance override only base-class functions (and not add new
member functions that aren’t in the base class)? This would mean
that the derived type is exactly the same type as the base class since
it has exactly the same interface. As a result, you can exactly
substitute an object of the derived class for an object of the base
class. This can be thought of as pure substitution, and it’s often
referred to as the substitution principle. In a sense, this is the ideal
way to treat inheritance. We often refer to the relationship between

The base class and derived classes in this case as an is-a relationship,
because you can say “a circle is a shape.” A test for inheritance is to
determine whether you can state the is-a relationship about the
classes and have it make sense.
There are times when you must add new interface elements to a
derived type, thus extending the interface and creating a new type.
The new type can still be substituted for the base type, but the
substitution isn’t perfect because your new functions are not
accessible from the base type. This can be described as an is-like-a
relationship; the new type has the interface of the old type but it
also contains other functions, so you can’t really say it’s exactly the
same.


Polymorphism
When dealing with type hierarchies, you often want to treat an
object not as the specific type that it is but instead as its base type.
This allows you to write code that doesn’t depend on specific types.

Such code is unaffected by the addition of new types, and adding
new types is the most common way to extend an object-oriented
program to handle new situations.

This ability to extend
a program easily by deriving new subtypes is important because it
greatly improves designs while reducing the cost of software
maintenance.

There’s a problem, however, with attempting to treat derived-type
objects as their generic base types

When a function is called
the compiler cannot know at compile-time
precisely what piece of code will be executed. That’s the whole
point – when the message is sent, the programmer doesn’t want to
know what piece of code will be executed;

If you
don’t have to know what piece of code will be executed, then when
you add a new subtype, the code it executes can be different
without requiring changes to the function call.

The answer is the primary twist in object-oriented programming:
The compiler cannot make a function call in the traditional sense.
The function call generated by a non-OOP compiler causes what is
called early binding, a term you may not have heard before because
you’ve never thought about it any other way. It means the compiler
generates a call to a specific function name, and the linker resolves this call to the absolute address of the code to be executed. In OOP,
the program cannot determine the address of the code until
runtime, so some other scheme is necessary when a message is sent
to a generic object.

To solve the problem, object-oriented languages use the concept of
late binding. When you send a message to an object, the code being
called isn’t determined until runtime. The compiler does ensure
that the function exists and performs type checking on the
arguments and return value (a language in which this isn’t true is
called weakly typed), but it doesn’t know the exact code to execute.

To perform late binding, the compiler inserts a special bit of
code in lieu of the absolute call. This code calculates the address of
the function body, using information stored in the object . Thus, each object
can behave differently according to the contents of that special bit
of code. When you send a message to an object, the object actually
does figure out what to do with that message.

To
demonstrate polymorphism, we want to write a single piece of
code that ignores the specific details of type and talks only to the
base class. That code is decoupled from type-specific information,
and thus is simpler to write and easier to understand.

If a new type is added through inheritance, the code you write will work just as well for the new type as
it did on the existing types. Thus, the program is extensible.

We call this process of treating a derived type as though it were its
base type upcasting. The name cast is used in the sense of casting
into a mold and the up comes from the way the inheritance diagram
is typically arranged, with the base type at the top and the derived classes fanning out downward. Thus, casting to a base type is
moving up the inheritance diagram: “upcasting.



Creating and destroying objects

Technically, the domain of OOP is abstract data typing, inheritance,
and polymorphism, but other issues can be at least as important.
This section gives an overview of these issues.
Especially important is the way objects are created and destroyed.
Where is the data for an object and how is the lifetime of that object
controlled? Different programming languages use different
philosophies here.

C++ takes the approach that control of efficiency
is the most important issue, so it gives the programmer a choice.
For maximum runtime speed, the storage and lifetime can be
determined while the program is being written, by placing the
objects on the stack or in static storage. The stack is an area in
memory that is used directly by the microprocessor to store data
during program execution. Variables on the stack are sometimes
called automatic or scoped variables. The static storage area is simply
a fixed patch of memory that is allocated before the program begins
to run. Using the stack or static storage area places a priority on the
speed of storage allocation and release, which can be valuable in
some situations. However, you sacrifice flexibility because you
must know the exact quantity, lifetime, and type of objects while
you’re writing the program. If you are trying to solve a more
general problem, such as computer-aided design, warehouse
management, or air-traffic control, this is too restrictive.

The second approach is to create objects dynamically in a pool of
memory called the heap. In this approach you don’t know until
runtime how many objects you need, what their lifetime is, or what
their exact type is. Those decisions are made at the spur of the
moment while the program is running. If you need a new object,
you simply make it on the heap when you need it.

When you’re finished with the storage, you must release
it.

Because the storage is managed dynamically at runtime, the
amount of time required to allocate storage on the heap is
significantly longer than the time to create storage on the stack.
(Creating storage on the stack is often a single microprocessor
instruction to move the stack pointer down, and another to move it
back up.) The dynamic approach makes the generally logical
assumption that objects tend to be complicated, so the extra
overhead of finding storage and releasing that storage will not have
an important impact on the creation of an object. In addition, the
greater flexibility is essential to solve general programming
problems.

There’s another issue, however, and that’s the lifetime of an object.
If you create an object on the stack or in static storage, the compiler
determines how long the object lasts and can automatically destroy
it. However, if you create it on the heap, the compiler has no
knowledge of its lifetime.

 As an alternative, the
environment can provide a feature called a garbage collector that
automatically discovers when an object is no longer in use and
destroys it. Of course, writing programs using a garbage collector is
much more convenient, but it requires that all applications must be
able to tolerate the existence of the garbage collector and the
overhead for garbage collection.



Exception handling wires error handling directly into the
programming language and sometimes even the operating system.
An exception is an object that is “thrown” from the site of the error
and can be “caught” by an appropriate exception handler designed to
handle that particular type of error. It’s as if exception handling is a
different, parallel path of execution that can be taken when things
go wrong. And because it uses a separate execution path, it doesn’t
need to interfere with your normally-executing code. This makes
that code simpler to write since you aren’t constantly forced to
check for errors. In addition, a thrown exception is unlike an error
value that’s returned from a function or a flag that’s set by a
function in order to indicate an error condition – these can be
ignored. An exception cannot be ignored so it’s guaranteed to be
dealt with at some point. Finally, exceptions provide a way to
recover reliably from a bad situation. Instead of just exiting the
program, you are often able to set things right and restore the
execution of a program, which produces much more robust
systems.
It’s worth noting that exception handling isn’t an object-oriented
feature, although in object-oriented languages the exception is
normally represented with an object. Exception handling existed
before object-oriented languages.
