### Initializing Arrays

You initialize arrays like PODs. The main difference between array and
POD declarations is that arrays specify length. Recall that this argument
goes in square brackets [].
When you use braced initializers to initialize arrays, the length argument becomes optional; the compiler can infer the size argument from the number of braced initializer arguments.

	int main() {
	  int array_1[]{ 1, 2, 3 }; // Array of length 3; 1, 2, 3
	  int array_2[5]{}; // Array of length 5; 0, 0, 0, 0, 0
	  int array_3[5]{ 1, 2, 3 }; // Array of length 5; 1, 2, 3, 0, 0
	  int array_4[5]; // Array of length 5; uninitialized values
	}

The array array_1 has length three, and its elements equal 1, 2, and 3.
The array array_2 has length five because you specified a length argument. The braced initializer is empty, so all five elements initialize to zero.
The array array_3 also has length five, but the braced initializer is not empty. It contains three elements, so the remaining two elements initialize to zero.
The array array_4 has no braced initializer, so it contains uninitialized objects.
