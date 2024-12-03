## static_cast

For “well-behaved” and “reasonably well-behaved” casts, including things you might now do without a cast (such as an automatic type conversion).

A static_cast is used for all conversions that are well-defined. These
include “safe” conversions that the compiler would allow you to do
without a cast and less-safe conversions that are nonetheless welldefined. The types of conversions covered by static_cast include typical castless conversions, narrowing (information-losing) conversions, forcing a conversion from a void*, implicit type conversions, and static navigation of class hierarchies

https://en.cppreference.com/w/cpp/language/static_cast

static_cast can perform conversions between pointers to related classes, not only upcasts (from pointer-to-derived to pointer-to-base), but also downcasts (from pointer-to-base to pointer-to-derived). No checks are performed during runtime to guarantee that the object being converted is in fact a full object of the destination type. Therefore, it is up to the programmer to ensure that the conversion is safe. On the other side, it does not incur the overhead of the type-safety checks of dynamic_cast.



static_cast, for casts that are checked at compile time only. static_cast returns an error if the compiler detects that you are trying to cast between types that are completely incompatible. You can also use it to cast between pointer-to-base and pointer-to-derived, but the compiler can't always tell whether such conversions will be safe at runtime.
C++

double d = 1.58947;
int i = d;  // warning C4244 possible loss of data
int j = static_cast<int>(d);       // No warning.
string s = static_cast<string>(d); // Error C2440:cannot convert from
                               // double to std:string

// No error but not necessarily safe.
Base* b = new Base();
Derived* d2 = static_cast<Derived*>(b);





class Base {};
class Derived: public Base {};
Base * a = new Base;
Derived * b = static_cast<Derived*>(a);

This would be valid code, although b would point to an incomplete object of the class and could lead to runtime errors if dereferenced.

Therefore, static_cast is able to perform with pointers to classes not only the conversions allowed implicitly, but also their opposite conversions.

static_cast is also able to perform all conversions allowed implicitly (not only those with pointers to classes), and is also able to perform the opposite of these. It can:

    Convert from void* to any pointer type. In this case, it guarantees that if the void* value was obtained by converting from that same pointer type, the resulting pointer value is the same.
    Convert integers, floating-point values and enum types to enum types.


Additionally, static_cast can also perform the following:

    Explicitly call a single-argument constructor or a conversion operator.
    Convert to rvalue references.
    Convert enum class values into integers or floating-point values.
    Convert any type to void, evaluating and discarding the value.












void func(int) {}

int main()
{
	int i = 0x7fff; // Max pos value = 32767
	long l;
	float f;

	// (1) Typical castless conversions:
	l = i;
	f = i;

	// Also works:
	l = static_cast<long>(i);
	f = static_cast<float>(i);
	3 : The C in C++ 183

	// (2) Narrowing conversions:
	i = l; // May lose digits
	i = f;	   // May lose info

	// Says "I know," eliminates warnings:
	i = static_cast<int>(l);
	i = static_cast<int>(f);
	char c = static_cast<char>(i);

	// (3) Forcing a conversion from void* :
	void *vp = &i;

	// Old way produces a dangerous conversion:
	float *fp = (float *)vp;

	// The new way is equally dangerous:
	fp = static_cast<float *>(vp);

	// (4) Implicit type conversions, normally performed by the compiler:
	double d = 0.0;
	int x = d;				   // Automatic type conversion
	x = static_cast<int>(d);   // More explicit
	func(d);				   // Automatic type conversion
	func(static_cast<int>(d)); // More explicit
}

In Section (1), you see the kinds of conversions you’re used to doing in C, with or without a cast. Promoting from an int to a long or float is not a problem because the latter can always hold every value that an int can contain. Although it’s unnecessary, you can use static_castto highlight these promotions.

Converting back the other way is shown in (2). Here, you can lose data because an int is not as “wide” as a long or a float; it won’t hold numbers of the same size. Thus these are called narrowing conversions. The compiler will still perform these, but will often give you a warning. You can eliminate this warning and indicate that you really did mean it using a cast.

Assigning from a void* is not allowed without a cast in C++ (unlike C), as seen in (3). This is dangerous and requires that programmers know what they’re doing. The static_cast, at least, is easier to locate than the old standard cast when you’re hunting for bugs.

Section (4) of the program shows the kinds of implicit type
conversions that are normally performed automatically by the
compiler. These are automatic and require no casting, but again
static_casthighlights the action in case you want to make it clear
what’s happening or hunt for it later.
















static_cast

When a value of one data type is automatically
changed to another data type, an implicit type coercion is said to have occurred.
As the examples in the preceding section illustrate, if you are not careful about data
types, implicit type coercion can generate unexpected results.
To avoid implicit type coercion, C++ provides for explicit type conversion through
the use of a cast operator. The cast operator, also called type conversion or type
casting, takes the following form:
static_cast<dataTypeName>(expression)
First, the expression is evaluated. Its value is then converted to a value of the type
specified by dataTypeName. In C++, static_cast is a reserved word.

| Expression | Evaluates to |
|------------|--------------|
| static_cast<int>(7.9) | 7 |
| static_cast<double>(25) | 25.0 |
| static_cast<double>(5 + 3) | = static_cast<double>(8) = 8.0 |
| static_cast<double>(15) / 2 | = 15.0 / 2 = 7.5 |
| static_cast<double>(15/2) | = static_cast<double>(7) = 7.0 |
| static_cast<int>(7.8 + static_cast<double>(15)/2) | = static_cast<int>(7.8 + 7.5) = static_cast<int>(15.3) = 15 |
| static_cast<int>(7.8 + static_cast<double>(15/2)) | = static_cast<int>(7.8 + 7.0) = static_cast<int>(14.8) = 14 |
| static_cast<int>('A') | = 65 |
|  static_cast<char>(56) | = '8' |

