Regular expressions are a powerful tool for text processing. They provide a way to simply and tersely describe patterns in text

In <regex>, the standard library provides
support for regular expressions in the form of the std::regex class and its supporting functions.

To give a taste of the style of the regex library, let us define and print a pattern:
regex pat {R"(\w{2}\s∗\d{5}(−\d{4})?)"};
// U.S. postal code pattern: XXddddd-dddd and variants

People who have used regular expressions in just about any language will find \w{2}\s∗\d{5}(−\d{4})? familiar.

Specifies
a pattern starting with two letters \w{2}
optionally followed by some space \s∗
followed by five digits \d{5}
optionally followed by a dash and four digits −\d{4}.




To express a regex pattern use a raw string literal starting with R"( and terminated by )".

This allows backslashes and quotes to be used directly in the string.

Raw strings are particularly suitable for regular expressions because they tend to contain a lot of backslashes. Had I used a conventional
string, the pattern definition would have been:
regex pat {"\\w{2}\\s∗\\d{5}(−\\d{4})?"};


In <regex>, the standard library provides support for regular expressions:
• regex_match(): Match a regular expression against a string (of known size).
• regex_search(): Search for a string that matches a regular expression in an arbitrarily long stream of data.
• regex_replace(): Search for strings that match a regular expression in an arbitrarily long stream of data and replace them.
• regex_iterator: Iterate over matches and submatches.
• regex_token_iterator: Iterate over non-matches.





Regular Expression Notation

The regex library can recognize several variants of the notation for regular expressions.

Used here is the default notation, a variant of the ECMA standard used for ECMAScript (more commonly known as JavaScript).

The syntax of regular expressions is based on characters with special meaning:

Regular Expression Special Characters
| Character | Meaning |
|-----------|---------|
| . | Any single character (a ‘‘wildcard’’) |
| [ | Begin character class  |
| ] | End character class  |
| { | Begin count  |
| } | End count  |
| ( | Begin grouping |
| ) | End grouping  |
| \ | Next character has a special meaning |
| ∗ | Zero or more (suffix operation) |
| + | One or more (suffix operation) |
| ? | Optional (zero or one) (suffix operation) |
| \| | Alternative (or) |
| ˆ | Start of line; negation |
| $ | End of line |

For example, we can specify a line starting with zero or more As followed by one or more Bs followed by an optional C like this:
ˆA∗B+C?$

matches:

AAAAAAAAAAAABBBBBBBBBC
BC
B

Examples that do not match:
AAAAA // no B
 AAAABC // initial space
AABBCC // too many Cs

A part of a pattern is considered a subpattern (which can be extracted separately from an smatch) if it is enclosed in parentheses:

\d+−\d+ // no subpatterns
\d+(−\d+) // one subpattern
(\d+)(−\d+) // two subpatterns

A pattern can be optional or repeated (the default is exactly once) by adding a suffix:

Repetition
| Suffix | Meaning |
|--------|---------|
| { n } | Exactly n times |
| { n, } | n or more times |
| {n,m} | At least n and at most m times |
| ∗ | Zero or more, that is, {0,} |
| + | One or more, that is, {1,} |
| ? | Optional (zero or one), that is {0,1} |

For example:
A{3}B{2,4}C∗

Examples that match:
AAABBC
AAABBB

Examples that do not match:
AABBC // too few As
AAABC // too few Bs
AAABBBBBCCC // too many Bs

A suffix ? after any of the repetition notations (?, ∗, +, and { }) makes the pattern matcher ‘‘lazy’’ or ‘‘non-greedy.’’

That is, when looking for a pattern, it will look for the shortest match rather than the longest. By default, the pattern matcher always looks for the longest match; this is known as the Max Munch rule.

Consider:
ababab

(ab)+ matches all of ababab.
(ab)+? matches only the first ab.

The most common character classifications have names:

