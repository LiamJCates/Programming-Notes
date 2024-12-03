An operator is a symbol that tells the compiler to perform specific mathematical or logical functions. C language is rich in built-in operators and provides the following types of operators −

    Arithmetic Operators
    Relational Operators
    Logical Operators
    Bitwise Operators
    Assignment Operators
    Misc Operators








The ? : Operator

We have covered conditional ternary operator ? : in the previous chapter which can be used to replace if...else statements. It has the following general form −

Exp1 ? Exp2 : Exp3;

Where Exp1, Exp2, and Exp3 are expressions. Notice the use and placement of the colon.

The value of a ? expression is determined like this −

    Exp1 is evaluated. If it is true, then Exp2 is evaluated and becomes the value of the entire ? expression.

    If Exp1 is false, then Exp3 is evaluated and its value becomes the value of the expression.















Assignment Operators

The following table lists the assignment operators supported by the C language −

Show Examples
Operator 	Description 	Example
= 	Simple assignment operator. Assigns values from right side operands to left side operand 	C = A + B will assign the value of A + B to C
+= 	Add AND assignment operator. It adds the right operand to the left operand and assign the result to the left operand. 	C += A is equivalent to C = C + A
-= 	Subtract AND assignment operator. It subtracts the right operand from the left operand and assigns the result to the left operand. 	C -= A is equivalent to C = C - A
*= 	Multiply AND assignment operator. It multiplies the right operand with the left operand and assigns the result to the left operand. 	C *= A is equivalent to C = C * A
/= 	Divide AND assignment operator. It divides the left operand with the right operand and assigns the result to the left operand. 	C /= A is equivalent to C = C / A
%= 	Modulus AND assignment operator. It takes modulus using two operands and assigns the result to the left operand. 	C %= A is equivalent to C = C % A
<<= 	Left shift AND assignment operator. 	C <<= 2 is same as C = C << 2
>>= 	Right shift AND assignment operator. 	C >>= 2 is same as C = C >> 2
&= 	Bitwise AND assignment operator. 	C &= 2 is same as C = C & 2
^= 	Bitwise exclusive OR and assignment operator. 	C ^= 2 is same as C = C ^ 2
|= 	Bitwise inclusive OR and assignment operator. 	C |= 2 is same as C = C | 2






Misc Operators ↦ sizeof & ternary

Besides the operators discussed above, there are a few other important operators including sizeof and ? : supported by the C Language.

Show Examples
Operator 	Description 	Example
sizeof() 	Returns the size of a variable. 	sizeof(a), where a is integer, will return 4.
& 	Returns the address of a variable. 	&a; returns the actual address of the variable.
* 	Pointer to a variable. 	*a;
? : 	Conditional Expression. 	If Condition is true ? then value X : otherwise value Y
Operators Precedence in C

Operator precedence determines the grouping of terms in an expression and decides how an expression is evaluated. Certain operators have higher precedence than others; for example, the multiplication operator has a higher precedence than the addition operator.

For example, x = 7 + 3 * 2; here, x is assigned 13, not 20 because operator * has a higher precedence than +, so it first gets multiplied with 3*2 and then adds into 7.

Here, operators with the highest precedence appear at the top of the table, those with the lowest appear at the bottom. Within an expression, higher precedence operators will be evaluated first.

Show Examples
Category 	Operator 	Associativity
Postfix 	() [] -> . ++ - - 	Left to right
Unary 	+ - ! ~ ++ - - (type)* & sizeof 	Right to left
Multiplicative 	* / % 	Left to right
Additive 	+ - 	Left to right
Shift 	<< >> 	Left to right
Relational 	< <= > >= 	Left to right
Equality 	== != 	Left to right
Bitwise AND 	& 	Left to right
Bitwise XOR 	^ 	Left to right
Bitwise OR 	| 	Left to right
Logical AND 	&& 	Left to right
Logical OR 	|| 	Left to right
Conditional 	?: 	Right to left
Assignment 	= += -= *= /= %=>>= <<= &= ^= |= 	Right to left
Comma 	, 	Left to right
