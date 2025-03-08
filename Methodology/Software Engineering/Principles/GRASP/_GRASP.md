# **GRASP (General Responsibility Assignment Software Patterns) – A Detailed Breakdown**

## **Introduction**
GRASP (General Responsibility Assignment Software Patterns) is a set of **nine fundamental principles** that guide **object-oriented design** by helping developers assign **responsibilities** effectively in a system. These principles, introduced by **Craig Larman** in his book *"Applying UML and Patterns"*, focus on **decoupling, maintainability, and reusability**.

GRASP helps answer key design questions:
- **Which class should handle which responsibility?**
- **How do we ensure low coupling and high cohesion?**
- **How do we make a system scalable and maintainable?**

---

## **The Nine GRASP Patterns**

### **1. Creator**
**Guides: Object Creation Responsibility**  
**Principle:** Assign responsibility for creating an object to a class that has the **closest relationship** with the object being created.

**Criteria for assigning the Creator responsibility:**
- The class **contains** or **aggregates** the object.
- The class **uses** the object extensively.
- The class has the **necessary information** to initialize the object.

**Example:**
- A `Order` class creating an instance of `OrderItem` because an order **contains** order items.

```java
class Order {
    private List<OrderItem> items = new ArrayList<>();
    
    public void addItem(Product product, int quantity) {
        items.add(new OrderItem(product, quantity));
    }
}
```

---

### **2. Controller**
**Guides: Assigning Responsibilities for Handling System Events**  
**Principle:** Assign the responsibility for **handling system input events** to a class that represents:
- A **use case or scenario** (e.g., `OrderController`).
- A **role in the system** (e.g., `UserManager`).

**Example:**
- In an MVC (Model-View-Controller) pattern, `OrderController` manages requests related to orders.

```java
class OrderController {
    private OrderService orderService;

    public OrderController(OrderService service) {
        this.orderService = service;
    }

    public void processOrder(OrderRequest request) {
        orderService.createOrder(request);
    }
}
```

---

### **3. Information Expert**
**Guides: Assigning Information Responsibilities**  
**Principle:** Assign responsibility to the class that has the **most relevant information** to fulfill a task.

**Example:**
- The `Order` class should calculate the total price because it **has access to its items**.

```java
class Order {
    private List<OrderItem> items;

    public double calculateTotal() {
        double total = 0;
        for (OrderItem item : items) {
            total += item.getSubtotal();
        }
        return total;
    }
}
```

---

### **4. Low Coupling**
**Guides: Minimizing Dependency Between Classes**  
**Principle:** Reduce dependencies between classes to **increase flexibility and maintainability**.

**Example:**
- Using **dependency injection** instead of hardcoded dependencies:

```java
class OrderService {
    private PaymentGateway paymentGateway;

    public OrderService(PaymentGateway gateway) {
        this.paymentGateway = gateway;
    }

    public void processPayment(Order order) {
        paymentGateway.charge(order.getTotal());
    }
}
```

---

### **5. High Cohesion**
**Guides: Grouping Related Behaviors Together**  
**Principle:** Keep related responsibilities within a class to **improve clarity and maintainability**.

**Example:**
- Instead of a **God class** handling all order-related operations, split into `Order`, `OrderService`, and `OrderRepository`.

```java
class OrderService {
    public void placeOrder(Order order) {
        order.validate();
        orderRepository.save(order);
    }
}
```

---

### **6. Polymorphism**
**Guides: Handling Variations in Behavior**  
**Principle:** Use **polymorphism** to delegate behavior to the correct class instead of using **conditionals**.

**Example:**
- Instead of using `if-else` to check the type of payment, use polymorphism.

```java
interface PaymentMethod {
    void pay(double amount);
}

class CreditCardPayment implements PaymentMethod {
    public void pay(double amount) {
        System.out.println("Paid with credit card: $" + amount);
    }
}

class PayPalPayment implements PaymentMethod {
    public void pay(double amount) {
        System.out.println("Paid with PayPal: $" + amount);
    }
}
```

---

### **7. Pure Fabrication**
**Guides: Creating Helper Classes to Avoid Breaking Other Principles**  
**Principle:** If assigning a responsibility to an existing class violates **low coupling or high cohesion**, create a **new class**.

**Example:**
- Instead of adding logging functionality to `OrderService`, create a separate `Logger` class.

```java
class Logger {
    public static void log(String message) {
        System.out.println("LOG: " + message);
    }
}
```

---

### **8. Indirection**
**Guides: Decoupling Two Classes Using an Intermediate Class**  
**Principle:** Use an intermediary to **reduce direct dependencies** between two classes.

**Example:**
- Instead of `Order` directly calling `PaymentGateway`, use an intermediary `PaymentProcessor`.

```java
class PaymentProcessor {
    private PaymentGateway gateway;

    public PaymentProcessor(PaymentGateway gateway) {
        this.gateway = gateway;
    }

    public void process(Order order) {
        gateway.charge(order.getTotal());
    }
}
```

---

### **9. Protected Variations**
**Guides: Designing for Change by Using Stable Interfaces**  
**Principle:** Shield parts of the system from **future changes** using **interfaces, encapsulation, and design patterns**.

**Example:**
- Instead of coding payment logic directly into `OrderService`, use an interface to support multiple payment providers.

```java
interface PaymentGateway {
    void charge(double amount);
}

class StripePaymentGateway implements PaymentGateway {
    public void charge(double amount) {
        System.out.println("Charged via Stripe: $" + amount);
    }
}

class PayPalPaymentGateway implements PaymentGateway {
    public void charge(double amount) {
        System.out.println("Charged via PayPal: $" + amount);
    }
}
```

---

## **Summary Table of GRASP Patterns**
| **GRASP Pattern**        | **Key Idea** | **Example Use Case** |
|----------------|---------|---------------|
| **Creator** | Assign object creation to a class with a strong relationship. | `Order` creates `OrderItem` |
| **Controller** | Assign system events to a dedicated handler class. | `OrderController` manages order requests. |
| **Information Expert** | Assign responsibility to the class with the most relevant data. | `Order` calculates the total. |
| **Low Coupling** | Reduce dependencies between classes. | Use **dependency injection**. |
| **High Cohesion** | Keep related responsibilities together. | `OrderService` handles business logic, `OrderRepository` handles persistence. |
| **Polymorphism** | Use inheritance/interfaces instead of conditionals. | `CreditCardPayment` and `PayPalPayment` implement `PaymentMethod`. |
| **Pure Fabrication** | Create a helper class to avoid breaking other principles. | A `Logger` class instead of adding logging to `OrderService`. |
| **Indirection** | Use an intermediary to reduce dependencies. | `PaymentProcessor` handles communication with `PaymentGateway`. |
| **Protected Variations** | Use interfaces and encapsulation to guard against future changes. | `PaymentGateway` interface allows switching payment providers easily. |

---

## **Conclusion**
GRASP patterns provide a **structured approach** to object-oriented design, helping developers assign **responsibilities efficiently** while maintaining **low coupling, high cohesion, and scalability**. By applying these principles, developers can build **flexible, maintainable, and extensible** software systems.

Would you like **real-world case studies** of GRASP in action?