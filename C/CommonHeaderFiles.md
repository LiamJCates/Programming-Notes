stdio.h

The header file stdio.h stands for Standard Input Output. It has the information related to input/output functions.

Here is the table that displays some of the functions in stdio.h in C language,

printf()
It is used to print the strings, integer, character etc on the output screen.

scanf()
It reads the character, string, integer etc from the keyboard.

getc()
It reads the character from the file.

putc()
It writes the character to the file.

fopen()
It opens the file and all file handling functions are defined in stdio.h header file.

fclose()
It closes the opened file.

remove()
It deletes the file.

fflush()
It flushes the file.

Example

#include<stdio.h>

int main () {
   char val;

   printf("Enter the character: \n");
   val = getc(stdin);
   printf("Character entered: ");
   putc(val, stdout);

   return(0);
}

Output

Enter the character: s
Character entered: s












stdlib.h

The header file stdlib.h stands for Standard Library. It has the information of memory allocation/freeing functions.

malloc()
It allocates the memory during execution of program.

free()
It frees the allocated memory.

abort()
It terminates the C program.

exit()
It terminates the program and does not return any value.

atol()
It converts a string to long int.

atoll()
It converts a string to long long int.

atof()
It converts a string to floating point value.

rand()
It returns a random integer value


Example

#include <stdio.h>
#include<stdlib.h>

int main() {
   char str1[20] = "53875";
   char str2[20] = "367587938";
   char str3[20] = "53875.8843";

   long int a = atol(str1);
   printf("String to long int : %d\n", a);

   long long int b = atoll(str2);
   printf("String to long long int : %d\n", b);

   double c = atof(str3);
   printf("String to long int : %f\n", c);
   printf("The first random value : %d\n", rand());
   printf("The second random value : %d", rand());

   return 0;
}

Output

String to long int : 53875
String to long long int : 367587938
String to long int : 53875.884300
The first random value : 1804289383
The second random value : 846930886









The standard headers <limits.h> and <float.h> contain
symbolic constants for float, double and long double of all three sizes.




string functions are declared in the standard header
<string.h>

strcpy(s1, s2);
Copies string s2 into string s1.


strcat(s1, s2);
Concatenates string s2 onto the end of string s1.


strlen(s1);
Returns the length of string s1.


strcmp(s1, s2);
Returns 0 if s1 and s2 are the same; less than 0 if s1<s2; greater than 0 if s1>s2.


strchr(s1, ch);
Returns a pointer to the first occurrence of character ch in string s1.


strstr(s1, s2);
Returns a pointer to the first occurrence of string s2 in string s1.



The standard header <ctype. h>, described in Appendix B, defines a family
of functions that provide tests and conversionsthat are independent of character
set.



In general, mathematical functions like those in <math.h> will use the double precision type
