## Relational Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Equal to | a == b | Yes |
| Not Equal To | a != b | Yes |
| Greater Than | a > b | Yes |
| Less Than | a < b | Yes |
| Greater Than or Equal | a >= b | Yes |
| Less Than or Equal | a <= b | Yes |

The relational operators have left-to-right associativity. Both operands of relational operators must be of arithmetic or pointer type. They yield values of type bool. The value returned is false (0) if the relationship in the expression is false; otherwise, the value returned is true (1).

The usual arithmetic conversions covered are applied to operands of arithmetic types:
[C++\Semantics\Types&Values\Conversions\StandardConversions.md]

When two pointers to objects of the same type are compared, the result is determined by the location of the objects pointed to in the program's address space. Pointers can also be compared to a constant expression that evaluates to 0 or to a pointer of type void *. If a pointer comparison is made against a pointer of type void *, the other pointer is implicitly converted to type void *. Then the comparison is made.

Two pointers of different types cannot be compared unless:

    One type is a class type derived from the other type.

    At least one of the pointers is explicitly converted (cast) to type void *. (The other pointer is implicitly converted to type void * for the conversion.)

Two pointers of the same type that point to the same object are guaranteed to compare equal. If two pointers to nonstatic members of an object are compared, the following rules apply:

    If the class type is not a union, and if the two members are not separated by an access-specifier, such as public, protected, or private, the pointer to the member declared last will compare greater than the pointer to the member declared earlier.

    If the two members are separated by an access-specifier, the results are undefined.

    If the class type is a union, pointers to different data members in that union compare equal.

If two pointers point to elements of the same array or to the element one beyond the end of the array, the pointer to the object with the higher subscript compares higher. Comparison of pointers is guaranteed valid only when the pointers refer to objects in the same array or to the location one past the end of the array.
