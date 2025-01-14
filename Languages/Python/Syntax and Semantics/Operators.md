# Operators

Python implements seven basic binary arithmetic operators, two of which can double as unary operators.

Arithmetic Operations

| Operator | Name | Description |
| -------- | ---- | ----------- |
| a + b | Addition | Sum of a and b |
| a - b | Subtraction | Difference of a and b |
| a * b | Multiplication | Product of a and b |
| a / b | True division | Quotient of a and b |
| a // b | Floor division | Quotient of a and b, removing fractional parts (Python 3) |
| a % b | Modulus | Remainder after division of a by b |
| a ** b | Exponentiation | a raised to the power of b |
| a @ b | Matrix product | Product of matrices a and b (Python 3.5) |
| -a | Negation | The negative of a |
| +a | Unary plus | a unchanged (rarely used) |

These operators can be used and combined in intuitive ways, using
standard parentheses to group operations.

The floor division operator was added in Python 3; you should be
aware if working in Python 2 that the standard division operator (/)
acts like floor division for integers and like true division for floating-
point numbers.

Bitwise Operations

| Operator | Name | Description |
| -------- | ---- | ----------- |
| a & b | Bitwise AND | Bits defined in both a and b |
| a | b | Bitwise OR | Bits defined in a or b or both |
| a ^ b | Bitwise XOR | Bits defined in a or b but not both |
| a << b | Bitwise shift left | Shift bits of a left by b units |
| a >> b | Bitwise shift right | Shift bits of a right by b units |
| ~a | Bitwise NOT | Bitwise negation of a |

These bitwise operators only make sense in terms of the binary representation of numbers, which you can see using the built-in bin function

print(bin(10))

Output: 
'0b1010'

The result is prefixed with 0b, which indicates a binary representation. 


Assignment Operations

| Operator | Name |
| -------- | ---- |
| a == b | simple assignment |
| a += b | addition assignment |
| a -= b | subtraction assignment |
| a *= b | multiplication assignment | 
| a /= b | division assignment |
| a //= b | floor division assignment |
| a %= b | remainder assignment |
| a **= b | exponentiation assignment |
| a &= b | Bitwise AND assignment |
| a |= b | Bitwise OR assignment |
| a ^= b | Bitwise XOR assignment |
| a <<= b | Bitwise shift left assignment |
| a >>= b | Bitwise shift right assignment |

Each one is equivalent to the corresponding operation followed by
assignment: that is, for any operator #, the expression a #= b is
equivalent to a = a # b.

HOWEVER, for mutable objects like lists, arrays, or DataFrames, these augmented assignment operations are actually subtly different than their more verbose counterparts: they modify the contents of the original object rather than creating a
new object to store the result.


Comparison Operations

| Operator | Description |
| -------- | ---- |
| a == b | a equal to b |
| a != b | a not equal to b |
| a < b | a less than b |
| a > b | a greater than b |
| a <= b | a less than or equal to b |
| a >= b | a greater than or equal to b |

Python implements standard comparison operators, which return Boolean values True and False.

We can string together multiple comparisons to check more complicated relationships:

'''Python
# check if a is between 15 and 30
a = 25
print(15 < a < 30)

# Output:
True
'''

Take a look at this comparison:

'''Python
print(-1 == ~0)

# Output:
True
'''

Recall that ~ is the bit-flip operator. 
Python uses two's complement to encode signed integers.


Boolean Operations


| Operator | Description |
| -------- | ---- |
| x and y | True if both are true |
| x or y | True if at least one is true |
| not x | True only if false |

Boolean algebra aficionados might notice that the XOR operator is
not included; this can of course be constructed in several ways from
a compound statement of the other operators. Otherwise, a clever
trick you can use for XOR of Boolean values is the following:
In [18]: # (x > 1) xor (x < 10)
(x > 1) != (x < 10)
Out [18]: False

Remember

Boolean operators should be used when you want to compute Boolean values (i.e.,
truth or falsehood) of entire statements. 

Bitwise operations should be used when you want to operate on individual bits or components
of the objects in question.


Identity and Membership Operators

| Operator | Description |
| -------- | ---- |
| a is b | True if a and b are identical objects |
| a is not b | True if a and b are not identical objects |
| a in b | True if a is a member of b |
| a not in b | True if a is not a member of b |

The is operator checks whether the two variables are
pointing to the same container (object), rather than referring to
what the container contains. With this in mind, in most cases that a
beginner is tempted to use is, what they really mean is ==

Membership operators check for membership within compound
objects.
