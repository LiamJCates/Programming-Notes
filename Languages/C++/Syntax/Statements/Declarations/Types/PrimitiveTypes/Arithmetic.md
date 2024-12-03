The arithmetic types represent characters, integers, boolean values, and floating-point numbers. The void type has no associated values and
can be used in only a few circumstances, most commonly as the return type for
functions that do not return a value.

The arithmetic types are divided into two categories: integral types (which include
character and boolean types) and floating-point types.


The size of—that is, the number of bits in—the arithmetic types varies across
machines. The standard guarantees minimum sizes

Type        Meaning                           Minimum Size
bool        boolean                           NA
char        character                         8 bits
wchar_t     wide character                    16 bits
char16_t    Unicode character                 16 bits
char32_t    Unicode character                 32 bits
short       short integer                     16 bits
int         integer                           16 bits
long        long integer                      32 bits
long        long long integer                 64 bits
float       single-precision floating-point   6 significant digits
double      double-precision floating-point   10 significant digits
long double extended-precision floating-point 10 significant digits

However,
compilers are allowed to use larger sizes for these types. Because the number of
bits varies, the largest (or smallest) value that a type can represent also varies.
