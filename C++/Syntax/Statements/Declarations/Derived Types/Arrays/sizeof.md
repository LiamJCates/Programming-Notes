## sizeof an array

Use the sizeof operator to obtain the total size in bytes of an array.

In general, the amount of memory reserved by the compiler for an array:
Bytes consumed by an array = sizeof(element-type) * Number of Elements

You can use a simple trick to determine the number of elements in an array: divide the size of the array by the size of a single constituent element:

  short array[] = { 104, 105, 32, 98, 105, 108, 108, 0 };
  size_t n_elements = sizeof(array) / sizeof(short);

On most systems, sizeof(array) will evaluate to 16 bytes and sizeof(short) will evaluate to 2 bytes. Regardless of the size of a short, n_elements will always initialize to 8 because the factor will cancel. This evaluation happens at compile time, so there is no runtime cost in evaluating the length of an array in this way.

The sizeof(x)/sizeof(y) construction is a bit of a hack, but it’s widely used in older code.
