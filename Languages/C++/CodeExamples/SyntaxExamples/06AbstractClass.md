Abstract class

Objects define their interface as the interaction with the outside world. For example, in the bulb case switch is the interface between you and the bulb. You press the button turn on and the bulb start glowing. C++ does not have any interface keyword, it just define some functions as abstract function by making it “= 0” thereby making the whole class abstract.

class BulbInterface
{
  public:
  virtual void turnOn() = 0;
  virtual void turnOff() = 0;
  virtual bool isOnFun() = 0;
};

// implements BulbInterface
class Bulb : public BulbInterface
{
  private:
  // Instance Variables
  bool isOn;
  public:
  // Constructor
  Bulb();
  // Instance Method
  virtual void turnOn();
  // Instance Method
  virtual void turnOff();
  // Instance Method
  virtual bool isOnFun();
};

int main()
{
  Bulb b;
  std::cout << "bulb is on return : " << b.isOnFun() << std::endl;
  b.turnOn();
  std::cout << "bulb is on return : " << b.isOnFun() << std::endl;
  return 0;
}

Analysis:
In this example, BulbInterface is the interface of Bulb class. Bulb class needs to implement all the methods of BulbInterface to make itself a concrete class.
A concrete class is a class whole object or instance can be created.
An abstract method is a method which does not have a definition. Such methods are declared with abstract keyword.
A class which has at least one abstract method need to be declared as abstract.
We cannot create objects of an abstract class. (A class which does not have any abstract method can also be declared as abstract to prevent its object creation.).

//Abstract Class
class Shape
{
  public:
  // Abstract Method
  virtual double area() = 0;
  // Abstract Method
  virtual double perimeter() = 0;
};

Shape is an abstract class. And its instance cannot be created. Those classes, which extend it, need to implement these two functions to become concrete class whose instances can be created.

class Circle : public Shape
{
  private:
  double radius = 0;public:
  Circle();
  Circle(double r);
  virtual void setRadius(double r);
  virtual double area() override;
  virtual double perimeter() override;
};

Circle::Circle() :
Circle(1)
{
}

Circle::Circle(double r)
{
  radius = r;
}

void Circle::setRadius(double r)
{
  radius = r;
}

double Circle::area()
{
  return M_PI * std::pow(radius, 2);
}

double Circle::perimeter()
{
  return 2 * M_PI * radius;
}

Circle is a class which extends shape class and implement area() and perimeter() methods.

class Rectangle : public Shape
{
  private:
  double width = 0, length = 0;
  public:
  Rectangle();
  Rectangle(double w, double l);virtual void setWidth(double w);
  virtual void setLength(double l);
  virtual double area() override;
  virtual double perimeter() override;
};

Rectangle::Rectangle() :
Rectangle(1, 1)
{
}

Rectangle::Rectangle(double w, double l)
{
  width = w;
  length = l;
}

void Rectangle::setWidth(double w)
{
  width = w;
}

void Rectangle::setLength(double l)
{
  length = l;
}

double Rectangle::area()
{
  return width * length; // Area = width * length
}

double Rectangle::perimeter()
{
  return 2 * (width + length); // Perimeter = 2(width + length)
}

Same as Circle class, Rectangle class also extends Shape class and implements its abstract functions.
#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
int main()
{
  double width = 2, length = 3;

  Shape *rectangle = new Rectangle(width, length);
  std::cout << "Rectangle width: " << width << " and length: " << length << " Area: " << rectangle->area() << " Perimeter: " << rectangle->perimeter() << std::endl;double radius = 10;

  Shape *circle = new Circle(radius);
  std::cout << "Circle radius: " << radius << " Area: " << circle>area() << " Perimeter: " << circle->perimeter() << std::endl;
}

Analysis: Shape demo creates an instance of the Rectangle and the Circle class and assign it to a pointer of type Shape.

Finally area() and perimeter() functions are called over instances
