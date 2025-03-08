# **SOLID Principles: A Detailed Breakdown**


The **SOLID principles** are five fundamental design principles in **object-oriented programming (OOP)** that improve **maintainability, scalability, and flexibility** of software systems. Introduced by **Robert C. Martin (Uncle Bob)**, these principles help avoid **rigid, fragile, or tightly coupled** code.

By following **SOLID**, developers can build systems that:
- Are **easier to understand and modify**.
- Reduce **code duplication**.
- Follow **best practices for object-oriented design**.

---

## **1. S – Single Responsibility Principle (SRP)**
**“A class should have only one reason to change.”**  

### **Explanation**
- Each **class, module, or function** should focus on **one responsibility**.
- If a class has multiple responsibilities, changes in one part can **affect other unrelated parts**.
- This ensures **high cohesion** and **low coupling**.

### **Example: Violating SRP**
A `User` class handling **both** user data and sending emails:
```java
class User {
    private String email;

    public void storeToDatabase() {
        // Save user to database
    }

    public void sendEmail(String message) {
        // Send email to user
    }
}
```
**Problem:**  
- If we change email logic, we might **accidentally break database logic**.

### **Fixing SRP: Separate Responsibilities**
```java
class User {
    private String email;
}

class UserRepository {
    public void storeUser(User user) {
        // Save user to database
    }
}

class EmailService {
    public void sendEmail(String email, String message) {
        // Send email
    }
}
```
**Benefits:**
- Each class **has a single responsibility**.
- Easier to **modify, test, and maintain**.

---

## **2. O – Open/Closed Principle (OCP)**
**“Software entities (classes, modules, functions) should be open for extension but closed for modification.”**  

### **Explanation**
- Code should be **extendable** without modifying existing code.
- Avoid modifying core logic when adding **new features**.
- This prevents **bugs** and follows **Encapsulation**.

### **Example: Violating OCP**
A `DiscountCalculator` class with hardcoded conditions:
```java
class DiscountCalculator {
    public double calculateDiscount(String customerType, double amount) {
        if (customerType.equals("Regular")) {
            return amount * 0.05;
        } else if (customerType.equals("VIP")) {
            return amount * 0.10;
        }
        return 0;
    }
}
```
**Problem:**  
- Every time a **new customer type** is added, we must **modify** the existing class.

### **Fixing OCP: Use Polymorphism**
```java
interface Discount {
    double apply(double amount);
}

class RegularDiscount implements Discount {
    public double apply(double amount) {
        return amount * 0.05;
    }
}

class VIPDiscount implements Discount {
    public double apply(double amount) {
        return amount * 0.10;
    }
}

class DiscountCalculator {
    public double calculateDiscount(Discount discount, double amount) {
        return discount.apply(amount);
    }
}
```
**Benefits:**
- New discount types can be **added without modifying existing code**.
- Follows **Encapsulation and Polymorphism**.

---

## **3. L – Liskov Substitution Principle (LSP)**
**“Subtypes must be substitutable for their base types.”**  

### **Explanation**
- **Derived classes must extend the behavior** of base classes **without altering correctness**.
- **Inheritance should be used properly**—if a subclass **breaks** the expected behavior of its parent, **it violates LSP**.

### **Example: Violating LSP**
A `Bird` superclass assumes all birds can fly:
```java
class Bird {
    public void fly() {
        System.out.println("Flying...");
    }
}

class Penguin extends Bird {
    @Override
    public void fly() {
        throw new UnsupportedOperationException("Penguins can't fly!");
    }
}
```
**Problem:**  
- **Penguin cannot fly**, but it still inherits `fly()`, violating LSP.
- **Code depending on Bird might break**.

### **Fixing LSP: Separate Interfaces**
```java
interface Flyable {
    void fly();
}

class Bird {
    // Common bird properties
}

class Sparrow extends Bird implements Flyable {
    public void fly() {
        System.out.println("Flying...");
    }
}

class Penguin extends Bird {
    // Penguins don’t implement Flyable
}
```
**Benefits:**
- **Avoids invalid behavior in subclasses.**
- **Ensures that derived classes can replace base classes without issues.**

