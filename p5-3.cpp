/* Programmer: Pooja Lingayat
   Date: 24-3-25
   Aim: To overload unary and binary operators in C++ for a Point class (negation, addition, and comparison). */

#include<iostream>
using namespace std;

class Point
{
private:
    int x, y;

public:
    // Constructor
    Point(int x = 0, int y = 0)
     {
        this->x = x;
        this->y = y;
    }

    // Overload unary - to negate the point
    Point operator- ()
    {
        return Point(-x, -y);
    }

    // Overload + to add two points
    Point operator+ (const Point& p)
     {
        return Point(x + p.x, y + p.y);
    }

    // Overload == to compare two points
    bool operator== (const Point& p)
    {
        return (x == p.x && y == p.y);
    }

    // Display point
    void display() {
        cout << "(" << x << ", " << y << ")";
    }
};

int main()
 {
    Point p1(3, 4), p2(1, 2), result;

    // Add points
    result = p1 + p2;
    cout << "p1 + p2 = ";
    result.display();
    cout << endl;

    // Negate point
    result = -p1;
    cout << "-p1 = ";
    result.display();
    cout << endl;

    // Compare points
    if (p1 == p2)
        cout << "p1 and p2 are equal." << endl;
    else
        cout << "p1 and p2 are not equal." << endl;

        cout << "\n24CE060_POOJA\n";
    return 0;
}

