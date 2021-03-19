## Equality comparisons and sameness

There are four equality algorithms in ES2015:

    Abstract Equality Comparison (==)
    Strict Equality Comparison (===) used by:
			Array.prototype.indexOf
			Array.prototype.lastIndexOf
			case-matching
    SameValueZero used by:
			%TypedArray% and ArrayBuffer constructors
			Map and Set operations
			String.prototype.includes
			Array.prototype.includes since ES2016
    SameValue used in all other places

JavaScript provides three different value-comparison operations:

    === - Strict Equality Comparison
			("strict equality", "identity", "triple equals")
    == - Abstract Equality Comparison
			("loose equality", "double equals")
    Object.is
			(provides SameValue new in ES2015)

Which operation you choose depends on what sort of comparison you are looking to perform.

Briefly:
  double equals (==) will perform a type conversion when comparing two things, and will handle NaN, -0, and +0 specially to conform to IEEE 754 (so NaN != NaN, and -0 == +0);
  triple equals (===) will do the same comparison as double equals (including the special handling for NaN, -0, and +0) but without type conversion; if the types differ, false is returned.
  Object.is does no type conversion and no special handling for NaN, -0, and +0 (giving it the same behavior as === except on those special numeric values).

Note that the distinction between these all have to do with their handling of primitives; none of them compares whether the parameters are conceptually similar in structure. For any non-primitive objects x and y which have the same structure but are distinct objects themselves, all of the above forms will evaluate to false.



### Strict equality using ===

Strict equality compares two values for equality. Neither value is implicitly converted to some other value before being compared. If the values have different types, the values are considered unequal. If the values have the same type, are not numbers, and have the same value, they're considered equal. Finally, if both values are numbers, they're considered equal if they're both not NaN and are the same value, or if one is +0 and one is -0.

	var num = 0;
	var obj = new String('0');
	var str = '0';

	console.log(num === num); // true
	console.log(obj === obj); // true
	console.log(str === str); // true

	console.log(num === obj); // false
	console.log(num === str); // false
	console.log(obj === str); // false
	console.log(null === undefined); // false
	console.log(obj === null); // false
	console.log(obj === undefined); // false

Strict equality is almost always the correct comparison operation to use. For all values except numbers, it uses the obvious semantics: a value is only equal to itself. For numbers it uses slightly different semantics to gloss over two different edge cases. The first is that floating point zero is either positively or negatively signed. This is useful in representing certain mathematical solutions, but as most situations don't care about the difference between +0 and -0, strict equality treats them as the same value. The second is that floating point includes the concept of a not-a-number value, NaN, to represent the solution to certain ill-defined mathematical problems: negative infinity added to positive infinity, for example. Strict equality treats NaN as unequal to every other value -- including itself. (The only case in which (x !== x) is true is when x is NaN.)



### Loose equality using ==

Loose equality compares two values for equality, after converting both values to a common type. After conversions (one or both sides may undergo conversions), the final equality comparison is performed exactly as === performs it. Loose equality is symmetric: A == B always has identical semantics to B == A for any values of A and B (except for the order of applied conversions).

The equality comparison OperandA == OperandB is performed as follows for various types with the type of OperandB specified by the top row and :

| | Undefined | Null | Number | String | Boolean | Object |
|-|-----------|------|--------|--------|---------|--------|
| Undefined | true | true | false | false | false | false |
| Null | true | true | false | false | false | false |
| Number | false | false | A === B | A === ToNumber(B) | A === ToNumber(B) | A == ToPrimitive(B) |
| String | false | false | ToNumber(A) === B | A === B | ToNumber(A) === ToNumber(B) | A == ToPrimitive(B) |
| Boolean | false | false | ToNumber(A) === B | ToNumber(A) === ToNumber(B) | A === B | ToNumber(A) == ToPrimitive(B) |
| Object | false | false | ToPrimitive(A) == B | ToPrimitive(A) == B | ToPrimitive(A) == ToNumber(B) | A === B |

