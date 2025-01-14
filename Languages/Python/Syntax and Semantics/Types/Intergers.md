Integers

Python integers are variable-precision, so you can do computations that would overflow in other languages:

'''Python
print(2 ** 200)

# Output:
1606938044258990275541962092341162602522202993782792835301376
'''


by default, division upcasts to floating-point type:
In [3]: 5 / 2
Out [3]: 2.5

Note that this upcasting is a feature of Python 3; in Python 2, like in
many statically typed languages such as C, integer division truncates
any decimal

Finally, note that although Python 2.x had both an int and long
type, Python 3 combines the behavior of these two into a single int
type.
