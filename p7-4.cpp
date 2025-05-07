/* Programmer: Pooja Lingayat
   Date: -05-25
   Aim: Generate student performance reports from file data with formatted tabular output using manipulators.*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string> // Using string instead of char arrays
using namespace std;

// Custom manipulator to set fixed column width
ostream& tab(ostream& os)
{
    return os << setw(15) << left;
}

// Structure to hold student record
struct Student
{
    string name; // Using std::string instead of char array
    int marks;
    char grade;
};

int main()
{
    ifstream fin("students.txt");
    if (!fin)
    {
        cout << "Error: Could not open file 'students.txt'. Please check if the file exists.\n";
        return 1;
    }

    cout << "\n--- Student Performance Report ---\n\n";
    cout << tab << "Name" << tab << "Marks" << tab << "Grade" << endl;
    cout << string(45, '-') << endl;

    Student s;
    while (fin >> s.name >> s.marks >> s.grade)
    {
        cout << tab << s.name << tab << s.marks << tab << s.grade << endl;
    }

    fin.close();

    cout << "\n24CE060_POOJA\n";
    return 0;
}
