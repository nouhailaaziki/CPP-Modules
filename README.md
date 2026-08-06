# C++98 Handbook for 42 School Modules (CPP00–CPP09)

> **Audience:** Students transitioning from C to C++ in the 42 cursus  
> **Standard:** Strictly **C++98** (no C++11+ features)  
> **Goal:** A practical and conceptual reference aligned with the 42 CPP modules

---

## How to use this handbook

This handbook is intentionally dense and structured for study, revision, and exam preparation.

- If you are new to C++, read **CPP00 → CPP09 in order**.
- If you need targeted revision, jump to module sections and use the **checklists**, **tables**, and **exam questions**.
- Compile examples with C++98 flags:

```bash
c++ -Wall -Wextra -Werror -std=c++98 *.cpp
```

---

## Table of Contents

1. [CPP00](#cpp00)
2. [CPP01](#cpp01)
3. [CPP02](#cpp02)
4. [CPP03](#cpp03)
5. [CPP04](#cpp04)
6. [CPP05](#cpp05)
7. [CPP06](#cpp06)
8. [CPP07](#cpp07)
9. [CPP08](#cpp08)
10. [CPP09](#cpp09)
11. [STL Cheat Sheet (C++98)](#stl-cheat-sheet-c98)
12. [Big-O Complexity Tables](#big-o-complexity-tables)
13. [C++98 Limitations](#c98-limitations)
14. [Interview & Exam Questions](#interview--exam-questions)
15. [42 Exam Notes](#42-exam-notes)
16. [Glossary](#glossary)
17. [Final Revision Checklist](#final-revision-checklist)

---

# CPP00

## 1) What is C++?

### Definition
C++ is a compiled, statically typed, multi-paradigm language that extends C with:
- classes and object-oriented programming,
- stronger type systems,
- generic programming via templates,
- resource management idioms (RAII),
- a standard library.

### Why it exists
C gives control and performance, but large software needs better abstractions. C++ was designed to provide higher-level organization while preserving low-level power.

### Syntax (first look)
```cpp
#include <iostream>

int main() {
    std::cout << "Hello, C++98" << std::endl;
    return 0;
}
```

### Internal behavior
- Preprocessor expands `#include`.
- Compiler parses and type-checks.
- Object files are generated.
- Linker resolves symbols into an executable.

### Memory diagram
```text
Process Memory
+-------------------------+
| Code (text segment)     |
+-------------------------+
| Global/static data      |
+-------------------------+
| Heap (dynamic memory)   |
|   grows upward          |
+-------------------------+
| Stack (local variables) |
|   grows downward        |
+-------------------------+
```

### Common mistakes
- Thinking C++ is “just C with classes”.
- Ignoring constructors/destructors and resource ownership.

### Best practices
- Prefer deterministic ownership patterns.
- Keep interfaces small and explicit.

---

## 2) C vs C++

| Topic | C | C++98 |
|---|---|---|
| Abstraction | structs + functions | classes, inheritance, polymorphism |
| I/O | `printf/scanf` | `iostream` (`std::cout`, `std::cin`) |
| Memory | `malloc/free` | `new/delete` (+ constructors/destructors) |
| Generic code | macros, void* | templates |
| Exceptions | none | `try/catch/throw` |

### Why C++ features matter
- Encapsulation controls mutation.
- Constructors enforce valid initialization.
- RAII prevents many leaks and handle misuse.

---

## 3) Compilation process

### Stages
1. **Preprocessing**: includes/macros expansion.
2. **Compilation**: source → assembly.
3. **Assembly**: assembly → object code.
4. **Linking**: object files + libraries → executable.

### Diagram
```text
main.cpp --(preprocess)--> main.ii
main.ii  --(compile)-----> main.s
main.s   --(assemble)----> main.o
main.o + lib... --(link)-> a.out
```

### Common mistakes
- Multiple definition errors from non-`inline` function definitions in headers.
- Undefined reference when declaration exists but definition missing.

---

## 4) Namespaces

### Definition
Namespace groups symbols to avoid name collisions.

### Syntax
```cpp
namespace math {
    int add(int a, int b) { return a + b; }
}

int x = math::add(2, 3);
```

### Why it exists
Large codebases reuse common names (`Vector`, `String`, `swap`). Namespaces prevent collisions.

### Mistakes
- `using namespace std;` in headers (pollutes all includers).

### Best practice
- In headers, fully qualify (`std::string`).

---

## 5) iostream

### Core stream objects
- `std::cout`: standard output
- `std::cin`: standard input
- `std::cerr`: unbuffered errors
- `std::clog`: buffered logs

### Syntax
```cpp
int n;
std::cout << "Enter n: ";
std::cin >> n;
std::cout << "n=" << n << std::endl;
```

### Internal behavior
- Streams use operator overloading (`operator<<`, `operator>>`).
- Formatting state is stored in stream flags.

### Common mistakes
- Not checking `std::cin.fail()` after invalid input.

---

## 6) Classes and objects

### Definition
A class defines a custom type (data + behavior). An object is an instance.

### Syntax
```cpp
class Account {
private:
    int _balance;
public:
    Account(int b) : _balance(b) {}
    void deposit(int x) { _balance += x; }
    int balance() const { return _balance; }
};
```

### Memory model (simplified)
```text
Account object in stack:
+------------------+
| _balance (int)   |
+------------------+
```
Member functions are in code segment, not duplicated per object.

### Common mistakes
- Forgetting `const` on read-only member functions.

---

## 7) Access specifiers

- `public`: visible everywhere.
- `private`: visible only inside class (and friends).
- `protected`: class + derived classes.

### Why
Enforces invariants and API boundaries.

---

## 8) Constructors / Destructors

### Constructor
Initializes object at creation.

### Destructor
Runs automatically at end of lifetime; cleanup point.

```cpp
class FileGuard {
public:
    FileGuard() { /* open */ }
    ~FileGuard() { /* close */ }
};
```

### Order
- Construction: base → members → derived body.
- Destruction: reverse.

---

## 9) Member functions, static members, `this`, init lists

### `this`
Implicit pointer to current object.

```cpp
class A {
    int _x;
public:
    A(int x) : _x(x) {}
    void setX(int x) { this->_x = x; }
};
```

### Static members
Belong to class, not any object.

```cpp
class Counter {
public:
    static int s_count;
};
int Counter::s_count = 0;
```

### Initialization list
Preferred/required for:
- const members,
- reference members,
- base class construction.

---

## 10) Encapsulation

### Definition
Hide representation; expose behavior.

### Why
Prevents invalid states and fragile coupling.

### Example
```cpp
class Temperature {
private:
    int _celsius;
public:
    void setCelsius(int c) {
        if (c < -273) c = -273;
        _celsius = c;
    }
};
```

---

## CPP00 exercises

1. Build a `Contact` class (as in 42 phonebook spirit) with validation.
2. Implement a tiny logger class with static counter of log messages.

---

# CPP01

## Stack vs Heap

### Stack
Automatic storage duration; fast allocation/deallocation (scope-based).

### Heap
Manual lifetime; flexible size; must `delete` what you `new`.

```text
main()
 stack: [local A][local B]
 heap : [obj1][obj2][array]
```

## References vs pointers

| Feature | Reference | Pointer |
|---|---|---|
| Null | cannot be null (conceptually) | can be null |
| Rebinding | no | yes |
| Syntax | alias-like | explicit dereference |

```cpp
int x = 5;
int& r = x;
int* p = &x;
```

## `new`/`delete`

```cpp
int* p = new int(42);
delete p;

int* arr = new int[10];
delete[] arr;
```

### Mistakes
- `delete` vs `delete[]` mismatch (UB).
- Leaks on early return/exception.

## File streams

```cpp
#include <fstream>

std::ifstream in("input.txt");
std::ofstream out("out.txt");
```

### Best practices
- Check `is_open()` and stream state.
- Close is automatic via destructor.

---

# CPP02

## Orthodox Canonical Form (OCF)

Typical required members in C++98 exercises:
1. Default constructor
2. Copy constructor
3. Copy assignment operator
4. Destructor

### Rule of Three
If class manages a resource, define all three: copy ctor, copy assignment, destructor.

```cpp
class Buffer {
private:
    char* _data;
public:
    Buffer();
    Buffer(const Buffer& other);
    Buffer& operator=(const Buffer& other);
    ~Buffer();
};
```

## Deep vs Shallow copy

- Shallow: copies pointer value only.
- Deep: duplicates pointed resource.

```text
Shallow:
A._p ----+
         +--> [data]
B._p ----+

Deep:
A._p --> [data1]
B._p --> [data2]
```

## Fixed-point numbers

Represent values as integer + implicit scaling factor.

`stored = real * (1 << frac_bits)`

### Why
Deterministic precision and often faster than float on constrained systems.

---

# CPP03

## Inheritance

```cpp
class ClapTrap { /* ... */ };
class ScavTrap : public ClapTrap { /* ... */ };
```

### Why
Model “is-a” relationships and reuse base behavior.

## Constructor/destructor order

```text
Construct Derived:
1) Base ctor
2) Derived ctor

Destroy Derived:
1) Derived dtor
2) Base dtor
```

## Overriding and name hiding

- Same signature in derived can override (virtual context).
- Different signature with same name may hide base overloads.

### Best practice
Use explicit qualification when needed: `Base::func()`.

## Virtual destructor
Required for polymorphic base deletion.

```cpp
class Base { public: virtual ~Base() {} };
```

---

# CPP04

## Polymorphism and virtual functions

### Dynamic dispatch
When calling virtual function through base pointer/reference, runtime selects derived override.

```cpp
class Animal {
public:
    virtual void makeSound() const { std::cout << "?\n"; }
    virtual ~Animal() {}
};
class Dog : public Animal {
public:
    void makeSound() const { std::cout << "Woof\n"; }
};
```

## vtable / vptr (conceptual)

```text
[Dog object]
+----------------------+
| vptr ----+           |
+----------|-----------+
           v
        [Dog vtable] -> &Dog::makeSound
```

(Implementation detail, but useful model.)

## Abstract classes / interfaces

```cpp
class ICharacter {
public:
    virtual void use(int idx) = 0;
    virtual ~ICharacter() {}
};
```

Cannot instantiate classes with pure virtual methods.

---

# CPP05

## Exceptions

### Syntax
```cpp
try {
    throw std::runtime_error("error");
} catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
}
```

### Stack unwinding
On throw, stack frames are destroyed until matching catch.

### RAII connection
Objects on stack clean resources during unwinding via destructors.

### Exception safety levels
- Basic guarantee
- Strong guarantee
- No-throw guarantee

### Best practices
- Throw by value, catch by const reference.
- Keep destructors non-throwing.

---

# CPP06

## Casts

### `static_cast`
Compile-time checked conversions (related types, numeric casts).

### `dynamic_cast`
Runtime-checked cast across polymorphic hierarchy.
- Pointer cast: returns `NULL` on failure.
- Reference cast: throws `std::bad_cast`.

### `reinterpret_cast`
Bit-level reinterpretation; highly unsafe; use minimally.

### `const_cast`
Add/remove constness; modifying truly const object is UB.

## RTTI
Runtime type information supports `dynamic_cast` and `typeid`.

## Scalar conversions
Convert among `char`, `int`, `float`, `double` with range/precision considerations.

---

# CPP07

## Templates

### Function template
```cpp
template <typename T>
T maxOf(T a, T b) { return (a > b) ? a : b; }
```

### Class template
```cpp
template <typename T>
class Box {
    T _value;
public:
    Box(T v) : _value(v) {}
};
```

### Instantiation
Compiler generates concrete code when used.

### Specialization
Custom behavior for specific type.

```cpp
template <>
class Box<bool> { /* specialized */ };
```

### Mistakes
- Defining template implementations only in `.cpp` (link errors). Keep in headers.

---

# CPP08

## STL overview
STL has containers, iterators, algorithms, function objects.

## Key containers (module scope)
- `vector`, `list`, `deque`
- container adapters: `stack`, `queue`, `priority_queue`
- utility: `pair`

## Iterators
Generalized pointers enabling algorithms over containers.

## Algorithms
`std::find`, `std::sort` (random-access iterators), `std::for_each`, etc.

### Complexity snapshots
- `vector` push_back: amortized O(1)
- `list` insert/erase with iterator: O(1)
- `deque` push_front/back: amortized O(1)

---

# CPP09

## Associative containers

### `map`
Ordered key-value pairs, unique keys.

### `set`
Ordered unique keys.

### `multimap`, `multiset`
Allow duplicate keys.

### Complexity (balanced BST typical)
- insert/find/erase: O(log n)

## `stringstream`
String-based stream parsing/formatting.

```cpp
#include <sstream>
std::stringstream ss("42 3.14");
int a; double b;
ss >> a >> b;
```

## Reverse Polish Notation (RPN)
Use a stack:
- number => push
- operator => pop two, apply, push result

Time complexity: O(n)

## Bitcoin Exchange project idea
- Parse historical rates into map by date.
- For each input date/value, find exact or closest previous date.

## Ford-Johnson Merge-Insertion Sort / Jacobsthal
Advanced comparison-efficient sorting strategy; often implemented with:
- pair grouping,
- recursive structure,
- insertion order guided by Jacobsthal sequence.

---

# STL Cheat Sheet (C++98)

## Sequence containers

| Container | Access | Insert end | Insert middle | Notes |
|---|---:|---:|---:|---|
| `vector` | O(1) | amortized O(1) | O(n) | contiguous memory |
| `list` | O(n) | O(1) | O(1) with iterator | doubly-linked |
| `deque` | O(1) | amortized O(1) at ends | O(n) | segmented array |

## Associative containers

| Container | Duplicates | find | insert | erase |
|---|---|---:|---:|---:|
| `map` | no | O(log n) | O(log n) | O(log n) |
| `set` | no | O(log n) | O(log n) | O(log n) |
| `multimap` | yes | O(log n) | O(log n) | O(log n) |
| `multiset` | yes | O(log n) | O(log n) | O(log n) |

## Adapters

| Adapter | Underlying default | Ops |
|---|---|---|
| `stack` | `deque` | `push`, `pop`, `top` |
| `queue` | `deque` | `push`, `pop`, `front`, `back` |
| `priority_queue` | `vector` | `push`, `pop`, `top` |

---

# Big-O Complexity Tables

## Common operations

| Structure | Search | Insert | Delete |
|---|---:|---:|---:|
| Array (unsorted) | O(n) | O(n) | O(n) |
| Linked list | O(n) | O(1)
(with iterator) | O(1)
(with iterator) |
| Balanced BST | O(log n) | O(log n) | O(log n) |
| Hash table* | avg O(1) | avg O(1) | avg O(1) |

\* `std::unordered_*` is not in C++98.

---

# C++98 Limitations

- No `auto` type deduction.
- No range-based for loop.
- No move semantics.
- No `nullptr` (use `NULL`/`0`).
- No smart pointers in standard library (`std::auto_ptr` exists but problematic).
- No lambda expressions.
- No `unordered_map`.

---

# Interview & Exam Questions

1. Why does Rule of Three exist?
2. Difference between deep and shallow copy?
3. Why should a polymorphic base have virtual destructor?
4. Difference between `static_cast` and `dynamic_cast`?
5. What is RAII and why is it crucial with exceptions?
6. Why can templates cause linker errors if defined in `.cpp` only?
7. Complexity differences between `vector` and `list` inserts?
8. How does dynamic dispatch work conceptually?

---

# 42 Exam Notes

- Compile flags matter: `-Wall -Wextra -Werror -std=c++98`.
- Follow canonical form exactly when asked.
- Verify copy semantics in classes owning raw pointers.
- In inheritance modules, confirm constructor/destructor order using logs.
- In polymorphism modules, test behavior through base pointers.
- In exception modules, test no leaks under throw paths.
- In STL modules, justify container choice with complexity.

---

# Glossary

- **RAII**: Resource Acquisition Is Initialization.
- **OCF**: Orthodox Canonical Form.
- **RTTI**: Run-Time Type Information.
- **UB**: Undefined Behavior.
- **Polymorphism**: One interface, multiple implementations.
- **Encapsulation**: Hiding internal representation.
- **Iterator**: Object used to traverse container elements.

---

# Final Revision Checklist

## Core language
- [ ] I can explain object lifetime on stack vs heap.
- [ ] I can implement class with proper ctor/dtor.
- [ ] I understand copy ctor vs assignment.
- [ ] I can diagnose shallow copy bugs.

## OOP
- [ ] I can design base/derived relationships.
- [ ] I know when to use virtual destructor.
- [ ] I understand abstract classes/interfaces.

## Exceptions
- [ ] I can write exception-safe code with RAII.
- [ ] I catch by `const std::exception&` where appropriate.

## Templates/STL
- [ ] I can write function/class templates.
- [ ] I know where template definitions must live.
- [ ] I can choose containers by complexity.

## Module-specific
- [ ] CPP00 fundamentals
- [ ] CPP01 memory and references
- [ ] CPP02 canonical form / fixed point
- [ ] CPP03 inheritance
- [ ] CPP04 polymorphism
- [ ] CPP05 exceptions
- [ ] CPP06 casts/RTTI
- [ ] CPP07 templates
- [ ] CPP08 STL algorithms/iterators
- [ ] CPP09 associative containers + project algorithms

---

## Final note

This README is a **solid foundation** for all 42 CPP modules in C++98. If you want, the next step is to expand each chapter into full “textbook mode” subchapters (with exhaustive solved exercises, extended diagrams, and module-by-module mini-project walkthroughs).
