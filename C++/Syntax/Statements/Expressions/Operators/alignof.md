| Name | Syntax | Overloadable |
|------|--------|--------------|
| alignof | alignof(type) | No |


The alignof operator returns the alignment in bytes of the specified type as a value of type size_t:

  alignof( type )

Returns the alignment, in bytes, required for any instance of the type indicated by type-id, which is either complete object type, an array type whose element type is complete, or a reference type to one of those types.

If the type is reference type, the operator returns the alignment of referenced type; if the type is array type, alignment requirement of the element type is returned.

Every object type has the property called alignment requirement, which is an integer value (of type std::size_t, always a power of 2) representing the number of bytes between successive addresses at which objects of this type can be allocated.
