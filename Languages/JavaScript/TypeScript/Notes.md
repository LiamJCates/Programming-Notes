# TypeScript

TypeScript is a programming language
that adds static typing to the dynamically
typed JavaScript language. It’s a strict syntac-
tic superset of JavaScript, which means that all
existing JavaScript is valid TypeScript. By contrast,
TypeScript is not valid JavaScript, because it supplies
additional features.

TypeScript’s syntax isn’t valid JavaScript, so a regular JavaScript runtime
environment can’t execute it. 

To run TypeScript in Node.js or a browser, we first need to use TSC to convert it to regular, backward- compatible JavaScript. We then execute the resulting JavaScript

Despite being called a compiler, TSC doesn’t actually compile TypeScript
into JavaScript. Instead, it transpiles it. The difference lies in the level of
abstraction. A compiler creates low-level code, while a transpiler is a source-
to- source compiler that produces equivalent source code in a language of
roughly the same abstraction. 

In addition to converting TypeScript to JavaScript, TSC checks your
code for type errors and verifies the contracts between your functions. The
transpiling and type- checking happen independently, and the TSC pro-
duces JavaScript regardless of the types you defined. TypeScript errors are
merely warnings emitted during the build. They won’t stop the transpiling
step as long as the JavaScript itself doesn’t produce an error.
The use of TypeScript won’t affect your code’s performance. The compiler
removes types and type operations during the transpilation step, essentially
stripping all TypeScript syntax from the actual JavaScript code. Therefore,
they can’t affect the runtime or the size of the final code. TypeScript is
consequently no slower than JavaScript, although the transpilation can take
some time.


TypeScript makes working with JavaScript’s type system less error prone, as
its compiler helps us see type errors instantly. Because JavaScript is dynami-
cally typed, you don’t need to specify a variable’s type when declaring it.
As soon as the runtime executes the script, it checks these types based on
usage. However, this means that errors resulting from invalid types (for
example, calling array.map on a variable that holds a number instead of an
array) won’t be discovered until runtime, at which point the complete pro-
gram fails.
In addition to being dynamically typed, JavaScript is also weakly typed,
which means it implicitly converts variables to their most plausible values.


Implicit conversion from a number to a string in JavaScript
```js
let string = "1";
let number = 1;
let result;
result = number + number;
console.log("value: ", result, " type of ", typeof(result)); //value: 2 type of number
result = number + string;
console.log("value: ", result, " type of ", typeof(result)); //value: 11 type of string
```

For an indepth explination and further examples see [here](../Concepts/Implicit%20Converstions.md)


Our
function might expect both parameters to be numbers, but we can’t verify this
without manually checking the type by using logic 

```js
let string = "1";
let number = 1;
let result;
const calculate = (a, b) => {
    if (Number.isInteger(a) === false || Number.isInteger(b) === false) {
        throw new Error("Invalid type: a parameter is not an integer");
    } else {
        return a + b;
    }
};

result = calculate(number, number);
console.log("value: ", result, " type of ", typeof(result));

result = calculate(number, string);
console.log("value: ", result, " type of ", typeof(result));
```

```
Error: Invalid type: a parameter is not an integer
```

There are two main concerns with manually checking the types. First,
it adds a lot of noise to our code, as we need to check for all possible types
every time we work with function or API contracts, such as when we accept
a parameter or return a value. Second, we’re not notified of issues during
development. To see the errors in dynamically typed languages, we need
to execute the code so that the interpreter can inform us about errors at
runtime.

Unlike dynamically typed languages, statically typed languages per-
form type checks on the code compilation, before runtime. The `TypeScript Compiler` (TSC) handles this chore; it can run in the background of our
code editor or IDE and instantly report all errors based on invalid type
usage. Therefore, you can catch errors and see each variable’s assigned
types and data structures early.
Even if you don’t set up instant feedback like that, running your code
through TSC is necessary before it can be used, which ensures that these
kinds of errors are caught earlier than they other wise would be. The abil-
ity to check for these errors is one of the most important benefits of using
TypeScript over JavaScript. 



