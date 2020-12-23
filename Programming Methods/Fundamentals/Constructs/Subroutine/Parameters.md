Parameter passing
Ways in which parameter data can be passed into and out of methods and functions.

Formal Parameter
A variable and its type
as they appear in the prototype of the function or method.

Actual Parameter
The variable or expression corresponding to a formal parameter
that appears in the function or method call in the calling environment.

Parameter passing
The mechanism used to pass parameters to a procedure (subroutine) or function.

Let us assume that a function B() is called from another function A().
In this case A is called the “caller function”
and B is called the “called function or callee function”.
Also, the arguments which A sends to B are called actual arguments
and the parameters of B are called formal arguments.

Modes:
IN: Passes info from caller to callee.
OUT: Callee writes values in caller.
IN/OUT: Caller tells callee value of variable, which may be updated by callee.

The most common methods are to pass the value of the actual parameter (call by value),
or to pass the memory address where the actual parameter is stored (call by reference).
by reference allows the procedure to change the value of the parameter,
by value guarantees that the procedure will not change the value of the parameter.
Other more complicated parameter-passing methods have been devised,
by name in Algol 60, where the actual parameter is re-evaluated each time it is required during execution of the procedure.


C and C++ both support call by value as well as call by reference
whereas Java doesn't support call by reference.


Types of parameter passing

Pass By Value : This method uses in-mode semantics.
the data associated with the actual parameter is copied into a separate storage location assigned to the formal parameter.
Changes made to formal parameter do not get transmitted back to the caller.
Any modifications to the formal parameter variable inside the call affect only the separate storage location and will not be reflected in the actual parameter in the calling environment.


Evaluate arguments
copy values to callee
alter in function scope
changes lost on return

NOTICE: even large structures are copied
Inefficiency in storage allocation
For objects and arrays, the copy semantics are costly



Pass by reference(aliasing) : This technique uses in/out-mode semantics.
Changes made to formal parameter are transmitted back to the caller.
Any changes to the formal parameter are reflected in the actual parameter
in the calling environment as formal parameter receives a reference (or pointer)
to the actual data. This method is also called as call by reference.
This method is efficient in both time and space.

pass reference to actual argument
address value computed when passed
bind to parameter
use implicitly dereferences to access original argument

NOTICE:any change to the parameter inside the function scope is computed immediately
Shortcomings: Many potential scenarios can occur
Programs are difficult to understand sometimes



Using expressions as actual parameters
When the formal parameter is passed by value,
the actual parameter can be an expression.
However, when the formal parameter is passed by reference,
the actual parameter must refer to one specific instance of the formal parameter type
stored in programmer-accessible memory.


Other methods of Parameter Passing

These techniques were used in earlier programming languages like Pascal, Algol and Fortran.
These techniques are not applicable in high level languages.

Pass by Result : This method uses out-mode semantics.
Just before control is transferred back to the caller,
the value of the formal parameter is transmitted back to the actual parameter.
This method is sometimes called "call by result".
In general, pass by result technique is implemented by copy.

Pass by Value-Result : This method uses in/out-mode semantics.
It is a combination of Pass-by-Value and Pass-by-result.
Just before the control is transferred back to the caller,
the value of the formal parameter is transmitted back to the actual parameter.
This method is sometimes called "call by value-result"
It finds use in concurrent applications

Pass by name : This technique is used in programming language such as Algol.
In this technique, symbolic “name” of a variable is passed,
which allows it both to be accessed and update.
We do not evaluate the the actual argument at the time of the call
This is called deferred or delayed evaluation
parameter names the expression in the argument list
each use of the name parameter evaluates the expression
Example:
To double the value of C[j], you can pass its name (not its value) into the following procedure.

procedure double(x);
  real x;
begin
  x:=x*2
end;

In general, the effect of pass-by-name is to textually substitute the argument in a procedure call
for the corresponding parameter in the body of the procedure.

Implications of Pass-by-Name mechanism:

The argument expression is re-evaluated each time the formal parameter is passed.
The procedure can change the values of variables used in the argument expression and hence change the expression’s value.




By need: cache computed actual args










Semantic Rules
Evaluation
Each use of a by-reference parameter must immediately retrieve the referenced value.
Typically, the reference itself will not be used as a value.

If a by-reference parameter is, itself, passed as an argument to another function by-reference,
then the new parameter ultimately references the original argument
(i.e., if a is passed by-reference and called b,
  which is then passed by-reference and called c,
  then c references a).

• Each assignment to a by-reference parameter must immediately update the referenced value.
The parameter itself (i.e., the binding in the associated scope) is not modified.

• Each use of a by-name parameter must evaluate the original expression in the original scope
(i.e., in the scope of the caller) to determine the parameter’s value.
This does imply that the resulting value may change between uses.

Dynamic Type Checking
• Assignment to a by-name parameter is not allowed (this is equally true when such an assignment ultimately passes through a by-reference parameter bound to a by-name parameter in the caller).

• Only identifiers may be passed as actual arguments for by-reference parameters.
