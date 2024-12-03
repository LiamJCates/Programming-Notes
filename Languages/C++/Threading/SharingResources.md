### Sharing Resources
The ability to use the same resources is convenient, but it does create the potential to cause problems if the actions of each thread are not coordinated.

Sharing resources between separate processes is not as easy as sharing between threads in the same process, because every process exists in its own address space. Variables and data are isolated to this address space. The threads in one process can't directly access the data of another process.

There are ways to communicate and share data between processes, but it requires a bit more work than communicating between threads. You have to use system provided inter-process communication mechanisms like sockets and pipes, allocating special inter-process shared memory space, or using remote procedure calls.



### Threads or Processes
It's possible to write parallel programs that use multiple processes working together towards a common goal, or using multiple threads within a single process.

So which is better, using multiple threads or multiple processes? - Well, like most things in programming, it depends. It depends on what you're doing and the environment it's running in, because the implementation of threads and processes differs between operating systems and programming languages.

If your application is going to be distributed across multiple computers, you'll most likely need separate processes for that.

As a rule of thumb, if you can structure your program to take advantage of multiple threads, stick with using threads, rather than multiple processes. Threads are considered lightweight compared to processes, which are more resource intensive. A thread requires less overhead to create and terminate than a process, and it's usually faster for an operating system to switch between executing threads from the same process, than to switch between different processes.

The getpid() function returns the process ID
The get_id() function returns the thread ID

```cpp
/**
 * Threads that waste CPU cycles
 */
#include <thread>
#include <chrono>
#include <unistd.h>

// a simple function that wastes CPU cycles "forever"
void cpu_waster()
{
	printf("CPU Waster Process ID: %d\n", getpid());
	printf("CPU Waster Thread ID %d\n", std::this_thread::get_id());
	while(true) continue;
}

int main()
{
	printf("Main Process ID: %d\n", getpid());
	printf("Main Thread ID: %d\n", std::this_thread::get_id());
	std::thread thread1(cpu_waster);
	std::thread thread2(cpu_waster);

	// keep the main thread alive "forever"
	while(true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}
```


### Passing Arguments

To Pass arguments to thread’s associated callable object or function just pass additional arguments to the std::thread constructor.

By default all arguments are copied into the internal storage of new thread.

Lets look at an example

```cpp
#include <iostream>
#include <string>
#include <thread>
void threadCallback(int x, std::string str)
{
    std::cout<<"Passed Number = "<<x<<std::endl;
    std::cout<<"Passed String = "<<str<<std::endl;
}
int main()  
{
    int x = 10;
    std::string str = "Sample String";
    std::thread threadObj(threadCallback, x, str);
    threadObj.join();
    return 0;
}
```

How not to pass arguments to threads in C++11

Don’t pass addresses of variables from local stack to thread’s callback function. Because it might be possible that local variable in Thread 1 goes out of scope but Thread 2 is still trying to access it through it’s address.
In such scenario accessing invalid address can cause unexpected behaviour.
For example,

```cpp
#include <iostream>
#include <thread>
void newThreadCallback(int * p)
{
    std::cout<<"Inside Thread :  "" : p = "<<p<<std::endl;
    std::chrono::milliseconds dura( 1000 );
    std::this_thread::sleep_for( dura );
    *p = 19;
}
void startNewThread()
{
    int i = 10;
    std::cout<<"Inside Main Thread :  "" : i = "<<i<<std::endl;
    std::thread t(newThreadCallback,&i);
    t.detach();
    std::cout<<"Inside Main Thread :  "" : i = "<<i<<std::endl;
}
int main()
{
    startNewThread();
    std::chrono::milliseconds dura( 2000 );
    std::this_thread::sleep_for( dura );
    return 0;
}
```

Similarly be careful while passing pointer to memory located on heap to thread. Because it might be possible that some thread deletes that memory before new thread tries to access it.

In such scenario accessing invalid address can cause unexpected behaviour.
For example,

```cpp
#include <iostream>
#include <thread>
void newThreadCallback(int * p)
{
    std::cout<<"Inside Thread :  "" : p = "<<p<<std::endl;
    std::chrono::milliseconds dura( 1000 );
    std::this_thread::sleep_for( dura );
    *p = 19;
}
void startNewThread()
{
    int * p = new int();
    *p = 10;
    std::cout<<"Inside Main Thread :  "" : *p = "<<*p<<std::endl;
    std::thread t(newThreadCallback,p);
    t.detach();
    delete p;
    p = NULL;
}
int main()
{
    startNewThread();
    std::chrono::milliseconds dura( 2000 );
    std::this_thread::sleep_for( dura );
    return 0;
}
```

How to pass references to std::thread in C++11

As arguments are copied to new threads stack so, if you need to pass references in common way i.e.

```cpp
#include <iostream>
#include <thread>
void threadCallback(int const & x)
{
    int & y = const_cast<int &>(x);
    y++;
    std::cout<<"Inside Thread x = "<<x<<std::endl;
}
int main()
{
    int x = 9;
    std::cout<<"In Main Thread : Before Thread Start x = "<<x<<std::endl;
    std::thread threadObj(threadCallback, x);
    threadObj.join();
    std::cout<<"In Main Thread : After Thread Joins x = "<<x<<std::endl;
    return 0;
}
```
Output:
```
In Main Thread : Before Thread Start x = 9
Inside Thread x = 10
In Main Thread : After Thread Joins x = 9
```
Even if threadCallback accepts arguments as reference but still changes done it are not visible outside the thread.
Its because x in the thread function threadCallback is reference to the temporary value copied at the new thread’s stack.

How to fix this ?

Using std::ref() i.e.
```cpp
#include <iostream>
#include <thread>
void threadCallback(int const & x)
{
    int & y = const_cast<int &>(x);
    y++;
    std::cout<<"Inside Thread x = "<<x<<std::endl;
}
int main()
{
    int x = 9;
    std::cout<<"In Main Thread : Before Thread Start x = "<<x<<std::endl;
    std::thread threadObj(threadCallback,std::ref(x));
    threadObj.join();
    std::cout<<"In Main Thread : After Thread Joins x = "<<x<<std::endl;
    return 0;
}
```
Output:
```
In Main Thread : Before Thread Start x = 9
Inside Thread x = 10
In Main Thread : After Thread Joins x = 10
```

Assigning pointer to member function of a class as thread function:

Pass the pointer to member function as callback function and pass pointer to Object as second argument.

For example:

```cpp
#include <iostream>
#include <thread>
class DummyClass {
public:
    DummyClass()
    {}
    DummyClass(const DummyClass & obj)
    {}
    void sampleMemberFunction(int x)
    {
        std::cout<<"Inside sampleMemberFunction "<<x<<std::endl;
    }
};
int main() {

    DummyClass dummyObj;
    int x = 10;
    std::thread threadObj(&DummyClass::sampleMemberFunction,&dummyObj, x);
    threadObj.join();
    return 0;
}
```
