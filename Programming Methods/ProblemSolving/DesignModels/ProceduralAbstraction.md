## Procedural Abstraction
Generally, Procedural abstraction is achieved when we solve a large problem by breaking it down into a series of sub-problems, which can be solved more-or-less independently and then combined to arrive at a complete solution.

Procedural abstraction has been extensively employed since the early days of computing, and virtually all programming languages provide support for the concept. In programming, this methodology reflects itself in the use of sub-programs. For example Fortran SUBROUTINE, Pascal procedure, C/C++ functions, Java static methods, etc...

Formally, Procedural Abstraction is the principle that any operation that achieves a well-defined effect can be treated by its users as a single entity, despite the fact that the operation may actually be achieved by some sequence of lower-level operations (see also abstraction).

Procedural abstraction is all about generalizing doing some action. A procedure is called, performs the action, and is then finished.

Procedural abstraction is when we write code sections, "procedures", which are generalizations of some action using variable parameters.  The idea is that we have code which can cope with a variety of different situations, depending on how its parameters are set when it is called. Functions written in this manner can be regarded as "black boxes". As users of the function, we neither know nor care why they work.

Procedural abstraction makes a program shorter and easier to understand, and helps debugging, since when we correct a procedure, we correct the program for all the cases where the procedure is called.


### Design Models
A "bottom-up" approach to introducing procedural abstraction is to look at cases where we have code which is similar to other pieces, or pieces which follow a common pattern, and see if there is a way we can convert these to calls to one procedure.

A "top-down" approach is to think of the generalized operation we want to do, write code which uses calls to the procedure for this operation, and then write code for the procedure.

One of the main purposes of using functions is to aid in the top down design of programs.

During the design stage, as a problem is subdivided into tasks (and then into sub-tasks, sub-sub-tasks, etc.), the problem solver (programmer) should have to consider only what a function is to do and not be concerned about the details of the function. The function name and comments at the beginning of the function should be sufficient to inform the user as to what the function does. (Indeed, during the early stages of program development, experienced programmers often use simple "dummy" functions or stubs, which simply return an arbitrary value of the correct type, to test out the control flow of the main or higher level program component.)


The top-down approach leads to the idea of writing code to specifications. We say precisely what we want a procedure to do in terms of its arguments, and expect it to do just that, nothing more and nothing less. Then we need have no knowledge of what is inside the procedure to make successful use of it. When we write the procedure, we need have no knowledge of the code which is going to make use of the procedure. This helps us break programs down into small manageable parts, perhaps handled by different programmers. Then if we know the only way different pieces of a program can interact is through procedure calls which have a carefully defined effect, it is easier for us to debug and modify program with less chance that changing one part will have an unexpected effect on another part.
