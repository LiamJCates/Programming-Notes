### Mutex

Anytime multiple threads are concurrently reading and writing a shared resource, it creates the potential for incorrect behavior, like a data race. But we can defend against that by identifying and protecting critical sections of code. A critical section, or critical region, is part of a program that accesses a shared resource, such as a data structured memory, or an external device, and it may not operate correctly if multiple threads concurrently access it. The critical section needs to be protected so that it only allows one thread or process to execute in it at a time.

These cases call for a mutex, short for mutual exclusion, which you'll also hear referred to as a lock. Only one thread or process can have possession of a lock at a time so it can be used to prevent multiple threads from simultaneously accessing a shared resource, forcing them to take turns.


The operation to acquire the lock is an atomic operation, which means it's always executed as a single indivisible action. To the rest of the system, an atomic operation appears to happen instantaneously, even if under the hood, it really takes multiple steps. The key here is that the atomic operation is uninterruptible.

Acquiring the mutex is an atomic action that no other thread can interfere with halfway through. Either you have the mutex, or you don't.

Threads that try to acquire a lock that's currently possessed by another thread can pause and wait 'til it's available.

Don't forget to release the mutex when you're done. Since threads can get blocked and stuck waiting for a thread in the critical section to finish executing, it's important to keep the section of code protected with the mutex as short as possible.



To fix race conditions in multi-threaded environment we need mutex i.e. each thread needs to lock a mutex before modifying or reading the shared data and after modifying the data each thread should unlock the mutex.
std::mutex

In the C++11 threading library, the mutexes are in the <mutex> header file. The class representing a mutex is the std::mutex class.

There are two important methods of mutex:
1.) lock()
2.) unlock()


we will see how to use std::mutex to fix the race condition in that multithreaded wallet.

As, Wallet provides a service to add money in Wallet and same Wallet object is used between different threads, so we need to add Lock in addMoney() method of the Wallet i.e.
Acquire lock before increment the money of Wallet and release lock before leaving that function. Let’s see the code,

Wallet class that internally maintains money and provides a service/function i.e. addMoney().
This member function, first acquires a lock then increments the internal money of wallet object by specified count and then releases the lock.
#include<iostream>
#include<thread>
#include<vector>
#include<mutex>
class Wallet
{
    int mMoney;
    std::mutex mutex;
public:
    Wallet() :mMoney(0){}
    int getMoney()   {     return mMoney; }
    void addMoney(int money)
    {
        mutex.lock();
        for(int i = 0; i < money; ++i)
        {
            mMoney++;
        }
        mutex.unlock();
    }
};

Now Let’s create 5 threads and all these threads will share a same object of class Wallet and add 1000 to internal money using it’s addMoney() member function in parallel.

So, if initially money in wallet is 0. Then after completion of all thread’s execution money in Wallet should be 5000.

And this mutex lock guarantees that Money in the Wallet will be 5000 at end.

Let’s test this,
int testMultithreadedWallet()
{
    Wallet walletObject;
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
    }
    for(int i = 0; i < threads.size() ; i++)
    {
        threads.at(i).join();
    }
    return walletObject.getMoney();
}
int main()
{
    int val = 0;
    for(int k = 0; k < 1000; k++)
    {
        if((val = testMultithreadedWallet()) != 5000)
        {
            std::cout << "Error at count = "<<k<<"  Money in Wallet = "<<val << std::endl;
            //break;
        }
    }
    return 0;
}

It’s guaranteed that it will not found a single scenario where money in wallet is less than 5000.
Because mutex lock in addMoney makes sure that once one thread finishes the modification of money then only any other thread modifies the money in Wallet.

But what if we forgot to unlock the mutex at the end of function. In such scenario, one thread will exit without releasing the lock and other threads will remain in waiting.
This kind of scenario can happen in case some exception came after locking the mutex. To avoid such scenarios we should use std::lock_guard.
std::lock_guard

std::lock_guard is a class template, which implements the RAII for mutex.
It wraps the mutex inside it’s object and locks the attached mutex in its constructor. When it’s destructor is called it releases the mutex.

