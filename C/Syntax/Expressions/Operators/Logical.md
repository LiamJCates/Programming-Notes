Logical Operators

Following table shows all the logical operators supported by C language. Assume variable A holds 1 and variable B holds 0, then −

| Operator | Description | Example |
+----------+-------------+---------+
| && | Called Logical AND operator. If both the operands are non-zero, then the condition becomes true. | (A && B) is false. |
| || | Called Logical OR Operator. If any of the two operands is non-zero, then the condition becomes true. | (A || B) is true. |
| ! | Called Logical NOT Operator. It is used to reverse the logical state of its operand. If a condition is true, then Logical NOT operator will make it false. | !(A && B) is true. |
|


### Logical Operators

There are two such operators. && logical AND and || locical OR. Both the operators have the same constraints and it is that both the operands will have scalar type.

The && operator gives 1 if both the operands are non-zero else 0. The result type is int. It is different from bitwise & operator in the sense that it guarantess left-to-right evaluation; if the second operand is evaluated, there is a sequence point between the evaluations of the first and second operands. If the first operand is 0 then the second operand is not evaluated. This is known as “short-circuit evaluation”.

The || operator gives 1 if any of operands are non-zero else it gives 0. Same as logical AND operator and unlike bitwise | operator it guarantees left-to-right evaluation and same goes for sequence points. If first operand is non-zero, the second is not evaluated.

```c
#include <stdio.h>
#include <stdbool.h>

int main()
{
  int i = 4, j = 5, k = 0;
  bool result;

  result = i&&j;
  printf("%d\n", result);

  result = i||j;
  printf("%d\n", result);

  result = k&&j;
  printf("%d\n", result);

  result = k||j;
  printf("%d\n", result);

  return 0;
}
```
and the output is:
```
1
1
0
1
```
note the use of bool here instead of _Bool.
