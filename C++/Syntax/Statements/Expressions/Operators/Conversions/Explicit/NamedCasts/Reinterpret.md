reinterpret_cast

reinterpret_cast converts any pointer type to any other pointer type, even of unrelated classes. The operation result is a simple binary copy of the value from one pointer to the other. All pointer conversions are allowed: neither the content pointed nor the pointer type itself is checked.

It can also cast pointers to or from integer types. The format in which this integer value represents a pointer is platform-specific. The only guarantee is that a pointer cast to an integer type large enough to fully contain it (such as intptr_t), is guaranteed to be able to be cast back to a valid pointer.

The conversions that can be performed by reinterpret_cast but not by static_cast are low-level operations based on reinterpreting the binary representations of the types, which on most cases results in code which is system-specific, and thus non-portable. For example:

1
2
3
4



class A { /* ... */ };
class B { /* ... */ };
A * a = new A;
B * b = reinterpret_cast<B*>(a);




This code compiles, although it does not make much sense, since now b points to an object of a totally unrelated and likely incompatible class. Dereferencing b is unsafe.






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
