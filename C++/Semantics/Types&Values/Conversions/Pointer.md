Pointer conversions

Pointers can be converted during assignment, initialization, comparison, and other expressions.

Pointer to classes

There are two cases in which a pointer to a class can be converted to a pointer to a base class.

The first case is when the specified base class is accessible and the conversion is unambiguous. For more information about ambiguous base-class references.

Whether a base class is accessible depends on the kind of inheritance used in derivation.

+---------+
| class A |
+---------+
^
|
+----------------+
| class B : * A  |    // * private protected or public
+----------------+
^
|
+--------------------+
| class C : public B |
+--------------------+


Inheritance Graph for Base-Class Accessibility

<table>
 <tr>
   <th>Type of Function</th>
   <th>Derivation</th>
   <th>Conversion from B\* to A\* Legal?</th>
 </tr>
 <tr>
   <td rowspan="3">External (not class-scoped) function</td>
   <td>Private</td>
   <td>No</td>
 </tr>
 <tr>
   <td>Protected</td>
   <td>No</td>
 </tr>
 <tr>
   <td>Public</td>
   <td>Yes</td>
 </tr>
 <tr>
   <td rowspan="3">B member function (in B scope)</td>
   <td>Private</td>
   <td>Yes</td>
 </tr>
 <tr>
   <td>Protected</td>
   <td>Yes</td>
 </tr>
 <tr>
   <td>Public</td>
   <td>Yes</td>
 </tr>
 <tr>
   <td rowspan="3">C member function (in C scope)</td>
   <td>Private</td>
   <td>No</td>
 </tr>
 <tr>
   <td>Protected</td>
   <td>Yes</td>
 </tr>
 <tr>
   <td>Public</td>
   <td>Yes</td>
 </tr>
</table>

The second case in which a pointer to a class can be converted to a pointer to a base class is when you use an explicit type conversion.

The result of such a conversion is a pointer to the subobject, the portion of the object that is completely described by the base class.

The following code defines two classes, A and B, where B is derived from A. (For more information on inheritance, see Derived Classes.) It then defines bObject, an object of type B, and two pointers (pA and pB) that point to the object.

class A
{
public:
    int AComponent;
    int AMemberFunc();
};

class B : public A
{
public:
    int BComponent;
    int BMemberFunc();
};
int main()
{
   B bObject;
   A *pA = &bObject;
   B *pB = &bObject;

   pA->AMemberFunc();   // OK in class A
   pB->AMemberFunc();   // OK: inherited from class A
   pA->BMemberFunc();   // Error: not in class A
}

The pointer pA is of type A *, which can be interpreted as meaning "pointer to an object of type A." Members of bObject (such as BComponent and BMemberFunc) are unique to type B and are therefore inaccessible through pA. The pA pointer allows access only to those characteristics (member functions and data) of the object that are defined in class A.


Pointer to function

A pointer to a function can be converted to type void *, if type void * is large enough to hold that pointer.
Pointer to void

Pointers to type void can be converted to pointers to any other type, but only with an explicit type cast (unlike in C). A pointer to any type can be converted implicitly to a pointer to type void. A pointer to an incomplete object of a type can be converted to a pointer to void (implicitly) and back (explicitly). The result of such a conversion is equal to the value of the original pointer. An object is considered incomplete if it's declared, but there's insufficient information available to determine its size or base class.

A pointer to any object that is not const or volatile can be implicitly converted to a pointer of type void *.
const and volatile pointers

C++ doesn't supply a standard conversion from a const or volatile type to a type that's not const or volatile. However, any sort of conversion can be specified using explicit type casts (including conversions that are unsafe).

Note

C++ pointers to members, except pointers to static members, are different from normal pointers and don't have the same standard conversions. Pointers to static members are normal pointers and have the same conversions as normal pointers.
null pointer conversions

An integral constant expression that evaluates to zero, or such an expression cast to a pointer type, is converted to a pointer called the null pointer. This pointer always compares unequal to a pointer to any valid object or function. An exception is pointers to based objects, which can have the same offset and still point to different objects.

In C++11, the nullptr type should be preferred to the C-style null pointer.
Pointer expression conversions

Any expression with an array type can be converted to a pointer of the same type. The result of the conversion is a pointer to the first array element. The following example demonstrates such a conversion:
C++

char szPath[_MAX_PATH]; // Array of type char.
char *pszPath = szPath; // Equals &szPath[0].

An expression that results in a function returning a particular type is converted to a pointer to a function returning that type, except when:

    The expression is used as an operand to the address-of operator (&).

    The expression is used as an operand to the function-call operator.
