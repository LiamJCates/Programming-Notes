At its core, TypeScript’s type system is structural: you describe shapes of data rather than nominal classes ([W3Schools.com][1]). 

You can define custom types via **type aliases** (for primitives, unions, tuples, mapped types, etc.) or **interfaces** (object contracts that support extension and declaration merging) ([JavaScript With Syntax For Types.][2], [JavaScript With Syntax For Types.][3]). 

Inside object types, you can mark properties as optional (`?`), readonly, indexed, or even use generics and mapped types to derive new types from existing ones ([JavaScript With Syntax For Types.][5], [JavaScript With Syntax For Types.][6]).

Advanced techniques include **union** and **intersection** types for flexible composition, **literal** and **template literal** types for precise string shapes, and **utility** and **custom mapped** types for transformations ([JavaScript With Syntax For Types.][3], [JavaScript With Syntax For Types.][7]).

To share types across files or with consumers of a library, you author **declaration files** (`.d.ts`), which contain only type information and never emit JavaScript ([JavaScript With Syntax For Types.][4]).  

---

## 1. Defining Custom Types

### 1.1 Type Aliases

* **Syntax**: `type Name = Definition;` lets you name any type expression—primitive, union, intersection, tuple, function signature, or mapped type ([W3Schools.com][1]).
* **Examples**:

  ```ts
  type ID = string | number;
  type Point = { x: number; y: number };
  type Callback = (err: Error|null, result?: any) => void;
  type ReadonlyStrings = readonly string[];
  ```
* **Use Cases**: alias complex unions (e.g. `type Status = "success" | "error" | "pending"`), parameterize generics (`type ApiResponse<T> = { payload: T; error?: string }`), or define tuple types (`type NameAge = [string, number]`) ([DigitalOcean][8]).

### 1.2 Interfaces

* **Syntax**: `interface Name { /* members */ }` is optimized for object shapes and supports extension via `extends` and merging across declarations ([JavaScript With Syntax For Types.][2]).
* **Examples**:

  ```ts
  interface User {
    id: ID;
    name: string;
    email?: string;      // optional property
    readonly createdAt: Date;
  }

  interface Admin extends User {
    role: "super" | "normal";
  }
  ```
* **Declaration Merging**: multiple `interface Config { … }` blocks with the same name merge into one type—useful for augmenting third-party libraries ([JavaScript With Syntax For Types.][9]).

---

## 2. Declaration Files (`.d.ts`)

* **Purpose**: Bundled with libraries or authored alongside `.ts` files, `.d.ts` files declare the public API’s types without emitting any JS code ([JavaScript With Syntax For Types.][4]).
* **Basic Structure**:

  ```ts
  // index.d.ts
  export interface MyLibOptions { url: string; timeout?: number }
  export function initialize(opts: MyLibOptions): void;
  ```
* **Module Layout**: Mirror your runtime module structure so that `import { x } from "my-lib/foo"` is matched by `foo.d.ts` in your type declarations ([JavaScript With Syntax For Types.][10]).
* **Triple-Slash Directives**: Use `/// <reference types="..." />` or `paths` in `tsconfig.json` for multi-package setups ([JavaScript With Syntax For Types.][11]).

---

## 3. Optional & Readonly Properties

* **Optional Properties**: Add `?` after the property name to indicate it may be omitted. Common in configuration “option bags.” ([JavaScript With Syntax For Types.][2])

  ```ts
  interface ChartOptions {
    width?: number;
    height?: number;
    title?: string;
  }
  ```
* **Readonly Properties**: Prefix with `readonly` to prevent assignment after initialization. Useful for immutable data. ([JavaScript With Syntax For Types.][5])

  ```ts
  interface Point {
    readonly x: number;
    readonly y: number;
  }
  ```

---

## 4. Advanced Type Constructs

### 4.1 Unions & Intersections

* **Union (`A | B`)**: value may conform to any of the member types; ideal for discriminated unions. ([JavaScript With Syntax For Types.][3])
* **Intersection (`A & B`)**: merges multiple object types into one containing all members. ([JavaScript With Syntax For Types.][3])

```ts
type Success = { status: "ok"; data: unknown };
type Error   = { status: "error"; message: string };
type Result = Success | Error;        // union

type WithID = { id: string } & User;  // intersection
```

### 4.2 Literal & Template Literal Types

