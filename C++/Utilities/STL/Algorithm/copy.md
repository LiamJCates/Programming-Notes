The copy Algorithm

The STL provides a convenient way to output the elements of a container with the help of the function copy. The function copy is provided as a part of the generic algorithm and can be used with any container type.

The function copy does more than output the elements of a container. In general, it allows us to copy the elements from one place to another.

template <class inputIterator, class outputIterator>
outputIterator copy(inputIterator first1, inputIterator last,
outputIterator first2);

The parameter first1 specifies the position from which to begin copying the elements; the parameter last specifies the end position, elements within the range first1...last-1 are copied

The parameter first2 specifies where to copy the elements. Therefore, the parameters first1 and last specify the source; parameter first2 specifies the destination.

The definition of the function template copy is contained in the header file algorithm.
Thus, to use the function copy, the program must include the statement
#include <algorithm>


### Copy_if

The copy_if function acts as a filter, copying only if the iterator elements satisfy the predicate.

copy_if() function is a library function of algorithm header, it is used to copy the elements of a container, it copies the certain elements (which satisfy the given condition) of a container from the given start position to another container from the given beginning position.

Note:To use copy_if() function – include <algorithm> header or you can simple use <bits/stdc++.h> header file.

Syntax of std::copy_if() function

    std::copy_if(
        iterator source_first,
        iterator source_end,
        iterator target_start,
        UnaryPredicate pred);

Parameter(s):

    iterator source_first, iterator source_end – are the iterator positions of the source container.
    iterator target_start – is the beginning iterator of the target container.
    UnaryPredicate pred – Unary function which accepts an element in the range as an argument, and returns a value convertible to bool.

Return value: iterator – it is an iterator to the end of the target range where elements have been copied.



C++ STL program to demonstrate use of std::copy_if() function

In this example, we are copying only positive elements of the array to the vector.

//C++ STL program to demonstrate use of
//std::copy_if() function
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    //declaring & initializing an int array
    int arr[] = { 10, 20, 30, -10, -20, 40, 50 };
    //vector declaration
    vector<int> v1(7);

    //copying 5 array elements to the vector
    copy_if(arr, arr + 7, v1.begin(), [](int i) { return (i >= 0); });

    //printing array
    cout << "arr: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    //printing vector
    cout << "v1: ";
    for (int x : v1)
        cout << x << " ";
    cout << endl;

    return 0;
}











Various varieties of copy() exist in C++ STL that allows to perform the copy operations in different manners, all of them having their own use. These all are defined in header <algorithm>. This article introduces everyone to these functions for usage in day-to-day programming.
1. copy(strt_iter1, end_iter1, strt_iter2) : The generic copy function used to copy a range of elements from one container to another. It takes 3 arguments:

    strt_iter1 : The pointer to the beginning of the source container, from where elements have to be started copying.
    end_iter1 : The pointer to the end of source container, till where elements have to be copied.
    strt_iter2 : The pointer to the beginning of destination container, to where elements have to be started copying.

2. copy_n(strt_iter1, num, strt_iter2) : This version of copy gives the freedom to choose how many elements have to be copied in the destination container. IT also takes 3 arguments:

    strt_iter1 : The pointer to the beginning of the source container, from where elements have to be started copying.
    num : Integer specifying how many numbers would be copied to destination container starting from strt_iter1. If a negative number is entered, no operation is performed.
    strt_iter2 : The pointer to the beginning of destination container, to where elements have to be started copying.

// C++ code to demonstrate the working of copy()
// and copy_n()

#include<iostream>
#include<algorithm> // for copy() and copy_n()
#include<vector>
using namespace std;

