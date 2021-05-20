## Type Qualifiers
Type qualifiers give one of two properties to an identifier. The const type qualifier declares an object to be nonmodifiable. The volatile type qualifier declares an item whose value can legitimately be changed by something beyond the control of the program in which it appears, such as a concurrently executing thread.

The type qualifiers, const, restrict, and volatile, can appear only once in a declaration. Type qualifiers can appear with any type specifier; however, they can't appear after the first comma in a multiple item declaration. For example, the following declarations are legal:

```cpp
typedef volatile int VI;
const int ci;
```

These declarations aren't legal:

```cpp
typedef int * i, volatile * vi;
float f, const cf;
```

NOTE
Type qualifiers are relevant only when accessing identifiers as l-values in expressions.

TODO:
https://en.cppreference.com/w/cpp/language/cv


### const and volatile

The following are legal const and volatile declarations:

```cpp
int const *p_ci;      // Pointer to constant int
int const (*p_ci);   // Pointer to constant int
int *const cp_i;     // Constant pointer to int
int (*const cp_i);   // Constant pointer to int
int volatile vint;     // Volatile integer
```

If the specification of an array type includes type qualifiers, the element is qualified, not the array type. If the specification of the function type includes qualifiers, the behavior is undefined. volatile and const don't affect the range of values or arithmetic properties of the object.

	The const keyword can be used to modify any fundamental or aggregate type, or a pointer to an object of any type, or a typedef. If an item is declared with only the const type qualifier, its type is taken to be const int. A const variable can be initialized or can be placed in a read-only region of storage. The const keyword is useful for declaring pointers to const since this requires the function not to change the pointer in any way.

	The compiler assumes that, at any point in the program, a volatile variable can be accessed by an unknown process that uses or modifies its value. Regardless of the optimizations specified on the command line, the code for each assignment to or reference of a volatile variable must be generated even if it appears to have no effect.

If volatile is used alone, int is assumed. The volatile type specifier can be used to provide reliable access to special memory locations. Use volatile with data objects that may be accessed or altered by signal handlers, by concurrently executing programs, or by special hardware such as memory-mapped I/O control registers. You can declare a variable as volatile for its lifetime, or you can cast a single reference to be volatile.

    An item can be both const and volatile, in which case the item couldn't be legitimately modified by its own program, but could be modified by some asynchronous process.



### restrict

The restrict type qualifier, introduced in C99, can be applied to pointer declarations. It qualifies the pointer, not what it points at.

restrict is an optimization hint to the compiler that no other pointer in the current scope refers to the same memory location. That is, only the pointer or a value derived from it (such as pointer + 1) is used to access the object during the lifetime of the pointer. This helps the compiler produce more optimized code. C++ has an equivalent mechanism, __restrict

Keep in mind that restrict is a contract between you and the compiler. If you do alias a pointer marked with restrict, the result is undefined.

Here's an example that uses restrict:

```cpp
void test(int *restrict first, int *restrict second, int *val)
{
    *first += *val;
    *second += *val;
}

int main()
{
    int i = 1, j = 2, k = 3;
    test(&i, &j, &k);

    return 0;
}

// Marking union members restrict tells the compiler that
// only z.x or z.y will be accessed in any scope, which allows
// the compiler to optimize access to the members.
union z
{
    int* restrict x;
    double* restrict y;
};
```
