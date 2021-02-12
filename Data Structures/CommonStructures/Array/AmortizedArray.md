## Array Amortized Analysis

A dynamic array dynamically adjusts capacity during insertion and deletion. Most typically, the array doubles or haves in size.

This additional functionality often comes with a cost. We have to allocate a new array and copy over all of the elements.

Doing all that copying takes O(n) time, where n is the number of elements in our array. __Oof__ That's an expensive cost for an append. In a fixed-length array, appends only take O(1) time!

But appends take O(n) time only when we insert into either a full or quarter full array. And that's pretty rare, especially if we double or half the size of the array every time we adjust the capacity.

So in most cases appending is still O(1) time, and sometimes it's O(n) time.

Amortized analysis looks at the cost of appending averaged over a large number of appends.

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
