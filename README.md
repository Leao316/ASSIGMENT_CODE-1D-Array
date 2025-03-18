#include <iostream>
#include <string>
using namespace std;

struct Student {
    int studentId;
    string firstName;
    string lastName;
    string course;
    float gpa;
};

int main() {
    int numStudents;


    cout << "Enter the number of students: ";
    cin >> numStudents;


    Student students[numStudents];


    for (int i = 0; i < numStudents; ++i) {
        cout << "\nEnter details for student " << i + 1 << ":\n";

        cout << "Enter student ID: ";
        cin >> students[i].studentId;

        cout << "Enter first name: ";
        cin >> students[i].firstName;

        cout << "Enter last name: ";
        cin >> students[i].lastName;

        cout << "Enter course: ";
        cin >> students[i].course;

        cout << "Enter previous semestral GPA: ";
        cin >> students[i].gpa;
    }


    cout << "\nStudent Records:\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Student ID: " << students[i].studentId << endl;
        cout << "Name: " << students[i].firstName << " " << students[i].lastName << endl;
        cout << "Course: " << students[i].course << endl;
        cout << "Previous Semestral GPA: " << students[i].gpa << endl;
    }

    return 0;
}
