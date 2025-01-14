Dictionaries

mappings of keys to values

created via a comma-separated list of key:value pairs within curly braces:

numbers = {'one':1, 'two':2, 'three':3}

the index is not a zero-based order but valid key in the dictionary:

# Access a value via the key
numbers['two']

# Output: 
2

New items can be added to the dictionary using indexing as well:
In [29]: # Set a new key/value pair
numbers['ninety'] = 90
print(numbers)
{'three': 3, 'ninety': 90, 'two': 2, 'one': 1}

Keep in mind that dictionaries do not maintain any sense of order
for the input parameters; this is by design. This lack of ordering
allows dictionaries to be implemented very efficiently, so that ran‐
dom element access is very fast, regardless of the size of the dictio‐
nary (if you’re curious how this works, read about the concept of a
hash table). 