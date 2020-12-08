Each C++ function comprises a sequence
of statements, which are programming constructs that specify the order of execution

Expression Statements
An expression statement is an expression followed by a semicolon (;).
Expression statements comprise most of the statements in a program.
You can turn any expression into a statement, which you should do
whenever you need to evaluate an expression but want to discard the
result. Of course, this is only useful if evaluating that expression causes
a side effect

Compound Statements
Compound statements, also called blocks, are a sequence of statements enclosed
by braces { }. Blocks are useful in control structures


Declaration Statements
Declaration statements (or just declarations) introduce identifiers, such as
functions, templates, and namespaces, into your programs.

Functions
A function declaration, also called the function’s signature or prototype, specifies a function’s inputs and outputs. The declaration doesn’t need to include parameter names, only their types.

Functions that aren’t member functions are called non-member functions,
or sometimes free functions, and they’re always declared outside of main()
at namespace scope. A function definition includes the function declaration
as well as the function’s body. A function’s declaration defines a function’s
interface, whereas a function’s definition defines its implementation.

function declarations are optional. So why do they exist?
The answer is that you can use declared functions throughout your
code as long as they’re eventually defined somewhere. Your compiler tool
chain can figure it out.





Namespaces
Namespaces prevent naming conflicts. In large projects or when importing
libraries, namespaces are essential for disambiguating symbols.

Placing Symbols Within Namespaces
By default, all symbols you declare go into the global namespace. The global
namespace contains all the symbols that you can access without adding
any namespace qualifiers.

To place a symbol within a namespace other than the global namespace,
you declare the symbol within a namespace block. A namespace block has the
following form:
namespace Namespace1 {
// All symbols declared within this block
// belong to the Namespace1 namespace
}
Namespaces can be nested in one of two ways.


nest namespace blocks:

namespace Namespace1 {
  namespace Namespace2 {
  // All symbols declared within this block
  // belong to the Namespace1::Namespace2 namespace
  }
}

Use the scope-resolution operator:

namespace Namespace1::Namespace2 {
  // All symbols declared within this block
  // belong to the Namespace1::Namespace2 namespace
}
The latter approach is more succinct.

Using Symbols in Namespaces
To use a symbol within a namespace, you can always use the scope-resolution
operator to specify the fully qualified name of a symbol.


Using Directives
You can employ a using directive to avoid a lot of typing. A using directive
imports a symbol into a block or, if you declare a using directive at namespace
scope, into the current namespace. Either way, you have to type the full
namespace path only once. The usage has the following pattern:
using my-type;
The corresponding my-type gets imported into the current namespace
or block, meaning you no longer have to use its full name.


You should never put a using namespace directive within a header file. Every source
file that includes your header will dump all the symbols from that using directive into
the global namespace. This can cause issues that are very difficult to debug








Type Aliasing
A type alias defines a name that refers to a previously defined name. You can
use a type alias as a synonym for the existing type name.
There is no difference between a type and any type aliases referring to
it. Also, type aliases cannot change the meaning of an existing type name.
To declare a type alias, you use the following format, where type-alias is
the type alias name and type-id is the target type:
using type-alias = type-id;

Type aliases can appear in any scope—block, class, or namespace.
You can introduce template parameters into type aliases. This enables
two important usages:
•	 You can perform partial application on template parameters. Partial
application is the process of fixing some number of arguments to a
template, producing another template with fewer template parameters.
•	 You can define a type alias for a template with a fully specified set of
template parameters.
Template instantiations can be quite verbose, and type aliases help you
avoid carpal tunnel syndrome.










Structured Bindings
Structured bindings enable you to unpack objects into their constituent elements. Any type whose non-static data members are public can be
unpacked this way—for example, the POD (plain-old-data class) types.

Syntax:
auto [object-1, object-2, ...] = plain-old-data;

This line will initialize an arbitrary number of objects (object-1, object-2, and so on) by peeling them off a POD object one by one. The objects peel off the POD from top to bottom, and they fill in the structured binding from left to right.

Consider a read_text_file function that takes a string argument corresponding to the file path. Such a function might fail, for example, if a file is locked or doesn’t exist.

