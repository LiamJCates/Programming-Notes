Copy Semantics
Copy Semantics is “the meaning of copy.” In practice, programmers use the term to mean the rules for making copies of objects: after x is copied into y, they’re equivalent and independent. That is, x == y is true after a copy (equivalence), and a modification to x doesn’t cause a modification of y (independence).


Copy Guidelines
When you implement copy behavior, think about the following criteria:

Correctness
You must ensure that class invariants are maintained.
The default copy constructor can violate invariants.

Independence
After copy assignment or copy construction, the original object and the copy shouldn’t change each other’s state during modification.

Equivalence
The original and the copy should be the same.
The semantics of sameness depend on context. But generally, an operation applied to the original should yield the same result when applied to the copy.



Copying is extremely common, especially when passing objects to functions by value.

For fundamental and POD types, the story is straightforward. Copying these types is memberwise, which means each member gets copied into its corresponding destination. This is effectively a bitwise copy from one memory address to another.

Fully featured classes require some more thought. The default copy semantics for fully featured classes is also the memberwise copy, and this can be extremely dangerous, called a shallow copy.

When we design a class, we must always consider if and how an object might be copied. For simple concrete types, memberwise copy is often exactly the right semantics for copy. For some sophisticated concrete types memberwise copy is not the right semantics for copy; for abstract types it almost never is.


Shallow Copying
Classes that contain a raw pointer member, one that points to dynamically allocated memory, typically allocate it in the constructor using new and deallocated in the destructor using delete.

When an object of this class is copied, the pointer member is copied, but not the pointed memory, resulting in two objects pointing to the same dynamically allocated piece of memory. When an object is destructed, delete deallocates the memory, thereby invalidating the pointer copy held by the other object.

Such copies are shallow and are a threat to the stability of the program. A class that uses a pointer to a dynamic value that is memeberwise copied will not maintain independence. Both the original and copies will reference the same region of memory leading to memory clobbering as seemingly independent object operate on the same memory due to a shallow copy

This result is bad, but even worse things happen when those objects start destructing. When one of the objects is destructed, the memory will be freed. When the remaining object tries to use that freed memory undefined behavior occurs. At some point, this remaining object will be destructed and free the memory location again, resulting in what is commonly called a double free.

NOTE
Like its nefarious cousin the use after free, the double free can result in subtle and hard-to-diagnose bugs that manifest only very infrequently. A double free occurs when you deallocate an object twice. Recall that once you’ve deallocated an object, its storage lifetime ends. This memory is now in an undefined state, and if you destruct an object that’s already been destructed, you’ve got undefined behavior. In certain situations, this can cause serious security vulnerabilities.


You can avoid this dumpster fire by taking control of copy semantics.

There are two ways to copy an object, copy constructors and copy assignment operators:
copy constructor when you create object on a non initialized space
copy operator where you need to release the old state of the object (that is expected to be valid) before setting the new state.
