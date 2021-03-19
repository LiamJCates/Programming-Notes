## Pointers

It can be useful for a program to be able to obtain the address of a variable during runtime. Pointers are the fundamental mechanism used to refer to memory addresses. Pointers encode both pieces of information required to interact with another object, the object’s address and the object’s type.

The values belonging to pointer data types are the memory addresses of your computer that are made available by the OS at runtime. Because the domain, the set of values of a pointer data type, is the addresses (locations) in memory, a pointer variable is a variable whose content is an address, that is, a memory location and the pointer variable is said to "point to" that memory location.

As in many other languages, there is no type name associated with the pointer data type in C++. A pointer, being a variable needs to be declared. To declare a pointer by specify a value type and appending an indirection operator (*). This would mean that the address contained in the pointer points to a location in the memory that holds that type.

The declaration of pointers follows this syntax:

  type * name;

where type is the data type pointed to by the pointer. This type is not the type of the pointer itself, but the type of the data the pointer points to.

Note that the asterisk (\*) used when declaring a pointer only means that it is a pointer (it is part of its type compound specifier).

  int intValue = 0;   //integer variable with value zero
  int* intPointer;    //integer pointer declaration

As is the case with most variables, unless you initialize a pointer it will contain a random value. Uninitialized pointers can result in your program accessing invalid memory locations, resulting in a crash.

You don’t want a random memory address to be accessed so you initialize a pointer to 0, or nullptr in C++11+. These are values that can be checked against and that cannot be a memory address:

  intPointer = 0;
  intPointer = nullptr;

We try to ensure that a pointer always points to an object so that it's use is valid. When we don’t have an object to point to or if we need to represent the notion of ‘‘no object available’’ (e.g., for an end of a list), we give the pointer the value nullptr (‘‘the null pointer’’).

You can obtain the address of a variable by prepending the address-of operator (&). This operator may be used to initialize a pointer so it “points to” the corresponding variable:

  intPointer = \&intValue;  //assign the memory location of intValue

This would assign the address of variable intValue to intPointer; by preceding the name of the variable intValue with the address-of operator (&), we are no longer assigning the content of the variable itself to intPointer, but its address.

Given a pointer, you can obtain the object residing at the corresponding address, called dereferencing. This is done via the dereference operator (*), a unary operator that accesses the object to which a pointer refers:

  int intValue2 = *intPointer; //dereference to obtain pointed to value 0

The reference and dereference operators are thus complementary:
  & is the address-of operator, and can be read simply as "address of"
  \* is the dereference operator, and can be read as "value pointed to by"

The dereference operator can be used to set the value of pointed to memory:

  *intPointer = 10;

intPointer was assigned the address of intValue using the address-of operator (&). Then, the value pointed to by intPointer is assigned a value of 10. Because, at this moment, intPointer is pointing to the memory location of intValue, this modifies the value of intValue.

If you try to declare multiple pointers on a single line be aware that as the indirection operator (*) modifies the identifier and not the type the operator is required before each pointer:

  int *pointer1, pointer2, pointer3;     //pointer2 and pointer3 are ints
  int \*pointer1, \*pointer2, *pointer3;  //all are integer pointers



### Example

  #include <cstdio>
  int main() {
    int gettysburg{};
    printf("gettysburg: %d\n", gettysburg);
    int *gettysburg_address = &gettysburg;
    printf("&gettysburg: %p\n", gettysburg_address);
  }

The integer gettysburg is declared and it's value is printed. A pointer, called gettysburg_address, is declared and it's value is initialized to the integer’s address; notice that the asterisk prepends the pointer and the ampersand prepends gettysburg. The pointer is printed and reveals the gettysburg integer’s address, memory locations are typically addressed using hexadecimal.

Windows 10 x86 output:

  gettysburg: 0
  &gettysburg: 0053FBA8           (could be a different address)

Windows 10 x64 output:

  gettysburg: 0
  &gettysburg: 0000007DAB53F594   (could be a different address)


gettysburg_address contains 8 hexadecimal digits (4 bytes) for an x86 architecture and 16 hexadecimal digits (8 bytes) for an x64 architecture. This should make some sense because on modern desktop systems, the pointer size is the same as the CPU’s general-purpose register. An x86 architecture has 32-bit (4-byte) general-purpose registers, whereas an x64 architecture has 64-bit (8-byte) general-purpose registers.

Your output should have an identical value for gettysburg, but gettysburg_address should be different each time.

This variation is due to address space layout randomization, which is a security feature that scrambles the base address of important memory regions to hamper exploitation.



### Pointers to pointers

C++ allows the use of pointers that point to pointers. The syntax simply requires an asterisk (*) for each level of indirection in the declaration of the pointer:

  char a;
  char * b;
  char ** c;
  a = 'z';
  b = &a;
  c = &b;

Assuming the randomly chosen memory locations for each variable of 7230, 8092, and 10502, could be represented as:

   a             b               c
+-----+       +------+       +------+
| 'z' | <---- | 7230 | <---- | 8092 |
+-----+       +------+       +------+
 7230           8092          10502

variable c, which is a pointer to a pointer, and can be used in three different levels of indirection, each one of them would correspond to a different value:

  c is of type char** and holds a memory value of 8092, for example
  \*c is of type char* and holds a memory value of 7230, for example
  **c is of type char and holds a value of 'z'



### sizeof() of a Pointer

Irrespective of the type that is being pointed to, the content of a pointer is an address — a number. The length of an address, that is the number of bytes required to store it, is a constant for a given system.

The sizeof() a pointer is dependent on the compiler and the operating system the program has been compiled for and is not dependent on the nature of the data being pointed to

For example, sizeof(char) is 1 byte and a sizeof(double) is 8 bytes, while the sizeof(char\*) and sizeof(double*) are both 4 bytes. This is because the amount of memory consumed by a pointer that stores an address is the same, irrespective of whether the memory at the address contains 1 byte or 8 bytes of data.

If you use a 32-bit compiler and run the program on a 32-bit system, you might see that the sizeof your pointer variable is 32 bits — that is, 4 bytes.

If you use a 64-bit compiler and run the program on a 64-bit system, you might see that the sizeof your pointer variable is 64 bits—that is, 8 bytes.



### (++ and --) on Pointers

A pointer contains a memory address. An increment or decrement operation on a pointer is interpreted by the compiler as your need to point to the next value in the block of memory, assuming it to be of the same type, and not to the next byte (unless the value type is 1 byte large, like a char, for
instance).

Decrementing pointers using operator (--) demonstrates the same effect—the address value contained in the pointer is reduced by the sizeof the data type it is being pointed to.

The address contained in the pointer is incremented or decremented by the sizeof the type being pointed to. This way, the compiler ensures
that the pointer never points to the middle or end of data placed in the memory; it only points to the beginning.

If a pointer has been declared as

Type* pType = Address;

++pType would mean that pType contains (and hence points to) Address +
sizeof(Type).
