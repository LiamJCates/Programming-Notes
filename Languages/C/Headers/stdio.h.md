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
