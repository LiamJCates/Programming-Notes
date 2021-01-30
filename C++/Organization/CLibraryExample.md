A tiny C-like library

A library usually starts out as a collection of functions, but if you have used third-party C libraries you know there’s usually more to it than that because there’s more to life than behavior, actions, and functions. There are also characteristics (blue, pounds, texture, luminance), which are represented by data.

When you start to deal with a set of characteristics in C, it is very convenient to clump them together into a struct, especially if you want to represent more than one similar thing in your problem space. Then you can
make a variable of this struct for each thing. Thus, most C libraries have a set of structs and a set of functions that act on those structs.

As an example of what such a system looks like, consider a programming tool that acts like an array, but whose size can be established at runtime, when it is created, called a CStash.

Although it’s written in C++, it has the style of what you’d write in C:

	// An array-like entity created at runtime

	typedef struct CStashTag {
		int size;				// Size of each space
		int quantity;		// Number of storage spaces
		int next;				// Next empty space

		// Dynamically allocated array of bytes:
		unsigned char* storage;
	} CStash;

	void initialize(CStash* s, int size);
	void cleanup(CStash* s);
	int add(CStash\* s, const void* element);
	void\* fetch(CStash* s, int index);
	int count(CStash* s);
	void inflate(CStash* s, int increase);

A tag name like CStashTag is generally used for a struct in case you need to reference the struct inside itself. For example, when creating a linked list (each element in your list contains a pointer to the next element), you need a pointer to the next struct variable, so you need a way to identify the type of that pointer within the struct body. Also, you'll almost universally see the typedef as shown above for every structin a C library. This is done so you can treat the struct as if it were a new type and define variables of that struct
like this:

	CStash A, B, C;

The storage pointer is an unsigned char\*. An unsigned char is the smallest piece of storage a C compiler supports, although on some machines it can be the same size as the largest. It’s implementation dependent, but is often one byte long. You might think that because the CStash is designed to hold any type of variable, a void\* would be more appropriate here. However, the purpose is not to treat this storage as a block of some unknown type, but rather as a block of
contiguous bytes.

The source code for the implementation file (which you may not get if you buy a library commercially – you might get only a compiled obj or lib or dll, etc.) looks like this:

	// Implementation of example C-like library
	// Declare structure and functions:
	#include "CLib.h"
	#include <iostream>
	#include <cassert>
	using namespace std;

	// Quantity of elements to add
	// when increasing storage:
	const int increment = 100;

	void initialize(CStash\* s, int sz)
	{
		s->size = sz;
		s->quantity = 0;
		s->storage = 0;
		s->next = 0;
	}

	int add(CStash\* s, const void\* element)
	{
		if(s->next >= s->quantity) //Enough space left?
			inflate(s, increment);
		// Copy element into storage,
		// starting at next empty space:
		int startBytes = s->next \* s->size;
		unsigned char\* e = (unsigned char\*)element;

		for(int i = 0; i < s->size; i++)
			s->storage[startBytes + i] = e[i];

		s->next++;
		return(s->next - 1); // Index number
	}

	void\* fetch(CStash\* s, int index)
	{
		// Check index boundaries:
		assert(0 <= index);

		if(index >= s->next)
			return 0; // To indicate the end
		// Produce pointer to desired element:
		return &(s->storage[index * s->size]);
	}

	int count(CStash* s)
	{
		return s->next; // Elements in CStash
	}

	void inflate(CStash* s, int increase)
	{
		assert(increase > 0);
		int newQuantity = s->quantity + increase;
		int newBytes = newQuantity * s->size;
		int oldBytes = s->quantity * s->size;
		unsigned char* b = new unsigned char[newBytes];

		for(int i = 0; i < oldBytes; i++)
			b[i] = s->storage[i]; // Copy old to new

		delete [](s->storage); // Old storage
		s->storage = b; // Point to new memory
		s->quantity = newQuantity;
	}

	void cleanup(CStash* s)
	{
		if(s->storage != 0) {
			cout << "freeing storage" << endl;
			delete []s->storage;
		}
	}

initialize() performs the necessary setup for struct CStash by setting the internal variables to appropriate values. Initially, the storage pointer is set to zero – no initial storage is allocated. The add() function inserts an element into the CStash at the next available location. First, it checks to see if there is any available space left. If not, it expands the storage using the inflate() function, described later.

