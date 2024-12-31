#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for account details
typedef struct {
    char name[50];
    int accountNumber;
    float balance;
} Account;

// Function prototypes
void createAccount();
void viewAccount();
void depositMoney();
void withdrawMoney();

int main() {
    int choice;

    while (1) {
        printf("\n====== Banking System Menu ======\n");
        printf("1. Create New Account\n");
        printf("2. View Account Details\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccount(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: printf("Exiting the program. Thank you!\n"); return 0;
            default: printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to create a new account
void createAccount() {
    Account acc;
    FILE *file = fopen("accounts.dat", "ab"); // Open file in append binary mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter your name: ");
    scanf("%s", acc.name);
    printf("Enter account number: ");
    scanf("%d", &acc.accountNumber);
    acc.balance = 0; // Initial balance

    fwrite(&acc, sizeof(Account), 1, file); // Write account to file
    fclose(file);

    printf("Account created successfully!\n");
}

// Function to view account details
void viewAccount() {
    Account acc;
    int accountNumber;
    int found = 0;

    FILE *file = fopen("accounts.dat", "rb"); // Open file in read binary mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.accountNumber == accountNumber) {
            printf("\nAccount Details:\n");
            printf("Name: %s\n", acc.name);
            printf("Account Number: %d\n", acc.accountNumber);
            printf("Balance: $%.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found!\n");
    }

    fclose(file);
}

// Function to deposit money
void depositMoney() {
    Account acc;
    int accountNumber;
    float amount;
    int found = 0;

    FILE *file = fopen("accounts.dat", "rb+"); // Open file in read-write binary mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to deposit: $");
    scanf("%f", &amount);

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.accountNumber == accountNumber) {
            acc.balance += amount; // it can also be written as acc.balance = acc.balance + amount;
            // Add deposit amount to balance
            fseek(file, -sizeof(Account), SEEK_CUR); // Move file pointer back
            fwrite(&acc, sizeof(Account), 1, file); // Update record
            printf("Deposit successful! New balance: $%.2f\n", acc.balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found!\n");
    }

    fclose(file);
}

// Function to withdraw money
void withdrawMoney() {
    Account acc;
    int accountNumber;
    float amount;
    int found = 0;

    FILE *file = fopen("accounts.dat", "rb+"); // Open file in read-write binary mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    printf("Enter amount to withdraw: $");
    scanf("%f", &amount);

    while (fread(&acc, sizeof(Account), 1, file)) {
        if (acc.accountNumber == accountNumber) {
            if (acc.balance >= amount) {
                acc.balance -= amount; // it can also be written as acc.balance = acc.balance - amount;
                // Subtract withdrawal amount from balance
                fseek(file, -sizeof(Account), SEEK_CUR); // Move file pointer back
                fwrite(&acc, sizeof(Account), 1, file); // Update record
                printf("Withdrawal successful! New balance: $%.2f\n", acc.balance);
            } else {
                printf("Insufficient balance!\n");
            }
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found!\n");
    }

    fclose(file);
}
