# Unions
A union is a special class type where only one of the non-static data members is active at a time.

A union is a struct in which all members are allocated at the same address so that the union occupies only as much space as its largest member. Naturally, a union can hold a value for only one member at a time.

The union is a cousin of the POD that puts all of its members in the same place. You can think of unions as different views or interpretations of a block of memory.

Declaring a Union
A union is declared using keyword union, followed by the name of the union and its data members within braces:
 union UnionName
 {
 Type1 member1;
 Type2 member2;
 …
 TypeN memberN;
 };

 You would instantiate and use a union like this:
 UnionName unionObject;
 unionObject.member2 = value; // choose member2 as the active member

Similar to the struct, the members of a union are public by default. Unlike a struct, however, unions cannot be used in inheritance hierarchies.

Additionally, the sizeof() a union is always fixed as the size of the largest member contained in the union—even if that member were inactive in an instance of the union.

Example declare a union: simply use the union keyword instead of struct.
union Variant {
  char string[10];
  int integer;
  double floating_point;
};


It takes up only as much memory as its largest member (probably string in
this case).
You use the dot operator (.) to specify a union’s interpretation.
Syntactically, this looks like accessing a member of a POD, but it’s completely different under the hood.
Because all members of a union are in the same place, you can cause
data corruption very easily.

#include <cstdio>
union Variant {
  char string[10];
  int integer;
  double floating_point;
};

int main() {
  Variant v;
  v.integer = 42;
  printf("The ultimate answer: %d\n", v.integer);
  v.floating_point = 2.7182818284;
  printf("Euler's number e: %f\n", v.floating_point);
  printf("A dumpster fire: %d\n", v.integer);
}


Where Would You Use a union?
the main problem with unions: it’s up to you to keep track of
which interpretation is appropriate. The compiler won’t help you.
You should avoid using unions in all but the rarest of cases

Often a union is used as a member of a struct to model a complex data type. In some implementations, the ability of a union to interpret the fixed memory space as another type is used for type conversions or memory reinterpretation—a practice that is controversial and not necessary given alternatives.

They can be useful in some low-level situations, such as when marshalling structures that must be consistent across architectures, dealing with type-checking issues related to C/C++ interoperation, and even when packing bitfields.
