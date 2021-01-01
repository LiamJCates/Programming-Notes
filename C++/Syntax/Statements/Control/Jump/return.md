### return
Terminates the current function and returns the specified value (if any) to its caller.

Syntax
(1) attr(optional) return expression(optional) ;
(2) attr(optional) return braced-init-list ; 	(2) 	(since C++11)
(3) attr(optional) co_return expression(optional) ; 	(3) 	(since C++20)
(4) attr(optional) co_return braced-init-list ; 	(4) 	(since C++20)

attr(C++11) - optional sequence of any number of attributes
expression - expression, convertible to the function return type
braced-init-list - brace-enclosed list of initializers and other braced-init-lists

Explanation
1) Evaluates the expression, terminates the current function and returns the result of the expression to the caller, after implicit conversion to the function return type. The expression is optional in functions whose return type is void, and disallowed in constructors and in destructors.

2) Uses copy-list-initialization to construct the return value of the function.

3,4) In a coroutine, the keyword co_return must be used instead of return for the final suspension point (see coroutines for details).
Notes

If control reaches the end of a function with the return type void, end of a constructor, end of a destructor, or the end of a function-try-block for a function with the return type void without encountering a return statement, return; is executed.

If control reaches the end of the main function, return 0; is executed.

Flowing off the end of a value-returning function (except main) without a return statement is undefined behavior.

In a function returning void, the return statement with expression can be used, if the expression type is void.

(since C++14)
The copy-initialization of the result of the function call is sequenced-before the destruction of all temporaries at the end of expression, which, in turn, is sequenced-before the destruction of local variables of the block enclosing the return statement.
