Global and local

A global variable is one that can be accessed and changed throughout the whole program.

In computer programming, a global variable is a variable with global scope, meaning that it is visible (hence accessible) throughout the program, unless shadowed. The set of all global variables is known as the global environment or global state. In compiled languages, global variables are generally static variables, whose extent (lifetime) is the entire runtime of the program, though in interpreted languages (including command-line interpreters), global variables are generally dynamically allocated when declared, since they are not known ahead of time.

In some languages, all variables are global, or global by default, while in most modern languages variables have limited scope, generally lexical scope, though global variables are often available by declaring a variable at the top level of the program. In other languages, however, global variables do not exist; these are generally modular programming languages that enforce a module structure, or class-based object-oriented programming languages that enforce a class structure.



Local Variable
Local variables only exist within a particular section of the program.

A variable declared (created) inside a code block statement is called a local variable, and it can only be accessed from within the code block statement. Outside the code block statement, it is as if the variable never existed at all and attempting to reference the variable will often place our program in an error state.

The region created within the code block statement is called the local scope of the code block statement.

Statements that create a local scope are generally:
  Selection
  Iteration
  Subroutines
  Classes





Trade Offs
Using local variables rather than global variables makes it easier to debug a program as the value of that variable can only be accessed within one subroutine. Another advantage of local variables is memory efficiency. Once a subroutine has finished running, the memory used for all local variables is removed.

In general, the use of global variables should be avoided wherever possible.


It might sound as if global variables are the way to go. But it is actually the opposite. We shall always strive to use local variables as often as we can. The reason is that it is hard to control global variables. Imagine that you have a program that is thousands of lines long, and all variables are global. They get changed here and there and all over, and then you discover that one of the variables has a value that would be impossible for it to have. Somewhere, a code line has changed this variable in a bad way. This is an error in our program, and we need to find it and fix it. But where is that line? As all parts of the program can change that variable (and all of the others that are declared global), it can be extremely hard to find that location. It might also be so that the reason this variable has a bad value is that some other variable had a bad value and that we discovered the error was just a side effect.







































A closure is a run-time representation that encapsulates the code for the function (i.e., what the function should do when called) and the defining context (the variables in the outer scopes that the function may access). We will refer to this defining context as the defining environment.

the evaluation of a function definition is the creation of a closure encapsulating the code for the function and the defining environment (the currently active environment at the time the function definition is evaluated).

Definition:
1. create a closure to capture function body and declaring context/environement

Call
1. Evaluate the “function expression” to gain access to a closure.
2. Evaluate the actual arguments in the context of the currently active environment
3. Create a new frame to store the parameters and local variables for the invoked closure.
4. Bind the values of the actual arguments with the corresponding formal parameters in this new table.
5. Set up the new context for the pending switch: Link this new table to the defining environment
stored within the closure.
6. Context switch: evaluate the body of the function with this new environment (that from the
previous step with the new table at the head) as the now currently active environment.
7. Upon return from the function call, restore the previous environment.




Static scoping
analysis done during compile
effect is at runtime

each frame keeps a pointer/link to the frame in which it was declared

in static scoping, if a function is called we instantly follow stack pointer to get values
the compiler precomputes number of link to frame

use offset instead of looking at name in runtime

load from position 0 frame pointer + offset

static links tell us directly where a variable is defined




dynamic scoping


With static (lexical) scoping, the structure of the program source code determines what variables you are referring to.

With dynamic scoping, the runtime state of the program stack determines what variable you are referring to.

This is likely a very unfamiliar concept, since basically every programming language in wide use today (except perhaps emacs lisp) uses lexical scoping, which tends to be dramatically easier for both humans and analysis tools to reason about.


Dynamic Scoping – Variable binding (context) can only be determined at the moment code is executed.
In a dynamically typed language, types are not checked until execution.
If an expression evaluates, then the type-checking worked. If not, it blows up to your error handling or the user.


Static Scoping – Variables can be bound at compile time without regards to calling code.
Statically typed languages check types at compile time.
The programmer ensures that parameter types are specified and the compiler ensures the programmers wishes will be followed.


Static and Dynamic Scoping
The scope of a variable x is the region of the program in which uses of x refers to its declaration.

One of the basic reasons of scoping is to keep variables in different parts of program distinct from one another. Since there are only a small number of short variable names, and programmers share habits about naming of variables (e.g., i for an array index),

in any program of moderate size the same variable name will be used in multiple different scopes.

Scoping is generally divided into two classes:
1.Static Scoping
2.Dynamic Scoping

Static Scoping:
Static scoping is also called lexical scoping.
In this scoping a variable always refers to its top level environment.
This is a property of the program text and unrelated to the run time call stack.
Static scoping also makes it much easier to make a modular code as programmer can figure out the scope just by looking at the code.
In contrast, dynamic scope requires the programmer to anticipate all possible dynamic contexts.


In most of the programming languages including C, C++ and Java, variables are always statically (or lexically) scoped i.e., binding of a variable can be determined by program text and is independent of the run-time function call stack.
For example, output for the below program is 10, i.e., the value returned by f() is not dependent on who is calling it (Like g() calls it and has a x with value 20). f() always returns the value of global variable x.
// A C program to demonstrate static scoping.
#include<stdio.h>
int x = 10;

// Called by g()
int f()
{
  return x;
}

// g() has its own variable
// named as x and calls f()
int g()
{
  int x = 20;
  return f();
}

int main()
{
 printf("%d", g());
 printf("\n");
 return 0;
}
Output :
10
To sum up in static scoping the compiler first searches in the current block, then in the surrounding blocks successively and finally in the global variables.


Dynamic Scoping:
With dynamic scope, a global identifier refers to the identifier associated with the most recent environment, and is uncommon in modern languages. In technical terms, this means that each identifier has a global stack of bindings and the occurrence of a identifier is searched in the most recent binding.
In simpler terms, in dynamic scoping the compiler first searches the current block and then successively all the calling functions.
// Since dynamic scoping is very uncommon in
// the familiar languages, we consider the
// following pseudo code as our example. It
// prints 20 in a language that uses dynamic
// scoping.    

int x = 10;

// Called by g()
int f()
{
  return x;
}

// g() has its own variable
// named as x and calls f()
int g()
{
  int x = 20;
  return f();
}

main()
{
 printf(g());
}
Output in a language that uses Dynamic Scoping :
20
Static Vs Dynamic Scoping
In most of the programming languages static scoping is dominant. This is simply because in static scoping it’s easy to reason about and understand just by looking at code. We can see what variables are in the scope just by looking at the text in the editor.
Dynamic scoping does not care how the code is written, but instead how it executes. Each time a new function is executed, a new scope is pushed onto the stack.

Perl supports both dynamic and static scoping. Perl’s keyword “my” defines a statically scoped local variable, while the keyword “local” defines dynamically scoped local variable.
# A perl code to demonstrate dynamic scoping
$x = 10;
sub f
{
  return $x;
}
sub g
{
  # Since local is used, x uses
  # dynamic scoping.
  local $x = 20;

  return f();
}
print g()."\n";
Output :
20
