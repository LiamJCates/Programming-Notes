When programming in C, the preprocessor is liberally used to create macros and to substitute values. Because the preprocessor simply does text replacement and has no concept nor facility for type checking, preprocessor value substitution introduces subtle problems that can be avoided in C++ by using const values.

The typical use of the preprocessor to substitute values for names in C looks like this:

#define BUFSIZE 100

BUFSIZE is a name that only exists during preprocessing, therefore it doesn’t occupy storage and can be placed in a header file to provide a single value for all translation units that use it.

This helps us avoid so called magic numbers, see:
[Programming Methods\CodeQuality\MagicNumbers.md]

Most of the time, BUFSIZE will behave like an ordinary variable. In addition, there’s no type information. This can hide bugs that are very difficult to find.

C++ uses const to eliminate these problems by bringing value substitution into the domain of the compiler. Now you can say

const int bufsize = 100;

You can use bufsize any place where the compiler must know the value at compile time.

The compiler can use bufsize to perform constant folding, which means the compiler will reduce a complicated constant expression to a simple one by performing the necessary calculations at compile time.

This is especially important in array definitions:

	char buf[bufsize];

You can use const for all the built-in types (char, int, float, and double) and their variants (as well as class objects, as you’ll see later in this chapter).

Because of subtle bugs that the preprocessor might introduce, you should always use const instead of #define value substitution.



### const in header files

To use const instead of #define, you must be able to place const definitions inside header files as you can with #define.

This way, you can place the definition for a const in a single place and distribute it to translation units by including the header file.


### const linkage

A const in C++ defaults to internal linkage; that is, it is visible only within the file where it is defined and cannot be seen at link time by other translation units.

You must always assign a value to a const when you define it, except when you make an explicit declaration using extern

extern const int bufsize;

Normally, the C++ compiler avoids creating storage for a const, but instead holds the definition in its symbol table.

When you use extern with const, however, you force storage to be allocated (this is also true for certain other cases, such as taking the address of a const).

Storage must be allocated because extern says “use external linkage,” which means that several translation units must be able to refer to the item, which requires it to have storage.

When the const is used, no storage is allocated, it is simply folded in at compile time.

The goal of never allocating storage for a const also fails with complicated structures. Whenever the compiler must allocate storage, constant folding is prevented (since there’s no way for the compiler to know for sure what the value of that storage is – if it could know that, it wouldn’t need to allocate the storage).

Because the compiler cannot always avoid allocating storage for a const, const definitions must default to internal linkage, that is, linkage only within that particular translation unit. Otherwise, linker errors would occur with complicated consts because they cause storage to be allocated in multiple cpp files. The linker would  then see the same definition in multiple object files, and complain. Because a const defaults to internal linkage, the linker doesn’t try to link those definitions across translation units, and there are no collisions. With built-in types, which are used in the majority of cases involving constant expressions, the compiler can always perform constant folding.



### Safety consts

The use of const is not limited to replacing #defines in constant expressions.

If you initialize a variable with a value that is produced at runtime and you know it will not change for the lifetime of that variable, it is good programming practice to make it a const so the compiler will give you an error message if you accidentally try to change it.

Here’s an example:

```cpp
//: C08:Safecons.cpp
// Using const for safety
#include <iostream>
using namespace std;
const int i = 100;		 // Typical constant
const int j = i + 10;	 // Value from const expr
long address = (long)&j; // Forces storage
char buf[j + 10];		 // Still a const expression
int main()
{
	cout << "type a character & CR:";
	const char c = cin.get(); // Can't change
	const char c2 = c + 'a';
	cout << c2;
	// ...
}
```

You can see that i is a compile-time const, but j is calculated from i.

However, because i is a const, the calculated value for j still comes from a constant expression and is itself a compile-time constant.

The very next line requires the address of j and therefore forces the compiler to allocate storage for j. Yet this doesn’t prevent the use of j in the determination of the size of buf because the compiler knows j is const and that the value is valid even if storage was allocated to hold that value at some point in the program.

In main( ), you see a different kind of const in the identifier c because the value cannot be known at compile time. This means storage is required, and the compiler doesn’t attempt to keep anything in its symbol table (the same behavior as in C). The initialization must still happen at the point of definition, and once the initialization occurs, the value cannot be changed.

You can see that c2 is calculated from c and also that scoping works for consts as it does for any other type – yet another improvement over the use of #define.

As a matter of practice, if you think a value shouldn’t change, you should make it a const. This not only provides insurance against inadvertent changes, it also allows the compiler to generate more efficient code by eliminating storage and memory reads.



### Aggregates

It’s possible to use const for aggregates, but you’re virtually assured that the compiler will not be sophisticated enough to keep an aggregate in its symbol table, so storage will be allocated.

In these situations, const means “a piece of storage that cannot be changed.” However, the value cannot be used at compile time because the compiler is not required to know the contents of the storage at compile time.

In the following code, you can see the statements that are illegal:

```cpp
//: C08:Constag.cpp
// Constants and aggregates
const int i[] = {1, 2, 3, 4};
//! float f[i[3]]; // Illegal
struct S
{
	int i, j;
};
const S s[] = {{1, 2}, {3, 4}};
//! double d[s[1].j]; // Illegal
int main() {}
```

In an array definition, the compiler must be able to generate code
that moves the stack pointer to accommodate the array. In both of
the illegal definitions above, the compiler complains because it
cannot find a constant expression in the array definition.

error: array bound is not an integer constant before ‘]’ token
