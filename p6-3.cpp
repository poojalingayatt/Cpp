/* Programmer: Pooja Lingayat
   Date: 11-04-25
   Aim: To merge two dynamically-sized sorted arrays into a single sorted array using manual memory management.
*/

#include <iostream>
using namespace std;

// Function to merge two sorted arrays into a new sorted array
int* mergeSortedArrays(int* arr1, int size1, int* arr2, int size2, int& mergedSize)
 {
    mergedSize = size1 + size2;
    int* merged = new int[mergedSize]; // Allocate memory for merged array

    int i = 0, j = 0, k = 0;

    // Merge both arrays in sorted order
    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    // Copy remaining elements (if any)
    while (i < size1)
        merged[k++] = arr1[i++];

    while (j < size2)
        merged[k++] = arr2[j++];

    return merged;
}

int main()
 {
    int size1, size2;

    // Input sizes of both arrays
    cout << "Enter size of first sorted array: ";
    cin >> size1;
    int* arr1 = new int[size1];

    cout << "Enter " << size1 << " sorted elements:\n";
    for (int i = 0; i < size1; ++i)
        cin >> arr1[i];

    cout << "Enter size of second sorted array: ";
    cin >> size2;
    int* arr2 = new int[size2];

    cout << "Enter " << size2 << " sorted elements:\n";
    for (int i = 0; i < size2; ++i)
        cin >> arr2[i];

    // Merge arrays
    int mergedSize;
    int* mergedArray = mergeSortedArrays(arr1, size1, arr2, size2, mergedSize);

    // Output merged sorted array
    cout << "Merged sorted array:\n";
    for (int i = 0; i < mergedSize; ++i)
        cout << mergedArray[i] << " ";
    cout << endl;

    // Free allocated memory
    delete[] arr1;
    delete[] arr2;
    delete[] mergedArray;

     cout << "\n24CE060_POOJA\n";
    return 0;
}

