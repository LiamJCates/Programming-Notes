std :: remove

It is defined in <algorithm> library. It removes value from range. Transforms the range [first,last) into a range with all the elements that compare equal to val removed, and returns an iterator to the new end of that range.

    The function cannot alter the properties of the object containing the range of elements (i.e., it cannot alter the size of an array or a container).
    The relative order of the elements not removed is preserved, while the elements between the returned iterator and last are left in a valid but unspecified state.
    The function uses operator== to compare the individual elements to val.

Function Template :  

ForwardIterator remove  (ForwardIterator first,
ForwardIterator last, const T& val)

first,last :
  The range used is [first,last), which contains all the
elements between first and last, including the element
pointed by first but not the element pointed by last.

val :
Value to be removed.

Return value :
An iterator to the element that follows the last element not removed.
The range between first and this iterator includes all the elements
in the sequence that do not compare equal to val.

Example:  

Input : 10 20 30 30 20 10 10 20
Output : 10 30 30 10 10    // Value removed is 20.

std :: remove_if


Transforms the range [first,last) into a range with all the elements for which pred returns true removed, and returns an iterator to the new end of that range.
Function Template :  

  ForwardIterator remove_if (ForwardIterator first,
  ForwardIterator last, UnaryPredicate pred);

pred
Unary function that accepts an element in the range as
argument, and returns a value convertible to bool. The
value returned indicates whether the element is to be
removed (if true, it is removed).
The function shall not modify its argument.
This can either be a function pointer or a function object.

Example:  

Input : 1 2 3 4 5 6 7 8 9 10
Output : 2 4 6 8 10    // Odd elements removed.

```cpp
// CPP program to illustrate std::remove and std::remove_if algorithm
#include <bits/stdc++.h>

// Function to check whether
// the element is odd or not.
bool IsOdd(int i) { return ((i % 2) == 1); }

// Driver code
int main()
{
    std ::vector<int> vec1{
        10, 20, 30, 30, 20, 10, 10, 20
    };
    std ::vector<int> vec2{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    // Print original vector
    std ::cout << "Original vector : ";
    for (int i = 0; i < vec1.size(); i++)
        std ::cout << " " << vec1[i];
    std ::cout << "\n";

    // Iterator that store the position of last element
    std ::vector<int>::iterator pend;

    // std ::remove function call
    pend = std ::remove(vec1.begin(), vec1.end(), 20);

    // Print the vector
    std ::cout << "After remove : ";
    for (std ::vector<int>::iterator p = vec1.begin();
         p != pend; ++p)
        std ::cout << ' ' << *p;
    std ::cout << '\n';

    // Print original vector
    std ::cout << "\nOriginal vector : ";
    for (int i = 0; i < vec2.size(); i++)
        std ::cout << " " << vec2[i];
    std ::cout << "\n";

    // std ::remove_if function call
    pend = std ::remove_if(vec2.begin(), vec2.end(), IsOdd);

    // the same of the above can be done using lambda
    // function in 1 line
    pend = std ::remove_if(
        vec2.begin(), vec2.end(),
        [](int i) { return ((i % 2) == 1); });

    // Print the vector
    std ::cout << "After remove_if : ";
    for (std ::vector<int>::iterator q = vec2.begin();
         q != pend; ++q)
        std ::cout << ' ' << *q;
    std ::cout << '\n';

    return 0;
}```
