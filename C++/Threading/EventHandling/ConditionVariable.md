### Condition Variables

Condition Variable is a kind of Event used for signaling between two or more threads. One or more thread can wait on it to get signaled, while an another thread can signal this.

Header file required for condition Variable in C++11 is ,
#include <condition_variable>

A mutex is required along with condition variable.

How things actually work with condition variable,

    Thread 1 calls the wait on condition variable, which internally acquires the mutex and check if required condition is met or not.
    If not then it releases the lock and waits for Condition Variable to get signaled ( thread gets blocked). Condition Variable’s wait() function provides both these operations in atomic manner.
    Another Thread i.e. like Thread 2 signals the Condition Variable when condition is met
    Once Conditional Variable get signaled the the Thread 1 which was waiting for it resumes. It then acquires the mutex lock again and checks if the condition associated with Condition Variable is actually met or if it is superiors call. If more than one thread was waiting then notify_one will unblock only one thread.
    If it was a superiors call then it again calls the wait() function.

Main member functions for std::condition_variable are,

Wait()

It makes the current thread to block until the condition variable get signaled or a spurious wake up happens.

It atomically releases the attached mutex, blocks the current thread, and adds it to the list of threads waiting on the current condition variable object. The thread will be unblocked when some thread calls notify_one() or notify_all() on same condition variable object. It may also be unblocked spuriously, therefore after every unblocking it needs to check condition again.

A callback is passed as an parameter to this function, which will be called to check if it is a spurious call or actually condition is met.

When threads get unlocked,

wait() function reacquires the mutex lock and checks that actually condition is met or not. If condition is not met then again it atomically releases the attached mutex, blocks the current thread, and adds it to the list of threads waiting on the current condition variable object.

notify_one()

If any threads are waiting on same conditional variable object then  notify_one unblocks one of the waiting threads.

notify_all()

If any threads are waiting on same conditional variable object then  notify_all unblocks all of the waiting threads.

Let’s see how we can handle previously discussed multi threaded scenario with condition variable i.e.

```cpp
#include <iostream>
#include <thread>
#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std::placeholders;
class Application
{
  std::mutex m_mutex;
  std::condition_variable m_condVar;
  bool m_bDataLoaded;
public:
  Application()
  {
    m_bDataLoaded = false;
  }
  void loadData()
  {
   // Make This Thread sleep for 1 Second
   std::this_thread::sleep_for(std::chrono::milliseconds(1000));
   std::cout<<"Loading Data from XML"<<std::endl;
   // Lock The Data structure
   std::lock_guard<std::mutex> guard(m_mutex);
   // Set the flag to true, means data is loaded
   m_bDataLoaded = true;
   // Notify the condition variable
   m_condVar.notify_one();
  }
  bool isDataLoaded()
  {
    return m_bDataLoaded;
  }
  void mainTask()
  {
    std::cout<<"Do Some Handshaking"<<std::endl;
    // Acquire the lock
    std::unique_lock<std::mutex> mlock(m_mutex);
    // Start waiting for the Condition Variable to get signaled
    // Wait() will internally release the lock and make the thread to block
    // As soon as condition variable get signaled, resume the thread and
    // again acquire the lock. Then check if condition is met or not
    // If condition is met then continue else again go in wait.
    m_condVar.wait(mlock, std::bind(&Application::isDataLoaded, this));
    std::cout<<"Do Processing On loaded Data"<<std::endl;
  }
};
int main()
{
   Application app;
   std::thread thread_1(&Application::mainTask, &app);
   std::thread thread_2(&Application::loadData, &app);
   thread_2.join();
   thread_1.join();
   return 0;
}
```


### std::future , std::promise and Returning values from Thread

A std::future object can be used with asych, std::packaged_task and std::promise. In this article will mainly focus on using std::future with std::promise object.

Many times we encounter a situation where we want a thread to return a result.

Now question is how to do this?

Lets take an example,

Suppose in our application we created a thread that will compress a given folder and we want this thread to return the new zip file name and its size in result.

Now to do this we have 2 ways,

1.) Old Way : Share data among threads using pointer

