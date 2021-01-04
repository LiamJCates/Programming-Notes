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
C++ lets you define a new simple data type wherein you specify its name and values,
but not the operations. Preventing users from creating their own operations helps to
avoid potential system failures.
The values that you specify for the data type must be identifiers.
This section may be skipped without any loss of continuity.

The syntax for enumeration type is:
enum typeName {value1, value2, ...};

in which value1, value2, . . . are identifiers called enumerators. In C++, enum is
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

C++ allows you to combine these two steps into one. That is, you
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
