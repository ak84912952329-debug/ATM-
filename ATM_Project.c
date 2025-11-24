#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 10   // mini statement limit

// Structure for Transaction
struct Transaction {
    char type[20];
    float amount;
    float balanceAfter;
};

// Structure for Account
struct Account {
    int pin;
    float savingsBalance;
    float currentBalance;
    struct Transaction history[MAX_TRANSACTIONS];
    int tIndex;   // points to next transaction
};

// Function Declarations
int authenticate(int storedPin);
void atmMenu(struct Account *acc);
void accountMenu(struct Account *acc, int accountType);
void checkBalance(struct Account *acc, int accountType);
void deposit(struct Account *acc, int accountType);
void withdraw(struct Account *acc, int accountType);
void upiTransfer(struct Account *acc, int accountType);
void printReceipt(float amount, char type[], float balance);
void addTransaction(struct Account *acc, char type[], float amount, float balance);
void miniStatement(struct Account *acc);

int main() {
    struct Account user = {1234, 5000.00, 3000.00, {}, 0};

    printf("\n=========== WELCOME TO ADVANCED ATM SYSTEM ===========\n");

    if (!authenticate(user.pin)) {
        printf("\n❌ Too many wrong attempts. Account locked!\n");
        return 0;
    }

    atmMenu(&user);

    return 0;
}

// PIN Authentication
int authenticate(int storedPin) {
    int pin, attempts = 0;

    while (attempts < 3) {
        printf("\nEnter your 4-digit PIN: ");
        scanf("%d", &pin);

        if (pin == storedPin) {
            printf("\n✔ Authentication Successful!\n");
            return 1;
        } else {
            attempts++;
            printf("❌ Incorrect PIN! Attempts left: %d\n", 3 - attempts);
        }
    }
    return 0;
}

// Main Menu
void atmMenu(struct Account *acc) {
    int choice;

    do {
        printf("\n================ MAIN MENU ================\n");
        printf("1. Savings Account\n");
        printf("2. Current Account\n");
        printf("3. Mini Statement\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: accountMenu(acc, 1); break;
            case 2: accountMenu(acc, 2); break;
            case 3: miniStatement(acc); break;
            case 4: printf("\nThank you for using the ATM!\n"); break;
            default: printf("❌ Invalid choice!\n");
        }

    } while (choice != 4);
}

// Account Menu
void accountMenu(struct Account *acc, int accountType) {
    int choice;

    do {
        printf("\n========== %s ACCOUNT MENU ==========\n",
               accountType == 1 ? "SAVINGS" : "CURRENT");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. UPI Transfer\n");
        printf("5. Back\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: checkBalance(acc, accountType); break;
            case 2: deposit(acc, accountType); break;
            case 3: withdraw(acc, accountType); break;
            case 4: upiTransfer(acc, accountType); break;
            case 5: return;
            default: printf("❌ Invalid option!\n");
        }
    } while (choice != 5);
}

// Check Balance
void checkBalance(struct Account *acc, int accountType) {
    float balance = accountType == 1 ? acc->savingsBalance : acc->currentBalance;
    printf("\n💰 Current Balance: ₹%.2f\n", balance);
}

// Deposit
void deposit(struct Account *acc, int accountType) {
    float amount;

    printf("\nEnter amount to deposit: ₹");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("❌ Invalid amount!\n");
        return;
    }

    if (accountType == 1)
        acc->savingsBalance += amount;
    else
        acc->currentBalance += amount;

    float newBal = accountType == 1 ? acc->savingsBalance : acc->currentBalance;

    printf("✔ Deposit Successful!\n");
    printReceipt(amount, "Deposit", newBal);

    addTransaction(acc, "Deposit", amount, newBal);
}

// Withdraw
void withdraw(struct Account *acc, int accountType) {
    float amount;
    float *balance = accountType == 1 ? &acc->savingsBalance : &acc->currentBalance;

    printf("\nEnter amount to withdraw: ₹");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("❌ Invalid amount!\n");
        return;
    }
    if (amount > *balance) {
        printf("❌ Insufficient Balance!\n");
        return;
    }

    *balance -= amount;

    printf("✔ Withdrawal Successful!\n");
    printReceipt(amount, "Withdraw", *balance);

    addTransaction(acc, "Withdraw", amount, *balance);
}

// UPI Transfer Feature
void upiTransfer(struct Account *acc, int accountType) {
    char upiID[50];
    float amount;
    float *balance = accountType == 1 ? &acc->savingsBalance : &acc->currentBalance;

    printf("\nEnter UPI ID (example: user@bank): ");
    scanf("%s", upiID);

    printf("Enter amount to transfer: ₹");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("❌ Invalid amount!\n");
        return;
    }
    if (amount > *balance) {
        printf("❌ Insufficient Balance!\n");
        return;
    }

    *balance -= amount;

    printf("\n✔ UPI Transfer Successful!\n");
    printf("Sent ₹%.2f to %s\n", amount, upiID);

    addTransaction(acc, "UPI", amount, *balance);
}

// Add Transaction to Mini Statement
void addTransaction(struct Account *acc, char type[], float amount, float balance) {
    int i = acc->tIndex % MAX_TRANSACTIONS;

    strcpy(acc->history[i].type, type);
    acc->history[i].amount = amount;
    acc->history[i].balanceAfter = balance;

    acc->tIndex++;
}

// Print Mini Statement
void miniStatement(struct Account *acc) {
    printf("\n============== MINI STATEMENT ==============\n");

    if (acc->tIndex == 0) {
        printf("No transactions yet.\n");
        return;
    }

    int count = acc->tIndex < MAX_TRANSACTIONS ? acc->tIndex : MAX_TRANSACTIONS;

    for (int i = 0; i < count; i++) {
        printf("%d. %-10s  ₹%.2f   Balance: ₹%.2f\n",
               i + 1,
               acc->history[i].type,
               acc->history[i].amount,
               acc->history[i].balanceAfter);
    }

    printf("============================================\n");
}

// Receipt Printer
void printReceipt(float amount, char type[], float balance) {
    printf("\n======== TRANSACTION RECEIPT ========\n");
    printf("Type: %s\n", type);
    printf("Amount: ₹%.2f\n", amount);
    printf("Balance After: ₹%.2f\n", balance);
    printf("=====================================\n");
}
