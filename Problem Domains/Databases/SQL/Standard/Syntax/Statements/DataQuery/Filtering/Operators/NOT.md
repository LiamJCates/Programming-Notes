### NOT Operator
A keyword used in a WHERE clause to negate a condition.
Because NOT is never used by itself (it is always used in conjunction with some other operator), its syntax is a little different from all other operators and can appear before or after the column name

WHERE NOT vend_id = 'DLL01'
is equal to
WHERE vend_id <> 'DLL01'
is equal to
WHERE vend_id NOT IN ('DLL01')

NOT IN
using NOT in conjunction with an IN operator finds all rows not matching a list of criteria.

IS NOT
using NOT in conjunction with an IS operator finds all rows that do not contain NULL