## Type Annotations

A type annotation is an optional way to explicitly tell the runtime environ- ment which types to expect. You add them following this schema: 

```ts
variable: type 
```

The following example shows a version of the calculate function in
which we type both parameters as numbers:

```ts
const calculate = (a: number, b: number) => a + b;
```

#### Over-typing

Some developers tend to add types to every thing in their code, and
by doing so, they add noise that makes the code less readable. This anti-
pattern, called over-typing, stems from a false understanding of how type
annotations should work. The TypeScript compiler infers types from usage.
Therefore, you don’t need to explicitly type every thing. Instead, the code
editor runs TSC in the background and leverages the results to display the
inferred type information and compiler errors.

Rather, type annotations are a way to ensure that code honors the API
contracts. 

There are three scenarios in which you’ll want to verify the contract, and only one of them is especially important.

annotating a variable’s declaration, is usually not recommended
annotating the return value of a function, is optional
annotating a function’s parameters, is essential.

### Declaring a Variable

The most obvious place to type a variable is upon an assignment or declara-
tion.

```ts
let weather: string = "sunny";
```

In most cases, however, this is a form of over-typing, as you could instead leverage the compiler’s type inference.

Because TSC automatically infers the type of this variable, the code
editor should show the type information when you hover over the variable.
Without the explicit annotation, we have a much cleaner syntax and avoid the
noise that the redundant type declaration adds to the code. This improves
code readability, which is why this kind of over-typing is usually to be avoided.

### Declaring a Return Value

Although TypeScript can infer a function’s return type, you’ll usually want
to annotate it explicitly. This code pattern ensures that the function’s con-
tract is honored, as the compiler shows implementation errors where the
function is defined instead of where it is used.

Another reason to use type annotations in this situation is that, as a
programmer, you must explicitly define what a function does. By clarifying
the function’s input and output types, you’ll gain a better understanding
of what you actually want the function to do. 


The return type annotation follows the parameter definitions

```ts
function getWeather(): string {
    const weather = "sunny";
    return weather;
}
```

We create a function that returns the weather variable we declared
earlier. The weather variable has the inferred string type. Hence, the func-
tion returns a string. Our type definition explicitly sets the function’s
return type.

### Declaring a Function’s Parameters

It’s essential to annotate the parameters of a function, because TypeScript
doesn’t have enough information to infer function parameters in most cases. By typing these parameters, you’re telling the compiler to check
the types when you call the function and pass it arguments. 

parameter type declarations follow a similar syntax to a variable's type declaration.


```ts
const weather = "sunny";

function getWeather(weather: string): string {
    return weather;
};

getWeather(weather)
```


## Built-in Types


Before you can use TypeScript and its annotations, you need to know what types
are available to you. One of TypeScript’s main benefits is that it enables you to
declare any of JavaScript’s primitive types explicitly. In addition, TypeScript adds
its own types, the most important of which are unions, tuples, any, and void. You
can also define custom types and interfaces.

### Primitive JavaScript Types
JavaScript has five primitive types: strings, numbers, Booleans, undefined,
and null. Everything else in the language is considered an object.


JavaScript’s primitive types with TypeScript’s type annotations

```ts
let stringType: string = "bar";
let booleanType: boolean = true;
let integerType: number = 1;
let floatType: number = 1.5;
let nullType: null = null;
let undefinedType: undefined = undefined;
```


### union

Unions are variables or parameters that can have more than one data type. 

```ts
let stringOrNumberUnionType: string | number;
stringOrNumberUnionType = "bar";
stringOrNumberUnionType = 1;
stringOrNumberUnionType = true;
```

We declare a union-type variable that can contain either a string or a
number, but nothing else. As soon as we assign a Boolean variable, TSC
throws an `error`, and the IDE shows the message Type 'boolean' is not
assignable to type 'string | number'.

