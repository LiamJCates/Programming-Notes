Bitwise Operators

Bitwise operator works on bits and perform bit-by-bit operation. The truth tables for &, |, and ^ is as follows −

| p | q | p & q | p | q | p ^ q |
+---+---+-------+---+---+-------+
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 | 0 |
| 1 | 0 | 0 | 1 | 1 |

Assume A = 60 and B = 13 in binary format, they will be as follows −

A = 0011 1100
B = 0000 1101

A&B == 0000 1100
A|B == 0011 1101
A^B == 0011 0001
~A == 1100 0011

The following table lists the bitwise operators supported by C. Assume variable 'A' holds 60 and variable 'B' holds 13, then −

| Operator | Description | Example |
+----------+-------------+---------+
| & | Binary AND Operator copies a bit to the result if it exists in both operands. | (A & B) = 12, i.e., 0000 1100 |
| \| | Binary OR Operator copies a bit if it exists in either operand. | (A | B) = 61, i.e., 0011 1101 |
| ^ | Binary XOR Operator copies the bit if it is set in one operand but not both. | (A ^ B) = 49, i.e., 0011 0001 |
| ~ | Binary One's Complement Operator is unary and has the effect of 'flipping' bits. | (~A ) = ~(60), i.e,. -0111101 |
| << | Binary Left Shift Operator. The left operands value is moved left by the number of bits specified by the right operand. | A << 2 = 240 i.e., 1111 0000 |
| >> | Binary Right Shift Operator. The left operands value is moved right by the number of bits specified by the right operand. | A >> 2 = 15 i.e., 0000 1111 |


#### Bitwise Operators

There are three bitwise operators. &, |, and ^. AND, OR and EX-OR respectively. OR is also called inclusive OR. These have the same contsraints and it is that operands should be integer types. The usual arithmetic conversions are performed on the operands.

The result of bianry & is the bitwise AND of operands (that is, each bit in the result is set if and only if each of the corresponding bits in the operands is set.)

The result of the ^ operator is the bitwise exclusive OR of the operands (that is, each bit in the result is set if and only if exactly one of the corresponding bits in the converted operands is set).

The result of the | operator is the bitwise inclusive OR of the operands (that is, each bit in the result is set if and only if at least one of the corresponding bits in the converted operands is set).

```c
#include <stdio.h>
#include <stdbool.h>

int main()
{
  int i = 4, j = 5;
  int result;

  result = i&j;
  printf("%d\n", result);

  result = i|j;
  printf("%d\n", result);

  result = i^j;
  printf("%d\n", result);

  return 0;
}
```
and the output is:
```
4
5
1
```



#### Bitwise Shift Operators

The constraint is same as other bitwise operators that operands should be integers. The integer promotions are performed on each of the operands. The type of the result if that of the promoted left operand. If the value of the right operand is negative or is greater than or equal to the width of the promoted left operand, the behavior is undefined.

The result of E1 << E2 is E1 left-shifted E2 bit-positions; vacated bits are filled with zeros. If E1 has an unsigned type, the value of the result is E1∗2E2
, reduced modulo one more than the maximum value representable in the reasult type. If E1 has a signed type and and nonnegative value, and E1∗2E2

is representable in the result type, then that is the resulting value; otherwise the behavior is undefined.

The result of E1 >> E2 is E1 right-shifted E2 bit-positions. If E1 has an unsigned type or if E1 has a signed type and a nonegative value, the value of the result is the integral part of the quotient of E1/2E2

. If E1 has a signed type and a negative value, the resulting value is implementation-defined.

// Author : Shiv S. Dayal
// Description : Demo of shift operators

#include <stdio.h>

int main()
{
  int i  = 4;
  char c ='A';
  int result;

  result = c<<i;
  printf("%d\n", result);

  result = c>>i;
  printf("%d\n", result);

  return 0;
}
