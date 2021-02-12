As an example, let Shape be a base class with a member function draw() and let Square and Circle be derived concrete classes. We cannot provide implementation of function draw() in Shape as the intended behavior would be ambiguous. Square and Circle, however, should each provide an implementation of draw() specific to the objects of their class.


class Shape
{
  public:
    virtual void draw(Point) = 0;
    ...
}

class Square
{
  private:
    int sideLength;
  public:
    void draw(Point center){
      //statements that draw a square with
      //sides of sideLength
      //centered at Point center
    }
}

class Circle
{
  private:
    int radiusLength;
  public:
    void draw(Point center){
      //statements that draw a circle with
      //radius of radiusLength
      //centered at Point center
    }
}