Let’s see the code,
class Wallet
{
    int mMoney;
    std::mutex mutex;
public:
    Wallet() :mMoney(0){}
    int getMoney()   {     return mMoney; }
    void addMoney(int money)
    {
        std::lock_guard<std::mutex> lockGuard(mutex);
        // In constructor it locks the mutex
        for(int i = 0; i < money; ++i)
        {
            // If some exception occurs at this
            // poin then destructor of lockGuard
            // will be called due to stack unwinding.
            //
            mMoney++;
        }
        // Once function exits, then destructor
        // of lockGuard Object will be called.
        // In destructor it unlocks the mutex.
    }
 };




### Try Lock
try lock, or try enter, which is a non-blocking version of the lock or acquire method, returns immediately, and one of two things will happen. If the mutex you're trying to lock is available, it will get locked and the method will return true. Otherwise, if the mutex is already possessed by another thread, the trial lock method will immediately return false. That return value of true or false lets the thread know whether or not it was successful in acquiring the lock.

Lock mutex if not locked
Attempts to lock the mutex, without blocking:

    If the mutex isn't currently locked by any thread, the calling thread locks it (from this point, and until its member unlock is called, the thread owns the mutex).
    If the mutex is currently locked by another thread, the function fails and returns false, without blocking (the calling thread continues its execution).
    If the mutex is currently locked by the same thread calling this function, it produces a deadlock (with undefined behavior). See recursive_mutex for a mutex type that allows multiple locks from the same thread.

This function may fail spuriously when no other thread has a lock on the mutex, but repeated calls in these circumstances shall succeed at some point.

All lock and unlock operations on the mutex follow a single total order, with all visible effects synchronized between the lock operations and previous unlock operations on the same object.

Parameters
none

Return value
true if the function succeeds in locking the mutex for the thread.
false otherwise.


Remeber
1. try_lock() is a non blocking call.
2. try_lock() tries to lock the mutex.
3. On successful lock, it will return true else it will return false.


Now what is the difference between “lock()” and “try_lock()”?

when 2nd thread calls “lock()” function, and if the “lock()” is acquired by previous thread, the second thread will be blocked till the first thread unlocks the resource. This is a blocking call.

But with “try_lock()”, if the 2nd thread tries to acquire lock, but the lock has been already acquired by other thread, the 2nd thread will return immediately. Thus it is a non blocking call.

Note:

If “try_lock()” is called on the same thread that owns the mutex, it will result in a undefined behaviour.

This is because, it will be a dead lock situation.
Example for mutex::try_lock

```cpp
#include <iostream>
#include <mutex>
#include <thread>

// for more tutorial in C++ visit www.prodevelopertutorial.com

using namespace std;

int count = 0;
std::mutex mu;

void incrementCount()
{
    if (mu.try_lock()) // try_lock()
    {
   		count++;//critial section
   		cout<<count<<endl;
   		mu.unlock();
   	}
}

int main(void)
{
    std::thread t1(incrementCount);
    std::thread t2(incrementCount);
    std::thread t3(incrementCount);

    t1.join();
    t2.join();
    t3.join();
}
```


### Reader Writer Lock
We use a lock or mutex to protect a critical section of code to defend against data races, which can occur when multiple threads are concurrently accessing the same location in memory and at least one of those threads is writing to that location. That second part is key because if we have a bunch of threads and none of them are writing, they're all just want to read from the same location, that's fine. It's okay to let multiple threads read the same shared value as long as no one else can change it. They'll all safely see the same thing. Danger only exists when you add a thread that's writing to the mix. When we use a basic lock or mutex to protect the shared resource, we limit access so that only one of the threads can use it at a time regardless of whether that thread is reading or writing or both. - That works but it's not necessarily the most efficient way to do things, especially when there are lots of threads that only need to read. This is where reader-writer locks can be useful. A reader-writer lock or shared mutex can be locked in one of two ways. It can be locked in a shared read mode that allows multiple threads that only need to read simultaneously to lock it or it can be locked in an exclusive write mode that limits access to only one thread at a time, allowing that thread to safely write to the shared resource.

Recognizing when to use a read-write lock is just as important as knowing how to use it. In certain scenarios, read-write locks can improve a program's performance versus using a standard mutex but they are more complicated to implement and they typically use more resources under the hood to keep track of the number of readers. - And there can be language-dependent differences in how they're implemented that affect performance. Do they give preference to readers or writers that are trying to acquire the lock? Deciding which type of mutex to use is a complicated decision. But as a general rule of thumb, it makes sense to use a shared reader-writer lock when you have a lot more threads that will be reading from the shared data than the number of threads that will be writing to it such as certain types of database applications. If the majority of your threads are writing then there's not much if any advantage to using a read-write lock.

