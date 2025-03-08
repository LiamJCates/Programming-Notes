## **Singleton Design Pattern: Detailed Breakdown**

### **1. Intent**  
The **Singleton** pattern ensures that a **class has only one instance** and provides a **global access point** to that instance.



### **2. Key Features**  

Singletons are often preferred to global variables because they do not pollute the global namespace (or their containing namespace). Additionally, they permit lazy allocation and initialization, whereas global variables in many languages will always consume resources.

The singleton pattern can also be used as a basis for other design patterns, such as the abstract factory, factory method, builder and prototype patterns. Facade objects are also often singletons because only one facade object is required.

Logging is a common real-world use case for singletons, because all objects that wish to log messages require a uniform point of access and conceptually write to a single source.


- **Single Instance:** Restricts the instantiation of a class to a single object.  
- **Global Access Point:** Provides a static method to access the instance.  
- **Lazy Allocation / Initialization (Optional):** Creates the instance only when it's first needed.  
- **Thread Safety (Optional):** Ensures safe access in multi-threaded environments.  

---

## **3. Singleton Implementation in C++**


Implementations of the singleton pattern ensure that only one instance of the singleton class ever exists and typically provide global access to that instance.

Typically, this is accomplished by:

    Declaring all constructors of the class to be private, which prevents it from being instantiated by other objects
    Providing a static method that returns a reference to the instance

The instance is usually stored as a private static variable; the instance is created when the variable is initialized, at some point before when the static method is first called. 






C++ provides multiple ways to implement the **Singleton** pattern. Below are **five variations**:

### **3.1 Basic Singleton (Non-thread-safe)**
```cpp
#include <iostream>

class Singleton {
private:
    static Singleton* instance; // Static instance pointer

    // Private constructor to prevent instantiation
    Singleton() { std::cout << "Singleton Instance Created" << std::endl; }

public:
    // Deleting copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Public method to access the instance
    static Singleton* getInstance() {
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() { std::cout << "Hello from Singleton!" << std::endl; }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s1->showMessage();

    std::cout << "s1 and s2 are the same instance: " << (s1 == s2) << std::endl;
    return 0;
}
```
#### **Key Points:**
- The **constructor** is private to prevent direct instantiation.
- The **copy constructor and assignment operator** are deleted to prevent cloning.
- The **static method `getInstance()`** ensures a **single instance** is created.
- **Not thread-safe!** Multiple threads can create multiple instances.

---

### **3.2 Thread-Safe Singleton (Using Mutex)**
```cpp
#include <iostream>
#include <mutex>

class Singleton {
private:
    static Singleton* instance;
    static std::mutex mutexLock;

    Singleton() { std::cout << "Thread-Safe Singleton Created" << std::endl; }

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        std::lock_guard<std::mutex> lock(mutexLock);
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void showMessage() { std::cout << "Thread-Safe Singleton Instance!" << std::endl; }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutexLock;

int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();
    return 0;
}
```
#### **Key Points:**
- Uses `std::mutex` to prevent **race conditions**.
- Ensures only **one instance** is created, even in **multi-threaded** environments.
- Performance overhead due to **mutex locking**.

---

### **3.3 Thread-Safe Singleton (C++11 `std::call_once`)**
```cpp
#include <iostream>
#include <mutex>

class Singleton {
private:
    static Singleton* instance;
    static std::once_flag flag;

    Singleton() { std::cout << "C++11 Thread-Safe Singleton Created" << std::endl; }

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        std::call_once(flag, []() { instance = new Singleton(); });
        return instance;
    }

    void showMessage() { std::cout << "C++11 Thread-Safe Singleton Instance!" << std::endl; }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
std::once_flag Singleton::flag;

int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();
    return 0;
}
```
#### **Key Points:**
- Uses `std::once_flag` and `std::call_once()` to ensure the instance is created **only once**.
- More **efficient than mutex-based locking**.

---

