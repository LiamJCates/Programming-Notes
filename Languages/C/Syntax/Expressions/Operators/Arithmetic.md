Arithmetic Operators

The following table shows all the arithmetic operators supported by the C language.

Assume variable A holds 10 and variable B holds 20:

| Operator | Description | Example |
+----------+-------------+---------+
| + | Adds two operands | A + B = 30 |
| − | Subtracts second operand from the first. | A − B = -10 |
| * | Multiplies both operands. | A * B = 200 |
| / | Divides numerator by denominator | B / A = 2 |
| % | Modulus Operator results in remainder after integer division | B % A = 0 |
| ++ | Increment operator increases the integer value by one. | A++ = 11 |
| -- | Decrement operator decreases the integer value by one. | A-- = 9 |



#### Additive Operators

There are two operators in this category. One you have seen in second chapter. These are + and -.

For addition, either both the operands will have arithmetic type, or one operand will be a pointer to an object type and the other will have integer type. (Incrementing is equivalent to adding 1.) We will see pointer arithmetic in the chapter dealing with pointers and arrays.

For subtraction following will hold:

    both operands have arithmetic type;

    both operands are pointers to qualified or unqualified versions of compatible object types; or

    the left operand is a pointer to an object type and the right operand has integer type. (Decrementing is equivalent to subtracting 1.)

If both operands have arithmetic type, the usual arithmetic conversions are performed on them. The result of the binary + operator is the sum of the operands. The result of the binary - operator is the difference resulting from the subtraction of the second operand from the first. There is also something called pointer arithmetic which we will see in Chapter 6 describing pointers and arrays.

#### Multiplicative Operators

There are three multiplicative operators. These are *, / and %. Each of the operands for these operands will have arithmetic type. That is character string cannot participate. The operands of % will have interger type. The usual arithmetic conversion are performed on the operands. The result of binary * operator is the product of operands. The result of the / operator is the quotient from the division; the result of the % operator is the remainder. In both the operations, if denominator is zero, the behavior is undefined. When integers are divided, the result of / operator is the algebraic quotient with any fractional parts discarded. This is often called “truncation towards zero”. Let us see a small program demonstrating these five arithmetic operators:

// Arithmetic operators

#include <stdio.h>

int main()
{
  int i = 10;
  float f = 6.45;
  char c = 'A';
  int iResult = 0;
  float fResult = 0.0;
  char cResult = '\0';

  cResult = c + i;
  printf("cResult = %c\n", cResult);
  cResult = cResult - 5;
  printf("cResult = %c\n", cResult);

  iResult = i - 10;
  printf("iResult = %d\n", iResult);
  iResult = i * c;
  printf("iResult = %d\n", iResult);
  iResult = (i + c)/3;
  printf("Result = %d\n", iResult);
  iResult = (i + c)%2;
  printf("iesult = %d\n", iResult);

  fResult = f * 2.12;
  printf("fesult = %f\n", fResult);
  fResult = f - i;
  printf("fesult = %f\n", fResult);
  fResult = f / 1.12;
  printf("fesult = %f\n", fResult);
  fResult = 1 % 3;
  printf("fesult = %f\n", fResult);

  return 0;
}

and the output is:

cResult = K
cResult = F
iResult = 0
iResult = 650
Result = 25
iesult = 1
fesult = 13.674000
fesult = -3.550000
fesult = 5.758928
fesult = 1.000000

First cResult is sumof 'A' + i which is 'K' as 'K' comes ten positions after A in ASCII table. Then we subtract five and go back to F.

First iReasult is 10 - i where value of i is 10 hence result is 0. Next we multiply it with c which contains 'A' who has got ASCII value of 65 and result becomes 650. Then We take sum of 'A' and i and divide by 3 so the result is 25 as it is a division of 75 by 3. Next we use modulus operator and remainder is 1. Note that in case of / and % if denominator is zero the behavior is undefined.

Same way you can udnerstand floating-point operations. Note that you cannot use modulus operator if either of the operands are floating-point numbers as it will make no sense because of data type promotion rules. Here data type promotion rule says smaller data types will be converted to bigger data types. Also, if there is a data type on left side of assignment the result of applying the operator to operands will be converted to the type of that. chars are promoted to ints, ints are promoted to floats anf floats to double. The point is that conversion will try to keep as much data as possible.



### Increment and Decrement Operators

There is one increment and one decrement operator. ++ and --. Both come in two forms prefix and postfix. First we will see prefix versions then postfix ones. There is only one constraint on prefix operators of these and that is the operand of the prefix increment or decrement operator will have qualified or unqualified real or pointer type and will be a modifiable lvalue.

The value of the operand of prefix ++ operator is incremented. The result is the new value of the operand after incrementation. The ++E is equivalent to (E += 1).

The prefix – operator is analogous to the prefix ++ operator except that the value of the operand is decremented. Now we will see postfix ones; the constraints are the same as prefix ones.

The result of the postfix ++ operator is the value of the operand. As a side effect, the value of the operand object is incremented (that is, the value 1 of the appropriate type is added to it). The value computation of the result is sequenced before the side effect of updating the stored value of the operand. With respect to an indeterminately-sequenced function call, the operation of postfix ++ is a single evaluation. The prefix -- operator is analogous to the prefix ++ operator except that the value of the operand is incremented. Here is the demo:

```c
#include <stdio.h>

int main()
{
  float f = 7.123;

  printf("%f\n", ++f);
  printf("%f\n", --f);
  printf("%f\n", f++);
  printf("%f\n", f--);
  printf("%f\n", f);

  return 0;
}
```
and the output is:
```
8.123000
7.123000
7.123000
8.123000
7.123000
```