While you might find union types useful for annotating function
parameters and arrays that can contain dif ferent types, you should use
them sparingly and avoid them whenever possible. This is because, before
working with union-typed items, you need to perform additional manual
type checks; other wise, they could cause errors. For example, if you iterated
over an array of strings or numbers and then wished to add all numeric items, you would
first need to convert all strings to numbers. Other wise, JavaScript would
implicitly convert the numbers to strings

### array

TypeScript provides a generic array type that offers array functions similar
to JavaScript’s array. 

The type of the array depends on the type of the array items.

```ts
let genericArray: [] = [];
genericArray.push(1);

let numberArray: number[] = [];
numberArray.push(1);
```

First we define an array without specifying the type of its items. Unfor-
tunately, what seems to be a definition of a generic array leads to issues
down the road. As soon as we try to add a value, TSC throws the error
Argument of type 'number' is not assignable to parameter of type 'never',
because the array is not typed.
Hence, we need to type the items in the array. Therefore, we create an
array, numberArray, in which each item has the type of number. Now we can
add numeric values to the array without running into errors.


### tuple

tuples are arrays with a specified number of typed items. 

```ts
let validTuple: [string, number] = ["bar", 1];
let invalidTuple: [string, number] = [1, "bar"];
```

We define two tuples. In both, the first array item is a string, and the sec-
ond is a number. If the type, order, or number of items added to the tuple
differs from the tuple’s declaration, TSC throws an error


### any

TypeScript’s any type is generic, meaning it can take any value, and you should avoid using it.

```ts
let indifferent: any = true;
indifferent = 1;
indifferent = [];
```

any accepts all values without throwing an error, which defeats the purpose of static typing.

Using any might seem like an easy choice, and it is tempting to rely on
it as an escape hatch. Avoid this at all costs. When you pass any as a value
to, say, a function, you break the contract you specified in the function
declaration, and when you use any to define the contract, there effectively
isn’t one.

```ts
const calculate = (a: any, b: any): any => a + b;
console.log(calculate (1,1));
console.log(calculate ("1",1));
```

We reuse the calculate function, which adds two numbers. When we
pass two numeric values, we receive the expected output of 2. In a previous
example, we typed the parameters as numbers, thus preventing the use of
invalid types as arguments.
However, when we use any instead of a number and pass a string to
the function, TSC doesn’t throw an error. JavaScript implicitly converts
the number to a string and returns an unexpected value of 11. We saw this
behav ior at the beginning of the chapter, in the untyped version of the
function. As you can see, using any is the same as using no types at all.
While convenient, the any type masks your bugs during programming
and hides your type designs, rendering type- checking useless. It also pre-
vents your IDE from displaying errors and invalid types.

### void

TypeScript’s void type is the opposite of any: it indicates no type at all. Its
only use case is to annotate the return value of a function that shouldn’t
have one

```ts
function log(msg: string): void {
    console.log(msg);
}
```

The custom log function we define here passes a parameter to the console. It doesn’t return anything, so we use void as the return type.


### object

TypeScript’s built-in object type is the same as JavaScript’s object. Although
you can define the properties’ types for TSC to type- check, the compiler can’t
ensure the order of the properties. Nonetheless, it typechecks them

```ts
let weatherDetail: {
    weather: string,
    zipcode: string,
    temp: number
    } = { weather: "sunny", zipcode: "00000", temp: 1 };

    weatherDetail.weather = 2;
```


Here we define an object with three properties: two that take a string
and another that takes a number. Then we try to assign a number to the
property weather annotated as a string. Now TSC notifies us with an error
explaining that we assigned a value of the wrong type.
Note that, usually, you should avoid typing objects inline, as in this
example. Instead, it is a best practice to create a custom type, which is
reusable and avoids cluttering our code, enhancing its readability.

## Custom Types and Interfaces

The previous sections introduced you to enough TypeScript to begin using
the language. However, you’ll find it helpful to know a few more advanced
concepts. 

