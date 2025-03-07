a circular buffer, circular queue, cyclic buffer or ring buffer is a data structure that uses a single, fixed-size buffer as if it were connected end-to-end.

This structure lends itself easily to buffering data streams.

Circular buffering makes a good implementation strategy for a queue that has fixed maximum size. Should a maximum size be adopted for a queue, then a circular buffer is a completely ideal implementation; all queue operations are constant time. However, expanding a circular buffer requires shifting memory, which is comparatively costly. For arbitrarily expanding queues, a linked list approach may be preferred instead.

A circular buffer can be implemented using four pointers, or two pointers and two integers:
  buffer start in memory
  buffer end in memory, or buffer capacity
  start of valid data (index or pointer)
  end of valid data (index or pointer), or amount of data currently in the buffer (integer)


When an element is overwritten, the start pointer is incremented to the next element.

In utilizing full buffer capacity with pointer-based implementation strategy, the buffer's full or empty state could not be resolved directly from checking the positions of the start and end indexes. Therefore, an additional mechanism must be implemented for checking this. One common way to deal with this, when using 2 pointers, is to only allow the buffer to hold (size − 1) items. When both pointers are equal, the buffer is empty, and when the end pointer is one less than the start pointer, the buffer is full.

When the buffer is instead designed to track the number of inserted elements n, checking for emptiness means checking n = 0 and checking for fullness means checking whether n equals the capacity.

Incrementing and decrementing the circular buffer address pointers is accomplished in software using the following modulus formulas:

   increment_address_one = (address + 1) % Length
   
   decrement_address_one = (address + Length - 1) % Length
