#include<iostream>
using namespace std;

class Calculator {
public:
    // Add two integers
    int add(int a, int b)
     {
        return a + b;
    }

    // Add two floats
    float add(float a, float b)
    {
        return a + b;
    }

    // Add an int and a float
    float add(int a, float b)
     {
        return a + b;
    }

    // Add a float and an int
    float add(float a, int b)
    {
        return a + b;
    }
};

int main()
 {
    Calculator calc;

    int result1 = calc.add(5, 10);                // int + int
    float result2 = calc.add(5.5f, 3.3f);         // float + float
    float result3 = calc.add(7, 2.5f);            // int + float
    float result4 = calc.add(3.7f, 4);            // float + int

    // Display Results
    cout << "5 + 10 = " << result1 << endl;
    cout << "5.5 + 3.3 = " << result2 << endl;
    cout << "7 + 2.5 = " << result3 << endl;
    cout << "3.7 + 4 = " << result4 << endl;

     cout << "\n24CE060_POOJA\n";
    return 0;
}

