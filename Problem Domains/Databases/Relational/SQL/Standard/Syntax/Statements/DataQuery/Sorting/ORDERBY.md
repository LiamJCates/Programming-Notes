#### ORDER BY clause
To explicitly sort data retrieved using a SELECT statement, the ORDER BY clause is used.
ORDER BY clause takes a comma delimited list of pairs composed of an expression and a sort order


	[SELECT clause]
	[FROM clause]
	[...]
	ORDER BY expression [ ASC | DESC ], ...;



##### Position of ORDER BY Clause
Be sure that an ORDER BY clause is the last SELECT statement clause or an error will be generated.

It is important to understand that when you are sorting by multiple columns, the sort sequence is exactly as specified. Result sets will be sorted by the first column specified, then tuples with equal values in each column are further sorted by each preceding column.



##### Relative Position
ORDER BY also supports ordering specified by relative column position

	ORDER BY 2, 3

sorts by the second and third column specified in the SELECT statement

The primary advantage of this technique is that it saves retyping column names.

But there are some downsides:
	Not explicitly listing column names increases the likelihood of you mistakenly specifying the wrong column.
	It is all too easy to mistakenly reorder data when making changes to the SELECT list (forgetting to make the corresponding changes to the ORDER BY clause).
	You cannot use this technique when sorting by columns that are not in the SELECT list.



##### Sorting by Nonselected Columns
It is perfectly legal to sort data by a column that is not retrieved.
you can mix and match actual column names and relative column positions in a single statement if needed.



##### Specifying Order
Ascending order is the default sort order (from A to Z, 1 to N)
To explicitly specify ascending sort order the keyword ASC can be specified.
ASC is short for ASCENDING, both keywords may be used.

Data sorting is not limited to ascending sort orders
To sort by descending order (from Z to A, N to 1), the keyword DESC can be specified.
DESC is short for DESCENDING, and both keywords may be used.


Ordering can be applied to multiple columns
In these cases multiple orderings can be specified

The DESC or ASC keyword only applies to the column name that directly precedes it, be sure each column has its own ordering keyword.

In practice, however, ASC is not usually used because ascending order is the default sequence (and is
assumed if neither ASC nor DESC are specified).

Tip: Case-Sensitivity and Sort Orders
In dictionary sort order, A is treated the same as a, and that is the default behavior for most Database Management Systems.  However, most good DBMSs enable database administrators to change this behavior if needed.
(If your database contains lots of foreign language characters, this might become necessary.)
The key here is that, if you do need an alternate sort order, you may not be able to accomplish this with a simple ORDER BY clause. You may need to contact your database administrator.
