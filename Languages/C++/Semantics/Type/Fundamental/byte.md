The std::byte Type
System programmers sometimes work directly with raw memory, which is a
collection of bits without a type. Employ the std::byte type, available in the
<cstddef> header, in such situations. The std::byte type permits bitwise logical operations and little else. Using this
type for raw data rather than an integral type can help to avoid common
sources of difficult-to-debug programming errors.
Note that unlike most other Simple Data types in <cstddef>, std::byte
doesn’t have an exact corollary type in the C language (a “C type”). Like
C++, C has char and unsigned char. These types are less safe to use because they support many operations that std::byte doesn’t. For example, you
can perform arithmetic, like addition (+), on a char but not a std::byte.
