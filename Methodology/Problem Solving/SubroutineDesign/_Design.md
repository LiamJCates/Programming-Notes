There are a number of useful concepts that we, as programmers, always should follow. One is to write code that is comprehensible, or easy to read and understand. Another is to avoid duplicating code.

Subroutines help fulfill both of these conceptual requirements.

When you start out your career as a programmer, you will find yourself copying and pasting code with small changes. This nullifies the comprehensibility concept as reading is tedious and tiny differences are hard to spot.

A better solution is to package code that we want to reuse several times into what is generally known as a subroutine. Subroutines give a name to a block of code and then, with this name, the code block can be executed whenever necessary.

Similarly to how software modules divide our code into small parts that is easier to read, update, and maintain. The same reason applies to subroutines as they, too, package our code into smaller units. Another reason we want to use subroutines is so we can easily reuse parts of our code.


A subroutine behaves in much the same way as a computer program that is used as one step in a larger program or another subprogram. A subroutine is often coded so that it can be started several times and from several places during one execution of the program, including from other subroutines, and then branch back (return) to the next instruction after the call, once the subroutine's task is done.




We want our code to be comprehensible, because that is the first step on the way to maintainability.

The first step to comprehensibility is to break computational tasks into meaningful chunks (represented as functions and classes) and name those. Such functions then provide the basic vocabulary of computation, just as the types (built-in and user-defined) provide the basic vocabulary of data.

Defining a function is the way you specify how an operation is to be done.

Next, we can compose functions representing common or specialized tasks into larger computations.

The number of errors in code correlates strongly with the amount of code and the complexity of the code. Both problems can be addressed by using more and shorter functions. Using a function to do a specific task often saves us from writing a specific piece of code in the middle of other code; making it a function forces us to name the activity and document its dependencies as well as provide it's interface.

Smaller and more functions allow for more opportunity to test.







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






functions provide a number of benefits that make them extremely useful in programs of non-trivial length or complexity.

  Organization -- As programs grow in complexity, having all the code live inside the main() function becomes increasingly complicated. A function is almost like a mini-program that we can write separately from the main program, without having to think about the rest of the program while we write it. This allows us to reduce a complicated program into smaller, more manageable chunks, which reduces the overall complexity of our program.

  Reusability -- Once a function is written, it can be called multiple times from within the program. This avoids duplicated code (“Don’t Repeat Yourself”) and minimizes the probability of copy/paste errors. Functions can also be shared with other programs, reducing the amount of code that has to be written from scratch (and retested) each time.
  Testing -- Because functions reduce code redundancy, there’s less code to test in the first place. Also because functions are self-contained, once we’ve tested a function to ensure it works, we don’t need to test it again unless we change it. This reduces the amount of code we have to test at one time, making it much easier to find bugs (or avoid them in the first place).

  Extensibility -- When we need to extend our program to handle a case it didn’t handle before, functions allow us to make the change in one place and have that change take effect every time the function is called.

  Abstraction -- In order to use a function, you only need to know its name, inputs, outputs, and where it lives. You don’t need to know how it works, or what other code it’s dependent upon to use it. This lowers the amount of knowledge required to use other people’s code (including everything in the standard library).


Effectively using functions

One of the biggest challenges new programmers encounter (besides learning the language) is understanding when and how to use functions effectively. Here are a few basic guidelines for writing functions:

  Statements that appear more than once in a program should generally be made into a function. For example, if we’re reading input from the user multiple times in the same way, that’s a great candidate for a function. If we output something in the same way multiple times, that’s also a great candidate for a function.
  Code that has a well-defined set of inputs and outputs is a good candidate for a function, particularly if it is complicated. For example, if we have a list of items that we want to sort, the code to do the sorting would make a great function, even if it’s only done once. The input is the unsorted list, and the output is the sorted list.
  A function should generally perform one (and only one) task.
  When a function becomes too long, too complicated, or hard to understand, it can be split into multiple sub-functions. This is called refactoring.
