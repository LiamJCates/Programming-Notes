//Say we have the class

class MyObject
{
  //MyObject has a member variable
public:
	int aNumber;
};


int main()
{
  //And we make an instance of the MyObject class
  MyObject obj1();

  //When we have a object of a given class,
  //and we want to access a member of that class we use the dot operator
  cout << MyObject.aNumber << endl;

  //Say we have a pointer of the class type
  MyObject* objPointer;

  //And we set the pointer equal to the address of the previously created object
  objPointer = &obj1;

  //In this case, to access the member we use the arrow operator
  cout << objPointer->aNumber << endl;


  //This is the same as if we had done
  cout << (*objPointer).aNumber << endl;

  //dereferenced the pointer first, then used the dot operator to access the member from the now dereferenced object value

  //This is not the same as
  cout << *objPointer.aNumber << endl;

  //This would try to dereference the aNumber value as the dot operator, "."
  // has a higher precedence than the dereference operator, "*"
  // becuae of the difference in precedence, we have to surround the (* ) dereference with paranthesis
  // in this way, the dereference happens before the member access done by the dot operator "."
   
}


/*
More formally the arrow operator, "->", is called the member-of-pointer operator


The member-of-pointer operator, or arrow operator (->), performs two simultaneous operations:
•	 It dereferences a pointer.
•	 It accesses a member of the pointed-to object.

You can use this operator to reduce notational friction, the resistance a programmer feels in expressing their intent in code, when you’re handling pointers to classes.

You’ll need to handle pointers to classes in a variety of design patterns. For example, you might want to pass a pointer to a class as a function parameter. If the receiving function needs to interact with a member of that class, the member-of-pointer operator is the tool for the job.


*/
