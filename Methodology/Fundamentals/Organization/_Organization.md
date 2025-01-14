If programs are used, they are also updated, and if you are the developer of a program, this means that you will need to edit the source code in order to add features and fix errors. 

Unorganized code is hard to read and maintain, needing much more time and attention to find where to mend broken, or insert new, code.

There can be other reasons, other than readability, for having code separated from other parts of the program. 

You want to reuse some functionality in other programs or even distribute it to others so they can also use it. To be able to do this, that code must be separate from the rest of the program. This means that it cannot be tightly entangled with other parts of the code. If it is, it will be hard to reuse.

One measure to make your code easier to handle is to distribute it into several logical blocks. But how do we decide what will go into such a block? 

Sections of code will logically belong together, where some things are done to enable others. We need to keep this in mind when deciding on how to split the code into some logical blocks.

There are no fixed rules for how this is done, but the language you use might give you some hints, depending on how it wants you to structure the code. In the end, it is up to you to make the final decision.



