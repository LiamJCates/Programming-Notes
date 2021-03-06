reinterpret_cast

https://en.cppreference.com/w/cpp/language/reinterpret_cast

reinterpret_cast converts any pointer type to any other pointer type, even of unrelated classes. The operation result is a simple binary copy of the value from one pointer to the other. All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked.

It can also cast pointers to or from integer types. The format in which this integer value represents a pointer is platform-specific. The only guarantee is that a pointer cast to an integer type large enough to fully contain it (such as intptr_t), is guaranteed to be able to be cast back to a valid pointer.

The conversions that can be performed by reinterpret_cast but not by static_cast are low-level operations based on reinterpreting the binary representations of the types, which on most cases results in code which is system-specific, and thus non-portable. For example:

class A { /* ... */ };
class B { /* ... */ };
A * a = new A;
B * b = reinterpret_cast<B*>(a);




This code compiles, although it does not make much sense, since now b points to an object of a totally unrelated and likely incompatible class. Dereferencing b is unsafe.











reinterpret_cast, for casts between unrelated types such as a pointer type and an int.

Note

This cast operator is not used as often as the others, and it's not guaranteed to be portable to other compilers.

The following example illustrates how reinterpret_cast differs from static_cast.
C++

const char* str = "hello";
int i = static_cast<int>(str);//error C2440: 'static_cast' : cannot
                              // convert from 'const char *' to 'int'
int j = (int)str; // C-style cast. Did the programmer really intend
                  // to do this?
int k = reinterpret_cast<int>(str);// Programming intent is clear.
                                   // However, it is not 64-bit safe.














reinterpret_cast
Sometimes in low-level programming, you must perform type conversions that are not well defined. In system programming and especially in
embedded environments, you often need complete control over how to
interpret memory. The reinterpret_cast gives you such control, but ensuring the correctness of these conversions is entirely your responsibility.
Suppose your embedded device keeps an unsigned long timer at memory
address 0x1000. You could use reinterpret_cast to read from the timer, as
demonstrated in Listing 6-5.
#include <cstdio>
int main() {
auto timer = reinterpret_castu<const unsigned long*v>(0x1000w);
printf("Timer is %lu.", *timer);
}
Listing 6-5: A program using reinterpret_cast. This program will compile, but you should
expect a runtime crash unless 0x1000 is readable.

The reinterpret_cast u takes a type parameter corresponding to the
desired pointer type v and the memory address the result should point to w.
Of course, the compiler has no idea whether the memory at address
0x1000 contains an unsigned long. It’s entirely up to you to ensure correctness. Because you’re taking full responsibility for this very dangerous construction, the compiler forces you to employ reinterpret_cast. You couldn’t,
for example, replace the initialization of timer with the following line:
const unsigned long* timer{ 0x1000 };
The compiler will grumble about converting an int to a pointer.



















Allows any pointer to be converted into any other pointer type. Also allows any integral type to be converted into any pointer type and vice versa.
Syntax

reinterpret_cast < type-id > ( expression )

Remarks

Misuse of the reinterpret_cast operator can easily be unsafe. Unless the desired conversion is inherently low-level, you should use one of the other cast operators.

The reinterpret_cast operator can be used for conversions such as char* to int*, or One_class* to Unrelated_class*, which are inherently unsafe.

The result of a reinterpret_cast cannot safely be used for anything other than being cast back to its original type. Other uses are, at best, nonportable.

The reinterpret_cast operator cannot cast away the const, volatile, or __unaligned attributes. See const_cast Operator for information on removing these attributes.

The reinterpret_cast operator converts a null pointer value to the null pointer value of the destination type.

One practical use of reinterpret_cast is in a hash function, which maps a value to an index in such a way that two distinct values rarely end up with the same index.
C++

#include <iostream>
using namespace std;

// Returns a hash code based on an address
unsigned short Hash( void *p ) {
   unsigned int val = reinterpret_cast<unsigned int>( p );
   return ( unsigned short )( val ^ (val >> 16));
}

using namespace std;
int main() {
   int a[20];
   for ( int i = 0; i < 20; i++ )
      cout << Hash( a + i ) << endl;
}

Output:
64641
64645
64889
64893
64881
64885
64873
64877
64865
64869
64857
64861
64849
64853
64841
64845
64833
64837
64825
64829

The reinterpret_cast allows the pointer to be treated as an integral type. The result is then bit-shifted and XORed with itself to produce a unique index (unique to a high degree of probability). The index is then truncated by a standard C-style cast to the return type of the function.