The shared mutex class has been part
of the standard library since C plus plus 17
to provide a mutex that can be acquired in a shared mode
in which multiple threads can share ownership
of the mutex as well as an exclusive mode
in which only one thread can have a lock
on the mutex.


The shared_mutex class is a synchronization primitive that can be used to protect shared data from being simultaneously accessed by multiple threads. In contrast to other mutex types which facilitate exclusive access, a shared_mutex has two levels of access:

    shared - several threads can share ownership of the same mutex.

    exclusive - only one thread can own the mutex.

If one thread has acquired the exclusive lock (through lock, try_lock), no other threads can acquire the lock (including the shared).

If one thread has acquired the shared lock (through lock_shared, try_lock_shared), no other thread can acquire the exclusive lock, but can acquire the shared lock.

Only when the exclusive lock has not been acquired by any thread, the shared lock can be acquired by multiple threads.

Within one thread, only one lock (shared or exclusive) can be acquired at the same time.

Shared mutexes are especially useful when shared data can be safely read by any number of threads simultaneously, but a thread may only write the same data when no other thread is reading or writing at the same time.

```cpp
/**
 * Several users reading a calendar, but only a few users updating it
 */
#include <thread>
#include <mutex>
#include <chrono>
#include <shared_mutex>

char WEEKDAYS[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
int today = 0;
std::shared_mutex marker;

void calendar_reader(const int id) {
    for (int i=0; i<7; i++) {
        marker.lock_shared();
        printf("Reader-%d sees today is %s\n", id, WEEKDAYS[today]);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
		marker.unlock_shared();
    }
}

void calendar_writer(const int id) {
    for (int i=0; i<7; i++) {
        marker.lock();
        today = (today + 1) % 7;
        printf("Writer-%d updated date to %s\n", id, WEEKDAYS[today]);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        marker.unlock();        
    }
}

int main() {
    // create ten reader threads ...but only two writer threads
    std::array<std::thread, 10> readers;
    for (unsigned int i=0; i<readers.size(); i++) {
        readers[i] = std::thread(calendar_reader, i);
    }
    std::array<std::thread, 2> writers;
    for (unsigned int i=0; i<writers.size(); i++) {
        writers[i] = std::thread(calendar_writer, i);
    }

    // wait for readers and writers to finish
    for (unsigned int i=0; i<readers.size(); i++) {
        readers[i].join();
    }
    for (unsigned int i=0; i<writers.size(); i++) {
        writers[i].join();
    }
}
```


To demonstrate using a shared mutex, this example program creates 10 threads to concurrently read what day it is from a shared calendar while two other threads update it. The calendar here is just an array of strings to represent the days of the week on line eight, as well as an integer to indicate which day today is on line nine.

There are two functions for the threads that will be reading the calendar value and those that will be writing to update it. They both use a for loop to perform their action of either reading or writing seven times. In the calendar readers for loop, the thread locks the marker mutex, prints out a message about what day it sees, sleeps for 100 milliseconds, and then lets go of the marker. We included the delay here to more easily see when each thread is in the critical section when looking at the program's output. In the calendar writers loop, the thread takes the marker, changes the calendar to the next day of the week, prints a message about it doing so, sleeps for 100 milliseconds, and then unlocks the marker mutex. Finally, down in the program's main function, we use a pair of for loops to create and start 10 reader threads and two writer threads, so there are five times as many readers as writers.


We include the shared mutex header at the top of the program. The marker shared mutex and lock shared and unlock shared versions of the lock and unlock function will allow multiple calendar reader threads to possess the marker mutex at the same time, whereas standard lock functions on lines 24 and 28 will only allow one calendar writer to access the shared variable at a time.

Before we build this program, use the C plus plus 17 standard.

-std=c++17

Depending on the development environment and compiler version you're using, you may or may not need to include this flag to make sure the compiler incorporates newer features, like the shared mutex. Now, when I make and then run this program, I see all of the reader threads enter the protected section at the same time to see what day it is. Then the writers take their turns individually holding the marker to update the calendar before the group of reader threads jump back in to look at the calendar together. The result is a program that finishes much quicker than before.













### Atomic

Using a lock to protect a shared variable with mutual exclusion works. But if you're only doing simple operations, like incrementing a variable's value, then the simpler solution is to use C++ atomic types which encapsulate a value and synchronize access to it to prevent a data race.


