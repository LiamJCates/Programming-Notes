### C++11 Thread Library

Original C++ Standard supported only single thread programming. The new C++ Standard (referred to as C++11 or C++0x) was published in 2011. In C++11 a new thread library is introduced.

How to compile on Linux:
	g++ –std=c++11 example.cpp -lpthread

In every C++ application there is one default main thread i.e. main() function.

When a new process or program begins running it will start with just one thread, which is called the main thread because it's the main one that runs when the program begins. That main thread can then start or spawn additional threads to help out, referred to as its child threads, which are part of the same process but execute independently to do other tasks. Those threads can spawn their own children if needed.

As each of those threads finish executing they'll notify their parent and terminate. Typically the main thread is the last to finish execution.

How threads are actually compiled and implemented under the hood can vary between operating systems, but by writing our code using the C++ Standard Library's thread class, it should be portable to different development environments.



### Initialization

In C++ 11 we can create additional threads by creating objects of std::thread class. Each of the std::thread object can be associated with a thread.

Header:
	#include <thread>

We initialize callback with the std::thread object, that will be executed when this new thread starts.

Callbacks Types
	Function Pointer
	Function Objects
	Lambda functions

Thread objects initialization syntax:

	std::thread thObj(<CALLBACK>);

A new Thread will start just after the initialization of the thread object and will execute the passed callback in parallel to thread that has started it.

Once the thread has finished executing the code supplied to it by it's initialization callback the thread will exit.


### Joining
Any thread can wait for a child threat to exit by calling join() function on that thread’s object.

Lets look at an example where main thread will create a separate thread. After creating this new thread, main thread will print some data on console and then wait for newly created thread to exit.

These implemention will used three different callback mechanism referenced above.


### Creating a thread using Function Pointer

```cpp
#include <iostream>
#include <thread>

void thread_function()
{
    for(int i = 0; i < 10000; i++);
        std::cout<<"thread function Executing"<<std::endl;
}

int main()  
{

    std::thread threadObj(thread_function);
    for(int i = 0; i < 10000; i++);
        std::cout<<"Display From MainThread"<<std::endl;
    threadObj.join();    
    std::cout<<"Exit of Main function"<<std::endl;
    return 0;
}
```

### Creating a thread using Function Objects

```cpp
#include <iostream>
#include <thread>
class DisplayThread
{
public:
    void operator()()     
    {
        for(int i = 0; i < 10000; i++)
            std::cout<<"Display Thread Executing"<<std::endl;
    }
};

int main()  
{
    std::thread threadObj( (DisplayThread()) );
    for(int i = 0; i < 10000; i++)
        std::cout<<"Display From Main Thread "<<std::endl;
    std::cout<<"Waiting For Thread to complete"<<std::endl;
    threadObj.join();
    std::cout<<"Exiting from Main Thread"<<std::endl;
    return 0;
}
```


### Creating a thread using Lambda functions

```cpp
#include <iostream>
#include <thread>
int main()  
{
    int x = 9;
    std::thread threadObj([]{
            for(int i = 0; i < 10000; i++)
                std::cout<<"Display Thread Executing"<<std::endl;
            });

    for(int i = 0; i < 10000; i++)
        std::cout<<"Display From Main Thread"<<std::endl;

    threadObj.join();
    std::cout<<"Exiting from Main Thread"<<std::endl;
    return 0;
}
```

### Differentiating between threads

Each of the std::thread object has an associated ID and we can fetch using,

Member function, gives id of associated thread object i.e.
std::thread::get_id()

To get the identifier for the current thread use,
std::this_thread::get_id()

If std::thread object does not have an associated thread then get_id() will return a default constructed std::thread::id object i.e. not any thread.

std::thread::id is a Object, it can be compared and printed on console too. Let’s look at an example,

```cpp
#include <iostream>
#include <thread>
void thread_function()
{
    std::cout<<"Inside Thread :: ID  = "<<std::this_thread::get_id()<<std::endl;    
}
int main()  
{
    std::thread threadObj1(thread_function);
    std::thread threadObj2(thread_function);

    if(threadObj1.get_id() != threadObj2.get_id())
        std::cout<<"Both Threads have different IDs"<<std::endl;

        std::cout<<"From Main Thread :: ID of Thread 1 = "<<threadObj1.get_id()<<std::endl;    
    std::cout<<"From Main Thread :: ID of Thread 2 = "<<threadObj2.get_id()<<std::endl;    

    threadObj1.join();    
    threadObj2.join();    
    return 0;
}
```
