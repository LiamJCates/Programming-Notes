Member and Pointer Operators

## Unary Pointer Operators
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Indirection | *a | Yes |
| Address-of | &a | Yes |


### Indirection
The unary indirection operator (*) dereferences a pointer; that is, it converts a pointer value to an l-value. The operand of the indirection operator must be a pointer to a type. The result of the indirection expression is the type from which the pointer type is derived.

If the operand points to a function, the result is a function designator. If it points to a storage location, the result is an l-value designating the storage location.

If the pointer value is invalid, the result is undefined. The following list includes some of the most common conditions that invalidate a pointer value.

    The pointer is a null pointer.

    The pointer specifies the address of a local item that is not visible at the time of the reference.

    The pointer specifies an address that is inappropriately aligned for the type of the object pointed to.

    The pointer specifies an address not used by the executing program.



### Address-of
The unary address-of operator (&) takes the address of its operand. The operand of the address-of operator can be either a function designator or an l-value that designates an object that's not a bit field.

The address-of operator can only be applied to variables of fundamental, structure, class, or union types that are declared at the file-scope level, or to subscripted array references. In these expressions, a constant expression that doesn't include the address-of operator can be added to or subtracted from the address-of expression.

When applied to functions or l-values, the result of the expression is a pointer type (an r-value) derived from the type of the operand. For example, if the operand is of type char, the result of the expression is of type pointer to char. The address-of operator, applied to const or volatile objects, evaluates to const type * or volatile type *, where type is the type of the original object.

The address of an overloaded function can be taken only when it's clear which version of the function is being referenced.

When the address-of operator is applied to a qualified name, the result depends on whether the qualified-name specifies a static member. If so, the result is a pointer to the type specified in the declaration of the member. For a member that isn't static, the result is a pointer to the member name of the class indicated by qualified-class-name.



## Member Access
| Name | Syntax | Overloadable |
|------|--------|--------------|
| Structure Dereference | a->b | Yes |
| Structure Reference | a.b | Yes |
| Member selected by pointer-to-member b of object pointed to by a | a->*b | Yes |
| Member of object a selected by pointer-to-member b | a.*b | Yes |



The member access operators . and -> are used to refer to members of structures, unions, and classes. Member access expressions have the value and type of the selected member.

There are two forms of member access expressions:

    In the first form, postfix-expression represents a value of struct, class, or union type, and name names a member of the specified structure, union, or class. The value of the operation is that of name and is an l-value if postfix-expression is an l-value.

    In the second form, postfix-expression represents a pointer to a structure, union, or class, and name names a member of the specified structure, union, or class. The value is that of name and is an l-value. The -> operator dereferences the pointer. Therefore, the expressions e->member and (*e).member (where e represents a pointer) yield identical results (except when the operators -> or * are overloaded).
