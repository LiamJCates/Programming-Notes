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

Output:
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



























Introduction to lambdas (anonymous functions)
By nascardriver on January 3rd, 2020 | last modified by Alex on December 21st, 2020

Consider this snippet of code that we introduced in lesson 9.25 -- Introduction to standard library algorithms:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

static bool containsNut(std::string_view str) // static means internal linkage in this context
{
  // std::string_view::find returns std::string_view::npos, which is a very large number,
  // if it doesn't find the substring.
  // Otherwise it returns the index where the substring occurs in str.
  return (str.find("nut") != std::string_view::npos);
}

int main()
{
  constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

  // std::find_if takes a pointer to a function
  const auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };

  if (found == arr.end())
  {
    std::cout << "No nuts\n";
  }
  else
  {
    std::cout << "Found " << *found << '\n';
  }

  return 0;
}

This code searches through an array of strings looking for the first element that contains the substring “nut”. Thus, it produces the result:

Found walnut

And while it works, it could be improved.

The root of the issue here is that std::find_if requires that we pass it a function pointer. Because of that, we are forced to define a function that’s only going to be used once, that must be given a name, and that must be put in the global scope (because functions can’t be nested!). The function is also so short, it’s almost easier to discern what it does from the one line of code than from the name and comments.

Lambdas to the rescue

A lambda expression (also called a lambda or closure) allows us to define an anonymous function inside another function. The nesting is important, as it allows us both to avoid namespace naming pollution, and to define the function as close to where it is used as possible (providing additional context).

The syntax for lambdas is one of the weirder things in C++, and takes a bit of getting used to. Lambdas take the form:

[ captureClause ] ( parameters ) -> returnType
{
    statements;
}

The capture clause and parameters can both be empty if they are not needed.

The return type is optional, and if omitted, auto will be assumed (thus using type inference used to determine the return type). While we previously noted that type inference for function return types should be avoided, in this context, it’s fine to use (because these functions are typically so trivial).

Also note that lambdas have no name, so we don’t need to provide one.

As an aside...

This means a trivial lambda definition looks like this:

1
2
3
4
5
6
7
8

#include <iostream>

int main()
{
  []() {}; // defines a lambda with no captures, no parameters, and no return type

  return 0;
}

Let’s rewrite the above example using a lambda:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
  constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

  // Define the function right where we use it.
  const auto found{ std::find_if(arr.begin(), arr.end(),
                           [](std::string_view str) // here's our lambda, no capture clause
                           {
                             return (str.find("nut") != std::string_view::npos);
                           }) };

  if (found == arr.end())
  {
    std::cout << "No nuts\n";
  }
  else
  {
    std::cout << "Found " << *found << '\n';
  }

  return 0;
}

This works just like the function pointer case, and produces an identical result:

Found walnut

Note how similar our lambda is to our containsNut function. They both have identical parameters and function bodies. The lambda has no capture clause (we’ll explain what a capture clause is in the next lesson) because it doesn’t need one. And we’ve omitted the trailing return type in the lambda (for conciseness), but since operator!= returns a bool, our lambda will return a bool too.

Type of a lambda

In the above example, we defined a lambda right where it was needed. This use of a lambda is sometimes called a function literal.

However, writing a lambda in the same line as it’s used can sometimes make code harder to read. Much like we can initialize a variable with a literal value (or a function pointer) for use later, we can also initialize a lambda variable with a lambda definition and then use it later. A named lambda along with a good function name can make code easier to read.

For example, in the following snippet, we’re using std::all_of to check if all elements of an array are even:

1
2

// Bad: We have to read the lambda to understand what's happening.
return std::all_of(array.begin(), array.end(), [](int i){ return ((i % 2) == 0); });

We can improve the readability of this as follows:

1
2
3
4
5
6
7
8
9

// Good: Instead, we can store the lambda in a named variable and pass it to the function.
auto isEven{
  [](int i)
  {
    return ((i % 2) == 0);
  }
};

return std::all_of(array.begin(), array.end(), isEven);

Note how well the last line reads: “return whether all of the elements in the array are even”

But what is the type of lambda isEven?