Pass a pointer to the new thread and this thread will set the data in it. Till then in main thread keep on waiting using a condition variable. When new thread sets the data and signals the condition variable, then main thread will wake up and fetch the data from that pointer.

To do a simple thing we used a condition variable, a mutex and a pointer i.e. 3 items to catch a returned value.
Now suppose we want this thread to return 3 different values at different point of time then problem will become more complex. Could there be a simple solution for returning the value from threads.

The answer is yes using std::future, checkout next solution for it.

2.) C++11 Way : Using std::future and std::promise

std::future is a class template and its object stores the future value.
Now what the hell is this future value.

Actually a std::future object internally stores a value that will be assigned in future and it also provides a mechanism to access that value i.e. using get() member function. But if somebody tries to access this associated value of future through get() function before it is available, then get() function will block till value is not available.

std::promise is also a class template and its object promises to set the value in future. Each std::promise object has an associated std::future object that will give the value once set by the std::promise object.

A std::promise object shares data with its associated std::future object.

Lets see step by step,

Create a std::promise object in Thread1.
std::promise<int> promiseObj;

As of now this promise object doesn’t have any associated value. But it gives a promise that somebody will surely set the value in it and
once its set then you can get that value through associated std::future object.

But now suppose Thread 1 created this promise object and passed it to Thread 2 object. Now how Thread 1 can know that when Thread 2 is going to set the value in this promise object?

The answer is using std::future object.

Every std::promise object has an associated std::future object, through which others can fetch the value set by promise.

So, Thread 1 will create the std::promise object and then fetch the std::future object from it before passing the std””promise object to thread 2 i.e.
 std::future<int> futureObj = promiseObj.get_future();

Now Thread 1 will pass the promiseObj to Thread 2.

Then Thread 1 will fetch the value set by Thread 2 in std::promise through std::future’s get function,
  int val = futureObj.get();

But if value is not yet set by thread 2 then this call will get blocked until thread 2 sets the value in promise object i.e.
  promiseObj.set_value(45);


std::promise and std::future

Lets see a complete std::future and std::promise example,

```cpp
#include <iostream>
#include <thread>
#include <future>
void initiazer(std::promise<int> * promObj)
{
    std::cout<<"Inside Thread"<<std::endl;     promObj->set_value(35);
}
int main()
{
    std::promise<int> promiseObj;
    std::future<int> futureObj = promiseObj.get_future();
    std::thread th(initiazer, &promiseObj);
    std::cout<<futureObj.get()<<std::endl;
    th.join();
    return 0;
}
```

If std::promise object is destroyed before setting the value the calling get() function on associated std::future object will throw exception.
A part from this, if you want your thread to return multiple values at different point of time then just pass multiple std::promise objects in thread and fetch multiple return values from thier associated multiple std::future objects.



###Async
what is std::async()

std::async() is a function template that accepts a callback(i.e. function or function object) as an argument and potentially executes them asynchronously.
template <class Fn, class... Args>
future<typename result_of<Fn(Args...)>::type> async (launch policy, Fn&& fn, Args&&... args);

std::async returns a std::future<T>, that stores the value returned by function object executed by std::async(). Arguments expected by function can be passed to std::async() as arguments after the function pointer argument.

First argument in std::async is launch policy, it control the asynchronous behaviour of std::async. We can create std::async with 3 different launch policies i.e.

    std::launch::async
        It guarantees the asynchronous behaviour i.e. passed function will be executed in seperate thread.
    std::launch::deferred
        Non asynchronous behaviour i.e. Function will be called when other thread will call get() on future to access the shared state.
    std::launch::async | std::launch::deferred
        Its the default behaviour. With this launch policy it can run asynchronously or not depending on the load on system. But we have no control over it.

If we do not specify an launch policy. Its behaviour will be similar to std::launch::async | std::launch::deferred.

We are going to use std::launch::async launch policy in this article.

We can pass any callback in std::async i.e.

    Function Pointer
    Function Object
    Lambda Function

Let’s understand the need of std::async by an example,
Need of std::async()

Suppose we have to fetch some data (string) from DB and some from files in file-system. Then I need to merge both the strings and print.

