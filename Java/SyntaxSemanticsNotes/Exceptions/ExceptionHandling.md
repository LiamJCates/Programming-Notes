Exception Handling

Exceptions represent the occurrence of a runtime error.
Exception handling enables a program to deal with runtime errors and continue its normal execution.
Runtime errors occur while a program is running if the JVM detects an operation that is impossible to carry out.

For example, if you access an array using an index that is out of bounds, you will get a runtime error with an ArrayIndexOutOfBoundsException. If you enter a double value when your program expects an integer, you will get a runtime error with an InputMismatchException.

In Java, runtime errors are thrown as exceptions. An exception is an object that represents an error or a condition that prevents execution from proceeding normally. If the exception is not handled, the program will terminate abnormally.

Exception handling allows us to effect control flow when an error occurs.
When a program carries out an illegal action, an exception is generated.
When an exception occurs and there is no handler for it, the program terminates.

Exception handling streamlines error handling by allowing your program to define a block of code, called an exception handler, that is executed automatically when an error occurs. It is not necessary to manually check the success or failure of each specific operation or method call. If an error occurs, it will be processed by the exception handler.

Unless your program handles exceptions, it will terminate after displaying a stack trace (the sequence of pending method calls)


Exceptions are thrown
Exceptions are thrown from a method. The caller of the method can catch and handle the exception.  If the exception is not handled, the program will terminate abnormally. This is clearly a problem. You should not let the method terminate the program—the caller should decide whether to terminate the program. How can a method notify its caller an exception has occurred? Java enables a method to throw an exception that can be caught and handled by the caller.

A program that detects an error can create an instance of an appropriate exception type and throw it. This is known as throwing an exception.

The execution of a throw statement is called throwing an exception. The exception is an object created from an exception class. For example, if the exception class is java.lang.ArithmeticException, the constructor ArithmeticException(str) is invoked to construct an exception object, where str is a message that describes the exception. When an exception is thrown, the normal execution flow is interrupted. As the name suggests, to “throw an exception” is to pass the exception from one place to another.

Here is an example: Suppose the program
detects that an argument passed to the method violates the method contract (e.g., the argument
must be nonnegative, but a negative argument is passed); the program can create an instance
of IllegalArgumentException and throw it, as follows:
IllegalArgumentException ex =
 new IllegalArgumentException("Wrong Argument");
throw ex;
Or, if you prefer, you can use the following:
throw new IllegalArgumentException("Wrong Argument")


IllegalArgumentException is an exception class in the Java API. In general, each exception class in the Java API has at least two constructors: a no-arg constructor  and a constructor with a String argument that describes the exception. This argument is called the exception message, which can be obtained by invoking getMessage() from an exception object.


The Consequences of an Uncaught
Exception Catching exceptions has a side benefit: It prevents abnormal program termination. When an exception is thrown, it must be caught by some piece of code, somewhere. In general, if your program does not catch an exception, then it will be caught by the JVM. The trouble is that the JVM’s default exception handler terminates execution and displays a stack trace and error message.

Exceptions Enable You to Handle Errors Gracefully
One of the key benefits of exception handling is that it enables your program to respond to an error and then continue running.
Catching Exceptions
If you do not want the program to terminate you must catch the exception.

When an exception is thrown, the normal execution flow is interrupted. As the name suggests, to “throw an exception” is to pass the exception from one place to another.

To catch an exception Java implements the try-catch block

A template for a try-throw-catch block may look as follows:
try {
 statements; // Statements that may throw exceptions
}
catch (Exception1 exVar1) {
 handler for exception1;
}
catch (Exception2 exVar2) {
 handler for exception2;
}
...
catch (ExceptionN exVarN) {
 handler for exceptionN;
}

The try block contains the code that is executed in normal circumstances.
The exception is caught by the catch block.
The code in the catch block is executed to handle the exception.

If no exceptions arise during the execution of the try block, the catch blocks are skipped. If one of the statements inside the try block throws an exception, Java skips the remaining statements in the try block and starts the process of finding the code to handle the exception. The code that handles the exception is called the exception handler; it is found by propagating the exception backward through a chain of method calls, starting from the current method. Each catch block is examined in turn, from first to last, to see whether the type of the exception object is an instance of the exception class in the catch block. If so, the exception object is assigned to the variable declared and the code in the catch block is executed. If no handler is found, Java exits this method, passes the exception to the method’s caller, and continues the same process to find a handler. If no handler is found in the chain of methods being invoked, the program terminates and prints an error message on the console. The process of finding a handler is called catching an exception.

