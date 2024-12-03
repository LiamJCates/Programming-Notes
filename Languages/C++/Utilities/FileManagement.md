how to create,
rename and delete files using the C++ Standard Library.
Here's working.cpp from chapter eight
of the exercise files.
We'll start by creating a file.
So I'm going to give it a file name.
We just call it file1,
and I will open the file in write mode,
file handle,
fopen
and the file name
and write mode.
And now that the file has been opened in write mode,
of course, if the file didn't exist,
the file will be created
and if file did exist, it will be empty.
It'll be overwritten with an empty file.
And so we'll just go ahead and close this now
because we have our file
and I'll just puts Done.
Like that.
And now when I build and run this,
you notice it says Done.
Now, how do I find my file?
Where is my file?
Well, on a Mac in Xcode,
you can control click on your result over here,
your working result,
and say Show in Finder.
And you'll notice if I control click up here,
I get the whole path.
See it's a crazy path.
This would be very hard to find on your own,
and that's why we have that Show in Finder over here.
And so here's our object file, it's our executable.
And here is the file that we just created.
And if I bring up the file info,
you'll notice that it is zero bytes.
It is an empty file.
Now, if I want to find the file on a PC,
here I have the same code in visual studio.
And you'll notice if I come over here to PowerShell
and I typed dir in my debug directory,
you'll notice I don't have any executable or anything
until I compile.
So I come back over here to visual studio
and I compile
using F7.
Now, when I type dir on my PowerShell,
you'll notice I have my executable working.exe,
and I can just say working.exe like this,
and it runs it.
And now when I type dir,
you'll notice
that there I have the file, file zero.
So it shows up right there in my debug directory
with my executable.
So now that we've found the file,
let's go ahead and rename it.
And so instead of opening it and closing it at this point,
what I'm going to do
is I'm going to create another file name.
And now I'm going to rename the file.
I'm going to say, rename
from the old file name, fn1,
to the new file name, fn2.
And I'll go ahead and I'll run this.
And now when I come out to finder,
you'll notice that I have file2 here instead of file1.
And if I want to remove the file altogether,
I now just have file2,
I can say remove instead of rename.
And when I build and run this
and come out here to finder,
you'll notice that my file is gone from my debug directory.
You'll have the same result on your windows PCs as well.
Both rename and remove
return zero on success or a non-zero value
if there's an error,
we'll look at how to read the return to error codes
in the lesson on handling system errors.
It's relatively simple to create,
delete and rename files using the C++ Standard Library,
and this is how you do that.






### FILE
Object containing information to control a stream

FILE is the object type that identifies a stream and contains the information needed to control it, including a pointer to its buffer, its position indicator and all its state indicators.

FILE objects are usually created by a call to either fopen or tmpfile, which both return a pointer to one of these objects.

The content of a FILE object is not meant to be accessed from outside the functions of the <cstdio> and <cwchar> headers; In fact, portable programs shall only use them in the form of pointers to identify streams, since for some implementations, even the value of the pointer itself could be significant to identify the stream (i.e., the pointer to a copy of a FILE object could be interpreted differently than a pointer to the original).

Its memory allocation is automatically managed: it is allocated by either fopen or tmpfile, and it is the responsibility of the library to free the resources once either the stream has been closed using fclose or the program terminates normally.

```cpp
/* FEOF example */
#include <stdio.h>

int main()
{
   FILE * pFile;
   char buffer [100];

   pFile = fopen ("myfile.txt" , "r");
   if (pFile == NULL) perror ("Error opening file");
   else
   {
     while ( !feof(pFile) )
     {
       if ( fgets (buffer , 100 , pFile) == NULL )
			 	break;
       fputs (buffer , stdout);
     }
     fclose (pFile);
   }
   return 0;
}
```


### fopen

Syntax:
	FILE * fopen ( const char * filename, const char * mode );

Opens the file whose name is specified in the parameter filename and associates it with a stream that can be identified in future operations by the FILE pointer returned.

The operations that are allowed on the stream and how these are performed are defined by the mode parameter.

