## String

https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String

JavaScript Strings are used to represent textual data. They are stored as sequences of 16‑bit code units (UTF‑16), and they are immutable (i.e. once created, they cannot be modified). 

### No Character type
There is no character type.

In some languages, there is a special “character” type for a single character. For example, in the C language and in Java it is called “char”.

In JavaScript, there is no such type. There’s only one type: string. A string may consist of zero characters (be empty), one character or many of them.


---

### String Declaration

Strings can be created using:

- **String Literals:**  

A string in JavaScript must be surrounded by single quotes ('), double quotes ("), or backticks (`) 

  Single or double quotes:
  ```js
  let greeting1 = 'Hello, World!';
  let greeting2 = "Hello, World!";
  ```
- **Template Literals (ES6):**  
Backticks declare Template literals which we will detail later.

  Use backticks to support embedded expressions and multi-line strings:
  ```js
  let name = "Alice";
  let greeting = `Hello, ${name}!
Welcome to JavaScript.`;
  console.log(greeting);
  ```

- **String Constructor:**  
  Creates a string object (usually not recommended):
  ```js
  let strObj = new String("Hello, World!");
  console.log(typeof strObj); // "object"
  console.log(typeof strObj.valueOf()); // "string"
  ```

---

### Quotes In Strings

To include quotes in strings, we have two options 

one is to use one of the other characters to declare the string:
```js
const goodQuotes1 = 'She said "I think so!"';
const goodQuotes2 = `She said "I'm not going in there!"`;
```
The other option is to escape the problem quotation mark with a backslash:

```js
const bigmouth = 'I\'ve got no right to take my place…';
console.log(bigmouth);
```
You can use the same technique to insert other special characters. See Escape sequences for more details.

### Line Breaks

For a string to include line breaks requires the line break characters (\n):

```js
const newline = "One day you finally knew\nwhat you had to do, and began,";
console.log(newline);

/*
One day you finally knew
what you had to do, and began,
*/
```

### Concatenation

You can concatenate normal strings using the + operator:

```js
const greeting = "Hello";
const name = "Chris";
console.log(greeting + ", " + name); // "Hello, Chris"
```










### Template

Template literals are literals delimited with backtick (`) characters, allowing for 

    multi-line strings, 
    string interpolation with embedded expressions, 
    special constructs called tagged templates.


### Multi-line 
Any newline characters inserted in the source are part of the template literal.

Using template literals, you can create multi-line strings without escape characters:

```js
console.log(`string text line 1
string text line 2`);
// "string text line 1
// string text line 2"
```

Like normal string literals, you can write a single-line string across multiple lines for source code readability, by escaping the newline with a backslash (\):

```js
console.log(`string text line 1 \
string text line 2`);
// "string text line 1 string text line 2"
```

### Embedded Expressions

Along with having normal strings, template literals can also contain other parts called placeholders, which are embedded expressions delimited by a dollar sign and curly braces: ${expression}. 
```js
let name = "John";

// embed a variable
alert( `Hello, ${name}!` ); // Hello, John!

// embed an expression
alert( `the result is ${1 + 2}` ); // the result is 3
```
Any expression inside ${…} is evaluated and undergoes implicit conversion

Please note that this can only be done in backticks. Other quotes don’t have this embedding functionality!
```js
alert( "the result is ${1 + 2}" ); // the result is ${1 + 2} (double quotes do nothing)
```

```js
const name = "Chris";
const greeting = `Hello, ${name}`;
console.log(greeting); // "Hello, Chris"
```

You can use the same technique to join together two variables:

```js
const one = "Hello, ";
const two = "how are you?";
const joined = `${one}${two}`;
console.log(joined); // "Hello, how are you?"
```

Joining strings together like this is called concatenation.



### String interpolation

Without template literals, when you want to combine output from expressions with strings, you'd concatenate them using the addition operator +:
js

const a = 5;
const b = 10;
console.log("Fifteen is " + (a + b) + " and\nnot " + (2 * a + b) + ".");
// "Fifteen is 15 and
// not 20."

That can be hard to read – especially when you have multiple expressions.

With template literals, you can avoid the concatenation operator — and improve the readability of your code — by using placeholders of the form ${expression} to perform substitutions for embedded expressions:
js

const a = 5;
const b = 10;
console.log(`Fifteen is ${a + b} and
not ${2 * a + b}.`);
// "Fifteen is 15 and
// not 20."

Note that there's a mild difference between the two syntaxes. Template literals coerce their expressions directly to strings, while addition coerces its operands to primitives first.




The strings and placeholders get passed to a function — either a default function, or a function you supply. The default function (when you don't supply your own) just performs string interpolation to do substitution of the placeholders and then concatenate the parts into a single string.






Below is a comprehensive guide on the JavaScript string data type, including in‐depth explanations and extensive code examples. This guide covers string creation, immutability, common properties, and a variety of built-in methods for manipulating strings. It also compares how different string operations work. Each section includes clear code examples to illustrate key concepts.






## String Properties

- **`length`:**  
  Returns the number of UTF‑16 code units in the string.
  ```js
  let text = "JavaScript";
  console.log(text.length); // 10
  ```

- **Character Access:**  
  You can access individual characters using bracket notation or `charAt()`:
  ```js
  console.log(text[0]);       // "J"
  console.log(text.charAt(0)); // "J"
  ```

> **Note:** Strings are immutable:
> ```js
> text[0] = "Y";
> console.log(text); // Still "JavaScript"
> ```

---

## Common String Methods

### 1. Concatenation
- **Using the `+` operator** or **`concat()` method**:
  ```js
  let firstName = "John";
  let lastName = "Doe";
  let fullName = firstName + " " + lastName;
  console.log(fullName); // "John Doe"

  // Using concat:
  let fullName2 = firstName.concat(" ", lastName);
  console.log(fullName2); // "John Doe"
  ```

### 2. Changing Case
- **`toUpperCase()` and `toLowerCase()`:**
  ```js
  let lower = "hello";
  let upper = lower.toUpperCase();
  console.log(upper); // "HELLO"
  
  let mixed = "HeLLo WoRLd";
  console.log(mixed.toLowerCase()); // "hello world"
  ```

### 3. Searching for Substrings
- **`indexOf()` and `lastIndexOf()`:**
  ```js
  let phrase = "JavaScript is awesome. JavaScript is fun.";
  console.log(phrase.indexOf("JavaScript"));   // 0
  console.log(phrase.lastIndexOf("JavaScript")); // 24
  ```
- **`includes()`:**
  ```js
  console.log(phrase.includes("awesome")); // true
  console.log(phrase.includes("Python"));  // false
  ```

### 4. Extracting Substrings
- **`slice()`:** Extracts a section of a string.
  ```js
  let sample = "Hello, World!";
  console.log(sample.slice(7, 12)); // "World"
  // Negative indices work from the end:
  console.log(sample.slice(-6, -1)); // "World"
  ```
- **`substring()`:** Similar to `slice()`, but negative values are treated as 0.
  ```js
  console.log(sample.substring(7, 12)); // "World"
  console.log(sample.substring(-3, 5)); // "Hello" because -3 becomes 0
  ```
- **`substr()` (deprecated):** Extracts based on starting index and length.
  ```js
  console.log(sample.substr(7, 5)); // "World"
  ```

### 5. Replacing Parts of a String
- **`replace()` and `replaceAll()`:**
  ```js
  let text2 = "I love JavaScript. JavaScript is great!";
  // Replaces only the first occurrence:
  console.log(text2.replace("JavaScript", "Python"));
  // Using a regular expression with the global flag to replace all:
  console.log(text2.replace(/JavaScript/g, "Python"));
  ```
  
### 6. Trimming Whitespace
- **`trim()`, `trimStart()`, and `trimEnd()`:**
  ```js
  let padded = "   Hello, World!   ";
  console.log(padded.trim());      // "Hello, World!"
  console.log(padded.trimStart()); // "Hello, World!   "
  console.log(padded.trimEnd());   // "   Hello, World!"
  ```

### 7. Splitting and Joining
- **`split()`** converts a string into an array.
  ```js
  let csv = "red,green,blue";
  let colors = csv.split(",");
  console.log(colors); // ["red", "green", "blue"]
  ```
- **`join()`** (on arrays) converts back to a string:
  ```js
  let newCsv = colors.join(";");
  console.log(newCsv); // "red;green;blue"
  ```

### 8. Repeating Strings
- **`repeat()`:**
  ```js
  let repeatStr = "Ha! ".repeat(3);
  console.log(repeatStr); // "Ha! Ha! Ha! "
  ```

### 9. Getting a Unicode Code Point
- **`charCodeAt()` and `codePointAt()`:**
  ```js
  let smile = "😊";
  console.log(smile.charCodeAt(0));  // returns the first 16-bit unit
  console.log(smile.codePointAt(0)); // returns the full Unicode code point (e.g. 128522)
  ```

---

## Practical Examples

### Reverse a String
```js
function reverseString(str) {
  return str.split("").reverse().join("");
}
console.log(reverseString("JavaScript")); // "tpircSavaJ"
```

### Check for a Palindrome
```js
function isPalindrome(str) {
  // Remove non-alphanumeric characters and convert to lowercase
  let cleaned = str.replace(/[\W_]/g, "").toLowerCase();
  return cleaned === reverseString(cleaned);
}
console.log(isPalindrome("A man, a plan, a canal, Panama")); // true
```

### Capitalize Each Word
```js
function capitalizeWords(str) {
  return str.split(" ").map(word => 
    word.charAt(0).toUpperCase() + word.slice(1).toLowerCase()
  ).join(" ");
}
console.log(capitalizeWords("hello world")); // "Hello World"
```




---


**String concatenation** means combining two or more strings into one. In JavaScript, concatenation can be done in several ways:

- Using the **`+` operator**
- Using the **`concat()` method**
- Using **template literals (backticks)**

Each method has its advantages and is useful in different scenarios.

---

## 1. Using the `+` Operator

The simplest and most common way to concatenate strings is with the **`+` operator**. This operator converts non-string operands to strings if necessary and combines them.

### Basic Example

```js
let firstName = "John";
let lastName = "Doe";
let fullName = firstName + " " + lastName;
console.log(fullName); // Output: "John Doe"
```

### Concatenating Numbers and Strings

JavaScript is loosely typed, so if you mix strings with numbers, the numbers are converted to strings:

```js
let age = 30;
let info = "Age: " + age;
console.log(info); // Output: "Age: 30"
```

However, pay attention to operator precedence:

```js
console.log("Result: " + 2 + 3);   // Output: "Result: 23"
console.log("Result: " + (2 + 3)); // Output: "Result: 5"
```

*Tip:* Use parentheses to ensure the correct order of operations.


If you have a numeric variable that you want to convert to a string or a string variable that you want to convert to a number, you can use the following two constructs:

    The Number() function converts anything passed to it into a number if it can. Try the following:
    js

const myString = "123";
const myNum = Number(myString);
console.log(typeof myNum);
// number

Conversely, the String() function converts its argument to a string. Try this:
js

    const myNum2 = 123;
    const myString2 = String(myNum2);
    console.log(typeof myString2);
    // string

These constructs can be really useful in some situations. For example, if a user enters a number into a form's text field, it's a string. However, if you want to add this number to something, you'll need it to be a number, so you could pass it through Number() to handle this.


---

## 2. Using the `concat()` Method

The **`concat()` method** is a built-in method that joins two or more strings and returns a new string without modifying the original strings.

### Basic Usage

```js
let greeting = "Hello";
let target = "World";
let message = greeting.concat(", ", target, "!");
console.log(message); // Output: "Hello, World!"
```

### Notes on `concat()`

- It does not modify the original strings.
- It can accept multiple arguments.
- While it works similarly to the `+` operator, the `+` operator is generally more concise and preferred in many cases.

---

## 3. Using Template Literals (Backticks)

**template literals** provide an elegant way to embed variables and expressions into strings. They are enclosed in backticks (`` ` ``) and use `${...}` for interpolation.

### Basic Example

```js
let firstName = "John";
let lastName = "Doe";
let fullName = `${firstName} ${lastName}`;
console.log(fullName); // Output: "John Doe"
```
---

## 4. Advanced Concatenation: Using Arrays and `join()`

Sometimes you might have an array of strings that you want to concatenate. The **`join()` method** is ideal in such cases.

### Example

```js
let words = ["JavaScript", "is", "fun!"];
let sentence = words.join(" ");
console.log(sentence); // Output: "JavaScript is fun!"
```

This method is particularly useful when building strings from dynamic data or when concatenating a large number of strings.

---

## Best Practices and Considerations

- **Operator Precedence:**  
  When mixing data types (numbers and strings), use parentheses to ensure proper evaluation.

- **Immutability:**  
  Remember that strings in JavaScript are immutable. All concatenation methods return a new string without altering the original strings.

- **Performance:**  
  For simple concatenation, the `+` operator is both concise and fast. For concatenating many strings (especially inside loops), consider using an array with `join()` to avoid creating multiple temporary strings.

- **Readability:**  
  Template literals not only make code more readable but also make multi-line strings and embedded expressions easier to manage.