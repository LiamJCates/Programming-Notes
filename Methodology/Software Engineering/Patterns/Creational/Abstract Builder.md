# **Abstract Builder Design Pattern in C++**

## **1. Introduction to Abstract Builder Design Pattern**

The **Abstract Builder** design pattern is an extension of the **Builder** pattern, aimed at separating the construction of a complex object from its representation. It introduces an **abstract builder interface** that defines methods for constructing different parts of the object. The concrete builder implements this interface, constructing a specific representation of the object.

### **Purpose of Abstract Builder**:
- **Separation of concerns**: Allows the construction logic of an object to be separated from the actual object itself.
- **Flexibility**: You can create different representations of an object (e.g., different types of houses, cars, etc.) using the same construction logic.
- **Maintainability**: Makes it easier to add new representations without modifying the construction process.

### **Structure of Abstract Builder**:
- **Builder Interface**: Defines the common interface for constructing the parts of the complex object.
- **Concrete Builder**: Implements the builder interface and assembles the final product.
- **Director**: Controls the construction process, using a builder to produce a complex object.
- **Product**: The final object created by the builder.

---

## **2. Core Components**

1. **Builder Interface**: Provides methods to create the individual parts of a product.
2. **Concrete Builder**: A specific implementation of the builder interface that assembles the parts and returns the final product.
3. **Director**: Coordinates the construction process using a builder.
4. **Product**: The complex object created by the builder.

### **Example of Components**:
- **Builder Interface**: Declares methods like `buildPart1()`, `buildPart2()`, etc.
- **Concrete Builder**: Implements the builder interface and assembles a product.
- **Director**: Defines the sequence in which parts are created, directing the builder to assemble the parts in a specific order.
- **Product**: Represents the complex object being built.

---

## **3. Example of Abstract Builder Design Pattern**

Let’s create an example in which we are building a **House** object using the **Abstract Builder** pattern. The house has multiple components such as the **roof**, **walls**, and **doors**. Different types of houses can be built by changing the concrete builder.

### **Classes in the Example**:
- **House**: The final product.
- **HouseBuilder**: The abstract builder interface.
- **ConcreteHouseBuilder**: The concrete builder that assembles the parts of the house.
- **Director**: Directs the building process.

---

### **Example Code in C++**

```cpp
#include <iostream>
#include <string>

// The Product
class House {
private:
    std::string roof;
    std::string walls;
    std::string doors;

public:
    void setRoof(const std::string& roof) { this->roof = roof; }
    void setWalls(const std::string& walls) { this->walls = walls; }
    void setDoors(const std::string& doors) { this->doors = doors; }

    void show() const {
        std::cout << "House Details:\n";
        std::cout << "Roof: " << roof << "\n";
        std::cout << "Walls: " << walls << "\n";
        std::cout << "Doors: " << doors << "\n";
    }
};

// The Builder Interface
class HouseBuilder {
public:
    virtual ~HouseBuilder() {}

    virtual void buildRoof() = 0;
    virtual void buildWalls() = 0;
    virtual void buildDoors() = 0;
    virtual House getResult() = 0;
};

// The Concrete Builder
class ConcreteHouseBuilder : public HouseBuilder {
private:
    House house;

public:
    void buildRoof() override {
        house.setRoof("Concrete Roof");
    }

    void buildWalls() override {
        house.setWalls("Brick Walls");
    }

    void buildDoors() override {
        house.setDoors("Wooden Doors");
    }

    House getResult() override {
        return house;
    }
};

// Another Concrete Builder (for a different type of house)
class WoodenHouseBuilder : public HouseBuilder {
private:
    House house;

public:
    void buildRoof() override {
        house.setRoof("Wooden Roof");
    }

    void buildWalls() override {
        house.setWalls("Wooden Walls");
    }

    void buildDoors() override {
        house.setDoors("Glass Doors");
    }

    House getResult() override {
        return house;
    }
};

// The Director
class Director {
private:
    HouseBuilder* builder;

public:
    Director(HouseBuilder* builder) : builder(builder) {}

    void construct() {
        builder->buildRoof();
        builder->buildWalls();
        builder->buildDoors();
    }
};

// Client Code
int main() {
    // Creating ConcreteHouseBuilder
    ConcreteHouseBuilder concreteBuilder;
    Director director(&concreteBuilder);
    director.construct();
    House concreteHouse = concreteBuilder.getResult();
    concreteHouse.show();

    std::cout << "\n";

    // Creating WoodenHouseBuilder
    WoodenHouseBuilder woodenBuilder;
    director = Director(&woodenBuilder);
    director.construct();
    House woodenHouse = woodenBuilder.getResult();
    woodenHouse.show();

    return 0;
}
```

### **Explanation of the Code**
1. **House**:
   - This is the **product** being built. It has three parts: `roof`, `walls`, and `doors`. These parts are set using setter methods.
   - The `show()` method displays the complete house.

2. **HouseBuilder**:
   - This is the **abstract builder interface** that defines methods like `buildRoof()`, `buildWalls()`, and `buildDoors()`. These methods will be implemented by concrete builders.

