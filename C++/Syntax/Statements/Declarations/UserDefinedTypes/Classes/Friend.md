Friend Function
Friend declarations are not class members but must appear in member lists.

A friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class. Even though the prototypes for friend functions appear in the class definition, friends are not member functions.

A friend can be a function, function template, or member function, or a class or class template, in which case the entire class and all of its members are friends.

To declare a function as a friend of a class, precede the function prototype in the class definition with keyword friend as follows −

class Box {
   double width;

   public:
      double length;
      friend void printWidth( Box box );
      void setWidth( double wid );
};

To declare all member functions of class ClassTwo as friends of class ClassOne, place a following declaration in the definition of class ClassOne −

friend class ClassTwo;

Consider the following program −
Live Demo

#include <iostream>

using namespace std;

class Box {
   double width;

   public:
      friend void printWidth( Box box );
      void setWidth( double wid );
};

// Member function definition
void Box::setWidth( double wid ) {
   width = wid;
}

// Note: printWidth() is not a member function of any class.
void printWidth( Box box ) {
   /* Because printWidth() is a friend of Box, it can
   directly access any member of this class */
   cout << "Width of box : " << box.width <<endl;
}

// Main function for the program
int main() {
   Box box;

   // set box width without member function
   box.setWidth(10.0);

   // Use friend function to print the wdith.
   printWidth( box );

   return 0;
}

Declaring a friend of a class
A class does not permit external access to its data members and methods that are
declared private. This rule is waived for classes and functions that are disclosed as
friend classes or functions, using keyword friend

#include <iostream>
 #include <string>
 using namespace std;

 class Human
 {
 private:
 friend class Utility;
 friend void DisplayAge(const Human& person);
 string name;
 int age;

 public:
 Human(string humansName, int humansAge)
 {
 name = humansName;
 age = humansAge;
 }
 };

 class Utility {
  public:
  static void DisplayAge(const Human& person)
  {
  cout << person.age << endl;
  }
  };

 void DisplayAge(const Human& person)
 {
 cout << person.age << endl;
 }23
 int main()
 {
 Human firstMan("Adam", 25);
 cout << "Accessing private member age via friend function ";
 DisplayAge(firstMan);

 return 0;
 }