---

## **4. I – Interface Segregation Principle (ISP)**
**“Clients should not be forced to depend on interfaces they do not use.”**  

### **Explanation**
- Large, general-purpose interfaces should be **split** into **smaller, specific ones**.
- This prevents **unnecessary dependencies**.

### **Example: Violating ISP**
```java
interface Worker {
    void work();
    void eat();
}

class Robot implements Worker {
    public void work() {
        System.out.println("Working...");
    }

    public void eat() {
        throw new UnsupportedOperationException("Robots don’t eat!");
    }
}
```
**Problem:**  
- `Robot` is **forced to implement `eat()`, which it doesn’t need**.

### **Fixing ISP: Split Interfaces**
```java
interface Workable {
    void work();
}

interface Eatable {
    void eat();
}

class Human implements Workable, Eatable {
    public void work() { System.out.println("Working..."); }
    public void eat() { System.out.println("Eating..."); }
}

class Robot implements Workable {
    public void work() { System.out.println("Working..."); }
}
```
**Benefits:**
- **No unnecessary dependencies.**
- **More flexible, smaller interfaces.**

---

## **5. D – Dependency Inversion Principle (DIP)**
**“High-level modules should not depend on low-level modules. Both should depend on abstractions.”**  

### **Explanation**
- Instead of directly **instantiating dependencies**, use **abstractions**.
- Enables **dependency injection**, making systems **more modular**.

### **Example: Violating DIP**
```java
class EmailService {
    public void sendEmail(String message) {
        System.out.println("Email sent: " + message);
    }
}

class Notification {
    private EmailService emailService = new EmailService();  // Hardcoded dependency

    public void notifyUser(String message) {
        emailService.sendEmail(message);
    }
}
```
**Problem:**  
- `Notification` is **tightly coupled** to `EmailService`.
- Hard to **replace EmailService with SMS or another service**.

### **Fixing DIP: Use Abstraction**
```java
interface MessageService {
    void sendMessage(String message);
}

class EmailService implements MessageService {
    public void sendMessage(String message) {
        System.out.println("Email sent: " + message);
    }
}

class Notification {
    private MessageService messageService;

    public Notification(MessageService messageService) {
        this.messageService = messageService;
    }

    public void notifyUser(String message) {
        messageService.sendMessage(message);
    }
}
```
**Benefits:**
- Now `Notification` can work with **any messaging service** (e.g., SMS, Push Notifications).
- **Reduces dependencies and increases flexibility**.

---

## **Conclusion**
The **SOLID principles** ensure **better software architecture** by improving **modularity, maintainability, and flexibility**.

| **Principle** | **Key Idea** |
|--------------|-------------|
| **SRP** | A class should have **only one responsibility**. |
| **OCP** | Code should be **open for extension but closed for modification**. |
| **LSP** | Subtypes should be **replaceable without breaking functionality**. |
| **ISP** | Avoid **forcing classes to implement unnecessary methods**. |
| **DIP** | High-level modules should **depend on abstractions, not concrete implementations**. |

Would you like **real-world examples** or **more details on specific principles**?











## Object-oriented Programming Principles

A design principle is a technique that can be applied when designing or writing code to make it more maintainable, flexible, or extensible.

One of the main problems when developing software is dealing with change. Software that is not well designed breaks easily at the first sign of change, but well-designed software can be changed easily.

### SOLID principles
The most popular set of principles are the SOLID principles.

SOLID is an acronym for
* Single responsibility
* Open-closed
* Liskov substitution
* Interface segregation
* Dependency injection

