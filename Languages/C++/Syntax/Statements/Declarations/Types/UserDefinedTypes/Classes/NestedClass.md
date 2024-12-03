Nested Class

A class within another class is called a nested class.

Compelling reasons for using nested classes include the following:

1. It is a way of logically grouping classes that are only used in one place: 	

	If a class is useful to only one other class, then it is logical to embed it in that class and keep the two together. Nesting such "helper classes" makes their package more streamlined.

2. It increases encapsulation:

	Consider two top-level classes, A and B, where B needs access to members of A that would otherwise be declared private. By hiding class B within class A, A's members can be declared private and B can access them. In addition, B itself can be hidden from the outside world.

3. It can lead to more readable and maintainable code:

	Nesting small classes within top-level classes places the code closer to where it is used. A nested class has an independent set of modifiers from the outer class. Visibility modifiers (public, private and protected) effect whether the nested class definition is accessible beyond the outer class definition. For example, a private nested class can be used by the outer class, but by no other classes.


Nested friends

Making a structure nested doesn’t automatically give it access to
privatemembers. To accomplish this, you must follow a particular
form: first, declare (without defining) the nested structure, then
declare it as a friend, and finally define the structure. The structure
definition must be separate from the frienddeclaration, otherwise
it would be seen by the compiler as a non-member. Here’s an
example:
//: C05:NestFriend.cpp
// Nested friends
#include <iostream>
#include <cstring> // memset()
using namespace std;
const int sz = 20;
struct Holder {
private:
int a[sz];
public:
void initialize();
struct Pointer;
friend Pointer;
struct Pointer {
private:
Holder* h;
int* p;
public:
void initialize(Holder* h);
// Move around in the array:
void next();
void previous();
void top();
void end();
// Access values:
int read();
void set(int i);
};
};
void Holder::initialize() {
memset(a, 0, sz * sizeof(int));
}
void Holder::Pointer::initialize(Holder* rv) {
h = rv;
p = rv->a;
}
void Holder::Pointer::next() {
if(p < &(h->a[sz - 1])) p++;
}
void Holder::Pointer::previous() {
if(p > &(h->a[0])) p--;
}
void Holder::Pointer::top() {
p = &(h->a[0]);
}
void Holder::Pointer::end() {
p = &(h->a[sz - 1]);
}
int Holder::Pointer::read() {
return *p;
}
void Holder::Pointer::set(int i) {
*p = i;
}
int main() {
Holder h;
Holder::Pointer hp, hp2;
int i;
h.initialize();
hp.initialize(&h);
hp2.initialize(&h);
for(i = 0; i < sz; i++) {
hp.set(i);
hp.next();
}
hp.top();
hp2.end();
for(i = 0; i < sz; i++) {
cout << "hp = " << hp.read()
<< ", hp2 = " << hp2.read() << endl;
hp.next();
hp2.previous();
}
} ///:~

Once Pointeris declared, it is granted access to the private
members of Holderby saying:

friend Pointer;

The struct Holder contains an array of ints and the Pointer allows
you to access them. Because Pointer is strongly associated with
Holder, it’s sensible to make it a member structure of Holder. But
because Pointer is a separate class from Holder, you can make
more than one of them in main( )and use them to select different
parts of the array. Pointer is a structure instead of a raw C pointer,
so you can guarantee that it will always safely point inside the
Holder.
The Standard C library function memset( )(in <cstring>) is used
for convenience in the program above. It sets all memory starting at
a particular address (the first argument) to a particular value (the
second argument) for n bytes past the starting address (n is the
third argument). Of course, you could have simply used a loop to
iterate through all the memory, but memset( )is available, welltested (so it’s less likely you’ll introduce an error), and probably
more efficient than if you coded it by hand.
