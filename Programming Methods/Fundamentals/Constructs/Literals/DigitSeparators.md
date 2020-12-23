Digit Separators
In some languages, integer and floating point literals may contain digit separators to allow digit grouping into more legible forms. This is particularly useful for large numbers and numbers that are typically grouped, such as credit card number or social security numbers.

Typically
decimal numbers (base-10) are grouped in three digit groups (representing one of 1000 possible values)
binary numbers (base-2) in four digit groups (one nibble, representing one of 16 possible values)
hexadecimal numbers (base-16) in two digit groups (each digit is one nibble, so two digits are one byte, representing one of 256 possible values).
Numbers from other systems (such as id numbers) are grouped following whatever convention is in use.

int oneMillion = 1_000_000;
int creditCardNumber = 1234_5678_9012_3456;
int socialSecurityNumber = 123_45_6789;
