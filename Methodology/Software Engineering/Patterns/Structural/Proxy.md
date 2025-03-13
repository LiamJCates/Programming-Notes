# **Proxy Design Pattern in C++**

## **1. Introduction to Proxy Design Pattern**

The **Proxy Design Pattern** is a structural design pattern that provides an object representing another object. The proxy acts as a placeholder, surrogate, or intermediary for the real object, controlling access to it. This pattern is typically used to control access, add additional functionality, or delay the creation/initialization of the real object.

### **Types of Proxies**:
1. **Virtual Proxy**: Controls access to a resource that is expensive to create or access. It delays the instantiation of the real object until it’s actually needed.
2. **Remote Proxy**: Represents an object that is in a different address space (e.g., over a network). The remote proxy handles communication between the client and the actual object.
3. **Protective Proxy**: Controls access to an object based on permissions. It checks if the client has proper access rights before delegating requests to the real object.
4. **Cache Proxy**: Stores the results of expensive method calls or computations and returns the cached result when the same request is made again.

### **Purpose of Proxy Pattern**:
- **Lazy initialization**: Instantiate objects only when they are actually needed.
- **Access control**: Add control over the access to the object.
- **Performance optimization**: Implement caching or other performance-related features.
- **Remote object communication**: Provide an intermediary for remote method calls.
- **Security**: Implement access control, logging, or other security measures.

---

## **2. Structure of the Proxy Design Pattern**

The Proxy Design Pattern typically involves the following components:

1. **Subject (Abstract)**: Defines the common interface for both the RealObject and the Proxy.
2. **RealSubject**: Implements the **Subject** interface and defines the real functionality.
3. **Proxy**: Implements the **Subject** interface and controls access to the **RealSubject**. It can add additional functionality like access control, caching, logging, etc.
4. **Client**: Interacts with the **Subject** interface and does not distinguish between the **RealSubject** and the **Proxy**.

---

## **3. Example of Proxy Design Pattern in C++**

In this example, we’ll implement a **Proxy** pattern for an image display system where loading an image is expensive. A **Virtual Proxy** will delay the loading of the image until it’s actually needed.

### **Classes in the Example**:
- **Image**: Represents the abstract subject (the interface for accessing the real image).
- **RealImage**: Represents the real image that is expensive to load.
- **ImageProxy**: A proxy for the real image that controls access to it, delaying the loading until necessary.
- **Client**: The client uses the image through the proxy.

---

### **Example Code in C++**

```cpp
#include <iostream>
#include <string>

// The Subject (Abstract class)
class Image {
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

// The RealSubject (Concrete class)
class RealImage : public Image {
private:
    std::string filename;

public:
    RealImage(const std::string& filename) : filename(filename) {
        loadImage();
    }

    void loadImage() {
        std::cout << "Loading image: " << filename << std::endl;
    }

    void display() override {
        std::cout << "Displaying image: " << filename << std::endl;
    }
};

// The Proxy (Concrete class)
class ImageProxy : public Image {
private:
    RealImage* realImage;
    std::string filename;

public:
    ImageProxy(const std::string& filename) : realImage(nullptr), filename(filename) {}

    void display() override {
        if (!realImage) {
            realImage = new RealImage(filename); // Load image only when needed
        }
        realImage->display();
    }

    ~ImageProxy() {
        delete realImage; // Clean up the real image
    }
};

// Client Code
int main() {
    // Using Proxy for lazy loading of the real image
    Image* image1 = new ImageProxy("image1.jpg");
    Image* image2 = new ImageProxy("image2.jpg");

    // Display image1 (this will trigger the loading of the image)
    image1->display();

    std::cout << "\n";

    // Display image2 (this will trigger the loading of the image)
    image2->display();

    std::cout << "\n";

    // Image1 already loaded, so only displaying it again
    image1->display();

    // Clean up
    delete image1;
    delete image2;

    return 0;
}
```

---

### **Explanation of the Code**

1. **Image (Abstract Subject)**:
   - This is the **abstract class** that defines the interface for both the **RealImage** and **ImageProxy**. It declares the `display()` method that is common to both the real object and the proxy.

2. **RealImage (Concrete Subject)**:
   - This is the **real object** that represents the image. It implements the `display()` method and has additional functionality like `loadImage()`, which simulates the expensive process of loading the image from disk.
   - The constructor of `RealImage` calls `loadImage()` to load the image when it’s created.