As it turns out, lambdas don’t have a type that we can explicitly use. When we write a lambda, the compiler generates a unique type just for the lambda that is not exposed to us.

For advanced readers

In actuality, lambdas aren’t functions (which is part of how they avoid the limitation of C++ not supporting nested functions). They’re a special kind of object called a functor. Functors are objects that contain an overloaded operator() that make them callable like a function.

Although we don’t know the type of a lambda, there are several ways of storing a lambda for use post-definition. If the lambda has an empty capture clause, we can use a regular function pointer. In the next lesson, we introduce lambda captures, a function pointer won’t work anymore at that point. However, std::function can be used for lambdas even if they are capturing something.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33

#include <functional>

int main()
{
  // A regular function pointer. Only works with an empty capture clause.
  double (*addNumbers1)(double, double){
    [](double a, double b) {
      return (a + b);
    }
  };

  addNumbers1(1, 2);

  // Using std::function. The lambda could have a non-empty capture clause (Next lesson).
  std::function addNumbers2{ // note: pre-C++17, use std::function<double(double, double)> instead
    [](double a, double b) {
      return (a + b);
    }
  };

  addNumbers2(3, 4);

  // Using auto. Stores the lambda with its real type.
  auto addNumbers3{
    [](double a, double b) {
      return (a + b);
    }
  };

  addNumbers3(5, 6);

  return 0;
}

The only way of using the lambda’s actual type is by means of auto. auto also has the benefit of having no overhead compared to std::function.

Unfortunately, we can’t always use auto. In cases where the actual lambda is unknown (e.g. because we’re passing a lambda to a function as a parameter and the caller determines what lambda will be passed in), we can’t use auto. In such cases, std::function should be used.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20

#include <functional>
#include <iostream>

// We don't know what fn will be. std::function works with regular functions and lambdas.
void repeat(int repetitions, const std::function<void(int)>& fn)
{
  for (int i{ 0 }; i < repetitions; ++i)
  {
    fn(i);
  }
}

int main()
{
  repeat(3, [](int i) {
    std::cout << i << '\n';
  });

  return 0;
}

Output

0
1
2

Rule
Use auto when initializing variables with lambdas, and std::function if you can’t initialize the variable with the lambda.

Generic lambdas

For the most part, lambda parameters work by the same rules as regular function parameters.

One notable exception is that since C++14 we’re allowed to use auto for parameters (note: in C++20, regular functions will be able to use auto for parameters too). When a lambda has one or more auto parameter, the compiler will infer what parameter types are needed from the calls to the lambda.

Because lambdas with one or more auto parameter can potentially work with a wide variety of types, they are called generic lambdas.

For advanced readers

When used in the context of a lambda, auto is just a shorthand for a template parameter.

Let’s take a look at a generic lambda:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
  constexpr std::array months{ // pre-C++17 use std::array<const char*, 12>
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
  };

  // Search for two consecutive months that start with the same letter.
  const auto sameLetter{ std::adjacent_find(months.begin(), months.end(),
                                      [](const auto& a, const auto& b) {
                                        return (a[0] == b[0]);
                                      }) };

  // Make sure that two months were found.
  if (sameLetter != months.end())
  {
    // std::next returns the next iterator after sameLetter
    std::cout << *sameLetter << " and " << *std::next(sameLetter)
              << " start with the same letter\n";
  }

  return 0;
}

Output:

June and July start with the same letter

In the above example, we use auto parameters to capture our strings by const reference. Because all string types allow access to their individual characters via operator[], we don’t need to care whether the user is passing in a std::string, C-style string, or something else. This allows us to write a lambda that could accept any of these, meaning if we change the type of months later, we won’t have to rewrite the lambda.

However, auto isn’t always the best choice. Consider:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
  constexpr std::array months{ // pre-C++17 use std::array<const char*, 12>
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
  };

  // Count how many months consist of 5 letters
  const auto fiveLetterMonths{ std::count_if(months.begin(), months.end(),
                                       [](std::string_view str) {
                                         return (str.length() == 5);
                                       }) };

  std::cout << "There are " << fiveLetterMonths << " months with 5 letters\n";

  return 0;
}

