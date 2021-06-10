C’s Memory Model

As you may be knowing RAM(random access memory) is the area which is used as primary memory. Whenever we execute a program the first thing which happens is that it gets loaded into memory. Now a binary program becomes a process when it is running i.e. a running program is referred as process. All processes have memory area divided into different portions. These portions are known as data segment, stack and code or text segment. Data segment is further split in three parts; initialized data segment, uninitialized data segment or BSS which is name after an ancient assembler Block Started by Symbol and heap. Initialized data segment contains initialized global variables and static variables. For uninitialized data segment it is same as above just that the variables are not initialized explicitly but implicitly to zero.

Heap is the largest area of memory used for dynamic memory allocation. As you will see later that you can manage heap using malloc(), calloc(), realloc() and {free(). Note that operating system does not manage memory allocated for you on heap. You, the programmer, are responsible for allocating and freeing up memory in area. If heap gets full os will use virtual memory or swap space on hard disk. Objects allocated on heap persist across function calls. However, there are some very nasty problems, which, come in picture when you use heap. There are several of them. You may forget to allocate memory and may dereference unallocated pointer. You may have initialized it to NULL and try to dereference that. You may allocate and free twice. You forgot to set pointer to ``NULL`` after freeing it. And last but not the least you loose all pointers to the memory area before you can free. The nature with this particular problem is that if your program is going to run for long time then it is going to consume more and more memory. Because of its nature it is known as memory leak. It is very difficult to detect such problems in code which does not run for long periods of time. Our friend Valgrind will come to help up with this problem. When a memory leak happens it eats up RAM slowly and then operating system has to use virtual memory as explained above. In a nutshell, I will say that heap means you have to manage it.

```
									+--------+
									|  Stack |
									|    |   |
									|    v   |
									+--------+
									|    ^   |
									|    |   |
									|  Heap  |
									+--------+
									|  Data  |
									+--------+
									|  Code  |
									+--------+
```

Stack is relatively simple. All non-static and non-register variables go on stack if not allocated dynamically. Stack variables do not retain there value across function calls unless they are passed as pointers. Also, when they go out of scope, that is the scope in which they were declared ends, they will be kind of lost. The way in which stack frame moves the same area will be used for new variables. However, stack is very limited (compared to heap) and in deeply nested function calls or recursion (you will see these in Functions chapter) stack may get full and program may crash. The reason for crashing is that operating system will not use virtual memory but will do a segmentation fault in its place. GNU/Linux allow its users to modify the stack size by ulimit command. Note that stack and heap are adjacent in memory and grow in opposite direction.

Code segment or text segment is an area where the executable instructions of program reside. It is typically constant and read-only area unless your system allows self-modifying code. Following diagram shows the memory layout.

Note that this memory model not only applies to C but any process.
