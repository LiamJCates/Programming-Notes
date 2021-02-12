Modes of Inheritance in C++


### Single Inheritance:

In single inheritance, a class is allowed to inherit from only one class. i.e. one derived class is inherited by one base class only.

  #include <iostream>
  using namespace std;

  // base class
  class Vehicle {
    public:
      Vehicle() { cout << "This is a Vehicle" << endl; }
  };

  // class derived from base class
  class Car: public Vehicle{
    public:
      Car() { cout << "This is a Car" << endl; }
  };

  // main function
  int main()
  {    
      // instantiation of derived class invokes the base class constructor
      Car obj;
  }

Output:

  This is a Vehicle
  This is a Car



### Multiple Inheritance

Multiple Inheritance is a feature of C++ where a class can inherit from more than one class. i.e one derived class inherits from more than one base class.

A C++ class derived from more than one classes means it inherits data and functions from multiple base classes.

C++ multiple inheritance class uses derivation list syntax:

  class derived-class: access-specifier baseA, access-specifier baseB, ...

where the name of the derived class, derived-class, is followed by a colon, :, and a comma separated derivation list which consists of base class relationships.

Each base class relationship is specified by an optional access-specifier and the name of a previously defined class, base-class.

  #include <iostream>
  using namespace std;

  class Vehicle {
  public:
    Vehicle() { cout << "This is a Vehicle" << endl; }
  };

  class FourWheeler {
  public:
    FourWheeler() { cout << "This is a 4 wheeler Vehicle" << endl; }
  };


  class Car: public Vehicle, public FourWheeler {   
  };

  int main()
  {    
    // instantiation of derived class invokes the base class constructor
    Car obj;
    return 0;
  }

Output:

  This is a Vehicle
  This is a 4 wheeler Vehicle



### Multilevel Inheritance

In this type of inheritance, a derived class is created from another derived class.

  #include <iostream>
  using namespace std;

  // base class
  class Vehicle  
  {
  public:
    Vehicle() { cout << "This is a Vehicle" << endl; }
  };

  // A class derived from one base class
  class fourWheeler: public Vehicle
  {  
    public:
      fourWheeler() { cout << "Objects with 4 wheels are vehicles" << endl; }
  };

  // A class derived from two base classes at two levels
  class Car: public fourWheeler{
   public:
     car()
     {
       cout<<"Car has 4 Wheels"<<endl;
     }
  };

  // main function
  int main()
  {    
    // instantiation of derived class invokes the base class constructor
    Car obj;
    return 0;
  }

Output:

  This is a Vehicle
  Objects with 4 wheels are vehicles
  Car has 4 Wheels



### Hierarchical Inheritance

In this type of inheritance, more than one derived class is inherited from a single base class. i.e. more than one derived class is created from a single base class.

  #include <iostream>
  using namespace std;

  // base class
  class Vehicle  
  {
  public:
    Vehicle() { cout << "This is a Vehicle" << endl; }
  };


  // first derived class  
  class Car: public Vehicle
  {

  };

  // second derived class
  class Bus: public Vehicle
  {

  };

  // main function
  int main()
  {    
    // instantiation of derived class invokes the base class constructor
    Car obj1;
    Bus obj2;
    return 0;
  }

Output:

This is a Vehicle
This is a Vehicle




### Hybrid Inheritance

Hybrid Inheritance is implemented by combining more than one type of inheritance. For example: Combining Hierarchical inheritance and Multiple Inheritance.

  #include <iostream>
  using namespace std;

  // base class  
  class Vehicle  
  {
    public:
      Vehicle() { cout << "This is a Vehicle" << endl; }
  };

  //base class
  class Fare
  {
    public:
      Fare() { cout<< "Fare of Vehicle\n"; }
  };

  // first derived class  
  class Car: public Vehicle
  {
  };

  // second derived class
  class Bus: public Vehicle, public Fare
  {
  };

  // main function
  int main()
  {    
    // instantiation of derived class invokes the base class constructor
    Bus obj2;
    return 0;
  }

Output:

This is a Vehicle
Fare of Vehicle


For