You have two options for handling errors:
•	 You can throw an exception within read_text_file.
•	 You can return a success status code from the function.

Let’s explore the second option.

struct TextFile {
  bool success;
  const char* contents;
  size_t n_bytes;
};

Listing 8-10: A TextFile type that will be returned by the read_text_file function

First, a flag communicates to the caller whether the function call was a success. Next is the contents of the file and its size n_bytes.

The prototype of read_text_file looks like this:
TextFile read_text_file(const char* path);

You can use a structured binding declaration to unpack a TextFile into
its parts within your program:

#include <cstdio>
struct TextFile {
  bool success;
  const char* data;
  size_t n_bytes;
};

TextFile read_text_file(const char* path) {
const static char contents[]{ "Sometimes the goat is you." };
return TextFile{
true,
contents,
sizeof(contents)
};
}
int main() {
const auto [success, contents, length] = read_text_file("REAMDE.txt");
if (success) {
printf("Read %zd bytes: %s\n", length, contents{);
} else {
printf("Failed to open REAMDE.txt.");
}
}
Read 27 bytes: Sometimes the goat is you.
Listing 8-11: A program simulating the reading of a text file that returns a POD that you
use in a structured binding
You’ve declared the TextFile and then provided a dummy definition
for read_text_file. (It doesn’t actually read a file; more on that in Part II.)
Within main, you invoke read_text_file and use a structured binding
declaration to unpack the results into three distinct variables: success,
contents, and length. After structured binding, you can use all these
variables as though you had declared them individually.
N O T E The types within a structured binding declaration don’t have to match.








Attributes apply implementation-defined features to an expression statement.
You introduce attributes using double brackets [[ ]] containing a list of one
or more comma-separated attribute elements.
Table 8-1 lists the standard attributes.

| Attribute | Meaning |
|-----------|---------|
| [[noreturn]] | Indicates that a function doesn’t return. |
| [[deprecated("reason")]] | Indicates that this expression is deprecated; that is, its use is discouraged. The "reason" is optional and indicates the reason for deprecation. |
| [[fallthrough]] | Indicates that a switch case intends to fall through to the next switch case. This avoids compiler errors that will check for switch case fallthrough, because it’s uncommon. |
| [[nodiscard]] | Indicates that the following function or type declaration should be used. If code using this element discards the value, the compiler should emit a warning. |
| [[maybe_unused]] | Indicates that the following element might be unused and that the compiler shouldn’t warn about it. |
| [[carries_dependency]] | Used within the <atomic> header to help the compiler optimize certain memory operations. You’re unlikely to encounter this directly.|

demonstrates using the [[noreturn]] attribute by defining a
function that never returns.
#include <cstdio>
#include <stdexcept>
[[noreturn]] void pitcher() {
throw std::runtime_error{ "Knuckleball." };
}
int main() {
try {
pitcher();
} catch(const std::exception& e) {
printf("exception: %s\n", e.what());
}
}
Exception: Knuckleball.
Listing 8-12: A program illustrating the use of the [[noreturn]] attribute

First, you declare the pitcher function with the [[noreturn]] attribute. Within this function, you throw an exception. Because you always throw an exception, pitcher never returns (hence the [[noreturn]] attribute).
Within main, you invoke pitcher and handle the caught exception. Of
course, this listing works without the [[noreturn]] attribute. But giving this
information to the compiler allows it to reason more completely on your
code (and potentially to optimize your program).
The situations in which you’ll need to use an attribute are rare, but they
convey useful information to the compiler nonetheless.


Control Structures
Control structures provide alternatives to sequential program execution and are used to alter the sequential flow of execution. The two most
common control structures are selection and repetition. In selection, the program
executes particular statements depending on some condition(s). In repetition, the
program repeats particular statements a certain number of times based on some
condition(s).



To permit more complex statements, C++ provides a structure called a compound statement or a block of statements.

Compound statement syntax:
{
statement_1
statement_2
...
statement_n
}












Selection Statements
Selection statements express conditional control flow. The two varieties of
selection statements are the if statement and the switch statement.


Conditional Statements

## If
if (boolean-expression) statement;

An if statement contains a Boolean expression and one or more nested statements. Depending on whether the Boolean evaluates to true or false, the program decides which nested statement to execute.

The statement could be a single statement followed by a semicolon or a block statement.

if (boolean-expression-1) statement-1
else if (boolean-expression-2) statement-2
else statement-3

if a Boolean expression evaluates to true the associated statement is executed, if neither do the optional else statement is executed.

You can include any number of else if clauses or omit them entirely.

Pairing an else with an if: In a nested if statement, C++ associates an else with
the most recent incomplete if—that is, the most recent if that has not been paired
with an else.

You can bind an object’s scope to an if statement by adding an init-statement
to if and else if declarations, as demonstrated in Listing 8-15.
if (init-statement; condition-1) {
// Execute only if condition-1 is true
} else if (init-statement; condition-2) { // optional
// Execute only if condition-2 is true
}
--snip--
Listing 8-15: An if statement with initializations
You can use this pattern with structured bindings to produce elegant
error handling. Listing 8-16 refactors Listing 8-11 using the initialization
statement to scope a TextFile to the if statement.
#include <cstdio>
struct TextFile {
bool success;
const char* data;
size_t n_bytes;
};
TextFile read_text_file(const char* path) {
--snip--
}
int main() {
if(const auto [success, txt, len] = read_text_file("REAMDE.txt"); success)
{
printf("Read %d bytes: %s\n", len, txt);
} else {
printf("Failed to open REAMDE.txt.");
}
}

You’ve moved the structured binding declaration into the initialization statement portion of the if statement. This scopes each of the unpacked objects—success, txt, and len—to the if block. You use success directly within the conditional expression of if to determine whether read_text_file was successful. If it was, you print the contents of REAMDE.txt. If it wasn’t, you print an error message.




constexpr if Statements
You can make an if statement constexpr; such statements are known as
constexpr if statements. A constexpr if statement is evaluated at compile
time. Code blocks that correspond to true conditions get emitted, and the
rest is ignored.
Usage of the constexpr if follows usage for a regular if statement, as
demonstrated in Listing 8-17.
if constexpr (condition-1) {
// Compile only if condition-1 is true
} else if constexpr (condition-2) { // optional; can be multiple else ifs
// Compile only if condition-2 is true
}
--snip--
} else { // optional
// Compile only if none of the conditionals is true
}
Listing 8-17: Usage of the constexpr if statement
In combination with templates and the <type_traits> header, constexpr if
statements are extremely powerful. A major use for constexpr if is to provide
custom behavior in a function template depending on some attributes of
type parameters.
The function template value_of in Listing 8-18 accepts pointers, references, and values. Depending on which kind of object the argument is,
value_of returns either the pointed-to value or the value itself.

