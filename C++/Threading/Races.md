### Races
In multithreading environment data sharing between threads is very easy. But this easy sharing of data can cause problems in application.

One such problem is Data Race

Data races are a kind of a bug that occurs in multithreaded applications.

When two or more threads perform a set of operations in parallel, that access the same memory location, and one or more thread out of them modifies the data in that memory location, then this can lead to unexpected results.

Data races are usually hard to find and reproduce because they don’t occur every time. They will occur only when relative order of execution of operations by two or more threads leads to an unexpected result.

A Practical example of a data race

Let’s Create a Wallet class that internally maintains money and provides a service/function i.e. addMoney(). This member function increments the internal money of wallet object by specified count.

```cpp
class Wallet
{
    int mMoney;
public:
    Wallet() :mMoney(0){}
    int getMoney() { return mMoney; }
    void addMoney(int money)
    {
       for(int i = 0; i < money; ++i)
       {
          mMoney++;
       }
    }
};
```

Now Let’s create 5 threads and all these threads will share a same object of class Wallet and add 1000 to internal money using it’s addMoney() member function in parallel.

So, if initially money in wallet is 0. We would expect, after the thread’s execution, the money in Wallet should be 5000.

But, as all threads are modifying the shared data at same time, it might be possible that in some scenarios money in wallet at end will be much lesser than 5000.

```cpp
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
       std::cout << "Error at count = "<<k<<" Money in Wallet = "<<val << std::endl;
     }
  }
  return 0;
}
```

As addMoney() member function of same Wallet class object is executed 5 times hence it’s internal money is expected to be 5000. But as addMoney() member function is executed in parallel hence in some scenarios mMoney will be much lesser than 5000 i.e.

Example Output
Error at count = 971  Money in Wallet = 4568                               Error at count = 971  Money in Wallet = 4568
Error at count = 972  Money in Wallet = 4260
Error at count = 972  Money in Wallet = 4260
Error at count = 973  Money in Wallet = 4976
Error at count = 973  Money in Wallet = 4976

This is a data race, as two or more threads were trying to modify the same memory location at same time and lead to unexpected result.

Each thread increments the same “mMoney” member variable in parallel. Although it seems a single line but this “mMoney++” is actually converted into three machine commands,

    Load “mMoney” variable value in Register
    Increment register’s value
    Update variable “mMoney” with register’s value

In this scenario it is possible that threads will perform the load or update actions at the same time either leading to increments geting neglected because instead of incrementing the “mMoney” variable twice, different registers got incremented and “mMoney” variable’s value was overwritten.

NOTE
data races are liable to happen whenever multiple threads are accessing and updating a piece of shared memory. Since a data race only occurs when at least one of the concurrent threads is modifying the value of a memory location, pay close attention to anywhere you see an assignment operation or an operator that changes a variable's value. If there's a potential that two or more threads could access that variable, then you will almost certainly need to use some mechanism to protect it.




### Race Conditions

Data races and race conditions are two different potential problems in concurrent programs that people often confuse.

Data races can occur when two or more threads concurrently access the same memory location. If at least one of those threads is writing to or changing that memory value that can cause the threads to overwrite each other or read wrong values.

To prevent those data races, you need to ensure mutual exclusion for the shared resource.


A race condition on the other hand is a flaw in the timing or ordering of a program's execution that causes incorrect behavior.

In practice, many race conditions are caused by data races and many data races lead to race conditions. But those two problems are not dependent on each other. It's possible to have data races without a race condition, and race conditions without a data race.


Imagine two people are inviting friends over for a party and want to buy chips for the occasion

The shopping list is the shared resource and this pencil serves as a mutex to protect it. Only the person or thread with the pencil can view or modify the shopping list.

The shopping list starts with one bag of chips
The hosts are represented by two threads,
  thread one adds three bags of chips to the list
  thread two doubles the number of chips on the list


Lets see how scheduling effects the outcome

In scenario one

Thread one is scheduled first, aquires the mutex, then changes the number of bags by adding three to the number, from 1 to 4, then releases the mutex.
Thread two is scheduled first, aquires the mutex, then changes the number of bags by doubling the number, from 4 to 8, then releases the mutex.


In scenario two

Thread two is scheduled first, aquires the mutex, then changes the number of bags by doubling the number, from 1 to 2, then releases the mutex.
Thread two is scheduled first, aquires the mutex, then changes the number of bags by adding three to the number, from 2 to 5, then releases the mutex.


Even though we're using a mutext to protect against a data race, the potential for a race condition still exists because the order in which our threads execute is not deterministic.

The race condition we created here is fairly straight forward. But in practice, race conditions can be really hard to discover.

This is because a program might run correctly for millions of times while you're building and testing it in one environment.
The finished program is then released and run in many different user environements and things happen to execute in a different order, causing incorrect results.

Unfortunately, there's not a single catch-all way to detect race conditions. Sometimes, putting sleep statements at different places throughout your code can help to uncover potential race conditions by changing the timing and therefore order in which threads get executed.

That said, race conditions are often a type of heisenbug, which is a software bug that seems to disappear or alter its behavior when you try to study it. Running debuggers and doing things to affect the timing of your code in search of a race condition may actually prevent the race condition from occurring.
