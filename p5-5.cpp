#include<iostream>
#include<cmath>
using namespace std;

class Rectangle
 {
    float length, width;
public:
    void input()
    {
        cout << "Enter length and width: ";
        cin >> length >> width;
    }
    float Area()
    {
        return length * width;
    }
};

class Circle {
    float radius;
public:
    void input()
    {
        cout << "Enter radius: ";
        cin >> radius;
    }
    float Area() {
        return M_PI * radius * radius;
    }
};

int main()
{
    int n;
    cout << "Enter number of shapes: ";
    cin >> n;

    Rectangle rectangles[100];
    Circle circles[100];

    int rectCount = 0, circleCount = 0;

    for (int i = 0; i < n; i++)
    {
        int type;
        cout << "\nSelect shape type (1-Rectangle, 2-Circle): ";
        cin >> type;

        if (type == 1) {
            rectangles[rectCount].input();
            rectCount++;
        }
        else if (type == 2) {
            circles[circleCount].input();
            circleCount++;
        }
        else {
            cout << "Invalid choice!" << endl;
            i--;
        }
    }

    cout << "\n----- Shape Areas -----\n";

    for (int i = 0; i < rectCount; i++)
    {
        cout << "Rectangle Area: " << rectangles[i].Area() << endl;
    }
    for (int i = 0; i < circleCount; i++)
    {
        cout << "Circle Area: " << circles[i].Area() << endl;
    }

    cout << "\n24CE060_POOJA\n";
    return 0;
}