* **String/Number Literals**: restrict values to specific constants (`type Direction = "north" | "south"`).
* **Template Literal Types**: compose new string types from others (`type EventName = `on\${Capitalize<keyof Handlers>}\`\`) ([JavaScript With Syntax For Types.][7]).

### 4.3 Generics

* **Syntax**: `<T, U extends Base>` parameterizes types/functions/classes.
* **Example**:

  ```ts
  function wrapArray<T>(x: T): T[] { return [x]; }
  interface ApiResponse<T> { data: T; error?: string }
  ```
* **Use Cases**: reusable data structures, typed containers, and polymorphic APIs ([JavaScript With Syntax For Types.][6]).

### 4.4 Mapped & Utility Types

* **Mapped Types**: iterate over keys to transform types (`type Nullable<T> = { [P in keyof T]?: T[P] | null }`). ([JavaScript With Syntax For Types.][12])
* **Built-in Utilities**: `Partial<T>`, `Required<T>`, `Readonly<T>`, `Pick<T,K>`, `Omit<T,K>`, etc. ([JavaScript With Syntax For Types.][13])

```ts
type PartialUser = Partial<User>;       // all props optional
type ReadonlyUser = Readonly<User>;     // all props readonly
type NameEmail = Pick<User, "name"|"email">;
```

---

## 5. Best Practices

1. **Prefer `type` aliases** for unions, intersections, tuples, and function signatures; use **`interface`** for object-shaped contracts and when you need declaration merging ([JavaScript With Syntax For Types.][3]).
2. **Keep `.d.ts` files in sync** with implementation or generate them via `declaration: true` in `tsconfig.json` to avoid drift ([JavaScript With Syntax For Types.][4]).
3. **Use optional (`?`) and `readonly` modifiers** judiciously\*\* to model optional fields and immutable data ([JavaScript With Syntax For Types.][5]).\*\*
4. **Leverage utility types** and custom mapped types to DRY up repetitive patterns and enforce consistency ([JavaScript With Syntax For Types.][13]).
5. **Document discriminated unions** clearly (e.g., a `status` tag) to aid type narrowing and reduce runtime errors ([DigitalOcean][8]).
6. **Avoid overly complex conditional and mapped types** that can hurt readability—favor clarity over cleverness ([JavaScript With Syntax For Types.][14]).

---

### Sources

1. Type Declarations (`.d.ts` files) — TypeScript Handbook
2. Interfaces — TypeScript Handbook
3. Type Aliases and Interfaces — W3Schools
4. Unions & Intersections — TypeScript Handbook
5. How To Create Custom Types in TypeScript — DigitalOcean
6. Declaration Merging — TypeScript Handbook
7. Generics — TypeScript Handbook
8. Basic Types & Property Modifiers — TypeScript Handbook
9. Module Declaration File Layout — TypeScript Handbook
10. Utility Types — TypeScript Handbook
11. Everyday Types — TypeScript Handbook
12. Introduction to Declaration Files — TypeScript Handbook
13. TypeScript vs. JavaScript — MDN Glossary
14. Template Literal Types — TypeScript Handbook
15. Declaration Merging Use Cases — DEV Community

[1]: https://www.w3schools.com/typescript/typescript_aliases_and_interfaces.php?utm_source=chatgpt.com "TypeScript Type Aliases and Interfaces - W3Schools"
[2]: https://www.typescriptlang.org/docs/handbook/interfaces.html?utm_source=chatgpt.com "Handbook - Interfaces - TypeScript"
[3]: https://www.typescriptlang.org/docs/handbook/unions-and-intersections.html?utm_source=chatgpt.com "Handbook - Unions and Intersection Types - TypeScript"
[4]: https://www.typescriptlang.org/docs/handbook/2/type-declarations.html?utm_source=chatgpt.com "Documentation - Type Declarations - TypeScript"
[5]: https://www.typescriptlang.org/docs/handbook/2/objects.html?utm_source=chatgpt.com "Documentation - Object Types - TypeScript"
[6]: https://www.typescriptlang.org/docs/handbook/2/generics.html?utm_source=chatgpt.com "Documentation - Generics - TypeScript"
[7]: https://www.typescriptlang.org/docs/handbook/2/template-literal-types.html?utm_source=chatgpt.com "Documentation - Template Literal Types - TypeScript"
[8]: https://www.digitalocean.com/community/tutorials/how-to-create-custom-types-in-typescript?utm_source=chatgpt.com "How To Create Custom Types in TypeScript - DigitalOcean"
[9]: https://www.typescriptlang.org/docs/handbook/declaration-merging.html?utm_source=chatgpt.com "Documentation - Declaration Merging - TypeScript"
[10]: https://www.typescriptlang.org/docs/handbook/declaration-files/templates/module-d-ts.html?utm_source=chatgpt.com "Documentation - Modules .d.ts - TypeScript"
[11]: https://www.typescriptlang.org/docs/handbook/declaration-files/introduction.html?utm_source=chatgpt.com "Documentation - Introduction - TypeScript"
[12]: https://www.typescriptlang.org/docs/handbook/advanced-types.html?utm_source=chatgpt.com "Documentation - Advanced Types - TypeScript"
[13]: https://www.typescriptlang.org/docs/handbook/utility-types.html?utm_source=chatgpt.com "Documentation - Utility Types - TypeScript"
[14]: https://www.typescriptlang.org/docs/handbook/2/everyday-types.html?utm_source=chatgpt.com "Documentation - Everyday Types - TypeScript"
