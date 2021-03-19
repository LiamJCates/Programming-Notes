ALTER TABLE

The ALTER TABLE statement is used to add, delete, or modify columns in an existing table.
as well as add and drop various constraints on an existing table.


ALTER TABLE - ADD Column
ALTER TABLE table_name ADD column_name datatype;

ALTER TABLE - DROP COLUMN
ALTER TABLE table_name DROP COLUMN column_name;


ALTER TABLE - ALTER/MODIFY COLUMN
To change the data type of a column in a table, use the following syntax:

ALTER TABLE table_name MODIFY COLUMN column_name new_datatype;
