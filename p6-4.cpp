/* Programmer: Pooja Lingayat
   Date: 11-04-25
   Aim: To demonstrate the need for virtual destructors in inheritance for correct memory deallocation.
*/

#include <iostream>
using namespace std;

// Base class with virtual destructor
class Base
{
public:
    Base()
    {
        cout << "Base constructor called\n";
    }

    // Virtual destructor ensures derived class destructor is called
    virtual ~Base()
    {
        cout << "Base destructor called\n";
    }
};

// Derived class with dynamic memory allocation
class Derived : public Base
{
private:
    int* data;

public:
    Derived()
    {
        data = new int[5];  // Dynamic resource allocation
        cout << "Derived constructor called (allocated memory)\n";
    }

    ~Derived()
    {
        delete[] data;  // Free memory
        cout << "Derived destructor called (freed memory)\n";
    }
};

int main()
{
    // Create object using base class pointer
    Base* obj = new Derived();

    // Delete using base class pointer (calls both destructors if virtual)
    delete obj;

     cout << "\n24CE060_POOJA\n";
    return 0;
}

