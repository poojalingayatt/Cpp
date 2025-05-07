/* Programmer: Pooja Lingayat
   Date: 21-3-25
   Aim: To implement operator overloading in C++ for complex number addition, subtraction, input, and output. */

#include<iostream>
using namespace std;

class Complex
{
private:
    float real;
    float imag;

public:
    // Constructor to initialize the complex number
    Complex(float r = 0, float i = 0)
    {
        real = r;
        imag = i;
    }

    // Overload the + operator for complex addition
    Complex operator + (const Complex& obj)
    {
        return Complex(real + obj.real, imag + obj.imag);
    }

    // Overload the - operator for complex subtraction
    Complex operator - (const Complex& obj)
    {
        return Complex(real - obj.real, imag - obj.imag);
    }

    // Overload the << operator for output
    friend ostream& operator << (ostream& out, const Complex& obj)
    {
        out << obj.real << " + " << obj.imag << "i";
        return out;
    }

    // Overload the >> operator for input
    friend istream& operator >> (istream& in, Complex& obj)
    {
        cout << "Enter real part: ";
        in >> obj.real;
        cout << "Enter imaginary part: ";
        in >> obj.imag;
        return in;
    }
};

int main()
{
    Complex num1, num2, result;

    // Take input for two complex numbers
    cout << "Enter first complex number:\n";
    cin >> num1;

    cout << "Enter second complex number:\n";
    cin >> num2;

    // Perform addition and subtraction
    result = num1 + num2;
    cout << "Addition of the two complex numbers: " << result << endl;

    result = num1 - num2;
    cout << "Subtraction of the two complex numbers: " << result << endl;

    cout << "\n24CE060_POOJA\n";
    return 0;
}

