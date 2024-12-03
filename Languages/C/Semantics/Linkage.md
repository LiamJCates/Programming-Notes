Linkages of an Identifier

There are three different kinds of linkages. External, internal and none. Global variables and functions have external linkage as long as they are not static. If they are static then they have internal linkage. By external linkage we mean that for a program which consists of multiple source code files these functions and variable identifiers can be referred in files other than in which they are declared. When functions and global variables are static i.e. they have internal linkage they cannot be accessed in other source code files.

The following identifiers have no linkage: an identifier declared to be anything other than an variable or a function; an identifier declared to be a function parameter; a block scope identifier for an object declared without the storage-class specifier extern.
