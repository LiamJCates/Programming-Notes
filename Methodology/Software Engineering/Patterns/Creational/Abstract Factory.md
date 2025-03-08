# **Abstract Factory Design Pattern (C++)**

## **Overview**
The **Abstract Factory pattern** is a **creational design pattern** that provides an interface for creating families of related or dependent objects **without specifying their concrete classes**.

### **Key Features**
✅ **Encapsulates object creation** for multiple related products  
✅ **Ensures compatibility** between created objects  
✅ **Follows Open/Closed Principle** (easy to introduce new product families)  
✅ **Decouples client code from specific classes**  

---

## **1️⃣ Structure of Abstract Factory Pattern**
The Abstract Factory pattern consists of **five main components**:

1. **Abstract Product A** → Common interface for a family of Product A types.  
2. **Abstract Product B** → Common interface for a family of Product B types.  
3. **Concrete Products** → Implementations of Product A and Product B.  
4. **Abstract Factory** → Interface for creating families of objects.  
5. **Concrete Factories** → Implementations that produce a set of related objects.

---

## **2️⃣ UML Diagram**
```
           [AbstractProductA]       [AbstractProductB]
                  ▲                         ▲
   ┌──────────────┴──────────────┐ ┌──────────────┴──────────────┐
   │      ConcreteProductA1      │ │      ConcreteProductB1      │
   │      ConcreteProductA2      │ │      ConcreteProductB2      │
   └─────────────────────────────┘ └─────────────────────────────┘
                  ▲                         ▲
           [AbstractFactory]
                  ▲
   ┌──────────────┴──────────────┐
   │      ConcreteFactory1       │
   │      ConcreteFactory2       │
   └─────────────────────────────┘
```

---

## **3️⃣ C++ Implementation**
### **Step 1: Define Abstract Products**
```cpp
#include <iostream>
#include <memory>

// Abstract Product A
class AbstractProductA {
public:
    virtual void operationA() const = 0;
    virtual ~AbstractProductA() = default;
};

// Abstract Product B
class AbstractProductB {
public:
    virtual void operationB() const = 0;
    virtual ~AbstractProductB() = default;
};
```
- `AbstractProductA` and `AbstractProductB` define **interfaces** for the product families.

---

### **Step 2: Create Concrete Products**
```cpp
// Concrete Product A1
class ConcreteProductA1 : public AbstractProductA {
public:
    void operationA() const override {
        std::cout << "ConcreteProductA1 operation.\n";
    }
};

// Concrete Product A2
class ConcreteProductA2 : public AbstractProductA {
public:
    void operationA() const override {
        std::cout << "ConcreteProductA2 operation.\n";
    }
};

// Concrete Product B1
class ConcreteProductB1 : public AbstractProductB {
public:
    void operationB() const override {
        std::cout << "ConcreteProductB1 operation.\n";
    }
};

// Concrete Product B2
class ConcreteProductB2 : public AbstractProductB {
public:
    void operationB() const override {
        std::cout << "ConcreteProductB2 operation.\n";
    }
};
```
- Each **ConcreteProduct** implements its respective interface.

---

### **Step 3: Define the Abstract Factory**
```cpp
// Abstract Factory
class AbstractFactory {
public:
    virtual std::unique_ptr<AbstractProductA> createProductA() const = 0;
    virtual std::unique_ptr<AbstractProductB> createProductB() const = 0;
    virtual ~AbstractFactory() = default;
};
```
- `AbstractFactory` provides a **common interface** for creating related objects.

---

### **Step 4: Implement Concrete Factories**
```cpp
// Concrete Factory 1
class ConcreteFactory1 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA1>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB1>();
    }
};

// Concrete Factory 2
class ConcreteFactory2 : public AbstractFactory {
public:
    std::unique_ptr<AbstractProductA> createProductA() const override {
        return std::make_unique<ConcreteProductA2>();
    }

    std::unique_ptr<AbstractProductB> createProductB() const override {
        return std::make_unique<ConcreteProductB2>();
    }
};
```
- Each **Concrete Factory** produces a **matching set of products**.

---

### **Step 5: Client Code**
```cpp
int main() {
    std::unique_ptr<AbstractFactory> factory1 = std::make_unique<ConcreteFactory1>();
    std::unique_ptr<AbstractFactory> factory2 = std::make_unique<ConcreteFactory2>();

    // Create products using Factory 1
    auto productA1 = factory1->createProductA();
    auto productB1 = factory1->createProductB();
    productA1->operationA();
    productB1->operationB();

    // Create products using Factory 2
    auto productA2 = factory2->createProductA();
    auto productB2 = factory2->createProductB();
    productA2->operationA();
    productB2->operationB();

    return 0;
}
```
**🔹 Expected Output:**
```
ConcreteProductA1 operation.
ConcreteProductB1 operation.
ConcreteProductA2 operation.
ConcreteProductB2 operation.
```