#include <cstdio>
#include <stdexcept>
#include <type_traits>
template <typename T>
auto value_of(T x) {
if constexpr (std::is_pointer<T>::value) {
if (!x) throw std::runtime_error{ "Null pointer dereference." };
return *x;
} else {
return x;
}
}
int main() {
unsigned long level{ 8998 };
auto level_ptr = &level;
auto &level_ref = level;
printf("Power level = %lu\n", value_of(level_ptr));
++*level_ptr;
printf("Power level = %lu\n", value_of(level_ref));
++level_ref;
printf("It's over %lu!\n", value_of(level++));
try {
level_ptr = nullptr;
value_of(level_ptr);
} catch(const std::exception& e) {
printf("Exception: %s\n", e.what());
}
}
Power level = 8998
Power level = 8999
It's over 9000!
Exception: Null pointer dereference.

Listing 8-18: An example function template, value_of, employing a constexpr if statement

The value_of function template accepts a single argument x. You determine whether the argument is a pointer type using the std::is_pointer<T>
type trait as the conditional expression in a constexpr if statement. In case
x is a pointer type, you check for nullptr and throw an exception if one is
encountered. If x isn’t a nullptr, you dereference it and return the result.
Otherwise, x is not a pointer type, so you return it (because it is therefore a
value).
Within main, you instantiate value_of multiple times with an unsigned long
pointer, an unsigned long reference, an unsigned long, and a nullptr respectively.

