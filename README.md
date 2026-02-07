# C++ Modules

This repository serves as a technical compendium for mastering C++ (C++98). It covers the transition from procedural programming to the **Object-Oriented** paradigm, focusing on resource management and class architecture.

---

## 1. The Foundation: Object-Oriented Programming

OOP shifts the focus from "steps of execution" to "interactions between entities."

### The 4 Pillars of OOP

* **Encapsulation (Access Control):** Bundling data and functions.
    * `Private`: Only accessible within the class (Hidden).
    * `Protected`: Accessible by the class and its children.
    * `Public`: Interface accessible by everyone.
* **Abstraction (Interface vs. Implementation):** Hiding complexity.
    * **Abstract Class:** Contains at least one **pure virtual function** (`= 0`).
    * **Interface:** A class with *only* pure virtual functions (a C++ convention).
* **Inheritance (Code Reuse):** Creating new classes from existing ones. 
    * *Note:* In 42, we primarily use **Public Inheritance** to model "is-a" relationships.
* **Polymorphism (Many Forms):**
    * **Static (Compile-time):** Function/Operator overloading and Templates.
    * **Dynamic (Runtime):** Achieved via **Virtual Functions**. The correct function is chosen based on the *real object type* at runtime.

---

## 2. Class Architecture & Lifecycle

### Orthodox Canonical Form (OCF)
To ensure classes behave predictably (especially when dealing with the Heap), we follow the **Rule of Three**. A class is OCF compliant when it defines:
1.  **Default Constructor**: `Class();`
2.  **Copy Constructor**: `Class(const Class& other);`
3.  **Copy Assignment Operator**: `Class& operator=(const Class& other);`
4.  **Destructor**: `~Class();`

> **Pro Tip:** Always check for **Self-Assignment** (`if (this != &other)`) in your assignment operator to prevent deleting your own data before copying it.

### Initialization Lists
Always initialize members in the constructor's initialization list.
* **Mechanical Necessity:** Required for `const` members and `references`.
* **Performance:** Avoids calling the default constructor and then the assignment operator.

---

## 3. Memory & Resource Management



### The Stack vs. The Heap
* **Stack:** Automatic, fast, but fixed size. Variables are destroyed when they go out of scope.
* **Heap:** Manual, flexible, but slower. Managed via `new` and `delete`.

### Deep vs. Shallow Copy
* **Shallow Copy:** Copies the pointer address. Both objects point to the same memory (leads to **Double Free** crashes).
* **Deep Copy:** Allocates new memory and copies the *values*. This is the goal of the OCF Copy Constructor.

### `new/delete` vs `malloc/free`
| Feature | `new` / `delete` | `malloc` / `free` |
| :--- | :--- | :--- |
| **Type Safety** | Returns typed pointer | Returns `void*` (needs cast) |
| **Object Awareness** | Calls Constructor/Destructor | Raw memory only |
| **Arrays** | `new[]` / `delete[]` | `malloc(size * n)` |

---

## 4. Pointers, References, and Namespaces

### References vs. Pointers
References are "aliases." Unlike pointers, they **cannot be NULL** and **cannot be reassigned**.
* **Use Pointers** when you need to point to nothing (`NULL`) or change what you point to later.
* **Use References** for function parameters to avoid copying large objects (use `const T&` for read-only).

### Namespaces
A scope tool to prevent name collisions.
* `std::` is the Standard Namespace.
* **Rule:** Avoid `using namespace std;` in headers. It is safer to use the scope resolution operator `::`.

---

## 5. Exception Handling & Logic Flow

Exceptions allow the program to handle "exceptional" runtime errors (like division by zero or failed allocations) without crashing.
* **`try`**: Wraps the risky code.
* **`throw`**: Signals that an error occurred (usually an object derived from `std::exception`).
* **`catch`**: Handles the error.

---

## 6. Templates (Parametric Polymorphism)
Templates allow you to write generic code. The compiler generates a specific version of the function or class for each data type you use.
```cpp
template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}
```

---
*Reference for 42 Network C++ Modules. Focus: C++98 Standard.*
