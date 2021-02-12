## Static Array

A static array has a fixed capacity that must be known at time of array instantiation and are thus also known as fixed-capacity or fixed-size arrays.

Most languages have a built in static array type

Advantages of Static Arrays
1. Efficient Access
	Elements are stored in adjacent memory locations; hence, search and access is very fast, as any element can be easily located.

2. Minimal Overhead
	Static arrays do not support dynamic memory allocation, so all the memory management is done by the system.

Limitations of Static Arrays
1. Size Alteration
	Insertion and deletion of elements in arrays is complicated and very time-consuming, as it requires the shifting of elements.

2. Static Size
	The size of the static array must be known in advance and cannot be changed during execution. This means arrays can potentially require more or less size than necessary for collections with high size fluctuation


	Operation Complexity

	  Traverse − O(n)
	
	  Insertion − O(n) Worst O(1) End

	  Deletion − O(n) Worst O(1) End

	  Search − O(n)

	  Update − O(1)