3. **ImageProxy (Proxy)**:
   - The **proxy** class implements the same interface as `RealImage`. It controls access to the real image. Initially, the image is not loaded (it is lazily loaded when the `display()` method is called for the first time).
   - The `display()` method checks if the `realImage` is null (not yet created). If it is null, it creates the `RealImage` object and then calls its `display()` method.
   - The proxy delays the creation and loading of the real image, thus reducing unnecessary computations and potentially saving resources.
   
4. **Client Code**:
   - The client uses the **ImageProxy** to interact with the image. The client does not know whether the object is a real image or a proxy; it only interacts with the `display()` method.
   - The `ImageProxy` ensures that the image is only loaded when it is actually displayed for the first time.

---

## **4. Advantages of Proxy Design Pattern**
- **Lazy Initialization**: The proxy delays the creation of the expensive real object until it is absolutely needed (e.g., lazy loading).
- **Access Control**: The proxy can provide additional functionality, such as authentication or permission checks, before delegating to the real object.
- **Performance Optimization**: Proxies can be used to implement caching, reducing repeated work or computations.
- **Transparent**: Clients interact with the proxy as if they were interacting with the real object, with no need to know the difference.
- **Remote Communication**: A **Remote Proxy** can represent objects that exist in a different address space, enabling communication across network boundaries.
- **Security**: A **Protective Proxy** can enforce security restrictions, ensuring that only authorized clients can access certain resources or services.

---

## **5. When to Use Proxy Pattern**
- When an object is expensive to create, and you want to delay its creation (use **Virtual Proxy**).
- When an object is located in a different address space (e.g., on a remote server) and needs to be accessed over a network (use **Remote Proxy**).
- When you need to add an additional layer for access control, logging, or security checks before allowing access to the real object (use **Protective Proxy**).
- When you want to cache the results of expensive method calls or calculations (use **Cache Proxy**).

---

## **6. Conclusion**

The **Proxy Design Pattern** is an incredibly versatile pattern that allows developers to manage access to an object while adding additional functionality such as lazy loading, security, or caching. By acting as an intermediary, the proxy provides a flexible and transparent way to interact with objects that are expensive to create, located remotely, or need access control.

This pattern is useful when you need to control how and when a resource is accessed, especially for resource-heavy objects. It helps in optimizing performance, enforcing security, and simplifying the management of resources.




# **Remote Proxy Design Pattern in C++**

## **1. Introduction to Remote Proxy Design Pattern**

The **Remote Proxy** pattern is a specific type of **Proxy Design Pattern** used to represent an object that is in a different address space, typically in a different process or on a remote machine. The proxy acts as a local representative for the real object, handling communication with the remote object (such as over a network or inter-process communication).

This type of proxy pattern is essential for situations where objects are located on remote systems or processes, and you want to interact with those objects as if they were locally available.

### **Key Use Cases for Remote Proxy**
- **Networked Applications**: When you want to access remote services over a network (e.g., client-server applications).
- **Distributed Systems**: Representing objects that reside in separate machines or address spaces.
- **Inter-process Communication (IPC)**: Accessing services or resources across different processes on the same or different machines.

### **Structure of Remote Proxy Design Pattern**
1. **Subject**: Defines the common interface for the RealSubject and Proxy.
2. **RealSubject**: Implements the Subject interface and represents the real object that is to be accessed remotely.
3. **Proxy**: Implements the same interface as the RealSubject and controls access to the real object. In the case of the Remote Proxy, it is responsible for handling the communication with the remote system or process.
4. **Client**: Interacts with the Subject (which can be either the real object or the proxy) in the same way, regardless of whether the object is local or remote.

---

## **2. Example: Remote Proxy for Accessing a Remote Server**

In this example, we’ll simulate accessing a **Remote Service** (e.g., an image processing service) over a network using a **Remote Proxy**.

- **RemoteService**: Represents the real service that is located on a remote server.
- **RemoteServiceProxy**: The proxy that communicates with the remote service over a network.
- **Client**: The client interacts with the service through the proxy as if it were a local object.

---

### **Example Code in C++**

