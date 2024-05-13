#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    int rollNumber;
    float marks;
};

void addStudent(vector<Student>& students) {
    Student newStudent;
    cout << "Enter student name: ";
    cin >> newStudent.name;
    cout << "Enter roll number: ";
    cin >> newStudent.rollNumber;
    cout << "Enter marks: ";
    cin >> newStudent.marks;
    students.push_back(newStudent);
}

void displayStudents(const vector<Student>& students) {
    cout << "Student Details:" << endl;
    for (const auto& student : students) {
        cout << "Name: " << student.name << ", Roll Number: " << student.rollNumber << ", Marks: " << student.marks << endl;
    }
}

float calculateAverageMarks(const vector<Student>& students) {
    float totalMarks = 0;
    for (const auto& student : students) {
        totalMarks += student.marks;
    }
    return totalMarks / students.size();
}

int main() {
    vector<Student> students;
    char choice;
    
    do {
        cout << "MENU:" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Calculate Average Marks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case '1':
                addStudent(students);
                break;
            case '2':
                displayStudents(students);
                break;
            case '3':
                if (!students.empty()) {
                    cout << "Average Marks: " << calculateAverageMarks(students) << endl;
                } else {
                    cout << "No students added yet." << endl;
                }
                break;
            case '4':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != '4');
    
    return 0;
}
