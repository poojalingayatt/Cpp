/* Programmer: Pooja Lingayat
   Date:--25
   Aim: To create a bank account management system */

#include<iostream>
#include<string>
using namespace std;

class BankAccounts
{
    // Private data members to store account details
    string Name;      // Account holder's name
    int AccNumber;    // Unique account number
    double Balance;   // Account balance

public:
    // Default constructor to initialize with test data
    BankAccounts()
    {
        Name = "Test Case";
        AccNumber = 0;
        Balance = 0.0;
    }

    // Parameterized constructor to initialize with specific values
    BankAccounts(int accnum, string name, double accbalance)
    {
        Name = name;
        AccNumber = accnum;
        Balance = accbalance;
    }

    // Function to display account details
    void Displaydetails()
    {
        cout << "Your details are as follows:" << endl;
        cout << "Account Holder's Name: " << Name << endl;
        cout << "Account Number: " << AccNumber << endl;
        cout << "Account's current Balance: " << Balance << endl;
    }

    // Function to deposit money into the account
    void DepositMoney(double Amount)
    {
        if (Amount > 0)
        {
            Balance += Amount; // Increase balance by deposit amount
            cout << Amount << " deposited successfully" << endl;
            cout << "New Balance is: " << Balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Function to withdraw money from the account
    void WithdrawMoney(double Amount)
    {
        if (Amount > 0 && Amount <= Balance)
        {
            Balance -= Amount; // Decrease balance by withdrawal amount
            cout << Amount << " withdrawn successfully" << endl;
            cout << "New Balance is: " << Balance << endl;
        }
        else if (Amount > Balance)
        {
            cout << "Not enough money to withdraw" << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount." << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter number of Accounts to be created: ";
    cin >> n;
    BankAccounts Account[n]; // Create an array of BankAccounts

    string name;    // Variable to store the account holder's name
    int number;     // Variable to store the account number
    double balance; // Variable to store the initial balance

    for (int i = 0; i < n; i++)
    {
        // Collect account details from the user
        cout << "\nEnter your Account Details or Enter 0 to set default values:" << endl;
        cout << "Enter Account Number: ";
        cin >> number;

        if (number == 0)
        {
            Account[i] = BankAccounts();
            cout << "Default record added." << endl;
        }
        else
        {
            cout << "Enter Account Holder's Name: ";
            cin >> name;

            cout << "\nEnter Account's Balance: ";
            cin >> balance;

            Account[i] = BankAccounts(number, name, balance);
        }
    }

    double Amt = 0; // Variable to store deposit/withdrawal amount
    int choice;      // Variable to store user choice

    // Menu-driven interface for user interaction
    do
    {
        cout << "\nEnter (1) to view all account details" << endl;
        cout << "Enter (2) to Deposit Money" << endl;
        cout << "Enter (3) to Withdraw Money" << endl;
        cout << "Enter (4) to exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                Account[i].Displaydetails();
            }
            break;

        case 2:
            cout << "Enter the amount to be deposited: ";
            cin >> Amt;
            for (int i = 0; i < n; i++)
            {
                Account[i].DepositMoney(Amt);
            }
            break;

        case 3:
            cout << "Enter the amount to be withdrawn: ";
            cin >> Amt;
            for (int i = 0; i < n; i++)
            {
                Account[i].WithdrawMoney(Amt);
            }
            break;

        case 4:
            cout << "Exiting the System" << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4); // Continue until user chooses to exit

    cout << "\n24CE060_POOJA\n";
    return 0;
}