---

## **4️⃣ When to Use Abstract Factory?**
Use the **Abstract Factory pattern** when:
✅ You need to create **families of related objects** (e.g., GUI widgets for different OS).  
✅ You want to **ensure compatibility** between created objects.  
✅ You want to **encapsulate object creation** logic.  
✅ You want to follow the **Open/Closed Principle**—adding new product families is easy.

---

## **5️⃣ Advantages & Disadvantages**
### ✅ **Advantages**
✔ **Encapsulates object creation**  
✔ **Ensures object compatibility**  
✔ **Supports Open/Closed Principle**  
✔ **Promotes loose coupling**  

### ❌ **Disadvantages**
❌ **Increased complexity** (many classes)  
❌ **Harder to extend for single products** (better suited for families of products)  

---

## **6️⃣ Abstract Factory vs. Other Creational Patterns**
| Pattern            | Purpose |
|-------------------|---------|
| **Factory Method** | Delegates instantiation to subclasses |
| **Abstract Factory** | Creates families of related objects |
| **Builder** | Constructs objects step-by-step |
| **Prototype** | Clones an existing object |
| **Singleton** | Ensures only one instance exists |

---

## **7️⃣ Alternative: Using a Factory Function Map**
Instead of subclassing, a **factory function map** provides a **more flexible** alternative:

```cpp
#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>

// Factory map
std::unordered_map<std::string, std::function<std::unique_ptr<AbstractProductA>()>> productAFactory = {
    {"A1", []() { return std::make_unique<ConcreteProductA1>(); }},
    {"A2", []() { return std::make_unique<ConcreteProductA2>(); }}
};

int main() {
    std::string type = "A1"; // Can be dynamically chosen
    auto productA = productAFactory[type]();
    productA->operationA();
    
    return 0;
}
```
✅ **More flexible**—new product types can be added dynamically.  
✅ **Removes the need for subclassing factories.**  

---

## **Final Thoughts**
The **Abstract Factory pattern** is ideal for **creating families of related objects** while ensuring **object compatibility and loose coupling**. However, for simpler cases, **Factory Method or a function-based factory** may be more suitable.





# **Abstract Factory vs. Factory Method: A Detailed Comparison**

Both **Abstract Factory** and **Factory Method** are **creational design patterns** that encapsulate object creation. However, they serve different purposes and are best suited for different scenarios.

---

## **1️⃣ Key Differences: Abstract Factory vs. Factory Method**
| Feature                | **Factory Method**                                      | **Abstract Factory**                                      |
|------------------------|------------------------------------------------|------------------------------------------------|
| **Purpose**           | Creates a single product by delegating instantiation to subclasses | Creates a **family of related products** |
| **Hierarchy**        | Uses **inheritance** to override a factory method | Uses **composition** to group multiple factory methods |
| **Scalability**       | Extending with new product families requires modifying multiple factories | Adding new families requires **creating a new factory** without modifying existing ones |
| **Flexibility**       | Less flexible for **multiple related objects** | Better for situations where **multiple related objects** must be created together |
| **Complexity**        | Less complex (one factory per product type) | More complex (factories for each product family) |
| **Encapsulation**    | Encapsulates instantiation of a **single product type** | Encapsulates instantiation of **multiple related products** |

---

## **2️⃣ Real-World Use Cases**
### **📌 Factory Method Example: Logger System**
**Scenario:** A **Logger system** that supports multiple output formats (ConsoleLogger, FileLogger).  
- **Each Logger type** is a separate class.
- **The Factory Method** is overridden by each subclass to create the correct Logger.

#### **Implementation**
```cpp
#include <iostream>
#include <memory>

// Product Interface
class Logger {
public:
    virtual void log(const std::string& message) = 0;
    virtual ~Logger() = default;
};

// Concrete Product: Console Logger
class ConsoleLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << "[Console] " << message << std::endl;
    }
};

// Concrete Product: File Logger (simulated)
class FileLogger : public Logger {
public:
    void log(const std::string& message) override {
        std::cout << "[File] " << message << std::endl;
    }
};

// Factory Method Class
class LoggerFactory {
public:
    virtual std::unique_ptr<Logger> createLogger() const = 0;
    virtual ~LoggerFactory() = default;
};

// Concrete Factory for Console Logger
class ConsoleLoggerFactory : public LoggerFactory {
public:
    std::unique_ptr<Logger> createLogger() const override {
        return std::make_unique<ConsoleLogger>();
    }
};

// Concrete Factory for File Logger
class FileLoggerFactory : public LoggerFactory {
public:
    std::unique_ptr<Logger> createLogger() const override {
        return std::make_unique<FileLogger>();
    }
};

// Client Code
int main() {
    std::unique_ptr<LoggerFactory> factory = std::make_unique<ConsoleLoggerFactory>();
    std::unique_ptr<Logger> logger = factory->createLogger();
    logger->log("Factory Method Pattern Example");

    return 0;
}
```
### **✔️ When to Use Factory Method?**
✅ When you need a **single type of object**, but **want to allow subclasses** to specify which one.  
✅ When you want to **decouple object creation** from business logic.  
✅ When there is a **limited number of variations** (e.g., File Logger, Console Logger).  

