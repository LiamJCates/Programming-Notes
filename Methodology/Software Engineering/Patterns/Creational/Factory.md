# **Factory Method Design Pattern (C++)**

## **Overview**
The **Factory Method pattern** is a **creational design pattern** that provides an interface for creating objects but allows subclasses to alter the type of objects that will be created.

### **Key Features**
✅ **Encapsulates object creation** logic  
✅ **Promotes loose coupling** between the creator and the concrete classes  
✅ **Follows the Open/Closed Principle** (new product types can be introduced without modifying existing code)  
✅ **Simplifies unit testing** (dependencies can be replaced with mocks)  

---

## **1️⃣ Structure of Factory Method Pattern**
The Factory Method pattern consists of **four main components**:

1. **Product (Interface/Abstract Class)** → Defines the common interface for objects created.
2. **Concrete Products** → Different implementations of the product interface.
3. **Creator (Abstract Factory)** → Declares a factory method that returns a product.
4. **Concrete Creators** → Implement the factory method to create specific products.

---

## **2️⃣ UML Diagram**
```
        [Product] (Interface/Abstract Class)
               ▲
               │
  ┌───────────┴───────────┐
  │ ConcreteProductA      │ ConcreteProductB
  │ Implements Product    │ Implements Product
  └───────────┬───────────┘
              │
  ┌───────────▼───────────┐
  │       Creator         │
  │ Declares FactoryMethod│
  └───────────┬───────────┘
  ┌───────────▼───────────┐
  │ ConcreteCreatorA      │ ConcreteCreatorB
  │ Implements FactoryMethod │ Implements FactoryMethod
  └────────────────────────┘
```

---

## **3️⃣ C++ Implementation**
### **Step 1: Define the Product Interface**
```cpp
#include <iostream>
#include <memory>

// Product Interface
class Product {
public:
    virtual void operation() const = 0; // Pure virtual function
    virtual ~Product() = default;
};
```
- The **Product** class defines a common interface for all objects that the factory method creates.

---

### **Step 2: Create Concrete Products**
```cpp
// Concrete Product A
class ConcreteProductA : public Product {
public:
    void operation() const override {
        std::cout << "ConcreteProductA operation executed.\n";
    }
};

// Concrete Product B
class ConcreteProductB : public Product {
public:
    void operation() const override {
        std::cout << "ConcreteProductB operation executed.\n";
    }
};
```
- `ConcreteProductA` and `ConcreteProductB` are specific implementations of `Product`.

---

### **Step 3: Define the Factory (Creator)**
```cpp
// Creator (Factory Interface)
class Creator {
public:
    virtual std::unique_ptr<Product> factoryMethod() const = 0; // Factory method
    virtual ~Creator() = default;

    // Common operation using the product
    void someOperation() const {
        std::unique_ptr<Product> product = factoryMethod();
        product->operation();
    }
};
```
- The `Creator` class declares the **factory method** `factoryMethod()` which must be implemented by subclasses.
- It includes a **common operation** `someOperation()`, which uses the product but **delegates creation to subclasses**.

---

### **Step 4: Implement Concrete Creators**
```cpp
// Concrete Creator A
class ConcreteCreatorA : public Creator {
public:
    std::unique_ptr<Product> factoryMethod() const override {
        return std::make_unique<ConcreteProductA>();
    }
};

// Concrete Creator B
class ConcreteCreatorB : public Creator {
public:
    std::unique_ptr<Product> factoryMethod() const override {
        return std::make_unique<ConcreteProductB>();
    }
};
```
- `ConcreteCreatorA` and `ConcreteCreatorB` override `factoryMethod()` to create specific product types.
- **Using smart pointers (`std::unique_ptr`) ensures automatic memory management.**

---

### **Step 5: Client Code**
```cpp
int main() {
    std::unique_ptr<Creator> creatorA = std::make_unique<ConcreteCreatorA>();
    std::unique_ptr<Creator> creatorB = std::make_unique<ConcreteCreatorB>();

    std::cout << "Using ConcreteCreatorA:\n";
    creatorA->someOperation();

    std::cout << "Using ConcreteCreatorB:\n";
    creatorB->someOperation();

    return 0;
}
```
**🔹 Expected Output:**
```
Using ConcreteCreatorA:
ConcreteProductA operation executed.
Using ConcreteCreatorB:
ConcreteProductB operation executed.
```

---

## **4️⃣ When to Use Factory Method?**
Use the **Factory Method** pattern when:
✅ A class **cannot anticipate** the type of objects it needs to create.  
✅ You want to **encapsulate object creation** to make code easier to maintain.  
✅ You follow **Open/Closed Principle**—new product types can be added **without modifying existing code**.  
✅ You need to **reduce coupling** between object creation logic and business logic.  

---

## **5️⃣ Advantages & Disadvantages**
### ✅ **Advantages**
✔ **Encapsulates object creation logic**  
✔ **Promotes loose coupling** between clients and concrete classes  
✔ **Supports the Open/Closed Principle** (easy to extend)  
✔ **Improves testability** (easier to mock objects in unit tests)  

### ❌ **Disadvantages**
❌ **Increased complexity**—requires additional classes  
❌ **May introduce unnecessary abstraction** if only one product type is needed  

---

## **6️⃣ Factory Method vs. Other Creational Patterns**
| Pattern            | Purpose |
|-------------------|---------|
| **Factory Method** | Delegates instantiation to subclasses |
| **Abstract Factory** | Creates families of related objects |
| **Builder** | Constructs objects step-by-step |
| **Prototype** | Clones an existing object |
| **Singleton** | Ensures only one instance exists |

---

## **7️⃣ Alternative: Using `std::function` for a More Flexible Factory**
Instead of subclassing, a **factory function map** provides a **simpler, extensible** alternative:

```cpp
#include <iostream>
#include <memory>
#include <unordered_map>
#include <functional>

// Factory function map
std::unordered_map<std::string, std::function<std::unique_ptr<Product>()>> productFactory = {
    {"A", []() { return std::make_unique<ConcreteProductA>(); }},
    {"B", []() { return std::make_unique<ConcreteProductB>(); }}
};

int main() {
    std::string type = "A"; // Can be dynamically chosen
    auto product = productFactory[type]();
    product->operation();
    
    return 0;
}
```
✅ **More flexible**—new product types can be added at runtime without modifying existing code.  
✅ **Removes the need for subclassing factory classes.**  

---

## **Final Thoughts**
The **Factory Method pattern** is a powerful tool for **decoupling object creation** from the business logic, making the code **more maintainable and scalable**. However, in some cases, a **simple factory function map** may be a more lightweight alternative.

Would you like a breakdown of the **Abstract Factory pattern** next?