### **3.4 Meyers’ Singleton (C++11 Thread-Safe)**
```cpp
#include <iostream>

class Singleton {
private:
    Singleton() { std::cout << "Meyers' Singleton Created" << std::endl; }

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton& getInstance() {
        static Singleton instance; // Guaranteed thread-safe in C++11+
        return instance;
    }

    void showMessage() { std::cout << "Meyers' Singleton Instance!" << std::endl; }
};

int main() {
    Singleton& s1 = Singleton::getInstance();
    s1.showMessage();
    return 0;
}
```
#### **Key Points:**
- Uses **static local variable initialization** (C++11+ guarantees thread safety).
- No **manual memory management** (no need for `new` or `delete`).
- **Best and most recommended Singleton implementation in C++**.

---

### **3.5 Singleton with Smart Pointer (`std::unique_ptr`)**
```cpp
#include <iostream>
#include <memory>

class Singleton {
private:
    static std::unique_ptr<Singleton> instance;

    Singleton() { std::cout << "Singleton with Smart Pointer Created" << std::endl; }

public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* getInstance() {
        if (!instance) {
            instance = std::make_unique<Singleton>();
        }
        return instance.get();
    }

    void showMessage() { std::cout << "Smart Pointer Singleton Instance!" << std::endl; }
};

// Initialize static member
std::unique_ptr<Singleton> Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();
    return 0;
}
```
#### **Key Points:**
- Uses `std::unique_ptr` to **automatically manage memory**.
- Prevents **memory leaks**.
- Not **thread-safe**, but can be combined with `std::call_once()` for safety.

---

