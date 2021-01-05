this Pointer

An important concept in C++, this is a reserved keyword applicable within the scope of a class and contains the address of the object. In other words, the value of this is &object to the object whose member function is being executed. Within a class member method, when you invoke another member method, the compiler sends this pointer as an implicit, invisible parameter in the function call.

Every object in C++ has access to its own address through an important pointer called this pointer. The this pointer is an implicit parameter to all member functions. Therefore, inside a member function, this may be used to refer to the invoking object.

Friend functions do not have a this pointer, because friends are not members of a class. Only member functions have a this pointer.

Note that the this pointer is not sent to class methods declared
as static as static functions are not connected to an instance
of the class. Instead they are shared by all instances.
To use an instance variable in a static function, you would explicitly declare a parameter and send this pointer as an argument.
