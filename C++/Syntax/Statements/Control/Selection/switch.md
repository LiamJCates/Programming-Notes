## Switch
The switch statement transfers control to one of several statements depending on the value of a condition, which evaluates to either an integer or enumeration type.


Syntax
attr(optional) switch ( condition ) statement 		(until C++17)
attr(optional) switch ( init-statement(optional) condition ) statement 		(since C++17)


attr(C++11) 	- 	any number of attributes

condition 	- 	any expression of integral or enumeration type, or of a class type contextually implicitly convertible to an integral or enumeration type, or a declaration of a single non-array variable of such type with a brace-or-equals initializer.

init-statement(C++17) 	- 	either
    an expression statement (which may be a null statement ";")
    a simple declaration, typically a declaration of a variable with initializer, but it may declare arbitrarily many variables or structured bindings

    Note that any init-statement must end with a semicolon ;, which is why it is often described informally as an expression or a declaration followed by a semicolon.

statement 	- 	any statement (typically a compound statement).
case: and default: labels are permitted in statement and break; statement has special meaning.

attr(optional) case constant_expression : statement 	(1) 	
attr(optional) default : statement 	(2) 	

constant_expression 	- 	a constant expression of the same type as the type of condition after conversions and integral promotions






Explanation
The switch keyword denotes a switch statement.
Like an if statement, switch statements provide conditional branching. When a switch statement executes, control transfers to the case fitting the condition or to a default condition if no case matches the condition expression.
The case keyword denotes a case, whereas the default keyword denotes the default condition.

The body of a switch statement may have an arbitrary number of case: labels, as long as the values of all constant_expressions are unique (after conversions/promotions). At most one default: label may be present (although nested switch statements may use their own default: labels or have case: labels whose constants are identical to the ones used in the enclosing switch)

If condition evaluates to the value that is equal to the value of one of constant_expressions, then control is transferred to the statement that is labeled with that constant_expression.

If condition evaluates to the value that doesn't match any of the case: labels, and the default: label is present, control is transferred to the statement labeled with the default: label.


Somewhat confusingly, execution will continue until the end of the switch statement or the break keyword.



You’ll almost always find a break at
the end of each switch condition.


switch(condition){
  case (case-value):
    {//case statements }
    break;
  case (case-value):
    {//case statements }
    break;
  default:  
}

All switch statements begin with the switch keyword followed by the condition in parentheses. Each case begins with the case keyword followed by the case’s enumeration or integral value. If condition is equal to a given case-value, the code in the associated block will execute. After each statement following a case, you place a break keyword or the following case will be executed. If condition matches none of the cases and a default case is specified, the default case executes.

The braces enclosing each case are optional but highly recommended. Without them,
you’ll sometimes get surprising behavior.


The usage is as follows:
switch (init-expression; condition) {
case (case-a): {
// Handle case-a here
} break;
case (case-b): {
// Handle case-b here
} break;
// Handle other conditions as desired
default: {
// Handle the default case here
}
}

The break statement, when encountered in statement exits the switch statement:

switch(1) {
    case 1 : cout << '1'; // prints "1",
    case 2 : cout << '2'; // then prints "2"
}

switch(1) {
    case 1 : cout << '1'; // prints "1"
             break;       // and exits the switch
    case 2 : cout << '2';
             break;
}

Compilers may issue warnings on fallthrough (reaching the next case label without a break) unless the attribute [[fallthrough]] appears immediately before the case label to indicate that the fallthrough is intentional.

If init-statement is used, the switch statement is equivalent to
{

    init_statement
    switch ( condition ) statement

}


Except that names declared by the init-statement (if init-statement is a declaration) and names declared by condition (if condition is a declaration) are in the same scope, which is also the scope of statement.
	(since C++17)

Because transfer of control is not permitted to enter the scope of a variable, if a declaration statement is encountered inside the statement, it has to be scoped in its own compound statement:

switch(1) {
    case 1: int x = 0; // initialization
            std::cout << x << '\n';
            break;
    default: // compilation error: jump to default: would enter the scope of 'x'
             // without initializing it
             std::cout << "default\n";
             break;
}

switch(1) {
    case 1: {  int x = 0;
               std::cout << x << '\n';
               break;
            } // scope of 'x' ends here
    default: std::cout << "default\n"; // no error
             break;
}


Listing 8-19 employs an initialization statement within a switch statement.

#include <cstdio>
enum class Color {
Mauve,
Pink,
Russet
};

struct Result {
const char* name;
Color color;
};

Result observe_shrub(const char* name) {
return Result{ name, Color::Russet };
}

int main() {
const char* description;
switch (const auto result = observe_shrub("Zaphod"); result.color) {
case Color::Mauve: {
description = "mauvey shade of pinky russet";
break;
} case Color::Pink: {
description = "pinky shade of mauvey russet";
break;
} case Color::Russet: {
description = "russety shade of pinky mauve";
break;
} default: {
description = "enigmatic shade of whitish black";
}}
printf("The other Shaltanac's joopleberry shrub is "
"always a more %s.", description);
}
The other Shaltanac's joopleberry shrub is always a more russety shade of
pinky mauve.

Listing 8-19: Using an initialization expression in a switch statement

You declare the familiar Color enum class and join it with a char*
member to form the POD type Result. The function observe_shrub
returns a Result. Within main, you call observe_shrub within the initialization expression and store the result in the result variable. Within
the conditional expression of switch, you extract the color element of this
result. This element determines the case that executes (and sets the
description pointer).

As with the if-statement-plus-initializer syntax, any object initialized in
the initialization expression is bound to the scope of the switch statement.
