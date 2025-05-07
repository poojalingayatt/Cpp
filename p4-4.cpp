/* Programmer: Pooja Lingayat
   Date: 3-3-25
   Aim: To implement a bank account system using inheritance and runtime polymorphism for savings and current accounts. */

#include<iostream>
#include<string>
using namespace std;

// Base class for Bank Account
class BankAccount {
protected:
    int accountNumber;
    double balance;
    double lastTransaction; // +ve for deposit, -ve for withdrawal
public:
    BankAccount(int accNo = 0, double bal = 0) {
        accountNumber = accNo;
        balance = bal;
        lastTransaction = 0;
    }
    virtual ~BankAccount() {
        cout << "Account " << accountNumber << " closed.\n";
    }

    void deposit(double amount) {
        balance += amount;
        lastTransaction = amount;
        cout << "Deposited: " << amount << endl;
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            lastTransaction = -amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void undoLastTransaction() {
        balance -= lastTransaction;
        cout << "Last transaction undone.\n";
        lastTransaction = 0;
    }

    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

// Derived class for Savings Account
class SavingsAccount : public BankAccount {
    double interestRate;
public:
    SavingsAccount(int accNo = 0, double bal = 0, double rate = 0) : BankAccount(accNo, bal) {
        interestRate = rate;
    }
    void addInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        lastTransaction = interest;
        cout << "Interest added: " << interest << endl;
    }
};

// Derived class for Current Account
class CurrentAccount : public BankAccount {
    double overdraftLimit;
public:
    CurrentAccount(int accNo = 0, double bal = 0, double limit = 0) : BankAccount(accNo, bal) {
        overdraftLimit = limit;
    }
    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            lastTransaction = -amount;
            cout << "Withdrawn: " << amount << endl;
        } else {
            cout << "Limit Exceeded!" << endl;
        }
    }
};

int main() {
    int choice;
    cout << "Select Account Type:\n1. Savings Account\n2. Current Account\nEnter choice: ";
    cin >> choice;

    int accNo;
    double bal;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Initial Balance: ";
    cin >> bal;

    if (choice == 1) {
        double rate;
        cout << "Enter Interest Rate (%): ";
        cin >> rate;

        SavingsAccount sa(accNo, bal, rate);
        int op;
        do {
            cout << "\n1. Deposit\n2. Withdraw\n3. Add Interest\n4. Undo Last Transaction\n5. Display\n0. Exit\nEnter operation: ";
            cin >> op;
            double amount;
            switch (op) {
                case 1: cout << "Enter amount: "; cin >> amount; sa.deposit(amount); break;
                case 2: cout << "Enter amount: "; cin >> amount; sa.withdraw(amount); break;
                case 3: sa.addInterest(); break;
                case 4: sa.undoLastTransaction(); break;
                case 5: sa.display(); break;
            }
        }
         while(op != 0);

    }
     else if (choice == 2) {
        double limit;
        cout << "Enter Overdraft Limit: ";
        cin >> limit;

        CurrentAccount ca(accNo, bal, limit);
        int op;
        do {
            cout << "\n1. Deposit\n2. Withdraw\n3. Undo Last Transaction\n4. Display\n0. Exit\nEnter operation: ";
            cin >> op;
            double amount;
            switch (op) {
                case 1:
                     cout << "Enter amount: "; cin >> amount; ca.deposit(amount);
                     break;
                case 2:
                     cout << "Enter amount: "; cin >> amount; ca.withdraw(amount);
                     break;
                case 3:
                    ca.undoLastTransaction();
                    break;
                case 4:
                     ca.display();
                      break;
            }
        } while(op != 0);

    } else {
        cout << "Invalid choice!" << endl;
    }
 cout << "\n24CE060_POOJA\n";
    return 0;
}

