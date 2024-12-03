A livelock looks similar to a deadlock in the sense that two threads are blocking each other from making progress. But the difference is that the threads in a livelock are actively trying to resolve the problem. A livelock can occur when two or more threads are designed to respond to the actions of each other. Both threads are busy doing something, but the combination of their efforts prevent them from actually making progress and accomplishing anything useful. The program will never reach the end. The ironic thing about livelocks is that they're often caused by algorithms that are intended to detect and recover from deadlock. If one or more process or thread takes action to resolve the deadlock, then those threads can end up being overly polite and stuck in a livelock. To avoid that, ensure that only one process takes action chosen by priority or some other mechanism like random selection.


To demonstrate a livelock scenario, we'll modify our original dining philosophers example.

#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count > 0) {
        first_chopstick.lock();
        second_chopstick.lock();
        if (sushi_count) {
            sushi_count--;
        }
        second_chopstick.unlock();
        first_chopstick.unlock();
    }
}

int main() {
    std::mutex chopstick_a, chopstick_b;
    std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    barron.join();
    olivia.join();
    printf("The philosophers are done eating.\n");
}

It creates two philosopher threads Barron and Olivia, which each grab a different first and second chopstick, and therefore have the potential to end up in a deadlock.

So, let's be clever and implement our own deadlock avoidance algorithm.

#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count > 0) {
        first_chopstick.lock();
        if(!second_chopstick.try_lock()){
					first_chopstick.unlock();
				}
				else
	        if (sushi_count) {
	            sushi_count--;
	        }
        second_chopstick.unlock();
        first_chopstick.unlock();
    }
}

int main() {
    std::mutex chopstick_a, chopstick_b;
    std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    barron.join();
    olivia.join();
    printf("The philosophers are done eating.\n");
}

I'll change the lock function on line 12 for the second chopstick from a regular lock to try_lock. And then I'll make that call to try_lock the condition for an if statement. If the second chopstick was already taken by another thread, try_lock will return false. In that case, this philosopher should politely put back their first chopstick by unlocking it, so another philosopher can take it. Otherwise, if the current thread successfully locked both chopsticks, it can continue on as normal, taking a piece of sushi and then unlocking both chopsticks. So, I'll enclose that within an else clause. Switching over to a command prompt, I'll make, and then run that program, and hooray, it reaches the end right away. By making our philosophers polite, we've successfully avoided a deadlock.

Now, let's invite a few more philosophers to this dinner party.
```cpp
#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count > 0) {
        first_chopstick.lock();
        if (!second_chopstick.try_lock()) {
            first_chopstick.unlock();
        } else {
            if (sushi_count) {
                sushi_count--;
            }
            second_chopstick.unlock();
            first_chopstick.unlock();
        }
    }
}

int main() {
    std::mutex chopstick_a, chopstick_b;
    std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    std::thread steve(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread nikki(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    barron.join();
    olivia.join();
    steve.join();
    nikki.join();
    printf("The philosophers are done eating.\n");
}
```
I'll copy and paste lines 26 and 27 to create two more philosophers. I'll name them Steve and Nikki. And then finally, I'll call the join functions on Steve and Nikki down near the end.

We've only invited two more philosophers to this party and there should still be plenty of sushi to go around. I'll make and then run that program. And now it's stuck. My first instinct would be to diagnose this type of behavior as a deadlock, but if I press Control + Shift + Escape to bring up the task manager, and then go to the performance tab, I see that the CPU is working hard at 100%.

This time, our threads that are trying to avoid a deadlock are instead caught in a livelock, with four philosophers grabbing for the chopsticks, by the time a philosopher has launched their first chopstick and goes for the second one, another philosopher already has it. They're constantly picking up and putting down chopsticks, but nobody can get both at the same time to take a piece of sushi. So, only to manually terminate this program by pressing Control + Break.

To resolve the livelock, I'll use the thread's yield function, which will reschedule its execution to allow other threads to run. Exactly how yield accomplishes that will vary depending on its implementation and the operating system scheduler.

```cpp
#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count > 0) {
        first_chopstick.lock();
        if (!second_chopstick.try_lock()) {
            first_chopstick.unlock();
            std::this_thread::yield();
        } else {
            if (sushi_count) {
                sushi_count--;
            }
            second_chopstick.unlock();
            first_chopstick.unlock();
        }
    }
}

int main() {
    std::mutex chopstick_a, chopstick_b;
    std::thread barron(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread olivia(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    std::thread steve(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread nikki(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    barron.join();
    olivia.join();
    steve.join();
    nikki.join();
    printf("The philosophers are done eating.\n");
}
```

Back in the code, after unsuccessfully trying to acquire the second chopstick and then putting back the first chopstick on line 13, I'll call the yield function on the current thread. This will cause the thread to temporarily wait for a moment before trying to grab the first chopstick again, which should give another philosopher the chance to get both chopsticks at the same time. We run the program, and see that it's able to successfully reach the end without getting stuck in either a deadlock or a livelock.
