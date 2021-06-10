printf

The prototype of printf is given by

int printf(const char* fmt, ...);

Let us take a minute to understand this as we have not yet covered functions. The first word is int which denotes the return type of the printf function. This is no. of characters printed. Then we have name of the function. fmt is the format string of type const char. In C, strings are either character arrays or character pointers. Here, const means printf will not modify the format string. The ... means variable no. of arguments, which can be 0 also, to be supplied to printf.

printf is a string based output function that is It writes character strings to stdout. The data which has to be written is formatted by format string as shown previously. After the format specifier it expects as many arguments as specified in format string. The characters which are not like, say %d for example, arecalled ordinary characters. These are simply copied to output stream, which, is stdout for printf. The %d like conversion characters are known as conversion specification or format specifiers. Each conversion specification should be augmented with one one argument. The results are undefined if there are insufficient arguments for the format. If extra arguments are given the excess arguments will be evaluated but are otherwise ignored. However, there is a big problem here! There is no type-safety.:-( In general compiler will warn you about it and you, the programmer, are responsible for giving correct format string, correct no. of correct type of arguments. Consider the following program for example:

```c
#include <stdio.h>

int main()
{
  printf("%d %d\n", 3, 8);

  //do not mess it. undefined behavior
  printf("%d %d\n", 5);

  //extra arguments ignored
  printf("%d %d\n", 3, 5, "hello");

  //legal because char is integer type
  printf("%d\n", 's');

  //wrap around of integer as char
  printf("%c\n", 836);

  //do not mess with type-safety
  int i = printf("%d\n", "hello");
  prinf("%d\n", i);

  return 0;
}
```

now that if you give the command like gcc printf.c then you will be shown following warnings:

```
printf.c:12:14: warning: more '%' conversions than data arguments [-Wformat]
        printf("%d %d\n", 5);
                 ~^
printf.c:15:26: warning: data argument not used by format string [-Wformat-extra-args]
        printf("%d %d\n", 3, 5, "hello");
             ~~~~~~~~~        ^
printf.c:24:19: warning: conversion specifies type 'int' but the argument has type
'char *' [-Wformat]
      int i = printf("%d\n", "hello");
                      ~^     ~~~~~~~
                      %s
3 warnings generated.
```

Clearly this is not a good sign for any program. A program should compile cleanly. In our case compiler is generating binary even though there are warnings. You can make compiler generate more warnings by issuing a -Wall flag. You can also treat all warnings as errors by passing -Werror to compiler. These two options will ensure that your code has no warnings. Now let us move to output and try to understand it. The output on my system is as given below. It may differ on your system:

3 8
5 8
3 5
115
D
134514119
10

First printf is correct as expected. The second line causes undefined behavior. You may think it is the previous 8 but believe me it is not guaranteed that it will always the case. Ii is UNDEFINED. Third printf is also fine in the sense that extra argument is ignored. Fourth and fifth are normal. Sixth is again a big problem. You are trying to print a decimal integer while argument is a character string. There is no way for compiler to determine that what should be printed which will fit on standards. Now we will have to take a look at all possible format specifier and their meanings. You have seen most of them so this is more for a reference. I have taken following from http://www3.opengroup.org and modified to suit the book. In particular, I have omitted facts related to XSI specification.

A full detail of all conversion specification is given in specification at The fprintf function §(iso.7.21.6.1), which lists fprintf function but conversion specifiers are same as printf.

In real-world most of the time the conversion specifiers are kept simple. Given below is a sample program showing some of the things given above:

I suggest you to read the desciption of conversion specifiers and experiment with various parameters to get different kind of output.
