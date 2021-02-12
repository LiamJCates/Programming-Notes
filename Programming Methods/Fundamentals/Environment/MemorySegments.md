### Memory Segments

The memory that a program uses is typically divided into a few different areas, called segments:

    Code segment: (text segment) Where the compiled program sits in memory, typically read-only.
    Bss segment: (uninitialized data segment) zero-initialized global and static variables
    Data segment: (initialized data segment), initialized global and static variables
    heap: Where dynamically allocated variables are allocated from.
    Call stack: Where function parameters, local variables, and other function-related information are stored.




### Text

The code segment, also known as a text segment or simply as text, is where a portion of an object file or the corresponding section of the program's address space that contains executable instructions is stored and is generally read-only and fixed size.



### Data

The .data segment contains any global or static variables which have a pre-defined value and can be modified. That is any variables that are not defined within a function (and thus can be accessed from anywhere) or are defined in a function but are defined as static so they retain their address across subsequent calls:

   int val = 3;
   char string[] = "Hello World";

The values for these variables are initially stored within the read-only memory (typically within .text) and are copied into the .data segment during the start-up routine of the program.

Note that in the above example, if these variables had been declared from within a function, they would default to being stored in the local stack frame.



### BSS

The BSS segment, also known as uninitialized data, is usually adjacent to the data segment. The BSS segment contains all global variables and static variables that are initialized to zero or do not have explicit initialization in source code. For instance, a variable defined as static int i; would be contained in the BSS segment.


### Heap

The heap area commonly begins at the end of the .bss and .data segments and grows to larger addresses from there. The heap area is managed by malloc, calloc, realloc, and free, which may use the brk and sbrk system calls to adjust its size (note that the use of brk/sbrk and a single "heap area" is not required to fulfill the contract of malloc/calloc/realloc/free; they may also be implemented using mmap/munmap to reserve/unreserve potentially non-contiguous regions of virtual memory into the process' virtual address space). The heap area is shared by all threads, shared libraries, and dynamically loaded modules in a process.



### Stack

The stack area contains the program stack, a LIFO structure, typically located in the higher parts of memory. A "stack pointer" register tracks the top of the stack; it is adjusted each time a value is "pushed" onto the stack. The set of values pushed for one function call is termed a "stack frame". A stack frame consists at minimum of a return address. Automatic variables are also allocated on the stack.

The stack area traditionally adjoined the heap area and they grew towards each other; when the stack pointer met the heap pointer, free memory was exhausted. With large address spaces and virtual memory techniques they tend to be placed more freely, but they still typically grow in a converging direction. On the standard PC x86 architecture the stack grows toward address zero, meaning that more recent items, deeper in the call chain, are at numerically lower addresses and closer to the heap. On some other architectures it grows the opposite direction.
