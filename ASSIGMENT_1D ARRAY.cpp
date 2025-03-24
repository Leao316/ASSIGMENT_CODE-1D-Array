#include <iostream>
#include <string>
using namespace std;

struct Student {
    int id;
    string firstName;
    string lastName;
    int age;
    string course;
    float grade;
};

Student students[100];
int studentCount = 0;

void addStudent() {
    if (studentCount >= 100) {
        cout << "Student list is full!\n";
        return;
    }
    cout << "Enter student ID: ";
    cin >> students[studentCount].id;
    cout << "Enter student first name: ";
    cin >> students[studentCount].firstName;
    cout << "Enter student last name: ";
    cin >> students[studentCount].lastName;
    cout << "Enter student age: ";
    cin >> students[studentCount].age;
    cout << "Enter student course: ";
    cin >> students[studentCount].course;
    cout << "Enter student grade: ";
    cin >> students[studentCount].grade;
    studentCount++;
    cout << "Student added successfully!\n";
}

bool validateStudentID(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) return true;
    }
    return false;
}

void editStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cout << "Enter new first name: ";
            cin >> students[i].firstName;
            cout << "Enter new last name: ";
            cin >> students[i].lastName;
            cout << "Enter new age: ";
            cin >> students[i].age;
            cout << "Enter new course: ";
            cin >> students[i].course;
            cout << "Enter new grade: ";
            cin >> students[i].grade;
            cout << "Student data updated!\n";
            return;
        }
    }
    cout << "Student ID not found!\n";
}

void deleteStudent(int id) {
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Student data deleted!\n";
            return;
        }
    }
    cout << "Student ID not found!\n";
}

void displayStudents() {
    if (studentCount == 0) {
        cout << "No student data available.\n";
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << students[i].id << ", Name: " << students[i].firstName << " " << students[i].lastName
             << ", Age: " << students[i].age << ", Course: " << students[i].course << ", Grade: " << students[i].grade << endl;
    }
}

int main() {
    int choice, id;
    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Add student\n2. Validate student ID\n3. Edit student\n4. Delete student\n5. Display students\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                cout << "Enter student ID to validate: ";
                cin >> id;
                if (validateStudentID(id))
                    cout << "Student ID is valid.\n";
                else
                    cout << "Invalid student ID!\n";
                break;
            case 3:
                cout << "Enter student ID to edit: ";
                cin >> id;
                editStudent(id);
                break;
            case 4:
                cout << "Enter student ID to delete: ";
                cin >> id;
                deleteStudent(id);
                break;
            case 5:
                displayStudents();
                break;
            case 6:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
