Avoiding conflicts using namespaces
When writing code, you will constantly name things, variables, constants, functions, source code files, etc...

The problem is, what if you give something a name that is already being used?

An application can consist of thousands of lines of code divided into hundreds of files. We also learned that we can install packages with code that others have written.

How can you make sure that the names you give something are not already taken or that a package we install is not using names that another package we already installed is using?

As you can see, handling names can be tricky.


Delving into namespaces
To understand what a namespace is, we can think of files and folders on our computer. On a computer, we can have multiple files with the same name, but within a folder, the filenames must be unique.

Many programming languages use a similar technique, called namespaces. Namespaces let us reuse the same name multiple times within an application, but in a namespace, all the names must be unique. The namespace acts like the folders on the computer, and the things we are naming are like the files.

How namespaces are implemented will differ between languages.
