## Boolean Types

The keyword bool specifies data object of logical (Boolean) values.

Boolean types have two states represented by the keywords true and false.

The central purpose of this data type is to manipulate logical (Boolean) expressions.

In addition, Integer types and the bool types convert readily:
	the true state converts to an integer value of 1
	the false state converts to an integer value of 0
	Any non-zero integer converts to true, and integer 0 converts to false.

Earlier versions of C++ did not provide built-in data types that had logical (or Boolean) values true and false. Because logical expressions evaluate to either 1 or 0, the value of a logical expression was stored in a variable of the data type int. Therefore, legacy code will use the int data type to manipulate logical (Boolean) expressions.