While working with TypeScript, remember that a TypeScript file without
top-level imports or exports is not a module; therefore, it runs in the global
scope. Consequently, all of its declarations are accessible in other modules.
By contrast, a TypeScript file with top-level imports or exports is its own
module, and all declarations are limited to the module scope, meaning
they’re available in the scope of this module only.

### Custom Types

TypeScript lets you define custom types by using the type keyword. Custom
types are a great way to simplify your code. 

Compared to the previously defined object, we will find type aliases cleaner and easier to read.

```ts
type WeatherDetailType = {
    weather: string;
    zipcode: string;
    temp?: number;
};

let weatherDetail: WeatherDetailType = {
    weather: "sunny",
    zipcode: "00000",
    temp: 30
};

const getWeatherDetail = (data: WeatherDetailType): WeatherDetailType => data;
```

We create a custom type, WeatherDetailType, with the type keyword. Note
that the overall syntax is similar to that used to define an object; we use the
equal sign (=) to assign the definition to the custom type.
The custom type has two required properties: weather and zipcode. In
addition, it has an optional temp property, as indicated by the question
mark (?). Now when we create the getWeatherDetail function, we can annotate
the parameter, weatherDetail, as an object with a type of WeatherDetailType.
Using this technique, we avoid using inline annotations and can reuse our
custom type later, such as to annotate the return type of a function.

### Interfaces


In addition to types, TypeScript has interfaces. However, the difference
between a type and an interface is blurry. You can freely decide which one
to use, so long as you follow a convention in your code

In general, we consider a type definition to answer the question, “Which
type is this data?” A possible answer might be a union or a tuple. An inter-
face is a way to describe the shape of some data, such as the properties
of an object. It answers the question, “Which properties does this object
have?” The most practical difference is that, unlike an interface, we cannot
directly modify a type after we’ve declared it. 


As a rule of thumb, use an interface to define a new object or the
method of an object. More generally, consider using interfaces over types,
as they provide more precise error messages. A classic React use case for
interfaces is to define the properties of a specific component.


```ts
interface WeatherProps {
    weather: string;
    zipcode: string;
    temp?: number;
}
const weatherComponent = (props: WeatherProps): string => props.weather;
```


Here we use the interface keyword to define a new interface. Unlike a
custom type’s definition, an interface definition does not use the equal sign
to assign the interface’s properties to its name. We then use the custom
interface to type the properties object props of the weatherComponent, which
returns a string.


### Type Declaration Files


To use custom types universally, you can define them in type declaration files,
which have the .d.ts extension. Unlike regular TypeScript files with the .ts or
.tsx extension, type declaration files shouldn’t contain any implementation code. Instead, TSC uses these type definitions to understand custom types
and perform type checks. They aren’t transpiled to JavaScript and are never
part of the executed script.
Type declaration files prove useful when you find yourself working
with external code bases. Often, third-party libraries aren’t written in
TypeScript. Therefore, they don’t provide type declaration files for their
code bases. Luckily, the DefinitelyTyped repository at http://definitelytyped
.github.io provides type declaration files for more than 7,000 libraries. Use
these files to add TypeScript support to these libraries.
Type declaration files are collected under the @types scope in npm. This
scope holds all the declarations from DefinitelyTyped. Hence, they are easy
to find and are grouped next to each other in your package.json file. All type
declaration files from the @types scope should be considered development
dependencies of your project. Hence, we use the --save-dev flag on the npm
install command to add them


```ts
interface WeatherQueryInterface {
    zipcode: string;
}

type WeatherDetailType = {
    weather: string;
    zipcode: string;
    temp?: number;
};
```
Save these definitions in a file called custom.d.ts in your root directory.
TSC should automatically load these definitions. You can now use the types
and interfaces from the file in your TypeScript modules.











A robust TypeScript type system lets you define complex, reusable shapes through **type aliases** and **interfaces**, both based on structural typing. ([JavaScript With Syntax For Types.][1]) 

