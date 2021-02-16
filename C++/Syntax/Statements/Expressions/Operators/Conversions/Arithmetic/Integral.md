## Integral conversions

Integral conversions are standard conversions between integral types.

The integral types are char, short (or short int), int, long, and long long. These types may be qualified with signed or unsigned, and unsigned can be used as shorthand for unsigned int.

If the destination type is signed, all is well, as long as the value can be represented. If it cannot, the behavior is implementation defined.

If the destination type is unsigned, the result is as many bits as can fit into the type. In other words, the high-order bits are lost and a narrowing conversion takes place.


#### Signed to unsigned

Objects of signed integral types can be converted to corresponding unsigned types. When these conversions occur, the actual bit pattern doesn't change. However, the interpretation of the data changes. Consider this code:

  #include <iostream>

  using namespace std;
  int main()
  {
      short  i = -3;
      unsigned short u;

      cout << (u = i) << "\n";
  }

Output:

  65533

In the preceding example, a signed short, i, is defined and initialized to a negative number. The expression (u = i) causes i to be converted to an unsigned short before the assignment to u.


#### Unsigned to signed

Objects of unsigned integral types can be converted to corresponding signed types. However, if the unsigned value is outside the representable range of the signed type, the result won't have the correct value, as demonstrated in the following example:
C++

  #include <iostream>
  using namespace std;

  int main()
  {
    short  i;
    unsigned short u = 65533;

    cout << (i = u) << "\n";
  }

Output:

  -3

In the preceding example, u is an unsigned short integral object that must be converted to a signed quantity to evaluate the expression (i = u). Because its value can't be properly represented in a signed short, the data is misinterpreted as shown.
