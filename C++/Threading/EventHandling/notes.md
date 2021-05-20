Threads can waste a lot of energy repeatedly acquiring a mutex to check for a certain condition.

A thread might repeatedly acquire the mutex, check the condition, see that it is not it's turn to perform some action, then release the lock until another thread eventually gets scheduled.

Repeatedly acquiring and releasing a lock to check for a certain condition to continue isn't very efficient, especially if it goes on for a long time.

The act of repeatedly acquiting a mutex to check if a condition is met is call busy waiting or spinning.






This is one of the limitations of using just a mutex. Sure, it restricts multiple threads from altering a protected section at the same time, but the mutex alone doesn't give our threads a way to signal each other to synchronize  actions.

To do that, we can use another mechanism, called a condition variable, which serves as a queue, or container, for threads that are waiting for a certain condition to occur.

Think of it as a place for threads to wait and be notified. The condition variable is associated with a mutex, and they work together to implement a higher-level construct called a monitor.

Monitors protect a critical section of code with mutual exclusion, and they provide the ability for threads to wait, or block, until a certain condition has become true, along with a mechanism to signal those waiting threads when their condition has been met.

Conceptually, you can think of a monitor like a room that contains the procedures and shared data that you want to protect. Only one thread can be in that room at a time to use those procedures and access the data. The mutex is a lock on the door. Other threads that try to enter the protected section while it's occupied, will wait outside in a condition variable, which is like a waiting room. They might all be waiting for the same condition to occur before they enter the monitor room, or, there might be multiple condition variables, or multiple waiting rooms, waiting for different conditions to occur to acquire that same mutex.

When the thread inside the monitor finishes its business in the critical section, it will signal one of the conditions that it's their turn to execute. Then it releases its lock on the door to exit the critical section.

One of the threads waiting for that condition that was signaled will wake up and take its turn in the monitor, locking the door behind it, so it can execute the critical section.


The condition variable has three main operations. Wait, signal, and broadcast. Before using a condition variable, I first need to acquire the mutex associated with it, check for my condition. I see that it's not my turn to take more soup, so I'll use the condition variable's wait operation, which releases my lock on the mutex, and then puts my thread to sleep, or a pause state, and places it into a queue, waiting for another thread to signal that somebody else takes soup.


Since the first thread released its lock on the lid before going to sleep, another thread can acquire it. If that thread is able to perform an action that changes the state required by the condition variable it can then use the signal operation to wake up a single thread from the waiting queue, so it can acquire the lock.

Depending on the language you're using, you'll also see this operation called notify or wake.

Finally, the second thread will release the lock on the mutex to allow the waiting threads to execute.


The third condition variable operation, broadcast, is similar to the signal operation, except that it wakes up all of the threads in the waiting queue.

You may also see it called things like notify all or wake all.

A common use case, that requires multiple condition variables, is implementing a shared queue or buffer. If multiple threads will be putting items in a queue and taking them out, then it needs a mutex to ensure that only one thread can add or remove items from it at a time. And for that, we can use two condition variables. If a thread tries to add an item to the queue, which is already full, then it can wait on a condition variable to indicate when the buffer is not full. And, if a thread tries to take an item, but the queue's empty, then it can wait on another condition variable for buffer not empty. These condition variables enable threads to signal each other when the state of the queue changes.




### Busy Waiting Example

```cpp
#include <thread>
#include <mutex>

int soup_servings = 10;
std::mutex slow_cooker_lid;

void hungry_person(int id) {
    int put_lid_back = 0;
    while (soup_servings > 0) {
			  // pick up the slow cooker lid
        std::unique_lock<std::mutex> lid_lock(slow_cooker_lid);

				//Check for condition
        if ((id == soup_servings % 2) && (soup_servings > 0)) {
            soup_servings--; // it's your turn; take some soup!
        } else {
            put_lid_back++; // it's not your turn; put the lid back...
        }
    }
    printf("Person %d put the lid back %u times.\n", id, put_lid_back);
}

int main() {
    std::thread hungry_threads[2];
    for (int i=0; i<2; i++) {
        hungry_threads[i] = std::thread(hungry_person, i);
    }
    for (auto& ht : hungry_threads) {
        ht.join();
    }
}
```

Output
```
Person 1 put back the lid 0 times.
Person 0 put back the lid 1183 times.
```


This C++ program to demonstrate using a condition variable has a function named hungry_person on line 10, which has an input parameter for an ID number. The hungry_person function will run as a thread that alternates with other hungry people threads to take servings of soup until it's all gone. The global variable on line seven represents the number of soup servings left, and the slow cooker lid on line eight is the mutex to protect the soup servings variable, so only one hungry person can change it at a time. Down within the while loop on line 12, the hungry person uses a unique lock to lock the slow cooker lid, then the if statement on line 14 compares their ID number with the number of soup servings remaining. It does that module 02, because in this example, we create two hungry person threads down in the main function. If it is the current thread's turn and there's still soup left, then the hungry person will take soup by decrementing the number of soup servings on line 15. Otherwise, the hungry person will put back the lid on line 17 and check again for their turn on the next loop iteration. Put_lid_back is a local variable we declared in the function on line 11 to keep track of how many times this particular thread puts back the lid because it's not their turn. At the end of the hungry_person function, we print a message with that value on line 20 to see what happened

As we can see from the sample output, a lot of wasted cycles were spent checking to see that it's not their turn for soup, so let's use a condition variable to help them coordinate.



### Using a Condition Variable

std::unique_lock<std::mutex> lk(cv_m);

while(!CONDITION)
{
	cv.wait(lk);
}

