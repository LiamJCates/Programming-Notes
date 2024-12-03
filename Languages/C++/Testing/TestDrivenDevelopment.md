Test-driven development starts with developing test for each of a services required features. The tests initially fail, as the tests are developed even before the development. A Development team then develops and refactors the code to pass the test.

Test-driven development is related to the test-first programming evolved as part of extreme programming concepts.

Test-Driven Development Process:
  Add a Test
  Run all tests and see if the new one fails
  Write some code
  Run tests and Refactor code
  Repeat

Advantages of TDD
The process of writing a test that encodes a requirement before implementing the solution is the fundamental idea behind TDD. Proponents say that
code written this way tends to be more modular, robust, clean, and well
designed. Writing good tests is the best way to document your code for
other developers. A good test suite is a fully working set of examples that
never gets out of sync. It protects against regressions in functionality
whenever you add new features.
Unit tests also serve as a fantastic way to submit bug reports by writing
a unit test that fails. Once the bug is fixed, it will stay fixed because the unit
test and the code that fixes the bug become part of the test suite.


Red-Green-Refactor
TDD practitioners have a mantra: red, green, refactor. Red is the first step,
and it means to implement a failing test. This is done for several reasons,
principal of which is to make sure you’re actually testing something. You
might be surprised how common it is to accidentally design a test that doesn’t
make any assertions. Next, you implement code that makes the test pass.
No more, no less. This turns the test from red to green. Now that you have
working code and a passing test, you can refactor your production code.
To refactor means to restructure existing code without changing its functionality. For example, you might find a more elegant way to write the same
code, replace your code with a third-party library, or rewrite your code to
have better performance characteristics.
If you accidentally break something, you’ll know immediately because
your test suite will tell you. Then you continue to implement the remainder
of the class using TDD.

Writing a Skeleton Class
Before you can write tests, you need to write a skeleton class, which implements
an interface but provides no functionality. It’s useful in TDD because you
can’t compile a test without a shell of the class you’re testing.

A skeleton class has no instructions are in the method body. You
just need a class that exposes the appropriate methods and compiles without error. Because the methods return void, you don’t even need a return
statement.



Adding a Service-Bus Interface

Classes will have dependencies.
and a generic dependency on some publish object callable with a single
BrakeCommand parameter.

Classes that are plainold-data types are easy to use directly in your unit tests.

The publish object is a little more complicated to initialize, but thanks to lambdas, it’s really not bad.

Suppose you want to refactor the service bus.

You want to accept a std::function to subscribe to each service, as in the new IServiceBus interface:

#include <functional>
using SpeedUpdateCallback = std::function<void(const SpeedUpdate&)>;
using CarDetectedCallback = std::function<void(const CarDetected&)>;

struct IServiceBus {
  virtual ~IServiceBus() = default;
  virtual void publish(const BrakeCommand&) = 0;
  virtual void subscribe(SpeedUpdateCallback) = 0;
  virtual void subscribe(CarDetectedCallback) = 0;
};

Because IServiceBus is an interface, you don’t need to know the implementation details. It’s a nice solution because it allows you to do your own wiring into the service bus. But there’s a problem. How do you test AutoBrake in isolation? If you try to use the production bus, you’re firmly in integration test territory, and you want easy-to-configure, isolated unit tests.



Mocking Dependencies
Fortunately, you don’t depend on the implementation: you depend on the interface. You can create a mock class that implements the IServiceBus interface and use this within a class to be tested.

A mock is a special implementation that you generate for the express purpose of testing a class that depends on the mock.

Now when you exercise the tested class in your unit tests, that class interacts with the mock rather than the production service bus.
Because you have complete control over the mock’s implementation and the mock is a unit-test-specific class, you have major flexibility in how you can test classes that depend on the interface:
  •	 You can capture arbitrarily detailed information about how the mock gets called. This can include information about the parameters and the number of times the mock was called, for example.
  •	 You can perform arbitrary computation in the mock.

In other words, you have complete control over the inputs and the outputs of the dependency of the interface.
