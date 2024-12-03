Doxygen is a free (in cost and license) tool that reads your source code, looks for comments that
follow a certain structure, and extracts information from the comments and from the code to produce
documentation. It produces output in a number of formats: HTML, RTF (rich text format), LaTeX, UNIX man
pages, and XML.

Doxygen has no relationship with the C++ standard or with any
C++ vendor. C++ lacks a standard for structured documentation, so you are free to do anything you want.
For example, Microsoft defines its own conventions for XML tags in comments, which is fine, if you plan to
work entirely within the Microsoft .NET environment. For other programmers, I recommend using tools
that have more widespread and portable use. The most popular solution is Doxygen, and I think every C++
programmer should know about it, even if you decide not to use it.


Structured Comments
Doxygen heeds comments that follow a specific format:

One-line comments
start with an extra slash or exclamation mark: /// or //!

Multiline comments
start with an extra asterisk or exclamation mark: /** or /*!

Also, Doxygen recognizes some widespread comment conventions and decorations. For example, it ignores a line of slashes.

```
//////////////////////////////////////////////////////////////////////////////
A multiline comment can begin with a row full of asterisks.
/*****************************************************************************
like this
*****************************************************************************/
And a line in a multiline comment can begin with an asterisk.
/****************************************************************************
* This is a structured comment for Doxygen. *
****************************************************************************/
```

Within a structured comment is where you document the various entities in your program: functions,
types, variables, and so on.
The convention is that the comment immediately before a declaration or definition applies to the entity
being declared or defined. Sometimes, you want to put the comment after the declaration, such as a one-line
description of a variable. To do that, use a “less-than” (<) sign at the start of the comment.
double const c = 299792458.0; ///< speed of light in m/sec


Documentation Tags and Markdown
Doxygen has its own markup language that utilizes tags. A tag can start with a backslash character (\return)
or an “at sign” (@return). Some tags take arguments and some don’t. In addition to its own tags, you can also
use a subset of HTML or Markdown (a wiki-like syntax that is easy to read and write). The most useful tags,
markup, and Markdown are as follows:

@b word
Marks up word in boldface. You can also use HTML markup, <b>phrase</b>, which is helpful when phrase
contains spaces, or use Markdown, by enclosing the text in asterisks: *phrase*.

@brief one-sentence-description
Describes an entity briefly. Entities have brief and detailed documentation. Depending on how you
configure Doxygen, the brief documentation can be the first sentence of the entity’s full documentation, or
you can require an explicit @brief tag. In either case, the rest of the comment is the detailed documentation
for the entity.

@c word
Treats word as a code fragment and set it in a fixed-pitch typeface. You can also use HTML markup,
<tt>phrase</tt>, or use backticks for Markdown, `phrase`.


@em word
Emphasizes word in italics. You can also use HTML tags, <em>phrase</em>, or underscores for Markdown:
_phrase_.
@file file name
Presents an overview of the source file. The detailed description can describe the purpose of the file, revision
history, and other global documentation. The file name is optional; without it, Doxygen uses the file’s real
name.
@link entity text @endlink
Creates a hyperlink to the named entity, such as a file. I use @link on my @mainpage to create a table of
contents to the most important files in the project or to the sole file. Markdown offers a variety of ways to
create links, such as [text](entity).
@mainpage title
Starts an overview of the entire project for the index or cover page. You can put @mainpage in any source file
or even set aside a separate file just for the comment. In small projects, I place @mainpage in the same source
file as the main function, but in large projects, I use a separate file, such as main.dox.
@p name
Sets name in a fixed-pitch typeface to distinguish it as a function parameter.
@par title
Starts a new paragraph. If you supply a one-line title, it becomes the paragraph heading. A blank line also
separates paragraphs.
@param name description
Documents a function parameter named name. If you want to refer to this parameter elsewhere in the
function’s documentation, use @p name.

@post postcondition
Documents a postcondition for a function. A postcondition is a Boolean expression that you can assume to be true when the function returns (assuming all preconditions were true). C++ lacks any formal mechanism for enforcing postconditions (other than assert), so documenting postconditions is crucial, especially for library writers.

@pre precondition
Documents a precondition for a function. A precondition is a Boolean expression that must be true before the function is called, or else the function is not guaranteed to work properly. C++ lacks any formal mechanism for enforcing preconditions (other than assert), so documenting preconditions is crucial,
especially for library writers.

@return description
Documents what a function returns.

@see xref
Inserts a cross-reference to an entity named xref. Doxygen looks for references to other documented entities within the structured comment. When it finds one, it inserts a hyperlink (or text cross-reference, depending on the output format). Sometimes, however, you have to insert an explicit reference to an entity that is not named in the documentation, so you can use @see.
You can suppress automatic hyperlink creation by prefacing a name with %.


@&, @@, @\, @%, @<
Escapes a literal character (&, @, \, %, or <), to prevent interpretation by Doxygen or HTML.
Doxygen is very flexible, and you have many, many ways to format your comments using native
Doxygen tags, HTML, or Markdown. This book’s website has links to the main Doxygen page, where you can
find more information about the tool and download the software. Most Linux users already have Doxygen;
other users can download Doxygen for their favorite platform.
Listing 28-1 shows a few of the many ways you can use Doxygen.



Using Doxygen
Instead of taking lots of command-line arguments, Doxygen uses a configuration file, typically named
Doxyfile, in which you can put all that juicy information. Among the information in the configuration
file are the name of the project, which files to examine for comments, which output format or formats to
generate, and a variety of options you can use to tweak and adjust the output.
Because of the plethora of options, Doxygen comes with a wizard, doxywizard, to help generate a
suitable configuration file, or you can just run the command-line doxygen utility with the -g switch, to
generate a default configuration file that has lots of comments to help you understand how to customize it.


nce you have configured Doxygen, running the program is trivial. Simply run doxygen, and away it
goes. Doxygen does a reasonable job at parsing C++, which is a complicated and difficult language to parse,
but it sometimes gets confused. Pay attention to the error messages, to see if it had any difficulties with your
source files.
The configuration file dictates the location of the output. Typically, each output format resides in its
own subdirectory. For example, the default configuration file stores HTML output in the html directory.
Open the html/index.html file in your favorite browser, to check out the results.
Download and install Doxygen on your system.
Add Doxygen comments to one of your programs. Configure and run Doxygen.
Future programs will continue to use Doxygen comments sporadically, when I think the comments help
you understand what the program does. In general, however, I try to avoid them in the book, because the text
usually explains things well enough, and I don’t want to waste any space. The programs that accompany the
book, however, have more complete Doxygen comments.
