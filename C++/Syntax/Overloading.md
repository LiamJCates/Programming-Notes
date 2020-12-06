C++ Programming Ch 13 for more Examples



## C++ Overloading (Operator and Function)
C++ allows you to specify more than one definition for a function name or an operator in the same scope, which is called function overloading and operator overloading respectively.

An overloaded declaration is a declaration that is declared with the same name as a previously declared declaration in the same scope, except that both declarations have different arguments and obviously different definition (implementation).

When you call an overloaded function or operator, the compiler determines the most appropriate definition to use, by comparing the argument types you have used to call the function or operator with the parameter types specified in the definitions. The process of selecting the most appropriate overloaded function or operator is called overload resolution.







## Function Overloading

You can have multiple definitions for the same function name in the same scope. The definition of the function must differ from each other by the types and/or the number of arguments in the argument list. You cannot overload function declarations that differ only by return type.








### Operator Overloading
For each fundamental type, some portion of the operators will be available.

For user-defined types, you can specify custom behavior for these operators by employing operator overloading. To specify behavior for an operator in a user-defined class, simply name the method with the word operator immediately followed by the operator; ensure that the return types and parameters match the types of the operands you want to deal with.

You can redefine or overload most of the built-in operators available in C++. Thus, a programmer can use operators with user-defined types as well.

Overloaded operators are functions with special names: the keyword "operator" followed by the symbol for the operator being defined. Like any other function, an overloaded operator has a return type and a parameter list.

An operator declaration looks quite like a
function declaration:
return_type operator operator_symbol (...parameter list...);

The operator_symbol in this case could be any of the several operator types that the
programmer can define. It could be + (addition) or && (logical AND) and so on.


When overloading an operator, keep the following in mind:
1. You cannot change the precedence of an operator.
2. The associativity cannot be changed. (For example, the associativity of
the arithmetic operator addition is from left to right, and it cannot be
changed.)
3. Default parameters cannot be used with an overloaded operator.
4. You cannot change the number of parameters an operator takes.
5. You cannot create new operators. Only existing operators can be
overloaded.
6. The operators that cannot be overloaded are:
. .* :: ?: sizeof
7. The meaning of how an operator works with built-in types, such as
int, remains the same. That is, you cannot redefine how operators
work with built-in data types.
8. Operators can be overloaded either for objects of the user-defined
types, or for a combination of objects of the user-defined type and
objects of the built-in type.



Overloadable/Non-overloadable Operators

Following is the list of operators which can be overloaded −
+ 	- 	* 	/ 	% 	^
& 	| 	~ 	! 	, 	=
< 	> 	<= 	>= 	++ 	--
<< 	>> 	== 	!= 	&& 	||
+= 	-= 	/= 	%= 	^= 	&=
|= 	*= 	<<= 	>>= 	[] 	()
-> 	->* 	new 	new [] 	delete 	delete []

Following is the list of operators, which can not be overloaded −
:: 	.* 	. 	?:



On a broad level, operators in C++ can be classified into two types: unary operators and
binary operators.

Unary Operators
operators that function on a single operand are called unary
operators. A unary operator that is implemented in the global namespace or as a static
member function of a class uses the following structure:
return_type operator operator_type (parameter_type)
{
// ... implementation
}
A unary operator that is a (non-static) member of a class has a similar structure but is
lacking in parameters, because the single parameter that it works upon is the instance of
the class itself (*this):
return_type operator operator_type ()
{
// ... implementation
}

Unary Operators

| Symbol | Name |
|--------|------|
| ++ | Increment |
| -- | Decrement |
| * | Pointer dereference |
| -> | Member selection |
| ! | Logical NOT |
| & | Address-of |
| ~ | One’s complement |
| + | Unary plus |
| - | Unary negation |



Example
A unary prefix increment operator (++) can be programmed using the following syntax
within the class declaration:
// Unary increment operator (prefix)
Date& operator ++ ()
{
// operator implementation code
return *this;
}

The postfix increment operator (++), on the other hand, has a different return type and an
input parameter (that is not always used):
Date operator ++ (int)
{
// Store a copy of the current state of the object, before incrementing day
Date copy (*this);
// increment implementation code
// Return state before increment (because, postfix)
return copy;
}