At runtime, the constexpr if statement disappears; each instantiation
of value_of contains one branch of the selection statement or the other. You
might be wondering why such a facility is useful. After all, programs are
meant to do something useful at runtime, not at compile time. Just flip back
to Listing 7-17 (on page 206), and you’ll see that compile time evaluation
can substantially simplify your programs by eliminating magic values.
There are other examples where compile time evaluation is popular,
especially when creating libraries for others to use. Because library writers
usually cannot know all the ways their users will utilize their library, they
need to write generic code. Often, they’ll use techniques like those you
learned in Chapter 6 so they can achieve compile-time polymorphism.
Constructs like constexpr can help when writing this kind of code.

N O T E
If you have a C background, you’ll immediately recognize the utility of compile time
evaluation when considering that it almost entirely replaces the need for preprocessor
macros.















## Switch
The switch statement transfers control to one of several statements depending on the value of a condition, which evaluates to either an integer or enumeration type.

The switch keyword denotes a switch statement.
Like an if statement, switch statements provide conditional branching. When a switch statement executes, control transfers to the case fitting the condition or to a default condition if no case matches the condition expression. The case
keyword denotes a case, whereas the default keyword denotes the default
condition.
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

As with if statements, you can instantiate within switch statements.
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
























## Iteration Statements
Iteration statements execute a statement repeatedly. The four kinds of iteration statements are the while loop, the do-while loop, the for loop, and the range-based for loop

Loops typically execute while a certain expression evaluates to true.

Typically, the expression checks whether a
variable, called the loop control variable (LCV), satisfies certain conditions.

The LCV must be properly initialized before the loop is encountered, and it should eventually make the expression evaluate to false. We do this by updating or assigning a new value to the LCV in the body of the loop.

Counter-Controlled Loop
Suppose you know exactly how many times certain statements need to be executed. For example, suppose you know exactly how many pieces of data (or entries) need to be read. In such cases, the loop assumes the form of a counter-controlled loop. That is, the LCV serves as a “counter.” Suppose that a set of statements needs to be executed N times. You can set up a counter (initialized to 0 before the loop) to track how many items have been read. Before executing the body of the loop statements, the counter is compared with N. If counter < N, the body of the loop executes. The body of the loop continues to execute until the value of counter >= N. Thus, inside the body of the loop, the value of counter increments by 1 after it reads a new item.

Sentinel Controlled Loop
You do not always know how many pieces of data (or entries) need to be read, but you may know that the last entry is a special value, called a sentinel, that will tell the loop to stop. In this case, you must read the first item before the loop so the test expression will have a valid value to test. If this item does not equal the sentinel, the body of the loop executes. The loop continues to execute as long as the program has not read the sentinel. Such a loop is called a sentinel-controlled loop.
The end-of-file (EOF) value is often a good sentinel value.

Flag-Controlled Loops
A flag-controlled loop uses a flag variable to control the loop. A flag variable is a bool variable that indicates whether a condition is true or false.
It is generally named for the true state of that condition: for example, isFound, isTallEnough, and isFull.

The condition is typically false before the loop body
In which case you set a flag variable initialized to false before executing the body of the loop statements.

The loop tests the flag variable to begin execution and continues to execute until the flag variable changes value

in the body of the loop, once a certain condition is met the flag variable is updated and the loop terminates after it finishes the current iteration.

### Loop Types
In a loop where the loop condition is evaluated before executing the body of the loop are called pretest loops.

In a loop where the loop condition is evaluated after executing the body of the loop are called posttest loops.

pretest loops have entry conditions so these loops may never
activate.

posttest loops have exit conditions and therefore
always executes the statement at least once.

## for
A for loop lets you repeat (or iterate) the execution of a statement a until a specified condition is false.

Initializer: First portion, sets counter variables.
Iteration condition: condition evaluated before each iteration.
Iteration statement: happens after each loop cycle.
Loop statement: a statement that repeats until the iteration condition is false, can be a single statement followed by a semi-colon or a block statement.

for(initializer, iteration condition, iteration statement)
  loop statement;

The for loop executes as follows:
1. The initializer executes.
2. The iteration condition is evaluated. If the loop condition evaluates to true:
  i. Execute the for loop statement.
  ii. Execute the iteration statement.
