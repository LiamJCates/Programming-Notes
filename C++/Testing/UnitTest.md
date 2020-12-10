Assertions: The Building Blocks of Unit Tests
A unit test’s most essential component is the assertion, which checks that
some condition is met. If the condition isn’t met, the enclosing test fails.

As a general rule, you should have a single assertion per test.

Listing 10-5 implements an assert_that function that throws an exception with an error message whenever some Boolean statement is false.

#include <stdexcept>
constexpr void assert_that(bool statement, const char* message) {
  if (!statement) throw std::runtime_error{ message };
}

int main() {
  assert_that(1 + 2 > 2, "Something is profoundly wrong with the universe.");
  assert_that(24 == 42, "This assertion will generate an exception.");
}

A subtle but important feature of unit tests is that if you don’t care about some
dependency of the unit under test, you can just provide an empty implementation
that performs some innocuous, default behavior. This empty implementation is
sometimes called a stub.

Test Harnesses
A test harness is code that executes unit tests. You can make a test harness that will invoke your unit test functions

#include <exception>
--snip--
void run_test(void(*unit_test)(), const char* name) {
  try {
    unit_test();
    printf("[+] Test %s successful.\n", name);
  } catch (const std::exception& e) {
    printf("[-] Test failure in %s. %s.\n", name, e.what()); w
  }
}

The run_test harness accepts a unit test as a function pointer named
unit_test and invokes it within a try-catch statement. As long as unit_test
doesn’t throw an exception, run_test will print a friendly message stating
that the unit test passed before returning. If any exception is thrown, the
test fails and prints a disapproving message.
To make a unit-test program that will run all of your unit tests, you place
the run_test test harness inside the main function of a new program.
