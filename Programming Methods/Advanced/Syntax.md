## Syntax
A programming language's surface form is known as its syntax.


### Tokens
The smallest individual unit of a program written in any language is called a token.


The syntax of textual programming languages is usually defined using a combination of
  regular expressions (for lexical structure)
  EBNF Backus–Naur form (for grammatical structure)

These rules inductively specify syntactic categories (nonterminals) and terminal symbols.

Syntactic categories are defined by rules called productions, which specify the values that belong to a particular syntactic category.

Terminal symbols are the concrete characters or strings of characters (for example keywords such as define, if, let, or void) from which syntactically valid programs are constructed.

The syntax of a language describes the possible combinations of symbols that form a syntactically correct program.

Documents that are syntactically invalid are said to have a syntax error.

The meaning given to a combination of symbols is handled by semantics (either formal or hard-coded in a reference implementation).

Not all syntactically correct programs are semantically correct.
Many syntactically correct programs are nonetheless ill-formed, per the language's rules; and may (depending on the language specification and the soundness of the implementation) result in an error on translation or execution.





Computer language syntax is generally distinguished into three levels:
  Words – the lexical level, determining how characters form tokens;
  Phrases – the grammar level, narrowly speaking, determining how tokens form phrases;
  Context – determining what objects or variables names refer to, if types are valid, etc

Distinguishing in this way yields modularity, allowing each level to be described and processed separately, and often independently.

First a lexer turns the linear sequence of characters into a linear sequence of tokens; this is known as "lexical analysis" or "lexing".

Second the parser turns the linear sequence of tokens into a hierarchical syntax tree; this is known as "parsing" narrowly speaking.

Thirdly the contextual analysis resolves names and checks types.

Fourth - Evaluation/ Runtime Error Handling





A language can have unique equivalent grammars.

The grammar needed to specify a programming language can be classified by its position in the Chomsky hierarchy.
The syntax of most programming languages can be specified using a Type-2 grammar, i.e., they are context-free grammars.



syntax of a computer language is the set of rules that defines the combinations of symbols that are considered to be a correctly structured document or fragment in that language.




The parsing stage itself can be divided into two parts:
the parse tree or "concrete syntax tree" which is determined by the grammar, but is generally far too detailed for practical use,
and the abstract syntax tree (AST), which simplifies this into a usable form.

The AST and contextual analysis steps can be considered a form of semantic analysis, as they are adding meaning and interpretation to the syntax

Syntax – the form – is contrasted with semantics – the meaning.




Syntax versus semantics
The syntax of a language describes the form of a valid program, but does not provide any information about the meaning of the program or the results of executing that program.

The meaning given to a combination of symbols is handled by semantics
Not all syntactically correct programs are semantically correct.
Many syntactically correct programs are nonetheless ill-formed, per the language's rules; and may (depending on the language specification and the soundness of the implementation) result in an error on translation or execution.

int x;
printf("%d", x);

