#MACHINE-LEVEL REPRESENTATION OF THE BUILT- IN TYPES

Computers store data as a sequence of bits, each holding a 0 or 1, such as
00011011011100010110010000111011 ...

Most computers deal with memory as chunks of bits of sizes that are powers of 2. The smallest chunk of addressable memory is referred to as a “byte.” The basic unit of storage, usually a small number of bytes, is referred to as a “word.”

In C++ a byte has at least as many bits as are needed to hold a character in the machine’s basic character set. On most machines a byte contains 8 bits and a word is either 32 or 64 bits, that is, 4 or 8 bytes.

Most computers associate a sequential number (called an “address”) with each byte in memory. On a machine with 8-bit bytes and 32-bit words, we might view a word of memory as follows

Address_|_Value__________
736424  | 0 0 1 1 1 0 1 1
736425  | 0 0 0 1 1 0 1 1
736426  | 0 1 1 1 0 0 0 1
736427  | 0 1 1 0 0 1 0 0

Here, the byte’s address is on the left, with the 8 bits of the byte following the address.
We can use an address to refer to any of several variously sized collections of bits
starting at that address. It is possible to speak of the word at address 736424 or the
byte at address 736427. To give meaning to memory at a given address, we must know
the type of the value stored there. The type determines how many bits are used and
how to interpret those bits.
If the object at location 736424 has type float and if floats on this machine are
stored in 32 bits, then we know that the object at that address spans the entire word.
The value of that float depends on the details of how the machine stores floating-
point numbers. Alternatively, if the object at location 736424 is an unsigned char on
a machine using the ISO-Latin-1 character set, then the byte at that address represents
a semicolon.


Data models

The choices made by each C++ implementation about the sizes of the fundamental types are collectively known as data model. 

Four data models have found wide acceptance:

32 bit systems:

        LP32 or 2/4/4 (int is 16-bit, long and pointer are 32-bit)

            Win16 API

        ILP32 or 4/4/4 (int, long, and pointer are 32-bit);

            Win32 API
            Unix and Unix-like systems (Linux, macOS)

64 bit systems:

        LLP64 or 4/4/8 (int and long are 32-bit, pointer is 64-bit)

            Win64 API

        LP64 or 4/8/8 (int is 32-bit, long and pointer are 64-bit)

            Unix and Unix-like systems (Linux, macOS)

Other models are very rare. For example, ILP64 (8/8/8: int, long, and pointer are 64-bit) only appeared in some early 64-bit Unix systems (e.g. UNICOS on Cray).










Properties

The following table summarizes all available integer types and their properties in various common data models:

Type specifier        Equivalent type     C++ standard  LP32  ILP32 LLP64  LP64

signed char           signed char         at least8     8     8     8      8
unsigned char         unsigned char       "

short                 short int           at least16    16    16    16     16
short int             "
signed short
signed short int

unsigned short        unsigned short int
unsigned short int    "

int                   int                 at least16  16    32    32    32
signed
signed int
unsigned              unsigned int
unsigned int

long                  long int 	          at least32  32    32    32    64
long int
signed long
signed long int
unsigned long         unsigned long int
unsigned long int

(C++11)
long long             long long int       at least64  64    64    64    64
long long int
signed long long
signed long long int

unsigned long long    unsigned long long int
unsigned long long int


Note: integer arithmetic is defined differently for the signed and unsigned integer types. See arithmetic operators, in particular integer overflows.

std::size_t is the unsigned integer type of the result of the sizeof operator as well as the sizeof... operator and the alignof operator (since C++11).

See also Fixed width integer types.
	(since C++11)
