Whitespace Formatting

Whitespaces are nonprintable in the sense that when they are printed on a white sheet of paper, the space between special symbols, reserved words, and identifiers is white. Proper utilization of whitespaces in a program is important. They can be used to make the program more readable.


Indentation
Many language recognize an indentation can be used to make the code easier to read, while some languages will use it for compound statement termination.


Ever since we moved away from machine code, the motivation has been that we want code that is easier to read and write for humans. We shall keep this in mind when we are writing code, as code does not just consist of instructions to the computer, but also something that needs to be maintained by either us or others. As we have learned, one tool that we can use to make the intentions of the code clearer to whoever reads it is indentation.  The indentation technique Indentation is a technique that we use to show that certain code lines belong together in a block. This is typically done for compound statements. Since a compound statement can be constructed of other statements or other compound statements, indentation becomes essential to be able to see what code block a statement belongs to  


Commonly, the text editor that a programmer uses to write the code will help with code indentation, either by automatically indenting code within a compound statement or by providing built-in commands that, when executed, will adequately format the code. There is another formatting trick that we can use to make our code more readable to humans. One such trick is the use of blank lines.


Blank lines
Blank lines separate the paragraphs in this file. The reason is apparent. Without them, the text would be hard to read. These empty lines are not inserted at random. The text within a paragraph is logically connected. We can indicate that the text changes focus by creating a new paragraph, which is by inserting a blank line in the text. The same thing applies to code. Blank lines are inserted for human readers. It is used to show the intent the programmer has. If three statements are somehow connected logically, we can indicate this by adding a blank line after the last statement.



Even if we don't understand anything about what the code does, the information carried by the indentation and the blank lines will give us clues that will make it easier to read the code. Blanks lines are also something that compilers and interpreters will ignore, so they are there for us humans. Just as it is vital to use paragraphs in a line of text correctly, we must use blank lines in a way that makes sense and assist the reader of our code.
