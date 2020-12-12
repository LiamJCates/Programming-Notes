A container adapter is a variation of a sequence or associative container that restricts the interface for simplicity and clarity. Container adapters don't support iterators.

A queue container follows FIFO (first in, first out) semantics. The first element pushed—that is, inserted into the queue—is the first to be popped—that is, removed from the queue.

A priority_queue container is organized such that the element that has the highest value is always first in the queue.

A stack container follows LIFO (last in, first out) semantics. The last element pushed on the stack is the first element popped.

Because container adapters don't support iterators, they can't be used with the C++ Standard Library algorithms.
