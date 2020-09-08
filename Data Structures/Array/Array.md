# Arrays

## Simple Array

An array is a contiguous collection of same typed data<br/>
The members of an array collection are called elements
<br/><br/>
Properties of arrays are its capacity, type, and size:
* Capacity is generally the number of items that the array can potentially store
* Type specifies the type of items stored by an array, the type of these items determines the memory space needed by each individual array member
* Array size is the size of an array in memory and it determined by the capacity * item memory size
<br/><br/>

A basic array has a fixed capacity that must be known at time of array instantiation and are thus known as fixed-capacity or fixed-size arrays.
<br/><br/>

## Dynamic Array

When using arrays as underlying storage for more complex data structures techniques are used to allow the array to resize or have a dynamic capacity.
<br/><br/>
dynamic arrays (also called resizable, growable, or extensible) are array variables whose index ranges may be expanded at any time after creation, without changing the values of its current elements.
<br/><br/>
A dynamic array can be implemented as a fixed-size array, with a counter that records how many elements are actually in use. The add/remove operations merely increments or decrement the counter accordingly, along with altering the collection by adding or removing an item, respectively. Once a threshold size is achieved, these operations then allocate a new array with a larger or smaller size, and copy the old elements to the new array then reassign the old arrays reference to point to the new array.
<br/><br/>
Generally:<br/>
When inserting, if the number of items stored in the array is equal to the capacity<br/>
* create another array of the same type and double capacity
* copy the members from the old to the new array
* reassign the reference
<br/><br/>

When removing items, if the number of items stored in the array is equal to capacity/4<br/>
* create another array of the same type and half the capacity
* copy the members from the old to the new array
* reassign the reference
<br/><br/>

## Array Amortized Analysis

A dynamic array automatically grows when you try to make an insertion and there is no more space left for the new item. Usually, the array doubles in size.

This additional functionality often comes with a cost. When we don't have any space for a new item, we have to allocate a bigger array and copy over all of the elements from the array we've outgrown before we can finally append our item.

Doing all that copying takes O(n) time, where n is the number of elements in our array.
Oof. That's an expensive cost for an append. In a fixed-length array, appends only take O(1) time!

But appends take O(n) time only when we insert into a full array. And that's pretty rare, especially if we double the size of the array every time we run out of space.

So in most cases appending is still O(1) time, and sometimes it's O(n) time.
Amortized analysis looks at the cost of a single append averaged over a large number of appends.

"Amortize" is a fancy verb used in finance that refers to paying off the cost of something gradually. With dynamic arrays, every expensive append where we have to grow the array "buys" us many cheap appends in the future. Conceptually, we can spread the cost of the expensive append over all those cheap appends.
Here, instead of looking at the worst case for an append individually, let's look at the overall cost of doing many appends—let's say m appends.
The cost of doing m appends is initially m, plus the cost of any doubling when the dynamic array needs to grow. How much does the doubling cost?
Say we start off with space for just one item. Then the first doubling costs 1. The second costs 2. The third costs 4. The fourth costs 8.

So, the cost we're looking at is:        Or from right to left:
1+2+4+8+...+m/2+m             m+m/2+m/4+...+4+2+1

We can see a trend when we represent this diagrammatically:

If this is m:<br/>
![A](https://github.com/LiamJCates/Programming-Notes/blob/master/Data%20Structures/Array/images/Array_m.png)<br/>
m/2​ is half the size:<br/>
![A/2](https://github.com/LiamJCates/Programming-Notes/blob/master/Data%20Structures/Array/images/Array_m2.png)<br/>
m/4 is half that:<br/>
![A/4](https://github.com/LiamJCates/Programming-Notes/blob/master/Data%20Structures/Array/images/Array_m4.png)<br/>
And so on:<br/>
![A/8](https://github.com/LiamJCates/Programming-Notes/blob/master/Data%20Structures/Array/images/Array_m8.png)<br/>

We see that the whole right side ends up being another square of size m, making the sum 2m.<br/><br/>

For m appends, the appends themselves cost m, and the doubling costs 2m.<br/> This is a total cost of 3m, which is O(m).
<br/><br/>
Therefore, on average, each individual append is O(1) and m appends cost us O(m).
<br/><br/>
Remember, even though the amortized cost of an append is O(1), the worst case cost is still O(n). Some appends will take a long time.
