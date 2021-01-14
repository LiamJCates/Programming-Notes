C++ introduces the nullptr literal to specify a zero-initialized pointer. In portable code, nullptr should be used instead of integral-type zero or macros such as NULL.

The perils of using 0 (or NULL) for null pointers

Note that the value of 0 isn’t a pointer type, so assigning 0 (or NULL, pre-C++11) to a pointer to denote that the pointer is a null pointer is a little inconsistent. In rare cases, when used as a literal argument, it can even cause problems because the compiler can’t tell whether we mean a null pointer or the integer 0:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25

#include <iostream>
#include <cstddef> // for NULL

void print(int x)
{
	std::cout << "print(int): " << x << '\n';
}

void print(int *x)
{
	if (!x)
		std::cout << "print(int*): null\n";
	else
		std::cout << "print(int*): " << *x << '\n';
}

int main()
{
	int *x { NULL };
	print(x); // calls print(int*) because x has type int*
	print(0); // calls print(int) because 0 is an integer literal
	print(NULL); // likely calls print(int), although we probably wanted print(int*)

	return 0;
}

In the likely case where NULL is defined as value 0, print(NULL) will call print(int), not print(int*) like you might expect for a null pointer literal.

nullptr in C++11

To address the above issues, C++11 introduces a new keyword called nullptr. nullptr is a keyword, much like the boolean keywords true and false are.

Starting with C++11, this should be favored instead of 0 when we want a null pointer:

1

int *ptr { nullptr }; // note: ptr is still an integer pointer, just set to a null value

C++ will implicitly convert nullptr to any pointer type. So in the above example, nullptr is implicitly converted to an integer pointer, and then the value of nullptr assigned to ptr. This has the effect of making integer pointer ptr a null pointer.

We can also call a function with a nullptr literal, which will match to any parameter that takes a pointer value:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24

#include <iostream>

void print(int x)
{
	std::cout << "print(int): " << x << '\n';
}

void print(int *x)
{
	if (!x)
		std::cout << "print(int*): null\n";
	else
		std::cout << "print(int*): " << *x << '\n';
}

int main()
{
	int *x { nullptr };
	print(x); // calls print(int*)

	print(nullptr); // calls print(int*) as desired

	return 0;
}

For advanced readers

A function with a different parameter list is a new function, even if a function with the same name exists. We cover this later (Function overloading).

Best practice

Use nullptr to initialize your pointers to a null value.

std::nullptr_t

C++11 also introduces a new type called std::nullptr_t (in header <cstddef>). std::nullptr_t can only hold one value: nullptr! While this may seem kind of silly, it’s useful in one situation. If we want to write a function that accepts only a nullptr argument, what type do we make the parameter? The answer is std::nullptr_t.

1
2
3
4
5
6
7
8
9
10
11
12
13
14

#include <iostream>
#include <cstddef> // for std::nullptr_t

void doSomething(std::nullptr_t ptr)
{
    std::cout << "in doSomething()\n";
}

int main()
{
    doSomething(nullptr); // call doSomething with an argument of type std::nullptr_t

    return 0;
}

You probably won’t ever need to use this, but it’s good to know, just in case.
