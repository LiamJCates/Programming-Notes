## String

https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/String

### No Character type
There is no character type.

In some languages, there is a special “character” type for a single character. For example, in the C language and in Java it is called “char”.

In JavaScript, there is no such type. There’s only one type: string. A string may consist of zero characters (be empty), one character or many of them.

### Declaration

A string in JavaScript must be surrounded by single quotes ('), double quotes ("), or backticks (`) 

    Double quotes: "Hello"
    Single quotes: 'Hello'
    Backticks: `Hello`

Double and single quotes are “simple” quotes. There’s practically no difference between strings declared with either.

Backticks declare Template literals which we will detail later.


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


What happens when we try to concatenate a string and a number? Let's try it in our console:
js

const name = "Front ";
const number = 242;
console.log(name + number); // "Front 242"

You might expect this to return an error, but it works just fine. How numbers should be displayed as strings is fairly well-defined, so the browser automatically converts the number to a string and concatenates the two strings.

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