| Character | Classes |
|-----------|---------|
| alnum | Any alphanumeric character |
| alpha | Any alphabetic character |
| blank | Any whitespace character that is not a line separator |
| cntrl | Any control character |
| d | Any decimal digit |
| digit | Any decimal digit |
| graph | Any graphical character |
| lower | Any lowercase character |
| print | Any printable character |
| punct | Any punctuation character |
| s | Any whitespace character |
| space | Any whitespace character |
| upper | Any uppercase character |
| w | Any word character (alphanumeric characters plus the underscore) |
| xdigit | Any hexadecimal digit character |

In a regular expression, a character class name must be bracketed by [: :]: [:digit:] //matches a decimal digit.

Furthermore, they must be used within a [ ] pair defining a character class.

Several character classes are supported by shorthand notation:

Character Class Abbreviations

| Symbols | Meaning |
|---------|---------|
| \d | A decimal digit [[:digit:]] |
| \s | A space (space, tab, etc.) [[:space:]] |
| \w | A letter (a-z) or digit (0-9) or underscore (_) [_[:alnum:]] |
| \D | Not \d [ˆ[:digit:]] |
| \S | Not \s [ˆ[:space:]] |
| \W | Not \w [ˆ_[:alnum:]] |

In addition, languages supporting regular expressions often provide:

Nonstandard (but Common) Character Class Abbreviations

| Symbols | Meaning |
|---------|---------|
| \l | A lowercase character [[:lower:]] |
| \u | An uppercase character [[:upper:]] |
| \L | Not \l [ˆ[:lower:]] |
| \U | Not \u [ˆ[:upper:]] |

For full portability, use the character class names rather than these abbreviations.

As an example, consider writing a pattern that describes C++ identifiers: an underscore or a letter followed by a possibly empty sequence of letters, digits, or underscores. To illustrate the subtleties involved, I include a few false attempts:

[:alpha:][:alnum:]∗
// wrong: characters from the set ":alpha" followed by ...

[[:alpha:]][[:alnum:]]∗
// wrong: doesn’t accept underscore ('_' is not alpha)

([[:alpha:]]|_)[[:alnum:]]∗
// wrong: underscore is not part of alnum either

([[:alpha:]]|_)([[:alnum:]]|_)∗
// OK, but clumsy

[[:alpha:]_][[:alnum:]_]∗
// OK: include the underscore in the character classes

[_[:alpha:]][_[:alnum:]]∗
// also OK

[_[:alpha:]]\w∗
// \w is equivalent to [_[:alnum:]]

Finally, here is a function that uses the simplest version of regex_match()  to test whether a string is an identifier:

bool is_identifier(const string& s)
{
  regex pat {"[_[:alpha:]]\\w∗"}; // underscore or letter
  // followed by zero or more underscores, letters, or digits
  return regex_match(s,pat);
}

Note the doubling of the backslash to include a backslash in an ordinary string literal. Use raw string literals to alleviate problems with special characters. For example:

bool is_identifier(const string& s)
{
  regex pat {R"([_[:alpha:]]\w∗)"};
  return regex_match(s,pat);
}

Here are some examples of patterns:
Ax∗ // A, Ax, Axxxx
Ax+ // Ax, Axxx Not A
\d−?\d // 1-2, 12 Not 1--2
\w{2}−\d{4,5} // Ab-1234, XX-54321, 22-5432 Digits are in \w
(\d∗:)?(\d+) // 12:3, 1:23, 123, :123 Not 123:
(bs|BS) // bs, BS Not bS
[aeiouy] // a, o, u An English vow el, not x
[ˆaeiouy] // x, k Not an English vow el, not e
[aˆeiouy] // a, ˆ, o, u An English vow el or ˆ

