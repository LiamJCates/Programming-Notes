Unit-Testing Frameworks
Unit-testing frameworks provide commonly used functions and the scaffolding you need to tie your tests together into a user-friendly program. These
frameworks provide a wealth of functionality that helps you create concise,
expressive tests.

Dozens of high-quality options are available. None of them is universally superior. Most frameworks support the same basic set of features, whereas some of the more advanced features will have heterogeneous support. Mainly, you should select a unit-testing framework based on the style
that makes you comfortable and productive.

Mocking Frameworks
Mocking frameworks are a bit more opinionated than unit-testing frameworks. Depending on the mocking framework, you must follow certain design
guidelines for how classes depend on each other.

The AutoBrake class used a
modern design pattern called dependency injection. The AutoBrake class depends
on an IServiceBus, which you injected using the constructor of AutoBrake. You
also made IServiceBus an interface. Other methods for achieving polymorphic
behavior exist (like templates), and each involves trade-offs.

Mocking frameworks enables you to define mock classes, often using macro or template voodoo. Within each unit test, you can customize the mock specifically
for that test. This would be extremely difficult to do with a single mock
definition.
This decoupling of the mock’s declaration from the mock’s test-specific
definition is extremely powerful for two reasons. First, you can define different kinds of behavior for each unit test. This allows you to, for example,
simulate exceptional conditions for some unit tests but not for others.
Second, it makes the unit tests far more specific. By placing the custom
mock’s behavior within a unit test rather than in a separate source file,
it’s much clearer to the developer what the test is trying to achieve.
The net effect of using a mocking framework is that it makes mocking
much less problematic. When mocking is easy, it makes good unit testing
(and TDD) possible. Without mocking, unit testing can be very difficult;
tests can be slow, unreliable, and brittle due to slow or error-prone dependencies. It’s generally preferable, for example, to use a mock database
connection instead of a full-blown production instance while you’re trying
to use TDD to implement new features into a class.
