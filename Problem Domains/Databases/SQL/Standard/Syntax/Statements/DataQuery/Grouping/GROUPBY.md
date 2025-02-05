GROUP BY

Groups are created using the GROUP BY clause in SELECT statements
Grouping lets you divide data into logical sets so that you can perform aggregate calculations on each group.

The GROUP BY clause instructs the DBMS to group the data and then perform the aggregate on each group rather than on the entire result set.

Allows multiple columns with a set function
Breaks result set into subsets
Runs set function against each subset
Result set returns 1 row per subset
Subset is dictated by column in GROUP BY
Column must appear in the SELECT LIST
Appears after FROM and/or WHERE Clauses

GROUP BY rules:
• GROUP BY clauses can contain as many columns as you want.
nested groups, provide more granular control over how data is grouped.

• If you have nested groups in your GROUP BY clause, data is summarized at the last specified group. In other words, all the columns specified are evaluated together when grouping is established (so you won’t get data back for each individual column level).

• Every column listed in GROUP BY must be a retrieved column or a valid expression (but not an aggregate function). The same expression is used in the SELECT, must be specified in GROUP BY, Aliases cannot be used.
• Aside from the aggregate calculations statements, every column in your SELECT statement must be present in the GROUP BY clause.


• Most SQL implementations do not allow GROUP BY columns with variable length datatypes (such as text or memo fields).

• If the grouping column contains a row with a NULL value, NULL will be returned as a group. If there are multiple rows with NULL values, they’ll all be grouped together.

• The GROUP BY clause must come after any WHERE clause and before any ORDER BY clause.

Some SQL implementations (such as Microsoft SQL Server) support an optional ALL clause within GROUP BY. This clause can be used to return all groups, even those that have no matching rows (in which case the aggregate would return NULL).

Specifying Columns by Relative Position
Some SQL implementations allow you to specify GROUP BY columns by the position in the SELECT list. For example, GROUP BY 2,1 can mean group by the second column selected and then by the first. Although this shorthand syntax is convenient, it is not supported by all SQL implementations. It’s use is also risky in that it is highly susceptible to the introduction of errors when editing SQL statements.
