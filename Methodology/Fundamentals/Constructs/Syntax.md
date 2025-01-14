## Syntax
https://en.wikipedia.org/wiki/Syntax_(programming_languages)
Just as human languages have grammar to dictate the rules of the language, a programming language has syntax.

In natural language, sentences are constructed according to specific grammatical rules. The rules that govern how sentences are constructed in a language is called syntax.

In computer science, the syntax of a computer language is defined to be the set of rules that defines the combinations of symbols that are considered to be correctly structured.



### Tokens
The smallest individual unit of a program written in any language is called a token. Larger programmatic units are comprised of combinations of symbols called tokens.

Common Token Elements
  Character Set
  Identifiers
  Operators
  Keywords and Reserved Words
  Comments
  Whitespace
  Delimiters




Free and Fixed-field Formats
A syntax is free filed if program statements may be written anywhere on an input line without regard for positioning on the line or for breaks between lines.

A holdover from the early punched card era of computing is fixed-filed syntax. A fixed–field syntax utilizes the positioning on a input line to convey information.

Strict fixed-field syntax, where each element of a statement must appear within a given part of an input line, is most often seen in assembly languages. Fixed-field syntax is increasingly rare today and free field is the norm.



Keywords
keywords, also called reserved words, are those words reserved by the language. If we use a keyword for something other than its intended use, we will get an error. A language will typically have between 30 and 50 keywords. Here is a list of some common keywords:
• for
• if
• else
• break
• continue
• return
• while

Most programming languages are case sensitive, so the use of uppercase and lowercase letters matters—for example, "if" is not the same thing as "If" or "IF".


Character Set
[Programming Methods\Fundamentals\Encoding\_Encoding.md]

Identifiers
[Programming Methods\Fundamentals\Constructs\Declarations\Identifiers.md]

Operators
[Programming Methods\Fundamentals\Constructs\Operators\_Operators.md]

Comments
[Programming Methods\Fundamentals\Constructs\Statements\Comments.md]

Whitespace
[Programming Methods\Fundamentals\Constructs\Whitespace.md]

Delimiters
[Programming Methods\Fundamentals\Constructs\Statements\_Statements.md]


## Violating Syntax Rules
There is one big difference between grammar and syntax and that is about forgiveness for errors. If you meet someone who speaks your native language but makes some errors here and there, you will still be able to understand what that person is trying to communicate to you. That is not the case for the syntax of a programming language. If written source code violates the syntactical rules of a programming language its interpretation or compilation will not be successful, the syntax must be flawless.

If we have an error in the syntax, it will be discovered during the translation, and here is where a compiled and an interpreted language will differ. For a compiled language, all the translation will be done before we can execute the program. If we have an error in the syntax, the compilation will stop as soon as the compiler discovers the mistake. We must then find the fault and correct it, then let the compiler try to translate the code again. It is not until our code does not have any syntax errors that we have something we can run completely.

This is different for an interpreted language as it will translate line by line as we run the program. This means that a syntax error can be hidden in a corner of the program that is rarely executed and will not be discovered until we eventually want to run that line of code. When this happens, the program will crash mid-execution with an error message letting us know what problem was there with our syntax.

This means that a source code document that we have written can either be syntactically correct or incorrect. The syntax is a set of rules defining how the source code will be written and structured.
