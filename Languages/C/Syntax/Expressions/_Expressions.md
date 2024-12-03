Expressions

An expression is a sequence of operators and operands. This sequence of operators and operands will lead to some computation; needless to say, however, it may designate an object or a function or it may generate a side effect or a combination.

The value computations of the operands of an operator are sequenced before the value computation of the result of the operator.

Consider the following where ++ is used as prefix and postfix increment unary operator, which should increment the value of operand after evaluating the operand:

i = ++i + 1;

a[i++] = i;

however, this is an undefined bahavior because if a side effect on a scalar (all arithmetic and pointer types are scalar) object is unsequenced relative to either a different side effect on the same scalar onject or a value computation using the value of the same scalar object, the behavior is undefined. If there are multiple allowable orderings of the subexpression of an expression, the behavior is undefined if such an unsequenced side effect occurs in any of the orderings.



The groupings of operators and operands is indicated by the syntax. The syntax specifies the precedence of operators in the evaluation, highest precedence first. The table is given later. The exceptions are cast expressions as operands of unary operators, and an operand contained between any of the following pairs of operators: grouping parentheses (), subscripting brackets[], function call parentheses (), and the conditional operator ?:.

Except as specified later, side effects and value computations of subexpressions are unsequenced. In an expression that is evaluated more than once during the execution of a program, unsequenced and indeterminately sequenced evaluations of its subexpressions need not be performed consistently in different evaluations.

Some operators (the unary operator ~, and the binary operators <<, >>, &, ^, and |, collectively described as bitwise opearators) are required to have operands that have integer types. These operators yield values that depend on the internal representation of intergers, and have implementation-defined and undefined aspects for signed types.

If an exceptional condition occurs during the evaluation of an expression (that is, if the result is not mathematicslly defined or not in the range of representable values for its type), the behavior is undefined.

The effective type of an object for an access to its stored value is the declared type of the object, if any. Note that allocated objects have no declared type. If a value is stored into an object having no declared type through an lvalue (a value whose address can be taken) having a type that is not a character type, then the type of the lvalue becomes the effective type of the object for that access and for subsequent accesses that do not modify the stored value. If a value is copied into an object having no declared type using memcpy or memmove, or is copied as an array of character type, then the effective type of the modified object for that access and for subsequent accesses that do not modify the value is the effective type of the object from which the value is copied, if it has one. For all other accesses to an object having no declared type, the effective type of the object is simply the type of the lvalue used for the access.

An object will have its stored value accessed only by an lvalue expression that has one of the following types:

    a type compatible with the effective type of the object,

    a qualified version of a type compatible with the effective type of the object,

    a type that is the signed or unsigned type corresponding to the effective type of the object,

    a type that is the signed or unsigned type corresponding to a qualified

    version of the effective type of the object,

    an aggregate or union type that includes one of the aforementioned types among its members (including, recursively, a member of a subaggregate or contained union), or a character type.

A floating expression may be contracted, that is, evaluated as though it were an atomic operation, thereby omitting rounding errors implied by the source code and the expression evaluation method. A contracted expression might also omit raising of floating-point exceptions. The FP_CONTRACT pragma in provides a way to disallow contracted expressions. Otherwise, whether and how expressions are contracted is implementation-defined.


#### Primary Expressions

An identifer is a primary expression, provided it has been decared as designating an object (in which case it is an lvalue) or a function (in which case it is a function designator). Thus, an undeclared identifire is a violation of syntax.

A constant is a primary expression. Its type depends on its form and lvalue (A value whose memory address can be taken. All variables except addresses themselves fall in this category).

A string literal is a primary expression. It is an lvalue.

A parenthesized expression is a primary expression. Its type and value are identical to those of upparenthesized expression. It is an lvalue, a function designator, or a void expression if the unparenthesized expression is, respectively, an lvalue, a function designator, or a void expression.
