Writing code with readability in mind

Code that you write will not only be executed by the computer. It will also be read both by
yourself and by others. Therefore, is it essential that you write code that is as easy to read
and understand as possible.
There are some simple rules we can follow that will assist in achieving readable code.
Using comments and documentation wisely
When creating code, you need an understanding what you do and why you do it. But
when coming back to your code a couple of months later, it is not always as clear what
these thoughts were and why you wrote things the way you did. Commenting on tricky
lines of code is a great way to document your thoughts for both your future self and others
that will read your code.
But comments can also make the code less readable. Never comment on things that are
obvious – things that any programmer, including yourself, will understand.
You should use comments when you look at a line of code and understand that a reader
who sees this line will need to stop and think before understanding what it does.
Commenting on functions and methods is often a good idea. These comments will
usually come right before the function or method or as the first thing inside it. What you
should use depends on what language you are using, as well as the conventions used by
programmers of that language.

Using names as documentation
By naming variables and functions wisely, the names by themselves will act as
documentation.


When descriptive functions are used, the function names will almost act like a table of content when reading this function. We understand what happens there, and we can go there if we want, but there is no need to do so just to learn what it does. The idea of a table of content in a book is that you will both learn what a chapter is about and learn where to find it. The same thing applies here. If we name our functions well, they will let us know what they do. Most integrated development environments will let us click the name, which means we will be taken to that function if we want to read it.

Best Practices
When writing code, there are some things we can keep in mind to make our code better, quality-wise.

Limiting line length
Long lines are never a good idea. Look at any newspaper and think about why the text hardly ever runs on one line across the full width of the page

A rule of thumb is that if the line is wider than what can fit on the screen, then it is too wide. Use your common sense and divide the code into several lines if needed, but do so in a way that makes sense.

80 characters is also a common line length metric

Some programming editors will assist you in determining the maximum length of your code lines by showing a line to indicate when it is time to add a line break. It is not only the length of the code lines that should be limited.



Limiting function/method length
A function or method should do one thing only, and they should be small. If your functions are hundreds of lines long, you need to make them smaller. When they are 50 lines long, you should probably make them even smaller. Long functions are hard to read, and it is hard to follow the logic as it goes in and out of if statements and loops.

There is no fixed rule for how long a function should be, but a metric that many programmers use is 20 lines.

The important thing is not the actual line count. Instead, you should focus on writing code that is easy to read. To help you write your functions and methods, you should let logic guide you. If you have a long function, just by looking at it, there might be clues that it is made up of multiple logical blocks. The things that can be an indication of this is blanks lines in the code as they are often used to indicate a logical transition of sorts. These decided segments of code can be good candidates to be lifted out of the original function and instead go into a function of their own. We can then just call that function from the place where the code was previously. Another hint can be code that is indented by more than one level. Each level of indentation marks a block of code. Look at the logic that goes on there and ask yourself if you can't make the code cleaner by turning these blocks into functions. Writing high-quality small functions is an art that takes practice to master, but if you don't practice, you will never master it. Get into the habit of always reviewing code you've written and ask yourself if the function or method you just wrote only does one thing. But what is one thing? Is the game Mario Kart one thing? Is asking the user for their credit card number one thing? Is incrementing a number one thing? If a function has a single task, then we might be able to break this task into several subtasks. We could then let the main task be a function and let this function call a function for each subtask.


Avoiding deep nesting
It is sometimes tempting to put several if statements or for loops inside each
other. But many levels of nested if statements or for loops can make them hard
to read and understand.

When you have nested structures that go beyond one level, you should ask yourself if
there is a better way to do this.
Another option is to move the logic into separate functions and call them instead. In some
situations, this will simplify the code and make it easier to read.



Using the DRY principle
DRY stands for Don't Repeat Yourself and was formulated by Andy Hunt and Dave Thomas. It states the following: "Every piece of knowledge must have a single, unambiguous, authoritative representation within a system." This states that we should not repeat the same or similar code more than once. A clear indication that you are about to contradict this principle is when you copy and paste code to a new location in your program, maybe with only some slight changes. This should always be avoided. The idea of DRY boils down to dividing the code into small reusable parts.


