Call Stacks and Exceptions

Call Stacks and Exception Handling
The runtime seeks the closest exception handler to a thrown exception.
If there is a matching exception handler in the current stack frame, it will
handle the exception. If no matching handler is found, the runtime will
unwind the call stack until it finds a suitable handler. Any objects whose
lifetimes end are destroyed in the usual way.

Throwing in Destructors
If you throw an exception in a destructor, you are juggling with chainsaws. Such an exception absolutely must be caught within the destructor.

Suppose an exception is thrown, and during stack unwinding, another exception is thrown by a destructor during normal cleanup. Now you have two exceptions in flight. How should the C++ runtime handle such a situation?

The runtime will call terminate.

Consider throwing an exception from a destructor:

#include <cstdio>
#include <stdexcept>
struct CyberdyneSeries800
{
  CyberdyneSeries800()
  {
    printf( "I'm a friend of Sarah Connor." );
  }
  ~CyberdyneSeries800()
  {
    throw std::runtime_error{ "I'll be back." };
  }
};

int main() {
  try
  {
    CyberdyneSeries800 t800;
    throw std::runtime_error{ "Come with me if you want to live." };
  }
  catch(const std::exception& e)
  {
    printf("Caught exception: %s\n", e.what());
  }
}


First, you declare the CyberdyneSeries800 class, which has a simple constructor that prints a message and a thoroughly belligerent destructor
that throws an uncaught exception.

Within main, you set up a try block where you initialize a CyberdyneSeries800 called t800 and throw a runtime_error. Under better circumstances, the catch block would handle this exception, print its message, and exit gracefully. Because t800 is an automatic variable within the try block, it destructs during the normal process of finding a handler for the exception you’ve thrown.

And because t800 throws an exception in its destructor, your program invokes
std::terminate and ends abruptly.

As a general rule, treat destructors as if they were noexcept.
