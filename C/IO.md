Character Input and Output

Text input or output, regardless of where it originates or where it goes to,
is dealt with as streams of characters, A text stream is a sequence of characters divided into lines; each line consists of zero or more characters followed by a newline character.

Every text stream has at least one character; a newline with length 1

The standard library provides several functions for reading or writing one
character at a time, of which getchar and putchar are the simplest.

getchar reads the next input character from a text stream
and returns that as its value.

putchar prints a character each time it is called

char c = getchar();

putchar(c);

File Copying
Given getchar and putchar, you can write a surprising amount of useful code without knowing anything more about input and output.

The simplest example is a program that copies its input to its output one character at a time:

read a character
while (character is not end-of-file indicator)
  output the character just read
  read a character

#include <stdio.h>

main(){
  int c;

  c = getchar();

  while(c != EOF){
    putchar(c);
    c = getchar();
  }
}

The problem is distinguishing the end of the input from valid data. The
solution is that getchar returns a distinctive value when there is no more
input, a value that cannot be confused with any real character. This value is
called EOF,for "end of file." We must declare c to be a type big enough to
hold any value that getchar returns. We can't use char since c must be big
enough to hold EOFin addition to any possible char. Therefore we use into
EOFis an integer defined in <stdio. h>, but the specific numeric value
doesn't matter as long as it is not the same as any char value. By using the
symbolic constant, we are assured that nothing in the program depends on the
specific numeric value.



We can shorten the last example by moving the assignment into the
#include <stdio.h>

main(){
  int c;

  while((c = getchar()) != EOF)
    putchar(c);

}



Character Counting

main(){
  double nc;

  for(nc = 0; getchar() != EOF; ++nc);

  printf("%.0f\n", nc);
}



Line Counting

 #include <stdio.h>

main(){
  int c, nl = 0;

  while((c = getchar()) != EOF)
    if(c == '\n')
      ++nl;
  printf("%d\n", nl);
}




Word Counting


 #include <stdio.h>

 #define IN 1   //Inside a word
 #define OUT 0  //Outside a word

