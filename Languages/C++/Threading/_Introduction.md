## Introduction to Threads

When a computer runs an application, that instance of the program executing is referred to as a process.

A process consists of the program's:
code,
data,
information about its state

Each process is independent and has its own separate address space and memory.

NOTE
A computer can have hundreds of active processes at once, and an operating system's job is to manage all of them.


### Threads

Within every process, there are one or more threads. Each thread is an independent path of execution through the program, a different sequence of instructions.  
Threads can only exist as part of a process.
Threads are the basic units that the operating system manages by allocating processor time to execute them.

To conceptualize the relationship between a process and its threads, think of two cooks in a kitchen as being two threads, executing as part of the same process. While work independently, their tasks contribute to the completion of a dish, or program.

When a program has more tasks that can be completed in unison it might create more threads to handle them. As threads finish executing their instructions they'll exit and leave the remaining threads to continue what they're doing.

Threads that belong to the same process share the process's address space, which gives them access to the same resources and memory, including the program's executable code and data.


### Sections
