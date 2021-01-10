### for
In C++ for is a reserved word.

Syntax

  attr for ( init-statement ; condition ; iteration_expression )
    statement 		

where
attr: is any number of attributes (C++11)

init-statement: is either
  an expression statement (which may be a null statement ";")

  a simple declaration, typically a declaration of a loop counter variable with initializer, but it may declare arbitrary many variables

condition: is either
  an expression which is contextually convertible to bool. This expression is evaluated before each iteration, and if it yields false, the loop is exited.

  a declaration of a single variable with a brace-or-equals initializer. the initializer is evaluated before each iteration, and if the value of the declared variable converts to false, the loop is exited.

iteration_expression: is any expression, which is executed after every iteration of the loop and before re-evaluating condition. Typically, this is the expression that increments the loop counter

statement: is any statement, typically a compound statement, which is the body of the loop

Explanation

Executes init-statement once, then executes statement and iteration_expression repeatedly, until the value of condition becomes false. The test takes place before each iteration.

The above syntax produces code equivalent to:

  init_statement
  while ( condition ) {
      statement
      iteration_expression ;
  }


Except that
1) Names declared by the init-statement and names declared by condition are in the same scope, the scope of statement.

2) continue in the statement will execute iteration_expression

3) Empty condition is equivalent to while(true)

If the execution of the loop needs to be terminated at some point, break statement can be used as terminating statement.

If the execution of the loop needs to be continued at the end of the loop body, continue statement can be used as shortcut.

As is the case with while loop, if statement is a single statement (not a compound statement), the scope of variables declared in it is limited to the loop body as if it was a compound statement.

for (;;)
    int n;
// n goes out of scope


Notes

As part of the C++ forward progress guarantee, the behavior is undefined if a loop that has no observable behavior (does not make calls to I/O functions, access volatile objects, or perform atomic or synchronization operations) does not terminate. Compilers are permitted to remove such loops.

While in C++, the scope of the init-statement and the scope of statement are one and the same, in C the scope of statement is nested within the scope of init-statement:

  for (int i = 0; ; ) {
    long i = 1;   // valid C, invalid C++
    // ...
  }


Example:

  #include <cstddef>
  #include <cstdio>

  int main()
  {
    unsigned long maximum = 0;
    unsigned long values[] = { 10, 50, 20, 40, 0 };

    for(size_t i = 0; i < 5; i++)
    {
      if (values[i] > maximumx) maximum = values[i];
    }
    printf("The maximum value is %lu", maximum);
  }

You might be wondering why size_t is employed instead of an int for the type of the loop counter, i. Consider that values could theoretically take up the maximum storage allowed. Although size_t is guaranteed to be able to index any value within it, int is not. In practice, it makes little difference, but technically size_t is correct.
