#include <iostream>
#include <string>
#include <vector>

using namespace std;



struct Student
{
	string name;
	string surname;

	int birth_day;
	int birth_month;
	int birth_year;
};



void ReadStudentsList (vector <Student>& students);

void AnswerQueries (int num_queries, const vector <Student>& students);



int main ()
{
	int num_students = 0;

	cin >> num_students;

	
	vector <Student> students (num_students);

	ReadStudentsList (students);


	int num_queries = 0;

	cin >> num_queries;

	AnswerQueries (num_queries, students);


	return 0;
}


void ReadStudentsList (vector <Student>& students)
{
	for (Student& person : students)
	{
		cin >> person.name;
		cin >> person.surname;
		
		cin >> person.birth_day;
		cin >> person.birth_month;
		cin >> person.birth_year;
	}
}


void AnswerQueries (int num_queries, const vector <Student>& students)
{

	string property;

	int student_number = 0;

	
	for (int i = 0; i < num_queries; i++)
	{
		cin >> property >> student_number;

		if (student_number > students.size() || student_number < 1)
		{
			cout << "bad request" << endl;
			continue;
		}


		const Student& student = students[student_number - 1];

		if (property == "name")
		{
			cout << student.name << " " << student.surname << endl;
		}
		else if (property == "date")
		{
			cout << student.birth_day << "." << student.birth_month << "." << student.birth_year << endl;
		}
		else
		{
			cout << "bad request" << endl;
		}
	}
}