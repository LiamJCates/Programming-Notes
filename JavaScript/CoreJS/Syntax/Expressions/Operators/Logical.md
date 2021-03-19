JavaScript Logical Operators

| Operator | Description |
|----------|-------------|
| && | logical and |
| || | logical or |
| ! | logical not |


The && and || operators use short-circuit logic, which means whether they will execute their second operand is dependent on the first. This is useful for checking for null objects before accessing their attributes:

var name = o && o.getName();

Or for caching values (when falsy values are invalid):

var name = cachedName || (cachedName = getName());
