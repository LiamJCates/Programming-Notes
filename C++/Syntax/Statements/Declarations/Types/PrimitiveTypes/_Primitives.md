General Primitive Types
[Programming Methods\Advanced\DataTypes\Primitives.md]


C++ defines a set of primitive types that include the arithmetic types and a special type named void.

The arithmetic types represent characters, integers, boolean values, and floating-point numbers.


The arithmetic types are divided into two categories:
integral types (which include character and boolean types) and floating-point types.



Primitives:



  Integral types: represent whole number values


    Character types: represent single characters

    Boolean type: represent true/false values



  Floating-point types: represent real values,  such as 3.14 or 0.01, with different levels of precision.

  void: The void type has no associated values and can be used in only a few circumstances, most commonly as the return type for functions that do not return a value.



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




Within each of the groups above, the difference between types is only their size (i.e., how much they occupy in memory): the first type in each group is the smallest, and the last is the largest, with each type being at least as large as the one preceding it in the same group. Other than that, the types in a group have the same properties.

Note in the panel above that other than char (which has a size of exactly one byte), none of the fundamental types has a standard size specified (but a minimum size, at most). Therefore, the type is not required (and in many cases is not) exactly this minimum size. This does not mean that these types are of an undetermined size, but that there is no standard size across all compilers and machines; each compiler implementation may specify the sizes for these types that fit the best the architecture where the program is going to run. This rather generic size specification for types gives the C++ language a lot of flexibility to be adapted to work optimally in all kinds of platforms, both present and future.






The properties of fundamental types in a particular system and compiler implementation can be obtained by using the numeric_limits classes (see standard header <limits>).

If for some reason, types of specific sizes are needed, the library defines certain fixed-size type aliases in header <cstdint>.



If the size or precision of the type is not a concern, then char, int, and double are typically selected to represent characters, integers, and floating-point values, respectively. The other types in their respective groups are only used in very particular cases.


A DVICE : D ECIDING W HICH T YPE TO U SE
C++, like C, is designed to let programs get close to the hardware when necessary.
The arithmetic types are defined to cater to the peculiarities of various kinds of hard-
ware. Accordingly, the number of arithmetic types in C++ can be bewildering. Most
programmers can (and should) ignore these complexities by restricting the types they
use. A few rules of thumb can be useful in deciding which type to use:
• Use an unsigned type when you know that the values cannot be negative.
• Use int for integer arithmetic. short is usually too small and, in practice, long
often has the same size as int. If your data values are larger than the minimum
guaranteed size of an int, then use long long.
• Do not use plain char or bool in arithmetic expressions. Use them only to hold
characters or truth values. Computations using char are especially problematic
because char is signed on some machines and unsigned on others. If you
need a tiny integer, explicitly specify either signed char or unsigned char.
• Use double for floating-point computations; float usually does not have
enough precision, and the cost of double-precision calculations versus single-
precision is negligible. In fact, on some machines, double-precision operations
are faster than single. The precision offered by long double usually is unnec-
essary and often entails considerable run-time cost.



C++ supports a wide variety of types based on the fundamental types discussed above; these other types are known as compound data types, and are one of the main strengths of the C++ language.