```cpp
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// Abstract Subject
class RemoteService {
public:
    virtual void processImage(const std::string& image) = 0;
    virtual ~RemoteService() = default;
};

// RealSubject (Remote service, representing a real object located remotely)
class RealRemoteService : public RemoteService {
public:
    void processImage(const std::string& image) override {
        std::cout << "Processing image: " << image << " on the remote server..." << std::endl;
        // Simulate the time it takes to process the image on a remote server
        std::this_thread::sleep_for(std::chrono::seconds(2));
        std::cout << "Image processing completed on the remote server!" << std::endl;
    }
};

// Proxy (Handles communication between client and remote service)
class RemoteServiceProxy : public RemoteService {
private:
    RealRemoteService* realService;
    std::string serverAddress;

public:
    RemoteServiceProxy(const std::string& address) : realService(nullptr), serverAddress(address) {}

    // Establish connection (simulated) to the remote server
    void connectToServer() {
        std::cout << "Connecting to the remote server at " << serverAddress << "...\n";
        // Simulate the network connection delay
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << "Connected to the remote server." << std::endl;
    }

    void processImage(const std::string& image) override {
        if (!realService) {
            connectToServer();
            realService = new RealRemoteService(); // Initialize the RealSubject (remote service)
        }
        realService->processImage(image);  // Delegate the task to the RealSubject
    }

    ~RemoteServiceProxy() {
        delete realService;
    }
};

// Client Code
int main() {
    // The proxy simulates the interaction with a remote service
    RemoteService* proxy = new RemoteServiceProxy("192.168.1.10");

    // Client invokes method on the proxy, which forwards the request to the real service
    std::cout << "Client: Requesting image processing...\n";
    proxy->processImage("image1.jpg");

    std::cout << "\n";

    // The proxy can be reused to call the real service multiple times
    std::cout << "Client: Requesting another image processing...\n";
    proxy->processImage("image2.jpg");

    // Clean up
    delete proxy;

    return 0;
}
```

---

### **Explanation of the Code**

1. **RemoteService (Abstract Subject)**:
   - This is the **abstract interface** that defines the method `processImage()`, which represents an operation that can be performed on a remote object (e.g., processing an image).

2. **RealRemoteService (Real Subject)**:
   - This represents the **real service** that is located on a remote server. It implements the `RemoteService` interface and provides the actual functionality (image processing). 
   - The `processImage()` method simulates the time-consuming task of processing the image, which would typically be done remotely, by sleeping for 2 seconds.

3. **RemoteServiceProxy (Proxy)**:
   - This is the **proxy** that acts as a representative for the `RealRemoteService`. It implements the same `RemoteService` interface but is responsible for handling the communication between the client and the remote server.
   - The proxy has a `serverAddress` and a `realService` pointer. It manages the connection to the remote server (`connectToServer()`) and initializes the real service only when needed (lazy initialization).
   - The `processImage()` method delegates the request to the real service after ensuring the connection is established. The proxy can be reused for multiple requests.

4. **Client Code**:
   - The client interacts with the **proxy** object as though it were interacting with the real remote service.
   - The client doesn’t need to worry about the remote nature of the service or how the image is processed remotely. It simply calls the `processImage()` method on the proxy, which forwards the request to the real service.

---

## **3. Advantages of Remote Proxy Design Pattern**

- **Transparent Access**: The client interacts with the proxy exactly as it would with the real object, without needing to be aware of the remote communication or network latency.
- **Performance Optimization**: The proxy can manage expensive operations like network communication, lazy initialization, and caching. For example, the remote object can be instantiated only when required.
- **Security**: The proxy can handle security concerns, such as access control or authentication, before delegating to the real service.
- **Simplified Communication**: The proxy abstracts the complexities of remote communication. It handles the networking, data serialization, and deserialization automatically.
- **Reduced Overhead**: If the client needs to make multiple calls to the remote service, the proxy can maintain a persistent connection, reducing the overhead of repeatedly establishing new connections.

---

## **4. When to Use Remote Proxy Pattern**

- **Networked Applications**: When the real object is located on a remote machine or server, and you want to access it as if it were a local object.
- **Distributed Systems**: For systems where different components run in different address spaces, and communication between these components needs to be abstracted.
- **Inter-process Communication (IPC)**: When you need to facilitate communication between processes (possibly running on different machines) while keeping the client code simple and abstracted from these complexities.
- **Service-Oriented Architectures (SOA)**: In distributed environments, the proxy can be used to access services hosted on remote servers, abstracting the complexity of service communication.

---

## **5. Conclusion**

