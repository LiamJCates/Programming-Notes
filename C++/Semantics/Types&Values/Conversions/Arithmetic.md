## Arithmetic conversions

Many binary operators cause conversions of operands, and yield results the same way. The conversions these operators cause are called usual arithmetic conversions. Arithmetic conversions of operands that have different native types are done as shown in the following table. Typedef types behave according to their underlying native types.

Conditions for type conversion

If either operand is of type long double the other operand is converted to type long double.

If preceding condition not met and either operand is of type double the other operand is converted to type double.

If preceding conditions not met and either operand is of type float the other operand is converted to type float.

If preceding conditions not met (none of the operands are of floating types).

Operands get integral promotions as follows:

If either operand is of type unsigned long, the other operand is converted to type unsigned long.

If preceding condition not met, and if either operand is of type long and the other of type unsigned int, both operands are converted to type unsigned long.

If the preceding two conditions aren't met, and if either operand is of type long, the other operand is converted to type long.

If the preceding three conditions aren't met, and if either operand is of type unsigned int, the other operand is converted to type unsigned int.

If none of the preceding conditions are met, both operands are converted to type int.
