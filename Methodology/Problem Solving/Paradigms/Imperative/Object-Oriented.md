Object-oriented programming (OOP) is a programming paradigm based on the concept of "objects" that interact with each other.
### **Object-Oriented Programming (OOP) Explained**
**Object-Oriented Programming (OOP)** is a programming paradigm that is based on the concept of **objects**. Objects are instances of **classes** that encapsulate both **data (attributes)** and **behavior (methods)**. OOP promotes code **modularity, reusability, and scalability** by organizing software into objects that interact with each other.

---

## **🔹 Key Principles of OOP (4 Pillars)**
1️⃣ **Encapsulation**  
   - Bundles data (attributes) and methods (functions) inside a class.  
   - Protects data by restricting direct access and exposing only necessary operations.  
   - **Example:** A `Car` object has private data like `engineStatus` and public methods like `startEngine()`.  

2️⃣ **Abstraction**  
   - Hides complex implementation details and exposes only essential features.  
   - **Example:** A `BankAccount` object exposes `deposit()` and `withdraw()` but hides how transactions are processed internally.  

3️⃣ **Inheritance**  
   - Allows a class (child) to inherit attributes and methods from another class (parent).  
   - **Example:** A `Dog` class inherits common properties from an `Animal` class (e.g., `eat()`, `sleep()`).  

4️⃣ **Polymorphism**  
   - Enables a single interface to represent different types of behavior.  
   - **Example:** A `draw()` function behaves differently for `Circle`, `Square`, and `Triangle` objects.  

---

## **🔹 Core OOP Concepts**
### **🔹 Classes & Objects**
- **Class** = Blueprint for creating objects (defines attributes & methods).  
- **Object** = An instance of a class.  

```python
# Example of a Class and Object in Python
class Car:
    def __init__(self, brand, model):
        self.brand = brand
        self.model = model

    def start_engine(self):
        return f"{self.brand} {self.model} engine started!"

# Creating an object
my_car = Car("Toyota", "Corolla")
print(my_car.start_engine())  # Output: Toyota Corolla engine started!
```

---

### **🔹 Method Overriding & Overloading**
- **Method Overriding**: A subclass **redefines** a method inherited from a parent class.  
- **Method Overloading**: Multiple methods with the **same name but different parameters** (not natively supported in Python).  

```python
# Overriding Example
class Animal:
    def make_sound(self):
        return "Some sound"

class Dog(Animal):
    def make_sound(self):  # Overriding method
        return "Bark!"

dog = Dog()
print(dog.make_sound())  # Output: Bark!
```

---

### **🔹 Advantages of OOP**
✅ **Code Reusability** – Inheritance allows reusing code.  
✅ **Scalability & Maintainability** – Encapsulation makes it easier to modify and manage code.  
✅ **Security** – Data hiding through private attributes and controlled access.  
✅ **Flexibility** – Polymorphism allows methods to work with different object types.  

---

### **🔹 OOP vs Procedural Programming**
| Feature | OOP | Procedural Programming |
|---------|-----|---------------------|
| **Approach** | Objects & Classes | Functions & Procedures |
| **Encapsulation** | Yes (Data & behavior together) | No (Data & behavior separate) |
| **Code Reusability** | High (Inheritance, Polymorphism) | Low (Code duplication) |
| **Flexibility** | More (Modular & Scalable) | Less (Harder to maintain large systems) |

---

### **🔹 OOP in Different Languages**
| **Language** | **OOP Support** |
|-------------|----------------|
| Python | ✅ Fully supported |
| Java | ✅ Fully supported |
| C++ | ✅ Fully supported |
| JavaScript | ✅ Uses Prototypes (not class-based OOP) |
| C | ❌ Not inherently OOP (uses procedural programming) |

---

### **🔹 When to Use OOP?**
✅ When building **large, scalable applications**  
✅ When **code reuse and modularity** are needed  
✅ When working with **real-world entities and complex relationships**  

❌ Avoid OOP for **simple scripts** or **small projects where procedural programming is sufficient**  







## Conceptual Application
Conceptually object-oriented programming models the process of classifying and grouping things using abstractions based on those things attributes and behavior. We can talk about vehicles, and we have shared knowledge of what is included in this group. Cars, bicycles, boats, and airplanes are, while pencils, ducks, and swimsuits are not.

Grouping things by abstractions allows us to focus on the specific details that make those things part of a group. Things within the vehicle abstraction can be very different, but if they share some key characteristics, we will understand it.

Using abstraction we can talk about a vehicle instead of a means of transportation for people or cargo that allows displacement with little opposition, a power source to provide the required kinetic energy and a means to control the motion, such as a brake and steering system.



## Object Oriented vs Structured
In the most general sense, a program can be organized in one of two ways:
around its code (what is happening)
around its data (what is being affected).

Structured programming techniques organize around code.
“code acting on data.”

Traditional structured programming consists of designing a set of procedures (or algorithms) to solve a problem. Once the procedures are determined, the traditional next step was to find appropriate ways to store the data.

Object-oriented programs reverse the order: putting the data first, then looking at the algorithms to operate on the data. They are organized around data, with the key principle being “data controlling access to code.”

In an object-oriented language, you define the data and the routines that are permitted to act on that data. Thus, a data type defines precisely what sort of operations can be applied to that data.

Software design using the object oriented paradigm focuses on objects and operations on objects. The object-oriented approach combines the power of the procedural paradigm with an added dimension that integrates data with operations into objects.

To support the principles of object-oriented programming, all OOP languages have three traits in common: encapsulation, polymorphism, and inheritance.

The object-oriented programming approach organizes programs in a way that mirrors the real world, in which all objects are associated with both attributes and activities.

Objects contain and data, code, and  identity: data in the form of fields (often known as attributes or properties), and code, in the form of procedures (often known as methods) and identity in that an object's own procedures can access and often modify the data fields of itself (objects have a notion of this or self).

In OOP, computer programs are designed by making them out of objects that interact with one another. OOP languages are diverse, but the most popular ones are class-based, meaning that objects are instances of classes, which also determine their types.

Many of the most widely used programming languages (such as C++, Java, Python, etc.) are multi-paradigm and they support object-oriented programming to a greater or lesser degree, typically in combination with imperative, procedural programming.


In contradistinction to functions in languages that are not object-oriented, objects make the connection between data and member functions much tighter and more meaningful. In languages that are not object-oriented, declarations of data and definitions of functions can be interspersed through the entire program, and only the program documentation indicates that there is a connection between them. In OOLs, a connection is established right at the outset; in fact, the program is based on this connection. An object is defined by related data and operations, and because there may be many objects used in the same program, the objects communicate by exchanging messages that reveal as little detail about their internal structure as necessary for adequate communication. Structuring programs in terms of objects allows us to accomplish several goals.

First, this strong coupling of data and operations can be used much better in modeling a fragment of the world, which is emphasized especially by software engineering.

Second, objects allow for easier error finding because operations are localized to the confines of their objects. Even if side effects occur, they are easier to trace.

Third, objects allow us to conceal certain details of their operations from other objects so that these operations may not be adversely affected by other objects. This is known as the information-hiding principle.
