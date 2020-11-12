Pointers
Some C programming tasks are performed more easily with pointers, and other tasks, such as dynamic memory allocation, cannot be performed without using pointers.

every variable is a memory location and every memory location has a defined address.

A pointer is a variable whose value is the address of another variable, i.e., direct address of the memory location. Like any variable or constant, you must declare a pointer before using it to store any variable address.

The general form of a pointer variable declaration is −

type *var-name;

Here, type is the pointer's base type; it must be a valid C data type and var-name is the name of the pointer variable.

how do you declare a pointer
int    *ip;    /* pointer to an integer */
double *dp;    /* pointer to a double */
float  *fp;    /* pointer to a float */
char   *ch     /* pointer to a character */


The actual data type of the value of all pointers, whether integer, float, character, or otherwise, is the same, a long hexadecimal number that represents a memory address. The only difference between pointers of different data types is the data type of the variable or constant that the pointer points to.


Using Pointers
To use pointer we can
(a) define a pointer variable,
(b) assign the address of a variable to a pointer
(c) access the value at the address available in the pointer variable.

To do this the unary operators * and & are used.

The unary operator * is the indirection or dereferencing operator; when applied to a pointer, it accesses the object the pointer points to.

The unary operator & gives the address of an object. The & operator only applies to objects in memory: variables and array elements. It cannot be applied to expressions, constants, or register variables.

  int  var = 20;   /* actual variable declaration */
  int  *ip;        /* pointer variable declaration */

  ip = &var;  /* store address of var in pointer variable*/

Address of var variable: bffd8b3c
Address stored in ip variable: bffd8b3c
Value of *ip variable: 20

int x = 1, y, z[10];
int *ip;               /* ip is a pointer to int */
ip = &x;               /* ip now points to x */
y = *ip;               /* y is now 1 */
*ip = 0;               /* x is now 0 */
ip = &z[O];            /* ip now points to z[O] */

If ip points to the integer x, then *ip can occur in any context where x could

The unary operators * and & bind more tightly than arithmetic operators, so the assignment
y = *ip + 1

takes whatever ip points at, adds 1, and assigns the result to y, while

*ip += 1

increments what ip points to, as do

++*ip

and

(*ip)++

The parentheses are necessary in this last example; without them, the expression
would increment ip instead of what it points to, because unary operators like *
and ++ associate right to left.
Finally, since pointers are variables, they can be used without dereferencing.
For example, if iq is another pointer to int,

iq = ip

copies the contents of ip into iq, thus making iq point to whatever ip pointed to.








Pointers and Function Arguments
Since C passes arguments to functions by value, there is no direct way for the called function to alter a variable in the calling function.

To declare an integer pointer as a function parameter
void funtion_name(int *x){
}

to call function_name with the address of a variable var:
int var;
function_name(&var);

Example
For instance, a sorting routine might exchange two out-of-order elements with a function called swap. It is not enough to write

int a = 2, b =1;
swap(a, b);

where the swap function is defined as

void swap(int x, int y) 1* WRONG *1
{
  int temp;

  temp = x;
  x = y;
  y = temp;
}

Because of call by value, swap can't affect the arguments a and b in the routine that called it. The function above only swaps copies of a and b.
The way to obtain the desired effect is for the calling program to pass
pointers to the values to be changed:

swap (&a, &b);

Since the operator & produces the address of a variable, &a is a pointer to a. In swap itself, the parameters are declared to be pointers, and the operands are accessed indirectly through them

void swap(int *px, int *py)
{
  int temp;

  temp = *px;
  *px = *py;
  *py = temp;
}




NULL Pointers

It is always a good practice to assign a NULL value to a pointer variable if it cannot otherwise be initialized. This is done at the time of variable declaration. A pointer that is assigned NULL is called a null pointer.

The NULL pointer is a constant with a value of zero defined in several standard libraries.


Typically, programs are not permitted to access memory at address 0 because that memory is reserved by the operating system.

However, the memory address 0 has special significance; it signals that the pointer is not intended to point to an accessible memory location.

But by convention, if a pointer contains the null (zero) value, it is assumed to point to nothing.

To check for a null pointer, you can use an 'if' statement as follows −
if(ptr)     /* succeeds if p is not null */
if(!ptr)    /* succeeds if p is null */


Function prototype for a pointer parameter
void function_name(type *parameter_name);

Pointers allow C, which is pass by value, to mutate data without
the use of global variables

#include <stdio.h>
#include <time.h>

void getSeconds(unsigned long *par);

int main () {
   unsigned long sec;
   getSeconds( &sec );
   /* print the actual value */
   printf("Number of seconds: %ld\n", sec );
   return 0;
}

void getSeconds(unsigned long *par) {
   /* get the current number of seconds */
   *par = time( NULL );
   return;
}




Pointers to an Array in C
Any operation that can be achieved by array subscripting can also be done with pointers. The pointer version will in general be faster but, at least to the uninitiated, somewhat harder to understand.


