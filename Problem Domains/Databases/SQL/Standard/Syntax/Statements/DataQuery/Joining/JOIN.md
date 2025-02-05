Joining Tables

One of SQL’s most powerful features is the capability to join tables within data retrieval queries.

The key here is that having multiple occurrences of the same data is never a good thing, and that principle is the basis for relational database design. Relational tables are designed so that information is split into multiple tables, one for each data type. The tables are related to each other through common values (and thus the relational in relational design).

The bottom line is that relational data can be stored efficiently and manipulated easily. Because of this, relational databases scale far better than non-relational databases.
To Scale well indicates ability to handle an increasing load without failing.
A well-designed database or application is said to scale well.

The primary key is a value or set of values used to uniquely identify each row of a table

If data is stored in multiple tables, how can you retrieve that data with a single SELECT statement?
The answer is to use a join. Simply put, a join is a mechanism used to associate,or join, tables within a SELECT statement (and thus the name join). By using a special syntax, you can join multiple tables so that a single set of output is returned, and the join associates the correct rows in each table


Understand that a join is not a physical entity; in other words, it does not exist in the actual database tables. A join is created by the DBMS as needed, and it persists for the duration of the query execution.


Cross Join / Cartesian Product


The SELECT clause specifies data in the return set
The FROM clause specifies all the tables to be included

SELECT [coulmns...]
FROM [table_name1], [table_name2];

When tables are joined in a SELECT statement, that relationship is constructed on the fly.
When you join two tables, what you are actually doing is pairing every row in the first table with every row in the second table.
The number of rows retrieved will be the number of rows in the first table multiplied by the number of rows in the second table.
every row in the first table will be paired with every row in the second table, regardless of whether they logically go together or not.
This is known as the cartesian product of the two tables.

Tip: Cross Joins
Sometimes you’ll hear the type of join that returns a Cartesian Product referred to as a cross join.


The cartesian product results from a table relationship without a join condition.
There is nothing in the database table definitions that can instruct the DBMS how to join the tables.
You have to do that yourself with a WHERE clause.




Inner Join

Emphasizes relational nature of databases by matching the column value in one table to the column value in another table.

The relation of a primary key to that of a foreign key is most common

A WHERE clause specifies how the tables of the FROM clause are related to each other.
The WHERE clause must use fully qualified names as tables are joined on columns of the same type.
The WHERE clause acts as a filter to only include rows that match the specified filter condition—
called the join condition

SELECT [coulmns...]
FROM [table_name1], [table_name2]
WHERE table1.column = table2.column;


This join is called an equijoin—a join based on the testing of equality between two tables. This kind of join is also called an innerjoin. In fact, you may use a slightly different syntax for these joins, specifying the type of join explicitly.

SELECT [coulmns...]
FROM [table_name1]
INNER JOIN [table_name2] ON table1.column = table2.column

Per the ANSI SQL specification, use of the INNER JOIN syntax is preferred over the simple equijoins syntax used previously.


Creating Advanced Joins


Joining Multiple Tables
SQL imposes no limit to the number of tables that may be joined in a SELECT statement. The basic rules for creating the join remain the same. First, list all the tables, and then define the relationship between each.

SELECT [coulmns...]
FROM [table_name1], [table_name2], [table_name3]
WHERE table1.column = table2.column
    AND table2.column = table3.column

Performance Considerations
DBMSs process joins at runtime relating each table as specified.
This process can become very resource intensive, so be careful not to join tables unnecessarily. The more tables you join, the more performance will degrade.


Using Table Aliases
In addition to using aliases for column names and calculated fields, SQL enables you to alias table names.

There are two primary reasons to do this:
To shorten the SQL syntax
To enable multiple uses of the same table within a single SELECT statement.

It is also worth noting that table aliases are only used during query execution.
Unlike column aliases, table aliases are never returned to the client.




Aggregate or Set Functions can also be used to summarize joined data
Using Different Join Types

Self Joins
One of the primary reasons to use table aliases is to be able to refer to the same table more than once in a single SELECT statement.

SELECT [t1.columns]
FROM table AS t1, table AS t2
WHERE t1.column = t2.column AND t2.column = value;

SELECT [column1] [column2] [column3]
FROM [table1]
WHERE column = (SELECT [column1]
FROM [table1]
WHERE column = value)

Tip:Self Joins Instead of Subqueries
Self joins are often used to replace statements using subqueries that retrieve data from the same table as the outer statement. Although the end result is the same, many DBMSs process joins far more quickly than they do subqueries. It is usually worth experimenting with both to determine which performs better.



Natural Joins
Whenever tables are joined, at least one column will appear in more than one table (the columns being used to create the join). Standard joins (the inner joins) return all data, even multiple occurrences of the same column. A natural join simply eliminates those multiple occurrences so that only one of each column is returned.
Outer Joins

Most joins relate rows in one table with rows in another.
But occasionally, you want to include rows that have no related rows.
Outer joins deal with Null values


FULL OUTER JOIN
The FULL OUTER JOIN returns all records with a match in left (table1) or right (table2) table records.
all rows in the left table
all rows in the right table
and all matching rows in both tables.

Tip: FULL OUTER JOIN and FULL JOIN are the same.
Note: FULL OUTER JOIN can potentially return very large result-sets!


FULL OUTER JOIN Syntax

SELECT column_name(s)
FROM table1
FULL OUTER JOIN table2
ON table1.column_name = table2.column_name
WHERE condition;


LEFT JOIN
LEFT JOIN returns all records from the left table (table1), and the matched records from the right table (table2). The result is NULL from the right side, if there is no match.

LEFT JOIN Syntax
SELECT column_name(s)
FROM table1
LEFT JOIN table2
ON table1.column_name = table2.column_name;

Note: In some databases LEFT JOIN is called LEFT OUTER JOIN.


RIGHT JOIN

The RIGHT JOIN keyword returns all records from the right table (table2), and the matched records from the left table (table1). The result is NULL from the left side, when there is no match.

RIGHT JOIN Syntax
SELECT column_name(s)
FROM table1
RIGHT JOIN table2
ON table1.column_name = table2.column_name;

Note: In some databases RIGHT JOIN is called RIGHT OUTER JOIN.




The only difference between right and left outer joins is the order of the tables that they are relating.
In other words, a left outer join can be turned into a right outer join simply by reversing the order of the tables in the FROM or WHERE clause. As such, the two types of outer join can be used interchangeably, and the decision about which one is used is based purely on convenience.
