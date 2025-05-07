/* Programmer: Pooja Lingayat
   Date: 28-2-25
   Aim: To demonstrate multilevel inheritance by managing manager details using Person, Employee, and Manager classes. */

#include<iostream>
#include<string>
using namespace std;

// Base class
class Person
{
protected:
    string name;
    int age;
public:
    Person() {}  // Default constructor
    Person(string n, int a)
     {
        name = n;
        age = a;
    }
    void displayPerson()
    {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Derived from Person
class Employee : public Person
{
protected:
    int empId;
public:
    Employee() {}  // Default constructor
    Employee(string n, int a, int id) : Person(n, a)
    {
        empId = id;
    }
    void displayEmployee()
     {
        displayPerson();
        cout << "Employee ID: " << empId << endl;
    }
};

// Derived from Employee
class Manager : public Employee
{
    string department;
public:
    Manager() {}  // Default constructor
    Manager(string n, int a, int id, string dept) : Employee(n, a, id)
     {
        department = dept;
    }
    void displayManager()
     {
        displayEmployee();
        cout << "Department: " << department << endl;
    }
};

int main()
 {
    int n;
    cout << "Enter number of managers: ";
    cin >> n;

    Manager managers[100];  // Fixed-size array (enough for most cases)

    for (int i = 0; i < n; i++)
        {
        string name, dept;
        int age, id;

        cout << "\nEnter details for Manager " << i + 1 << ":" << endl;

        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Employee ID: ";
        cin >> id;

        cout << "Enter Department: ";
        cin.ignore();
        getline(cin, dept);

        managers[i] = Manager(name, age, id, dept);  // Direct object creation
    }

    cout << "\n----- Manager Details -----\n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nManager " << i + 1 << " Details:" << endl;
        managers[i].displayManager();
    }
     cout << "\n24CE060_POOJA\n";
    return 0;
}
