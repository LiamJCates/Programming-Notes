## The Function-Call Operator
You can make user-defined types callable or invocable by overloading the function-call operator operator(). Such a type is called a function type, and instances of a function type are called function objects. The function-call operator permits any combination of argument types, return types, and modifiers (except static).

The primary reason you might want to make a user-defined type callable is to interoperate with code that expects function objects to use the function-call operator. You’ll find that many libraries, such as the stdlib, use the function-call operator as the interface for function-like objects.

When we create an asynchronous task with the std::async function, which accepts an arbitrary function object that can execute on a separate thread. It uses the function-call operator as the interface. The committee that invented std::async could have required you to expose, say, a run method, but they chose the function-call operator because it allows generic code to use identical notation to invoke a function or a function object.

Listing 9-11 illustrates the function-call operator’s usage.
struct type-name {
  return-type operator()(arg-type1 arg1, arg-type2 arg2, ...) {
    // Body of function-call operator
  }
}

The function-call operator has the special operator() method name. You declare an arbitrary number of arguments, and you also decide the appropriate return type.
When the compiler evaluates a function-call expression, it will invoke the function-call operator on the first operand, passing the remaining operands as arguments. The result of the function-call expression is the result of invoking the corresponding function-call operator.

A Counting Example
Consider the function type CountIf, which computes the frequency of a particular char in a null-terminated string:

#include <cstdio>
#include <cstdint>

struct CountIf {
  CountIf(char x) : x{ x } { }
  size_t operator()(const char* str) const {
    size_t index{}, result{};
    while (str[index]) {
      if (str[index] == x) result++;
      index++;
    }
    return result;
  }
private:
  const char x;
};

int main() {
  CountIf s_counter{ 's' };
  auto sally = s_counter("Sally sells seashells by the seashore.");
  printf("Sally: %zd\n", sally);
  auto sailor = s_counter("Sailor went to sea to see what he could see.");
  printf("Sailor: %zd\n", sailor);
  auto buffalo = CountIf{ 'f' }("Buffalo buffalo Buffalo buffalo "
  "buffalo buffalo Buffalo buffalo.");
  printf("Buffalo: %zd\n", buffalo);
}

Output
Sally: 7
Sailor: 3
Buffalo: 16

Listing 9-12: A function type that counts the number of characters appearing in a nullterminated string

You initialize CountIf objects using a constructor taking a char. You can call the resulting function object as if it were a function taking a nullterminated string argument, because you’ve implemented the function call operator. The function call operator iterates through each character in the argument str using an index variable, incrementing the result variable whenever the character matches the x field. Because calling the function doesn’t modify the state of a CountIf object, you’ve marked it const. Within main, you’ve initialized the CountIf function object s_counter, which will count the frequency of the letter s. You can use s_counter as if it were a function. You can even initialize a CountIf object and use the function operator directly as an rvalue object. You might find this convenient to do in some settings where, for example, you might only need to invoke the object a single time.

You can employ function objects as partial applications:

#include <cstdio>
#include <cstdint>

size_t count_if(char x, const char* str) {
  size_t index{}, result{};
  while (str[index]) {
    if (str[index] == x) result++;
    index++;
  }
  return result;
}
int main() {
  auto sally = count_if('s', "Sally sells seashells by the seashore.");
  printf("Sally: %zd\n", sally);
  auto sailor = count_if('s', "Sailor went to sea to see what he could see.");
  printf("Sailor: %zd\n", sailor);258 Chapter 9
  auto buffalo = count_if('f', "Buffalo buffalo Buffalo buffalo "
  "buffalo buffalo Buffalo buffalo.");
  printf("Buffalo: %zd\n", buffalo);
}

Output:
Sally: 7
Sailor: 3
Buffalo: 16

Listing 9-13: A free function emulating Listing 9-12

The count_if function has an extra argument x u, but otherwise it’s almost identical to the function operator of CountIf.

N O T E
In functional programming parlance, the CountIf is the partial application of x to count_if. When you partially apply an argument to a function, you fix that argument’s value. The product of such a partial application is another function taking one less argument.

Declaring function types is verbose. You can often reduce the boilerplate substantially with lambda expressions.
