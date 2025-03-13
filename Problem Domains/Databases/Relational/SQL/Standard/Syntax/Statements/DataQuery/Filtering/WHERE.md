WHERE: Filtering Data

The WHERE Clause informs the database how to constrain the result set  used to extract a subset of table data by specifying a predicate filter condition.

The WHERE clause is specified right after the FROM clause table name:

[SELECT clause]
[FROM clause]
WHERE [conditions];


### WHERE Clause Position
When using both ORDER BY and WHERE clauses, make sure that ORDER BY comes after the WHERE.


### Logical Operators
=, >, >=, !>, <, <=, !<, <> or !=

!= and <> can usually be used interchangeably.
However, not all DBMSs support both forms of the non-equality operator.



### When to Use Quotes
Single quotes are used to delimit a string. If you are comparing a value against a column that is a string datatype, the delimiting quotes are required.



### Combining WHERE Clauses
We can use multiple predicates in a single WHERE clause using the logical operators AND /OR



#### Order of Evaluation
SQL (like most languages) processes AND operators before OR operators.

As parentheses have a higher order of evaluation than either AND or OR operators.
Don’t ever rely on the default evaluation order, even if it is exactly what you want.
There is no downside to using parentheses, and you are always better off eliminating any ambiguity.



### NULL and Non-matches
You might expect that when you filter to select all rows that do not have a particular value, rows with a NULL will be returned.

WHERE [column_name] != some_value;

But this will not return NULL values. Because of the special meaning of unknown, the database does not know whether or not they match, and so they are not returned when filtering for matches or when filtering for non-matches.

When filtering data, make sure to verify that the rows with a NULL in the filtered column are really present in the returned data.

WHERE prod_price != some_value OR IS NULL;

For more information regarding other where operators, see:
[Databases\SQL\Standard\Syntax\Statements\DataQuery\Filtering\Operators]




### SQL Versus Application Filtering
To filter data at the application level, an SQL SELECT statement retrieves more data than is actually required for the client application, and the client code loops through the returned data to extract just the needed rows.

As a rule, this practice is strongly discouraged:
Databases are optimized to perform filtering quickly and efficiently.
Making the client application (or development language) do the database’s job will dramatically impact application performance and will create applications that cannot scale properly.
In addition, if data is filtered at the client, the server has to send unneeded data across the network connections, resulting in a waste of network bandwidth usage.
