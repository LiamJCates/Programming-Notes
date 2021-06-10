Single Character I/O

There are several functions for single character i/o. They are getc(), putc(), getchar(), putchar(), fgetc() and fputc(). Apart from getchar() and putchar() rest can do any FILE stream-based i/o. Let us see them as they are mostly trivial.

// Author: Shiv S. Dayal
// Description: Single character funciton demo
#include<stdio.h>

int main()
{
  char c ='';

  c = getchar();
  putchar(c);

  c = getchar();
  putchar(c);

  c = fgetc(stdin);
  fputc(c, stdout);

  c = getchar();
  putchar(c);

  c = getc(stdin);
  putc(c, stdout);

  return 0;
}

and the output is:

4
4
5
5
6
6

The first 4, 5 and 6 were keyboard inputs. Note the use of extra getchar() and putchar() to handle the situation we faced during scanf().
