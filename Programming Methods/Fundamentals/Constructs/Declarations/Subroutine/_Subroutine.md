In general, a computer programming subroutine is a group of statements, given a name, which can be called from some point in the program to be executed to accomplish some task.

Formally, computer programming subroutine is a code block that can take inputs, execute instructions, and return a result. Functions allow a programmer to structure programs in segments of code to perform individual tasks.

In different programming languages, a subroutine may be called a routine, subprogram, function, method, or procedure. Technically, these terms all have different definitions. The generic, umbrella term "callable unit" is sometimes used.

Functions enable you to divide the content of your application into functional units that can be invoked in a sequence of your choosing.

In the following discussion we shall refer to the more general concept of subroutine using the word function.


### Implementing Functions

{return type} function_name([parameter list])
  //function body

The basic components of a function:
  Function Name
  Function Body
  Return Type {if required}
  Parameter List [optional]

#### Function Name
A function has a name that is used to reference its content elsewhere in our source code. The conventions used by a language for naming functions usually follow those of other identifiers:
[Programming Methods\Fundamentals\Constructs\Declarations\Identifiers.md]

Referencing a function in another portion of code is known as calling the function.

#### Function Body
The content of a function is its body, which is the statement that is executed when the function is called or invoked.

The function body can be a single statement or a code block

#### Parameter List
The parameter list identifies function input

The parameter list is a list of zero or more identifiers that are utilized by the function body.

While the syntax of parameter lists varies by language many follow a basic structure.

Parameter list:
  declaration follows the function name
  Are delimited by parentheses:
    opening with an open parentheses "("
    closing with a close parentheses ")"
  The identifiers listed follow that languages naming conventions
  Identifiers are comma delimited
  For languages that require it, an identifiers associated type proceeds the identifier name


#### Return Type
The return type identifies function output

For those languages that require a return type it is specified proceeding the function name.



### Execution
Functions are a method of managing a program's control flow

By convention, and required by many languages, a function is specified before it is called. Though the code for the function is above the rest of the function, it will not execute until we call the function.

Once a function has been declared we can call the function as often as we like, and all of the code within it will run each time.

Typically, the function name and function call operator () are used to reference the function throughout the source code

When a function is called, control flow is transferred from sequential execution of one code block to the top of the function.

The code block that referenced the function is known as the caller.
The function that is referenced is known as the callee.

Once the function has been executed, program execution will return to where the call occurred and continue from there.


Example:

say_hi()
  print "Hi there!"

print "Before the function"
say_hi()
print "After the function"

Output:
Before the function
Hi there!
After the function

Execution begins at the top of the example but a function body only executes when the function is called. The function declaration is remembered by the interpreter or compiler for use later. The above function is an example of a situation where the optional parameter list and return.

Therefore, the first noticeable output is the print statement "Before the function".
The function name is then used to call the function and output the print statement "Hi there".
Last to be executed is the print statement "After the function"




### Function Output
The idea behind a function is that it not only can be used to package code so we can reuse it over and over it can optionally return some sort of value.

In its simplest form, returning a value from a function works like this:

greet()
  return "Hello"

result = greet()
print result

Output:
Hello

Here, we have a function called greet. All it does is return a string containing the greeting, Hello. Remember that the code within a function is not executed until the function is actually called. The call happens below the function.

Consider:
result = greet()

The thing to the right of the assignment operator (=) is executed first. This is the call to the function. Control flow jumps to the function, executing the code within it. The only thing inside the function is this:

  return "Hello my friend"


We must understand two things about this line.
A line with the return keyword will exit the function, even if there is more code following it.
Secondly, it will return whatever follows the word return back to the location that called the function.

This will take us back to this line:
result = greet()

We are now done with the operation on the right of =, which returned a string, Hello.

That string is now assigned to the result variable.
On the last line, the content of that variable is printed.



### Function Input
Often, we want our functions to be somewhat flexible, so they don't do exactly the same thing every time we call them.

Consider the following two functions:
add_2_and_3()
  return 2 + 3

add_5_and 9()
  return 5 + 9

These two functions add two numbers and return the result. The first one adds 2 and 3, and the second one does the same but with 5 and 9. Now, these are just two pairs of numbers. If we would like to have a function that could add any numbers, we would need to create an endless number of functions.

But if we look at what the functions do, we can see that they are actually doing the same thing. They add two numbers and return the result. The only thing that changes are the numbers that are used in the addition operation.
What we want is to be able to pass the numbers we want to be added to the function so it can use them in the calculation, and by that, only have one function that can add any two numbers.

We can pass data to functions that specify parameters. We say that the function can accept arguments. For a function that can add two numbers, this can look like this:

add(number1, number2)
  return number1 + number2

Here, we can see that we now have made use of the parenthesis that has followed the function name. This is where we can specify variables that will receive the data we want to pass to the function. Now we can use this function like this:

result = add(73, 8)
print(result)
result = add(2, 3)
print result
result = add(5, 9)
print result

Output:
81
5
14


When we make the first call to the function, we are passing in the values, 73 and 8. These are called arguments.

On the receiving side, that is, in the add function, these two values will be assigned to two variables, number1 and number2. These are called the parameters of the function.