Output:

There are 2 months with 5 letters

In this example, using auto would infer a type of const char*. C-style strings aren’t easy to work with (apart from using operator[]). In this case, we prefer to explicitly define the parameter as a std::string_view, which allows us to work with the underlying data much more easily (e.g. we can ask the string view for its length, even if the user passed in a C-style array).

Generic lambdas and static variables

One thing to be aware of is that a unique lambda will be generated for each different type that auto resolves to. The following example shows how one generic lambda turns into two distinct lambdas:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
  // Print a value and count how many times @print has been called.
  auto print{
    [](auto value) {
      static int callCount{ 0 };
      std::cout << callCount++ << ": " << value << '\n';
    }
  };

  print("hello"); // 0: hello
  print("world"); // 1: world

  print(1); // 0: 1
  print(2); // 1: 2

  print("ding dong"); // 2: ding dong

  return 0;
}

Output

0: hello
1: world
0: 1
1: 2
2: ding dong

In the above example, we define a lambda and then call it with two different parameters (a string literal parameter, and an integer parameter). This generates two different versions of the lambda (one with a string literal parameter, and one with an integer parameter).

Most of the time, this is inconsequential. However, note that if the generic lambda uses static duration variables, those variables are not shared between the generated lambdas.

We can see this in the example above, where each type (string literals and integers) has its own unique count! Although we only wrote the lambda once, two lambdas were generated -- and each has its own version of callCount. To have a shared counter between the two generated lambdas, we’d have to define a variable outside of the lambda. For now, this means defining the variable even outside of the function the lambda is defined in. In the above example, this means adding a global variable. We’ll be able to avoid the global variable after talking about lambda captures in the next lesson.

Return type deduction and trailing return types

If return type deduction is used, a lambda’s return type is deduced from the return-statements inside the lambda. If return type inference is used, all return statements in the lambda must return the same type (otherwise the compiler won’t know which one to prefer).

For example:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16

#include <iostream>

int main()
{
  auto divide{ [](int x, int y, bool bInteger) { // note: no specified return type
    if (bInteger)
      return x / y;
    else
      return static_cast<double>(x) / y; // ERROR: return type doesn't match previous return type
  } };

  std::cout << divide(3, 2, true) << '\n';
  std::cout << divide(3, 2, false) << '\n';

  return 0;
}

This produces a compile error because the return type of the first return statement (int) doesn’t match the return type of the second return statement (double).

In the case where we’re returning different types, we have two options:
1) Do explicit casts to make all the return types match, or
2) explicitly specify a return type for the lambda, and let the compiler do implicit conversions.

The second case is usually the better choice:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17

#include <iostream>

int main()
{
  // note: explicitly specifying this returns a double
  auto divide{ [](int x, int y, bool bInteger) -> double {
    if (bInteger)
      return x / y; // will do an implicit conversion to double
    else
      return static_cast<double>(x) / y;
  } };

  std::cout << divide(3, 2, true) << '\n';
  std::cout << divide(3, 2, false) << '\n';

  return 0;
}

That way, if you ever decide to change the return type, you (usually) only need to change the lambda’s return type, and not touch the lambda body.

Standard library function objects

For common operations (e.g. addition, negation, or comparison) you don’t need to write your own lambdas, because the standard library comes with many basic callable objects that can be used instead. These are defined in the <functional> header.

In the following example:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26

#include <algorithm>
#include <array>
#include <iostream>

bool greater(int a, int b)
{
  // Order @a before @b if @a is greater than @b.
  return (a > b);
}

int main()
{
  std::array arr{ 13, 90, 99, 5, 40, 80 };

  // Pass greater to std::sort
  std::sort(arr.begin(), arr.end(), greater);

  for (int i : arr)
  {
    std::cout << i << ' ';
  }

  std::cout << '\n';

  return 0;
}

Output

99 90 80 40 13 5

Instead of converting our greater function to a lambda (which would obscure its meaning a bit), we can instead use std::greater:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21

#include <algorithm>
#include <array>
#include <iostream>
#include <functional> // for std::greater