Each instantiation and full specialization of the std::atomic template defines an atomic type. If one thread writes to an atomic object while another thread reads from it, the behavior is well-defined (see memory model for details on data races)

In addition, accesses to atomic objects may establish inter-thread synchronization and order non-atomic memory accesses as specified by std::memory_order.


Header:
	#include <atomic>

Declaration:
	std::atomic<T> identifier;
	std::atomic_T identifier;

In both examples above, T is replaced with one of the type names defined here:
https://en.cppreference.com/w/cpp/atomic/atomic

```cpp
#include <thread>
#include <atomic>

std::atomic<unsigned int> counter(0);

void count() {
    for (int i=0; i<10000; i++) {
        counter++;
    }
}

int main() {
    std::thread one(count);
    std::thread two(count);
    one.join();
    two.join();
    printf("Count is: %u\n", counter.load());
}
```

### Member functions

operator=
stores a value into an atomic object

is_lock_free
checks if the atomic object is lock-free

store
atomically replaces the value of the atomic object with a non-atomic argument

load
atomically obtains the value of the atomic object

operator T
loads a value from an atomic object

exchange
atomically replaces the value of the atomic object and obtains the value held previously

compare_exchange_weak
compare_exchange_strong
atomically compares the value of the atomic object with non-atomic argument and performs atomic exchange if equal or atomic load if not

wait
(C++20) blocks the thread until notified and the atomic value changes
notify_one
(C++20) notifies at least one thread waiting on the atomic object
notify_all
(C++20) notifies all threads blocked waiting on the atomic object

### Specialized member functions

fetch_add atomically adds the argument to the value stored in the atomic object and obtains the value held previously

fetch_sub atomically subtracts the argument from the value stored in the atomic object and obtains the value held previously

fetch_and atomically performs bitwise AND between the argument and the value of the atomic object and obtains the value held previously

fetch_or atomically performs bitwise OR between the argument and the value of the atomic object and obtains the value held previously

fetch_xor atomically performs bitwise XOR between the argument and the value of the atomic object and obtains the value held previously

operator++
operator--
increments or decrements the atomic value by one

operator+=
operator-=
operator&=
operator|=
operator^=
adds, subtracts, or performs bitwise AND, OR, XOR with the atomic value





### Recursive Mutex
If a thread tries to lock a mutex that it's already locked, it'll enter into a waiting list for that mutex, which results in something called a deadlock because no other thread can unlock that mutex. There may be times when a program needs to lock a mutex multiple times before unlocking it. In that case, you should use a reentrant mutex to prevent this type of problem. A reentrant mutex is a particular type of mutex that can be locked multiple times by the same process or thread. Internally, the reentrant mutex keeps track of how many times it's been locked by the owning thread and it has to be unlocked an equal number of times before another thread can lock it.


If your program needs to lock a mutex multiple times, using a reentrant mutex may seem like an easy way to avoid a deadlock. But if you don't unlock the reentrant mutex the same number of times, you can still end up stuck.

Many programmers like using reentrant locks because it can make things easier. You don't need to worry as much about what's already been locked and they make it easier to retrofit locks into existing code. As an example, say I have a function to increment a shared counter and it uses a mutex to protect that operation. If later, I create another function that uses the same mutex to protect some other section of code, and that section of code uses the increment counter function, since those functions are nested, when I execute my function, it'll end up locking the mutex twice before unlocking it. If I was using a regular non-reentrant lock, that would produce a deadlock but with a reentrant mutex, this works just fine. Now, like many things in the world of programmers, there are some very strong opinions about whether reentrant locks are good or evil. Some opponents of using reentrant locks will argue that the example I just showed you should be refactored to avoid having nested locks by using a third function that increments the counter and only gets called from within a protected section. I'm not going to advocate either way on this debate. There are pros and cons to both sides. - One use case where reentrant locks are really needed is when writing a recursive function. That is a function that calls itself. If the function makes a recursive call to itself from within a locked section, it will lock the mutex multiple times as it repeats itself and then unlock the mutex an equal number of times as it returns and unwinds. Since a reentrant mutex can be used recursively like this, you'll often hear it referred to as a recursive mutex or a recursive lock. Different languages use different terms but these all basically mean the same thing.

To define a recursive mutex:

std::recursive_mutex identifier;

The lock and unlock commands are the same but function as defined above.
