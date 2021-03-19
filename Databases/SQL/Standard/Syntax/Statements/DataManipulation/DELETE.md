DELETE

The DELETE statement is used to delete on or more existing records in a table.

DELETE Syntax
DELETE FROM table_name WHERE condition;

Delete All Records

It is possible to delete all rows in a table without deleting the table. This means that the table structure, attributes, and indexes will be intact:
DELETE FROM table_name;
