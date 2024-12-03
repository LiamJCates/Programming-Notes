### Abandoned Lock
Another form of a deadlock through thread death. If one thread, or process, acquires a lock and then terminates because of some unexpected reason, it may not automatically release the lock before it disappears. That leaves other tasks stuck waiting for a lock that will never be released.


To demonstrate what happens if a lock gets abandoned, we'll use a modified version of the previous dining philosopher's example that we used to demonstrate a deadlock. In this version, we still have two philosophers eating and thinking but we've consolidated the two mutexs into a single mutex simply named chopsticks.

```cpp
#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &chopsticks) {
    while (sushi_count > 0) {
        chopsticks.lock();
        if (sushi_count) {
            sushi_count--;
        }
        chopsticks.unlock();
    }
}

int main() {
    std::mutex chopsticks;
    std::thread Philosopher_A(philosopher, std::ref(chopsticks));
    std::thread Philosopher_B(philosopher, std::ref(chopsticks));
    Philosopher_A.join();
    Philosopher_B.join();
    printf("The philosophers are done eating.\n");
}
```

The philosophers will lock the chopstick mutex on line 11 before taking a bite of sushi and then unlocking it immediately afterwards on line 15. With only one mutex at play, the risk of deadlock is removed. So, if I run this program, the philosophers successfully take turns eating sushi until all of the pieces are gone.


Now, if one of the philosopher threads lock the mutex, and then something happens in the critical section, that thread could finish before it gets the chance to release the lock.

To simulate that happening, I'll add another if statement that checks to see if there are exactly 10 pieces of sushi left. And if so, the thread will print a message that this philosopher has had enough. And then after that, they'll use a break statement to immediately break out of the while loop before unlocking the chopstick.

```cpp
#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &chopsticks) {
  while (sushi_count > 0) {
      chopsticks.lock();
      if (sushi_count) {
          sushi_count--;
      }
      if (sushi_count == 10) {
          printf("This philosopher has had enough!\n");
          break;
      }
      chopsticks.unlock();
  }
}

int main() {
    std::mutex chopsticks;
    std::thread barron(philosopher, std::ref(chopsticks));
    std::thread olivia(philosopher, std::ref(chopsticks));
    barron.join();
    olivia.join();
    printf("The philosophers are done eating.\n");
}
```

When this program is run, I get the message that one of the philosophers has had enough, but the other philosopher never finishes eating the last few pieces of sushi. That other thread is stuck waiting on a mutex that will never get unlocked so the program will be stuck here forever. This scenario is not the same as the deadlock we looked at previously, because the two threads are not waiting on each other to release a lock. But, it's a related scenario and the impact is the same. The program isn't making any progress.

A good way to avoid this problem with C++ is to use a mutex wrapper class like the scoped lock.

```cpp
#include <thread>
#include <mutex>

int sushi_count = 5000;

void philosopher(std::mutex &chopsticks) {
    while (sushi_count > 0) {
        std::scoped_lock lock(chopsticks);
        if (sushi_count) {
            sushi_count--;
        }
        if (sushi_count == 10) {
            printf("This philosopher has had enough!\n");
            break;
        }
    }
}

int main() {
    std::mutex chopsticks;
    std::thread barron(philosopher, std::ref(chopsticks));
    std::thread olivia(philosopher, std::ref(chopsticks));
    barron.join();
    olivia.join();
    printf("The philosophers are done eating.\n");
}
```

I'll replace the lock function on line 11 with the code to create a new scoped lock object named lock using the chopsticks mutex. And then delete the unlock function on line 19.

The scoped lock will only hold onto its lock of the mutex for the scope in which the scoped locked object was created which is the while loop iteration. If something happens to make the loop exit prematurely, like the break statement on line 17, the scope locked will automatically release its lock on the mutex for another thread to take. Using the scoped lock, the program is able to run until the end even after one of the philosopher threads has had more than enough sushi.
