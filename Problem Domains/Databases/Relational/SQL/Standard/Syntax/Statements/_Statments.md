
### Statements

A statement is a complete "something" that a database engine can understand and produce a result set for.

Statements may have a persistent effect on schemata and data, or may control transactions, program flow, connections, sessions, or diagnostics.

#### Terminator

SQL statements also include the semicolon ";" statement terminator.
Most DBMSs do not require that a semicolon be specified after single statements
Multiple SQL statements must be separated by semicolons
Though not required on every platform, the semicolon statement terminator is defined as a standard part of the SQL grammar.


#### SQL Is Case-Insensitive

SQL statements are case-insensitive
by convention
  
  keywords are typically specified using capital letters,
  identifiers are expressed in lower case with dashes for spaces

Many SQL developers find that using uppercase for all SQL keywords and lowercase for column and table names makes code easier to read and debug.

while the SQL language is case-insensitive, the names of tables, columns, and values may not be (that depends on your DBMS and how it is configured).

It was originally meant for readability. Before, SQL was written in plain-text editors (no syntax/code highlighting) and keywords needed to be differentiated for better readability and maintenance.

```sql
SELECT column_name
FROM table_name
WHERE column_name = column_value
```

vs

```sql
select column_name from table_name where column_name = column_value
```

The first word in each line told the reader exactly what was going on (selecting something from somewhere where something).

But now with syntax-highlighting, there's really no point. But it IS a best practice and allows SQL developers to be on the same page/style while developing.



Every SQL statement can be broken down into individual tokens called keywords and identifiers

SQL statements are categorized into five different types of statements:

	DDL (DATA DEFINITION LANGUAGE)
	DML (DATA MANIPULATION LANGUAGE)
  DQL (DATA QUERY LANGUAGE)  
  DCL (DATA CONTROL LANGUAGE)
  TCL (TRANSACTION CONTROL LANGUAGE)
