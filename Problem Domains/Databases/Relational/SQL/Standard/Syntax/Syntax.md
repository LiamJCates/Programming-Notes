SQL Syntax

## Language Elements
The SQL language is subdivided into several language elements, including:

### Statements
A SQL Statement is a valid SQL instruction that tells a database what you want it to do

#### Queries
retrieve data based on specific criteria.

#### Clauses
constituent components of statements and queries.


#### Expressions
a combination of one or more values, operators and SQL functions that evaluate to produce either scalar values, or tables consisting of columns and rows of data

#### Predicates
specify conditions that can be evaluated to SQL three-valued logic (3VL) (true/false/unknown) or Boolean truth values and are used to limit the effects of statements and queries, or to change program flow.





### Tokens

#### Keywords

SQL statements are made up of one or more plain English terms, called keywords
Keywords are defined in the SQL specification

Keywords are reserved words that are part of the SQL language.

#### Identifiers
SQL identifiers are the names given to database objects
Never use a keyword as an identifier

#### Whitespace
Insignificant whitespace is generally ignored during the processing of SQL statements and queries, making it easier to format SQL code for readability.
Most SQL developers find that breaking up statements over multiple lines makes them easier to read and debug.




### Case Sensitivity
SQL statements are case-insensitive
By convention
keywords are typically specified using capital letters,
identifiers are expressed in lower case with dashes for spaces

Many SQL developers find that using uppercase for all SQL keywords and lowercase for column and table names makes code easier to read and debug.

while the SQL language is case-insensitive, the names of tables, columns, and values may not be (that depends on your DBMS and how it is configured).