int main()
{
  std::array arr{ 13, 90, 99, 5, 40, 80 };

  // Pass std::greater to std::sort
  std::sort(arr.begin(), arr.end(), std::greater{}); // note: need curly braces to instantiate object

  for (int i : arr)
  {
    std::cout << i << ' ';
  }

  std::cout << '\n';

  return 0;
}

Output

99 90 80 40 13 5

Conclusion

Lambdas and the algorithm library may seem unnecessarily complicated when compared to a solution that uses a loop. However, this combination can allow some very powerful operations in just a few lines of code, and can be more readable than writing your own loops. On top of that, the algorithm library features powerful and easy-to-use parallelism, which you won’t get with loops. Upgrading source code that uses library functions is easier than upgrading code that uses loops.

Lambdas are great, but they don’t replace regular functions for all cases. Prefer regular functions for non-trivial and reusable cases.
















Lambda captures
By nascardriver on January 3rd, 2020 | last modified by Alex on December 21st, 2020


Capture clauses and capture by value

In the previous lesson (10.15 -- Introduction to lambdas (anonymous functions)), we introduced this example:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

int main()
{
  std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

  auto found{ std::find_if(arr.begin(), arr.end(),
                           [](std::string_view str)
                           {
                             return (str.find("nut") != std::string_view::npos);
                           }) };

  if (found == arr.end())
  {
    std::cout << "No nuts\n";
  }
  else
  {
    std::cout << "Found " << *found << '\n';
  }

  return 0;
}

Now, let’s modify the nut example and let the user pick a substring to search for. This isn’t as intuitive as you might expect.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>

int main()
{
  std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

  // Ask the user what to search for.
  std::cout << "search for: ";

  std::string search{};
  std::cin >> search;

  auto found{ std::find_if(arr.begin(), arr.end(), [](std::string_view str) {
    // Search for @search rather than "nut".
    return (str.find(search) != std::string_view::npos); // Error: search not accessible in this scope
  }) };

  if (found == arr.end())
  {
    std::cout << "Not found\n";
  }
  else
  {
    std::cout << "Found " << *found << '\n';
  }

  return 0;
}

This code won’t compile. Unlike nested blocks, where any identifier defined in an outer block is accessible in the scope of the nested block, lambdas can only access specific kinds of identifiers: global identifiers, entities that are known at compile time, and entities with static storage duration. search fulfills none of these requirements, so the lambda can’t see it. That’s what the capture clause is there for.

The capture clause

The capture clause is used to (indirectly) give a lambda access to variables available in the surrounding scope that it normally would not have access to. All we need to do is list the entities we want to access from within the lambda as part of the capture clause. In this case, we want to give our lambda access to the value of variable search, so we add it to the capture clause:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
#include <string>

int main()
{
  std::array<std::string_view, 4> arr{ "apple", "banana", "walnut", "lemon" };

  std::cout << "search for: ";

  std::string search{};
  std::cin >> search;

  // Capture @search                                vvvvvv
  auto found{ std::find_if(arr.begin(), arr.end(), [search](std::string_view str) {
    return (str.find(search) != std::string_view::npos);
  }) };

  if (found == arr.end())
  {
    std::cout << "Not found\n";
  }
  else
  {
    std::cout << "Found " << *found << '\n';
  }

  return 0;
}

The user can now search for an element of our array.

Output

search for: nana
Found banana

So how do captures actually work?

While it might look like our lambda in the example above is directly accessing the value of main‘s search variable, this is not the case. Lambdas might look like nested blocks, but they work slightly differently (and the distinction is important).

When a lambda definition is executed, for each variable that the lambda captures, a clone of that variable is made (with an identical name) inside the lambda. These cloned variables are initialized from the outer scope variables of the same name at this point.

Thus, in the above example, when the lambda object is created, the lambda gets its own cloned variable named search. This cloned search has the same value as main‘s search, so it behaves like we’re accessing main‘s search, but we’re not.

While these cloned variable have the same name, they don’t necessarily have the same type as the original variable. We’ll explore this in the upcoming sections of this lesson.

Key insight

