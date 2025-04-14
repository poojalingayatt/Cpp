/* Programmer: Pooja Lingayat
   Date: --25
   Aim: To create an inventory management system */

#include<iostream>
#include<string>
using namespace std;

// Class to represent a product in the inventory
class Product
{
    int PId, PStock;            // Product ID and available stock
    string PName;               // Product name
    float Price;                // Product price

public:
    // Default constructor to initialize product with test data
    Product()
    {
        PId = 0;
        PStock = 0;
        PName = "Test Case";
        Price = 0.0;
    }

    // Parameterized constructor to initialize product with specific values
    Product(int id, int stock, string name, float price)
    {
        PId = id;
        PStock = stock;
        PName = name;
        Price = price;
    }

    // Function to display product details
    void Displaydetails()
    {
        cout << "Product ID: " << PId << endl;
        cout << "Product Name: " << PName << endl;
        cout << "Product Price: " << Price << endl;
        cout << "Available Product Stock: " << PStock << endl;
    }

    // Function to get product ID
    int getId()
    {
        return PId;
    }

    // Function to add stock to the product
    void AddStock(int quantity)
    {
        if (quantity > 0)
        {
            PStock += quantity; // Increase stock by given quantity
            cout << quantity << " of " << PName << " added successfully" << endl;
            cout << "The new Stock is: " << PStock << endl;
        }
        else
        {
            cout << "Invalid quantity to add." << endl;
        }
    }

    // Function to sell the product and reduce stock
    void SellProduct(int quantity)
    {
        if (quantity > 0 && quantity <= PStock)
        {
            PStock -= quantity; // Decrease stock by sold quantity
            cout << quantity << " of " << PName << " sold successfully" << endl;
            cout << "The new Stock is: " << PStock << endl;
        }
        else if (quantity > PStock)
        {
            cout << "Insufficient stock available." << endl;
        }
        else
        {
            cout << "Invalid quantity to sell." << endl;
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of inventory items to be created: ";
    cin >> n;

    Product items[n]; // Array to store multiple inventory items

    // Loop to initialize product details
    for (int i = 0; i < n; i++) {
        int id, stock;
        string name;
        float price;

        cout << "\nEnter details for Item " << (i + 1) << ":" << endl;
        cout << "Enter Item ID (or 0 for default): ";
        cin >> id;

        if (id == 0)
        {
            items[i] = Product(); // Use default constructor
            cout << "Default item record added." << endl;
        }
        else
        {
            cout << "Enter Item Name: ";
            cin >> name;
            cout << "Enter Item Price: ";
            cin >> price;
            cout << "Enter Available Stock: ";
            cin >> stock;

            items[i] = Product(id, stock, name, price); // Use parameterized constructor
        }
    }

    int choice, qty, product_id;

    // Menu-driven interface for user interaction
    do {
        cout << "\nEnter (1) to View Inventory" << endl;
        cout << "Enter (2) to Add Stock" << endl;
        cout << "Enter (3) to Sell Items" << endl;
        cout << "Enter (4) to Exit" << endl;
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            // Display details of all products
            for (int i = 0; i < n; i++)
            {
                items[i].Displaydetails();
            }
            break;

        case 2:
            // Add stock to a specific product
            cout << "Enter Product ID: ";
            cin >> product_id;
            cout << "Enter quantity to add: ";
            cin >> qty;

            for (int i = 0; i < n; i++)
            {
                if (items[i].getId() == product_id)
                {
                    items[i].AddStock(qty);
                    break;
                }
                if (i == n - 1)
                    cout << "Invalid product id." << endl;
            }
            break;

        case 3:
            // Sell stock from a specific product
            cout << "Enter Product ID: ";
            cin >> product_id;
            cout << "Enter quantity to sell: ";
            cin >> qty;

            for (int i = 0; i < n; i++)
            {
                if (items[i].getId() == product_id)
                {
                    items[i].SellProduct(qty);
                    break;
                }
                if (i == n - 1)
                    cout << "Invalid product id." << endl;
            }
            break;

        case 4:
            cout << "Exiting the system." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4); // Continue until user chooses to exit

    cout << "\n24CE060_POOJA\n";
    return 0;
}
