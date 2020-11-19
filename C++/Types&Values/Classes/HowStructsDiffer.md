How struct Differs from class
struct is a keyword from the days of C, and for all practical purposes it is treated by a C++ compiler similarly to a class.

As with a class, members of a struct include instance variables as well as functions, including constructors and a destructor. 

The exceptions are applicable to the access specifiers
(public and private) when the programmer has not specified any. Unless specified, members in a struct are public by default (private for a class), and unless specified, a struct features public inheritance from a base struct (private for a class).

A struct variant of class Human from Listing 9.13 would be the following:
struct Human
{
// constructor, public by default (as no access specified is mentioned)
Human(const MyString& humansName, int humansAge, bool humansGender)
: name(humansName), age (humansAge), Gender(humansGender) {}int GetAge ()
{
return age;
}
private:
int age;
bool gender;
MyString name;
};
As you can see, a struct Human is similar to class Human, and instantiation of an
object of type struct would be similar to type class as well:
Human firstMan("Adam", 25, true); // an instance of struct Human
