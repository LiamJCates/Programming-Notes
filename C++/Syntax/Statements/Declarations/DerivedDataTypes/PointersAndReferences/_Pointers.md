## Computer Memory
Variables have been explained as locations in the computer's memory which can be accessed by a programmer provided identifier. This way, the program does not need to care about the physical address of the data in memory; it simply uses the identifier whenever it needs to refer to the data at that location.

For a C++ program, a block of computer memory is presented as consecutive memory cells, each one byte in size, and each with a unique address. These single-byte memory cells are ordered in a way that allows data representations larger than one byte to occupy memory cells that have consecutive addresses.

This way, each cell can be easily located in the memory by means of its unique address. For example, the memory cell with the address 1776 always follows immediately after the cell with address 1775 and precedes the one with 1777, and is exactly one thousand cells after 776 and exactly one thousand cells before 2776.

  +------+       +------+------+------+       +------+
  |      |  ...  |      |      |      |  ...  |      |
  +------+       +------+------+------+       +------+
    776            1775   1776   1777           2776

When a variable is declared, the memory needed to store its value is assigned a specific location in memory (its memory address). Generally, C++ programs do not actively decide the exact memory addresses where its variables are stored. Fortunately, that task is left to the environment where the program is run - generally, an operating system that decides the particular memory locations on runtime. The process of separating the programmer from the complexity of the underlying system is known as abstraction, abstraction allows the programmer and program to focus on details of greater importance.



### Heaping and Stacking Variables
C++ applications use two kinds of memory: heap and stack.

The heap is a common area of memory that your application allocates for the different functions in your application to use. Global variables go in this heap.

Whenever your application calls a function, however, the function gets its own little private area of memory storage in an area of memory known as a
stack. It is called a stack because it’s treated like a stack of papers: You can put something on the top of the stack, and you can take something off the top of the stack, but you can’t put anything in the middle or take anything from the middle. The computer uses this stack to keep track of all your function calls.

Every position in memory has a number associated with it.

When your application starts, the computer sets aside a large chunk of memory and then works closely with the microprocessor to assign bits to the memory.

These bits are your application’s variables and code.

As your application sits in memory, each function and each variable in your application has a place where it resides in memory. That place has a number associated with it, called an address. Therefore, each function and each variable has an address.

The stack where the computer keeps track of the function calls is just a bunch of memory, too. What the computer considers the top of the stack is really the next position in memory. And the way the computer puts a function on the stack is by putting on the stack the address of where the computer left off in the preceding function.

When the computer calls one of your functions, it not only saves the address of the return location on the stack but also reserves some space on the stack for your local variables.

This means that your variables can live in two places:
✦ Heap: The heap is a common area in memory where you can store global
variables.
✦ Stack: The stack is the area where the computer stores both the information about the functions being called and the local variables for those functions.



## Dealing With Addresses
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

  int * pointer1, pointer2, pointer3;     //pointer2 and pointer3 are ints
  int * pointer1, \*pointer2, *pointer3;  //all are integer pointers



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




### Void Pointer
You can also specify a pointer to a block of memory (called a void pointer):

  void* voidPointer;

The void type of pointer is a special type of pointer. In C++, void represents the absence of type. Therefore, void pointers are pointers that point to a value that has no type (and thus also an undetermined length and undetermined dereferencing properties).

This gives void pointers a great flexibility, by being able to point to any data type, from an integer value or a float to a string of characters. In exchange, they have a great limitation: the data pointed to by them cannot be directly dereferenced (which is logical, since we have no type to dereference to), and for that reason, any address in a void pointer needs to be transformed into some other pointer type that points to a concrete data type before being dereferenced.

One of its possible uses may be to pass generic parameters to a function.




### const Pointers

declaring a variable as const effectively ensures that value of the variable is fixed as the initialization value for the life of the variable. The value of a const-variable cannot be changed, and therefore it cannot be used as an l-value.

Pointers are variables, too, and hence the const keyword that is relevant to variables is relevant to pointers as well. However, pointers are a special kind of variable as they contain a memory address and are used to modify memory at that address. Thus, when it comes to pointers and constants, you have the following cases:

The address contained in the pointer is constant and cannot be changed, yet the data at that address can be changed:

  int daysInMonth = 30;
  int* const pDaysInMonth = \&daysInMonth;
  *pDaysInMonth = 31; // OK! Data pointed to can be changed
  int daysInLunarMonth = 28;
  pDaysInMonth = \&daysInLunarMonth; // Not OK! Cannot change address!