The throw statement is analogous to a method call, but instead of calling a method, it calls a catch block. In this sense, a catch block is like a method definition with a parameter that matches the type of the value being thrown. Unlike a method, however, after the catch block
is executed, the program control does not return to the throw statement; instead, it executes
the next statement after the catch block.

The identifier ex in the catch–block header catch (ArithmeticException ex) acts very much like a parameter in a method. Thus, this parameter is referred to as a catch–block parameter. The type (e.g., ArithmeticException) preceding ex specifies what kind of exception the catch block can catch. Once the exception is caught, you can access the thrown value from this parameter in the body of a catch block.

An exception may be thrown directly by using a throw statement in a try block, or by
invoking a method that may throw an exception.


Use
Now you can see the advantage of using exception handling: It enables a method to throw an exception to its caller, enabling the caller to handle the exception. Without this capability, the called method itself must handle the exception or terminate the program. Often the called method does not know what to do in case of error. This is typically the case for the library methods. The library method can detect the error, but only the caller knows what needs to be done when an error occurs. The key benefit of exception handling is separating the detection of an error (done in a called method) from the handling of an error (done in the calling method).

In most programs, the lower-level methods simply propagate exceptions to their callers.

A handler for an exception is found by propagating the exception backward through a chain of method calls, starting from the current method.

Some higher-level method, such as main or a part of the user interface, catches exceptions and informs the user.

For debugging purposes, you sometimes want to see the stack trace. Call the printStackTrace
method like this:
try
{
}
catch (Exception e)
{
e.printStackTrace() ;
//take corrective action
}

The stack trace lists all the methods in the call stack, which provides valuable information for debugging runtime errors. The getStackTrace() method provides programmatic access to the stack trace information printed by printStackTrace().

The catch block allows us to specify the type of error that it should catch. In our example, we are trying to catch a general error. Therefore, we write:    

catch (Exception e)

where Exception refers to the class that the error belongs to and e is now the name given to the error. Exception is a pre-written class in Java. It handles all general errors and has a method called getMessage() that explains the reason for the exception. To display the error message, we write System.out.println(e.getMessage());

Does the presence of a try-catch block impose overhead when no exception occurs?
No. The reason is the presence of a try-catch block imposes overhead only when an exception occurs. If no exception occurs, the catch blocks are skipped.
Catching Subclass Exceptions
A catch clause for a superclass will also match any of its subclasses. For example, since the superclass of all exceptions is Throwable, to catch all possible exceptions, catch Throwable. If you want to catch exceptions of both a superclass type and a subclass type, put the subclass first in the catch sequence. If you don’t, then the superclass catch will also catch all derived classes. This rule is self-enforcing because putting the superclass first causes unreachable code to be created, since the subclass catch clause can never execute. In Java, unreachable code is an error.

Q: Why would I want to catch superclass exceptions? A: There are, of course, a variety of reasons. Here are a couple. First, if you add a catch clause that catches exceptions of type Exception, then you have effectively added a “catch all” clause to your exception handler that deals with all program-related exceptions. Such a “catch all” clause might be useful in a situation in which abnormal program termination must be avoided no matter what occurs. Second, in some situations, an entire category of exceptions can be handled by the same clause. Catching the superclass of these exceptions allows you to handle all without duplicated code.



The Exception Hierarchy

[import Exception Hierarchy png]

Exceptions are objects, and objects are defined using classes. The root class for exceptions is java.lang.Throwable.

In Java, all exceptions are represented by classes.
 All exception classes are derived from a class called Throwable.

Thus, when an exception occurs in a program, an object of some type of exception class is generated. There are two direct subclasses of Throwable: Exception and Error.

Exceptions of type Error are related to errors that occur in the Java Virtual Machine itself, and not in your program. System errors are thrown by the JVM and are represented in the Error class. The Error class describes internal system errors, though such errors rarely occur. If one does, there is little you can do beyond notifying the user and trying to terminate the program gracefully.

Errors that result from program activity are represented by subclasses of Exception. For example, divide-by-zero, array boundary, and file errors fall into this category. In general, your program should handle exceptions of these types. An important subclass of Exception is RuntimeException, which is used to represent various common types of run-time errors.

Runtime exceptions are represented in the RuntimeException class, which describes programming errors, such as bad casting, accessing an out-of-bounds array, and numeric errors. Runtime exceptions normally indicate programming errors.

