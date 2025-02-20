#include <iostream>
/*
Enums

Enums restrict a variable to have one of the few predefined values.
*/

enum class BulbSize
{
  SMALL,
  MEDIUM,
  LARGE
};

class Bulb
{
private:
  // Instance Variables
  BulbSize size;
public:
  // Instance Method
  BulbSize getBulbSize()
  {
    return size;
  }
  //Instance Method
  void setBulbSize(BulbSize s)
  {
    size = s;
  }
  //Other bulb class fields and methods...
};

int main()
{
  Bulb b;
  b.setBulbSize(BulbSize::MEDIUM);

  std::cout << "Bulb Size :" << (int)b.getBulbSize() << std::endl;
}

/*
Analysis:
We added a field to the Bulb class, size, and size is of type enum BulbSize. 
The allowed values of the size are SMALL, MEDIUM and LARGE.
*/