Semaphores

A semaphore is another synchronization mechanism that can be used to control access to shared resources sort of like a mutex, but unlike a mutex a semaphore can allow multiple threads to access the resource at the same time, and it includes a counter to track how many times it's been acquired or released.

As long as the semaphore's count value is positive, any thread can use acquire() which then decrements that counter value. If the counter reaches zero then threads trying to acquire the semaphore will be blocked and placed in a queue to wait until it's available.

When a thread is done using the resources it uses releas() which increments that counter value. And if there are any other threads waiting to acquire the semaphore, they'll be signaled to wake up and do so.

This type of semaphore is called a counting semaphore because it can have a value of zero, one, two, three, and so on, to represent the number of resources we have.

In software a counting semaphore might be used to manage access among multiple threads to a limited pool of connections for something like a server or a database. Or, a counting semaphore could be used to track how many items are in a queue.

Now it's also common to restrict the possible values of a semaphore to only being either zero or one, with zero representing a locked state, and one representing unlocked. This is called a binary semaphore and at first glance it looks a lot like a mutex. In fact, it can be used just like a mutex with a threat acquiring and releasing the semaphore to lock and unlock it.

However, there is a key difference. A mutex can only be unlocked by the same thread that originally locked it. A semaphore on the other hand can be acquired and released by different threads. Any thread can increment the semaphore's value by releasing it or attempt to decrement the value by acquiring it. That may sound like a recipe for trouble, and it certainly can be if you're not careful, but the ability for different threads to increment and decrement a semaphore's value and for threads to wait and be signaled by the semaphore is what enables it to be used as a signaling mechanism to synchronize the action between threads.

For example, a pair of semaphores can be used in a similar way to condition variables to synchronize producer and consumer threads adding and removing elements from a shared finite queue or buffer. One semaphore tracks the number of items in the buffer, shown here as fillCount, and the other one tracks the number of free spaces, which I'll call empty count. To add an element to the buffer, the producer will first acquire the empty count which decrements its value. Then it pushes the item into the buffer, and finally, it releases the fill count semaphore to increment its value. Now on the other side of the buffer, when the consumer wants to take an item it first acquires fillCount to decrement its value, then it removes an item from the buffer, and finally, increments the empty count by releasing it. Notice that the producer and the consumer each acquire a different semaphore as the first operation in their respective sequences. If the consumer tries to take an item when the buffer is empty then when it tries to acquire that fill count semaphore it'll block and wait until a producer adds an item and releases fill count which will then signal the consumer to continue. Likewise, if the producer tries to add an item to the full buffer, then it goes to acquire the empty count semaphore, it'll block and wait until a consumer removes an item and releases the empty count.



### Semaphore Example

At the time of this writing, in the first half of 2020, the C++ standard library doesn't formally include a semaphore class. That should change in the future when the C++ 20 Standard is officially published, and fully implemented with compilers, but we're not quite there yet. Until then, the well known Boost C++ library does include a semaphore class, if you want something ready to use.

Or you can implement your own semaphore class, which is what we've done for this example

```cpp
#include <thread>
#include <chrono>
#include <mutex>
#include <condition_variable>

class Semaphore {
public:
    Semaphore(unsigned long init_count) {
        count_ = init_count;
    }

    void acquire() { // decrement the internal counter
        std::unique_lock<std::mutex> lck(m_);
        while (!count_) {
            cv_.wait(lck);
        }
        count_--;
    }

    void release() { // increment the internal counter
        std::unique_lock<std::mutex> lck(m_);
        count_++;
        lck.unlock();
       cv_.notify_one();
    }

private:
    std::mutex m_;
    std::condition_variable cv_;
    unsigned long count_;
};

Semaphore charger(4);

void cell_phone(int id) {
    charger.acquire();
    printf("Phone %d is charging...\n", id);
    srand(id); // charge for "random" amount between 1-3 seconds
    std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 2000 + 1000));
    printf("Phone %d is DONE charging!\n", id);
    charger.release();
}

int main() {
    std::thread phones[10];
    for (int i=0; i<10; i++) {
        phones[i] = std::thread(cell_phone, i);
    }
    for (auto& p : phones) {
        p.join();
    }
}
```
Output:
```
Phone 0 is charging...
Phone 1 is charging...
Phone 2 is charging...
Phone 4 is charging...
Phone 4 is DONE charging!
Phone 5 is charging...
Phone 2 is DONE charging!
Phone 3 is charging...
Phone 0 is DONE charging!
Phone 1 is DONE charging!
Phone 6 is charging...
Phone 7 is charging...
Phone 6 is DONE charging!
Phone 8 is charging...
Phone 5 is DONE charging!
Phone 9 is charging...
Phone 3 is DONE charging!
Phone 7 is DONE charging!
Phone 9 is DONE charging!
Phone 8 is DONE charging!
```

starting on line nine. We built the semaphore class using a mutex, a condition variable and a count variable, which are defined down on line 31 through 33.

The semaphore's constructor function on line 11 accepts the initial value to set the count variable.

When you call the semaphore's acquire function on line 15 it initializes a unique lock on the mutex, and then uses a while loop to wait if the count has been decreased down to zero. This is similar to the use of a condition variable. After this thread gets notified on the condition variable that the count has been increased, it can move past the while loop to decrement the count variable on line 20.

In the release function, after locking the mutex, the function increments the count variable on line 23 then releases the lock and notifies the condition variable.

Scrolling down on line 36, we initialize a new semaphore named charger and initialize it to have a count value of four, representing the number of available charging ports.

The cell_phone function attempts to acquire the charger semaphore on line 39. If the semaphore is not available, because its count value is zero, then the thread will wait there until a charging port opens up and the semaphore is released.

