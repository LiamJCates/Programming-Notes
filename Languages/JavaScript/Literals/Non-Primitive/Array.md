## Array literals

An array literal is a list of zero or more expressions, each of which represents an array element, enclosed in square brackets ([]). When you create an array using an array literal, it is initialized with the specified values as its elements, and its length is set to the number of arguments specified.

The following example creates the coffees array with three elements and a length of three:
```javascript
const coffees = ["French Roast", "Colombian", "Kona"];
```
An array literal creates a new array object every time the literal is evaluated. For example, an array defined with a literal in the global scope is created once when the script loads. However, if the array literal is inside a function, a new array is instantiated every time that function is called.

Note: Array literals create Array objects. See Array and Indexed collections for details on Array objects.

### Extra commas in array literals

If you put two commas in a row in an array literal, the array leaves an empty slot for the unspecified element. The following example creates the fish array:
```javascript
const fish = ["Lion", , "Angel"];
```
When you log this array, you will see:

```javascript
console.log(fish);
// [ 'Lion', <1 empty item>, 'Angel' ]
```

Note that the second item is "empty", which is not exactly the same as the actual undefined value. When using array-traversing methods like Array.prototype.map, empty slots are skipped. However, index-accessing fish[1] still returns undefined.

If you include a trailing comma at the end of the list of elements, the comma is ignored.

Note: Trailing commas help keep git diffs clean when you have a multi-line array, because appending an item to the end only adds one line, but does not modify the previous line.

```diff
const myList = [
  "home",
  "school",
+ "hospital",
];
```

Understanding the behavior of commas is important to understanding JavaScript as a language.

```javascript
const myList = ["home", , "school"];
//Length is three. All commas indicate a new element.

const myList = [, "home", , "school"]; 
//Length is four, and myList[0] and myList[2] are missing. All commas indicate a new element.

const myList = ["home", , "school", ,]; 
//Length is four, and myList[1] and myList[3] are missing. The last comma is ignored.
```

When writing your own code, you should explicitly declare the missing elements as undefined, or at least insert a comment to highlight its absence. Doing this increases your code's clarity and maintainability.

```javascript
const myList = ["home", /* empty */, "school", /* empty */, ];
```