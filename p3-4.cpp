#include <iostream>
#include <string>
using namespace std;

// Function to calculate the sum of digits of a given number
int sumOfDigits(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;  // Add the last digit to sum
        num /= 10;        // Remove the last digit
    }
    return sum;
}

// Recursive function to calculate the super digit
int superDigit(int num)
{
    if (num < 10)        // Base case: if number is a single digit, return it
        return num;
    return superDigit(sumOfDigits(num));  // Recursively call with sum of digits
}

// Function to compute the initial sum of digits of string n, multiply it by k, and find its super digit
int sum(string& n, int k)
{
    int sum = 0;
    // Calculate the sum of digits in the string n
    for (int i = 0; i < n.length(); i++)
    {
        sum += (n[i] - '0');  // Convert character to integer and add
    }
    int totalSum = sum * k;        // Multiply the sum by k
    return superDigit(totalSum);   // Find and return the super digit
}

int main()
{
    string n;   // String to hold the number input
    int k;      // Number of times to repeat the string number

    // Taking inputs from the user
    cout << "Enter the number n: ";
    cin >> n;
    cout << "Enter the number of times k: ";
    cin >> k;

    // Call the sum function to compute the super digit and store the result
    int result = sum(n, k);

    // Display the result
    cout << "The super digit is: " << result << endl;

    return 0;
}
