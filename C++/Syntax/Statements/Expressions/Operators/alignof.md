| Name | Syntax | Overloadable |
|------|--------|--------------|
| alignof | alignof(type) | No |



The alignof operator returns the alignment in bytes of the specified type as a value of type size_t.

alignof( type )

The alignof value is the same as the value for sizeof for basic types.

For structures the alignof value is the alignment requirement of the largest element in the structure.
