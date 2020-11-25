A structure is a collection of one or more variables, possibly of different
types, grouped together under a single name for convenient handling. (Structures are called "records" in some languages, notably Pascal.) Structures help
to organize complicated data, particularly in large programs, because they permit a group of related variables to be treated as a unit instead of as separate
entities.

Defining a Structure

To define a structure, you must use the struct statement. The struct statement defines a new data type, with one or more members:

struct [structure tag] {

   member definition;
   member definition;
   ...
   member definition;
} [structure variables];  

The structure tag is optional and each member definition is a normal variable definition, such as int i; or float f; or any other valid variable definition. At the end of the structure's definition, before the final semicolon, you can specify one or more structure variables.

The variables named in a structure are called members. A structure
member or tag and an ordinary (i.e., non-member) variable can have the same
name without conflict, since they can always be distinguished by context.
Furthermore, the same member names may occur in different structures,
although as a matter of style one would normally use the same names only for
closely related objects.


A struct declaration defines a type. The right brace that terminates the
list of members may be followedby a list of variables, just as for any basic type.
That is,
struct { ...} x, y, Z;

is syntactically analogous to

int x, y, Z;

in the sense that each statement declares x, y and z to be variables of the
named type and causes space to be set aside for them.


A structure declaration that is not followed by a list of variables reserves no
storage; it merely describes a template or the shape of a structure. If the
declaration is tagged, however, the tag can be used later in definitions of
instances of the structure.


Here is the way you would declare the Book structure −

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
} book;  

For example, given the declaration above


struct Books book1;

defines a variable book1 which is a structure of type struct point.

Initialzing Structures
A structure can be initialized by following its definition with a list of initializers, each a constant expression, for the members:

struct Books book1 = {"Title", "Author", "Subject", 123};

An automatic structure may also be initialized by assignment or by calling a function that returns a structure of the right type.


Accessing Structure Members

To access any member of a structure, we use the member access operator (.). The member access operator is coded as a period between the structure variable name and the structure member that we wish to access.

structure-name.member


Structure Operations
The only legal operations on a structure are copying it or assigning to it as a unit, taking its address with &, and accessing its members. Copy and assignment include passing arguments to functions and returning values from functions as well. Structures may not be compared. A structure may be initialized
by a list of constant member values; an automatic structure may also be initialized by an assignment.



Structure Pointers

struct [struct tag] *name;

says that "name" is a pointer to a structure of type "struct tag".

If pp points to a point structure, *pp is the structure, and (*pp). x and (*pp).y are the members

The parentheses are necessary in (*pp).x because the precedence of the structure member operator . is higher than *. The expression *pp. x means * (pp . x) , which is illegal here because x is not a pointer.

Pointers to structures are so frequently used that an alternative notation is provided as a shorthand called arrow notation

If p is a pointer to a structure, use p->member-of-structure to reference a member

So if p is a pointer with memebers x and y, we could write instead
printf("origin is (%d,%d)\n", p->x, p->y);

IF we have this declaration
struct rect r, *rp = &r;
these four expressions are equivalent

r.pt1.x
rp->pt1.x
(r. pt 1).x
(rp->pt1).x


The structure operators . and ->, together with () for function calls and [] for subscripts, are at the top of the precedence hierarchy and thus bind very tightly


For example, given the declaration
struct {
  int len;
  char *str;
} *p;

then

++p->len;

increments len, not p, because the implied parenthesization is ++(p->len). Parentheses can be used to alter the binding: (++p)->len increments p before accessing len, and (p++) -> len increments p afterward.

In the same way, *p->str fetches whatever str points to; *p->str++
increments str after accessing whatever it points to (just like *s++);
(*p->str )++ increments whatever str points to; and *p++->str increments p after accessing whatever str points to.








Structures as Function Arguments
Functions manipulate through at least three possible approaches:
pass components separately
pass an entire structure
pass a pointer to it.

You can pass a structure as a function argument in the same way as you pass any other variable or pointer. If a large structure is to be passed to a function, it is generally more efficient to pass a pointer than to copy the whole structure.

Example
#include <stdio.h>
#include <string.h>

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

/* function declaration */
void printBook( struct Books book );

int main( ) {

   struct Books Book1;        /* Declare Book1 of type Book */
   struct Books Book2;        /* Declare Book2 of type Book */

   /* book 1 specification */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;

   /* print Book1 info */
   printBook( Book1 );

   /* Print Book2 info */
   printBook( Book2 );

   return 0;
}

void printBook( struct Books book ) {

   printf( "Book title : %s\n", book.title);
   printf( "Book author : %s\n", book.author);
   printf( "Book subject : %s\n", book.subject);
   printf( "Book book_id : %d\n", book.book_id);
}

When the above code is compiled and executed, it produces the following result −

Book title : C Programming
Book author : Nuha Ali
Book subject : C Programming Tutorial
Book book_id : 6495407
Book title : Telecom Billing
Book author : Zara Ali
Book subject : Telecom Billing Tutorial
Book book_id : 6495700









Pointers to Structures

You can define pointers to structures in the same way as you define pointer to any other variable −

struct Books *struct_pointer;

Now, you can store the address of a structure variable in the above defined pointer variable. To find the address of a structure variable, place the '&'; operator before the structure's name as follows −

struct_pointer = &Book1;

To access the members of a structure using a pointer to that structure, you must use the → operator as follows −

struct_pointer->title;

Let us re-write the above example using structure pointer.

#include <stdio.h>
#include <string.h>

