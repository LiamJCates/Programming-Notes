JavaScript Assignment Operators

Assignment operators assign values to JavaScript variables.

| Name | Shorthand operator | Meaning |
|------|--------------------|---------|
| Assignment | x = y | x = y |
| Addition assignment | x += y | x = x + y |
| Subtraction assignment | x -= y | x = x - y |
| Multiplication assignment | x *= y | x = x * y |
| Division assignment | x /= y | x = x / y |
| Remainder assignment | x %= y | x = x % y |
| Exponentiation assignment | x **= y | x = x ** y |
| Left shift assignment | x <<= y | x = x << y |
| Right shift assignment | x >>= y | x = x >> y |
| Unsigned right shift assignment | x >>>= y | x = x >>> y |
| Bitwise AND assignment | x &= y | x = x & y |
| Bitwise XOR assignment | x ^= y | x = x ^ y |
| Bitwise OR assignment | x \|= y | x = x \| y |
| Logical AND assignment | x &&= y | x && (x = y) |
| Logical OR assignment | x \|\|= y | x \|\| (x = y) |
| Logical nullish assignment | x ??= y | x ?? (x = y) |




For general information related to assignment, see:
[Programming Methods\Fundamentals\Constructs\Operators\Assignment.md]

NOTE
JavaScript has an atypical logical nullish assignment operator. The logical nullish assignment (x ??= y) operator only assigns if x is nullish (null or undefined).

Return value and chaining

The assignment operation evaluates to the assigned value. Chaining the assignment operator is possible in order to assign a single value to multiple variables

The return value matches the expression to the right of the = sign in the “Meaning” column of the table above. That means that (x = y) returns y, (x += y) returns the resulting sum x + y, (x **= y) returns the resulting power x ** y, and so on.

In the case of logical assignments, (x &&= y), (x ||= y), and (x ??= y), the return value is that of the logical operation without the assignment, so x && y, x || y, and x ?? y, respectively.

Note that the return values are always based on the operands’ values before the operation.

When chaining these expressions, each assignment is evaluated right-to-left. Consider these examples:

	w = z = x = y is equivalent to w = (z = (x = y))
	or x = y; z = y; w = y

	z += x *= y is equivalent to z += (x *= y)
	or tmp = x * y; x *= y; z += tmp (except without the tmp).


Destructuring

For more complex assignments, the destructuring assignment syntax is a JavaScript expression that makes it possible to extract data from arrays or objects using a syntax that mirrors the construction of array and object literals.

	var foo = ['one', 'two', 'three'];

	// without destructuring
	var one   = foo[0];
	var two   = foo[1];
	var three = foo[2];

	// with destructuring
	var [one, two, three] = foo;
