Aborts the current process and returns an error code.

void abort( void );

Return Value

abort does not return control to the calling process. By default, it checks for an abort signal handler and raises SIGABRT if one is set. Then abort terminates the current process and returns an exit code to the parent process.

Calling the abort function causes immediate termination. It bypasses the normal destruction process for initialized global static objects. It also bypasses any special processing that was specified using the atexit function.


ANSI 4.10.4.1 The behavior of the abort function with regard to open and temporary files

The abort function does not close files that are open or temporary. It does not flush stream buffers.


Example

The following program tries to open a file and aborts if the attempt fails.
C

// crt_abort.c
// compile with: /TC
// This program demonstrates the use of
// the abort function by attempting to open a file
// and aborts if the attempt fails.

#include  <stdio.h>
#include  <stdlib.h>

int main( void )
{
    FILE    *stream = NULL;
    errno_t err = 0;

    err = fopen_s(&stream, "NOSUCHF.ILE", "r" );
    if ((err != 0) || (stream == NULL))
    {
        perror( "File could not be opened" );
        abort();
    }
    else
    {
        fclose( stream );
    }
}

Output

File could not be opened: No such file or directory
