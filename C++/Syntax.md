## Statements
C++ programs are composed of statements.
All statements in C++ end with a semicolon (;)

The next statement can start immediately after the semicolon, but for convenience and readability you often program successive statements on successive lines.

Whitespaces typically are not visible to the compiler. This includes spaces, tabs, line feeds, carriage returns, and so on. Whitespaces within string literals, though, make a difference to the output.

If you need to spread a statement over two lines by inserting a backslash (\) at the end:
cout << "Hello \
World" << endl; // split to two lines is OK

The preceding statement can be written as two string literals:
cout << "Hello "
"World" << endl; // two string literals is also OK

The compiler notices two adjacent string literals and concatenates them.


When you group statements together within braces {...}, you create a compound statement or a block




## increment and decrement
You often hear of cases where prefix increment or decrement
operators are preferred on grounds of better performance. That
is, ++startValue is preferred over startValue++.
This is true at least theoretically because with the postfix
operators, the compiler needs to store the initial value
temporarily in the event of it needing to be assigned. The effect
on performance in these cases is negligible with respect to
integers, but in the case of certain classes there might be a
point in this argument. Smart compilers may optimize away the
differences.



## short-circuit evaluation
Yes, the &&, ||  operators in C++ use short-circuit evaluation, in case you want to evaluate all expressions anyway you can use the & and | operators.

Note that evaluation of an expression to true in C++ essentially
means that the expression does not evaluate to false, false
being zero. So, an expression that evaluates to any non-zero
number—negative or positive—is essentially considered to be
evaluating to true when used in a conditional statement.



## The Precedence of Operators
https://en.cppreference.com/w/cpp/language/operator_precedence





## Controlling Program Flow
if, switch, ternary, break, continue statements same as java
for, for in, while, do while loops same as java

goto

goto instructs execution to continue from a particular, labeled,
point in code. You can use it to go backward and re-execute certain statements.
The syntax for the goto statement is
SomeFunction()
{
Start: // Called a label
CodeThatRepeats;
goto Start;
}





## Preprocessor Directive

As the name suggests, a preprocessor is a tool that runs before the actual compilation
starts. Preprocessor directives are commands to the preprocessor and always start with
a pound sign #
 #include
Professionally programmed C++ applications include standard
headers
if an artifact declared in FileA needs to be used in
FileB, you need to include the former in the latter. You usually do
that by inserting the following include statement in FileA:
 #include "...relative path \FileB"
We use quotes in this case and not angle brackets in including
a self-programmed header. <> brackets are typically used when
including standard headers.
