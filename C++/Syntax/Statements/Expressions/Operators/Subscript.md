| Name | Syntax | Overloadable |
|------|--------|--------------|
| Subscript | a[b] | Yes |

Subscript
A postfix expression (which can also be a primary expression) followed by the subscript operator, [ ], specifies array indexing.

Usually, the value represented by postfix-expression is a pointer value, such as an array identifier, and expression is an integral value (including enumerated types). However, all that is required syntactically is that one of the expressions be of pointer type and the other be of integral type. Thus the integral value could be in the postfix-expression position and the pointer value could be in the brackets in the expression or subscript position.

the expression nArray[2] is identical to 2[nArray]. The reason is that the result of a subscript expression e1[e2] is given by:

  *((e2) + (e1))

The address yielded by the expression is not e2 bytes from the address e1. Rather, the address is scaled to yield the next object in the array e2.

A subscript expression can also have multiple subscripts, as follows:

expression1 [ expression2 ] [ expression3 ] ...

Subscript expressions associate from left to right. The leftmost subscript expression, expression1 [ expression2 ], is evaluated first. The address that results from adding expression1 and expression2 forms a pointer expression; then expression3 is added to this pointer expression to form a new pointer expression, and so on until the last subscript expression has been added. The indirection operator (*) is applied after the last subscripted expression is evaluated, unless the final pointer value addresses an array type.

Expressions with multiple subscripts refer to elements of multidimensional arrays.

Positive and negative subscripts

The first element of an array is element 0. The range of a C++ array is from array[0] to array[size - 1]. However, C++ supports positive and negative subscripts. Negative subscripts must fall within array boundaries; if they do not, the results are unpredictable.

The subscript operator is commutative. Therefore, the expressions array[index] and index[array] are guaranteed to be equivalent as long as the subscript operator is not overloaded (see Overloaded Operators). The first form is the most common coding practice, but either works.
