<div align="center">
    
# 🍜 TKF Restaurant Payment System

A feature-rich, console-based **Point-of-Sale (POS) and Restaurant Management System** built in **C**, simulating the ordering, cart, and payment workflow of **The Korean Food (TKF) Restaurant**.

Originally conceived as an academic exercise, this repository represents an independent **modular architecture overhaul**, transforming a basic script into a structured, scalable application with persistent file management.

---

![Language](https://img.shields.io/badge/Language-C-%2300599C?style=for-the-badge&logo=c&logoColor=white)
![Compiler](https://img.shields.io/badge/Compiler-GCC-%23A42E2B?style=for-the-badge&logo=gnu&logoColor=white)
![Environment](https://img.shields.io/badge/Environment-MSYS2%20UCRT64-%231F1F1F?style=for-the-badge&logo=msys2&logoColor=white)
![Platform](https://img.shields.io/badge/Platform-Console%2FCLI-%230E8A16?style=for-the-badge&logo=windows&logoColor=white)
![Architecture](https://img.shields.io/badge/Architecture-Modular-%23563D7C?style=for-the-badge)

</div>

---

## Application Preview

<div align="center">

![TKF Restaurant Dashboard Preview](assets/screenshots/tkf.png)

*Modern interactive CLI dashboard with UTF-8 support and ANSI UI styling*

</div>

---

## Overview & Evolution

The **TKF Restaurant Payment System** demonstrates advanced use of procedural programming principles in C to solve practical, real-world business constraints. 

### What's New in This Version?
This enhanced release introduces a complete architectural refactor:
* **Modular Codebase:** Separated monolithic scripts into dedicated functional modules (`menu`, `order`, `payment`, `admin`, etc.).
* **Robust Data Structures:** Utilizes custom `struct` definitions to cleanly map entities like customers, cart items, and catalog items.
* **Persistent Storage:** Integrated file-handling operations to ensure transaction ledgers (`TransactionRecord.txt`) persist post-execution.
* **Expanded Capabilities:** Comprehensive admin toolset and dynamic cart handling.
  
---

## Technical Implementation
The system leverages core structured programming paradigms:

* **Custom Structures (`struct`):** Encapsulates relational data safely.

```C
struct Customer {
    char name[50];
    char memberStatus[20];
    float totalBill;
};

struct Menu {
    int id;
    char name[50];
    float regularPrice;
    float largePrice;
};

struct CartItem {
    char foodName[50];
    char size[10];
    int quantity;
    float totalPrice;
};
```
* **Modular Design**: Decoupled logic improves maintainability, debugging speed, and code readability.

* **File Handling**: Built-in stream management (fopen, fprintf, fgets, fclose) handles local log persistence.
---

## Core Features

### Customer Experience
* **Interactive Menu:** Browse categorized options with customizable sizing (Regular / Large).
* **Smart Cart System:** Add, modify, or remove items dynamically prior to checkout.
* **Discounts & Billing:** Automatic member status validation and total calculations.
* **Flexible Dining Options:** Seamlessly switch between dine-in and takeaway flows.
* **Audit Trails:** Instant receipt generation and automatic logging to persistent storage.

### Administrative 
* **Catalog Management:** Add, update, or remove menu items on the fly.
* **Sales Monitoring:** Review historical transactional records and metrics.

---

# Technologies Used

| Category | Details & Specifications |
| :--- | :--- |
| **Language** | C Programming Language |
| **Compiler** | GCC Compiler |
| **Environment** | MSYS2 UCRT64 Environment |
| **Paradigm** | Structured Programming, File Processing |
| **Application Type** | Console Application |

---

# Getting Started & Compilation

### Prerequisites
Ensure you have a working C compiler toolchain installed. This project is optimized for MSYS2 UCRT64 on Windows:
* GCC Compiler
* Make / Bash terminal

### Compilation & Execution
Clone the repository and compile via your terminal:

```bash
# Clone the repository
git clone [https://github.com/mhdhamka/TKFSystem.git](https://github.com/mhdhamka/TKFSystem.git)
cd TKFSystem

#Compile
gcc main.c menu.c order.c payment.c receipt.c admin.c file.c utility.c -o TKF

## Run
./TKF.exe
```

---

# Development Enhancement

This version was independently developed to improve the original TKF Restaurant Payment System by introducing:

- Better source code organization
- Modular architecture
- Improved ordering workflow
- Shopping cart implementation
- Payment processing
- Administrative functions
- Persistent transaction records
- Improved maintainability

The enhancement focuses on transforming a basic console application into a more structured and scalable software system.

---

# Project Structure

```
TKF-Restaurant-Payment-System
│
├── main.c                  # Main program controller
├── tkf.h                   # Structures and function prototypes
│
├── menu.c                  # Menu management
├── order.c                 # Ordering and cart system
├── payment.c               # Payment calculation
├── receipt.c               # Receipt generation
├── admin.c                 # Admin management
├── file.c                  # Transaction file handling
├── utility.c               # Helper functions
│
├── TransactionRecord.txt  # Stored transaction history
│
└── README.md
```

---

# License

Developed as an independent enhancement initiative based on an initial academic project. Designed for educational, portfolio, and software design practice purposes.

---

