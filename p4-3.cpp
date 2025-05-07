/* Programmer: Pooja Lingayat
   Date: 3-3-25
   Aim: To implement multiple inheritance by managing car details using separate base classes for fuel type and brand name. */

#include<iostream>
#include<string>
using namespace std;

// Base class for fuel type
class Fuel
{
protected:
    string fuelType;
public:
    Fuel(string fuel = "")
    {
        fuelType = fuel;
    }
    void displayFuel() 
    {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// Base class for brand name
class Brand
{
protected:
    string brandName;
public:
    Brand(string brand = "") 
{
        brandName = brand;
    }
    void displayBrand() 
    {
        cout << "Brand Name: " << brandName << endl;
    }
};

// Derived class combining Fuel and Brand
class Car : public Fuel, public Brand 
{
public:
    Car(string fuel = "", string brand = "") : Fuel(fuel), Brand(brand) {}
    void displayCar()
   {
        displayBrand();
        displayFuel();
    }
};

int main()
  {
    int n;
    cout << "Enter number of cars in service queue: ";
    cin >> n;

    Car cars[100];  // fixed size array, assuming max 100 cars

    for (int i = 0; i < n; i++) 
    {
        string fuel, brand;

        cout << "\nEnter details for Car " << i + 1 << ":" << endl;
        cout << "Enter Fuel Type: ";
        cin.ignore();
        getline(cin, fuel);

        cout << "Enter Brand Name: ";
        getline(cin, brand);

        cars[i] = Car(fuel, brand);
    }

    cout << "\n--- Service Queue Details ---\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nCar " << i + 1 << " Details:" << endl;
        cars[i].displayCar();
    }
 cout << "\n24CE060_POOJA\n";
    return 0;
}
