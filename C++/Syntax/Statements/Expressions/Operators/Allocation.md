| Name | Syntax | Overloadable |
|------|--------|--------------|
| Allocate storage | new type | Yes |
| Allocate array storage new type[n] | Yes |
| Deallocate storage | delete a | Yes |
| Deallocate array storage | delete[] a | Yes |

C++ supports dynamic allocation and deallocation of objects using the new and delete operators. These operators allocate memory for objects from a pool called the free store. The new operator calls the special function operator new, and the delete operator calls the special function operator delete.

The new function in the C++ Standard Library supports the behavior specified in the C++ standard, which is to throw a std::bad_alloc exception if the memory allocation fails.


If the request is for zero bytes of storage, operator new returns a pointer to a distinct object. That is, repeated calls to operator new return different pointers. If there's insufficient memory for the allocation request, operator new throws a std::bad_alloc exception.




new
Allocates memory for an object or array of objects of type-name from the free store and returns a suitably typed, nonzero pointer to the object.

[::] new [placement] new-type-name [new-initializer]
[::] new [placement] ( type-name ) [new-initializer]




Scope for operator new functions

::operator new 	              Global
class-name ::operator new     Class

The first argument to operator new must be of type size_t, defined in <stddef.h>, and the return type is always void*.

The global operator new function is called when the new operator is used to allocate objects of built-in types, objects of class type that don't contain user-defined operator new functions, and arrays of any type. When the new operator is used to allocate objects of a class type where an operator new is defined, that class's operator new is called.

An operator new function defined for a class is a static member function (which can't be virtual) that hides the global operator new function for objects of that class type.

The compiler supports member array new and delete operators in a class declaration.


delete

Deallocates a block of memory.

Syntax
[::] delete cast-expression
[::] delete [] cast-expression

The cast-expression argument must be a pointer to a block of memory previously allocated for an object created with the new operator. The delete operator has a result of type void and therefore does not return a value.

Using delete on a pointer to an object not allocated with new gives unpredictable results. You can, however, use delete on a pointer with the value 0. This provision means that, when new returns 0 on failure, deleting the result of a failed new operation is harmless.

Using the delete operator on an object deallocates its memory. A program that dereferences a pointer after the object is deleted can have unpredictable results or crash.

When delete is used to deallocate memory for a C++ class object, the object's destructor is called before the object's memory is deallocated (if the object has a destructor).

If the operand to the delete operator is a modifiable l-value, its value is undefined after the object is deleted.


Memory that is dynamically allocated using the new operator can be freed using the delete operator. The delete operator calls the operator delete function, which frees memory back to the available pool. Using the delete operator also causes the class destructor (if one exists) to be called.

There are global and class-scoped operator delete functions. Only one operator delete function can be defined for a given class; if defined, it hides the global operator delete function. The global operator delete function is always called for arrays of any type.

The global operator delete function. Two forms exist for the global operator delete and class-member operator delete functions:
C++

void operator delete( void * );
void operator delete( void *, size_t );

Only one of the preceding two forms can be present for a given class. The first form takes a single argument of type void *, which contains a pointer to the object to deallocate. The second form, sized deallocation, takes two arguments: the first is a pointer to the memory block to deallocate, and the second is the number of bytes to deallocate. The return type of both forms is void (operator delete can't return a value).

The intent of the second form is to speed up searching for the correct size category of the object to delete. This information often isn't stored near the allocation itself, and is likely uncached. The second form is useful when an operator delete function from a base class is used to delete an object of a derived class.

The operator delete function is static, so it can't be virtual. The operator delete function obeys access control, as described in Member-Access Control.




how delete works
The delete operator invokes the function operator delete.

For objects not of class type (class, struct, or union), the global delete operator is invoked. For objects of class type, the name of the deallocation function is resolved in global scope if the delete expression begins with the unary scope resolution operator (::). Otherwise, the delete operator invokes the destructor for an object prior to deallocating memory (if the pointer is not null). The delete operator can be defined on a per-class basis; if there is no such definition for a given class, the global operator delete is invoked. If the delete expression is used to deallocate a class object whose static type has a virtual destructor, the deallocation function is resolved through the virtual destructor of the dynamic type of the object.