Data pointed to is constant and cannot be changed, yet the address contained in the pointer can be changed — that is, the pointer can also point elsewhere:

  int hoursInDay = 24;
  const int* pointsToInt = &hoursInDay;
  int monthsInYear = 12;
  pointsToInt = &monthsInYear; // OK!
  *pointsToInt = 13; // Not OK! Cannot change data being pointed to
  int* newPointer = pointsToInt; // Not OK! Cannot assign const to non-const


Both the address contained in the pointer and the value being pointed to are
constant and cannot be changed (most restrictive variant):

  int hoursInDay = 24;
  const int* const pHoursInDay = &hoursInDay;
  *pHoursInDay = 25; // Not OK! Cannot change data being pointed to
  int daysInMonth = 30;
  pHoursInDay = &daysInMonth; // Not OK! Cannot change address


These different forms of const are particularly useful when passing pointers to functions. Function parameters need to be declared to support the highest possible (restrictive) level of const-ness, to ensure that a function does not modify the pointed value when it is not supposed to. This will keep programmers of your application from making unwanted changes to pointer values or data.



### Array Pointer
Pointers share several characteristics with arrays. Pointers encode object location. Arrays encode the location and length of contiguous objects.

At the slightest provocation, an array will decay into a pointer. A decayed array loses length information and converts to a pointer to the array’s first element:

  int key_to_the_universe[]{ 3, 6, 9 };
  int* key_ptr = key_to_the_universe; // Points to 3

After initialization, key_ptr points to the first element of key_to_the_universe.

An array is a pointer to the first element. Should you need to access the second element via the expression myNumbers[1], you can also access the same using the pointer pointToNums with the syntax *(pointToNums + 1). The third element is accessed in the static array using myNumbers[2], whereas the third element is accessed in the dynamic array using the syntax *(pointToNums + 2).



#### Handling Decay
Often, you pass arrays as two arguments:
•	 A pointer to the first array element
•	 The array’s length
The mechanism that enables this pattern is the subscript operator ([]), which works with pointers just as with arrays.

  #include <cstdio>
  struct College {
    char name[256];
  };

  void print_names(College* colleges, size_t n_colleges) {
    for (size_t i = 0; i < n_colleges; i++)
      printf("%s College\n", colleges[i].name);
  }

  int main() {
    College oxford[] = { "Magdalen", "Nuffield", "Kellogg" };
    print_names(oxford, sizeof(oxford) / sizeof(College));
  }

Output:
Magdalen College
Nuffield College
Kellogg College




## Pointer Arithmetic
To obtain the address of the nth element of an array, you have two options.
First, you can take the direct approach of obtaining the nth element with
the subscript operator ([]) and then use the address-of (&) operator:

  College* third_college_ptr = &oxford[2];

Pointer arithmetic, the set of rules for addition and subtraction on pointers, provides an alternate approach. When you add or subtract integers to pointers, the compiler figures out the correct byte offset using the size of the pointed-to type.

For example, adding 4 to a uint64_t pointer adds 32 bytes as a uint64_t takes up 8 bytes, so 4 of them take up 32 bytes.

The following is therefore equivalent to the previous option of obtaining the address of the nth element of an array:

  College* third_college_ptr = oxford + 2;




## string literal Pointers
As pointed earlier, string literals are arrays containing null-terminated character sequences. They can also be accessed directly. String literals are arrays of the proper array type to contain all its characters plus the terminating null-character, with each of the elements being of type const char (as literals, they can never be modified). For example:

const char * foo = "hello";

This declares an array with the literal representation for "hello", and then a pointer to its first element is assigned to foo. If we Suppose that "hello" is stored at the memory locations that start at address 1702, then foo is a pointer and contains the value 1702, and not 'h', nor "hello", although 1702 indeed is the address of both of these.

The pointer foo points to a sequence of characters. Because pointers and arrays behave essentially the same way in expressions, foo can be used to access the characters in the same way arrays of null-terminated character sequences are. For example:

  *(foo+4)
  foo[4]


Both expressions have a value of 'o' (the fifth element of the array).

When using a pointer to a string, to access the characters of the string through that pointer, you need to put parentheses around the asterisk and the pointer variable. Otherwise, the compiler first tries to access the index in brackets with the variable name and afterward applies the asterisk due to the precedence:

  (*ptrToString)[i]
