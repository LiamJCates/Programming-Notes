Data models

The choices made by each implementation about the sizes of the fundamental types are collectively known as data model. Four data models found wide acceptance:

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
