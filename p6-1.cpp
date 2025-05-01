/* Programmer: Pooja Lingayat
   Date: -4-25
   Aim: To implement a dynamic array using OOP concepts without using STL, supporting insertion, deletion, and access operations */

#include <iostream>
using namespace std;

// Class to implement a dynamic array without using STL
class DynamicArray
{
private:
    int* data;       // Pointer to the actual array in heap
    int size;
    int capacity;

public:
    // Constructor: initializes array with a given initial capacity
    DynamicArray(int init_capacity = 10)
    {
        data = new int[init_capacity]; // Allocate memory
        size = 0;
        capacity = init_capacity;
    }

    // Destructor: releases allocated memory to prevent memory leaks
    ~DynamicArray()
    {
        delete[] data;
    }

    // Function to insert a new element at the end of the array
    void insert(int value)
    {
        // If array is full, resize it to double the capacity
        if (size == capacity)
            resize();

        data[size++] = value; // Insert value and increase size
    }

    // Function to remove an element at a specific index
    void remove(int index)
    {
        if (index < 0 || index >= size)
        {
            cout << "Invalid index for removal.\n";
            return;
        }

        // Shift elements to left to fill the gap
        for (int i = index; i < size - 1; ++i)
        {
            data[i] = data[i + 1];
        }

        --size; // Reduce size count
    }

    // Function to get an element at a specific index
    int get(int index) const
    {
        // Check for invalid index
        if (index < 0 || index >= size)
        {
            cout << "Invalid index for get.\n";
            return -1; // Return dummy value
        }

        return data[index];
    }

    // Function to get the current number of elements
    int getSize() const
    {
        return size;
    }

    // Function to display the entire array (for testing)
    void display() const {
        cout << "Array elements: ";
        for (int i = 0; i < size; ++i) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

private:
    // Function to resize the array when full
    void resize()
    {
        capacity *= 2; // Double the capacity
        int* newData = new int[capacity]; // Allocate new memory

        // Copy old data to new array
        for (int i = 0; i < size; ++i)
            newData[i] = data[i];

        delete[] data;  // Free old memory
        data = newData; // Update pointer
    }
};

int main()
{
    DynamicArray arr;

    // Insert elements
    arr.insert(10);
    arr.insert(20);
    arr.insert(30);
    arr.insert(40);

    // Display current array
    arr.display();  // Output: 10 20 30 40

    // Remove element at index 1 (value 20)
    arr.remove(1);
    arr.display();  // Output: 10 30 40

    // Get element at index 1
    cout << "Element at index 1: " << arr.get(1) << endl;  // Output: 30

    // Current size of array
    cout << "Current size: " << arr.getSize() << endl;  // Output: 3
    cout << "\n24CE060_POOJA\n";
    return 0;
}
