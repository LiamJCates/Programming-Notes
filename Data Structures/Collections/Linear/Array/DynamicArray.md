## Dynamic Array

When using arrays as underlying storage for more complex data structures techniques are necessary to allow the array to resize, known as a dynamic capacity.

These so called dynamic arrays (also called resizable, growable, or extensible) are array variables whose index ranges may be altered after instantiation.

Many languages have built in support for dynamic arrays that present an interface for the array ADT.


### Implementing Dynamic Arrays

A simple dynamic array can be constructed by allocating an array of fixed-size.

The elements of the dynamic array are stored contiguously at the start of the underlying array, and the remaining positions towards the end of the underlying array are reserved, or unused. Elements can be added at the end of a dynamic array in constant time by using the reserved space, until this space is completely consumed. When all space is consumed, and an additional element is to be added, then the underlying fixed-sized array needs to be increased in size.

Typically resizing is expensive because it involves allocating a new underlying array and copying each element from the original array. Elements can be removed from the end of a dynamic array in constant time, as no resizing is required. The number of elements used by the dynamic array contents is its logical size or size, while the size of the underlying array is called the dynamic array's capacity or physical size, which is the maximum possible size without relocating data.


The static array has a fixed capacity and
The counter is used to record how many elements are actually in use.

The add/remove operations merely increments or decrement the counter accordingly, along with altering the collection by adding or removing an item, respectively. Once a threshold size is achieved, these operations then allocate a new array with a larger or smaller size, and copy the old elements to the new array then reassign the old arrays reference to point to the new array.
<br/><br/>
Generally:<br/>
When inserting, if, before the insertion, the number of items stored in the array is equal to the capacity<br/>
* create another array of the same type and double capacity
* copy the members from the old to the new array
* reassign the old array reference
* perform the intended addition


When removing items, if, after the removal, the number of items stored in the array is equal to capacity/4
* create another array of the same type and half the capacity
* copy the members from the old to the new array
* reassign the old array reference
