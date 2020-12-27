Methods
Methods are a classes' member functions.

Methods create an explicit connection among a class, its data members, and some code. Defining a method is as simple as adding a function to a class definition. Methods have access to all of a class’s members.



Accessor function: A member function of a class that only accesses (that is, does not modify) the value(s) of the member variable(s).

Mutator function: A member function of a class that modifies the value(s) of the member variable(s).



## Inline
C++ inline function is a powerful concept that is commonly used with classes. If a function is inline, the compiler places a copy of the code of that function at each point where the function is called at compile time.

A function definition in a class definition is an inline function definition by default.

## Const
The const specifiers on the functions indicate that a function does not modify the object for which it is called. A const member function can be invoked for both const and non-const objects, but a non-const member function can only be invoked for non-const objects.


### constexpr
It is possible to define a constructor as a constant expression
too, using keyword constexpr. In special cases where such a
construct would be useful from a performance point of view, you
would use it at the constructor declaration.
class Sample {
  const char* someString;
public:
  constexpr Sample(const char* input) :someString(input)
  { // constructor code }
};


constexpr with Classes and Objects
constexpr offers a powerful way to improve the performance of your C++ application.

By marking functions that operate on constants or const-expressions as constexpr, we are instructing the compiler to evaluate those functions and insert their result instead of inserting instructions
that compute the result when the application is executed.

This keyword can also be used with classes and objects that evaluate as constants.

Note
that the compiler would ignore constexpr when the function or class is used with entities that are not constant.

#include <iostream>
 using namespace std;

 class Human
 {
 int age;
 public:
 constexpr Human(int humansAge) : age(humansAge) {}
 constexpr int GetAge() const { return age; }
 };

 int main()
 {
 constexpr Human somePerson(15);
 const int hisAge = somePerson.GetAge();

 Human anotherPerson(45); // not constant expression

 return 0;
 }
