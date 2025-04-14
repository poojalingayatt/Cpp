#include <iostream>
#include <string>
using namespace std;

int sumOfDigits(int num)
 {
    int sum = 0;
    while (num > 0) 
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int superDigit(int num) {
    if (num < 10) 
        return num;
    return superDigit(sumOfDigits(num));
}

int sum( string& n, int k)
 {
    int  sum = 0;
    for (int i = 0; i < n.length(); i++)
    {
    sum += (n[i] - '0');
    }
    int totalSum = sum * k;
    return superDigit(totalSum);
}

int main() {
    string n;
    int k;
    cout << "Enter the number n: ";
    cin >> n;
    cout << "Enter the number of times k: ";
    cin >> k;
    int result = sum(n, k);
    cout << "The super digit is: " << result << endl;
    return 0;
}
