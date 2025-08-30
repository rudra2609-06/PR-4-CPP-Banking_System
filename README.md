# PR-4-CPP-Banking_System

-----

# C++ Banking System: An Object-Oriented Approach

This project is a robust, console-based banking system developed in C++. It serves as a practical demonstration of core Object-Oriented Programming (OOP) principles, including abstraction, inheritance, and polymorphism, to create a flexible and maintainable application for managing various types of bank accounts.

## Project Overview

The application provides a command-line interface for common banking operations, enabling users to manage a registry of bank accounts. The system is architected around a class hierarchy that models real-world banking entities, ensuring scalability and adherence to solid software design principles.

## Core Features

  * **Account Management**: Create and manage different account types through a dynamic menu.
  * **Polymorphic Operations**: Seamlessly perform common banking operations like deposits and withdrawals, with behaviors that are dynamically determined based on the specific account type (e.g., a withdrawal from a `CheckingAccount` handles overdrafts, while a withdrawal from a `FixedDepositAccount` is disallowed).
  * **Dynamic Data Storage**: The registry uses an array of base-class pointers, showcasing polymorphism by storing and managing all derived-class objects in a unified manner.
  * **Search Functionality**: Efficiently locate any account in the registry using its unique account number.
  * **Account Information Display**: Retrieve and present detailed information for each account, including type-specific attributes like interest rates or overdraft limits.

## Technical Design & Implementation

The system's architecture is built on a strong foundation of C++ OOP concepts:

### Class Hierarchy

  * **`BankAccount` (Abstract Class)**: This class serves as the abstract base class for all account types. It encapsulates the shared attributes (`accountNumber`, `accountHolderName`, `balance`) and defines the interface for common banking operations through virtual functions (`deposit`, `withdraw`, `displayAccountInfo`). The presence of a pure virtual function, `calculateInterest()`, makes this class abstract, enforcing that all derived classes must provide their own specific implementation.
  * **`SavingsAccount`**: Inherits from `BankAccount`. It introduces the `interestRate` attribute and provides a concrete implementation for `calculateInterest()`, showcasing how different accounts can have distinct behaviors while conforming to a common interface.
  * **`CheckingAccount`**: Inherits from `BankAccount`. This class demonstrates method overriding to implement specific business logic. Its `withdraw()` method is overridden to incorporate an `overdraftLimit`, preventing a withdrawal that would exceed the allowed negative balance.
  * **`FixedDepositAccount`**: Inherits from `BankAccount`. This class provides a clear example of restrictive behavior. It overrides `deposit()` and `withdraw()` to explicitly prevent these operations, reflecting the non-liquid nature of a fixed deposit account.

### Project Structure

```
.
├── .vscode/               # VS Code configuration files
├── .gitignore             # Git ignore file
├── banking_system.cpp     # Main source code file
├── banking_system.exe     # Executable (after compilation)
└── README.md              # Project documentation
```

### Compilation and Execution

To compile and run this project, you will need a C++ compiler (e.g., g++).

1.  **Clone the Repository**:
    ```bash
    git clone https://github.com/your-username/your-repo.git
    cd your-repo
    ```
2.  **Compile the Source Code**:
    ```bash
    g++ banking_system.cpp -o banking_system
    ```
3.  **Run the Executable**:
    ```bash
    ./banking_system
    ```

## Screenshots

The following screenshots provide a visual walkthrough of the application's functionality and user interface.

### 1\. Account Creation

This screenshot demonstrates the menu-driven process of adding a new Savings Account, highlighting the data entry for key account attributes.

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/158f4613-93e3-4a2b-bfa5-ff55f353fd75" />


### 2\. Deposit and Withdrawal

This screenshot illustrates the successful execution of both a deposit and a withdrawal operation, showcasing the system's transaction handling.

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/9592f9f5-2b2f-4fb8-bfe2-92eea37c621e" />


### 3\. Account Lookup

This final screenshot captures the successful withdrawal followed by a search for the account, which displays the updated balance and other account details, confirming the integrity of the data.

<img width="1920" height="1080" alt="image" src="https://github.com/user-attachments/assets/2257953d-a128-41c4-ad89-bbf7680ab9e9" />


-----

### Author

  * **Rudra Thakkar**
  * BCA (Data Science) Student
  * Practicing **Full Stack Development & C++**
