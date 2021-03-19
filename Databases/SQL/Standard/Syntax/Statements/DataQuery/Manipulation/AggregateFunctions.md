Summarizing Data

Aggregate Functions / Set Functions
Aggregate Functions operate on a set of rows to calculate and return a single value
Used to summarize data without actually retrieving it, saving time and application processing

Aggregate functions are used in place of columns in a SELECT clause
SELECT statements may contain as few or as many aggregate functions as needed

SQL features a set of five aggregate functions:

| Function | Description | Handles NULL |
|----------|-------------|--------------|
| AVG | returns the average value of a given column | ignores NULL |
| COUNT | returns the total number of values in a given column | ignores NULL |
| COUNT(*) | returns the number of rows in a table | processes NULL |
| MIN | returns the smallest value in a given column | ignores NULL |
| MAX | returns the largest value in a given column | ignores NULL |
| SUM | returns the sum of numeric values in a given column | ignores NULL |

AVG() determines the average of a specific numeric column name specified as the function parameter.
To obtain the average value of multiple columns, multiple AVG() functions must be used.

COUNT(), you can determine the number of rows in a table or that match a specific criterion.
Use COUNT(*) to count the number of rows in a table, including NULL values.
Use COUNT(column) to count the number of rows in a specific column, ignoring NULL values.

MIN() and MAX() typically find numeric or date values, but many DBMSs allow the return of values in any columns returning the first and last element, respectively, if the data were sorted by that column.

SUM() is used to return the sum (total) of the values in a specific column or calculated values.

All the aggregate functions can be used to perform calculations on multiple columns using the standard mathematical operators as calculated values


Aggregate Function Qualifiers

The five aggregate functions can all be used in two ways:

• To perform calculations on all rows, specify the ALL argument or specify no argument at all
(ALL is default behavior).

• To only include unique values, specify the DISTINCT argument.
DISTINCT may only be used with COUNT(column_name) not COUNT(*).
DISTINCT must be used with a column name and not with a calculation or expression.


Additional Aggregate Arguments
In addition to the DISTINCT and ALL arguments, some DBMSs support additional arguments such as

TOP and TOP PERCENT that let you perform calculations on subsets of query results. Refer to DBMS documentation.


Aggregate Function Aliases
When specifying alias names to contain the results of an aggregate function, try to not use the name of an actual column in the table. Although there is nothing illegal about doing so, many SQL implementations do not support this and will generate obscure error messages if you do so.
