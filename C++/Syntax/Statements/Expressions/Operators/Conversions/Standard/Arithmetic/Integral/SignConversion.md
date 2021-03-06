A signed integral type and its unsigned counterpart are always the same size, but they differ in how the bit pattern is interpreted for value transformation. The following code example demonstrates what happens when the same bit pattern is interpreted as a signed value and as an unsigned value. The bit pattern stored in both num and num2 never changes from what is shown in the earlier illustration.


	#include <limits>
	using namespace std;
	unsigned short num = numeric_limits<unsigned short>::max(); //
	short num2 = num;
	cout << "unsigned val = " << num << " signed val = " << num2 << endl;
	// Prints: unsigned val = 65535 signed val = -1

	// Go the other way.
	num2 = -1;
	num = num2;
	cout << "unsigned val = " << num << " signed val = " << num2 << endl;
	// Prints: unsigned val = 65535 signed val = -1

Notice that values are reinterpreted in both directions. If your program produces odd results in which the sign of the value seems inverted from what you expect, look for implicit conversions between signed and unsigned integral types. In the following example, the result of the expression ( 0 - 1) is implicitly converted from int to unsigned int when it's stored in num. This causes the bit pattern to be reinterpreted.
C++

unsigned int u3 = 0 - 1;
cout << u3 << endl; // prints 4294967295

The compiler does not warn about implicit conversions between signed and unsigned integral types. Therefore, it is recommended to avoid signed-to-unsigned conversions altogether. If you can't avoid them, then add to your code a runtime check to detect whether the value being converted is greater than or equal to zero and less than or equal to the maximum value of the signed type. Values in this range will transfer from signed to unsigned or from unsigned to signed without being reinterpreted.
