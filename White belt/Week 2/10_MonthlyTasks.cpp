#include <iostream>
#include <string>
#include <vector>


using namespace std;



void AddTask (vector <vector <string>>& tasks, int day, string name);
void DumpDay (const vector <vector <string>>& tasks, int day);

void SwitchMonth    (vector <vector <string>>& tasks, int new_num_days);
void ManageOldTasks (vector <vector <string>>& tasks, int current_end, int new_end);



int main ()
{
	int num_queries;
	cin >> num_queries;


	int current_month = 0;

	vector <int> days_in_month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	vector <vector <string>> tasks (days_in_month[current_month]);


	int day;

	string name;

	string command;

	for (int i = 0; i < num_queries; i++)
	{
		cin >> command;

		if (command == "NEXT")
		{
			current_month++;
			current_month %= 12;
			SwitchMonth (tasks, days_in_month[current_month]);
		}
		else
		{
			cin >> day;

			if (command == "ADD")
			{
				cin >> name;

				AddTask (tasks, day, name);
			}
			else
			{
				DumpDay (tasks, day);
			}
		}
	}


	return 0;
}


void AddTask (vector <vector <string>>& tasks, int day, string name)
{
	tasks[day - 1].push_back(name);
}


void DumpDay (const vector <vector <string>>& tasks, int day)
{
	int num_tasks = tasks[day - 1].size();

	cout << num_tasks << ' ';

	for (int i = 0; i < num_tasks; i++)
	{
		cout << tasks[day - 1][i] << ' ';
	}

	cout << endl;
}



void SwitchMonth (vector <vector <string>>& tasks, int new_num_days)
{
	int new_end     = new_num_days - 1;
	int current_end = tasks.size() - 1;

	for (int day = new_end + 1; day <= current_end; day++)
	{
		tasks[new_end].insert(end(tasks[new_end]), begin(tasks[day]), end(tasks[day]));
	}

	tasks.resize (new_num_days);
}