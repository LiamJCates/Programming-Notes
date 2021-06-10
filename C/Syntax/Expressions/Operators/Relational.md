Relational Operators

The following table shows all the relational operators supported by C. Assume variable A holds 10 and variable B holds 20:


| Operator | Description | Example |
+----------+-------------+---------+
| == | Checks if the values of two operands are equal or not. If yes, then the condition becomes true. | (A == B) is not true. |
| != | Checks if the values of two operands are equal or not. If the values are not equal, then the condition becomes true. | (A != B) is true. |
| > | Checks if the value of left operand is greater than the value of right operand. If yes, then the condition becomes true. | (A > B) is not true. |
| < | Checks if the value of left operand is less than the value of right operand. If yes, then the condition becomes true. | (A < B) is true. |
| >= | Checks if the value of left operand is greater than or equal to the value of right operand. If yes, then the condition becomes true. | (A >= B) is not true. |
| <= | Checks if the value of left operand is less than or equal to the value of right operand. If yes, then the condition becomes true. | (A <= B) is true. |


#### Relational Operators
For the relational operators: <, >, <= and >=. One of the following will be true for these operators:

    both operands have real type;

    both operands are pointers to qualified or unqualified versions of compatible object types (types that fully describe onjects; we will see pointers later); or

    both operands are pointers to qualified or unqualified versions of compatible incomplete types (types that describe onjects but lack information needed to determine their size).

    If both the operands have arithmetic type, the usual arithmetic convrsions are performed.

    For the purposes of these operators, a pointer to an object that is not an element of an array behaves the same as a pointer to the first element of an array of length onr with the type of the object as its element type.

    When two pointers are compared, the result depends on the relative locations in the address space of the objects pointed to. If two pointers to object or incomplete types both point to the same object, or both point one past the last element of the same array object, they compare equal. If the objects pointed to are members of the same aggregate object, pointers to structure members declared later compare greater than pointers to members declared earlier in the structure, and pointers to array elements with larger subscript values compare greater than pointers to elements of the same array with lower subscript values. All pointers to members of the same union object compare equal. If the expression P points to an element of an array object and the expression Q points to the last element of the same array object, the pointer expression Q+1 compares greater than P. In all other cases, the behavior is undefined.

    Each of the operators < (less than), > (greater than), <= (less than or equal to), and >= (greater than or equal to) will yield 1 if the specified relation is true and 0 if it is false. The expression a<b<c is not implemented as in ordinary mathematics. As the syntax indicates, it means (a<b)<c. The result has type int.


```c
#include <stdio.h>
#include <stdbool.h>

int main()
{
  int i = 4, j = 5;
  _Bool result = 0;

  result = i < j;
  printf("%d\n", result);

  result = i > j;
  printf("%d\n", result);

  result = i <= j;
  printf("%d\n", result);

  result = i >= j;
  printf("%d\n", result);

  return 0;
}
```
and the output is:
```
1
0
1
0
```
Note that you should not apply these to floating-point data types as they may not be represented correctly and two different entities have the same internal representation.




#### Equality Operators

There are two equlity operators == and !=. Following contraints apply to these:

    both operands have arithmetic type;

    both operands are pointers to qualified or unqualified versions of compatible types; or

    one operand is a pointer to an object or incomplete type and the other is a

    pointer to a qualified or unqualified version of void; or

    one operand is a pointer and the other is a null pointer constant.

Given below are semantics of these operators.

    The == (equal to) and != (not equal to) operators are analogous to the relational operators except for their lower precedence. Because of the precedences, a<b == c<d is 1 whenever a<b and c<d have the same truth-value. Each of the operators yields 1 if the specified relation is true and 0 if it is false. The result has type int. For any pair of operands, exactly one of the relations is true.

    If both of the operands have arithmetic type, the usual arithmetic conversions are performed. Values of complex types are equal if and only if both their real parts are equal and also their imaginary parts are equal. Any two values of arithmetic types from different type domains are equal if and only if the results of their conversions to the (complex) result type determined by the usual arithmetic conversions are equal.

    Otherwise, at least one operand is a pointer. If one operand is a pointer and the other is a null pointer constant, the null pointer constant is converted to the type of the pointer. If one operand is a pointer to an object or incomplete type and the other is a pointer to a qualified or unqualified version of void, the former is converted to the type of the latter.

    Two pointers compare equal if and only if both are null pointers, both are pointers to the same object (including a pointer to an object and a subobject at its beginning) or function, both are pointers to one past the last element of the same array object, or one is a pointer to one past the end of one array object and the other is a pointer to the start of a different array object that happens to immediately follow the first array object in the address space.

    For the purposes of these operators, a pointer to an object that is not an element of an array behaves the same as a pointer to the first element of an array of length one with the type of the object as its element type.

```c
#include <stdio.h>
#include <stdbool.h>
int main()
{
  int i = 4, j = 5;
  _Bool result = 0;

  result = i == j;
  printf("%d\n", result);

  result = i != j;
  printf("%d\n", result);

  return 0;
}
```
and the output is:
```
0
1
```