### Single Responsibility
The Single Responsibility principle states a class should only do one thing, this way you're making sure each class has only one reason to change. When you see a class that has more than one reason to change, it's probably trying to do too many things. Take for example this Car class represented in a UML class diagram, drive, fillTank, changeTires. Sounds like this class is trying to do too many things. So maybe it could be better to have some methods to start and stop the car in the Car class and move the drive and fillTanks methods to a Driver class, passing a current instance as a parameter of these methods. In the same way, we can move the changeTires method to a Mechanic class.

### Open-Closed
The Open-Closed principle states classes will be open for extension and closed for modification. This means allowing change, but in a way that doesn't require you to modify existing code. The easiest way to apply this principle is by using inheritance. For example, instead of modifying the Car class to make it behave like an SUV, we can extend it to create an SUVCar subclass. Applying this principle is actually a combination of applying encapsulation and abstraction. The behavior that stays the same is abstracted into a base class and locked for a modification. When you need new or different behavior, subclasses can handle the changes by extending the base class.

### Liskov Substitution
The Liskov substitution principle says that when you inherit from the class, you must be able to substitute the subclass for base class without things going wrong. When you use inheritance, your subclass gets almost all the methods and fields from the superclass. If you use inheritance incorrectly, you're going to end up with methods and fields that probably don't make sense or that you don't need on your subclass. For example, can you actually use an SUVCar class instead of the more generic Car class? Does it make sense in your application? That's what the Liskov substitution principle is about.

When a derived class specializes the behavior and attributes of a base class (which is the common case), any
code that you write involving the base class should work equally well with an object of the derived class.

Barbara Liskov and Jeannette Wing formalized this fundamental principle of object-oriented programming, which is often known today as the Substitution Principle or Liskov’s Substitution Principle.
Briefly, the Substitution Principle states that if you have base class B and derived class D, in any situation
that calls for an object of type B, you can substitute an object of type D, with no ill effects.

The Substitution Principle helps you write programs, but it also imposes a burden. It helps because it
frees you to write code that depends on base class behavior without concerning yourself about any derived
classes.

The burden is on class authors to ensure that their click behavior meets the requirements of the Substitution Principle. The easiest way to meet the
requirements is to let the derived class inherit the behavior of the base class. Sometimes, however, the
derived class has additional work to do. Instead of inheriting, it provides new behavior. In that case, the
programmer must ensure that the behavior is a valid substitution for the base class behavior.


### Interface Segregation
The interface segregation principle says that you should define fine-grained interfaces as specific to the client that is going to use them. This means that it's better to have many as modern interfaces than fewer bigger interfaces. For example, let's say we have an interface with the methods start, stop, activate4WheelDrive, and openSunRoof. And for the purpose of this example, the interface doesn't violate the single responsibility principle. So following the interface segregation principle, we can break this interface into three smaller ones, separating the FourWheel and the SunRoofBehaviors. Not every car has a 4-wheel system or a sun roof, so this will allow us to make different combinations.

### Dependency Injection
The Dependency Injection principle states high-level modules should not depend on low-level modules; however, both should depend upon instructions, which can be interfaces or after classes. In this example, the Car class depends on Engine, the base class for FourCylinderEngine and V6Engine. This way through polymorphism we can inject into Car either one of these subclasses.

### Other Principles
There are many other principles that I'll be mentioning throughout the course, the don't repeat yourself principle, or DRY for short, about avoiding duplicated code, encapsulate what changes to protect your classes for unnecessary changes, favor composition over inheritance because object composition is an alternative to class inheritance that allow us to keep each class encapsulated and focused on one task, and programming to an interface, not an implementation because by using interfaces, your code will work with all the present and future implementations, which give you flexibility. If you know these principles by heart, your software well be well designed. But you don't have to start from scratch with these principles, it's better to reuse solutions that have worked for us in the past. The same patterns represent these reasonable solutions, and they are based on all these principles. We can say that principles are low-level design knowledge and patterns are high level. Patterns are proven solutions that other experts have applied successfully, and everyone can apply them without having to rediscover them.
<br/><br/><br/>
