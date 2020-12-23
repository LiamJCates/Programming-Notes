There are a number of useful concepts that we, as programmers, always should follow. One is to write code that is easy to read and understand. Another is to avoid duplicating code. When you start out your career as a programmer, you will find yourself copying and pasting code and just changing some small things here and there. This is a bad habit as it nullifies the first concept of code that is easy to read because reading more or less the same lines over and over is tedious and it is hard to spot the tiny differences. A better solution is to package code that we want to reuse several times into what is generally known as a subroutine. Subroutines give a name to a block of code and then, with this name, the code block can be executed whenever necessary.

Similarly to how software modules divide our code into small parts that is easier to read, update, and maintain. The same reason applies to subroutines as they, too, package our code into smaller units. Another reason we want to use subroutines is so we can easily reuse parts of our code.


A subroutine behaves in much the same way as a computer program that is used as one step in a larger program or another subprogram. A subroutine is often coded so that it can be started several times and from several places during one execution of the program, including from other subroutines, and then branch back (return) to the next instruction after the call, once the subroutine's task is done.




Subroutine Design

When deciding what will go into a subroutine, we can have some basic rules of thumb.

A subroutine should always do only one thing and it will be named after what reflects that. What this means is that if we have a subroutine named send_email_and_print_invoice, we are doing things wrong. This subroutine does two distinct tasks and should, therefore, be two separate subroutines. We can rephrase this rule with a quote by Robert C. Martin, the author of an excellent book on writing clean code:

  "A function should do something or answer something, but not both."

What this means is that a subroutine either should have a very well-specified task and only do that task and nothing else or it should answer a well-specified question and only answer that question and nothing else, and a single subroutine should absolutely not do both of these things.

Another quote from Robert C. Martin about subroutines is as follows:

"The first rule of functions is that they should be small."

This is an interesting quote because it raises some questions. What if I have a very well-defined problem that I would like to package within a subroutine so it follows the first quote, but the problem is rather complex and the resulting subroutine ends up being several hundred lines of code? Would that not contradict the second quote? Yes, it would and we will need to deal with it. We can take this long subroutine and find subtasks and move these subtasks into separate subroutines.










Functional Decomposition
Functional decomposition is a method of analysis that dissects a complex process in order to examine its individual elements. A function, in this context, is a task in a larger process whereby decomposition breaks down that process into smaller, easier to comprehend units.