Any class that can be thrown extends from Throwable. Throwable has two direct subclasses: Error and Exception. As a rule, it is usually the responsibility of the programmer to address and fix Exceptions where necessary. Errors are not something you can recover from, such as an OutOfMemoryError or a NoClassDefFoundError. Exceptions themselves are split into two definitions: An exception is either a runtime exception or a checked exception. A runtime exception is any subclass of RuntimeException. A checked exception is any other exception. When using a method (or constructor) that may throw a checked exception, that exception must be explicitly defined on the method definition. Any caller to the code must be prepared to handle that exception, by either throwing it back to any caller of that method, or surrounding the method call in a try/catch/finally block, and deal with the exceptional case appropriately.
Are runtime exceptions or checked exceptions better?
Another area of great debate is whether checked or runtime exceptions are better. Arguments certainly exist for both sides.
With checked exceptions, you are being explicit to any user of your code about what could possibly go
wrong. When writing a method that may throw a checked exception, be as explicit as possible. A method
definition such as public String getHostName() throws Exception does not give much clue to what
may go wrong. If it were defined as public String getHostName() throws UnknownHostException,
the client code would know what may go wrong, and it also would give some more insight as to how
exactly the method works.
With runtime exceptions, defining the exception on the method, rethrowing the exception, or using
a try/catch/finally block are all optional. As a general rule, RuntimeExceptions are exceptions
that a diligent programmer should already have mitigated: problems such as accessing an array
index value larger than the size of the array—ArrayIndexOutOfBoundsException—or trying to
call methods on a null reference—NullPointerException.
When defining an API and deciding whether to use runtime or checked exceptions, this author’s
opinion is to favor runtime exceptions and be explicit in any documentation as to what exactly may
be thrown to any clients calling that method. Using try/catch/finally blocks adds a significant
amount of boilerplate code to even the simplest of method calls, and makes life very difficult for
any future maintainer of the code. Just examine any non-trivial use of JDBC, and you will often
see try/finally blocks inside try/catch/finally blocks. Modern languages such as Scala have
stepped away from checked exceptions, and have only runtime exceptions.

Exception Handling Fundamentals
Java exception handling is managed via five keywords: try, catch, throw, throws, and finally. They form an interrelated subsystem in which the use of one implies the use of another.

Program statements that you want to monitor for exceptions are contained within a try block. If an exception occurs within the try block, it is thrown. Your code can catch this exception using catch and handle it in some rational manner. System-generated exceptions are automatically thrown by the Java run-time system. To manually throw an exception, use the keyword throw.

In some cases, an exception that is thrown out of a method must be specified as such by a throws clause.

Any code that absolutely must be executed upon exiting from a try block is put in a finally block.

Java has a number of built-in exception cases.
You can also throw your own exceptions if you find that a programmer makes an error when using one of your classes.

There are two categories of exceptions: checked and unchecked.

In general, a checked exception is caused by an external condition beyond the programmer's control.
If you call a method that might throw a checked exception, you must either declare it or catch it.
Exceptions that occur during input and output are checked because the file system or network may spontaneously cause problems that the programmer cannot control. Therefore, the compiler insists that the programmer provide code to handle these situations.

On the other hand, unchecked exceptions are generally the programmer's fault. You should never get a NullPointerException. Therefore, the compiler doesn't tell you to provide a handler for a NullPointerException. Instead, you should spend your energy on making sure that the error doesn't occur in the first place. Either initialize your variables properly, or test that they aren't null before making a method call.

RuntimeException, Error, and their subclasses are known as unchecked exceptions. All other exceptions are known as checked exceptions, meaning the compiler forces the programmer to check and deal with them in a try-catch block or declare it in the method header.

Unchecked exceptions can occur anywhere in a program. To avoid cumbersome overuse of try-catch blocks, Java does not mandate that you write code to catch or declare unchecked exceptions.

Q: Just to be sure, could you review the conditions that cause an exception to be generated?
A: Exceptions are generated in three different ways. First, the Java Virtual Machine can generate an exception in response to some internal error which is beyond your control. Normally, your program won’t handle these types of exceptions. Second, standard exceptions, such as those corresponding to divide-byzero or array index out-of-bounds, are generated by errors in program code. You need to handle these exceptions. Third, you can manually generate an exception by using the throw statement. No matter how an exception is generated, it is handled in the same way.

When you write code that might cause a checked exception, take one of two actions:
1. Declare the exception in the method header.
2. Handle (or catch) the exception.

 Every method must state the types of
