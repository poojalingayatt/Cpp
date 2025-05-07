/* Programmer: Pooja Lingayat
   Date: -05-25
   Aim:To design a data processing system that filters out duplicate transaction IDs from large datasets using an associative container
   to ensure uniqueness and maintain sorted order. */

#include <iostream>
#include <set>
#include <iterator>

using namespace std;

int main()
{
    int n;

    // Ask for number of transactions
    cout << "Enter the number of transaction IDs: ";
    cin >> n;

    set<int> uniqueTransactions;  // Set to store unique transaction IDs

    cout << "Enter the transaction IDs: ";

    // Read transaction IDs and insert them into the set
    for (int i = 0; i < n; ++i)
    {
        int transactionID;
        cin >> transactionID;
        uniqueTransactions.insert(transactionID);  // Duplicates will be automatically removed
    }

    // Display the unique transaction IDs in sorted order
    cout << "\nUnique Transaction IDs: ";
    for (auto it = uniqueTransactions.begin(); it != uniqueTransactions.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
cout << "\n24CE060_POOJA\n";
    return 0;
}