The **Remote Proxy Design Pattern** is essential in distributed systems and networked applications, where objects reside on different machines or processes. The proxy provides a local interface to a remote object, handling communication, connection establishment, and potential security concerns. By using the proxy, clients can interact with remote services as if they were local, abstracting away the complexities of network communication and remote procedure calls (RPCs).

The Remote Proxy pattern is particularly useful when:
- There are network or communication costs (e.g., latency) that should be hidden from the client.
- You want to provide a **transparent layer** for remote access, allowing for easier client-side interactions.







## **Cache Proxy Design Pattern: Detailed Breakdown**

### **1. Intent**
The **Cache Proxy** pattern is a structural design pattern that provides **access control** to a resource while maintaining a **cache** of results to **optimize performance**. Instead of directly accessing a **slow resource** (such as a database or a remote service), the **Cache Proxy** returns the result from the cache if it exists, otherwise, it fetches the result and stores it in the cache for subsequent accesses.

---

### **2. Key Features of Cache Proxy:**
- **Caching:** Stores the results of expensive operations, reducing the need for repetitive access to slow resources.
- **Access Control:** Can provide additional logic for data retrieval, such as lazy loading or access rights checking.
- **Lazy Initialization:** The proxy can fetch and cache the data on-demand, i.e., **lazily**, when the first request occurs.
- **Transparency:** The client doesn't need to know about the cache proxy. It behaves as if it is accessing the real object.

---

## **3. Structure of the Cache Proxy Pattern**

### **Roles:**
1. **Subject (Interface)**: The common interface that both the RealObject and Proxy implement.
2. **RealSubject (RealObject)**: The actual object that performs the expensive operation.
3. **Proxy**: The proxy object that holds the cache and forwards the requests to the real object. It checks whether the result is already cached, and if not, it fetches the data from the real object and stores it in the cache.

---

### **4. Components in the Cache Proxy Pattern**
- **Cache**: A data structure (e.g., a hash map, dictionary) that stores previously fetched results.
- **RealSubject**: The object that performs the real, slow task (e.g., fetching data from the database).
- **Proxy**: The object that caches results and forwards requests to the real object when necessary.

---

## **5. Example Code in C++: Cache Proxy**

We will implement a Cache Proxy for a system that fetches user data. The `RealSubject` simulates fetching data from a remote database (a slow operation), and the `CacheProxy` handles caching to avoid unnecessary data fetching.

### **5.1 Subject Interface**
```cpp
#include <iostream>
#include <string>

// Subject interface
class IUserData {
public:
    virtual ~IUserData() {}
    virtual std::string getUserData(int userId) = 0;
};
```

### **5.2 RealSubject Class**
```cpp
#include <iostream>
#include <string>
#include <thread>
#include <chrono>

// RealSubject class simulating fetching data from a slow resource (e.g., a database)
class RealUserData : public IUserData {
public:
    std::string getUserData(int userId) override {
        // Simulating a slow operation, such as a database fetch
        std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulate delay
        std::cout << "Fetching user data for user ID " << userId << " from the database." << std::endl;
        return "User data for user " + std::to_string(userId);
    }
};
```

### **5.3 CacheProxy Class**
```cpp
#include <iostream>
#include <unordered_map>
#include <memory>
#include <string>

// Cache Proxy class
class CacheProxy : public IUserData {
private:
    std::shared_ptr<RealUserData> realUserData;
    std::unordered_map<int, std::string> cache;  // Simple cache (in-memory store)

public:
    CacheProxy() {
        realUserData = std::make_shared<RealUserData>();
    }

    std::string getUserData(int userId) override {
        // Check if the data is already cached
        if (cache.find(userId) != cache.end()) {
            std::cout << "Returning cached data for user ID " << userId << "." << std::endl;
            return cache[userId];
        } else {
            // Fetch data from the real object and cache it
            std::string data = realUserData->getUserData(userId);
            cache[userId] = data;
            return data;
        }
    }
};
```

### **5.4 Client Code**
```cpp
#include <iostream>
#include <memory>

// Client code interacting with the Cache Proxy
int main() {
    // Creating the CacheProxy object
    std::shared_ptr<IUserData> userDataProxy = std::make_shared<CacheProxy>();

    // First request for user 1, will take time to fetch from the "real" database
    std::cout << userDataProxy->getUserData(1) << std::endl;

    // Second request for user 1, should return cached data
    std::cout << userDataProxy->getUserData(1) << std::endl;

    // Request for user 2, will fetch from "real" database again
    std::cout << userDataProxy->getUserData(2) << std::endl;

    // Request for user 2, should return cached data
    std::cout << userDataProxy->getUserData(2) << std::endl;

    return 0;
}
```

