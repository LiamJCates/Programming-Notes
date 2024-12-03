The size_t Type
You use the size_t type, also available in the <cstddef> header, to encode size
of objects. The size_t objects guarantee that their maximum values are sufficient to represent the maximum size in bytes of all objects. Technically,
this means a size_t could take 2 bytes or 200 bytes depending on the implementation. In practice, it’s usually identical to an unsigned long long on 64-bit
architectures.
The type size_t is a C type in the <stddef> header, but it’s identical to the C++ version, which resides in the std namespace. Occasionally, you’ll see the (technically correct) construction std::size_t instead.
