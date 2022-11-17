#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;



int main ()
{
	int num_queries;
	cin >> num_queries;


	map <set <string>, int> routes;

	int index = 1;


	int num_stations;

	string name;

	set <string> stations;

	for (int i = 0; i < num_queries; i++)
	{
		cin >> num_stations;

		for (int i = 0; i < num_stations; i++)
		{
			cin >> name;

			stations.insert(name);
		}


		if (routes[stations] == 0)
		{
			cout << "New bus " << index << endl;
			routes[stations] = index++;
		}
		else
		{
			cout << "Already exists for " << routes[stations] << endl;
		}


		stations.clear();
	}


	return 0;
}