---

### **6. Explanation of the Cache Proxy Implementation**

#### **1. Subject Interface (IUserData)**
- Defines the method `getUserData()`, which will be implemented by both the `RealSubject` and `CacheProxy`.

#### **2. RealSubject (RealUserData)**
- This class simulates the **real operation** that retrieves data from a slow resource, such as a database or a remote server.
- The `getUserData()` method simulates a delay (using `sleep_for()`) to demonstrate how long data retrieval could take.

#### **3. CacheProxy**
- The `CacheProxy` class:
  - Caches the results of the data retrieval in an in-memory cache (using an `unordered_map`).
  - Checks if the requested data is in the cache first. If it is, it returns the cached data. If not, it calls the `RealUserData` object to fetch and cache the result.

#### **4. Client Code**
- The client interacts with the `CacheProxy` class. The first time a request is made for user data, the data is fetched from the "real" source (simulating a database). On subsequent requests, the cached data is returned.

---

### **7. Example Output**
```
Fetching user data for user ID 1 from the database.
User data for user 1
Returning cached data for user ID 1.
User data for user 1
Fetching user data for user ID 2 from the database.
User data for user 2
Returning cached data for user ID 2.
User data for user 2
```

- **First request for user 1:** The data is fetched from the real source and cached.
- **Second request for user 1:** The cached data is returned.
- **Request for user 2:** The data is fetched from the real source and cached.
- **Second request for user 2:** The cached data is returned.

---

### **8. Pros & Cons of Cache Proxy**
#### **Pros:**
- **Performance improvement:** Reduces the overhead of repeatedly fetching data from a slow resource.
- **Transparency:** The client does not need to know about the caching mechanism.
- **Reduces load on the real resource:** Minimizes the number of expensive operations (e.g., database queries).
  
#### **Cons:**
- **Cache invalidation:** The cache can become outdated if the data changes frequently. Cache invalidation logic needs to be handled.
- **Memory usage:** The cache consumes memory, so it might need to be managed effectively to prevent excessive memory use.

---

### **9. Variations of Cache Proxy**
- **Lazy Caching:** The data is only cached when it’s first accessed.
- **Expiration-based Caching:** Cached data can have an expiration time after which it is considered stale and will be refetched.
- **LRU Caching (Least Recently Used):** A cache eviction strategy where the least recently used data is removed when the cache reaches its limit.

---

### **10. When to Use Cache Proxy?**
- When you have **expensive operations** (e.g., database queries, network calls) and want to **avoid repeating** those operations.
- When you want to **optimize performance** by caching the results of **slow or frequent queries**.
- When you need to **reduce load** on external systems (e.g., databases, APIs).

---

### **11. Conclusion**
The **Cache Proxy** pattern is useful for improving the **performance** and **efficiency** of systems that perform expensive operations by **caching** the results. It hides the complexity of caching from the client and ensures faster responses for subsequent requests.

Would you like additional variations, optimizations, or a comparison with other proxy patterns (e.g., Virtual Proxy)?







# **Virtual Proxy Design Pattern in C++**

## **1. Introduction to Virtual Proxy Design Pattern**

The **Virtual Proxy** pattern is a specific type of **Proxy Design Pattern** that provides a placeholder or surrogate for an object that is expensive to create or access. The main idea behind this proxy is to delay the instantiation or loading of the real object until it is actually needed, thus improving performance by deferring the creation of resource-intensive objects.

### **Key Use Cases for Virtual Proxy**
- **Lazy Initialization**: When the creation of an object is resource-intensive or time-consuming (e.g., loading large images, reading files, or accessing a database).
- **Memory Management**: To manage memory usage more efficiently by creating objects only when they are actually needed.
- **Performance Optimization**: To improve performance by deferring resource allocation and initialization until required.

### **Structure of Virtual Proxy Design Pattern**
1. **Subject**: Defines the common interface for both the RealSubject and Proxy.
2. **RealSubject**: Implements the Subject interface and performs the actual work.
3. **Proxy**: Implements the same interface as the RealSubject and is responsible for controlling access to the RealSubject. It handles the lazy initialization of the RealSubject and delegates requests to it.
4. **Client**: Interacts with the Subject and does not need to be aware of the proxy or real object. It accesses the subject through the proxy.

