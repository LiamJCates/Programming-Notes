The basic structure of a linked list requires us to have a pointer and to manage memory allocation and deallocation manually using the new and delete operators. Although it is not difficult, it can lead to bugs that are difficult to trace. Hence, just like std::array provides a thin wrapper over C-style arrays, std::forward_list provides a thin wrapper over a basic linked list.

The purpose of std::forward_list is to provide some additional functionality without compromising performance compared to a basic linked list. To maintain performance, it doesn't provide functions to get the size of the list or to get any element but the first one directly. Hence, it has a function called front() to get the reference to the first element, but nothing like back() to access the last element.

It does provide functions for common operations, such as insertion, deletion, reverse, and splice. These functions don't affect the memory requirements or performance over basic linked lists.

Additionally, just like std::vector, std::forward_list can also take a custom allocator as the second template parameter if required. Hence, we can easily use it for advanced applications that benefit from custom memory management.


## Inserting and Deleting Elements in forward_list

std:: forward_list provides the push_front and insert_after functions, which can be
used to insert an element in a linked list. Both of these are slightly different compared
to insertion functions for vectors. push_front is useful for inserting an element at the
front. Since forward_list doesn't have direct access to the last element, it doesn't
provide a push_back function. For insertion at a specific location, we use insert_after
instead of insert. This is because inserting an element in a linked list requires updating
the next pointer of the element, after which we want to insert a new element. If we
provide just the iterator, where we want to insert a new element, we can't get access to
the previous element quickly, since traversing backward is not allowed in forward_list.
Since this is a pointer-based mechanism, we don't really need to shift the elements
during insertion. Hence, both of the insertion functions are quite a bit faster compared
to any array-based structures. Both the functions just modify the pointers to insert
a new element at the intended position. This operation is not dependent on the size
of the list and therefore has a time complexity of O(1). We shall take a look at the
implementation of these functions in the following exercise.
Now, let's see how we can insert elements in a linked list:
std::forward_list<int> fwd_list = {1, 2, 3};
fwd_list.push_front(0);
// list becomes {0, 1, 2, 3}
auto it = fwd_list.begin();
fwd_list.insert_after(it, 5);
// list becomes {0, 5, 1, 2, 3}
fwd_list.insert_after(it, 6);
// list becomes {0, 6, 5, 1, 2, 3}
forward_list also provides emplace_front and emplace_after, which is similar to emplace
for a vector. Both of these functions do the same thing as insertion functions, but more
efficiently by avoiding extra copying and moving.
forward_list also has pop_front and erase_after functions for the deletion of elements.
pop_front, as the name suggests, removes the first element. Since it doesn't require
any shifting, the operation is quite fast in practice and has a time complexity of O(1).
erase_after has two overloads – to remove a single element (by taking an iterator to
its previous element), and to remove multiple elements in a range (by taking an iterator
to the element before the first element of the range and another iterator to the last
element).
The time complexity of the erase_after function is linear to the number of elements
that are erased because the deletion of elements can't be done via deallocating just a
single chunk of memory. Since all the nodes are scattered across random locations in
memory, the function needs to deallocate each of them separately.26 | Lists, Stacks, and Queues
Now, let's see how we can remove the elements from the list:
std::forward_list<int> fwd_list = {1, 2, 3, 4, 5};
fwd_list.pop_front();
// list becomes {2, 3, 4, 5}
auto it = fwd_list.begin();
fwd_list.erase_after(it);
// list becomes {2, 4, 5}
fwd_list.erase_after(it, fwd_list.end());
// list becomes {2}
Let's explore what other operations we can do with forward_list in the following
section.
Other Operations on forward_list
Apart from the erase functions to delete elements based on its position determined
by iterators, forward_list also provides the remove and remove_if functions to remove
elements based on their values. The remove function takes a single parameter – the
value of the elements to be removed. It removes all the elements that match the given
element based on the equality operator defined for the type of the value. Without
the equality operator, the compiler doesn't allow us to call that function and throws
a compilation error. Since remove only deletes the elements based on the equality
operator, it is not possible to use it for deletion based on other conditions, since we
can't change the equality operator after defining it once. For a conditional removal,
forward_list provides the remove_if function. It takes a predicate as a parameter, which
is a function taking an element of the value type as a parameter, and a Boolean as the
return value. So, all the elements for which the predicate returns true are removed from
the list. With the latest C++ versions, we can easily specify the predicate with lambdas
as well. The following exercise should help you to understand how to implement these
functions.std::forward_list | 2
