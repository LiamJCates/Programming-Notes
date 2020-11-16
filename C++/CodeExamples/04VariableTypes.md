Kinds of Variables

The C++ programming language defines three kinds of variables:

1. Instance Variables (Non-Static): They are instance variables so they are unique to each instance/object of a class.

2. Class Variables (Static): A class variable is any field with
the static modifier. These variables are linked with the class not with the objects of the class. There is exactly one copy of these variables regardless of how many instances of the class are created.

3. Local Variables: the temporary variables in a method are called local variables. The local variables are only visible to the method in which they are declared. The parameters that are passed to the methods are also local variables of the called method.

class Bulb
{
  private:
  // Class Variables
  static int TotalBulbCount;
  // Instance Variables
  bool isOn;

  public:
  // Constructor
  Bulb();
  // Class Method
  static int getBulbCount();
  // Instance Method
  virtual void turnOn();
  // Instance Method
  virtual void turnOff();
  // Instance Method
  virtual bool isOnFun();
};

Bulb::Bulb()
{
  isOn = false;
  TotalBulbCount++;
}

int Bulb::getBulbCount()
{
  return TotalBulbCount;
}

void Bulb::turnOn()
{
  isOn = true;
}

void Bulb::turnOff()
{
  isOn = false;
}

bool Bulb::isOn()
{
  return isOn;
}

Analysis: isOn is an instance variable that is separate for each object.

Each bulb has its state of on or off. However, the total number of bulb is property of the whole class, which is the total number of objects of type bulb created. The TotalBulbCount is a class variable and getBulbCount is class method.
