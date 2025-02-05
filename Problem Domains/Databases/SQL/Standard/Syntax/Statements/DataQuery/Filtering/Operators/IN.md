### IN Operator
The IN operator is used to specify a collection to be matched.
IN takes a comma-delimited value list, enclosed within parentheses.

A single IN operator accomplishes the same goal as multiple OR operators

	WHERE vend_id IN ('DLL01','BRS01')
	WHERE vend_id = 'DLL01' OR vend_id = 'BRS01'


The above WHERE clauses are equivalent

The advantages are
• When you are working with long lists of valid options, the IN operator syntax is far cleaner and easier to read.
• The order of evaluation is easier to manage when IN is used in conjunction with other AND and OR operators.
• IN operators almost always execute more quickly than lists of OR operators (although you’ll not see any performance difference with very short lists like the ones we’re using here).
• The biggest advantage of IN is that the IN operator can contain another SELECT statement, enabling you to build highly dynamic WHERE clauses.
