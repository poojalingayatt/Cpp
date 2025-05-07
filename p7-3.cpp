/* Programmer: Pooja Lingayat
   Date: 05-25
   Aim: To implement a basic inventory management system with add, view, and search operations using file storage.*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

struct Product
{
    string name;
    int quantity;
    float price;
};

// Function to add a new product
void addProduct()
{
    Product p;
    cout << "Enter product name: ";
    getline(cin, p.name);

    cout << "Enter quantity: ";
    cin >> p.quantity;

    cout << "Enter price: ";
    cin >> p.price;
    cin.ignore(); // To ignore the newline character left by cin

    ofstream fout("inventory.txt", ios::app);
    if (!fout)
    {
        cout << "Error opening file.\n";
        return;
    }

    fout << p.name << "," << p.quantity << "," << p.price << "\n";
    fout.close();
    cout << "Product added successfully.\n";
}

// Function to view all products
void viewInventory()
{
    ifstream fin("inventory.txt");
    if (!fin)
    {
        cout << "No inventory file found.\n";
        return;
    }

    cout << "\n--- Inventory ---\n";
    string line;
    while (getline(fin, line))
    {
        stringstream ss(line);
        string name;
        string qty;
        string price;

        getline(ss, name, ',');
        getline(ss, qty, ',');
        getline(ss, price, ',');

        cout << "Name: " << name << ", Quantity: " << qty << ", Price: " << price << "\n";
    }
    fin.close();
}

// Function to search a product by name
void searchProduct()
{
    string target;
    cout << "Enter product name to search: ";
    getline(cin, target);

    ifstream fin("inventory.txt");
    if (!fin)
    {
        cout << "No inventory file found.\n";
        return;
    }

    string line;
    bool found = false;
    while (getline(fin, line))
    {
        stringstream ss(line);
        string name;
        string qty;
        string price;

        getline(ss, name, ',');

        if (name == target)
        {
            getline(ss, qty, ',');
            getline(ss, price, ',');

            cout << "Product found:\n";
            cout << "Name: " << name << ", Quantity: " << qty << ", Price: " << price << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Product not found.\n";

    fin.close();
}

int main()
{
    int choice;
    do
    {
        cout << "\n--- Inventory Menu ---\n";
        cout << "1. Add Product\n2. View Inventory\n3. Search Product\n4. Exit\nEnter choice: ";
        cin >> choice;
        cin.ignore();  // To ignore the newline character after entering the choice

        switch (choice)
        {
            case 1: addProduct(); break;
            case 2: viewInventory(); break;
            case 3: searchProduct(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    cout << "\n24CE060_POOJA\n";
    return 0;
}
