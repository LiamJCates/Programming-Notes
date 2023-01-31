std::nullptr_t
Defined in header <cstddef>

typedef decltype(nullptr) nullptr_t;
		(since C++11)


std::nullptr_t is the type of the null pointer literal, nullptr. It is a distinct type that is not itself a pointer type or a pointer to member type. Its values are null pointer constant (see NULL), and may be implicitly converted to any pointer and pointer to member type.

sizeof(std::nullptr_t) is equal to sizeof(void *). 
