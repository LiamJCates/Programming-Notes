### Initializing Arrays

You initialize arrays like PODs. The main difference between array and
POD declarations is that arrays specify length. Recall that this argument
goes in square brackets [].

For more information regarding array syntax and usage, see:
[C++\Syntax\Statements\Declarations\Derived Types\Arrays]

When you use braced initializers to initialize arrays, the length argument becomes optional; the compiler can infer the size argument from the number of braced initializer arguments.

```cpp
int array_1[]{ 1, 2, 3 }; 	// Array of length 3; 1, 2, 3
int array_2[5]{}; 					// Array of length 5; 0, 0, 0, 0, 0
int array_3[5]{ 1, 2, 3 }; 	// Array of length 5; 1, 2, 3, 0, 0
int array_4[5]; 						// Array of length 5; uninitialized values
```

The array array_1 has length three, and its elements equal 1, 2, and 3.
The array array_2 has length five because you specified a length argument. The braced initializer is empty, so all five elements initialize to zero.
The array array_3 also has length five, but the braced initializer is not empty. It contains three elements, so the remaining two elements initialize to zero.
The array array_4 has no braced initializer, so it contains uninitialized objects.


### Empty Brace / Partial Initialization

See https://stackoverflow.com/questions/38892455/initializing-an-array-of-zeroes


For arrays of a primitive type the empty braced initialization:

```cpp
int array_a[5]{};
int array_b[5] = {};
```

performs aggregation-initialization of the array: this leads to zero-initialization of the int elements.

During empty brace or partial initialization, the remaining elements may be default initialized depending on the type of the array.

For arrays of a class type, value-initialization is performed.

For more information on types of initialization, see:
[C++\Syntax\Statements\Expressions\Initialization\InitializationTypes.md]
