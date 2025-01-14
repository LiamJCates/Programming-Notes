One design goal is to treat classes as "black boxes," whose external interface is public but whose internal details are hidden from view. Hiding internal information permits implementation of a class to be changed without requiring any clients of the class to modify code.

The vital key here is the interface. An interface is what we use to communicate with an object.

The remote control object is a black box as we can't see the internals of the remote, and there is no need for us to either. The only thing we need to understand to be able to use the object is the interface. If the remote is not working correctly, we can take it to someone who understands the inner workings of it, and they can repair it. If they don't change the interface, the buttons, and what functionality that is associated with them, we won't need to change the way we use the remote before and after the modification.



An object is like a black box whose behavior is very well defined, and we use the object because we know what it does, not because we have an insight into how it does it.

This opacity of objects is extremely useful for maintaining them independently of each other. If communication channels between the objects are well defined, then changes made inside an object can affect other objects only as much as these changes affect the communication channels. Knowing the kind of information sent out and received by an object, the object can be replaced more easily by another object more suitable in a particular situation; a new object can perform the same task differently but more quickly in a certain hardware environment.