An array name is a constant pointer to the first element of the array. Therefore, in the declaration −

double balance[50];

balance is a pointer to &balance[0], which is the address of the first element of the array balance. Thus, the following program fragment assigns p as the address of the first element of balance −

double *p;
double balance[10];

p = balance;

It is legal to use array names as constant pointers, and vice versa. Therefore, *(balance + 4) is a legitimate way of accessing the data at balance[4].

Once you store the address of the first element in 'p', you can access the array elements using *p, *(p+1), *(p+2) and so on.

a reference to a[i] can also be written as *(a+i). In evaluating a[i], C converts it to *(a+i) immediately; the two forms are equivalent. Applying the operator & to both parts of this equivalence, it follows that &a[i] and a+i are also identical: a+i is the address of the i-th element beyond a.

As well, if pa is a pointer, expressions may use it with a subscript; pa[i] is identical to *(pa+i).

In short, an array-and-index expression is equivalent to one written as a pointer and offset.

For
int *pa, a[];
A pointer is a variable, so pa = a and pa++ are legal.
An array name is not a variable; so a = pa and a++ are illegal



It is possible to pass part of an array to a function, by passing a pointer to the beginning of the subarray. For example, if a is an array,
f(&a[2])

and f(a+2)

both pass to the function f the address of the subarray that starts at a [ 2 ].

Within f, the parameter declaration can read
f(int arr[]) { ... }
or
f(int *arr) { ... }

As formal parameters in a function definition, both are equivalent.

So as far as f is concerned, the fact that the parameter refers to part of a larger array is of no consequence

If one is sure that the elements exist, it is also possible to index backwards in
an array; p[-1], p[-2], and so on are syntactically legal, and refer to the elements that immediately precede p[ 0 ]. Of course, it is illegal to refer to objects
that are not within the array bounds.


Pointer Arithmetic
If p is a pointer to some element of an array, then p++ increments p to point to the next element, and p+=i increments it to point i elements beyond where it currently does.

A pointer in C is an address, which is a numeric value. Therefore, you can perform arithmetic operations on a pointer just as you can on a numeric value. There are four arithmetic operators that can be used on pointers: ++, --, +, and -

To understand pointer arithmetic, let us consider that ptr is an integer pointer which points to the address 1000. Assuming 32-bit integers, let us perform the following arithmetic operation on the pointer −

ptr++

After the above operation, the ptr will point to the location 1004 because each time ptr is incremented, it will point to the next integer location which is 4 bytes next to the current location. This operation will move the pointer to the next memory location without impacting the actual value at the memory location. If ptr points to a character whose address is 1000, then the above operation will point to the location 1001 because the next character will be available at 1001.

All the pointer manipulations automatically take into account the size of the object pointed to

The valid pointer operations are assignment of pointers of the same type, adding or subtracting a pointer and an integer, subtracting or comparing two pointers to members of the same array, and assigning or comparing to zero. All other pointer arithmetic is illegal. It is not legal to add two pointers, or to multiply or divide or shift or mask them, or to add float or double to them, or even, except for void *, to assign a pointer of one type to a pointer of another type without a cast.


Incrementing a Pointer
We may use a pointer in our program instead of an array because the variable pointer can be incremented, unlike the array name which cannot be incremented because it is a constant pointer.

Decrementing a Pointer

The same considerations apply to decrementing a pointer, which decreases its value by the number of bytes of its data type



The following program increments the variable pointer to access each succeeding element of the array −
#include <stdio.h>

const int MAX = 3;

int main () {

   int  var[] = {10, 100, 200};
   int  i, *ptr;

   /* let us have array address in pointer */
   ptr = var;

   for ( i = 0; i < MAX; i++) {

      printf("Address of var[%d] = %x\n", i, ptr );
      printf("Value of var[%d] = %d\n", i, *ptr );

      /* move to the next location */
      ptr++;
   }

   return 0;
}


Pointer Comparisons

Pointers may be compared by using relational operators, such as ==, <, and >.

Any pointer can be meaningfully compared for equality or inequality with zero. But the behavior is undefined for arithmetic or comparisons with pointers that do not point to members of the same array.

The following program modifies the previous example − one by incrementing the variable pointer so long as the address to which it points is either less than or equal to the address of the last element of the array, which is &var[MAX - 1] −


#include <stdio.h>

const int MAX = 3;

int main () {

   int  var[] = {10, 100, 200};
   int  i, *ptr;

   /* let us have address of the first element in pointer */
   ptr = var;
   i = 0;

   while ( ptr <= &var[MAX - 1] ) {

      printf("Address of var[%d] = %x\n", i, ptr );
      printf("Value of var[%d] = %d\n", i, *ptr );

      /* point to the next location */
      ptr++;
      i++;
   }

   return 0;
}




