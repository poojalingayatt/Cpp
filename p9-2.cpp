/* Programmer: Pooja Lingayat
   Date: 9-05-25
   Aim: Create a basic banking system with error handling and transaction logging.
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX_LOGS = 100;

struct Transaction
{
    string type;
    double amount;
    string status;
};

class BankAccount
{
    string name;
    int accountNumber;
    double balance;
    Transaction log[MAX_LOGS];
    int logCount;

public:
    BankAccount(string n, int accNo, double initialBalance)
    {
        name = n;
        accountNumber = accNo;
        balance = initialBalance;
        logCount = 0;
    }

    void deposit(double amount)
    {
        if (amount <= 0)
        {
            logTransaction("Deposit", amount, "Failed - Invalid Amount");
            cout << "Deposit failed: Amount must be positive.\n";
            return;
        }
        balance += amount;
        logTransaction("Deposit", amount, "Success");
        cout << "Deposited: Rs." << amount << endl;
    }

    void withdraw(double amount)
    {
        if (amount <= 0)
        {
            logTransaction("Withdraw", amount, "Failed - Invalid Amount");
            cout << "Withdrawal failed: Amount must be positive.\n";
            return;
        }
        if (amount > balance)
        {
            logTransaction("Withdraw", amount, "Failed - Insufficient Balance");
            cout << "Withdrawal failed: Insufficient balance.\n";
            return;
        }
        balance -= amount;
        logTransaction("Withdraw", amount, "Success");
        cout << "Withdrawn: Rs." << amount << endl;
    }

    void logTransaction(string type, double amount, string status)
    {
        if (logCount < MAX_LOGS)
        {
            log[logCount++] = {type, amount, status};
        }
    }

    void printTransactionLog()
    {
        cout << "\n--- Transaction Log ---\n";
        for (int i = 0; i < logCount; ++i)
        {
            cout << log[i].type << " Rs." << log[i].amount << " - " << log[i].status << endl;
        }
    }

    void displayBalance()
    {
        cout << "\nCurrent Balance: Rs." << balance << endl;
    }
};

int main()
{
    BankAccount acc("Pooja Lingayat", 1001, 5000);

    acc.deposit(2000);
    acc.withdraw(1000);
    acc.withdraw(10000);  // Error case
    acc.deposit(-500);    // Error case

    acc.displayBalance();
    acc.printTransactionLog();

    cout << "\n24CE060_POOJA\n";
    return 0;
}

