https://en.wikipedia.org/wiki/Statement_(computer_science)

https://en.wikipedia.org/wiki/Expression_(computer_science)

Informally, a statement can be viewed as a command that we give to the application.

Formally, a statement is syntactic unit of an imperative language which expresses some action to be carried out.

Statements are the most prominent syntactic component in imperative languages, the dominant of class languages in use today. Their syntax has a critical effect on the overall regularity, readability and writability of the language. Some languages adopt a single basic statement format, whereas others use a different syntax for each different statement type. The former approach emphasizes regularity, whereas the latter emphasizes readability. A more important difference in statement structures is that between structured or nested statements and simple statements. A simple statement contains no other embedded statements. A structured statement may contain embedded statements.



Many languages make a distinction between statements and definitions
  a statement only contains executable code
  a definition instantiates an identifier,
  an expression evaluates to a value only.


A distinction can also be made between simple and compound statements; the latter may contain statements as components.

Many statements are introduced by keyword identifiers like if, while or repeat. Often statement keywords are reserved and cannot be used as names of variables or functions.

Each statement introduced via keyword typically uses a unique syntax, which looks quite different from function calls.













Statements are made up of internal components called expressions, and expressions are made up of even smaller parts

In computer science, an expression is a syntactic entity in a programming language that may be evaluated to determine its value. It is a combination of one or more constants, variables, functions, and operators that the programming language interprets and computes to produce another value.




Conceptually, there are two types of expressions: those that resolve to a value and those that assign a value to a variable.

  2 + 3

is both an arithmetic and programming expression of addition, which evaluates to 5.

  x

is a single variable as well as an expression because it must be evaluated to determine its value in memory.

  x + 6

is an expression that is made up of the single variable expression x and arithmetic addition, both of which produce results and are expressions.

  x = 2

is an expression made up of the single variable expressions x, and an assignment expression assigning 2 to the memory location referenced by x. An assignment statement sets the value stored in the storage location(s) denoted by a variable, in other words, it copies a value into the memory space referenced by a given variable name.

  y = 2 + 3

This example is an addition expression which evaluates to 5 and an assignment expression assigning 5 to the memory location referenced by y. The example above could be interpreted ambiguously without particular rules of precedence and association, much like those rules found in arithmetic. Each language has its own precedence and association rules defined by the languages semantics. Semantics describes the processes a computer follows when executing a program in that specific language.







Statement Types:
The appearance of statements shapes the look of programs. Programming languages are characterized by the type of statements they use (e.g. the curly brace language family). Many statements are introduced by identifiers like if, while or repeat. Often statement keywords are reserved such that they cannot be used as names of variables or functions.


The following are some of the major generic kinds of statements, pseudocoded.

Simple statements

    assertion: assert(ptr != NULL);
    assignment: A = A + 5
    goto: goto label;
    return: return value;
    call: function_name()

Compound statements

    block: { ... }
    do-loop: do { [computation] } while ([boolean expression]);
    for-loop: for A := 1 to 10 do WRITELN(A) end
    if-statement: if A > 3 then WRITELN(A) else WRITELN("NOT YET"); end
    switch-statement: switch (c) { case 'a': alert(); break; case 'q': quit(); break; }
    while-loop: while NOT EOF do begin READLN end
    with-statement: with open(filename) as f: use(f)











Compound Statements
Some statements are made up of more than one single line, often called
compound statements.

A compound statement is a statement that spans several lines. These compound
statements are made up of one or more normal one-line statements. They can also
consist of other compound statements.


Block
A block is a notation for a group of two or more statements, expressions or other units of code that are related in such a way as to comprise a whole.

Code Blocks
Having our code in one long sequence would make it difficult to read. It would be like having a book with no chapters or paragraphs. To add the concept of chapters and paragraphs to our code, we use something called code blocks.

It is common for a language to also allow us to define blocks of code. There are several reasons why you would want to do that, and we will talk more about them in later. However, for now, we can think of a block of code like a paragraph in standard text.

The language then defines how we mark the beginning and end of the block. A common technique that many languages employ is using parentheses, also called braces or curly brackets — {}. A language like this would open the code block with { and close the code block with }. Everything within is considered part of the block.

Other languages might have different ways to do the same thing, so again, when switching between languages, we must learn what the syntax rules are for that language.

Programming language statements typically have conventions for:
  statement separators
  statement terminators
  line continuation

A statement separator is used to demarcate boundaries between two separate statements. A statement terminator is used to demarcate the end of an individual statement. Languages that interpret the end of line to be the end of a statement are called "line-oriented" languages.

"Line continuation" is a convention in line-oriented languages where the newline character could potentially be misinterpreted as a statement terminator. In such languages, it allows a single statement to span more than just one line.



Separating statements
A programming language will separate statements by defining where a statement ends. If the language can figure out where one statement ends, it also knows that what comes after it must be the beginning of another statement.

If we compare how different languages terminate statements, we will see that we have three main ways for it to be done.

Many languages will terminate a statement by inserting a new line. This means that, in general, every line is a single statement if it is not a compound statement, as it will need to be handled uniquely.

Another popular way to terminate statements is by using a semicolon, ;. For languages that use this technique, we can have several statements on a single line. The language knows that a statement ends as soon as it sees a semicolon.

A third variant is to use a period, ., instead of a semicolon.

Apart from that, it works the same way as when a semicolon is used so that we can have more than one statement on a single line. A few languages will use other techniques, such as using a colon instead of a semicolon.


For compound statements, we will need a way to define where they begin and where they end. As a compound statement is made up of one or more statements, many languages will use another method to terminate them.

Here, we will find three main techniques that languages use.
One is to use curly brackets, {}, to indicate where a compound statement begins and ends.

  if(current_time > sunset_time){
    turn_on_light()
  }

Everything that is placed between the brackets is considered to be part of the compound statement.

Another way to do this is to use end statements.
if current_time > sunset_time
  turn_on_light()
end

Different languages will have slight variations on this.

The last variant is the language that will use indentation to accomplish the same thing

if current_time > sunset_time
  turn_on_light()























control flow (or flow of control) is the order in which individual statements of an imperative program are executed or evaluated.

The emphasis on explicit control flow distinguishes an imperative programming language from a declarative programming language.

Within an imperative programming language, a control flow statement is a statement, the execution of which results in a choice being made as to which of two or more paths to follow. For non-strict functional languages, functions and language constructs exist to achieve the same result, but they are usually not termed control flow statements.
A set of statements is in turn generally structured as a block, which in addition to grouping, also defines a lexical scope.


#### Control Structures
Control structures provide alternatives to sequential program execution and are used to alter the sequential flow of execution.

The most common control structures are selection, iteration, and jump statements:
  Selection statements cause the program to execute particular statements depending on some condition(s).
  Iteration statements cause the program to repeat particular statements based on some condition(s).
  Jump statements cause the program to transfer execution unconditionally











## Semantics
Semantically many statements differ from subroutine calls by their handling of parameters. Usually an actual subroutine parameter is evaluated once before the subroutine is called. This contrasts to many statement parameters that can be evaluated several times (e.g. the condition of a while loop) or not at all (e.g. the loop body of a while loop). Technically such statement parameters are call-by-name parameters. Call-by-name parameters are evaluated when needed (see also lazy evaluation). When call-by-name parameters are available a statement like behaviour can be implemented with subroutines (see Lisp). For languages without call-by-name parameters the semantic description of a loop or conditional is usually beyond the capabilities of the language.
