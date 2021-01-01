## Integral conversions

Integral conversions are conversions between integral types. The integral types are char, short (or short int), int, long, and long long. These types may be qualified with signed or unsigned, and unsigned can be used as shorthand for unsigned int.

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
// Output: 65533

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
//Output: -3

In the preceding example, u is an unsigned short integral object that must be converted to a signed quantity to evaluate the expression (i = u). Because its value can't be properly represented in a signed short, the data is misinterpreted as shown.



## Floating point conversions

An object of a floating type can be safely converted to a more precise floating type — that is, the conversion causes no loss of significance. For example, conversions from float to double or from double to long double are safe, and the value is unchanged.

An object of a floating type can also be converted to a less precise type, if it's in a range representable by that type. (See Floating Limits for the ranges of floating types.) If the original value isn't representable precisely, it can be converted to either the next higher or the next lower representable value. The result is undefined if no such value exists. Consider the following example:
C++

cout << (float)1E300 << endl;

The maximum value representable by type float is 3.402823466E38 — a much smaller number than 1E300. Therefore, the number is converted to infinity, and the result is "inf".



## Conversions between integral and floating point types

Certain expressions can cause objects of floating type to be converted to integral types, or vice versa. When an object of integral type is converted to a floating type, and the original value isn't representable exactly, the result is either the next higher or the next lower representable value.

When an object of floating type is converted to an integral type, the fractional part is truncated, or rounded toward zero. A number like 1.3 is converted to 1, and -1.3 is converted to -1. If the truncated value is higher than the highest representable value, or lower than the lowest representable value, the result is undefined.
