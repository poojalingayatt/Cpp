/* Programmer: Pooja Lingayat
   Date: 7-04-25
   Aim: To design a class that supports dynamic repositioning of points on a coordinate plane using user input, method chaining, and pointer-based manipulation.
*/

#include <iostream>
using namespace std;

// Class representing a point in 2D space
class Point
{
private:
    int x, y;

public:
    // Constructor to initialize point coordinates
    Point(int x_val = 0, int y_val = 0)
    {
        x = x_val;
        y = y_val;
    }

    // Function to move the point by dx and dy (supports method chaining)
    Point* moveBy(int dx, int dy)
    {
        x += dx;
        y += dy;
        return this;
    }

    // Function to display current coordinates
    void display() const
    {
        cout << "Current Coordinates: (" << x << ", " << y << ")\n";
    }
};

int main()
{
    int x, y, n, dx, dy;

    // Get initial coordinates from user
    cout << "Enter initial coordinates (x y): ";
    cin >> x >> y;

    // Create Point object using pointer
    Point* p = new Point(x, y);

    // Ask how many movements to perform
    cout << "Enter number of movements: ";
    cin >> n;

    // Apply each movement with chaining
    for (int i = 1; i <= n; ++i) {
        cout << "Enter dx and dy for movement " << i << ": ";
        cin >> dx >> dy;
        p->moveBy(dx, dy);
    }

    // Display final position
    p->display();

    // Free allocated memory
    delete p;
     cout << "\n24CE060_POOJA\n";
    return 0;
}
