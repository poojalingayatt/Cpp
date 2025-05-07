/* Programmer: Pooja Lingayat
   Date: 25-4-25
   Aim: Display student marks and tuition fees using formatting manipulators and a custom currency symbol.*/

#include <iostream>
#include <iomanip>
using namespace std;

// User-defined manipulator to print currency symbol
ostream& currency(ostream& os)
{
    return os << "Rs.";
}

// Structure to hold student data
struct Student
{
    string name;
    int marks;
    float tuitionFee;
};

int main()
{
    Student students[] = {
        {"Amit", 85, 45250.5},
        {"Rina", 91, 50000},
        {"Kunal", 73, 38000.75},
        {"Priya", 88, 46000}
    };

    int n = sizeof(students) / sizeof(Student);

    // Print headers
    cout << left << setw(15) << "Name"
         << setw(10) << "Marks"
         << setw(15) << "Tuition Fee" << endl;

    cout << setfill('-') << setw(40) << "-" << setfill(' ') << endl;

    // Print student data
    for (int i = 0; i < n; ++i)
    {
        cout << left << setw(15) << students[i].name
             << setw(10) << students[i].marks
             << currency << fixed << setprecision(2) << setw(15) << students[i].tuitionFee << endl;
    }

    cout << "\n24CE060_POOJA\n";
    return 0;
}

