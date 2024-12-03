## Assert
C++ includes a predefined function, assert, that is useful in stopping program execution when certain errors occur.


The specification of the assert function is found in the header file cassert. Therefore, to use the assert function, a program must include:

  #include <cassert>

The syntax to use the assert function is:

  assert(expression);

Here, expression is any logical expression. If expression evaluates to true, the next statement executes. If expression evaluates to false, the program halts.

The assert statement not only halts the program, but also identifies the expression where the assertion failed, the name of the file containing the source code, and the line number where the assertion failed.

The intention of the assertion expression is that it will be true unless there is a bug in the program. If the expression evaluates to true, the assertion statement does nothing. If the conditional expression evaluates to false, an error message is displayed and the program is terminated (via std::abort). This error message typically contains the expression that failed as text, along with the name of the code file and the line number of the assertion. This makes it very easy to tell not only what the problem was, but where in the code the problem occurred. This can help with debugging efforts immensely.


  #include <cassert> // for assert()
  #include <cmath> // for std::sqrt
  #include <iostream>

  double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity)
  {
    assert(gravity > 0.0); // The object won't reach the ground unless there is positive gravity.

    if (initialHeight <= 0.0)
    {
      // The object is already on the ground. Or buried.
      return 0.0;
    }

    return std::sqrt((2.0 * initialHeight) / gravity);
  }

  int main()
  {
    std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, -9.8) << " second(s)\n";

    return 0;
  }

When the program calls calculateTimeUntilObjectHitsGround(100.0, -9.8), assert(gravity > 0.0) will evaluate to false, which will trigger the assert. That will print a message similar to this:

dropsimulator: src/main.cpp:6: double calculateTimeUntilObjectHitsGround(double, double): Assertion 'gravity > 0.0' failed.

The actual message varies depending on which compiler you use.

Although asserts are most often used to validate function parameters, they can be used anywhere you would like to validate that something is true.

Although programs should generally avoid preprocessor macros, asserts are one of the few preprocessor macros that are considered acceptable to use. Use assert statements liberally throughout your code.



### Excluding Assertions
The assert macro comes with a small performance cost that is incurred each time the assert condition is checked. Furthermore, asserts should (ideally) never be encountered in production code (because your code should already be thoroughly tested).

This means that assert statements are useful during program development. After a program has been developed and put into use, if an assert statement fails for some reason, an end user would have no idea what the error means. Consequently, many developers prefer that asserts are only active in debug builds.

Therefore, after you have developed and tested a program, you might want to remove or disable the assert statements. In a very large program, it could be tedious, and perhaps impossible, to remove all of the assert statements that you used during development. In addition, if you plan to modify a program in the future, you might like to keep the assert statements. Therefore, the logical choice is to keep these statements but to disable them.

You can disable assert statements by using the following preprocessor directive:

  #define NDEBUG

This preprocessor directive #define NDEBUG must be placed before the directive

  #include <cassert>.

For more information about the preprocessor see:
[C++\Syntax\Statements\Declarations\PreprocessorDirectives.md]

Some IDEs set NDEBUG by default as part of the project settings for release configurations. For example, in Visual Studio, the following preprocessor definitions are set at the project level: WIN32;NDEBUG;_CONSOLE. If you’re using Visual Studio and want your asserts to trigger in release builds, you’ll need to remove NDEBUG from this setting.

If you’re using an IDE or build system that doesn’t automatically define NDEBUG in release configuration, add it in the project or compilation settings manually.



### Making Assertions More Descriptive

Sometimes assert expressions aren’t very descriptive. Consider the following statement:

  assert(found);

If this assert is triggered, the assert output will generally produce:

  Assertion failed: found, file C:\\VCProjects\\Test.cpp, line 34

To make your assert statements more descriptive, join a string literal by a logical AND:

  assert(found && "Car could not be found in database");

When the assert triggers, the string literal will be included in the assert message:

  Assertion failed: found && "Car could not be found in database", file C:\\VCProjects\\Test.cpp, line 34


Here’s why this works: A string literal always evaluates to Boolean true. So if found is false, false && true is false. If found is true, true && true is true. Thus, logical AND-ing a string literal doesn’t impact the evaluation of the assert.



### assert limitations and warnings

There are a few pitfalls and limitations to asserts. First, the assert itself can have a bug. If this happens, the assert will either report an error where none exists, or fail to report a bug where one does exist.

Second, your asserts should have no side effects -- that is, the program should run the same with and without the assert. Otherwise, what you are testing in a debug configuration will not be the same as in a release configuration (assuming you ship with NDEBUG).

Also note that the abort() function terminates the program immediately, without a chance to do any further cleanup (e.g. close a file or database). Because of this, asserts should be used only in cases where corruption isn’t likely to occur if the program terminates unexpectedly.




### Asserts vs error handling

Assertions and error handling are similar enough that their purposes can be confused, so let’s clarify:

The goal of an assertion is to catch programming errors by documenting something that should never happen. If that thing does happen, then the programmer made an error somewhere, and that error can be identified and fixed. Assertions do not allow recovery from errors (after all, if something should never happen, there’s no need to recover from it), and the program will not produce a friendly error message.

On the other hand, error handling is designed to gracefully handle cases that could happen (however rarely) in release configurations. These may or may not be recoverable, but one should always assume a user of the program may encounter them.




### Best practice

Use assertions to document cases that should be logically impossible.

Assertions are also sometimes used to document cases that were not implemented because they were not needed at the time the programmer wrote the code:

  assert(moved && "Need to handle case where student was just moved to another classroom");

That way, if a future user of the code does encounter a situation where this case is needed, the code will fail with a useful error message, and the programmer can then determine how to implement that case.




### static_assert

C++11 added another type of assert called static_assert. A static_assert is an assertion that is checked at compile-time rather than at runtime, with a failing static_assert causing a compile error.

A static_assert takes the following form:

  static_assert(condition, diagnostic_message)

If the condition is not true, the diagnostic message is printed. Here’s an example of using static_assert to ensure types have a certain size:

  static_assert(sizeof(long) == 8, "long must be 8 bytes");
  static_assert(sizeof(int) == 4, "int must be 4 bytes");

  int main()
  {
  	return 0;
  }

On the author’s machine, when compiled, the compiler errors:

1>c:\consoleapplication1\main.cpp(19): error C2338: long must be 8 bytes

Because static_assert is evaluated by the compiler, the condition must be able to be evaluated at compile time. Also, unlike normal assert (which is evaluated at runtime), static_assert can be placed anywhere in the code file (even in global space).

In C++11 and C++14, the diagnostic message must be supplied as the second parameter. Since C++17, providing a diagnostic message is optional.
