### IS Operator
The WHERE clause uses IS to check for columns with NULL values

When a column contains no value, it is said to be the value NULL.
as opposed to a field containing 0, or an empty string, or just spaces.

To determine if a value is NULL, you cannot simply check to see if = NULL.

IS NULL clause

SELECT [column_name] FROM [table_name] WHERE [column_name] IS NULL;
