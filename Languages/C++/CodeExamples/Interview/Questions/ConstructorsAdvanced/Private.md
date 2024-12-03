A constructor is a special member function of a class which initializes objects of a class. In C++, constructor is automatically called when object of a class is created.

While, by default, constructors are defined in public section of class, constructor can be defined in private section of class.

How to use Constructors in private section?
  instantiation by a friend class
  Singleton design pattern
  named constructor idiom



### Using Friend Class
 If we want that class should not be instantiated by anyone else but only by a friend class.

#include <iostream>
using namespace std;

// class A
class A{
private:
    A(){
       cout << "constructor of A\n";
    }
    friend class B;
};

// class B, friend of class A
class B{
public:
    B(){
        A a1;
        cout << "constructor of B\n";
    }
};

// Driver program
int main(){
    B b1;
    return 0;
}

Output:

constructor of A
constructor of B

If you comment the line friend class B, you will encounter below error:


test1.cpp: In constructor ‘B::B()’:
test1.cpp:9:5: error: ‘A::A()’ is private
     A(){
     ^
test1.cpp:19:11: error: within this context
         A a1;




### Singleton
Using Singleton design pattern: When we want to design a singleton class. This means instead of creating several objects of class, the system is driven by a single object or a very limited number of objects.
Named Constructor Idiom : Since constructor has same name as of class, different constructors are differentiated by their parameter list, but if numbers of constructors is more, then implementation can become error prone.





### Named Constructor Idiom
With the Named Constructor Idiom, you declare all the class’s constructors in the private or protected sections, and then for accessing objects of class, you create public static functions.

For example, consider below CPP program

// Demonstrates ambiguous nature of constructor with
// the same permutation of parameter types

#include <iostream> 
using namespace std;
class Point  
{
    public:

    // Rectangular coordinates
    Point(float x, float y);      

    // Polar coordinates (radius and angle)
    Point(float r, float a);      

    // error: ‘Point::Point(float, float)’ cannot
    // be overloaded
};
int main()
{
    // Ambiguous: Which constructor to be called ?
    Point p = Point(5.7, 1.2);  
    return 0;
}

This problem can be resolved by Named Constructor Idiom. The above CPP program can be improved as following :

// CPP program to demonstrate
// named constructor idiom
#include <iostream>
#include <cmath>
using namespace std;
class Point  
{
    private:
    float x1, y1;
    Point(float x, float y)
    {
        x1 = x;
        y1 = y;
    };
public:
    // polar(radius, angle)
    static Point Polar(float, float);  

    // rectangular(x, y)
    static Point Rectangular(float, float);  
    void display();
};

// utility function for displaying of coordinates
void Point :: display()
{
    cout << "x :: " << this->x1 <<endl;
    cout << "y :: " << this->y1 <<endl;
}

// return polar coordinates
Point Point :: Polar(float x, float y)
{
    return Point(x*cos(y), x*sin(y));
}

// return rectangular coordinates
Point Point :: Rectangular(float x, float y)
{
    return Point(x,y);
}
int main()
{
    // Polar coordinates
    Point pp = Point::Polar(5.7, 1.2);
    cout << "polar coordinates \n";
    pp.display();

    // rectangular coordinates
    Point pr = Point::Rectangular(5.7,1.2);
    cout << "rectangular coordinates \n";
    pr.display();
    return 0;
}

Output :

polar coordinates
x :: 2.06544
y :: 5.31262
rectangular coordinates
x :: 5.7
y :: 1.2
