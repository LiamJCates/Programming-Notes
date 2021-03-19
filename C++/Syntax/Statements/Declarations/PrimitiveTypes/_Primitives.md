Primitive data types are basic types implemented directly by the language that represent the basic storage units supported natively by most systems.

Primitives can generally be classified into:
  Character types: Those that represent a single character, such as 'A' or '$'. The most basic type is char, which is a one-byte character. Other types are also provided for wider characters.

  Numerical integer types: They can store a whole number value, such as 7 or 1024. They exist in a variety of sizes, and can either be signed or unsigned, depending on whether they support negative values or not.

  Floating-point types: They can represent real values, such as 3.14 or 0.01, with different levels of precision, depending on which of the three floating-point types is used.

  Boolean type: The boolean type, known in C++ as bool, can only represent one of two states, true or false.


Here is the complete list of fundamental types in C++:
<table>
 <tr>
   <th>Group</th>
   <th>Type names*</th>
   <th>Notes on size / precision </th>
 </tr>
 <tr>
   <td rowspan="4">Character types</td>
   <td>char</td>
   <td>Exactly one byte in size. At least 8 bits.</td>
 </tr>
 <tr>
   <td>char16_t</td>
   <td>Not smaller than char. At least 16 bits.</td>
 </tr>
 <tr>
   <td>char32_t</td>
   <td>Not smaller than char16_t. At least 32 bits.</td>
 </tr>
 <tr>
   <td>wchar_t</td>
   <td>Can represent the largest supported character set.</td>
 </tr>
 <tr>
  <td rowspan="5">Integer types (signed)</td>
  <td>signed char</td>
  <td>Same size as char. At least 8 bits.</td>
 </tr>
 <tr>
  <td>signed short int</td>
  <td>Not smaller than char. At least 16 bits.</td>
 </tr>
 <tr>
  <td>signed int</td>
  <td>Not smaller than short. At least 16 bits.</td>
 </tr>
 <tr>
  <td>signed long int</td>
  <td>Not smaller than int. At least 32 bits.</td>
 </tr>
 <tr>
  <td>signed long long int</td>
  <td>Not smaller than long. At least 64 bits.</td>
 </tr>
 <tr>
  <td rowspan="5">Integer Types (unsigned)</td>
  <td>unsigned char</td>
  <tdrowspan="5">(same size as their signed counterparts)</td>
 </tr>
 <tr>
  <td>unsigned short int</td>
 </tr>
 <tr>
  <td>unsigned int</td>
 </tr>
 <tr>
  <td>unsigned long int</td>
 </tr>
 <tr>
  <td>unsigned long long int</td>
 </tr>
 <tr>
  <td rowspan="3">Floating-point Types</td>
  <td>float</td>
  <td></td>
 </tr>
 <tr>
  <td>double</td>
  <td>precision not less than float</td>
 </tr>
 <tr>
  <td>long double</td>
  <td>Precision not less than double</td>
 </tr>
 <tr>
  <td>Boolean Type</td>
  <td>bool</td>
  <td></td>
 </tr>
 <tr>
  <td>Void Type</td>
  <td>void</td>
  <td>no storage</td>
 </tr>
 <tr>
  <td>Null pointer</td>
  <td>decltype (nullptr)</td>
  <td></td>
 </tr>
</table>



Specifiers modify the meanings of the basic built-in types and
expand them to a much larger set. There are four specifiers: long,
short, signed, and unsigned.

long and short modify the maximum and minimum values that a data type will hold. A plain int must be at least the size of a short. The size hierarchy for integral types is: short int, int, long int. All the sizes could conceivably be the same, as long as they satisfy the minimum/maximum value requirements. On a machine with a 64-bit word, for instance, all the data types might be 64 bits.

The size hierarchy for floating point numbers is: float, double, and long double. “long float” is not a legal type. There are no short floating-point numbers.

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

The names of certain integer types can be abbreviated
  int can be removed in the case of a short, long, or long long
  signed can be removed as all integer types are signed by default

I.e., signed short int can be abbreviated as signed short, short int, or simply short; they all identify the same fundamental type.

Within each of the groups above, the difference between types is only their size (i.e., how much they occupy in memory): the first type in each group is the smallest, and the last is the largest, with each type being at least as large as the one preceding it in the same group. Other than that, the types in a group have the same properties.

Note in the panel above that other than char (which has a size of exactly one byte), none of the fundamental types has a standard size specified (but a minimum size, at most). Therefore, the type is not required (and in many cases is not) exactly this minimum size. This does not mean that these types are of an undetermined size, but that there is no standard size across all compilers and machines; each compiler implementation may specify the sizes for these types that fit the best the architecture where the program is going to run. This rather generic size specification for types gives the C++ language a lot of flexibility to be adapted to work optimally in all kinds of platforms, both present and future.

Type sizes above are expressed in bits; the more bits a type has, the more distinct values it can represent, but at the same time, also consumes more space in memory:

| Size | Unique representable values | Notes |
|------|-----------------------------|-------|
| 8-bit | 256 | = 2^8 |
| 16-bit | 65 536 | = 2^16 |
| 32-bit | 4 294 967 296 | = 2^32 (~4 billion) |
| 64-bit | 18 446 744 073 709 551 616 | = 2^64 (~18 billion billion) |

For integer types, having more representable values means that the range of values they can represent is greater; for example, a 16-bit unsigned integer would be able to represent 65536 distinct values in the range 0 to 65535, while its signed counterpart would be able to represent, on most cases, values between -32768 and 32767. Note that the range of positive values is approximately halved in signed types compared to unsigned types, due to the fact that one of the 16 bits is used for the sign; this is a relatively modest difference in range, and seldom justifies the use of unsigned types based purely on the range of positive values they can represent.

For floating-point types, the size affects their precision, by having more or less bits for their significant and exponent.

If the size or precision of the type is not a concern, then char, int, and double are typically selected to represent characters, integers, and floating-point values, respectively. The other types in their respective groups are only used in very particular cases.

The properties of fundamental types in a particular system and compiler implementation can be obtained by using the numeric_limits classes (see standard header <limits>). If for some reason, types of specific sizes are needed, the library defines certain fixed-size type aliases in header <cstdint>.

The types described above (characters, integers, floating-point, and boolean) are collectively known as arithmetic types. But two additional fundamental types exist: void, which identifies the lack of type; and the type nullptr, which is a special type of pointer. Both types will be discussed further in a coming chapter about pointers.

C++ supports a wide variety of types based on the fundamental types discussed above; these other types are known as compound data types, and are one of the main strengths of the C++ language.
