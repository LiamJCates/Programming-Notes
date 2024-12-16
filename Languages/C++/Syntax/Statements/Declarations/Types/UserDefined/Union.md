### Unions

A union is a special class type where only one of the non-static data members is active at a time.

Unions allow one portion of memory to be accessed as different data types. Its declaration and use is similar to that of structures, but its functionality is totally different.

A union's members are allocated at the same address so that the union occupies only as much space as its largest member. Naturally, a union can hold a value for only one member at a time.

The union is a cousin of the POD that puts all of its members in the same place. You can think of unions as different views or interpretations of a block of memory.


### Declaring a Union

A union is declared using keyword union, followed by the name of the union and its data members within braces:

  union type_name {
  member_type1 member_name1;
  member_type2 member_name2;
  ...
  member_typeN member_nameN;
  } object_names;

This creates a new union type, identified by type_name, in which all its member elements occupy the same physical space in memory.

You would instantiate and use a union like this:

  type_name unionObject;
  unionObject.member2 = value; // choose member2 as the active member

You use the dot operator (.) to specify a union’s interpretation. Syntactically, this looks like accessing a member of a POD, but it’s completely different under the hood.

Similar to the struct, the members of a union are public by default. Unlike a struct, however, unions cannot be used in inheritance hierarchies.

The size of this type is the one of the largest member element. For example:

  union mytypes_t {
    char c;
    int i;
    float f;
  } mytypes;

declares an object (mytypes) with three members:

  mytypes.c
  mytypes.i
  mytypes.f

Each of these members is of a different data type. But since all of them are referring to the same location in memory, the modification of one of the members will affect the value of all of them. It is not possible to store different values in them in a way that each is independent of the others.

One of the uses of a union is to be able to access a value either in its entirety or as an array or structure of smaller elements. For example:

  union mix_t {
    int l;
    struct {
      short hi;
      short lo;
      } s;
    char c[4];
  } mix;

If we assume that the system where this program runs has an int type with a size of 4 bytes, and a short type of 2 bytes, the union defined above allows the access to the same group of 4 bytes: mix.l, mix.s and mix.c, and which we can use according to how we want to access these bytes: as if they were a single value of type int, or as if they were two values of type short, or as an array of char elements, respectively.

The exact alignment and order of the members of a union in memory depends on the system, with the possibility of creating portability issues.

Additionally, the sizeof() a union is always fixed as the size of the largest member contained in the union — even if that member were inactive in an instance of the union.

Because all members of a union are in the same place, you can cause data corruption very easily.

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



### Anonymous unions
When unions are members of a class (or structure), they can be declared with no name. In this case, they become anonymous unions, and its members are directly accessible from objects by their member names. For example, see the differences between these two structure declarations:

structure with regular union

  struct book1_t {
    char title[50];
    char author[50];
    union {
      float dollars;
      int yen;
    } price;
  } book1;


structure with anonymous union

  struct book2_t {
    char title[50];
    char author[50];
    union {
      float dollars;
      int yen;
    };
  } book2;


The only difference between the two types is that in the first one, the member union has a name (price), while in the second it has not. This affects the way to access members dollars and yen of an object of this type. For an object of the first type (with a regular union), it would be:

  book1.price.dollars
  book1.price.yen

whereas for an object of the second type (which has an anonymous union), it would be:

  book2.dollars
  book2.yen

Again, remember that because it is a member union (not a member structure), the members dollars and yen actually share the same memory location, so they cannot be used to store two different values simultaneously. The price can be set in dollars or in yen, but not in both simultaneously.



### Where Would You Use a union?

the main problem with unions: it’s up to you to keep track of which interpretation is appropriate. The compiler won’t help you. You should avoid using unions in all but the rarest of cases

Often a union is used as a member of a struct to model a complex data type. In some implementations, the ability of a union to interpret the fixed memory space as another type is used for type conversions or memory reinterpretation—a practice that is controversial and not necessary given alternatives.

They can be useful in some low-level situations, such as when marshalling structures that must be consistent across architectures, dealing with type-checking issues related to C/C++ interoperation, and even when packing bitfields.
