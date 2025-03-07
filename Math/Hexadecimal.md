# Comprehensive Guide to the Hexadecimal Numeral System

## 1. Definition
The **hexadecimal numeral system** (or **hex system**) is a **base-16** numbering system that uses **16 distinct digits**:  

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F

The digits **A to F** represent decimal values **10 to 15**, respectively:

| Hex | Decimal |
|-----|---------|
| A   | 10      |
| B   | 11      |
| C   | 12      |
| D   | 13      |
| E   | 14      |
| F   | 15      |

Since it is a **positional** numeral system, the value of each digit depends on its **position** in the number.

---

## 2. Positional Representation
Each digit in a hexadecimal number represents a power of **16**.  
The rightmost digit (least significant) is multiplied by \( 16^0 \), the next by \( 16^1 \), and so on.

For a hexadecimal number \( (d_k d_{k-1} ... d_2 d_1 d_0)_{16} \), its decimal equivalent is:

\[
d_k \cdot 16^k + d_{k-1} \cdot 16^{k-1} + ... + d_2 \cdot 16^2 + d_1 \cdot 16^1 + d_0 \cdot 16^0
\]

### Example: Converting `(2F3)₁₆` to Decimal
\[
2 \times 16^2 + F \times 16^1 + 3 \times 16^0
\]
\[
= 2 \times 256 + 15 \times 16 + 3 \times 1
\]
\[
= 512 + 240 + 3 = 755_{10}
\]

---

## 3. Hexadecimal to Binary Conversion
Each **hexadecimal digit corresponds exactly to four binary digits (bits)** because:

\[
16 = 2^4
\]

### Conversion Steps:
1. Convert each **hex digit** to its **four-bit binary equivalent**.
2. Combine all binary groups.

#### Example: Converting `(3F)₁₆` to Binary

3₁₆ = 0011₂ F₁₆ = 1111₂

Thus, `(3F)₁₆ = (00111111)₂`.

---

## 4. Binary to Hexadecimal Conversion
To convert from binary to hexadecimal:
1. **Group the binary digits into sets of four** from right to left.
2. Convert each group into its corresponding **hex digit**.

#### Example: Converting `(110111101010)₂` to Hex
1. Group the binary digits: **1101 1110 1010**
2. Convert each group:
   - `1101₂ = D₁₆`
   - `1110₂ = E₁₆`
   - `1010₂ = A₁₆`

Thus, `(110111101010)₂ = (DEA)₁₆`.

---

## 5. Decimal to Hexadecimal Conversion
To convert a **decimal number** to hexadecimal:
1. **Divide** the decimal number by 16.
2. **Record the remainder**.
3. **Repeat** the process with the quotient until you reach 0.
4. The **remainders, read in reverse order**, form the hexadecimal number.

#### Example: Converting `(755)₁₀` to Hex

755 ÷ 16 = 47, remainder 3 47 ÷ 16 = 2, remainder F (15) 2 ÷ 16 = 0, remainder 2

Reading the remainders from bottom to top:  
`(755)₁₀ = (2F3)₁₆`.

---

## 6. Arithmetic in Hexadecimal
Hexadecimal arithmetic follows the same basic rules as decimal but operates in base 16.

### Hexadecimal Addition Example

A9₁₆ + 3F₁₆

1. Convert to decimal:
   - `A9₁₆ = (10 × 16 + 9) = 169₁₀`
   - `3F₁₆ = (3 × 16 + 15) = 63₁₀`
   - `169 + 63 = 232₁₀`

2. Convert `232₁₀` to hex:
   - `232 ÷ 16 = 14`, remainder `8` → **E8**
   - So, `A9₁₆ + 3F₁₆ = E8₁₆`.

### Hexadecimal Multiplication Example

B₁₆ × 4₁₆

1. Convert to decimal:
   - `B₁₆ = 11₁₀`
   - `4₁₆ = 4₁₀`
   - `11 × 4 = 44₁₀`

2. Convert `44₁₀` to hex:
   - `44 ÷ 16 = 2`, remainder `C`
   - So, `B₁₆ × 4₁₆ = 2C₁₆`.

---

## 7. Applications of the Hexadecimal System
Hexadecimal is widely used in **computing, digital electronics, and programming**.

1. **Memory Addressing**
   - Computers use hex to represent **memory addresses** efficiently.
   - Example: `0x3F4A` instead of `0011111101001010₂`.

2. **Color Representation in Graphics**
   - Web colors use hex codes:  
     Example: `#FF5733`
     - `FF` (255) = Red
     - `57` (87) = Green
     - `33` (51) = Blue

3. **Machine Code & Assembly Language**
   - Opcodes in machine language are represented in hex.
   - Example: `0x8B 0x45 0xFC`.

4. **MAC Addresses & IP Addresses**
   - MAC addresses: `00:1A:2B:3C:4D:5E`
   - IPv6 addresses: `2001:0db8:85a3:0000:0000:8a2e:0370:7334`

---

## 8. Comparison with Other Numeral Systems
| Base  | Digits Used  | Examples |
|-------|------------|----------|
| **Binary (2)**  | 0, 1  | `1010`, `1101` |
| **Octal (8)**   | 0-7   | `57`, `345` |
| **Decimal (10)**| 0-9   | `23`, `485` |
| **Hexadecimal (16)** | 0-9, A-F | `1A3`, `F4B` |

- **Hex is more compact than binary** (1 hex digit = 4 bits).
- **More efficient than octal**, which only groups bits in sets of 3.

---

## 9. Summary
- The **hexadecimal system (base 16)** uses **digits 0-9 and A-F**.
- It is **easy to convert to/from binary** (1 hex digit = 4 bits).
- **Hex arithmetic follows base-16 rules**.
- It is widely used in **computing, memory addressing, colors, and networking**.


Hexadecimal

The base 16 hexadecimal system is common in computing. We will first explore how to use it then given an example of why it is useful.

As it is a base 16 system, each hexadecimal digit can represent 16 values; therefore, we need 16 digits. Since we only have 10 digits in our decimal system, we must use some symbols in the hexadecimal system to represent the values between 10 and 15. By convention those symbols are the six letters A to F.

Similar to the decimal system of base 10, the hexadecimal system of base 16 uses larger digits once the value at that digital position exceeds 16.

  F + 1 = 10    //Decimal representation: 15 + 1 = 16

Todo: Show correspondence between a single hexadecimal digit and four binary digits.


Converting hexadecimal to binary is like eating an elephant. You just
need to take one nibble at a time. 

Remember that a nibble is half a byte, or four bits. Each digit of a hexadecimal number converts neatly into a nibble.



Hexadecimal is used to represent colors in a web page:
<body bgcolor="#007F7F">



Binary is necessary to understand subnet masks in an IP network.
192.168.0.24/30
Converting hexadecimal to binary

Converting hexadecimal to binary is like eating an elephant. You just need to take one nibble at a time. Remember that a nibble is half a byte, or four bits. Each digit of a hexadecimal number converts neatly into a nibble.

HEXADECIMAL    BINARY
0              0000
1              0001
2              0010
3              0011
4              0100
5              0101
6              0110
7              0111
8              1000
9              1001
A              1010
B              1011
C              1100
D              1101
E              1110
F              1111