checked exceptions it might throw. This is known as declaring exceptions. Because system
errors and runtime errors can happen to any code, Java does not require that you declare Error
and RuntimeException (unchecked exceptions) explicitly in the method. However, all other
exceptions thrown by the method must be explicitly declared in the method header so the caller
of the method is informed of the exception.
To declare an exception in a method, use the throws keyword in the method header, as in
this example:
public void myMethod() throws IOException
The throws keyword indicates myMethod might throw an IOException. If the method
might throw multiple exceptions, add a list of the exceptions, separated by commas, after
throws:
public void myMethod()
 throws Exception1, Exception2, ..., ExceptionN
Note
If a method does not declare exceptions in the superclass, you cannot override it to
declare exceptions in the subclass.

If there is no file with the given name, the FileReader constructor throws a FileNotFoundException. Because it is a checked exception, the compiler insists that you handle it. However, the implementor of the read method probably has no idea how to correct this situation. Therefore, the optimal remedy is to let the exception propagate to its caller. That means that the read method terminates, and that the exception is thrown to the method that called it.

Whenever a method propagates a checked exception, you must declare the exception in the method header, like this:
public void read (String filename) throws FileNotFoundException
{
FileReader reader = new FileReader(filename) ;
}

If a method can throw multiple exceptions, you list them all, separated by commas.

reading objects from an object stream can cause both
IOException (if there is a problem with reading the input)
ClassNotFoundException (if the input contains an object from an unknown class).
A read method can declare that it throws both exceptions:
public void read(String filename) throws IOException , ClassNotFoundException { . . . }

In some cases, if a method generates an exception that it does not handle, it must declare that exception in a throws clause. Here is the general form of a method that includes a throws clause:

ret-type methName(param-list) throws except-list {
// body
}

When you tag a method with a throws clause, the callers of this method are now put on notice that there is the possibility that a checked exception may occur.
Of course, those calling methods also need to deal with these exceptions. Generally, the calling methods also add throws declarations. When you carry this process out for the entire program, the main method ends up being tagged as well:  
public static void main(String[] args) throws IOException , ClassNotFoundException { . . . }

If an exception actually occurs, the main method is terminated, a stack trace is displayed, and the program exits.

Here, except-list is a comma-separated list of exceptions that the method might throw outside of itself. You might be wondering why you did not need to specify a throws clause for some of the preceding examples, which threw exceptions outside of methods. The answer is that exceptions that are subclasses of Error or RuntimeException don’t need to be specified in a throws list. Java simply assumes that a method may throw one. All other types of exceptions do need to be declared. Failure to do so causes a compile-time error.



Finally
Occasionally, a method must carry out an action even if a prior statement caused an exception. A typical example is closing a file. A program can only open a limited number of files at one time, and it should close all files that it opened. To ensure that a file is closed even if an exception occurred during file processing, use the finally clause.
You can have more than one catch block. In addition, the finally block is optional.

se the following syntax:
try
{
//code that might throw an IOExcepti on
}
catch (IOException exception)
{
//take corrective action
}
finally
{
//do this regardless of whether the try or catch condition is met.
}

The finally block will be executed whenever execution leaves a try/catch block, no matter what conditions cause it. That is, whether the try block ends normally, or because of an exception, the last code executed is that defined by finally. The finally block is also executed if any code within the try block or any of its catch statements return from the method.


Try Blocks Can Be Nested
One try block can be nested within another. An exception generated within the inner try block that is not caught by a catch associated with that try is propagated to the outer try block.

Specific Errors
In the example above, we used the Exception class to catch a general error. In addition to the Exception class, Java has other classes that can handle more specific errors. This is useful if you want to perform specific tasks depending on the error caught.

They are found here: https://docs.oracle.com/javase/7/docs/api/java/lang/Exception.html

Rethrowing an Exception
An exception caught by one catch statement can be rethrown so that it can be caught by an outer catch. The most likely reason for rethrowing this way is to allow multiple handlers access to the exception. For example, perhaps one exception handler manages one aspect of an exception, and a second handler copes with another aspect. Remember, when you rethrow an exception, it will not be recaught by the same catch statement. It will propagate to the next catch statement.

Throwing Exceptions
In addition to catching errors under pre-defined conditions, we can also define our own conditions for when an error should occur. This is known as throwing an exception.

throw new [specificException]();