3. **ConcreteHouseBuilder** and **WoodenHouseBuilder**:
   - These are **concrete builders** that implement the `HouseBuilder` interface and build a specific type of house.
   - The `ConcreteHouseBuilder` builds a house with a concrete roof, brick walls, and wooden doors.
   - The `WoodenHouseBuilder` builds a house with a wooden roof, wooden walls, and glass doors.

4. **Director**:
   - The `Director` class is responsible for managing the construction process. It calls the builder’s methods in a particular sequence (`buildRoof()`, `buildWalls()`, `buildDoors()`) to create a complete house.
   - The client does not need to know about the specific builder or construction process; it only interacts with the director and builder.

5. **Client Code**:
   - In the main function, we create instances of the concrete builders and use the director to construct the house step by step. The final product (a `House` object) is obtained by calling `getResult()`.

---

## **4. Advantages of the Abstract Builder Pattern**
- **Separation of Construction Logic**: The construction of the product is decoupled from its representation. This makes it easier to manage and extend the creation of complex objects.
- **Reusability**: You can easily switch between different builders to create various representations of the product.
- **Extensibility**: You can add new builders to create new types of products without modifying existing code.
- **Maintainability**: The builder pattern organizes the construction process in a way that is easy to maintain and update.

---

## **5. When to Use the Abstract Builder Pattern**
The **Abstract Builder** pattern is useful when:
1. You need to construct complex objects with multiple parts and configurations.
2. The construction process should be independent of the parts that make up the object.
3. You want to create different representations or variations of the product using the same construction process.
4. You want to control the order in which parts of the product are constructed.

---

## **6. Conclusion**
The **Abstract Builder** pattern is a powerful way to create complex objects while maintaining flexibility and separation of concerns. It is particularly useful in scenarios where you need to create different types of products with shared construction logic. By using this pattern, you can easily extend your code to handle new variations of products without affecting the overall construction process.




# **Parameterized Builders in the Abstract Builder Design Pattern in C++**

## **1. Introduction to Parameterized Builders**

The **Parameterized Builder** design pattern is an extension of the **Abstract Builder** pattern that provides more flexibility by allowing parameters to be passed directly to the builder methods. This helps in creating more dynamic objects, especially when some parts of the object need to be customized at the time of construction.

In this variation, the **builder** doesn't rely on pre-configured values alone. Instead, it can accept parameters that influence the construction of the **product**. This adds more flexibility for clients who wish to create customized versions of an object.

### **Why Use Parameterized Builders?**
- **Customization**: It allows the client to pass dynamic parameters to the builder for more fine-grained control over the product.
- **Flexibility**: It enables the creation of different product configurations without modifying the builder.
- **Decoupling Construction and Representation**: Like the regular Abstract Builder, it separates the construction process from the actual representation of the product, but with added parameterization.

### **Structure of Parameterized Builders**
1. **Builder Interface**: Defines methods for constructing parts of the product with parameters.
2. **Concrete Builder**: Implements the builder interface and constructs the product based on the parameters passed.
3. **Director**: (Optional) If used, coordinates the construction but may pass parameters to the builder.
4. **Product**: The final object that is constructed.

---

## **2. Example: Building a House with Parameterized Builders**

In this example, we will enhance our previous **House** example by adding parameters to the builder methods so that different aspects of the house can be customized when constructing it.

### **The House**: 
- **Roof**: Material and type.
- **Walls**: Material and color.
- **Doors**: Type and material.

Instead of having fixed properties, the builder will accept parameters that will be passed during construction to build various configurations of a house.

---

### **Example Code in C++**

