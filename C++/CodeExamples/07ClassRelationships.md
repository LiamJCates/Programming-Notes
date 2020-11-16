Relationship

These various relationships exist between two classes:
1. Dependency: Objects of one-class use objects of another class temporarily. When a class creates an instance of another class inside its member method and use it and when the method exits, then the instance of the other class is deleted.

2. Association: Objects of one class work with objects of another class for some amount of time. The association is of two kinds - Aggregation and Composition.

3. Aggregation: One class object share a pointer to objects of another class. When a class stores the pointer of another class inside it. Just a pointer is kept inside the class.

4. Composition: One class contains objects of another class. In Composition, the containing object is responsible for the creation and deletion of the contained object.

5. Inheritance: One class is a sub-type of another class. Inheritance is a straightforward relationship to explain the parent-child relationship.

AdvanceBulb is sub-class of Bulb class. Demonstrating Inheritance.
class AdvanceBulb : public Bulb
{
  private:// Instance Variables
  int intensity;
  public:
  AdvanceBulb();
  // Instance Method
  virtual void setIntersity(int i);
  // Instance Method
  virtual int getIntersity();
};

AdvanceBulb::AdvanceBulb()
{
  intensity = 0;
}

void AdvanceBulb::setIntersity(int i)
{
  intensity = i;
}

int AdvanceBulb::getIntersity()
{
  return intensity;
}

Analysis: In our example, AdvanceBulb is a sub-class of Bulb. When an object of AdvanceBulb is created, all public and protected methods of Bulb class are also accessible to it.
