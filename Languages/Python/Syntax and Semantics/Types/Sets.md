Sets

contains unordered col‐
lections of unique items.

primes = {2, 3, 5, 7}
odds = {1, 3, 5, 7, 9}

# union: items appearing in either
primes | odds # with an operator
primes.union(odds) # equivalently with a method
Out [31]: {1, 2, 3, 5, 7, 9}

# intersection: items appearing in both
primes & odds # with an operator
primes.intersection(odds) # equivalently with a method
Out [32]: {3, 5, 7}

# difference: items in primes but not in odds
primes - odds # with an operator
primes.difference(odds) # equivalently with a method
Out [33]: {2}

# symmetric difference: items appearing in only one set
primes ^ odds # with an operator
primes.symmetric_difference(odds) # equivalently with a method

Out [34]: {1, 2, 9}