is syntactically valid, but not semantically defined, as it uses an uninitialized variable.
Even though compilers for some programming languages (e.g., Java and C#) would detect uninitialized variable errors of this kind, they should be regarded as semantic errors rather than syntax errors.


A lexical analyzer identifies the tokens of the programming language grammar, e.g. identifiers or keywords, which are themselves expressed in a simpler formal language, usually by means of regular expressions.

A parser attempts to decide if the source program is valid, that is if it belongs to the programming language for which the compiler was built.

Of course, compilers do more than just parse the source code – they usually translate it into some executable format. Because of this, a parser usually outputs more than a yes/no answer, typically an abstract syntax tree.

The abstract syntax tree is used by subsequent stages of the compiler to eventually generate an executable containing machine code that runs directly on the hardware, or some intermediate code that requires a virtual machine to execute.



the grammar written in BNF or EBNF defines the syntax of a programming language, which drives the parser's implementation





Lexical analysis
lexical analysis, lexing or tokenization: converts character a sequence into a token sequence
tokens: strings with identified meaning

A lexer is generally combined with a parser, which together analyze the syntax of programming languages

It is structured as a pair consisting of a token name and an optional token value.
The token name is a category of lexical unit.

Common token names are
identifier: names the programmer chooses;
keyword: names already in the programming language;
separator (also known as punctuators): punctuation characters and paired-delimiters;
operator: symbols that operate on arguments and produce results;
literal: numeric, logical, textual, reference literals;
comment: line, block.

| Token name | Sample token values |
|------------|---------------------|
| identifier | x, color, UP |
| keyword | if, while, return |
| separator | }, (, ; |
| operator | +, <, = |
| literal | true, 6.02e23, "music" |
| comment | /* Retrieves user data */, // must be negative |

Consider this expression in the C programming language:
x = a + b * 2;
The lexical analysis of this expression yields the following sequence of tokens:
[(identifier, x), (operator, =), (identifier, a), (operator, +), (identifier, b), (operator, *), (literal, 2), (separator, ;)]

The specification of a programming language often includes a set of rules, the lexical grammar, which defines the lexical syntax.
The lexical syntax is usually a regular language, with the grammar rules consisting of regular expressions; they define the set of possible character sequences (lexemes) of a token.
A lexer recognizes strings, and for each kind of string found the lexical program takes an action, most simply producing a token.


extended Backus-Naur form (EBNF)
metasyntax notation, used to express a context-free grammar.
EBNF expresses the formal description of a formal language

EBNF is a code that expresses the grammar of a formal language.
An EBNF consists of terminal symbols and non-terminal production rules

Examples of terminal symbols include alphanumeric characters, punctuation marks, and whitespace characters.

The EBNF defines production rules where sequences of symbols are respectively assigned to a nonterminal:

production rules defines the nonterminal on the left side of the assignment.
The vertical bar represents an alternative
terminal symbols are enclosed with quotation marks followed by a semicolon as terminating character.

Expressions that may be omitted or repeated can be represented through curly braces { ... }:

option [ ... ]: may appear 0-1 times


| Usage | Notation |
|-------|----------|
| definition | = |
| concatenation | , |
| termination | ; |
| alternation | | |
| optional | [ ... ] |
| repetition | { ... } |
| grouping | ( ... ) |
| terminal string | " ... " |
| terminal string | ' ... ' |
| comment | (* ... *) |
| special sequence | ? ... ? |
| exception | - |

terminal        match function:    if  == 'term' then nextToken() else ERROR
non-terminal    parser has function for each
sequence    
alternation
repetition

http://web.cse.ohio-state.edu/software/2231/web-sw2/extras/slides/27.Recursive-Descent-Parsing.pdf
Parser

A parser must be deterministic
We use the grammar to implement a recursive-descent parser (i.e., an algorithm to parse a program and construct the corresponding Program object)
A single grammer rule typically drives the implementation of each parser function

A parser uses a context-free grammar (CFG) to specify syntactically valid programs

A CFG can be used to generate strings in its language – “Given the CFG, construct a string that is in the language”
A CFG can also be used to recognize strings in its language – “Given a string, decide whether it is in the language”
– If so, we may construct a derivation tree (or AST)

The definition of the abstract syntax takes the form of a datatype declaration that is reminiscent of a context-free grammar, but which abstracts from matters of lexical presentation (such as precedences of operators, parenthesization, conventions for naming the operators, etc.)

Parsing generally refers to this last step, i.e., going from a string (in the language) to its derivation tree or— for a programming language— perhaps to an AST for the program.

In computer science, a grammar is informally called a recursive grammar if it contains production rules that are recursive, meaning that expanding a non-terminal according to these rules can eventually lead to a string that includes the same non-terminal again. Otherwise it is called a non-recursive grammar.

A Recursive-Descent Parser
a recursive descent parser is a kind of top-down parser built from a set of mutually recursive procedures (or a non-recursive equivalent) where each such procedure implements one of the nonterminals of the grammar. Thus the structure of the resulting program closely mirrors that of the grammar it recognizes.

A predictive parser is a recursive descent parser that does not require backtracking. Predictive parsing is possible only for the class of LL(k) grammars, which are the context-free grammars for which there exists some positive integer k that allows a recursive descent parser to decide which production to use by examining only the next k tokens of input. The LL(k) grammars therefore exclude all ambiguous grammars, as well as all grammars that contain left recursion. Any context-free grammar can be transformed into an equivalent grammar that has no left recursion, but removal of left recursion does not always yield an LL(k) grammar. A predictive parser runs in linear time.

• One parse method per non-terminal symbol
terminal and nonterminal symbols are the lexical elements used in specifying the production rulesconstituting a formal grammar. Terminal symbols are the elementary symbols of the language defined by a formal grammar.Nonterminal symbols (or syntactic variables) are replaced by groups of terminal symbols according to the production rules.
The terminals and nonterminals of a particular grammar are two disjoint sets.

Terminal symbols are literal symbols which may appear in the outputs of the production rules of a formal grammar and which cannot be changed using the rules of the grammar. Applying the rules recursively to a source string of symbols will usually terminate in a final output string consisting only of terminal symbols.

• A non-terminal symbol on the right-hand side of a rewrite rule leads to a call to the parse method for that non-terminal
• A terminal symbol on the right-hand side of a rewrite rule leads to “consuming” that token from the input token string
• | in the CFG leads to “if-else” in the parser

https://en.wikipedia.org/wiki/Extended_Backus%E2%80%93Naur_form
The special CFG symbols { and } mean that the enclosed sequence of symbols occurs zero or more times; this helps change a left-recursive CFG into an equivalent CFG that can be parsed by recursive descent.
• {...} in the CFG leads to “while” in the parser

Nonterminal symbols are those symbols which can be replaced. They may also be called simply syntactic variables. A formal grammar includes a start symbol, a designated member of the set of nonterminals from which all the strings in the language may be derived by successive applications of the production rules. In fact, the language defined by a grammar is precisely the set of terminal strings that can be so derived.
Context-free grammars are those grammars in which the left-hand side of each production rule consists of only a single nonterminal symbol. This restriction is non-trivial; not all languages can be generated by context-free grammars. Those that can are called context-free languages. These are exactly the languages that can be recognized by a non-deterministic push down automaton. Context-free languages are the theoretical basis for the syntax of most programming languages.
https://en.wikipedia.org/wiki/Context-free_grammar

Production rules
A grammar is defined by production rules (or just 'productions') that specify which symbols may replace which other symbols; these rules may be used to generate strings, or to parse them. Each such rule has a head, or left-hand side, which consists of the string that may be replaced, and a body, or right-hand side, which consists of a string that may replace it. Rules are often written in the form head → body; e.g., the rule a → b specifies that a can be replaced by b.




In programming languages, the associativity of an operator is a property that determines how operators of the same precedence are grouped in the absence of parentheses. If an operand is both preceded and followed by operators (for example, ^ 3 ^), and those operators have equal precedence, then the operand may be used as input to two different operations (i.e. the two operations indicated by the two operators). The choice of which operations to apply the operand to, is determined by the "associativity" of the operators. Operators may be associative (meaning the operations can be grouped arbitrarily), left-associative (meaning the operations are grouped from the left), right-associative (meaning the operations are grouped from the right) or non-associative (meaning operations cannot be chained, often because the output type is incompatible with the input types). The associativity and precedence of an operator is a part of the definition of the programming language; different programming languages may have different associativity and precedence for the same type of operator.

Consider the expression a ~ b ~ c. If the operator ~ has left associativity, this expression would be interpreted as (a ~ b) ~ c. If the operator has right associativity, the expression would be interpreted as a ~ (b ~ c).
If the operator is non-associative, the expression might be a syntax error, or it might have some special meaning.

Some mathematical operators have inherent associativity. For example, subtraction and division, as used in conventional math notation, are inherently left-associative.

Addition and multiplication, by contrast, are both left and right associative. (e.g. (a * b) * c = a * (b * c)).

The concept of notational associativity described here is related to, but different from the mathematical associativity. An operation that is mathematically associative, by definition requires no notational associativity. (For example, addition has the associative property, therefore it does not have to be either left associative or right associative.) An operation that is not mathematically associative, however, must be notationally left-, right-, or non-associative. (For example, subtraction does not have the associative property, therefore it must have notational associativity.)

In order to reflect normal usage, addition, subtraction, multiplication, and division operators are usually left-associative, while an exponentiation operator (if present) is right-associative;[1][2][3][4][5] this applies to the up-arrow operator as well. Any assignment operators are also typically right-associative. To prevent cases where operands would be associated with two operators, or no operator at all, operators with the same precedence must have the same associativity.

In many imperative programming languages, the assignment operator is defined to be right-associative, and assignment is defined to be an expression (with a value), not just a statement. This allows chained assignment by using the value of one assignment expression as the input (right operand) of the next.

A parse tree or parsing tree[1] or derivation tree or concrete syntax tree is an ordered, rooted tree that represents the syntactic structure of a stringaccording to some context-free grammar. The term parse tree itself is used primarily in computational linguistics; in theoretical syntax, the term syntax treeis more common.

The constituency-based parse trees of constituency grammars (= phrase structure grammars) distinguish between terminal and non-terminal nodes. The interior nodes are labeled by non-terminal categories of the grammar, while the leaf nodes are labeled by terminal categories.

Each node in the tree is either a root node, a branch node, or a leaf node.[4] A root node is a node that doesn't have any branches on top of it. Within a sentence, there is only ever one root node. A branch node is a mother node that connects to two or more daughter nodes. A leaf node, however, is a terminal node that does not dominate other nodes in the tree.

The following example demonstrates the common case of parsing a computer language with two levels of grammar: lexical and syntactic.
The first stage is the token generation, or lexical analysis, by which the input character stream is split into meaningful symbols defined by a grammar of regular expressions. For example, a calculator program would look at an input such as "12 * (3 + 4)^2" and split it into the tokens 12, *, (, 3, +, 4, ), ^, 2, each of which is a meaningful symbol in the context of an arithmetic expression. The lexer would contain rules to tell it that the characters *, +, ^, ( and ) mark the start of a new token, so meaningless tokens like "12*" or "(3" will not be generated.
The next stage is parsing or syntactic analysis, which is checking that the tokens form an allowable expression. This is usually done with reference to a context-free grammar which recursively defines components that can make up an expression and the order in which they must appear. However, not all rules defining programming languages can be expressed by context-free grammars alone, for example type validity and proper declaration of identifiers. These rules can be formally expressed with attribute grammars.
The final phase is semantic parsing or analysis, which is working out the implications of the expression just validated and taking the appropriate action. In the case of a calculator or interpreter, the action is to evaluate the expression or program; a compiler, on the other hand, would generate some kind of code. Attribute grammars can also be used to define these actions.

Top-down parsing - Top-down parsing can be viewed as an attempt to find left-most derivations of an input-stream by searching for parse trees using a top-down expansion of the given formal grammar rules. Tokens are consumed from left to right. Inclusive choice is used to accommodate ambiguity by expanding all alternative right-hand-sides of grammar rules.[5]

 recursive-descent parser are examples of top-down parsers which cannot accommodate left recursiveproduction rules.

The deterministic behavior is desired and expected in compiling programming languages.

abstract syntax tree(AST), or just syntax tree, is a tree representation of the abstract syntactic structure of source codewritten in a programming language. Each node of the tree denotes a construct occurring in the source code. The syntax is "abstract" in the sense that it does not represent every detail appearing in the real syntax, but rather just the structural, content-related details. For instance, grouping parentheses are implicit in the tree structure, and a syntactic construct like an if-condition-then expression may be denoted by means of a single node with three branches.
This distinguishes abstract syntax trees from concrete syntax trees, traditionally designated parse trees, which are typically built by a parserduring the source code translation and compilingprocess. Once built, additional information is added to the AST by means of subsequent processing, e.g., contextual analysis.
Abstract syntax trees are also used in program analysis and program transformation systems.

If an operator is left-associative, then the corresponding production will be left recursive and vice versa

i=0nci    traversal time for tree with children per node = c and max depth = n

Abstract syntax is abstract because it omits irrelevant details (‘‘irrelevant’’ depends on the analysis task)

Converting concrete syntax to abstract syntax is the job of a parser

To evaluate an expression, first evaluate the sub-expressions, then combine their values

expression evaluation takes two arguments:
an expression
a set of lazy substitutions the set of lazy substitutions is called an environment
