Character String I/O Functions

These functions are very simple compared to printf() and scanf(). They take a pointer to a character array or a character pointer and fill it with input or print it to monitor. Note that gets() and puts() work only with stdin and stdout respectively while fgets() and fputs() work with FILE streams. They can read and write to file streams that is. Here is a sample program:

// Author: Shiv S. Dayal
// Description : Demo of string i/o
#include <stdio.h>
#include <stdlib.h>

int main()
{
  char cStack[1024] = "";
  char *cHeap = (char*)malloc(sizeof(1024));

  gets(cStack);
  puts(cStack);

  cHeap = fgets(cHeap, 1024, stdin);
  fputs(cHeap, stdout);

  return 0;
}

and the output is:

Hi!
Hi!
Hello!
Hello!

First "Hi!" and "Hello!" are keyboard inputs. Do not worry about array and pointer syntax at the moment. Just see the difference between function calls. Their is a problem with gets() that it can cause buffer overflow. If input is bigger than 1024 bytes including the null terminator then buffer overflow will happen. Note how you can prevent it with fgets() by specifying the number of characters you want to read. Rest of input will be ignored by fgets(). This is a security hole and therefore you should never ever use gets().