The prefix and postfix decrement operators have a similar syntax as the increment
operators, just that the declaration would contain a -- where you see a ++.

As the implementation of the postfix operators demonstrates, a
copy containing the existing state of the object is created before
the increment or decrement operation to be returned thereafter.
In other words, if you had the choice between using ++ object;
and object ++; to essentially only increment, you should
choose the former to avoid the creation of a temporary copy that
will not be used.






Binary Operators
Operators that function on two operands are called binary operators. The definition of
a binary operator implemented as a global function or a static member function is the
following:
return_type operator_type (parameter1, parameter2);
The definition of a binary operator implemented as a class member is
return_type operator_type (parameter);
The reason the class member version of a binary operator accepts only one parameter is
that the second parameter is usually derived from the attributes of the class itself.


Overloadable Binary Operators
| Symbol | Name |
|--------|------| |
| , | Comma |
| != | Inequality |
| % | Modulus |
| %= | Modulus/assignment |
| & | Bitwise AND |
| && | Logical AND |
| &= | Bitwise AND/assignment |
| * | Multiplication |
| *= | Multiplication/assignment |
| + | Addition |
| += | Addition/assignment |
| - | Subtraction |
| -= | Subtraction/assignment |
| ->* | Pointer-to-member selection |
| / | Division |
| /= | Division/assignment |
| < | Less than |
| << | Left shift |
| <<= | Left shift/assignment |
| <= | Less than or equal to |
| = | Assignment, Copy Assignment and Move Assignment |
| == | Equality |
| \> | Greater than |
| \>= | Greater than or equal to |
| \>> | Right shift |
| \>>= | Right shift/assignment |
| ^ | Exclusive OR |
| ^= | Exclusive OR/assignment |
| | | Bitwise inclusive OR |
| |= | Bitwise inclusive OR/assignment |
| || | Logical OR |
| [] | Subscript operator |




Operator Overloading Examples

Here are various operator overloading examples to help you in understanding the concept.

Unary Operators Overloading
https://www.tutorialspoint.com/cplusplus/unary_operators_overloading.htm

Binary Operators Overloading
https://www.tutorialspoint.com/cplusplus/binary_operators_overloading.htm

Relational Operators Overloading
https://www.tutorialspoint.com/cplusplus/relational_operators_overloading.htm

Input/Output Operators Overloading
https://www.tutorialspoint.com/cplusplus/input_output_operators_overloading.htm

++ and -- Operators Overloading
https://www.tutorialspoint.com/cplusplus/increment_decrement_operators_overloading.htm

Assignment/Copy Operators Overloading
https://www.tutorialspoint.com/cplusplus/assignment_operators_overloading.htm

Function call () Operator Overloading
https://www.tutorialspoint.com/cplusplus/function_call_operator_overloading.htm

Subscripting [] Operator Overloading
https://www.tutorialspoint.com/cplusplus/subscripting_operator_overloading.htm

Class Member Access Operator -> Overloading
https://www.tutorialspoint.com/cplusplus/class_member_access_operator_overloading.htm



Casting Operators
Casting is a mechanism by which the programmer can temporarily or
permanently change the interpretation of an object by the compiler.
Note that this does not imply that the programmer changes the object
itself—he simply changes the interpretation thereof. Operators that
change the interpretation of an object are called casting operators.







Overloading Operator new
allocate objects with dynamic storage duration using operator new. By default, operator new will allocate memory on the
free store to make space for your dynamic objects. The free store, also known
as the heap, is an implementation-defined storage location. On desktop operating systems, the kernel usually manages the free store and is generally vast.

Free Store Availability
In some environments, like the Windows kernel or embedded systems,
there is no free store available to you by default. In other settings, such as
game development or high-frequency trading, free store allocations simply
involve too much latency, because you’ve delegated its management to the
operating system.
You could try to avoid using the free store entirely, but this is severely
limiting. One major limitation this would introduce is to preclude the use
of stdlib containers, which after reading Part II you’ll agree is a major loss.
Rather than settling for these severe restrictions, you can overload the free
store operations and take control over allocations. You do this by overloading operator new.


The <new> Header
In environments that support free store operations, the <new> header contains the following four operators:
•	 void* operator new(size_t);
•	 void operator delete(void*);
•	 void* operator new[](size_t);
•	 void operator delete[](void*);

