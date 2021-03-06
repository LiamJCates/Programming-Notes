### Bool Conversions
Pointers, integers, and floating-point numbers can all be implicitly converted to bool objects.

If the value is nonzero, the result of implicit conversion is true. Otherwise, the result is false.

Example:
	int{ 1 } 	// true
	int{} 		// false

Pointer to void*
Pointers can always be implicitly converted to void*
