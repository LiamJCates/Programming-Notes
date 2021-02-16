const_cast
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
