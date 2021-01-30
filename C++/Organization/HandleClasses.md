Handle classes
Access control in C++ allows you to separate interface from
implementation, but the implementation hiding is only partial. The
compiler must still see the declarations for all parts of an object in
order to create and manipulate it properly. You could imagine a
programming language that requires only the public interface of an
object and allows the private implementation to be hidden, but C++
performs type checking statically (at compile time) as much as
possible. This means that you’ll learn as early as possible if there’s
an error. It also means that your program is more efficient.
However, including the private implementation has two effects: the
implementation is visible even if you can’t easily access it, and it
can cause needless recompilation.5: Hiding the Implementation 295
Hiding the implementation
Some projects cannot afford to have their implementation visible to
the client programmer. It may show strategic information in a
library header file that the company doesn’t want available to
competitors. You may be working on a system where security is an
issue – an encryption algorithm, for example – and you don’t want
to expose any clues in a header file that might help people to crack
the code. Or you may be putting your library in a “hostile”
environment, where the programmers will directly access the
private components anyway, using pointers and casting. In all
these situations, it’s valuable to have the actual structure compiled
inside an implementation file rather than exposed in a header file.
Reducing recompilation
The project manager in your programming environment will cause
a recompilation of a file if that file is touched (that is, modified) or if
another file it’s dependent upon – that is, an included header file –
is touched. This means that any time you make a change to a class,
whether it’s to the public interface or to the private member
declarations, you’ll force a recompilation of anything that includes
that header file. This is often referred to as the fragile base-class
problem. For a large project in its early stages this can be very
unwieldy because the underlying implementation may change
often; if the project is very big, the time for compiles can prohibit
rapid turnaround.
The technique to solve this is sometimes called handle classes or the
“Cheshire cat”2 – everything about the implementation disappears
except for a single pointer, the “smile.” The pointer refers to a
structure whose definition is in the implementation file along with
all the member function definitions. Thus, as long as the interface is
2 This name is attributed to John Carolan, one of the early pioneers in C++, and of
course, Lewis Carroll. This technique can also be seen as a form of the “bridge”
design pattern, described in Volume 2.296 Thinking in C++ www.BruceEckel.com
unchanged, the header file is untouched. The implementation can
change at will, and only the implementation file needs to be
recompiled and relinked with the project.
Here’s a simple example demonstrating the technique. The header
file contains only the public interface and a single pointer of an
incompletely specified class:
//: C05:Handle.h
// Handle classes
#ifndef HANDLE_H
#define HANDLE_H
class Handle {
struct Cheshire; // Class declaration only
Cheshire* smile;
public:
void initialize();
void cleanup();
int read();
void change(int);
};
#endif // HANDLE_H ///:~
This is all the client programmer is able to see. The line
struct Cheshire;
is an incomplete type specification or a class declaration (A class
definition includes the body of the class.) It tells the compiler that
Cheshireis a structure name, but it doesn’t give any details about
the struct. This is only enough information to create a pointer to the
struct; you can’t create an object until the structure body has been
provided. In this technique, that structure body is hidden away in
the implementation file:
//: C05:Handle.cpp {O}
// Handle implementation
#include "Handle.h"
#include "../require.h"
// Define Handle's implementation:5: Hiding the Implementation 297
struct Handle::Cheshire {
int i;
};
void Handle::initialize() {
smile = new Cheshire;
smile->i = 0;
}
void Handle::cleanup() {
delete smile;
}
int Handle::read() {
return smile->i;
}
void Handle::change(int x) {
smile->i = x;
} ///:~
Cheshireis a nested structure, so it must be defined with scope
resolution:
struct Handle::Cheshire {
In Handle::initialize(, storage is allocated for a ) Cheshire
structure, and in Handle::cleanup( this storage is released. This )
storage is used in lieu of all the data elements you’d normally put
into the privatesection of the class. When you compile Handle.cpp,
this structure definition is hidden away in the object file where no
one can see it. If you change the elements of Cheshire, the only file
that must be recompiled is Handle.cppbecause the header file is
untouched.
The use of Handleis like the use of any class: include the header,
create objects, and send messages.
//: C05:UseHandle.cpp
//{L} Handle
// Use the Handle class
#include "Handle.h"
int main() {
Handle u;
u.initialize();
u.read();
u.change(1);
u.cleanup();
} ///:~
The only thing the client programmer can access is the public
interface, so as long as the implementation is the only thing that
changes, the file above never needs recompilation. Thus, although
this isn’t perfect implementation hiding, it’s a big improvement.
