/* Programmer: Pooja Lingayat
   Date: 28-4-25
   Aim: Reverse a sequence of integers using both std::reverse and manual iteration approaches.*/

#include <iostream>
#include <vector>
#include <algorithm> // for std::reverse

using namespace std;

// Approach 1: Using std::reverse function
void reverseUsingStdReverse(vector<int>& numbers)
{
    // Reverse using std::reverse
    std::reverse(numbers.begin(), numbers.end());
}

// Approach 2: Manually reversing using iterators
void reverseUsingIterators(vector<int>& numbers)
{
    auto start = numbers.begin();
    auto end = numbers.end() - 1;

    while (start < end)
    {
        // Swap the elements
        swap(*start, *end);
        ++start;
        --end;
    }
}

int main()
 {
    int n;
    cout << "Enter the number of elements in the sequence: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter the sequence of " << n << " numbers: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    // Display original sequence
    cout << "\nOriginal sequence: ";
    for (int num : numbers)
    {
        cout << num << " ";
    }

    // Approach 1: Reverse using std::reverse
    reverseUsingStdReverse(numbers);
    cout << "\nReversed using std::reverse: ";
    for (int num : numbers)
    {
        cout << num << " ";
    }

    // Restore the original sequence
    reverseUsingStdReverse(numbers); // Reversing again to get the original sequence

    // Approach 2: Reverse manually using iterators
    reverseUsingIterators(numbers);
    cout << "\nReversed manually using iterators: ";
    for (int num : numbers)
    {
        cout << num << " ";
    }

    cout << endl;
    cout << "\n24CE060_POOJA\n";
    return 0;
}

