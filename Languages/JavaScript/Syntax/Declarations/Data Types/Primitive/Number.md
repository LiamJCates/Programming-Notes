Number

https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Number

let n = 123;
n = 12.345;

The number type represents both integer and floating point numbers.

There are many operations for numbers, e.g. multiplication *, division /, addition +, subtraction -, and so on.

Besides regular numbers, there are so-called “special numeric values” which also belong to this data type: Infinity, -Infinity and NaN.

    Infinity represents the mathematical Infinity ∞. It is a special value that’s greater than any number.

    We can get it as a result of division by zero:

alert( 1 / 0 ); // Infinity

Or just reference it directly:

alert( Infinity ); // Infinity

NaN represents a computational error. It is a result of an incorrect or an undefined mathematical operation, for instance:

alert( "not a number" / 2 ); // NaN, such division is erroneous

NaN is sticky. Any further mathematical operation on NaN returns NaN:

    alert( NaN + 1 ); // NaN
    alert( 3 * NaN ); // NaN
    alert( "not a number" / 2 - 1 ); // NaN

    So, if there’s a NaN somewhere in a mathematical expression, it propagates to the whole result (there’s only one exception to that: NaN ** 0 is 1).

Mathematical operations are safe

Doing maths is “safe” in JavaScript. We can do anything: divide by zero, treat non-numeric strings as numbers, etc.

The script will never stop with a fatal error (“die”). At worst, we’ll get NaN as the result.

Special numeric values formally belong to the “number” type. Of course they are not numbers in the common sense of this word.