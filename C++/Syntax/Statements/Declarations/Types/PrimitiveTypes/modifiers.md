Modifiers

Modifies the basic integer type. Can be mixed in any order. Only one of each group can be present in type name.

Signedness

    signed - target type will have signed representation (this is the default if omitted)
    unsigned - target type will have unsigned representation

Size

    short - target type will be optimized for space and will have width of at least 16 bits.
    long - target type will have width of at least 32 bits.

    long long - target type will have width of at least 64 bits.

	(since C++11)

Note: as with all type specifiers, any order is permitted: unsigned long long int and long int unsigned long name the same type.


Specifiers modify the meanings of the basic built-in types and
expand them to a much larger set. There are four specifiers: long, short, signed, and unsigned.

long and short modify the maximum and minimum values that a data type will hold. A plain int must be at least the size of a short. The size hierarchy for integral types is: short int, int, long int. All the sizes could conceivably be the same, as long as they satisfy the minimum/maximum value requirements. On a machine with a 64-bit word, for instance, all the data types might be 64 bits.

The size hierarchy for floating point numbers is: float, double, and long double. “long float” is not a legal type. There are no short floating-point numbers.






Signedness

Except for bool and the extended character types, the integral types may be signed or unsigned.

A signed type represents negative or positive numbers (including zero);
an unsigned type represents only values greater than or equal to zero.

The types int, short, long, and long long are all signed. We obtain the
corresponding unsigned type by adding unsigned to the type, such as unsigned
long. The type unsigned int may be abbreviated as unsigned.

Unlike the other integer types, there are three distinct basic character types:
char, signed char, and unsigned char. In particular, char is not the same
type as signed char. Although there are three character types, there are only
two representations: signed and unsigned. The (plain) char type uses one of these
representations. Which of the other two character representations is equivalent to
char depends on the compiler.
In an unsigned type, all the bits represent the value. For example, an 8-bit
unsigned char can hold the values from 0 through 255 inclusive.
The standard does not define how signed types are represented, but does spec-
ify that the range should be evenly divided between positive and negative values.
Hence, an 8-bit signed char is guaranteed to be able to hold values from –127
through 127; most modern machines use representations that allow values from
–128 through 127.


The signed and unsigned specifiers tell the compiler how to use
the sign bit with integral types and characters (floating-point
numbers always contain a sign). An unsignednumber does not
keep track of the sign and thus has an extra bit available, so it can
store positive numbers twice as large as the positive numbers that
can be stored in a signed number. signed is the default and is only
necessary with char; char may or may not default to signed. By
specifying signed char, you force the sign bit to be used.

  // Demonstrates the use of specifiers
  #include <iostream>
  using namespace std;
  int main()
  {
  	char c;
  	unsigned char cu;
  	int i;
  	unsigned int iu;
  	short int is;
  	short iis; // Same as short int
  	unsigned short int isu;
  	unsigned short iisu;
  	long int il;
  	long iil; // Same as long int
  	unsigned long int ilu;
  	unsigned long iilu;
  	float f;
  	double d;
  	long double ld;
  	cout
  		<< "\n char= " << sizeof(c)
  		<< "\n unsigned char = " << sizeof(cu)
  		<< "\n int = " << sizeof(i)
  		<< "\n unsigned int = " << sizeof(iu)
  		<< "\n short = " << sizeof(is)
  		<< "\n unsigned short = " << sizeof(isu)
  		<< "\n long = " << sizeof(il)
  		<< "\n unsigned long = " << sizeof(ilu)
  		<< "\n float = " << sizeof(f)
  		<< "\n double = " << sizeof(d)
  		<< "\n long double = " << sizeof(ld)
  		<< endl;
  }

Be aware that the results you get by running this program will probably be different from one machine/operating system/compiler to the next, since (as mentioned previously) the only thing that must be consistent is that each different type hold the minimum and maximum values specified in the Standard.
