
Starvation occurs when a thread is unable
to gain access to a necessary resource
and is therefore unable to make progress.
If another greedy thread is frequently holding a lock
on the shared resource,
then the starved thread won't get a change to execute.

In a simple scenario like ours,
with two equal threads competing for execution time,
starvation probably isn't a concern.

However, if our two threads are given different priorities,
then that may not be the case.


How different thread priorities get treated
will depend on the operating system,
but generally, higher priority threads
will be scheduled to execute more often.
And, that can leave low priority threads hungry.

Another thing that can lead to starvation
is having too many concurrent threads.

```cpp
#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &chopsticks) {
    int sushi_eaten = 0;
    while (sushi_count > 0) {
        std::scoped_lock lock(chopsticks);
        if (sushi_count) {
            sushi_count--;
            sushi_eaten++;
        }
    }
    printf("Philosopher %d ate %d.\n", std::this_thread::get_id(), sushi_eaten);
}

int main() {
    std::mutex chopsticks;
    std::array<std::thread, 200> philosophers;
    for (size_t i=0; i<philosophers.size(); i++) {
        philosophers[i] = std::thread(philosopher,std::ref(chopsticks));
    }
    for (size_t i=0; i<philosophers.size(); i++) {
        philosophers[i].join();
    }
    printf("The philosophers are done eating.\n");
}
```
To demonstrate thread starvation, we'll modify this version of the dining philosophers example program to add a local variable within the philosopher function to keep track of how many pieces of sushi each philosopher thread gets to eat. We'll increment the philosopher's sushi eating variable after they take a piece of sushi on line 15, and then at the end, after their while loop finishes, we'll print a message with the number of pieces this philosopher was able to take.

run this program, and when it finishes I can see that each philosopher got a different amount of sushi. It's not necessarily fair, but there's plenty of sushi to go around, so both of the philosophers are well fed. Now let's see what happens if we drastically increase the number of philosophers at the dinner party, by modifying the array to hold philosopher threads on line 23 from having only two threads to 200 threads. The following for loops on lines 24 and 27 will then create 200 unique philosopher threads before waiting for them all to finish and join. I'll make, and then run the program with that change, and as I scroll through the finale counts for each thread, I can see that some philosophers got a decent amount of sushi, but a lot of them didn't get any at all. This one philosopher here took over 1000. All of these threads were created with the same default priority, but because there were so many threads, some never got scheduled to execute. This represents a real problem in programs containing a large number of threads. For example, if instead of feeding sushi to a bunch of hungry philosophers, this program was a web server that created new threads to handle a huge number of incoming requests, some of those requests may never get processed, and that would lead to some impatient and angry users on the other end. There are techniques that can be used to improve, or even guarantee fairness among threads, but that type of workload management is very situational dependent
