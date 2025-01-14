Dynamic dispatch/message passing
We say that objects communicate by passing messages to each other.



It is the responsibility of the object, not any external code, to select the procedural code to execute in response to a method call, typically by looking up the method at run time in a table associated with the object. This feature is known as dynamic dispatch, and distinguishes an object from an abstract data type (or module), which has a fixed (static) implementation of the operations for all instances. If the call variability relies on more than the single type of the object on which it is called (i.e. at least one other parameter object is involved in the method choice), one speaks of multiple dispatch.

A method call is also known as message passing. It is conceptualized as a message (the name of the method and its input parameters) being passed to the object for dispatch.

Message passing is equivalent to a function call in traditional languages. However, to stress the fact that in OOLs the member functions are relative to objects, this new term is used.

For example, the call to public memberFunction1() in object1,
	 object1.memberFunction1();
is seen as message memberFunction1() sent to object1.

Upon receiving the message, the object invokes its member function and displays all relevant information.

Messages can include parameters so that
	 object1.memberFunction2(123);
is the message memberFunction2() with parameter 123 received by object1.

The lines containing these messages are either in the main program, in a function, or in a member function of another object. Therefore, the receiver of the message is identifiable, but not necessarily the sender. If object1 receives the message
memberFunction1(), it does not know where the message originated. It only responds to it by displaying the information memberFunction1() encapsulates.

The same goes for memberFunction2(). Therefore, the sender may prefer sending a message that also includes its identification, as follows:
	 object1.memberFunction2(123, "object1");