Because the compiler doesn’t know the specific type of the variable
being stored (all the function gets is a void*), you can’t just do an
assignment, which would certainly be the convenient thing.
Instead, you must copy the variable byte-by-byte. The most
straightforward way to perform the copying is with array indexing.
Typically, there are already data bytes in storage, and this is
indicated by the value of next. To start with the right byte offset,
next is multiplied by the size of each element (in bytes) to produce
startBytes. Then the argument element is cast to an unsigned char*
so that it can be addressed byte-by-byte and copied into the
available storagespace. next is incremented so that it indicates the
next available piece of storage, and the “index number” where the
value was stored so that value can be retrieved using this index
number with fetch().
fetch() checks to see that the index isn’t out of bounds and then
returns the address of the desired variable, calculated using the
index argument. Since index indicates the number of elements to

offset into the CStash, it must be multiplied by the number of bytes
occupied by each piece to produce the numerical offset in bytes.
When this offset is used to index into storageusing array indexing,
you don’t get the address, but instead the byte at the address. To
produce the address, you must use the address-of operator &.
count() may look a bit strange at first to a seasoned C programmer.
It seems like a lot of trouble to go through to do something that
would probably be a lot easier to do by hand. If you have a struct
CStashcalled intStash, for example, it would seem much more
straightforward to find out how many elements it has by saying
intStash.nex instead of making a function call (which has t
overhead), such as count(&intStash. However, if you wanted to )
change the internal representation of CStashand thus the way the
count was calculated, the function call interface allows the
necessary flexibility. But alas, most programmers won’t bother to
find out about your “better” design for the library. They’ll look at
the structand grab the next value directly, and possibly even
change next without your permission. If only there were some way
for the library designer to have better control over things like this!
(Yes, that’s foreshadowing.)
Dynamic storage allocation
You never know the maximum amount of storage you might need
for a CStash, so the memory pointed to by storageis allocated from
the heap. The heap is a big block of memory used for allocating
smaller pieces at runtime. You use the heap when you don’t know
the size of the memory you’ll need while you’re writing a program.
That is, only at runtime will you find out that you need space to
hold 200 Airplanevariables instead of 20. In Standard C, dynamicmemory allocation functions include malloc() , calloc() , realloc() ,
and free() . Instead of library calls, however, C++ has a more
sophisticated (albeit simpler to use) approach to dynamic memory
that is integrated into the language via the keywords new and
delete.

