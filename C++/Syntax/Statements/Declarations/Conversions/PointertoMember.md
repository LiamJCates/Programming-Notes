Pointer to member

Pointers to class members can be converted during assignment, initialization, comparison, and other expressions. This section describes the following pointer-to-member conversions:
Pointer to base class member

A pointer to a member of a base class can be converted to a pointer to a member of a class derived from it, when the following conditions are met:

    The inverse conversion, from pointer to derived class to base-class pointer, is accessible.

    The derived class does not inherit virtually from the base class.

When the left operand is a pointer to member, the right operand must be of pointer-to-member type or be a constant expression that evaluates to 0. This assignment is valid only in the following cases:

    The right operand is a pointer to a member of the same class as the left operand.

    The left operand is a pointer to a member of a class derived publicly and unambiguously from the class of the right operand.

null pointer to member conversions

An integral constant expression that evaluates to zero is converted to a null pointer. This pointer always compares unequal to a pointer to any valid object or function. An exception is pointers to based objects, which can have the same offset and still point to different objects.

The following code illustrates the definition of a pointer to member i in class A. The pointer, pai, is initialized to 0, which is the null pointer.
C++

class A
{
public:
int i;
};

int A::*pai = 0;

int main()
{
}
