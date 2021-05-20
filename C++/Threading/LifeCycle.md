#### Life Cycle
Over the lifecycle of a thread from creation through execution and finally termination, threads will usually be in one of four states.

New
threads will begin in the new state
the thread isn't actually running yet so it doesn't take any CPU resources.
Part of creating a new thread is assigning it a function, the code it's going to execute.
Some programming languages require you to explicitly start a thread after creating it.

Runnable
Once started, threads enter the runnable state, which means the operating system can schedule it to execute. Through contact switches, I'll get swapped out with other threads to run on one of the available processors.

Once the child thread is running independently the parent thread is free to continue executing it's own tasks

Blocked
When a thread needs to wait for an event to occur, like an external input or a timer, it goes into a blocked state. While blocked, it is not using any CPU resources, and leaves the processor free for other threads. The operating system will return it to the runnable state when the blocking condition is met.

A parent thread may eventually reach a point where I need to wait until one of my children threads has finished to continue. The thread can wait for a child by calling the join method. When I call join, the thread will enter a blocked state. Once the thread is joined by the child it wil go back to the runnable state and continue executing.

Terminated
Once a thread has finished executing it will notify the parent thread and then enter the final terminated state. A thread enters the terminated state when it either completes its execution or is abnormally aborted.

Different programming languages may use different names for their states and have a few additional ones but in general, new, runnable, blocked, and terminated are the four phases of the lifecycle of a thread.

```cpp
#include <thread>
#include <chrono>

void run()
{
	printf("Child running");
	std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main()
{
	printf("Main thread running...");
	std::thread child(run);

	printf("Main Continues...");
	std::this_thread::sleep_for(std::chrono::seconds(1));
	printf("Waiting for child...");
	child.join();

	printf("Both Done.");
}
```
