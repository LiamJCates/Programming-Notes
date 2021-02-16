### C-style
The simplest explicit casting operator is inherited from the C language, is to precede the expression to be converted by the new type enclosed between parentheses (()):

(type-name) cast-expression

Where
	type-name, delimited by parentheses, indicates one of the C++ data type (or a user-defined data type) to which the value of the expression is to be converted.
	cast-expression indicates a C++ expression; a literal value, variable, or complex expression whose data type is to be converted.

The compiler treats cast-expression as type (type-name) after a type cast has been made.

C-style casts can be used to convert objects of any scalar type to or from any other scalar type.

For information regarding type classifications, see:


C-style casts, but this is done mainly to maintain some compatibility between the languages.



C-style casts are far more dangerous than the named casts (and this is saying quite a bit).

The syntax of the C++ explicit casts is intentionally ugly and verbose.

This calls attention to a point in the code where the rigid rules of the type
system are being bent or broken. The C-style cast doesn’t do this. In addition, it’s not clear from the cast what kind of conversion the programmer is
intending. When you use finer instruments like the named casts, the compiler can at least enforce some constraints. For example, it’s all too easy to
forget const correctness when using a C-style cast when you only intended a
reinterpret_cast.

For each C-style cast, there exists some incantation of static_casts,
const_casts, and reinterpret_casts that would achieve the desired type conversion.











Syntax
( new_type ) expression 	(1) 	
new_type ( expression ) 	(2) 	
new_type ( arg1, arg2, ... ) 	(3) 	
new_type ( ) 	(4) 	
new_type { arg1, arg2, ...(optional) } 	(5) 	(since C++11)
template-name ( arg1, arg2, ...(optional) ) 	(6) 	(since C++17)
template-name { arg1, arg2, ...(optional) } 	(7) 	(since C++17)

Returns a value of type new_type.
Explanation
1) When the C-style cast expression is encountered, the compiler attempts to interpret it as the following cast expressions, in this order:
a) const_cast<new_type>(expression);
b) static_cast<new_type>(expression), with extensions: pointer or reference to a derived class is additionally allowed to be cast to pointer or reference to unambiguous base class (and vice versa) even if the base class is inaccessible (that is, this cast ignores the private inheritance specifier). Same applies to casting pointer to member to pointer to member of unambiguous non-virtual base;
c) static_cast (with extensions) followed by const_cast;
d) reinterpret_cast<new_type>(expression);
e) reinterpret_cast followed by const_cast.
The first choice that satisfies the requirements of the respective cast operator is selected, even if it cannot be compiled (see example). If the cast can be interpreted in more than one way as static_cast followed by a const_cast, it cannot be compiled.
In addition, C-style cast notation is allowed to cast from, to, and between pointers to incomplete class type. If both expression and new_type are pointers to incomplete class types, it's unspecified whether static_cast or reinterpret_cast gets selected.
2) The functional cast expression consists of a simple type specifier or a typedef specifier (in other words, a single-word type name: unsigned int(expression) or int*(expression) are not valid), followed by a single expression in parentheses. This cast expression is exactly equivalent to the corresponding C-style cast expression.
3) If there are more than one expression or braced-init-list (since C++11) in parentheses, new_type must be a class with a suitably declared constructor. This expression is a prvalue of type new_type designating a temporary (until C++17)whose result object is (since C++17) direct-initialized with expression-list.
4) If new_type names a non-array complete object type, this expression is an prvalue of type new_type, designating a temporary (until C++17)whose result object is (possibly with added cv-qualifiers) (since C++17) of that type. If new_type is an object type, the object is value-initialized. If new_type is (possibly cv-qualified) void, the expression is a void prvalue without a result object (since C++17).
5) A single-word type name followed by a braced-init-list is a prvalue of the specified type designating a temporary (until C++17)whose result object is (since C++17) direct-list-initialized with the specified braced-init-list. If new_type is (possibly cv-qualified) void, the expression is a void prvalue without a result object (since C++17).

This is the only cast expression that can create an array prvalue.
	(until C++20)
6,7) Same as (2-5), except first performs class template argument deduction,

As with all cast expressions, the result is:

    an lvalue if new_type is an lvalue reference type or an rvalue reference to function type;
    an xvalue if new_type is an rvalue reference to object type;
    a prvalue otherwise.
