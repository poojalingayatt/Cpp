/* Programmer: Pooja Lingayat
   Date: 9-05-25
   Aim: Create a basic banking system with error handling and transaction logging.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;
    vector<string> transactions;  // Using vector instead of raw pointer

    void logTransaction(const string& log) {
        transactions.push_back(log);
    }

public:
    BankAccount(const string& name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
        logTransaction("Deposited: ₹" + to_string(amount));
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient balance.");
        }
        balance -= amount;
        logTransaction("Withdrew: ₹" + to_string(amount));
    }

    void displayBalance() const {
        cout << "Current Balance: ₹" << balance << endl;
    }

    void showTransactionHistory() const {
        cout << "\nTransaction History for " << accountHolder << ":\n";
        if (transactions.empty()) {
            cout << "No transactions yet.\n";
        } else {
            for (size_t i = 0; i < transactions.size(); ++i) {
                cout << i + 1 << ". " << transactions[i] << endl;
            }
        }
    }
};

int main() {
    string name;
    double initialBalance;

    cout << "Enter account holder's name: ";
    getline(cin, name);

    cout << "Enter initial balance: ₹";
    cin >> initialBalance;

    BankAccount account(name, initialBalance);

    int choice;
    double amount;

    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Show Balance\n4. Show Transaction History\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
                case 1:
                    cout << "Enter deposit amount: ₹";
                    cin >> amount;
                    account.deposit(amount);
                    break;
                case 2:
                    cout << "Enter withdrawal amount: ₹";
                    cin >> amount;
                    account.withdraw(amount);
                    break;
                case 3:
                    account.displayBalance();
                    break;
                case 4:
                    account.showTransactionHistory();
                    break;
                case 5:
                    cout << "Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (choice != 5);
   
    cout << "\n24CE060_POOJA\n";
    return 0;
}