```cpp
#include <iostream>
#include <string>

// The Product: House
class House {
private:
    std::string roof;
    std::string walls;
    std::string doors;

public:
    void setRoof(const std::string& roof) { this->roof = roof; }
    void setWalls(const std::string& walls) { this->walls = walls; }
    void setDoors(const std::string& doors) { this->doors = doors; }

    void show() const {
        std::cout << "House Details:\n";
        std::cout << "Roof: " << roof << "\n";
        std::cout << "Walls: " << walls << "\n";
        std::cout << "Doors: " << doors << "\n";
    }
};

// The Abstract Builder Interface (with parameterized methods)
class HouseBuilder {
public:
    virtual ~HouseBuilder() {}

    virtual void buildRoof(const std::string& roofType, const std::string& roofMaterial) = 0;
    virtual void buildWalls(const std::string& wallMaterial, const std::string& wallColor) = 0;
    virtual void buildDoors(const std::string& doorType, const std::string& doorMaterial) = 0;
    virtual House getResult() = 0;
};

// Concrete Builder: Concrete House Builder with parameterized construction
class ConcreteHouseBuilder : public HouseBuilder {
private:
    House house;

public:
    void buildRoof(const std::string& roofType, const std::string& roofMaterial) override {
        house.setRoof("Roof Type: " + roofType + ", Material: " + roofMaterial);
    }

    void buildWalls(const std::string& wallMaterial, const std::string& wallColor) override {
        house.setWalls("Material: " + wallMaterial + ", Color: " + wallColor);
    }

    void buildDoors(const std::string& doorType, const std::string& doorMaterial) override {
        house.setDoors("Type: " + doorType + ", Material: " + doorMaterial);
    }

    House getResult() override {
        return house;
    }
};

// Concrete Builder: Wooden House Builder with parameterized construction
class WoodenHouseBuilder : public HouseBuilder {
private:
    House house;

public:
    void buildRoof(const std::string& roofType, const std::string& roofMaterial) override {
        house.setRoof("Roof Type: " + roofType + ", Material: " + roofMaterial);
    }

    void buildWalls(const std::string& wallMaterial, const std::string& wallColor) override {
        house.setWalls("Material: " + wallMaterial + ", Color: " + wallColor);
    }

    void buildDoors(const std::string& doorType, const std::string& doorMaterial) override {
        house.setDoors("Type: " + doorType + ", Material: " + doorMaterial);
    }

    House getResult() override {
        return house;
    }
};

// Director: Manages the building process
class Director {
private:
    HouseBuilder* builder;

public:
    Director(HouseBuilder* builder) : builder(builder) {}

    void constructConcreteHouse() {
        builder->buildRoof("Gabled", "Concrete");
        builder->buildWalls("Brick", "Gray");
        builder->buildDoors("Wooden", "Oak");
    }

    void constructWoodenHouse() {
        builder->buildRoof("Hip", "Wood");
        builder->buildWalls("Wood", "Brown");
        builder->buildDoors("Sliding", "Glass");
    }
};

// Client Code
int main() {
    // Create ConcreteHouseBuilder and Director
    ConcreteHouseBuilder concreteBuilder;
    Director director(&concreteBuilder);
    director.constructConcreteHouse();
    House concreteHouse = concreteBuilder.getResult();
    concreteHouse.show();

    std::cout << "\n";

    // Create WoodenHouseBuilder and Director
    WoodenHouseBuilder woodenBuilder;
    director = Director(&woodenBuilder);
    director.constructWoodenHouse();
    House woodenHouse = woodenBuilder.getResult();
    woodenHouse.show();

    return 0;
}
```

---

### **Explanation of the Code**

1. **House**:
   - Represents the product being built (the complex object). It has properties like `roof`, `walls`, and `doors`, which are set via setter methods. The `show()` method displays the full house configuration.

2. **HouseBuilder (Abstract Builder)**:
   - This is the **abstract builder interface** with parameterized methods `buildRoof()`, `buildWalls()`, and `buildDoors()`. Each method takes parameters to specify the type of material or configuration for the corresponding part of the house.
   
3. **ConcreteHouseBuilder and WoodenHouseBuilder (Concrete Builders)**:
   - These are the **concrete builders** that implement the `HouseBuilder` interface and construct the house with specific materials, types, and configurations provided by the parameters.
   - `ConcreteHouseBuilder` builds a house with concrete roofs, brick walls, and wooden doors.
   - `WoodenHouseBuilder` builds a house with a wooden roof, wood walls, and glass sliding doors.

4. **Director**:
   - The **Director** class manages the construction process by invoking builder methods in a specific order. It uses the concrete builders to create two types of houses: one made of concrete and the other made of wood.
   - The `constructConcreteHouse()` and `constructWoodenHouse()` methods of the `Director` guide the construction process by passing specific parameters to the builder methods.

5. **Client Code**:
   - The client interacts with the director and the concrete builder to construct the house. The director is responsible for managing the construction order and parameters, and it constructs the house based on the provided builder.

---

## **3. Advantages of Parameterized Builders**

- **Increased Flexibility**: By passing parameters directly to the builder, you can create more flexible and dynamic objects that fit specific configurations based on the client’s needs.
- **Customization**: Builders can now accept varying configurations for each part of the product (e.g., a house's roof, walls, and doors), giving the client control over the construction.
- **Decoupling**: Like the Abstract Builder pattern, the parameterized builder decouples the construction process from the product itself, but it adds the capability to customize each part.
- **Reusability**: You can reuse the builder for constructing multiple instances of the product with different configurations, avoiding code duplication.

---

## **4. When to Use Parameterized Builders**
You should consider using **Parameterized Builders** when:
1. You need to construct objects with many configurable parts, each requiring its own set of parameters.
2. You want to ensure flexibility in the construction process without hardcoding values.
3. You need to support multiple representations of a product with a common construction process.
4. You want to provide clients with control over the construction of a complex product, allowing them to customize parts at the time of construction.

---

## **5. Conclusion**
The **Parameterized Builder** is a powerful extension of the **Abstract Builder** pattern that allows you to create complex objects with dynamic, client-specific configurations. It offers high flexibility and reusability, making it a great solution for scenarios where you need fine-grained control over how different parts of a product are constructed. By passing parameters to the builder, you can customize the object creation process without compromising the integrity and maintainability of the code.