---

## **2. Example of Virtual Proxy Design Pattern in C++**

In this example, we will simulate a **virtual proxy** for **image loading**. The real image is large and expensive to load, so the proxy will delay the loading of the image until the client actually requests to display the image.

- **Image**: The abstract interface that both the real image and the proxy implement.
- **RealImage**: The real image that performs the actual loading and display.
- **ImageProxy**: The proxy that delays the loading of the real image until it is needed.
- **Client**: The client that interacts with the image through the proxy.

---

### **Example Code in C++**

```cpp
#include <iostream>
#include <string>

// Abstract Subject
class Image {
public:
    virtual void display() = 0;
    virtual ~Image() = default;
};

// RealSubject (Concrete Image)
class RealImage : public Image {
private:
    std::string filename;

public:
    RealImage(const std::string& filename) : filename(filename) {
        loadImage();  // Simulate the expensive operation of loading the image
    }

    void loadImage() {
        std::cout << "Loading image: " << filename << " from disk...\n";
    }

    void display() override {
        std::cout << "Displaying image: " << filename << "\n";
    }
};

// Proxy (Virtual Proxy)
class ImageProxy : public Image {
private:
    RealImage* realImage;
    std::string filename;

public:
    ImageProxy(const std::string& filename) : realImage(nullptr), filename(filename) {}

    void display() override {
        if (!realImage) {
            // Lazy initialization: only load the image when display() is called
            realImage = new RealImage(filename);
        }
        realImage->display();  // Delegate the task to the real image
    }

    ~ImageProxy() {
        delete realImage;  // Clean up the real image
    }
};

// Client Code
int main() {
    // The proxy is used to delay the creation of the real image
    Image* image1 = new ImageProxy("image1.jpg");
    Image* image2 = new ImageProxy("image2.jpg");

    // Display image1 (this will load the image for the first time)
    std::cout << "Client: Requesting image1 display...\n";
    image1->display();

    std::cout << "\n";

    // Display image2 (this will load the image for the first time)
    std::cout << "Client: Requesting image2 display...\n";
    image2->display();

    std::cout << "\n";

    // Display image1 again (this will not trigger reloading)
    std::cout << "Client: Requesting image1 display again...\n";
    image1->display();

    // Clean up
    delete image1;
    delete image2;

    return 0;
}
```

---

### **Explanation of the Code**

1. **Image (Abstract Subject)**:
   - This is the **abstract interface** that defines the method `display()`. Both the real object (`RealImage`) and the proxy (`ImageProxy`) will implement this interface.
   
2. **RealImage (Concrete Subject)**:
   - This is the **real object** representing the image. It implements the `Image` interface and performs the actual work of loading and displaying the image. The constructor of `RealImage` calls `loadImage()`, simulating the expensive operation of loading the image from disk.
   - The `display()` method simply displays the image, representing the final functionality the client will use.

3. **ImageProxy (Proxy)**:
   - This is the **virtual proxy** that represents the image. It also implements the `Image` interface and controls access to the real image (`RealImage`). The `ImageProxy` handles the **lazy initialization** of the real image, meaning it only loads the image when it is first needed (when `display()` is called).
   - The `display()` method checks if the `realImage` has been created yet. If not, it initializes the `RealImage` object and calls `display()` on it. This defers the costly image loading operation until absolutely necessary.
   
4. **Client Code**:
   - The client interacts with the `ImageProxy` as if it were interacting with the real image. The client calls `display()` on the proxy, and the proxy ensures that the real image is loaded and displayed.
   - If the client requests the same image multiple times, the proxy ensures the image is only loaded once, avoiding unnecessary reloading.

---

## **3. Advantages of Virtual Proxy Design Pattern**

- **Lazy Initialization**: The proxy defers the creation of the real object until it is needed, optimizing performance and resource usage.
- **Reduced Memory Usage**: The real object is not created unless necessary, saving memory in cases where objects might not be used.
- **Improved Performance**: If the creation or loading of an object is expensive, the proxy ensures that this operation is only performed once, and it is deferred until it is actually required.
- **Transparent to Clients**: The client interacts with the proxy as if it were the real object, without needing to know about the delay or resource management handled by the proxy.
- **Resource Management**: It allows better management of resources by controlling when objects are created, initialized, or loaded.

---

