### If
Conditionally executes another statement.

Used where code needs to be executed based on a run-time or compile-time condition.

Syntax
attr(optional) if ( condition ) statement-true 		(until C++17)
attr(optional) if ( condition ) statement-true else statement-false 		(until C++17)
attr(optional) if constexpr(optional) ( init-statement(optional) condition ) statement-true 		(since C++17)
attr(optional) if constexpr(optional) ( init-statement(optional) condition ) statement-true else statement-false 		(since C++17)


attr(C++11) 	- 	any number of attributes

condition 	- 	one of
    expression which is contextually convertible to bool
    declaration of a single non-array variable with a brace-or-equals initializer.

init-statement(C++17) 	- 	either
    an expression statement (which may be a null statement ";")
    a simple declaration, typically a declaration of a variable with initializer, but it may declare arbitrary many variables or be a decomposition declaration

    Note that any init-statement must end with a semicolon ;, which is why it is often described informally as an expression or a declaration followed by a semicolon.

statement-true 	- 	any statement (often a compound statement), which is executed if condition evaluates to true

statement-false 	- 	any statement (often a compound statement), which is executed if condition evaluates to false




Explanation

if (boolean-expression) statement;

An if statement minimally contains a Boolean expression and one or more nested statements. Depending on whether the Boolean evaluates to true or false, the program decides which nested statement to execute.

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
If you have a C background, you’ll immediately recognize the utility of compile time evaluation when considering that it almost entirely replaces the need for preprocessor macros.







More:
https://en.cppreference.com/w/cpp/language/if
