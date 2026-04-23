#include <iomanip>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Student {
    string name;
    int groupNumber;
    double avgMark;

    void printStudent() const {
        cout << left
             << setw(25) << name
             << setw(15) << groupNumber
             << setw(10) << avgMark << endl;
    }
};

void printHeader() {
    cout << left
         << setw(25) << "Full Name"
         << setw(15) << "Group Number"
         << setw(10) << "Avg Mark" << endl;
    cout << string(50, '-') << endl;
}

void printStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students in the list." << endl;
        return;
    }
    printHeader();
    for (const auto& student : students) {
        student.printStudent();
    }
    cout << string(50, '-') << endl;
    cout << "Total students: " << students.size() << endl;
}

void addStudent(vector<Student>& students) {
    Student student;

    cin.ignore();
    cout << "Enter full name: ";
    getline(cin, student.name);

    cout << "Enter group number: ";
    cin >> student.groupNumber;

    cout << "Enter average mark: ";
    cin >> student.avgMark;

    students.push_back(student);
    cout << "Student added successfully." << endl;
}

void deleteStudentByName(vector<Student>& students) {
    cin.ignore();
    cout << "Enter full name to delete: ";
    string name;
    getline(cin, name);

    auto it = find_if(students.begin(), students.end(), [&name](const Student& s) {
        return s.name == name;
    });

    if (it != students.end()) {
        students.erase(it);
        cout << "Student \"" << name << "\" deleted." << endl;
    } else {
        cout << "Student \"" << name << "\" not found." << endl;
    }
}

void sortStudentsByAvgMark(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.avgMark < b.avgMark;
    });
    cout << "Students sorted by average mark." << endl;
}

void sortStudentsByGroupAndMark(vector<Student>& students) {
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        if (a.groupNumber != b.groupNumber)
            return a.groupNumber < b.groupNumber;
        return a.avgMark < b.avgMark;
    });
    cout << "Students sorted by group and average mark." << endl;
}

void findStudentsByGroup(const vector<Student>& students) {
    int group;
    cout << "Enter group number to search: ";
    cin >> group;

    vector<Student> result;
    for (const auto& s : students) {
        if (s.groupNumber == group)
            result.push_back(s);
    }

    if (result.empty()) {
        cout << "No students found in group " << group << "." << endl;
    } else {
        cout << "Students in group " << group << ":" << endl;
        printStudents(result);
    }
}

void findStudentsAboveMark(const vector<Student>& students) {
    double mark;
    cout << "Enter minimum average mark: ";
    cin >> mark;

    vector<Student> result;
    for (const auto& s : students) {
        if (s.avgMark > mark)
            result.push_back(s);
    }

    if (result.empty()) {
        cout << "No students with average mark above " << mark << "." << endl;
    } else {
        cout << "Students with average mark above " << mark << ":" << endl;
        printStudents(result);
    }
}

void menu() {
    cout << endl;
    cout << "\t=== MENU ===" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Delete student by name" << endl;
    cout << "3. Sort by average mark" << endl;
    cout << "4. Sort by group and average mark" << endl;
    cout << "5. Print all students" << endl;
    cout << "6. Find students by group" << endl;
    cout << "7. Find students above mark" << endl;
    cout << "0. Exit" << endl;
    cout << endl;
}

int main() {
    vector<Student> students;
    int command;

    while (true) {
        menu();
        cout << "Enter command: ";
        cin >> command;

        switch (command) {
            case 1:
                addStudent(students);
                break;
            case 2:
                deleteStudentByName(students);
                break;
            case 3:
                sortStudentsByAvgMark(students);
                break;
            case 4:
                sortStudentsByGroupAndMark(students);
                break;
            case 5:
                printStudents(students);
                break;
            case 6:
                findStudentsByGroup(students);
                break;
            case 7:
                findStudentsAboveMark(students);
                break;
            case 0:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Unknown command. Try again." << endl;
        }
    }
}
