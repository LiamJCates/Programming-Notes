#### LIMIT
LIMIT specifies the number of rows to return.
LIMIT with an OFFSET specifies where to start from

SELECT [column_name] FROM [Table_name] LIMIT n [OFFSET n];


LIMIT n        			//Returns the first N rows
LIMIT n OFFSET n    //To get the next N rows, specify start exclusive and number of rows to retrieve


Caution: Row 0
The first row retrieved is row 0, not row 1. As such, LIMIT 1 OFFSET 1 will retrieve the second row, not the first one.

Tip: MySQL and MariaDB Shortcut
MySQL and MariaDB support a shorthand version of LIMIT n OFFSET n, combine them as LIMIT n, n.
