## Semicolons
Semicolons separate JavaScript statements.

A semicolon at the end of a line indicates where a statement ends. It is only required when you need to separate statements on a single line. However, some people believe it's good practice to have semicolons at the end of each statement. Ending statements with semicolon is not required, but highly recommended. A terminal semicolon can be omitted if the statement is followed by a line break (or there’s only one statement in a {block})

#### Avoid!

1. After a closing curly bracket

You shouldn’t put a semicolon after a closing curly bracket }. The only exceptions are assignment statements, such as var obj = {};

2. After the round bracket of an if, for, while or switch statement

It won't harm to put a semicolon after the { } of an if statement (it will be ignored, and you might see a warning that it's unnecessary). But a semicolon where it doesn't belong (such as after the round (brackets) of an if, for, while, or switch statement) will result in logical errors

### How to fix your semicolons

The JavaScript syntax proofing tool JSLint, does a pretty good job of finding unnecessary semicolons – or missing ones.
