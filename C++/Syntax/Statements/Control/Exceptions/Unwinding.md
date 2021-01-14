Call Stacks and Exceptions

Call Stacks and Exception Handling
The runtime seeks the closest exception handler to a thrown exception.
If there is a matching exception handler in the current stack frame, it will
handle the exception. If no matching handler is found, the runtime will
unwind the call stack until it finds a suitable handler. Any objects whose
lifetimes end are destroyed in the usual way.


At this point, some of you are probably wondering why it’s a good idea to pass errors back to the caller. Why not just make MySqrt() handle its own error? The problem is that different applications may want to handle errors in different ways. A console application may want to print a text message. A windows application may want to pop up an error dialog. In one application, this may be a fatal error, and in another application it may not be. By passing the error back up the stack, each application can handle an error from mySqrt() in a way that is the most context appropriate for it! Ultimately, this keeps mySqrt() as modular as possible, and the error handling can be placed in the less-modular parts of the code.

There are quite a few interesting principles illustrated by this program:

First, the immediate caller of a function that throws an exception doesn’t have to handle the exception if it doesn’t want to. It delegated that responsibility to one of its callers up the stack.

Second, if a try block doesn’t have a catch handler for the type of exception being thrown, stack unwinding occurs just as if there were no try block at all.

Third, once an exception is handled, control flow proceeds as normal starting from the end of the catch blocks.

As you can see, stack unwinding provides us with some very useful behavior -- if a function does not want to handle an exception, it doesn’t have to. The exception will propagate up the stack until it finds someone who will! This allows us to decide where in the call stack is the most appropriate place to handle any errors that may occur.


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
