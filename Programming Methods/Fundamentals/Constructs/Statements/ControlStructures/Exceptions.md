In computing and computer programming, exception handling is the process of responding to the occurrence of exceptions – anomalous or exceptional conditions requiring special processing - during the execution of a program.

In general, an exception breaks the normal flow of execution and executes a pre-registered exception handler; the details of how this is done depend on whether it is a hardware or software exception and how the software exception is implemented.

In programming language with mechanisms for exception handling, the term exception is typically used in a specific sense to denote a data structure storing information about an exceptional condition. One mechanism to transfer control, or raise an exception, is known as a throw. The exception is said to be thrown. Execution is transferred to a "catch".

From the point of view of the author of a routine, raising an exception is a useful way to signal that a routine could not execute normally - for example, when an input argument is invalid (e.g. value is outside of the domain of a function) or when a resource it relies on is unavailable (like a missing file, a hard disk error, or out-of-memory errors), or that the routine has detected a normal condition that requires special handling, e.g., attention, end of file.

Programming languages differ substantially in their notion of what an exception is. Contemporary languages can roughly be divided into two groups:
  Languages where exceptions are designed to be used as flow control structures
  Languages where exceptions are only used to handle abnormal, unpredictable, erroneous situations

In many computer languages with built-in support for exceptions and exception handling. Exception handling is commonly not resumable in those languages, and when an exception is thrown, the program searches back through the stack of function calls until an exception handler is found.

Some languages call for unwinding the stack as this search progresses. That is, if function f, containing a handler H for exception E, calls function g, which in turn calls function h, and an exception E occurs in h, then functions h and g may be terminated, and H in f will handle E.


Handling Exceptions
To understand how we can handle exceptions, we must first understand what the origins of a problem might be. It is only when we have understood this that we can insert measures to handle them correctly.

There are many types of errors and languages offer a variety of methods to handle errors depending on the type of error that occurs. Exceptions can be caught, but we need to specify what exception it is we want to handle. If we get an exception of an unanticipated type, the program will crash as before.


Syntax
Exception handling syntax is the set of keywords and/or structures provided by a computer programming language to allow exception handling, which separates the handling of errors that arise during a program's operation from its ordinary processes. Syntax for exception handling varies between programming languages, partly to cover semantic differences but largely to fit into each language's overall syntactic structure. Some languages do not call the relevant concept "exception handling"; others may not have direct facilities for it, but can still provide means to implement it.

Most commonly, error handling uses a try...\[catch...\]\[finally...\] block, and errors are created via a throw statement, but there is significant variation in naming and syntax.

Excluding minor syntactic differences, there are only a couple of exception handling styles in use.

In the most popular style, an exception is initiated by a special statement (throw or raise) with an exception object (e.g. with Java or Object Pascal) or a value of a special extendable enumerated type (e.g. with Ada or SML).

The scope for exception handlers
  starts with a marker clause (try or the language's block starter such as begin)
  ends in the start of the first handler clause (catch, except, rescue).

Several handler clauses can follow, and each can specify which exception types it handles and what name it uses for the exception object.

A few languages also permit a clause (else) that is used in case no exception occurred before the end of the handler's scope was reached.

Commonly a related clause (finally or ensure) that is executed whether an exception occurred or not, typically to release resources acquired within the body of the exception-handling block.

In its whole, exception handling code might look like this (in Java-like pseudocode):

try {
    line = console.readLine();

    if (line.length() == 0) {
        throw new EmptyLineException("The line read from console was empty!");
    }

    console.printLine("Hello %s!" % line);
    console.printLine("The program ran successfully.");
}
catch (EmptyLineException e) {
    console.printLine("Hello!");
}
catch (Exception e) {
    console.printLine("Error: " + e.message());
}
finally {
    console.printLine("The program is now terminating.");
}

As a minor variation, some languages use a single handler clause, which deals with the class of the exception internally.







Uncaught exceptions

If an exception is thrown and not caught (operationally, an exception is thrown when there is no applicable handler specified), the uncaught exception is handled by the runtime; the routine that does this is called the uncaught exception handler. The most common default behavior is to terminate the program and print an error message to the console, usually including debug information such as a string representation of the exception and the stack trace. This is often avoided by having a top-level (application-level) handler (for example in an event loop) that catches exceptions before they reach the runtime.

Note that even though an uncaught exception may result in the program terminating abnormally (the program may not be correct if an exception is not caught, notably by not rolling back partially completed transactions, or not releasing resources), the process terminates normally (assuming the runtime works correctly), as the runtime (which is controlling execution of the program) can ensure orderly shutdown of the process.
