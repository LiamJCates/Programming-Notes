## Overview

getchar is recommended to read a single char from stdint

getc is recommended to get a character from an arbitrary stream

fgetc is guaranteed to be a function, thus we can take its address. This allows us to pass the address of fgetc as an argument to another function.
Calls to fgetc probably take longer than calls to getc, as it usually takes more time to call a function.

gets Reads characters from the standard input (stdin) and stores them as a C string into str until a newline character or the end-of-file is reached.

fgets accepts arbitrary stream argument, but also allows to specify the maximum size of str and includes in the string any ending newline character.

all functions are accessed by an #include <stdio.h>



## getc
int getc ( FILE * stream );

Get character from stream
Returns the character currently pointed by the internal file position indicator of the specified stream. The internal file position indicator is then advanced to the next character.

getc and fgetc are equivalent, except that getc may be implemented as a macro in some libraries.

Parameters

stream
    Pointer to a FILE object that identifies an input stream.
    Because some libraries may implement this function as a macro, and this may evaluate the stream expression more than once, this should be an expression without side effects.


Return Value
On success, the character read is returned (promoted to an int value).
The return type is int to accommodate for the special value EOF, which indicates failure:
If the position indicator was at the end-of-file, the function returns EOF and sets the eof indicator (feof) of stream.
If some other reading error happens, the function also returns EOF, but sets its error indicator (ferror) instead.

#include <stdio.h>
int main ()
{
  FILE * pFile;
  int c;
  int n = 0;
  pFile=fopen ("myfile.txt","r");
  if (pFile==NULL) perror ("Error opening file");
  else
  {
    do {
      c = getc (pFile);
      if (c == '$') n++;
    } while (c != EOF);
    fclose (pFile);
    printf ("File contains %d$.\n",n);
  }
  return 0;
}



## getchar
getchar() only reads from standard input while getc() can read from any input stream. So getchar() is equivalent to getc(stdin).

#include <stdio.h>

int main () {
   char c;

   printf("Enter character: ");
   c = getchar();

   printf("Character entered: ");
   putchar(c);

   return(0);
}

getch
getch() is a nonstandard function and is present in conio.h header file.
It is not part of the C standard library or ISO C, nor is it defined by POSIX

It reads also a single character from keyboard. But it does not use any buffer, so the entered character is immediately returned without waiting for the enter key.

getche
Like getch(), this is also a non-standard function present in conio.h. It reads a single character from the keyboard and displays immediately on output screen without waiting for enter key.


## fgetc

int fgetc ( FILE * stream );

Get character from stream
Returns the character currently pointed by the internal file position indicator of the specified stream. The internal file position indicator is then advanced to the next character.

Parameters

stream
    Pointer to a FILE object that identifies an input stream.


Return Value
On success, the character read is returned (promoted to an int value).
The return type is int to accommodate for the special value EOF, which indicates failure:
If the position indicator was at the end-of-file, the function returns EOF and sets the eof indicator (feof) of stream.
If some other reading error happens, the function also returns EOF, but sets its error indicator (ferror) instead.


#include <stdio.h>
int main ()
{
  FILE * pFile;
  int c;
  int n = 0;
  pFile=fopen ("myfile.txt","r");
  if (pFile==NULL) perror ("Error opening file");
  else
  {
    do {
      c = fgetc (pFile);
      if (c == '$') n++;
    } while (c != EOF);
    fclose (pFile);
    printf ("The file contains %d dollar sign characters ($).\n",n);
  }
  return 0;
}


## getc vs fgetc
The difference between getc and fgetc is that getc can be implemented as a macro, whereas fgetc cannot be implemented as a macro. This means three things:

    The argument to getc should not be an expression with side effects.
    Since fgetc is guaranteed to be a function, we can take its address. This allows us to pass the address of fgetc as an argument to another function.
    Calls to fgetc probably take longer than calls to getc, as it usually takes more time to call a function.



## gets

char * gets ( char * str );

Get string from stdin
Reads characters from the standard input (stdin) and stores them as a C string into str until a newline character or the end-of-file is reached.

The newline character, if found, is not copied into str.

A terminating null character is automatically appended after the characters copied to str.

Notice that gets is quite different from fgets: not only gets uses stdin as source, but it does not include the ending newline character in the resulting string and does not allow to specify a maximum size for str (which can lead to buffer overflows).

Parameters

str
    Pointer to a block of memory (array of char) where the string read is copied as a C string.


Return Value
On success, the function returns str.
If the end-of-file is encountered while attempting to read a character, the eof indicator is set (feof). If this happens before any characters could be read, the pointer returned is a null pointer (and the contents of str remain unchanged).
If a read error occurs, the error indicator (ferror) is set and a null pointer is also returned (but the contents pointed by str may have changed).

Compatibility
The most recent revision of the C standard (2011) has definitively removed this function from its specification.
The function is deprecated in C++ (as of 2011 standard, which follows C99+TC3).


## fgets

char * fgets ( char * str, int num, FILE * stream );

Get string from stream
Reads characters from stream and stores them as a C string into str until (num-1) characters have been read or either a newline or the end-of-file is reached, whichever happens first.

A newline character makes fgets stop reading, but it is considered a valid character by the function and included in the string copied to str.

A terminating null character is automatically appended after the characters copied to str.

Notice that fgets is quite different from gets: not only fgets accepts a stream argument, but also allows to specify the maximum size of str and includes in the string any ending newline character.

Parameters

str
    Pointer to an array of chars where the string read is copied.
num
    Maximum number of characters to be copied into str (including the terminating null-character).
stream
    Pointer to a FILE object that identifies an input stream.
    stdin can be used as argument to read from the standard input.


Return Value
On success, the function returns str.
If the end-of-file is encountered while attempting to read a character, the eof indicator is set (feof). If this happens before any characters could be read, the pointer returned is a null pointer (and the contents of str remain unchanged).
If a read error occurs, the error indicator (ferror) is set and a null pointer is also returned (but the contents pointed by str may have changed).