## **4. When to Use Virtual Proxy Pattern**

- **Expensive Object Creation**: When creating an object is computationally expensive or involves significant resources (e.g., loading large images, establishing database connections, or creating network connections).
- **Deferred Initialization**: When the object might not always be used, and you want to delay its creation until it is actually needed (e.g., lazy loading).
- **Memory Management**: If objects are large or numerous, you may want to create them on demand to avoid excessive memory consumption.
- **Optimizing User Interface**: In graphical applications, where images or other resources may need to be displayed only when they are required by the user.

---

## **5. Conclusion**

The **Virtual Proxy Design Pattern** is highly effective for managing expensive or resource-intensive objects by delaying their instantiation until they are actually needed. This pattern is especially useful in cases where resource management, performance optimization, and memory efficiency are important considerations. 

In our example, the **ImageProxy** ensures that the **RealImage** is loaded only when the client requests to display it, improving performance by avoiding unnecessary image loading operations.

This pattern is particularly beneficial in:
- **User interfaces** (e.g., lazy loading of images, views, or components),
- **Distributed systems** (e.g., handling remote objects),
- **Caching mechanisms** (e.g., caching expensive objects for repeated access).








# **Protective Proxy Design Pattern in C++**

## **1. Introduction to Protective Proxy Design Pattern**

The **Protective Proxy** pattern is a type of **Proxy Design Pattern** where the proxy controls access to the real object by enforcing certain access rules or security policies. This proxy acts as a gatekeeper, ensuring that only authorized clients can access the real object, and it may perform checks such as user authentication or permissions before allowing access.

### **Key Use Cases for Protective Proxy**
- **Access Control**: Restricting access to sensitive operations or resources based on user roles or permissions.
- **Security**: Ensuring that only authorized users can invoke specific methods on an object.
- **Encapsulation**: Hiding the implementation details of an object and exposing only the necessary functionality while enforcing strict security policies.
- **Resource Protection**: Protecting expensive or restricted resources from unauthorized access, such as sensitive data or system resources.

### **Structure of Protective Proxy Design Pattern**
1. **Subject**: Defines the common interface that both the RealSubject and Proxy will implement.
2. **RealSubject**: Represents the real object that the proxy is protecting, implementing the Subject interface and performing the actual operations.
3. **Proxy**: Implements the Subject interface and controls access to the real object. It may perform additional checks (such as authentication or permission checks) before delegating the request to the real object.
4. **Client**: Interacts with the Subject (through the Proxy) and may not be aware of the access restrictions being enforced.

---

## **2. Example of Protective Proxy Design Pattern in C++**

In this example, we will simulate a **protective proxy** for a **bank account system**. The proxy will enforce **security checks** before allowing access to the real bank account operations, such as withdrawing money. Only users with the appropriate **authorization level** will be able to perform sensitive actions.

- **Account**: The abstract interface representing the operations that can be performed on the bank account (e.g., deposit, withdraw).
- **RealAccount**: The real bank account that performs the actual operations.
- **AccountProxy**: The proxy that checks if the user has the required authorization to access the bank account operations.
- **Client**: The client that interacts with the account through the proxy.

---

### **Example Code in C++**

```cpp
#include <iostream>
#include <string>

// Abstract Subject
class Account {
public:
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual ~Account() = default;
};

// RealSubject (Concrete Bank Account)
class RealAccount : public Account {
private:
    double balance;

public:
    RealAccount() : balance(0.0) {}

    void deposit(double amount) override {
        balance += amount;
        std::cout << "Deposited " << amount << ". New balance: " << balance << "\n";
    }

    void withdraw(double amount) override {
        if (amount > balance) {
            std::cout << "Insufficient funds for withdrawal.\n";
        } else {
            balance -= amount;
            std::cout << "Withdrew " << amount << ". New balance: " << balance << "\n";
        }
    }
};

// Proxy (Protective Proxy)
class AccountProxy : public Account {
private:
    RealAccount* realAccount;
    std::string userRole;

public:
    AccountProxy(const std::string& userRole) : realAccount(new RealAccount()), userRole(userRole) {}

    void deposit(double amount) override {
        std::cout << "Proxy: Checking permissions for deposit...\n";
        if (userRole == "admin" || userRole == "user") {
            realAccount->deposit(amount);
        } else {
            std::cout << "Proxy: Unauthorized access for deposit!\n";
        }
    }

    void withdraw(double amount) override {
        std::cout << "Proxy: Checking permissions for withdrawal...\n";
        if (userRole == "admin") {
            realAccount->withdraw(amount);
        } else {
            std::cout << "Proxy: Unauthorized access for withdrawal!\n";
        }
    }

    ~AccountProxy() {
        delete realAccount;
    }
};

// Client Code
int main() {
    // Client with 'user' role
    Account* userAccount = new AccountProxy("user");

    std::cout << "Client: User trying to deposit...\n";
    userAccount->deposit(100.0);

    std::cout << "\nClient: User trying to withdraw...\n";
    userAccount->withdraw(50.0);

    std::cout << "\n";

    // Client with 'admin' role
    Account* adminAccount = new AccountProxy("admin");

    std::cout << "Client: Admin trying to deposit...\n";
    adminAccount->deposit(200.0);

    std::cout << "\nClient: Admin trying to withdraw...\n";
    adminAccount->withdraw(150.0);

    std::cout << "\n";

    // Clean up
    delete userAccount;
    delete adminAccount;

    return 0;
}
```

