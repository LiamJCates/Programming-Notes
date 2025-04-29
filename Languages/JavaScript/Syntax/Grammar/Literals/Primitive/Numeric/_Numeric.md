# Numeric Literals

In JavaScript, numeric literals represent numbers directly in your source code. JavaScript uses a single number type: the IEEE 754 double-precision floating-point number. Despite having one underlying type, JavaScript supports multiple notations for numeric literals.

Note that the language specification requires numeric literals to be unsigned. Nevertheless, code fragments like -123.4 are fine, being interpreted as a unary - operator applied to the numeric literal 123.4.

---

## Numeric Literal Formats

### Decimal Literals

- **Format:** A sequence of digits (0–9), optionally including a decimal point.
- **Examples:**
  ```javascript
  42
  3.14159
  .5    // interpreted as 0.5
  5.    // interpreted as 5.0
  ```

### Scientific (Exponential) Notation

- **Format:** A decimal number followed by `e` (or `E`) and an exponent.
- **Purpose:** To represent very large or very small numbers.
- **Examples:**
  ```javascript
  1.23e4   // equals 12300
  5E-3     // equals 0.005
  ```

### Hexadecimal Literals

- **Format:** Prefixed with `0x` or `0X`, followed by hexadecimal digits (0–9 and A–F/a–f).
- **Use Case:** Common for defining colors, bit masks, or low-level programming tasks.
- **Examples:**
  ```javascript
  0xFF      // equals 255
  0X1a3f    // equals 6719
  ```

### Binary Literals

- **Format:** Prefixed with `0b` or `0B`, followed by binary digits (0 and 1).
- **Introduced:** ECMAScript 2015 (ES6)
- **Examples:**
  ```javascript
  0b1010   // equals 10
  0B1101   // equals 13
  ```

### Octal Literals

- **Format:** Prefixed with `0o` or `0O`, followed by octal digits (0–7).
- **Introduced:** ECMAScript 2015 (ES6) as a standard notation (legacy octal literals used a leading zero).
- **Examples:**
  ```javascript
  0o755   // equals 493 in decimal
  0O644   // equals 420 in decimal
  ```

### Numeric Separators (Underscores)

- **Purpose:** Improve readability of large numbers.
- **Introduced:** ECMAScript 2021
- **Examples:**
  ```javascript
  1_000_000   // equals 1000000
  0b1010_0101 // equals 165 in decimal
  ```

---

## Special Numeric Values

- **Infinity and -Infinity:**  
  Represent values beyond the upper or lower limits.
  ```javascript
  console.log(Infinity);   // Infinity
  console.log(-Infinity);  // -Infinity
  ```






## Numeric Seperators

Numeric separators use the underscore symbol _ to separate groups of digits in a numeric literal.

```javascript
const largeNumber = 123_456_789;
```

The underscores in this example separate the number into three groups of three digits each, making it easier to read and understand the value of the number.

Numeric separators can be used with decimal, binary, and hexadecimal literals, as well as with scientific notation

```javascript
const decimalNumber = 1_000_000.25;
const binaryNumber = 0b1010_0010_0100_0001;
const hexadecimalNumber = 0x1234_abcd_ef;
const scientificNumber = 1.23e4_5;
```

### Benefits of Numeric Separators

Numeric separators offer several benefits to developers. They make it easier to read and understand large numbers. This is particularly useful for code that involves financial calculations or other situations where large numbers are common.

### Limitations of Numeric Separators

While numeric separators are a useful feature in JavaScript, they do have some limitations. For example, they cannot be used at the beginning or end of a number. Here are some examples of code that will result in errors:

```javascript
const invalidNumber1 = _1000; // Error: numeric separator cannot be used at the beginning of a number
const invalidNumber2 = 1000_; // Error: numeric separator cannot be used at the end of a number
```

### Browser Support

Numeric separators are a relatively new feature in JavaScript, and not all browsers support them yet. As of 2022, numeric separators are supported in most modern browsers, including Chrome, Firefox, Safari, and Edge. However, some older browsers may not support numeric separators.

To ensure that your code is compatible with all browsers, it is a good idea to use a transpiler like Babel to convert your code to a more widely supported format.


















## Best Practices & Common Pitfalls

### Floating Point Precision
- **Issue:**  
  Because JavaScript numbers are based on IEEE 754, calculations may yield imprecise results.
- **Example:**
  ```javascript
  console.log(0.1 + 0.2);  // 0.30000000000000004
  ```
- **Tip:**  
  Use techniques like rounding or libraries for high-precision arithmetic.

### Implicit Type Conversions
- **Be Aware:**  
  JavaScript may perform implicit conversions in arithmetic and comparisons.
- **Example:**
  ```javascript
  console.log("5" + 3);  // "53"
  console.log("5" - 3);  // 2
  ```


