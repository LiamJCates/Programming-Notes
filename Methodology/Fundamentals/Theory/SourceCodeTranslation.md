## Source Code Translation
The high level language modern programmers write is called source code. The many hello world examples above are each an example of their respective languages source code.

Source code must be translated into machine code so that the computer can understand it. There are two main principles of how this translation is done. We will first explore these two concepts and look at their pros and cons before we look at a combination of these two concepts.

One way to carry out this translation is by using an interpreter. An interpreter will look at a single line of source code, translate it into machine code, let the computer execute this line, and then move on to the next line of code. The way the interpreter works is a bit like how a simultaneous translator works with human languages. A simultaneous translator will, for example, work for the UN. In the UN, everyone is entitled to speak in their native language. A group of translators listens to the talk, and as they listen, they will translate it into another language. Delegates can then listen to the speech in real time in their native language through headphones.

Another way to carry out the translation is by using a technique called compiling. When we compile source code into machine code, we first translate every line of code, and it is not until the translation of all of the lines of code has been done that the program is executed. We can compare this to the concept of translating a book. First, an author writes the book in one language. A translator will then translate the whole book into another language. It is not until the translation of all of the text in the original book is done that it will be available to read.

Interpreting and compiling are two of the main techniques for translating source code. A programming language can use either one of these techniques, and a language is therefore often referred to as either an interpreted or compiled language.

Let's look more closely at these two techniques so that we can understand them better before we compare them.

When an interpreted languages source code is executed, a specialized program called an interpreter will read the source code line by line and translate each line during runtime, the time the program is active.

A compiler will instead translate all the code in the source code document and store it in a file containing the machine code instructions. When we want to run the program, we can use this file to run it; it is at this point that the CPU will execute the machine code.


What are the advantages and disadvantages of these two methods of translation?

Advantages of Interpretation:
• It has a smaller program size.
• If we have the code and an interpreter, we can run it on any platform (for example, Windows, Linux, macOS, and so on).
• Interpreted languages tend to be more flexible for programmers to use. One
example of this is called dynamic typing.

Disadvantages of  Interpretation:
• The program runs slower as translation happens during runtime.
• Anyone who wants to run the program must have an interpreter installed.
• The user of the program has access to the source code, so if it is a commercial application, all the code we have written will be accessible to anyone, including any potential business secrets.



Advantages of Compilation:
• It runs faster as the translation is done previous to runtime.
• No extra program is needed to run the application — that is, the application has all the information it needs to run, so the user does not need to have any other programs installed.
• Compiled programming languages tend to help the programmer with things such
as type checking to a higher degree.

Disadvantages of Compilation:
• The programs tend to be larger as a single line of programming language code can constitute many lines of machine code as previous examples indicate.
• We need to make versions for all of the platforms that we intend the program to run on — that is, we need a Windows version, a macOS version, and a Linux version as the file a compiler outputs is only translated for one type of machine.
• The time it takes to complete the translation can be long, making it harder to try things out as we write the program.

Some examples of interpreted languages are PHP, Ruby, and JavaScript.
Some examples of compiled languages are C, C++, COBOL, ALGOL, Fortran, and Lisp


We also have a group of languages that both compile and interpret. When they compile the source code, they do not directly compile it into machine code. They follow an intermediate step where they compile the source code into byte code. This byte code is then interpreted as the program executes. The benefit of doing this is that we get some of the advantages of both techniques. For example, this byte code can be distributed to anyone who wants to run the program, and then an interpreter will interpret the byte code into machine code for the current system that the program is executed on.

Another advantage that compiled languages have—and this applies to the technique of mixing them, too—is that if there is an error in the source code, the compiler will detect this because the syntax (the grammar of a language) has to be correct and if it is not, the compiler can't proceed and will stop the translation. The programmer then needs to go back and correct the error before the program can compile again. Mixed technique languages share a disadvantage with interpreted languages, which is that programs written with them will run slower than programs written in a compiled language.

Some examples of mixed technique languages are Python, Java, C#, and Perl.