The returned stream is fully buffered by default if it is known to not refer to an interactive device (see setbuf).

The returned pointer can be disassociated from the file by calling fclose or freopen. All opened files are automatically closed on normal program termination.


Parameters

filename
    C string containing the name of the file to be opened.
    Its value shall follow the file name specifications of the running environment and can include a path (if supported by the system).

mode

C string containing a file access mode. It can be:
  "r"	read: Open file for input operations. The file must exist.
  "w"	write: Create an empty file for output operations. If a file with the same name already exists, its contents are discarded and the file is treated as a new empty file.
  "a"	append: Open file for output at the end of a file. Output operations always write data at the end of the file, expanding it. Repositioning operations (fseek, fsetpos, rewind) are ignored. The file is created if it does not exist.
  "r+"	read/update: Open a file for update (both for input and output). The file must exist.
  "w+"	write/update: Create an empty file and open it for update (both for input and output). If a file with the same name already exists its contents are discarded and the file is treated as a new empty file.
  "a+"	append/update: Open a file for update (both for input and output) with all output operations writing data at the end of the file. Repositioning operations (fseek, fsetpos, rewind) affects the next input operations, but output operations move the position back to the end of file. The file is created if it does not exist.

With the mode specifiers above the file is open as a text file. In order to open a file as a binary file, a "b" character has to be included in the mode string. This additional "b" character can either be appended at the end of the string (thus making the following compound modes: "rb", "wb", "ab", "r+b", "w+b", "a+b") or be inserted between the letter and the "+" sign for the mixed modes ("rb+", "wb+", "ab+").

The new C standard (C2011, which is not part of C++) adds a new standard subspecifier ("x"), that can be appended to any "w" specifier (to form "wx", "wbx", "w+x" or "w+bx"/"wb+x"). This subspecifier forces the function to fail if the file exists, instead of overwriting it.

If additional characters follow the sequence, the behavior depends on the library implementation: some implementations may ignore additional characters so that for example an additional "t" (sometimes used to explicitly state a text file) is accepted.

On some library implementations, opening or creating a text file with update mode may treat the stream instead as a binary file.


Text files are files containing sequences of lines of text. Depending on the environment where the application runs, some special character conversion may occur in input/output operations in text mode to adapt them to a system-specific text file format. Although on some environments no conversions occur and both text files and binary files are treated the same way, using the appropriate mode improves portability.

For files open for update (those which include a "+" sign), on which both input and output operations are allowed, the stream shall be flushed (fflush) or repositioned (fseek, fsetpos, rewind) before a reading operation that follows a writing operation. The stream shall be repositioned (fseek, fsetpos, rewind) before a writing operation that follows a reading operation (whenever that operation did not reach the end-of-file).

Return Value
If the file is successfully opened, the function returns a pointer to a FILE object that can be used to identify the stream on future operations.
Otherwise, a null pointer is returned.
On most library implementations, the errno variable is also set to a system-specific error code on failure.

```cpp
/* fopen example */
#include <stdio.h>
int main ()
{
  FILE * pFile;
  pFile = fopen ("myfile.txt","w");
  if (pFile!=NULL)
  {
    fputs ("fopen example",pFile);
    fclose (pFile);
  }
  return 0;
}
```


#### fclose

Syntax:
	int fclose ( FILE * stream );

Closes the file associated with the stream and disassociates it.

All internal buffers associated with the stream are disassociated from it and flushed: the content of any unwritten output buffer is written and the content of any unread input buffer is discarded.

Even if the call fails, the stream passed as parameter will no longer be associated with the file nor its buffers.

Parameters

stream
    Pointer to a FILE object that specifies the stream to be closed.


Return Value
If the stream is successfully closed, a zero value is returned.
On failure, EOF is returned.

```cpp
/* fclose example */
#include <stdio.h>
int main ()
{
  FILE * pFile;
  pFile = fopen ("myfile.txt","wt");
  fprintf (pFile, "fclose example");
  fclose (pFile);
  return 0;
}
```