In the above table, ToNumber(A) attempts to convert its argument to a number before comparison. Its behavior is equivalent to +A (the unary + operator). ToPrimitive(A) attempts to convert its object argument to a primitive value, by attempting to invoke varying sequences of A.toString and A.valueOf methods on A.

Traditionally, and according to ECMAScript, all objects are loosely unequal to undefined and null. But most browsers permit a very narrow class of objects (specifically, the document.all object for any page), in some contexts, to act as if they emulate the value undefined. Loose equality is one such context: null == A and undefined == A evaluate to true if, and only if, A is an object that emulates undefined. In all other cases an object is never loosely equal to undefined or null.

	var num = 0;
	var obj = new String('0');
	var str = '0';

	console.log(num == num); // true
	console.log(obj == obj); // true
	console.log(str == str); // true

	console.log(num == obj); // true
	console.log(num == str); // true
	console.log(obj == str); // true
	console.log(null == undefined); // true

	// both false, except in rare cases
	console.log(obj == null);
	console.log(obj == undefined);

In most cases, using loose equality is discouraged. The result of a comparison using strict equality is easier to predict, and may evaluate more quickly due to the lack of type coercion.
Same-value equality

Same-value equality addresses a final use case: determining whether two values are functionally identical in all contexts. (This use case demonstrates an instance of the Liskov substitution principle.) One instance occurs when an attempt is made to mutate an immutable property:

	// Add an immutable NEGATIVE_ZERO property to the Number constructor.
	Object.defineProperty(Number, 'NEGATIVE_ZERO',
	                      { value: -0, writable: false, configurable: false, enumerable: false });

	function attemptMutation(v) {
	  Object.defineProperty(Number, 'NEGATIVE_ZERO', { value: v });
	}

Object.defineProperty will throw an exception when attempting to change an immutable property, but it does nothing if no actual change is requested. If v is -0, no change has been requested, and no error will be thrown. Internally, when an immutable property is redefined, the newly-specified value is compared against the current value using same-value equality.

Same-value equality is provided by the Object.is method.



### Same-value-zero equality

Similar to same-value equality, but +0 and -0 are considered equal.



### Abstract equality, strict equality, and same value in the specification

