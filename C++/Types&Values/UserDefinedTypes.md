User-defined types are types that the user can define:

Enumerations
The simplest of the user-defined types. The values
that an enumeration can take are restricted to a set of possible values. Enumerations are excellent for modeling categorical concepts.

Structures
The simplest kind of classes that only contain data are plain-old-data classes (PODs) often called Structures.

Unions A boutique user-defined type. All members share the same memory location. Unions are dangerous and easy to misuse.











# Enumerations

There are situations where a particular variable should be allowed to accept only a certain set of values. These are situations where you don’t want the colors in the rainbow to contain Turquoise or the directions on a compass to contain Left.

In both these cases, you need a type of variable whose values are restricted to a certain set defined by you. Enumerations are exactly the tool you need in this situation.

Enumerations comprise a set of constants called enumerators.

Declare enumerations using the keyword enum followed by the type name and a listing of the values it can take.

These values are arbitrary alphanumeric strings that will represent whatever categories you want to represent. Under the hood, these values are simply integers, but they allow you to write safer, more expressive code by using programmer-defined types rather than integers that could mean anything

Syntax:
enum enum-name { list of names } var-list;

RainbowColors as an unscoped enumeration:

enum RainbowColors
{
Violet,
Indigo,
Blue,
Green,
Yellow,
Orange,
Red
} color;


color = Red;


To define an enumeration type, you need the following items:
? A name for the data type
? A set of values for the data type
? A set of operations on the values
C11 lets you define a new simple data type wherein you specify its name and values,
but not the operations. Preventing users from creating their own operations helps to
avoid potential system failures.
The values that you specify for the data type must be identifiers.
This section may be skipped without any loss of continuity.

The syntax for enumeration type is:
enum typeName {value1, value2, ...};

in which value1, value2, . . . are identifiers called enumerators. In C11, enum is
a reserved word.
By listing all of the values between the braces, you also specify an ordering between
the values. That is, value1 < value2 < value3 <.... Thus, the enumeration type
is an ordered set of values. Moreover, the default value assigned to these enumerators
starts at 0. That is, the default value assigned to value1 is 0, the default value assigned
to value2 is 1, and so on. (You can assign different values—other than the default
values—for the enumerators when you define the enumeration type.) Also notice that
the enumerators value1, value2, . . . are not variables.


Declaring Variables
Once a data type is defined, you can declare variables of that type. The syntax for
declaring variables of an enum type is the same as before:
The statement:
enum sports {BASKETBALL, FOOTBALL, HOCKEY, BASEBALL, SOCCER,
VOLLEYBALL};
defines an enumeration type called sports. The statement:
sports popularSport, mySport;
declares popularSport and mySport to be variables of type sports.
Assignment
Once a variable is declared, you can store values in it. Assuming the previous
declaration, the statement:
popularSport = FOOTBALL;
stores FOOTBALL in popularSport. The statement:
mySport = popularSport;
copies the value of popularSport into mySport.


Operations on Enumeration Types
No arithmetic operations are allowed on the enumeration type.

Suppose you want to increment the value of popularSport by 1. You can use the cast
operator as follows:
popularSport = static_cast<sports>(popularSport + 1);
When the type name is used, the compiler assumes that the user understands what
he or she is doing. Thus, the preceding statement is compiled, and during execution,
it advances the value of popularSport to the next value in the list. Consider the following statements:
popularSport = FOOTBALL;
popularSport = static_cast<sports>(popularSport + 1);
After the second statement, the value of popularSport is HOCKEY. Similarly, the
statements:
popularSport = FOOTBALL;
popularSport = static_cast<sports>(popularSport - 1);
result in storing BASKETBALL in popularSport.

Relational Operators
Because an enumeration is an ordered set of values, the relational operators can be
used with the enumeration type. Once again, suppose you have the enumeration type
sports and the variables popularSport and mySport as defined earlier. Then:
FOOTBALL <= SOCCER is true
HOCKEY > BASKETBALL is true
BASEBALL < FOOTBALL is false
Suppose that:
popularSport = SOCCER;
mySport = VOLLEYBALL;472 | Chapter 7: User-Defined Simple Data Types, Namespaces, and the string Type
Then:
popularSport < mySport is true
ENUMERATION TYPES AND LOOPS
Recall that the enumeration type is an integral type and that, using the cast operator
(that is, type name), you can increment, decrement, and compare the values of the
enumeration type. Therefore, you can use these enumeration types in loops. Suppose
mySport is a variable as declared earlier. Consider the following for loop:
for (mySport = BASKETBALL; mySport <= SOCCER; mySport =
static_cast<sports>(mySport + 1))
...
This for loop has five iterations.
Using enumeration types in loops increases the readability of the program.


