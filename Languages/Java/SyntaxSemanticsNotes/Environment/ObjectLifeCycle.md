The life cycle of an object:
1. Before an object can be created from a class, the class must be loaded. To do that, the Java runtime locates the class on disk (in a .class file) and reads it into memory. Then Java looks for any static initializers that initialize static fields — fields that don’t belong to any particular instance of the class, but
belong to the class itself and are shared by all objects created from the class.

A class is loaded the first time you create an object from the class or access a static field/method. When you run the main method of a class, for example, the class is initialized because the main method is static.

2. An object is created from a class when you use the new keyword. To initialize the class, Java allocates memory for the object and sets up a reference to the object so that the Java runtime can keep track of it. Then Java calls the class constructor, which is like a method but is called only once: when the object is created. The constructor is responsible for doing any processing required to initialize the object — initializing variables, opening files or databases, and so on.

3. The object lives its life, providing access to its public methods and fields to whoever wants and needs them.

4. When it’s time for the object to die, the object is removed from memory, and Java drops its internal reference to it. You don’t have to destroy objects yourself. A special part of the Java runtime called the garbage collector takes care of destroying all objects when they are no longer in use.
Object Memory / Garbage Collection

Objects are dynamically allocated from a pool of free memory by using the new operator.

Each time an object is created in Java, it goes into an area of memory known as The Heap.
All objects—no matter when, where, or how they’re created – live in the heap.
But it’s not just any old memory heap; the Java heap is actually called the Garbage-Collectible Heap.

When you create an object, Java allocates memory space on the heap according to how much that particular object needs.

Memory is not infinite, and the free memory can be exhausted. Thus, it is possible for new to fail because there is insufficient free memory to create the desired object. For this reason, a key component of any dynamic allocation scheme is the recovery of free memory from unused objects, making that memory available for subsequent reallocation.

What happens when you need to reclaim that space? How do you get an object out of the heap when you’re done with it?

In some programming languages, the release of previously allocated memory is handled manually. However, Java uses a different, more trouble-free approach: garbage collection

Java manages that memory for you!

Java’s garbage collection system reclaims objects automatically— occurring transparently, behind the scenes, without any programmer intervention. It works like this: When no references to an object exist, that object is assumed to be no longer needed, and the memory occupied by the object is released. This recycled memory can then be used for a subsequent allocation.

An object is marked for garbage collection once it no longer has active references
When the JVM can ‘see’ that an object can never be used again, that object becomes eligible for garbage collection. And if you’re running low on memory, the Garbage Collector will run, throw out the unreachable objects, and free up the space, so that the space can be reused.

Garbage collection occurs only sporadically during the execution of your program. It will not occur simply because one or more objects exist that are no longer used. For efficiency, the garbage collector will usually run only when two conditions are met: there are objects to recycle, and there is a reason to recycle them. Remember, garbage collection takes time, so the Java run-time system does it only when it is appropriate. Thus, you can’t know precisely when garbage collection will take place.