While `type` aliases can represent primitives, unions, intersections, and mapped types, `interface` is optimized for defining object contracts and supports declaration merging. ([GeeksforGeeks][2])

You can compose types via **unions** (`A | B`) and **intersections** (`A & B`) to model flexible data, and leverage **generic** parameters to produce reusable abstractions. ([JavaScript With Syntax For Types.][3]) 

Finally, TypeScript’s built-in **utility types** (e.g. `Partial<T>`, `Pick<T,U>`) and custom **mapped types** let you transform existing types without code duplication. ([JavaScript With Syntax For Types.][4])

## 1. Type Aliases

### 1.1 Defining Simple Aliases

```ts
type ID = string | number;
type Point = { x: number; y: number };
```

* **`type`** aliases can name **unions**, **intersections**, **primitives**, and even **tuples** or **function signatures**. ([DigitalOcean][5])
* Aliases are purely compile-time and cannot be merged or extended after declaration. ([Total TypeScript][6])

### 1.2 Union & Intersection Types

```ts
type Success<T> = { status: "ok"; data: T };
type Failure = { status: "error"; message: string };
type Result<T> = Success<T> | Failure;

type A = { a: number };
type B = { b: string };
type AB = A & B; // { a: number; b: string }
```

* **Union (`|`)** lets a value be one of several types (e.g., success vs. failure).
* **Intersection (`&`)** merges multiple object shapes into one. ([JavaScript With Syntax For Types.][3])

## ## 2. Interfaces

### 2.1 Basic Object Contracts

```ts
interface User {
  id: ID;
  name: string;
  email?: string; // optional
}
```

* **`interface`** declares the *shape* of objects and supports `extends` for inheritance. ([JavaScript With Syntax For Types.][7])
* Interfaces are open—multiple declarations with the same name merge (declaration merging). ([Stack Overflow][8])

### 2.2 Extending & Implementing

```ts
interface Person { name: string }
interface Employee extends Person { salary: number }

class Manager implements Employee {
  constructor(public name: string, public salary: number) {}
}
```

* Use `extends` to build hierarchies and `implements` to enforce contracts on classes. ([Prismic][9])

## ## 3. Mapped & Utility Types

### 3.1 Built-in Utility Types

```ts
type ReadonlyUser = Readonly<User>;
type PartialUser = Partial<User>;
type RequiredUser = Required<User>;
type PickedUser = Pick<User, "id" | "name">;
```

* TypeScript ships with many generic transformers (`Partial`, `Readonly`, `Pick`, `Omit`, etc.) to reshape types. ([JavaScript With Syntax For Types.][4])

### 3.2 Custom Mapped Types

```ts
type Nullable<T> = { [P in keyof T]: T[P] | null };

type NullableUser = Nullable<User>; 
// { id: string|number|null; name: string|null; email?: string|null }
```

* Mapped types iterate over each property key (`keyof T`) to produce new forms. ([Angular Experts][10])

## ## 4. Generics for Reusability

```ts
interface ApiResponse<T> {
  status: number;
  payload: T;
  error?: string;
}

function fetchJson<T>(url: string): Promise<ApiResponse<T>> { /*…*/ }
```

* **Generics** (`<T>`) parameterize types or interfaces, enabling one definition to work with many data shapes. ([JavaScript With Syntax For Types.][3])

## ## 5. Declaration Merging (Interfaces Only)

```ts
interface Config { url: string }
interface Config { timeout: number }

const cfg: Config = { url: "…", timeout: 5000 };
```

* Duplicate `interface` names automatically merge their members, useful for augmenting third-party definitions. ([Stack Overflow][8])

## ## 6. Key Differences & When to Use Which

* **Interfaces**

  * Best for describing object shapes and OOP-style inheritance (`extends`, `implements`).
  * Support declaration merging.
* **Type Aliases**

  * Can name primitives, unions, intersections, tuples, and function signatures.
  * Cannot be reopened or merged. ([GeeksforGeeks][2])