Declaring Variables When Defining the Enumeration Type

C11 allows you to combine these two steps into one. That is, you
can declare variables of an enumeration type when you define an enumeration type.
For example, the statement:
enum grades {A, B, C, D, F} courseGrade;
defines an enumeration type, grades, and declares a variable courseGrade of type
grades.

Anonymous Data Types
A data type wherein you directly specify values in the variable declaration with no
type name is called an anonymous type. The following statement creates an anonymous type:
enum {BASKETBALL, FOOTBALL, BASEBALL, HOCKEY} mySport;
This statement specifies the values and declares a variable mySport, but no name is
given to the data type.

Creating an anonymous type, however, has drawbacks. First, because there is no
name for the type, you cannot pass an anonymous type as a parameter to a function,
and a function cannot return an anonymous type value. Second, values used in one
anonymous type can be used in another anonymous type, but variables of those types
are treated differently. Consider the following statements:
enum {ENGLISH, FRENCH, SPANISH, GERMAN, RUSSIAN} languages;
enum {ENGLISH, FRENCH, SPANISH, GERMAN, RUSSIAN} foreignLanguages;
Even though the variables languages and foreignLanguages have the same values,
the compiler treats them as variables of different types. The following statement is,
therefore, illegal:
languages = foreignLanguages; //Illegal
Even though these facilities are available, use them with care. To avoid confusion, first
define an enumeration type and then declare the variables.




















# Plain-Old-Data Classes
Classes are user-defined types that contain data and functions, and they’re the heart and soul of C++. PODs are simple containers. Think of them as a sort of heterogeneous array of elements of potentially different types.

PODs are often called Structures.

struct: A collection of a fixed number of components in which the components are accessed by name.

In C++, struct is a reserved word.
Every Structure begins with the keyword struct followed by the Structures desired name. Next, you list the members’ types and names.

Each element of a class is called a member. The members of a struct, even though enclosed in braces (that is, they form a block), are not considered to form a compound statement. Thus, a semicolon (after the right brace) is essential to end the struct statement.
A semicolon at the end of the struct is, therefore, a part of the syntax.



General struct syntax:

struct [structure tag] {
   member definition;
   member definition;
   ...
   member definition;
} [one or more structure variables];  


Consider the following Book class declaration with four members:
struct Book {
  char name[256];
  int year;
  int pages;
  bool hardcover;
};


You declare POD variables just like any other variables: by type and name.

Like any type definition, a struct is a definition, not a declaration. That is, it defines
only a data type; no memory is allocated.
Once a data type is defined, you can declare variables of that type:

Book book1;

The memory allocated is large enough to store all of the structs members.

You can also declare struct variables when you define the struct by following the closing } with any number of identifiers.

Typically, in a program, a struct is defined before the definitions of all the functions in
the program, so that the struct can be used throughout the program. Therefore, if you
define a struct and also simultaneously declare a struct variable (as in the preceding statements), then that struct variable becomes a global variable and thus can be
accessed anywhere in the program. Keeping in mind the side effects of global variables,
you should first only define a struct and then declare the struct variables.


### Accessing Members
You can then access members of the variable using the dot operator (.). In C++, the dot (.) is an operator called the member access operator:

structVariableName.memberName

#include <cstdio>
struct Book {
  char name[256];
  int year;
  int pages;
  bool hardcover;
};
int main() {
  Book neuromancer;
  neuromancer.pages = 271;
  printf("Neuromancer has %d pages.", neuromancer.pages);
}

PODs have some useful low-level features: they’re C compatible, you can employ machine instructions that are highly efficient to copy or move them, and they can be efficiently represented in memory.
C++ guarantees that members will be sequential in memory, although some implementations require members to be aligned along word boundaries, which depend on
CPU register length. As a general rule, you should order members from largest to
smallest within POD definitions.


### Assignment
We can assign the value of one struct variable to another struct variable of the same type by using an assignment statement.


Comparison (Relational Operators)
To compare struct variables, you compare them member-wise, by accessing and comparing the values of similar members. No aggregate relational operations are performed on a struct.



## Pointers to Structures
You can define pointers to structures in very similar way as you define pointer to any other variable:

struct [struct type] *[struct pointer name];

Now, you can store the address of a structure variable in the above defined pointer variable. To find the address of a structure variable, place the & operator before the structure's name as follows −

[struct pointer name] = &[struct name];




## Access Operators
If you have a pointer firstWoman to an instance of class Human, you can either use the pointer operator (->) to access members, or use the indirection operator (*) to reference the object following the dot operator.

Human* firstWoman = new Human();
(*firstWoman).IntroduceSelf();

If an object has been instantiated on the free store using new or if you have a pointer to an object, then you use the pointer operator (->) to access the member attributes and functions

