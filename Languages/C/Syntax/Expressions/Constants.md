Constants
Constants refer to fixed values that the program may not alter during its execution. Constants can be of any of the basic data types. Constants are treated just like regular variables except that their values cannot be modified after their definition.



We have seen some variables now let us see some constants. There are five categories of constants: character, integer, floating-point, string, and enumeration constant. We will see enumeration constants later first we see remaining four types of constants. There are certain rules about constants. Commas and spaces are not allowed except for character and string constants. Their range cannot outgrow the range of there data type. For numeric type of stants they can have a leading (-)minus sign.


Defining Constants

There are two simple ways in C to define constants −

    Using #define preprocessor.

    Using const keyword.





The #define Preprocessor

Form #define preprocessor to define a constant −
#define identifier value

Example
#include <stdio.h>

#define LENGTH 10   
#define WIDTH  5
#define NEWLINE '\n'

int main() {
   int area;  

   area = LENGTH * WIDTH;
   printf("value of area : %d", area);
   printf("%c", NEWLINE);

   return 0;
}

Result
value of area : 50





The const Keyword
The qualifier const can be prefixed to the declaration of any variable to specify that its value will not be changed.

For an array, the const qualifier says that the elements will not be altered.

const type variable = value;

Example

#include <stdio.h>

int main() {
   const int  LENGTH = 10;
   const int  WIDTH = 5;
   const char NEWLINE = '\n';
   int area;  

   area = LENGTH * WIDTH;
   printf("value of area : %d", area);
   printf("%c", NEWLINE);

   return 0;
}

result

value of area : 50

Note that it is a good programming practice to define constants in CAPITALS.



Constant Expression
A constant expression is an expression that involves only constants. Such expressions may be evaluated during compilation rather than run-time, and accordingly may be used in any place that a constant can occur, as in

#define MAXLINE 1000
char line[MAXLINE+1];

or

#define LEAP 1 /* in leap years */
int days[31+28+LEAP+31+30+31+30+31+31+30+31+30+31];
