Testing our code is essential so that we can verify that it does what it should. We will also use tests to make sure that any changes we make to the code have not made things that previously worked stop working or behave in an undesired way.

Testing Types
  Unit Testing
  Integration Test
  System Testing
  Acceptance Testing:
    User acceptance testing
    Operational acceptance testing
    Constructional and regulatory acceptance testing
    Alpha and beta testing
    
  Regression Testing



Unit Testing
The unit part indicates that the test will be done on an individual unit of our code. This is typically at a function level. This means that we will try to isolate one single function (or another small unit of code) and run our tests on just that unit.



Integration Test
Integration testing is about putting several units together and testing them so that they work correctly when they are no longer isolated, but work together.



System testing
System testing tests a system when it is completely integrated into its execution environment. Here, we will test things such as whether the login works, whether we can create and edit data in the application, whether the user interface presents data correctly, and whether we can delete entries. These things are typically tested earlier in the development process too, but they need to be verified when the source code is in its live production environment.

Acceptance testing
Acceptance testing is often divided into four different types:
• User acceptance testing
• Operational acceptance testing
• Constructional and regulatory acceptance testing
• Alpha and beta testing
Let's understand these in detail:

• User acceptance testing:
This is a way to verify that the solution created works for the end users of our application. The questions we are trying to answer with these tests are if the users can use the software, if it is what they asked for, whether they have any trouble using it, and if the application behaves as anticipated.
• Operational acceptance testing:
This is done to verify the operational readiness of an application before it is released to end users.

• Constructional and regulatory acceptance testing: This is done to verify that
the developed software fulfills the conditions specified in the agreement that was
entered into with the organization that ordered the software. Regulatory testing
verifies that the software conforms to the current regulations.

• Alpha and beta testing: These are two tests that are performed to verify and
identify all possible issues and bugs. Alpha testing is performed early in the
development process, while beta testing is done near the end of the development
process. They are both conducted by potential users of the finished product or by
a group of people with a similar skill level as the end users of the application.

Regression testing
Regression testing focuses on finding defects after a significant code change and seeks to
uncover software regressions. A software regression is a bug that will make some features
in an application stop functioning after the update. There is also software performance
regression, where the software still operates correctly, but where an update harmed the
system's performance.
These were some other tests we can perform on our software. There are many more, but
the ones we have covered here are among the most typical tests you will get exposed to
as a software developer.
When we have code that is tested, we can make it available to the end users of our
application. Before we talk about how to make the code we have written available to
our users, we should stop and talk about what a release is.
