SQL Aliases

SQL aliases are used to give a table, or a column in a table, a temporary name.
Aliases are often used to make column and table names more readable.
An alias only exists for the duration of the query.


Anytime you use a table, immediately after you may give it an alternate name
The alias can be used in lieu of the full table name throughout the SQL statement, even in the portion of the statement that precedes the alias declaration. Aliases are used to avoid repetition of lengthy table names, to repeat the same table multiple times in a join. Listing the same table with a different alias allows for a table to be used multiple times without having to make a copy.


Aliases are assigned with the AS keyword.

Alias Column Syntax
SELECT [column_name] AS [alias_name] FROM [table_name];

Alias Table Syntax
SELECT [column_name(s)] FROM [table_name] AS [alias_name];


any client application can refer to this column by name, just as it would to any actual table column.

AS Often Optional
Use of the AS keyword is optional in many DBMSs, but using it is considered a best practice.

Tip: Other Uses for Aliases
Aliases have other uses too.
Some common uses include renaming a column if the real table column name contains illegal characters (for example, spaces), and expanding column names if the original names are either ambiguous or easily misread.

Alias Names
Aliases may be single words or complete strings. If the latter is used then the string should be enclosed within quotes. This practice is legal, but is strongly discouraged.
While multiword names are indeed highly readable, they create all sorts of problems for many client applications. So much so, that one of the most common uses of aliases is to rename multiword column names to single word names (as explained above).
Aliases are also referred to as “derived columns,”
