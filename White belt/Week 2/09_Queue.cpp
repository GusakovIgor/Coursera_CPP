#include <iostream>
#include <string>
#include <vector>

using namespace std;



void ReadCommand (string& command, int& argument);

int CountWorried (vector <bool> queue);



int main ()
{
	int num_queries;
	cin >> num_queries;


	vector <bool> queue;

	int num_worried = 0;


	int argument;

	string command;

	for (int i = 0; i < num_queries; i++)
	{
		ReadCommand (command, argument);

		if (command == "WORRY" || command == "QUIET")
		{
			queue[argument] = (command == "WORRY");
		}
		else if (command == "COME")
		{
			queue.resize (queue.size() + argument, false);
		}
		else if (command == "WORRY_COUNT")
		{
			cout << CountWorried (queue) << endl;
		}
		else
		{
			cout << "Unkown command: \"" << command << "\"" << endl;
		}
	}

	return 0;
}


void ReadCommand (string& command, int& argument)
{
	cin >> command;

	if (command != "WORRY_COUNT")
	{
		cin >> argument;
	}
}


int CountWorried (vector <bool> queue)
{
	int num_worried = 0;

	for (auto elem : queue)
	{
		if (elem == true)
		{
			num_worried++;
		}
	}

	return num_worried;
}