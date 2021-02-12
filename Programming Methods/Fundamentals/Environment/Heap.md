The heap is a common area of memory that your application allocates for the different functions in your application to use.

The heap segment (“free store”) keeps track of memory used for dynamic memory allocation.

The mechanics behind the process of how free memory is located and allocated to the user is typically abstracted by the language such that developers typically do not have to worry about it.

When a dynamically allocated variable is freed, the memory is “returned” to the heap and can then be reassigned as future allocation requests are received. Remember that deleting a pointer does not delete the variable, it just returns the memory at the associated address back to the operating system.

The heap has advantages and disadvantages:

    Allocating memory on the heap is comparatively slow.
    Allocated memory stays allocated until it is specifically deallocated (beware memory leaks) or the application ends (at which point the OS should clean it up).
    Dynamically allocated memory must be accessed through a pointer. Dereferencing a pointer is slower than accessing a variable directly.
    Because the heap is a big pool of memory, large arrays, structures, or classes can be allocated here.
