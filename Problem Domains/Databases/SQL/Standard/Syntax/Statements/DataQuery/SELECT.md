SELECT Statement

The SQL SELECT statement is used to retrieve records from one or more tables in your SQL database. The records retrieved are known as a result set.

SELECT expressions
FROM tables
[WHERE conditions]
[ORDER BY expression [ ASC | DESC ]];


To use the SELECT statement to retrieve table data you must specify at least two pieces of information:

what to select, specified by the SELECT clause
from where to select it, specified by the FROM clause



### SELECT clause
A SELECT clause is composed of the SELECT keyword and a SELECT LIST

SELECT LIST
consists of at least one column
multiple columns are comma delimited
can utilize a wildcard * to pull all columns from a table

SELECT [column1, column2, …, columnN]

column names used in a SELECT LIST require a FROM clause to be used to specify the table from which the columns originate






### FROM clause

The SQL FROM clause is used to list the tables and any joins required for the SQL statement.

FROM [table]

FROM table1
[ { INNER JOIN
  | LEFT [OUTER] JOIN
  | RIGHT [OUTER] JOIN
  | FULL [OUTER] JOIN } table2
ON table1.column1 = table2.column1 ]

For more information regarding joins, see:
[Databases\SQL\Standard\Syntax\Statements\DataQuery\JOIN.md]




#### Wildcard
When a wildcard (*) is specified after the SELECT all the columns in the table are returned.
Though wildcards may save you the effort needed to list the desired columns explicitly, retrieving unnecessary columns slows down performance
There is one big advantage to using wildcards. As you do not explicitly specify column names it is possible to retrieve columns of which the names are unknown.





SELECT Clause Ordering
SELECT > FROM > WHERE > GROUP BY > HAVING > ORDER BY

SELECT Clauses and Their Sequence
| Clause | Description | Required |
|--------|-------------|----------|
| SELECT | Columns or expressions to be returned | Yes |
| FROM | Table to retrieve data from | Only if selecting data from a table | |
| WHERE | Row-level filtering | No |
| GROUP BY | Group specification | Only if calculating aggregates by group |
| HAVING | Group-level filtering | No |
| ORDER BY | Output sort order | No |



### Best practices

Qualify column name with table name:    [table_name].[column_name]
    some DBMS will run queries with table qualified column names faster

Alias FROM clause table names