To access the members of a structure using a pointer to that structure, you must use the -> operator as follows −

[struct name]->[struct member];


Human* firstWoman = new Human();
firstWoman->dateOfBirth = "1970";
firstWoman->IntroduceSelf();
delete firstWoman;

What is a better way to access members: using the dot operator (.) or using the pointer operator (->)?

A If you have a pointer to an object, the pointer operator would be best suited. If you have instantiated an object as a local variable on the stack, then the dot operator is best suited.




struct Variables and Functions
A struct variable can be passed as a parameter either by value or by
reference, and
A function can return a value of type struct.

Recall that when a variable is passed by value, the formal parameter copies the value
of the actual parameter. Therefore, if the formal parameter modifies the data, the
modification has no effect on the data of the actual parameter.
Suppose that a struct has several data members requiring a large amount of memory to store the data, and you need to pass a variable of that struct type by value.
The corresponding formal parameter then receives a copy of the data of the variable.
The compiler must then allocate memory for the formal parameter in order to copy
the value of the actual parameter. This operation might require, in addition to a large
amount of storage space, a considerable amount of computer time to copy the value
of the actual parameter into the formal parameter.
On the other hand, if a variable is passed by reference, the formal parameter receives
only the address of the actual parameter. Therefore, an efficient way to pass a variable as a parameter is by reference. If a variable is passed by reference, then when the
formal parameter changes, the actual parameter also changes. Sometimes, however,
you do not want the function to be able to change the values of the actual parameter.
In C11, you can pass a variable by reference and still prevent the function from
changing its value. This is done by using the keyword const in the formal parameter
declaration






## Struct Example
struct Vector {
int sz; // number of elements
double∗ elem; // pointer to elements
};

This first version of Vector consists of an int and a double∗.

A variable of type Vector can be defined like this:

Vector v;

However, by itself that is not of much use because v’s elem pointer doesn’t point to anything. For it to be useful, we must give v some elements to point to. For example, we can construct a Vector like
this:

void vector_init(Vector& v, int s)
{
v.elem = new double[s]; // allocate an array of s doubles
v.sz = s;
}

That is, v’s elem member gets a pointer produced by the new operator and v’s sz member gets the number of elements. The & in Vector& indicates that we pass v by non-const reference (§1.7); that way, vector_init() can modify the vector passed to it.

The new operator allocates memory from an area called the free store (also known as dynamic memory and heap). Objects allocated on the free store are independent of the scope from which they are created and ‘‘live’’ until they are destroyed using the delete operator.




A simple use of Vector looks like this:
double read_and_sum(int s)
// read s integers from cin and return their sum; s is assumed to be positive
{
Vector v;
vector_init(v,s); // allocate s elements for v
for (int i=0; i!=s; ++i)
cin>>v.elem[i]; // read into elements
double sum = 0;
for (int i=0; i!=s; ++i)
sum+=v.elem[i]; // compute the sum of the elements
return sum;
}

We use . (dot) to access struct members through a name (and through a reference) and −> to
access struct members through a pointer. For example:
void f(Vector v, Vector& rv, Vector∗ pv)
{
int i1 = v.sz; // access through name
int i2 = rv.sz; // access through reference
int i3 = pv−>sz; // access through pointer
}


## Access Controls
Access controls restrict member access.

Information can be classified into at least two categories: public data that we don’t mind the public knowing
private data that we would like to make private.

C++ enables you to model class attributes and methods as public or private.

Keywords public and private

Public and private are the two major access controls. Anyone can access a public member, but only members can access private members. All struct members are public by default.



#include <iostream>
using namespace std;

//structure definition with private and public memebers
struct Student
{
    private:
        int rNo;
        float perc;
    public:
        //function to read details
        void read(void)
        {
            cout<<"Enter roll number: ";
            cin>>rNo;
            cout<<"Enter percentage: ";
            cin>>perc;
        }
        //function to print details
        void print(void)
        {
            cout<<endl;
            cout<<"Roll number: "<<rNo<<endl;
            cout<<"Pecentage: "<<perc<<"%"<<endl;
        }
};

//Main code
int main()
{
    //declaring structure variable
    struct Student student;
    //reading and printing student details
    //by calling public member functions of the structure
    student.read();
    student.print();

    return 0;
}

Output:
Enter roll number: 101
Enter percentage: 84.02

Roll number: 101
Pecentage: 84.02%

Public member functions read() and print() are accessing private data members rNo and perc. And the public member functions are calling within the main() function using the structure variable named student.
































# Unions
A union is a special class type where only one of the non-static data members is active at a time.

A union is a struct in which all members are allocated at the same address so that the union occupies only as much space as its largest member. Naturally, a union can hold a value for only one
member at a time.

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