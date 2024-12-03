Testing Intro

Testing is the cornerstone of any professional software product. Testing itself comes in many forms, at many different levels. Software is tested as a whole, complete artifact, but when broken down, each of the individual components should be tested, and therefore be testable, too.

Test Driven Development: by thinking of testing at the start of the development process, the software as a whole becomes easier to test

Plenty of rich, full-featured, complete testing solutions are available for testing code written for Java. One of the most ubiquitous and well-understood libraries for this is JUnit.

By writing tests first and making sure the tests are fully integrated into a build means that the tests will run any time a build is created, such as before code is checked in, or when a release artifact is built. This, in turn, builds confidence that the system is working correctly. Any time a test fails for a seemingly unknown reason; this can often be due to new code introducing bugs elsewhere in the system. This is known as a regression.

The smaller the change made between test runs, the more confidence you can have that your change made a test pass, rather than some environmental change or even a change in a seemingly unrelated piece of code.

All Java code should be written to be testable by small, independent JUnit tests.
This is a good discipline to carry through for any small coding interview questions
and is generally a good technique for understanding how code works. Rather than
polluting classes with a main() method to execute test code, writing JUnit tests provides isolated, independent snippets of code. On a project managed by Maven, or
something similar, this code would not be loaded into a live production system either.
While attempting to understand the code, rather than scattering plenty of
System.out.println() or logger.debug() lines, you can make assertions, and
use the JUnit framework to test these assertions. A passing test means your assertions are correct.
These small exploratory snippets of code become tests in their own right: As long
as the tests are consistently passing, you have created the beginnings of a test suite.
The more tests you write, the better you become at reasoning about existing code,
and it also helps to break down code into small, atomic, isolated chunks.
Any time you are asked to do a small programming assignment as part of an interview, you should always write tests, whether you were asked to or not. It demonstrates that you are disciplined; have mature reasoning for how to understand and
test code; and also provides a level of documentation, which is an aid to any interviewer to how you were thinking at the time.



### What value do JUnit tests give?
JUnit tests are often used with the development approach known as Test-Driven Development
(TDD). The process of TDD is to perform short, iterative loops: You write a test based on expectations and assertions about what your code should do. Considering you would not yet have written
the code for these tests, they should not pass. You then write the code to make the tests pass. Once
the test passes, you repeat the process for a new piece of functionality. If your tests completely cover
a specification of what you are trying to achieve, then once all the tests pass, you have the confidence that your code works and is correct.
The tests do not need to be confined to making sure functionality is correct: You can specify nonfunctional requirements, and only pass tests once those requirements are met. Some examples could
be making sure a server under load responds to requests within a certain time, or that certain security parameters are met.
For any reasonable-sized project, you will probably be using a build system, such as Maven or Ant.
The tests you have written can, and should, be integrated into your build, so that any changes to
the underlying code that break the tests means your build halts, and you must fix the code before
your build works again. This saves you from introducing bugs once the code has been released.
For Maven, the tests are automatically run as part of the build. For Ant, tests are integrated with a
single command.

Confidence in your code being correct means you can put increased reliance in automated tools.
For developing server-side architectures, you can move toward a continuous delivery model, where
fully tested code is automatically released to a production server with no human intervention after
check-in.



### How are JUnit tests run?
while JUnit is well integrated into many build tools, but it is still possible to invoke it manually on the command line.

In the JUnit library, the class JUnitCore contains the main method used for starting the tests from
the command line. The arguments are a list of classes to test:
$ /path/to/java –cp /path/to/junit.jar:. [classes to test]

For Maven, which works with project layouts following a specific convention, simply running
mvn test in the root directory of the project will find and run all tests in the project. Maven itself is
highly configurable, and specifying only a dependency on the JUnit library will specifically use JUnit
for testing.

You can run Maven with a declaration of which tests to run. If you set the system property test,
only the tests set in that property will be run:

mvn test –Dtest=SystemTest

The test parameter can take wildcards, so setting the system property to a value such as -Dtest=*IntegrationTest would run any test suffixed with IntegrationTest.




### The JUnit Test Life Cycle
When you run a test suite, each test follows a prescribed set of steps. These steps can help you
modularize your tests and reuse as much code as possible.

What happens when running a JUnit test?

A test suite is usually confined to a class.
Before annotations arrived in JUnit 4, you would need your class to extend TestSuite.

You can define a method, or set of methods, to run once, before the whole suite is run. These may
do some long-running computations, such as preparing the filesystem for the upcoming tests, or
some kind of pretesting notification to a build server or similar.

