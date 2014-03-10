#include <iostream>
#include <cstring>

using namespace std;

class Student {
private:
	char name[25];
	unsigned int age;
	char id[10];
	unsigned int score[4];

public:
	void SetName() {
		cin.get(name, 25, ',');	// "," make me crazy, maybe it isn't a good func name.
	}

	void SetId() {
		cin.get(id, 25, ',');
	}

	void SetAge() {
		cin >> age;
	}

	int GetAverageScore();
	void SetStudentInfo();
	void PrintStudentInfo();
	void PrintStudentAveScore();

	void Set4Scores() {
		char b;
		cin >> score[0] >> b >> score[1] >> b
			>> score[2] >> b >> score[3];
	}

	void Print4Scores() {
		int i = 0;
		for (i = 0; i < 4; i++) {
			cout << "Year " << i + 1 << ": "
				 << score[i] << endl;
		}
	}

	Student() {
		strcpy(name, "poorleo_no_oscar");
		age = 18;
		strcpy(id, "007");

		for (int i = 0; i < 4; i++) {
			score[i] = 0;
		}
	}
};

int Student::GetAverageScore() {
	int sum = 0;
	for (int i = 0; i < 4; i++) {
		sum += score[i];
	}
	return sum / 4;
}

void Student::SetStudentInfo() {
	char nouse;					// honestly i don't know why, but it works....
	SetName();
	cin >> nouse;
	SetAge();
	cin >> nouse;
	SetId();
	cin >> nouse;
	Set4Scores();
}

void Student::PrintStudentAveScore() {
	cout << name << "," << age << ","
		 << id <<"," << GetAverageScore() << endl;
}

int main()
{
	Student stu1;

	stu1.SetStudentInfo();
	stu1.PrintStudentAveScore();
	
	return 0;
}
