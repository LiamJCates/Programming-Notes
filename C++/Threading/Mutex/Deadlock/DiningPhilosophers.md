Small Example

To demonstrate a deadlock, we've created this example program that simulates two dining philosophers thinking and eating sushi.

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
    std::thread Philosopher_A(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
    std::thread Philosopher_B(philosopher, std::ref(chopstick_b), std::ref(chopstick_a));
    Philosopher_A.join();
    Philosopher_B.join();
    printf("The philosophers are done eating.\n");
}


The philosopher function on line nine takes two reference parameters named first chopstick and second chopstick, which indicate the order in which the philosopher will lock the two mutexes. The while loop on line 10 will continue to run as long as the sushi count variable is positive, which represents the amount of sushi left on the shared plate between the philosophers. We initialize the sushi count to 5,000 on line seven, so our two philosophers should both end up very well fed. Within the while loop, the philosopher will pick up and acquire a lock on their first chopstick followed by their second chopstick, at which point they're in the critical section. If there's still sushi left on the plate, they'll take a piece by decrementing the sushi count variable online 14, then finally unlock both chopsticks to put them down for someone else to take. Down in the main function we initialize two mutexes named chopstick A and chopstick B, then start to philosopher threads named Philosopher_A and Philosopher_B. Notice that each philosopher has a different first and second chopstick. Philosopher_A will acquire chopstick A first and then B, whereas Philosopher_B acquires chopstick B first and then A. After both philosophers have eaten all of the sushi, their threads will finish and the program will print out a final message on line 27.

Switching over to the command prompt, when I run this program, it should take less than a second for our philosophers to eat 5,000 pieces of sushi, but I don't get that final output message. Our philosophers are stuck in a deadlock.


### Simple Solution
A simple solution is to prioritize the locks.

std::thread Philosopher_A(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));
std::thread Philosopher_B(philosopher, std::ref(chopstick_a), std::ref(chopstick_b));

We'll say that chopstick A has the highest priority and B is second.

Each philosopher should always take their highest priority chopstick first. I see that online 24, Philosopher_B takes chopstick B as her first chopstick and chopstick A as her second one. So, I'll swap those around. Now both threads will acquire the two chopsticks in the same order. If I make and run the program now, it reaches the end and prints the final message that our sushi filled philosophers are done eating. Now, we designed this example to be as simple as possible by only including a single shared resource, the sushi plate, in practice, this program only really needs one lock to protect it. We intentionally created the potential for deadlock because we nested two locks inside of each other to demonstrate the concept. As your programs grow in complexity to include more critical sections, locks and parallel threads with intertwined dependencies, it becomes increasingly more difficult to identify and prevent potential deadlocks.

The simplest technique to prevent deadlocks is the one we used in this video, which is to ensure that locks are always taken in the same order by every threaD. However, lock ordering may not always be feasible. For example, a thread may not know all of the locks it will need to acquire ahead of taking any of them.


### Scoped Lock
For our dining philosophers example, another possible solution in C plus plus is to use a scoped_lock. When you create a scoped_lock object, it takes ownership of one or more mutexes and holds onto them for the scope in which that object was created. The scoped_lock has a built-in deadlock avoidance algorithm when it's used to acquire multiple mutexes at once.

#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &first_chopstick, std::mutex &second_chopstick) {
    while (sushi_count > 0) {
        std::scoped_lock lock(first_chopstick, second_chopstick);
        if (sushi_count) {
            sushi_count--;
        }
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

Back in our code, I'll return line 24 to its original state, which creates the potential for a deadlock. Then I'll replace lines 11 and 12, which lock the first and second chopsticks with the constructor for a new scoped_lock. Creating this scoped_lock at the beginning of the while loop will acquire both mutexes and hold onto them until the end of that while loop, at which point the scoped_lock is destructed and the mutexes are released. They'll be automatically unlocked, so I don't need these to unlock statements. Switching back to the console, I'll make, and then run the program again, and it finishes right away. But this time it's using the C plus plus scope_lock mechanism to avoid a deadlock rather than ordering the locks by priority.













Dining Philosophers Problem (DPP)


The dining philosophers problem states that there are 5 philosophers sharing a circular table and they eat and think alternatively. There is a bowl of rice for each of the philosophers and 5 chopsticks. A philosopher needs both their right and left chopstick to eat. A hungry philosopher may only eat if there are both chopsticks available. Otherwise a philosopher puts down their chopstick and begin thinking again.

The dining philosopher is a classic synchronization problem as it demonstrates a large class of concurrency control problems.
Solution of Dining Philosophers Problem

A solution of the Dining Philosophers Problem is to use a semaphore to represent a chopstick. A chopstick can be picked up by executing a wait operation on the semaphore and released by executing a signal semaphore.

The structure of the chopstick is shown below −

semaphore chopstick [5];

Initially the elements of the chopstick are initialized to 1 as the chopsticks are on the table and not picked up by a philosopher.

The structure of a random philosopher i is given as follows −

do {
   wait( chopstick[i] );
   wait( chopstick[ (i+1) % 5] );
   . .
   . EATING THE RICE
   .
   signal( chopstick[i] );
   signal( chopstick[ (i+1) % 5] );
   .
   . THINKING
   .
} while(1);

In the above structure, first wait operation is performed on chopstick[i] and chopstick[ (i+1) % 5]. This means that the philosopher i has picked up the chopsticks on his sides. Then the eating function is performed.

After that, signal operation is performed on chopstick[i] and chopstick[ (i+1) % 5]. This means that the philosopher i has eaten and put down the chopsticks on his sides. Then the philosopher goes back to thinking.
Difficulty with the solution

The above solution makes sure that no two neighboring philosophers can eat at the same time. But this solution can lead to a deadlock. This may happen if all the philosophers pick their left chopstick simultaneously. Then none of them can eat and deadlock occurs.

Some of the ways to avoid deadlock are as follows −

    There should be at most four philosophers on the table.
    An even philosopher should pick the right chopstick and then the left chopstick while an odd philosopher should pick the left chopstick and then the right chopstick.
    A philosopher should only be allowed to pick their chopstick if both are available at the same time.