To run some code once as the test suite is started, you specify a public static method that returns
void, and annotate it with @BeforeClass. The method is static, so you do not have access to a fully
constructed instance of the test suite class, such as the instance variables or instance methods.

Mirroring this annotation is @AfterClass. Methods with this annotation are run after all tests have
completed.

As soon as the @BeforeClass annotated methods have completed successfully, the test runner performs the following steps for each test in the suite:

1. A new instance of the suite is constructed. As with all Java classes, any code in the constructor is run. Test suite classes may only declare a single constructor with no arguments.

2. Immediately following the object construction, any public methods with a @Before annotation
and with a void return type are run. These usually set up anything common across all tests,
such as mock objects or objects with state. Because this is run before each test, you can use this
to return stateful objects to their correct state, or perhaps set the filesystem to a state expected
for your test. Because both the constructor and @Before annotated methods are run before
each test, you can do any test setup in either of these positions. The convention is to perform
the setup in the @Before methods, to keep symmetry with the equivalent @After method.

3. The test is then run. Tests that are defined with the @Test annotation, are public, and again,
have a void return type.

4. Following a successful, or unsuccessful, run of the test, the @After annotated (again,
public void) methods are called. This will tidy up anything the test may have dirtied, such
as a database or filesystem, or perhaps perform some post-test logging.


The order in which the @Before, @After, and @Test methods run is not guaranteed, so you cannot do some partial setup in one @Before method, and expect another @Before method written later in the source file to finish that setup.
This is the heart of JUnit: Your tests should be independent and atomic.v
This shows all of the steps for a suite with two tests, using a counter to verify the order in which all the components are run.

public class JUnitLifecycle {
    private static int counter = 0;

    @BeforeClass
    public static void suiteSetup() {assertEquals(0, counter++);}

    public JUnitLifecycle() {
        assertTrue(Arrays.asList(1, 5).contains(counter++));
    }

    @Before
    public void prepareTest() {
        assertTrue(Arrays.asList(2, 6).contains(counter++));
    }

    @Test
    public void peformFirstTest() {
        assertTrue(Arrays.asList(3, 7).contains(counter++));
    }

    @Test
    public void performSecondTest() {
        assertTrue(Arrays.asList(3, 7).contains(counter++));
        counter++;
    }

    @After
    public void cleanupTest() {
       assertTrue(Arrays.asList(4, 8).contains(counter++));
    }

    @AfterClass
    public static void suiteFinished() { assertEquals(9, counter); }
}
The counter used in the code is a static variable, because for this test suite to run, the test runner
instantiates JUnitLifecycle twice, one for each @Test.


Any test methods annotated with @Ignore are ignored. The @Ignore annotation is often used for
tests that are known to fail and would break a continuous integration build. This is often a sign of
code smell: The code backed by the tests has changed, but the tests have not. Code smell is a symptom that usually points to a deeper problem. This can lead to code not covered by tests, and reduces
the confidence of a correct codebase. Any @Ignored tests in code submitted for an interview would
be treated with concern.
Should you ever find yourself with a justifiable reason for annotating some tests with @Ignore, be
sure to include a comment with a date as to why the test is ignored, describing how and when this
will be rectified.
You can also use the @Ignore annotation at the class level, instructing the JUnit runner to skip a
whole suite of tests.




### Assert
One of the core classes in the JUnit library is the Assert class. It contains many static methods for
expressing an assumption, which then verifies that assumption is true. Some of the key methods and
their function are:
➤ assertEquals—Two objects are equal according to their equals method.
➤ assertTrue and assertFalse—The given statement matches the Boolean expectation.
➤ assertNotNull—An object is not null.
➤ assertArrayEquals—The two arrays contain the same values, checking equality by
equals if comparing Object arrays.
If the assertion does not hold, an exception is thrown. Unless that exception is expected, or caught,
that exception will fail the JUnit test.
There is also the fail method, which you can use if your test has reached a failing state. Most of
the assertXXX methods call fail when necessary.
Take a look at the Assert class, and see what other assertion methods exist and how you can make
use of them.
Each of the assertXXX methods are overloaded in pairs, with an extra String parameter available:
public static void assertTrue(String message, boolean condition)
public static void assertTrue(boolean condition)

This String parameter is a message that is displayed when assertion fails.






### Exceptions

How can you expect certain exceptions?

If you are testing a failing situation in your code, and you expect an exception to occur, you can notify the test of your expected exception type. If that exception is thrown in the test, it passes. Completion of the test without that exception being thrown is a failure.

