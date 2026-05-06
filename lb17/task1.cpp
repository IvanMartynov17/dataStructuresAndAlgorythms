#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Student {
    string surname;
    int groupNumber;
    double studentsMarks[4];
    double averageMark;
};

double calculateAverageMark(Student& student) {
    double sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += student.studentsMarks[i];
    }
    return sum / 4;
}

void insertMarks(vector<Student>& students) {
    for (int i = 0; i < students.size(); i++) {
        cout << "Student " << (i+1) << ": ";

        cout << "Surname: " << endl;
        cin >> students[i].surname;

        cout << "Group number: " << endl;
        cin >> students[i].groupNumber;

        cout << "Marks: " << endl;
        for (int j = 0; j < 4; j++) {
            cin >> students[i].studentsMarks[j];
        }

        students[i].averageMark = calculateAverageMark(students[i]);
        cout << "Average mark: " << students[i].averageMark << endl;
    }
}

void bubbleSort(vector<Student>& students) {
    int n = students.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (students[j].averageMark > students[j+1].averageMark) {
                swap(students[j], students[j+1]);
            }
        }
    }
}

void insertionSortByGroupNumber(vector<Student>& students) {
    int n = students.size();
    for (int i = 1; i < n; i++) {
        Student key = students[i];
        int j = i - 1;
        while (j >= 0 && students[j].groupNumber < key.groupNumber) {
            students[j+1] = students[j];
            j--;
        }
        students[j+1] = key;
    }
}

vector<int> binarySearch(const vector<Student>& students, double target) {
    vector <int> result;
    int left = 0, right = students.size() - 1;
    int found = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].averageMark == target) {
            found = mid;
            break;
        } else if (students[mid].averageMark < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (found != -1) {
        int i = found;
        while (i >= 0 && students[i].averageMark == target) i--;
        i++;
        while (i < (int)students.size() && students[i].averageMark == target){
            result.push_back(i);
            i++;
        }
    }

    return result;
}

void printStudents(const vector<Student>& students) {
    cout << "\tStudents info: " << endl;
    cout << left << setw(20) << "Surname: "
    << left << setw(10) << "Group: "
    << left << setw(30) << "Marks: "
    << left << setw(10) << "Average:  " << endl;

    for (const auto& student : students) {
        cout << left << setw(20) << student.surname
         << setw(10) << student.groupNumber;

        for (int i = 0; i < 4; i++)
            cout << setw(9) << student.studentsMarks[i];
        cout << left << setw(10) << student.averageMark << endl;
    }

}
int main() {

    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    vector<Student> students(n);
    insertMarks(students);


    vector<Student> sortedByAverage = students;
    cout << "\tBubble sort by average mark:" << endl;
    bubbleSort(sortedByAverage);
    printStudents(sortedByAverage);

    vector<Student> sortedByGroup = students;
    cout << "\tInsertion sort by group number:" << endl;
    insertionSortByGroupNumber(sortedByGroup);
    printStudents(sortedByGroup);

    double searchMark;
    cout << "Enter the mark to search: ";
    cin >> searchMark;

    vector<int> found = binarySearch(sortedByAverage, searchMark);
    cout << "\tSearch results:" << endl;
    if (found.empty()) {
        cout << "Not found" << endl;
    }
    else {
        cout << "Found: " << found.size() << " students" << endl;
        for (const auto& index : found) {
            cout << " " << sortedByAverage[index].surname
            << " | Group: " << sortedByAverage[index].groupNumber
            << " | Average: " << sortedByAverage[index].averageMark << endl;
        }
    }
    return 0;
}

