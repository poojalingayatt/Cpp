/* Programmer: Pooja Lingayat
   Date:10-2-25
   Aim:to create an employee payroll management system for a retail store*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

// Employee class to manage employee details
class Employee
{
    string Name;          // Stores the employee's name
    double BasicSalary;   // Stores the employee's basic salary
    double Bonus;         // Stores the employee's bonus amount

public:

    // Constructor to initialize employee details (with a default bonus of 5000)
    Employee(string name, double salary, double bonus=5000)
    {
       Name= name;            // Initialize name
       BasicSalary= salary;   // Initialize basic salary
       Bonus= bonus;          // Initialize bonus (default is 5000)
    }

    // Inline function to calculate the total salary by adding basic salary and bonus
    inline double CalculateTotalSalary()
    {
        return BasicSalary + Bonus; // Return total salary
    }

    // Function to display employee details
    void Displaydetails()
    {
        cout << "Name: " << Name << endl;                   // Output employee's name
        cout << "Basic Salary: " << BasicSalary << endl;     // Output basic salary
        cout << "Bonus: " << Bonus << endl;                 // Output bonus
        cout << "Total Salary: " << CalculateTotalSalary() << endl; // Output total salary
    }
};

int main()
{
    // Vector to store employee records dynamically
    vector<Employee> employees;

    int numEmployees; // Variable to store the number of employees
    cout << "Enter the number of employees: ";
    cin >> numEmployees; // Input the number of employees

    // Loop to input details of each employee
    for(int i=0; i<numEmployees; i++)
    {
        string name;       // Variable to store employee's name
        double salary;     // Variable to store basic salary
        double bonus;      // Variable to store bonus

        // Input employee details
        cout << "Enter details for employee " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin >> name;               // Input name
        cout << "Basic Salary: ";
        cin >> salary;             // Input basic salary
        cout << "Bonus (Enter 0 for default bonus): ";
        cin >> bonus;              // Input bonus (0 means use default bonus)

        // Add employee to the vector, handling default bonus if necessary
        if(bonus == 0)
            employees.push_back(Employee(name,salary)); // Use default bonus
        else
            employees.push_back(Employee(name,salary,bonus)); // Use custom bonus

    }

    // Display all employee payroll details
    cout << "\nEmployee Payroll Details:" << endl;

    // Loop to display each employee's details
    for(int i=0; i<numEmployees; i++)
    {
        employees[i].Displaydetails(); // Call function to display details
    }

    return 0; // Exit the program
}
