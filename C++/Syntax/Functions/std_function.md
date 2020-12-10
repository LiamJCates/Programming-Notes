Edit with C++ Crash Course pg 269

std::function
Sometimes you just want a uniform container for storing callable objects. The
std::function class template from the <functional> header is a polymorphic
wrapper around a callable object. In other words, it’s a generic function
pointer. You can store a static function, a function object, or a lambda into
a std::function.
N O T E The function class is in the stdlib. We’re presenting it a little ahead of schedule
because it fits naturally.
With functions, you can:
•	 Invoke without the caller knowing the function’s implementation
•	 Assign, move, and copy
•	 Have an empty state, similar to a nullptr
Declaring a Function
To declare a function, you must provide a single template parameter containing the function prototype of the callable object:
std::function<return-type(arg-type-1, arg-type-2, etc.)>
The std::function class template has a number of constructors. The
default constructor constructs a std::function in empty mode, meaning it
contains no callable object.
Empty Functions
If you invoke a std::function with no contained object, std::function will
throw a std::bad_function_call exception. Consider Listing 9-25.
#include <cstdio>
#include <functional>
int main() {
std::function<void()> func; u
try {
func(); v
} catch(const std::bad_function_call& e) {
printf("Exception: %s", e.what()); w
}
}
Exception: bad function call w
Listing 9-25: The default std::function constructor and the std::bad_function_call
exception270 Chapter 9
You default-construct a std::function u. The template parameter void()
denotes a function taking no arguments and returning void. Because you
didn’t fill func with a callable object, it’s in an empty state. When you invoke
func v, it throws a std::bad_function_call, which you catch and print w.
Assigning a Callable Object to a Function
To assign a callable object to a function, you can either use the constructor
or assignment operator of function, as in Listing 9-26.
#include <cstdio>
#include <functional>
void static_func() { u
printf("A static function.\n");
}
int main() {
std::function<void()> func { [] { printf("A lambda.\n"); } }; v
func(); w
func = static_func; x
func(); y
}
A lambda. w
A static function. y
Listing 9-26: Using the constructor and assignment operator of function
You declare the static function static_func that takes no arguments and
returns void u. In main, you create a function called func v. The template
parameter indicates that a callable object contained by func takes no arguments and returns void. You initialize func with a lambda that prints the
message A lambda. You invoke func immediately afterward w, invoking the
contained lambda and printing the expected message. Next, you assign
static_func to func, which replaces the lambda you assigned upon construction x. You then invoke func, which invokes static_func rather than the
lambda, so you see A static function. printed y.
An Extended Example
You can construct a function with callable objects, as long as that object supports the function semantics implied by the template parameter of function.
Listing 9-27 uses an array of std::function instances and fills it with a
static function that counts spaces, a CountIf function object from Listing 9-12,
and a lambda that computes string length.
#include <cstdio>
#include <cstdint>
#include <functional>
struct CountIf {Functions 271
--snip--
};
size_t count_spaces(const char* str) {
size_t index{}, result{};
while (str[index]) {
if (str[index] == ' ') result++;
index++;
}
return result;
}
std::functionu<size_t(const char*)v> funcs[]{
count_spaces, w
CountIf{ 'e' }, x
[](const char* str) { y
size_t index{};
while (str[index]) index++;
return index;
}
};
auto text = "Sailor went to sea to see what he could see.";
int main() {
size_t index{};
for(const auto& func : funcsz) {
printf("func #%zd: %zd\n", index++, func(text){);
}
}
func #0: 9 w
func #1: 7 x
func #2: 44 y
Listing 9-27: Using a std::function array to iterate over a uniform collection of callable
objects with varying underlying types
You declare a std::function array u with static storage duration called
funcs. The template argument is the function prototype for a function taking
a const char* and returning a size_t v. In the funcs array, you pass in a
static function pointer w, a function object x, and a lambda y. In main,
you use a range-based for loop to iterate through each function in funcs z.
You invoke each function func with the text Sailor went to sea to see what he
could see. and print the result.
Notice that, from the perspective of main, all the elements in funcs are
the same: you just invoke them with a null-terminated string and get back
a size_t {.
N O T E Using a function can incur runtime overhead. For technical reasons, function might
need to make a dynamic allocation to store the callable object. The compiler also has
difficulty optimizing away function invocations, so you’ll often incur an indirect
function call. Indirect function calls require additional pointer dereferences.