The first argument that we pass in, the value, 73, is assigned to the first parameter, number1, and the second argument, the value, 8, will be assigned to the parameter called number2.


## Advanced Subroutine Topics



A subroutine may be written so that it expects to obtain one or more data values upon being called. The calling program provides actual values for these parameters, known as arguments.

Different programming languages may use different conventions for passing arguments:


Call by value: Arguments are evaluated and copy of the value is passed to subroutine
Call by reference: Reference to an argument, typically its address is passed 	Call by result: Parameter value is copied back to argument on return from the subroutine
Call by value-result: Parameter value is copied back on entry to the subroutine and again on return
Call by name: Replaces the parameters with the unevaluated argument expressions
Call by constant value: Like call by value except that the parameter is treated as a constant

The subroutine may return a computed value to its caller (its return value), or provide various result values or output parameters. Indeed, a common use of subroutines is to implement mathematical functions, in which the purpose of the subroutine is purely to compute one or more results whose values are entirely determined by the arguments passed to the subroutine. (Examples might include computing the logarithm of a number or the determinant of a matrix.) This type is called a function.

A subroutine call may also have side effects such as modifying data structures in a computer memory, reading from or writing to a peripheral device, creating a file, halting the program or the machine, or even delaying the program's execution for a specified time. A subprogram with side effects may return different results each time it is called, even if it is called with the same arguments. An example is a random number subroutine, available in many languages, that returns a different pseudo-random number each time it is called. The widespread use of subroutines with side effects is a characteristic of imperative programming languages.

A subroutine can be coded so that it may call itself recursively, at one or more places, to perform its task. This method allows direct implementation of functions defined by mathematical induction and recursive divide and conquer algorithms.

A subroutine whose purpose is to compute one boolean-valued function (that is, to answer a yes/no question) is sometimes called a predicate. In logic programming languages, often[vague] all subroutines are called predicates, since they primarily[vague] determine success or failure.[citation needed]

A subroutine that returns no value or returns a null value is sometimes called a procedure. Procedures usually modify their arguments and are a core part of procedural programming.




Advantages

The advantages of breaking a program into subroutines include:

  Decomposing a complex programming task into simpler steps: this is one of the two main tools of structured programming, along with data structures
  Reducing duplicate code within a program
  Enabling reuse of code across multiple programs
  Dividing a large programming task among various programmers or various stages of a project
  Hiding implementation details from users of the subroutine
  Improving readability of code by replacing a block of code with a function call where a descriptive function name serves to describe the block of code. This makes the calling code concise and readable even if the function is not meant to be reused.
  Improving traceability (i.e. most languages offer ways to obtain the call trace which includes the names of the involved subroutines and perhaps even more information such as file names and line numbers); by not decomposing the code into subroutines, debugging would be severely impaired

Disadvantages

Compared to using in-line code, invoking a subroutine imposes some computational overhead in the call mechanism.

A subroutine typically requires standard housekeeping code – both at the entry to, and exit from, the function (function prologue and epilogue – usually saving general purpose registers and return address as a minimum).












Conventions

A wide number of conventions for the coding of subroutines have been developed. Pertaining to their naming, many developers have adopted the approach that the name of a subroutine should be a verb when it does a certain task, and adjective when it makes some inquiry, and a noun when it is used to substitute variables.

Some programmers suggest that a subroutine should perform only one task, and if a subroutine does perform more than one task, it should be split up into more subroutines. They argue that subroutines are key components in code maintenance, and their roles in the program must remain distinct.

Proponents of modular programming (modularizing code) advocate that each subroutine should have minimal dependency on other pieces of code. For example, the use of global variables is generally deemed unwise by advocates for this perspective, because it adds tight coupling between the subroutine and these global variables. If such coupling is not necessary, their advice is to refactor subroutines to accept passed parameters instead. However, increasing the number of parameters passed to subroutines can affect code readability.



Optimization of subroutine calls

There is a significant runtime overhead in a calling a subroutine, including passing the arguments, branching to the subprogram, and branching back to the caller. The overhead often includes saving and restoring certain processor registers, allocating and reclaiming call frame storage, etc.. In some languages, each subroutine call also implies automatic testing of the subroutine's return code or the handling of exceptions that it may raise. In object-oriented languages, a significant source of overhead is the intensively used dynamic dispatch for method calls.

There are some seemingly obvious optimizations of procedure calls that cannot be applied if the procedures may have side effects. For example, in the expression (f(x)-1)/(f(x)+1), the function f must be called twice, because the two calls may return different results. Moreover, the value of x must be fetched again before the second call, since the first call may have changed it. Determining whether a subprogram may have a side effect is very difficult (indeed, undecidable by virtue of Rice's theorem). So, while those optimizations are safe in purely functional programming languages, compilers of typical imperative programming usually have to assume the worst.
Inlining
A method used to eliminate this overhead is inline expansion or inlining of the subprogram's body at each call site (versus branching to the subroutine and back). Not only does this avoid the call overhead, but it also allows the compiler to optimize the procedure's body more effectively by taking into account the context and arguments at that call. The inserted body can be optimized by the compiler. Inlining, however, will usually increase the code size, unless the program contains only one call to the subroutine.
