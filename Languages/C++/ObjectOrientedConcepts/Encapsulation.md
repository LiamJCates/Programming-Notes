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




























Encapsulation
To encapsulate functionality combine the methods and member variables into a single entity, hiding some of them and making some accessible.
The accessible ones together make up the interface of the object. And finally
(this is important!), when you create an object, you create one that can perform on its own. In other words, the users of the class tell it what to do (such
as perform a sales transaction) by calling its member functions and supplying parameters, and the object does the work. The calling function doesn’t
care how the object does its thing, just that it can do it.

For example, a cash
register class knows how to perform a sales transaction. As the designer of
the class, don’t force users to first call Sale and then call separate functions
to manually modify the amount of cash in the register and modify the running total. Rather, the Sale function does all the hard work, and users of the
class don’t have to worry about how that work takes place.
And now the fundamental question: Why do you need to know the word
encapsulation? Because it’s a common term that computer scientists like
to throw around. If they use it, however, they are likely to use it as a verb:
“Look at me! I am going to encapsulate this information into an object!”
But the process matters more than the word itself. When you design objects
and classes, you encapsulate your information into individual objects. If you
keep the process in mind, you will be better off. Here are the things you need
to do every time you design a class:
✦ Encapsulate the information. Combine the information into a single
entity that becomes the class. This single entity has member variables
representing its characteristics and member functions representing its
capabilities.
✦ Clearly define the public interface of the class. Provide a set of functions that are public (and, possibly, member variables that are public,
although it’s best to keep them protected or private), and make the rest
of the members either protected or private.
✦ Write the class so that it knows how to do its own work. The class’s
users should need only to call the functions in the public interface, and
these public functions should be simple to use.

✦ Think of your class as a black box. The object has an interface that
provides a means so that others can use it. The class includes details of
how it does its thing; users only care that it does it. In other words, the
users don’t see into the class.
✦ Never change the class interface after you publish the class. Many
application errors occur when a developer changes how methods,
events, or access methods in the class work after publishing the class.
If application developers rely on one behavior and the class developer
introduces a new behavior, all applications that rely on the original
behavior will break. You can always add to a class interface but never
subtract from it or modify it. If you find that you must introduce a new
behavior to Sale(), add the new behavior to a new method, Sale2().

A common saying in object-oriented programming is that you should never
make your member variables public. The idea is that if users of the object
can easily make changes to the object’s member variables, a big mess
could result. (For example, making the cash member variable public in a
CashRegister class is asking for functions that just modify it directly,
screwing up the balance.) By allowing users to call only member functions,
you can put checking code inside to handle bad situations.




All C++ programs are composed of the following two fundamental elements −

    Program statements (code) − This is the part of a program that performs actions and they are called functions.

    Program data − The data is the information of the program which gets affected by the program functions.

Encapsulation is an Object Oriented Programming concept that binds together the data and functions that manipulate the data, and that keeps both safe from outside interference and misuse. Data encapsulation led to the important OOP concept of data hiding.

Data encapsulation is a mechanism of bundling the data, and the functions that use them and data abstraction is a mechanism of exposing only the interfaces and hiding the implementation details from the user.

C++ supports the properties of encapsulation and data hiding through the creation of user-defined types, called classes. We already have studied that a class can contain private, protected and public members. By default, all items defined in a class are private. For example −

class Box {
   public:
      double getVolume(void) {
         return length * breadth * height;
      }

   private:
      double length;      // Length of a box
      double breadth;     // Breadth of a box
      double height;      // Height of a box
};

The variables length, breadth, and height are private. This means that they can be accessed only by other members of the Box class, and not by any other part of your program. This is one way encapsulation is achieved.

To make parts of a class public (i.e., accessible to other parts of your program), you must declare them after the public keyword. All variables or functions defined after the public specifier are accessible by all other functions in your program.

Making one class a friend of another exposes the implementation details and reduces encapsulation. The ideal is to keep as many of the details of each class hidden from all other classes as possible.
Data Encapsulation Example

Any C++ program where you implement a class with public and private members is an example of data encapsulation and data abstraction. Consider the following example −
Live Demo

#include <iostream>
using namespace std;

class Adder {
   public:
      // constructor
      Adder(int i = 0) {
         total = i;
      }

      // interface to outside world
      void addNum(int number) {
         total += number;
      }

      // interface to outside world
      int getTotal() {
         return total;
      };

   private:
      // hidden data from outside world
      int total;
};

int main() {
   Adder a;

   a.addNum(10);
   a.addNum(20);
   a.addNum(30);

   cout << "Total " << a.getTotal() <<endl;
   return 0;
}

When the above code is compiled and executed, it produces the following result −

Total 60

Above class adds numbers together, and returns the sum. The public members addNum and getTotal are the interfaces to the outside world and a user needs to know them to use the class. The private member total is something that is hidden from the outside world, but is needed for the class to operate properly.
Designing Strategy

Most of us have learnt to make class members private by default unless we really need to expose them. That's just good encapsulation.

This is applied most frequently to data members, but it applies equally to all members, including virtual functions.