The captured variables of a lambda are clones of the outer scope variables, not the actual variables.

For advanced readers

Although lambdas look like functions, they’re actually objects that can be called like functions (these are called functors -- we’ll discuss how to create your own functors from scratch in a future lesson).

When the compiler encounters a lambda definition, it creates a custom object definition for the lambda. Each captured variable becomes a data member of the object.

At runtime, when the lambda definition is encountered, the lambda object is instantiated, and the members of the lambda are initialized at that point.

Captures default to const value

By default, variables are captured by const value. This means when the lambda is created, the lambda captures a constant copy of the outer scope variable, which means that the lambda is not allowed to modify them. In the following example, we capture the variable ammo and try to decrement it.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23

#include <iostream>

int main()
{
  int ammo{ 10 };

  // Define a lambda and store it in a variable called "shoot".
  auto shoot{
    [ammo]() {
      // Illegal, ammo was captured as a const copy.
      --ammo;

      std::cout << "Pew! " << ammo << " shot(s) left.\n";
    }
  };

  // Call the lambda
  shoot();

  std::cout << ammo << " shot(s) left\n";

  return 0;
}

In the above example, when we capture ammo, a new const variable with the same name and value is created in the lambda. We can’t modify it, because it is const, which causes a compile error.

Mutable capture by value

To allow modifications of variables that were captured by value, we can mark the lambda as mutable. The mutable keyword in this context removes the const qualification from all variables captured by value.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23

#include <iostream>

int main()
{
  int ammo{ 10 };

  auto shoot{
    // Added mutable after the parameter list.
    [ammo]() mutable {
      // We're allowed to modify ammo now
      --ammo;

      std::cout << "Pew! " << ammo << " shot(s) left.\n";
    }
  };

  shoot();
  shoot();

  std::cout << ammo << " shot(s) left\n";

  return 0;
}

Output:

Pew! 9 shot(s) left.
Pew! 8 shot(s) left.
10 shot(s) left

While this now compiles, there’s still a logic error. What happened? When the lambda was called, the lambda captured a copy of ammo. When the lambda decremented ammo from 10 to 9 to 8, it decremented its own copy, not the original value.

Note that the value of ammo is preserved across calls to the lambda!

Capture by reference

Much like functions can change the value of arguments passed by reference, we can also capture variables by reference to allow our lambda to affect the value of the argument.

To capture a variable by reference, we prepend an ampersand (&) to the variable name in the capture. Unlike variables that are captured by value, variables that are captured by reference are non-const, unless the variable they’re capturing is const. Capture by reference should be preferred over capture by value whenever you would normally prefer passing an argument to a function by reference (e.g. for non-fundamental types).

Here’s the above code with ammo captured by reference:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22

#include <iostream>

int main()
{
  int ammo{ 10 };

  auto shoot{
    // We don't need mutable anymore
    [&ammo]() { // &ammo means ammo is captured by reference
      // Changes to ammo will affect main's ammo
      --ammo;

      std::cout << "Pew! " << ammo << " shot(s) left.\n";
    }
  };

  shoot();

  std::cout << ammo << " shot(s) left\n";

  return 0;
}

This produces the expected answer:

Pew! 9 shot(s) left.
9 shot(s) left

Now, let’s use a reference capture to count how many comparisons std::sort makes when it sorts an array.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38

#include <algorithm>
#include <array>
#include <iostream>
#include <string>

struct Car
{
  std::string make{};
  std::string model{};
};

int main()
{
  std::array<Car, 3> cars{ { { "Volkswagen", "Golf" },
                             { "Toyota", "Corolla" },
                             { "Honda", "Civic" } } };

  int comparisons{ 0 };

  std::sort(cars.begin(), cars.end(),
    // Capture @comparisons by reference.
    [&comparisons](const auto& a, const auto& b) {
      // We captured comparisons by reference. We can modify it without "mutable".
      ++comparisons;

      // Sort the cars by their make.
      return (a.make < b.make);
  });

  std::cout << "Comparisons: " << comparisons << '\n';

  for (const auto& car : cars)
  {
    std::cout << car.make << ' ' << car.model << '\n';
  }

  return 0;
}

