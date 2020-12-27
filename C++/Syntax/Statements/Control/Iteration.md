## Iteration Statements
Iteration statements repeatedly execute some code.

C++ uses four kinds of iteration statements are the while loop, the do-while loop, the for loop, and the range-based for loop


(1) attr(optional) while ( condition ) statement
(2) attr(optional) do statement while ( expression ) ;
(3) attr(optional) for ( init-statement condition(optional) ; expression(optional) ) statement
(4) attr(optional) for ( for-range-decl : for-range-init ) statement (since C++11)
1) while loop;
2) do-while loop;
3) for loop;
4) range for loop.



### for
In C++ for is a reserved word. The statement can be either a simple or compound statement. A single statement is . The initializer is used to set variables that are relevant to loop execution, for example a counter variable. The iteration condition is an expression that act to determine if the loop should continue and is usually a logical expression. The iteration statement executes after each loop iteration and is typically used to increment counter variables.

for(initializer, iteration condition, iteration statement){
  //statement;
}

#include <cstddef>
#include <cstdio>
int main() {
  unsigned long maximum = 0;
  unsigned long values[] = { 10, 50, 20, 40, 0 };
  for(size_t i = 0; i < 5; i++) {
    if (values[i] > maximumx) maximum = values[i];
  }
  printf("The maximum value is %lu", maximum);
}

If you’ve programmed C or C++ before, you might be wondering why size_t is employed instead of an int for the type of i. Consider that values could theoretically take up the maximum storage allowed. Although size_t is guaranteed to be able to index any value within it, int is not. In practice, it makes little difference, but technically size_t is correct.


### The Range-Based for Loop
For certain objects which are collections of other objects, like arrays, a C++ for loop may iterate over the range of values within an object. Each loop iteration references one element from the collection

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
    if (value > maximum) maximum = value;
  }
  printf("The maximum value is %lu.", maximum);
}

### while
while (expression){
  //statement;
}

In C++, while is a reserved word. The statement can be either a simple or compound statement. The expression acts as an expression that act to determine if the loop should continue and is usually a logical expression.

### do while
do {
  //statement
}
while (expression);

In C++, do is a reserved word. The statement executes first, and can be either a simple or compound statement. The expression acts as an expression that act to determine if the loop should continue and is usually a logical expression.
