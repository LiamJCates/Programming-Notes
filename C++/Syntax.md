## Statements
Languages—spoken or programmed—are composed of statements that are executed one
after another.

All statements in
C++ end with a semicolon (;)

The next statement can start
immediately after the semicolon, but for convenience and readability you often program
successive statements on successive lines.

Whitespaces typically are not visible to the compiler. This
includes spaces, tabs, line feeds, carriage returns, and so on.
Whitespaces within string literals, though, make a difference to
the output.

If you need to spread
a statement over two lines for some reason, you can do it by inserting a backslash (\) at
the end:
cout << "Hello \
World" << endl; // split to two lines is OK

Another way of writing the preceding statement in two lines is to write two string literals
instead of just one:
cout << "Hello "
"World" << endl; // two string literals is also OK
In the preceding example, the compiler notices two adjacent string literals and
concatenates them for you.


## Compound Statements or Blocks
When you group statements together within braces {...}, you create a compound
statement or a block




## Operators
int daysInYear = 365;
The preceding statement uses the assignment operator in initializing the integer to 365.
The assignment operator replaces the value contained by the operand to the left
(unimaginatively called l-value) by that on the right (called r-value).
Understanding L-values and R-values
L-values often refer to locations in memory. A variable such as daysInYear from the
preceding example is actually a handle to a memory location and is an l-value. R-values,
on the other hand, can be the very content of a memory location.So, all l-values can be r-values, but not all r-values can be l-values. To understand it
better, look at the following example, which doesn’t make any sense and therefore won’t
compile:
365 = daysInYear;


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


Yes, the &&, ||  operators in C++ use short-circuit evaluation, in case you want to evaluate all expressions anyway you can use the & and | operators.

Note that evaluation of an expression to true in C++ essentially
means that the expression does not evaluate to false, false
being zero. So, an expression that evaluates to any non-zero
number—negative or positive—is essentially considered to be
evaluating to true when used in a conditional statement.

The Precedence of Operators
Rank Name Operator
1 Scope resolution ::
2 Member selection, subscripting, increment, and decrement . -> () ++ --
3 sizeof, prefix increment and decrement, complement, and,
not, unary minus and plus, address-of and dereference, new,
new[], delete, delete[], casting, sizeof()
++ -- ^ ! - + & * ()
4 Member selection for pointer .* ->*
5 Multiply, divide, modulo * / %
6 Add, subtract + -
7 Shift (shift left, shift right) << >>
8 Inequality relational << = >>=
9 Equality, inequality == !=
10 Bitwise AND &
11 Bitwise exclusive OR ^
12 Bitwise OR |+
13 Logical AND &&
14 Logical OR ||
15 Conditional ?:
16 Assignment operators = *= /= %= += -= <<= >>= &= |= ^=
17 Comma ,


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