* **Rule of thumb**: default to `type` for flexibility; switch to `interface` when you need merging or clear object inheritance. ([Total TypeScript][6])

## ## 7. Practical Examples

### 7.1 API Data Models

```ts
type Pagination = { page: number; perPage: number };
interface ListParams extends Pagination { sortBy?: string }

interface ApiError { code: number; message: string }
type ListResponse<T> = ApiResponse<{ items: T[]; total: number }>;
```

### 7.2 React Props

```tsx
type ButtonProps = {
  label: string;
  onClick(): void;
} & React.HTMLAttributes<HTMLButtonElement>;

const Button: React.FC<ButtonProps> = ({ label, onClick, ...rest }) => (
  <button onClick={onClick} {...rest}>{label}</button>
);
```

## ## 8. Best Practices

* **Prefer explicitness**: use `type` or `interface` consistently per team convention. ([Medium][11])
* **Leverage utility types** to avoid duplication.
* **Use declaration merging** sparingly to extend external declarations only when necessary.
* **Avoid overly complex mapped types** that hinder readability.

---

### Sources

1. Interfaces — TypeScript Handbook (typescriptlang.org)&#x20;
2. Utility Types — TypeScript Handbook (typescriptlang.org)&#x20;
3. TypeScript: Types vs Interfaces — Medium (medium.com)&#x20;
4. Type vs Interface: Which Should You Use? — Total TypeScript (totaltypescript.com)&#x20;
5. Advanced Types — TypeScript Handbook (typescriptlang.org)&#x20;
6. TypeScript Interfaces: A Practical Guide — Prismic (prismic.io)&#x20;
7. Interfaces vs Types in TypeScript — Stack Overflow (stackoverflow\.com)&#x20;
8. TypeScript Utility Types: Pick, Omit, Partial… — Medium (medium.com)&#x20;
9. A Comprehensive Comparison of Type vs Interface — SitePoint (sitepoint.com)&#x20;
10. TypeScript Interface Custom Types — DEV Community (dev.to)&#x20;

[1]: https://www.typescriptlang.org/play/typescript/language-extensions/types-vs-interfaces.ts.html?utm_source=chatgpt.com "Playground Example - Types vs Interfaces - TypeScript"
[2]: https://www.geeksforgeeks.org/what-is-the-difference-between-interface-and-type-in-typescript/?utm_source=chatgpt.com "What is the difference between interface and type in TypeScript"
[3]: https://www.typescriptlang.org/docs/handbook/advanced-types.html?utm_source=chatgpt.com "Documentation - Advanced Types - TypeScript"
[4]: https://www.typescriptlang.org/docs/handbook/utility-types.html?utm_source=chatgpt.com "Documentation - Utility Types - TypeScript"
[5]: https://www.digitalocean.com/community/tutorials/how-to-create-custom-types-in-typescript?utm_source=chatgpt.com "How To Create Custom Types in TypeScript - DigitalOcean"
[6]: https://www.totaltypescript.com/type-vs-interface-which-should-you-use?utm_source=chatgpt.com "Type vs Interface: Which Should You Use? - Total TypeScript"
[7]: https://www.typescriptlang.org/docs/handbook/interfaces.html?utm_source=chatgpt.com "Handbook - Interfaces - TypeScript"
[8]: https://stackoverflow.com/questions/37233735/interfaces-vs-types-in-typescript?utm_source=chatgpt.com "Interfaces vs Types in TypeScript - Stack Overflow"
[9]: https://prismic.io/blog/typescript-interfaces?utm_source=chatgpt.com "TypeScript Interfaces: A Practical Guide with Code Examples - Prismic"
[10]: https://angularexperts.io/blog/advanced-typescript/?utm_source=chatgpt.com "Advanced TypeScript - Angular Experts"
[11]: https://medium.com/%40leivadiazjulio/typescript-types-vs-interfaces-a-practical-guide-afdc8fef7515?utm_source=chatgpt.com "TypeScript: Types vs Interfaces — A Practical Guide | by Julio Leiva"