## **4. Pros & Cons of Singleton Pattern**
### **Pros:**
✅ **Ensures a single instance** of a class.  
✅ **Provides a global access point**.  
✅ **Can be lazily initialized** to improve efficiency.  
✅ **Thread-safe versions exist** (e.g., Meyers' Singleton).  

### **Cons:**
❌ **Violates the Single Responsibility Principle (SRP)** (manages instance creation).  
❌ **Introduces global state** (can lead to hidden dependencies).  
❌ **Not easily testable** (mocking is difficult).  
❌ **Multithreading concerns** (manual synchronization needed).  

---

## **5. When to Use Singleton?**
✔ **Configuration management** (e.g., Logger, Database Connection).  
✔ **Thread Pool management** (avoiding unnecessary object creation).  
✔ **Device drivers or OS kernel objects** (ensuring a single access point).  

🚫 **Avoid Singleton when:**
- You need to write unit tests with different instances.  
- The class does not **truly require a single instance**.  

---

## **Final Thoughts**
Use Singletons **wisely**, as they can **introduce hidden dependencies** and **global state issues**.


The **Meyers’ Singleton** is the **best** approach in **modern C++** due to **automatic memory management and built-in thread safety**. 




### **Which Implementation Should You Use?**
- **If using C++11 or later:** **Use Meyers’ Singleton (Best Choice)**
- **If using C++98/03:** **Use Double-Checked Locking (but be cautious of memory reordering issues)**





Lazy initialization
A singleton implementation may use lazy initialization in which the instance is created when the static method is first invoked. 
In multithreaded programs, this can cause race conditions that result in the creation of multiple instances. 


Here is a **thread-safe** Singleton implementation in C++ using **lazy initialization** with **double-checked locking**.

---

## **Thread-Safe Singleton with Double-Checked Locking**
```cpp
#include <iostream>
#include <mutex>

class Singleton {
private:
    static Singleton* instance;
    static std::mutex mutexLock;  // Mutex for synchronization

    // Private constructor to prevent direct instantiation
    Singleton() { std::cout << "Singleton Instance Created" << std::endl; }

public:
    // Deleting copy constructor and assignment operator to prevent copies
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    // Public method to get the Singleton instance
    static Singleton* getInstance() {
        if (instance == nullptr) {  // First check (without locking)
            std::lock_guard<std::mutex> lock(mutexLock);  // Lock the mutex
            if (instance == nullptr) {  // Second check (with locking)
                instance = new Singleton();
            }
        }
        return instance;
    }

    void showMessage() { std::cout << "Thread-Safe Singleton Instance!" << std::endl; }
};

// Initialize static members
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutexLock;

int main() {
    Singleton* s1 = Singleton::getInstance();
    s1->showMessage();
    
    return 0;
}
```

---

## **Explanation of Double-Checked Locking**
### **1️⃣ First Check (Outside the Lock)**
```cpp
if (instance == nullptr) {
```
- This prevents unnecessary **locking** when an instance **already exists**.  
- Improves performance by avoiding mutex overhead when the instance is already created.

### **2️⃣ Mutex Locking**
```cpp
std::lock_guard<std::mutex> lock(mutexLock);
```
- Ensures that **only one thread** enters the critical section.  
- Prevents race conditions in **multi-threaded environments**.

### **3️⃣ Second Check (Inside the Lock)**
```cpp
if (instance == nullptr) {
    instance = new Singleton();
}
```
- Ensures that **no other thread** created the instance while waiting for the lock.  

---

## **Why Use Double-Checked Locking?**
✅ **Thread-safe lazy initialization** (only creates an instance when needed).  
✅ **Minimizes locking overhead** (only locks on the first initialization).  
✅ **Efficient in performance-sensitive applications**.  

---

## **Potential Issues & Alternative Solutions**
### **1. Memory Order Issues in Some Compilers**
Some compilers may optimize instruction reordering, leading to a **partially constructed object** being accessed.  
- **Fix:** Use `std::atomic<Singleton*>` to prevent instruction reordering.



### **Hidden Dependencies and Global State Issues in Singleton Pattern**

The **Singleton pattern**, while useful, introduces risks such as **hidden dependencies** and **global state issues**. These problems can make code **hard to test, debug, and maintain**. Below is a detailed breakdown of these issues.

---

## **1. Hidden Dependencies**
A **hidden dependency** occurs when a class depends on a **global Singleton instance** but **this dependency is not explicitly stated**. This makes the class harder to understand and test.

### **Example of Hidden Dependency**
```cpp
class Logger {
public:
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    void log(const std::string& message) {
        std::cout << "[LOG]: " << message << std::endl;
    }
};

class UserService {
public:
    void createUser() {
        // Implicit dependency on Logger
        Logger::getInstance().log("User created");
    }
};
```
#### **Issues with Hidden Dependencies**
❌ **Implicit Dependency:**  
- `UserService` **depends on** `Logger::getInstance()`, but **this dependency is not visible** in its constructor.  
- If `Logger` is modified, `UserService` may break unexpectedly.

❌ **Difficult to Mock or Replace:**  
- Since `Logger` is accessed via `Logger::getInstance()`, we **cannot replace it** easily for testing.  
- A **better approach** is to inject `Logger` via constructor.

#### **Solution: Use Dependency Injection (DI)**
Instead of relying on the global `Logger` Singleton, pass it as a parameter:
```cpp
class UserService {
private:
    Logger& logger;

public:
    UserService(Logger& loggerInstance) : logger(loggerInstance) {}

    void createUser() {
        logger.log("User created");
    }
};
```
✅ **Explicit dependency**  
✅ **Easier to test by injecting a mock `Logger`**  

---

## **2. Global State Issues**
A **global state issue** occurs when a Singleton acts as a **global variable**, leading to unpredictable behavior and unintended side effects.

### **Example of Global State Problem**
```cpp
class Configuration {
public:
    static Configuration& getInstance() {
        static Configuration instance;
        return instance;
    }

    void setConfig(const std::string& key, const std::string& value) {
        config[key] = value;
    }

    std::string getConfig(const std::string& key) {
        return config[key];
    }

private:
    std::unordered_map<std::string, std::string> config;
};
```
If multiple parts of the program modify `Configuration`, it can **unexpectedly change behavior** elsewhere.

#### **Problems with Global State**
❌ **Unpredictable Behavior:**  
- If `Module A` changes `Configuration`, `Module B` might behave differently **without realizing why**.

❌ **Difficult Debugging:**  
- A **bug in one part of the codebase** can affect **other unrelated parts**, making debugging harder.

❌ **Thread Safety Issues:**  
- If multiple threads modify the global state, **race conditions** can occur.

#### **Solution: Pass Configuration Explicitly**
Instead of using a global `getInstance()`, pass `Configuration` explicitly:
```cpp
class Service {
private:
    Configuration& config;

public:
    Service(Configuration& cfg) : config(cfg) {}

    void doSomething() {
        std::cout << "Config value: " << config.getConfig("theme") << std::endl;
    }
};
```
✅ **Avoids unintended global state modification**  
✅ **Improves testability and maintainability**  

---

## **3. Singleton Makes Unit Testing Hard**
### **Why?**
- Singletons introduce **hardcoded dependencies**.
- You **cannot replace** a Singleton instance easily for testing.
- Many **testing frameworks discourage global state**.

### **Example: Testing Problem**
```cpp
class Database {
public:
    static Database& getInstance() {
        static Database instance;
        return instance;
    }

    void connect() { std::cout << "Database Connected!" << std::endl; }
};

class UserService {
public:
    void createUser() {
        Database::getInstance().connect();  // Hardcoded dependency!
    }
};
```
Now, writing a unit test is **impossible** unless we modify `Database` itself.

#### **Solution: Use Dependency Injection**
Instead of `Database::getInstance()`, inject it:
```cpp
class UserService {
private:
    Database& db;

public:
    UserService(Database& database) : db(database) {}

    void createUser() {
        db.connect();
    }
};
```
Now, we can **mock the Database** during testing:
```cpp
class MockDatabase : public Database {
public:
    void connect() override { std::cout << "Mock Database Connected!" << std::endl; }
};

int main() {
    MockDatabase mockDb;
    UserService service(mockDb);
    service.createUser();  // Uses MockDatabase instead of real Database
}
```
✅ **Easier to test**  
✅ **No global state issues**  

---

## **4. Singleton Violates SOLID Principles**
Singletons violate **two SOLID principles**:

| Principle | How Singleton Violates |
|-----------|------------------------|
| **Single Responsibility Principle (SRP)** | Singleton manages both **instance control** and **business logic** |
| **Dependency Inversion Principle (DIP)** | Code depends on **concrete Singleton class** instead of an **interface** |

---

## **5. When Singleton is Acceptable**
Despite the issues, Singleton is **acceptable in some cases**:
- **Global resources that must have one instance** (e.g., **Logging, Thread Pools, Hardware Controllers**).
- **Caching objects** that should persist across the application.

### **Best Practices if Using Singleton**
✔ **Use Meyers’ Singleton** (C++11+ ensures thread safety):
```cpp
class Singleton {
public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }

private:
    Singleton() {}
};
```
✔ **Avoid using Singletons inside business logic**—pass them explicitly instead.  
✔ **Ensure thread safety** if modification is required.  

---

## **Final Thoughts**
While Singleton **provides controlled instantiation**, it often **introduces hidden dependencies and global state problems**. A **better alternative** is **dependency injection**, which improves **testability, maintainability, and code clarity**.





### **Refactoring a Singleton-Heavy Codebase to Use Dependency Injection**

### **Problem with Singleton-Heavy Codebases**
Singletons are often misused as a **global state**, leading to **hidden dependencies**, **tight coupling**, and **testability issues**. Refactoring to **Dependency Injection (DI)** improves **modularity, testability, and maintainability**.

---

## **1️⃣ Singleton-Heavy Code (Before Refactoring)**
Consider a **Logger** singleton used across multiple classes.

### **Singleton-Based Logger**
```cpp
#include <iostream>
#include <memory>

// Singleton Logger
class Logger {
public:
    static Logger& getInstance() {
        static Logger instance; // Lazy initialization
        return instance;
    }

    void log(const std::string& message) {
        std::cout << "[LOG]: " << message << std::endl;
    }

private:
    Logger() = default;  // Private constructor
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

// Class Using Singleton
class Service {
public:
    void doSomething() {
        Logger::getInstance().log("Service is doing something...");
    }
};

int main() {
    Service service;
    service.doSomething();
    return 0;
}
```

### **Problems with This Approach**
❌ **Hidden dependencies**: `Service` directly depends on `Logger` but **doesn’t declare it explicitly**.  
❌ **Tight coupling**: `Logger` is hardcoded and cannot be easily replaced.  
❌ **Difficult testing**: Cannot mock or inject a fake `Logger` in unit tests.  

---

## **2️⃣ Refactoring to Use Dependency Injection**
### **Steps for Refactoring**
1. **Extract an Interface (`ILogger`)** for `Logger`.
2. **Inject `ILogger` as a dependency** instead of directly using `Logger::getInstance()`.
3. **Use Constructor Injection** to provide dependencies.
4. **Pass dependencies from the main function (composition root)**.

---

### **Step 1: Define an Interface**
```cpp
// Logger Interface
class ILogger {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~ILogger() = default;
};
```
- The **interface** allows flexibility in implementation.

---

### **Step 2: Implement Concrete Logger**
```cpp
// Concrete Logger
class ConsoleLogger : public ILogger {
public:
    void log(const std::string& message) override {
        std::cout << "[LOG]: " << message << std::endl;
    }
};
```
- `ConsoleLogger` **implements** `ILogger`, making it easy to swap or mock.

---

### **Step 3: Inject Dependencies**
```cpp
// Service now depends on ILogger
class Service {
private:
    ILogger& logger;

public:
    explicit Service(ILogger& loggerRef) : logger(loggerRef) {}

    void doSomething() {
        logger.log("Service is doing something...");
    }
};
```
- `Service` **declares its dependency** (`ILogger& logger`).
- No direct call to `Logger::getInstance()`.  

---

### **Step 4: Provide Dependencies in `main()`**
```cpp
int main() {
    ConsoleLogger logger; // Dependency created in main()
    Service service(logger); // Inject dependency
    service.doSomething();
    return 0;
}
```
- The **main function acts as the composition root**, responsible for wiring dependencies.

---

### **3️⃣ Benefits of Dependency Injection**
✅ **Explicit dependencies** → No more hidden dependencies.  
✅ **Loose coupling** → Easily swap `ConsoleLogger` with another implementation.  
✅ **Better testability** → Inject a mock/fake logger in tests.

---

## **4️⃣ Writing Unit Tests**
A major advantage of DI is **testability**. Let's create a **Mock Logger** for unit tests.

```cpp
#include <gtest/gtest.h>

// Mock Logger for Testing
class MockLogger : public ILogger {
public:
    std::string lastMessage;

    void log(const std::string& message) override {
        lastMessage = message;
    }
};

// Test Case
TEST(ServiceTest, LogsCorrectMessage) {
    MockLogger mockLogger; // Inject mock dependency
    Service service(mockLogger);
    
    service.doSomething();

    EXPECT_EQ(mockLogger.lastMessage, "Service is doing something...");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```
- `MockLogger` stores the last message instead of printing it.
- The test **asserts the expected log message**.

---

## **5️⃣ Further Improvements**
| Improvement | Description |
|------------|------------|
| **Factory Pattern** | Instead of manually instantiating dependencies in `main()`, use a factory. |
| **Dependency Injection Frameworks** | Use frameworks like **Google Guice for C++ (Fruit)** for automatic dependency resolution. |
| **Smart Pointers** | Use `std::shared_ptr<ILogger>` instead of raw references if ownership needs to be shared. |

### **Using `std::shared_ptr` for More Flexibility**
```cpp
class Service {
private:
    std::shared_ptr<ILogger> logger;

public:
    explicit Service(std::shared_ptr<ILogger> loggerPtr) : logger(std::move(loggerPtr)) {}

    void doSomething() {
        logger->log("Service is doing something...");
    }
};
```
```cpp
int main() {
    auto logger = std::make_shared<ConsoleLogger>();
    Service service(logger);
    service.doSomething();
    return 0;
}
```
- `std::shared_ptr` helps with **ownership management**.

---

## **Conclusion**
By replacing **Singletons with Dependency Injection**, we achieve:
✔ **Better testability** (mock dependencies easily).  
✔ **Loose coupling** (swap implementations without modifying client code).  
✔ **Improved maintainability** (dependencies are explicit and clear).  

Would you like a **comparison between DI and Service Locator** as an alternative approach? 





Replacing a **Singleton** with `std::shared_ptr` improves **testability, flexibility, and avoids global state**. Below is a step-by-step guide showing **before** (using Singleton) and **after** (using `std::shared_ptr` with Dependency Injection).  

---

## **🔴 Before: Singleton Pattern (Bad Practice)**
A traditional **Singleton** enforces a single instance but introduces **hidden dependencies**, **global state**, and makes testing difficult.

```cpp
#include <iostream>

// Singleton Logger
class Logger {
private:
    static Logger* instance; // Static instance
    Logger() {} // Private constructor to prevent multiple instances

public:
    static Logger* getInstance() {
        if (!instance) {
            instance = new Logger();
        }
        return instance;
    }

    void log(const std::string& message) {
        std::cout << "Log: " << message << std::endl;
    }
};

// Initialize static member
Logger* Logger::instance = nullptr;

// Usage
class Service {
public:
    void doSomething() {
        Logger::getInstance()->log("Service is doing something...");
    }
};

int main() {
    Service service;
    service.doSomething();  // Uses Singleton Logger
    return 0;
}
```
🔴 **Problems with Singleton**:
1. **Global State**: `Logger::getInstance()` is a hidden dependency.
2. **Hard to Test**: Can't easily mock `Logger` in unit tests.
3. **Tightly Coupled**: `Service` is tightly coupled to `Logger`.

---

## **🟢 After: Using `std::shared_ptr` for Dependency Injection**
Instead of a **Singleton**, we use **`std::shared_ptr`** and **Dependency Injection**.

### **✅ Step 1: Modify Logger to Use `std::shared_ptr`**
```cpp
#include <iostream>
#include <memory>

// Logger Interface
class ILogger {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~ILogger() = default;
};

// Concrete Logger
class Logger : public ILogger {
public:
    void log(const std::string& message) override {
        std::cout << "Log: " << message << std::endl;
    }
};
```

---

### **✅ Step 2: Inject Logger Using `std::shared_ptr`**
```cpp
class Service {
private:
    std::shared_ptr<ILogger> logger;

public:
    explicit Service(std::shared_ptr<ILogger> logger) : logger(std::move(logger)) {}

    void doSomething() {
        logger->log("Service is doing something...");
    }
};
```

---

### **✅ Step 3: Create and Pass Shared Instances**
```cpp
int main() {
    std::shared_ptr<ILogger> logger = std::make_shared<Logger>();  // Shared instance

    Service service(logger);  // Inject dependency
    service.doSomething();

    return 0;
}
```

---

## **🎯 Why `std::shared_ptr` Is Better?**
| Feature | Singleton (❌) | `std::shared_ptr` (✅) |
|---------|--------------|----------------|
| **Global State** | ✅ Exists | ❌ Removed |
| **Testability** | ❌ Hard to mock | ✅ Easy to inject mocks |
| **Thread Safety** | ❌ Needs locks | ✅ `std::shared_ptr` is safe |
| **Code Maintainability** | ❌ Tight coupling | ✅ Loose coupling |

---

## **🛠 Bonus: Unit Testing with a Mock Logger**
Since `std::shared_ptr<ILogger>` is injected, we can easily **mock** it for testing.

```cpp
#include <gtest/gtest.h>

// Mock Logger for Testing
class MockLogger : public ILogger {
public:
    std::string lastMessage;

    void log(const std::string& message) override {
        lastMessage = message;
    }
};

// Test Case
TEST(ServiceTest, LogsCorrectMessage) {
    auto mockLogger = std::make_shared<MockLogger>();  
    Service service(mockLogger);  // Inject mock logger

    service.doSomething();

    EXPECT_EQ(mockLogger->lastMessage, "Service is doing something...");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
```
✅ **Unit Test Benefits**:
- **Mocks** can be used instead of real `Logger`.
- **No reliance on global state**.
- **Verifiable behavior**.

---

## **🎯 Key Takeaways**
✅ **Avoid Singleton**: It creates **hidden dependencies** and **global state issues**.  
✅ **Use `std::shared_ptr`**: It allows **dependency injection** and **better resource management**.  
✅ **Improves Testability**: Easily **mock dependencies** in unit tests.  
✅ **Encourages Loose Coupling**: Classes depend on **interfaces**, not concrete implementations.  