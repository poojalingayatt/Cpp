/* Programmer: Pooja Lingayat
   Date: 18-4-25
   Aim: To implement static and dynamic memory management for calculating the area of circles using OOP and vectors in C++. */
#include <iostream>
#include <vector>
#define PI 3.14159

using namespace std;

// Base class: Shape
class Shape
{
protected:
    double radius;
public:
    void setRadius(double r)
    {
        radius = r;
    }
};

// Derived class: Circle
class Circle : public Shape
{
public:
    double calculateArea()
    {
        return PI * radius * radius;
    }
};

// Function to manage circles dynamically (using vector)
void dynamicCircles()
{
    int n;
    cout << "Enter number of circles: ";
    cin >> n;

    vector<Circle> circles; // Dynamic storage
    for (int i = 0; i < n; i++)
    {
        double r;
        cout << "Enter radius for Circle " << (i + 1) << ": ";
        cin >> r;

        Circle c;          // Create a Circle object
        c.setRadius(r);    // Set its radius
        circles.push_back(c); // Store it in vector
    }

    cout << "\nCircle Areas (Dynamic Storage):\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Circle " << (i + 1) << ": " << circles[i].calculateArea() << "\n";
    }
}


// Function to manage circles statically (using array)
void staticCircles()
  {
    Circle circles[3];

    for (int i = 0; i < 3; i++)
    {
        double r;
        cout << "Enter radius for Circle " << (i + 1) << ": ";
        cin >> r;
        circles[i].setRadius(r);
    }

    cout << "\nCircle Areas (Static Storage):\n";
    for (int i = 0; i < 3; i++) {
        cout << "Circle " << (i + 1) << ": " << circles[i].calculateArea() << "\n";
    }
}

int main()
 {
    int choice;
    cout << "Choose storage method:\n1. Dynamic (Vector)\n2. Static (Array)\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
        dynamicCircles();

    else if (choice == 2)
        staticCircles();

    else
        cout << "Invalid choice!\n";

        cout << "\n24CE060_POOJA\n";
    return 0;
}

