### Unit Tests
Unit tests verify that a focused, cohesive collection of code, a unit, such as a function or a class, behaves exactly as the programmer intended.

Good unit tests isolate the unit being tested from its dependencies. Sometimes this can be hard to do: the unit might depend on other units. In such situations, you use mocks to stand in for these dependencies. Mocks are fake objects you use solely during testing to provide you with fine-grained control over how a unit’s dependencies behave during the test. Mocks can also record how a unit interacted with them, so you can test whether a unit is interacting with its dependencies as expected. You can also use mocks to simulate rare events, such as a system running out of memory, by programming them to throw an exception.

### Integration Tests
Testing a collection of units together is called an integration test.

Integration tests can also refer to testing interactions between software and hardware, which system programmers deal with often. Integration tests are an important layer on top of unit tests, because they ensure that the software you’ve written works together as a system. These tests complement, but don’t replace, unit tests.

### Acceptance Tests
Acceptance tests ensure that your software meets all of your customers’ requirements.

High-performing software teams can use acceptance tests to guide development. Once all of the acceptance tests pass, your software is deliverable. Because these acceptance tests become part of the code base, there
is built-in protection against refactoring or feature regression, where you
break an existing feature in the process of adding a new one.


### Performance Tests
Performance tests evaluate whether software meets effectiveness requirements,
such as speed of execution or memory/power consumption. Optimizing
code is a fundamentally empirical exercise. You can (and should) have
ideas about which parts of your code are causing performance bottlenecks
but can’t know for sure unless you measure. Also, you cannot know whether
the code changes you implement with the intent of optimizing are improving performance unless you measure again. You can use performance tests
to instrument your code and provide relevant measures. Instrumentation
is a technique for measuring product performance, detecting errors, and
logging how a program executes. Sometimes customers have strict performance requirements (for example, computation cannot take more than
100 milliseconds or the system cannot allocate more than 1MB of memory).
You can automate testing such requirements and make sure that future
code changes don’t violate them. Code testing can be an abstract, dry subject.



### Application Architecture
The monumental task of writing a fully feature application is broken out into teams. Each team is responsible for a service. Services interact with each other via a service bus, where each service publishes events. Other services subscribe to these events as needed. This design pattern is called a service bus architecture.



### Implementing A Service
The conceptually simple way to implement a service is to iterate among writing some code, compiling the production binary, uploading it to a live environment,
and testing functionality manually.

This approach is likely to cause program crashes and to waste a whole lot of time.

A better approach is to write code, compile a unit-test binary, and run it in your desktop development environment. You can iterate among these steps more quickly; once you’re reasonably confident that the code you’ve written works as intended, you can do a manual test in a live environment.

The unit-test binary will be a simple console application targeting the
desktop operating system. In the unit-test binary, you’ll run a suite of unit
tests that pass specific inputs into a service and assert that it produces
the expected results.

A management team will communicate certain requirements that the service must achieve.
To ensure that a services requirements are met modern methods use test-driven development (TDD).
