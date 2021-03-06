Explicit Type Conversion

C++ is a strong-typed language. Many conversions, specially those that imply a different interpretation of the value, require an explicit conversion.

Explicit type conversions are also called casts, and the act of performing an explicit type conversion is known as type-casting.

Type-casting, or casting, is a mechanism by which the programmer can temporarily or permanently change the interpretation of an object by the compiler.

There primary mechanisms that support C++ casting operations are called:
	Explicit Casting Operators
	Named Conversions

Operators that change the interpretation of an object are called casting operators.

Explicit Casting Operators

| Name | Syntax | Overloadable |
|------|--------|--------------|
| C-Style Conversion | (type)a | Yes |
| Functional Conversion | type(a) | No |

Standard Named Conversions

| Name | Syntax | Overloadable |
|------|--------|--------------|
| static_cast | static_cast<type>(a) | Yes |
| dynamic_cast | dynamic_cast<type>(a) | No |
| const_cast | const_cast<type>(a) | No |
| reinterpret_cast | reinterpret_cast<type>(a) | No |

Note
Some third-party libraries support additional named conversions.



Using an explicit cast instructs the compiler to convert a value of one type to another type. 

Casts should be used carefully, because what you are actually doing is saying to the compiler “Forget type checking – treat it as this other type instead.”

That is, you’re introducing a hole in the C++ type system and preventing the compiler from telling you that you’re doing something wrong with a type.

What’s worse, the compiler believes you implicitly and doesn’t perform any other checking to catch errors. Once you start casting, you open yourself up for all kinds of problems. In fact, any program that uses a lot of casts should be viewed with suspicion, no matter how much you are told it simply “must” be done that way. In general, casts should be few and isolated to the solution of very specific problems. Once you understand this and are presented with a buggy program, your first inclination may be to look for casts as culprits.

The compiler will raise an error in some cases if the two types are completely unrelated, but in other cases it will not raise an error even if the operation is not type-safe. Use casts sparingly because any conversion from one type to another is a potential source of program error. However, casts are sometimes required, and not all casts are equally dangerous. One effective use of a cast is when your code performs a narrowing conversion and you know that the conversion is not causing your program to produce incorrect results. In effect, this tells the compiler that you know what you are doing and to stop bothering you with warnings about it. Another use is to cast from a pointer-to-derived class to a pointer-to-base class. Another use is to cast away the const-ness of a variable to pass it to a function that requires a non-const argument. Most of these cast operations involve some risk.

Use the explicit type conversions with care, since these mechanisms override the C++ compiler's built-in type checking.



Legal Type Casts
| Destination Types | Potential Sources |
|-------------------|-------------------|
| Integral types | Any integer type or floating-point type, or pointer to an object |
| Floating-point | Any arithmetic type |
| A pointer to an object, or (void *) | Any integer type, (void *), a pointer to an object, or a function pointer |
| Function pointer | Any integral type, a pointer to an object, or a function pointer |
| A structure, union, or array | None |
| Void type | Any type |

Any identifier can be cast to void type. However, if the type specified in a type-cast expression is not void, then the identifier being cast to that type cannot be a void expression. Any expression can be cast to void, but an expression of type void cannot be cast to any other type. For example, a function with void return type cannot have its return cast to another type.

Note that a void * expression has a type pointer to void, not type void. If an object is cast to void type, the resulting expression cannot be assigned to any item. Similarly, a type-cast object is not an acceptable l-value, so no assignment can be made to a type-cast object.

You can convert an expression to type void with a cast, but the resulting expression can be used only where a value is not required. An object pointer converted to void * and back to the original type will return to its original value.

Type definition within casts is illegal.

The C++ language provides that if a class is derived from a base class containing virtual functions, a pointer to that base class type can be used to call the implementations of the virtual functions residing in the derived class object. A class containing virtual functions is sometimes called a "polymorphic class."

Since a derived class completely contains the definitions of all the base classes from which it is derived, it is safe to cast a pointer up the class hierarchy to any of these base classes. Given a pointer to a base class, it might be safe to cast the pointer down the hierarchy. It is safe if the object being pointed to is actually of a type derived from the base class. In this case, the actual object is said to be the "complete object." The pointer to the base class is said to point to a "subobject" of the complete object.













The first port of call for conducting an explicit type conversion is braced initialization {}. This approach has the major benefit of being fully type safe and non-narrowing. The use of braced initialization ensures at compile time that only safe, well-behaved, non-narrowing conversions are allowed.
