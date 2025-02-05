Data Manipulation Functions

Functions are operations that are usually performed on data, usually to facilitate conversion and manipulation.

Unlike SQL statements (for example, SELECT), which for the most part are supported by all DBMSs
equally, functions tend to be very DBMS specific.
Although all types of functionality are usually available in each DBMS, the function name or syntax can differ greatly.



Unlike SQL statements, SQL functions are not portable

Portable
Code that is written so that it will run on multiple systems.
SQL programmers may opt not to use any implementation-specific features for code portability

Opting not to use any implementation-specific features is a trade off between code portability and application performance. If you do decide to use functions, make sure you comment your code well, so that at a later date you (or another developer) will know exactly what SQL implementation you were writing to.

Most SQL implementations support the following types of functions:
• Text functions manipulate text strings
(For example, trimming, padding values, and converting to upper or lowercase).
• Numeric functions are used to perform mathematical operations on numeric data
(for example, returning absolute numbers and performing algebraic calculations).
• Date and time functions manipulate date and time values or extract there components
(for example, returning differences between dates, and checking date validity).
• System functions return information specific to the DBMS being used
(for example, returning user login information).

https://www.w3schools.com/Sql/sql_ref_mysql.asp 