Notice that the return type of operator new is void*. The free store operators deal in raw, uninitialized memory.
It’s possible to provide your own versions of these four operators. All
you do is define them once in your program. The compiler will use your
versions rather than the defaults.
Free store management is a surprisingly complicated task. One of the
major issues is memory fragmentation. Over time, large numbers of memory
allocations and releases can leave free blocks of memory scattered throughout
the region dedicated for the free store. It’s possible to get into situations where
there is plenty of free memory, but it’s scattered across allocated memory.
When this happens, large requests for memory will fail, even though there is
technically enough free memory to provide to the requester. Figure 7-1 illustrates such a situation. There is plenty of memory for the desired allocation,
but the available memory is noncontiguous.

Buckets
One approach is to chop allocated memory into so-called buckets of a fixed
size. When you request memory, the environment allocates a whole bucket,
even if you didn’t request all the memory. For example, Windows provides
two functions for allocating dynamic memory: VirtualAllocEx and HeapAlloc.
The VirtualAllocEx function is low level, which allows you to provide many
options, such as which process to allocate memory into, the preferred memory address, the requested size, and permissions, like whether the memory
should be readable, writable, and executable. This function will never allocate fewer than 4096 bytes (a so-called page).
On the other hand, HeapAlloc is a higher-level function that hands
out less than a page of memory when it can; otherwise, it will invoke
VirtualAllocEx on your behalf. At least with the Visual Studio compiler,
new will call HeapAlloc by default.
This arrangement prevents memory fragmentation in exchange for
some overhead associated with rounding up allocations to bucket size.
Modern operating systems like Windows will have fairly complex schemes
for allocating memory of different sizes. You don’t see any of this complexity unless you want to take control.
Taking Control of the Free Store
Listing 7-4 demonstrates implementing very simple Bucket and Heap classes.
These will facilitate taking control over dynamic memory allocation:
#include <cstddef>
#include <new>
struct Bucket {
const static size_t data_size{ 4096 };
std::byte data[data_size];
};
struct Heap {
void* allocate(size_t bytes) {
if (bytes > Bucket::data_size) throw std::bad_alloc{};
for (size_t i{}; i < n_heap_buckets; i++) {
if (!bucket_used[i]) {
bucket_used[i] = true;
return buckets[i].data;
}
}
throw std::bad_alloc{};
}
void free(void* p) {
for (size_t i{}; i < n_heap_buckets; i++) {
if (buckets[i].data == p) {
bucket_used[i] = false;
return;
}
}
}
static const size_t n_heap_buckets{ 10 };
Bucket buckets[n_heap_buckets]{};
bool bucket_used[n_heap_buckets]{};
};
Listing 7-4: Heap and Bucket classes
The Bucket class is responsible for taking up space in memory. As
an homage to the Windows heap manager, the bucket size is hardcoded to 4096. All of the management logic goes into the Heap class.
Two important accounting members are in Heap: buckets and bucket_used. The buckets member houses all the Buckets, neatly packed into a contiguous string. The bucket_used member is a relatively tiny array containing
objects of type bool that keeps track of whether a Bucket in buckets with the
same index has been loaned out yet. Both members are initialized to zero.
The Heap class has two methods: allocate and free. The allocate
method first checks whether the number of bytes requested is greater
than the bucket size. If it is, it throws a std::bad_alloc exception. Once the
size check passes, Heap iterates through the buckets looking for one that
isn’t marked true in bucket_used. If it finds one, it returns the data member
pointer for the associated Bucket. If it can’t find an unused Bucket, it throws
a std::bad_alloc exception. The free method accepts a void* and iterates
through all the buckets looking for a matching data member pointer. If
it finds one, it sets bucket_used for the corresponding bucket to false and
returns.



