# ATM-
This is a replica of ATM .


#Unique feature of my code
Added UPI Transfer in ATM

📌 Advanced ATM System (C Project)

A fully functional ATM Simulation System in C, featuring PIN authentication, Savings & Current account operations, UPI transfers, mini statement (transaction history), and printed receipts.
This project demonstrates use of structures, arrays, modular programming, and input validation in C.

🚀 Features
🔐 1. Secure PIN Authentication

User gets 3 attempts to enter correct PIN

Locks account after failed attempts

💳 2. Two Account Types

Savings Account

Current Account

🏦 3. Banking Operations
Feature	Savings	Current
Check balance	✔	✔
Deposit	✔	✔
Withdraw	✔	✔
UPI Transfer	✔	✔

All operations automatically update account balance.

🧾 4. Transaction History (Mini Statement)

Stores last 10 transactions

Circular buffer implementation

Shows:

Transaction Type

Amount

Balance After Transaction

📄 5. Receipt Printing

Every Deposit, Withdrawal, or UPI transfer prints a formatted receipt.

🧱 Tech Used

C Language

Arrays & Structures

Modular Functions

Terminal-based user interface

📁 Project Structure
ATM-System/
│
├── atm.c          # Main source code
└── README.md      # Documentation

🖥️ How to Compile & Run
Compile
gcc atm.c -o atm

Run
./atm

🛠️ How the Mini Statement Works

The system keeps the last 10 transactions using:

A fixed-size array

Circular indexing

Automatic overwrite of oldest entries

📌 Sample Output
=========== WELCOME TO ADVANCED ATM SYSTEM ===========
Enter your 4-digit PIN: ****

✔ Authentication Successful!

=============== MAIN MENU ================
1. Savings Account
2. Current Account
3. Mini Statement
4. Exit

🧩 Possible Future Enhancements

Here are optional features you can add:

✔ Support for multiple users

✔ File storage (save account & transactions)

✔ ATM cash dispenser logic

✔ More robust UPI format validation


✔ Encrypted PIN storage

If you want, I can generate the improved code.

<img width="831" height="569" alt="Screenshot 2025-11-24 102603" src="https://github.com/user-attachments/assets/55e9afc1-7775-4305-b5f3-efb4e80fd4e0" />

<img width="859" height="804" alt="Screenshot 2025-11-24 104446" src="https://github.com/user-attachments/assets/b049b5ad-d91e-4c67-8f69-a7c7f44c8039" />


