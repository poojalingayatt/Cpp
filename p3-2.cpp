/* Programmer: Pooja Lingayat
   Date:17-2-25
   Aim: To compare recursive and iterative approaches for calculating the sum of an array */

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to calculate sum
int recursiveSum(const vector<int>& arr, int n)
 {
    if (n == 0) return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
 }

// Iterative function to calculate sum
int iterativeSum(const vector<int>& arr, int n)
 {
    int total = 0;
     for (int i = 0; i<n; i++)
    {
        total += arr[i];
    }
    return total;

}

int main()
 {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr;
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        arr.push_back(value);
    }

    // Compute recursive sum
    int recursiveResult = recursiveSum(arr, n);
    cout << "Recursive Sum: " << recursiveResult << endl;

    // Compute iterative sum
    int iterativeResult = iterativeSum(arr,n);
    cout << "Iterative Sum: " << iterativeResult << endl;
cout << "\n24CE060_POOJA\n";
    return 0;
}
