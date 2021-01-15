## Assignment Operators
C++ assignment is an expression, evaluated from right to left, that assigns a value to the specified identifier and resolves to the value assigned.

| Name | Syntax | Meaning | Overloadable |
|------|--------|---------|--------------|
| Basic assignment | a = b | | Yes |
| Addition Assignment | a += b | a = a + b | Yes |
| Subtraction Assignment | a +-= b | a = a - b | Yes |
| Multiplication Assignment | a *= b | a = a * b | Yes |
| Division Assignment | a /= b | a = a / b | Yes |
| Modulo Assignment | a %= b | a = a % b | Yes |
| Bitwise AND Assignment | a &= b | a = a & b | Yes |
| Bitwise OR Assignment | a \|= b | a = a \| b | Yes |
| Bitwise XOR Assignment | a ^= b | a = a ^ b | Yes |
| Bitwise left shift Assignment | a <<= b | a = a << b | Yes |
| Bitwise right shift Assignment | a >>= b | a = a >> b | Yes |

Assignment operators store a value in the object specified by the left operand. There are two kinds of assignment operations:

    simple assignment, in which the value of the second operand is stored in the object specified by the first operand.

    compound assignment, in which an arithmetic, shift, or bitwise operation is performed before storing the result.

All assignment operators except the = operator are compound assignment operators.



### Simple Assignment

The simple assignment operator (=) causes the value of the second operand to be stored in the object specified by the first operand. If both objects are of arithmetic types, the right operand is converted to the type of the left, before storing the value.

Assignments to reference types behave as if the assignment were being made to the object to which the reference points.

Objects of const and volatile types can be assigned to l-values of types that are only volatile, or that aren't const or volatile.

Assignment to objects of class type (struct, union, and class types) is performed by a function named operator=. The default behavior of this operator function is to perform a bitwise copy; however, this behavior can be modified using overloaded operators. Class types can also have copy assignment and move assignment operators.

An object of any unambiguously derived class from a given base class can be assigned to an object of the base class. The reverse isn't true because there's an implicit conversion from derived class to base class, but not from base class to derived class.



### Compound Assignment

The compound assignment operators are shown in the Assignment operators table. These operators have the form e1 op= e2, where e1 is a non-const modifiable l-value and e2 is:

    an arithmetic type

    a pointer, if op is + or -

The e1 op= e2 form behaves as e1 = e1 op e2, but e1 is evaluated only once.

Compound assignment to an enumerated type generates an error message. If the left operand is of a pointer type, the right operand must be of a pointer type, or it must be a constant expression that evaluates to 0. When the left operand is of an integral type, the right operand must not be of a pointer type.



Result of assignment operators
The assignment operators return the value of the object specified by the left operand after the assignment. The resultant type is the type of the left operand. The result of an assignment expression is always an l-value. These operators have right-to-left associativity. The left operand must be a modifiable l-value.
