C++ explicit casts
Casts should be used carefully, because what you are actually
doing is saying to the compiler “Forget type checking – treat it as
this other type instead.” That is, you’re introducing a hole in the
C++ type system and preventing the compiler from telling you that
you’re doing something wrong with a type. What’s worse, the
compiler believes you implicitly and doesn’t perform any other
checking to catch errors. Once you start casting, you open yourself
up for all kinds of problems. In fact, any program that uses a lot of
casts should be viewed with suspicion, no matter how much you
are told it simply “must” be done that way. In general, casts should
be few and isolated to the solution of very specific problems.
Once you understand this and are presented with a buggy
program, your first inclination may be to look for casts as culprits.
But how do you locate C-style casts? They are simply type names
inside of parentheses, and if you start hunting for such things you’ll
discover that it’s often hard to distinguish them from the rest of
your code.
Standard C++ includes an explicit cast syntax that can be used to
completely replace the old C-style casts (of course, C-style casts
cannot be outlawed without breaking code, but compiler writers
could easily flag old-style casts for you). The explicit cast syntax is
such that you can easily find them, as you can see by their names:
static_cast For “well-behaved” and
“reasonably well-behaved” casts,
including things you might now
do without a cast (such as an
automatic type conversion).
const_cast To cast away const and/or
volatile.
reinterpret_cast To cast to a completely different
meaning. The key is that you’ll182 Thinking in C++ www.BruceEckel.com
need to cast back to the original
type to use it safely. The type you
cast to is typically used only for
bit twiddling or some other
mysterious purpose. This is the
most dangerous of all the casts.
dynamic_cast For type-safe downcasting (this
cast will be described in Chapter
15).
The first three explicit casts will be described more completely in
the following sections, while the last one can be demonstrated only
after you’ve learned more, in Chapter 15.
static_cast
A static_castis used for all conversions that are well-defined. These
include “safe” conversions that the compiler would allow you to do
without a cast and less-safe conversions that are nonetheless welldefined. The types of conversions covered by static_castinclude
typical castless conversions, narrowing (information-losing)
conversions, forcing a conversion from a void*, implicit type
conversions, and static navigation of class hierarchies (since you
haven’t seen classes and inheritance yet, this last topic will be
delayed until Chapter 15):
//: C03:static_cast.cpp
void func(int) {}
int main() {
int i = 0x7fff; // Max pos value = 32767
long l;
float f;
// (1) Typical castless conversions:
l = i;
f = i;
// Also works:
l = static_cast<long>(i);
f = static_cast<float>(i);3: The C in C++ 183
// (2) Narrowing conversions:
i = l; // May lose digits
i = f; // May lose info
// Says "I know," eliminates warnings:
i = static_cast<int>(l);
i = static_cast<int>(f);
char c = static_cast<char>(i);
// (3) Forcing a conversion from void* :
void* vp = &i;
// Old way produces a dangerous conversion:
float* fp = (float*)vp;
// The new way is equally dangerous:
fp = static_cast<float*>(vp);
// (4) Implicit type conversions, normally
// performed by the compiler:
double d = 0.0;
int x = d; // Automatic type conversion
x = static_cast<int>(d); // More explicit
func(d); // Automatic type conversion
func(static_cast<int>(d)); // More explicit
} ///:~
In Section (1), you see the kinds of conversions you’re used to
doing in C, with or without a cast. Promoting from an int to a long
or float is not a problem because the latter can always hold every
value that an int can contain. Although it’s unnecessary, you can
use static_castto highlight these promotions.
Converting back the other way is shown in (2). Here, you can lose
data because an int is not as “wide” as a long or a float; it won’t
hold numbers of the same size. Thus these are called narrowing
conversions. The compiler will still perform these, but will often give
you a warning. You can eliminate this warning and indicate that
you really did mean it using a cast.
Assigning from a void* is not allowed without a cast in C++ (unlike
C), as seen in (3). This is dangerous and requires that programmers184 Thinking in C++ www.BruceEckel.com
know what they’re doing. The static_cast, at least, is easier to locate
than the old standard cast when you’re hunting for bugs.
Section (4) of the program shows the kinds of implicit type
conversions that are normally performed automatically by the
compiler. These are automatic and require no casting, but again
static_casthighlights the action in case you want to make it clear
what’s happening or hunt for it later.
const_cast
If you want to convert from a const to a nonconst or from a volatile
to a nonvolatile, you use const_cast. This is the only conversion
allowed with const_cast; if any other conversion is involved it must
be done using a separate expression or you’ll get a compile-time
error.
//: C03:const_cast.cpp
int main() {
const int i = 0;
int* j = (int*)&i; // Deprecated form
j = const_cast<int*>(&i); // Preferred
// Can't do simultaneous additional casting:
//! long* l = const_cast<long*>(&i); // Error
volatile int k = 0;
int* u = const_cast<int*>(&k);
} ///:~
If you take the address of a const object, you produce a pointer to a
const, and this cannot be assigned to a nonconst pointer without a
cast. The old-style cast will accomplish this, but the const_castis
the appropriate one to use. The same holds true for volatile.
reinterpret_cast
This is the least safe of the casting mechanisms, and the one most
likely to produce bugs. A reinterpret_cas pretends that an object is t
just a bit pattern that can be treated (for some dark purpose) as if it
were an entirely different type of object. This is the low-level bit
twiddling that C is notorious for. You’ll virtually always need to3: The C in C++ 185
reinterpret_cas back to the original type (or otherwise treat the t
variable as its original type) before doing anything else with it.
//: C03:reinterpret_cast.cpp
#include <iostream>
using namespace std;
const int sz = 100;
struct X { int a[sz]; };
void print(X* x) {
for(int i = 0; i < sz; i++)
cout << x->a[i] << ' ';
cout << endl << "--------------------" << endl;
}
int main() {
X x;
print(&x);
int* xp = reinterpret_cast<int*>(&x);
for(int* i = xp; i < xp + sz; i++)
*i = 0;
// Can't use xp as an X* at this point
// unless you cast it back:
print(reinterpret_cast<X*>(xp));
// In this example, you can also just use
// the original identifier:
print(&x);
} ///:~
In this simple example, struct Xjust contains an array of int, but
when you create one on the stack as in X x, the values of each of the
ints are garbage (this is shown using the print( )function to display
the contents of the struct). To initialize them, the address of the X is
taken and cast to an int pointer, which is then walked through the
array to set each int to zero. Notice how the upper bound for i is
calculated by “adding” sz to xp; the compiler knows that you
actually want sz pointer locations greater than xp and it does the
correct pointer arithmetic for you.
The idea of reinterpret_cas is that when you use it, what you get is t
so foreign that it cannot be used for the type’s original purpose186 Thinking in C++ www.BruceEckel.com
unless you cast it back. Here, we see the cast back to an X* in the
call to print, but of course since you still have the original identifier
you can also use that. But the xp is only useful as an int*, which is
truly a “reinterpretation” of the original X.
A reinterpret_cas often indicates inadvisable and/or nonportable t
programming, but it’s available when you decide you have to use
it.
