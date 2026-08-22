# C++ Modules

A comprehensive series of projects focused on Object-Oriented Programming (OOP) paradigms, memory management, and high-performance system design in C++. 

Developed as part of the 42 Network curriculum, this repository systematically covers the transition from procedural C code to advanced C++ concepts, culminating in custom template design and Standard Template Library (STL) algorithmic optimizations.

---

## Key Competencies

* **Core Paradigms:** Encapsulation, Abstraction, Subtype Polymorphism, Ad-hoc Polymorphism.
* **Architecture & Patterns:** Orthodox Canonical Form, Factory Design Pattern, Interface Segregation.
* **Memory & Safety:** Manual Allocation (`new`/`delete`), Pointer-Reference Semantics, Deep Copy Protocols, Custom Exception Handling.
* **Modern C++ Foundations:** Explicit Type Casting (`static_cast`, `dynamic_cast`, `reinterpret_cast`), Template Metaprogramming, STL Containers and Iterators.

---

## Curriculum Structure

| Module | Core Domain | Primary Topics & Technical Scope |
| :--- | :--- | :--- |
| **Module 00** | Fundamental Syntax & Scope | Namespaces, class attributes, member functions, standard I/O streams, static parameters, and initialization lists. |
| **Module 01** | Memory & References | Heap vs. stack allocation, pointer-to-member syntax, file stream manipulation, and reference lifecycles. |
| **Module 02** | Operator Overloading | Fixed-point numerical representations, operator overloads (arithmetic, comparison, increment), and canonical form compliance. |
| **Module 03** | Inheritance | Base/derived class dynamics, method overriding, constructor-destructor chaining, and virtual inheritance (resolving the diamond problem). |
| **Module 04** | Subtype Polymorphism | Abstract classes, pure virtual functions, interface definitions, and deep copy memory validation. |
| **Module 05** | Error Handling | Exception propagation (`try`/`catch`), custom `std::exception` class hierarchies, and input boundary enforcement. |
| **Module 06** | Type Conversion | Type casting semantics (`static_cast`, `dynamic_cast`, `reinterpret_cast`), scalar conversions, and runtime type identification. |
| **Module 07** | Generic Programming | Function templates, class templates, array bounds checking, and generic element iteration. |
| **Module 08** | STL Algorithms | Sequenced and associative container navigation, custom iterators, element retrieval, and span computation algorithms. |
| **Module 09** | Advanced Data Structures | Complex STL applications, stack evaluation algorithms (RPN), and dual-container performance profiling (Ford-Johnson Merge-Insertion). |

---

## Detailed Exercise Specifications

<details>
<summary><b>Module 00: Fundamentals</b></summary>

* **Ex00: Noise Control** – Command-line string manipulation using standard output streams.
* **Ex01: Contact Directory** – Static array management, entity encapsulation, and tabular output formatting.
* **Ex02: Transaction Ledger** – Log analysis, static member state tracking, and timestamp synchronization.
</details>

<details>
<summary><b>Module 01: Memory Allocation & File Streams</b></summary>

* **Ex00: Dynamic Instantiation** – Managing single-object allocation lifetime between stack and heap memory.
* **Ex01: Array Allocation** – Allocating, initializing, and releasing memory blocks using heap vectors.
* **Ex02: Variable Referencing** – Memory address comparison between direct values, pointers, and references.
* **Ex03: Composition & References** – Binding persistent object references inside composite class definitions.
* **Ex04: String Replacement Engine** – File stream reading/writing (`std::ifstream`/`std::ofstream`) with search-and-replace logic.
* **Ex05: Event Router** – Replacing conditional logic blocks with member function pointer dispatch tables.
* **Ex06: Log Filtering** – Cascading log level extraction using fallthrough `switch` mechanisms.
</details>

<details>
<summary><b>Module 02: Fixed-Point Arithmetic & Canonical Design</b></summary>

* **Ex00: Canonical Base** – Constructing a fixed-point class adhering to default, copy, assignment, and destructor rules.
* **Ex01: Scaled Conversions** – Implementing integer and floating-point conversions for fixed-point representation.
* **Ex02: Operator Overloads** – Full overload suite including arithmetic, relational, boolean, and increment operations.
* **Ex03: Spatial Triangulation** – Binary Space Partitioning (BSP) point-in-triangle algorithm using fixed-point calculations.
</details>

