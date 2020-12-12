## Overview
putchar is recommended to write a single char to stdint

putc  is recommended to write a character to an arbitrary stream

fputc is guaranteed to be a function, thus we can take its address. This allows us to pass the address of fputc as an argument to another function.
Calls to fputc probably take longer than calls to outc, as it usually takes more time to call a function.

puts Writes a C string to stdout and appends a newline character ('\n').

fputs differs from puts in that the destination stream can be specified, but also fputs does not write additional characters, while puts appends a newline character at the end automatically.

all functions are accessed by an #include <stdio.h>



## putc

int putc ( int character, FILE * stream );

Write character to stream
Writes a character to the stream and advances the position indicator.

The character is written at the position indicated by the internal position indicator of the stream, which is then automatically advanced by one.

putc and fputc are equivalent, except that putc may be implemented as a macro in some libraries. See putchar for a similar function that writes directly to stdout.

Parameters

character
    The int promotion of the character to be written.
    The value is internally converted to an unsigned char when written.
    Because some libraries may implement this function as a macro, and this may evaluate the stream expression more than once, this should be an expression without side effects.
stream
    Pointer to a FILE object that identifies an output stream.


Return Value
On success, the character written is returned.
If a writing error occurs, EOF is returned and the error indicator (ferror) is set.

/* putc example: alphabet writer */
#include <stdio.h>

int main ()
{
  FILE * pFile;
  char c;

  pFile=fopen("alphabet.txt","wt");
  for (c = 'A' ; c <= 'Z' ; c++) {
    putc (c , pFile);
    }
  fclose (pFile);
  return 0;
}


## putchar

int putchar ( int character );

Write character to stdout
Writes a character to the standard output (stdout).

It is equivalent to calling putc with stdout as second argument.

Parameters

character
    The int promotion of the character to be written.
    The value is internally converted to an unsigned char when written.


Return Value
On success, the character written is returned.
If a writing error occurs, EOF is returned and the error indicator (ferror) is set.

/* putchar example: printing the alphabet */
#include <stdio.h>

int main ()
{
  char c;
  for (c = 'A' ; c <= 'Z' ; c++) putchar (c);

  return 0;
}



## fputc

int fputc ( int character, FILE * stream );

Write character to stream
Writes a character to the stream and advances the position indicator.

The character is written at the position indicated by the internal position indicator of the stream, which is then automatically advanced by one.

Parameters

character
    The int promotion of the character to be written.
    The value is internally converted to an unsigned char when written.
stream
    Pointer to a FILE object that identifies an output stream.


Return Value
On success, the character written is returned.
If a writing error occurs, EOF is returned and the error indicator (ferror) is set.

/* fputc example: alphabet writer */
#include <stdio.h>

int main ()
{
  FILE * pFile;
  char c;

  pFile = fopen ("alphabet.txt","w");
  if (pFile!=NULL) {

    for (c = 'A' ; c <= 'Z' ; c++)
      fputc ( c , pFile );

    fclose (pFile);
  }
  return 0;
}



## puts

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



## fputs

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
