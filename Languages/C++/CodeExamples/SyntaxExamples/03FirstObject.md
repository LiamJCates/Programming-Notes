An Object is an entity with state and behavior.

For example a bulb have two states (on, off) and the two behaviors (turn on, turn off).

Software objects are just like real world objects. They have state in the form of member variables called fields (isOn) and they expose behavior in the form of member functions called methods (turn on, turn off).

Hiding internal details (state) of the object and allowing all the actions to be performed over the objects using methods is known has data-encapsulation.

A Class is a prototype (blueprint) of objects. An object is an instance of a class.

class Bulb
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
  virtual bool isOn();
};

In this example, we have a class name Bulb.
It has a member variable isOn, which indicates its state that the bulb is on or off.
It has two methods turnOn() and turnoff() which will change the state of the object.
