## Lambda Functions

Lambda expressions were introduced in C++11 and help in the usage of STL algorithms to sort or process data.

An example of usage is a sort function. Typically, a sort function requires you to supply a binary predicate. This is a function that compares two arguments and returns true if one is less than the other, else false, thereby helping in deciding the order of elements in a sort operation.

Such predicates are typically implemented as operators in a class, leading to a tedious bit of coding. Lambda expressions can compact predicate definitions

Lambda expressions construct unnamed function objects succinctly. The function object implies the function type, resulting in a quick way to declare a function object on the fly. Lambdas don’t provide any additional functionality other than declaring function types the old-fashioned way. But they’re extremely convenient when you need to initialize a function object in only a single context.

There are five components to a lambda expression:
•	 captures: The member variables of the function object
•	 parameters: The arguments required to invoke the function object
•	 body: The function object’s code
•	 specifiers: Elements like constexpr, mutable, noexcept, and [[noreturn]]
•	 return type: The type returned by the function object

Syntax:
[captures] (parameters) modifiers -> return-type { body }

Only the captures and the body are required; everything else is
optional.


Each lambda component has a direct analogue in a function object.
To form a bridge between the function objects like CountIf and lambda
expressions, look at:

struct CountIf {
  CountIf(char x) : x{ x } { }                //capture
  size_t operator()(const char* str) const {  //return-type parameters modifiers
    size_t index{}, result{};
    while (str[index]) {
      if (str[index] == x) result++;
      index++;
    }
    return result;                            //body
  }
private:
  const char x;                               //parameter
};

int main() {
  CountIf s_counter{ 's' };
  auto sally = s_counter("Sally sells seashells by the seashore.");
  printf("Sally: %zd\n", sally);
}

The member variables you set in the constructor of CountIf are analogous
to a lambda’s capture. The function-call operator’s arguments, body, and return type are analogous to the lambda’s parameters, body, and return type. Finally, modifiers can apply to the function-call operator and the lambda.



### Lambda Parameters and Bodies
Lambda expressions produce function objects. As function objects, lambdas are callable. Most of the time, you’ll want your function object to accept parameters upon invocation. The lambda’s body is just like a function body: all of the parameters have function scope.

You declare lambda parameters and bodies using essentially the same
syntax that you use for functions.

For example, the following lambda expression yields a function object
that will square its int argument:

[](int x) { return x*x; }

The lambda takes a single int x and uses it within the lambda’s body to
perform the squaring.

#include <cstdio>
#include <cstdint>
template <typename Fn>
void transform(Fn fn, const int* in, int* out, size_t length) {
  for(size_t i{}; i<length; i++) {
    out[i] = fn(in[i]);
  }
}
int main() {
  const size_t len{ 3 };
  int base[]{ 1, 2, 3 }, a[len], b[len], c[len];
  transform([](int x) { return 1; }, base, a, len);
  transform([](int x) { return x; }, base, b, len);
  transform([](int x) { return 10*x+5; }, base, c, len);
  for (size_t i{}; i < len; i++) {
    printf("Element %zd: %d %d %d\n", i, a[i], b[i], c[i]);
  }
}

Element 0: 1 1 15
Element 1: 1 2 25
Element 2: 1 3 35

The transform template function accepts four arguments: a function
object fn, an in array and an out array, and the corresponding length of
those arrays. Within transform, you invoke fn on each element of in and
assign the result to the corresponding element of out.

Within main, you declare a base array 1, 2, 3 that will be used as the in
array. In the same line you also declare three uninitialized arrays a, b, and c,
which will be used as the out arrays.
  The first call to transform passes a lambda ([](int x) { return 1; }) that always returns 1, and the result is stored into a.
  The second call to transform ([](int x) { return x; }) simply returns its argument x, and the result is stored into b.
  The third call to transform multiplies the argument by 10 and adds 5. The result is stored in c.

You then print the output into a matrix where each column illustrates the transform that was applied to the different lambdas in each case.

Notice that you declared transform as a template function, allowing you to reuse it with any function object.


