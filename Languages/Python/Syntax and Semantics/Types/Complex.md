Complex Numbers

Construct a complex number:

'''Python
print(complex(1, 2))

# Output: 
(1+2j)
'''

Alternatively, the j suffix may indicate the imaginary part:

'''Python
print(1 + 2j)

# Output:
(1+2j)
'''

Complex numbers have a variety of interesting attributes and methods:

'''Python
c = 3 + 4j
# real part
print(c.real)
# imaginary part
print(c.imag)
# complex conjugate
print(c.conjugate())
# magnitude--that is, sqrt(c.real ** 2 + c.imag ** 2)
print(abs(c)) 

# Output: 
3.0
4.0
(3-4j)
5.0
'''