Once a cell_phone thread has acquired the semaphore, it prints a message that it's charging, and then sleeps for a random amount of time from one to two seconds. After that, the cell_phone prints a message that it's done charging, and then releases the semaphore on line 44 to increment its value, so another thread can acquire it.

Down in the main section of the program, we use a simple for loop to create and start 10 cell_phone threads. That's a lot of cell phones to charge at once.

When we run this program, I see that four of the phones connect immediately at the beginning. Then as each phone finishes charging and releases the semaphore, another phone acquires it and begins charging. At most, there will be four phones connected to the charger at any given time.


Now instead of using it as a counting semaphore, if I change the initialization value for the semaphore on line 36 from four to just one, it will act as a binary semaphore.

Semaphore charger(1);

When I make and run this program, now only one thread at a time will be able to acquire the semaphore.


Output
```
Phone 0 is charging...
Phone 0 is DONE charging!
Phone 1 is charging...
Phone 1 is DONE charging!
Phone 2 is charging...
Phone 2 is DONE charging!
Phone 3 is charging...
Phone 3 is DONE charging!
Phone 4 is charging...
Phone 4 is DONE charging!
Phone 5 is charging...
Phone 5 is DONE charging!
Phone 6 is charging...
Phone 6 is DONE charging!
Phone 7 is charging...
Phone 7 is DONE charging!
Phone 8 is charging...
Phone 8 is DONE charging!
Phone 9 is charging...
Phone 9 is DONE charging!
```
The way we're using the binary semaphore now with the same thread that acquires it also being the one to release it, means it's basically acting the same as a mutex. In fact, we could replace the charger semaphore with a mutex in this particular program, and it would function in a similar way.





























In 1965, Dijkstra proposed a new and very significant technique for managing concurrent processes by using the value of a simple integer variable to synchronize the progress of interacting processes. This integer variable is called a semaphore. So it is basically a synchronizing tool and is accessed only through two low standard atomic operations, wait and signal designated by P(S) and V(S) respectively.

In very simple words, the semaphore is a variable that can hold only a non-negative Integer value, shared between all the threads, with operations wait and signal, which work as follow:

P(S): if S >= 1 then S := S - 1
      else <block and enqueue the process>;

V(S): if <some process is blocked on the queue>
        then <unblock a process>
      else S := S + 1;

The classical definitions of wait and signal are:

    Wait: This operation decrements the value of its argument S, as soon as it would become non-negative(greater than or equal to 1). This Operation mainly helps you to control the entry of a task into the critical section. In the case of the negative or zero value, no operation is executed. wait() operation was originally termed as P; so it is also known as P(S) operation. The definition of wait operation is as follows:

wait(S)
{
    while (S<=0);//no operation
    S--;
}

Note:

When one process modifies the value of a semaphore then, no other process can simultaneously modify that same semaphore's value. In the above case the integer value of S(S<=0) as well as the possible modification that is S-- must be executed without any interruption.

    Signal: Increments the value of its argument S, as there is no more process blocked on the queue. This Operation is mainly used to control the exit of a task from the critical section.signal() operation was originally termed as V; so it is also known as V(S) operation. The definition of signal operation is as follows:

signal(S)
{
S++;
}

Also, note that all the modifications to the integer value of semaphore in the wait() and signal() operations must be executed indivisibly.
Properties of Semaphores

    It's simple and always have a non-negative integer value.

    Works with many processes.

    Can have many different critical sections with different semaphores.

    Each critical section has unique access semaphores.

    Can permit multiple processes into the critical section at once, if desirable.

We will now cover the types of semaphores in the Operating system;
Types of Semaphores

Semaphores are mainly of two types in Operating system:

    Binary Semaphore:

    It is a special form of semaphore used for implementing mutual exclusion, hence it is often called a Mutex. A binary semaphore is initialized to 1 and only takes the values 0 and 1 during the execution of a program. In Binary Semaphore, the wait operation works only if the value of semaphore = 1, and the signal operation succeeds when the semaphore= 0. Binary Semaphores are easier to implement than counting semaphores.

    Counting Semaphores:

    These are used to implement bounded concurrency. The Counting semaphores can range over an unrestricted domain. These can be used to control access to a given resource that consists of a finite number of Instances. Here the semaphore count is used to indicate the number of available resources. If the resources are added then the semaphore count automatically gets incremented and if the resources are removed, the count is decremented. Counting Semaphore has no mutual exclusion.

Example of Use

Here is a simple step-wise implementation involving declaration and usage of semaphore.

Shared var mutex: semaphore = 1;
Process i
    begin
    .
    .
    P(mutex);
    execute CS;
    V(mutex);
    .
    .
    End;

Advantages of Semaphores

Benefits of using Semaphores are as given below:

    With the help of semaphores, there is a flexible management of resources.

    Semaphores are machine-independent and they should be run in the machine-independent code of the microkernel.

    Semaphores do not allow multiple processes to enter in the critical section.

    They allow more than one thread to access the critical section.

    As semaphores follow the mutual exclusion principle strictly and these are much more efficient than some other methods of synchronization.

    No wastage of resources in semaphores because of busy waiting in semaphores as processor time is not wasted unnecessarily to check if any condition is fulfilled in order to allow a process to access the critical section.

Disadvantages of Semaphores

    One of the biggest limitations is that semaphores may lead to priority inversion; where low priority processes may access the critical section first and high priority processes may access the critical section later.

    To avoid deadlocks in the semaphore, the Wait and Signal operations are required to be executed in the correct order.

    Using semaphores at a large scale is impractical; as their use leads to loss of modularity and this happens because the wait() and signal() operations prevent the creation of the structured layout for the system.

    Their use is not enforced but is by convention only.

    With improper use, a process may block indefinitely. Such a situation is called Deadlock. We will be studying deadlocks in detail in coming lessons.
