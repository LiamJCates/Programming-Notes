HAVING

In addition to being able to group data using GROUP BY, SQL also allows you to filter which groups to include and which to exclude. To obtain this data you must filter based on the complete group, not on individual rows.

But WHERE does not work here because WHERE filters specific rows, not groups. As a matter
of fact, WHERE has no idea what a group is.

HAVING is very similar to WHERE, the only difference is that WHERE filters rows and HAVING filters
groups. All the techniques and options  used with WHERE can be applied to HAVING. The syntax is identical; just the keyword is different.

WHERE filters before data is grouped, and HAVING filters after data is grouped; rows that are eliminated by a WHERE clause will not be included in the group.

HAVING is so similar to WHERE that most DBMSs treat them as the same thing if no GROUP BY is specified. Nevertheless, you should make that distinction yourself. Use HAVING only in conjunction with GROUP BY clauses. Use WHERE for standard row level filtering.

ORDER BY Versus GROUP BY
ORDER BY            
Sorts generated output.        
Any columns (even columns not selected) may be used.
Never required.

GROUP BY
Groups rows. The output might not be in group order, however.
Only selected columns or expressions columns may be used, and every selected column expression must be used.
Required if using columns (or expressions) with aggregate functions.

As a rule, anytime you use a GROUP BY clause, you should also specify an ORDER BY clause. That is the only way to ensure that data will be sorted properly. Never rely on GROUP BY to sort your data