In ES5, the comparison performed by == is described in Section 11.9.3, The Abstract Equality Algorithm. The === comparison is 11.9.6, The Strict Equality Algorithm. (Go look at these. They're brief and readable. Hint: read the strict equality algorithm first.) ES5 also describes, in Section 9.12, The SameValue Algorithm for use internally by the JS engine. It's largely the same as the Strict Equality Algorithm, except that 11.9.6.4 and 9.12.4 differ in handling Numbers. ES2015 proposes to expose this algorithm through Object.is.

We can see that with double and triple equals, with the exception of doing a type check upfront in 11.9.6.1, the Strict Equality Algorithm is a subset of the Abstract Equality Algorithm, because 11.9.6.2–7 correspond to 11.9.3.1.a–f.



### A model for understanding equality comparisons?

Prior to ES2015, you might have said of double equals and triple equals that one is an "enhanced" version of the other. For example, someone might say that double equals is an extended version of triple equals, because the former does everything that the latter does, but with type conversion on its operands. E.g., 6 == "6". (Alternatively, someone might say that double equals is the baseline, and triple equals is an enhanced version, because it requires the two operands to be the same type, so it adds an extra constraint. Which one is the better model for understanding depends on how you choose to view things.)

However, this way of thinking about the built-in sameness operators is not a model that can be stretched to allow a place for ES2015's Object.is on this "spectrum". Object.is isn't "looser" than double equals or "stricter" than triple equals, nor does it fit somewhere in between (i.e., being both stricter than double equals, but looser than triple equals). We can see from the sameness comparisons table below that this is due to the way that Object.is handles NaN. Notice that if Object.is(NaN, NaN) evaluated to false, we could say that it fits on the loose/strict spectrum as an even stricter form of triple equals, one that distinguishes between -0 and +0. The NaN handling means this is untrue, however. Unfortunately, Object.is has to be thought of in terms of its specific characteristics, rather than its looseness or strictness with regard to the equality operators.

Sameness Comparisons

| x | y | == | === | Object.is | SameValueZero |
|---|---|----|-----|-----------|---------------|
| undefined | undefined | true | true | true | true |
| null | null | true | true | true | true |
| true | true | true | true | true | true |
| false | false | true | true | true | true |
| 'foo' | 'foo' | true | true | true | true |
| 0 | 0 | true | true | true | true |
| +0 | -0 | true | true | false | true |
| +0 | 0 | true | true | true | true |
| -0 | 0 | true | true | false | true |
| 0n | -0n | true | true | true | true |
| 0 | false | true | false | false | false |
| "" | false | true | false | false | false |
| "" | 0 | true | false | false | false |
| '0' | 0 | true | false | false | false |
| '17' | 17 | true | false | false | false |
| [1, 2] | '1,2' | true | false | false | false |
| new String('foo') | 'foo' | true | false | false | false |
| null | undefined | true | false | false | false |
| null | false | false | false | false | false |
| undefined | false | false | false | false | false |
| { foo: 'bar' } | { foo: 'bar' } | false | false | false | false |
| new String('foo') | new String('foo') | false | false | false | false |
| 0 | null | false | false | false | false |
| 0 | NaN | false | false | false | false |
| 'foo' | NaN | false | false | false | false |
| NaN | NaN | false | false | true | true |



### When to use Object.is versus triple equals

In general, the only time Object.is's special behavior towards zeros is likely to be of interest is in the pursuit of certain meta-programming schemes, especially regarding property descriptors, when it is desirable for your work to mirror some of the characteristics of Object.defineProperty. If your use case does not require this, it is suggested to avoid Object.is and use === instead. Even if your requirements involve having comparisons between two NaN values evaluate to true, generally it is easier to special-case the NaN checks (using the isNaN method available from previous versions of ECMAScript) than it is to work out how surrounding computations might affect the sign of any zeros you encounter in your comparison.

Here's a non-exhaustive list of built-in methods and operators that might cause a distinction between -0 and +0 to manifest itself in your code:

- (unary negation)

    let stoppingForce = obj.mass * -obj.velocity;

If obj.velocity is 0 (or computes to 0), a -0 is introduced at that place and propagates out into stoppingForce.

Math.atan2
Math.ceil
Math.pow
Math.round
In some cases,it's possible for a -0 to be introduced into an expression as a return value of these methods even when no -0 exists as one of the parameters. For example, using Math.pow to raise -Infinity to the power of any negative, odd exponent evaluates to -0. Refer to the documentation for the individual methods.

Math.floor
Math.max
Math.min
Math.sin
Math.sqrt
Math.tan
It's possible to get a -0 return value out of these methods in some cases where a -0 exists as one of the parameters. E.g., Math.min(-0, +0) evaluates to -0. Refer to the documentation for the individual methods.

\~
\<\<
\>\>
Each of these operators uses the ToInt32 algorithm internally. Since there is only one representation for 0 in the internal 32-bit integer type, -0 will not survive a round trip after an inverse operation. E.g., both Object.is(\~~(-0), -0) and Object.is(-0 << 2 >> 2, -0) evaluate to false.

Relying on Object.is when the signedness of zeros is not taken into account can be hazardous. Of course, when the intent is to distinguish between -0 and +0, it does exactly what's desired.


### Caveat: Object.is and NaN

The Object.is specification treats all instances of NaN as the same object. However, since typed arrays are available, we can have distinct instances, which don't behave identically in all contexts. For example:

	var f2b = x => new Uint8Array(new Float64Array([x]).buffer);
	var b2f = x => new Float64Array(x.buffer)[0];
	var n = f2b(NaN);
	n[0] = 1;
	var nan2 = b2f(n);
	nan2;
	// > NaN
	Object.is(nan2, NaN);
	// > true
	f2b(NaN);
	// > Uint8Array(8) [0, 0, 0, 0, 0, 0, 248,127)
	f2b(nan2);
	// > Uint8Array(8) [1, 0, 0, 0, 0, 0, 248,127)