@Test(expected = NoSuchFileException.class)
public void expectException() throws IOException {
 Files.size(Paths.get("/tmp/non-existent-file.txt"));
}
The parameter to the @Test annotation provides an indication to the test runner that this test
should throw an exception. The method still needs to declare throws IOException here because
IOException is a checked exception.

It is advisable to use the expected parameter on the @Test annotation sparingly. The most reliable tests using this parameter have only one line in the method body: the line that should throw the exception. Therefore, it is crystal clear to see how and why a test could start failing





### timeout
How can a test fail if it does not complete quickly enough?

The @Test annotation can take two parameters. One is expected (which you have already seen),
which allows tests to pass when a certain type of exception is thrown. The other parameter is a
timeout, which takes a value of type long. The number represents a number of milliseconds, and if
the test is running for longer than that time, the test fails.
This test condition can help meet certain non-functional conditions. For example, if you were writing a service that had a requirement to respond within a second, you would write an integration test
to make sure this requirement was met.

@Test(timeout = 1000L)
public void serviceResponseTime() {
 // constructed against a real service
 final HighScoreService realHighScoreService = ...
 final Game gameUnderTest = new Game(realHighScoreService);
 final String highScoreDisplay = gameUnderTest.displayHighScores();
 assertNotNull(highScoreDisplay);
}

This integration test calls out to a real-world high score service, and if the test does not complete within a second, an exception is thrown with the notification that the test timed out. Of course, this timeout is for the whole test to complete, not the specific long-running method call. Similar to the exception expectation, if you want to explicitly check that a method call took less than a certain amount of time, you can either have that single method call in the test, or run the method call in a separate thread





### @RunWith
How does the @RunWith annotation work?

The @RunWith annotation is a class-level annotation, and it provides a mechanism for changing
the default behavior of the test runner. The parameter to the annotation is a subclass of Runner.
JUnit itself comes with several runners, the default being JUnit4, and a common alternative is the
Parameterized class.

When a JUnit test is annotated with @RunWith(Parameterized.class), several changes are made
to the life cycle of the test and the way the test is run. A class-level method providing the test data is
expected, and this returns an array of data to use for testing. This data could be hard-coded in the
test, or for more sophisticated tests, this could be dynamically produced, or even pulled in from a
filesystem, database, or another relevant storage mechanism.
However this data is generated, each element in the array from this method is passed into the constructor for the test suite, and all tests run with that data.

Listing 9-9 shows a test suite run with the Parameterized runner. It provides a layer of abstraction
over the tests; all of the tests are run against each of the data sets.
Listing 9-9: Using the Parameterized test runner

@RunWith(Parameterized.class)
public class TestWithParameters {
 private final int a;
 private final int b;
 private final int expectedAddition;
 private final int expectedSubtraction;
 private final int expectedMultiplication;
 private final int expectedDivision;
 public TestWithParameters(final int a,
 final int b,
 final int expectedAddition,
 final int expectedSubtraction,
 final int expectedMultiplication,
 final int expectedDivision) {
 this.a = a;
 this.b = b;
 this.expectedAddition = expectedAddition;
 this.expectedSubtraction = expectedSubtraction;
 this.expectedMultiplication = expectedMultiplication;
 this.expectedDivision = expectedDivision;
 }
 @Parameterized.Parameters
 public static List<Integer[]> parameters() {
 return new ArrayList<Integer[]>(3) {{
 add(new Integer[] {1, 2, 3, -1, 2, 0});
 add(new Integer[] {0, 1, 1, -1, 0, 0});
 add(new Integer[] {-11, 2, -9, -13, -22, -5});
 }};
 }
 @Test
 public void addNumbers() {
 assertEquals(expectedAddition, a + b);
 }
 @Test
 public void subtractNumbers() {
 assertEquals(expectedSubtraction, a - b);
 }
 @Test
 public void multiplyNumbers() {
 assertEquals(expectedMultiplication, a * b);
 }
 @Test
 public void divideNumbers() {
 assertEquals(expectedDivision, a / b);
 }
}

This listing introduces some new concepts. First, a new annotation, @Parameterized.Parameters,
needs to be placed on a public class method, and it returns a list of arrays. The objects in each array
are passed to the constructor of the test, with the same ordering in the array as the ordering to the
constructor.
One thing to bear in mind is that for test suites that require many parameters, it can be unwieldy or
unclear as to which position in the provided array matches which constructor argument.
For this listing, the parameters() class method returns a readily constructed instance of an
ArrayList.






Learn JUnit / Mokito
