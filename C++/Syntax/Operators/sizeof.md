## sizeof
The unary operator sizeof accepts one parameter, which can be either a type or a variable, and returns the size in bytes of that type or object:

x = sizeof (char);

Here, x is assigned the value 1, because char is a type with a size of one byte.

The sizeof operator always returns a size_t.

The value returned by sizeof is a compile-time constant, so it is always determined before program execution.
