various methods by which we can terminate a C program which is currently in execution.

Starting with the most widely used and most obvious function that is by using the exit() function. Some of the common ways to terminate a program in C are:

    exit
    _Exit()
    quick_exit
    abort
    at_quick_exit

We will, now, go through each of the above methods in detail.
exit()

This function requires the declaration of the C library stdlib.h in which it is defined.

And to use this function in C++ we may have to include the C++ library cstdlib.

It should be noted that this exit() function is not a program control statement used in C programs like break/goto/continue.

This function doesn't affect the control flow rather it exits the / closes the current program in execution.

This function forces forcefully termination of the current program and the control is transferred to the Operating system.

This function immediately interrupts and closes the current program in execution.

The general prototype of the exit() is :-

void exit(int returning_value)
C++
Copy

Now let's look at a pseudo code to identify when we actually use a exit() statement during normal execution of our program.

Here the example we will be considering the example of is graphic card is present or not because graphic card is must for running high end games.

#include<stdlib.h>

int main(void)
{
    if(!graphic_card_present)exit(1);
        letsplay();
    /*
    Any code we can define
    */
    return 0;
}
C++
Copy

Note that the "returning_value" is returned to the calling process , it means mostly it will return to the operating system.

The argument is taken to be 0 to indicate normal execution and if some other value is used then that's value is used to show some kind of error.

Two Macros that are used as argument here are :-

    EXIT_SUCCESS
    This macro means successful execution of the program.

    EXIT_FAILURE
    This macro indicates unsuccessful execution of the program.

These above two macros are used in the case of passing the argument to the exit function.

Sample code using exit() :-

void menu(void)
{
char ch;
printf("1. Check Spelling\n");
printf("2. Correct Spelling Errors\n");
printf("3. Display Spelling Errors\n");
printf("4. Quit\n");
printf(" Enter your choice: ");
do {
ch = getchar(); /* read the selection from
the keyboard */
switch(ch) {
case '1':
check_spelling();
break;
case '2':
correct_errors();
break;
case '3':
display_errors();
break;
case '4':
exit(0); /* return to OS */
}
} while(ch!='1' && ch!='2' && ch!='3');
}
C
Copy

_Exit()

The major difference between this _Exit() and exit(argument) is that the exit(argument) perform cleaning before termination but the _Exit() performs no cleaning before termination of program.

Cleaning here means closing all the pointers , opened files ,flushes the buffer etc.

The general prototype of the above function :-

void _Exit( int exit_argument );
C++
Copy

Sample code using _Exit() :-

#include <stdlib.h>
#include <stdio.h>


int main(void)
{
   int t=2;
   while(t--)
   {
    printf("Enter P to run program and E to terminate the program\n");
    char c;
    scanf("%c",&c);
    if(c=='E')
    {
         printf("Program Terminated\n");
         _Exit(0);
    }
    else printf("Program running\n");
   }

}
C
Copy

The result of the above code for the given inputs :-

Inputs:-
P
E
Outputs:-
Enter P to run program and E to terminate the program
Program running
Enter P to run program and E to terminate the program
Program running
C
Copy

quick_exit

This function does cleaning before exiting but the cleaning before exiting is not complete cleaning.

The most important characteristic of this function is it exits the called functions is the order opposite to the order in which functions were called.

The above statement would be clear from the sample code mentioned below :-

#include <stdlib.h>
#include <stdio.h>

void fun1(void)
{
    puts("Deleted the first function");
    fflush(stdout);
}

void fun2(void)
{
    puts("Deleted the second function");
}

int main(void)
{
    at_quick_exit(fun1);
    at_quick_exit(fun2);
    quick_exit(0);
}
C
Copy

The result of the above code for the given inputs :-

Output:-
Deleted the second function
Deleted the first function
C
Copy

In the above output just notice that the functions are terminated in the reverse order of the orderin which they were called. This functions can be assumed analogous to destructor in C++.
abort

This function doen't close the files that are open .

This function also doesn't delete the buffers before closing the program neither does it clears the buffer.

Prototype of the Function:-

void abort ( no arguments );
C
Copy

at_quick_exit

This function requires the declaration of the header <stdlib.h> .

Prototype of the Function:-

int at_quick_exit( void (*func)(void) );
C
Copy

Now notice that the prototype of this statement is quiet different from the ones we saw recently. Here the argument void (*func)(void) is actually a function pointer .

So , whats the importance of the argument passed in the above function prototype and what exactly does that indicate ?

The void (*func)(void) argument passed in the above function is actually a pointer to a function and this function is called just before the program is ended.

The function int at_quick_exit( void (*func)(void) ) returns 0 if execution is successful else the any other value is returned.

Now let's see the functions that help in interacting with the enviroment :-

    system
    getenv, getenv_s

1. SYSTEM

This function requires the declaration of the header <stdlib.h> .

This function helps in calling the enviroment's command processor by passing the argument .

If system() is called with a nullpointer,it will return non-zero if a command processor is present, and zero otherwise.

In simple words it means we can pass the commands that can be passed using the terminal of Operating System and returns the command after the execution is done.

Prototype of the Function:-

int system( const char *command );
C
Copy

Now let's see an example code for better understanding.

#include <stdio.h>
#include <string.h>

int main () {
   char command[50];

   strcpy( command, "dir" );
   system(command);

   return(0);
}
C
Copy


Output
Note that change the key word used for the respective Operating SYstem Terminals otherwise error will be shown.

C
Copy

2. GET_ENV

It is a related function to system().

This function requires the declaration of the header <stdlib.h> and if we are using C++ then we have to use the library < cstdlib >.

The getenv() function returns a pointer to environmental information associated with the string pointed to by name in the implementation-defined environmental information table. The string returned must never be changed by the program.

Return value when it gets successfully executed this function shall return a pointer to a string containing the value for the specified name.

Prototype of the Function:-

char *getenv(const char *name);
C
Copy

A sample code to help you understand better the code :-

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char *env_p = getenv("PATH");//the required function is being used here
    if (env_p) // if the function is not null
        printf("PATH = %s\n", env_p);
}
C
Copy

3. GETENV_S()

This getenv_s() function helps in searching for the environmental variable with a given name in the environment that we are using .

The detailed function definition :-

errno_t getenv_s(
   size_t *required_return,
   char (&buffer)[length],
   const char *nameofvar
);
C
Copy

This function is rarely used by anyone so, better to avoid this function.

Now let's see the functions in signal management the C provides support for some signal management :-

1. sig_atomic_t
It is a typedef present in the header <signal.h> .
It is an integer type that can be accessed individually even when the interrupts that are asynchronous are still present.

2. SIG_DFL AND SIG_IGN
Both of the above macros present in the header <signal.h> .
They both help in defining strategies that help in signal handling.

3. signal
It is a function present in the header <signal.h> .
It helps in setting the signal handler for a particular signal.

4. raise
It is a function present in the header <signal.h> .
This actually runs the signal handler that has been intiated for a particular signal.

5. SIG_ERR
It is a macros present in the header <signal.h> .
This show that some error has been generated.

Finally let's see some the signals that are present in C :-

These all are defined macros constants:-

    SIGABRT
    SIGSEGV
    SIGILL
    SIGINT
    SIGFPE
    SIGTERM
