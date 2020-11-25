Encapsulation is an Object Oriented Programming concept that binds together the data and functions that manipulate the data.

C++ supports the properties of encapsulation through the creation of user-defined types, called classes.

In general, encapsulation is a process of wrapping similar code in one place.

In C++, we can bundle data members and functions that operate together inside a single class. For example,

class Rectangle {
  public:
    int length;
    int breadth;

    int getArea() {
      return length * breadth;
    }
};

In the above program, the function getArea() calculates the area of a rectangle. To calculate the area, it needs length and breadth.

Hence, the data members (length and breadth) and the function getArea() are kept together in the Rectangle class.

// Program to calculate the area of a rectangle
#include <iostream>
using namespace std;

class Rectangle {
  public:
    // Variables required for area calculation
    int length;
    int breadth;

    // Constructor to initialize variables
    Rectangle(int len, int brth) : length(len), breadth(brth) {}

    // Function to calculate area
    int getArea() {
      return length * breadth;
    }
};

int main() {
  // Create object of Rectangle class
  Rectangle rect(8, 6);

  // Call getArea() function
  cout << "Area = " << rect.getArea();

  return 0;
}

Output

Area = 48

In the above example, we are calculating the area of a rectangle.

To calculate an area, we need two variables: length and breadth and a function: getArea(). Hence, we bundled these variables and function inside a single class named Rectangle.



Here, the variables and functions can be accessed from other classes as well. This is encapsulation, we are keeping similar codes together.

Note: People often consider encapsulation as data hiding, but that's not entirely true.

Encapsulation refers to the bundling of related fields and methods together. This can be used to achieve data hiding. Encapsulation in itself is not data hiding.

[See DataHiding.md]


Why Encapsulation?

In C++, encapsulation helps us keep related data and functions together, which makes our code cleaner and easy to read.

Consider a situation where we want the length field in a class to be non-negative. Here we can make the length variable private and apply the logic inside the method setLength(). For example

class Rectangle {
  public:
    int length;

    void setLength(int len) {
      if (len >= 0)
        length = len;
    }
};
