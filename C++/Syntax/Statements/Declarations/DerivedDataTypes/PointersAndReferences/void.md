### Void Pointer
You can also specify a pointer to a block of memory (called a void pointer):

  void* voidPointer;

The void type of pointer is a special type of pointer. In C++, void represents the absence of type. Therefore, void pointers are pointers that point to a value that has no type (and thus also an undetermined length and undetermined dereferencing properties).

This gives void pointers a great flexibility, by being able to point to any data type, from an integer value or a float to a string of characters. In exchange, they have a great limitation: the data pointed to by them cannot be directly dereferenced (which is logical, since we have no type to dereference to), and for that reason, any address in a void pointer needs to be transformed into some other pointer type that points to a concrete data type before being dereferenced.

One of its possible uses may be to pass generic parameters to a function.










Void pointers
By Alex on July 19th, 2007 | last modified by Alex on December 21st, 2020

The void pointer, also known as the generic pointer, is a special type of pointer that can be pointed at objects of any data type! A void pointer is declared like a normal pointer, using the void keyword as the pointer’s type:

1

void *ptr; // ptr is a void pointer

A void pointer can point to objects of any data type:

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

int nValue;
float fValue;

struct Something
{
    int n;
    float f;
};

Something sValue;

void *ptr;
ptr = &nValue; // valid
ptr = &fValue; // valid
ptr = &sValue; // valid

However, because the void pointer does not know what type of object it is pointing to, direct indirection through it is not possible! Rather, the void pointer must first be explicitly cast to another pointer type before indirecting through the new pointer.

1
2
3
4
5
6
7
8

int value{ 5 };
void *voidPtr{ &value };

// std::cout << *voidPtr << '\n'; // illegal: Indirection through a void pointer

int *intPtr{ static_cast<int*>(voidPtr) }; // however, if we cast our void pointer to an int pointer...

std::cout << *intPtr << '\n'; // then we can use indirection through it like normal

This prints:

5

The next obvious question is: If a void pointer doesn’t know what it’s pointing to, how do we know what to cast it to? Ultimately, that is up to you to keep track of.

Here’s an example of a void pointer in use:

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
26
27
28
29
30
31
32
33
34
35
36
37
38
39

#include <iostream>

enum class Type
{
    INT,
    FLOAT,
    CSTRING
};

void printValue(void *ptr, Type type)
{
    switch (type)
    {
        case Type::INT:
            std::cout << *static_cast<int*>(ptr) << '\n'; // cast to int pointer and perform indirection
            break;
        case Type::FLOAT:
            std::cout << *static_cast<float*>(ptr) << '\n'; // cast to float pointer and perform indirection
            break;
        case Type::CSTRING:
            std::cout << static_cast<char*>(ptr) << '\n'; // cast to char pointer (no indirection)
            // std::cout knows to treat char* as a C-style string
            // if we were to perform indirection through the result, then we'd just print the single char that ptr is pointing to
            break;
    }
}

int main()
{
    int nValue{ 5 };
    float fValue{ 7.5f };
    char szValue[]{ "Mollie" };

    printValue(&nValue, Type::INT);
    printValue(&fValue, Type::FLOAT);
    printValue(szValue, Type::CSTRING);

    return 0;
}

This program prints:

5
7.5
Mollie

Void pointer miscellany

Void pointers can be set to a null value:

1

void *ptr{ nullptr }; // ptr is a void pointer that is currently a null pointer

Although some compilers allow deleting a void pointer that points to dynamically allocated memory, doing so should be avoided, as it can result in undefined behavior.

It is not possible to do pointer arithmetic on a void pointer. This is because pointer arithmetic requires the pointer to know what size object it is pointing to, so it can increment or decrement the pointer appropriately.

Note that there is no such thing as a void reference. This is because a void reference would be of type void &, and would not know what type of value it referenced.

Conclusion

In general, it is a good idea to avoid using void pointers unless absolutely necessary, as they effectively allow you to avoid type checking. This allows you to inadvertently do things that make no sense, and the compiler won’t complain about it. For example, the following would be valid:

1
2

    int nValue{ 5 };
    printValue(&nValue, Type::CSTRING);

But who knows what the result would actually be!

Although the above function seems like a neat way to make a single function handle multiple data types, C++ actually offers a much better way to do the same thing (via function overloading) that retains type checking to help prevent misuse. Many other places where void pointers would once be used to handle multiple data types are now better done using templates, which also offer strong type checking.

However, very occasionally, you may still find a reasonable use for the void pointer. Just make sure there isn’t a better (safer) way to do the same thing using other language mechanisms first!
