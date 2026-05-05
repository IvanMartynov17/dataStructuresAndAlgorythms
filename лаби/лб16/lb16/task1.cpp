#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
#include <iomanip>

using namespace std;
struct Student
{
    string studentName;
    int studentScores[3];
    double averageScore;

    void calculateAvgScore() {
            averageScore = (studentScores[0] + studentScores[1] + studentScores[2]) / 3.0;
    }
};

void inputStudents(vector<Student> &students) {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    students.resize(n);

    for (int i = 0; i < n; i++) {
        cout << "--- Student " << i + 1 << " ---" << endl;
        cout << "Name: ";
        cin >> students[i].studentName;

        for (int j = 0; j < 3; j++) {
            cout << "Exam score " << j + 1 << ": ";
            while (!(cin >> students[i].studentScores[j])
                || students[i].studentScores[j] < 0 || students[i].studentScores[j] > 100) {
                cout << "Please enter a number between 0 and 100: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        students[i].calculateAvgScore();
    }

}

void printStudentList(vector<Student> &students) {
    cout << "\n"
    << left << setw(5) << "№ "
    << setw(20) << "Name: "
    << setw(15) << "Score 1: "
    << setw(15) << "Score 2: "
    << setw(15) << "Score 3: "
    << setw(20) << "Average Score" << endl;

    for (size_t i = 0; i < students.size(); i++) {
        cout << left << setw(5) << (i + 1)
        << setw(20) << students[i].studentName
        << setw(15) << students[i].studentScores[0]
        << setw(15) << students[i].studentScores[1]
        << setw(15) << students[i].studentScores[2]
        << fixed << setprecision(2) << setw(20)
        << students[i].averageScore << endl;
    }
}

void linearSearch(vector<Student> &students) {
    cout << "\n\t---Linear Search---\t\n";

    double maxAverage = students[0].averageScore;
    for (const auto& student : students) {
        if (student.averageScore > maxAverage) {
            maxAverage = student.averageScore;
        }
    }

    vector <int> indices;
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i].averageScore == maxAverage) {
            indices.push_back(static_cast<int>(i));
        }
    }

    cout << "Max average score: " << fixed
    << setprecision(2) << maxAverage << endl;
    cout << "Student indices: " << indices.size() << endl;
    cout << "Student index: " << endl;
    for (int idx : indices) {
        cout << " N" << idx + 1 << " - "
        << students[idx].studentName
        << " (" << fixed << setprecision(2)
        << students[idx].averageScore << ") " << endl;
    }
}

void binarySearch(vector<Student> &students) {
    cout << "\n\t---Binery Search---\t\n";
    double maxAverage = students[0].averageScore;

    sort(students.begin(), students.end()
        , [](const Student &a, const Student &b) {
            return a.averageScore > b.averageScore;
        });

    cout << "Sorted list: " << endl;
    printStudentList(students);

    double target;
    cout << "Enter average mark for search: ";
    cin >> target;

    int low = 0;
    int high = static_cast<int>(students.size()) - 1;
    int found = -1;

    while (low <= high) {
        int middle = (low + high) / 2;
        if (students[middle].averageScore == target) {
            found = middle;
            break;
        }
        else if (students[middle].averageScore < target) {
            low = middle + 1;
        }else {
            high = middle - 1;
        }
    }

if (found == -1) {
    cout << "Student with " << fixed
    << setprecision(2) << target << " Not found.\n";
    return;
}
    int left = found, right = found;
    while (left > 0 && students[left - 1].averageScore == target) {
        left--;
    }
    while (right < static_cast<int>(students.size()) -1 &&
        students[right + 1].averageScore == target) {
        right++;
    }

    cout << "Student with " << fixed
    << setprecision(2) << target << ": \n";
    for (int i = left; i <= right; i++) {
        cout << " N" << (i + 1) << " - " << students[i].studentName
        << " (" << fixed << setprecision(2) << students[i].averageScore << ")\n";
    }

 }

int main(){
    vector<Student> students;

    inputStudents(students);
    printStudentList(students);


    linearSearch(students);
    binarySearch(students);
    return 0;
}