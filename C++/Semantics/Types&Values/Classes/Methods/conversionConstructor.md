## Using Constructors to Convert Types
Constructors can be overloaded, that is, they may take one or more parameters. This feature is often used to convert one type to another.

Let’s consider a class Human that features an overloaded constructor that accepts an integer.

class Human
{
  int age;
  public:
  Human(int humansAge): age(humansAge) {}
};
// Function that takes a Human as a parameter
void DoSomething(Human person)
{
  cout << "Human sent did something" << endl;
  return;
}

This constructor allows a conversion:
Human kid(10); // convert integer in to a Human
DoSomething(kid);

Such converting constructors allow implicit conversions:

Human anotherKid = 11; // int converted to Human
DoSomething(10); // 10 converted to Human!

We declared DoSomething(Human person) as a function that accepts a parameter of type Human and does not accept an int! So, why did that line work? The compiler knows that class Human supports a constructor that accepts an integer and performed an implicit conversion for you—it created an object of type Human using the integer you supplied and sent it as an argument to the function.

To avoid implicit conversions, use keyword explicit at the time of declaring the constructor:

class Human
{
  int age;
  public:
  explicit Human(int humansAge): age(humansAge) {}
};

Using explicit is not a prerequisite but in many cases a good programming practice. The following sample in Listing 9.12 demonstrates a version of class Human that does not permit implicit conversions.

Use Keyword explicit to Block Unintentional Implicit Conversions
 #include<iostream>
 using namespace std;

 class Human
 {
 int age;
 public:
 // explicit constructor blocks implicit conversions explicit Human(int humansAge) : age(humansAge) {}
 };

 void DoSomething(Human person)
 {
 cout << "Human sent did something" << endl;
 return;
 }

 int main()
 {
 Human kid(10); // explicit conversion is OK
 Human anotherKid = Human(11); // explicit, OK
 DoSomething(kid); // OK

 // Human anotherKid2 = 11; // failure: implicit conversion not OK
 // DoSomething(10); // implicit conversion

 return 0;
 }
