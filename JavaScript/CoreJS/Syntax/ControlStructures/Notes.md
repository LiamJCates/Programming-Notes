if else conditional statements


## loops

### while

```js
while (true) {
  // an infinite loop!
}
```

### do-while

```js
var input;
do {
  input = get_input();
} while (inputIsNotValid(input));
```

### for loops

```js
for (var i = 0; i < 5; i++) {
  // Will execute 5 times
}
```

JavaScript also contains two other prominent for loops:

for...of

```js
for (let value of array) {
  // do something with value
}
```

for...in

```js
for (let property in object) {
  // do something with object property
}
```



### switch

The switch statement can be used for multiple branches based on a number or string:

```js
switch (action) {
  case 'draw':
    drawIt();
    break;
  case 'eat':
    eatIt();
    break;
  default:
    doNothing();
}
```
If you don't add a break statement, execution will "fall through" to the next level. This is very rarely what you want — in fact it's worth specifically labeling deliberate fallthrough with a comment if you really meant it to aid debugging:

```js
switch (a) {
  case 1: // fallthrough
  case 2:
    eatIt();
    break;
  default:
    doNothing();
}
```

The default clause is optional. You can have expressions in both the switch part and the cases if you like; comparisons take place between the two using the === operator:

```js
switch (1 + 3) {
  case 2 + 2:
    yay();
    break;
  default:
    neverhappens();
}
```
