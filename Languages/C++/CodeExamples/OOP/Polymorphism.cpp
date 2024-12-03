/*
Suppose you’re in charge of implementing a Bank class that transfers money
between accounts. Auditing is very important for the Bank class’s transactions,
so you provide support for logging with a ConsoleLogger class
*/

#include <cstdio>
struct ConsoleLogger {
  void log_transfer(long from, long to, double amount) {
    printf("%ld -> %ld: %f\n", from, to, amount);
  }
};
struct Bank {
  void make_transfer(long from, long to, double amount) {
    --snip--
    logger.log_transfer(from, to, amount);
  }
  ConsoleLogger logger;
};
int main() {
  Bank bank;
  bank.make_transfer(1000, 2000, 49.95);
  bank.make_transfer(2000, 4000, 20.00);
}

/*
Suppose you have a requirement to implement different kinds of loggers.
For example, you might require a remote server logger, a local file logger, or
even a logger that sends jobs to a printer. In addition, you must be able to
change how the program logs at runtime (for example, an administrator
might need to switch from logging over the network to logging to the local
filesystem because of some server maintenance).
How can you accomplish such a task?
A simple approach is to use an enum class to switch between the various
loggers.
*/

#include <cstdio>
#include <stdexcept>

struct FileLogger {
  void log_transfer(long from, long to, double amount) {
    --snip--
    printf("[file] %ld,%ld,%f\n", from, to, amount);
  }
};

struct ConsoleLogger {
  void log_transfer(long from, long to, double amount) {
    printf("[cons] %ld -> %ld: %f\n", from, to, amount);
  }
};

enum class LoggerType {
  Console,
  File
};

struct Bank {
  Bank() : type { LoggerType::Console } { }
  void set_logger(LoggerType new_type) {
    type = new_type;
  }
  void make_transfer(long from, long to, double amount) {
    --snip--
    switch(type) {
      case LoggerType::Console: {
        consoleLogger.log_transfer(from, to, amount);
        break;
      } case LoggerType::File: {
        fileLogger.log_transfer(from, to, amount);
        break;
      } default: {
        throw std::logic_error("Unknown Logger type encountered.");
      } }
    }
  private:
    LoggerType type;
    ConsoleLogger consoleLogger;
    FileLogger fileLogger;
  };
  int main() {
    Bank bank;
    bank.make_transfer(1000, 2000, 49.95);
    bank.make_transfer(2000, 4000, 20.00);
    bank.set_logger(LoggerType::File);
    bank.make_transfer(3000, 2000, 75.00);
  }
/*
this approach suffers from several design problems.
Adding a new kind of logging requires you to make several updates
throughout the code:
1. You need to write a new logger type.
2. You need to add a new enum value to the enum class LoggerType.
3. You must add a new case in the switch statement y.
4. You must add the new logging class as a member to Bank.
That’s a lot of work for a simple change!
Consider an alternative approach where Bank holds a pointer to a logger.
This way, you can set the pointer directly and get rid of LoggerType entirely.
You exploit the fact that your loggers have the same function prototype.
This is the idea behind an interface: the Bank class doesn’t need to know the
implementation details of the Logger reference it holds, just how to invoke its
methods.
*/

#include <cstdio>
struct Logger
{
  virtual ~Logger() = default;
  virtual void log_transfer(long from, long to, double amount) = 0;
};

struct ConsoleLogger : Logger
{
  void log_transfer(long from, long to, double amount) override
  {
    printf("%ld -> %ld: %f\n", from, to, amount);
  }
};

/*
Updating the Bank Logger
The Logger interface allows you to provide multiple logger implementations.
This allows a Logger consumer to log transfers with the log_transfer method
without having to know the logger’s implementation details.

Consider how you can add another implementation called FileLogger. For simplicity, in this code you’ll only modify the log output’s prefix, but you can imagine how you might implement some more complicated behavior.
*/

#include <cstdio>
struct Logger {
  virtual ~Logger() = default;
  virtual void log_transfer(long from, long to, double amount) = 0;
};
struct ConsoleLogger : Logger {
  void log_transfer(long from, long to, double amount) override {
    printf("[cons] %ld -> %ld: %f\n", from, to, amount);
  }
};

struct FileLogger : Logger {
  void log_transfer(long from, long to, double amount) override {
    printf("[file] %ld,%ld,%f\n", from, to, amount);
  }
};

/*
Logger is a pure virtual class (interface) with a default virtual destructor
and a single method log_transfer.

ConsoleLogger and FileLogger are Logger implementations, because they derive from the interface. You’ve implemented log_transfer and placed the override keyword on both.
*/

/*
Now we’ll look at how you could use either constructor injection or
property injection to update Bank.


Constructor Injection
Using constructor injection, you have a Logger reference that you pass into
the Bank class’s constructor. By incorporating the appropriate Bank constructor, you establish the kind of logging that a particular Bank instantiation will perform.
*/

struct Bank {
  Bank(Logger& logger) : logger{ logger } { }
  void make_transfer(long from, long to, double amount) {
    --snip--
    logger.log_transfer(from, to, amount);
  }
private:
  Logger& logger;
};
int main() {
  ConsoleLogger logger;
  Bank bank{ logger }; v
  bank.make_transfer(1000, 2000, 49.95);
  bank.make_transfer(2000, 4000, 20.00);
}

/*
The Bank class’s constructor sets the value of logger using a member initializer. References can’t be reseated, so the object that logger points to
doesn’t change for the lifetime of Bank. You fix your logger choice upon Bank
construction.
*/

/*
Property Injection
Instead of using constructor injection to insert a Logger into a Bank, you
could use property injection. This approach uses a pointer instead of a
reference. Because pointers can be reseated (unlike references), you can
change the behavior of Bank whenever you like.
*/

struct Bank {
  void set_logger(Logger* new_logger) {
    logger = new_logger;
  }
  void make_transfer(long from, long to, double amount) {
    if (logger) logger->log_transfer(from, to, amount);
  }
private:
  Logger* logger{};
};
int main() {
  ConsoleLogger console_logger;
  FileLogger file_logger;
  Bank bank;
  bank.set_logger(&console_logger);
  bank.make_transfer(1000, 2000, 49.95);
  bank.set_logger(&file_logger);
  bank.make_transfer(2000, 4000, 20.00);
}


/*
Choosing Constructor or Property Injection
Whether you choose constructor or property injection depends on design
requirements. If you need to be able to modify underlying types of an object’s
members throughout the object's life cycle, you should choose pointers
and the property injector method. But the flexibility of using pointers and
property injection comes at a cost. In the Bank example in this chapter, you
must make sure that you either don’t set logger to nullptr or that you check
for this condition before using logger. There’s also the question of what the
default behavior is: what is the initial value of logger?
One possibility is to provide constructor and property injection.
This encourages anyone who uses your class to think about initializing
it.
*/

#include <cstdio>
struct Logger {
--snip--
};
struct Bank {
Bank(Logger* logger) : logger{ logger } ()
void set_logger(Logger* new_logger) {
logger = new_logger;
}
void make_transfer(long from, long to, double amount) {
if (logger) logger->log_transfer(from, to, amount);
}
private:
Logger* logger;
};

/*
As you can see, you can include a constructor and a setter. This
requires the user of a Bank to initialize logger with a value, even if it’s just
nullptr. Later on, the user can easily swap out this value using property
injection.
*/