### Default Arguments
You can provide default arguments to a lambda. Default lambda parameters
behave just like default function parameters. The caller can specify values
for default parameters, in which case the lambda uses the caller-provided
values. If the caller doesn’t specify a value, the lambda uses the default.


### Generic Lambdas
Generic lambdas are lambda expression templates. For one or more parameters, you specify auto rather than a concrete type. These auto types become
template parameters, meaning the compiler will stamp out a custom instantiation of the lambda.

#include <cstdio>
#include <cstdint>
template <typename Fn, typename T>
  void transform(Fn fn, const T* in, T* out, size_t len) {
    for(size_t i{}; i<len; i++) {
      out[i] = fn(in[i]);
    }
}
int main() {
  constexpr size_t len{ 3 };
  int base_int[]{ 1, 2, 3 }, a[len];
  float base_float[]{ 10.f, 20.f, 30.f }, b[len];
  auto translate = [](auto x) { return 10 * x + 5; };
  transform(translate, base_int, a, l);
  transform(translate, base_float, b, l);
  for (size_t i{}; i < l; i++) {
    printf("Element %zd: %d %f\n", i, a[i], b[i]);
  }
}

Output:
Element 0: 15 105.000000
Element 1: 25 205.000000
Element 2: 35 305.000000

You add a second template parameter to transform, which you use as the pointed-to type of in and out. This allows you to apply transform to arrays of any type, not just of int types. To test out the upgraded transform template, you declare two arrays with different pointed-to types: int and float.

Next, you assign a generic lambda expression to translate x. This allows you to use the same lambda for each instantiation of transform: when you
instantiate with base_int and with base_float.

Without a generic lambda, you’d declare the parameter types explicitly:
--snip—
transform([](int x) { return 10 * x + 5; }, base_int, a, l); y
transform([](double x) { return 10 * x + 5; }, base_float, b, l); z

So far, you’ve been leaning on the compiler to deduce the return types
of your lambdas. This is especially useful for generic lambdas, because often
the lambda’s return type will depend on its parameter types. But you can
explicitly state the return type if you want.



### Lambda Return Types
The compiler deduces a lambda’s return type for you.

To take over from the compiler, you use the arrow -> syntax:

[](int x, double y) -> double { return x + y; }

This lambda expression accepts an int and a double and returns a double. You can also use decltype expressions, which can be useful with generic lambdas:

[](auto x, double y) -> decltype(x+y) { return x + y; }

Here you’ve explicitly declared that the return type of the lambda is
whatever type results from adding an x to a y.
You’ll rarely need to specify a lambda’s return type explicitly.
A far more common requirement is that you must inject an object into a lambda before invocation. This is the role of lambda captures.

Lambda Captures
Lambda captures inject objects into the lambda. The injected objects help to modify the behavior of the lambda.

Declare a lambda’s capture by specifying a capture list within brackets []. The capture list goes before the parameter list, and it can contain any number of comma-separated arguments. You then use these arguments within the lambda’s body.

A lambda can capture by reference or by value. By default, lambdas capture by value.

A lambda’s capture list is analogous to a function type’s constructor.

We reformulate CountIf:

#include <cstdio>
#include <cstdint>

int main() {
  char to_count{ 's' };
  auto s_counter = [to_count](const char* str) {
    size_t index{}, result{};
    while (str[index]) {
      if (str[index] == to_count) result++;
      index++;
    }
    return result;
  };
  auto sally = s_counter("Sally sells seashells by the seashore.");
  printf("Sally: %zd\n", sally);
  auto sailor = s_counter("Sailor went to sea to see what he could see.");
  printf("Sailor: %zd\n", sailor);
}
Sally: 7
Sailor: 3

You initialize a char called to_count to the letter s. Next, you capture
to_count within the lambda expression assigned to s_counter. This
makes to_count available within the body of the lambda expression.

