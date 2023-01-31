## Computer Memory

Whenever you run a program, it is first loaded (typically from disk) into the computer’s memory. Thus, all elements of your program are located somewhere in memory.

Memory is typically laid out as a sequential series of memory locations; we usually refer to these locations as eight-bit bytes but actually the size of each space depends on the architecture of the particular machine and is usually called that machine’s word size. Each space can be uniquely distinguished from all other spaces by its address. For the purposes of this discussion, we’ll just say that all machines use bytes that have sequential addresses starting at zero and going up to however much memory you have in your computer.

Since your program lives in memory while it’s being run, every element of your program has a memory address. Each of the elements in this program has a location in storage when the program is running. Even the function occupies storage. As you’ll see, it turns out that what an element is and the way you define it usually determines the area of memory where that element is placed.

Variables have been explained as locations in the computer's memory which can be accessed by a programmer provided identifier. This way, the program does not need to care about the physical address of the data in memory; it simply uses the identifier whenever it needs to refer to the data at that location.

For a C++ program, a block of computer memory is presented as consecutive memory cells, each one byte in size, and each with a unique address. These single-byte memory cells are ordered in a way that allows data representations larger than one byte to occupy memory cells that have consecutive addresses.

Variables defined one right after the other appear to be placed contiguously in memory. They are separated by the number of bytes that are required by their data type.

This way, each cell can be easily located in the memory by means of its unique address. For example, the memory cell with the address 1776 always follows immediately after the cell with address 1775 and precedes the one with 1777, and is exactly one thousand cells after 776 and exactly one thousand cells before 2776.

  +------+       +------+------+------+       +------+
  |      |  ...  |      |      |      |  ...  |      |
  +------+       +------+------+------+       +------+
    776            1775   1776   1777           2776

When a variable is declared, the memory needed to store its value is assigned a specific location in memory (its memory address). Generally, C++ programs do not actively decide the exact memory addresses where its variables are stored. Fortunately, that task is left to the environment where the program is run - generally, an operating system that decides the particular memory locations at runtime. The process of separating the programmer from the complexity of the underlying system is known as abstraction, abstraction allows the programmer and program to focus on details of greater importance.




Every position in memory has a number associated with it.

When your application starts, the computer sets aside a large chunk of memory and then works closely with the microprocessor to assign bits to the memory.

These bits are your application’s variables and code.

As your application sits in memory, each function and each variable in your application has a place where it resides in memory. That place has a number associated with it, called an address. Therefore, your code, each function and each variable, has associated addresses.


To manipulate memory addresses C++ uses:
	Pointers
	References