int main()
{

   // initializing source vector
   vector<int> v1 = { 1, 5, 7, 3, 8, 3 };

   // declaring destination vectors
   vector<int> v2(6);
   vector<int> v3(6);

   // using copy() to copy 1st 3 elements
   copy(v1.begin(), v1.begin()+3, v2.begin());

   // printing new vector
   cout << "The new vector elements entered using copy() : ";
   for(int i=0; i<v2.size(); i++)
   cout << v2[i] << " ";

   cout << endl;

   // using copy_n() to copy 1st 4 elements
   copy_n(v1.begin(), 4, v3.begin());

   // printing new vector
   cout << "The new vector elements entered using copy_n() : ";
   for(int i=0; i<v3.size(); i++)
   cout << v3[i] << " ";

}

Output:

The new vector elements entered using copy() : 1 5 7 0 0 0
The new vector elements entered using copy_n() : 1 5 7 3 0 0

3. copy_if(): As the name suggests, this function copies according to the result of a “condition“.This is provided with the help of a 4th argument, a function returning a boolean value.
This function takes 4 arguments, 3 of them similar to copy() and an additional function, which when returns true, a number is copied, else number is not copied.
4. copy_backward(): This function starts copying elements into the destination container from backward and keeps on copying till all numbers are not copied. The copying starts from the “strt_iter2” but in the backward direction. It also takes similar arguments as copy().

// C++ code to demonstrate the working of copy_if()
// and copy_backward()

#include<iostream>
#include<algorithm> // for copy_if() and copy_backward()
#include<vector>
using namespace std;

int main()
{

    // initializing source vector
    vector<int> v1 = { 1, 5, 6, 3, 8, 3 };

    // declaring destination vectors
    vector<int> v2(6);
    vector<int> v3(6);

    // using copy_if() to copy odd elements
    copy_if(v1.begin(), v1.end(), v2.begin(), [](int i){return i%2!=0;});

    // printing new vector
    cout << "The new vector elements entered using copy_if() : ";
    for(int i=0; i<v2.size(); i++)
    cout << v2[i] << " ";

    cout << endl;

    // using copy_backward() to copy 1st 4 elements
    // ending at second last position
    copy_backward(v1.begin(), v1.begin() + 4, v3.begin()+ 5);

    // printing new vector
    cout << "The new vector elements entered using copy_backward() : ";
    for(int i=0; i<v3.size(); i++)
    cout << v3[i] << " ";

}

Output:


The new vector elements entered using copy_if() : 1 5 3 3 0 0
The new vector elements entered using copy_backward() : 0 1 5 6 3 0

5. Copy using inserter():

Before copy() operation let us understand the syntax of inserter().

inserter() is used as a destination that where we want to copy the elements of the container.

inserter() takes two parameters. The first is a container of arbitrary type and the second is an iterator into the container.

It returns an instance of insert_iterator working on a container of arbitrary type. This wrapper function helps in creating insert_iterator instances. Typing the name of the %iterator requires knowing the precise full type of the container, which can be tedious and impedes generic programming. Using this function lets you take advantage of automatic template parameter deduction, making the compiler match the correct types for you.

The syntax for inserter():

std::inserter(Container& x, typename Container::iterator it);

x: Destination container where the new elements will
be inserted.
it: Iterator pointing to the insertion point.

Returns: An insert_iterator that inserts elements into
x at the position indicated by it.

The syntax for copy using inserter():

copy(strt_iter1, end_iter1, inserter(Container& x, typename Container::iterator it));

```cpp
// C++ code to demonstrate the working of copy() using inserter()

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{

    vector<int> v1 = {1, 5, 7, 3, 8, 3};
    vector<int>::iterator itr;
    vector<int> v2;

    //using inserter()
    copy(v1.begin(), v1.end(), inserter(v2, itr));

    cout << "\nThe new vector elements entered using inserter: ";
    for (int i = 0; i < v2.size(); i++)
        cout << v2[i] << " ";
}
```



```cpp
#include <iostream>
#include <iterator>
#include <algorithm>
#include <sstream>
int main()
{
    std::istringstream stream("1 2 3 4 5");
    std::copy(
        std::istream_iterator<int>(stream),
        std::istream_iterator<int>(),
        std::ostream_iterator<int>(std::cout, " ")
    );
}
```
