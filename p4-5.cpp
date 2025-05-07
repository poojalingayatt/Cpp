/* Programmer: Pooja Lingayat
   Date: 7-3-25
   Aim: To implement an abstract class for students and compute grades for undergraduate and postgraduate students using runtime polymorphism. */

#include<iostream>
#include<string>
using namespace std;

// Abstract Base Class
class Student {
protected:
    string name;
    float marks;
public:
    void getData() {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Marks: ";
        cin >> marks;
    }

    virtual void computeGrade() = 0; // pure virtual
};

// Undergraduate class
class Undergraduate : public Student {
public:
    void computeGrade() override {
        cout << "Undergraduate Student: " << name << endl;
        if (marks >= 80)
            cout << "Grade: A\n";
        else if (marks >= 60)
            cout << "Grade: B\n";
        else if (marks >= 40)
            cout << "Grade: C\n";
        else
            cout << "Grade: F\n";
    }
};

// Postgraduate class
class Postgraduate : public Student {
public:
    void computeGrade() override {
        cout << "Postgraduate Student: " << name << endl;
        if (marks >= 85)
            cout << "Grade: A\n";
        else if (marks >= 70)
            cout << "Grade: B\n";
        else if (marks >= 50)
            cout << "Grade: C\n";
        else
            cout << "Grade: F\n";
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int type;
        cout << "\nSelect Student Type (1-UG, 2-PG): ";
        cin >> type;

        if (type == 1) {
            Undergraduate ug;
            ug.getData();
            ug.computeGrade();
        } else if (type == 2) {
            Postgraduate pg;
            pg.getData();
            pg.computeGrade();
        } else {
            cout << "Invalid type!\n";
        }
    }
 cout << "\n24CE060_POOJA\n";
    return 0;
}

