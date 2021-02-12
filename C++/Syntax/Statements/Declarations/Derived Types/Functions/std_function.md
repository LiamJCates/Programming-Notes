Edit with C++ Crash Course pg 269

std::function

The std::function class template is a polymorphic wrapper around a callable object that acts as a generic function pointer. This class allows the declaration of a uniform container for storing callable objects such as a static function, a function object, or a lambda.

The std::function class in the stdlib allows:
•	 Invocation without the caller knowing the function’s implementation
•	 Assign, move, and copy
•	 Have an empty state, similar to a nullptr

The use of the std::function class requires the <function> header:

	#include <functional>



### Declaring a Function
To declare a function, you must provide a single template parameter containing the function prototype of the callable object:

	std::function<return-type(arg-type-list)>

where return-type is the return type of the callable object and arg-type-list is a comma separated list of types defined by the parameters of the object. The std::function class template has a number of constructors. The default constructor constructs a std::function in empty mode, meaning it contains no callable object.



## Empty Functions

If you invoke a std::function with no contained object, std::function will
throw a std::bad_function_call exception.

	#include <cstdio>
	#include <functional>

	int main() {
		std::function<void()> func;
		try {
			func();
		} catch(const std::bad_function_call& e) {
			printf("Exception: %s", e.what());
		}
	}

Output:

	Exception: bad function call

A std::function has been default-constructed. The template parameter void() denotes a function taking no arguments and returning void. Because you didn’t fill func with a callable object, it’s in an empty state.

When we func is invoked, it throws a std::bad_function_call, which is caught catch and printed.



## Assigning a Callable Object to a Function

To assign a callable object to a function, you can either use the constructor
or assignment operator of function.

	#include <cstdio>
	#include <functional>

	void static_func() {
		printf("A static function.\n");
	}

	int main() {
		std::function<void()> func { [] { printf("A lambda.\n"); } };
		func();
		func = static_func;
		func();
	}

Output:
	A lambda
	A static function

static_func, a function that takes no arguments and returns void, is defined.

In main, a function called func with a template parameter indicating that a callable object contained by func takes no arguments and returns void is initialize with a lambda that prints the message "A lambda".

func is immediately invoked, causing the contained lambda to print "A lambda".

static_func is then assigned to func, which replaces the lambda assigned upon construction.

func invocation now calls static_func rather than the lambda, printing "A static function".



An Extended Example
You can construct a function with callable objects, as long as that object supports the function semantics implied by the template parameter of function.

The following uses an array of std::function instances and fills it with a static function that counts spaces, a CountIf function, and a lambda that computes string length.

	#include <cstdio>
	#include <cstdint>
	#include <functional>
	struct CountIf
	{
	  --snip--
	};

	size_t count_spaces(const char *str)
	{
	  size_t index{}, result{};
	  while (str[index])
	  {
	    if (str[index] == ' ')
	      result++;
	    index++;
	  }
	  return result;
	}

	std::function<size_t(const char *)> funcs[]{
	    count_spaces, CountIf{'e'},
	    [](const char *str) {
	      size_t index{};
	      while (str[index])
	        index++;
	      return index;
	    }};

	auto text = "Sailor went to sea to see what he could see.";

	int main()
	{
	  size_t index{};
	  for (const auto &func : funcs)
	  {
	    printf("func #%zd: %zd\n", index++, func(text));
	  }
	}

Output:

	func #0: 9
	func #1: 7
	func #2: 44

Using a std::function array to iterate over a uniform collection of callable objects with varying underlying types

A std::function array with static storage duration called funcs is declared. The template argument is the function prototype for a function taking a const char* and returning a size_t. In the funcs array, a static function pointer, a function object, and a lambda is passed in. In main, a range-based for loop is used to iterate through each function in funcs.

Each function func is invoked with the text "Sailor went to sea to see what he could see." and the retult is printed.

Notice that, from the perspective of main, all the elements in funcs are the same: invoked with a null-terminated string to produce a size_t.


Using a function can incur runtime overhead. For technical reasons, function might need to make a dynamic allocation to store the callable object. The compiler also has difficulty optimizing away function invocations, so you’ll often incur an indirect function call. Indirect function calls require additional pointer dereferences.
