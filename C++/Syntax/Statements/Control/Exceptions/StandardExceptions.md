Standard Exceptions

C++ provides a list of standard exceptions defined in <exception> which we can use in our programs.

C++ provides support to handle exceptions via a hierarchy of classes. The class
exception is the base of the classes designed to handle exceptions. Among others,
this class contains the function what. The function what returns a string containing an appropriate message. All derived classes of the class exception override the
function what to issue their own error messages.

stdlib Exception Classes
You can arrange classes into parent-child relationships using inheritance.
Inheritance has a big impact on how the code handles exceptions. There is
a nice, simple hierarchy of existing exception types available for use in the
stdlib. You should try to use these types for simple programs.

Standard Exception Classes
The stdlib provides you with the standard exception classes in the <stdexcept>
header. These should be your first port of call when you’re programming
exceptions. The superclass for all the standard exception classes is the
class std::exception. All the subclasses in std::exception can be partitioned
into three groups: logic errors, runtime errors, and language support
errors. While language support errors are not generally relevant to you as
a programmer, you’ll definitely encounter logic errors and runtime errors.

Two classes are immediately derived from the class exception: logic_error and
runtime_error. Both of these classes are defined in the header file stdexcept.


Logic Errors
Logic errors derive from the logic_error class. Generally, you could avoid these
exceptions through more careful programming. A primary example is when
a logical precondition of a class isn’t satisfied, such as when a class invariant cannot be established.

a class invariant is something that the programmer defines, neither the compiler nor the runtime environment can enforce it without help.
You can use a class constructor to check for various conditions, and if you
cannot establish a class invariant, you can throw an exception. If the failure
is the result of, say, passing an incorrect parameter to the constructor, a
logic_error is an appropriate exception to throw.

To deal with logical errors in a program, such as a string subscript out of range or an invalid argument to a function call, several classes are derived from the class logic_error. For example, the class invalid_argument is designed to deal with illegal arguments used in a function call. The class out_of_range deals with the
string subscript out of range error. If a length greater than the maximum allowed for
a string object is used, the class length_error deals with this error. For example,
recall that every string object has a maximum length (see Chapter 7). If a length larger
than the maximum length allowed for a string is used, then the length_error exception is generated. If the operator new cannot allocate memory space, this operator
throws a bad_alloc exception.


The logic_error has several subclasses that you should be aware of:
•	 The domain_error reports errors related to valid input range, especially
for math functions. The square root, for example, only supports nonnegative numbers (in the real case). If a negative argument is passed, a
square root function could throw a domain_error.
•	 The invalid_argument exception reports generally unexpected arguments.
•	 The length_error exception reports that some action would violate a
maximum size constraint.
•	 The out_of_range exception reports that some value isn’t in an expected
range. The canonical example is bounds-checked indexing into a data
structure.




Runtime Errors
Runtime errors derive from the runtime_error class. These exceptions help
you report error conditions that are outside the program’s scope.

The class runtime_error is designed to deal with errors that can be detected only
during program execution. For example, to deal with arithmetic overflow and underflow exceptions, the classes overflow_error and underflow_error are derived
from the class runtime_error.

runtime_error has some subclasses that you might find useful:
•	 The system_error reports that the operating system encountered some
error. You can get a lot of mileage out of this kind of exception. Inside
of the <system_error> header, there’s a large number of error codes and
error conditions. When a system_error is constructed, information about
the error is packed in so you can determine the nature of the error.
The .code() method returns an enum class of type std::errc that has
a large number of values, such as bad_file_descriptor, timed_out, and
permission_denied.
•	 The overflow_error and underflow_error report arithmetic overflow and
underflow, respectively.
Other errors inherit directly from exception. A common one is the
bad_alloc exception, which reports that new failed to allocate the required
memory for dynamic storage.
Language Support Errors
You won’t use language support errors directly. They exist to indicate that
some core language feature failed at runtime.