The typical usage pattern for a condition variable involves first locking the mutex that we'll be using with the condition variable and then using a while loop to check for some condition. If the condition is not true, then we need to wait. Calling the condition variable's wait function will release this thread's lock on the mutex and cause it to wait here. Now, I want to emphasize here that the condition variable is not the condition itself, or an event. The condition that we're checking for is the logic of the while loop, is it this thread's turn to take soup? The condition variable is just a place or mechanism for threads to wait. When the waiting thread gets signaled by another thread, it will wake up, lock the mutex, and then check the while loop's condition again. If the condition is true this time, then we'll continue past the loop to execute the critical section of code. Now, one important reason for placing the condition variable's wait function inside of a while loop like this is that in certain operating environments, the condition variable could have what is called a spurious wakeup, meaning it wakes up from its waiting state when it's not supposed to. By placing it inside of a while loop, if a spurious wakeup occurs, the thread will see that it's still not time to continue on and it will go back to sleeping.

```cpp
#include <thread>
#include <mutex>
#include <condition_variable>				//Include header

int soup_servings = 10;
std::mutex slow_cooker_lid;
std::condition_variable soup_taken; //Add condition variable

void hungry_person(int id) {
    int put_lid_back = 0;
    while (soup_servings > 0) {
        std::unique_lock<std::mutex> lid_lock(slow_cooker_lid);

				//Change if statement to while loop, and modify condition
        while ((id != soup_servings % 2) && (soup_servings > 0)) {
            put_lid_back++; // it's not your turn; put the lid back...
            soup_taken.wait(lid_lock); //wait on condition
        }
				//Add a check
        if (soup_servings > 0) {
            soup_servings--; // it's your turn; take some soup!
            lid_lock.unlock(); // put back the lid
            soup_taken.notify_one(); // notify another thread to take their turn
        }
    }
    printf("Person %d put the lid back %u times.\n", id, put_lid_back);
}

int main() {
    std::thread hungry_threads[2];
    for (int i=0; i<2; i++) {
        hungry_threads[i] = std::thread(hungry_person, i);
    }
    for (auto& ht : hungry_threads) {
        ht.join();
    }
}
```
Output
```
Person 1 put back the lid 4 times.
Person 0 put back the lid 5 times.
```

To implement that in our hungry_person function, we'll

	include the condition variable header at the top of our program.
	create a new condition variable object on line 10 named soup_taken.
	change the if statement on line 16 into a while loop and we'll modify the condition it checks for to see if it's not this hungry person's turn to take soup.
	If it's not their turn, then we'll have the thread wait on the condition variable to get signaled after another thread takes soup.

Notice that we're passing in the lid_lock, so that the wait function knows which lock to release and then reacquire later when this thread gets signaled.

We'll also move incrementing the put_lit_back counter into the while loop to track how many times each thread has to wait because it was not their turn.

Now, if the thread checks the condition and it is their turn then execution will continue past the while loop. We need to add another check to make sure that there is still soup left. If there is soup left, the thread will take soup by decrementing the soup servings. And then, finally, it will need to signal the other thread to wake up. To do that, we'll release our lock on the lid. And then call the condition variable's notify_one function to signal the other hungry person that soup was taken, so it should be their turn.

Given the example output, we have two hungry threads that are taking turns and coordinating their actions to avoid wasting a whole lot of energy unnecessarily checking whose turn it is.




### Notify All Example

```cpp
#include <thread>
#include <mutex>
#include <condition_variable>				//Include header

int soup_servings = 10;
std::mutex slow_cooker_lid;
std::condition_variable soup_taken; //Add condition variable

void hungry_person(int id) {
    int put_lid_back = 0;
    while (soup_servings > 0) {
        std::unique_lock<std::mutex> lid_lock(slow_cooker_lid); // pick up the slow cooker lid

				//Change if statement to while loop
        while ((id != soup_servings % 5) && (soup_servings > 0)) { // is it your turn to take soup?
            put_lid_back++; // it's not your turn; put the lid back...
            soup_taken.wait(lid_lock); // ...and wait...
        }
        if (soup_servings > 0) {
            soup_servings--; // it's your turn; take some soup!
            lid_lock.unlock(); // put back the lid
            soup_taken.notify_all(); // notify another thread to take their turn
        }
    }
    printf("Person %d put the lid back %u times.\n", id, put_lid_back);
}

int main() {
    std::thread hungry_threads[5];
    for (int i=0; i<5; i++) {
        hungry_threads[i] = std::thread(hungry_person, i);
    }
    for (auto& ht : hungry_threads) {
        ht.join();
    }
}
```
Output
```
Person 1 put back the lid 2 times.
Person 3 put back the lid 2 times.
Person 0 put back the lid 3 times.
Person 2 put back the lid 2 times.
Person 4 put back the lid 2 times.
```


Now, let's see what happens if we expand this dinner party to include more hungry people by modifying the program's main function to create five hungry people threads instead of just two. We'll also need to modify the condition statement on line 16 to rotate servings among the five people. Now, if I build... And try to run the program again, it gets stuck.

The problem here is that we used the notify_one function on line 23, which only wakes up one of the waiting threads. Of those four other threads, if it doesn't wake up the one whose turn it is next, then the program will get stuck. The fix here is to change that function to notify_all to wake up all of the waiting threads to check and see if it's their turn. Now when I build and run the program... Everything works great. All of the threads eat, and they take turns doing so. If you only need to signal one waiting thread and you don't care which one it is, then the basic notify_one function will work fine. But in this example, since we wanted a specific thread to wake up and see that it's their turn, relying on the single notify_one function to wake up the right thread will not always work.