Throwable Methods
Since all exceptions are subclasses of Throwable, all exceptions support the methods defined by Throwable.

Exception.fillInStackTrace()    
//returns a throwable object that contains a complete stack trace, can be rethrown
Exception.getLocalizedMessage()
//returns a localized description of the exception
Exception.getMessage()
//returns a description of the exception
Exception.printStackTrace()
//Displays stack trace
Exception.printStackTrace(PrintStream s)
//sends the stack trace to the specified stream
Exception.printStackTrace(PrintWriter w)
//sends the stack trace to the specified stream
Exception.toString()
//returns a String object containing a complete description of the exception. This method is called by println() when outputting a throwable object.

Of the methods defined by Throwable, two of the most interesting are printStackTrace( ) and toString( ). You can display the standard error message plus a record of the method calls that lead up to the exception by calling printStackTrace( ). You can use toString( ) to retrieve the standard error message. The toString( ) method is also called when an exception is used as an argument to println( ).
Three Additional Exception

Features Beginning with JDK 7, Java's exception handling mechanism was expanded with the addition of three features. The first supports automatic resource management, which automates the process of releasing a resource, such as a file, when it is no longer needed. It is based on an expanded form of try, called the try-with-resources statement, and it is described in Chapter 10, when files are discussed. The second new feature is called multi-catch, and the third is sometimes called final rethrow or more precise rethrow. These two features are described here. Multi-catch allows two or more exceptions to be caught by the same catch clause. As you learned earlier, it is possible (indeed, common) for a try to be followed by two or more catch clauses. Although each catch clause often supplies its own unique code sequence, it is not uncommon to have situations in which two or more catch clauses execute the same code sequence even though they catch different exceptions. Instead of having to catch each exception type individually, you can use a single catch clause to handle the exceptions without code duplication. To create a multi-catch, specify a list of exceptions within a single catch clause. You do this by separating each exception type in the list with the OR operator. Each multi-catch parameter is implicitly final. (You can explicitly specify final, if desired, but it is not necessary.) Because each multi-catch parameter is implicitly final, it can't be assigned a new value. Here is how you can use the multi-catch feature to catch both ArithmeticException and ArrayIndexOutOfBoundsException with a single catch clause:

catch(ArithmeticException | ArrayIndexOutofBoundException){
}

The more precise rethrow feature restricts the type of exceptions that can be rethrown to only those checked exceptions that the associated try block throws, that are not handled by a preceding catch clause, and that are a subtype or supertype of the parameter. While this capability might not be needed often, it is now available for use. For the final rethrow feature to be in force, the catch parameter must be effectively final. This means that it must not be assigned a new value inside the catch block. It can also be explicitly specified as final, but this is not necessary.


Java’s Built-in Exceptions

Inside the standard package java.lang, Java defines several exception classes. The most general of these exceptions are subclasses of the standard type RuntimeException. Since java.lang is implicitly imported into all Java programs, many exceptions derived from RuntimeException are automatically available. Furthermore, they need not be included in any method’s throws list. In the language of Java, these are called unchecked exceptions because the compiler does not check to see if a method handles or throws these exceptions.

[Built-in Exceptions png]

The next table lists those exceptions defined by java.lang that must be included in a method’s throws list if that method can generate one of these exceptions and does not handle it itself. These are called checked exceptions. In addition to the exceptions in java.lang, Java defines several other types of exceptions that relate to other packages, such as IOException

[CheckedExceptions.png]