In a single thread we will do like this,
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std::chrono;
std::string fetchDataFromDB(std::string recvdData)
{
    // Make sure that function takes 5 seconds to complete
    std::this_thread::sleep_for(seconds(5));
    //Do stuff like creating DB Connection and fetching Data
    return "DB_" + recvdData;
}
std::string fetchDataFromFile(std::string recvdData)
{
    // Make sure that function takes 5 seconds to complete
    std::this_thread::sleep_for(seconds(5));
    //Do stuff like fetching Data File
    return "File_" + recvdData;
}
int main()
{
    // Get Start Time
    system_clock::time_point start = system_clock::now();
    //Fetch Data from DB
    std::string dbData = fetchDataFromDB("Data");
    //Fetch Data from File
    std::string fileData = fetchDataFromFile("Data");
    // Get End Time
    auto end = system_clock::now();
    auto diff = duration_cast < std::chrono::seconds > (end - start).count();
    std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;
    //Combine The Data
    std::string data = dbData + " :: " + fileData;
    //Printing the combined Data
    std::cout << "Data = " << data << std::endl;
    return 0;
}

Output:
Total Time Taken = 10 Seconds
Data = DB_Data :: File_Data

As both the functions fetchDataFromDB() & fetchDataFromFile() takes 5 seconds each and are running in a single thread so, total time consumed will be 10 seconds.

Now as fetching data from DB and file are independent of each other and also time consuming. So, we can run them in parallel.
One way to do is create a new thread pass a promise as an argument to thread function and fetch data from associated std::future object in calling thread.

The other easy way is using std::async.
Calling std::async with function pointer as callback

Now let’s modify the above code and call fetchDataFromDB() asynchronously using std::async() i.e.
std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");
// Do Some Stuff
//Fetch Data from DB
// Will block till data is available in future<std::string> object.
std::string dbData = resultFromDB.get();

std::async() does following things,

    It automatically creates a thread (Or picks from internal thread pool) and a promise object for us.
    Then passes the std::promise object to thread function and returns the associated std::future object.
    When our passed argument function exits then its value will be set in this promise object, so eventually return value will be available in std::future object.

Now change the above example and use std::async to read data from DB asyncronously i.e.

Checkout the compete example as follows,
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>
using namespace std::chrono;
std::string fetchDataFromDB(std::string recvdData)
{
    // Make sure that function takes 5 seconds to complete
    std::this_thread::sleep_for(seconds(5));
    //Do stuff like creating DB Connection and fetching Data
    return "DB_" + recvdData;
}
std::string fetchDataFromFile(std::string recvdData)
{
    // Make sure that function takes 5 seconds to complete
    std::this_thread::sleep_for(seconds(5));
    //Do stuff like fetching Data File
    return "File_" + recvdData;
}
int main()
{
    // Get Start Time
    system_clock::time_point start = system_clock::now();
    std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");
    //Fetch Data from File
    std::string fileData = fetchDataFromFile("Data");
    //Fetch Data from DB
    // Will block till data is available in future<std::string> object.
    std::string dbData = resultFromDB.get();
    // Get End Time
    auto end = system_clock::now();
    auto diff = duration_cast < std::chrono::seconds > (end - start).count();
    std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;
    //Combine The Data
    std::string data = dbData + " :: " + fileData;
    //Printing the combined Data
    std::cout << "Data = " << data << std::endl;
    return 0;
}

Now it will take 5 seconds only.

Output:
Total Time Taken = 5 Seconds
Data = DB_Data :: File_Data

 Calling std::async with Function Object as callback

/*
 * Function Object
 */
struct DataFetcher
{
    std::string operator()(std::string recvdData)
    {
        // Make sure that function takes 5 seconds to complete
        std::this_thread::sleep_for (seconds(5));
        //Do stuff like fetching Data File
        return "File_" + recvdData;
    }
};
//Calling std::async with function object
std::future<std::string> fileResult = std::async(DataFetcher(), "Data");



Calling std::async with Lambda function as callback

//Calling std::async with lambda function
std::future<std::string> resultFromDB = std::async([](std::string recvdData){
                        std::this_thread::sleep_for (seconds(5));
                        //Do stuff like creating DB Connection and fetching Data
                        return "DB_" + recvdData;
                    }, "Data");