---

### **📌 Abstract Factory Example: Cross-Platform UI Components**
**Scenario:** A GUI framework needs to create **buttons** and **checkboxes** for **multiple platforms** (Windows, macOS).  
- **Each OS** has its own **set of UI components**.
- **The Abstract Factory** ensures the UI components for each platform match.

#### **Implementation**
```cpp
#include <iostream>
#include <memory>

// Abstract Product A: Button
class Button {
public:
    virtual void render() const = 0;
    virtual ~Button() = default;
};

// Abstract Product B: Checkbox
class Checkbox {
public:
    virtual void render() const = 0;
    virtual ~Checkbox() = default;
};

// Concrete Product A1: Windows Button
class WindowsButton : public Button {
public:
    void render() const override {
        std::cout << "Rendering Windows Button.\n";
    }
};

// Concrete Product A2: Mac Button
class MacButton : public Button {
public:
    void render() const override {
        std::cout << "Rendering Mac Button.\n";
    }
};

// Concrete Product B1: Windows Checkbox
class WindowsCheckbox : public Checkbox {
public:
    void render() const override {
        std::cout << "Rendering Windows Checkbox.\n";
    }
};

// Concrete Product B2: Mac Checkbox
class MacCheckbox : public Checkbox {
public:
    void render() const override {
        std::cout << "Rendering Mac Checkbox.\n";
    }
};

// Abstract Factory
class GUIFactory {
public:
    virtual std::unique_ptr<Button> createButton() const = 0;
    virtual std::unique_ptr<Checkbox> createCheckbox() const = 0;
    virtual ~GUIFactory() = default;
};

// Concrete Factory: Windows GUI
class WindowsGUIFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<WindowsButton>();
    }
    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<WindowsCheckbox>();
    }
};

// Concrete Factory: Mac GUI
class MacGUIFactory : public GUIFactory {
public:
    std::unique_ptr<Button> createButton() const override {
        return std::make_unique<MacButton>();
    }
    std::unique_ptr<Checkbox> createCheckbox() const override {
        return std::make_unique<MacCheckbox>();
    }
};

// Client Code
void renderUI(const GUIFactory& factory) {
    auto button = factory.createButton();
    auto checkbox = factory.createCheckbox();
    button->render();
    checkbox->render();
}

int main() {
    WindowsGUIFactory windowsFactory;
    MacGUIFactory macFactory;

    std::cout << "Windows UI:\n";
    renderUI(windowsFactory);

    std::cout << "\nMac UI:\n";
    renderUI(macFactory);

    return 0;
}
```
### **✔️ When to Use Abstract Factory?**
✅ When multiple objects **must be created together** and remain compatible (e.g., GUI widgets for an OS).  
✅ When you want to **encapsulate the creation of product families**.  
✅ When **extensibility** is important—new product families can be added without modifying existing code.  

---

## **3️⃣ Summary Table**
| Feature              | **Factory Method**                           | **Abstract Factory**                         |
|----------------------|-----------------------------------|--------------------------------|
| **Creates**         | A **single** product type at a time | **Multiple related products** together |
| **How?**           | Subclasses override a method | Concrete factories implement a common factory interface |
| **Encapsulation**  | Encapsulates instantiation of a single product | Encapsulates multiple product families |
| **Client Knows?**  | The client knows about the factory class | The client knows only about the abstract factory |
| **Best for?**      | When only **one type** of object is created | When **multiple related** objects are needed |

---

## **4️⃣ Which One Should You Use?**
| **Use Factory Method When…** | **Use Abstract Factory When…** |
|----------------------------|----------------------------|
| You need **one type of object** | You need **multiple related objects** |
| Variations are **limited** | You expect to add new families of products |
| You want **loose coupling** for a single product | You need **matching objects** (e.g., GUI elements) |

---

## **Final Thoughts**
Both **Factory Method** and **Abstract Factory** help decouple object creation from business logic. The choice depends on whether you're dealing with **a single object type (Factory Method)** or **a family of related objects (Abstract Factory)**.