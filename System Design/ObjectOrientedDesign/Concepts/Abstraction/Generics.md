A powerful feature of most object oriented languages is the possibility of declaring generic classes by using type parameters in the class declaration.

For example, if we need to declare a class that uses an array for storing some items, then we may declare this class as

class intClass {
  int storage[50];
  ..................
};

However, in this way, we limit the usability of this class to integers only; if we need a class that performs the same operations as intClass except that it operates on float numbers, then a new declaration is needed, such as

class floatClass {
  float storage[50];
  ..................
};

If storage is to hold structures, or pointers to characters, then two more classes must be declared. This is inefficient in code and the time spent to produce it.

It is much better to declare a generic class and decide what type of items the object is referring to only when defining the object.

Fortunately OOL's allow us to declare a class in this way, and the declaration for the example is


class genClass <genType> {
  genType storage[50];
  ...................
};

Later, we make the decision about how to initialize genType:
genClass<int> intObject;
genClass<float> floatObject;

This generic class becomes a basis for generating two new classes, genClass
of int and genClass of float, and then these two classes are used to create two objects, intObject and floatObject.

In this way, the generic class manifests itself in different forms depending on the specific declaration. One generic declaration suffices for enabling such different forms.


This method of using generic types is not limited to classes only; we can use them in function declarations as well. For example, the standard operation for swapping two values can be defined by the function

template<class genType>
  void swap(genType& el1, genType& el2) {
  genType tmp = el1; el1 = el2; el2 = tmp;
}

This example also indicates the need for adapting built-in operators to specific situations. If genType is a number, a character, or a structure, then the assignment operator, =, performs its function properly. But if genType is an array, then we can expect a problem in swap(). The problem can be resolved by overloading the assignment operator by adding to it the functionality required by a specific data type.
After a generic function has been declared, a proper function can be generated at
compilation time. For example, if the compiler sees two calls,
	 swap(n,m); // swap two integers;
	 swap(x,y); // swap two floats;
it generates two swap functions to be used during execution of the program
