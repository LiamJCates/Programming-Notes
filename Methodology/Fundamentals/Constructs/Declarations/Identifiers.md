Identifiers are used to reference code elements from other parts of our program.

While the rules for specifying an identifier vary by language some standard rules are as follows:
  It can contain letters, numbers, and underscores.
  It must contain at least one letter - at the start of the name.
  It must not contain special characters or whitespace.
  It must not be one of the language's reserved or keywords

These conventions, called naming conventions, are common.

The name should be meaningful - it should represent the code element the identifier names.




## Multiple Words
There are also conventions for how to create names that are made up of more than one word.

A common recommendation is "Use meaningful identifiers." A single word may not be as meaningful, or specific, as multiple words. Consequently, some naming conventions specify rules for the treatment of "compound" identifiers containing more than one word.

As most programming languages do not allow whitespace in identifiers, a method of delimiting each word is needed (to make it easier for subsequent readers to interpret which characters belong to which word).

One approach is to delimit separate words with a nonalphanumeric character. The two characters commonly used for this purpose are the hyphen ("-") known as kebab case and the underscore ("_") known as snake case; e.g., the two-word name "two words" would be represented as "two-words" or "two_words".

Another approach is to indicate word boundaries using medial capitalization, called "camelCase".  There are two sub-types — upper camel case (also known as Pascal case) typically used for function names and lower camel case (also known as Dromedary case) typically used for variables. Thus respectively rendering "two words" as "twoWords" or "TwoWords".

Multiple-word identifier formats

| Formatting | Name(s) |
|------------|---------|
| twowords | flat case |
| TWOWORDS | upper flat case |
| twoWords | (lower) camelCase, dromedaryCase |
| TwoWords | upper CamelCase, PascalCase, StudlyCase[14] |
| two_words | snake_case, pothole_case |
| TWO_WORDS | SCREAMING_SNAKE_CASE, MACRO_CASE, CONSTANT_CASE |
| two_Words | camel_Snake_Case |
| Two_Words | Pascal_Snake_Case |
| two-words | kebab-case, dash-case, lisp-case |
| two|words | doner\|case |
| TWO-WORDS | TRAIN-CASE, COBOL-CASE, SCREAMING-KEBAB-CASE |
| Two-Words | Train-Case, HTTP-Header-Case |



## Potential Benefits
Some of the potential benefits that can be obtained by adopting a naming convention include the following:

    to provide additional information (i.e., metadata) about the use to which an identifier is put;
    to help formalize expectations and promote consistency within a development team;
    to enable the use of automated refactoring or search and replace tools with minimal potential for error;
    to enhance clarity in cases of potential ambiguity;
    to enhance the aesthetic and professional appearance of work product (for example, by disallowing overly long names, comical or "cute" names, or abbreviations);
    to help avoid "naming collisions" that might occur when the work product of different organizations is combined (see also: namespaces);
    to provide meaningful data to be used in project handovers which require submission of program source code and all relevant documentation;
    to provide better understanding in case of code reuse after a long interval of time.