3. Repeat Step 2 until the loop condition evaluates to false.

The initializer statement usually initializes a variable (called the for loop control, or for indexed, variable)

#include <cstddef>
#include <cstdio>
int main() {
  unsigned long maximum = 0;
  unsigned long values[] = { 10, 50, 20, 40, 0 }; v
  for(size_t i=0; i < 5; i++) { w
    if (values[i] > maximumx) maximum = values[i]; y
  }
  printf("The maximum value is %lu", maximum); z
}

If you’ve programmed C or C++ before, you might be wondering why Listing 2-10
employs size_t instead of an int for the type of i. Consider that values could theoretically take up the maximum storage allowed. Although size_t is guaranteed to be
able to index any value within it, int is not. In practice, it makes little difference,
but technically size_t is correct.

The Range-Based for Loop
For certain objects which are collections of other objects, like arrays, for understands how to iterate over the range of values within an object. Each loop iteration references one element from the collection

element-type: value type which the loop will iterate over, must match the types within the iterable
element-name: identifier used to reference an element of the collection during the iteration
iterable-name: identifier of the iteration collection of which we would like to access the members of.

for(element-type element-name : iterable-name)
  loop statement;

#include <cstdio>
int main() {
  unsigned long maximum = 0;
  unsigned long values[] = { 10, 50, 20, 40, 0 };
  for(unsigned long value : values) {
    if (value > maximum) maximum = valuw;
  }
  printf("The maximum value is %lu.", maximum);
}

## while
while (expression)
  statement;

In C++, while is a reserved word. Of course, the statement can be either a simple
or compound statement. The expression acts as a decision maker and is usually a
logical expression. The statement is called the body of the loop.

## do while
do
  statement
while (expression);


Of course, statement can be either a simple or compound statement. If it is a compound statement, enclose it between braces.

In C++, do is a reserved word.
The statement executes first, and then the expression is evaluated. If the expression
evaluates to true, the statement executes again. As long as the expression in a
do. . .while statement is true, the statement executes. To avoid an infinite loop, you
must, once again, make sure that the loop body contains a statement that ultimately
makes the expression false and assures that it exits properly.









## Jump Statements
Jump statements, including the break, continue, and goto statements, transfer
control flow. Unlike selection statements, jump statements are not conditional. You should avoid using them because they can almost always
be replaced with higher-level control structures.

### break
The break statement terminates execution of the enclosing iteration or
switch statement. Once break completes, execution transfers to the statement
immediately following the for, range-based for, while, do-while, or switch
statement.

The break statement is typically used for two purposes:
  To exit early from a loop.
  To skip the remainder of the switch structure.
After the break statement executes, the program continues to execute with the first statement after the structure. The use of a break statement in a loop can eliminate the use of certain (flag) variables.

The break statement is an effective way to avoid extra variables to control a loop
and produce an elegant code. However, break statements must be used very sparingly
within a loop. An excessive use of these statements in a loop will produce spaghetti-code
(loops with many exit conditions) that can be very hard to understand and manage. You
should be extra careful in using break statements and ensure that the use of the break
statements makes the code more readable and not less readable. If you’re not sure, don’t
use break statements.

### continue
The continue statement skips the remainder of an enclosing iteration statement and continues with the next iteration.

The continue statement is used in while, for, and do...while structures.

In a while and do...while structure, the expression (that is, the loop-continue test) is evaluated immediately after the continue statement. In a for structure, the update statement is executed after the continue statement, and then the loop condition (that is, the loop-continue test) executes.


### goto
The goto statement is an unconditional jump. The target of a goto statement
is a label.

Labels
Labels are identifiers you can add to any statement. Labels give statements
a name, and they have no direct impact on the program. To assign a label,
prepend a statement with the desired name of the label followed by a
semicolon.

goto instructs execution to continue from a particular, labeled,
point in code. You can use it to go backward and re-execute certain statements.

Syntax:
SomeFunction()
{
  Start: //Label
  CodeThatRepeats;
  goto Start;
}

In modern C++, there is no good role for goto statements. Don’t use them.
