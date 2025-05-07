/* Programmer: Pooja Lingayat
   Date: 24-3-25
   Aim: To implement conversion between Celsius and Fahrenheit using classes and check equality of temperatures. */

#include<iostream>
using namespace std;

class Fahrenheit; // Forward declaration

class Celsius
{
private:
    float tempC;

public:
    Celsius(float t = 0)
    {
        tempC = t;
    }

    // Convert Celsius to Fahrenheit
    Fahrenheit toFahrenheit();

    // Getter
    float getTemp()
    {
        return tempC;
    }

    // Compare with Fahrenheit
    bool isEqual(Fahrenheit f);
};

class Fahrenheit
 {
private:
    float tempF;

public:
    Fahrenheit(float t = 0)
    {
        tempF = t;
    }

    // Convert Fahrenheit to Celsius
    Celsius toCelsius()
    {
        return Celsius((tempF - 32) * 5 / 9);
    }

    // Getter
    float getTemp()
    {
        return tempF;
    }

    // Compare with Celsius
    bool isEqual(Celsius c)
    {
        return (tempF == (c.getTemp() * 9 / 5 + 32));
    }
};

// Celsius to Fahrenheit conversion implementation
Fahrenheit Celsius::toFahrenheit()
{
    return Fahrenheit(tempC * 9 / 5 + 32);
}

// Celsius == Fahrenheit
bool Celsius::isEqual(Fahrenheit f)
{
    return (tempC == (f.getTemp() - 32) * 5 / 9);
}

int main()
 {
    Celsius c1(37);
    Fahrenheit f1(98.6);

    // Convert Celsius to Fahrenheit
    Fahrenheit f2 = c1.toFahrenheit();
    cout << "Celsius to Fahrenheit: " << f2.getTemp() << "°F" << endl;

    // Convert Fahrenheit to Celsius
    Celsius c2 = f1.toCelsius();
    cout << "Fahrenheit to Celsius: " << c2.getTemp() << "°C" << endl;

    // Compare
    if (c1.isEqual(f1))
        cout << "Both temperatures are equal." << endl;
    else
        cout << "Temperatures are not equal." << endl;

    cout << "\n24CE060_POOJA\n";
    return 0;
}
