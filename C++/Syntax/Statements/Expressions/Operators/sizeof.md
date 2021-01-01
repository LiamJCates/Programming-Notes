| Name | Syntax | Overloadable |
|------|--------|--------------|
| sizeof VariableType | sizeof(a) | Yes |
| sizeof Type | sizeof(type) | Yes |
| sizeof parameter pack | sizeof...(Args) No |

The result of the sizeof operator is of type size_t, an integral type defined in the include file <stddef.h>. This operator allows you to avoid specifying machine-dependent data sizes in your programs.

The operand to sizeof can be one of the following:
  A type name. To use sizeof with a type name, the name must be enclosed in parentheses.
  An expression. When used with an expression, sizeof can be specified with or without the parentheses. The expression is not evaluated.

When the sizeof operator is applied to an object of type char, it yields 1. When the sizeof operator is applied to an array, it yields the total number of bytes in that array, not the size of the pointer represented by the array identifier. To obtain the size of the pointer represented by the array identifier, pass it as a parameter to a function that uses sizeof.

The value returned by sizeof is a compile-time constant, so it is always determined before program execution.



When the sizeof operator is applied to a class, struct, or union type, the result is the number of bytes in an object of that type, plus any padding added to align members on word boundaries. The result does not necessarily correspond to the size calculated by adding the storage requirements of the individual members.



The sizeof operator never yields 0, even for an empty class.

The sizeof operator cannot be used with the following operands:
  Functions. (However, sizeof can be applied to pointers to functions.)
  Bit fields.
  Undefined classes.
  The type void.
  Dynamically allocated arrays.
  External arrays.
  Incomplete types.
  Parenthesized names of incomplete types.

When the sizeof operator is applied to a reference, the result is the same as if sizeof had been applied to the object itself.

If an unsized array is the last element of a structure, the sizeof operator returns the size of the structure without the array.

The sizeof operator is often used to calculate the number of elements in an array using an expression of the form:

  sizeof array / sizeof array[0]
