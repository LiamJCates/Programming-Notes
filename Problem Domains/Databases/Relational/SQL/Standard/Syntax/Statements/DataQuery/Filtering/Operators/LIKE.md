### LIKE Operator
LIKE instructs the DBMS that the following search pattern is to be compared using a wildcard match rather than a straight equality match.

A Search pattern is a search condition made up of literal text and wildcard characters.

### Wildcard Filtering
Wildcard searching can only be used with text fields (strings), you can’t use wildcards to search fields of non-text datatypes.

Wildcards are special characters used to create search patterns that match parts of a value.

The wildcards are actually characters that have special meanings within SQL WHERE clauses

To use wildcards in search clauses, the LIKE operator must be used.

The Percent Sign (%) Wildcard
Within a search string, % means, match any number of occurrences of any character.

The example "WHERE [column_name] LIKE 'F%k';
" finds all products that begin with F and end with k.

Note: Case-Sensitivity
Depending on our DBMS and how it is configured, searches may be case-sensitive


In addition to matching one or more characters, % also matches zero characters.
% represents zero, one, or more characters at the specified location in the search pattern.

Note: Watch for Trailing Spaces
Many DBMSs pad field contents with spaces.
For example, if a column expects 50 characters and the text stored is 17 characters, 33 spaces may be appended to the text so as to fully fill the column.

While this usually has no real impact on data and how it is used, the clause WHERE prod_name LIKE 'F%k' will only match prod_name if it starts with F and ends with k, and if the value is padded with spaces then it will not end with k.
One simple solution to this problem is to append a second % to the search pattern, 'F%k%' will also match characters (or spaces) after the k.

Caution: Watch for NULL
it may seem that the % wildcard matches anything, there is one exception, NULL.
WHERE prod_name LIKE '%' would not match a row with the value NULL as the product name.

The Underscore (_) Wildcard
Another useful wildcard is the underscore (_). The underscore is used just like %, but instead of
matching multiple characters the underscore matches just a single character.
Instead of _ some DBs use ?

Unlike % which can match 0 characters, _ always matches 1 character.

The Brackets ([]) Wildcard
The brackets ([]) wildcard is used to specify a set of characters, any one of which must match a
character in the specified position (the location of the wildcard).

Note: Sets Are Not Commonly Supported
Unlike the wildcards describes thus far, the use of [] to create sets is not supported by all DBMSs

For example, to find all contacts whose names begin with the letters J or M:
WHERE cust_contact LIKE '[JM]%'

A set can be negated by prefixing the characters with ^ (the carat character).

Note: Negating Sets in Microsoft Access
If using Microsoft Access use ! instead of ^ to negate a set, so [!JM] instead of [^JM].

You can accomplish the same result using the NOT operator.
The advantage of ^ is that it can simplify the syntax if you are using multiple WHERE clauses

As you can see, SQL’s wildcards are extremely powerful, however Wildcard searches typically take far longer to process than any other search types discussed previously.

Here are some rules to keep in mind when using wildcards:
• Don’t overuse wildcards. If another search operator will do, use it instead.
• When you do use wildcards, try to not use them at the beginning of the search pattern unless
absolutely necessary. Search patterns that begin with wildcards are the slowest to process.
• Pay careful attention to the placement of the wildcard symbols. If they are misplaced, you might not return the data you intended.