The inflate() function uses new to get a bigger chunk of space for
the CStash. In this situation, we will only expand memory and not
shrink it, and the assert() will guarantee that a negative number is
not passed to inflate() as the increasevalue. The new number of
elements that can be held (after inflate() completes) is calculated as
newQuantity, and this is multiplied by the number of bytes per
element to produce newBytes, which will be the number of bytes in
the allocation. So that we know how many bytes to copy over from
the old location, oldBytesis calculated using the old quantity.
The actual storage allocation occurs in the new-expression, which is
the expression involving the new keyword:
new unsigned char[newBytes];
The general form of the new-expression is:
new Type;
in which Type describes the type of variable you want allocated on
the heap. In this case, we want an array of unsigned charthat is
newByteslong, so that is what appears as the Type. You can also
allocate something as simple as an int by saying:
new int;
and although this is rarely done, you can see that the form is
consistent.
A new-expression returns a pointer to an object of the exact type
that you asked for. So if you say new Type, you get back a pointer
to a Type. If you say new int, you get back a pointer to an int. If
you want a new unsigned chararray, you get back a pointer to the
first element of that array. The compiler will ensure that you assign
the return value of the new-expression to a pointer of the correct
type.4: Data Abstraction 241
Of course, any time you request memory it’s possible for the
request to fail, if there is no more memory. As you will learn, C++
has mechanisms that come into play if the memory-allocation
operation is unsuccessful.
Once the new storage is allocated, the data in the old storage must
be copied to the new storage; this is again accomplished with array
indexing, copying one byte at a time in a loop. After the data is
copied, the old storage must be released so that it can be used by
other parts of the program if they need new storage. The delete
keyword is the complement of new, and must be applied to release
any storage that is allocated with new (if you forget to use delete,
that storage remains unavailable, and if this so-called memory leak
happens enough, you’ll run out of memory). In addition, there’s a
special syntax when you’re deleting an array. It’s as if you must
remind the compiler that this pointer is not just pointing to one
object, but to an array of objects: you put a set of empty square
brackets in front of the pointer to be deleted:
delete []myArray;
Once the old storage has been deleted, the pointer to the new
storage can be assigned to the storagepointer, the quantity is
adjusted, and inflate() has completed its job.
Note that the heap manager is fairly primitive. It gives you chunks
of memory and takes them back when you deletethem. There’s no
inherent facility for heap compaction, which compresses the heap to
provide bigger free chunks. If a program allocates and frees heap
storage for a while, you can end up with a fragmented heap that has
lots of memory free, but without any pieces that are big enough to';[p]
allocate the size you’re looking for at the moment. A heap
compactor complicates a program because it moves memory
chunks around, so your pointers won’t retain their proper values.
Some operating environments have heap compaction built in, but
they require you to use special memory handles (which can be
temporarily converted to pointers, after locking the memory so the heap compactor can’t move it) instead of pointers. You can also
build your own heap-compaction scheme, but this is not a task to
be undertaken lightly.
When you create a variable on the stack at compile-time, the
storage for that variable is automatically created and freed by the
compiler. The compiler knows exactly how much storage is needed,
and it knows the lifetime of the variables because of scoping. With
dynamic memory allocation, however, the compiler doesn’t know
how much storage you’re going to need, and it doesn’t know the
lifetime of that storage. That is, the storage doesn’t get cleaned up
automatically. Therefore, you’re responsible for releasing the
storage using delete, which tells the heap manager that storage can
be used by the next call to new. The logical place for this to happen
in the library is in the cleanup() function because that is where all
the closing-up housekeeping is done.
To test the library, two CStashes are created. The first holds ints
and the second holds arrays of 80 chars:
//: C04:CLibTest.cpp
//{L} CLib
// Test the C-like library
#include "CLib.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
int main() {
// Define variables at the beginning
// of the block, as in C:
CStash intStash, stringStash;
int i;
char* cp;
ifstream in;
string line;
const int bufsize = 80;
// Now remember to initialize the variables:4: Data Abstraction 243
initialize(&intStash, sizeof(int));
for(i = 0; i < 100; i++)
add(&intStash, &i);
for(i = 0; i < count(&intStash); i++)
cout << "fetch(&intStash, " << i << ") = "
<< *(int*)fetch(&intStash, i)
<< endl;
// Holds 80-character strings:
initialize(&stringStash, sizeof(char)*bufsize);
in.open("CLibTest.cpp");
assert(in);
while(getline(in, line))
add(&stringStash, line.c_str());
i = 0;
while((cp = (char*)fetch(&stringStash,i++))!=0)
cout << "fetch(&stringStash, " << i << ") = "
<< cp << endl;
cleanup(&intStash);
cleanup(&stringStash);
} ///:~
Following the form required by C, all the variables are created at
the beginning of the scope of main() . Of course, you must
remember to initialize the CStash variables later in the block by
calling initialize( . One of the problems with C libraries is that you )
must carefully convey to the user the importance of the
initialization and cleanup functions. If these functions aren’t called,
there will be a lot of trouble. Unfortunately, the user doesn’t always
wonder if initialization and cleanup are mandatory. They know
what they want to accomplish, and they’re not as concerned about
you jumping up and down saying, “Hey, wait, you have to do this
first!” Some users have even been known to initialize the elements
of a structure themselves. There’s certainly no mechanism in C to
prevent it (more foreshadowing).
The intStash is filled up with integers, and the stringStash is filled
with character arrays. These character arrays are produced by
opening the source code file, CLibTest.cpp, and reading the lines
from it into a string called line, and then producing a pointer to the
character representation of line using the member function c_str().
After each Stash is loaded, it is displayed. The intStash is printed
using a for loop, which uses count() to establish its limit. The
string Stashis printed with a while, which breaks out when fetch()
returns zero to indicate it is out of bounds.
You’ll also notice an additional cast in
cp = (char*)fetch(&stringStash,i++)
This is due to the stricter type checking in C++, which does not
allow you to simply assign a void* to any other type (C allows
this).
Bad guesses
There is one more important issue you should understand before
we look at the general problems in creating a C library. Note that
the CLib.h header file must be included in any file that refers to
CStash because the compiler can’t even guess at what that
structure looks like. However, it can guess at what a function looks
like; this sounds like a feature but it turns out to be a major C
pitfall.
Although you should always declare functions by including a
header file, function declarations aren’t essential in C. It’s possible
in C (but not in C++) to call a function that you haven’t declared. A
good compiler will warn you that you probably ought to declare a
function first, but it isn’t enforced by the C language standard. This
is a dangerous practice, because the C compiler can assume that a
function that you call with an int argument has an argument list
containing int, even if it may actually contain a float. This can
produce bugs that are very difficult to find, as you will see.
Each separate C implementation file (with an extension of .c) is a
translation unit. That is, the compiler is run separately on each
translation unit, and when it is running it is aware of only that unit.
Thus, any information you provide by including header files is
quite important because it determines the compiler’s4: Data Abstraction 245
understanding of the rest of your program. Declarations in header
files are particularly important, because everywhere the header is
included, the compiler will know exactly what to do. If, for
example, you have a declaration in a header file that says void
func(float), the compiler knows that if you call that function with
an integer argument, it should convert the int to a float as it passes
the argument (this is called promotion). Without the declaration, the
C compiler would simply assume that a function func(int) existed,
it wouldn’t do the promotion, and the wrong data would quietly be
passed into func().
For each translation unit, the compiler creates an object file, with an
extension of .o or .obj or something similar. These object files, along
with the necessary start-up code, must be collected by the linker
into the executable program. During linking, all the external
references must be resolved. For example, in CLibTest.cpp,
functions such as initialize( and ) fetch() are declared (that is, the
compiler is told what they look like) and used, but not defined.
They are defined elsewhere, in CLib.cpp. Thus, the calls in
CLib.cpp are external references. The linker must, when it puts all
the object files together, take the unresolved external references and
find the addresses they actually refer to. Those addresses are put
into the executable program to replace the external references.
It’s important to realize that in C, the external references that the
linker searches for are simply function names, generally with an
underscore in front of them. So all the linker has to do is match up
the function name where it is called and the function body in the
object file, and it’s done. If you accidentally made a call that the
compiler interpreted as func(int) and there’s a function body for
func(float) in some other object file, the linker will see _func in one
place and _func in another, and it will think everything’s OK. The
func() at the calling location will push an int onto the stack, and
the func() function body will expect a float to be on the stack. If the
function only reads the value and doesn’t write to it, it won’t blow
up the stack. In fact, the float value it reads off the stack might even make some kind of sense. That’s worse because it’s harder to find
the bug.

