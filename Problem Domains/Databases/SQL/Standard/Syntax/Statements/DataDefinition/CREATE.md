CREATE clauses



CREATE DATABASE

The CREATE DATABASE statement is used to create a new SQL database.

Syntax
CREATE DATABASE database_name;


Not part of the SQL Standard but part of all popular implementations




USE DATABASE

Syntax
USE DATABASE db_name

Used to scope future queries,
all queries that occur after a USE DATABASE statement will reference that chosen db


Commands may instead fully qualify database objects with their table name
    This is best practice and can result in efficiency gains in some implementations





CREATE TABLE

The CREATE TABLE statement is used to create a new table in a database.

Syntax
CREATE TABLE table_name (
    column1 datatype,
    column2 datatype,
    column3 datatype,
   ....
);

The column parameters specify the names of the columns of the table.

The datatype parameter specifies the type of data the column can hold (e.g. varchar, integer, date, etc.).

Tip: For an overview of the available data types, go to our complete Data Types Reference.





Create Table Using Another Table

A copy of an existing table can also be created using CREATE TABLE.

The new table gets the same column definitions. All columns or specific columns can be selected.

If you create a new table using an existing table, the new table will be filled with the existing values from the old table.
Syntax
CREATE TABLE new_table_name AS
    SELECT column1, column2,...
    FROM existing_table_name
    WHERE ....;