A group (a subpattern) potentially to be represented by a sub_match is delimited by parentheses. If you need parentheses that should not define a subpattern, use (?: rather than plain (.
For example:
(\s|:|,)∗(\d∗)
// optional spaces, colons, and/or commas followed by an optional number

Assuming that we were not interested in the characters before the number (presumably separators), we could write:
(?:\s|:|,)∗(\d∗)
// optional spaces, colons, and/or commas followed by an optional number

This would save the regular expression engine from having to store the first characters: the (?: variant has only one subpattern.


Regular Expression Grouping Examples
\d∗\s\w+ No groups (subpatterns)
(\d∗)\s(\w+) Tw o groups
(\d∗)(\s(\w+))+ Tw o groups (groups do not nest)
(\s∗\w∗)+ One group; one or more subpatterns;
only the last subpattern is saved as a sub_match
<(.∗?)>(.∗?)</\1> Three groups; the \1 means ‘‘same as group 1’’

That last pattern is useful for parsing XML. It finds tag/end-of-tag markers. Note that I used a non-greedy match (a lazy match), .∗?, for the subpattern between the tag and the end tag.

Had I used plain .∗, this input would have caused a problem:
Always look on the <b>bright</b> side of <b>life</b>.

A greedy match for the first subpattern would match the first < with the last >. That would be correct behavior, but unlikely what the programmer wanted.






## Searching
The simplest way of using a pattern is to search for it in a stream:

int lineno = 0;
for (string line; getline(cin,line); ) { // read into line buffer
  ++lineno;
  smatch matches; // matched strings go here
  if (regex_search(line,matches,pat)) // search for pat in line
    cout << lineno << ": " << matches[0] << '\n';
}

regex_search(line ,matches, pat) searches the line for anything that matches the regular expression stored in pat and if it finds any matches, it stores them in matches.

If no match was found, regex_search(line ,matches,pat) returns false.

The matches variable is of type smatch. The ‘‘s’’ stands for ‘‘sub’’ or ‘‘string,’’ and an smatch is a vector of submatches of type string. The first element, here matches[0], is the complete match.

The result of a regex_search() is a collection of matches, typically represented as an smatch:
void use()
{
  ifstream in("file.txt"); // input file
  if (!in) // check that the file was opened
    cerr << "no file\n";

  regex pat {R"(\w{2}\s∗\d{5}(−\d{4})?)"}; // U.S. postal code pattern
  int lineno = 0;
  for (string line; getline(in,line); ) {
    ++lineno;
    smatch matches; // matched strings go here
    if (regex_search(line , matches, pat)) {
      cout << lineno << ": " << matches[0] << '\n'; // the complete match
      if (1<matches.siz e() && matches[1].matched) // if there is a sub-pattern and if it is matched
        cout << "\t: " << matches[1] << '\n'; // submatch
    }
  }
}

This function reads a file looking for U.S. postal codes, such as TX77845 and DC 20500−0001. An smatch type is a container of regex results. Here, matches[0] is the whole pattern and matches[1] is the optional four-digit subpattern.

The newline character, \n, can be part of a pattern, so we can search for multiline patterns.

Obviously, we shouldn’t read one line at a time if we want to do that.

The regular expression syntax and semantics are designed so that regular expressions can be compiled into state machines for efficient execution [Cox,2007]. The regex type performs this compilation at run time







## Iterators
We can define a regex_iterator for iterating over a sequence of characters finding matches for a pattern.

sregex_iterator (a regex_iterator<string>) outputs all whitespace separated words in a string:

void test()
{
  string input = "aa as; asd ++eˆasdf asdfg";
  regex pat {R"(\s+(\w+))"};
  for (sregex_iterator p(input.begin(),input.end(),pat); p!=sregex_iterator{}; ++p)
    cout << (∗p)[1] << '\n';
}

This outputs:
as
asd
asdfg

We missed the first word, aa, because it has no preceding whitespace.

If we simplify the pattern to R"((\w+))":
aa
as
asd
e
asdf
asdfg

A regex_iterator is a bidirectional iterator, so we cannot directly iterate over an istream (which offers only an input iterator). Also, we cannot write through a regex_iterator, and the default regex_iterator (regex_iterator{}) is the only possible end-of-sequence.
