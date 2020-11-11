Variables defined and declared within a function are private or local to the function, no other function can have direct access to them.

Each local
variable in a function comes into existence only when the function is called, and
disappears when the function is exited. This is why such variables are usually
known as automatic variables, following terminology in other languages. We
will use the term automatic henceforth to refer to these local variables

Because automatic variables come and go with function invocation, they do
not retain their values from one call to the next, and must be explicitly set upon
each entry. If they are not set, they will contain garbage.
As an alternative to automatic variables, it is possible to define variables that
are external to all functions, that is, variables that can be accessed by name by
any function.

Because external variables are globally
accessible, they can be used instead of argument lists to communicate data
between functions. Furthermore, because external variables remain in existence
permanently, rather than appearing and disappearing as functions are called and
exited, they retain their values even after the functions that set them have
returned.
An external variable must be defined, exactly once, outside of any function;
this sets aside storage for it. The variable must also be declared in each function that wants to access it; this states the type of the variable. The declaration
may be an explicit extern statement or may be implicit from context.





Print Longest Line

#include <stdio.h>
#define MAXLINE 1000

int max;
char current_line[MAXLINE];
char longest_line[MAXLINE];

int getline(void);
void copy(void);

main(){
  int len;
  extern int max;
  extern char longest_line[];

  max = 0;

  while((len = getline(current_line)) > 0){
    if(len > max) {
      max = len;
      copy();
    }
  }
  if(max > 0)
    printf("%s", longest);

  return 0;
}

getline(void){
  int c, i;
  extern char current_line[];

  for(i = 0; i < MAXLINE-1 && (c = getchar()) != EOF && c != '\n'; i++)
    current_line[i] = c;
  if(c == '\n')
    current_line[i++] = c;

  current_line[i] = '\0';
  return i;
}

void copy(void){
  int i;
  extern char current_line[], longest_line[];

  for(i = 0;(longest_line[i] = current_line[i]) != '\0'; ++i);
}


The external variables in main, getline, and copy are defined by the
first lines of the example above, which state their type and cause storage to be
allocated for them. Syntactically, external definitions are just like definitions of
local variables, but since they occur outside of functions, the variables are external. Before a function can use an external variable, the name of the variable
must be made known to the function. One way to do this is to write an
extern declaration in the function; the declaration is the same as before except
for the added keyword extern.
In certain circumstances, the extern declaration can be omitted. If the
definition of an external variable occurs in the source file before its use in a particular function, then there is no need for an extern declaration in the function. The extern declarations in main,getline and copyare thus redundant. In fact, common practice is to place definitions of all external variables at
the beginning of the source file, and then omit all extern declarations.
If the program is in several source files, and a variable is defined in filel
and used in fUe2 and file3, then extern declarations are needed in file2 and
file3 to connect the occurrences of the variable. The usual practice is to collect
extern declarations of variables and functions in a separate file, historically
called a header, that is included by #include at the front of each source file.
The suffix •h is conventional for header names.