Possible output

Comparisons: 2
Honda Civic
Toyota Corolla
Volkswagen Golf

Capturing multiple variables

Multiple variables can be captured by separating them with a comma. This can include a mix of variables captured by value or by reference:

1
2
3
4
5
6

int health{ 33 };
int armor{ 100 };
std::vector<CEnemy> enemies{};

// Capture health and armor by value, and enemies by reference.
[health, armor, &enemies](){};

Default captures

Having to explicitly list the variables you want to capture can be burdensome. If you modify your lambda, you may forget to add or remove captured variables. Fortunately, we can enlist the compiler’s help to auto-generate a list of variables we need to capture.

A default capture (also called a capture-default) captures all variables that are mentioned in the lambda. Variables not mentioned in the lambda are not captured if a default capture is used.

To capture all used variables by value, use a capture value of =.
To capture all used variables by reference, use a capture value of &.

Here’s an example of using a default capture by value:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29

#include <array>
#include <iostream>

int main()
{
  std::array areas{ 100, 25, 121, 40, 56 };

  int width{};
  int height{};

  std::cout << "Enter width and height: ";
  std::cin >> width >> height;

  auto found{ std::find_if(areas.begin(), areas.end(),
                           [=](int knownArea) { // will default capture width and height by value
                             return (width * height == knownArea); // because they're mentioned here
                           }) };

  if (found == areas.end())
  {
    std::cout << "I don't know this area :(\n";
  }
  else
  {
    std::cout << "Area found :)\n";
  }

  return 0;
}

Default captures can be mixed with normal captures. We can capture some variables by value and others by reference, but each variable can only be captured once.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24

int health{ 33 };
int armor{ 100 };
std::vector<CEnemy> enemies{};

// Capture health and armor by value, and enemies by reference.
[health, armor, &enemies](){};

// Capture enemies by reference and everything else by value.
[=, &enemies](){};

// Capture armor by value and everything else by reference.
[&, armor](){};

// Illegal, we already said we want to capture everything by reference.
[&, &armor](){};

// Illegal, we already said we want to capture everything by value.
[=, armor](){};

// Illegal, armor appears twice.
[armor, &health, &armor](){};

// Illegal, the default capture has to be the first element in the capture group.
[armor, &](){};

Defining new variables in the lambda-capture

Sometimes we want to capture a variable with a slight modification or declare a new variable that is only visible in the scope of the lambda. We can do so by defining a variable in the lambda-capture without specifying its type.

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33

#include <array>
#include <iostream>

int main()
{
  std::array areas{ 100, 25, 121, 40, 56 };

  int width{};
  int height{};

  std::cout << "Enter width and height: ";
  std::cin >> width >> height;

  // We store areas, but the user entered width and height.
  // We need to calculate the area before we can search for it.
  auto found{ std::find_if(areas.begin(), areas.end(),
                           // Declare a new variable that's visible only to the lambda.
                           // The type of userArea is automatically deduced to int.
                           [userArea{ width * height }](int knownArea) {
                             return (userArea == knownArea);
                           }) };

  if (found == areas.end())
  {
    std::cout << "I don't know this area :(\n";
  }
  else
  {
    std::cout << "Area found :)\n";
  }

  return 0;
}

userArea will only be calculated once when the lambda is defined. The calculated area is stored in the lambda object and is the same for every call. If a lambda is mutable and modifies a variable that was defined in the capture, the original value will be overridden.

Best practice

Only initialize variables in the capture if their value is short and their type is obvious. Otherwise it’s best to define the variable outside of the lambda and capture it.

Dangling captured variables

Variables are captured at the point where the lambda is defined. If a variable captured by reference dies before the lambda, the lambda will be left holding a dangling reference.

For example:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23

#include <iostream>
#include <string>

// returns a lambda
auto makeWalrus(const std::string& name)
{
  // Capture name by reference and return the lambda.
  return [&]() {
    std::cout << "I am a walrus, my name is " << name << '\n'; // Undefined behavior
  };
}