main(){
  int c, nl, nw, nc, state;

  state = OUT;

  nl = nw = nc = 0;
  while((c = getchar()) != EOF){
    ++nc;
    if (c == '\n')
      ++nl;
    if (c == ' ', || c == '\n' || c = = '\t')
      state = OUT;
    else if (state == OUT) {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc)
}






Print Longest Line

#include <stdio.h>
#define MAXLINE 1000

int getline(char line[], int maxline);
void copy(char to[], char from[]);

main(){
  int len;
  int max;
  char current_line[MAXLINE];
  char longest_line[MAXLINE];

  max = 0;

  while((len = getline(current_line)) > 0){
    if(len > max) {
      max = len;
      copy(current_line, longest_line);
    }
  }
  if(max > 0)
    printf("%s", longest);

  return 0;
}

getline(char s[]){
  int c, i;

  i = 0;
  while (i < MAXLINE-1 && (c=getchar()) != EOF && c != '\n')
    s[i++] = c;

  if(c == '\n')
    s[i++] = c;

  s[i] = '\0';
  return i;
}

void copy(char to[], char from[]){
  int i;
  for(i = 0;(to[i] = from[i]) != '\0'; ++i);
}











The scanf() and printf() Functions

The int scanf(const char *format, ...) function reads the input from the standard input stream stdin and scans that input according to the format provided.

The int printf(const char *format, ...) function writes the output to the standard output stream stdout and produces the output according to the format provided.

The format can be a simple constant string, but you can specify %s, %d, %c, %f, etc., to print or read strings, integer, character or float respectively. There are many other formatting options available which can be used based on requirements. Let us now proceed with a simple example to understand the concepts better −

#include <stdio.h>
int main( ) {

   char str[100];
   int i;

   printf( "Enter a value :");
   scanf("%s %d", str, &i);

   printf( "\nYou entered: %s %d ", str, i);

   return 0;
}

When the above code is compiled and executed, it waits for you to input some text. When you enter a text and press enter, then program proceeds and reads the input and displays it as follows −

$./a.out
Enter a value : seven 7
You entered: seven 7

Here, it should be noted that scanf() expects input in the same format as you provided %s and %d, which means you have to provide valid inputs like "string integer". If you provide "string string" or "integer integer", then it will be assumed as wrong input. Secondly, while reading a string, scanf() stops reading as soon as it encounters a space, so "this is test" are three strings for scanf().








File I/O

The last chapter explained the standard input and output devices handled by C programming language. This chapter cover how C programmers can create, open, close text or binary files for their data storage.

A file represents a sequence of bytes, regardless of it being a text file or a binary file. C programming language provides access on high level functions as well as low level (OS level) calls to handle file on your storage devices. This chapter will take you through the important calls for file management.
Opening Files

You can use the fopen( ) function to create a new file or to open an existing file. This call will initialize an object of the type FILE, which contains all the information necessary to control the stream. The prototype of this function call is as follows −

FILE *fopen( const char * filename, const char * mode );

Here, filename is a string literal, which you will use to name your file, and access mode can have one of the following values −
Sr.No. 	Mode & Description
1 	

r

Opens an existing text file for reading purpose.
2 	

w

Opens a text file for writing. If it does not exist, then a new file is created. Here your program will start writing content from the beginning of the file.
3 	

a

Opens a text file for writing in appending mode. If it does not exist, then a new file is created. Here your program will start appending content in the existing file content.
4 	

r+

Opens a text file for both reading and writing.
5 	

w+

Opens a text file for both reading and writing. It first truncates the file to zero length if it exists, otherwise creates a file if it does not exist.
6 	

a+

Opens a text file for both reading and writing. It creates the file if it does not exist. The reading will start from the beginning but writing can only be appended.

If you are going to handle binary files, then you will use following access modes instead of the above mentioned ones −

"rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"

Closing a File

To close a file, use the fclose( ) function. The prototype of this function is −

int fclose( FILE *fp );

The fclose(-) function returns zero on success, or EOF if there is an error in closing the file. This function actually flushes any data still pending in the buffer to the file, closes the file, and releases any memory used for the file. The EOF is a constant defined in the header file stdio.h.

There are various functions provided by C standard library to read and write a file, character by character, or in the form of a fixed length string.
Writing a File

Following is the simplest function to write individual characters to a stream −

int fputc( int c, FILE *fp );

The function fputc() writes the character value of the argument c to the output stream referenced by fp. It returns the written character written on success otherwise EOF if there is an error. You can use the following functions to write a null-terminated string to a stream −

int fputs( const char *s, FILE *fp );

The function fputs() writes the string s to the output stream referenced by fp. It returns a non-negative value on success, otherwise EOF is returned in case of any error. You can use int fprintf(FILE *fp,const char *format, ...) function as well to write a string into a file. Try the following example.

Make sure you have /tmp directory available. If it is not, then before proceeding, you must create this directory on your machine.

#include <stdio.h>

main() {
   FILE *fp;

   fp = fopen("/tmp/test.txt", "w+");
   fprintf(fp, "This is testing for fprintf...\n");
   fputs("This is testing for fputs...\n", fp);
   fclose(fp);
}

When the above code is compiled and executed, it creates a new file test.txt in /tmp directory and writes two lines using two different functions. Let us read this file in the next section.
Reading a File

Given below is the simplest function to read a single character from a file −

int fgetc( FILE * fp );

The fgetc() function reads a character from the input file referenced by fp. The return value is the character read, or in case of any error, it returns EOF. The following function allows to read a string from a stream −

char *fgets( char *buf, int n, FILE *fp );

The functions fgets() reads up to n-1 characters from the input stream referenced by fp. It copies the read string into the buffer buf, appending a null character to terminate the string.

If this function encounters a newline character '\n' or the end of the file EOF before they have read the maximum number of characters, then it returns only the characters read up to that point including the new line character. You can also use int fscanf(FILE *fp, const char *format, ...) function to read strings from a file, but it stops reading after encountering the first space character.

#include <stdio.h>

main() {

   FILE *fp;
   char buff[255];

   fp = fopen("/tmp/test.txt", "r");
   fscanf(fp, "%s", buff);
   printf("1 : %s\n", buff );

   fgets(buff, 255, (FILE*)fp);
   printf("2: %s\n", buff );

   fgets(buff, 255, (FILE*)fp);
   printf("3: %s\n", buff );
   fclose(fp);

}

When the above code is compiled and executed, it reads the file created in the previous section and produces the following result −

1 : This
2: is testing for fprintf...

3: This is testing for fputs...

Let's see a little more in detail about what happened here. First, fscanf() read just This because after that, it encountered a space, second call is for fgets() which reads the remaining line till it encountered end of line. Finally, the last call fgets() reads the second line completely.
Binary I/O Functions

There are two functions, that can be used for binary input and output −

size_t fread(void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

size_t fwrite(const void *ptr, size_t size_of_elements, size_t number_of_elements, FILE *a_file);

Both of these functions should be used to read or write blocks of memories - usually arrays or structures.
