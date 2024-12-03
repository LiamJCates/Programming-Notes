### The Range-Based for Loop
Executes a for loop over a range.

Used as a more readable equivalent to the traditional for loop operating over a range of values, such as all elements in a container.

For certain objects which are collections of other objects, like arrays, a C++ for loop may iterate over the range of values within an object. Each loop iteration references one element from the collection. The syntax is:

Syntax
(until C++20)

  attr(optional) for ( range_declaration : range_expression )
    statement 		

(since C++20)

  attr(optional) for ( init-statement; range_declaration : range_expression )
    statement

attr: is any number of attributes
init-statement(C++20) is either
    an expression statement (which may be a null statement ";")
    a simple declaration, typically a declaration of a variable with initializer, but it may declare arbitrary many variables or be a structured binding declaration

range_declaration: is a declaration of a named variable, whose type is the type of the element of the sequence represented by range_expression, or a reference to that type. Often uses the auto specifier for automatic type deduction

range_expression: is any expression that represents a suitable sequence (either an array or an object for which begin and end member functions or free functions are defined, see below) or a braced-init-list.

statement: is any statement, typically a compound statement, which is the loop body


Example:

  #include <cstdio>

  int main()
  {
    unsigned long maximum = 0;
    unsigned long values[] = { 10, 50, 20, 40, 0 };

    for(unsigned long value : values)
    {
      if (value > maximum) maximum = value;
    }
    printf("The maximum value is %lu.", maximum);
  }




Can I get the index of the current element?

For-each loops do not provide a direct way to get the array index of the current element. This is because many of the structures that for-each loops can be used with (such as linked lists) are not directly indexable!

Since C++20, range-based for-loops can be used with an init-statement just like the init-statement in if-statements. We can use the init-statement to create a manual index counter without polluting the function in which the for-loop is placed.

The init-statement is placed right before the loop variable:

for (init-statement; element_declaration : array)
   statement;

In the following code, we have two arrays which are correlated by index. For example, the student with the name at names[3] has a score of scores[3]. Whenever a student with a new high score is found, we print their name and difference in points to the previous high score.

  #include <iostream>

  int main()
  {
    std::string names[]{ "Alex", "Betty", "Caroline", "Dave", "Emily" };
    constexpr int scores[]{ 84, 92, 76, 81, 56 };
    int maxScore{ 0 };

    for (int i{ 0 }; auto score : scores)
    {
        if (score > maxScore)
        {
            std::cout << names[i] << " beat the previous best score of " << maxScore << " by " << (score - maxScore) << " points!\n";
            maxScore = score;
        }

        ++i;
    }

    std::cout << "The best score was " << maxScore << '\n';

    return 0;
  }

Output

Alex beat the previous best score of 0 by 84 points!
Betty beat the previous best score of 84 by 8 points!
The best score was 92

The int i{ 0 }; is the init-statement, it only gets executed once when the loop starts. At the end of each iteration, we increment i, similar to a normal for-loop. However, if we were to use continue inside the loop, the ++i would get skipped, leading to unexpected results. If you use continue, you need to make sure that i gets incremented before the continue is encountered.

Before C++20, the index variable i had to be declared outside of the loop, which could lead to name conflicts when we wanted to define another variable named i later in the function.
