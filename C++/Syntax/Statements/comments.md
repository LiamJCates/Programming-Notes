## Comments
There are two common types of comments in a C++ program:
  single-line comments
  multiple-line comments

Single-line comments begin with // and can be placed anywhere in a line:

  //single line

The compiler ignores anything that appears after // on the same line.

Having comments to the right of a line can make both the code and the comment hard to read, particularly if the line is long. If the lines are fairly short, the comments can simply be aligned (usually to a tab stop), like so:

std::cout << "Hello world!\n";        // std::cout lives in the iostream library
std::cout << "Nice to meet you!\n";   // this is easy to read
std::cout << "Yeah!\n";               // don't you think so?

However, if the lines are long, placing comments to the right can make your lines really long. In that case, single-line comments are often placed above the line it is commenting:

// std::cout lives in the iostream library
std::cout << "Hello world!\n";

// this is much easier to read
std::cout << "It is very nice to meet you!\n";

// don't you think so?
std::cout << "Yeah!\n";




Multi-line Comments

The /* and */ pair of symbols denotes a C-style multi-line comment.

Multiple-line comments are delimited between /* and */:

/* This is a multi-line comment.
   This line will be ignored.
   So will this one. */

The compiler ignores anything that appears between /* and */

Since everything between the symbols is ignored, you will sometimes see programmers “beautify” their multi-line comments:


/* This is a multi-line comment.
 \* the matching asterisks to the left
 \* can make this easier to read
 */

Multi-line style comments can not be nested. Consequently, the following will have unexpected results:

/* This is a multi-line /* comment */ this is not inside the comment */
// The above comment ends at the first */, not the second */

When the compiler tries to compile this, it will ignore everything from the first /* to the first */. Since “this is not inside the comment */” is not considered part of the comment, the compiler will try to compile it. That will inevitably result in a compile error.

This is one place where using a syntax highlighter can be really useful, as the different coloring for comment should make clear what’s considered part of the comment vs not.