Void Pointer
You should also note the implication that a pointer is constrained to point to
a particular kind of object: every pointer points to a specific data type. (There
is one exception: a "pointer to void" is used to hold any type of pointer but
cannot be dereferenced itself.

A pointer of type void * represents the address of an object, but not its type. For example, a memory allocation function void *malloc( size_t size ); returns a pointer to void which can be casted to any data type.










Passing pointers
C programming allows passing a pointer to a function. To do so, simply declare the function parameter as a pointer type.





Returning a Pointer
C also allows to return a pointer from a function. To do so, you would have to declare a function returning a pointer as in the following example −

int * myFunction() {
   .
   .
   .
}

Second point to remember is that, it is not a good idea to return the address of a local variable outside the function, so you would have to define the local variable as static variable.








Character Pointers and functions
Perhaps the most common occurrence of string constants is as arguments to
functions, as in
printf( "hello, world\n");

When a character string like this appears in a program, access to it is through a
character pointer; printf receives a pointer to the beginning of the character
array. That is, a string constant is accessed by a pointer to its first element.
String constants need not be function arguments. If pmessaqe is declared

char *pmessage;

then the statement

pmessage = "now is the time";

assigns to pmessaqe a pointer to the character array. This is not a string
copy; only pointers are involved. C does not provide any operators for processing an entire string of characters as a unit.
There is an important difference between these definitions:

char amessage[] = "now is the time";
char *pmessage = "now is the time";

amessaqe is an array, just big enough to hold the sequence of characters and
,\0' that initializes it. Individual characters within the array may be changed
but amessaqe will always refer to the same storage. On the other hand,
pmessaqe is a pointer, initialized to point to a string constant; the pointer may
subsequently be modified to point elsewhere, but the result is undefined if you
try to modify the string contents.





Pointer to a Pointer
A pointer to a pointer is a form of multiple indirection, or a chain of pointers. Normally, a pointer contains the address of a variable. When we define a pointer to a pointer, the first pointer contains the address of the second pointer, which points to the location that contains the actual value

A variable that is a pointer to a pointer must be declared as such. This is done by placing an additional asterisk in front of its name. For example, the following declaration declares a pointer to a pointer of type int −

int **var;

When a target value is indirectly pointed to by a pointer to a pointer, accessing that value requires that the asterisk operator be applied twice





Pointer Arrays
Since pointers are variables themselves, they can be stored in arrays just as
other variables can.


Initialization of Pointer Arrays

Consider the problem of writing a function month_name (n), which returns
a pointer to a character string containing the name of the n-th month. This is
an ideal application for an internal static array. month_name contains a
private array of character strings, and returns a pointer to the proper one when
called. This section shows how that array of names is initialized.
The syntax is similar to previous initializations:

/* month_name: return name of n-th month */
char *month_name(int n)
{
  static char *name[] = {
    "Illegal month",
    "January", "February", "March",
    "April", "May", "June",
    "July", "August", "September",
    "October", "November", "December"
  };
  return (n < 1 || n > 12) ? name[0] : name[n];
}

The initializer is a list of character strings;
each is assigned to the corresponding position in the array. The characters of the i-th string are placed somewhere, and a pointer to them is stored in name [i]. Since the size of the array name is not specified, the compiler counts the initializers and fills in the correct number.

Pointers vs. Multi-dimensional Arrays
Newcomers to C are sometimes confused about the difference between a
two-dimensional array and an array of pointers, such as name in the example
above. Given the definitions
int a [10][20] ;
int *b[10];

then a [ 3] [4] and b [3 ] [4] are both syntactically legal references to a single
into But a is a true two-dimensional array: 200 int-sized locations have been
set aside, and the conventional rectangular subscript calculation 20xrow+col is
used to find the element a I[rowHcol]. For b, however, the definition only allocates 10 pointers and does not initialize them; initialization must be done explicitly, either statically or with code. Assuming that each element of b does point
to a twenty-element array, then there will be 200 ints set aside, plus ten cells
for the pointers. The important advantage of the pointer array is that the rows
of the array may be of different lengths. That is, each element of b need no

point to a twenty-element vector; some may point to two elements, some to fifty,
and some to none at all.
Although we have phrased this discussion in terms of integers, by far the
most frequent use of arrays of pointers is to store character strings of diverse
lengths, as in the function month_name.








Thus if the array day tab is to
be passed to a function f, the declaration of f would be
f (int daytab [2][13]) { ... }
It could also be
f (int daytab [][13]) { ... }

since the number of rows is irrelevant, or it could be
f (int (*daytab) [13]) { ... }

which says that the parameter is a pointer to an array of 13 integers. The
parentheses are necessary since brackets [] have higher precedence than *.
Without parentheses, the declaration
int *daytab[13]
is an array of 13 pointers to integers. More generally, only the first dimension
(subscript) of an array is free; all the others have to be specified.







Pointers to Functions

In C, a function itself is not a variable, but it is possible to define pointers to
functions, which can be assigned, placed in arrays, passed to functions, returned
by functions, and so on.


See The C Programming Language 2nd Edition Section 5.11 page 118 for a detailed example of pointers to Functions

5.12 Complicated Declarations Page 122
