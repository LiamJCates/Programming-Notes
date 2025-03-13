# **Fluent Builder Design Pattern in C++**

## **1. Introduction**
The **Fluent Builder** pattern is an enhancement of the **Builder pattern**, designed to allow **method chaining** for constructing objects in a readable and expressive way.

### **Why Use Fluent Builder?**
✅ **Improves Code Readability** – Makes object creation intuitive.  
✅ **Encapsulates Object Construction** – Hides complex initialization logic.  
✅ **Reduces Boilerplate Code** – No need for large constructors.  
✅ **Immutable Objects** – Can be used for thread-safe object creation.  

---
## **2. Understanding Fluent Builder**
A **Fluent Builder**:
- Uses **method chaining** (`return *this` or `return shared_from_this()`).
- Allows **step-by-step object construction**.
- Can enforce **mandatory fields** with **progressive interfaces**.

---
## **3. Basic Fluent Builder Implementation**
### **Example: Constructing a `Car` Object with Fluent Builder**
```cpp
#include <iostream>
#include <string>

class Car {
private:
    std::string make;
    std::string model;
    int year;
    std::string color;

public:
    Car(std::string make, std::string model, int year, std::string color)
        : make(make), model(model), year(year), color(color) {}

    void show() const {
        std::cout << "Car: " << year << " " << make << " " << model << " (" << color << ")\n";
    }

    class Builder {
    private:
        std::string make;
        std::string model;
        int year = 0;
        std::string color = "Unknown";

    public:
        Builder& setMake(const std::string& make) {
            this->make = make;
            return *this;
        }

        Builder& setModel(const std::string& model) {
            this->model = model;
            return *this;
        }

        Builder& setYear(int year) {
            this->year = year;
            return *this;
        }

        Builder& setColor(const std::string& color) {
            this->color = color;
            return *this;
        }

        Car build() {
            return Car(make, model, year, color);
        }
    };
};

int main() {
    Car car = Car::Builder()
                  .setMake("Toyota")
                  .setModel("Corolla")
                  .setYear(2022)
                  .setColor("Blue")
                  .build();

    car.show();
    return 0;
}
```
### **Key Takeaways**
✔ **Method chaining (`return *this`) allows intuitive usage.**  
✔ **Encapsulates object creation (`build()` finalizes it).**  
✔ **Fluent syntax: `Car::Builder().setMake("Toyota").setModel("Corolla").build();`**  

---
## **4. Advanced Fluent Builder with Smart Pointers**
Using `std::shared_ptr` allows **dynamic allocation** and ensures **safe memory management**.

### **Example: Fluent Builder with `std::shared_ptr`**
```cpp
#include <iostream>
#include <string>
#include <memory>

class House {
private:
    std::string type;
    int floors;
    bool hasGarage;

public:
    House(std::string type, int floors, bool hasGarage)
        : type(type), floors(floors), hasGarage(hasGarage) {}

    void show() const {
        std::cout << "House Type: " << type << ", Floors: " << floors
                  << ", Garage: " << (hasGarage ? "Yes" : "No") << "\n";
    }

    class Builder : public std::enable_shared_from_this<Builder> {
    private:
        std::string type = "Default";
        int floors = 1;
        bool hasGarage = false;

    public:
        static std::shared_ptr<Builder> create() {
            return std::make_shared<Builder>();
        }

        std::shared_ptr<Builder> setType(const std::string& type) {
            this->type = type;
            return shared_from_this();
        }

        std::shared_ptr<Builder> setFloors(int floors) {
            this->floors = floors;
            return shared_from_this();
        }

        std::shared_ptr<Builder> setGarage(bool hasGarage) {
            this->hasGarage = hasGarage;
            return shared_from_this();
        }

        std::shared_ptr<House> build() {
            return std::make_shared<House>(type, floors, hasGarage);
        }
    };
};

int main() {
    std::shared_ptr<House> house = House::Builder::create()
                                      ->setType("Villa")
                                      ->setFloors(2)
                                      ->setGarage(true)
                                      ->build();

    house->show();
    return 0;
}
```
### **Key Takeaways**
✔ **Uses `std::shared_ptr` to manage memory automatically.**  
✔ **`std::enable_shared_from_this` enables safe method chaining.**  
✔ **Fluent syntax remains intuitive and expressive.**  

---
## **5. Thread-Safe Fluent Builder**
A **thread-safe Fluent Builder** ensures multiple threads can **safely build objects**.

