For definition without an initializer: variables with static storage duration are implicitly initialized with NULL (all bytes have the value 0); the initial value of all other variables are undefined.


An explicitly initialized automatic variable is initialized each time the function or block it is in is entered; the initializer may be any
expression. External and static variables are initialized to zero by default.
Automatic variables for which there is no explicit initializer have undefined
(i.e., garbage) values.






Initializing Arrays

You can initialize an array in C either one by one or using a single statement as follows −

double balance[5] = {1000.0, 2.0, 3.4, 7.0, 50.0};

The number of values between braces { } cannot be larger than the number of elements that we declare for the array between square brackets [ ].

If you omit the size of the array, an array just big enough to hold the initialization is created. Therefore, if you write −

double balance[] = {1000.0, 2.0, 3.4, 7.0, 50.0};

You will create exactly the same array as you did in the previous example.



Initializing Two-Dimensional Arrays

Multidimensional arrays may be initialized by specifying bracketed values for each row. Following is an array with 3 rows and each row has 4 columns.

int a[3][4] = {  
   {0, 1, 2, 3} ,   /*  initializers for row indexed by 0 */
   {4, 5, 6, 7} ,   /*  initializers for row indexed by 1 */
   {8, 9, 10, 11}   /*  initializers for row indexed by 2 */
};

The nested braces, which indicate the intended row, are optional. The following initialization is equivalent to the previous example −

int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};






String initialization
The following declaration and initialization create a string consisting of the word "Hello".

char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};

If you follow the rule of array initialization then you can write the above statement as follows −

char greeting[] = "Hello";

The C compiler automatically places the '\0' at the end of the string when it initializes the array.








Initializing Local and Global Variables

When a local variable is defined, it is not initialized by the system, you must initialize it yourself. Global variables are initialized automatically by the system when you define them as follows −
int 	0
char 	'\0'
float 	0
double 	0
pointer 	NULL

It is a good programming practice to initialize variables properly, otherwise your program may produce unexpected results, because uninitialized variables will take some garbage value already available at their memory location.

In the absence of explicit initialization, external and static variables are guaranteed to be initialized to zero;

Absent explicit initialization, automatic and register variables have undefined (i.e., garbage)  initial values


Scalar variables may be initialized when they are defined, by following the name with an equals sign and an expression:

For external and static variables, the initializer must be a constant expression;
the initialization is done once, conceptually before the program begins execution.

For automatic and register variables, initialization is done each time
the block is entered

For automatic and register variables, the initializer is not restricted to being a constant: it may be any expression involving previously defined values, even function calls.

When the size of the array is omitted, the compiler will compute the length by counting the initializers,


If there are fewer initializers for an array than the number specified, the missing elements will be zero for external, static, and automatic variables.

It is an error to have more initializers than the array declaration indicates

Character arrays are a special case of initialization; a string may be used instead of
the braces and commas notation:
