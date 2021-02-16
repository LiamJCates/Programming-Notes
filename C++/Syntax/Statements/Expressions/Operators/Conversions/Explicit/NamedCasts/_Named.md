### Named Conversion
Named conversions are language features that explicitly convert one type into
another type. You use named conversions sparingly in situations where you
cannot use implicit conversions or constructors to get the types you need.
All named conversions accept a single object parameter, which is the
object you want to cast object-to-cast, and a single type parameter, which is
the type you want to cast to desired-type:

named-conversion<desired-type>(object-to-cast)

There are casting operators specific to the C++ language, intended to remove some of the ambiguity and danger inherent in old style C language casts.

These operators are:
  dynamic_cast Used for conversion of polymorphic types.
  static_cast Used for conversion of nonpolymorphic types.
  const_cast Used to remove the const, volatile, and __unaligned attributes.
  reinterpret_cast Used for simple reinterpretation of bits.
  safe_cast Used in C++/CLI to produce verifiable MSIL.


You can use type casts to explicitly convert types.

Syntax

cast-expression:
    unary expression
    ( type-name ) cast-expression

type-name:
    specifier-qualifier-list abstract-declarator opt

The type-name is a type and cast-expression is a value to be converted to that type. An expression with a type cast is not an l-value. The cast-expression is converted as though it had been assigned to a variable of type type-name. The conversion rules for assignments (outlined in Assignment Conversions) apply to type casts as well. The following table shows the types that can be cast to any given type.
