fThe Scope and Lifetime of Variables
Scope determines what objects are visible to other parts of your program, i.e. where a variable can be referenced or accessed by its identifier. A variable is visible only to statements inside the variable’s scope. As a variable can no longer be referenced outside of it's scope, scope also determines the lifetime of those objects.

Java allows variables to be declared within any block, the block a variable is declared in defines its scope. Thus, each time you start a new block, you are creating a new scope. In general, every declaration in Java has a scope. As a result, Java defines a powerful, finely grained concept of scope.

Block Scope
Blocks define the scope of your variables. A block can be nested inside another block. Here is a block that is nested inside the block of the main method:

public static void main(String[] args) {
int n;
. . .
{
int k;    // the identifier k is only defined in this block
. . .
}
}
Common Scopes include Classes, Methods, Loops

The scope defined by a class, method, or loop is anything between its opening and closing curly braces.

The scope of a method parameter covers the entire method as a parameter is actually a local variable.
A variable declared in the initial part of a for-loop header has scope through the entire loop. However, a variable declared inside a for-loop body has its scope limited to each iteration of the loop body from the point of declaration to the end of the block that contains the variable

As a general rule, variables declared inside a scope are not visible (that is, accessible) to code that is defined outside that scope. Thus, when you declare a variable within a scope, you are localizing that variable and protecting it from unauthorized access and/or modification. As such, these scope rules provide the foundation for encapsulation.

Scopes can be nested. For example, each time you create a block of code, you are creating a new, nested scope. When this occurs, the outer scope encloses the inner scope. This means that objects declared in the outer scope will be visible to code within the inner scope. However, the reverse is not true. Objects declared within the inner scope will not be visible outside it.

Within a block, variables can be declared at any point, but are valid only after they are declared. Thus, if you define a variable at the start of a method, it is available to all of the code within that method. Conversely, if you declare a variable at the end of a block, it is effectively useless, because no code will have access to it.

Here is another important point to remember: variables are created when their scope is entered, and destroyed when their scope is left. This means that a variable will not hold its value once it has gone out of scope. Therefore, variables declared within a method will not hold their values between calls to that method. Also, a variable declared within a block will lose its value when the block is left. Thus, the lifetime of a variable is confined to its scope. If a variable declaration includes an initializer, that variable will be reinitialized each time the block in which it is declared is entered.

The scope of instance and static variables is the entire class, regardless of where the variables are declared.

Instance and static variables in a class are referred to as the class’s variables or data fields. A variable defined inside a method is referred to as a local variable. The scope of a class’s variables is the entire class, regardless of where the variables are declared. A class’s variables and methods can appear in any order in the class. The exception is when a data field is initialized based on a reference to another data field. In such cases, the other data field must be declared first. For consistency, typically data field declarations are at the beginning of the class.

You can declare a local variable with the same name in different blocks in a method, but you cannot declare a local variable twice in the same block or in nested blocks

A shadowed variable is a variable that would otherwise be accessible but is temporarily made unavailable because a variable with the same name has been declared in a more immediate scope.

You can declare a class’s variable only once, but you can declare the same variable name in a method many times in different nonnesting blocks. If a local variable has the same name as a class’s variable, the local variable takes precedence and the class’s variable with the same name is hidden.
Local memory and function call stack

In Java, variables declared in instruction blocks are all created and stored in the local memory of the corresponding function. This local memory is named the function call stack. Whenever a function is called, the required memory for the local variables is allocated into the function stack, and the arguments are passed by value

Whenever inside the body of the  current function another function, say G, is called, the same mechanism applies: First, local memory for storing all block variables declared in the function block of G is allocated, and arguments are passed by value. Once G is completed, the local memory allocated for its execution is released. These various levels of nested function calls yield the function call stack.

The function variables are allocated into the local memory stack and are thus not visible to other functions. The pass-by-value mechanism binds the function arguments with the respective expression values at calling time

Note that since arguments are passed by values, the local variables of the calling functions are not changed.

Example:
swapping two integer variables cannot be achieved by the following erroneous code since Java is pass-by-value:
public void badSwap(int var1, int var2) {
int temp = var1;
var1 = var2;
var2 = temp;
} // at the end of this block, var1 and var2 keeps their original value


Loosely speaking, functions usually do not change the calling environment. Function y=F(x) returns a result that is taken into account in the calling environment. There are of course different ways for functions and procedures to alter the calling environment. This bears the name of side-effect functions.

Side-effects of functions: Changing the calling environment

we split the memory into two parts: The local function call stack memory (function variables) and the global memory (static variables and referenced structures). Thus in Java, we can voluntarily alter the calling environment by handling arrays and other non-primitive user-defined typed objects that are manipulated by their references.


Activation Record / Call Stack

Each time a method is invoked, the system creates an activation record (also called an activation frame) that stores parameters and variables for the method and places the activation record in an area of memory known as a call stack. A call stack is also known as an execution stack, runtime stack, or machine stack and it is often shortened to just “the stack.” When a method calls another method, the caller’s activation record is kept intact and a new activation record is created for the new method called. When a method finishes its work and returns to its caller, its activation record is removed from the call stack. A call stack stores the activation records in a last-in, first-out fashion: The activation record for the method that is invoked last is removed first from the stack. For example, suppose method m1 calls method m2, and m2 calls method m3. The runtime system pushes m1’s activation record into the stack, then m2’s, and then m3’s. After m3 is finished, its activation record is removed from the stack. After m2 is finished, its activation record is removed from the stack. After m1 is finished, its activation record is removed from the stack.
