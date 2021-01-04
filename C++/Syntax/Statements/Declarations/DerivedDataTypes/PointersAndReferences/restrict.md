restrict  
A pointer qualified by restrict is initially the only means by which the object it points to can be accessed. Only C99 adds a new type qualifier called restrict.

The restrict keyword can be considered an extension to the strict aliasing rule. It allows the programmer to declare that pointers which share the same type (or were otherwise validly created) do not alias eachother. By using restrict the programmer can declare that any loads and stores through the qualified pointer (or through another pointer copied either directly or indirectly from the restricted pointer) are the only loads and stores to the same address during the lifetime of the pointer. In other words, the pointer is not aliased by any pointers other than its own copies.

Restrict is a "no data hazards will be generated" contract between the programmer and the compiler. The compiler relies on this information to make optimizations. If the data is, in fact, aliased, the results are undefined and a programmer should not expect the compiler to output a warning. The compiler assumes the programmer is not lying.

The restrict keyword is a type qualifier for pointers and is a formal part of the C99 standard.

Example usage:

int* restrict foo;
Notice that the restrict keyword qualifies the pointer and not the object being pointed to.
Not all compilers are compliant with the C99 standard. For example Microsoft's compiler, does not support the C99 standard at all. If you are using MSVC on a x86 platform you will not have access to this critical optimization option.
When using GCC, remember to enable the C99 standard by adding -std=c99 to your compilation flags. In code that cannot be compiled with C99, use either __restrict or __restrict__ to enable the keyword as a GCC extension.
The restrict keyword was not included as part of the C++98 standard. However some C++ compilers may support it as an extension. It's important that when restrict is used in C++ to remember that the implicit this pointer should also be restricted. Consult your compiler's manual for how to do this, if possible. 