Using Our Heap
One way to allocate a Heap is to declare it at namespace scope so it has static
storage duration. Because its lifetime begins when the program starts, you
can use it inside the operator new and operator delete overrides, as shown in
Listing 7-5.
Heap heap;
void* operator new(size_t n_bytes) {
return heap.allocate(n_bytes);
}
void operator delete(void* p) {
return heap.free(p);
}
Listing 7-5: Overriding the new and delete operators to use the Heap class from Listing 7-4
Listing 7-5 declares a Heap and uses it inside the operator new overload and the operator delete overload. Now if you use new and delete,
dynamic memory management will use heap instead of the default free store
offered by the environment. Listing 7-6 kicks the tires of the overloaded
dynamic memory management.
#include <cstdio>
--snip--
int main() {
printf("Buckets: %p\n", heap.buckets);
auto breakfast = new unsigned int{ 0xC0FFEE };
auto dinner = new unsigned int { 0xDEADBEEF };
printf("Breakfast: %p 0x%x\n", breakfast, *breakfast);
printf("Dinner: %p 0x%x\n", dinner, *dinner);
delete breakfast;
delete dinner;
try {
while (true) {
new char;
printf("Allocated a char.\n");
}
} catch (const std::bad_alloc&) {
printf("std::bad_alloc caught.\n");
}
}
Buckets: 00007FF792EE3320
Breakfast: 00007FF792EE3320 0xc0ffee
Dinner: 00007FF792EE4320 0xdeadbeef
Allocated a char.
Allocated a char.
Allocated a char.
Allocated a char.
Allocated a char.
Allocated a char.
Allocated a char.
Allocated a char.
Allocated a char.
Allocated a char.
std::bad_alloc caught.
Listing 7-6: A program illustrating the use of Heap to manage dynamic allocations
You’ve printed the memory address of the first buckets element of the
heap. This is the memory location loaned out to the first new invocation. You verify that this is the case by printing the memory address and
value pointed to by breakfast. Notice that the memory address matches
the memory address of the first Bucket in heap. You’ve done the same for
the memory pointed to by dinner. Notice that the memory address is
exactly 0x1000 greater than that of breakfast. This coincides exactly with
the 4096-byte length of a Bucket, as defined in the const static member
Bucket::data_size.
After printing, you delete breakfast and dinner. Then, you allocate
char objects with reckless abandon until a std::bad_alloc is thrown when heap
runs out of memory. Each time you make an allocation, you print Allocated
a char. There are 10 lines before you see a std::bad_alloc
exception. Notice that this is exactly the number of buckets you’ve set in
Heap::n_heap_buckets. This means that, for each char you’ve allocated, you’ve
taken up 4096 bytes of memory!


Placement Operators
Sometimes, you don’t want to override all free store allocations. In such situations, you can use the placement operators, which perform the appropriate
initialization on preallocated memory:
•	 void* operator new(size_t, void*);
•	 void operator delete(size_t, void*);
•	 void* operator new[](void*, void*);
•	 void operator delete[](void*, void*);


Using placement operators, you can manually construct objects in
arbitrary memory. This has the advantage of enabling you to manually
manipulate an object’s lifetime. However, you cannot use delete to release
the resulting dynamic objects. You must call the object’s destructor directly
(and exactly once!), as demonstrated in Listing 7-7.
#include <cstdio>
#include <cstddef>
#include <new>
struct Point {
Point() : x{}, y{}, z{} {
printf("Point at %p constructed.\n", this);
}
~Point() {
printf("Point at %p destructed.\n", this);
}
double x, y, z;
};
int main() {
const auto point_size = sizeof(Point);
std::byte data[3 * point_size];
printf("Data starts at %p.\n", data);
auto point1 = new(&data[0 * point_size]) Point{};
auto point2 = new(&data[1 * point_size]) Point{};
auto point3 = new(&data[2 * point_size]) Point{};
point1->~Point(); {
point2->~Point(); |
point3->~Point(); }
}

Output:
Data starts at 0000004D290FF8E8.
Point at 0000004D290FF8E8 constructed.
Point at 0000004D290FF900 constructed.
Point at 0000004D290FF918 constructed.
Point at 0000004D290FF8E8 destructed.
Point at 0000004D290FF900 destructed.
Point at 0000004D290FF918 destructed.


The constructor prints a message indicating that a Point at a particular address was constructed, and the destructor prints a corresponding
message indicating that the Point is getting destructed. You’ve printed the
address of data, which is the first address where placement new initializes a
Point.
Observe that each placement new has allocated the Point within the
memory occupied by your data array. You must invoke each destructor individually.