### **Example: Thread-Safe Fluent Builder**
```cpp
#include <iostream>
#include <string>
#include <memory>
#include <mutex>

class Computer {
private:
    std::string CPU;
    int RAM;
    int storage;

    Computer(std::string CPU, int RAM, int storage)
        : CPU(CPU), RAM(RAM), storage(storage) {}

public:
    void show() const {
        std::cout << "Computer: " << CPU << ", RAM: " << RAM << "GB, Storage: " << storage << "GB\n";
    }

    class Builder {
    private:
        std::string CPU = "Unknown";
        int RAM = 4;
        int storage = 128;
        mutable std::mutex mtx; // Protect shared resource

    public:
        Builder& setCPU(const std::string& CPU) {
            std::lock_guard<std::mutex> lock(mtx);
            this->CPU = CPU;
            return *this;
        }

        Builder& setRAM(int RAM) {
            std::lock_guard<std::mutex> lock(mtx);
            this->RAM = RAM;
            return *this;
        }

        Builder& setStorage(int storage) {
            std::lock_guard<std::mutex> lock(mtx);
            this->storage = storage;
            return *this;
        }

        Computer build() {
            std::lock_guard<std::mutex> lock(mtx);
            return Computer(CPU, RAM, storage);
        }
    };
};

int main() {
    Computer pc = Computer::Builder()
                      .setCPU("Intel i7")
                      .setRAM(16)
                      .setStorage(512)
                      .build();

    pc.show();
    return 0;
}
```
### **Why It’s Thread-Safe**
✔ **`std::mutex` ensures thread-safety for concurrent access.**  
✔ **Each setter locks access to prevent race conditions.**  

---
## **6. Fluent Builder with Director**
A **Director** can **standardize complex builds** by providing **predefined configurations**.

### **Example: Using a Director**
```cpp
class CarDirector {
public:
    static Car buildSportsCar() {
        return Car::Builder()
            .setMake("Ferrari")
            .setModel("F8")
            .setYear(2023)
            .setColor("Red")
            .build();
    }

    static Car buildFamilyCar() {
        return Car::Builder()
            .setMake("Toyota")
            .setModel("Camry")
            .setYear(2022)
            .setColor("White")
            .build();
    }
};

int main() {
    Car sportsCar = CarDirector::buildSportsCar();
    sportsCar.show();

    Car familyCar = CarDirector::buildFamilyCar();
    familyCar.show();

    return 0;
}
```
✔ **Encapsulates predefined configurations.**  
✔ **Simplifies client code when standard options exist.**  

---
## **7. Conclusion**
### **Fluent Builder Advantages**
✅ **Improves readability with method chaining**.  
✅ **Encapsulates complex object construction**.  
✅ **Supports smart pointers (`std::shared_ptr`)**.  
✅ **Can be made thread-safe with `std::mutex`**.  
✅ **Can be combined with a Director for predefined configurations**.  




# **Further Optimizations for Fluent Builder: Immutable Objects and Functional-Style Builders**

## **1. Introduction to Further Optimizations**
In the context of the **Fluent Builder pattern**, we can explore two major optimizations:
1. **Immutable Objects**: Enforcing that the object is immutable after it is created.
2. **Functional-Style Builders**: Using **functional programming** concepts to construct the object in a more declarative, immutable style, often leveraging **`std::function`** or **lambda expressions** for greater flexibility.

---

## **2. Optimizing Fluent Builder with Immutable Objects**
In this approach, we will ensure that the created objects are **immutable**, i.e., they cannot be modified once constructed. This helps guarantee consistency and prevents side effects in multi-threaded environments.

### **Why Immutable Objects?**
- **Thread-Safety**: Immutability prevents concurrent modification.
- **Simplifies Design**: No need for setters post-construction.
- **Predictability**: Reduces unexpected changes during the object's lifecycle.

### **Immutable Object Example with Fluent Builder**
Here we enhance the `Car` class to ensure that after it is built, its properties cannot be changed.

```cpp
#include <iostream>
#include <string>
#include <memory>

class Car {
private:
    std::string make;
    std::string model;
    int year;
    std::string color;

    // Private constructor ensures objects are only built via Builder
    Car(std::string make, std::string model, int year, std::string color)
        : make(make), model(model), year(year), color(color) {}

public:
    // Getter methods (no setters, ensuring immutability)
    const std::string& getMake() const { return make; }
    const std::string& getModel() const { return model; }
    int getYear() const { return year; }
    const std::string& getColor() const { return color; }

    void show() const {
        std::cout << "Car: " << year << " " << make << " " << model << " (" << color << ")\n";
    }

    class Builder {
    private:
        std::string make;
        std::string model;
        int year = 0;
        std::string color = "Unknown";

    public:
        Builder& setMake(const std::string& make) {
            this->make = make;
            return *this;
        }

        Builder& setModel(const std::string& model) {
            this->model = model;
            return *this;
        }

        Builder& setYear(int year) {
            this->year = year;
            return *this;
        }

        Builder& setColor(const std::string& color) {
            this->color = color;
            return *this;
        }

        Car build() {
            return Car(make, model, year, color); // Returns an immutable object
        }
    };
};

int main() {
    Car car = Car::Builder()
                  .setMake("Toyota")
                  .setModel("Corolla")
                  .setYear(2022)
                  .setColor("Blue")
                  .build();

    car.show();  // Shows the immutable car details
    return 0;
}
```

### **Key Features of This Approach**
- The **`Car` object is immutable**: No setter methods are provided after object creation.
- The object is **constructed** only once, using the **Builder**.
- Once created, it cannot be modified, ensuring **predictability and thread-safety**.

