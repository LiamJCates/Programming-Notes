INSERT

The INSERT INTO statement is used to insert new records in a table.

INSERT INTO Syntax

It is possible to write the INSERT INTO statement in two ways.

The first way specifies both the column names and the values to be inserted:

INSERT INTO table_name (column1, column2, column3, ...)
VALUES (value1, value2, value3, ...);

If you are adding values for all the columns of the table, you do not need to specify the column names in the SQL query. However, make sure the order of the values is in the same order as the columns in the
table.

The INSERT INTO syntax would be as follows:

INSERT INTO table_name
VALUES (value1, value2, value3, ...);


Only one table is allowed in the INSERT clause
an INSERT must update all required columns
A column might not be required or might have a default value
The number of columns and values must be equal
The order of columns need not match the underlying database


BULK INSERT
While only a single table and set of columns can be referenced, multiple rows may be included in values
Each new row is enclosed by a set of parens and comma delimited

INSERT INTO table_name VALUES
(valueA1, valueA2, valueA3, ...),
(valueB1, valueB2, valueB3, ...),
...
(value1, value2, value3, ...);
