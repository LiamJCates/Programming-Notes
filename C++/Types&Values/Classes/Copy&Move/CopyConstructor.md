Copy Constructor
copy construction creates a copy and assigns it to a brand-new object.

If a copy constructor is not defined in a class, the compiler itself defines one. If the class has pointer variables and has some dynamic memory allocations, then it is a must to have a copy constructor.

If you were to program a class that needs to contain string data and you used std::string instead of char* you might not even need a copy constructor given the absence of raw pointers. This is because the default copy constructor inserted by the compiler would ensure the invocation of all available copy constructors of member objects such as std::string.



## Invoking Copy Constructor
You use the copy constructor just like other constructors, using the uniform initialization syntax of braced initializers:
MyObject a;
MyObject a_copy{ a };

The second line invokes the copy constructor of MyObject with a to
yield a_copy.




## Copy Constructor Declaration

class MyObject {
  --snip--
  MyObject(const MyObject& other);
};

NOTE
Notice that other is const. You’re copying from some original MyObject, and you have no reason to modify it.

Using const in the copy constructor declaration ensures that the copy constructor does not modify the source object being referred to. Additionally, the parameter in the copy constructor is passed by reference as a necessity. If this weren’t a reference, the copy constructor would itself invoke a copy, thus invoking itself again and so on till the system runs out of memory


## Implementing the Copy Constructor
Let’s implement the copy constructor of MyObject. You want what is known as a deep copy where you copy the data pointed to by the original. Rather than copying the pointer buffer, you’ll make a new allocation on the free store and then copy all the data pointed to by the original buffer.

You shouldn’t pass by value to avoid modification. Use a const reference.

The copy constructor is a constructor which creates an object by initializing it with an object of the same class, which has been created previously. The copy constructor is used to:
  Initialize one object from another of the same type.
  Copy an object to pass it as an argument to a function.
  Copy an object to return it from a function.

 The most common form of copy constructor is shown here:

MyObject::MyObject (const MyObject &obj)
{
   // body of constructor
}

Here, obj is a reference to an object that is being used to initialize another object.

The copy constructor is an overloaded constructor that you supply. It is invoked by the compiler every time an object of the class is copied.
