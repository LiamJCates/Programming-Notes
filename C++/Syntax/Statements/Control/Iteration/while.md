### while
Executes a statement repeatedly, until the value of condition becomes false. The test takes place before each iteration.
Syntax
attr(optional) while ( condition ) statement 		

where
attr(C++11): is any number of attributes

condition: is any expression which is contextually convertible to bool or a declaration of a single variable with a brace-or-equals initializer. This expression is evaluated before each iteration, and if it yields false, the loop is exited. If this is a declaration, the initializer is evaluated before each iteration, and if the value of the declared variable converts to false, the loop is exited.

statement: is any statement, typically a compound statement, which is the body of the loop

Explanation

Whether statement is a compound statement or not, it always introduces a block scope. Variables declared in it is only visible in the loop body, in other words,

while (--x >= 0)
    int i;
// i goes out of scope

is the same as

while (--x >= 0) {
    int i;
} // i goes out of scope

If condition is a declaration such as T t = x, the declared variable is only in scope in the body of the loop, and is destroyed and recreated on every iteration, in other words, such while loop is equivalent to

label:
{ // start of condition scope
    T t = x;
    if (t) {
        statement
        goto label; // calls the destructor of t
    }
}

If the execution of the loop needs to be terminated at some point, break statement can be used as terminating statement.

If the execution of the loop needs to be continued at the end of the loop body, continue statement can be used as shortcut. 