int main()
{
  // Create a new walrus whose name is Roofus.
  // sayName is the lambda returned by makeWalrus.
  auto sayName{ makeWalrus("Roofus") };

  // Call the lambda function that makeWalrus returned.
  sayName();

  return 0;
}

The call to makeWalrus creates a temporary std::string from the string literal “Roofus”. The lambda in makeWalrus captures the temporary string by reference. The temporary string dies when makeWalrus returns, but the lambda still references it. Then when we call sayName, the dangling reference is accessed, causing undefined behavior.

Note that this also happens if name is passed to makeWalrus by value. The variable name still dies at the end of makeWalrus, and the lambda is left holding a dangling reference.

Warning

Be extra careful when you capture variables by reference, especially with a default reference capture. The captured variables must outlive the lambda.

If we want the captured name to be valid when the lambda is used, we need to capture it by value instead (either explicitly or using a default-capture by value).

Unintended copies of mutable lambdas

Because lambdas are objects, they can be copied. In some cases, this can cause problems. Consider the following code:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21

#include <iostream>

int main()
{
  int i{ 0 };

  // Create a new lambda named count
  auto count{ [i]() mutable {
    std::cout << ++i << '\n';
  } };

  count(); // invoke count

  auto otherCount{ count }; // create a copy of count

  // invoke both count and the copy
  count();
  otherCount();

  return 0;
}

Output

1
2
2

Rather than printing 1, 2, 3, the code prints 2 twice. When we created otherCount as a copy of count, we created a copy of count in its current state. count‘s i was 1, so otherCount‘s i is 1 as well. Since otherCount is a copy of count, they each have their own i.

Now let’s take a look at a slightly less obvious example:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23

#include <iostream>
#include <functional>

void invoke(const std::function<void(void)>& fn)
{
    fn();
}

int main()
{
    int i{ 0 };

    // Increments and prints its local copy of @i.
    auto count{ [i]() mutable {
      std::cout << ++i << '\n';
    } };

    invoke(count);
    invoke(count);
    invoke(count);

    return 0;
}

Output:

1
1
1

This exhibits the same problem as the prior example in a more obscure form. When std::function is created with a lambda, the std::function internally makes a copy of the lambda object. Thus, our call to fn() is actually being executed on the copy of our lambda, not the actual lambda.

If we need to pass a mutable lambda, and want to avoid the possibility of inadvertent copies being made, there are two options. One option is to use a non-capturing lambda instead -- in the above case, we could remove the capture and track our state using a static local variable instead. But static local variables can be difficult to keep track of and make our code less readable. A better option is to prevent copies of our lambda from being made in the first place. But since we can’t affect how std::function (or other standard library functions or objects) are implemented, how can we do this?

Fortunately, C++ provides a convenient type (as part of the <functional> header) called std::reference_wrapper that allows us to pass a normal type as if it were a reference. For even more convenience, a std::reference_wrapper can be created by using the std::ref() function. By wrapping our lambda in a std::reference_wrapper, whenever anybody tries to make a copy of our lambda, they’ll make a copy of the reference instead, which will copy the reference rather than the actual object.

Here’s our updated code using std::ref:

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26

#include <iostream>
#include <functional>

void invoke(const std::function<void(void)> &fn)
{
    fn();
}

int main()
{
    int i{ 0 };

    // Increments and prints its local copy of @i.
    auto count{ [i]() mutable {
      std::cout << ++i << '\n';
    } };

    // std::ref(count) ensures count is treated like a reference
    // thus, anything that tries to copy count will actually copy the reference
    // ensuring that only one count exists
    invoke(std::ref(count));
    invoke(std::ref(count));
    invoke(std::ref(count));

    return 0;
}

Our output is now as expected:

1
2
3

Note that the output doesn’t change even if invoke takes fn by value. std::function doesn’t create a copy of the lambda if we create it with std::ref.

Rule

Standard library functions may copy function objects (reminder: lambdas are function objects). If you want to provide lambdas with mutable captured variables, pass them by reference using std::ref.

Best practice

Try to avoid lambdas with states altogether. Stateless lambdas are easier to understand and don’t suffer from the above issues, as well as more dangerous issues that arise when you add parallel execution.