Using code conventions
Most programming languages have code conventions. These are recommendations for
how we shall organize our files, indent our code, format comments, and use naming
conventions, just to mention a few.
These are not rules but a recommended code style and the idea is that if all programmers
using a language use the same code convention, their code will look more or less the same.
This means that if you know the convention, it is easier for you to navigate the code and
read it. It is, therefore, essential to learn the convention for every programming language
you are using.
We will look at some typical conventions and see how they differ among a couple
of languages.
Naming conventions
A naming convention is a set of rules for formatting the names of variables, types,
functions, and other entities in the source code.
Sometimes, programming languages come with official naming conventions. Other
times, they are not official but commonly used by the community using a language.
Some companies have developed their own naming conventions for the code written
within that company.
A naming convention is not about how you name things, but how you format the names.
A naming convention dictates how uppercase and lowercase characters should be used
and how names consisting of multiple words should be formatted. Some different styles
are frequently used. Let's look at some of them.
Camel case
In camel case, each word in a multi-word name has an initial capital letter, except for the
initial letter. For example, if we want to store a value for the outside temperature, the name
used for that variable would be outsideTemperature in camel case.342 Code Quality
Camel case is also known as camel caps. The name refers to the apparent humps that the
capital letters form. One early use of this style was by the Swedish chemist Jöns Jacob
Berzelius, who suggested, in an 1813 essay in Annals of Philosophy 2, that chemical
elements should be written as one-letter or two-letter symbols with the first letter
capitalized. That would allow formulae such as NaCl to be written without any spaces.
Pascal case
Pascal case is like camel case, with the only difference being that the first letter is also
written using a capital case. So, the pascal case, the outside temperature variable would be
named OutsideTemperature.
Pascal case gets its name from the programming language Pascal. Even though Pascal is
case-insensitive, the practice was popularized by the Pascal convention to use this style.
Snake case
In snake case, all letters are written in lowercase, and an underscore separates
words. The outside temperature variable, when written in snake case, would be
outside_temperature.
Snake case has been in use for a long time but did not have any established name. An early
reference to the name snake_case comes from Gavin Kistner, who, in 2004, wrote a post
named Appropriate use of CamelCase in the group comp.lang.ruby on Usenet. In it, he said
the following:
"BTW...what *do* you call that naming style? snake_case? That's what I'll call it until
someone corrects me."

Indentation conventions
There are several different styles that are used when it comes to indentation and how compound statements are indicated. For languages that use braces, how the braces are placed is a never-ending debate. Let's look at some variants.

K&R style
The K&R style originates from the Kernighan and Ritchie book The C Programming Language from 1978. When following this style, each function has its opening brace on a new line and the same indentation level as the function header. Blocks inside the function will have their opening brace at the same line as the statement they are opening.

1TBS
1TBS is an abbreviation for one true brace style and is a variant on the K&R style. The only difference is that the opening brace for functions is located on the same line as the function header. Also, in 1TBS, control structures only containing one line will always have braces, a habit not always used in the K&R style.

Java
In Java, a commonly accepted practice is to use the K&R style, extended so that all opening braces are on the same line as the statement it opens. This applies to control structures, classes, and methods.

Allman style
The Allman style, named after the American programmer Eric Allman, puts all opening braces on a new line. People arguing for this style means that it becomes easier to see where a block begins and ends, when the opening and closing braces are on the same indentation level.

Lisp or Python style
This style can be used in any language that uses braces, but is mostly used by languages that don't use braces and use an indentation level to identify blocks of code instead, such as Lisp and Python.

In Python, the indentation levels are part of the language. This is sometimes called the offside rule, a name coined by the British computer scientist Peter J. Landin, most likely as a pun on the offside rule in football, compared to languages that use braces, meaning indentation levels are not decided on by the language.
