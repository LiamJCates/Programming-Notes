| Name | Syntax | Overloadable |
|------|--------|--------------|
| Function Call | a(Args) | Yes |

A function call is a kind of postfix-expression, formed by an expression that evaluates to a function or callable object followed by the function-call operator, (). An object can declare an operator () function, which provides function call semantics for the object.
Syntax

    postfix-expression:
     postfix-expression ( argument-expression-list opt )


The arguments to the function-call operator come from an argument-expression-list, a comma-separated list of expressions. The values of these expressions are passed to the function as arguments. The argument-expression-list can be empty. Before C++ 17, the order of evaluation of the function expression and the argument expressions is unspecified and may occur in any order. In C++17 and later, the function expression is evaluated before any argument expressions or default arguments. The argument expressions are evaluated in an indeterminate sequence.

The postfix-expression evaluates to the function to call. It can take any of several forms:
  a function identifier, visible in the current scope or in the scope of any of the function arguments provided,
  an expression that evaluates to a function, a function pointer, a callable object, or to a reference to one,
  a member function accessor, either explicit or implied,
  a dereferenced pointer to a member function.

The postfix-expression may be an overloaded function identifier or overloaded member function accessor. The rules for overload resolution determine the actual function to call. If the member function is virtual, the function to call is determined at run time.

A function call evaluates to an rvalue unless the function is declared as a reference type. Functions with reference return types evaluate to lvalues. These functions can be used on the left side of an assignment statement

Functions that return class types, pointers to class types, or references to class types can be used as the left operand to member-selection operators
