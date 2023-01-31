Type sizes above are expressed in bits; the more bits a type has, the more distinct values it can represent, but at the same time, also consumes more space in memory:

| Size | Unique representable values | Notes |
|------|-----------------------------|-------|
| 8-bit | 256 | = 2^8 |
| 16-bit | 65 536 | = 2^16 |
| 32-bit | 4 294 967 296 | = 2^32 (~4 billion) |
| 64-bit | 18 446 744 073 709 551 616 | = 2^64 (~18 billion billion) |

For integer types, having more representable values means that the range of values they can represent is greater; for example, a 16-bit unsigned integer would be able to represent 65536 distinct values in the range 0 to 65535, while its signed counterpart would be able to represent, on most cases, values between -32768 and 32767. Note that the range of positive values is approximately halved in signed types compared to unsigned types, due to the fact that one of the 16 bits is used for the sign; this is a relatively modest difference in range, and seldom justifies the use of unsigned types based purely on the range of positive values they can represent.

For floating-point types, the size affects their precision, by having more or less bits for their significant and exponent.
