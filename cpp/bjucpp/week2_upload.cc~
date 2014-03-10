#include <iostream>
#include <string>
#include <algorithm>			// str remove needed

using namespace std;

class Student {
private:
	//string name;
	char name[25];
	int age;
	//string id;
	char id[10];
	// int 1st_ys;
	// int 2ec_ys;
	// int 3rd_ys;
	// int 4th_ys;
	int score[4];

public:
	void SetName() {
		//cin >> name;
		cin.get(name, 25, ',');
		//name.erase(remove(name.begin(), name.end(), ','), name.end());
		//name.erase(remove(name.begin(), name.end(), ' '), name.end());
	}

	void SetId() {
		//cin >> id;
		cin.get(id, 25, ',');
		//id.erase(remove(id.begin(), id.end(), ' '), id.end());
	}

	void SetAge() {
		cin >> age;
	}

	int GetAverageScore();
	void SetStudentInfo();
	void PrintStudentInfo();
	void PrintStudentAveScore();
	// int SetScore() {
	// 	int x;
	// 	cin >> x;
	// 	return x;
	// }

	void Set4Scores() {
		// int i = 0;
		// for (i = 0; i < 4; i++) {
		// 	score[i] = SetScore();
		// }
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

	// Student(string name_ = "enheng", int age_ = 0,
	// 		string id_ = "007") {
	// 	name = name_;
	// 	age = age_;
	// 	id = id_;
	// }
	
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
	char nouse;
	SetName();
	cin >> nouse;
	SetAge();
	cin >> nouse;
	SetId();
	cin >> nouse;
	Set4Scores();
}

void Student::PrintStudentInfo() {
	cout << "name: " << name << endl;
	cout << "age: " << age <<endl;
	cout << "id: " << id << endl;
	Print4Scores();
}

void Student::PrintStudentAveScore() {
	cout << name << "," << age << ","
		 << id <<"," << GetAverageScore() << endl;
}

int main()
{
	Student stu1;

	stu1.SetStudentInfo();
	//stu1.PrintStudentInfo();
	stu1.PrintStudentAveScore();
	
	return 0;
}
