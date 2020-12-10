
### Operator Overloading
For each fundamental type, some portion of the operators will be available.

For user-defined types, you can specify custom behavior for these operators by employing operator overloading. To specify behavior for an operator in a user-defined class, simply name the method with the word operator immediately followed by the operator; ensure that the return types and parameters match the types of the operands you want to deal with.

You can redefine or overload most of the built-in operators available in C++. Thus, a programmer can use operators with user-defined types as well.

Overloaded operators are functions with special names: the keyword "operator" followed by the symbol for the operator being defined. Like any other function, an overloaded operator has a return type and a parameter list.

An operator declaration looks quite like a
function declaration:
return_type operator operator_symbol (...parameter list...);

The operator_symbol in this case could be any of the several operator types that the
programmer can define. It could be + (addition) or && (logical AND) and so on.


When overloading an operator, keep the following in mind:
1. You cannot change the precedence of an operator.
2. The associativity cannot be changed. (For example, the associativity of
the arithmetic operator addition is from left to right, and it cannot be
changed.)
3. Default parameters cannot be used with an overloaded operator.
4. You cannot change the number of parameters an operator takes.
5. You cannot create new operators. Only existing operators can be
overloaded.
6. The operators that cannot be overloaded are:
. .* :: ?: sizeof
7. The meaning of how an operator works with built-in types, such as
int, remains the same. That is, you cannot redefine how operators
work with built-in data types.
8. Operators can be overloaded either for objects of the user-defined
types, or for a combination of objects of the user-defined type and
objects of the built-in type.



Overloadable/Non-overloadable Operators

Following is the list of operators which can be overloaded −
+ 	- 	* 	/ 	% 	^
& 	| 	~ 	! 	, 	=
< 	> 	<= 	>= 	++ 	--
<< 	>> 	== 	!= 	&& 	||
+= 	-= 	/= 	%= 	^= 	&=
|= 	*= 	<<= 	>>= 	[] 	()
-> 	->* 	new 	new [] 	delete 	delete []

Following is the list of operators, which can not be overloaded −
:: 	.* 	. 	?:



On a broad level, operators in C++ can be classified into two types: unary operators and
binary operators.

Unary Operators
operators that function on a single operand are called unary
operators. A unary operator that is implemented in the global namespace or as a static
member function of a class uses the following structure:
return_type operator operator_type (parameter_type)
{
// ... implementation
}
A unary operator that is a (non-static) member of a class has a similar structure but is
lacking in parameters, because the single parameter that it works upon is the instance of
the class itself (*this):
return_type operator operator_type ()
{
// ... implementation
}

Unary Operators

| Symbol | Name |
|--------|------|
| ++ | Increment |
| -- | Decrement |
| * | Pointer dereference |
| -> | Member selection |
| ! | Logical NOT |
| & | Address-of |
| ~ | One’s complement |
| + | Unary plus |
| - | Unary negation |



Example
A unary prefix increment operator (++) can be programmed using the following syntax
within the class declaration:
// Unary increment operator (prefix)
Date& operator ++ ()
{
// operator implementation code
return *this;
}

The postfix increment operator (++), on the other hand, has a different return type and an
input parameter (that is not always used):
Date operator ++ (int)
{
// Store a copy of the current state of the object, before incrementing day
Date copy (*this);
// increment implementation code
// Return state before increment (because, postfix)
return copy;
}


The prefix and postfix decrement operators have a similar syntax as the increment
operators, just that the declaration would contain a -- where you see a ++.

As the implementation of the postfix operators demonstrates, a
copy containing the existing state of the object is created before
the increment or decrement operation to be returned thereafter.
In other words, if you had the choice between using ++ object;
and object ++; to essentially only increment, you should
choose the former to avoid the creation of a temporary copy that
will not be used.






Binary Operators
Operators that function on two operands are called binary operators. The definition of
a binary operator implemented as a global function or a static member function is the
following:
return_type operator_type (parameter1, parameter2);
The definition of a binary operator implemented as a class member is
return_type operator_type (parameter);
The reason the class member version of a binary operator accepts only one parameter is
that the second parameter is usually derived from the attributes of the class itself.


Overloadable Binary Operators
| Symbol | Name |
|--------|------| |
| , | Comma |
| != | Inequality |
| % | Modulus |
| %= | Modulus/assignment |
| & | Bitwise AND |
| && | Logical AND |
| &= | Bitwise AND/assignment |
| * | Multiplication |
| *= | Multiplication/assignment |
| + | Addition |
| += | Addition/assignment |
| - | Subtraction |
| -= | Subtraction/assignment |
| ->* | Pointer-to-member selection |
| / | Division |
| /= | Division/assignment |
| < | Less than |
| << | Left shift |
| <<= | Left shift/assignment |
| <= | Less than or equal to |
| = | Assignment, Copy Assignment and Move Assignment |
| == | Equality |
| \> | Greater than |
| \>= | Greater than or equal to |
| \>> | Right shift |
| \>>= | Right shift/assignment |
| ^ | Exclusive OR |
| ^= | Exclusive OR/assignment |
| | | Bitwise inclusive OR |
| |= | Bitwise inclusive OR/assignment |
| || | Logical OR |
| [] | Subscript operator |




Operator Overloading Examples

Here are various operator overloading examples to help you in understanding the concept.

Unary Operators Overloading
https://www.tutorialspoint.com/cplusplus/unary_operators_overloading.htm

Binary Operators Overloading
https://www.tutorialspoint.com/cplusplus/binary_operators_overloading.htm

Relational Operators Overloading
https://www.tutorialspoint.com/cplusplus/relational_operators_overloading.htm

Input/Output Operators Overloading
https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm

++ and -- Operators Overloading
https://www.tutorialspoint.com/cplusplus/increment_decrement_operators_overloading.htm

Assignment/Copy Operators Overloading
https://www.tutorialspoint.com/cplusplus/assignment_operators_overloading.htm

Function call () Operator Overloading
https://www.tutorialspoint.com/cplusplus/function_call_operator_overloading.htm

Subscripting [] Operator Overloading
https://www.tutorialspoint.com/cplusplus/subscripting_operator_overloading.htm

Class Member Access Operator -> Overloading
https://www.tutorialspoint.com/cplusplus/class_member_access_operator_overloading.htm
