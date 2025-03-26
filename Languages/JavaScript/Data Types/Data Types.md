## Data types

Data types are categorized into two main types, Primitive and Non-Primitive.

The latest ECMAScript standard defines eight data types:

    Seven data types that are primitives:
        Boolean. true and false.
        null. A special keyword denoting a null value. (Because JavaScript is case-sensitive, null is not the same as Null, NULL, or any other variant.)
        undefined. A top-level property whose value is not defined.
        Number. An integer or floating point number. For example: 42 or 3.14159.
        BigInt. An integer with arbitrary precision. For example: 9007199254740992n.
        String. A sequence of characters that represent a text value. For example: "Howdy".
        Symbol. A data type whose instances are unique and immutable.

    Object
    Array



Data type conversion

JavaScript is a dynamically typed language. This means you don't have to specify the data type of a variable when you declare it. It also means that data types are automatically converted as-needed during script execution.

So, for example, you could define a variable as follows:
js

let answer = 42;

And later, you could assign the same variable a string value, for example:
js

answer = "Thanks for all the fish!";

Because JavaScript is dynamically typed, this assignment does not cause an error message.