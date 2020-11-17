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



















# Plain-Old-Data Classes
Classes are user-defined types that contain data and functions, and they’re the heart and soul of C++. PODs are simple containers. Think of them as a sort of heterogeneous array of elements of potentially different types.

PODs are often called Structures.

Every Structure begins with the keyword struct followed by the Structures desired name. Next, you list the members’ types and names.
Each element of a class is called a member.

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
You can then access members of the variable using the dot operator (.).

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