This simple code creates a new text file, then writes a sentence to it, and then closes it.


#### feof

Syntax:
	int feof ( FILE * stream );

Check end-of-file indicator
Checks whether the end-of-File indicator associated with stream is set, returning a value different from zero if it is.

This indicator is generally set by a previous operation on the stream that attempted to read at or past the end-of-file.

Notice that stream's internal position indicator may point to the end-of-file for the next operation, but still, the end-of-file indicator may not be set until an operation attempts to read at that point.

This indicator is cleared by a call to clearerr, rewind, fseek, fsetpos or freopen. Although if the position indicator is not repositioned by such a call, the next i/o operation is likely to set the indicator again.

Parameters

stream
    Pointer to a FILE object that identifies the stream.


Return Value
A non-zero value is returned in the case that the end-of-file indicator associated with the stream is set.
Otherwise, zero is returned.

```cpp
/* feof example: byte counter */
#include <stdio.h>

int main ()
{
  FILE * pFile = fopen ("myfile.txt","rb");
  int n = 0;
  if (pFile==NULL)
		perror ("Error opening file");
  else
  {
    while (fgetc(pFile) != EOF) {
      ++n;
    }
    if (feof(pFile)) {
      puts ("End-of-File reached.");
      printf ("Total number of bytes read: %d\n", n);
    }
    else
			puts ("End-of-File was not reached.");
    fclose (pFile);
  }
  return 0;
}
```

This code opens the file called myfile.txt, and counts the number of characters that it contains by reading all of them one by one. The program checks whether the end-of-file was reached, and if so, prints the total number of bytes read.



#### rename

Syntax:
	int rename ( const char * oldname, const char * newname );

Rename file
Changes the name of the file or directory specified by oldname to newname.

This is an operation performed directly on a file; No streams are involved in the operation.

If oldname and newname specify different paths and this is supported by the system, the file is moved to the new location.

If newname names an existing file, the function may either fail or override the existing file, depending on the specific system and library implementation.

Proper file access shall be available.

Parameters

oldname
    C string containing the name of an existing file to be renamed and/or moved.
    Its value shall follow the file name specifications of the running environment and can include a path (if supported by the system).
newname
    C string containing the new name for the file.
    Its value shall follow the file name specifications of the running environment and can include a path (if supported by the system).


Return value
If the file is successfully renamed, a zero value is returned.
On failure, a nonzero value is returned.
On most library implementations, the errno variable is also set to a system-specific error code on failure.

```cpp
/* rename example */
#include <stdio.h>

int main ()
{
  int result;
  char oldname[] ="oldname.txt";
  char newname[] ="newname.txt";
  result= rename( oldname , newname );
  if ( result == 0 )
    puts ( "File successfully renamed" );
  else
    perror( "Error renaming file" );
  return 0;
}
```


If the file oldname.txt could be successfully renamed to newname.txt the following message would be written to stdout:

File successfully renamed


Otherwise, a message similar to this will be written to stderr:

Error renaming file: Permission denied



#### Remove

Syntax

	int remove ( const char * filename );

remove deletes the file whose name is specified in filename.

This is an operation performed directly on a file identified by its filename; No streams are involved in the operation.

Parameters

filename
    C string containing the name of the file to be deleted.
    Its value shall follow the file name specifications of the running environment and can include a path (if supported by the system).


Return value
If the file is successfully deleted, a zero value is returned.
On failure, a nonzero value is returned.
On most library implementations, the errno variable is also set to a system-specific error code on failure.

```cpp
/* remove example: remove myfile.txt */
#include <stdio.h>

int main ()
{
  if( remove( "myfile.txt" ) != 0 )
    perror( "Error deleting file" );
  else
    puts( "File successfully deleted" );
  return 0;
}
```


If the file myfile.txt exists before the execution and the program has write access to it, the file would be deleted and this message would be written to stdout:

File successfully deleted


Otherwise, a message similar to this would be written to stderr:

Error deleting file: No such file or directory