---

### **Explanation of the Code**

1. **Account (Abstract Subject)**:
   - This is the **abstract interface** that defines the operations that can be performed on the bank account, such as `deposit()` and `withdraw()`. Both the real object (`RealAccount`) and the proxy (`AccountProxy`) implement this interface.

2. **RealAccount (Concrete Subject)**:
   - This is the **real object** representing the actual bank account. It implements the `Account` interface and performs the actual operations such as depositing and withdrawing money. It manages the account balance.
   - The `deposit()` and `withdraw()` methods manipulate the balance and print the new account balance.

3. **AccountProxy (Proxy)**:
   - This is the **protective proxy** that acts as a gatekeeper to the `RealAccount`. It checks the `userRole` to enforce security and access control.
   - If the user has the appropriate role (e.g., "admin" or "user"), it allows the operation (e.g., deposit or withdraw) to proceed by delegating the task to the real account.
   - If the user does not have the correct role (e.g., "guest"), the proxy blocks the operation and notifies the user of the unauthorized access.

4. **Client Code**:
   - The client interacts with the `Account` interface through the `AccountProxy`, providing a role ("user" or "admin").
   - The `AccountProxy` checks the permissions based on the user's role before allowing operations like deposit and withdrawal.
   - For example, users with the role "admin" are allowed to withdraw money, but users with the role "user" can only deposit money.

---

## **3. Advantages of Protective Proxy Design Pattern**

- **Access Control**: The proxy ensures that only authorized users can perform sensitive operations, providing an additional layer of security.
- **Centralized Security Management**: The proxy can be used to centralize security checks, preventing unauthorized access to the real object.
- **Flexibility**: The proxy can enforce different access control rules based on user roles, making it flexible and adaptable to various security policies.
- **Encapsulation**: The real object remains protected behind the proxy, and access control is managed externally, separating concerns of security from business logic.
- **Separation of Concerns**: By handling authorization and security checks in the proxy, the real object focuses solely on its core functionality, maintaining clean separation of concerns.

---

## **4. When to Use Protective Proxy Pattern**

- **Sensitive Operations**: When access to certain operations needs to be restricted based on security policies, such as withdrawing money, modifying account details, or deleting data.
- **Authorization and Authentication**: When there is a need to enforce authentication or authorization checks before performing certain operations (e.g., user roles like "admin" or "guest").
- **Security and Compliance**: In systems that require security measures or compliance with regulations, such as preventing unauthorized access to sensitive data.
- **Resource Protection**: When resources (e.g., files, database records, network resources) need to be protected from unauthorized access or modification.

---

## **5. Conclusion**

The **Protective Proxy Design Pattern** is a useful pattern for enforcing **access control** and **security policies** in a system. By using a proxy to control access to sensitive operations, we can ensure that only authorized users can invoke specific actions, such as withdrawing money from a bank account or modifying critical data. 

In the example above, the **AccountProxy** checks the user's role before allowing access to certain account operations. This pattern is particularly valuable in scenarios where security, compliance, and access control are critical requirements.

This pattern is commonly used in:
- **Banking systems** (for ensuring that only authorized users can access sensitive financial operations),
- **Enterprise applications** (for enforcing different levels of access to resources),
- **Networked systems** (for controlling access to remote resources or services),
- **Distributed systems** (for managing secure communication between components).