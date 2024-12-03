const_cast

To cast away const and/or volatile.

https://en.cppreference.com/w/cpp/language/const_cast

This type of casting manipulates the constness of the object pointed by a pointer, either to be set or to be removed. For example, in order to pass a const pointer to a function that expects a non-const argument:

	// const_cast
	#include <iostream>
	using namespace std;

	void print (char * str)
	{
	  cout << str << '\n';
	}

	int main () {
	  const char * c = "sample text";
	  print ( const_cast<char *> (c) );
	  return 0;
	}

Output:

  sample text

The example above is guaranteed to work because function print does not write to the pointed object. Note though, that removing the constness of a pointed object to actually write to it causes undefined behavior.









const_cast, for casting away the const-ness of a variable, or converting a non-const variable to be const. Casting away const-ness by using this operator is just as error-prone as is using a C-style cast, except that with const_cast you are less likely to perform the cast accidentally. Sometimes you have to cast away the const-ness of a variable, for example, to pass a const variable to a function that takes a non-const parameter. The following example shows how to do this.
C++

void Func(double& d) { ... }
void ConstCast()
{
   const double pi = 3.14;
   Func(const_cast<double&>(pi)); //No error.
}
















const_cast
The const_cast function shucks away the const modifier, allowing the modification of const values. The object-to-cast is of some const type, and the
desired-type is that type minus the const qualifier.


void carbon_thaw(const int& encased_solo)
{
  //encased_solo++;     // Compiler error; modifying const
  auto& hibernation_sick_solo = const_cast<int&>(encased_solo);
  hibernation_sick_solo++;
}

The encased_solo parameter is const, so any attempt to modify it would result in a compiler error.

You use const_cast to obtain the non-const reference hibernation_sick_solo. The const_cast takes a single template parameter, the type you want to cast into. It also takes a function parameter, the object you want to remove const from.

You’re then free to modify the int pointed to by encased_solo via the new, non-const reference.

Only use const_cast to obtain write access to const objects. Any other
type conversion will result in a compiler error.

N O T E
Trivially, you can use const_cast to add const to an object’s type, but you shouldn’t because it’s verbose and unnecessary. Use an implicit cast instead. You can also use const_cast to remove the volatile modifier from an object.










const_cast
If you want to convert from a const to a nonconst or from a volatile
to a nonvolatile, you use const_cast. This is the only conversion
allowed with const_cast; if any other conversion is involved it must
be done using a separate expression or you’ll get a compile-time
error.
//: C03:const_cast.cpp
int main() {
const int i = 0;
int* j = (int*)&i; // Deprecated form
j = const_cast<int*>(&i); // Preferred
// Can't do simultaneous additional casting:
//! long* l = const_cast<long*>(&i); // Error
volatile int k = 0;
int* u = const_cast<int*>(&k);
} ///:~
If you take the address of a const object, you produce a pointer to a
const, and this cannot be assigned to a nonconst pointer without a
cast. The old-style cast will accomplish this, but the const_castis
the appropriate one to use. The same holds true for volatile.











Removes the const, volatile, and __unaligned attribute(s) from a class.
Syntax

const_cast <type-id> (expression)

Remarks

A pointer to any object type or a pointer to a data member can be explicitly converted to a type that is identical except for the const, volatile, and __unaligned qualifiers. For pointers and references, the result will refer to the original object. For pointers to data members, the result will refer to the same member as the original (uncast) pointer to data member. Depending on the type of the referenced object, a write operation through the resulting pointer, reference, or pointer to data member might produce undefined behavior.

You cannot use the const_cast operator to directly override a constant variable's constant status.

The const_cast operator converts a null pointer value to the null pointer value of the destination type.
Example
C++

// expre_const_cast_Operator.cpp
// compile with: /EHsc
#include <iostream>

using namespace std;
class CCTest {
public:
   void setNumber( int );
   void printNumber() const;
private:
   int number;
};

void CCTest::setNumber( int num ) { number = num; }

void CCTest::printNumber() const {
   cout << "\nBefore: " << number;
   const_cast< CCTest * >( this )->number--;
   cout << "\nAfter: " << number;
}

int main() {
   CCTest X;
   X.setNumber( 8 );
   X.printNumber();
}

On the line containing the const_cast, the data type of the this pointer is const CCTest *. The const_cast operator changes the data type of the this pointer to CCTest *, allowing the member number to be modified. The cast lasts only for the remainder of the statement in which it appears.