To capture an element by reference rather than by value, prefix the
captured object’s name with an ampersand &. Listing 9-19 adds a capture
reference to s_counter that keeps a running tally across lambda invocations.
#include <cstdio>
#include <cstdint>
int main() {
  char to_count{ 's' };
  size_t tally{};
  auto s_counter = [to_count, &tally](const char* str) {
    size_t index{}, result{};
    while (str[index]) {
      if (str[index] == to_count) result++;
      index++;
    }
    tally += result;
    return result;
  };
  printf("Tally: %zd\n", tally);
  auto sally = s_counter("Sally sells seashells by the seashore.");
  printf("Sally: %zd\n", sally);
  printf("Tally: %zd\n", tally);
  auto sailor = s_counter("Sailor went to sea to see what he could see.");
  printf("Sailor: %zd\n", sailor);
  printf("Tally: %zd\n", tally);
}

Tally: 0
Sally: 7
Tally: 7
Sailor: 3
Tally: 10

You initialize the counter variable tally to zero, and then the s_counter lambda captures tally by reference (note the ampersand &). Within the lambda’s body, you add a statement to increment tally by an invocation’s result before returning. The result is that tally will track the total count no matter how many times you invoke the lambda. Before the first s_counter invocation, you print the value of tally (which is still zero). After you invoke s_counter with Sally sells seashells by the seashore., you have a tally of 7. The last invocation of s_counter with Sailor went to sea to see what he could see. returns 3, so the value of tally is 7 + 3 = 10.

Default Capture
So far, you’ve had to capture each element by name. Sometimes this style of capturing is called named capture. If you’re lazy, you can capture all automatic variables used within a lambda using default capture. To specify a default capture by value within a capture list, use a lone equal sign =. To specify a default capture by reference, use a lone ampersand &.

For example, you could “simplify” the lambda expression in Listing 9-19
to perform a default capture by reference, as demonstrated in Listing 9-20.
--snip--
auto s_counter = [&](const char* str) {
size_t index{}, result{};
while (str[index]) {
if (str[index] == to_count) result++;
index++;
}
tally += result;
return result;
};
--snip--

You specify a default capture by reference, which means any automatic
variables in the body of the lambda expression get captured by reference.
There are two: to_count and tally.

If you compile and run the refactored listing, you’ll obtain identical
output. However, notice that to_count is now captured by reference. If you accidentally modify it within the lambda expression’s body, the change will occur across lambda invocations as well as within main (where to_count is an automatic variable).

What would happen if you performed a default capture by value instead?
You would only need to change the = to an & in the capture list, as demonstrated in Listing 9-21.
--snip--
auto s_counter = [=](const char* str) {
size_t index{}, result{};
while (str[index]) {
if (str[index] == to_count) result++;
index++;
}
tally += result;
return result;
};
--snip--


You change the default capture to be by value. The to_count capture is
unaffected, but attempting to modify tally results in a compiler error.
You’re not allowed to modify variables captured by value unless you add the
mutable keyword to the lambda expression. The mutable keyword allows you to
modify value-captured variables. This includes calling non-const methods
on that object:

#include <cstdio>
#include <cstdint>
int main() {
char to_count{ 's' };
size_t tally{};
auto s_counter = [=](const char* str) mutable {
size_t index{}, result{};
while (str[index]) {
if (str[index] == to_count) result++;
index++;
}
tally += result;
return result;
};
auto sally = s_counter("Sally sells seashells by the seashore.");
printf("Tally: %zd\n", tally);
printf("Sally: %zd\n", sally);
printf("Tally: %zd\n", tally);
auto sailor = s_counter("Sailor went to sea to see what he could see.");
printf("Sailor: %zd\n", sailor);
printf("Tally: %zd\n", tally);
}
Tally: 0
Sally: 7
Tally: 0
Sailor: 3
Tally: 0


You declare a default capture by value , and you make the lambda
s_counter mutable. Each of the three times you print tally, you get a
zero value. Why?

Because tally gets copied by value (via the default capture), the version
in the lambda is, in essence, an entirely different variable that just happens
to have the same name. Modifications to the lambda’s copy of tally don’t
affect the automatic tally variable of main. The tally in main() is initialized
to zero and never gets modified.

