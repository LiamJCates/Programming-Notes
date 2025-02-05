Calculated Fields


Calculated fields don’t actually exist in database tables. Rather, a calculated field is created on-the fly within a SQL SELECT statement. Only the database knows which columns in a SELECT statement are actual table columns and which are calculated fields.

Field
Essentially means the same thing as column and often used interchangeably, although database columns are typically called columns and the term fields is usually used in conjunction with calculated fields.



### Arithmetic Calculation
A frequent use for calculated fields is performing mathematical calculations on retrieved data.

To expand the item price (item price multiplied by quantity ordered), you simply do the following:

SELECT prod_id, quantity, item_price, quantity*item_price AS expanded_price
FROM OrderItems
WHERE order_num = 20008;

EX
prod_id     quantity     item_price     expanded_price
----------     -----------     ------------     -----------------
RGAN01         5         4.9900         24.9500...

Mathematical Operators:
\+ Addition,
\- Subtraction,
\* Multiplication,
\/ Division





### Concatenate
Joining values together by appending them to each other to form a single long value.

In MySQL SELECT statements, you can concatenate columns using a special function
CONCAT(expression1, expression2, expression3,...)

SELECT CONCAT(vend_name, '(', vend_country, ')')
FROM Vendors
ORDER BY vend_name;



### Trim
Many databases (although not all) save text values padded to the column width.
The RTRIM() function trims all space from the right of a value.

SELECT RTRIM(CONCAT(vend_name, '(', vend_country, ')'))

Note: The TRIM Functions
Most DBMSs support RTRIM(), as well as LTRIM() which trims the left side of a string, and TRIM() which trims both the right and left.
