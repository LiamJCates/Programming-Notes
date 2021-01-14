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
