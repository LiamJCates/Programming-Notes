getc

getchar
getchar() only reads from standard input while getc() can read from any input stream. So getchar() is equivalent to getc(stdin).

getch
getch() is a nonstandard function and is present in conio.h header file which is mostly used by MS-DOS compilers like Turbo C. It is not part of the C standard library or ISO C, nor is it defined by POSIX (Source: http://en.wikipedia.org/wiki/Conio.h)
Like above functions, it reads also a single character from keyboard. But it does not use any buffer, so the entered character is immediately returned without waiting for the enter key.

getche
Like getch(), this is also a non-standard function present in conio.h. It reads a single character from the keyboard and displays immediately on output screen without waiting for enter key.




puts

int puts ( const char * str );

Write string to stdout
Writes the C string pointed by str to the standard output (stdout) and appends a newline character ('\n').

The function begins copying from the address specified (str) until it reaches the terminating null character ('\0'). This terminating null-character is not copied to the stream.

Notice that puts not only differs from fputs in that it uses stdout as destination, but it also appends a newline character at the end automatically (which fputs does not).

Parameters

str
    C string to be printed.


Return Value
On success, a non-negative value is returned.
On error, the function returns EOF and sets the error indicator (ferror).

/* puts example : hello world! */
#include <stdio.h>

int main ()
{
  char string [] = "Hello world!";
  puts (string);
}





fputs

int fputs ( const char * str, FILE * stream );

Write string to stream
Writes the C string pointed by str to the stream.

The function begins copying from the address specified (str) until it reaches the terminating null character ('\0'). This terminating null-character is not copied to the stream.

Notice that fputs not only differs from puts in that the destination stream can be specified, but also fputs does not write additional characters, while puts appends a newline character at the end automatically.

Parameters

str
    C string with the content to be written to stream.
stream
    Pointer to a FILE object that identifies an output stream.


Return Value
On success, a non-negative value is returned.
On error, the function returns EOF and sets the error indicator (ferror).

/* fputs example */
#include <stdio.h>

int main ()
{
   FILE * pFile;
   char sentence [256];

   printf ("Enter sentence to append: ");
   fgets (sentence,256,stdin);
   pFile = fopen ("mylog.txt","a");
   fputs (sentence,pFile);
   fclose (pFile);
   return 0;
}