What's wrong?
We are remarkably adaptable, even in situations in which perhaps
we shouldn’t adapt. The style of the CStashlibrary has been a staple
for C programmers, but if you look at it for a while, you might
notice that it’s rather . . . awkward. When you use it, you have to
pass the address of the structure to every single function in the
library. When reading the code, the mechanism of the library gets
mixed with the meaning of the function calls, which is confusing
when you’re trying to understand what’s going on.
One of the biggest obstacles, however, to using libraries in C is the
problem of name clashes. C has a single name space for functions;
that is, when the linker looks for a function name, it looks in a
single master list. In addition, when the compiler is working on a
translation unit, it can work only with a single function with a
given name.
Now suppose you decide to buy two libraries from two different
vendors, and each library has a structure that must be initialized
and cleaned up. Both vendors decided that initialize( and )
cleanup() are good names. If you include both their header files in
a single translation unit, what does the C compiler do? Fortunately,
C gives you an error, telling you there’s a type mismatch in the two
different argument lists of the declared functions. But even if you
don’t include them in the same translation unit, the linker will still
have problems. A good linker will detect that there’s a name clash,
but some linkers take the first function name they find, by
searching through the list of object files in the order you give them
in the link list. (This can even be thought of as a feature because it
allows you to replace a library function with your own version.)4: Data Abstraction 247
In either event, you can’t use two C libraries that contain a function
with the identical name. To solve this problem, C library vendors
will often prepend a sequence of unique characters to the beginning
of all their function names. So initialize( and ) cleanup() might
become CStash_initialize( and ) CStash_cleanup( . This is a )
logical thing to do because it “decorates” the name of the structthe
function works on with the name of the function.
Now it’s time to take the first step toward creating classes in C++.
Variable names inside a structdo not clash with global variable
names. So why not take advantage of this for function names, when
those functions operate on a particular struct? That is, why not
make functions members of structs?