struct Books {
   char  title[50];
   char  author[50];
   char  subject[100];
   int   book_id;
};

/* function declaration */
void printBook( struct Books *book );
int main( ) {

   struct Books Book1;        /* Declare Book1 of type Book */
   struct Books Book2;        /* Declare Book2 of type Book */

   /* book 1 specification */
   strcpy( Book1.title, "C Programming");
   strcpy( Book1.author, "Nuha Ali");
   strcpy( Book1.subject, "C Programming Tutorial");
   Book1.book_id = 6495407;

   /* book 2 specification */
   strcpy( Book2.title, "Telecom Billing");
   strcpy( Book2.author, "Zara Ali");
   strcpy( Book2.subject, "Telecom Billing Tutorial");
   Book2.book_id = 6495700;

   /* print Book1 info by passing address of Book1 */
   printBook( &Book1 );

   /* print Book2 info by passing address of Book2 */
   printBook( &Book2 );

   return 0;
}

void printBook( struct Books *book ) {

   printf( "Book title : %s\n", book->title);
   printf( "Book author : %s\n", book->author);
   printf( "Book subject : %s\n", book->subject);
   printf( "Book book_id : %d\n", book->book_id);
}

When the above code is compiled and executed, it produces the following result −

Book title : C Programming
Book author : Nuha Ali
Book subject : C Programming Tutorial
Book book_id : 6495407
Book title : Telecom Billing
Book author : Zara Ali
Book subject : Telecom Billing Tutorial
Book book_id : 6495700








Bit Fields

Bit Fields allow the packing of data in a structure. This is especially useful when memory or data storage is at a premium. Typical examples include −

    Packing several objects into a machine word. e.g. 1 bit flags can be compacted.

    Reading external file formats -- non-standard file formats could be read in, e.g., 9-bit integers.

C allows us to do this in a structure definition by putting :bit length after the variable. For example −

struct packed_struct {
   unsigned int f1:1;
   unsigned int f2:1;
   unsigned int f3:1;
   unsigned int f4:1;
   unsigned int type:4;
   unsigned int my_int:9;
} pack;

Here, the packed_struct contains 6 members: Four 1 bit flags f1..f3, a 4-bit type and a 9-bit my_int.

C automatically packs the above bit fields as compactly as possible, provided that the maximum length of the field is less than or equal to the integer word length of the computer. If this is not the case, then some compilers may allow memory overlap for the fields while others would store the next field in the next word.


Suppose your C program contains a number of TRUE/FALSE variables grouped in a structure called status, as follows −

struct {
   unsigned int widthValidated;
   unsigned int heightValidated;
} status;

This structure requires 8 bytes of memory space but in actual, we are going to store either 0 or 1 in each of the variables. The C programming language offers a better way to utilize the memory space in such situations.

If you are using such variables inside a structure then you can define the width of a variable which tells the C compiler that you are going to use only those number of bytes. For example, the above structure can be re-written as follows −

struct {
   unsigned int widthValidated : 1;
   unsigned int heightValidated : 1;
} status;

The above structure requires 4 bytes of memory space for status variable, but only 2 bits will be used to store the values.

If you will use up to 32 variables each one with a width of 1 bit, then also the status structure will use 4 bytes. However as soon as you have 33 variables, it will allocate the next slot of the memory and it will start using 8 bytes. Let us check the following example to understand the concept −
Live Demo

#include <stdio.h>
#include <string.h>

/* define simple structure */
struct {
   unsigned int widthValidated;
   unsigned int heightValidated;
} status1;

/* define a structure with bit fields */
struct {
   unsigned int widthValidated : 1;
   unsigned int heightValidated : 1;
} status2;

int main( ) {
   printf( "Memory size occupied by status1 : %d\n", sizeof(status1));
   printf( "Memory size occupied by status2 : %d\n", sizeof(status2));
   return 0;
}

When the above code is compiled and executed, it produces the following result −

Memory size occupied by status1 : 8
Memory size occupied by status2 : 4

Bit Field Declaration

The declaration of a bit-field has the following form inside a structure −

struct {
   type [member_name] : width ;
};

The following table describes the variable elements of a bit field −
Sr.No. 	Element & Description
1 	

type

An integer type that determines how a bit-field's value is interpreted. The type may be int, signed int, or unsigned int.
2 	

member_name

The name of the bit-field.
3 	

width

The number of bits in the bit-field. The width must be less than or equal to the bit width of the specified type.

The variables defined with a predefined width are called bit fields. A bit field can hold more than a single bit; for example, if you need a variable to store a value from 0 to 7, then you can define a bit field with a width of 3 bits as follows −

struct {
   unsigned int age : 3;
} Age;

The above structure definition instructs the C compiler that the age variable is going to use only 3 bits to store the value. If you try to use more than 3 bits, then it will not allow you to do so. Let us try the following example −
Live Demo

#include <stdio.h>
#include <string.h>

struct {
   unsigned int age : 3;
} Age;

int main( ) {

   Age.age = 4;
   printf( "Sizeof( Age ) : %d\n", sizeof(Age) );
   printf( "Age.age : %d\n", Age.age );

   Age.age = 7;
   printf( "Age.age : %d\n", Age.age );

   Age.age = 8;
   printf( "Age.age : %d\n", Age.age );

   return 0;
}

When the above code is compiled it will compile with a warning and when executed, it produces the following result −

Sizeof( Age ) : 4
Age.age : 4
Age.age : 7
Age.age : 0