It’s also possible to mix a default capture with a named capture. You
could, for example, default capture by reference and copy to_count by value
using the following formulation:

auto s_counter = [&,to_count](const char* str) {
--snip--
};

This specifies a default capture by reference and to_count capture
by value.

Although performing a default capture might seem like an easy shortcut, refrain from using it. It’s far better to declare captures explicitly. If you catch yourself saying “I’ll just use a default capture because there are too
many variables to list out,” you probably need to refactor your code.




### Initializer Expressions in Capture Lists
Sometimes you want to initialize a whole new variable within a capture list.
Maybe renaming a captured variable would make a lambda expression’s
intent clearer. Or perhaps you want to move an object into a lambda and
therefore need to initialize a variable.

To use an initializer expression, just declare the new variable’s name
followed by an equal sign and the value you want to initialize your variable
with:

auto s_counter = [&tally,my_char=to_count](const char* str) {
  size_t index{}, result{};
  while (str[index]) {
    if (str[index] == my_char) result++;
    --snip--
};

The capture list contains a simple named capture where you have
tally by reference. The lambda also captures to_count by value, but you’ve
elected to use the variable name my_char instead. Of course, you’ll need
to use the name my_char instead of to_count inside the lambda.

N O T E
An initializer expression in a capture list is also called an init capture.


### Capturing this
Sometimes lambda expressions have an enclosing class. You can capture an
enclosing object (pointed-to by this) by value or by reference using either
[*this] or [this], respectively.

#include <cstdio>
#include <cstdint>

struct LambdaFactory {
LambdaFactory(char in) : to_count{ in }, tally{} { }
auto make_lambda() {
return [this](const char* str) {
size_t index{}, result{};
while (str[index]) {
if (str[index] == to_count) result++;
index++;
}
tally += result;
return result;
};
}
const char to_count;
size_t tally;
};
int main() {
LambdaFactory factory{ 's' };
auto lambda = factory.make_lambda();
printf("Tally: %zd\n", factory.tally);
printf("Sally: %zd\n", lambda("Sally sells seashells by the seashore."));
printf("Tally: %zd\n", factory.tally);
printf("Sailor: %zd\n", lambda("Sailor went to sea to see what he could
see."));
printf("Tally: %zd\n", factory.tally);
}
Tally: 0
Sally: 7
Tally: 7
Sailor: 3
Tally: 10

The LambdaFactory constructor takes a single character and initializes
the to_count field with it. The make_lambda method illustrates how you can
capture this by reference and use the to_count and tally member
variables within the lambda expression.

Within main, you initialize a factory and make a lambda using the make_lambda method. The output is identical to Listing 9-19, because you capture this by reference and state of tally persists across invocations of lambda.



### Clarifying Examples
There are a lot of possibilities with capture lists, but once you have a command of the basics—capturing by value and by reference—there aren’t
many surprises.

Clarifying Examples of Lambda Capture Lists

| Capture list | Meaning |
|--------------|---------|
| [&] | Default capture by reference |
| [&,i] | Default capture by reference; capture i by value |
| [=] | Default capture by value |
| [=,&i] | Default capture by value; capture i by reference |
| [i] | Capture i by value |
| [&i] | Capture i by reference |
| [i,&j] | Capture i by value; capture j by reference |
| [i=j,&k] | Capture j by value as i; capture k by reference |
| [this] | Capture enclosing object by reference |
| [*this] | Capture enclosing object by value |
| [=,*this,i,&j] | Default capture by value; capture this and i by value; capture j by reference |



### constexpr Lambda Expressions

All lambda expressions are constexpr as long as the lambda can be invoked at compile time. You can optionally make the constexpr declaration explicit:

[] (int x) constexpr { return x * x; }
You should mark a lambda constexpr if you want to make sure that it
meets all constexpr requirements. As of C++17, this means no dynamic memory allocations and no calling non-constexpr functions, among other restrictions. The standards committee plans to loosen these restrictions with each
release, so if you write a lot of code using constexpr, be sure to brush up on
the latest constexpr constraints.
