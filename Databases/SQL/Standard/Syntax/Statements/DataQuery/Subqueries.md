Subqueries
queries that are embedded into other queries

Queries containing subqueries are always processed starting with the innermost SELECT statement, working outward.

When the SELECT statement subquery is processed, the DBMS actually performs two operations.
First it runs the subquery.
those values are then passed to the outer query

SELECT statements containing subqueries can be difficult to read and debug, especially as they grow in complexity. Breaking up the queries over multiple lines and indenting the lines appropriately  can greatly simplify working with subqueries.

There is no limit imposed on the number of subqueries that can be nested, although in practice you will find that performance will tell you when you are nesting too deeply.

Single Column Only
Subquery SELECT statements can only retrieve a single column. Attempting to retrieve
multiple columns will return an error.

The WHERE clause in a subquery is a little different from the WHERE clauses used previously.
If a table name in a subquery is the same as an outer query we must use fully qualified column names.
Instead of just a column name, fully qualified names specify [table_name].[column_name]
This syntax—the table name and the column name separated by a period—must be used whenever
there is possible ambiguity about column names.


The following WHERE clause tells SQL to compare the cust_id in the Orders table to the one currently being retrieved from the Customers table:

WHERE Orders.cust_id = Customers.cust_id

A good rule is that if you are ever working with more than one table in a SELECT statement, then use fully qualified column names to avoid any and all ambiguity.
