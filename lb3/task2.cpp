#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

enum Faculty {
	informationtechnologies,
	economy,
	law,
	management
};
struct Student {
	string surname;
	int course;
	double avgMark;
	Faculty faculty;
};

int main()
{
	Student s[5];
	int  i, facult, searchStudent;
	double sum = 0;

	for (i = 0; i < 5; i++)
	{
		cout << "\tStudent number " << i + 1 << endl;

		cout << "Enter a surname: " << endl;
		cin >> s[i].surname;

		cout << "Enter a course: " << endl;
		cin >> s[i].course;

		cout << "Enter average mark: " << endl;
		cin >> s[i].avgMark;

		cout << "Choose faculty (0-IT, 1-Economy, 2-Law, 3-Management): ";
		cin >> facult;
		s[i].faculty = (Faculty)facult;
	}
	cout << "Enter faculty to display students (0-IT,1-Economy,2-Law,3-Management): ";
		cin >> searchStudent;

		for (i = 0; i < 5; i++)
		{
			sum += s[i].avgMark;
		}

		cout << "Average mark of group: " << sum / 5 << endl;

		for (i = 0; i < 5; i++)
		{
			if (s[i].faculty == searchStudent)
			{
				cout << s[i].surname << endl;
			}
		}

	return 0;
}