<details>
<summary><b>Module 03: Class Hierarchies</b></summary>

* **Ex00: Base Unit** – Encapsulated state machine with hit points, energy metrics, and action methods.
* **Ex01: Heavy Defender** – Derived subclass overriding behavior while extending state capacity.
* **Ex02: Specialized Unit** – Alternative derived implementation demonstrating polymorphic extension patterns.
* **Ex03: Hybrid Class** – Resolving multiple inheritance ambiguity using `virtual` base inheritance.
</details>

<details>
<summary><b>Module 04: Abstract Classes & Interfaces</b></summary>

* **Ex00: Virtual Dispatch** – Dynamic method resolution over base class pointers using runtime vtables.
* **Ex01: Memory Integrity** – Allocating nested pointers within derived classes to ensure strict deep-copy safety.
* **Ex02: Abstract Enforcers** – Converting concrete base entities into non-instantiable abstract interfaces.
* **Ex03: Interface Architecture** – Decoupled component system using interface contracts (`ICharacter`, `IMateriaSource`).
</details>

<details>
<summary><b>Module 05: Robustness & Exceptions</b></summary>

* **Ex00: Grade Boundaries** – Custom exceptions enforcing integer range validation (1 to 150).
* **Ex01: Form Authorizations** – Multi-class authorization protocols validating execution authority levels.
* **Ex02: Concrete Execution** – Specialized actionable documents (`Shrubbery`, `Robotomy`, `Pardon`) executing context actions.
* **Ex03: Form Factory** – Dynamic object generation using matching string keys without rigid conditional trees.
</details>

<details>
<summary><b>Module 06: Type Systems & Casts</b></summary>

* **Ex00: Scalar Parsing** – String conversion engine detecting primitive types and safely invoking `static_cast`.
* **Ex01: Data Serialization** – Pointer address serialization to `uintptr_t` scalar types using `reinterpret_cast`.
* **Ex02: Dynamic Identification** – Identifying unknown runtime object references using `dynamic_cast`.
</details>

<details>
<summary><b>Module 07: Template Metaprogramming</b></summary>

* **Ex00: Utility Templates** – Type-agnostic utility functions for variable swapping and comparison.
* **Ex01: Array Iteration** – Function template applying functional callbacks across arrays of arbitrary types.
* **Ex02: Generic Array** – Memory-managed dynamic array template featuring subscript operator safety and automatic sizing.
</details>

<details>
<summary><b>Module 08: Standard Template Library</b></summary>

* **Ex00: Generic Search** – Target discovery within standard sequential containers using standard iterators.
* **Ex01: Range Evaluation** – High-performance span computation across container populations.
* **Ex02: Iterable Stack** – Adapter exposing underlying container iterators for the standard stack interface.
</details>

<details>
<summary><b>Module 09: Algorithmic Efficiency & Data Structures</b></summary>

* **Ex00: Rate Exchange Engine** – CSV database parsing and temporal rate lookup via `std::map`.
* **Ex01: Reverse Polish Evaluator** – Postfix mathematical expression parsing backed by `std::stack`.
* **Ex02: Dual-Container Sorter** – Implementation of the Ford-Johnson (Merge-Insertion) algorithm comparing runtime performance across `std::vector` and `std::deque`.
</details>

---

## Execution & Quality Control

### Environment Standards

* **Compiler Requirement:** Explicit compilation using the `c++` compiler alias.
* **Flags:** `-Wall -Wextra -Werror -std=c++98`.
* **Verification:** Zero toleration for unhandled exceptions or memory leaks (`valgrind` / AddressSanitizer verified).

### Workflow Integration

Each exercise is self-contained within its corresponding directory and includes a custom `Makefile`. 

To compile and verify any specific component:

```bash
# Target directory structure: CPP-Module-[XX]/ex[YY]
make -C CPP-Module-02/ex02

# Execute the generated binary target
./CPP-Module-02/ex02/a.out

# Clean object dependencies and binaries
make -C CPP-Module-02/ex02 fclean
