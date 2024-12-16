## Passing by Address

Passing an argument by address involves passing a pointer that typically acts as the address of the argument variable rather than the argument variable itself. When you pass a pointer to a function, the pointer’s value (the address it points to) is copied from the argument to the function’s parameter. In other words, this is simply a case of passed by value!

If the function parameter is then dereferenced and the value accessed or altered, this will impact the value the argument is pointing to in the caller's environment, since both the function parameter and argument are pointing to the same value!

As the address is pass by value, if you change the function parameter’s value, you are only changing a copy, the original pointer argument will not be changed. After changing the function parameter’s address, the function parameter and argument will point to different values, so dereferencing the parameter and changing the value will no longer affect the value pointed to by the argument.

As the parameter is a pointer, some special consideration must be given:
	We must ensure parameters passed by address are not null pointers before dereferencing them. Dereferencing a NULL pointer is undefined behavior from the language standpoint, such operation is well defined in compilers for targets which have memory at corresponding address. In this case, the result of such operation consists in simply reading the memory at address 0 which is a segmentation fault.

The next logical question is, “What if we want to change the address an argument points to from within the function?”. Turns out, this is surprisingly easy. You can simply pass the address by reference. The syntax for doing a reference to a pointer is a little strange (and easy to get backwards). However, if you do get it backwards, the compiler will give you an error:

  type *& variableName




### const

const type qualification effects pointers in two ways:

	const int * intPtr1; // Declares a pointer whose contents cannot be changed.
	int * const intPtr2; // Declares a pointer that cannot be changed.

Parameter Cases:

Making the pointed value const means that the pointer cannot be used to alter the value at the pointer's address.

void someFunc1(const int * arg) {
	int i = 9;
	*arg = i; // <- compiler error as pointed value is const
}

Making the pointer const means that the pointer cannot be altered within the method, however, as the pointer was passed by value, this is declaration is only relevant in the context of the pointer value within the function.

void someFunc1(int * const arg) {
	int i = 9;
	arg = &i; // <- compiler error as pointer is const
}

We can combine the two modes of const-ness to prevent both of the cases:

void someFunc1(const int * const arg) {
    int i = 9;
    *arg = i; // <- compiler error as pointed value is const
    arg = &i; // <- compiler error as pointer is const
}


NOTE
The following const is unnecessary, there's no reason to put it in a function declaration:

void someFunc1(int * const arg);

However, you might want to put it in the function implementation, for the same reason that you might want to declare a local variable (or anything else) const - the implementation may be easier to follow when you know that certain things won't change. You can do that whether or not it's declared const in any forward declarations of the function.

However, its a good practice to declare values as const in forward declarations as this will not only increase readability but also the caller will be aware of the contract and have more confidence regarding immutability of arguments.



### Pros and cons of pass by address

Advantages of passing by address:

    Pass by address allows a function to change the value of the argument, which is sometimes useful. Otherwise, const can be used to guarantee the function won’t change the argument. (However, if you want to do this with a non-pointer, you should use pass by reference instead).
    Because a copy of the argument is not made, it is fast, even when used with large structs or classes.
    We can return multiple values from a function via out parameters.

Disadvantages of passing by address:

    Because literals (excepting C-style string literals) and expressions do not have addresses, pointer arguments must be normal variables.
    All values must be checked to see whether they are null. Trying to dereference a null value will result in a crash. It is easy to forget to do this.
    Because dereferencing a pointer is slower than accessing a value directly, accessing arguments passed by address is slower than accessing arguments passed by value.

When to use pass by address:

    When passing built-in arrays (if you’re okay with the fact that they’ll decay into a pointer).
    When passing a pointer and nullptr is a valid argument logically.

When not to use pass by address:

    When passing a pointer and nullptr is not a valid argument logically (use pass by reference).
    When passing structs or classes (use pass by reference).
    When passing fundamental types (use pass by value).

As you can see, pass by address and pass by reference have almost identical advantages and disadvantages. Because pass by reference is generally safer than pass by address, pass by reference should be preferred in most cases.

Rule

Prefer pass by reference to pass by address whenever applicable.
