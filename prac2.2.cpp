#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string rollNumber;
    string name;
    float marks[3]; // Marks in three subjects
    float average;

public:
    // Default constructor for initializing student with default values
    Student() {
        rollNumber = "Unknown";
        name = "Unknown";
        marks[0] = marks[1] = marks[2] = 0.0;
        average = 0.0;
    }

    // Constructor that accepts specific details for a student
    Student(string rNo, string n, float m1, float m2, float m3) {
        rollNumber = rNo;
        name = n;
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
        calculateAverage();
    }

    // Function to calculate average marks
    void calculateAverage() {
        average = (marks[0] + marks[1] + marks[2]) / 3.0;
    }

    // Function to display student details
    void displayStudentDetails() {
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
        cout << "Average Marks: " << average << endl;
    }


};

int main() {
    Student students[3];
    string rollNumber,name;
        float m1,m2,m3;
    for (int i = 0; i < 3; i++)
    {
        cout<<"Enter Details for Student"<<i+1<<endl;
        cout<<"Enter Roll Number: ";
        cin>>rollNumber;
        cout<<"Enter Name";
        cin>>name;
        cout<<"Enter Marks for Three Subject: ";
        cin>>m1>>m2>>m3;
        students[i]= Student(rollNumber, name, m1,m2,m3);
    }


    // Displaying all student details
    cout << "\nStudent Records:\n";
    for (int i = 0; i < 3; i++) {
        students[i].displayStudentDetails();
        cout << "----------------------\n";
    }

    return 0;
}
