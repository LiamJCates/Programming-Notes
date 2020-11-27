The STL provides some 70 generic functions, called algorithms, that can be applied to
the STL containers and to arrays.


These
algorithms are implementing operations that are very frequently used in most programs, such as locating an element in a container, inserting an element into a sequence
of elements, removing an element from a sequence, modifying elements, comparing
elements, finding a value based on a sequence of elements, sorting the sequence of elements, and so on. Almost all STL algorithms use iterators to indicate the range of elements on which they operate. The first iterator references the first element of the range,
and the second iterator references an element after the last element of the range. Therefore, it is assumed that it is always possible to reach the position indicated by the second
iterator by incrementing the first iterator. Here are some examples.
The call
	 random_shuffle(c.begin(), c.end());


 randomly reorders all the elements of the container c. The call
 	 i3 = find(i1, i2, el);
 returns an iterator indicating the position of element el in the range i1 up to, but
 not including, i2. The call
 	 n = count_if(i1, i2, oddNum);
 counts with the algorithm count_if() the elements in the range indicated by iterators i1 and i2 for which a one-argument user-defined Boolean function oddNum()
 returns true.
 Algorithms are functions that are in addition to the member functions provided
 by containers. However, some algorithms are also defined as member functions to
 provide better performance.





The copy Algorithm
The STL
provides a convenient way to output the elements of a container with the help of
the function copy. The function copy is provided as a part of the generic algorithm
and can be used with any container type.

The function copy does more than output the elements of a container. In general, it allows us to copy the elements from one place to another.

template <class inputIterator, class outputIterator>
outputIterator copy(inputIterator first1, inputIterator last,
outputIterator first2);

The parameter first1 specifies the position from which to begin copying the elements; the parameter last specifies the end position, elements within the range first1...last-1 are copied

The parameter first2 specifies where to copy the elements. Therefore, the parameters first1 and last specify the source; parameter first2 specifies the destination.

The definition of the function template copy is contained in the header file algorithm.
Thus, to use the function copy, the program must include the statement
#include <algorithm>
