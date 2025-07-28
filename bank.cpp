#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string accName, int accNum) {
        name = accName;
        accountNumber = accNum;
        balance = 0.0;  // Initial balance is 0
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "✅ Amount " << amount << " deposited successfully!\n";
        } else {
            cout << "❌ Invalid deposit amount.\n";
        }
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= balance && amount > 0) {
            balance -= amount;
            cout << "✅ Amount " << amount << " withdrawn successfully!\n";
        } else {
            cout << "❌ Insufficient balance or invalid amount.\n";
        }
    }

    // Show balance
    void checkBalance() {
        cout << "💰 Current balance: " << balance << "\n";
    }

    // Show account details
    void accountDetails() {
        cout << "\n=== Account Details ===\n";
        cout << "Name: " << name << "\n";
        cout << "Account Number: " << accountNumber << "\n";
        cout << "Balance: " << balance << "\n";
    }
};

int main() {
    string name;
    int accNum, choice;
    double amount;

    cout << "🏦 Welcome to Simple Bank Management System\n";
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter new account number: ";
    cin >> accNum;

    BankAccount myAccount(name, accNum);

    do {
        cout << "\n===== Menu =====\n";
        cout << "1. Deposit Money\n";
        cout << "2. Withdraw Money\n";
        cout << "3. Check Balance\n";
        cout << "4. Show Account Details\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            myAccount.deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            myAccount.withdraw(amount);
            break;
        case 3:
            myAccount.checkBalance();
            break;
        case 4:
            myAccount.accountDetails();
            break;
        case 5:
            cout << "👋 Thank you for using our bank!\n";
            break;
        default:
            cout << "❌ Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
