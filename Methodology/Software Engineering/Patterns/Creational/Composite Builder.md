# **Composite Builder Design Pattern in C++**

## **1. Introduction to Composite Builder Design Pattern**
The **Composite Builder** pattern is a combination of the **Composite** pattern and the **Builder** pattern, aimed at constructing complex objects that may consist of other complex objects. It allows the **composition** of objects with **hierarchical structures** where each part of the hierarchy can be independently constructed using a builder.

### **Why Use Composite Builder?**
- **Hierarchical Object Construction**: For objects that consist of subcomponents, each of which is built separately.
- **Reusability**: Each component can be reused and modified without affecting the whole structure.
- **Separation of Concerns**: Different parts of the object are constructed in isolation, allowing for cleaner, maintainable code.
- **Extensibility**: The builder can be extended to accommodate more complex objects or additional components.

---
## **2. Core Concepts of Composite Builder**

- **Composite Pattern**: Allows objects to be composed into tree-like structures to represent part-whole hierarchies.
- **Builder Pattern**: Provides a way to construct complex objects step by step.

### **How Composite Builder Works**
1. **Composite Structure**: The object is made up of smaller parts, which can themselves be objects constructed using the builder.
2. **Builder Interface**: A unified interface for creating the entire object.
3. **Recursive Composition**: The builder may call other builders to create parts of the whole, leading to a recursive construction process.

---
## **3. Example of Composite Builder Design Pattern**

### **Scenario**: Building a complex `Computer` object, which consists of:
- A `CPU` (which can be independently constructed).
- A `Motherboard`.
- RAM and Storage.

Each of these parts can be built using individual builders, and the `Computer` builder will use these builders to compose the final object.

### **Example Code in C++**

```cpp
#include <iostream>
#include <string>
#include <memory>
#include <vector>

// Base Part: CPU
class CPU {
private:
    std::string model;
    int cores;

public:
    CPU(const std::string& model, int cores) : model(model), cores(cores) {}

    void show() const {
        std::cout << "CPU: " << model << " with " << cores << " cores\n";
    }

    class Builder {
    private:
        std::string model;
        int cores;

    public:
        Builder& setModel(const std::string& model) {
            this->model = model;
            return *this;
        }

        Builder& setCores(int cores) {
            this->cores = cores;
            return *this;
        }

        CPU build() {
            return CPU(model, cores);
        }
    };
};

// Base Part: RAM
class RAM {
private:
    std::string type;
    int size;

public:
    RAM(const std::string& type, int size) : type(type), size(size) {}

    void show() const {
        std::cout << "RAM: " << size << "GB " << type << "\n";
    }

    class Builder {
    private:
        std::string type;
        int size;

    public:
        Builder& setType(const std::string& type) {
            this->type = type;
            return *this;
        }

        Builder& setSize(int size) {
            this->size = size;
            return *this;
        }

        RAM build() {
            return RAM(type, size);
        }
    };
};

// Base Part: Storage
class Storage {
private:
    std::string type;
    int size;

public:
    Storage(const std::string& type, int size) : type(type), size(size) {}

    void show() const {
        std::cout << "Storage: " << size << "GB " << type << "\n";
    }

    class Builder {
    private:
        std::string type;
        int size;

    public:
        Builder& setType(const std::string& type) {
            this->type = type;
            return *this;
        }

        Builder& setSize(int size) {
            this->size = size;
            return *this;
        }

        Storage build() {
            return Storage(type, size);
        }
    };
};

// Composite Object: Computer
class Computer {
private:
    CPU cpu;
    RAM ram;
    Storage storage;

public:
    Computer(CPU cpu, RAM ram, Storage storage) : cpu(cpu), ram(ram), storage(storage) {}

    void show() const {
        std::cout << "Computer Specifications:\n";
        cpu.show();
        ram.show();
        storage.show();
    }

    // Composite Builder for Computer
    class Builder {
    private:
        CPU cpu;
        RAM ram;
        Storage storage;

    public:
        Builder& setCPU(const CPU& cpu) {
            this->cpu = cpu;
            return *this;
        }

        Builder& setRAM(const RAM& ram) {
            this->ram = ram;
            return *this;
        }

        Builder& setStorage(const Storage& storage) {
            this->storage = storage;
            return *this;
        }

        Computer build() {
            return Computer(cpu, ram, storage);
        }

        // Convenience method to build a complete Computer from individual parts
        static Computer buildFullComputer(const CPU::Builder& cpuBuilder, const RAM::Builder& ramBuilder, const Storage::Builder& storageBuilder) {
            return Builder()
                .setCPU(cpuBuilder.build())
                .setRAM(ramBuilder.build())
                .setStorage(storageBuilder.build())
                .build();
        }
    };
};

int main() {
    // Create individual builders
    CPU::Builder cpuBuilder;
    RAM::Builder ramBuilder;
    Storage::Builder storageBuilder;

    // Set values for each part
    cpuBuilder.setModel("Intel i9").setCores(8);
    ramBuilder.setType("DDR4").setSize(32);
    storageBuilder.setType("SSD").setSize(512);

    // Build individual parts
    CPU cpu = cpuBuilder.build();
    RAM ram = ramBuilder.build();
    Storage storage = storageBuilder.build();

    // Use the Composite Builder to construct the full Computer
    Computer computer = Computer::Builder()
                            .setCPU(cpu)
                            .setRAM(ram)
                            .setStorage(storage)
                            .build();

    // Alternatively, use the convenience method for the full build
    Computer fullComputer = Computer::Builder::buildFullComputer(cpuBuilder, ramBuilder, storageBuilder);

    // Show both computers
    std::cout << "\nComputer Built Using Composite Builder:\n";
    computer.show();
    std::cout << "\nComputer Built Using Convenience Method:\n";
    fullComputer.show();

    return 0;
}
```

### **Explanation of the Code**
1. **CPU, RAM, and Storage**: These are individual components, each with its own builder. The `Builder` class for each component provides methods to set its properties.
2. **Computer Class**: This is the composite object that aggregates the individual components (`CPU`, `RAM`, and `Storage`). The `Computer::Builder` is a composite builder that allows the client to add parts to the `Computer` step by step.
3. **Building Process**:
   - Individual builders for `CPU`, `RAM`, and `Storage` are used to construct the parts.
   - The `Computer::Builder` allows the client to set each part and then build the final `Computer`.
   - A convenience static method `buildFullComputer` is provided to allow building a full computer using already constructed part builders.

### **Composite Pattern Applied Here**
- **Part-Whole Hierarchy**: `Computer` is a composite object consisting of `CPU`, `RAM`, and `Storage`. Each of these parts is built separately using its own builder.
- **Recursive Construction**: The `Computer` builder can use the individual part builders, thus creating a recursive object composition.

---
## **4. Benefits of the Composite Builder Pattern**
- **Flexibility**: The Composite Builder allows each part of the object to be built independently. New parts can be easily added by extending the builders.
- **Readability**: The step-by-step construction process allows for clear and understandable code.
- **Extensibility**: New parts and their respective builders can be added without changing the existing system.
- **Reusability**: Each part builder can be reused across different composite objects.

---
## **5. Conclusion**

The **Composite Builder** design pattern effectively combines the **Composite** and **Builder** patterns to handle complex objects with hierarchical structures. It provides a flexible, readable, and extensible way to construct objects composed of other objects. This pattern is particularly useful when you need to build objects with parts that themselves require complex initialization.

Would you like to explore **variations** of this pattern, such as **Abstract Builder** or **Director** usage in Composite Builder? Let me know! 🚀