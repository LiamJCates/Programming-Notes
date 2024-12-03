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