---

## **3. Functional-Style Builder**
In a **Functional-Style Builder**, we embrace **functional programming principles** like **immutability**, **declarative programming**, and **lambda functions**. This approach provides more flexibility and can integrate with functional pipelines.

### **Why Use Functional-Style Builders?**
- **Declarative Style**: Objects are constructed by composing functions.
- **Higher Flexibility**: Functions can be reused, combined, and passed as arguments.
- **Immutability**: The object’s state remains unchanged after creation.
- **Composability**: Functions can easily be composed into a fluent interface.

### **Functional-Style Fluent Builder Example**
Here, we implement a functional-style builder that allows composition of construction steps using lambdas.

```cpp
#include <iostream>
#include <string>
#include <functional>

// The object to be built
class Car {
private:
    std::string make;
    std::string model;
    int year;
    std::string color;

    // Private constructor ensures that it's built using the builder
    Car(std::string make, std::string model, int year, std::string color)
        : make(make), model(model), year(year), color(color) {}

public:
    void show() const {
        std::cout << "Car: " << year << " " << make << " " << model << " (" << color << ")\n";
    }

    // Getter methods (no setters, ensuring immutability)
    const std::string& getMake() const { return make; }
    const std::string& getModel() const { return model; }
    int getYear() const { return year; }
    const std::string& getColor() const { return color; }

    // Functional Builder definition
    static std::function<Car()> create(
        const std::string& make = "Unknown",
        const std::string& model = "Unknown",
        int year = 0,
        const std::string& color = "Unknown")
    {
        return [=]() { return Car(make, model, year, color); };
    }

    // Builder methods that return functions to modify attributes
    static std::function<Car()> setMake(const std::string& make, std::function<Car()> builder) {
        return [=]() {
            Car temp = builder();
            return Car(make, temp.getModel(), temp.getYear(), temp.getColor());
        };
    }

    static std::function<Car()> setModel(const std::string& model, std::function<Car()> builder) {
        return [=]() {
            Car temp = builder();
            return Car(temp.getMake(), model, temp.getYear(), temp.getColor());
        };
    }

    static std::function<Car()> setYear(int year, std::function<Car()> builder) {
        return [=]() {
            Car temp = builder();
            return Car(temp.getMake(), temp.getModel(), year, temp.getColor());
        };
    }

    static std::function<Car()> setColor(const std::string& color, std::function<Car()> builder) {
        return [=]() {
            Car temp = builder();
            return Car(temp.getMake(), temp.getModel(), temp.getYear(), color);
        };
    }
};

int main() {
    // Using the functional-style builder
    auto car = Car::create()
                .setMake("Tesla")
                .setModel("Model S")
                .setYear(2022)
                .setColor("Red")();

    car.show();  // Shows the immutably constructed car details

    return 0;
}
```

### **Key Features of Functional-Style Builder**
- **Functions as parameters**: The builder methods (`setMake`, `setModel`, etc.) accept functions, making it highly flexible.
- **Immutability**: Each call to `setMake` or `setModel` returns a **new** object, leaving the original unchanged.
- **Lambdas**: Lambdas are used to construct and modify the object.
- **Declarative**: Object construction is done in a functional pipeline style.

### **Pros of Functional-Style Builders**
- **Composable**: Easily create reusable building blocks for object construction.
- **Declarative and Clean**: Enhances readability and expressiveness, especially for complex objects.
- **Encapsulated Logic**: The logic for setting object properties is encapsulated in functions, promoting clarity and modularity.

---

## **4. Comparing the Approaches**

| Feature                         | Fluent Builder                         | Immutable Object Builder         | Functional-Style Builder          |
|----------------------------------|----------------------------------------|----------------------------------|----------------------------------|
| **Immutability**                 | Not guaranteed                         | **Yes**, no setters after build  | **Yes**, objects remain unchanged |
| **Method Chaining**              | **Yes**                                | **Yes**                          | **Yes**, via function composition |
| **Thread-Safety**                | Can be achieved with synchronization   | **Yes**                          | **Yes**, as functions are stateless |
| **Complexity**                   | Moderate                               | Simple and clean                 | High, but flexible and declarative |
| **Readability**                  | Easy to read                           | Very readable                    | Highly readable (if familiar with functional programming) |
| **Flexibility**                  | Limited by fluent syntax               | Low flexibility                  | **High**, can easily extend with new behavior |

---

## **5. Conclusion**
### **Optimizations**
1. **Immutable Objects**:
   - Ensure that the created objects are immutable after construction, promoting **thread safety** and **predictability**.
   
2. **Functional-Style Builders**:
   - Use **lambdas** and **function composition** to achieve a declarative and **flexible object construction** process.
   - This approach provides high **reusability** and **composability**, perfect for scenarios requiring dynamic or complex object construction pipelines.

Would you like to explore **advanced patterns** such as **Factory methods** or **Composite Builders** for even more flexible object creation? 🚀