NOTE
In C++, the cast operator can also take the form dataType(expression). This form is called C-like casting. For example, double(5) = 5.0 and int(17.6) = 17.

However, static_cast is more stable than C-like casting.



The static_cast reverses a well-defined implicit conversion, such as an integer type to another integer type. The object-to-cast is of some type that the
desired-type implicitly converts to. The reason you might need static_cast is
that, generally, implicit casts aren’t reversible.

The next program defines an increment_as_short function that takes a void pointer argument. It employs a static_cast to create a short pointer from this argument, increment the pointed-to short, and return the result. In some low-level applications, such as network programming or handling binary file formats, you might need to interpret raw bytes as an integer type.

#include <cstdio>

short increment_as_short(void* target)
{
  auto as_short = static_cast<short*>(target);
  *as_short = *as_short + 1;
  return *as_short;
}

int main() {
  short beast{ 665 };
  auto mark_of_the_beast = increment_as_short(&beast);
  printf("%d is the mark_of_the_beast.", mark_of_the_beast);
}

The target parameter is a void pointer. You employ static_cast to cast
target into a short*. The template parameter is the desired type, and
the function parameter is the object you want to cast into.

Notice that the implicit conversion of short* to void* is well defined.
Attempting ill-defined conversions with static_cast, such as converting a
char* to a float*, will result in a compiler error:
float on = 3.5166666666;
auto not_alright = static_cast<char*>(&on); // Bang!

To perform such chainsaw juggling, you need to use reinterpret_cast





















Converts an expression to the type of type-id, based only on the types that are present in the expression.
Syntax

static_cast <type-id> ( expression )

Remarks

In standard C++, no run-time type check is made to help ensure the safety of the conversion. In C++/CX, a compile time and runtime check are performed. For more information, see Casting.

The static_cast operator can be used for operations such as converting a pointer to a base class to a pointer to a derived class. Such conversions are not always safe.

In general you use static_cast when you want to convert numeric data types such as enums to ints or ints to floats, and you are certain of the data types involved in the conversion. static_cast conversions are not as safe as dynamic_cast conversions, because static_cast does no run-time type check, while dynamic_cast does. A dynamic_cast to an ambiguous pointer will fail, while a static_cast returns as if nothing were wrong; this can be dangerous. Although dynamic_cast conversions are safer, dynamic_cast only works on pointers or references, and the run-time type check is an overhead. For more information, see dynamic_cast Operator.

In the example that follows, the line D* pd2 = static_cast<D*>(pb); is not safe because D can have fields and methods that are not in B. However, the line B* pb2 = static_cast<B*>(pd); is a safe conversion because D always contains all of B.
C++

// static_cast_Operator.cpp
// compile with: /LD
class B {};

class D : public B {};

void f(B* pb, D* pd) {
   D* pd2 = static_cast<D*>(pb);   // Not safe, D can have fields
                                   // and methods that are not in B.

   B* pb2 = static_cast<B*>(pd);   // Safe conversion, D always
                                   // contains all of B.
}

In contrast to dynamic_cast, no run-time check is made on the static_cast conversion of pb. The object pointed to by pb may not be an object of type D, in which case the use of *pd2 could be disastrous. For instance, calling a function that is a member of the D class, but not the B class, could result in an access violation.

The dynamic_cast and static_cast operators move a pointer throughout a class hierarchy. However, static_cast relies exclusively on the information provided in the cast statement and can therefore be unsafe. For example:
C++

// static_cast_Operator_2.cpp
// compile with: /LD /GR
class B {
public:
   virtual void Test(){}
};
class D : public B {};

void f(B* pb) {
   D* pd1 = dynamic_cast<D*>(pb);
   D* pd2 = static_cast<D*>(pb);
}

If pb really points to an object of type D, then pd1 and pd2 will get the same value. They will also get the same value if pb == 0.

If pb points to an object of type B and not to the complete D class, then dynamic_cast will know enough to return zero. However, static_cast relies on the programmer's assertion that pb points to an object of type D and simply returns a pointer to that supposed D object.

Consequently, static_cast can do the inverse of implicit conversions, in which case the results are undefined. It is left to the programmer to verify that the results of a static_cast conversion are safe.

This behavior also applies to types other than class types. For instance, static_cast can be used to convert from an int to a char. However, the resulting char may not have enough bits to hold the entire int value. Again, it is left to the programmer to verify that the results of a static_cast conversion are safe.

The static_cast operator can also be used to perform any implicit conversion, including standard conversions and user-defined conversions. For example:
C++

// static_cast_Operator_3.cpp
// compile with: /LD /GR
typedef unsigned char BYTE;

void f() {
   char ch;
   int i = 65;
   float f = 2.5;
   double dbl;

   ch = static_cast<char>(i);   // int to char
   dbl = static_cast<double>(f);   // float to double
   i = static_cast<BYTE>(ch);
}

The static_cast operator can explicitly convert an integral value to an enumeration type. If the value of the integral type does not fall within the range of enumeration values, the resulting enumeration value is undefined.

The static_cast operator converts a null pointer value to the null pointer value of the destination type.

Any expression can be explicitly converted to type void by the static_cast operator. The destination void type can optionally include the const, volatile, or __unaligned attribute.

The static_cast operator cannot cast away the const, volatile, or __unaligned attributes. See const_cast Operator for information on removing these attributes.

C++/CLI: Due to the danger of performing unchecked casts on top of a relocating garbage collector, the use of static_cast should only be in performance-critical code when you are certain it will work correctly. If you must use static_cast in release mode, substitute it with safe_cast in your debug builds to ensure success.