Q: I have heard that Java supports something called chained exceptions. What are they? A: Chained exceptions were added to Java by JDK 1.4. The chained exception feature allows you to specify one exception as the underlying cause of another. For example, imagine a situation in which a method throws an ArithmeticException because of an attempt to divide by zero. However, the actual cause of the problem was that an I/O error occurred, which caused the divisor to be set improperly. Although the method must certainly throw an ArithmeticException, since that is the error that occurred, you might also want to let the calling code know that the underlying cause was an I/O error. Chained exceptions let you handle this, and any other situation, in which layers of exceptions exist. To allow chained exceptions, two constructors and two methods were added to Throwable. The constructors are shown here: Throwable(Throwable causeExc) Throwable(String msg, Throwable causeExc) In the first form, causeExc is the exception that causes the current exception. That is, causeExc is the underlying reason that an exception occurred. The second form allows you to specify a description at the same time that you specify a cause exception. These two constructors have also been added to the Error, Exception, and RuntimeException classes. The chained exception methods added to Throwable are getCause( ) and initCause( ). These methods are shown here: Throwable getCause( ) Throwable initCause(Throwable causeExc) The getCause( ) method returns the exception that underlies the current exception. If there is no underlying exception, null is returned. The initCause( ) method associates causeExc with the invoking exception and returns a reference to the exception. Thus, you can associate a cause with an exception after the exception has been created. In general, initCause( ) is used to set a cause for legacy exception classes that don’t support the two additional constructors described earlier. Chained exceptions are not something that every program will need. However, in cases in which knowledge of an underlying cause is useful, they offer an elegant solution.
What is exception chaining?
When catching an exception to deal with an error case, it is entirely possible you would want to
rethrow that exception, or even throw an exception of a different type.
Reasons to do this include “laundering” an exception from a checked exception to a runtime one, or
perhaps performing some logging of the exception and then rethrowing it. When throwing a previously caught exception, it is advisable to throw a new exception and add a reference on that new
exception. This technique is called exception chaining.
This mindset is the same for throwing a new exception within a catch block. Add a reference to the
old exception in the new exception’s constructor.
The reason for doing this is that these exception chains are extremely valuable for debugging
should the exception not be handled at all, and the stack trace make it all the way to the application
console.

The chains are referenced in the stack trace by a “caused by” line. This refers to the original exception prior to being wrapped in a new exception or rethrown.
Listing 8-28 shows how to create a chained exception. The exception instance in the catch block is
chained to the new IllegalStateException instance, by passing that reference to the constructor
of the IllegalStateException.
Listing 8-28: Handling chained exceptions
public class Exceptions {
 private int addNumbers(int first, int second) {
 if(first > 42) {
 throw new IllegalArgumentException("First parameter must be small");
 }
 return first + second;
 }
 @Test
 public void exceptionChaining() {
 int total = 0;
 try {
 total = addNumbers(100, 25);
 System.out.println("total = " + total);
 } catch (IllegalArgumentException e) {
 throw new IllegalStateException("Unable to add numbers together", e);
 }
 }
}
All standard Java library exceptions can take a throwable as a constructor parameter, and should
you ever create any new Exception classes, make sure you adhere to this.
When this (admittedly contrived) test is run, it demonstrates that the IllegalStateException was
indeed caused by the first parameter to addNumbers being too high:
java.lang.IllegalStateException: Unable to add numbers together
 at com.wiley.acinginterview.chapter08.Exceptions.exceptionChaining(Exceptions.java:23)
 at sun.reflect.NativeMethodAccessorImpl.invoke0(Native Method)
...
<Exeption truncated>
...
 at sun.reflect.NativeMethodAccessorImpl.invoke(NativeMethodAccessorImpl.java:39)
 at com.intellij.rt.execution.application.AppMain.main(AppMain.java:120)
Caused by: java.lang.IllegalArgumentException: First parameter must be small
 at com.wiley.acinginterview.chapter08.Exceptions.addNumbers(Exceptions.java:9)
 at com.wiley.acinginterview.chapter08.Exceptions.exceptionChaining(Exceptions.java:20)
 ... 26 more

Had the exceptions not been chained, and the code inside the try block much larger, trying to work
out where the original exception had been thrown from could have been a time-wasting chore.
If you ever see an exception being thrown in a catch block, and it does not chain the original exception, add a reference there and to that original exception. You’ll thank yourself later!
Creating Exception Subclasses

Through the use of custom exceptions, you can manage errors that relate specifically to your application.

Just define a subclass of Exception (which is, of course, a subclass of Throwable). Your subclasses don’t need to actually implement anything—it is their existence in the type system that allows you to use them as exceptions. The Exception class does not define any methods of its own. It does, of course, inherit those methods provided by Throwable. Thus, all exceptions, including those that you create, have the methods defined by Throwable available to them. Of course, you can override one or more of these methods in exception subclasses that you create.

class custExceptionName extends Exception {
}

Q: When should I use exception handling in a program? When should I create my own custom exception classes? A: Since the Java API makes extensive use of exceptions to report errors, nearly all real-world programs will make use of exception handling. This is the part of exception handling that most new Java programmers find easy. It is harder to decide when and how to use your own custom-made exceptions. In general, errors can be reported in two ways: return values and exceptions. When is one approach better than the other? Simply put, in Java, exception handling should be the norm. Certainly, returning an error code is a valid alternative in some cases, but exceptions provide a more powerful, structured way to handle errors. They are the way professional Java programmers handle errors in their code.
