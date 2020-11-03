Operators

Generally, there are three types of operators: unary, binary, and ternary.
These terms reflect the number of operands an operator requires.

arithmetic operators in Java include +, -, *, / and % which represent addition, subtraction, multiplication, division and modulus respectively.

For exponent operations the Math.pow(a, b) method can be used

In Java, division truncates to the nearest integer answer if both x and y are integers.
In order for a division operation to return a floating-point value, one of the operands must be of a floating-point data type.

Zero
Floating-point zeros can be positive or negative. Java considers positive and negative zeros to be equal numerically.

Dividing by Zero throws and exception

If you try to divide a floating-point type by zero Java assigns special values:
» If you divide a number by zero, and the sign of both numbers is the same, the result is positive infinity. 40.0 divided by 0.0 is positive infinity, as is -34.0 divided by -0.0.
» If you divide a number by zero, and the signs of the numbers are different, the result is negative infinity. -40.0 divided by 0.0 is negative infinity, as is 34.0 divided by -0.0.
» If you divide zero by zero, the result is not a number (NaN), regardless of the signs.



Printing a floating-point variable holding these special values, Java converts to an appropriate string:
double k =  50.0 / 0.0;    would display ∞
     -50.0 / 0.0;     would display -Infinity
        0.0 / 0.0;    would display NaN.
System.out.println(k);

In most cases, Java’s floating-point math is close enough not to matter. The margin of error is extremely small. If you’re using Java to measure the size of your house, you’d need an electron microscope to notice the error. If you’re writing applications that deal with financial transactions, however, normal rounding can sometimes magnify the errors to make them significant. You may charge a penny too much or too little sales tax. And in extreme cases, your invoices may actually have obvious addition errors.

Integer types are stored in binary too, of course. But integers aren’t subject to the same errors that floating-point types are — because integers don’t represent fractions at all — so you don’t have to worry about this type of error for integer types.



Increment and Decrement
The ++ and -- operators are used to increment or decrement the value of a variable by 1.

These operators are unusual because they are unary operators that can be placed either before (prefix) or after (postfix)the variable they apply to.
A prefix operator is applied before the rest of the expression is evaluated.
As a result, the altered value of the variable is used in the expression.
A postfix operator is applied after the expression is evaluated.
Thus the unaltered value of the variable is used in the expression.

Suppose we have an integer named counter. If we write
System.out.println(counter++);
the program first prints the original value of counter before incrementing counter by 1, as opposed to the reverse for postfix.


Assignment Operators
The assignment operator is one equals sign =

Compound Assignment Operators
These operators combine a binary operation with assignment
the operation is performed between either side of the compound operator and assigned to the left side.
Arithmetic: +=     -=    *=    /=    %=    Logical:    &=    |=    ^=



Logical operators
&    AND
&&    Short-circuit AND
|    OR
||    Short-circuit OR
^    XOR
!     NOT

Logical operators work with  boolean value expression operands to produce a boolean value
Q: As short-circuit operators are potentially more efficient at determining the boolean value of an expression, why does Java still offer the normal AND and OR operators?
A: In some cases you will want both operands of an AND or OR operation to be evaluated, even if the eventual result value can be determined by the first operand because of the side effects produced by the operand expressions.


Ternary Operator
variable = (condition) ? expressionTrue : expressionFalse;

shorthand for a single if-else statement


Comparison Operators
Most control flow statements involve doing some form of comparison. The program proceeds differently depending on the boolean result of the comparison. To produce this result we use the comparison operators:
< less than
<= less than or equal to
> greater than
>= greater than or equal to
== equal
!= not equal


Bitwise Operators
&    Bitwise AND
|    Bitwise OR
^    Bitwise XOR
>>    Shift Right
>>>    Unsigned Shift Right
<<    Shift Left
~    One's Complement (unary NOT)

Called bitwise operators because they are used to test, set, or shift individual bits of a value.
The bitwise operators can be used on values of type long, int, short, char, or byte.
Bitwise operations cannot be used on boolean, float, double, or class types.

bitwise shift operators can be used to perform very fast multiplication or division by two.

left shift doubles a value by shifting all bits left one position and a 0 bit to be brought in on the right.
right shift haves a value by shift all bits to the right one position and preserving the sign bit.

As you may know, negative numbers are usually represented by setting the highorder bit of an integer value to 1, and this is the approach used by Java. Thus, if the value being shifted is negative, each right shift brings in a 1 on the left. If the value is positive, each right shift brings in a 0 on the left. In addition to the sign bit, there is something else to be aware of when right shifting. Java uses two’s complement to represent negative values. In this approach negative values are stored by first reversing the bits in the value and then adding 1. Thus, the byte value for –1 in binary is 1111 1111. Right shifting this value will always produce –1! If you don’t want to preserve the sign bit when shifting right, you can use an unsigned right shift (>>>), which always brings in a 0 on the left. For this reason, the >>> is also called the zero-fill right shift. You will use the unsigned right shift when shifting bit patterns, such as status codes, that do not represent integers. For all of the shifts, the bits shifted out are lost. Thus, a shift is not a rotate, and there is no way to retrieve a bit that has been shifted out.

You need to be careful when shifting byte and short values because Java will automatically promote these types to int when evaluating an expression.
The result of the shift will also be of type int.
Often this conversion is of no consequence. However, if you shift a negative byte or short value, it will be sign-extended when it is promoted to int. Thus, the high-order bits of the resulting integer value will be filled with ones. This is fine when performing a normal right shift. But when you perform a zero-fill right shift, there are 24 ones to be shifted before the byte value begins to see zeros.



Operator Precedence
Although technically separators, the [], (), and . can also act like operators. In that capacity, they would have the highest precedence.

Operations of the same order of precedence are done from left to right.
override the order of precedence using parentheses.
Within parentheses sets, operations follow the order of precedence.
In general, use parentheses to specify the sequence of operations whenever there's any doubt about it.
